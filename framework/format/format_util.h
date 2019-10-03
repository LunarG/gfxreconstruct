/*
** Copyright (c) 2018 Valve Corporation
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

#ifndef GFXRECON_FORMAT_FORMAT_UTIL_H
#define GFXRECON_FORMAT_FORMAT_UTIL_H

#include "format/format.h"
#include "util/compressor.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(format)

// Utilities for converting API handles to the HandleId type.
template <typename T>
typename std::enable_if<std::is_pointer<T>::value, HandleId>::type ToHandleId(const T& handle)
{
    return reinterpret_cast<HandleId>(handle);
}

template <typename T>
typename std::enable_if<!std::is_pointer<T>::value, HandleId>::type ToHandleId(const T& handle)
{
    return static_cast<HandleId>(handle);
}

template <typename T>
typename std::enable_if<std::is_pointer<T>::value, T>::type FromHandleId(HandleId id)
{
    return reinterpret_cast<T>(id);
}

template <typename T>
typename std::enable_if<!std::is_pointer<T>::value, T>::type FromHandleId(HandleId id)
{
    return static_cast<T>(id);
}

// Utilities for managing compressed block types.
inline bool IsBlockCompressed(BlockType type)
{
    return ((type & kCompressedBlockTypeBit) == kCompressedBlockTypeBit);
}

inline BlockType AddCompressedBlockBit(BlockType type)
{
    return static_cast<BlockType>(type | kCompressedBlockTypeBit);
}

inline BlockType RemoveCompressedBlockBit(BlockType type)
{
    return static_cast<BlockType>(type & ~kCompressedBlockTypeBit);
}

// Utilities for format validation.
bool ValidateFileHeader(const FileHeader& header);

// Utilities for object creation.
util::Compressor* CreateCompressor(CompressionType type);

GFXRECON_END_NAMESPACE(format)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_FORMAT_FORMAT_UTIL_H
