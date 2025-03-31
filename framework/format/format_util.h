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
#include "util/memory_output_stream.h"

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

//! groups memory regions for header & data of an optionally compressed function-block
struct function_call_block_t
{
    char        header[std::max(sizeof(format::FunctionCallHeader), sizeof(format::CompressedFunctionCallHeader))]{};
    size_t      header_size = 0;
    const void* data        = nullptr;
    size_t      data_size   = 0;
};

/**
 * @brief   CreateFunctionCallBlock can be used to create an optionally compressed function-call block
 *          and return pointers to the created header- and data-segments.
 *
 * @param   call_id                     provided ApiCallId
 * @param   thread_id                   provided ThreadId
 * @param   parameter_buffer            a MemoryOutputStream containing parameters
 * @param   compressor                  optional compressor, can be nullptr
 * @param   compressor_scratch_space    optional scratch-space to be used during compression, can be nullptr
 * @return  a struct grouping pointers for header- and data-segments
 */
format::function_call_block_t CreateFunctionCallBlock(format::ApiCallId               call_id,
                                                      format::ThreadId                thread_id,
                                                      const util::MemoryOutputStream* parameter_buffer,
                                                      util::Compressor*               compressor,
                                                      std::vector<uint8_t>*           compressor_scratch_space);

GFXRECON_END_NAMESPACE(format)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_FORMAT_FORMAT_UTIL_H
