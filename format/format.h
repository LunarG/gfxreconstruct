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

#ifndef BRIMSTONE_FORMAT_FORMAT_H
#define BRIMSTONE_FORMAT_FORMAT_H

#include <inttypes.h>

#include "util/defines.h"
#include "format/api_call_id.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

enum BlockType : uint32_t
{
    kUnknownBlock = 0,
    kFrameBlock = 1,
    kStateBlock = 2,                // Encapsulates a group of metadata, apicall, and methodcall blocks representing the initial state for a trimmed trace.
    kMetaDataBlock = 3,
    kFunctionCallBlock = 4,
    kCompressedFunctionCallBlock = 5
};

enum MetaDataType : uint32_t
{
    kUnknownMetaDataType = 0,
    kVulkanPhysicalDeviceInfo = 1,
    kVulkanMemoryInfo = 2,
    kFillMemoryCommand = 3
};

enum CompressionType : uint32_t
{
    kNone = 0,
    kLz4 = 1
};

enum FileOption : uint32_t
{
    kUnknownFileOption = 0,
    kCompressionType = 1,           // One of the CompressionType values defining the compression algorithm used with parameter encoding. Default = CompressionType::kNone.
    kHaveThreadId = 2,              // Boolean value: true if the thread ID was included with the API call block header. Default = true.
    kHaveBeginEndTimestamp = 3,     // Boolean value: true if begin and end timestamps were included with the API call block header. Default = false.
    kOmitTextures = 4,              // Boolean value: true if textures were omitted. Default = false.
    kOmitBuffers = 5,               // Boolean value: true if bufferes were omitted. Default = false.
    kAddressEncodingSize = 6,       // Unsigned integer value: defines number of bits used for address encoding, valid values are 32 and 64. Default = 64.
    kObjectEncodingSize = 7,        // Unsigned integer value: defines number of bits used for size_t encoding, valid values are 32 and 64. Default = 64.
    kHandleEncodingSize = 8         // Unsigned integer value: defines number of bits used for API handle encoding, valid values are 32 and 64. Default = 64.
};

enum PointerAttributes : uint32_t
{
    kIsNull         = 0x01,     // The pointer was null, so the address and data were not encoded.

    // Type of data
    kIsSingle       = 0x02,     // Pointer to a single value.
    kIsArray        = 0x04,     // Pointer to an array of values (can be combined with kIsString or kIsStruct).

    // Type modifiers for pointers to aggregate data types
    kIsString       = 0x08,     // Pointer to a string.
    kIsStruct       = 0x10,     // Pointer to a struct.

    // What was encoded
    kHasAddress     = 0x20,     // The address of the pointer was encoded (always comes before data).
    kHasData        = 0x40,     // The data pointed to was encoded.
};

struct EnabledOptions
{
    CompressionType     compression_type{ kNone };
    bool                record_thread_id{ true };
    bool                record_begin_end_timestamp{ false };
    bool                omit_textures{ false };
    bool                omit_buffers{ false };
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
    uint32_t major_version;     // File format major version.
    uint32_t minor_version;     // File format minor version.
    uint32_t num_options;
};

struct BlockHeader
{
    uint64_t size;
    BlockType type;
};

struct FunctionCallHeader
{
    BlockHeader block_header;
    ApiCallId api_call_id;
};

struct MethodCallHeader
{
    BlockHeader block_header;
    ApiCallId api_call_id;
    uint64_t object_id;
};

struct MetaDataHeader
{
    BlockHeader block_header;
    MetaDataType meta_data_type;
};

#pragma pack(pop)

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_FORMAT_H
