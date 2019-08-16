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

#ifndef GFXRECON_FORMAT_FORMAT_H
#define GFXRECON_FORMAT_FORMAT_H

#include "format/api_call_id.h"
#include "util/compressor.h"
#include "util/defines.h"

#include <cinttypes>
#include <type_traits>

#define GFXRECON_FOURCC GFXRECON_MAKE_FOURCC('G', 'F', 'X', 'R')
#define GFXRECON_FILE_EXTENSION ".gfxr"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(format)

// Types to define encoding sizes.
typedef uint32_t EnumEncodeType;
typedef uint32_t FlagsEncodeType;
typedef uint32_t SampleMaskEncodeType;
typedef uint64_t HandleEncodeType;
typedef uint64_t DeviceSizeEncodeType;
typedef uint64_t SizeTEncodeType;
typedef uint64_t AddressEncodeType;

typedef HandleEncodeType HandleId;
typedef uint64_t         ThreadId;

const uint32_t kCompressedBlockTypeBit = 0x80000000;

constexpr uint32_t MakeCompressedBlockType(uint32_t block_type)
{
    return kCompressedBlockTypeBit | block_type;
}

// clang-format off
enum BlockType : uint32_t
{
    kUnknownBlock                = 0,
    kFrameMarkerBlock            = 1, // Marker to denote frame status, such as the start or end of a frame.
    kStateMarkerBlock            = 2, // Marker to denote state snapshot status, such as the start or end of a state snapshot.
    kMetaDataBlock               = 3,
    kFunctionCallBlock           = 4,
    kCompressedMetaDataBlock     = MakeCompressedBlockType(kMetaDataBlock),
    kCompressedFunctionCallBlock = MakeCompressedBlockType(kFunctionCallBlock)
};

enum MarkerType : uint32_t
{
    kUnknownMarker = 0,
    kBeginMarker   = 1,
    kEndMarker     = 2
};

enum MetaDataType : uint32_t
{
    kUnknownMetaDataType = 0,

    // Platform independent metadata commands.
    kDisplayMessageCommand = 1,
    kFillMemoryCommand     = 2,
    kResizeWindowCommand   = 3,

    // Commands for trimmed frame state setup.
    kSetSwapchainImageStateCommand = 4
};

enum CompressionType : uint32_t
{
    kNone = 0,
    kLz4  = 1,
    kZlib = 2
};

enum FileOption : uint32_t
{
    kUnknownFileOption     = 0,
    kCompressionType       = 1, // One of the CompressionType values defining the compression algorithm used with parameter
                                // encoding. Default = CompressionType::kNone.
};

enum PointerAttributes : uint32_t
{
    kIsNull         = 0x01, // The pointer was null, so the address and data were not encoded.

    // Type of data
    kIsSingle       = 0x02, // Pointer to a single value.
    kIsArray        = 0x04, // Pointer to an array of values (can be combined with kIsString or kIsStruct).

    // Type modifiers for pointers to aggregate data types
    kIsString       = 0x08, // Pointer to a string.
    kIsWString      = 0x10, // Pointer to a wide character string.
    kIsStruct       = 0x20, // Pointer to a struct.

    // What was encoded
    kHasAddress     = 0x40, // The address of the pointer was encoded (always comes before data).
    kHasData        = 0x80, // The data pointed to was encoded.
};
// clang-format on

struct EnabledOptions
{
    CompressionType compression_type{ CompressionType::kNone };
};

#pragma pack(push)
#pragma pack(4)

struct FileOptionPair
{
    FileOption key;
    uint32_t   value;
};

struct FileHeader
{
    uint32_t fourcc;
    uint32_t major_version; // File format major version.
    uint32_t minor_version; // File format minor version.
    uint32_t num_options;
};

struct BlockHeader
{
    uint64_t  size;
    BlockType type;
};

struct Marker
{
    BlockHeader header;
    MarkerType  marker_type;
    uint64_t    frame_number;
};

struct FunctionCallHeader
{
    BlockHeader      block_header;
    ApiCallId        api_call_id;
    format::ThreadId thread_id;
};

struct CompressedFunctionCallHeader
{
    BlockHeader      block_header;
    ApiCallId        api_call_id;
    format::ThreadId thread_id;
    uint64_t         uncompressed_size;
};

struct MethodCallHeader
{
    BlockHeader      block_header;
    ApiCallId        api_call_id;
    uint64_t         object_id;
    format::ThreadId thread_id;
};

// Metadata block headers and data types.
struct MetaDataHeader
{
    BlockHeader  block_header;
    MetaDataType meta_data_type;
};

struct FillMemoryCommandHeader
{
    MetaDataHeader meta_header;
    format::ThreadId
        thread_id; // NOTE: This is currently the ID of the thread that processed the dirty pages and wrote them to
                   // the file, which may not be the thread that originally modified the memory pages.
    HandleId memory_id;
    uint64_t memory_offset; // Offset from the start of the mapped pointer, not the start of the memory object.
    uint64_t memory_size;   // Uncompressed size of the data encoded after the header.
};

struct DisplayMessageCommandHeader
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    // NOTE: Message size is determined by subtracting the sizeof(MetaDataType) + sizeof(ThreadId) from
    // BlockHeader::size.  This computed size is the length of the ASCII message string, not including the null
    // terminator.
};

// Not a header because this command does not include a variable length data payload.
// All of the command data is present in the struct.
struct ResizeWindowCommand
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    HandleId         surface_id;
    uint32_t         width;
    uint32_t         height;
};

struct SetSwapchainImageStateCommandHeader
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId device_id;
    format::HandleId swapchain_id;
    uint32_t         queue_family_index;
    uint32_t         image_entry_count;
};

struct SwapchainImageStateEntry
{
    format::HandleId image_id;
    uint32_t         image_index;
    uint32_t         image_layout;
    uint32_t         acquired;
    uint32_t         acquire_device_mask;
    format::HandleId acquire_semaphore_id;
    format::HandleId acquire_fence_id;
    format::HandleId last_presented_queue_id;
};

#pragma pack(pop)

GFXRECON_END_NAMESPACE(format)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_FORMAT_FORMAT_H
