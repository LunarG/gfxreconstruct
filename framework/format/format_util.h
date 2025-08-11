/*
** Copyright (c) 2018, 2022 Valve Corporation
** Copyright (c) 2018, 2022 LunarG, Inc.
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
/// @file Helpers for the capture file format.
#ifndef GFXRECON_FORMAT_FORMAT_UTIL_H
#define GFXRECON_FORMAT_FORMAT_UTIL_H

#include "format/format.h"
#include "util/compressor.h"
#include "util/defines.h"

#include <string>

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

// Utilities for file encoding.
template <typename T>
uint64_t GetMetaDataBlockBaseSize(const T& block)
{
    return (sizeof(block) - sizeof(block.meta_header.block_header));
}

/// @return The size of an annotation block header minus the size of the header
constexpr size_t GetAnnotationBlockBaseSize()
{
    return (sizeof(AnnotationHeader) - sizeof(BlockHeader));
}

// Utilities for format validation.
bool ValidateFileHeader(const FileHeader& header);

// Utilities for object creation.
util::Compressor* CreateCompressor(CompressionType type);

std::string GetCompressionTypeName(CompressionType type);

std::string GetApiCallName(ApiCallId call_id);
std::string GetApiFamilyName(ApiFamilyId family_id);
std::string GetApiCallFamilyName(ApiCallId call_id);

GFXRECON_END_NAMESPACE(format)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_FORMAT_FORMAT_UTIL_H
