/*
** Copyright (c) 2018-2022 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
** Copyright (c) 2023-2025 Advanced Micro Devices, Inc. All rights reserved.
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
#include <concepts>
#include <type_traits>

#define GFXRECON_FOURCC GFXRECON_MAKE_FOURCC('G', 'F', 'X', 'R')
#define GFXRECON_FILE_EXTENSION ".gfxr"

#define GFXRECON_MAKE_FILE_VERSION(major, minor) ((static_cast<uint64_t>(major) << 32) | minor)
#define GFXRECON_CURRENT_FILE_VERSION GFXRECON_MAKE_FILE_VERSION(0, 1)
#define GFXRECON_CURRENT_FILE_MAJOR static_cast<uint32_t>(GFXRECON_CURRENT_FILE_VERSION >> 32)
#define GFXRECON_CURRENT_FILE_MINOR static_cast<uint32_t>(GFXRECON_CURRENT_FILE_VERSION)

// After this version, implicit frame boundaries are ignored
#define GFXRECON_EXPLICIT_FRAME_MARKER_FILE_VERSION GFXRECON_MAKE_FILE_VERSION(0, 1)

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

// The primitives are recorded as themselves. They are named here anyway so that every logical category below selects a
// type from this list, rather than some selecting a typedef and others naming a C type directly.
typedef int8_t   Int8EncodeType;
typedef int16_t  Int16EncodeType;
typedef int32_t  Int32EncodeType;
typedef int64_t  Int64EncodeType;
typedef uint8_t  UInt8EncodeType;
typedef uint16_t UInt16EncodeType;
typedef uint32_t UInt32EncodeType;
typedef uint64_t UInt64EncodeType;
typedef float    FloatEncodeType;
typedef double   DoubleEncodeType;

typedef HandleEncodeType HandleId;
typedef uint64_t         ThreadId;

static_assert(sizeof(EnumEncodeType) == 4);
static_assert(sizeof(FlagsEncodeType) == 4);
static_assert(sizeof(Flags64EncodeType) == 8);
static_assert(sizeof(SampleMaskEncodeType) == 4);
static_assert(sizeof(SizeTEncodeType) == 8);
static_assert(sizeof(DeviceSizeEncodeType) == 8);
static_assert(sizeof(DeviceAddressEncodeType) == 8);
static_assert(sizeof(AddressEncodeType) == 8);
static_assert(sizeof(CharEncodeType) == 1);
static_assert(sizeof(WCharEncodeType) == 2);
static_assert(sizeof(HandleEncodeType) == 8);

// A handle ID is the capture-file identity of an API handle. It is currently a typedef of the handle wire type, so
// an operation may record one as the other.
static_assert(std::is_same_v<HandleId, HandleEncodeType>);

const uint32_t kCompressedBlockTypeBit    = 0x80000000;
const size_t   kUuidSize                  = 16;
const size_t   kMaxPhysicalDeviceNameSize = 256;
const HandleId kNullHandleId              = 0;
const size_t   kAdapterDescriptionSize    = 128;
const int8_t   kNoneIndex                 = -1;

// Layout version of the resource aliasing groups meta-data block.  A reader refuses a block it does not
// know the layout of; a purely additive change goes into a new per-member property instead of a bump.
const uint32_t kResourceAliasingGroupsLayoutVersion = 1;

/// Label for operation annotation, which captures parameters used by tools
/// operating on a capture file.
constexpr char kAnnotationLabelOperation[]           = "operation";
constexpr char kAnnotationLabelReplayOptions[]       = "replayopts";
constexpr char kAnnotationLabelRemovedResource[]     = "removed-resource";
constexpr char kAnnotationLabelRemovedFunctionCall[] = "removed-function-call";
constexpr char kAnnotationLabelTransformer[]         = "transformer";
constexpr char kAnnotationPipelineCreationAttempt[]  = "pipelinecreationattempt";

constexpr char kOperationAnnotationGfxreconstructVersion[] = "gfxrecon-version";
constexpr char kOperationAnnotationVulkanVersion[]         = "vulkan-version";
constexpr char kOperationAnnotationTimestamp[]             = "timestamp";
constexpr char kOperationAnnotationCaptureParameters[]     = "capture-parameters";

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
    kUnknownMetaDataType                                = 0,
    kDisplayMessageCommand                              = 1,
    kFillMemoryCommand                                  = 2,
    kResizeWindowCommand                                = 3,
    kSetSwapchainImageStateCommand                      = 4,
    kBeginResourceInitCommand                           = 5,
    kEndResourceInitCommand                             = 6,
    kInitBufferCommand                                  = 7,
    kInitImageCommand                                   = 8,
    kCreateHardwareBufferCommand_deprecated             = 9,
    kDestroyHardwareBufferCommand                       = 10,
    kSetDevicePropertiesCommand                         = 11,
    kSetDeviceMemoryPropertiesCommand                   = 12,
    kResizeWindowCommand2                               = 13,
    kSetOpaqueAddressCommand                            = 14,
    kSetRayTracingShaderGroupHandlesCommand             = 15,
    kCreateHeapAllocationCommand                        = 16,
    kInitSubresourceCommand                             = 17,
    kExeFileInfoCommand                                 = 18,
    kInitDx12AccelerationStructureCommand_deprecated    = 19,
    kFillMemoryResourceValueCommand                     = 20,
    kDxgiAdapterInfoCommand                             = 21,
    kDriverInfoCommand                                  = 22,
    kReserved23                                         = 23,
    kCreateHardwareBufferCommand_deprecated2            = 24,
    kReserved25                                         = 25,
    kDx12RuntimeInfoCommand                             = 26,
    kParentToChildDependency                            = 27,
    kVulkanBuildAccelerationStructuresCommand           = 28,
    kVulkanCopyAccelerationStructuresCommand            = 29,
    kVulkanWriteAccelerationStructuresPropertiesCommand = 30,
    kReserved31                                         = 31,
    kSetEnvironmentVariablesCommand                     = 32,
    kViewRelativeLocation                               = 33,
    kExecuteBlocksFromFile                              = 34,
    kCreateHardwareBufferCommand                        = 35,
    kInitializeMetaCommand                              = 36,
    kSetOpaqueCaptureDescriptorDataCommand              = 37,
    kInitDx12AccelerationStructureCommand2              = 38,
    kInitTensorCommand                                  = 39,
    kReserved40                                         = 40, // LunarG internal use
    kReserved41                                         = 41, // LunarG internal use
    kReserved42                                         = 42, // LunarG internal use
    kReserved43                                         = 43, // LunarG internal use
    kReserved44                                         = 44, // LunarG internal use
    kReserved45                                         = 45, // LunarG internal use
    kReserved46                                         = 46, // LunarG internal use
    kReserved47                                         = 47, // LunarG internal use
    kResourceAliasingGroupsCommand                      = 48,
    kCaptureStartQueueSubmitIndexCommand                = 49,

    //! reserve values with highest-bit for special purposes
    kBeginExperimentalReservedRange = 1U << 15U
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

// Resource type for members of resource aliasing groups.
enum class ResourceAliasingResourceType : uint32_t
{
    kUnknown = 0,
    kBuffer  = 1,
    kImage   = 2,
    kTensor  = 3,
};

// Per-member properties of a resource aliasing group.
enum class ResourceAliasingPropertyId : uint32_t
{
    kUnknown    = 0,
    kCreateInfo = 1, // The member's create-info, written by the generated struct encoders.
};

// Resource values are values contained in resource data that may require special handling (e.g., mapping for replay).
enum class ResourceValueType : uint8_t
{
    kUnknown                       = 0,
    kGpuVirtualAddress             = 1,
    kGpuDescriptorHandle           = 2,
    kShaderIdentifier              = 3,
    kIndirectArgumentDispatchRays  = 4,
    kExecuteIndirectCountBuffer    = 5,
    kRaytracingInstanceDescPointer = 6,
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

// Written before the trim state of each file that has one. queue_submit_index is the number of
// application queue submissions before the first captured one.
struct CaptureStartQueueSubmitIndexCommand
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    uint64_t         queue_submit_index;
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

struct CreateHardwareBufferCommandHeader_deprecated2
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

struct CreateHardwareBufferCommandHeader
{
    MetaDataHeader meta_header;
    ThreadId       thread_id;
    HandleId       device_id;
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

    // sum of all resource-size in bytes.
    uint64_t total_copy_size;

    // size of single largest resource requiring a staging copy, in bytes.
    uint64_t max_copy_size;
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

struct InitTensorCommandHeader
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId device_id;
    format::HandleId tensor_id;
    uint64_t         data_size;
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

struct SetOpaqueDescriptorDataCommand
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId device_id;
    format::HandleId object_id;
    uint32_t         data_size;
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
    uint32_t       inputs_geometry_descs_size{ 0 };
    uint64_t       inputs_data_size{ 0 };

    // In the capture file, accel struct data is written in the following order:
    // InitDx12AccelerationStructureCommandHeader
    // deprecated: inputs_geometry_descs_size is the numdescs for BLAS.
    // deprecated: inputs_geometry_descs_size * InitDx12AccelerationStructureGeometryDesc
    // now: inputs_geometry_descs_size is the size of the serialized
    // D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS struct. now:
    // D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS struct build inputs data
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
    char16_t Description[kAdapterDescriptionSize];
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

inline int64_t pack_luid(const format::DxgiAdapterDesc& adapter_desc)
{
    return static_cast<int64_t>((static_cast<uint64_t>(adapter_desc.LuidHighPart) << 32) | adapter_desc.LuidLowPart);
}

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

static constexpr char kEnvironmentStringDelimeter = (char)-1;
struct SetEnvironmentVariablesCommand
{
    MetaDataHeader meta_header;
    ThreadId       thread_id;
    uint64_t       string_length;

    // In the capture file, a string will immediately follow this block
    // containing a list of environment variables and their values
};

struct VulkanMetaBuildAccelerationStructuresHeader
{
    format::MetaDataHeader meta_header;
};

struct VulkanWriteAccelerationStructuresPropertiesCommandHeader
{
    format::MetaDataHeader meta_header;
};

struct VulkanCopyAccelerationStructuresCommandHeader
{
    format::MetaDataHeader meta_header;
};

struct ExecuteBlocksFromFile
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;

    // Number of commands to execute from file.
    // 0 means execute till the end of file.
    uint32_t n_blocks;

    // The offset from the start of the file to start executing
    int64_t offset;

    // Number of characters in file name
    uint32_t filename_length;
};

struct ViewRelativeLocation
{
    format::HandleId session_id;
    format::HandleId space_id;

    // Locate status
    uint64_t flags;

    // Orientation
    float qx;
    float qy;
    float qz;
    float qw;

    // Position
    float x;
    float y;
    float z;
};

struct ViewRelativeLocationCmd
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;

    ViewRelativeLocation location;
};

struct InitializeMetaCommand
{
    MetaDataHeader   meta_header{};
    ThreadId         thread_id;
    format::HandleId capture_id;
    uint32_t         block_index{ 0 };
    uint32_t         total_number_of_initializemetacommand{ 0 };
    uint64_t         data_size{ 0 };

    // In the capture file, initialize metacommand data is written in the following order:
    // InitializeMetaCommandHeder
    // parameters data
};

// Groups of resources that alias one another inside a single device memory object, written by
// gfxrecon-optimize after the vkCreateDevice of the device the groups belong to.  In the capture file the
// block is written in the following order:
//   ResourceAliasingGroupsCommandHeader
//   group_count x
//       ResourceAliasingGroupHeader
//       member_count x
//           ResourceAliasingMemberHeader
//           property_count x
//               ResourceAliasingPropertyHeader
//               property_size bytes of property payload
struct ResourceAliasingGroupsCommandHeader
{
    MetaDataHeader   meta_header;
    format::ThreadId thread_id;
    format::HandleId device_id;
    uint32_t         layout_version; // kResourceAliasingGroupsLayoutVersion the block was written with.
    uint32_t         group_count;
};

struct ResourceAliasingGroupHeader
{
    format::HandleId memory_id;    // Capture handle id of the memory the group's members are bound to.
    uint32_t         group_id;     // Identifies the group within the block, >= 1.
    uint32_t         member_count; // >= 2, a group of one is not an alias.
};

struct ResourceAliasingMemberHeader
{
    uint32_t         resource_type; // One of the ResourceAliasingResourceType values.
    uint32_t         property_count;
    format::HandleId resource_id; // Capture handle id of the buffer, image or tensor.
    uint64_t         bind_offset; // Captured memory offset the member was bound at.
};

struct ResourceAliasingPropertyHeader
{
    uint32_t property_id;   // One of the ResourceAliasingPropertyId values.
    uint32_t property_size; // Bytes of payload following this header.
};

// Restore size_t to normal behavior.
#undef size_t

#pragma pack(pop)

// The logical categories follow the wire structures above because the text categories name PointerAttributes. Everything from
// here to the end of the namespace is the category vocabulary; nothing above it depends on it.

// Logical value categories.
//
// Each name above is already a category -- DeviceSizeEncodeType says there is a category called DeviceSize and states its
// width. These tags make that vocabulary addressable, so an operation can dispatch on a category and read the width
// from the category itself rather than restating the join.
//
// A category is not the same question as a type. VkDeviceSize and uint64_t are the same width and the same bytes on the
// wire; the category is what lets a reader tell one from the other. That distinction is the reason these exist.
GFXRECON_BEGIN_NAMESPACE(category)

// Every category derives from this, so an operation can require a category rather than accept any type that happens to
// carry an encode_type. It is what stops Decode<uint32_t> -- the wire type passed where the category belongs, which is
// the mistake this vocabulary exists to prevent.
struct Tag
{};

// Categories sharing the scalar access pattern derive from this, so one concept can select the family while the exact
// category still selects the operation.
struct Scalar : Tag
{};

// Categories sharing text access patterns derive from this.
// Well formed Text categories have a text_attribute and an encode_type
struct Text : Tag
{};

// clang-format off
struct Int8   : Scalar { using encode_type = Int8EncodeType; };
struct Int16  : Scalar { using encode_type = Int16EncodeType; };
struct Int32  : Scalar { using encode_type = Int32EncodeType; };
struct Int64  : Scalar { using encode_type = Int64EncodeType; };
struct UInt8  : Scalar { using encode_type = UInt8EncodeType; };
struct UInt16 : Scalar { using encode_type = UInt16EncodeType; };
struct UInt32 : Scalar { using encode_type = UInt32EncodeType; };
struct UInt64 : Scalar { using encode_type = UInt64EncodeType; };
struct Float  : Scalar { using encode_type = FloatEncodeType; };
struct Double : Scalar { using encode_type = DoubleEncodeType; };

// Text reaches an operation through a string decoder rather than a value or pointer one, so like a handle its
// access pattern differs from a scalar's and it does not derive from Scalar. No API field is a single character
// either: text is always an array, a pointer, or a run of pointers.
struct Char  : Text { using encode_type = CharEncodeType; constexpr static PointerAttributes text_attribute = PointerAttributes::kIsString; };
struct WChar : Text { using encode_type = WCharEncodeType; constexpr static PointerAttributes text_attribute = PointerAttributes::kIsWString; };
struct SizeT         : Scalar { using encode_type = SizeTEncodeType; };
struct Enum          : Scalar { using encode_type = EnumEncodeType; };
struct Flags         : Scalar { using encode_type = FlagsEncodeType; };
struct Flags64       : Scalar { using encode_type = Flags64EncodeType; };
struct SampleMask    : Scalar { using encode_type = SampleMaskEncodeType; };
struct DeviceSize    : Scalar { using encode_type = DeviceSizeEncodeType; };
struct DeviceAddress : Scalar { using encode_type = DeviceAddressEncodeType; };
struct Format        : Scalar { using encode_type = FormatEncodeType; };

// An opaque type: one the API declares and never describes, a platform structure such as ANativeWindow or a platform
// handle typedef such as HWND. A member of one, or a pointer to one, is recorded as a 64-bit address and never
// followed. Like a handle it records an identifier, so it does not derive from Scalar.
struct Opaque   : Tag { using encode_type = AddressEncodeType; };

// A function pointer, the registry's funcpointer category: recorded as a 64-bit address.
struct Callback : Tag { using encode_type = AddressEncodeType; };

// A handle records the capture-file identifier rather than the handle itself, so its access pattern differs from a
// scalar's and it does not derive from Scalar.
struct Handle : Tag { using encode_type = HandleEncodeType; };

#if defined(D3D12_SUPPORT)
struct D3D_FEATURE_LEVEL : Scalar { using encode_type = D3D_FEATURE_LEVELEncodeType; };
#endif
// clang-format on

// No encode_type on purpose. An aggregate is expanded field by field and a void has no bytes of its own, so naming
// a width for either would be a lie. Asking one of these for its encode_type is a substitution failure, which is
// how an operation declines a category it has no wire form for.
struct Struct : Tag
{};

struct Void : Tag
{};

GFXRECON_END_NAMESPACE(category)

template <typename Category>
concept IsCategory = std::derived_from<Category, category::Tag>;
template <typename Category>
concept IsScalarCategory = std::derived_from<Category, category::Scalar>;

// One predicate per category or family, so a layer above asks which category a field has without spelling the tag. The
// single categories are identity tests today; if one grows children, its predicate becomes a derived_from and no
// consumer changes.
template <typename Category>
concept IsHandleCategory = std::same_as<Category, category::Handle>;
template <typename Category>
concept IsStructCategory = std::same_as<Category, category::Struct>;
template <typename Category>
concept IsOpaqueCategory = std::same_as<Category, category::Opaque>;
template <typename Category>
concept IsCallbackCategory = std::same_as<Category, category::Callback>;

// A category with a wire form. Struct and Void are categories and satisfy IsCategory, but neither has bytes of its own, so an
// operation that needs a width constrains on this and declines them by name rather than by a missing member.
template <typename Category>
concept HasEncodeType = IsCategory<Category> && requires
{
    typename Category::encode_type;
};

// A text category has a wire form and a text_attribute that names the character type
template <typename Category>
concept IsTextCategory = std::derived_from<Category, category::Text> && HasEncodeType<Category> && requires
{
    Category::text_attribute;
};

// The wire type a category is recorded as. Written this way so a dependent context reads EncodeTypeFor<K> rather than
// typename K::encode_type; it adds nothing else.
template <HasEncodeType Category>
using EncodeTypeFor = typename Category::encode_type;

GFXRECON_END_NAMESPACE(format)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_FORMAT_FORMAT_H
