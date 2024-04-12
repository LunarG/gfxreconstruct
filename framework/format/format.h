/*
** Copyright (c) 2018-2022 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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
/// @file Definition of the capture file format.

#ifndef GFXRECON_FORMAT_FORMAT_H
#define GFXRECON_FORMAT_FORMAT_H

#include "format/api_call_id.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/file_path.h"
#include "util/driver_info.h"

#include <cinttypes>
#include <type_traits>

#define GFXRECON_FOURCC GFXRECON_MAKE_FOURCC('G', 'F', 'X', 'R')
#define GFXRECON_FILE_EXTENSION ".gfxr"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(format)

// Types to define encoding sizes.
typedef uint32_t EnumEncodeType;
typedef uint32_t FlagsEncodeType;
typedef uint64_t Flags64EncodeType;
typedef uint32_t SampleMaskEncodeType;
typedef uint64_t HandleEncodeType;
typedef uint64_t DeviceSizeEncodeType;
typedef uint64_t DeviceAddressEncodeType;
typedef uint64_t SizeTEncodeType;
typedef uint64_t AddressEncodeType;
typedef uint8_t  CharEncodeType;  // Encoding type for UTF-8 strings.
typedef uint16_t WCharEncodeType; // Encoding type for LPCWSTR (UTF-16) strings.
typedef uint32_t FormatEncodeType;
typedef uint32_t D3D_FEATURE_LEVELEncodeType;

typedef HandleEncodeType HandleId;
typedef uint64_t         ThreadId;

const uint32_t kCompressedBlockTypeBit    = 0x80000000;
const size_t   kUuidSize                  = 16;
const size_t   kMaxPhysicalDeviceNameSize = 256;
const HandleId kNullHandleId              = 0;
const size_t   kAdapterDescriptionSize    = 128;
const int8_t   kNoneIndex                 = -1;

/// Label for operation annotation, which captures parameters used by tools
/// operating on a capture file.
const char* const kAnnotationLabelOperation       = "operation";
const char* const kAnnotationLabelReplayOptions   = "replayopts";
const char* const kAnnotationLabelRemovedResource = "removed-resource";

const char* const kOperationAnnotationGfxreconstructVersion = "gfxrecon-version";
const char* const kOperationAnnotationVulkanVersion         = "vulkan-version";
const char* const kOperationAnnotationTimestamp             = "timestamp";
const char* const kOperationAnnotationCaptureParameters     = "capture-parameters";

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
    kAnnotation                  = 5,
    kMethodCallBlock             = 6,
    kCompressedMetaDataBlock     = MakeCompressedBlockType(kMetaDataBlock),
    kCompressedFunctionCallBlock = MakeCompressedBlockType(kFunctionCallBlock),
    kCompressedMethodCallBlock   = MakeCompressedBlockType(kMethodCallBlock),
};

enum MarkerType : uint32_t
{
    kUnknownMarker = 0,
    kBeginMarker   = 1,
    kEndMarker     = 2
};

enum AnnotationType : uint32_t
{
    kUnknown = 0,
    kText    = 1,
    kJson    = 2,
    kXml     = 3
};

enum AdapterType
{
    kUnknownAdapter  = 0,
    kSoftwareAdapter = 1,
    kHardwareAdapter = 2
};

enum class MetaDataType : uint16_t
{
    kUnknownMetaDataType                    = 0,
    kDisplayMessageCommand                  = 1,
    kFillMemoryCommand                      = 2,
    kResizeWindowCommand                    = 3,
    kSetSwapchainImageStateCommand          = 4,
    kBeginResourceInitCommand               = 5,
    kEndResourceInitCommand                 = 6,
    kInitBufferCommand                      = 7,
    kInitImageCommand                       = 8,
    kCreateHardwareBufferCommand_deprecated = 9,
    kDestroyHardwareBufferCommand           = 10,
    kSetDevicePropertiesCommand             = 11,
    kSetDeviceMemoryPropertiesCommand       = 12,
    kResizeWindowCommand2                   = 13,
    kSetOpaqueAddressCommand                = 14,
    kSetRayTracingShaderGroupHandlesCommand = 15,
    kCreateHeapAllocationCommand            = 16,
    kInitSubresourceCommand                 = 17,
    kExeFileInfoCommand                     = 18,
    kInitDx12AccelerationStructureCommand   = 19,
    kFillMemoryResourceValueCommand         = 20,
    kDxgiAdapterInfoCommand                 = 21,
    kDriverInfoCommand                      = 22,
    kReserved23                             = 23,
    kCreateHardwareBufferCommand            = 24,
    kReserved25                             = 25,
    kDx12RuntimeInfoCommand                 = 26,
    kParentToChildDependency                = 27,
    kReserved28                             = 28,
    kReserved29                             = 29,
    kReserved30                             = 30,
    kReserved31                             = 31,
};

// MetaDataId is stored in the capture file and its type must be uint32_t to avoid breaking capture file compatibility.
typedef uint32_t MetaDataId;

constexpr uint32_t MakeMetaDataId(ApiFamilyId api_family, MetaDataType meta_data_type)
{
    return ((static_cast<uint32_t>(api_family) << 16) & 0xffff0000) |
           (static_cast<uint32_t>(meta_data_type) & 0x0000ffff);
}

inline ApiFamilyId GetMetaDataApi(MetaDataId meta_data_id)
{
    return static_cast<ApiFamilyId>((meta_data_id >> 16) & 0x0000ffff);
}

inline MetaDataType GetMetaDataType(MetaDataId meta_data_id)
{
    return static_cast<MetaDataType>(meta_data_id & 0x0000ffff);
}

enum CompressionType : uint32_t
{
    kNone = 0,
    kLz4  = 1,
    kZlib = 2,
    kZstd = 3
};

enum FileOption : uint32_t
{
    kUnknownFileOption = 0,
    kCompressionType   = 1, // One of the CompressionType values defining the compression algorithm used with parameter
                            // encoding. Default = CompressionType::kNone.
};

enum PointerAttributes : uint32_t
{
    kIsNull         = 0x0001, // The pointer was null, so the address and data were not encoded.

    // Type of data
    kIsSingle       = 0x0002, // Pointer to a single value.
    kIsArray        = 0x0004, // Pointer to an array of values (can be combined with kIsString or kIsStruct).
    kIsArray2D      = 0x0100, // Pointer to an array of pointers or arrays.

    // Type modifiers for pointers to aggregate data types
    kIsString       = 0x0008, // Pointer to a UTF-8 string.
    kIsWString      = 0x0010, // Pointer to a UTF-16 string.
    kIsStruct       = 0x0020, // Pointer to a struct.

    // What was encoded
    kHasAddress     = 0x0040, // The address of the pointer was encoded (always comes before data).
    kHasData        = 0x0080, // The data pointed to was encoded.
};

enum ResizeWindowPreTransform : uint32_t
{
    kPreTransform0   = 0,
    kPreTransform90  = 1,
    kPreTransform180 = 2,
    kPreTransform270 = 3
};
// clang-format on

struct EnabledOptions
{
    CompressionType compression_type{ CompressionType::kNone };
};

// Resource values are values contained in resource data that may require special handling (e.g., mapping for replay).
enum class ResourceValueType : uint8_t
{
    kUnknown                      = 0,
    kGpuVirtualAddress            = 1,
    kGpuDescriptorHandle          = 2,
    kShaderIdentifier             = 3,
    kIndirectArgumentDispatchRays = 4,
    kExecuteIndirectCountBuffer   = 5
};

#pragma pack(push)
#pragma pack(4)

// Prevent size_t from being used in data structs that will be written to the capture file.
#define size_t \
    static_assert(false, "Capture file data types must be constant size across all platforms. size_t is not allowed.");

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
    format::HandleId object_id;
    format::ThreadId thread_id;
};

struct CompressedMethodCallHeader
{
    BlockHeader      block_header;
    ApiCallId        api_call_id;
    format::HandleId object_id;
    format::ThreadId thread_id;
    uint64_t         uncompressed_size;
};

struct AnnotationHeader
{
    BlockHeader    block_header;
    AnnotationType annotation_type;
    uint32_t       label_length;
    uint64_t       data_length;
};

// Metadata block headers and data types.
struct MetaDataHeader
{
    BlockHeader block_header;
    MetaDataId  meta_data_id; // Encodes ApiFamilyId in upper 2 bytes and MetaDataType in lower 2 bytes.
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

struct FillMemoryResourceValueCommandHeader
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id; // thread_id is here as a placeholder. Currently always set to 0.
    uint64_t         resource_value_count;

    // The data for MapAndFillMemoryCommand will be organized as:
    // map_value_count * ResourceValueType // type of value to map
    // map_value_count * uint64_t          // offset of value to map
};

struct DisplayMessageCommandHeader
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    // NOTE: Message size is determined by subtracting the sizeof(MetaDataId) + sizeof(ThreadId) from
    // BlockHeader::size.  This computed size is the length of the ASCII message string, not including the null
    // terminator.
};

struct DriverInfoBlock
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    char             driver_record[util::filepath::kMaxDriverInfoSize];
};

struct ExeFileInfoBlock
{
    MetaDataHeader           meta_header;
    format::ThreadId         thread_id;
    util::filepath::FileInfo info_record;
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

// Not a header because this command does not include a variable length data payload.
// All of the command data is present in the struct.
struct ResizeWindowCommand2
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    HandleId         surface_id;
    uint32_t         width;
    uint32_t         height;
    uint32_t         pre_transform;
};

// This command header's "usage" member is sized incorrectly.  Existing decoding must remain in place in order to
// process captures that already exist.  Do not use this command header in any new code.
struct CreateHardwareBufferCommandHeader_deprecated
{
    MetaDataHeader meta_header;
    ThreadId       thread_id;
    HandleId       memory_id; // Globally unique ID assigned to the buffer for tracking memory modifications.
    uint64_t       buffer_id; // Address of the buffer object.
    uint32_t       format;
    uint32_t       width;
    uint32_t       height;
    uint32_t       stride; // Size of a row in pixels.
    uint32_t       usage;
    uint32_t       layers;
    uint32_t       planes; // When additional multi-plane data is available, header is followed by 'planes' count
                           // HardwareBufferLayerInfo records.  When unavailable, 'planes' is zero.
};

struct CreateHardwareBufferCommandHeader
{
    MetaDataHeader meta_header;
    ThreadId       thread_id;
    HandleId       memory_id; // Globally unique ID assigned to the buffer for tracking memory modifications.
    uint64_t       buffer_id; // Address of the buffer object.
    uint32_t       format;
    uint32_t       width;
    uint32_t       height;
    uint32_t       stride; // Size of a row in pixels.
    uint64_t       usage;
    uint32_t       layers;
    uint32_t       planes; // When additional multi-plane data is available, header is followed by 'planes' count
                           // HardwareBufferLayerInfo records.  When unavailable, 'planes' is zero.
};

struct HardwareBufferPlaneInfo
{
    uint64_t offset;       // Offset from the start of the memory allocation in bytes.
    uint32_t pixel_stride; // Bytes between pixels.
    uint32_t row_pitch;    // Size of a row in bytes.
};

// Not a header because this command does not include a variable length data payload.
// All of the command data is present in the struct.
struct DestroyHardwareBufferCommand
{
    MetaDataHeader meta_header;
    ThreadId       thread_id;
    uint64_t       buffer_id;
};

struct SetSwapchainImageStateCommandHeader
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId device_id;
    format::HandleId swapchain_id;
    uint32_t         last_presented_image;
    uint32_t         image_info_count;
};

struct SwapchainImageStateInfo
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

struct BeginResourceInitCommand
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId device_id;
    uint64_t         max_resource_size; // Size of largest resource in upload data set.
    uint64_t         max_copy_size;     // Size of largest resource requiring a staging copy at capture.
};

struct EndResourceInitCommand
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId device_id;
};

struct InitBufferCommandHeader
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId device_id;
    format::HandleId buffer_id;
    uint64_t         data_size;
};

struct InitImageCommandHeader
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId device_id;
    format::HandleId image_id;
    uint64_t         data_size;
    uint32_t         aspect;
    uint32_t         layout;
    uint32_t         level_count;
};

struct InitSubresourceCommandHeader
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId device_id;
    format::HandleId resource_id;
    uint32_t         subresource;
    uint32_t         initial_state;
    uint32_t         resource_state;
    uint32_t         barrier_flags;
    uint64_t         data_size;
};

struct SetDeviceMemoryPropertiesCommand
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId physical_device_id;
    uint32_t         memory_type_count;
    uint32_t         memory_heap_count;
};

struct DeviceMemoryType
{
    uint32_t property_flags;
    uint32_t heap_index;
};

struct DeviceMemoryHeap
{
    uint64_t size;
    uint32_t flags;
};

struct SetDevicePropertiesCommand
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId physical_device_id;
    uint32_t         api_version;
    uint32_t         driver_version;
    uint32_t         vendor_id;
    uint32_t         device_id;
    uint32_t         device_type;
    uint8_t          pipeline_cache_uuid[kUuidSize];
    uint32_t         device_name_len;
};

struct SetOpaqueAddressCommand
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId device_id;
    format::HandleId object_id;
    uint64_t         address;
};

struct SetRayTracingShaderGroupHandlesCommandHeader
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId device_id;
    format::HandleId pipeline_id;
    uint64_t         data_size;
};

struct CreateHeapAllocationCommand
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    uint64_t         allocation_id;
    uint64_t         allocation_size;
};

struct InitDx12AccelerationStructureCommandHeader
{
    MetaDataHeader meta_header{};
    ThreadId       thread_id;
    uint64_t       dest_acceleration_structure_data{ 0 };
    uint64_t       copy_source_gpu_va{ 0 };
    uint32_t       copy_mode{ 0 };
    uint32_t       inputs_type{ 0 };
    uint32_t       inputs_flags{ 0 };
    uint32_t       inputs_num_instance_descs{ 0 }; ///< NumDescs for TLAS
    uint32_t       inputs_num_geometry_descs{ 0 }; ///< NumDescs for BLAS
    uint64_t       inputs_data_size{ 0 };

    // In the capture file, accel struct data is written in the following order:
    // InitDx12AccelerationStructureCommandHeader
    // inputs_num_geometry_descs * InitDx12AccelerationStructureGeometryDesc
    // build inputs data
};

struct InitDx12AccelerationStructureGeometryDesc
{
    uint32_t geometry_type{ 0 };
    uint32_t geometry_flags{ 0 };
    uint64_t aabbs_count{ 0 };
    uint64_t aabbs_stride{ 0 };
    uint32_t triangles_has_transform{ false };
    uint32_t triangles_index_format{ 0 };
    uint32_t triangles_vertex_format{ 0 };
    uint32_t triangles_index_count{ 0 }; // 0 if no index buffer
    uint32_t triangles_vertex_count{ 0 };
    uint64_t triangles_vertex_stride{ 0 };
};

struct DxgiAdapterDesc
{
    wchar_t  Description[kAdapterDescriptionSize];
    uint32_t VendorId;
    uint32_t DeviceId;
    uint32_t SubSysId;
    uint32_t Revision;
    uint64_t DedicatedVideoMemory;
    uint64_t DedicatedSystemMemory;
    uint64_t SharedSystemMemory;
    uint32_t LuidLowPart;
    int32_t  LuidHighPart;
    uint32_t extra_info; // 2 bits (LSB) to store Type and 30 bits for object ID
};

struct DxgiAdapterInfoCommandHeader
{
    MetaDataHeader  meta_header;
    ThreadId        thread_id;
    DxgiAdapterDesc adapter_desc;
};

struct Dx12RuntimeInfo
{
    uint32_t version[util::filepath::kFileVersionSize] = {};
    char     src[util::filepath::kMaxFilePropertySize] = {};
};

struct Dx12RuntimeInfoCommandHeader
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    Dx12RuntimeInfo  runtime_info;
};

enum ParentToChildDependencyType : uint32_t
{
    kUnknownDependency                = 0,
    kAccelerationStructuresDependency = 1
};

struct ParentToChildDependencyHeader
{
    MetaDataHeader              meta_header;
    format::ThreadId            thread_id;
    ParentToChildDependencyType dependency_type;
    format::HandleId            parent_id;
    uint32_t                    child_count;
};

// Restore size_t to normal behavior.
#undef size_t

#pragma pack(pop)

GFXRECON_END_NAMESPACE(format)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_FORMAT_FORMAT_H
