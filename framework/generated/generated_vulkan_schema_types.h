/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef  GFXRECON_GENERATED_VULKAN_SCHEMA_TYPES_H
#define  GFXRECON_GENERATED_VULKAN_SCHEMA_TYPES_H

#include "format/format.h"
#include "format/platform_types.h"
#include "util/defines.h"
#include "util/type_list.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#ifdef WIN32
#ifdef CreateEvent
#undef CreateEvent
#endif
#ifdef CreateSemaphore
#undef CreateSemaphore
#endif
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

// API type descriptors. A descriptor carries the API's own type for one element and the logical kind
// that names its Encode and Decode operation. It carries no wire representation type and no decoded
// representation; each kind in format/format.h carries the wire type it is recorded as.
GFXRECON_BEGIN_NAMESPACE(vulkan)
GFXRECON_BEGIN_NAMESPACE(api_types)
struct Char { using element_type = char; using kind = format::kind::Char; };
struct ExternalObject { using element_type = void*; using kind = format::kind::Address; };
struct Float { using element_type = float; using kind = format::kind::Float; };
struct GenericHandle { using element_type = uint64_t; using kind = format::kind::Handle; };
struct Int { using element_type = int; using kind = format::kind::Int32; };
struct Int16 { using element_type = int16_t; using kind = format::kind::Int16; };
struct Int32 { using element_type = int32_t; using kind = format::kind::Int32; };
struct Int64 { using element_type = int64_t; using kind = format::kind::Int64; };
struct Int8 { using element_type = int8_t; using kind = format::kind::Int8; };
struct OpaqueBytes { using element_type = uint8_t; using kind = format::kind::UInt8; };
struct PFN_vkAllocationFunction { using element_type = ::PFN_vkAllocationFunction; using kind = format::kind::Address; };
struct PFN_vkDebugReportCallbackEXT { using element_type = ::PFN_vkDebugReportCallbackEXT; using kind = format::kind::Address; };
struct PFN_vkDebugUtilsMessengerCallbackEXT { using element_type = ::PFN_vkDebugUtilsMessengerCallbackEXT; using kind = format::kind::Address; };
struct PFN_vkDeviceMemoryReportCallbackEXT { using element_type = ::PFN_vkDeviceMemoryReportCallbackEXT; using kind = format::kind::Address; };
struct PFN_vkFreeFunction { using element_type = ::PFN_vkFreeFunction; using kind = format::kind::Address; };
struct PFN_vkGetInstanceProcAddrLUNARG { using element_type = ::PFN_vkGetInstanceProcAddrLUNARG; using kind = format::kind::Address; };
struct PFN_vkInternalAllocationNotification { using element_type = ::PFN_vkInternalAllocationNotification; using kind = format::kind::Address; };
struct PFN_vkInternalFreeNotification { using element_type = ::PFN_vkInternalFreeNotification; using kind = format::kind::Address; };
struct PFN_vkReallocationFunction { using element_type = ::PFN_vkReallocationFunction; using kind = format::kind::Address; };
struct SECURITY_ATTRIBUTES { using element_type = ::SECURITY_ATTRIBUTES; using kind = format::kind::Struct; };
struct Size { using element_type = size_t; using kind = format::kind::SizeT; };
struct StdVideoAV1CDEF { using element_type = ::StdVideoAV1CDEF; using kind = format::kind::Struct; };
struct StdVideoAV1ChromaSamplePosition { using element_type = ::StdVideoAV1ChromaSamplePosition; using kind = format::kind::Enum; };
struct StdVideoAV1ColorConfig { using element_type = ::StdVideoAV1ColorConfig; using kind = format::kind::Struct; };
struct StdVideoAV1ColorConfigFlags { using element_type = ::StdVideoAV1ColorConfigFlags; using kind = format::kind::Struct; };
struct StdVideoAV1ColorPrimaries { using element_type = ::StdVideoAV1ColorPrimaries; using kind = format::kind::Enum; };
struct StdVideoAV1FilmGrain { using element_type = ::StdVideoAV1FilmGrain; using kind = format::kind::Struct; };
struct StdVideoAV1FilmGrainFlags { using element_type = ::StdVideoAV1FilmGrainFlags; using kind = format::kind::Struct; };
struct StdVideoAV1FrameRestorationType { using element_type = ::StdVideoAV1FrameRestorationType; using kind = format::kind::Enum; };
struct StdVideoAV1FrameType { using element_type = ::StdVideoAV1FrameType; using kind = format::kind::Enum; };
struct StdVideoAV1GlobalMotion { using element_type = ::StdVideoAV1GlobalMotion; using kind = format::kind::Struct; };
struct StdVideoAV1InterpolationFilter { using element_type = ::StdVideoAV1InterpolationFilter; using kind = format::kind::Enum; };
struct StdVideoAV1Level { using element_type = ::StdVideoAV1Level; using kind = format::kind::Enum; };
struct StdVideoAV1LoopFilter { using element_type = ::StdVideoAV1LoopFilter; using kind = format::kind::Struct; };
struct StdVideoAV1LoopFilterFlags { using element_type = ::StdVideoAV1LoopFilterFlags; using kind = format::kind::Struct; };
struct StdVideoAV1LoopRestoration { using element_type = ::StdVideoAV1LoopRestoration; using kind = format::kind::Struct; };
struct StdVideoAV1MatrixCoefficients { using element_type = ::StdVideoAV1MatrixCoefficients; using kind = format::kind::Enum; };
struct StdVideoAV1Profile { using element_type = ::StdVideoAV1Profile; using kind = format::kind::Enum; };
struct StdVideoAV1Quantization { using element_type = ::StdVideoAV1Quantization; using kind = format::kind::Struct; };
struct StdVideoAV1QuantizationFlags { using element_type = ::StdVideoAV1QuantizationFlags; using kind = format::kind::Struct; };
struct StdVideoAV1Segmentation { using element_type = ::StdVideoAV1Segmentation; using kind = format::kind::Struct; };
struct StdVideoAV1SequenceHeader { using element_type = ::StdVideoAV1SequenceHeader; using kind = format::kind::Struct; };
struct StdVideoAV1SequenceHeaderFlags { using element_type = ::StdVideoAV1SequenceHeaderFlags; using kind = format::kind::Struct; };
struct StdVideoAV1TileInfo { using element_type = ::StdVideoAV1TileInfo; using kind = format::kind::Struct; };
struct StdVideoAV1TileInfoFlags { using element_type = ::StdVideoAV1TileInfoFlags; using kind = format::kind::Struct; };
struct StdVideoAV1TimingInfo { using element_type = ::StdVideoAV1TimingInfo; using kind = format::kind::Struct; };
struct StdVideoAV1TimingInfoFlags { using element_type = ::StdVideoAV1TimingInfoFlags; using kind = format::kind::Struct; };
struct StdVideoAV1TransferCharacteristics { using element_type = ::StdVideoAV1TransferCharacteristics; using kind = format::kind::Enum; };
struct StdVideoAV1TxMode { using element_type = ::StdVideoAV1TxMode; using kind = format::kind::Enum; };
struct StdVideoDecodeAV1PictureInfo { using element_type = ::StdVideoDecodeAV1PictureInfo; using kind = format::kind::Struct; };
struct StdVideoDecodeAV1PictureInfoFlags { using element_type = ::StdVideoDecodeAV1PictureInfoFlags; using kind = format::kind::Struct; };
struct StdVideoDecodeAV1ReferenceInfo { using element_type = ::StdVideoDecodeAV1ReferenceInfo; using kind = format::kind::Struct; };
struct StdVideoDecodeAV1ReferenceInfoFlags { using element_type = ::StdVideoDecodeAV1ReferenceInfoFlags; using kind = format::kind::Struct; };
struct StdVideoDecodeH264PictureInfo { using element_type = ::StdVideoDecodeH264PictureInfo; using kind = format::kind::Struct; };
struct StdVideoDecodeH264PictureInfoFlags { using element_type = ::StdVideoDecodeH264PictureInfoFlags; using kind = format::kind::Struct; };
struct StdVideoDecodeH264ReferenceInfo { using element_type = ::StdVideoDecodeH264ReferenceInfo; using kind = format::kind::Struct; };
struct StdVideoDecodeH264ReferenceInfoFlags { using element_type = ::StdVideoDecodeH264ReferenceInfoFlags; using kind = format::kind::Struct; };
struct StdVideoDecodeVP9PictureInfo { using element_type = ::StdVideoDecodeVP9PictureInfo; using kind = format::kind::Struct; };
struct StdVideoDecodeVP9PictureInfoFlags { using element_type = ::StdVideoDecodeVP9PictureInfoFlags; using kind = format::kind::Struct; };
struct StdVideoEncodeAV1DecoderModelInfo { using element_type = ::StdVideoEncodeAV1DecoderModelInfo; using kind = format::kind::Struct; };
struct StdVideoEncodeAV1ExtensionHeader { using element_type = ::StdVideoEncodeAV1ExtensionHeader; using kind = format::kind::Struct; };
struct StdVideoEncodeAV1OperatingPointInfo { using element_type = ::StdVideoEncodeAV1OperatingPointInfo; using kind = format::kind::Struct; };
struct StdVideoEncodeAV1OperatingPointInfoFlags { using element_type = ::StdVideoEncodeAV1OperatingPointInfoFlags; using kind = format::kind::Struct; };
struct StdVideoEncodeAV1PictureInfo { using element_type = ::StdVideoEncodeAV1PictureInfo; using kind = format::kind::Struct; };
struct StdVideoEncodeAV1PictureInfoFlags { using element_type = ::StdVideoEncodeAV1PictureInfoFlags; using kind = format::kind::Struct; };
struct StdVideoEncodeAV1ReferenceInfo { using element_type = ::StdVideoEncodeAV1ReferenceInfo; using kind = format::kind::Struct; };
struct StdVideoEncodeAV1ReferenceInfoFlags { using element_type = ::StdVideoEncodeAV1ReferenceInfoFlags; using kind = format::kind::Struct; };
struct StdVideoEncodeH264PictureInfo { using element_type = ::StdVideoEncodeH264PictureInfo; using kind = format::kind::Struct; };
struct StdVideoEncodeH264PictureInfoFlags { using element_type = ::StdVideoEncodeH264PictureInfoFlags; using kind = format::kind::Struct; };
struct StdVideoEncodeH264RefListModEntry { using element_type = ::StdVideoEncodeH264RefListModEntry; using kind = format::kind::Struct; };
struct StdVideoEncodeH264RefPicMarkingEntry { using element_type = ::StdVideoEncodeH264RefPicMarkingEntry; using kind = format::kind::Struct; };
struct StdVideoEncodeH264ReferenceInfo { using element_type = ::StdVideoEncodeH264ReferenceInfo; using kind = format::kind::Struct; };
struct StdVideoEncodeH264ReferenceInfoFlags { using element_type = ::StdVideoEncodeH264ReferenceInfoFlags; using kind = format::kind::Struct; };
struct StdVideoEncodeH264ReferenceListsInfo { using element_type = ::StdVideoEncodeH264ReferenceListsInfo; using kind = format::kind::Struct; };
struct StdVideoEncodeH264ReferenceListsInfoFlags { using element_type = ::StdVideoEncodeH264ReferenceListsInfoFlags; using kind = format::kind::Struct; };
struct StdVideoEncodeH264SliceHeader { using element_type = ::StdVideoEncodeH264SliceHeader; using kind = format::kind::Struct; };
struct StdVideoEncodeH264SliceHeaderFlags { using element_type = ::StdVideoEncodeH264SliceHeaderFlags; using kind = format::kind::Struct; };
struct StdVideoEncodeH264WeightTable { using element_type = ::StdVideoEncodeH264WeightTable; using kind = format::kind::Struct; };
struct StdVideoEncodeH264WeightTableFlags { using element_type = ::StdVideoEncodeH264WeightTableFlags; using kind = format::kind::Struct; };
struct StdVideoH264AspectRatioIdc { using element_type = ::StdVideoH264AspectRatioIdc; using kind = format::kind::Enum; };
struct StdVideoH264CabacInitIdc { using element_type = ::StdVideoH264CabacInitIdc; using kind = format::kind::Enum; };
struct StdVideoH264ChromaFormatIdc { using element_type = ::StdVideoH264ChromaFormatIdc; using kind = format::kind::Enum; };
struct StdVideoH264DisableDeblockingFilterIdc { using element_type = ::StdVideoH264DisableDeblockingFilterIdc; using kind = format::kind::Enum; };
struct StdVideoH264HrdParameters { using element_type = ::StdVideoH264HrdParameters; using kind = format::kind::Struct; };
struct StdVideoH264LevelIdc { using element_type = ::StdVideoH264LevelIdc; using kind = format::kind::Enum; };
struct StdVideoH264MemMgmtControlOp { using element_type = ::StdVideoH264MemMgmtControlOp; using kind = format::kind::Enum; };
struct StdVideoH264ModificationOfPicNumsIdc { using element_type = ::StdVideoH264ModificationOfPicNumsIdc; using kind = format::kind::Enum; };
struct StdVideoH264PictureParameterSet { using element_type = ::StdVideoH264PictureParameterSet; using kind = format::kind::Struct; };
struct StdVideoH264PictureType { using element_type = ::StdVideoH264PictureType; using kind = format::kind::Enum; };
struct StdVideoH264PocType { using element_type = ::StdVideoH264PocType; using kind = format::kind::Enum; };
struct StdVideoH264PpsFlags { using element_type = ::StdVideoH264PpsFlags; using kind = format::kind::Struct; };
struct StdVideoH264ProfileIdc { using element_type = ::StdVideoH264ProfileIdc; using kind = format::kind::Enum; };
struct StdVideoH264ScalingLists { using element_type = ::StdVideoH264ScalingLists; using kind = format::kind::Struct; };
struct StdVideoH264SequenceParameterSet { using element_type = ::StdVideoH264SequenceParameterSet; using kind = format::kind::Struct; };
struct StdVideoH264SequenceParameterSetVui { using element_type = ::StdVideoH264SequenceParameterSetVui; using kind = format::kind::Struct; };
struct StdVideoH264SliceType { using element_type = ::StdVideoH264SliceType; using kind = format::kind::Enum; };
struct StdVideoH264SpsFlags { using element_type = ::StdVideoH264SpsFlags; using kind = format::kind::Struct; };
struct StdVideoH264SpsVuiFlags { using element_type = ::StdVideoH264SpsVuiFlags; using kind = format::kind::Struct; };
struct StdVideoH264WeightedBipredIdc { using element_type = ::StdVideoH264WeightedBipredIdc; using kind = format::kind::Enum; };
struct StdVideoVP9ColorConfig { using element_type = ::StdVideoVP9ColorConfig; using kind = format::kind::Struct; };
struct StdVideoVP9ColorConfigFlags { using element_type = ::StdVideoVP9ColorConfigFlags; using kind = format::kind::Struct; };
struct StdVideoVP9ColorSpace { using element_type = ::StdVideoVP9ColorSpace; using kind = format::kind::Enum; };
struct StdVideoVP9FrameType { using element_type = ::StdVideoVP9FrameType; using kind = format::kind::Enum; };
struct StdVideoVP9InterpolationFilter { using element_type = ::StdVideoVP9InterpolationFilter; using kind = format::kind::Enum; };
struct StdVideoVP9Level { using element_type = ::StdVideoVP9Level; using kind = format::kind::Enum; };
struct StdVideoVP9LoopFilter { using element_type = ::StdVideoVP9LoopFilter; using kind = format::kind::Struct; };
struct StdVideoVP9LoopFilterFlags { using element_type = ::StdVideoVP9LoopFilterFlags; using kind = format::kind::Struct; };
struct StdVideoVP9Profile { using element_type = ::StdVideoVP9Profile; using kind = format::kind::Enum; };
struct StdVideoVP9Segmentation { using element_type = ::StdVideoVP9Segmentation; using kind = format::kind::Struct; };
struct StdVideoVP9SegmentationFlags { using element_type = ::StdVideoVP9SegmentationFlags; using kind = format::kind::Struct; };
struct UInt16 { using element_type = uint16_t; using kind = format::kind::UInt16; };
struct UInt32 { using element_type = uint32_t; using kind = format::kind::UInt32; };
struct UInt64 { using element_type = uint64_t; using kind = format::kind::UInt64; };
struct UInt8 { using element_type = uint8_t; using kind = format::kind::UInt8; };
struct VkAabbPositionsKHR { using element_type = ::VkAabbPositionsKHR; using kind = format::kind::Struct; };
struct VkAccelerationStructureBuildGeometryInfoKHR { using element_type = ::VkAccelerationStructureBuildGeometryInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR; };
struct VkAccelerationStructureBuildRangeInfoKHR { using element_type = ::VkAccelerationStructureBuildRangeInfoKHR; using kind = format::kind::Struct; };
struct VkAccelerationStructureBuildSizesInfoKHR { using element_type = ::VkAccelerationStructureBuildSizesInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR; };
struct VkAccelerationStructureBuildTypeKHR { using element_type = ::VkAccelerationStructureBuildTypeKHR; using kind = format::kind::Enum; };
struct VkAccelerationStructureCaptureDescriptorDataInfoEXT { using element_type = ::VkAccelerationStructureCaptureDescriptorDataInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT; };
struct VkAccelerationStructureCompatibilityKHR { using element_type = ::VkAccelerationStructureCompatibilityKHR; using kind = format::kind::Enum; };
struct VkAccelerationStructureCreateFlagsKHR { using element_type = ::VkAccelerationStructureCreateFlagsKHR; using kind = format::kind::Flags; };
struct VkAccelerationStructureCreateInfo2KHR { using element_type = ::VkAccelerationStructureCreateInfo2KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_2_KHR; };
struct VkAccelerationStructureCreateInfoKHR { using element_type = ::VkAccelerationStructureCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR; };
struct VkAccelerationStructureCreateInfoNV { using element_type = ::VkAccelerationStructureCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV; };
struct VkAccelerationStructureDeviceAddressInfoKHR { using element_type = ::VkAccelerationStructureDeviceAddressInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR; };
struct VkAccelerationStructureGeometryAabbsDataKHR { using element_type = ::VkAccelerationStructureGeometryAabbsDataKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR; };
struct VkAccelerationStructureGeometryInstancesDataKHR { using element_type = ::VkAccelerationStructureGeometryInstancesDataKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR; };
struct VkAccelerationStructureGeometryKHR { using element_type = ::VkAccelerationStructureGeometryKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR; };
struct VkAccelerationStructureGeometryLinearSweptSpheresDataNV { using element_type = ::VkAccelerationStructureGeometryLinearSweptSpheresDataNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV; };
struct VkAccelerationStructureGeometryMicromapDataKHR { using element_type = ::VkAccelerationStructureGeometryMicromapDataKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MICROMAP_DATA_KHR; };
struct VkAccelerationStructureGeometryMotionTrianglesDataNV { using element_type = ::VkAccelerationStructureGeometryMotionTrianglesDataNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV; };
struct VkAccelerationStructureGeometrySpheresDataNV { using element_type = ::VkAccelerationStructureGeometrySpheresDataNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV; };
struct VkAccelerationStructureGeometryTrianglesDataKHR { using element_type = ::VkAccelerationStructureGeometryTrianglesDataKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR; };
struct VkAccelerationStructureInfoNV { using element_type = ::VkAccelerationStructureInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV; };
struct VkAccelerationStructureInstanceKHR { using element_type = ::VkAccelerationStructureInstanceKHR; using kind = format::kind::Struct; };
struct VkAccelerationStructureKHR { using element_type = ::VkAccelerationStructureKHR; using kind = format::kind::Handle; };
struct VkAccelerationStructureMatrixMotionInstanceNV { using element_type = ::VkAccelerationStructureMatrixMotionInstanceNV; using kind = format::kind::Struct; };
struct VkAccelerationStructureMemoryRequirementsInfoNV { using element_type = ::VkAccelerationStructureMemoryRequirementsInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV; };
struct VkAccelerationStructureMemoryRequirementsTypeNV { using element_type = ::VkAccelerationStructureMemoryRequirementsTypeNV; using kind = format::kind::Enum; };
struct VkAccelerationStructureMotionInfoFlagsNV { using element_type = ::VkAccelerationStructureMotionInfoFlagsNV; using kind = format::kind::Flags; };
struct VkAccelerationStructureMotionInfoNV { using element_type = ::VkAccelerationStructureMotionInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV; };
struct VkAccelerationStructureNV { using element_type = ::VkAccelerationStructureNV; using kind = format::kind::Handle; };
struct VkAccelerationStructureSRTMotionInstanceNV { using element_type = ::VkAccelerationStructureSRTMotionInstanceNV; using kind = format::kind::Struct; };
struct VkAccelerationStructureTrianglesDisplacementMicromapNV { using element_type = ::VkAccelerationStructureTrianglesDisplacementMicromapNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV; };
struct VkAccelerationStructureTrianglesOpacityMicromapEXT { using element_type = ::VkAccelerationStructureTrianglesOpacityMicromapEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT; };
struct VkAccelerationStructureTrianglesOpacityMicromapKHR { using element_type = ::VkAccelerationStructureTrianglesOpacityMicromapKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_KHR; };
struct VkAccelerationStructureTypeKHR { using element_type = ::VkAccelerationStructureTypeKHR; using kind = format::kind::Enum; };
struct VkAccelerationStructureVersionInfoKHR { using element_type = ::VkAccelerationStructureVersionInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR; };
struct VkAccessFlags { using element_type = ::VkAccessFlags; using kind = format::kind::Flags; };
struct VkAccessFlags2 { using element_type = ::VkAccessFlags2; using kind = format::kind::Flags64; };
struct VkAccessFlags3KHR { using element_type = ::VkAccessFlags3KHR; using kind = format::kind::Flags64; };
struct VkAcquireNextImageInfoKHR { using element_type = ::VkAcquireNextImageInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR; };
struct VkAcquireProfilingLockFlagsKHR { using element_type = ::VkAcquireProfilingLockFlagsKHR; using kind = format::kind::Flags; };
struct VkAcquireProfilingLockInfoKHR { using element_type = ::VkAcquireProfilingLockInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR; };
struct VkAddressCommandFlagsKHR { using element_type = ::VkAddressCommandFlagsKHR; using kind = format::kind::Flags; };
struct VkAddressCopyFlagsKHR { using element_type = ::VkAddressCopyFlagsKHR; using kind = format::kind::Flags; };
struct VkAllocationCallbacks { using element_type = ::VkAllocationCallbacks; using kind = format::kind::Struct; };
struct VkAmigoProfilingSubmitInfoSEC { using element_type = ::VkAmigoProfilingSubmitInfoSEC; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC; };
struct VkAndroidHardwareBufferFormatProperties2ANDROID { using element_type = ::VkAndroidHardwareBufferFormatProperties2ANDROID; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID; };
struct VkAndroidHardwareBufferFormatPropertiesANDROID { using element_type = ::VkAndroidHardwareBufferFormatPropertiesANDROID; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID; };
struct VkAndroidHardwareBufferFormatResolvePropertiesANDROID { using element_type = ::VkAndroidHardwareBufferFormatResolvePropertiesANDROID; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID; };
struct VkAndroidHardwareBufferPropertiesANDROID { using element_type = ::VkAndroidHardwareBufferPropertiesANDROID; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID; };
struct VkAndroidHardwareBufferUsageANDROID { using element_type = ::VkAndroidHardwareBufferUsageANDROID; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID; };
struct VkAndroidSurfaceCreateFlagsKHR { using element_type = ::VkAndroidSurfaceCreateFlagsKHR; using kind = format::kind::Flags; };
struct VkAndroidSurfaceCreateInfoKHR { using element_type = ::VkAndroidSurfaceCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR; };
struct VkAntiLagDataAMD { using element_type = ::VkAntiLagDataAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ANTI_LAG_DATA_AMD; };
struct VkAntiLagModeAMD { using element_type = ::VkAntiLagModeAMD; using kind = format::kind::Enum; };
struct VkAntiLagPresentationInfoAMD { using element_type = ::VkAntiLagPresentationInfoAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ANTI_LAG_PRESENTATION_INFO_AMD; };
struct VkAntiLagStageAMD { using element_type = ::VkAntiLagStageAMD; using kind = format::kind::Enum; };
struct VkApplicationInfo { using element_type = ::VkApplicationInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_APPLICATION_INFO; };
struct VkAttachmentDescription { using element_type = ::VkAttachmentDescription; using kind = format::kind::Struct; };
struct VkAttachmentDescription2 { using element_type = ::VkAttachmentDescription2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2; };
struct VkAttachmentDescriptionFlags { using element_type = ::VkAttachmentDescriptionFlags; using kind = format::kind::Flags; };
struct VkAttachmentDescriptionStencilLayout { using element_type = ::VkAttachmentDescriptionStencilLayout; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT; };
struct VkAttachmentFeedbackLoopInfoEXT { using element_type = ::VkAttachmentFeedbackLoopInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT; };
struct VkAttachmentLoadOp { using element_type = ::VkAttachmentLoadOp; using kind = format::kind::Enum; };
struct VkAttachmentReference { using element_type = ::VkAttachmentReference; using kind = format::kind::Struct; };
struct VkAttachmentReference2 { using element_type = ::VkAttachmentReference2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2; };
struct VkAttachmentReferenceStencilLayout { using element_type = ::VkAttachmentReferenceStencilLayout; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT; };
struct VkAttachmentSampleCountInfoAMD { using element_type = ::VkAttachmentSampleCountInfoAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD; };
struct VkAttachmentSampleLocationsEXT { using element_type = ::VkAttachmentSampleLocationsEXT; using kind = format::kind::Struct; };
struct VkAttachmentStoreOp { using element_type = ::VkAttachmentStoreOp; using kind = format::kind::Enum; };
struct VkBaseOutStructure { using element_type = ::VkBaseOutStructure; using kind = format::kind::Struct; };
struct VkBeginCustomResolveInfoEXT { using element_type = ::VkBeginCustomResolveInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BEGIN_CUSTOM_RESOLVE_INFO_EXT; };
struct VkBindAccelerationStructureMemoryInfoNV { using element_type = ::VkBindAccelerationStructureMemoryInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV; };
struct VkBindBufferMemoryDeviceGroupInfo { using element_type = ::VkBindBufferMemoryDeviceGroupInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO; };
struct VkBindBufferMemoryInfo { using element_type = ::VkBindBufferMemoryInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO; };
struct VkBindDataGraphPipelineSessionMemoryInfoARM { using element_type = ::VkBindDataGraphPipelineSessionMemoryInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_DATA_GRAPH_PIPELINE_SESSION_MEMORY_INFO_ARM; };
struct VkBindDescriptorBufferEmbeddedSamplersInfoEXT { using element_type = ::VkBindDescriptorBufferEmbeddedSamplersInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT; };
struct VkBindDescriptorSetsInfo { using element_type = ::VkBindDescriptorSetsInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO; };
struct VkBindImageMemoryDeviceGroupInfo { using element_type = ::VkBindImageMemoryDeviceGroupInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO; };
struct VkBindImageMemoryInfo { using element_type = ::VkBindImageMemoryInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO; };
struct VkBindImageMemorySwapchainInfoKHR { using element_type = ::VkBindImageMemorySwapchainInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR; };
struct VkBindImagePlaneMemoryInfo { using element_type = ::VkBindImagePlaneMemoryInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO; };
struct VkBindIndexBuffer3InfoKHR { using element_type = ::VkBindIndexBuffer3InfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_INDEX_BUFFER_3_INFO_KHR; };
struct VkBindIndexBufferIndirectCommandEXT { using element_type = ::VkBindIndexBufferIndirectCommandEXT; using kind = format::kind::Struct; };
struct VkBindIndexBufferIndirectCommandNV { using element_type = ::VkBindIndexBufferIndirectCommandNV; using kind = format::kind::Struct; };
struct VkBindMemoryStatus { using element_type = ::VkBindMemoryStatus; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS; };
struct VkBindPipelineIndirectCommandNV { using element_type = ::VkBindPipelineIndirectCommandNV; using kind = format::kind::Struct; };
struct VkBindShaderGroupIndirectCommandNV { using element_type = ::VkBindShaderGroupIndirectCommandNV; using kind = format::kind::Struct; };
struct VkBindSparseInfo { using element_type = ::VkBindSparseInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO; };
struct VkBindTensorMemoryInfoARM { using element_type = ::VkBindTensorMemoryInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_TENSOR_MEMORY_INFO_ARM; };
struct VkBindTransformFeedbackBuffer2InfoEXT { using element_type = ::VkBindTransformFeedbackBuffer2InfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_TRANSFORM_FEEDBACK_BUFFER_2_INFO_EXT; };
struct VkBindVertexBuffer3InfoKHR { using element_type = ::VkBindVertexBuffer3InfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_VERTEX_BUFFER_3_INFO_KHR; };
struct VkBindVertexBufferIndirectCommandEXT { using element_type = ::VkBindVertexBufferIndirectCommandEXT; using kind = format::kind::Struct; };
struct VkBindVertexBufferIndirectCommandNV { using element_type = ::VkBindVertexBufferIndirectCommandNV; using kind = format::kind::Struct; };
struct VkBindVideoSessionMemoryInfoKHR { using element_type = ::VkBindVideoSessionMemoryInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR; };
struct VkBlendFactor { using element_type = ::VkBlendFactor; using kind = format::kind::Enum; };
struct VkBlendOp { using element_type = ::VkBlendOp; using kind = format::kind::Enum; };
struct VkBlendOverlapEXT { using element_type = ::VkBlendOverlapEXT; using kind = format::kind::Enum; };
struct VkBlitImageCubicWeightsInfoQCOM { using element_type = ::VkBlitImageCubicWeightsInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM; };
struct VkBlitImageInfo2 { using element_type = ::VkBlitImageInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2; };
struct VkBlockMatchWindowCompareModeQCOM { using element_type = ::VkBlockMatchWindowCompareModeQCOM; using kind = format::kind::Enum; };
struct VkBool32 { using element_type = ::VkBool32; using kind = format::kind::UInt32; };
struct VkBorderColor { using element_type = ::VkBorderColor; using kind = format::kind::Enum; };
struct VkBuffer { using element_type = ::VkBuffer; using kind = format::kind::Handle; };
struct VkBufferCaptureDescriptorDataInfoEXT { using element_type = ::VkBufferCaptureDescriptorDataInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT; };
struct VkBufferCopy { using element_type = ::VkBufferCopy; using kind = format::kind::Struct; };
struct VkBufferCopy2 { using element_type = ::VkBufferCopy2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUFFER_COPY_2; };
struct VkBufferCreateFlags { using element_type = ::VkBufferCreateFlags; using kind = format::kind::Flags; };
struct VkBufferCreateInfo { using element_type = ::VkBufferCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO; };
struct VkBufferDeviceAddressAlignmentAllocateInfoVALVE { using element_type = ::VkBufferDeviceAddressAlignmentAllocateInfoVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_ALIGNMENT_ALLOCATE_INFO_VALVE; };
struct VkBufferDeviceAddressCreateInfoEXT { using element_type = ::VkBufferDeviceAddressCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT; };
struct VkBufferDeviceAddressInfo { using element_type = ::VkBufferDeviceAddressInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO; };
struct VkBufferImageCopy { using element_type = ::VkBufferImageCopy; using kind = format::kind::Struct; };
struct VkBufferImageCopy2 { using element_type = ::VkBufferImageCopy2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2; };
struct VkBufferMemoryBarrier { using element_type = ::VkBufferMemoryBarrier; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER; };
struct VkBufferMemoryBarrier2 { using element_type = ::VkBufferMemoryBarrier2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2; };
struct VkBufferMemoryRequirementsInfo2 { using element_type = ::VkBufferMemoryRequirementsInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2; };
struct VkBufferOpaqueCaptureAddressCreateInfo { using element_type = ::VkBufferOpaqueCaptureAddressCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO; };
struct VkBufferUsageFlags { using element_type = ::VkBufferUsageFlags; using kind = format::kind::Flags; };
struct VkBufferUsageFlags2 { using element_type = ::VkBufferUsageFlags2; using kind = format::kind::Flags64; };
struct VkBufferUsageFlags2CreateInfo { using element_type = ::VkBufferUsageFlags2CreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO; };
struct VkBufferView { using element_type = ::VkBufferView; using kind = format::kind::Handle; };
struct VkBufferViewCreateFlags { using element_type = ::VkBufferViewCreateFlags; using kind = format::kind::Flags; };
struct VkBufferViewCreateInfo { using element_type = ::VkBufferViewCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO; };
struct VkBuildAccelerationStructureFlagsKHR { using element_type = ::VkBuildAccelerationStructureFlagsKHR; using kind = format::kind::Flags; };
struct VkBuildAccelerationStructureModeKHR { using element_type = ::VkBuildAccelerationStructureModeKHR; using kind = format::kind::Enum; };
struct VkBuildMicromapFlagsEXT { using element_type = ::VkBuildMicromapFlagsEXT; using kind = format::kind::Flags; };
struct VkBuildMicromapModeEXT { using element_type = ::VkBuildMicromapModeEXT; using kind = format::kind::Enum; };
struct VkBuildPartitionedAccelerationStructureIndirectCommandNV { using element_type = ::VkBuildPartitionedAccelerationStructureIndirectCommandNV; using kind = format::kind::Struct; };
struct VkBuildPartitionedAccelerationStructureInfoNV { using element_type = ::VkBuildPartitionedAccelerationStructureInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_BUILD_PARTITIONED_ACCELERATION_STRUCTURE_INFO_NV; };
struct VkCalibratedTimestampInfoKHR { using element_type = ::VkCalibratedTimestampInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR; };
struct VkCheckpointData2NV { using element_type = ::VkCheckpointData2NV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV; };
struct VkCheckpointDataNV { using element_type = ::VkCheckpointDataNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV; };
struct VkChromaLocation { using element_type = ::VkChromaLocation; using kind = format::kind::Enum; };
struct VkClearAttachment { using element_type = ::VkClearAttachment; using kind = format::kind::Struct; };
struct VkClearColorValue { using element_type = ::VkClearColorValue; using kind = format::kind::Struct; };
struct VkClearDepthStencilValue { using element_type = ::VkClearDepthStencilValue; using kind = format::kind::Struct; };
struct VkClearRect { using element_type = ::VkClearRect; using kind = format::kind::Struct; };
struct VkClearValue { using element_type = ::VkClearValue; using kind = format::kind::Struct; };
struct VkCoarseSampleLocationNV { using element_type = ::VkCoarseSampleLocationNV; using kind = format::kind::Struct; };
struct VkCoarseSampleOrderCustomNV { using element_type = ::VkCoarseSampleOrderCustomNV; using kind = format::kind::Struct; };
struct VkCoarseSampleOrderTypeNV { using element_type = ::VkCoarseSampleOrderTypeNV; using kind = format::kind::Enum; };
struct VkColorBlendAdvancedEXT { using element_type = ::VkColorBlendAdvancedEXT; using kind = format::kind::Struct; };
struct VkColorBlendEquationEXT { using element_type = ::VkColorBlendEquationEXT; using kind = format::kind::Struct; };
struct VkColorComponentFlags { using element_type = ::VkColorComponentFlags; using kind = format::kind::Flags; };
struct VkColorSpaceKHR { using element_type = ::VkColorSpaceKHR; using kind = format::kind::Enum; };
struct VkCommandBuffer { using element_type = ::VkCommandBuffer; using kind = format::kind::Handle; };
struct VkCommandBufferAllocateInfo { using element_type = ::VkCommandBufferAllocateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO; };
struct VkCommandBufferBeginInfo { using element_type = ::VkCommandBufferBeginInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO; };
struct VkCommandBufferInheritanceConditionalRenderingInfoEXT { using element_type = ::VkCommandBufferInheritanceConditionalRenderingInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT; };
struct VkCommandBufferInheritanceInfo { using element_type = ::VkCommandBufferInheritanceInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO; };
struct VkCommandBufferInheritanceRenderPassTransformInfoQCOM { using element_type = ::VkCommandBufferInheritanceRenderPassTransformInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM; };
struct VkCommandBufferInheritanceRenderingInfo { using element_type = ::VkCommandBufferInheritanceRenderingInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO; };
struct VkCommandBufferInheritanceViewportScissorInfoNV { using element_type = ::VkCommandBufferInheritanceViewportScissorInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV; };
struct VkCommandBufferLevel { using element_type = ::VkCommandBufferLevel; using kind = format::kind::Enum; };
struct VkCommandBufferResetFlags { using element_type = ::VkCommandBufferResetFlags; using kind = format::kind::Flags; };
struct VkCommandBufferSubmitInfo { using element_type = ::VkCommandBufferSubmitInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO; };
struct VkCommandBufferUsageFlags { using element_type = ::VkCommandBufferUsageFlags; using kind = format::kind::Flags; };
struct VkCommandPool { using element_type = ::VkCommandPool; using kind = format::kind::Handle; };
struct VkCommandPoolCreateFlags { using element_type = ::VkCommandPoolCreateFlags; using kind = format::kind::Flags; };
struct VkCommandPoolCreateInfo { using element_type = ::VkCommandPoolCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO; };
struct VkCommandPoolResetFlags { using element_type = ::VkCommandPoolResetFlags; using kind = format::kind::Flags; };
struct VkCommandPoolTrimFlags { using element_type = ::VkCommandPoolTrimFlags; using kind = format::kind::Flags; };
struct VkCompareOp { using element_type = ::VkCompareOp; using kind = format::kind::Enum; };
struct VkComponentMapping { using element_type = ::VkComponentMapping; using kind = format::kind::Struct; };
struct VkComponentSwizzle { using element_type = ::VkComponentSwizzle; using kind = format::kind::Enum; };
struct VkComponentTypeKHR { using element_type = ::VkComponentTypeKHR; using kind = format::kind::Enum; };
struct VkCompositeAlphaFlagBitsKHR { using element_type = ::VkCompositeAlphaFlagBitsKHR; using kind = format::kind::Enum; };
struct VkCompositeAlphaFlagsKHR { using element_type = ::VkCompositeAlphaFlagsKHR; using kind = format::kind::Flags; };
struct VkComputeOccupancyPriorityParametersNV { using element_type = ::VkComputeOccupancyPriorityParametersNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COMPUTE_OCCUPANCY_PRIORITY_PARAMETERS_NV; };
struct VkComputePipelineCreateInfo { using element_type = ::VkComputePipelineCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO; };
struct VkComputePipelineIndirectBufferInfoNV { using element_type = ::VkComputePipelineIndirectBufferInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV; };
struct VkConditionalRenderingBeginInfo2EXT { using element_type = ::VkConditionalRenderingBeginInfo2EXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_2_EXT; };
struct VkConditionalRenderingBeginInfoEXT { using element_type = ::VkConditionalRenderingBeginInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT; };
struct VkConditionalRenderingFlagsEXT { using element_type = ::VkConditionalRenderingFlagsEXT; using kind = format::kind::Flags; };
struct VkConformanceVersion { using element_type = ::VkConformanceVersion; using kind = format::kind::Struct; };
struct VkConservativeRasterizationModeEXT { using element_type = ::VkConservativeRasterizationModeEXT; using kind = format::kind::Enum; };
struct VkConvertCooperativeVectorMatrixInfoNV { using element_type = ::VkConvertCooperativeVectorMatrixInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_CONVERT_COOPERATIVE_VECTOR_MATRIX_INFO_NV; };
struct VkCooperativeMatrixFlagsEXT { using element_type = ::VkCooperativeMatrixFlagsEXT; using kind = format::kind::Flags; };
struct VkCooperativeMatrixFlexibleDimensionsPropertiesNV { using element_type = ::VkCooperativeMatrixFlexibleDimensionsPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV; };
struct VkCooperativeMatrixProperties2EXT { using element_type = ::VkCooperativeMatrixProperties2EXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_2_EXT; };
struct VkCooperativeMatrixPropertiesKHR { using element_type = ::VkCooperativeMatrixPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR; };
struct VkCooperativeMatrixPropertiesNV { using element_type = ::VkCooperativeMatrixPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV; };
struct VkCooperativeVectorMatrixLayoutNV { using element_type = ::VkCooperativeVectorMatrixLayoutNV; using kind = format::kind::Enum; };
struct VkCooperativeVectorPropertiesNV { using element_type = ::VkCooperativeVectorPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COOPERATIVE_VECTOR_PROPERTIES_NV; };
struct VkCopyAccelerationStructureInfoKHR { using element_type = ::VkCopyAccelerationStructureInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR; };
struct VkCopyAccelerationStructureModeKHR { using element_type = ::VkCopyAccelerationStructureModeKHR; using kind = format::kind::Enum; };
struct VkCopyAccelerationStructureToMemoryInfoKHR { using element_type = ::VkCopyAccelerationStructureToMemoryInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR; };
struct VkCopyBufferInfo2 { using element_type = ::VkCopyBufferInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2; };
struct VkCopyBufferToImageInfo2 { using element_type = ::VkCopyBufferToImageInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2; };
struct VkCopyCommandTransformInfoQCOM { using element_type = ::VkCopyCommandTransformInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM; };
struct VkCopyDescriptorSet { using element_type = ::VkCopyDescriptorSet; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET; };
struct VkCopyDeviceMemoryImageInfoKHR { using element_type = ::VkCopyDeviceMemoryImageInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_DEVICE_MEMORY_IMAGE_INFO_KHR; };
struct VkCopyDeviceMemoryInfoKHR { using element_type = ::VkCopyDeviceMemoryInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_DEVICE_MEMORY_INFO_KHR; };
struct VkCopyImageInfo2 { using element_type = ::VkCopyImageInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2; };
struct VkCopyImageToBufferInfo2 { using element_type = ::VkCopyImageToBufferInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2; };
struct VkCopyImageToImageInfo { using element_type = ::VkCopyImageToImageInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO; };
struct VkCopyImageToMemoryInfo { using element_type = ::VkCopyImageToMemoryInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO; };
struct VkCopyMemoryIndirectCommandKHR { using element_type = ::VkCopyMemoryIndirectCommandKHR; using kind = format::kind::Struct; };
struct VkCopyMemoryIndirectInfoKHR { using element_type = ::VkCopyMemoryIndirectInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_MEMORY_INDIRECT_INFO_KHR; };
struct VkCopyMemoryToAccelerationStructureInfoKHR { using element_type = ::VkCopyMemoryToAccelerationStructureInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR; };
struct VkCopyMemoryToImageIndirectCommandKHR { using element_type = ::VkCopyMemoryToImageIndirectCommandKHR; using kind = format::kind::Struct; };
struct VkCopyMemoryToImageIndirectInfoKHR { using element_type = ::VkCopyMemoryToImageIndirectInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INDIRECT_INFO_KHR; };
struct VkCopyMemoryToImageInfo { using element_type = ::VkCopyMemoryToImageInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO; };
struct VkCopyMemoryToMicromapInfoEXT { using element_type = ::VkCopyMemoryToMicromapInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT; };
struct VkCopyMicromapInfoEXT { using element_type = ::VkCopyMicromapInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT; };
struct VkCopyMicromapModeEXT { using element_type = ::VkCopyMicromapModeEXT; using kind = format::kind::Enum; };
struct VkCopyMicromapToMemoryInfoEXT { using element_type = ::VkCopyMicromapToMemoryInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT; };
struct VkCopyTensorInfoARM { using element_type = ::VkCopyTensorInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_COPY_TENSOR_INFO_ARM; };
struct VkCoverageModulationModeNV { using element_type = ::VkCoverageModulationModeNV; using kind = format::kind::Enum; };
struct VkCoverageReductionModeNV { using element_type = ::VkCoverageReductionModeNV; using kind = format::kind::Enum; };
struct VkCubicFilterWeightsQCOM { using element_type = ::VkCubicFilterWeightsQCOM; using kind = format::kind::Enum; };
struct VkCullModeFlags { using element_type = ::VkCullModeFlags; using kind = format::kind::Flags; };
struct VkCustomResolveCreateInfoEXT { using element_type = ::VkCustomResolveCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_CUSTOM_RESOLVE_CREATE_INFO_EXT; };
struct VkD3D12FenceSubmitInfoKHR { using element_type = ::VkD3D12FenceSubmitInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR; };
struct VkDataGraphModelCacheTypeQCOM { using element_type = ::VkDataGraphModelCacheTypeQCOM; using kind = format::kind::Enum; };
struct VkDataGraphOpticalFlowCreateFlagsARM { using element_type = ::VkDataGraphOpticalFlowCreateFlagsARM; using kind = format::kind::Flags; };
struct VkDataGraphOpticalFlowExecuteFlagsARM { using element_type = ::VkDataGraphOpticalFlowExecuteFlagsARM; using kind = format::kind::Flags; };
struct VkDataGraphOpticalFlowGridSizeFlagsARM { using element_type = ::VkDataGraphOpticalFlowGridSizeFlagsARM; using kind = format::kind::Flags; };
struct VkDataGraphOpticalFlowImageFormatInfoARM { using element_type = ::VkDataGraphOpticalFlowImageFormatInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_OPTICAL_FLOW_IMAGE_FORMAT_INFO_ARM; };
struct VkDataGraphOpticalFlowImageFormatPropertiesARM { using element_type = ::VkDataGraphOpticalFlowImageFormatPropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_ARM; };
struct VkDataGraphOpticalFlowImageUsageFlagsARM { using element_type = ::VkDataGraphOpticalFlowImageUsageFlagsARM; using kind = format::kind::Flags; };
struct VkDataGraphOpticalFlowPerformanceLevelARM { using element_type = ::VkDataGraphOpticalFlowPerformanceLevelARM; using kind = format::kind::Enum; };
struct VkDataGraphPipelineBuiltinModelCreateInfoQCOM { using element_type = ::VkDataGraphPipelineBuiltinModelCreateInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_BUILTIN_MODEL_CREATE_INFO_QCOM; };
struct VkDataGraphPipelineCompilerControlCreateInfoARM { using element_type = ::VkDataGraphPipelineCompilerControlCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_COMPILER_CONTROL_CREATE_INFO_ARM; };
struct VkDataGraphPipelineConstantARM { using element_type = ::VkDataGraphPipelineConstantARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_ARM; };
struct VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM { using element_type = ::VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_TENSOR_SEMI_STRUCTURED_SPARSITY_INFO_ARM; };
struct VkDataGraphPipelineCreateInfoARM { using element_type = ::VkDataGraphPipelineCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CREATE_INFO_ARM; };
struct VkDataGraphPipelineDispatchFlagsARM { using element_type = ::VkDataGraphPipelineDispatchFlagsARM; using kind = format::kind::Flags64; };
struct VkDataGraphPipelineDispatchInfoARM { using element_type = ::VkDataGraphPipelineDispatchInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_DISPATCH_INFO_ARM; };
struct VkDataGraphPipelineIdentifierCreateInfoARM { using element_type = ::VkDataGraphPipelineIdentifierCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_IDENTIFIER_CREATE_INFO_ARM; };
struct VkDataGraphPipelineInfoARM { using element_type = ::VkDataGraphPipelineInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_INFO_ARM; };
struct VkDataGraphPipelineNeuralStatisticsCreateInfoARM { using element_type = ::VkDataGraphPipelineNeuralStatisticsCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_NEURAL_STATISTICS_CREATE_INFO_ARM; };
struct VkDataGraphPipelineNodeConnectionTypeARM { using element_type = ::VkDataGraphPipelineNodeConnectionTypeARM; using kind = format::kind::Enum; };
struct VkDataGraphPipelineNodeTypeARM { using element_type = ::VkDataGraphPipelineNodeTypeARM; using kind = format::kind::Enum; };
struct VkDataGraphPipelineOpticalFlowCreateInfoARM { using element_type = ::VkDataGraphPipelineOpticalFlowCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_OPTICAL_FLOW_CREATE_INFO_ARM; };
struct VkDataGraphPipelineOpticalFlowDispatchInfoARM { using element_type = ::VkDataGraphPipelineOpticalFlowDispatchInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_OPTICAL_FLOW_DISPATCH_INFO_ARM; };
struct VkDataGraphPipelinePropertyARM { using element_type = ::VkDataGraphPipelinePropertyARM; using kind = format::kind::Enum; };
struct VkDataGraphPipelinePropertyQueryResultARM { using element_type = ::VkDataGraphPipelinePropertyQueryResultARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_PROPERTY_QUERY_RESULT_ARM; };
struct VkDataGraphPipelineResourceInfoARM { using element_type = ::VkDataGraphPipelineResourceInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM; };
struct VkDataGraphPipelineResourceInfoImageLayoutARM { using element_type = ::VkDataGraphPipelineResourceInfoImageLayoutARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_IMAGE_LAYOUT_ARM; };
struct VkDataGraphPipelineSessionARM { using element_type = ::VkDataGraphPipelineSessionARM; using kind = format::kind::Handle; };
struct VkDataGraphPipelineSessionBindPointARM { using element_type = ::VkDataGraphPipelineSessionBindPointARM; using kind = format::kind::Enum; };
struct VkDataGraphPipelineSessionBindPointRequirementARM { using element_type = ::VkDataGraphPipelineSessionBindPointRequirementARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENT_ARM; };
struct VkDataGraphPipelineSessionBindPointRequirementsInfoARM { using element_type = ::VkDataGraphPipelineSessionBindPointRequirementsInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENTS_INFO_ARM; };
struct VkDataGraphPipelineSessionBindPointTypeARM { using element_type = ::VkDataGraphPipelineSessionBindPointTypeARM; using kind = format::kind::Enum; };
struct VkDataGraphPipelineSessionCreateFlagsARM { using element_type = ::VkDataGraphPipelineSessionCreateFlagsARM; using kind = format::kind::Flags64; };
struct VkDataGraphPipelineSessionCreateInfoARM { using element_type = ::VkDataGraphPipelineSessionCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_CREATE_INFO_ARM; };
struct VkDataGraphPipelineSessionMemoryRequirementsInfoARM { using element_type = ::VkDataGraphPipelineSessionMemoryRequirementsInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_MEMORY_REQUIREMENTS_INFO_ARM; };
struct VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM { using element_type = ::VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_NEURAL_STATISTICS_CREATE_INFO_ARM; };
struct VkDataGraphPipelineShaderModuleCreateInfoARM { using element_type = ::VkDataGraphPipelineShaderModuleCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SHADER_MODULE_CREATE_INFO_ARM; };
struct VkDataGraphPipelineSingleNodeConnectionARM { using element_type = ::VkDataGraphPipelineSingleNodeConnectionARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CONNECTION_ARM; };
struct VkDataGraphPipelineSingleNodeCreateInfoARM { using element_type = ::VkDataGraphPipelineSingleNodeCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CREATE_INFO_ARM; };
struct VkDataGraphProcessingEngineCreateInfoARM { using element_type = ::VkDataGraphProcessingEngineCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DATA_GRAPH_PROCESSING_ENGINE_CREATE_INFO_ARM; };
struct VkDebugMarkerMarkerInfoEXT { using element_type = ::VkDebugMarkerMarkerInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT; };
struct VkDebugMarkerObjectNameInfoEXT { using element_type = ::VkDebugMarkerObjectNameInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT; };
struct VkDebugMarkerObjectTagInfoEXT { using element_type = ::VkDebugMarkerObjectTagInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT; };
struct VkDebugReportCallbackCreateInfoEXT { using element_type = ::VkDebugReportCallbackCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT; };
struct VkDebugReportCallbackEXT { using element_type = ::VkDebugReportCallbackEXT; using kind = format::kind::Handle; };
struct VkDebugReportFlagsEXT { using element_type = ::VkDebugReportFlagsEXT; using kind = format::kind::Flags; };
struct VkDebugReportObjectTypeEXT { using element_type = ::VkDebugReportObjectTypeEXT; using kind = format::kind::Enum; };
struct VkDebugUtilsLabelEXT { using element_type = ::VkDebugUtilsLabelEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT; };
struct VkDebugUtilsMessageSeverityFlagBitsEXT { using element_type = ::VkDebugUtilsMessageSeverityFlagBitsEXT; using kind = format::kind::Enum; };
struct VkDebugUtilsMessageSeverityFlagsEXT { using element_type = ::VkDebugUtilsMessageSeverityFlagsEXT; using kind = format::kind::Flags; };
struct VkDebugUtilsMessageTypeFlagsEXT { using element_type = ::VkDebugUtilsMessageTypeFlagsEXT; using kind = format::kind::Flags; };
struct VkDebugUtilsMessengerCallbackDataEXT { using element_type = ::VkDebugUtilsMessengerCallbackDataEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT; };
struct VkDebugUtilsMessengerCallbackDataFlagsEXT { using element_type = ::VkDebugUtilsMessengerCallbackDataFlagsEXT; using kind = format::kind::Flags; };
struct VkDebugUtilsMessengerCreateFlagsEXT { using element_type = ::VkDebugUtilsMessengerCreateFlagsEXT; using kind = format::kind::Flags; };
struct VkDebugUtilsMessengerCreateInfoEXT { using element_type = ::VkDebugUtilsMessengerCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT; };
struct VkDebugUtilsMessengerEXT { using element_type = ::VkDebugUtilsMessengerEXT; using kind = format::kind::Handle; };
struct VkDebugUtilsObjectNameInfoEXT { using element_type = ::VkDebugUtilsObjectNameInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT; };
struct VkDebugUtilsObjectTagInfoEXT { using element_type = ::VkDebugUtilsObjectTagInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT; };
struct VkDecompressMemoryInfoEXT { using element_type = ::VkDecompressMemoryInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DECOMPRESS_MEMORY_INFO_EXT; };
struct VkDecompressMemoryRegionEXT { using element_type = ::VkDecompressMemoryRegionEXT; using kind = format::kind::Struct; };
struct VkDedicatedAllocationBufferCreateInfoNV { using element_type = ::VkDedicatedAllocationBufferCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV; };
struct VkDedicatedAllocationImageCreateInfoNV { using element_type = ::VkDedicatedAllocationImageCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV; };
struct VkDedicatedAllocationMemoryAllocateInfoNV { using element_type = ::VkDedicatedAllocationMemoryAllocateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV; };
struct VkDefaultVertexAttributeValueKHR { using element_type = ::VkDefaultVertexAttributeValueKHR; using kind = format::kind::Enum; };
struct VkDeferredOperationKHR { using element_type = ::VkDeferredOperationKHR; using kind = format::kind::Handle; };
struct VkDependencyFlags { using element_type = ::VkDependencyFlags; using kind = format::kind::Flags; };
struct VkDependencyInfo { using element_type = ::VkDependencyInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEPENDENCY_INFO; };
struct VkDepthBiasInfoEXT { using element_type = ::VkDepthBiasInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT; };
struct VkDepthBiasRepresentationEXT { using element_type = ::VkDepthBiasRepresentationEXT; using kind = format::kind::Enum; };
struct VkDepthBiasRepresentationInfoEXT { using element_type = ::VkDepthBiasRepresentationInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT; };
struct VkDepthClampModeEXT { using element_type = ::VkDepthClampModeEXT; using kind = format::kind::Enum; };
struct VkDepthClampRangeEXT { using element_type = ::VkDepthClampRangeEXT; using kind = format::kind::Struct; };
struct VkDescriptorAddressInfoEXT { using element_type = ::VkDescriptorAddressInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT; };
struct VkDescriptorBindingFlags { using element_type = ::VkDescriptorBindingFlags; using kind = format::kind::Flags; };
struct VkDescriptorBufferBindingInfoEXT { using element_type = ::VkDescriptorBufferBindingInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT; };
struct VkDescriptorBufferBindingPushDescriptorBufferHandleEXT { using element_type = ::VkDescriptorBufferBindingPushDescriptorBufferHandleEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT; };
struct VkDescriptorBufferInfo { using element_type = ::VkDescriptorBufferInfo; using kind = format::kind::Struct; };
struct VkDescriptorGetInfoEXT { using element_type = ::VkDescriptorGetInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT; };
struct VkDescriptorGetTensorInfoARM { using element_type = ::VkDescriptorGetTensorInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_GET_TENSOR_INFO_ARM; };
struct VkDescriptorPool { using element_type = ::VkDescriptorPool; using kind = format::kind::Handle; };
struct VkDescriptorPoolCreateFlags { using element_type = ::VkDescriptorPoolCreateFlags; using kind = format::kind::Flags; };
struct VkDescriptorPoolCreateInfo { using element_type = ::VkDescriptorPoolCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO; };
struct VkDescriptorPoolInlineUniformBlockCreateInfo { using element_type = ::VkDescriptorPoolInlineUniformBlockCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO; };
struct VkDescriptorPoolResetFlags { using element_type = ::VkDescriptorPoolResetFlags; using kind = format::kind::Flags; };
struct VkDescriptorPoolSize { using element_type = ::VkDescriptorPoolSize; using kind = format::kind::Struct; };
struct VkDescriptorSet { using element_type = ::VkDescriptorSet; using kind = format::kind::Handle; };
struct VkDescriptorSetAllocateInfo { using element_type = ::VkDescriptorSetAllocateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO; };
struct VkDescriptorSetBindingReferenceVALVE { using element_type = ::VkDescriptorSetBindingReferenceVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE; };
struct VkDescriptorSetLayout { using element_type = ::VkDescriptorSetLayout; using kind = format::kind::Handle; };
struct VkDescriptorSetLayoutBinding { using element_type = ::VkDescriptorSetLayoutBinding; using kind = format::kind::Struct; };
struct VkDescriptorSetLayoutBindingFlagsCreateInfo { using element_type = ::VkDescriptorSetLayoutBindingFlagsCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO; };
struct VkDescriptorSetLayoutCreateFlags { using element_type = ::VkDescriptorSetLayoutCreateFlags; using kind = format::kind::Flags; };
struct VkDescriptorSetLayoutCreateInfo { using element_type = ::VkDescriptorSetLayoutCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO; };
struct VkDescriptorSetLayoutHostMappingInfoVALVE { using element_type = ::VkDescriptorSetLayoutHostMappingInfoVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE; };
struct VkDescriptorSetLayoutSupport { using element_type = ::VkDescriptorSetLayoutSupport; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT; };
struct VkDescriptorSetVariableDescriptorCountAllocateInfo { using element_type = ::VkDescriptorSetVariableDescriptorCountAllocateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO; };
struct VkDescriptorSetVariableDescriptorCountLayoutSupport { using element_type = ::VkDescriptorSetVariableDescriptorCountLayoutSupport; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT; };
struct VkDescriptorType { using element_type = ::VkDescriptorType; using kind = format::kind::Enum; };
struct VkDescriptorUpdateTemplate { using element_type = ::VkDescriptorUpdateTemplate; using kind = format::kind::Handle; };
struct VkDescriptorUpdateTemplateCreateFlags { using element_type = ::VkDescriptorUpdateTemplateCreateFlags; using kind = format::kind::Flags; };
struct VkDescriptorUpdateTemplateCreateInfo { using element_type = ::VkDescriptorUpdateTemplateCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO; };
struct VkDescriptorUpdateTemplateEntry { using element_type = ::VkDescriptorUpdateTemplateEntry; using kind = format::kind::Struct; };
struct VkDescriptorUpdateTemplateType { using element_type = ::VkDescriptorUpdateTemplateType; using kind = format::kind::Enum; };
struct VkDevice { using element_type = ::VkDevice; using kind = format::kind::Handle; };
struct VkDeviceAddress { using element_type = ::VkDeviceAddress; using kind = format::kind::DeviceAddress; };
struct VkDeviceAddressBindingCallbackDataEXT { using element_type = ::VkDeviceAddressBindingCallbackDataEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT; };
struct VkDeviceAddressBindingFlagsEXT { using element_type = ::VkDeviceAddressBindingFlagsEXT; using kind = format::kind::Flags; };
struct VkDeviceAddressBindingTypeEXT { using element_type = ::VkDeviceAddressBindingTypeEXT; using kind = format::kind::Enum; };
struct VkDeviceAddressRangeKHR { using element_type = ::VkDeviceAddressRangeKHR; using kind = format::kind::Struct; };
struct VkDeviceBufferMemoryRequirements { using element_type = ::VkDeviceBufferMemoryRequirements; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS; };
struct VkDeviceCreateFlags { using element_type = ::VkDeviceCreateFlags; using kind = format::kind::Flags; };
struct VkDeviceCreateInfo { using element_type = ::VkDeviceCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO; };
struct VkDeviceDeviceMemoryReportCreateInfoEXT { using element_type = ::VkDeviceDeviceMemoryReportCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT; };
struct VkDeviceDiagnosticsConfigCreateInfoNV { using element_type = ::VkDeviceDiagnosticsConfigCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV; };
struct VkDeviceDiagnosticsConfigFlagsNV { using element_type = ::VkDeviceDiagnosticsConfigFlagsNV; using kind = format::kind::Flags; };
struct VkDeviceEventInfoEXT { using element_type = ::VkDeviceEventInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT; };
struct VkDeviceEventTypeEXT { using element_type = ::VkDeviceEventTypeEXT; using kind = format::kind::Enum; };
struct VkDeviceFaultAddressInfoKHR { using element_type = ::VkDeviceFaultAddressInfoKHR; using kind = format::kind::Struct; };
struct VkDeviceFaultAddressTypeKHR { using element_type = ::VkDeviceFaultAddressTypeKHR; using kind = format::kind::Enum; };
struct VkDeviceFaultCountsEXT { using element_type = ::VkDeviceFaultCountsEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT; };
struct VkDeviceFaultDebugInfoKHR { using element_type = ::VkDeviceFaultDebugInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_FAULT_DEBUG_INFO_KHR; };
struct VkDeviceFaultFlagsKHR { using element_type = ::VkDeviceFaultFlagsKHR; using kind = format::kind::Flags; };
struct VkDeviceFaultInfoEXT { using element_type = ::VkDeviceFaultInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT; };
struct VkDeviceFaultInfoKHR { using element_type = ::VkDeviceFaultInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_KHR; };
struct VkDeviceFaultShaderAbortMessageInfoKHR { using element_type = ::VkDeviceFaultShaderAbortMessageInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_FAULT_SHADER_ABORT_MESSAGE_INFO_KHR; };
struct VkDeviceFaultVendorBinaryHeaderVersionKHR { using element_type = ::VkDeviceFaultVendorBinaryHeaderVersionKHR; using kind = format::kind::Enum; };
struct VkDeviceFaultVendorBinaryHeaderVersionOneKHR { using element_type = ::VkDeviceFaultVendorBinaryHeaderVersionOneKHR; using kind = format::kind::Struct; };
struct VkDeviceFaultVendorInfoKHR { using element_type = ::VkDeviceFaultVendorInfoKHR; using kind = format::kind::Struct; };
struct VkDeviceGroupBindSparseInfo { using element_type = ::VkDeviceGroupBindSparseInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO; };
struct VkDeviceGroupCommandBufferBeginInfo { using element_type = ::VkDeviceGroupCommandBufferBeginInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO; };
struct VkDeviceGroupDeviceCreateInfo { using element_type = ::VkDeviceGroupDeviceCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO; };
struct VkDeviceGroupPresentCapabilitiesKHR { using element_type = ::VkDeviceGroupPresentCapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR; };
struct VkDeviceGroupPresentInfoKHR { using element_type = ::VkDeviceGroupPresentInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR; };
struct VkDeviceGroupPresentModeFlagBitsKHR { using element_type = ::VkDeviceGroupPresentModeFlagBitsKHR; using kind = format::kind::Enum; };
struct VkDeviceGroupPresentModeFlagsKHR { using element_type = ::VkDeviceGroupPresentModeFlagsKHR; using kind = format::kind::Flags; };
struct VkDeviceGroupRenderPassBeginInfo { using element_type = ::VkDeviceGroupRenderPassBeginInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO; };
struct VkDeviceGroupSubmitInfo { using element_type = ::VkDeviceGroupSubmitInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO; };
struct VkDeviceGroupSwapchainCreateInfoKHR { using element_type = ::VkDeviceGroupSwapchainCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR; };
struct VkDeviceImageMemoryRequirements { using element_type = ::VkDeviceImageMemoryRequirements; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS; };
struct VkDeviceImageSubresourceInfo { using element_type = ::VkDeviceImageSubresourceInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO; };
struct VkDeviceMemory { using element_type = ::VkDeviceMemory; using kind = format::kind::Handle; };
struct VkDeviceMemoryCopyKHR { using element_type = ::VkDeviceMemoryCopyKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_MEMORY_COPY_KHR; };
struct VkDeviceMemoryImageCopyKHR { using element_type = ::VkDeviceMemoryImageCopyKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_MEMORY_IMAGE_COPY_KHR; };
struct VkDeviceMemoryOpaqueCaptureAddressInfo { using element_type = ::VkDeviceMemoryOpaqueCaptureAddressInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO; };
struct VkDeviceMemoryOverallocationCreateInfoAMD { using element_type = ::VkDeviceMemoryOverallocationCreateInfoAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD; };
struct VkDeviceMemoryReportCallbackDataEXT { using element_type = ::VkDeviceMemoryReportCallbackDataEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT; };
struct VkDeviceMemoryReportEventTypeEXT { using element_type = ::VkDeviceMemoryReportEventTypeEXT; using kind = format::kind::Enum; };
struct VkDeviceMemoryReportFlagsEXT { using element_type = ::VkDeviceMemoryReportFlagsEXT; using kind = format::kind::Flags; };
struct VkDeviceOrHostAddressConstKHR { using element_type = ::VkDeviceOrHostAddressConstKHR; using kind = format::kind::Struct; };
struct VkDeviceOrHostAddressKHR { using element_type = ::VkDeviceOrHostAddressKHR; using kind = format::kind::Struct; };
struct VkDevicePipelineBinaryInternalCacheControlKHR { using element_type = ::VkDevicePipelineBinaryInternalCacheControlKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR; };
struct VkDevicePrivateDataCreateInfo { using element_type = ::VkDevicePrivateDataCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO; };
struct VkDeviceQueueCreateFlags { using element_type = ::VkDeviceQueueCreateFlags; using kind = format::kind::Flags; };
struct VkDeviceQueueCreateInfo { using element_type = ::VkDeviceQueueCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO; };
struct VkDeviceQueueGlobalPriorityCreateInfo { using element_type = ::VkDeviceQueueGlobalPriorityCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO; };
struct VkDeviceQueueInfo2 { using element_type = ::VkDeviceQueueInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2; };
struct VkDeviceQueueShaderCoreControlCreateInfoARM { using element_type = ::VkDeviceQueueShaderCoreControlCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM; };
struct VkDeviceSize { using element_type = ::VkDeviceSize; using kind = format::kind::DeviceSize; };
struct VkDeviceTensorMemoryRequirementsARM { using element_type = ::VkDeviceTensorMemoryRequirementsARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DEVICE_TENSOR_MEMORY_REQUIREMENTS_ARM; };
struct VkDirectDriverLoadingFlagsLUNARG { using element_type = ::VkDirectDriverLoadingFlagsLUNARG; using kind = format::kind::Flags; };
struct VkDirectDriverLoadingInfoLUNARG { using element_type = ::VkDirectDriverLoadingInfoLUNARG; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG; };
struct VkDirectDriverLoadingListLUNARG { using element_type = ::VkDirectDriverLoadingListLUNARG; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG; };
struct VkDirectDriverLoadingModeLUNARG { using element_type = ::VkDirectDriverLoadingModeLUNARG; using kind = format::kind::Enum; };
struct VkDirectFBSurfaceCreateFlagsEXT { using element_type = ::VkDirectFBSurfaceCreateFlagsEXT; using kind = format::kind::Flags; };
struct VkDirectFBSurfaceCreateInfoEXT { using element_type = ::VkDirectFBSurfaceCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT; };
struct VkDiscardRectangleModeEXT { using element_type = ::VkDiscardRectangleModeEXT; using kind = format::kind::Enum; };
struct VkDispatchIndirect2InfoKHR { using element_type = ::VkDispatchIndirect2InfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPATCH_INDIRECT_2_INFO_KHR; };
struct VkDispatchIndirectCommand { using element_type = ::VkDispatchIndirectCommand; using kind = format::kind::Struct; };
struct VkDispatchParametersARM { using element_type = ::VkDispatchParametersARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPATCH_PARAMETERS_ARM; };
struct VkDispatchTileInfoQCOM { using element_type = ::VkDispatchTileInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPATCH_TILE_INFO_QCOM; };
struct VkDisplayEventInfoEXT { using element_type = ::VkDisplayEventInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT; };
struct VkDisplayEventTypeEXT { using element_type = ::VkDisplayEventTypeEXT; using kind = format::kind::Enum; };
struct VkDisplayKHR { using element_type = ::VkDisplayKHR; using kind = format::kind::Handle; };
struct VkDisplayModeCreateFlagsKHR { using element_type = ::VkDisplayModeCreateFlagsKHR; using kind = format::kind::Flags; };
struct VkDisplayModeCreateInfoKHR { using element_type = ::VkDisplayModeCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR; };
struct VkDisplayModeKHR { using element_type = ::VkDisplayModeKHR; using kind = format::kind::Handle; };
struct VkDisplayModeParametersKHR { using element_type = ::VkDisplayModeParametersKHR; using kind = format::kind::Struct; };
struct VkDisplayModeProperties2KHR { using element_type = ::VkDisplayModeProperties2KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR; };
struct VkDisplayModePropertiesKHR { using element_type = ::VkDisplayModePropertiesKHR; using kind = format::kind::Struct; };
struct VkDisplayModeStereoPropertiesNV { using element_type = ::VkDisplayModeStereoPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV; };
struct VkDisplayNativeHdrSurfaceCapabilitiesAMD { using element_type = ::VkDisplayNativeHdrSurfaceCapabilitiesAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD; };
struct VkDisplayPlaneAlphaFlagBitsKHR { using element_type = ::VkDisplayPlaneAlphaFlagBitsKHR; using kind = format::kind::Enum; };
struct VkDisplayPlaneAlphaFlagsKHR { using element_type = ::VkDisplayPlaneAlphaFlagsKHR; using kind = format::kind::Flags; };
struct VkDisplayPlaneCapabilities2KHR { using element_type = ::VkDisplayPlaneCapabilities2KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR; };
struct VkDisplayPlaneCapabilitiesKHR { using element_type = ::VkDisplayPlaneCapabilitiesKHR; using kind = format::kind::Struct; };
struct VkDisplayPlaneInfo2KHR { using element_type = ::VkDisplayPlaneInfo2KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR; };
struct VkDisplayPlaneProperties2KHR { using element_type = ::VkDisplayPlaneProperties2KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR; };
struct VkDisplayPlanePropertiesKHR { using element_type = ::VkDisplayPlanePropertiesKHR; using kind = format::kind::Struct; };
struct VkDisplayPowerInfoEXT { using element_type = ::VkDisplayPowerInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT; };
struct VkDisplayPowerStateEXT { using element_type = ::VkDisplayPowerStateEXT; using kind = format::kind::Enum; };
struct VkDisplayPresentInfoKHR { using element_type = ::VkDisplayPresentInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR; };
struct VkDisplayProperties2KHR { using element_type = ::VkDisplayProperties2KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR; };
struct VkDisplayPropertiesKHR { using element_type = ::VkDisplayPropertiesKHR; using kind = format::kind::Struct; };
struct VkDisplaySurfaceCreateFlagsKHR { using element_type = ::VkDisplaySurfaceCreateFlagsKHR; using kind = format::kind::Flags; };
struct VkDisplaySurfaceCreateInfoKHR { using element_type = ::VkDisplaySurfaceCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR; };
struct VkDisplaySurfaceStereoCreateInfoNV { using element_type = ::VkDisplaySurfaceStereoCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV; };
struct VkDisplaySurfaceStereoTypeNV { using element_type = ::VkDisplaySurfaceStereoTypeNV; using kind = format::kind::Enum; };
struct VkDrawIndexedIndirectCommand { using element_type = ::VkDrawIndexedIndirectCommand; using kind = format::kind::Struct; };
struct VkDrawIndirect2InfoKHR { using element_type = ::VkDrawIndirect2InfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DRAW_INDIRECT_2_INFO_KHR; };
struct VkDrawIndirectCommand { using element_type = ::VkDrawIndirectCommand; using kind = format::kind::Struct; };
struct VkDrawIndirectCount2InfoKHR { using element_type = ::VkDrawIndirectCount2InfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DRAW_INDIRECT_COUNT_2_INFO_KHR; };
struct VkDrawIndirectCountIndirectCommandEXT { using element_type = ::VkDrawIndirectCountIndirectCommandEXT; using kind = format::kind::Struct; };
struct VkDrawMeshTasksIndirectCommandEXT { using element_type = ::VkDrawMeshTasksIndirectCommandEXT; using kind = format::kind::Struct; };
struct VkDrawMeshTasksIndirectCommandNV { using element_type = ::VkDrawMeshTasksIndirectCommandNV; using kind = format::kind::Struct; };
struct VkDriverId { using element_type = ::VkDriverId; using kind = format::kind::Enum; };
struct VkDrmFormatModifierProperties2EXT { using element_type = ::VkDrmFormatModifierProperties2EXT; using kind = format::kind::Struct; };
struct VkDrmFormatModifierPropertiesEXT { using element_type = ::VkDrmFormatModifierPropertiesEXT; using kind = format::kind::Struct; };
struct VkDrmFormatModifierPropertiesList2EXT { using element_type = ::VkDrmFormatModifierPropertiesList2EXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT; };
struct VkDrmFormatModifierPropertiesListEXT { using element_type = ::VkDrmFormatModifierPropertiesListEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT; };
struct VkDynamicState { using element_type = ::VkDynamicState; using kind = format::kind::Enum; };
struct VkEvent { using element_type = ::VkEvent; using kind = format::kind::Handle; };
struct VkEventCreateFlags { using element_type = ::VkEventCreateFlags; using kind = format::kind::Flags; };
struct VkEventCreateInfo { using element_type = ::VkEventCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO; };
struct VkExportFenceCreateInfo { using element_type = ::VkExportFenceCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO; };
struct VkExportFenceWin32HandleInfoKHR { using element_type = ::VkExportFenceWin32HandleInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR; };
struct VkExportMemoryAllocateInfo { using element_type = ::VkExportMemoryAllocateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO; };
struct VkExportMemoryAllocateInfoNV { using element_type = ::VkExportMemoryAllocateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV; };
struct VkExportMemoryWin32HandleInfoKHR { using element_type = ::VkExportMemoryWin32HandleInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR; };
struct VkExportMemoryWin32HandleInfoNV { using element_type = ::VkExportMemoryWin32HandleInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV; };
struct VkExportSemaphoreCreateInfo { using element_type = ::VkExportSemaphoreCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO; };
struct VkExportSemaphoreWin32HandleInfoKHR { using element_type = ::VkExportSemaphoreWin32HandleInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR; };
struct VkExtensionProperties { using element_type = ::VkExtensionProperties; using kind = format::kind::Struct; };
struct VkExtent2D { using element_type = ::VkExtent2D; using kind = format::kind::Struct; };
struct VkExtent3D { using element_type = ::VkExtent3D; using kind = format::kind::Struct; };
struct VkExternalBufferProperties { using element_type = ::VkExternalBufferProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES; };
struct VkExternalFenceFeatureFlags { using element_type = ::VkExternalFenceFeatureFlags; using kind = format::kind::Flags; };
struct VkExternalFenceHandleTypeFlagBits { using element_type = ::VkExternalFenceHandleTypeFlagBits; using kind = format::kind::Enum; };
struct VkExternalFenceHandleTypeFlags { using element_type = ::VkExternalFenceHandleTypeFlags; using kind = format::kind::Flags; };
struct VkExternalFenceProperties { using element_type = ::VkExternalFenceProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES; };
struct VkExternalFormatANDROID { using element_type = ::VkExternalFormatANDROID; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID; };
struct VkExternalImageFormatProperties { using element_type = ::VkExternalImageFormatProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES; };
struct VkExternalImageFormatPropertiesNV { using element_type = ::VkExternalImageFormatPropertiesNV; using kind = format::kind::Struct; };
struct VkExternalMemoryAcquireUnmodifiedEXT { using element_type = ::VkExternalMemoryAcquireUnmodifiedEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT; };
struct VkExternalMemoryBufferCreateInfo { using element_type = ::VkExternalMemoryBufferCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO; };
struct VkExternalMemoryFeatureFlags { using element_type = ::VkExternalMemoryFeatureFlags; using kind = format::kind::Flags; };
struct VkExternalMemoryFeatureFlagsNV { using element_type = ::VkExternalMemoryFeatureFlagsNV; using kind = format::kind::Flags; };
struct VkExternalMemoryHandleTypeFlagBits { using element_type = ::VkExternalMemoryHandleTypeFlagBits; using kind = format::kind::Enum; };
struct VkExternalMemoryHandleTypeFlags { using element_type = ::VkExternalMemoryHandleTypeFlags; using kind = format::kind::Flags; };
struct VkExternalMemoryHandleTypeFlagsNV { using element_type = ::VkExternalMemoryHandleTypeFlagsNV; using kind = format::kind::Flags; };
struct VkExternalMemoryImageCreateInfo { using element_type = ::VkExternalMemoryImageCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO; };
struct VkExternalMemoryImageCreateInfoNV { using element_type = ::VkExternalMemoryImageCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV; };
struct VkExternalMemoryProperties { using element_type = ::VkExternalMemoryProperties; using kind = format::kind::Struct; };
struct VkExternalMemoryTensorCreateInfoARM { using element_type = ::VkExternalMemoryTensorCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_TENSOR_CREATE_INFO_ARM; };
struct VkExternalSemaphoreFeatureFlags { using element_type = ::VkExternalSemaphoreFeatureFlags; using kind = format::kind::Flags; };
struct VkExternalSemaphoreHandleTypeFlagBits { using element_type = ::VkExternalSemaphoreHandleTypeFlagBits; using kind = format::kind::Enum; };
struct VkExternalSemaphoreHandleTypeFlags { using element_type = ::VkExternalSemaphoreHandleTypeFlags; using kind = format::kind::Flags; };
struct VkExternalSemaphoreProperties { using element_type = ::VkExternalSemaphoreProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES; };
struct VkExternalTensorPropertiesARM { using element_type = ::VkExternalTensorPropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_EXTERNAL_TENSOR_PROPERTIES_ARM; };
struct VkFence { using element_type = ::VkFence; using kind = format::kind::Handle; };
struct VkFenceCreateFlags { using element_type = ::VkFenceCreateFlags; using kind = format::kind::Flags; };
struct VkFenceCreateInfo { using element_type = ::VkFenceCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO; };
struct VkFenceGetFdInfoKHR { using element_type = ::VkFenceGetFdInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR; };
struct VkFenceGetWin32HandleInfoKHR { using element_type = ::VkFenceGetWin32HandleInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR; };
struct VkFenceImportFlags { using element_type = ::VkFenceImportFlags; using kind = format::kind::Flags; };
struct VkFilter { using element_type = ::VkFilter; using kind = format::kind::Enum; };
struct VkFilterCubicImageViewImageFormatPropertiesEXT { using element_type = ::VkFilterCubicImageViewImageFormatPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT; };
struct VkFormat { using element_type = ::VkFormat; using kind = format::kind::Enum; };
struct VkFormatFeatureFlags { using element_type = ::VkFormatFeatureFlags; using kind = format::kind::Flags; };
struct VkFormatFeatureFlags2 { using element_type = ::VkFormatFeatureFlags2; using kind = format::kind::Flags64; };
struct VkFormatFeatureFlags4KHR { using element_type = ::VkFormatFeatureFlags4KHR; using kind = format::kind::Flags64; };
struct VkFormatProperties { using element_type = ::VkFormatProperties; using kind = format::kind::Struct; };
struct VkFormatProperties2 { using element_type = ::VkFormatProperties2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2; };
struct VkFormatProperties3 { using element_type = ::VkFormatProperties3; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3; };
struct VkFormatProperties4KHR { using element_type = ::VkFormatProperties4KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_4_KHR; };
struct VkFragmentShadingRateAttachmentInfoKHR { using element_type = ::VkFragmentShadingRateAttachmentInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR; };
struct VkFragmentShadingRateCombinerOpKHR { using element_type = ::VkFragmentShadingRateCombinerOpKHR; using kind = format::kind::Enum; };
struct VkFragmentShadingRateNV { using element_type = ::VkFragmentShadingRateNV; using kind = format::kind::Enum; };
struct VkFragmentShadingRateTypeNV { using element_type = ::VkFragmentShadingRateTypeNV; using kind = format::kind::Enum; };
struct VkFrameBoundaryEXT { using element_type = ::VkFrameBoundaryEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT; };
struct VkFrameBoundaryFlagsEXT { using element_type = ::VkFrameBoundaryFlagsEXT; using kind = format::kind::Flags; };
struct VkFrameBoundaryTensorsARM { using element_type = ::VkFrameBoundaryTensorsARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FRAME_BOUNDARY_TENSORS_ARM; };
struct VkFramebuffer { using element_type = ::VkFramebuffer; using kind = format::kind::Handle; };
struct VkFramebufferAttachmentImageInfo { using element_type = ::VkFramebufferAttachmentImageInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO; };
struct VkFramebufferAttachmentsCreateInfo { using element_type = ::VkFramebufferAttachmentsCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO; };
struct VkFramebufferCreateFlags { using element_type = ::VkFramebufferCreateFlags; using kind = format::kind::Flags; };
struct VkFramebufferCreateInfo { using element_type = ::VkFramebufferCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO; };
struct VkFramebufferMixedSamplesCombinationNV { using element_type = ::VkFramebufferMixedSamplesCombinationNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV; };
struct VkFrontFace { using element_type = ::VkFrontFace; using kind = format::kind::Enum; };
struct VkFullScreenExclusiveEXT { using element_type = ::VkFullScreenExclusiveEXT; using kind = format::kind::Enum; };
struct VkGeneratedCommandsInfoEXT { using element_type = ::VkGeneratedCommandsInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_EXT; };
struct VkGeneratedCommandsInfoNV { using element_type = ::VkGeneratedCommandsInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV; };
struct VkGeneratedCommandsMemoryRequirementsInfoEXT { using element_type = ::VkGeneratedCommandsMemoryRequirementsInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_EXT; };
struct VkGeneratedCommandsMemoryRequirementsInfoNV { using element_type = ::VkGeneratedCommandsMemoryRequirementsInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV; };
struct VkGeneratedCommandsPipelineInfoEXT { using element_type = ::VkGeneratedCommandsPipelineInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT; };
struct VkGeneratedCommandsShaderInfoEXT { using element_type = ::VkGeneratedCommandsShaderInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT; };
struct VkGeometryAABBNV { using element_type = ::VkGeometryAABBNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV; };
struct VkGeometryDataNV { using element_type = ::VkGeometryDataNV; using kind = format::kind::Struct; };
struct VkGeometryFlagsKHR { using element_type = ::VkGeometryFlagsKHR; using kind = format::kind::Flags; };
struct VkGeometryInstanceFlagsKHR { using element_type = ::VkGeometryInstanceFlagsKHR; using kind = format::kind::Flags; };
struct VkGeometryNV { using element_type = ::VkGeometryNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GEOMETRY_NV; };
struct VkGeometryTrianglesNV { using element_type = ::VkGeometryTrianglesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV; };
struct VkGeometryTypeKHR { using element_type = ::VkGeometryTypeKHR; using kind = format::kind::Enum; };
struct VkGetLatencyMarkerInfoNV { using element_type = ::VkGetLatencyMarkerInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV; };
struct VkGpaDeviceClockModeAMD { using element_type = ::VkGpaDeviceClockModeAMD; using kind = format::kind::Enum; };
struct VkGpaDeviceClockModeInfoAMD { using element_type = ::VkGpaDeviceClockModeInfoAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GPA_DEVICE_CLOCK_MODE_INFO_AMD; };
struct VkGpaDeviceGetClockInfoAMD { using element_type = ::VkGpaDeviceGetClockInfoAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GPA_DEVICE_GET_CLOCK_INFO_AMD; };
struct VkGpaPerfBlockAMD { using element_type = ::VkGpaPerfBlockAMD; using kind = format::kind::Enum; };
struct VkGpaPerfBlockPropertiesAMD { using element_type = ::VkGpaPerfBlockPropertiesAMD; using kind = format::kind::Struct; };
struct VkGpaPerfBlockPropertiesFlagsAMD { using element_type = ::VkGpaPerfBlockPropertiesFlagsAMD; using kind = format::kind::Flags; };
struct VkGpaPerfCounterAMD { using element_type = ::VkGpaPerfCounterAMD; using kind = format::kind::Struct; };
struct VkGpaSampleBeginInfoAMD { using element_type = ::VkGpaSampleBeginInfoAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GPA_SAMPLE_BEGIN_INFO_AMD; };
struct VkGpaSampleTypeAMD { using element_type = ::VkGpaSampleTypeAMD; using kind = format::kind::Enum; };
struct VkGpaSessionAMD { using element_type = ::VkGpaSessionAMD; using kind = format::kind::Handle; };
struct VkGpaSessionCreateInfoAMD { using element_type = ::VkGpaSessionCreateInfoAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GPA_SESSION_CREATE_INFO_AMD; };
struct VkGpaSqShaderStageFlagsAMD { using element_type = ::VkGpaSqShaderStageFlagsAMD; using kind = format::kind::Flags; };
struct VkGraphicsPipelineCreateInfo { using element_type = ::VkGraphicsPipelineCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO; };
struct VkGraphicsPipelineLibraryCreateInfoEXT { using element_type = ::VkGraphicsPipelineLibraryCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT; };
struct VkGraphicsPipelineLibraryFlagsEXT { using element_type = ::VkGraphicsPipelineLibraryFlagsEXT; using kind = format::kind::Flags; };
struct VkGraphicsPipelineShaderGroupsCreateInfoNV { using element_type = ::VkGraphicsPipelineShaderGroupsCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV; };
struct VkGraphicsShaderGroupCreateInfoNV { using element_type = ::VkGraphicsShaderGroupCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV; };
struct VkHdrMetadataEXT { using element_type = ::VkHdrMetadataEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_HDR_METADATA_EXT; };
struct VkHdrVividDynamicMetadataHUAWEI { using element_type = ::VkHdrVividDynamicMetadataHUAWEI; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI; };
struct VkHeadlessSurfaceCreateFlagsEXT { using element_type = ::VkHeadlessSurfaceCreateFlagsEXT; using kind = format::kind::Flags; };
struct VkHeadlessSurfaceCreateInfoEXT { using element_type = ::VkHeadlessSurfaceCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT; };
struct VkHostImageCopyDevicePerformanceQuery { using element_type = ::VkHostImageCopyDevicePerformanceQuery; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY; };
struct VkHostImageCopyFlags { using element_type = ::VkHostImageCopyFlags; using kind = format::kind::Flags; };
struct VkHostImageLayoutTransitionInfo { using element_type = ::VkHostImageLayoutTransitionInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO; };
struct VkIOSSurfaceCreateFlagsMVK { using element_type = ::VkIOSSurfaceCreateFlagsMVK; using kind = format::kind::Flags; };
struct VkIOSSurfaceCreateInfoMVK { using element_type = ::VkIOSSurfaceCreateInfoMVK; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK; };
struct VkImage { using element_type = ::VkImage; using kind = format::kind::Handle; };
struct VkImageAlignmentControlCreateInfoMESA { using element_type = ::VkImageAlignmentControlCreateInfoMESA; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA; };
struct VkImageAspectFlagBits { using element_type = ::VkImageAspectFlagBits; using kind = format::kind::Enum; };
struct VkImageAspectFlags { using element_type = ::VkImageAspectFlags; using kind = format::kind::Flags; };
struct VkImageBlit { using element_type = ::VkImageBlit; using kind = format::kind::Struct; };
struct VkImageBlit2 { using element_type = ::VkImageBlit2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_BLIT_2; };
struct VkImageCaptureDescriptorDataInfoEXT { using element_type = ::VkImageCaptureDescriptorDataInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT; };
struct VkImageCompressionControlEXT { using element_type = ::VkImageCompressionControlEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT; };
struct VkImageCompressionFixedRateFlagsEXT { using element_type = ::VkImageCompressionFixedRateFlagsEXT; using kind = format::kind::Flags; };
struct VkImageCompressionFlagsEXT { using element_type = ::VkImageCompressionFlagsEXT; using kind = format::kind::Flags; };
struct VkImageCompressionPropertiesEXT { using element_type = ::VkImageCompressionPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT; };
struct VkImageCopy { using element_type = ::VkImageCopy; using kind = format::kind::Struct; };
struct VkImageCopy2 { using element_type = ::VkImageCopy2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_COPY_2; };
struct VkImageCreateFlags { using element_type = ::VkImageCreateFlags; using kind = format::kind::Flags; };
struct VkImageCreateFlags2CreateInfoKHR { using element_type = ::VkImageCreateFlags2CreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_CREATE_FLAGS_2_CREATE_INFO_KHR; };
struct VkImageCreateFlags2KHR { using element_type = ::VkImageCreateFlags2KHR; using kind = format::kind::Flags64; };
struct VkImageCreateInfo { using element_type = ::VkImageCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO; };
struct VkImageDrmFormatModifierExplicitCreateInfoEXT { using element_type = ::VkImageDrmFormatModifierExplicitCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT; };
struct VkImageDrmFormatModifierListCreateInfoEXT { using element_type = ::VkImageDrmFormatModifierListCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT; };
struct VkImageDrmFormatModifierPropertiesEXT { using element_type = ::VkImageDrmFormatModifierPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT; };
struct VkImageFormatListCreateInfo { using element_type = ::VkImageFormatListCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO; };
struct VkImageFormatProperties { using element_type = ::VkImageFormatProperties; using kind = format::kind::Struct; };
struct VkImageFormatProperties2 { using element_type = ::VkImageFormatProperties2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2; };
struct VkImageLayout { using element_type = ::VkImageLayout; using kind = format::kind::Enum; };
struct VkImageMemoryBarrier { using element_type = ::VkImageMemoryBarrier; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER; };
struct VkImageMemoryBarrier2 { using element_type = ::VkImageMemoryBarrier2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2; };
struct VkImageMemoryRequirementsInfo2 { using element_type = ::VkImageMemoryRequirementsInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2; };
struct VkImagePipeSurfaceCreateFlagsFUCHSIA { using element_type = ::VkImagePipeSurfaceCreateFlagsFUCHSIA; using kind = format::kind::Flags; };
struct VkImagePipeSurfaceCreateInfoFUCHSIA { using element_type = ::VkImagePipeSurfaceCreateInfoFUCHSIA; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA; };
struct VkImagePlaneMemoryRequirementsInfo { using element_type = ::VkImagePlaneMemoryRequirementsInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO; };
struct VkImageResolve { using element_type = ::VkImageResolve; using kind = format::kind::Struct; };
struct VkImageResolve2 { using element_type = ::VkImageResolve2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2; };
struct VkImageSparseMemoryRequirementsInfo2 { using element_type = ::VkImageSparseMemoryRequirementsInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2; };
struct VkImageStencilUsage2CreateInfoKHR { using element_type = ::VkImageStencilUsage2CreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_2_CREATE_INFO_KHR; };
struct VkImageStencilUsageCreateInfo { using element_type = ::VkImageStencilUsageCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO; };
struct VkImageSubresource { using element_type = ::VkImageSubresource; using kind = format::kind::Struct; };
struct VkImageSubresource2 { using element_type = ::VkImageSubresource2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2; };
struct VkImageSubresourceLayers { using element_type = ::VkImageSubresourceLayers; using kind = format::kind::Struct; };
struct VkImageSubresourceRange { using element_type = ::VkImageSubresourceRange; using kind = format::kind::Struct; };
struct VkImageSwapchainCreateInfoKHR { using element_type = ::VkImageSwapchainCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR; };
struct VkImageTiling { using element_type = ::VkImageTiling; using kind = format::kind::Enum; };
struct VkImageTilingControlCreateInfoEXT { using element_type = ::VkImageTilingControlCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_TILING_CONTROL_CREATE_INFO_EXT; };
struct VkImageTilingControlEXT { using element_type = ::VkImageTilingControlEXT; using kind = format::kind::Enum; };
struct VkImageToMemoryCopy { using element_type = ::VkImageToMemoryCopy; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY; };
struct VkImageType { using element_type = ::VkImageType; using kind = format::kind::Enum; };
struct VkImageUsageFlags { using element_type = ::VkImageUsageFlags; using kind = format::kind::Flags; };
struct VkImageUsageFlags2CreateInfoKHR { using element_type = ::VkImageUsageFlags2CreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_USAGE_FLAGS_2_CREATE_INFO_KHR; };
struct VkImageUsageFlags2KHR { using element_type = ::VkImageUsageFlags2KHR; using kind = format::kind::Flags64; };
struct VkImageView { using element_type = ::VkImageView; using kind = format::kind::Handle; };
struct VkImageViewASTCDecodeModeEXT { using element_type = ::VkImageViewASTCDecodeModeEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT; };
struct VkImageViewAddressPropertiesNVX { using element_type = ::VkImageViewAddressPropertiesNVX; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX; };
struct VkImageViewCaptureDescriptorDataInfoEXT { using element_type = ::VkImageViewCaptureDescriptorDataInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT; };
struct VkImageViewCreateFlags { using element_type = ::VkImageViewCreateFlags; using kind = format::kind::Flags; };
struct VkImageViewCreateInfo { using element_type = ::VkImageViewCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO; };
struct VkImageViewHandleInfoNVX { using element_type = ::VkImageViewHandleInfoNVX; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX; };
struct VkImageViewMinLodCreateInfoEXT { using element_type = ::VkImageViewMinLodCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT; };
struct VkImageViewSampleWeightCreateInfoQCOM { using element_type = ::VkImageViewSampleWeightCreateInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM; };
struct VkImageViewSlicedCreateInfoEXT { using element_type = ::VkImageViewSlicedCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT; };
struct VkImageViewType { using element_type = ::VkImageViewType; using kind = format::kind::Enum; };
struct VkImageViewUsage2CreateInfoKHR { using element_type = ::VkImageViewUsage2CreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_2_CREATE_INFO_KHR; };
struct VkImageViewUsageCreateInfo { using element_type = ::VkImageViewUsageCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO; };
struct VkImportAndroidHardwareBufferInfoANDROID { using element_type = ::VkImportAndroidHardwareBufferInfoANDROID; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID; };
struct VkImportFenceFdInfoKHR { using element_type = ::VkImportFenceFdInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR; };
struct VkImportFenceWin32HandleInfoKHR { using element_type = ::VkImportFenceWin32HandleInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR; };
struct VkImportMemoryFdInfoKHR { using element_type = ::VkImportMemoryFdInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR; };
struct VkImportMemoryHostPointerInfoEXT { using element_type = ::VkImportMemoryHostPointerInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT; };
struct VkImportMemoryMetalHandleInfoEXT { using element_type = ::VkImportMemoryMetalHandleInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT; };
struct VkImportMemoryWin32HandleInfoKHR { using element_type = ::VkImportMemoryWin32HandleInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR; };
struct VkImportMemoryWin32HandleInfoNV { using element_type = ::VkImportMemoryWin32HandleInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV; };
struct VkImportMemoryZirconHandleInfoFUCHSIA { using element_type = ::VkImportMemoryZirconHandleInfoFUCHSIA; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA; };
struct VkImportSemaphoreFdInfoKHR { using element_type = ::VkImportSemaphoreFdInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR; };
struct VkImportSemaphoreWin32HandleInfoKHR { using element_type = ::VkImportSemaphoreWin32HandleInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR; };
struct VkImportSemaphoreZirconHandleInfoFUCHSIA { using element_type = ::VkImportSemaphoreZirconHandleInfoFUCHSIA; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA; };
struct VkIndexType { using element_type = ::VkIndexType; using kind = format::kind::Enum; };
struct VkIndirectCommandsExecutionSetTokenEXT { using element_type = ::VkIndirectCommandsExecutionSetTokenEXT; using kind = format::kind::Struct; };
struct VkIndirectCommandsIndexBufferTokenEXT { using element_type = ::VkIndirectCommandsIndexBufferTokenEXT; using kind = format::kind::Struct; };
struct VkIndirectCommandsInputModeFlagBitsEXT { using element_type = ::VkIndirectCommandsInputModeFlagBitsEXT; using kind = format::kind::Enum; };
struct VkIndirectCommandsInputModeFlagsEXT { using element_type = ::VkIndirectCommandsInputModeFlagsEXT; using kind = format::kind::Flags; };
struct VkIndirectCommandsLayoutCreateInfoEXT { using element_type = ::VkIndirectCommandsLayoutCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_EXT; };
struct VkIndirectCommandsLayoutCreateInfoNV { using element_type = ::VkIndirectCommandsLayoutCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV; };
struct VkIndirectCommandsLayoutEXT { using element_type = ::VkIndirectCommandsLayoutEXT; using kind = format::kind::Handle; };
struct VkIndirectCommandsLayoutNV { using element_type = ::VkIndirectCommandsLayoutNV; using kind = format::kind::Handle; };
struct VkIndirectCommandsLayoutTokenEXT { using element_type = ::VkIndirectCommandsLayoutTokenEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_EXT; };
struct VkIndirectCommandsLayoutTokenNV { using element_type = ::VkIndirectCommandsLayoutTokenNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV; };
struct VkIndirectCommandsLayoutUsageFlagsEXT { using element_type = ::VkIndirectCommandsLayoutUsageFlagsEXT; using kind = format::kind::Flags; };
struct VkIndirectCommandsLayoutUsageFlagsNV { using element_type = ::VkIndirectCommandsLayoutUsageFlagsNV; using kind = format::kind::Flags; };
struct VkIndirectCommandsPushConstantTokenEXT { using element_type = ::VkIndirectCommandsPushConstantTokenEXT; using kind = format::kind::Struct; };
struct VkIndirectCommandsStreamNV { using element_type = ::VkIndirectCommandsStreamNV; using kind = format::kind::Struct; };
struct VkIndirectCommandsTokenTypeNV { using element_type = ::VkIndirectCommandsTokenTypeNV; using kind = format::kind::Enum; };
struct VkIndirectCommandsVertexBufferTokenEXT { using element_type = ::VkIndirectCommandsVertexBufferTokenEXT; using kind = format::kind::Struct; };
struct VkIndirectExecutionSetCreateInfoEXT { using element_type = ::VkIndirectExecutionSetCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_CREATE_INFO_EXT; };
struct VkIndirectExecutionSetEXT { using element_type = ::VkIndirectExecutionSetEXT; using kind = format::kind::Handle; };
struct VkIndirectExecutionSetInfoTypeEXT { using element_type = ::VkIndirectExecutionSetInfoTypeEXT; using kind = format::kind::Enum; };
struct VkIndirectExecutionSetPipelineInfoEXT { using element_type = ::VkIndirectExecutionSetPipelineInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT; };
struct VkIndirectExecutionSetShaderInfoEXT { using element_type = ::VkIndirectExecutionSetShaderInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT; };
struct VkIndirectExecutionSetShaderLayoutInfoEXT { using element_type = ::VkIndirectExecutionSetShaderLayoutInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT; };
struct VkIndirectStateFlagsNV { using element_type = ::VkIndirectStateFlagsNV; using kind = format::kind::Flags; };
struct VkInitializePerformanceApiInfoINTEL { using element_type = ::VkInitializePerformanceApiInfoINTEL; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL; };
struct VkInputAttachmentAspectReference { using element_type = ::VkInputAttachmentAspectReference; using kind = format::kind::Struct; };
struct VkInstance { using element_type = ::VkInstance; using kind = format::kind::Handle; };
struct VkInstanceCreateFlags { using element_type = ::VkInstanceCreateFlags; using kind = format::kind::Flags; };
struct VkInstanceCreateInfo { using element_type = ::VkInstanceCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO; };
struct VkLatencyMarkerNV { using element_type = ::VkLatencyMarkerNV; using kind = format::kind::Enum; };
struct VkLatencySleepInfoNV { using element_type = ::VkLatencySleepInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV; };
struct VkLatencySleepModeInfoNV { using element_type = ::VkLatencySleepModeInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV; };
struct VkLatencySubmissionPresentIdNV { using element_type = ::VkLatencySubmissionPresentIdNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV; };
struct VkLatencySurfaceCapabilitiesNV { using element_type = ::VkLatencySurfaceCapabilitiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV; };
struct VkLatencyTimingsFrameReportNV { using element_type = ::VkLatencyTimingsFrameReportNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV; };
struct VkLayerProperties { using element_type = ::VkLayerProperties; using kind = format::kind::Struct; };
struct VkLayerSettingEXT { using element_type = ::VkLayerSettingEXT; using kind = format::kind::Struct; };
struct VkLayerSettingsCreateInfoEXT { using element_type = ::VkLayerSettingsCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT; };
struct VkLayeredDriverUnderlyingApiMSFT { using element_type = ::VkLayeredDriverUnderlyingApiMSFT; using kind = format::kind::Enum; };
struct VkLineRasterizationMode { using element_type = ::VkLineRasterizationMode; using kind = format::kind::Enum; };
struct VkLogicOp { using element_type = ::VkLogicOp; using kind = format::kind::Enum; };
struct VkMacOSSurfaceCreateFlagsMVK { using element_type = ::VkMacOSSurfaceCreateFlagsMVK; using kind = format::kind::Flags; };
struct VkMacOSSurfaceCreateInfoMVK { using element_type = ::VkMacOSSurfaceCreateInfoMVK; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK; };
struct VkMappedMemoryRange { using element_type = ::VkMappedMemoryRange; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE; };
struct VkMemoryAllocateFlags { using element_type = ::VkMemoryAllocateFlags; using kind = format::kind::Flags; };
struct VkMemoryAllocateFlagsInfo { using element_type = ::VkMemoryAllocateFlagsInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO; };
struct VkMemoryAllocateInfo { using element_type = ::VkMemoryAllocateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO; };
struct VkMemoryBarrier { using element_type = ::VkMemoryBarrier; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_BARRIER; };
struct VkMemoryBarrier2 { using element_type = ::VkMemoryBarrier2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_BARRIER_2; };
struct VkMemoryBarrierAccessFlags3KHR { using element_type = ::VkMemoryBarrierAccessFlags3KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR; };
struct VkMemoryDecompressionMethodFlagsEXT { using element_type = ::VkMemoryDecompressionMethodFlagsEXT; using kind = format::kind::Flags64; };
struct VkMemoryDedicatedAllocateInfo { using element_type = ::VkMemoryDedicatedAllocateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO; };
struct VkMemoryDedicatedAllocateInfoTensorARM { using element_type = ::VkMemoryDedicatedAllocateInfoTensorARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_TENSOR_ARM; };
struct VkMemoryDedicatedRequirements { using element_type = ::VkMemoryDedicatedRequirements; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS; };
struct VkMemoryFdPropertiesKHR { using element_type = ::VkMemoryFdPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR; };
struct VkMemoryGetAndroidHardwareBufferInfoANDROID { using element_type = ::VkMemoryGetAndroidHardwareBufferInfoANDROID; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID; };
struct VkMemoryGetFdInfoKHR { using element_type = ::VkMemoryGetFdInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR; };
struct VkMemoryGetMetalHandleInfoEXT { using element_type = ::VkMemoryGetMetalHandleInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT; };
struct VkMemoryGetRemoteAddressInfoNV { using element_type = ::VkMemoryGetRemoteAddressInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV; };
struct VkMemoryGetWin32HandleInfoKHR { using element_type = ::VkMemoryGetWin32HandleInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR; };
struct VkMemoryGetZirconHandleInfoFUCHSIA { using element_type = ::VkMemoryGetZirconHandleInfoFUCHSIA; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA; };
struct VkMemoryHeap { using element_type = ::VkMemoryHeap; using kind = format::kind::Struct; };
struct VkMemoryHeapFlags { using element_type = ::VkMemoryHeapFlags; using kind = format::kind::Flags; };
struct VkMemoryHostPointerPropertiesEXT { using element_type = ::VkMemoryHostPointerPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT; };
struct VkMemoryMapFlags { using element_type = ::VkMemoryMapFlags; using kind = format::kind::Flags; };
struct VkMemoryMapInfo { using element_type = ::VkMemoryMapInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_MAP_INFO; };
struct VkMemoryMapPlacedInfoEXT { using element_type = ::VkMemoryMapPlacedInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT; };
struct VkMemoryMarkerInfoAMD { using element_type = ::VkMemoryMarkerInfoAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_MARKER_INFO_AMD; };
struct VkMemoryMetalHandlePropertiesEXT { using element_type = ::VkMemoryMetalHandlePropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT; };
struct VkMemoryOpaqueCaptureAddressAllocateInfo { using element_type = ::VkMemoryOpaqueCaptureAddressAllocateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO; };
struct VkMemoryOverallocationBehaviorAMD { using element_type = ::VkMemoryOverallocationBehaviorAMD; using kind = format::kind::Enum; };
struct VkMemoryPriorityAllocateInfoEXT { using element_type = ::VkMemoryPriorityAllocateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT; };
struct VkMemoryPropertyFlags { using element_type = ::VkMemoryPropertyFlags; using kind = format::kind::Flags; };
struct VkMemoryRangeBarrierKHR { using element_type = ::VkMemoryRangeBarrierKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_RANGE_BARRIER_KHR; };
struct VkMemoryRangeBarriersInfoKHR { using element_type = ::VkMemoryRangeBarriersInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_RANGE_BARRIERS_INFO_KHR; };
struct VkMemoryRequirements { using element_type = ::VkMemoryRequirements; using kind = format::kind::Struct; };
struct VkMemoryRequirements2 { using element_type = ::VkMemoryRequirements2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2; };
struct VkMemoryToImageCopy { using element_type = ::VkMemoryToImageCopy; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY; };
struct VkMemoryType { using element_type = ::VkMemoryType; using kind = format::kind::Struct; };
struct VkMemoryUnmapFlags { using element_type = ::VkMemoryUnmapFlags; using kind = format::kind::Flags; };
struct VkMemoryUnmapInfo { using element_type = ::VkMemoryUnmapInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO; };
struct VkMemoryWin32HandlePropertiesKHR { using element_type = ::VkMemoryWin32HandlePropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR; };
struct VkMemoryZirconHandlePropertiesFUCHSIA { using element_type = ::VkMemoryZirconHandlePropertiesFUCHSIA; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA; };
struct VkMetalSurfaceCreateFlagsEXT { using element_type = ::VkMetalSurfaceCreateFlagsEXT; using kind = format::kind::Flags; };
struct VkMetalSurfaceCreateInfoEXT { using element_type = ::VkMetalSurfaceCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT; };
struct VkMicromapBuildInfoEXT { using element_type = ::VkMicromapBuildInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT; };
struct VkMicromapBuildSizesInfoEXT { using element_type = ::VkMicromapBuildSizesInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT; };
struct VkMicromapCreateFlagsEXT { using element_type = ::VkMicromapCreateFlagsEXT; using kind = format::kind::Flags; };
struct VkMicromapCreateInfoEXT { using element_type = ::VkMicromapCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT; };
struct VkMicromapEXT { using element_type = ::VkMicromapEXT; using kind = format::kind::Handle; };
struct VkMicromapTriangleKHR { using element_type = ::VkMicromapTriangleKHR; using kind = format::kind::Struct; };
struct VkMicromapTypeEXT { using element_type = ::VkMicromapTypeEXT; using kind = format::kind::Enum; };
struct VkMicromapUsageEXT { using element_type = ::VkMicromapUsageEXT; using kind = format::kind::Struct; };
struct VkMicromapUsageKHR { using element_type = ::VkMicromapUsageKHR; using kind = format::kind::Struct; };
struct VkMicromapVersionInfoEXT { using element_type = ::VkMicromapVersionInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT; };
struct VkMultiDrawIndexedInfoEXT { using element_type = ::VkMultiDrawIndexedInfoEXT; using kind = format::kind::Struct; };
struct VkMultiDrawInfoEXT { using element_type = ::VkMultiDrawInfoEXT; using kind = format::kind::Struct; };
struct VkMultisamplePropertiesEXT { using element_type = ::VkMultisamplePropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT; };
struct VkMultisampledRenderToSingleSampledInfoEXT { using element_type = ::VkMultisampledRenderToSingleSampledInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT; };
struct VkMultiviewPerViewAttributesInfoNVX { using element_type = ::VkMultiviewPerViewAttributesInfoNVX; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX; };
struct VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM { using element_type = ::VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM; };
struct VkMutableDescriptorTypeCreateInfoEXT { using element_type = ::VkMutableDescriptorTypeCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT; };
struct VkMutableDescriptorTypeListEXT { using element_type = ::VkMutableDescriptorTypeListEXT; using kind = format::kind::Struct; };
struct VkNeuralAcceleratorStatisticsModeARM { using element_type = ::VkNeuralAcceleratorStatisticsModeARM; using kind = format::kind::Enum; };
struct VkObjectType { using element_type = ::VkObjectType; using kind = format::kind::Enum; };
struct VkOffset2D { using element_type = ::VkOffset2D; using kind = format::kind::Struct; };
struct VkOffset3D { using element_type = ::VkOffset3D; using kind = format::kind::Struct; };
struct VkOpacityMicromapFormatKHR { using element_type = ::VkOpacityMicromapFormatKHR; using kind = format::kind::Enum; };
struct VkOpaqueCaptureDescriptorDataCreateInfoEXT { using element_type = ::VkOpaqueCaptureDescriptorDataCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT; };
struct VkOpticalFlowExecuteFlagsNV { using element_type = ::VkOpticalFlowExecuteFlagsNV; using kind = format::kind::Flags; };
struct VkOpticalFlowExecuteInfoNV { using element_type = ::VkOpticalFlowExecuteInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV; };
struct VkOpticalFlowGridSizeFlagsNV { using element_type = ::VkOpticalFlowGridSizeFlagsNV; using kind = format::kind::Flags; };
struct VkOpticalFlowImageFormatInfoNV { using element_type = ::VkOpticalFlowImageFormatInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV; };
struct VkOpticalFlowImageFormatPropertiesNV { using element_type = ::VkOpticalFlowImageFormatPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV; };
struct VkOpticalFlowPerformanceLevelNV { using element_type = ::VkOpticalFlowPerformanceLevelNV; using kind = format::kind::Enum; };
struct VkOpticalFlowSessionBindingPointNV { using element_type = ::VkOpticalFlowSessionBindingPointNV; using kind = format::kind::Enum; };
struct VkOpticalFlowSessionCreateFlagsNV { using element_type = ::VkOpticalFlowSessionCreateFlagsNV; using kind = format::kind::Flags; };
struct VkOpticalFlowSessionCreateInfoNV { using element_type = ::VkOpticalFlowSessionCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV; };
struct VkOpticalFlowSessionCreatePrivateDataInfoNV { using element_type = ::VkOpticalFlowSessionCreatePrivateDataInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV; };
struct VkOpticalFlowSessionNV { using element_type = ::VkOpticalFlowSessionNV; using kind = format::kind::Handle; };
struct VkOpticalFlowUsageFlagsNV { using element_type = ::VkOpticalFlowUsageFlagsNV; using kind = format::kind::Flags; };
struct VkOutOfBandQueueTypeInfoNV { using element_type = ::VkOutOfBandQueueTypeInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV; };
struct VkOutOfBandQueueTypeNV { using element_type = ::VkOutOfBandQueueTypeNV; using kind = format::kind::Enum; };
struct VkPartitionedAccelerationStructureFlagsNV { using element_type = ::VkPartitionedAccelerationStructureFlagsNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV; };
struct VkPartitionedAccelerationStructureInstanceFlagsNV { using element_type = ::VkPartitionedAccelerationStructureInstanceFlagsNV; using kind = format::kind::Flags; };
struct VkPartitionedAccelerationStructureInstancesInputNV { using element_type = ::VkPartitionedAccelerationStructureInstancesInputNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCES_INPUT_NV; };
struct VkPartitionedAccelerationStructureOpTypeNV { using element_type = ::VkPartitionedAccelerationStructureOpTypeNV; using kind = format::kind::Enum; };
struct VkPartitionedAccelerationStructureUpdateInstanceDataNV { using element_type = ::VkPartitionedAccelerationStructureUpdateInstanceDataNV; using kind = format::kind::Struct; };
struct VkPartitionedAccelerationStructureWriteInstanceDataNV { using element_type = ::VkPartitionedAccelerationStructureWriteInstanceDataNV; using kind = format::kind::Struct; };
struct VkPartitionedAccelerationStructureWritePartitionTranslationDataNV { using element_type = ::VkPartitionedAccelerationStructureWritePartitionTranslationDataNV; using kind = format::kind::Struct; };
struct VkPastPresentationTimingEXT { using element_type = ::VkPastPresentationTimingEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_EXT; };
struct VkPastPresentationTimingFlagsEXT { using element_type = ::VkPastPresentationTimingFlagsEXT; using kind = format::kind::Flags; };
struct VkPastPresentationTimingGOOGLE { using element_type = ::VkPastPresentationTimingGOOGLE; using kind = format::kind::Struct; };
struct VkPastPresentationTimingInfoEXT { using element_type = ::VkPastPresentationTimingInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_INFO_EXT; };
struct VkPastPresentationTimingPropertiesEXT { using element_type = ::VkPastPresentationTimingPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_PROPERTIES_EXT; };
struct VkPeerMemoryFeatureFlags { using element_type = ::VkPeerMemoryFeatureFlags; using kind = format::kind::Flags; };
struct VkPerTileBeginInfoQCOM { using element_type = ::VkPerTileBeginInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PER_TILE_BEGIN_INFO_QCOM; };
struct VkPerTileEndInfoQCOM { using element_type = ::VkPerTileEndInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PER_TILE_END_INFO_QCOM; };
struct VkPerfHintInfoQCOM { using element_type = ::VkPerfHintInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PERF_HINT_INFO_QCOM; };
struct VkPerfHintTypeQCOM { using element_type = ::VkPerfHintTypeQCOM; using kind = format::kind::Enum; };
struct VkPerformanceConfigurationAcquireInfoINTEL { using element_type = ::VkPerformanceConfigurationAcquireInfoINTEL; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL; };
struct VkPerformanceConfigurationINTEL { using element_type = ::VkPerformanceConfigurationINTEL; using kind = format::kind::Handle; };
struct VkPerformanceConfigurationTypeINTEL { using element_type = ::VkPerformanceConfigurationTypeINTEL; using kind = format::kind::Enum; };
struct VkPerformanceCounterARM { using element_type = ::VkPerformanceCounterARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_ARM; };
struct VkPerformanceCounterDescriptionARM { using element_type = ::VkPerformanceCounterDescriptionARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_ARM; };
struct VkPerformanceCounterDescriptionFlagsARM { using element_type = ::VkPerformanceCounterDescriptionFlagsARM; using kind = format::kind::Flags; };
struct VkPerformanceCounterDescriptionFlagsKHR { using element_type = ::VkPerformanceCounterDescriptionFlagsKHR; using kind = format::kind::Flags; };
struct VkPerformanceCounterDescriptionKHR { using element_type = ::VkPerformanceCounterDescriptionKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR; };
struct VkPerformanceCounterKHR { using element_type = ::VkPerformanceCounterKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR; };
struct VkPerformanceCounterScopeKHR { using element_type = ::VkPerformanceCounterScopeKHR; using kind = format::kind::Enum; };
struct VkPerformanceCounterStorageKHR { using element_type = ::VkPerformanceCounterStorageKHR; using kind = format::kind::Enum; };
struct VkPerformanceCounterUnitKHR { using element_type = ::VkPerformanceCounterUnitKHR; using kind = format::kind::Enum; };
struct VkPerformanceMarkerInfoINTEL { using element_type = ::VkPerformanceMarkerInfoINTEL; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL; };
struct VkPerformanceOverrideInfoINTEL { using element_type = ::VkPerformanceOverrideInfoINTEL; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL; };
struct VkPerformanceOverrideTypeINTEL { using element_type = ::VkPerformanceOverrideTypeINTEL; using kind = format::kind::Enum; };
struct VkPerformanceParameterTypeINTEL { using element_type = ::VkPerformanceParameterTypeINTEL; using kind = format::kind::Enum; };
struct VkPerformanceQuerySubmitInfoKHR { using element_type = ::VkPerformanceQuerySubmitInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR; };
struct VkPerformanceStreamMarkerInfoINTEL { using element_type = ::VkPerformanceStreamMarkerInfoINTEL; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL; };
struct VkPerformanceValueINTEL { using element_type = ::VkPerformanceValueINTEL; using kind = format::kind::Struct; };
struct VkPhysicalDevice { using element_type = ::VkPhysicalDevice; using kind = format::kind::Handle; };
struct VkPhysicalDevice16BitStorageFeatures { using element_type = ::VkPhysicalDevice16BitStorageFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES; };
struct VkPhysicalDevice4444FormatsFeaturesEXT { using element_type = ::VkPhysicalDevice4444FormatsFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT; };
struct VkPhysicalDevice8BitStorageFeatures { using element_type = ::VkPhysicalDevice8BitStorageFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES; };
struct VkPhysicalDeviceASTCDecodeFeaturesEXT { using element_type = ::VkPhysicalDeviceASTCDecodeFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT; };
struct VkPhysicalDeviceAccelerationStructureFeaturesKHR { using element_type = ::VkPhysicalDeviceAccelerationStructureFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR; };
struct VkPhysicalDeviceAccelerationStructurePropertiesKHR { using element_type = ::VkPhysicalDeviceAccelerationStructurePropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR; };
struct VkPhysicalDeviceAddressBindingReportFeaturesEXT { using element_type = ::VkPhysicalDeviceAddressBindingReportFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT; };
struct VkPhysicalDeviceAmigoProfilingFeaturesSEC { using element_type = ::VkPhysicalDeviceAmigoProfilingFeaturesSEC; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC; };
struct VkPhysicalDeviceAntiLagFeaturesAMD { using element_type = ::VkPhysicalDeviceAntiLagFeaturesAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD; };
struct VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT { using element_type = ::VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT; };
struct VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT { using element_type = ::VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT; };
struct VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT { using element_type = ::VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT; };
struct VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT { using element_type = ::VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT; };
struct VkPhysicalDeviceBorderColorSwizzleFeaturesEXT { using element_type = ::VkPhysicalDeviceBorderColorSwizzleFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT; };
struct VkPhysicalDeviceBufferDeviceAddressAllocationAlignmentFeaturesVALVE { using element_type = ::VkPhysicalDeviceBufferDeviceAddressAllocationAlignmentFeaturesVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_ALLOCATION_ALIGNMENT_FEATURES_VALVE; };
struct VkPhysicalDeviceBufferDeviceAddressAllocationAlignmentPropertiesVALVE { using element_type = ::VkPhysicalDeviceBufferDeviceAddressAllocationAlignmentPropertiesVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_ALLOCATION_ALIGNMENT_PROPERTIES_VALVE; };
struct VkPhysicalDeviceBufferDeviceAddressFeatures { using element_type = ::VkPhysicalDeviceBufferDeviceAddressFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES; };
struct VkPhysicalDeviceBufferDeviceAddressFeaturesEXT { using element_type = ::VkPhysicalDeviceBufferDeviceAddressFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT; };
struct VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI { using element_type = ::VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI; };
struct VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI { using element_type = ::VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI; };
struct VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI { using element_type = ::VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI; };
struct VkPhysicalDeviceCoherentMemoryFeaturesAMD { using element_type = ::VkPhysicalDeviceCoherentMemoryFeaturesAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD; };
struct VkPhysicalDeviceColorWriteEnableFeaturesEXT { using element_type = ::VkPhysicalDeviceColorWriteEnableFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT; };
struct VkPhysicalDeviceCommandBufferInheritanceFeaturesNV { using element_type = ::VkPhysicalDeviceCommandBufferInheritanceFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV; };
struct VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV { using element_type = ::VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_OCCUPANCY_PRIORITY_FEATURES_NV; };
struct VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR { using element_type = ::VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR; };
struct VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR { using element_type = ::VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR; };
struct VkPhysicalDeviceConditionalRenderingFeaturesEXT { using element_type = ::VkPhysicalDeviceConditionalRenderingFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT; };
struct VkPhysicalDeviceConservativeRasterizationPropertiesEXT { using element_type = ::VkPhysicalDeviceConservativeRasterizationPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT; };
struct VkPhysicalDeviceCooperativeMatrix2FeaturesNV { using element_type = ::VkPhysicalDeviceCooperativeMatrix2FeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV; };
struct VkPhysicalDeviceCooperativeMatrix2PropertiesNV { using element_type = ::VkPhysicalDeviceCooperativeMatrix2PropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV; };
struct VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM { using element_type = ::VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_CONVERSION_FEATURES_QCOM; };
struct VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV { using element_type = ::VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_DECODE_VECTOR_FEATURES_NV; };
struct VkPhysicalDeviceCooperativeMatrixFeaturesKHR { using element_type = ::VkPhysicalDeviceCooperativeMatrixFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR; };
struct VkPhysicalDeviceCooperativeMatrixFeaturesNV { using element_type = ::VkPhysicalDeviceCooperativeMatrixFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV; };
struct VkPhysicalDeviceCooperativeMatrixInfo2EXT { using element_type = ::VkPhysicalDeviceCooperativeMatrixInfo2EXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_INFO_2_EXT; };
struct VkPhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT { using element_type = ::VkPhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_MAINTENANCE_1_FEATURES_EXT; };
struct VkPhysicalDeviceCooperativeMatrixPropertiesKHR { using element_type = ::VkPhysicalDeviceCooperativeMatrixPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR; };
struct VkPhysicalDeviceCooperativeMatrixPropertiesNV { using element_type = ::VkPhysicalDeviceCooperativeMatrixPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV; };
struct VkPhysicalDeviceCooperativeVectorFeaturesNV { using element_type = ::VkPhysicalDeviceCooperativeVectorFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV; };
struct VkPhysicalDeviceCooperativeVectorPropertiesNV { using element_type = ::VkPhysicalDeviceCooperativeVectorPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV; };
struct VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR { using element_type = ::VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR; };
struct VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR { using element_type = ::VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_KHR; };
struct VkPhysicalDeviceCornerSampledImageFeaturesNV { using element_type = ::VkPhysicalDeviceCornerSampledImageFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV; };
struct VkPhysicalDeviceCoverageReductionModeFeaturesNV { using element_type = ::VkPhysicalDeviceCoverageReductionModeFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV; };
struct VkPhysicalDeviceCubicClampFeaturesQCOM { using element_type = ::VkPhysicalDeviceCubicClampFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM; };
struct VkPhysicalDeviceCubicWeightsFeaturesQCOM { using element_type = ::VkPhysicalDeviceCubicWeightsFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM; };
struct VkPhysicalDeviceCustomBorderColorFeaturesEXT { using element_type = ::VkPhysicalDeviceCustomBorderColorFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT; };
struct VkPhysicalDeviceCustomBorderColorPropertiesEXT { using element_type = ::VkPhysicalDeviceCustomBorderColorPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT; };
struct VkPhysicalDeviceCustomResolveFeaturesEXT { using element_type = ::VkPhysicalDeviceCustomResolveFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_RESOLVE_FEATURES_EXT; };
struct VkPhysicalDeviceDataGraphFeaturesARM { using element_type = ::VkPhysicalDeviceDataGraphFeaturesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM; };
struct VkPhysicalDeviceDataGraphModelFeaturesQCOM { using element_type = ::VkPhysicalDeviceDataGraphModelFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_MODEL_FEATURES_QCOM; };
struct VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM { using element_type = ::VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_NEURAL_ACCELERATOR_STATISTICS_FEATURES_ARM; };
struct VkPhysicalDeviceDataGraphOperationSupportARM { using element_type = ::VkPhysicalDeviceDataGraphOperationSupportARM; using kind = format::kind::Struct; };
struct VkPhysicalDeviceDataGraphOperationTypeARM { using element_type = ::VkPhysicalDeviceDataGraphOperationTypeARM; using kind = format::kind::Enum; };
struct VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM { using element_type = ::VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_OPTICAL_FLOW_FEATURES_ARM; };
struct VkPhysicalDeviceDataGraphProcessingEngineARM { using element_type = ::VkPhysicalDeviceDataGraphProcessingEngineARM; using kind = format::kind::Struct; };
struct VkPhysicalDeviceDataGraphProcessingEngineTypeARM { using element_type = ::VkPhysicalDeviceDataGraphProcessingEngineTypeARM; using kind = format::kind::Enum; };
struct VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV { using element_type = ::VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV; };
struct VkPhysicalDeviceDepthBiasControlFeaturesEXT { using element_type = ::VkPhysicalDeviceDepthBiasControlFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT; };
struct VkPhysicalDeviceDepthClampControlFeaturesEXT { using element_type = ::VkPhysicalDeviceDepthClampControlFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT; };
struct VkPhysicalDeviceDepthClampZeroOneFeaturesKHR { using element_type = ::VkPhysicalDeviceDepthClampZeroOneFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR; };
struct VkPhysicalDeviceDepthClipControlFeaturesEXT { using element_type = ::VkPhysicalDeviceDepthClipControlFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT; };
struct VkPhysicalDeviceDepthClipEnableFeaturesEXT { using element_type = ::VkPhysicalDeviceDepthClipEnableFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT; };
struct VkPhysicalDeviceDepthStencilResolveProperties { using element_type = ::VkPhysicalDeviceDepthStencilResolveProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES; };
struct VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT { using element_type = ::VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT; };
struct VkPhysicalDeviceDescriptorBufferFeaturesEXT { using element_type = ::VkPhysicalDeviceDescriptorBufferFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT; };
struct VkPhysicalDeviceDescriptorBufferPropertiesEXT { using element_type = ::VkPhysicalDeviceDescriptorBufferPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT; };
struct VkPhysicalDeviceDescriptorBufferTensorFeaturesARM { using element_type = ::VkPhysicalDeviceDescriptorBufferTensorFeaturesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_FEATURES_ARM; };
struct VkPhysicalDeviceDescriptorBufferTensorPropertiesARM { using element_type = ::VkPhysicalDeviceDescriptorBufferTensorPropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_PROPERTIES_ARM; };
struct VkPhysicalDeviceDescriptorIndexingFeatures { using element_type = ::VkPhysicalDeviceDescriptorIndexingFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES; };
struct VkPhysicalDeviceDescriptorIndexingProperties { using element_type = ::VkPhysicalDeviceDescriptorIndexingProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES; };
struct VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV { using element_type = ::VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV; };
struct VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE { using element_type = ::VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE; };
struct VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR { using element_type = ::VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_ADDRESS_COMMANDS_FEATURES_KHR; };
struct VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV { using element_type = ::VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV; };
struct VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT { using element_type = ::VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT; };
struct VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV { using element_type = ::VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV; };
struct VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT { using element_type = ::VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT; };
struct VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV { using element_type = ::VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV; };
struct VkPhysicalDeviceDeviceMemoryReportFeaturesEXT { using element_type = ::VkPhysicalDeviceDeviceMemoryReportFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT; };
struct VkPhysicalDeviceDiagnosticsConfigFeaturesNV { using element_type = ::VkPhysicalDeviceDiagnosticsConfigFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV; };
struct VkPhysicalDeviceDiscardRectanglePropertiesEXT { using element_type = ::VkPhysicalDeviceDiscardRectanglePropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT; };
struct VkPhysicalDeviceDisplacementMicromapFeaturesNV { using element_type = ::VkPhysicalDeviceDisplacementMicromapFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV; };
struct VkPhysicalDeviceDisplacementMicromapPropertiesNV { using element_type = ::VkPhysicalDeviceDisplacementMicromapPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV; };
struct VkPhysicalDeviceDriverProperties { using element_type = ::VkPhysicalDeviceDriverProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES; };
struct VkPhysicalDeviceDrmPropertiesEXT { using element_type = ::VkPhysicalDeviceDrmPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT; };
struct VkPhysicalDeviceDynamicRenderingFeatures { using element_type = ::VkPhysicalDeviceDynamicRenderingFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES; };
struct VkPhysicalDeviceDynamicRenderingLocalReadFeatures { using element_type = ::VkPhysicalDeviceDynamicRenderingLocalReadFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES; };
struct VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT { using element_type = ::VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT; };
struct VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM { using element_type = ::VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ELAPSED_TIMER_QUERY_FEATURES_QCOM; };
struct VkPhysicalDeviceExclusiveScissorFeaturesNV { using element_type = ::VkPhysicalDeviceExclusiveScissorFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV; };
struct VkPhysicalDeviceExtendedDynamicState2FeaturesEXT { using element_type = ::VkPhysicalDeviceExtendedDynamicState2FeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT; };
struct VkPhysicalDeviceExtendedDynamicState3FeaturesEXT { using element_type = ::VkPhysicalDeviceExtendedDynamicState3FeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT; };
struct VkPhysicalDeviceExtendedDynamicState3PropertiesEXT { using element_type = ::VkPhysicalDeviceExtendedDynamicState3PropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT; };
struct VkPhysicalDeviceExtendedDynamicStateFeaturesEXT { using element_type = ::VkPhysicalDeviceExtendedDynamicStateFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT; };
struct VkPhysicalDeviceExtendedFlagsFeaturesKHR { using element_type = ::VkPhysicalDeviceExtendedFlagsFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_FLAGS_FEATURES_KHR; };
struct VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV { using element_type = ::VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV; };
struct VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV { using element_type = ::VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV; };
struct VkPhysicalDeviceExternalBufferInfo { using element_type = ::VkPhysicalDeviceExternalBufferInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO; };
struct VkPhysicalDeviceExternalFenceInfo { using element_type = ::VkPhysicalDeviceExternalFenceInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO; };
struct VkPhysicalDeviceExternalFormatResolveFeaturesANDROID { using element_type = ::VkPhysicalDeviceExternalFormatResolveFeaturesANDROID; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID; };
struct VkPhysicalDeviceExternalFormatResolvePropertiesANDROID { using element_type = ::VkPhysicalDeviceExternalFormatResolvePropertiesANDROID; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID; };
struct VkPhysicalDeviceExternalImageFormatInfo { using element_type = ::VkPhysicalDeviceExternalImageFormatInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO; };
struct VkPhysicalDeviceExternalMemoryHostPropertiesEXT { using element_type = ::VkPhysicalDeviceExternalMemoryHostPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT; };
struct VkPhysicalDeviceExternalMemoryRDMAFeaturesNV { using element_type = ::VkPhysicalDeviceExternalMemoryRDMAFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV; };
struct VkPhysicalDeviceExternalSemaphoreInfo { using element_type = ::VkPhysicalDeviceExternalSemaphoreInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO; };
struct VkPhysicalDeviceExternalTensorInfoARM { using element_type = ::VkPhysicalDeviceExternalTensorInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_TENSOR_INFO_ARM; };
struct VkPhysicalDeviceFaultFeaturesEXT { using element_type = ::VkPhysicalDeviceFaultFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT; };
struct VkPhysicalDeviceFaultFeaturesKHR { using element_type = ::VkPhysicalDeviceFaultFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_KHR; };
struct VkPhysicalDeviceFaultPropertiesKHR { using element_type = ::VkPhysicalDeviceFaultPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_PROPERTIES_KHR; };
struct VkPhysicalDeviceFeatures { using element_type = ::VkPhysicalDeviceFeatures; using kind = format::kind::Struct; };
struct VkPhysicalDeviceFeatures2 { using element_type = ::VkPhysicalDeviceFeatures2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2; };
struct VkPhysicalDeviceFloatControlsProperties { using element_type = ::VkPhysicalDeviceFloatControlsProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES; };
struct VkPhysicalDeviceFormatPackFeaturesARM { using element_type = ::VkPhysicalDeviceFormatPackFeaturesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM; };
struct VkPhysicalDeviceFragmentDensityMap2FeaturesEXT { using element_type = ::VkPhysicalDeviceFragmentDensityMap2FeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT; };
struct VkPhysicalDeviceFragmentDensityMap2PropertiesEXT { using element_type = ::VkPhysicalDeviceFragmentDensityMap2PropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT; };
struct VkPhysicalDeviceFragmentDensityMapFeaturesEXT { using element_type = ::VkPhysicalDeviceFragmentDensityMapFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT; };
struct VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE { using element_type = ::VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE; };
struct VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE { using element_type = ::VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_PROPERTIES_VALVE; };
struct VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT { using element_type = ::VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT; };
struct VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT { using element_type = ::VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_EXT; };
struct VkPhysicalDeviceFragmentDensityMapPropertiesEXT { using element_type = ::VkPhysicalDeviceFragmentDensityMapPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT; };
struct VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR { using element_type = ::VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR; };
struct VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR { using element_type = ::VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR; };
struct VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT { using element_type = ::VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT; };
struct VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV { using element_type = ::VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV; };
struct VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV { using element_type = ::VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV; };
struct VkPhysicalDeviceFragmentShadingRateFeaturesKHR { using element_type = ::VkPhysicalDeviceFragmentShadingRateFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR; };
struct VkPhysicalDeviceFragmentShadingRateKHR { using element_type = ::VkPhysicalDeviceFragmentShadingRateKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR; };
struct VkPhysicalDeviceFragmentShadingRatePropertiesKHR { using element_type = ::VkPhysicalDeviceFragmentShadingRatePropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR; };
struct VkPhysicalDeviceFrameBoundaryFeaturesEXT { using element_type = ::VkPhysicalDeviceFrameBoundaryFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT; };
struct VkPhysicalDeviceGlobalPriorityQueryFeatures { using element_type = ::VkPhysicalDeviceGlobalPriorityQueryFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES; };
struct VkPhysicalDeviceGpaFeaturesAMD { using element_type = ::VkPhysicalDeviceGpaFeaturesAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GPA_FEATURES_AMD; };
struct VkPhysicalDeviceGpaProperties2AMD { using element_type = ::VkPhysicalDeviceGpaProperties2AMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GPA_PROPERTIES_2_AMD; };
struct VkPhysicalDeviceGpaPropertiesAMD { using element_type = ::VkPhysicalDeviceGpaPropertiesAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GPA_PROPERTIES_AMD; };
struct VkPhysicalDeviceGpaPropertiesFlagsAMD { using element_type = ::VkPhysicalDeviceGpaPropertiesFlagsAMD; using kind = format::kind::Flags; };
struct VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT { using element_type = ::VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT; };
struct VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT { using element_type = ::VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT; };
struct VkPhysicalDeviceGroupProperties { using element_type = ::VkPhysicalDeviceGroupProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES; };
struct VkPhysicalDeviceHdrVividFeaturesHUAWEI { using element_type = ::VkPhysicalDeviceHdrVividFeaturesHUAWEI; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI; };
struct VkPhysicalDeviceHostImageCopyFeatures { using element_type = ::VkPhysicalDeviceHostImageCopyFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES; };
struct VkPhysicalDeviceHostImageCopyProperties { using element_type = ::VkPhysicalDeviceHostImageCopyProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES; };
struct VkPhysicalDeviceHostQueryResetFeatures { using element_type = ::VkPhysicalDeviceHostQueryResetFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES; };
struct VkPhysicalDeviceIDProperties { using element_type = ::VkPhysicalDeviceIDProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES; };
struct VkPhysicalDeviceImage2DViewOf3DFeaturesEXT { using element_type = ::VkPhysicalDeviceImage2DViewOf3DFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT; };
struct VkPhysicalDeviceImageAlignmentControlFeaturesMESA { using element_type = ::VkPhysicalDeviceImageAlignmentControlFeaturesMESA; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA; };
struct VkPhysicalDeviceImageAlignmentControlPropertiesMESA { using element_type = ::VkPhysicalDeviceImageAlignmentControlPropertiesMESA; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA; };
struct VkPhysicalDeviceImageCompressionControlFeaturesEXT { using element_type = ::VkPhysicalDeviceImageCompressionControlFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT; };
struct VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT { using element_type = ::VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT; };
struct VkPhysicalDeviceImageDrmFormatModifierInfoEXT { using element_type = ::VkPhysicalDeviceImageDrmFormatModifierInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT; };
struct VkPhysicalDeviceImageFormatInfo2 { using element_type = ::VkPhysicalDeviceImageFormatInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2; };
struct VkPhysicalDeviceImageProcessing2FeaturesQCOM { using element_type = ::VkPhysicalDeviceImageProcessing2FeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM; };
struct VkPhysicalDeviceImageProcessing2PropertiesQCOM { using element_type = ::VkPhysicalDeviceImageProcessing2PropertiesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM; };
struct VkPhysicalDeviceImageProcessing3FeaturesQCOM { using element_type = ::VkPhysicalDeviceImageProcessing3FeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_3_FEATURES_QCOM; };
struct VkPhysicalDeviceImageProcessingFeaturesQCOM { using element_type = ::VkPhysicalDeviceImageProcessingFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM; };
struct VkPhysicalDeviceImageProcessingPropertiesQCOM { using element_type = ::VkPhysicalDeviceImageProcessingPropertiesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM; };
struct VkPhysicalDeviceImageRobustnessFeatures { using element_type = ::VkPhysicalDeviceImageRobustnessFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES; };
struct VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT { using element_type = ::VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT; };
struct VkPhysicalDeviceImageTilingControlFeaturesEXT { using element_type = ::VkPhysicalDeviceImageTilingControlFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_TILING_CONTROL_FEATURES_EXT; };
struct VkPhysicalDeviceImageViewImageFormatInfoEXT { using element_type = ::VkPhysicalDeviceImageViewImageFormatInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT; };
struct VkPhysicalDeviceImageViewMinLodFeaturesEXT { using element_type = ::VkPhysicalDeviceImageViewMinLodFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT; };
struct VkPhysicalDeviceImagelessFramebufferFeatures { using element_type = ::VkPhysicalDeviceImagelessFramebufferFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES; };
struct VkPhysicalDeviceIndexTypeUint8Features { using element_type = ::VkPhysicalDeviceIndexTypeUint8Features; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES; };
struct VkPhysicalDeviceInfoPropertiesINTEL { using element_type = ::VkPhysicalDeviceInfoPropertiesINTEL; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INFO_PROPERTIES_INTEL; };
struct VkPhysicalDeviceInheritedViewportScissorFeaturesNV { using element_type = ::VkPhysicalDeviceInheritedViewportScissorFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV; };
struct VkPhysicalDeviceInlineUniformBlockFeatures { using element_type = ::VkPhysicalDeviceInlineUniformBlockFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES; };
struct VkPhysicalDeviceInlineUniformBlockProperties { using element_type = ::VkPhysicalDeviceInlineUniformBlockProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES; };
struct VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR { using element_type = ::VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INTERNALLY_SYNCHRONIZED_QUEUES_FEATURES_KHR; };
struct VkPhysicalDeviceInvocationMaskFeaturesHUAWEI { using element_type = ::VkPhysicalDeviceInvocationMaskFeaturesHUAWEI; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI; };
struct VkPhysicalDeviceLayeredApiKHR { using element_type = ::VkPhysicalDeviceLayeredApiKHR; using kind = format::kind::Enum; };
struct VkPhysicalDeviceLayeredApiPropertiesKHR { using element_type = ::VkPhysicalDeviceLayeredApiPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_KHR; };
struct VkPhysicalDeviceLayeredApiPropertiesListKHR { using element_type = ::VkPhysicalDeviceLayeredApiPropertiesListKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR; };
struct VkPhysicalDeviceLayeredApiVulkanPropertiesKHR { using element_type = ::VkPhysicalDeviceLayeredApiVulkanPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR; };
struct VkPhysicalDeviceLayeredDriverPropertiesMSFT { using element_type = ::VkPhysicalDeviceLayeredDriverPropertiesMSFT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT; };
struct VkPhysicalDeviceLegacyDitheringFeaturesEXT { using element_type = ::VkPhysicalDeviceLegacyDitheringFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT; };
struct VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT { using element_type = ::VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT; };
struct VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT { using element_type = ::VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT; };
struct VkPhysicalDeviceLimits { using element_type = ::VkPhysicalDeviceLimits; using kind = format::kind::Struct; };
struct VkPhysicalDeviceLineRasterizationFeatures { using element_type = ::VkPhysicalDeviceLineRasterizationFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES; };
struct VkPhysicalDeviceLineRasterizationProperties { using element_type = ::VkPhysicalDeviceLineRasterizationProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES; };
struct VkPhysicalDeviceLinearColorAttachmentFeaturesNV { using element_type = ::VkPhysicalDeviceLinearColorAttachmentFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV; };
struct VkPhysicalDeviceMaintenance10FeaturesKHR { using element_type = ::VkPhysicalDeviceMaintenance10FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR; };
struct VkPhysicalDeviceMaintenance10PropertiesKHR { using element_type = ::VkPhysicalDeviceMaintenance10PropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_PROPERTIES_KHR; };
struct VkPhysicalDeviceMaintenance11FeaturesKHR { using element_type = ::VkPhysicalDeviceMaintenance11FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_11_FEATURES_KHR; };
struct VkPhysicalDeviceMaintenance3Properties { using element_type = ::VkPhysicalDeviceMaintenance3Properties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES; };
struct VkPhysicalDeviceMaintenance4Features { using element_type = ::VkPhysicalDeviceMaintenance4Features; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES; };
struct VkPhysicalDeviceMaintenance4Properties { using element_type = ::VkPhysicalDeviceMaintenance4Properties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES; };
struct VkPhysicalDeviceMaintenance5Features { using element_type = ::VkPhysicalDeviceMaintenance5Features; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES; };
struct VkPhysicalDeviceMaintenance5Properties { using element_type = ::VkPhysicalDeviceMaintenance5Properties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES; };
struct VkPhysicalDeviceMaintenance6Features { using element_type = ::VkPhysicalDeviceMaintenance6Features; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES; };
struct VkPhysicalDeviceMaintenance6Properties { using element_type = ::VkPhysicalDeviceMaintenance6Properties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES; };
struct VkPhysicalDeviceMaintenance7FeaturesKHR { using element_type = ::VkPhysicalDeviceMaintenance7FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR; };
struct VkPhysicalDeviceMaintenance7PropertiesKHR { using element_type = ::VkPhysicalDeviceMaintenance7PropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR; };
struct VkPhysicalDeviceMaintenance8FeaturesKHR { using element_type = ::VkPhysicalDeviceMaintenance8FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR; };
struct VkPhysicalDeviceMaintenance9FeaturesKHR { using element_type = ::VkPhysicalDeviceMaintenance9FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR; };
struct VkPhysicalDeviceMaintenance9PropertiesKHR { using element_type = ::VkPhysicalDeviceMaintenance9PropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_PROPERTIES_KHR; };
struct VkPhysicalDeviceMapMemoryPlacedFeaturesEXT { using element_type = ::VkPhysicalDeviceMapMemoryPlacedFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT; };
struct VkPhysicalDeviceMapMemoryPlacedPropertiesEXT { using element_type = ::VkPhysicalDeviceMapMemoryPlacedPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT; };
struct VkPhysicalDeviceMemoryBudgetPropertiesEXT { using element_type = ::VkPhysicalDeviceMemoryBudgetPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT; };
struct VkPhysicalDeviceMemoryDecompressionFeaturesEXT { using element_type = ::VkPhysicalDeviceMemoryDecompressionFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_EXT; };
struct VkPhysicalDeviceMemoryDecompressionPropertiesEXT { using element_type = ::VkPhysicalDeviceMemoryDecompressionPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_EXT; };
struct VkPhysicalDeviceMemoryPriorityFeaturesEXT { using element_type = ::VkPhysicalDeviceMemoryPriorityFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT; };
struct VkPhysicalDeviceMemoryProperties { using element_type = ::VkPhysicalDeviceMemoryProperties; using kind = format::kind::Struct; };
struct VkPhysicalDeviceMemoryProperties2 { using element_type = ::VkPhysicalDeviceMemoryProperties2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2; };
struct VkPhysicalDeviceMeshShaderFeaturesEXT { using element_type = ::VkPhysicalDeviceMeshShaderFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT; };
struct VkPhysicalDeviceMeshShaderFeaturesNV { using element_type = ::VkPhysicalDeviceMeshShaderFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV; };
struct VkPhysicalDeviceMeshShaderPropertiesEXT { using element_type = ::VkPhysicalDeviceMeshShaderPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT; };
struct VkPhysicalDeviceMeshShaderPropertiesNV { using element_type = ::VkPhysicalDeviceMeshShaderPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV; };
struct VkPhysicalDeviceMultiDrawFeaturesEXT { using element_type = ::VkPhysicalDeviceMultiDrawFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT; };
struct VkPhysicalDeviceMultiDrawPropertiesEXT { using element_type = ::VkPhysicalDeviceMultiDrawPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT; };
struct VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT { using element_type = ::VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT; };
struct VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT { using element_type = ::VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SWAPCHAIN_FEATURES_EXT; };
struct VkPhysicalDeviceMultiviewFeatures { using element_type = ::VkPhysicalDeviceMultiviewFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES; };
struct VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX { using element_type = ::VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX; };
struct VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM { using element_type = ::VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM; };
struct VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM { using element_type = ::VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM; };
struct VkPhysicalDeviceMultiviewProperties { using element_type = ::VkPhysicalDeviceMultiviewProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES; };
struct VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT { using element_type = ::VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT; };
struct VkPhysicalDeviceNestedCommandBufferFeaturesEXT { using element_type = ::VkPhysicalDeviceNestedCommandBufferFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT; };
struct VkPhysicalDeviceNestedCommandBufferPropertiesEXT { using element_type = ::VkPhysicalDeviceNestedCommandBufferPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT; };
struct VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT { using element_type = ::VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT; };
struct VkPhysicalDeviceOpacityMicromapFeaturesEXT { using element_type = ::VkPhysicalDeviceOpacityMicromapFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT; };
struct VkPhysicalDeviceOpacityMicromapFeaturesKHR { using element_type = ::VkPhysicalDeviceOpacityMicromapFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_KHR; };
struct VkPhysicalDeviceOpacityMicromapPropertiesEXT { using element_type = ::VkPhysicalDeviceOpacityMicromapPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT; };
struct VkPhysicalDeviceOpacityMicromapPropertiesKHR { using element_type = ::VkPhysicalDeviceOpacityMicromapPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_KHR; };
struct VkPhysicalDeviceOpticalFlowFeaturesNV { using element_type = ::VkPhysicalDeviceOpticalFlowFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV; };
struct VkPhysicalDeviceOpticalFlowPropertiesNV { using element_type = ::VkPhysicalDeviceOpticalFlowPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV; };
struct VkPhysicalDevicePCIBusInfoPropertiesEXT { using element_type = ::VkPhysicalDevicePCIBusInfoPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT; };
struct VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT { using element_type = ::VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT; };
struct VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV { using element_type = ::VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV; };
struct VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV { using element_type = ::VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV; };
struct VkPhysicalDevicePerStageDescriptorSetFeaturesNV { using element_type = ::VkPhysicalDevicePerStageDescriptorSetFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV; };
struct VkPhysicalDevicePerformanceCountersByRegionFeaturesARM { using element_type = ::VkPhysicalDevicePerformanceCountersByRegionFeaturesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_FEATURES_ARM; };
struct VkPhysicalDevicePerformanceCountersByRegionPropertiesARM { using element_type = ::VkPhysicalDevicePerformanceCountersByRegionPropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_PROPERTIES_ARM; };
struct VkPhysicalDevicePerformanceQueryFeaturesKHR { using element_type = ::VkPhysicalDevicePerformanceQueryFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR; };
struct VkPhysicalDevicePerformanceQueryPropertiesKHR { using element_type = ::VkPhysicalDevicePerformanceQueryPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR; };
struct VkPhysicalDevicePipelineBinaryFeaturesKHR { using element_type = ::VkPhysicalDevicePipelineBinaryFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR; };
struct VkPhysicalDevicePipelineBinaryPropertiesKHR { using element_type = ::VkPhysicalDevicePipelineBinaryPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR; };
struct VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC { using element_type = ::VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC; };
struct VkPhysicalDevicePipelineCreationCacheControlFeatures { using element_type = ::VkPhysicalDevicePipelineCreationCacheControlFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES; };
struct VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR { using element_type = ::VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR; };
struct VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesKHR { using element_type = ::VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_KHR; };
struct VkPhysicalDevicePipelineOpacityMicromapFeaturesARM { using element_type = ::VkPhysicalDevicePipelineOpacityMicromapFeaturesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM; };
struct VkPhysicalDevicePipelineProtectedAccessFeatures { using element_type = ::VkPhysicalDevicePipelineProtectedAccessFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES; };
struct VkPhysicalDevicePipelineRobustnessFeatures { using element_type = ::VkPhysicalDevicePipelineRobustnessFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES; };
struct VkPhysicalDevicePipelineRobustnessProperties { using element_type = ::VkPhysicalDevicePipelineRobustnessProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES; };
struct VkPhysicalDevicePointClippingProperties { using element_type = ::VkPhysicalDevicePointClippingProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES; };
struct VkPhysicalDevicePortabilitySubsetFeaturesKHR { using element_type = ::VkPhysicalDevicePortabilitySubsetFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR; };
struct VkPhysicalDevicePortabilitySubsetPropertiesKHR { using element_type = ::VkPhysicalDevicePortabilitySubsetPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR; };
struct VkPhysicalDevicePresentBarrierFeaturesNV { using element_type = ::VkPhysicalDevicePresentBarrierFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV; };
struct VkPhysicalDevicePresentId2FeaturesKHR { using element_type = ::VkPhysicalDevicePresentId2FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR; };
struct VkPhysicalDevicePresentIdFeaturesKHR { using element_type = ::VkPhysicalDevicePresentIdFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR; };
struct VkPhysicalDevicePresentMeteringFeaturesNV { using element_type = ::VkPhysicalDevicePresentMeteringFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV; };
struct VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR { using element_type = ::VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR; };
struct VkPhysicalDevicePresentTimingFeaturesEXT { using element_type = ::VkPhysicalDevicePresentTimingFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_TIMING_FEATURES_EXT; };
struct VkPhysicalDevicePresentWait2FeaturesKHR { using element_type = ::VkPhysicalDevicePresentWait2FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR; };
struct VkPhysicalDevicePresentWaitFeaturesKHR { using element_type = ::VkPhysicalDevicePresentWaitFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR; };
struct VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT { using element_type = ::VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_RESTART_INDEX_FEATURES_EXT; };
struct VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT { using element_type = ::VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT; };
struct VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT { using element_type = ::VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT; };
struct VkPhysicalDevicePrivateDataBaseHandleFeaturesNV { using element_type = ::VkPhysicalDevicePrivateDataBaseHandleFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_BASE_HANDLE_FEATURES_NV; };
struct VkPhysicalDevicePrivateDataFeatures { using element_type = ::VkPhysicalDevicePrivateDataFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES; };
struct VkPhysicalDeviceProperties { using element_type = ::VkPhysicalDeviceProperties; using kind = format::kind::Struct; };
struct VkPhysicalDeviceProperties2 { using element_type = ::VkPhysicalDeviceProperties2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2; };
struct VkPhysicalDeviceProtectedMemoryFeatures { using element_type = ::VkPhysicalDeviceProtectedMemoryFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES; };
struct VkPhysicalDeviceProtectedMemoryProperties { using element_type = ::VkPhysicalDeviceProtectedMemoryProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES; };
struct VkPhysicalDeviceProvokingVertexFeaturesEXT { using element_type = ::VkPhysicalDeviceProvokingVertexFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT; };
struct VkPhysicalDeviceProvokingVertexPropertiesEXT { using element_type = ::VkPhysicalDeviceProvokingVertexPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT; };
struct VkPhysicalDevicePushConstantBankFeaturesNV { using element_type = ::VkPhysicalDevicePushConstantBankFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_FEATURES_NV; };
struct VkPhysicalDevicePushConstantBankPropertiesNV { using element_type = ::VkPhysicalDevicePushConstantBankPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_PROPERTIES_NV; };
struct VkPhysicalDevicePushDescriptorProperties { using element_type = ::VkPhysicalDevicePushDescriptorProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES; };
struct VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM { using element_type = ::VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_INFO_ARM; };
struct VkPhysicalDeviceQueuePerfHintFeaturesQCOM { using element_type = ::VkPhysicalDeviceQueuePerfHintFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_PERF_HINT_FEATURES_QCOM; };
struct VkPhysicalDeviceQueuePerfHintPropertiesQCOM { using element_type = ::VkPhysicalDeviceQueuePerfHintPropertiesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_PERF_HINT_PROPERTIES_QCOM; };
struct VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT { using element_type = ::VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT; };
struct VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT { using element_type = ::VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT; };
struct VkPhysicalDeviceRawAccessChainsFeaturesNV { using element_type = ::VkPhysicalDeviceRawAccessChainsFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV; };
struct VkPhysicalDeviceRayQueryFeaturesKHR { using element_type = ::VkPhysicalDeviceRayQueryFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR; };
struct VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT { using element_type = ::VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_EXT; };
struct VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV { using element_type = ::VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV; };
struct VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT { using element_type = ::VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_EXT; };
struct VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV { using element_type = ::VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV; };
struct VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV { using element_type = ::VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV; };
struct VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR { using element_type = ::VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR; };
struct VkPhysicalDeviceRayTracingMotionBlurFeaturesNV { using element_type = ::VkPhysicalDeviceRayTracingMotionBlurFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV; };
struct VkPhysicalDeviceRayTracingPipelineFeaturesKHR { using element_type = ::VkPhysicalDeviceRayTracingPipelineFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR; };
struct VkPhysicalDeviceRayTracingPipelinePropertiesKHR { using element_type = ::VkPhysicalDeviceRayTracingPipelinePropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR; };
struct VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR { using element_type = ::VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR; };
struct VkPhysicalDeviceRayTracingPropertiesNV { using element_type = ::VkPhysicalDeviceRayTracingPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV; };
struct VkPhysicalDeviceRayTracingValidationFeaturesNV { using element_type = ::VkPhysicalDeviceRayTracingValidationFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV; };
struct VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG { using element_type = ::VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG; };
struct VkPhysicalDeviceRenderPassStripedFeaturesARM { using element_type = ::VkPhysicalDeviceRenderPassStripedFeaturesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM; };
struct VkPhysicalDeviceRenderPassStripedPropertiesARM { using element_type = ::VkPhysicalDeviceRenderPassStripedPropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM; };
struct VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV { using element_type = ::VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV; };
struct VkPhysicalDeviceRobustness2FeaturesKHR { using element_type = ::VkPhysicalDeviceRobustness2FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR; };
struct VkPhysicalDeviceRobustness2PropertiesKHR { using element_type = ::VkPhysicalDeviceRobustness2PropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR; };
struct VkPhysicalDeviceSampleLocationsPropertiesEXT { using element_type = ::VkPhysicalDeviceSampleLocationsPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT; };
struct VkPhysicalDeviceSamplerFilterMinmaxProperties { using element_type = ::VkPhysicalDeviceSamplerFilterMinmaxProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES; };
struct VkPhysicalDeviceSamplerYcbcrConversionFeatures { using element_type = ::VkPhysicalDeviceSamplerYcbcrConversionFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES; };
struct VkPhysicalDeviceScalarBlockLayoutFeatures { using element_type = ::VkPhysicalDeviceScalarBlockLayoutFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES; };
struct VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM { using element_type = ::VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_DISPATCH_PARAMETERS_PROPERTIES_ARM; };
struct VkPhysicalDeviceSchedulingControlsFeaturesARM { using element_type = ::VkPhysicalDeviceSchedulingControlsFeaturesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM; };
struct VkPhysicalDeviceSchedulingControlsFlagsARM { using element_type = ::VkPhysicalDeviceSchedulingControlsFlagsARM; using kind = format::kind::Flags64; };
struct VkPhysicalDeviceSchedulingControlsPropertiesARM { using element_type = ::VkPhysicalDeviceSchedulingControlsPropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM; };
struct VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures { using element_type = ::VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES; };
struct VkPhysicalDeviceShader64BitIndexingFeaturesEXT { using element_type = ::VkPhysicalDeviceShader64BitIndexingFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT; };
struct VkPhysicalDeviceShaderAbortFeaturesKHR { using element_type = ::VkPhysicalDeviceShaderAbortFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ABORT_FEATURES_KHR; };
struct VkPhysicalDeviceShaderAbortPropertiesKHR { using element_type = ::VkPhysicalDeviceShaderAbortPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ABORT_PROPERTIES_KHR; };
struct VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV { using element_type = ::VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV; };
struct VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT { using element_type = ::VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT; };
struct VkPhysicalDeviceShaderAtomicFloatFeaturesEXT { using element_type = ::VkPhysicalDeviceShaderAtomicFloatFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT; };
struct VkPhysicalDeviceShaderAtomicInt64Features { using element_type = ::VkPhysicalDeviceShaderAtomicInt64Features; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES; };
struct VkPhysicalDeviceShaderBfloat16FeaturesKHR { using element_type = ::VkPhysicalDeviceShaderBfloat16FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR; };
struct VkPhysicalDeviceShaderClockFeaturesKHR { using element_type = ::VkPhysicalDeviceShaderClockFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR; };
struct VkPhysicalDeviceShaderConstantDataFeaturesKHR { using element_type = ::VkPhysicalDeviceShaderConstantDataFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CONSTANT_DATA_FEATURES_KHR; };
struct VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM { using element_type = ::VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM; };
struct VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM { using element_type = ::VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM; };
struct VkPhysicalDeviceShaderCoreProperties2AMD { using element_type = ::VkPhysicalDeviceShaderCoreProperties2AMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD; };
struct VkPhysicalDeviceShaderCorePropertiesAMD { using element_type = ::VkPhysicalDeviceShaderCorePropertiesAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD; };
struct VkPhysicalDeviceShaderCorePropertiesARM { using element_type = ::VkPhysicalDeviceShaderCorePropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM; };
struct VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures { using element_type = ::VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES; };
struct VkPhysicalDeviceShaderDrawParametersFeatures { using element_type = ::VkPhysicalDeviceShaderDrawParametersFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES; };
struct VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD { using element_type = ::VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD; };
struct VkPhysicalDeviceShaderExpectAssumeFeatures { using element_type = ::VkPhysicalDeviceShaderExpectAssumeFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES; };
struct VkPhysicalDeviceShaderFloat16Int8Features { using element_type = ::VkPhysicalDeviceShaderFloat16Int8Features; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES; };
struct VkPhysicalDeviceShaderFloat8FeaturesEXT { using element_type = ::VkPhysicalDeviceShaderFloat8FeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT; };
struct VkPhysicalDeviceShaderFloatControls2Features { using element_type = ::VkPhysicalDeviceShaderFloatControls2Features; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES; };
struct VkPhysicalDeviceShaderFmaFeaturesKHR { using element_type = ::VkPhysicalDeviceShaderFmaFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR; };
struct VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT { using element_type = ::VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT; };
struct VkPhysicalDeviceShaderImageFootprintFeaturesNV { using element_type = ::VkPhysicalDeviceShaderImageFootprintFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV; };
struct VkPhysicalDeviceShaderIntegerDotProductFeatures { using element_type = ::VkPhysicalDeviceShaderIntegerDotProductFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES; };
struct VkPhysicalDeviceShaderIntegerDotProductProperties { using element_type = ::VkPhysicalDeviceShaderIntegerDotProductProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES; };
struct VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL { using element_type = ::VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL; };
struct VkPhysicalDeviceShaderLongVectorFeaturesEXT { using element_type = ::VkPhysicalDeviceShaderLongVectorFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_FEATURES_EXT; };
struct VkPhysicalDeviceShaderLongVectorPropertiesEXT { using element_type = ::VkPhysicalDeviceShaderLongVectorPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_PROPERTIES_EXT; };
struct VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR { using element_type = ::VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR; };
struct VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE { using element_type = ::VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MIXED_FLOAT_DOT_PRODUCT_FEATURES_VALVE; };
struct VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT { using element_type = ::VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT; };
struct VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT { using element_type = ::VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT; };
struct VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM { using element_type = ::VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MULTIPLE_WAIT_QUEUES_FEATURES_QCOM; };
struct VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM { using element_type = ::VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MULTIPLE_WAIT_QUEUES_PROPERTIES_QCOM; };
struct VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT { using element_type = ::VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OCP_MICROSCALING_TYPES_FEATURES_EXT; };
struct VkPhysicalDeviceShaderObjectFeaturesEXT { using element_type = ::VkPhysicalDeviceShaderObjectFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT; };
struct VkPhysicalDeviceShaderObjectPropertiesEXT { using element_type = ::VkPhysicalDeviceShaderObjectPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT; };
struct VkPhysicalDeviceShaderQuadControlFeaturesKHR { using element_type = ::VkPhysicalDeviceShaderQuadControlFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR; };
struct VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR { using element_type = ::VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR; };
struct VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT { using element_type = ::VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT; };
struct VkPhysicalDeviceShaderSMBuiltinsFeaturesNV { using element_type = ::VkPhysicalDeviceShaderSMBuiltinsFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV; };
struct VkPhysicalDeviceShaderSMBuiltinsPropertiesNV { using element_type = ::VkPhysicalDeviceShaderSMBuiltinsPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV; };
struct VkPhysicalDeviceShaderSplitBarrierFeaturesEXT { using element_type = ::VkPhysicalDeviceShaderSplitBarrierFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SPLIT_BARRIER_FEATURES_EXT; };
struct VkPhysicalDeviceShaderSplitBarrierPropertiesEXT { using element_type = ::VkPhysicalDeviceShaderSplitBarrierPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SPLIT_BARRIER_PROPERTIES_EXT; };
struct VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures { using element_type = ::VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES; };
struct VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT { using element_type = ::VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_PARTITIONED_FEATURES_EXT; };
struct VkPhysicalDeviceShaderSubgroupRotateFeatures { using element_type = ::VkPhysicalDeviceShaderSubgroupRotateFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES; };
struct VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR { using element_type = ::VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR; };
struct VkPhysicalDeviceShaderTerminateInvocationFeatures { using element_type = ::VkPhysicalDeviceShaderTerminateInvocationFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES; };
struct VkPhysicalDeviceShaderTileImageFeaturesEXT { using element_type = ::VkPhysicalDeviceShaderTileImageFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT; };
struct VkPhysicalDeviceShaderTileImagePropertiesEXT { using element_type = ::VkPhysicalDeviceShaderTileImagePropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT; };
struct VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT { using element_type = ::VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT; };
struct VkPhysicalDeviceShaderUntypedPointersFeaturesKHR { using element_type = ::VkPhysicalDeviceShaderUntypedPointersFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR; };
struct VkPhysicalDeviceShadingRateImageFeaturesNV { using element_type = ::VkPhysicalDeviceShadingRateImageFeaturesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV; };
struct VkPhysicalDeviceShadingRateImagePropertiesNV { using element_type = ::VkPhysicalDeviceShadingRateImagePropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV; };
struct VkPhysicalDeviceSparseImageFormatInfo2 { using element_type = ::VkPhysicalDeviceSparseImageFormatInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2; };
struct VkPhysicalDeviceSparseProperties { using element_type = ::VkPhysicalDeviceSparseProperties; using kind = format::kind::Struct; };
struct VkPhysicalDeviceSubgroupProperties { using element_type = ::VkPhysicalDeviceSubgroupProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES; };
struct VkPhysicalDeviceSubgroupSizeControlFeatures { using element_type = ::VkPhysicalDeviceSubgroupSizeControlFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES; };
struct VkPhysicalDeviceSubgroupSizeControlProperties { using element_type = ::VkPhysicalDeviceSubgroupSizeControlProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES; };
struct VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT { using element_type = ::VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT; };
struct VkPhysicalDeviceSurfaceInfo2KHR { using element_type = ::VkPhysicalDeviceSurfaceInfo2KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR; };
struct VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR { using element_type = ::VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR; };
struct VkPhysicalDeviceSynchronization2Features { using element_type = ::VkPhysicalDeviceSynchronization2Features; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES; };
struct VkPhysicalDeviceTensorFeaturesARM { using element_type = ::VkPhysicalDeviceTensorFeaturesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_FEATURES_ARM; };
struct VkPhysicalDeviceTensorPropertiesARM { using element_type = ::VkPhysicalDeviceTensorPropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_PROPERTIES_ARM; };
struct VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT { using element_type = ::VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT; };
struct VkPhysicalDeviceTexelBufferAlignmentProperties { using element_type = ::VkPhysicalDeviceTexelBufferAlignmentProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES; };
struct VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT { using element_type = ::VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_3D_FEATURES_EXT; };
struct VkPhysicalDeviceTextureCompressionASTCHDRFeatures { using element_type = ::VkPhysicalDeviceTextureCompressionASTCHDRFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES; };
struct VkPhysicalDeviceThrottleHintFeaturesSEC { using element_type = ::VkPhysicalDeviceThrottleHintFeaturesSEC; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_THROTTLE_HINT_FEATURES_SEC; };
struct VkPhysicalDeviceTileMemoryHeapFeaturesQCOM { using element_type = ::VkPhysicalDeviceTileMemoryHeapFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM; };
struct VkPhysicalDeviceTileMemoryHeapPropertiesQCOM { using element_type = ::VkPhysicalDeviceTileMemoryHeapPropertiesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM; };
struct VkPhysicalDeviceTilePropertiesFeaturesQCOM { using element_type = ::VkPhysicalDeviceTilePropertiesFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM; };
struct VkPhysicalDeviceTileShadingFeaturesQCOM { using element_type = ::VkPhysicalDeviceTileShadingFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM; };
struct VkPhysicalDeviceTileShadingPropertiesQCOM { using element_type = ::VkPhysicalDeviceTileShadingPropertiesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM; };
struct VkPhysicalDeviceTimelineSemaphoreFeatures { using element_type = ::VkPhysicalDeviceTimelineSemaphoreFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES; };
struct VkPhysicalDeviceTimelineSemaphoreProperties { using element_type = ::VkPhysicalDeviceTimelineSemaphoreProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES; };
struct VkPhysicalDeviceToolProperties { using element_type = ::VkPhysicalDeviceToolProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES; };
struct VkPhysicalDeviceTransformFeedbackFeaturesEXT { using element_type = ::VkPhysicalDeviceTransformFeedbackFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT; };
struct VkPhysicalDeviceTransformFeedbackPropertiesEXT { using element_type = ::VkPhysicalDeviceTransformFeedbackPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT; };
struct VkPhysicalDeviceType { using element_type = ::VkPhysicalDeviceType; using kind = format::kind::Enum; };
struct VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR { using element_type = ::VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR; };
struct VkPhysicalDeviceUniformBufferStandardLayoutFeatures { using element_type = ::VkPhysicalDeviceUniformBufferStandardLayoutFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES; };
struct VkPhysicalDeviceVariablePointersFeatures { using element_type = ::VkPhysicalDeviceVariablePointersFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES; };
struct VkPhysicalDeviceVertexAttributeDivisorFeatures { using element_type = ::VkPhysicalDeviceVertexAttributeDivisorFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES; };
struct VkPhysicalDeviceVertexAttributeDivisorProperties { using element_type = ::VkPhysicalDeviceVertexAttributeDivisorProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES; };
struct VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT { using element_type = ::VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT; };
struct VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT { using element_type = ::VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT; };
struct VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT { using element_type = ::VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT; };
struct VkPhysicalDeviceVideoDecodeVP9FeaturesKHR { using element_type = ::VkPhysicalDeviceVideoDecodeVP9FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR; };
struct VkPhysicalDeviceVideoEncodeAV1FeaturesKHR { using element_type = ::VkPhysicalDeviceVideoEncodeAV1FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR; };
struct VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR { using element_type = ::VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_FEEDBACK_2_FEATURES_KHR; };
struct VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR { using element_type = ::VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR; };
struct VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR { using element_type = ::VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR; };
struct VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR { using element_type = ::VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR; };
struct VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE { using element_type = ::VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE; };
struct VkPhysicalDeviceVideoFormatInfoKHR { using element_type = ::VkPhysicalDeviceVideoFormatInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR; };
struct VkPhysicalDeviceVideoMaintenance1FeaturesKHR { using element_type = ::VkPhysicalDeviceVideoMaintenance1FeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR; };
struct VkPhysicalDeviceVulkan11Features { using element_type = ::VkPhysicalDeviceVulkan11Features; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES; };
struct VkPhysicalDeviceVulkan11Properties { using element_type = ::VkPhysicalDeviceVulkan11Properties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES; };
struct VkPhysicalDeviceVulkan12Features { using element_type = ::VkPhysicalDeviceVulkan12Features; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES; };
struct VkPhysicalDeviceVulkan12Properties { using element_type = ::VkPhysicalDeviceVulkan12Properties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES; };
struct VkPhysicalDeviceVulkan13Features { using element_type = ::VkPhysicalDeviceVulkan13Features; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES; };
struct VkPhysicalDeviceVulkan13Properties { using element_type = ::VkPhysicalDeviceVulkan13Properties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES; };
struct VkPhysicalDeviceVulkan14Features { using element_type = ::VkPhysicalDeviceVulkan14Features; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES; };
struct VkPhysicalDeviceVulkan14Properties { using element_type = ::VkPhysicalDeviceVulkan14Properties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES; };
struct VkPhysicalDeviceVulkanMemoryModelFeatures { using element_type = ::VkPhysicalDeviceVulkanMemoryModelFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES; };
struct VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR { using element_type = ::VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR; };
struct VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT { using element_type = ::VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT; };
struct VkPhysicalDeviceYcbcrDegammaFeaturesQCOM { using element_type = ::VkPhysicalDeviceYcbcrDegammaFeaturesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM; };
struct VkPhysicalDeviceYcbcrImageArraysFeaturesEXT { using element_type = ::VkPhysicalDeviceYcbcrImageArraysFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT; };
struct VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT { using element_type = ::VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT; };
struct VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures { using element_type = ::VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES; };
struct VkPipeline { using element_type = ::VkPipeline; using kind = format::kind::Handle; };
struct VkPipelineBinaryCreateInfoKHR { using element_type = ::VkPipelineBinaryCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR; };
struct VkPipelineBinaryDataInfoKHR { using element_type = ::VkPipelineBinaryDataInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR; };
struct VkPipelineBinaryDataKHR { using element_type = ::VkPipelineBinaryDataKHR; using kind = format::kind::Struct; };
struct VkPipelineBinaryHandlesInfoKHR { using element_type = ::VkPipelineBinaryHandlesInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR; };
struct VkPipelineBinaryInfoKHR { using element_type = ::VkPipelineBinaryInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR; };
struct VkPipelineBinaryKHR { using element_type = ::VkPipelineBinaryKHR; using kind = format::kind::Handle; };
struct VkPipelineBinaryKeyKHR { using element_type = ::VkPipelineBinaryKeyKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR; };
struct VkPipelineBinaryKeysAndDataKHR { using element_type = ::VkPipelineBinaryKeysAndDataKHR; using kind = format::kind::Struct; };
struct VkPipelineBindPoint { using element_type = ::VkPipelineBindPoint; using kind = format::kind::Enum; };
struct VkPipelineCache { using element_type = ::VkPipelineCache; using kind = format::kind::Handle; };
struct VkPipelineCacheCreateFlags { using element_type = ::VkPipelineCacheCreateFlags; using kind = format::kind::Flags; };
struct VkPipelineCacheCreateInfo { using element_type = ::VkPipelineCacheCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO; };
struct VkPipelineCacheHeaderVersion { using element_type = ::VkPipelineCacheHeaderVersion; using kind = format::kind::Enum; };
struct VkPipelineCacheHeaderVersionDataGraphQCOM { using element_type = ::VkPipelineCacheHeaderVersionDataGraphQCOM; using kind = format::kind::Struct; };
struct VkPipelineCacheHeaderVersionOne { using element_type = ::VkPipelineCacheHeaderVersionOne; using kind = format::kind::Struct; };
struct VkPipelineColorBlendAdvancedStateCreateInfoEXT { using element_type = ::VkPipelineColorBlendAdvancedStateCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT; };
struct VkPipelineColorBlendAttachmentState { using element_type = ::VkPipelineColorBlendAttachmentState; using kind = format::kind::Struct; };
struct VkPipelineColorBlendStateCreateFlags { using element_type = ::VkPipelineColorBlendStateCreateFlags; using kind = format::kind::Flags; };
struct VkPipelineColorBlendStateCreateInfo { using element_type = ::VkPipelineColorBlendStateCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO; };
struct VkPipelineColorWriteCreateInfoEXT { using element_type = ::VkPipelineColorWriteCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT; };
struct VkPipelineCompilerControlCreateInfoAMD { using element_type = ::VkPipelineCompilerControlCreateInfoAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD; };
struct VkPipelineCompilerControlFlagsAMD { using element_type = ::VkPipelineCompilerControlFlagsAMD; using kind = format::kind::Flags; };
struct VkPipelineCoverageModulationStateCreateFlagsNV { using element_type = ::VkPipelineCoverageModulationStateCreateFlagsNV; using kind = format::kind::Flags; };
struct VkPipelineCoverageModulationStateCreateInfoNV { using element_type = ::VkPipelineCoverageModulationStateCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV; };
struct VkPipelineCoverageReductionStateCreateFlagsNV { using element_type = ::VkPipelineCoverageReductionStateCreateFlagsNV; using kind = format::kind::Flags; };
struct VkPipelineCoverageReductionStateCreateInfoNV { using element_type = ::VkPipelineCoverageReductionStateCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV; };
struct VkPipelineCoverageToColorStateCreateFlagsNV { using element_type = ::VkPipelineCoverageToColorStateCreateFlagsNV; using kind = format::kind::Flags; };
struct VkPipelineCoverageToColorStateCreateInfoNV { using element_type = ::VkPipelineCoverageToColorStateCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV; };
struct VkPipelineCreateFlags { using element_type = ::VkPipelineCreateFlags; using kind = format::kind::Flags; };
struct VkPipelineCreateFlags2 { using element_type = ::VkPipelineCreateFlags2; using kind = format::kind::Flags64; };
struct VkPipelineCreateFlags2CreateInfo { using element_type = ::VkPipelineCreateFlags2CreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO; };
struct VkPipelineCreateInfoKHR { using element_type = ::VkPipelineCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_CREATE_INFO_KHR; };
struct VkPipelineCreationFeedback { using element_type = ::VkPipelineCreationFeedback; using kind = format::kind::Struct; };
struct VkPipelineCreationFeedbackCreateInfo { using element_type = ::VkPipelineCreationFeedbackCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO; };
struct VkPipelineCreationFeedbackFlags { using element_type = ::VkPipelineCreationFeedbackFlags; using kind = format::kind::Flags; };
struct VkPipelineDepthStencilStateCreateFlags { using element_type = ::VkPipelineDepthStencilStateCreateFlags; using kind = format::kind::Flags; };
struct VkPipelineDepthStencilStateCreateInfo { using element_type = ::VkPipelineDepthStencilStateCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO; };
struct VkPipelineDiscardRectangleStateCreateFlagsEXT { using element_type = ::VkPipelineDiscardRectangleStateCreateFlagsEXT; using kind = format::kind::Flags; };
struct VkPipelineDiscardRectangleStateCreateInfoEXT { using element_type = ::VkPipelineDiscardRectangleStateCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT; };
struct VkPipelineDynamicStateCreateFlags { using element_type = ::VkPipelineDynamicStateCreateFlags; using kind = format::kind::Flags; };
struct VkPipelineDynamicStateCreateInfo { using element_type = ::VkPipelineDynamicStateCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO; };
struct VkPipelineExecutableInfoKHR { using element_type = ::VkPipelineExecutableInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR; };
struct VkPipelineExecutableInternalRepresentationKHR { using element_type = ::VkPipelineExecutableInternalRepresentationKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR; };
struct VkPipelineExecutablePropertiesKHR { using element_type = ::VkPipelineExecutablePropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR; };
struct VkPipelineExecutableStatisticFormatKHR { using element_type = ::VkPipelineExecutableStatisticFormatKHR; using kind = format::kind::Enum; };
struct VkPipelineExecutableStatisticKHR { using element_type = ::VkPipelineExecutableStatisticKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR; };
struct VkPipelineExecutableStatisticValueKHR { using element_type = ::VkPipelineExecutableStatisticValueKHR; using kind = format::kind::Struct; };
struct VkPipelineFragmentDensityMapLayeredCreateInfoVALVE { using element_type = ::VkPipelineFragmentDensityMapLayeredCreateInfoVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_DENSITY_MAP_LAYERED_CREATE_INFO_VALVE; };
struct VkPipelineFragmentShadingRateEnumStateCreateInfoNV { using element_type = ::VkPipelineFragmentShadingRateEnumStateCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV; };
struct VkPipelineFragmentShadingRateStateCreateInfoKHR { using element_type = ::VkPipelineFragmentShadingRateStateCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR; };
struct VkPipelineIndirectDeviceAddressInfoNV { using element_type = ::VkPipelineIndirectDeviceAddressInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV; };
struct VkPipelineInfoKHR { using element_type = ::VkPipelineInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR; };
struct VkPipelineInputAssemblyStateCreateFlags { using element_type = ::VkPipelineInputAssemblyStateCreateFlags; using kind = format::kind::Flags; };
struct VkPipelineInputAssemblyStateCreateInfo { using element_type = ::VkPipelineInputAssemblyStateCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO; };
struct VkPipelineLayout { using element_type = ::VkPipelineLayout; using kind = format::kind::Handle; };
struct VkPipelineLayoutCreateFlags { using element_type = ::VkPipelineLayoutCreateFlags; using kind = format::kind::Flags; };
struct VkPipelineLayoutCreateInfo { using element_type = ::VkPipelineLayoutCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO; };
struct VkPipelineLibraryCreateInfoKHR { using element_type = ::VkPipelineLibraryCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR; };
struct VkPipelineMultisampleStateCreateFlags { using element_type = ::VkPipelineMultisampleStateCreateFlags; using kind = format::kind::Flags; };
struct VkPipelineMultisampleStateCreateInfo { using element_type = ::VkPipelineMultisampleStateCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO; };
struct VkPipelineRasterizationConservativeStateCreateFlagsEXT { using element_type = ::VkPipelineRasterizationConservativeStateCreateFlagsEXT; using kind = format::kind::Flags; };
struct VkPipelineRasterizationConservativeStateCreateInfoEXT { using element_type = ::VkPipelineRasterizationConservativeStateCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT; };
struct VkPipelineRasterizationDepthClipStateCreateFlagsEXT { using element_type = ::VkPipelineRasterizationDepthClipStateCreateFlagsEXT; using kind = format::kind::Flags; };
struct VkPipelineRasterizationDepthClipStateCreateInfoEXT { using element_type = ::VkPipelineRasterizationDepthClipStateCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT; };
struct VkPipelineRasterizationLineStateCreateInfo { using element_type = ::VkPipelineRasterizationLineStateCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO; };
struct VkPipelineRasterizationProvokingVertexStateCreateInfoEXT { using element_type = ::VkPipelineRasterizationProvokingVertexStateCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT; };
struct VkPipelineRasterizationStateCreateFlags { using element_type = ::VkPipelineRasterizationStateCreateFlags; using kind = format::kind::Flags; };
struct VkPipelineRasterizationStateCreateInfo { using element_type = ::VkPipelineRasterizationStateCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO; };
struct VkPipelineRasterizationStateRasterizationOrderAMD { using element_type = ::VkPipelineRasterizationStateRasterizationOrderAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD; };
struct VkPipelineRasterizationStateStreamCreateFlagsEXT { using element_type = ::VkPipelineRasterizationStateStreamCreateFlagsEXT; using kind = format::kind::Flags; };
struct VkPipelineRasterizationStateStreamCreateInfoEXT { using element_type = ::VkPipelineRasterizationStateStreamCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT; };
struct VkPipelineRenderingCreateInfo { using element_type = ::VkPipelineRenderingCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO; };
struct VkPipelineRepresentativeFragmentTestStateCreateInfoNV { using element_type = ::VkPipelineRepresentativeFragmentTestStateCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV; };
struct VkPipelineRobustnessBufferBehavior { using element_type = ::VkPipelineRobustnessBufferBehavior; using kind = format::kind::Enum; };
struct VkPipelineRobustnessCreateInfo { using element_type = ::VkPipelineRobustnessCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO; };
struct VkPipelineRobustnessImageBehavior { using element_type = ::VkPipelineRobustnessImageBehavior; using kind = format::kind::Enum; };
struct VkPipelineSampleLocationsStateCreateInfoEXT { using element_type = ::VkPipelineSampleLocationsStateCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT; };
struct VkPipelineShaderStageCreateFlags { using element_type = ::VkPipelineShaderStageCreateFlags; using kind = format::kind::Flags; };
struct VkPipelineShaderStageCreateInfo { using element_type = ::VkPipelineShaderStageCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO; };
struct VkPipelineShaderStageModuleIdentifierCreateInfoEXT { using element_type = ::VkPipelineShaderStageModuleIdentifierCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT; };
struct VkPipelineShaderStageRequiredSubgroupSizeCreateInfo { using element_type = ::VkPipelineShaderStageRequiredSubgroupSizeCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO; };
struct VkPipelineStageFlagBits { using element_type = ::VkPipelineStageFlagBits; using kind = format::kind::Enum; };
struct VkPipelineStageFlags { using element_type = ::VkPipelineStageFlags; using kind = format::kind::Flags; };
struct VkPipelineStageFlags2 { using element_type = ::VkPipelineStageFlags2; using kind = format::kind::Flags64; };
struct VkPipelineTessellationDomainOriginStateCreateInfo { using element_type = ::VkPipelineTessellationDomainOriginStateCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO; };
struct VkPipelineTessellationStateCreateFlags { using element_type = ::VkPipelineTessellationStateCreateFlags; using kind = format::kind::Flags; };
struct VkPipelineTessellationStateCreateInfo { using element_type = ::VkPipelineTessellationStateCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO; };
struct VkPipelineVertexInputDivisorStateCreateInfo { using element_type = ::VkPipelineVertexInputDivisorStateCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO; };
struct VkPipelineVertexInputStateCreateFlags { using element_type = ::VkPipelineVertexInputStateCreateFlags; using kind = format::kind::Flags; };
struct VkPipelineVertexInputStateCreateInfo { using element_type = ::VkPipelineVertexInputStateCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO; };
struct VkPipelineViewportCoarseSampleOrderStateCreateInfoNV { using element_type = ::VkPipelineViewportCoarseSampleOrderStateCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV; };
struct VkPipelineViewportDepthClampControlCreateInfoEXT { using element_type = ::VkPipelineViewportDepthClampControlCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT; };
struct VkPipelineViewportDepthClipControlCreateInfoEXT { using element_type = ::VkPipelineViewportDepthClipControlCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT; };
struct VkPipelineViewportExclusiveScissorStateCreateInfoNV { using element_type = ::VkPipelineViewportExclusiveScissorStateCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV; };
struct VkPipelineViewportShadingRateImageStateCreateInfoNV { using element_type = ::VkPipelineViewportShadingRateImageStateCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV; };
struct VkPipelineViewportStateCreateFlags { using element_type = ::VkPipelineViewportStateCreateFlags; using kind = format::kind::Flags; };
struct VkPipelineViewportStateCreateInfo { using element_type = ::VkPipelineViewportStateCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO; };
struct VkPipelineViewportSwizzleStateCreateFlagsNV { using element_type = ::VkPipelineViewportSwizzleStateCreateFlagsNV; using kind = format::kind::Flags; };
struct VkPipelineViewportSwizzleStateCreateInfoNV { using element_type = ::VkPipelineViewportSwizzleStateCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV; };
struct VkPipelineViewportWScalingStateCreateInfoNV { using element_type = ::VkPipelineViewportWScalingStateCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV; };
struct VkPointClippingBehavior { using element_type = ::VkPointClippingBehavior; using kind = format::kind::Enum; };
struct VkPolygonMode { using element_type = ::VkPolygonMode; using kind = format::kind::Enum; };
struct VkPresentFrameTokenGGP { using element_type = ::VkPresentFrameTokenGGP; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP; };
struct VkPresentGravityFlagsKHR { using element_type = ::VkPresentGravityFlagsKHR; using kind = format::kind::Flags; };
struct VkPresentId2KHR { using element_type = ::VkPresentId2KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PRESENT_ID_2_KHR; };
struct VkPresentIdKHR { using element_type = ::VkPresentIdKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PRESENT_ID_KHR; };
struct VkPresentInfoKHR { using element_type = ::VkPresentInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR; };
struct VkPresentModeKHR { using element_type = ::VkPresentModeKHR; using kind = format::kind::Enum; };
struct VkPresentRegionKHR { using element_type = ::VkPresentRegionKHR; using kind = format::kind::Struct; };
struct VkPresentRegionsKHR { using element_type = ::VkPresentRegionsKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR; };
struct VkPresentScalingFlagsKHR { using element_type = ::VkPresentScalingFlagsKHR; using kind = format::kind::Flags; };
struct VkPresentStageFlagsEXT { using element_type = ::VkPresentStageFlagsEXT; using kind = format::kind::Flags; };
struct VkPresentStageTimeEXT { using element_type = ::VkPresentStageTimeEXT; using kind = format::kind::Struct; };
struct VkPresentTimeGOOGLE { using element_type = ::VkPresentTimeGOOGLE; using kind = format::kind::Struct; };
struct VkPresentTimesInfoGOOGLE { using element_type = ::VkPresentTimesInfoGOOGLE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE; };
struct VkPresentTimingInfoEXT { using element_type = ::VkPresentTimingInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PRESENT_TIMING_INFO_EXT; };
struct VkPresentTimingInfoFlagsEXT { using element_type = ::VkPresentTimingInfoFlagsEXT; using kind = format::kind::Flags; };
struct VkPresentTimingSurfaceCapabilitiesEXT { using element_type = ::VkPresentTimingSurfaceCapabilitiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PRESENT_TIMING_SURFACE_CAPABILITIES_EXT; };
struct VkPresentTimingsInfoEXT { using element_type = ::VkPresentTimingsInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PRESENT_TIMINGS_INFO_EXT; };
struct VkPresentWait2InfoKHR { using element_type = ::VkPresentWait2InfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PRESENT_WAIT_2_INFO_KHR; };
struct VkPrimitiveTopology { using element_type = ::VkPrimitiveTopology; using kind = format::kind::Enum; };
struct VkPrivateDataSlot { using element_type = ::VkPrivateDataSlot; using kind = format::kind::Handle; };
struct VkPrivateDataSlotCreateFlags { using element_type = ::VkPrivateDataSlotCreateFlags; using kind = format::kind::Flags; };
struct VkPrivateDataSlotCreateInfo { using element_type = ::VkPrivateDataSlotCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO; };
struct VkProtectedSubmitInfo { using element_type = ::VkProtectedSubmitInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO; };
struct VkProvokingVertexModeEXT { using element_type = ::VkProvokingVertexModeEXT; using kind = format::kind::Enum; };
struct VkPushConstantBankInfoNV { using element_type = ::VkPushConstantBankInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PUSH_CONSTANT_BANK_INFO_NV; };
struct VkPushConstantRange { using element_type = ::VkPushConstantRange; using kind = format::kind::Struct; };
struct VkPushConstantsInfo { using element_type = ::VkPushConstantsInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO; };
struct VkPushDescriptorSetInfo { using element_type = ::VkPushDescriptorSetInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO; };
struct VkPushDescriptorSetWithTemplateInfo { using element_type = ::VkPushDescriptorSetWithTemplateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO; };
struct VkQueryControlFlags { using element_type = ::VkQueryControlFlags; using kind = format::kind::Flags; };
struct VkQueryPipelineStatisticFlags { using element_type = ::VkQueryPipelineStatisticFlags; using kind = format::kind::Flags; };
struct VkQueryPool { using element_type = ::VkQueryPool; using kind = format::kind::Handle; };
struct VkQueryPoolCreateFlags { using element_type = ::VkQueryPoolCreateFlags; using kind = format::kind::Flags; };
struct VkQueryPoolCreateInfo { using element_type = ::VkQueryPoolCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO; };
struct VkQueryPoolPerformanceCreateInfoKHR { using element_type = ::VkQueryPoolPerformanceCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR; };
struct VkQueryPoolPerformanceQueryCreateInfoINTEL { using element_type = ::VkQueryPoolPerformanceQueryCreateInfoINTEL; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL; };
struct VkQueryPoolSamplingModeINTEL { using element_type = ::VkQueryPoolSamplingModeINTEL; using kind = format::kind::Enum; };
struct VkQueryPoolVideoEncodeFeedbackCreateInfoKHR { using element_type = ::VkQueryPoolVideoEncodeFeedbackCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR; };
struct VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR { using element_type = ::VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_PER_PARTITION_FEEDBACK_CREATE_INFO_KHR; };
struct VkQueryResultFlags { using element_type = ::VkQueryResultFlags; using kind = format::kind::Flags; };
struct VkQueryType { using element_type = ::VkQueryType; using kind = format::kind::Enum; };
struct VkQueue { using element_type = ::VkQueue; using kind = format::kind::Handle; };
struct VkQueueFamilyCheckpointProperties2NV { using element_type = ::VkQueueFamilyCheckpointProperties2NV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV; };
struct VkQueueFamilyCheckpointPropertiesNV { using element_type = ::VkQueueFamilyCheckpointPropertiesNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV; };
struct VkQueueFamilyDataGraphOpticalFlowPropertiesARM { using element_type = ::VkQueueFamilyDataGraphOpticalFlowPropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_OPTICAL_FLOW_PROPERTIES_ARM; };
struct VkQueueFamilyDataGraphProcessingEnginePropertiesARM { using element_type = ::VkQueueFamilyDataGraphProcessingEnginePropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM; };
struct VkQueueFamilyDataGraphPropertiesARM { using element_type = ::VkQueueFamilyDataGraphPropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROPERTIES_ARM; };
struct VkQueueFamilyGlobalPriorityProperties { using element_type = ::VkQueueFamilyGlobalPriorityProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES; };
struct VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR { using element_type = ::VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUEUE_FAMILY_OPTIMAL_IMAGE_TRANSFER_GRANULARITY_PROPERTIES_KHR; };
struct VkQueueFamilyOwnershipTransferPropertiesKHR { using element_type = ::VkQueueFamilyOwnershipTransferPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUEUE_FAMILY_OWNERSHIP_TRANSFER_PROPERTIES_KHR; };
struct VkQueueFamilyProperties { using element_type = ::VkQueueFamilyProperties; using kind = format::kind::Struct; };
struct VkQueueFamilyProperties2 { using element_type = ::VkQueueFamilyProperties2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2; };
struct VkQueueFamilyQueryResultStatusPropertiesKHR { using element_type = ::VkQueueFamilyQueryResultStatusPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR; };
struct VkQueueFamilyVideoPropertiesKHR { using element_type = ::VkQueueFamilyVideoPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR; };
struct VkQueueFlags { using element_type = ::VkQueueFlags; using kind = format::kind::Flags; };
struct VkQueueGlobalPriority { using element_type = ::VkQueueGlobalPriority; using kind = format::kind::Enum; };
struct VkRasterizationOrderAMD { using element_type = ::VkRasterizationOrderAMD; using kind = format::kind::Enum; };
struct VkRayTracingInvocationReorderModeEXT { using element_type = ::VkRayTracingInvocationReorderModeEXT; using kind = format::kind::Enum; };
struct VkRayTracingLssIndexingModeNV { using element_type = ::VkRayTracingLssIndexingModeNV; using kind = format::kind::Enum; };
struct VkRayTracingLssPrimitiveEndCapsModeNV { using element_type = ::VkRayTracingLssPrimitiveEndCapsModeNV; using kind = format::kind::Enum; };
struct VkRayTracingPipelineCreateInfoKHR { using element_type = ::VkRayTracingPipelineCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR; };
struct VkRayTracingPipelineCreateInfoNV { using element_type = ::VkRayTracingPipelineCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV; };
struct VkRayTracingPipelineInterfaceCreateInfoKHR { using element_type = ::VkRayTracingPipelineInterfaceCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR; };
struct VkRayTracingShaderGroupCreateInfoKHR { using element_type = ::VkRayTracingShaderGroupCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR; };
struct VkRayTracingShaderGroupCreateInfoNV { using element_type = ::VkRayTracingShaderGroupCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV; };
struct VkRayTracingShaderGroupTypeKHR { using element_type = ::VkRayTracingShaderGroupTypeKHR; using kind = format::kind::Enum; };
struct VkRect2D { using element_type = ::VkRect2D; using kind = format::kind::Struct; };
struct VkRectLayerKHR { using element_type = ::VkRectLayerKHR; using kind = format::kind::Struct; };
struct VkRefreshCycleDurationGOOGLE { using element_type = ::VkRefreshCycleDurationGOOGLE; using kind = format::kind::Struct; };
struct VkReleaseCapturedPipelineDataInfoKHR { using element_type = ::VkReleaseCapturedPipelineDataInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR; };
struct VkReleaseSwapchainImagesInfoKHR { using element_type = ::VkReleaseSwapchainImagesInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_KHR; };
struct VkRenderPass { using element_type = ::VkRenderPass; using kind = format::kind::Handle; };
struct VkRenderPassAttachmentBeginInfo { using element_type = ::VkRenderPassAttachmentBeginInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO; };
struct VkRenderPassBeginInfo { using element_type = ::VkRenderPassBeginInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO; };
struct VkRenderPassCreateFlags { using element_type = ::VkRenderPassCreateFlags; using kind = format::kind::Flags; };
struct VkRenderPassCreateInfo { using element_type = ::VkRenderPassCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO; };
struct VkRenderPassCreateInfo2 { using element_type = ::VkRenderPassCreateInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2; };
struct VkRenderPassCreationControlEXT { using element_type = ::VkRenderPassCreationControlEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT; };
struct VkRenderPassCreationFeedbackCreateInfoEXT { using element_type = ::VkRenderPassCreationFeedbackCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT; };
struct VkRenderPassCreationFeedbackInfoEXT { using element_type = ::VkRenderPassCreationFeedbackInfoEXT; using kind = format::kind::Struct; };
struct VkRenderPassFragmentDensityMapCreateInfoEXT { using element_type = ::VkRenderPassFragmentDensityMapCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT; };
struct VkRenderPassFragmentDensityMapOffsetEndInfoEXT { using element_type = ::VkRenderPassFragmentDensityMapOffsetEndInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT; };
struct VkRenderPassInputAttachmentAspectCreateInfo { using element_type = ::VkRenderPassInputAttachmentAspectCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO; };
struct VkRenderPassMultiviewCreateInfo { using element_type = ::VkRenderPassMultiviewCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO; };
struct VkRenderPassPerformanceCountersByRegionBeginInfoARM { using element_type = ::VkRenderPassPerformanceCountersByRegionBeginInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_PERFORMANCE_COUNTERS_BY_REGION_BEGIN_INFO_ARM; };
struct VkRenderPassSampleLocationsBeginInfoEXT { using element_type = ::VkRenderPassSampleLocationsBeginInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT; };
struct VkRenderPassStripeBeginInfoARM { using element_type = ::VkRenderPassStripeBeginInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM; };
struct VkRenderPassStripeInfoARM { using element_type = ::VkRenderPassStripeInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM; };
struct VkRenderPassStripeSubmitInfoARM { using element_type = ::VkRenderPassStripeSubmitInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM; };
struct VkRenderPassSubpassFeedbackCreateInfoEXT { using element_type = ::VkRenderPassSubpassFeedbackCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT; };
struct VkRenderPassSubpassFeedbackInfoEXT { using element_type = ::VkRenderPassSubpassFeedbackInfoEXT; using kind = format::kind::Struct; };
struct VkRenderPassTileShadingCreateInfoQCOM { using element_type = ::VkRenderPassTileShadingCreateInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM; };
struct VkRenderPassTransformBeginInfoQCOM { using element_type = ::VkRenderPassTransformBeginInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM; };
struct VkRenderingAreaInfo { using element_type = ::VkRenderingAreaInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDERING_AREA_INFO; };
struct VkRenderingAttachmentFlagsInfoKHR { using element_type = ::VkRenderingAttachmentFlagsInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_FLAGS_INFO_KHR; };
struct VkRenderingAttachmentFlagsKHR { using element_type = ::VkRenderingAttachmentFlagsKHR; using kind = format::kind::Flags; };
struct VkRenderingAttachmentInfo { using element_type = ::VkRenderingAttachmentInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO; };
struct VkRenderingAttachmentLocationInfo { using element_type = ::VkRenderingAttachmentLocationInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO; };
struct VkRenderingEndInfoKHR { using element_type = ::VkRenderingEndInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDERING_END_INFO_KHR; };
struct VkRenderingFlags { using element_type = ::VkRenderingFlags; using kind = format::kind::Flags; };
struct VkRenderingFragmentDensityMapAttachmentInfoEXT { using element_type = ::VkRenderingFragmentDensityMapAttachmentInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT; };
struct VkRenderingFragmentShadingRateAttachmentInfoKHR { using element_type = ::VkRenderingFragmentShadingRateAttachmentInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR; };
struct VkRenderingInfo { using element_type = ::VkRenderingInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDERING_INFO; };
struct VkRenderingInputAttachmentIndexInfo { using element_type = ::VkRenderingInputAttachmentIndexInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO; };
struct VkResolveImageFlagsKHR { using element_type = ::VkResolveImageFlagsKHR; using kind = format::kind::Flags; };
struct VkResolveImageInfo2 { using element_type = ::VkResolveImageInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2; };
struct VkResolveImageModeInfoKHR { using element_type = ::VkResolveImageModeInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_RESOLVE_IMAGE_MODE_INFO_KHR; };
struct VkResolveModeFlagBits { using element_type = ::VkResolveModeFlagBits; using kind = format::kind::Enum; };
struct VkResolveModeFlags { using element_type = ::VkResolveModeFlags; using kind = format::kind::Flags; };
struct VkResult { using element_type = ::VkResult; using kind = format::kind::Enum; };
struct VkSRTDataNV { using element_type = ::VkSRTDataNV; using kind = format::kind::Struct; };
struct VkSampleCountFlagBits { using element_type = ::VkSampleCountFlagBits; using kind = format::kind::Enum; };
struct VkSampleCountFlags { using element_type = ::VkSampleCountFlags; using kind = format::kind::Flags; };
struct VkSampleLocationEXT { using element_type = ::VkSampleLocationEXT; using kind = format::kind::Struct; };
struct VkSampleLocationsInfoEXT { using element_type = ::VkSampleLocationsInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT; };
struct VkSampleMask { using element_type = ::VkSampleMask; using kind = format::kind::SampleMask; };
struct VkSampler { using element_type = ::VkSampler; using kind = format::kind::Handle; };
struct VkSamplerAddressMode { using element_type = ::VkSamplerAddressMode; using kind = format::kind::Enum; };
struct VkSamplerBlockMatchWindowCreateInfoQCOM { using element_type = ::VkSamplerBlockMatchWindowCreateInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM; };
struct VkSamplerBorderColorComponentMappingCreateInfoEXT { using element_type = ::VkSamplerBorderColorComponentMappingCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT; };
struct VkSamplerCaptureDescriptorDataInfoEXT { using element_type = ::VkSamplerCaptureDescriptorDataInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT; };
struct VkSamplerCreateFlags { using element_type = ::VkSamplerCreateFlags; using kind = format::kind::Flags; };
struct VkSamplerCreateInfo { using element_type = ::VkSamplerCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO; };
struct VkSamplerCubicWeightsCreateInfoQCOM { using element_type = ::VkSamplerCubicWeightsCreateInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM; };
struct VkSamplerCustomBorderColorCreateInfoEXT { using element_type = ::VkSamplerCustomBorderColorCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT; };
struct VkSamplerMipmapMode { using element_type = ::VkSamplerMipmapMode; using kind = format::kind::Enum; };
struct VkSamplerReductionMode { using element_type = ::VkSamplerReductionMode; using kind = format::kind::Enum; };
struct VkSamplerReductionModeCreateInfo { using element_type = ::VkSamplerReductionModeCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO; };
struct VkSamplerYcbcrConversion { using element_type = ::VkSamplerYcbcrConversion; using kind = format::kind::Handle; };
struct VkSamplerYcbcrConversionCreateInfo { using element_type = ::VkSamplerYcbcrConversionCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO; };
struct VkSamplerYcbcrConversionImageFormatProperties { using element_type = ::VkSamplerYcbcrConversionImageFormatProperties; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES; };
struct VkSamplerYcbcrConversionInfo { using element_type = ::VkSamplerYcbcrConversionInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO; };
struct VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM { using element_type = ::VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM; };
struct VkSamplerYcbcrModelConversion { using element_type = ::VkSamplerYcbcrModelConversion; using kind = format::kind::Enum; };
struct VkSamplerYcbcrRange { using element_type = ::VkSamplerYcbcrRange; using kind = format::kind::Enum; };
struct VkScopeKHR { using element_type = ::VkScopeKHR; using kind = format::kind::Enum; };
struct VkScreenSurfaceCreateFlagsQNX { using element_type = ::VkScreenSurfaceCreateFlagsQNX; using kind = format::kind::Flags; };
struct VkScreenSurfaceCreateInfoQNX { using element_type = ::VkScreenSurfaceCreateInfoQNX; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX; };
struct VkSemaphore { using element_type = ::VkSemaphore; using kind = format::kind::Handle; };
struct VkSemaphoreCreateFlags { using element_type = ::VkSemaphoreCreateFlags; using kind = format::kind::Flags; };
struct VkSemaphoreCreateInfo { using element_type = ::VkSemaphoreCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO; };
struct VkSemaphoreGetFdInfoKHR { using element_type = ::VkSemaphoreGetFdInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR; };
struct VkSemaphoreGetWin32HandleInfoKHR { using element_type = ::VkSemaphoreGetWin32HandleInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR; };
struct VkSemaphoreGetZirconHandleInfoFUCHSIA { using element_type = ::VkSemaphoreGetZirconHandleInfoFUCHSIA; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA; };
struct VkSemaphoreImportFlags { using element_type = ::VkSemaphoreImportFlags; using kind = format::kind::Flags; };
struct VkSemaphoreSignalInfo { using element_type = ::VkSemaphoreSignalInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO; };
struct VkSemaphoreSubmitInfo { using element_type = ::VkSemaphoreSubmitInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO; };
struct VkSemaphoreType { using element_type = ::VkSemaphoreType; using kind = format::kind::Enum; };
struct VkSemaphoreTypeCreateInfo { using element_type = ::VkSemaphoreTypeCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO; };
struct VkSemaphoreWaitFlags { using element_type = ::VkSemaphoreWaitFlags; using kind = format::kind::Flags; };
struct VkSemaphoreWaitInfo { using element_type = ::VkSemaphoreWaitInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO; };
struct VkSetDescriptorBufferOffsetsInfoEXT { using element_type = ::VkSetDescriptorBufferOffsetsInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT; };
struct VkSetLatencyMarkerInfoNV { using element_type = ::VkSetLatencyMarkerInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV; };
struct VkSetPresentConfigNV { using element_type = ::VkSetPresentConfigNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV; };
struct VkSetStateFlagsIndirectCommandNV { using element_type = ::VkSetStateFlagsIndirectCommandNV; using kind = format::kind::Struct; };
struct VkShaderCodeTypeEXT { using element_type = ::VkShaderCodeTypeEXT; using kind = format::kind::Enum; };
struct VkShaderCorePropertiesFlagsAMD { using element_type = ::VkShaderCorePropertiesFlagsAMD; using kind = format::kind::Flags; };
struct VkShaderCreateFlagsEXT { using element_type = ::VkShaderCreateFlagsEXT; using kind = format::kind::Flags; };
struct VkShaderCreateInfoEXT { using element_type = ::VkShaderCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT; };
struct VkShaderEXT { using element_type = ::VkShaderEXT; using kind = format::kind::Handle; };
struct VkShaderFloatControlsIndependence { using element_type = ::VkShaderFloatControlsIndependence; using kind = format::kind::Enum; };
struct VkShaderGroupShaderKHR { using element_type = ::VkShaderGroupShaderKHR; using kind = format::kind::Enum; };
struct VkShaderInfoTypeAMD { using element_type = ::VkShaderInfoTypeAMD; using kind = format::kind::Enum; };
struct VkShaderModule { using element_type = ::VkShaderModule; using kind = format::kind::Handle; };
struct VkShaderModuleCreateFlags { using element_type = ::VkShaderModuleCreateFlags; using kind = format::kind::Flags; };
struct VkShaderModuleCreateInfo { using element_type = ::VkShaderModuleCreateInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO; };
struct VkShaderModuleIdentifierEXT { using element_type = ::VkShaderModuleIdentifierEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT; };
struct VkShaderModuleValidationCacheCreateInfoEXT { using element_type = ::VkShaderModuleValidationCacheCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT; };
struct VkShaderResourceUsageAMD { using element_type = ::VkShaderResourceUsageAMD; using kind = format::kind::Struct; };
struct VkShaderStageFlagBits { using element_type = ::VkShaderStageFlagBits; using kind = format::kind::Enum; };
struct VkShaderStageFlags { using element_type = ::VkShaderStageFlags; using kind = format::kind::Flags; };
struct VkShaderStatisticsInfoAMD { using element_type = ::VkShaderStatisticsInfoAMD; using kind = format::kind::Struct; };
struct VkShadingRatePaletteEntryNV { using element_type = ::VkShadingRatePaletteEntryNV; using kind = format::kind::Enum; };
struct VkShadingRatePaletteNV { using element_type = ::VkShadingRatePaletteNV; using kind = format::kind::Struct; };
struct VkSharedPresentSurfaceCapabilities2KHR { using element_type = ::VkSharedPresentSurfaceCapabilities2KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_2_KHR; };
struct VkSharedPresentSurfaceCapabilitiesKHR { using element_type = ::VkSharedPresentSurfaceCapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR; };
struct VkSharingMode { using element_type = ::VkSharingMode; using kind = format::kind::Enum; };
struct VkSparseBufferMemoryBindInfo { using element_type = ::VkSparseBufferMemoryBindInfo; using kind = format::kind::Struct; };
struct VkSparseImageFormatFlags { using element_type = ::VkSparseImageFormatFlags; using kind = format::kind::Flags; };
struct VkSparseImageFormatProperties { using element_type = ::VkSparseImageFormatProperties; using kind = format::kind::Struct; };
struct VkSparseImageFormatProperties2 { using element_type = ::VkSparseImageFormatProperties2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2; };
struct VkSparseImageMemoryBind { using element_type = ::VkSparseImageMemoryBind; using kind = format::kind::Struct; };
struct VkSparseImageMemoryBindInfo { using element_type = ::VkSparseImageMemoryBindInfo; using kind = format::kind::Struct; };
struct VkSparseImageMemoryRequirements { using element_type = ::VkSparseImageMemoryRequirements; using kind = format::kind::Struct; };
struct VkSparseImageMemoryRequirements2 { using element_type = ::VkSparseImageMemoryRequirements2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2; };
struct VkSparseImageOpaqueMemoryBindInfo { using element_type = ::VkSparseImageOpaqueMemoryBindInfo; using kind = format::kind::Struct; };
struct VkSparseMemoryBind { using element_type = ::VkSparseMemoryBind; using kind = format::kind::Struct; };
struct VkSparseMemoryBindFlags { using element_type = ::VkSparseMemoryBindFlags; using kind = format::kind::Flags; };
struct VkSpecializationInfo { using element_type = ::VkSpecializationInfo; using kind = format::kind::Struct; };
struct VkSpecializationMapEntry { using element_type = ::VkSpecializationMapEntry; using kind = format::kind::Struct; };
struct VkStencilFaceFlags { using element_type = ::VkStencilFaceFlags; using kind = format::kind::Flags; };
struct VkStencilOp { using element_type = ::VkStencilOp; using kind = format::kind::Enum; };
struct VkStencilOpState { using element_type = ::VkStencilOpState; using kind = format::kind::Struct; };
struct VkStreamDescriptorSurfaceCreateFlagsGGP { using element_type = ::VkStreamDescriptorSurfaceCreateFlagsGGP; using kind = format::kind::Flags; };
struct VkStreamDescriptorSurfaceCreateInfoGGP { using element_type = ::VkStreamDescriptorSurfaceCreateInfoGGP; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP; };
struct VkStridedDeviceAddressNV { using element_type = ::VkStridedDeviceAddressNV; using kind = format::kind::Struct; };
struct VkStridedDeviceAddressRangeKHR { using element_type = ::VkStridedDeviceAddressRangeKHR; using kind = format::kind::Struct; };
struct VkStridedDeviceAddressRegionKHR { using element_type = ::VkStridedDeviceAddressRegionKHR; using kind = format::kind::Struct; };
struct VkStructureType { using element_type = ::VkStructureType; using kind = format::kind::Enum; };
struct VkSubgroupFeatureFlags { using element_type = ::VkSubgroupFeatureFlags; using kind = format::kind::Flags; };
struct VkSubmitFlags { using element_type = ::VkSubmitFlags; using kind = format::kind::Flags; };
struct VkSubmitInfo { using element_type = ::VkSubmitInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SUBMIT_INFO; };
struct VkSubmitInfo2 { using element_type = ::VkSubmitInfo2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SUBMIT_INFO_2; };
struct VkSubpassBeginInfo { using element_type = ::VkSubpassBeginInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO; };
struct VkSubpassContents { using element_type = ::VkSubpassContents; using kind = format::kind::Enum; };
struct VkSubpassDependency { using element_type = ::VkSubpassDependency; using kind = format::kind::Struct; };
struct VkSubpassDependency2 { using element_type = ::VkSubpassDependency2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2; };
struct VkSubpassDescription { using element_type = ::VkSubpassDescription; using kind = format::kind::Struct; };
struct VkSubpassDescription2 { using element_type = ::VkSubpassDescription2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2; };
struct VkSubpassDescriptionDepthStencilResolve { using element_type = ::VkSubpassDescriptionDepthStencilResolve; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE; };
struct VkSubpassDescriptionFlags { using element_type = ::VkSubpassDescriptionFlags; using kind = format::kind::Flags; };
struct VkSubpassEndInfo { using element_type = ::VkSubpassEndInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SUBPASS_END_INFO; };
struct VkSubpassMergeStatusEXT { using element_type = ::VkSubpassMergeStatusEXT; using kind = format::kind::Enum; };
struct VkSubpassResolvePerformanceQueryEXT { using element_type = ::VkSubpassResolvePerformanceQueryEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT; };
struct VkSubpassSampleLocationsEXT { using element_type = ::VkSubpassSampleLocationsEXT; using kind = format::kind::Struct; };
struct VkSubresourceHostMemcpySize { using element_type = ::VkSubresourceHostMemcpySize; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE; };
struct VkSubresourceLayout { using element_type = ::VkSubresourceLayout; using kind = format::kind::Struct; };
struct VkSubresourceLayout2 { using element_type = ::VkSubresourceLayout2; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2; };
struct VkSurfaceCapabilities2EXT { using element_type = ::VkSurfaceCapabilities2EXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT; };
struct VkSurfaceCapabilities2KHR { using element_type = ::VkSurfaceCapabilities2KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR; };
struct VkSurfaceCapabilitiesFullScreenExclusiveEXT { using element_type = ::VkSurfaceCapabilitiesFullScreenExclusiveEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT; };
struct VkSurfaceCapabilitiesKHR { using element_type = ::VkSurfaceCapabilitiesKHR; using kind = format::kind::Struct; };
struct VkSurfaceCapabilitiesPresentBarrierNV { using element_type = ::VkSurfaceCapabilitiesPresentBarrierNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV; };
struct VkSurfaceCapabilitiesPresentId2KHR { using element_type = ::VkSurfaceCapabilitiesPresentId2KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_ID_2_KHR; };
struct VkSurfaceCapabilitiesPresentWait2KHR { using element_type = ::VkSurfaceCapabilitiesPresentWait2KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_WAIT_2_KHR; };
struct VkSurfaceCounterFlagBitsEXT { using element_type = ::VkSurfaceCounterFlagBitsEXT; using kind = format::kind::Enum; };
struct VkSurfaceCounterFlagsEXT { using element_type = ::VkSurfaceCounterFlagsEXT; using kind = format::kind::Flags; };
struct VkSurfaceFormat2KHR { using element_type = ::VkSurfaceFormat2KHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR; };
struct VkSurfaceFormatKHR { using element_type = ::VkSurfaceFormatKHR; using kind = format::kind::Struct; };
struct VkSurfaceFullScreenExclusiveInfoEXT { using element_type = ::VkSurfaceFullScreenExclusiveInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT; };
struct VkSurfaceFullScreenExclusiveWin32InfoEXT { using element_type = ::VkSurfaceFullScreenExclusiveWin32InfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT; };
struct VkSurfaceKHR { using element_type = ::VkSurfaceKHR; using kind = format::kind::Handle; };
struct VkSurfacePresentModeCompatibilityKHR { using element_type = ::VkSurfacePresentModeCompatibilityKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_KHR; };
struct VkSurfacePresentModeKHR { using element_type = ::VkSurfacePresentModeKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_KHR; };
struct VkSurfacePresentScalingCapabilitiesKHR { using element_type = ::VkSurfacePresentScalingCapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_KHR; };
struct VkSurfaceProtectedCapabilitiesKHR { using element_type = ::VkSurfaceProtectedCapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR; };
struct VkSurfaceTransformFlagBitsKHR { using element_type = ::VkSurfaceTransformFlagBitsKHR; using kind = format::kind::Enum; };
struct VkSurfaceTransformFlagsKHR { using element_type = ::VkSurfaceTransformFlagsKHR; using kind = format::kind::Flags; };
struct VkSwapchainCalibratedTimestampInfoEXT { using element_type = ::VkSwapchainCalibratedTimestampInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SWAPCHAIN_CALIBRATED_TIMESTAMP_INFO_EXT; };
struct VkSwapchainCounterCreateInfoEXT { using element_type = ::VkSwapchainCounterCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT; };
struct VkSwapchainCreateFlagsKHR { using element_type = ::VkSwapchainCreateFlagsKHR; using kind = format::kind::Flags; };
struct VkSwapchainCreateInfoKHR { using element_type = ::VkSwapchainCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR; };
struct VkSwapchainDisplayNativeHdrCreateInfoAMD { using element_type = ::VkSwapchainDisplayNativeHdrCreateInfoAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD; };
struct VkSwapchainFlagsSurfaceCapabilitiesEXT { using element_type = ::VkSwapchainFlagsSurfaceCapabilitiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SWAPCHAIN_FLAGS_SURFACE_CAPABILITIES_EXT; };
struct VkSwapchainKHR { using element_type = ::VkSwapchainKHR; using kind = format::kind::Handle; };
struct VkSwapchainLatencyCreateInfoNV { using element_type = ::VkSwapchainLatencyCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV; };
struct VkSwapchainPresentBarrierCreateInfoNV { using element_type = ::VkSwapchainPresentBarrierCreateInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV; };
struct VkSwapchainPresentFenceInfoKHR { using element_type = ::VkSwapchainPresentFenceInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_KHR; };
struct VkSwapchainPresentModeInfoKHR { using element_type = ::VkSwapchainPresentModeInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_KHR; };
struct VkSwapchainPresentModesCreateInfoKHR { using element_type = ::VkSwapchainPresentModesCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_KHR; };
struct VkSwapchainPresentScalingCreateInfoKHR { using element_type = ::VkSwapchainPresentScalingCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_KHR; };
struct VkSwapchainTimeDomainPropertiesEXT { using element_type = ::VkSwapchainTimeDomainPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SWAPCHAIN_TIME_DOMAIN_PROPERTIES_EXT; };
struct VkSwapchainTimingPropertiesEXT { using element_type = ::VkSwapchainTimingPropertiesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_SWAPCHAIN_TIMING_PROPERTIES_EXT; };
struct VkTensorARM { using element_type = ::VkTensorARM; using kind = format::kind::Handle; };
struct VkTensorCaptureDescriptorDataInfoARM { using element_type = ::VkTensorCaptureDescriptorDataInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TENSOR_CAPTURE_DESCRIPTOR_DATA_INFO_ARM; };
struct VkTensorCopyARM { using element_type = ::VkTensorCopyARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TENSOR_COPY_ARM; };
struct VkTensorCreateFlagsARM { using element_type = ::VkTensorCreateFlagsARM; using kind = format::kind::Flags64; };
struct VkTensorCreateInfoARM { using element_type = ::VkTensorCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TENSOR_CREATE_INFO_ARM; };
struct VkTensorDependencyInfoARM { using element_type = ::VkTensorDependencyInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TENSOR_DEPENDENCY_INFO_ARM; };
struct VkTensorDescriptionARM { using element_type = ::VkTensorDescriptionARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TENSOR_DESCRIPTION_ARM; };
struct VkTensorExplicitTilingFormatPropertiesARM { using element_type = ::VkTensorExplicitTilingFormatPropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TENSOR_EXPLICIT_TILING_FORMAT_PROPERTIES_ARM; };
struct VkTensorFormatPropertiesARM { using element_type = ::VkTensorFormatPropertiesARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TENSOR_FORMAT_PROPERTIES_ARM; };
struct VkTensorMemoryBarrierARM { using element_type = ::VkTensorMemoryBarrierARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TENSOR_MEMORY_BARRIER_ARM; };
struct VkTensorMemoryRequirementsInfoARM { using element_type = ::VkTensorMemoryRequirementsInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TENSOR_MEMORY_REQUIREMENTS_INFO_ARM; };
struct VkTensorRollingBackingCreateInfoARM { using element_type = ::VkTensorRollingBackingCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TENSOR_ROLLING_BACKING_CREATE_INFO_ARM; };
struct VkTensorTilingARM { using element_type = ::VkTensorTilingARM; using kind = format::kind::Enum; };
struct VkTensorUsageFlagsARM { using element_type = ::VkTensorUsageFlagsARM; using kind = format::kind::Flags64; };
struct VkTensorViewARM { using element_type = ::VkTensorViewARM; using kind = format::kind::Handle; };
struct VkTensorViewCaptureDescriptorDataInfoARM { using element_type = ::VkTensorViewCaptureDescriptorDataInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TENSOR_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_ARM; };
struct VkTensorViewCreateFlagsARM { using element_type = ::VkTensorViewCreateFlagsARM; using kind = format::kind::Flags64; };
struct VkTensorViewCreateInfoARM { using element_type = ::VkTensorViewCreateInfoARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TENSOR_VIEW_CREATE_INFO_ARM; };
struct VkTessellationDomainOrigin { using element_type = ::VkTessellationDomainOrigin; using kind = format::kind::Enum; };
struct VkTextureLODGatherFormatPropertiesAMD { using element_type = ::VkTextureLODGatherFormatPropertiesAMD; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD; };
struct VkThrottleHintSubmitInfoSEC { using element_type = ::VkThrottleHintSubmitInfoSEC; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_THROTTLE_HINT_SUBMIT_INFO_SEC; };
struct VkThrottleHintTypeSEC { using element_type = ::VkThrottleHintTypeSEC; using kind = format::kind::Enum; };
struct VkTileMemoryBindInfoQCOM { using element_type = ::VkTileMemoryBindInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM; };
struct VkTileMemoryRequirementsQCOM { using element_type = ::VkTileMemoryRequirementsQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TILE_MEMORY_REQUIREMENTS_QCOM; };
struct VkTileMemorySizeInfoQCOM { using element_type = ::VkTileMemorySizeInfoQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM; };
struct VkTilePropertiesQCOM { using element_type = ::VkTilePropertiesQCOM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM; };
struct VkTileShadingRenderPassFlagsQCOM { using element_type = ::VkTileShadingRenderPassFlagsQCOM; using kind = format::kind::Flags; };
struct VkTimeDomainKHR { using element_type = ::VkTimeDomainKHR; using kind = format::kind::Enum; };
struct VkTimelineSemaphoreSubmitInfo { using element_type = ::VkTimelineSemaphoreSubmitInfo; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO; };
struct VkToolPurposeFlags { using element_type = ::VkToolPurposeFlags; using kind = format::kind::Flags; };
struct VkTraceRaysIndirectCommand2KHR { using element_type = ::VkTraceRaysIndirectCommand2KHR; using kind = format::kind::Struct; };
struct VkTraceRaysIndirectCommandKHR { using element_type = ::VkTraceRaysIndirectCommandKHR; using kind = format::kind::Struct; };
struct VkTransformMatrixKHR { using element_type = ::VkTransformMatrixKHR; using kind = format::kind::Struct; };
struct VkValidationCacheCreateFlagsEXT { using element_type = ::VkValidationCacheCreateFlagsEXT; using kind = format::kind::Flags; };
struct VkValidationCacheCreateInfoEXT { using element_type = ::VkValidationCacheCreateInfoEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT; };
struct VkValidationCacheEXT { using element_type = ::VkValidationCacheEXT; using kind = format::kind::Handle; };
struct VkValidationCheckEXT { using element_type = ::VkValidationCheckEXT; using kind = format::kind::Enum; };
struct VkValidationFeatureDisableEXT { using element_type = ::VkValidationFeatureDisableEXT; using kind = format::kind::Enum; };
struct VkValidationFeatureEnableEXT { using element_type = ::VkValidationFeatureEnableEXT; using kind = format::kind::Enum; };
struct VkValidationFeaturesEXT { using element_type = ::VkValidationFeaturesEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT; };
struct VkValidationFlagsEXT { using element_type = ::VkValidationFlagsEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT; };
struct VkVertexInputAttributeDescription { using element_type = ::VkVertexInputAttributeDescription; using kind = format::kind::Struct; };
struct VkVertexInputAttributeDescription2EXT { using element_type = ::VkVertexInputAttributeDescription2EXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT; };
struct VkVertexInputBindingDescription { using element_type = ::VkVertexInputBindingDescription; using kind = format::kind::Struct; };
struct VkVertexInputBindingDescription2EXT { using element_type = ::VkVertexInputBindingDescription2EXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT; };
struct VkVertexInputBindingDivisorDescription { using element_type = ::VkVertexInputBindingDivisorDescription; using kind = format::kind::Struct; };
struct VkVertexInputRate { using element_type = ::VkVertexInputRate; using kind = format::kind::Enum; };
struct VkViSurfaceCreateFlagsNN { using element_type = ::VkViSurfaceCreateFlagsNN; using kind = format::kind::Flags; };
struct VkViSurfaceCreateInfoNN { using element_type = ::VkViSurfaceCreateInfoNN; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN; };
struct VkVideoBeginCodingFlagsKHR { using element_type = ::VkVideoBeginCodingFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoBeginCodingInfoKHR { using element_type = ::VkVideoBeginCodingInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR; };
struct VkVideoCapabilitiesKHR { using element_type = ::VkVideoCapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR; };
struct VkVideoCapabilityFlagsKHR { using element_type = ::VkVideoCapabilityFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoChromaSubsamplingFlagsKHR { using element_type = ::VkVideoChromaSubsamplingFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoCodecOperationFlagBitsKHR { using element_type = ::VkVideoCodecOperationFlagBitsKHR; using kind = format::kind::Enum; };
struct VkVideoCodecOperationFlagsKHR { using element_type = ::VkVideoCodecOperationFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoCodingControlFlagsKHR { using element_type = ::VkVideoCodingControlFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoCodingControlInfoKHR { using element_type = ::VkVideoCodingControlInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR; };
struct VkVideoComponentBitDepthFlagsKHR { using element_type = ::VkVideoComponentBitDepthFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoDecodeAV1CapabilitiesKHR { using element_type = ::VkVideoDecodeAV1CapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR; };
struct VkVideoDecodeAV1DpbSlotInfoKHR { using element_type = ::VkVideoDecodeAV1DpbSlotInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR; };
struct VkVideoDecodeAV1PictureInfoKHR { using element_type = ::VkVideoDecodeAV1PictureInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR; };
struct VkVideoDecodeAV1ProfileInfoKHR { using element_type = ::VkVideoDecodeAV1ProfileInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR; };
struct VkVideoDecodeAV1SessionParametersCreateInfoKHR { using element_type = ::VkVideoDecodeAV1SessionParametersCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR; };
struct VkVideoDecodeCapabilitiesKHR { using element_type = ::VkVideoDecodeCapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR; };
struct VkVideoDecodeCapabilityFlagsKHR { using element_type = ::VkVideoDecodeCapabilityFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoDecodeFlagsKHR { using element_type = ::VkVideoDecodeFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoDecodeH264CapabilitiesKHR { using element_type = ::VkVideoDecodeH264CapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR; };
struct VkVideoDecodeH264DpbSlotInfoKHR { using element_type = ::VkVideoDecodeH264DpbSlotInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR; };
struct VkVideoDecodeH264PictureInfoKHR { using element_type = ::VkVideoDecodeH264PictureInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR; };
struct VkVideoDecodeH264PictureLayoutFlagBitsKHR { using element_type = ::VkVideoDecodeH264PictureLayoutFlagBitsKHR; using kind = format::kind::Enum; };
struct VkVideoDecodeH264ProfileInfoKHR { using element_type = ::VkVideoDecodeH264ProfileInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR; };
struct VkVideoDecodeH264SessionParametersAddInfoKHR { using element_type = ::VkVideoDecodeH264SessionParametersAddInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR; };
struct VkVideoDecodeH264SessionParametersCreateInfoKHR { using element_type = ::VkVideoDecodeH264SessionParametersCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR; };
struct VkVideoDecodeInfoKHR { using element_type = ::VkVideoDecodeInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR; };
struct VkVideoDecodeUsageFlagsKHR { using element_type = ::VkVideoDecodeUsageFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoDecodeUsageInfoKHR { using element_type = ::VkVideoDecodeUsageInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR; };
struct VkVideoDecodeVP9CapabilitiesKHR { using element_type = ::VkVideoDecodeVP9CapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_CAPABILITIES_KHR; };
struct VkVideoDecodeVP9PictureInfoKHR { using element_type = ::VkVideoDecodeVP9PictureInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR; };
struct VkVideoDecodeVP9ProfileInfoKHR { using element_type = ::VkVideoDecodeVP9ProfileInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PROFILE_INFO_KHR; };
struct VkVideoEncodeAV1CapabilitiesKHR { using element_type = ::VkVideoEncodeAV1CapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR; };
struct VkVideoEncodeAV1CapabilityFlagsKHR { using element_type = ::VkVideoEncodeAV1CapabilityFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeAV1DpbSlotInfoKHR { using element_type = ::VkVideoEncodeAV1DpbSlotInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR; };
struct VkVideoEncodeAV1FrameSizeKHR { using element_type = ::VkVideoEncodeAV1FrameSizeKHR; using kind = format::kind::Struct; };
struct VkVideoEncodeAV1GopRemainingFrameInfoKHR { using element_type = ::VkVideoEncodeAV1GopRemainingFrameInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR; };
struct VkVideoEncodeAV1PictureInfoKHR { using element_type = ::VkVideoEncodeAV1PictureInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR; };
struct VkVideoEncodeAV1PredictionModeKHR { using element_type = ::VkVideoEncodeAV1PredictionModeKHR; using kind = format::kind::Enum; };
struct VkVideoEncodeAV1ProfileInfoKHR { using element_type = ::VkVideoEncodeAV1ProfileInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR; };
struct VkVideoEncodeAV1QIndexKHR { using element_type = ::VkVideoEncodeAV1QIndexKHR; using kind = format::kind::Struct; };
struct VkVideoEncodeAV1QualityLevelPropertiesKHR { using element_type = ::VkVideoEncodeAV1QualityLevelPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR; };
struct VkVideoEncodeAV1QuantizationMapCapabilitiesKHR { using element_type = ::VkVideoEncodeAV1QuantizationMapCapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR; };
struct VkVideoEncodeAV1RateControlFlagsKHR { using element_type = ::VkVideoEncodeAV1RateControlFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeAV1RateControlGroupKHR { using element_type = ::VkVideoEncodeAV1RateControlGroupKHR; using kind = format::kind::Enum; };
struct VkVideoEncodeAV1RateControlInfoKHR { using element_type = ::VkVideoEncodeAV1RateControlInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR; };
struct VkVideoEncodeAV1RateControlLayerInfoKHR { using element_type = ::VkVideoEncodeAV1RateControlLayerInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR; };
struct VkVideoEncodeAV1SessionCreateInfoKHR { using element_type = ::VkVideoEncodeAV1SessionCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR; };
struct VkVideoEncodeAV1SessionParametersCreateInfoKHR { using element_type = ::VkVideoEncodeAV1SessionParametersCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR; };
struct VkVideoEncodeAV1StdFlagsKHR { using element_type = ::VkVideoEncodeAV1StdFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeAV1SuperblockSizeFlagsKHR { using element_type = ::VkVideoEncodeAV1SuperblockSizeFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeCapabilitiesKHR { using element_type = ::VkVideoEncodeCapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR; };
struct VkVideoEncodeCapabilityFlagsKHR { using element_type = ::VkVideoEncodeCapabilityFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeContentFlagsKHR { using element_type = ::VkVideoEncodeContentFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeFeedback2CapabilitiesKHR { using element_type = ::VkVideoEncodeFeedback2CapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_FEEDBACK_2_CAPABILITIES_KHR; };
struct VkVideoEncodeFeedbackFlagsKHR { using element_type = ::VkVideoEncodeFeedbackFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeFlagsKHR { using element_type = ::VkVideoEncodeFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeH264CapabilitiesKHR { using element_type = ::VkVideoEncodeH264CapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR; };
struct VkVideoEncodeH264CapabilityFlagsKHR { using element_type = ::VkVideoEncodeH264CapabilityFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeH264DpbSlotInfoKHR { using element_type = ::VkVideoEncodeH264DpbSlotInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR; };
struct VkVideoEncodeH264FrameSizeKHR { using element_type = ::VkVideoEncodeH264FrameSizeKHR; using kind = format::kind::Struct; };
struct VkVideoEncodeH264GopRemainingFrameInfoKHR { using element_type = ::VkVideoEncodeH264GopRemainingFrameInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR; };
struct VkVideoEncodeH264NaluSliceInfoKHR { using element_type = ::VkVideoEncodeH264NaluSliceInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR; };
struct VkVideoEncodeH264PictureInfoKHR { using element_type = ::VkVideoEncodeH264PictureInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR; };
struct VkVideoEncodeH264ProfileInfoKHR { using element_type = ::VkVideoEncodeH264ProfileInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR; };
struct VkVideoEncodeH264QpKHR { using element_type = ::VkVideoEncodeH264QpKHR; using kind = format::kind::Struct; };
struct VkVideoEncodeH264QualityLevelPropertiesKHR { using element_type = ::VkVideoEncodeH264QualityLevelPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR; };
struct VkVideoEncodeH264QuantizationMapCapabilitiesKHR { using element_type = ::VkVideoEncodeH264QuantizationMapCapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR; };
struct VkVideoEncodeH264RateControlFlagsKHR { using element_type = ::VkVideoEncodeH264RateControlFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeH264RateControlInfoKHR { using element_type = ::VkVideoEncodeH264RateControlInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR; };
struct VkVideoEncodeH264RateControlLayerInfoKHR { using element_type = ::VkVideoEncodeH264RateControlLayerInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR; };
struct VkVideoEncodeH264SessionCreateInfoKHR { using element_type = ::VkVideoEncodeH264SessionCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR; };
struct VkVideoEncodeH264SessionParametersAddInfoKHR { using element_type = ::VkVideoEncodeH264SessionParametersAddInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR; };
struct VkVideoEncodeH264SessionParametersCreateInfoKHR { using element_type = ::VkVideoEncodeH264SessionParametersCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR; };
struct VkVideoEncodeH264SessionParametersFeedbackInfoKHR { using element_type = ::VkVideoEncodeH264SessionParametersFeedbackInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR; };
struct VkVideoEncodeH264SessionParametersGetInfoKHR { using element_type = ::VkVideoEncodeH264SessionParametersGetInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR; };
struct VkVideoEncodeH264StdFlagsKHR { using element_type = ::VkVideoEncodeH264StdFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeH265CtbSizeFlagsKHR { using element_type = ::VkVideoEncodeH265CtbSizeFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeH265QuantizationMapCapabilitiesKHR { using element_type = ::VkVideoEncodeH265QuantizationMapCapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR; };
struct VkVideoEncodeInfoKHR { using element_type = ::VkVideoEncodeInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR; };
struct VkVideoEncodeIntraRefreshCapabilitiesKHR { using element_type = ::VkVideoEncodeIntraRefreshCapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_CAPABILITIES_KHR; };
struct VkVideoEncodeIntraRefreshInfoKHR { using element_type = ::VkVideoEncodeIntraRefreshInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR; };
struct VkVideoEncodeIntraRefreshModeFlagBitsKHR { using element_type = ::VkVideoEncodeIntraRefreshModeFlagBitsKHR; using kind = format::kind::Enum; };
struct VkVideoEncodeIntraRefreshModeFlagsKHR { using element_type = ::VkVideoEncodeIntraRefreshModeFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodePerPartitionFeedbackFlagsKHR { using element_type = ::VkVideoEncodePerPartitionFeedbackFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeProfileRgbConversionInfoVALVE { using element_type = ::VkVideoEncodeProfileRgbConversionInfoVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_PROFILE_RGB_CONVERSION_INFO_VALVE; };
struct VkVideoEncodeQualityLevelInfoKHR { using element_type = ::VkVideoEncodeQualityLevelInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR; };
struct VkVideoEncodeQualityLevelPropertiesKHR { using element_type = ::VkVideoEncodeQualityLevelPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR; };
struct VkVideoEncodeQuantizationMapCapabilitiesKHR { using element_type = ::VkVideoEncodeQuantizationMapCapabilitiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR; };
struct VkVideoEncodeQuantizationMapInfoKHR { using element_type = ::VkVideoEncodeQuantizationMapInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR; };
struct VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR { using element_type = ::VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR; };
struct VkVideoEncodeRateControlFlagsKHR { using element_type = ::VkVideoEncodeRateControlFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeRateControlInfoKHR { using element_type = ::VkVideoEncodeRateControlInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR; };
struct VkVideoEncodeRateControlLayerInfoKHR { using element_type = ::VkVideoEncodeRateControlLayerInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR; };
struct VkVideoEncodeRateControlModeFlagBitsKHR { using element_type = ::VkVideoEncodeRateControlModeFlagBitsKHR; using kind = format::kind::Enum; };
struct VkVideoEncodeRateControlModeFlagsKHR { using element_type = ::VkVideoEncodeRateControlModeFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeRgbChromaOffsetFlagBitsVALVE { using element_type = ::VkVideoEncodeRgbChromaOffsetFlagBitsVALVE; using kind = format::kind::Enum; };
struct VkVideoEncodeRgbChromaOffsetFlagsVALVE { using element_type = ::VkVideoEncodeRgbChromaOffsetFlagsVALVE; using kind = format::kind::Flags; };
struct VkVideoEncodeRgbConversionCapabilitiesVALVE { using element_type = ::VkVideoEncodeRgbConversionCapabilitiesVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_RGB_CONVERSION_CAPABILITIES_VALVE; };
struct VkVideoEncodeRgbModelConversionFlagBitsVALVE { using element_type = ::VkVideoEncodeRgbModelConversionFlagBitsVALVE; using kind = format::kind::Enum; };
struct VkVideoEncodeRgbModelConversionFlagsVALVE { using element_type = ::VkVideoEncodeRgbModelConversionFlagsVALVE; using kind = format::kind::Flags; };
struct VkVideoEncodeRgbRangeCompressionFlagBitsVALVE { using element_type = ::VkVideoEncodeRgbRangeCompressionFlagBitsVALVE; using kind = format::kind::Enum; };
struct VkVideoEncodeRgbRangeCompressionFlagsVALVE { using element_type = ::VkVideoEncodeRgbRangeCompressionFlagsVALVE; using kind = format::kind::Flags; };
struct VkVideoEncodeSessionIntraRefreshCreateInfoKHR { using element_type = ::VkVideoEncodeSessionIntraRefreshCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_INTRA_REFRESH_CREATE_INFO_KHR; };
struct VkVideoEncodeSessionParametersFeedbackInfoKHR { using element_type = ::VkVideoEncodeSessionParametersFeedbackInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR; };
struct VkVideoEncodeSessionParametersGetInfoKHR { using element_type = ::VkVideoEncodeSessionParametersGetInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR; };
struct VkVideoEncodeSessionRgbConversionCreateInfoVALVE { using element_type = ::VkVideoEncodeSessionRgbConversionCreateInfoVALVE; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_RGB_CONVERSION_CREATE_INFO_VALVE; };
struct VkVideoEncodeTuningModeKHR { using element_type = ::VkVideoEncodeTuningModeKHR; using kind = format::kind::Enum; };
struct VkVideoEncodeUsageFlagsKHR { using element_type = ::VkVideoEncodeUsageFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEncodeUsageInfoKHR { using element_type = ::VkVideoEncodeUsageInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR; };
struct VkVideoEndCodingFlagsKHR { using element_type = ::VkVideoEndCodingFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoEndCodingInfoKHR { using element_type = ::VkVideoEndCodingInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR; };
struct VkVideoFormatAV1QuantizationMapPropertiesKHR { using element_type = ::VkVideoFormatAV1QuantizationMapPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR; };
struct VkVideoFormatH265QuantizationMapPropertiesKHR { using element_type = ::VkVideoFormatH265QuantizationMapPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR; };
struct VkVideoFormatPropertiesKHR { using element_type = ::VkVideoFormatPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR; };
struct VkVideoFormatQuantizationMapPropertiesKHR { using element_type = ::VkVideoFormatQuantizationMapPropertiesKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR; };
struct VkVideoInlineQueryInfoKHR { using element_type = ::VkVideoInlineQueryInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR; };
struct VkVideoPictureResourceInfoKHR { using element_type = ::VkVideoPictureResourceInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR; };
struct VkVideoProfileInfoKHR { using element_type = ::VkVideoProfileInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR; };
struct VkVideoProfileListInfoKHR { using element_type = ::VkVideoProfileListInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR; };
struct VkVideoReferenceIntraRefreshInfoKHR { using element_type = ::VkVideoReferenceIntraRefreshInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR; };
struct VkVideoReferenceSlotInfoKHR { using element_type = ::VkVideoReferenceSlotInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR; };
struct VkVideoSessionCreateFlagsKHR { using element_type = ::VkVideoSessionCreateFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoSessionCreateInfoKHR { using element_type = ::VkVideoSessionCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR; };
struct VkVideoSessionKHR { using element_type = ::VkVideoSessionKHR; using kind = format::kind::Handle; };
struct VkVideoSessionMemoryRequirementsKHR { using element_type = ::VkVideoSessionMemoryRequirementsKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR; };
struct VkVideoSessionParametersCreateFlagsKHR { using element_type = ::VkVideoSessionParametersCreateFlagsKHR; using kind = format::kind::Flags; };
struct VkVideoSessionParametersCreateInfoKHR { using element_type = ::VkVideoSessionParametersCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR; };
struct VkVideoSessionParametersKHR { using element_type = ::VkVideoSessionParametersKHR; using kind = format::kind::Handle; };
struct VkVideoSessionParametersUpdateInfoKHR { using element_type = ::VkVideoSessionParametersUpdateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR; };
struct VkViewport { using element_type = ::VkViewport; using kind = format::kind::Struct; };
struct VkViewportCoordinateSwizzleNV { using element_type = ::VkViewportCoordinateSwizzleNV; using kind = format::kind::Enum; };
struct VkViewportSwizzleNV { using element_type = ::VkViewportSwizzleNV; using kind = format::kind::Struct; };
struct VkViewportWScalingNV { using element_type = ::VkViewportWScalingNV; using kind = format::kind::Struct; };
struct VkWaylandSurfaceCreateFlagsKHR { using element_type = ::VkWaylandSurfaceCreateFlagsKHR; using kind = format::kind::Flags; };
struct VkWaylandSurfaceCreateInfoKHR { using element_type = ::VkWaylandSurfaceCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR; };
struct VkWin32KeyedMutexAcquireReleaseInfoKHR { using element_type = ::VkWin32KeyedMutexAcquireReleaseInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR; };
struct VkWin32KeyedMutexAcquireReleaseInfoNV { using element_type = ::VkWin32KeyedMutexAcquireReleaseInfoNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV; };
struct VkWin32SurfaceCreateFlagsKHR { using element_type = ::VkWin32SurfaceCreateFlagsKHR; using kind = format::kind::Flags; };
struct VkWin32SurfaceCreateInfoKHR { using element_type = ::VkWin32SurfaceCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR; };
struct VkWriteDescriptorSet { using element_type = ::VkWriteDescriptorSet; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET; };
struct VkWriteDescriptorSetAccelerationStructureKHR { using element_type = ::VkWriteDescriptorSetAccelerationStructureKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR; };
struct VkWriteDescriptorSetAccelerationStructureNV { using element_type = ::VkWriteDescriptorSetAccelerationStructureNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV; };
struct VkWriteDescriptorSetInlineUniformBlock { using element_type = ::VkWriteDescriptorSetInlineUniformBlock; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK; };
struct VkWriteDescriptorSetPartitionedAccelerationStructureNV { using element_type = ::VkWriteDescriptorSetPartitionedAccelerationStructureNV; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV; };
struct VkWriteDescriptorSetTensorARM { using element_type = ::VkWriteDescriptorSetTensorARM; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_TENSOR_ARM; };
struct VkWriteIndirectExecutionSetPipelineEXT { using element_type = ::VkWriteIndirectExecutionSetPipelineEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_PIPELINE_EXT; };
struct VkWriteIndirectExecutionSetShaderEXT { using element_type = ::VkWriteIndirectExecutionSetShaderEXT; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_SHADER_EXT; };
struct VkXYColorEXT { using element_type = ::VkXYColorEXT; using kind = format::kind::Struct; };
struct VkXcbSurfaceCreateFlagsKHR { using element_type = ::VkXcbSurfaceCreateFlagsKHR; using kind = format::kind::Flags; };
struct VkXcbSurfaceCreateInfoKHR { using element_type = ::VkXcbSurfaceCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR; };
struct VkXlibSurfaceCreateFlagsKHR { using element_type = ::VkXlibSurfaceCreateFlagsKHR; using kind = format::kind::Flags; };
struct VkXlibSurfaceCreateInfoKHR { using element_type = ::VkXlibSurfaceCreateInfoKHR; using kind = format::kind::Struct; static constexpr ::VkStructureType structure_type = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR; };
struct Void { using element_type = void; using kind = format::kind::Void; };
struct WChar { using element_type = wchar_t; using kind = format::kind::WChar; };
GFXRECON_END_NAMESPACE(api_types)

// The catalog: what exists, per genre, as lists of descriptors by name. A sub-list is a fact the generator
// applied, so no list is filtered at compile time.
GFXRECON_BEGIN_NAMESPACE(catalog)

// Every structure descriptor.
using structures = util::TypeList<
    api_types::SECURITY_ATTRIBUTES,
    api_types::StdVideoAV1CDEF,
    api_types::StdVideoAV1ColorConfig,
    api_types::StdVideoAV1ColorConfigFlags,
    api_types::StdVideoAV1FilmGrain,
    api_types::StdVideoAV1FilmGrainFlags,
    api_types::StdVideoAV1GlobalMotion,
    api_types::StdVideoAV1LoopFilter,
    api_types::StdVideoAV1LoopFilterFlags,
    api_types::StdVideoAV1LoopRestoration,
    api_types::StdVideoAV1Quantization,
    api_types::StdVideoAV1QuantizationFlags,
    api_types::StdVideoAV1Segmentation,
    api_types::StdVideoAV1SequenceHeader,
    api_types::StdVideoAV1SequenceHeaderFlags,
    api_types::StdVideoAV1TileInfo,
    api_types::StdVideoAV1TileInfoFlags,
    api_types::StdVideoAV1TimingInfo,
    api_types::StdVideoAV1TimingInfoFlags,
    api_types::StdVideoDecodeAV1PictureInfo,
    api_types::StdVideoDecodeAV1PictureInfoFlags,
    api_types::StdVideoDecodeAV1ReferenceInfo,
    api_types::StdVideoDecodeAV1ReferenceInfoFlags,
    api_types::StdVideoDecodeH264PictureInfo,
    api_types::StdVideoDecodeH264PictureInfoFlags,
    api_types::StdVideoDecodeH264ReferenceInfo,
    api_types::StdVideoDecodeH264ReferenceInfoFlags,
    api_types::StdVideoDecodeVP9PictureInfo,
    api_types::StdVideoDecodeVP9PictureInfoFlags,
    api_types::StdVideoEncodeAV1DecoderModelInfo,
    api_types::StdVideoEncodeAV1ExtensionHeader,
    api_types::StdVideoEncodeAV1OperatingPointInfo,
    api_types::StdVideoEncodeAV1OperatingPointInfoFlags,
    api_types::StdVideoEncodeAV1PictureInfo,
    api_types::StdVideoEncodeAV1PictureInfoFlags,
    api_types::StdVideoEncodeAV1ReferenceInfo,
    api_types::StdVideoEncodeAV1ReferenceInfoFlags,
    api_types::StdVideoEncodeH264PictureInfo,
    api_types::StdVideoEncodeH264PictureInfoFlags,
    api_types::StdVideoEncodeH264RefListModEntry,
    api_types::StdVideoEncodeH264RefPicMarkingEntry,
    api_types::StdVideoEncodeH264ReferenceInfo,
    api_types::StdVideoEncodeH264ReferenceInfoFlags,
    api_types::StdVideoEncodeH264ReferenceListsInfo,
    api_types::StdVideoEncodeH264ReferenceListsInfoFlags,
    api_types::StdVideoEncodeH264SliceHeader,
    api_types::StdVideoEncodeH264SliceHeaderFlags,
    api_types::StdVideoEncodeH264WeightTable,
    api_types::StdVideoEncodeH264WeightTableFlags,
    api_types::StdVideoH264HrdParameters,
    api_types::StdVideoH264PictureParameterSet,
    api_types::StdVideoH264PpsFlags,
    api_types::StdVideoH264ScalingLists,
    api_types::StdVideoH264SequenceParameterSet,
    api_types::StdVideoH264SequenceParameterSetVui,
    api_types::StdVideoH264SpsFlags,
    api_types::StdVideoH264SpsVuiFlags,
    api_types::StdVideoVP9ColorConfig,
    api_types::StdVideoVP9ColorConfigFlags,
    api_types::StdVideoVP9LoopFilter,
    api_types::StdVideoVP9LoopFilterFlags,
    api_types::StdVideoVP9Segmentation,
    api_types::StdVideoVP9SegmentationFlags,
    api_types::VkAabbPositionsKHR,
    api_types::VkAccelerationStructureBuildGeometryInfoKHR,
    api_types::VkAccelerationStructureBuildRangeInfoKHR,
    api_types::VkAccelerationStructureBuildSizesInfoKHR,
    api_types::VkAccelerationStructureCaptureDescriptorDataInfoEXT,
    api_types::VkAccelerationStructureCreateInfo2KHR,
    api_types::VkAccelerationStructureCreateInfoKHR,
    api_types::VkAccelerationStructureCreateInfoNV,
    api_types::VkAccelerationStructureDeviceAddressInfoKHR,
    api_types::VkAccelerationStructureGeometryAabbsDataKHR,
    api_types::VkAccelerationStructureGeometryInstancesDataKHR,
    api_types::VkAccelerationStructureGeometryKHR,
    api_types::VkAccelerationStructureGeometryLinearSweptSpheresDataNV,
    api_types::VkAccelerationStructureGeometryMicromapDataKHR,
    api_types::VkAccelerationStructureGeometryMotionTrianglesDataNV,
    api_types::VkAccelerationStructureGeometrySpheresDataNV,
    api_types::VkAccelerationStructureGeometryTrianglesDataKHR,
    api_types::VkAccelerationStructureInfoNV,
    api_types::VkAccelerationStructureInstanceKHR,
    api_types::VkAccelerationStructureMatrixMotionInstanceNV,
    api_types::VkAccelerationStructureMemoryRequirementsInfoNV,
    api_types::VkAccelerationStructureMotionInfoNV,
    api_types::VkAccelerationStructureSRTMotionInstanceNV,
    api_types::VkAccelerationStructureTrianglesDisplacementMicromapNV,
    api_types::VkAccelerationStructureTrianglesOpacityMicromapEXT,
    api_types::VkAccelerationStructureTrianglesOpacityMicromapKHR,
    api_types::VkAccelerationStructureVersionInfoKHR,
    api_types::VkAcquireNextImageInfoKHR,
    api_types::VkAcquireProfilingLockInfoKHR,
    api_types::VkAllocationCallbacks,
    api_types::VkAmigoProfilingSubmitInfoSEC,
    api_types::VkAndroidHardwareBufferFormatProperties2ANDROID,
    api_types::VkAndroidHardwareBufferFormatPropertiesANDROID,
    api_types::VkAndroidHardwareBufferFormatResolvePropertiesANDROID,
    api_types::VkAndroidHardwareBufferPropertiesANDROID,
    api_types::VkAndroidHardwareBufferUsageANDROID,
    api_types::VkAndroidSurfaceCreateInfoKHR,
    api_types::VkAntiLagDataAMD,
    api_types::VkAntiLagPresentationInfoAMD,
    api_types::VkApplicationInfo,
    api_types::VkAttachmentDescription,
    api_types::VkAttachmentDescription2,
    api_types::VkAttachmentDescriptionStencilLayout,
    api_types::VkAttachmentFeedbackLoopInfoEXT,
    api_types::VkAttachmentReference,
    api_types::VkAttachmentReference2,
    api_types::VkAttachmentReferenceStencilLayout,
    api_types::VkAttachmentSampleCountInfoAMD,
    api_types::VkAttachmentSampleLocationsEXT,
    api_types::VkBaseOutStructure,
    api_types::VkBeginCustomResolveInfoEXT,
    api_types::VkBindAccelerationStructureMemoryInfoNV,
    api_types::VkBindBufferMemoryDeviceGroupInfo,
    api_types::VkBindBufferMemoryInfo,
    api_types::VkBindDataGraphPipelineSessionMemoryInfoARM,
    api_types::VkBindDescriptorBufferEmbeddedSamplersInfoEXT,
    api_types::VkBindDescriptorSetsInfo,
    api_types::VkBindImageMemoryDeviceGroupInfo,
    api_types::VkBindImageMemoryInfo,
    api_types::VkBindImageMemorySwapchainInfoKHR,
    api_types::VkBindImagePlaneMemoryInfo,
    api_types::VkBindIndexBuffer3InfoKHR,
    api_types::VkBindIndexBufferIndirectCommandEXT,
    api_types::VkBindIndexBufferIndirectCommandNV,
    api_types::VkBindMemoryStatus,
    api_types::VkBindPipelineIndirectCommandNV,
    api_types::VkBindShaderGroupIndirectCommandNV,
    api_types::VkBindSparseInfo,
    api_types::VkBindTensorMemoryInfoARM,
    api_types::VkBindTransformFeedbackBuffer2InfoEXT,
    api_types::VkBindVertexBuffer3InfoKHR,
    api_types::VkBindVertexBufferIndirectCommandEXT,
    api_types::VkBindVertexBufferIndirectCommandNV,
    api_types::VkBindVideoSessionMemoryInfoKHR,
    api_types::VkBlitImageCubicWeightsInfoQCOM,
    api_types::VkBlitImageInfo2,
    api_types::VkBufferCaptureDescriptorDataInfoEXT,
    api_types::VkBufferCopy,
    api_types::VkBufferCopy2,
    api_types::VkBufferCreateInfo,
    api_types::VkBufferDeviceAddressAlignmentAllocateInfoVALVE,
    api_types::VkBufferDeviceAddressCreateInfoEXT,
    api_types::VkBufferDeviceAddressInfo,
    api_types::VkBufferImageCopy,
    api_types::VkBufferImageCopy2,
    api_types::VkBufferMemoryBarrier,
    api_types::VkBufferMemoryBarrier2,
    api_types::VkBufferMemoryRequirementsInfo2,
    api_types::VkBufferOpaqueCaptureAddressCreateInfo,
    api_types::VkBufferUsageFlags2CreateInfo,
    api_types::VkBufferViewCreateInfo,
    api_types::VkBuildPartitionedAccelerationStructureIndirectCommandNV,
    api_types::VkBuildPartitionedAccelerationStructureInfoNV,
    api_types::VkCalibratedTimestampInfoKHR,
    api_types::VkCheckpointData2NV,
    api_types::VkCheckpointDataNV,
    api_types::VkClearAttachment,
    api_types::VkClearColorValue,
    api_types::VkClearDepthStencilValue,
    api_types::VkClearRect,
    api_types::VkClearValue,
    api_types::VkCoarseSampleLocationNV,
    api_types::VkCoarseSampleOrderCustomNV,
    api_types::VkColorBlendAdvancedEXT,
    api_types::VkColorBlendEquationEXT,
    api_types::VkCommandBufferAllocateInfo,
    api_types::VkCommandBufferBeginInfo,
    api_types::VkCommandBufferInheritanceConditionalRenderingInfoEXT,
    api_types::VkCommandBufferInheritanceInfo,
    api_types::VkCommandBufferInheritanceRenderPassTransformInfoQCOM,
    api_types::VkCommandBufferInheritanceRenderingInfo,
    api_types::VkCommandBufferInheritanceViewportScissorInfoNV,
    api_types::VkCommandBufferSubmitInfo,
    api_types::VkCommandPoolCreateInfo,
    api_types::VkComponentMapping,
    api_types::VkComputeOccupancyPriorityParametersNV,
    api_types::VkComputePipelineCreateInfo,
    api_types::VkComputePipelineIndirectBufferInfoNV,
    api_types::VkConditionalRenderingBeginInfo2EXT,
    api_types::VkConditionalRenderingBeginInfoEXT,
    api_types::VkConformanceVersion,
    api_types::VkConvertCooperativeVectorMatrixInfoNV,
    api_types::VkCooperativeMatrixFlexibleDimensionsPropertiesNV,
    api_types::VkCooperativeMatrixProperties2EXT,
    api_types::VkCooperativeMatrixPropertiesKHR,
    api_types::VkCooperativeMatrixPropertiesNV,
    api_types::VkCooperativeVectorPropertiesNV,
    api_types::VkCopyAccelerationStructureInfoKHR,
    api_types::VkCopyAccelerationStructureToMemoryInfoKHR,
    api_types::VkCopyBufferInfo2,
    api_types::VkCopyBufferToImageInfo2,
    api_types::VkCopyCommandTransformInfoQCOM,
    api_types::VkCopyDescriptorSet,
    api_types::VkCopyDeviceMemoryImageInfoKHR,
    api_types::VkCopyDeviceMemoryInfoKHR,
    api_types::VkCopyImageInfo2,
    api_types::VkCopyImageToBufferInfo2,
    api_types::VkCopyImageToImageInfo,
    api_types::VkCopyImageToMemoryInfo,
    api_types::VkCopyMemoryIndirectCommandKHR,
    api_types::VkCopyMemoryIndirectInfoKHR,
    api_types::VkCopyMemoryToAccelerationStructureInfoKHR,
    api_types::VkCopyMemoryToImageIndirectCommandKHR,
    api_types::VkCopyMemoryToImageIndirectInfoKHR,
    api_types::VkCopyMemoryToImageInfo,
    api_types::VkCopyMemoryToMicromapInfoEXT,
    api_types::VkCopyMicromapInfoEXT,
    api_types::VkCopyMicromapToMemoryInfoEXT,
    api_types::VkCopyTensorInfoARM,
    api_types::VkCustomResolveCreateInfoEXT,
    api_types::VkD3D12FenceSubmitInfoKHR,
    api_types::VkDataGraphOpticalFlowImageFormatInfoARM,
    api_types::VkDataGraphOpticalFlowImageFormatPropertiesARM,
    api_types::VkDataGraphPipelineBuiltinModelCreateInfoQCOM,
    api_types::VkDataGraphPipelineCompilerControlCreateInfoARM,
    api_types::VkDataGraphPipelineConstantARM,
    api_types::VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM,
    api_types::VkDataGraphPipelineCreateInfoARM,
    api_types::VkDataGraphPipelineDispatchInfoARM,
    api_types::VkDataGraphPipelineIdentifierCreateInfoARM,
    api_types::VkDataGraphPipelineInfoARM,
    api_types::VkDataGraphPipelineNeuralStatisticsCreateInfoARM,
    api_types::VkDataGraphPipelineOpticalFlowCreateInfoARM,
    api_types::VkDataGraphPipelineOpticalFlowDispatchInfoARM,
    api_types::VkDataGraphPipelinePropertyQueryResultARM,
    api_types::VkDataGraphPipelineResourceInfoARM,
    api_types::VkDataGraphPipelineResourceInfoImageLayoutARM,
    api_types::VkDataGraphPipelineSessionBindPointRequirementARM,
    api_types::VkDataGraphPipelineSessionBindPointRequirementsInfoARM,
    api_types::VkDataGraphPipelineSessionCreateInfoARM,
    api_types::VkDataGraphPipelineSessionMemoryRequirementsInfoARM,
    api_types::VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM,
    api_types::VkDataGraphPipelineShaderModuleCreateInfoARM,
    api_types::VkDataGraphPipelineSingleNodeConnectionARM,
    api_types::VkDataGraphPipelineSingleNodeCreateInfoARM,
    api_types::VkDataGraphProcessingEngineCreateInfoARM,
    api_types::VkDebugMarkerMarkerInfoEXT,
    api_types::VkDebugMarkerObjectNameInfoEXT,
    api_types::VkDebugMarkerObjectTagInfoEXT,
    api_types::VkDebugReportCallbackCreateInfoEXT,
    api_types::VkDebugUtilsLabelEXT,
    api_types::VkDebugUtilsMessengerCallbackDataEXT,
    api_types::VkDebugUtilsMessengerCreateInfoEXT,
    api_types::VkDebugUtilsObjectNameInfoEXT,
    api_types::VkDebugUtilsObjectTagInfoEXT,
    api_types::VkDecompressMemoryInfoEXT,
    api_types::VkDecompressMemoryRegionEXT,
    api_types::VkDedicatedAllocationBufferCreateInfoNV,
    api_types::VkDedicatedAllocationImageCreateInfoNV,
    api_types::VkDedicatedAllocationMemoryAllocateInfoNV,
    api_types::VkDependencyInfo,
    api_types::VkDepthBiasInfoEXT,
    api_types::VkDepthBiasRepresentationInfoEXT,
    api_types::VkDepthClampRangeEXT,
    api_types::VkDescriptorAddressInfoEXT,
    api_types::VkDescriptorBufferBindingInfoEXT,
    api_types::VkDescriptorBufferBindingPushDescriptorBufferHandleEXT,
    api_types::VkDescriptorBufferInfo,
    api_types::VkDescriptorGetInfoEXT,
    api_types::VkDescriptorGetTensorInfoARM,
    api_types::VkDescriptorPoolCreateInfo,
    api_types::VkDescriptorPoolInlineUniformBlockCreateInfo,
    api_types::VkDescriptorPoolSize,
    api_types::VkDescriptorSetAllocateInfo,
    api_types::VkDescriptorSetBindingReferenceVALVE,
    api_types::VkDescriptorSetLayoutBinding,
    api_types::VkDescriptorSetLayoutBindingFlagsCreateInfo,
    api_types::VkDescriptorSetLayoutCreateInfo,
    api_types::VkDescriptorSetLayoutHostMappingInfoVALVE,
    api_types::VkDescriptorSetLayoutSupport,
    api_types::VkDescriptorSetVariableDescriptorCountAllocateInfo,
    api_types::VkDescriptorSetVariableDescriptorCountLayoutSupport,
    api_types::VkDescriptorUpdateTemplateCreateInfo,
    api_types::VkDescriptorUpdateTemplateEntry,
    api_types::VkDeviceAddressBindingCallbackDataEXT,
    api_types::VkDeviceAddressRangeKHR,
    api_types::VkDeviceBufferMemoryRequirements,
    api_types::VkDeviceCreateInfo,
    api_types::VkDeviceDeviceMemoryReportCreateInfoEXT,
    api_types::VkDeviceDiagnosticsConfigCreateInfoNV,
    api_types::VkDeviceEventInfoEXT,
    api_types::VkDeviceFaultAddressInfoKHR,
    api_types::VkDeviceFaultCountsEXT,
    api_types::VkDeviceFaultDebugInfoKHR,
    api_types::VkDeviceFaultInfoEXT,
    api_types::VkDeviceFaultInfoKHR,
    api_types::VkDeviceFaultShaderAbortMessageInfoKHR,
    api_types::VkDeviceFaultVendorBinaryHeaderVersionOneKHR,
    api_types::VkDeviceFaultVendorInfoKHR,
    api_types::VkDeviceGroupBindSparseInfo,
    api_types::VkDeviceGroupCommandBufferBeginInfo,
    api_types::VkDeviceGroupDeviceCreateInfo,
    api_types::VkDeviceGroupPresentCapabilitiesKHR,
    api_types::VkDeviceGroupPresentInfoKHR,
    api_types::VkDeviceGroupRenderPassBeginInfo,
    api_types::VkDeviceGroupSubmitInfo,
    api_types::VkDeviceGroupSwapchainCreateInfoKHR,
    api_types::VkDeviceImageMemoryRequirements,
    api_types::VkDeviceImageSubresourceInfo,
    api_types::VkDeviceMemoryCopyKHR,
    api_types::VkDeviceMemoryImageCopyKHR,
    api_types::VkDeviceMemoryOpaqueCaptureAddressInfo,
    api_types::VkDeviceMemoryOverallocationCreateInfoAMD,
    api_types::VkDeviceMemoryReportCallbackDataEXT,
    api_types::VkDeviceOrHostAddressConstKHR,
    api_types::VkDeviceOrHostAddressKHR,
    api_types::VkDevicePipelineBinaryInternalCacheControlKHR,
    api_types::VkDevicePrivateDataCreateInfo,
    api_types::VkDeviceQueueCreateInfo,
    api_types::VkDeviceQueueGlobalPriorityCreateInfo,
    api_types::VkDeviceQueueInfo2,
    api_types::VkDeviceQueueShaderCoreControlCreateInfoARM,
    api_types::VkDeviceTensorMemoryRequirementsARM,
    api_types::VkDirectDriverLoadingInfoLUNARG,
    api_types::VkDirectDriverLoadingListLUNARG,
    api_types::VkDirectFBSurfaceCreateInfoEXT,
    api_types::VkDispatchIndirect2InfoKHR,
    api_types::VkDispatchIndirectCommand,
    api_types::VkDispatchParametersARM,
    api_types::VkDispatchTileInfoQCOM,
    api_types::VkDisplayEventInfoEXT,
    api_types::VkDisplayModeCreateInfoKHR,
    api_types::VkDisplayModeParametersKHR,
    api_types::VkDisplayModeProperties2KHR,
    api_types::VkDisplayModePropertiesKHR,
    api_types::VkDisplayModeStereoPropertiesNV,
    api_types::VkDisplayNativeHdrSurfaceCapabilitiesAMD,
    api_types::VkDisplayPlaneCapabilities2KHR,
    api_types::VkDisplayPlaneCapabilitiesKHR,
    api_types::VkDisplayPlaneInfo2KHR,
    api_types::VkDisplayPlaneProperties2KHR,
    api_types::VkDisplayPlanePropertiesKHR,
    api_types::VkDisplayPowerInfoEXT,
    api_types::VkDisplayPresentInfoKHR,
    api_types::VkDisplayProperties2KHR,
    api_types::VkDisplayPropertiesKHR,
    api_types::VkDisplaySurfaceCreateInfoKHR,
    api_types::VkDisplaySurfaceStereoCreateInfoNV,
    api_types::VkDrawIndexedIndirectCommand,
    api_types::VkDrawIndirect2InfoKHR,
    api_types::VkDrawIndirectCommand,
    api_types::VkDrawIndirectCount2InfoKHR,
    api_types::VkDrawIndirectCountIndirectCommandEXT,
    api_types::VkDrawMeshTasksIndirectCommandEXT,
    api_types::VkDrawMeshTasksIndirectCommandNV,
    api_types::VkDrmFormatModifierProperties2EXT,
    api_types::VkDrmFormatModifierPropertiesEXT,
    api_types::VkDrmFormatModifierPropertiesList2EXT,
    api_types::VkDrmFormatModifierPropertiesListEXT,
    api_types::VkEventCreateInfo,
    api_types::VkExportFenceCreateInfo,
    api_types::VkExportFenceWin32HandleInfoKHR,
    api_types::VkExportMemoryAllocateInfo,
    api_types::VkExportMemoryAllocateInfoNV,
    api_types::VkExportMemoryWin32HandleInfoKHR,
    api_types::VkExportMemoryWin32HandleInfoNV,
    api_types::VkExportSemaphoreCreateInfo,
    api_types::VkExportSemaphoreWin32HandleInfoKHR,
    api_types::VkExtensionProperties,
    api_types::VkExtent2D,
    api_types::VkExtent3D,
    api_types::VkExternalBufferProperties,
    api_types::VkExternalFenceProperties,
    api_types::VkExternalFormatANDROID,
    api_types::VkExternalImageFormatProperties,
    api_types::VkExternalImageFormatPropertiesNV,
    api_types::VkExternalMemoryAcquireUnmodifiedEXT,
    api_types::VkExternalMemoryBufferCreateInfo,
    api_types::VkExternalMemoryImageCreateInfo,
    api_types::VkExternalMemoryImageCreateInfoNV,
    api_types::VkExternalMemoryProperties,
    api_types::VkExternalMemoryTensorCreateInfoARM,
    api_types::VkExternalSemaphoreProperties,
    api_types::VkExternalTensorPropertiesARM,
    api_types::VkFenceCreateInfo,
    api_types::VkFenceGetFdInfoKHR,
    api_types::VkFenceGetWin32HandleInfoKHR,
    api_types::VkFilterCubicImageViewImageFormatPropertiesEXT,
    api_types::VkFormatProperties,
    api_types::VkFormatProperties2,
    api_types::VkFormatProperties3,
    api_types::VkFormatProperties4KHR,
    api_types::VkFragmentShadingRateAttachmentInfoKHR,
    api_types::VkFrameBoundaryEXT,
    api_types::VkFrameBoundaryTensorsARM,
    api_types::VkFramebufferAttachmentImageInfo,
    api_types::VkFramebufferAttachmentsCreateInfo,
    api_types::VkFramebufferCreateInfo,
    api_types::VkFramebufferMixedSamplesCombinationNV,
    api_types::VkGeneratedCommandsInfoEXT,
    api_types::VkGeneratedCommandsInfoNV,
    api_types::VkGeneratedCommandsMemoryRequirementsInfoEXT,
    api_types::VkGeneratedCommandsMemoryRequirementsInfoNV,
    api_types::VkGeneratedCommandsPipelineInfoEXT,
    api_types::VkGeneratedCommandsShaderInfoEXT,
    api_types::VkGeometryAABBNV,
    api_types::VkGeometryDataNV,
    api_types::VkGeometryNV,
    api_types::VkGeometryTrianglesNV,
    api_types::VkGetLatencyMarkerInfoNV,
    api_types::VkGpaDeviceClockModeInfoAMD,
    api_types::VkGpaDeviceGetClockInfoAMD,
    api_types::VkGpaPerfBlockPropertiesAMD,
    api_types::VkGpaPerfCounterAMD,
    api_types::VkGpaSampleBeginInfoAMD,
    api_types::VkGpaSessionCreateInfoAMD,
    api_types::VkGraphicsPipelineCreateInfo,
    api_types::VkGraphicsPipelineLibraryCreateInfoEXT,
    api_types::VkGraphicsPipelineShaderGroupsCreateInfoNV,
    api_types::VkGraphicsShaderGroupCreateInfoNV,
    api_types::VkHdrMetadataEXT,
    api_types::VkHdrVividDynamicMetadataHUAWEI,
    api_types::VkHeadlessSurfaceCreateInfoEXT,
    api_types::VkHostImageCopyDevicePerformanceQuery,
    api_types::VkHostImageLayoutTransitionInfo,
    api_types::VkIOSSurfaceCreateInfoMVK,
    api_types::VkImageAlignmentControlCreateInfoMESA,
    api_types::VkImageBlit,
    api_types::VkImageBlit2,
    api_types::VkImageCaptureDescriptorDataInfoEXT,
    api_types::VkImageCompressionControlEXT,
    api_types::VkImageCompressionPropertiesEXT,
    api_types::VkImageCopy,
    api_types::VkImageCopy2,
    api_types::VkImageCreateFlags2CreateInfoKHR,
    api_types::VkImageCreateInfo,
    api_types::VkImageDrmFormatModifierExplicitCreateInfoEXT,
    api_types::VkImageDrmFormatModifierListCreateInfoEXT,
    api_types::VkImageDrmFormatModifierPropertiesEXT,
    api_types::VkImageFormatListCreateInfo,
    api_types::VkImageFormatProperties,
    api_types::VkImageFormatProperties2,
    api_types::VkImageMemoryBarrier,
    api_types::VkImageMemoryBarrier2,
    api_types::VkImageMemoryRequirementsInfo2,
    api_types::VkImagePipeSurfaceCreateInfoFUCHSIA,
    api_types::VkImagePlaneMemoryRequirementsInfo,
    api_types::VkImageResolve,
    api_types::VkImageResolve2,
    api_types::VkImageSparseMemoryRequirementsInfo2,
    api_types::VkImageStencilUsage2CreateInfoKHR,
    api_types::VkImageStencilUsageCreateInfo,
    api_types::VkImageSubresource,
    api_types::VkImageSubresource2,
    api_types::VkImageSubresourceLayers,
    api_types::VkImageSubresourceRange,
    api_types::VkImageSwapchainCreateInfoKHR,
    api_types::VkImageTilingControlCreateInfoEXT,
    api_types::VkImageToMemoryCopy,
    api_types::VkImageUsageFlags2CreateInfoKHR,
    api_types::VkImageViewASTCDecodeModeEXT,
    api_types::VkImageViewAddressPropertiesNVX,
    api_types::VkImageViewCaptureDescriptorDataInfoEXT,
    api_types::VkImageViewCreateInfo,
    api_types::VkImageViewHandleInfoNVX,
    api_types::VkImageViewMinLodCreateInfoEXT,
    api_types::VkImageViewSampleWeightCreateInfoQCOM,
    api_types::VkImageViewSlicedCreateInfoEXT,
    api_types::VkImageViewUsage2CreateInfoKHR,
    api_types::VkImageViewUsageCreateInfo,
    api_types::VkImportAndroidHardwareBufferInfoANDROID,
    api_types::VkImportFenceFdInfoKHR,
    api_types::VkImportFenceWin32HandleInfoKHR,
    api_types::VkImportMemoryFdInfoKHR,
    api_types::VkImportMemoryHostPointerInfoEXT,
    api_types::VkImportMemoryMetalHandleInfoEXT,
    api_types::VkImportMemoryWin32HandleInfoKHR,
    api_types::VkImportMemoryWin32HandleInfoNV,
    api_types::VkImportMemoryZirconHandleInfoFUCHSIA,
    api_types::VkImportSemaphoreFdInfoKHR,
    api_types::VkImportSemaphoreWin32HandleInfoKHR,
    api_types::VkImportSemaphoreZirconHandleInfoFUCHSIA,
    api_types::VkIndirectCommandsExecutionSetTokenEXT,
    api_types::VkIndirectCommandsIndexBufferTokenEXT,
    api_types::VkIndirectCommandsLayoutCreateInfoEXT,
    api_types::VkIndirectCommandsLayoutCreateInfoNV,
    api_types::VkIndirectCommandsLayoutTokenEXT,
    api_types::VkIndirectCommandsLayoutTokenNV,
    api_types::VkIndirectCommandsPushConstantTokenEXT,
    api_types::VkIndirectCommandsStreamNV,
    api_types::VkIndirectCommandsVertexBufferTokenEXT,
    api_types::VkIndirectExecutionSetCreateInfoEXT,
    api_types::VkIndirectExecutionSetPipelineInfoEXT,
    api_types::VkIndirectExecutionSetShaderInfoEXT,
    api_types::VkIndirectExecutionSetShaderLayoutInfoEXT,
    api_types::VkInitializePerformanceApiInfoINTEL,
    api_types::VkInputAttachmentAspectReference,
    api_types::VkInstanceCreateInfo,
    api_types::VkLatencySleepInfoNV,
    api_types::VkLatencySleepModeInfoNV,
    api_types::VkLatencySubmissionPresentIdNV,
    api_types::VkLatencySurfaceCapabilitiesNV,
    api_types::VkLatencyTimingsFrameReportNV,
    api_types::VkLayerProperties,
    api_types::VkLayerSettingEXT,
    api_types::VkLayerSettingsCreateInfoEXT,
    api_types::VkMacOSSurfaceCreateInfoMVK,
    api_types::VkMappedMemoryRange,
    api_types::VkMemoryAllocateFlagsInfo,
    api_types::VkMemoryAllocateInfo,
    api_types::VkMemoryBarrier,
    api_types::VkMemoryBarrier2,
    api_types::VkMemoryBarrierAccessFlags3KHR,
    api_types::VkMemoryDedicatedAllocateInfo,
    api_types::VkMemoryDedicatedAllocateInfoTensorARM,
    api_types::VkMemoryDedicatedRequirements,
    api_types::VkMemoryFdPropertiesKHR,
    api_types::VkMemoryGetAndroidHardwareBufferInfoANDROID,
    api_types::VkMemoryGetFdInfoKHR,
    api_types::VkMemoryGetMetalHandleInfoEXT,
    api_types::VkMemoryGetRemoteAddressInfoNV,
    api_types::VkMemoryGetWin32HandleInfoKHR,
    api_types::VkMemoryGetZirconHandleInfoFUCHSIA,
    api_types::VkMemoryHeap,
    api_types::VkMemoryHostPointerPropertiesEXT,
    api_types::VkMemoryMapInfo,
    api_types::VkMemoryMapPlacedInfoEXT,
    api_types::VkMemoryMarkerInfoAMD,
    api_types::VkMemoryMetalHandlePropertiesEXT,
    api_types::VkMemoryOpaqueCaptureAddressAllocateInfo,
    api_types::VkMemoryPriorityAllocateInfoEXT,
    api_types::VkMemoryRangeBarrierKHR,
    api_types::VkMemoryRangeBarriersInfoKHR,
    api_types::VkMemoryRequirements,
    api_types::VkMemoryRequirements2,
    api_types::VkMemoryToImageCopy,
    api_types::VkMemoryType,
    api_types::VkMemoryUnmapInfo,
    api_types::VkMemoryWin32HandlePropertiesKHR,
    api_types::VkMemoryZirconHandlePropertiesFUCHSIA,
    api_types::VkMetalSurfaceCreateInfoEXT,
    api_types::VkMicromapBuildInfoEXT,
    api_types::VkMicromapBuildSizesInfoEXT,
    api_types::VkMicromapCreateInfoEXT,
    api_types::VkMicromapTriangleKHR,
    api_types::VkMicromapUsageEXT,
    api_types::VkMicromapUsageKHR,
    api_types::VkMicromapVersionInfoEXT,
    api_types::VkMultiDrawIndexedInfoEXT,
    api_types::VkMultiDrawInfoEXT,
    api_types::VkMultisamplePropertiesEXT,
    api_types::VkMultisampledRenderToSingleSampledInfoEXT,
    api_types::VkMultiviewPerViewAttributesInfoNVX,
    api_types::VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM,
    api_types::VkMutableDescriptorTypeCreateInfoEXT,
    api_types::VkMutableDescriptorTypeListEXT,
    api_types::VkOffset2D,
    api_types::VkOffset3D,
    api_types::VkOpaqueCaptureDescriptorDataCreateInfoEXT,
    api_types::VkOpticalFlowExecuteInfoNV,
    api_types::VkOpticalFlowImageFormatInfoNV,
    api_types::VkOpticalFlowImageFormatPropertiesNV,
    api_types::VkOpticalFlowSessionCreateInfoNV,
    api_types::VkOpticalFlowSessionCreatePrivateDataInfoNV,
    api_types::VkOutOfBandQueueTypeInfoNV,
    api_types::VkPartitionedAccelerationStructureFlagsNV,
    api_types::VkPartitionedAccelerationStructureInstancesInputNV,
    api_types::VkPartitionedAccelerationStructureUpdateInstanceDataNV,
    api_types::VkPartitionedAccelerationStructureWriteInstanceDataNV,
    api_types::VkPartitionedAccelerationStructureWritePartitionTranslationDataNV,
    api_types::VkPastPresentationTimingEXT,
    api_types::VkPastPresentationTimingGOOGLE,
    api_types::VkPastPresentationTimingInfoEXT,
    api_types::VkPastPresentationTimingPropertiesEXT,
    api_types::VkPerTileBeginInfoQCOM,
    api_types::VkPerTileEndInfoQCOM,
    api_types::VkPerfHintInfoQCOM,
    api_types::VkPerformanceConfigurationAcquireInfoINTEL,
    api_types::VkPerformanceCounterARM,
    api_types::VkPerformanceCounterDescriptionARM,
    api_types::VkPerformanceCounterDescriptionKHR,
    api_types::VkPerformanceCounterKHR,
    api_types::VkPerformanceMarkerInfoINTEL,
    api_types::VkPerformanceOverrideInfoINTEL,
    api_types::VkPerformanceQuerySubmitInfoKHR,
    api_types::VkPerformanceStreamMarkerInfoINTEL,
    api_types::VkPerformanceValueINTEL,
    api_types::VkPhysicalDevice16BitStorageFeatures,
    api_types::VkPhysicalDevice4444FormatsFeaturesEXT,
    api_types::VkPhysicalDevice8BitStorageFeatures,
    api_types::VkPhysicalDeviceASTCDecodeFeaturesEXT,
    api_types::VkPhysicalDeviceAccelerationStructureFeaturesKHR,
    api_types::VkPhysicalDeviceAccelerationStructurePropertiesKHR,
    api_types::VkPhysicalDeviceAddressBindingReportFeaturesEXT,
    api_types::VkPhysicalDeviceAmigoProfilingFeaturesSEC,
    api_types::VkPhysicalDeviceAntiLagFeaturesAMD,
    api_types::VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT,
    api_types::VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT,
    api_types::VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT,
    api_types::VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT,
    api_types::VkPhysicalDeviceBorderColorSwizzleFeaturesEXT,
    api_types::VkPhysicalDeviceBufferDeviceAddressAllocationAlignmentFeaturesVALVE,
    api_types::VkPhysicalDeviceBufferDeviceAddressAllocationAlignmentPropertiesVALVE,
    api_types::VkPhysicalDeviceBufferDeviceAddressFeatures,
    api_types::VkPhysicalDeviceBufferDeviceAddressFeaturesEXT,
    api_types::VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI,
    api_types::VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI,
    api_types::VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI,
    api_types::VkPhysicalDeviceCoherentMemoryFeaturesAMD,
    api_types::VkPhysicalDeviceColorWriteEnableFeaturesEXT,
    api_types::VkPhysicalDeviceCommandBufferInheritanceFeaturesNV,
    api_types::VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV,
    api_types::VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR,
    api_types::VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR,
    api_types::VkPhysicalDeviceConditionalRenderingFeaturesEXT,
    api_types::VkPhysicalDeviceConservativeRasterizationPropertiesEXT,
    api_types::VkPhysicalDeviceCooperativeMatrix2FeaturesNV,
    api_types::VkPhysicalDeviceCooperativeMatrix2PropertiesNV,
    api_types::VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM,
    api_types::VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV,
    api_types::VkPhysicalDeviceCooperativeMatrixFeaturesKHR,
    api_types::VkPhysicalDeviceCooperativeMatrixFeaturesNV,
    api_types::VkPhysicalDeviceCooperativeMatrixInfo2EXT,
    api_types::VkPhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT,
    api_types::VkPhysicalDeviceCooperativeMatrixPropertiesKHR,
    api_types::VkPhysicalDeviceCooperativeMatrixPropertiesNV,
    api_types::VkPhysicalDeviceCooperativeVectorFeaturesNV,
    api_types::VkPhysicalDeviceCooperativeVectorPropertiesNV,
    api_types::VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR,
    api_types::VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR,
    api_types::VkPhysicalDeviceCornerSampledImageFeaturesNV,
    api_types::VkPhysicalDeviceCoverageReductionModeFeaturesNV,
    api_types::VkPhysicalDeviceCubicClampFeaturesQCOM,
    api_types::VkPhysicalDeviceCubicWeightsFeaturesQCOM,
    api_types::VkPhysicalDeviceCustomBorderColorFeaturesEXT,
    api_types::VkPhysicalDeviceCustomBorderColorPropertiesEXT,
    api_types::VkPhysicalDeviceCustomResolveFeaturesEXT,
    api_types::VkPhysicalDeviceDataGraphFeaturesARM,
    api_types::VkPhysicalDeviceDataGraphModelFeaturesQCOM,
    api_types::VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM,
    api_types::VkPhysicalDeviceDataGraphOperationSupportARM,
    api_types::VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM,
    api_types::VkPhysicalDeviceDataGraphProcessingEngineARM,
    api_types::VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV,
    api_types::VkPhysicalDeviceDepthBiasControlFeaturesEXT,
    api_types::VkPhysicalDeviceDepthClampControlFeaturesEXT,
    api_types::VkPhysicalDeviceDepthClampZeroOneFeaturesKHR,
    api_types::VkPhysicalDeviceDepthClipControlFeaturesEXT,
    api_types::VkPhysicalDeviceDepthClipEnableFeaturesEXT,
    api_types::VkPhysicalDeviceDepthStencilResolveProperties,
    api_types::VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT,
    api_types::VkPhysicalDeviceDescriptorBufferFeaturesEXT,
    api_types::VkPhysicalDeviceDescriptorBufferPropertiesEXT,
    api_types::VkPhysicalDeviceDescriptorBufferTensorFeaturesARM,
    api_types::VkPhysicalDeviceDescriptorBufferTensorPropertiesARM,
    api_types::VkPhysicalDeviceDescriptorIndexingFeatures,
    api_types::VkPhysicalDeviceDescriptorIndexingProperties,
    api_types::VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV,
    api_types::VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE,
    api_types::VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR,
    api_types::VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV,
    api_types::VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT,
    api_types::VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV,
    api_types::VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT,
    api_types::VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV,
    api_types::VkPhysicalDeviceDeviceMemoryReportFeaturesEXT,
    api_types::VkPhysicalDeviceDiagnosticsConfigFeaturesNV,
    api_types::VkPhysicalDeviceDiscardRectanglePropertiesEXT,
    api_types::VkPhysicalDeviceDisplacementMicromapFeaturesNV,
    api_types::VkPhysicalDeviceDisplacementMicromapPropertiesNV,
    api_types::VkPhysicalDeviceDriverProperties,
    api_types::VkPhysicalDeviceDrmPropertiesEXT,
    api_types::VkPhysicalDeviceDynamicRenderingFeatures,
    api_types::VkPhysicalDeviceDynamicRenderingLocalReadFeatures,
    api_types::VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT,
    api_types::VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM,
    api_types::VkPhysicalDeviceExclusiveScissorFeaturesNV,
    api_types::VkPhysicalDeviceExtendedDynamicState2FeaturesEXT,
    api_types::VkPhysicalDeviceExtendedDynamicState3FeaturesEXT,
    api_types::VkPhysicalDeviceExtendedDynamicState3PropertiesEXT,
    api_types::VkPhysicalDeviceExtendedDynamicStateFeaturesEXT,
    api_types::VkPhysicalDeviceExtendedFlagsFeaturesKHR,
    api_types::VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV,
    api_types::VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV,
    api_types::VkPhysicalDeviceExternalBufferInfo,
    api_types::VkPhysicalDeviceExternalFenceInfo,
    api_types::VkPhysicalDeviceExternalFormatResolveFeaturesANDROID,
    api_types::VkPhysicalDeviceExternalFormatResolvePropertiesANDROID,
    api_types::VkPhysicalDeviceExternalImageFormatInfo,
    api_types::VkPhysicalDeviceExternalMemoryHostPropertiesEXT,
    api_types::VkPhysicalDeviceExternalMemoryRDMAFeaturesNV,
    api_types::VkPhysicalDeviceExternalSemaphoreInfo,
    api_types::VkPhysicalDeviceExternalTensorInfoARM,
    api_types::VkPhysicalDeviceFaultFeaturesEXT,
    api_types::VkPhysicalDeviceFaultFeaturesKHR,
    api_types::VkPhysicalDeviceFaultPropertiesKHR,
    api_types::VkPhysicalDeviceFeatures,
    api_types::VkPhysicalDeviceFeatures2,
    api_types::VkPhysicalDeviceFloatControlsProperties,
    api_types::VkPhysicalDeviceFormatPackFeaturesARM,
    api_types::VkPhysicalDeviceFragmentDensityMap2FeaturesEXT,
    api_types::VkPhysicalDeviceFragmentDensityMap2PropertiesEXT,
    api_types::VkPhysicalDeviceFragmentDensityMapFeaturesEXT,
    api_types::VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE,
    api_types::VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE,
    api_types::VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT,
    api_types::VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT,
    api_types::VkPhysicalDeviceFragmentDensityMapPropertiesEXT,
    api_types::VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR,
    api_types::VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR,
    api_types::VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT,
    api_types::VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV,
    api_types::VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV,
    api_types::VkPhysicalDeviceFragmentShadingRateFeaturesKHR,
    api_types::VkPhysicalDeviceFragmentShadingRateKHR,
    api_types::VkPhysicalDeviceFragmentShadingRatePropertiesKHR,
    api_types::VkPhysicalDeviceFrameBoundaryFeaturesEXT,
    api_types::VkPhysicalDeviceGlobalPriorityQueryFeatures,
    api_types::VkPhysicalDeviceGpaFeaturesAMD,
    api_types::VkPhysicalDeviceGpaProperties2AMD,
    api_types::VkPhysicalDeviceGpaPropertiesAMD,
    api_types::VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT,
    api_types::VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT,
    api_types::VkPhysicalDeviceGroupProperties,
    api_types::VkPhysicalDeviceHdrVividFeaturesHUAWEI,
    api_types::VkPhysicalDeviceHostImageCopyFeatures,
    api_types::VkPhysicalDeviceHostImageCopyProperties,
    api_types::VkPhysicalDeviceHostQueryResetFeatures,
    api_types::VkPhysicalDeviceIDProperties,
    api_types::VkPhysicalDeviceImage2DViewOf3DFeaturesEXT,
    api_types::VkPhysicalDeviceImageAlignmentControlFeaturesMESA,
    api_types::VkPhysicalDeviceImageAlignmentControlPropertiesMESA,
    api_types::VkPhysicalDeviceImageCompressionControlFeaturesEXT,
    api_types::VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT,
    api_types::VkPhysicalDeviceImageDrmFormatModifierInfoEXT,
    api_types::VkPhysicalDeviceImageFormatInfo2,
    api_types::VkPhysicalDeviceImageProcessing2FeaturesQCOM,
    api_types::VkPhysicalDeviceImageProcessing2PropertiesQCOM,
    api_types::VkPhysicalDeviceImageProcessing3FeaturesQCOM,
    api_types::VkPhysicalDeviceImageProcessingFeaturesQCOM,
    api_types::VkPhysicalDeviceImageProcessingPropertiesQCOM,
    api_types::VkPhysicalDeviceImageRobustnessFeatures,
    api_types::VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT,
    api_types::VkPhysicalDeviceImageTilingControlFeaturesEXT,
    api_types::VkPhysicalDeviceImageViewImageFormatInfoEXT,
    api_types::VkPhysicalDeviceImageViewMinLodFeaturesEXT,
    api_types::VkPhysicalDeviceImagelessFramebufferFeatures,
    api_types::VkPhysicalDeviceIndexTypeUint8Features,
    api_types::VkPhysicalDeviceInfoPropertiesINTEL,
    api_types::VkPhysicalDeviceInheritedViewportScissorFeaturesNV,
    api_types::VkPhysicalDeviceInlineUniformBlockFeatures,
    api_types::VkPhysicalDeviceInlineUniformBlockProperties,
    api_types::VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR,
    api_types::VkPhysicalDeviceInvocationMaskFeaturesHUAWEI,
    api_types::VkPhysicalDeviceLayeredApiPropertiesKHR,
    api_types::VkPhysicalDeviceLayeredApiPropertiesListKHR,
    api_types::VkPhysicalDeviceLayeredApiVulkanPropertiesKHR,
    api_types::VkPhysicalDeviceLayeredDriverPropertiesMSFT,
    api_types::VkPhysicalDeviceLegacyDitheringFeaturesEXT,
    api_types::VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT,
    api_types::VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT,
    api_types::VkPhysicalDeviceLimits,
    api_types::VkPhysicalDeviceLineRasterizationFeatures,
    api_types::VkPhysicalDeviceLineRasterizationProperties,
    api_types::VkPhysicalDeviceLinearColorAttachmentFeaturesNV,
    api_types::VkPhysicalDeviceMaintenance10FeaturesKHR,
    api_types::VkPhysicalDeviceMaintenance10PropertiesKHR,
    api_types::VkPhysicalDeviceMaintenance11FeaturesKHR,
    api_types::VkPhysicalDeviceMaintenance3Properties,
    api_types::VkPhysicalDeviceMaintenance4Features,
    api_types::VkPhysicalDeviceMaintenance4Properties,
    api_types::VkPhysicalDeviceMaintenance5Features,
    api_types::VkPhysicalDeviceMaintenance5Properties,
    api_types::VkPhysicalDeviceMaintenance6Features,
    api_types::VkPhysicalDeviceMaintenance6Properties,
    api_types::VkPhysicalDeviceMaintenance7FeaturesKHR,
    api_types::VkPhysicalDeviceMaintenance7PropertiesKHR,
    api_types::VkPhysicalDeviceMaintenance8FeaturesKHR,
    api_types::VkPhysicalDeviceMaintenance9FeaturesKHR,
    api_types::VkPhysicalDeviceMaintenance9PropertiesKHR,
    api_types::VkPhysicalDeviceMapMemoryPlacedFeaturesEXT,
    api_types::VkPhysicalDeviceMapMemoryPlacedPropertiesEXT,
    api_types::VkPhysicalDeviceMemoryBudgetPropertiesEXT,
    api_types::VkPhysicalDeviceMemoryDecompressionFeaturesEXT,
    api_types::VkPhysicalDeviceMemoryDecompressionPropertiesEXT,
    api_types::VkPhysicalDeviceMemoryPriorityFeaturesEXT,
    api_types::VkPhysicalDeviceMemoryProperties,
    api_types::VkPhysicalDeviceMemoryProperties2,
    api_types::VkPhysicalDeviceMeshShaderFeaturesEXT,
    api_types::VkPhysicalDeviceMeshShaderFeaturesNV,
    api_types::VkPhysicalDeviceMeshShaderPropertiesEXT,
    api_types::VkPhysicalDeviceMeshShaderPropertiesNV,
    api_types::VkPhysicalDeviceMultiDrawFeaturesEXT,
    api_types::VkPhysicalDeviceMultiDrawPropertiesEXT,
    api_types::VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT,
    api_types::VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT,
    api_types::VkPhysicalDeviceMultiviewFeatures,
    api_types::VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX,
    api_types::VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM,
    api_types::VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM,
    api_types::VkPhysicalDeviceMultiviewProperties,
    api_types::VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT,
    api_types::VkPhysicalDeviceNestedCommandBufferFeaturesEXT,
    api_types::VkPhysicalDeviceNestedCommandBufferPropertiesEXT,
    api_types::VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT,
    api_types::VkPhysicalDeviceOpacityMicromapFeaturesEXT,
    api_types::VkPhysicalDeviceOpacityMicromapFeaturesKHR,
    api_types::VkPhysicalDeviceOpacityMicromapPropertiesEXT,
    api_types::VkPhysicalDeviceOpacityMicromapPropertiesKHR,
    api_types::VkPhysicalDeviceOpticalFlowFeaturesNV,
    api_types::VkPhysicalDeviceOpticalFlowPropertiesNV,
    api_types::VkPhysicalDevicePCIBusInfoPropertiesEXT,
    api_types::VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT,
    api_types::VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV,
    api_types::VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV,
    api_types::VkPhysicalDevicePerStageDescriptorSetFeaturesNV,
    api_types::VkPhysicalDevicePerformanceCountersByRegionFeaturesARM,
    api_types::VkPhysicalDevicePerformanceCountersByRegionPropertiesARM,
    api_types::VkPhysicalDevicePerformanceQueryFeaturesKHR,
    api_types::VkPhysicalDevicePerformanceQueryPropertiesKHR,
    api_types::VkPhysicalDevicePipelineBinaryFeaturesKHR,
    api_types::VkPhysicalDevicePipelineBinaryPropertiesKHR,
    api_types::VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC,
    api_types::VkPhysicalDevicePipelineCreationCacheControlFeatures,
    api_types::VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR,
    api_types::VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesKHR,
    api_types::VkPhysicalDevicePipelineOpacityMicromapFeaturesARM,
    api_types::VkPhysicalDevicePipelineProtectedAccessFeatures,
    api_types::VkPhysicalDevicePipelineRobustnessFeatures,
    api_types::VkPhysicalDevicePipelineRobustnessProperties,
    api_types::VkPhysicalDevicePointClippingProperties,
    api_types::VkPhysicalDevicePortabilitySubsetFeaturesKHR,
    api_types::VkPhysicalDevicePortabilitySubsetPropertiesKHR,
    api_types::VkPhysicalDevicePresentBarrierFeaturesNV,
    api_types::VkPhysicalDevicePresentId2FeaturesKHR,
    api_types::VkPhysicalDevicePresentIdFeaturesKHR,
    api_types::VkPhysicalDevicePresentMeteringFeaturesNV,
    api_types::VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR,
    api_types::VkPhysicalDevicePresentTimingFeaturesEXT,
    api_types::VkPhysicalDevicePresentWait2FeaturesKHR,
    api_types::VkPhysicalDevicePresentWaitFeaturesKHR,
    api_types::VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT,
    api_types::VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT,
    api_types::VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT,
    api_types::VkPhysicalDevicePrivateDataBaseHandleFeaturesNV,
    api_types::VkPhysicalDevicePrivateDataFeatures,
    api_types::VkPhysicalDeviceProperties,
    api_types::VkPhysicalDeviceProperties2,
    api_types::VkPhysicalDeviceProtectedMemoryFeatures,
    api_types::VkPhysicalDeviceProtectedMemoryProperties,
    api_types::VkPhysicalDeviceProvokingVertexFeaturesEXT,
    api_types::VkPhysicalDeviceProvokingVertexPropertiesEXT,
    api_types::VkPhysicalDevicePushConstantBankFeaturesNV,
    api_types::VkPhysicalDevicePushConstantBankPropertiesNV,
    api_types::VkPhysicalDevicePushDescriptorProperties,
    api_types::VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM,
    api_types::VkPhysicalDeviceQueuePerfHintFeaturesQCOM,
    api_types::VkPhysicalDeviceQueuePerfHintPropertiesQCOM,
    api_types::VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT,
    api_types::VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT,
    api_types::VkPhysicalDeviceRawAccessChainsFeaturesNV,
    api_types::VkPhysicalDeviceRayQueryFeaturesKHR,
    api_types::VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT,
    api_types::VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV,
    api_types::VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT,
    api_types::VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV,
    api_types::VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV,
    api_types::VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR,
    api_types::VkPhysicalDeviceRayTracingMotionBlurFeaturesNV,
    api_types::VkPhysicalDeviceRayTracingPipelineFeaturesKHR,
    api_types::VkPhysicalDeviceRayTracingPipelinePropertiesKHR,
    api_types::VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR,
    api_types::VkPhysicalDeviceRayTracingPropertiesNV,
    api_types::VkPhysicalDeviceRayTracingValidationFeaturesNV,
    api_types::VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG,
    api_types::VkPhysicalDeviceRenderPassStripedFeaturesARM,
    api_types::VkPhysicalDeviceRenderPassStripedPropertiesARM,
    api_types::VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV,
    api_types::VkPhysicalDeviceRobustness2FeaturesKHR,
    api_types::VkPhysicalDeviceRobustness2PropertiesKHR,
    api_types::VkPhysicalDeviceSampleLocationsPropertiesEXT,
    api_types::VkPhysicalDeviceSamplerFilterMinmaxProperties,
    api_types::VkPhysicalDeviceSamplerYcbcrConversionFeatures,
    api_types::VkPhysicalDeviceScalarBlockLayoutFeatures,
    api_types::VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM,
    api_types::VkPhysicalDeviceSchedulingControlsFeaturesARM,
    api_types::VkPhysicalDeviceSchedulingControlsPropertiesARM,
    api_types::VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures,
    api_types::VkPhysicalDeviceShader64BitIndexingFeaturesEXT,
    api_types::VkPhysicalDeviceShaderAbortFeaturesKHR,
    api_types::VkPhysicalDeviceShaderAbortPropertiesKHR,
    api_types::VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV,
    api_types::VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT,
    api_types::VkPhysicalDeviceShaderAtomicFloatFeaturesEXT,
    api_types::VkPhysicalDeviceShaderAtomicInt64Features,
    api_types::VkPhysicalDeviceShaderBfloat16FeaturesKHR,
    api_types::VkPhysicalDeviceShaderClockFeaturesKHR,
    api_types::VkPhysicalDeviceShaderConstantDataFeaturesKHR,
    api_types::VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM,
    api_types::VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM,
    api_types::VkPhysicalDeviceShaderCoreProperties2AMD,
    api_types::VkPhysicalDeviceShaderCorePropertiesAMD,
    api_types::VkPhysicalDeviceShaderCorePropertiesARM,
    api_types::VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures,
    api_types::VkPhysicalDeviceShaderDrawParametersFeatures,
    api_types::VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD,
    api_types::VkPhysicalDeviceShaderExpectAssumeFeatures,
    api_types::VkPhysicalDeviceShaderFloat16Int8Features,
    api_types::VkPhysicalDeviceShaderFloat8FeaturesEXT,
    api_types::VkPhysicalDeviceShaderFloatControls2Features,
    api_types::VkPhysicalDeviceShaderFmaFeaturesKHR,
    api_types::VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT,
    api_types::VkPhysicalDeviceShaderImageFootprintFeaturesNV,
    api_types::VkPhysicalDeviceShaderIntegerDotProductFeatures,
    api_types::VkPhysicalDeviceShaderIntegerDotProductProperties,
    api_types::VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL,
    api_types::VkPhysicalDeviceShaderLongVectorFeaturesEXT,
    api_types::VkPhysicalDeviceShaderLongVectorPropertiesEXT,
    api_types::VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR,
    api_types::VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE,
    api_types::VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT,
    api_types::VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT,
    api_types::VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM,
    api_types::VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM,
    api_types::VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT,
    api_types::VkPhysicalDeviceShaderObjectFeaturesEXT,
    api_types::VkPhysicalDeviceShaderObjectPropertiesEXT,
    api_types::VkPhysicalDeviceShaderQuadControlFeaturesKHR,
    api_types::VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR,
    api_types::VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT,
    api_types::VkPhysicalDeviceShaderSMBuiltinsFeaturesNV,
    api_types::VkPhysicalDeviceShaderSMBuiltinsPropertiesNV,
    api_types::VkPhysicalDeviceShaderSplitBarrierFeaturesEXT,
    api_types::VkPhysicalDeviceShaderSplitBarrierPropertiesEXT,
    api_types::VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures,
    api_types::VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT,
    api_types::VkPhysicalDeviceShaderSubgroupRotateFeatures,
    api_types::VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR,
    api_types::VkPhysicalDeviceShaderTerminateInvocationFeatures,
    api_types::VkPhysicalDeviceShaderTileImageFeaturesEXT,
    api_types::VkPhysicalDeviceShaderTileImagePropertiesEXT,
    api_types::VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT,
    api_types::VkPhysicalDeviceShaderUntypedPointersFeaturesKHR,
    api_types::VkPhysicalDeviceShadingRateImageFeaturesNV,
    api_types::VkPhysicalDeviceShadingRateImagePropertiesNV,
    api_types::VkPhysicalDeviceSparseImageFormatInfo2,
    api_types::VkPhysicalDeviceSparseProperties,
    api_types::VkPhysicalDeviceSubgroupProperties,
    api_types::VkPhysicalDeviceSubgroupSizeControlFeatures,
    api_types::VkPhysicalDeviceSubgroupSizeControlProperties,
    api_types::VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT,
    api_types::VkPhysicalDeviceSurfaceInfo2KHR,
    api_types::VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR,
    api_types::VkPhysicalDeviceSynchronization2Features,
    api_types::VkPhysicalDeviceTensorFeaturesARM,
    api_types::VkPhysicalDeviceTensorPropertiesARM,
    api_types::VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT,
    api_types::VkPhysicalDeviceTexelBufferAlignmentProperties,
    api_types::VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT,
    api_types::VkPhysicalDeviceTextureCompressionASTCHDRFeatures,
    api_types::VkPhysicalDeviceThrottleHintFeaturesSEC,
    api_types::VkPhysicalDeviceTileMemoryHeapFeaturesQCOM,
    api_types::VkPhysicalDeviceTileMemoryHeapPropertiesQCOM,
    api_types::VkPhysicalDeviceTilePropertiesFeaturesQCOM,
    api_types::VkPhysicalDeviceTileShadingFeaturesQCOM,
    api_types::VkPhysicalDeviceTileShadingPropertiesQCOM,
    api_types::VkPhysicalDeviceTimelineSemaphoreFeatures,
    api_types::VkPhysicalDeviceTimelineSemaphoreProperties,
    api_types::VkPhysicalDeviceToolProperties,
    api_types::VkPhysicalDeviceTransformFeedbackFeaturesEXT,
    api_types::VkPhysicalDeviceTransformFeedbackPropertiesEXT,
    api_types::VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR,
    api_types::VkPhysicalDeviceUniformBufferStandardLayoutFeatures,
    api_types::VkPhysicalDeviceVariablePointersFeatures,
    api_types::VkPhysicalDeviceVertexAttributeDivisorFeatures,
    api_types::VkPhysicalDeviceVertexAttributeDivisorProperties,
    api_types::VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT,
    api_types::VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT,
    api_types::VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT,
    api_types::VkPhysicalDeviceVideoDecodeVP9FeaturesKHR,
    api_types::VkPhysicalDeviceVideoEncodeAV1FeaturesKHR,
    api_types::VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR,
    api_types::VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR,
    api_types::VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR,
    api_types::VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR,
    api_types::VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE,
    api_types::VkPhysicalDeviceVideoFormatInfoKHR,
    api_types::VkPhysicalDeviceVideoMaintenance1FeaturesKHR,
    api_types::VkPhysicalDeviceVulkan11Features,
    api_types::VkPhysicalDeviceVulkan11Properties,
    api_types::VkPhysicalDeviceVulkan12Features,
    api_types::VkPhysicalDeviceVulkan12Properties,
    api_types::VkPhysicalDeviceVulkan13Features,
    api_types::VkPhysicalDeviceVulkan13Properties,
    api_types::VkPhysicalDeviceVulkan14Features,
    api_types::VkPhysicalDeviceVulkan14Properties,
    api_types::VkPhysicalDeviceVulkanMemoryModelFeatures,
    api_types::VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR,
    api_types::VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT,
    api_types::VkPhysicalDeviceYcbcrDegammaFeaturesQCOM,
    api_types::VkPhysicalDeviceYcbcrImageArraysFeaturesEXT,
    api_types::VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT,
    api_types::VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures,
    api_types::VkPipelineBinaryCreateInfoKHR,
    api_types::VkPipelineBinaryDataInfoKHR,
    api_types::VkPipelineBinaryDataKHR,
    api_types::VkPipelineBinaryHandlesInfoKHR,
    api_types::VkPipelineBinaryInfoKHR,
    api_types::VkPipelineBinaryKeyKHR,
    api_types::VkPipelineBinaryKeysAndDataKHR,
    api_types::VkPipelineCacheCreateInfo,
    api_types::VkPipelineCacheHeaderVersionDataGraphQCOM,
    api_types::VkPipelineCacheHeaderVersionOne,
    api_types::VkPipelineColorBlendAdvancedStateCreateInfoEXT,
    api_types::VkPipelineColorBlendAttachmentState,
    api_types::VkPipelineColorBlendStateCreateInfo,
    api_types::VkPipelineColorWriteCreateInfoEXT,
    api_types::VkPipelineCompilerControlCreateInfoAMD,
    api_types::VkPipelineCoverageModulationStateCreateInfoNV,
    api_types::VkPipelineCoverageReductionStateCreateInfoNV,
    api_types::VkPipelineCoverageToColorStateCreateInfoNV,
    api_types::VkPipelineCreateFlags2CreateInfo,
    api_types::VkPipelineCreateInfoKHR,
    api_types::VkPipelineCreationFeedback,
    api_types::VkPipelineCreationFeedbackCreateInfo,
    api_types::VkPipelineDepthStencilStateCreateInfo,
    api_types::VkPipelineDiscardRectangleStateCreateInfoEXT,
    api_types::VkPipelineDynamicStateCreateInfo,
    api_types::VkPipelineExecutableInfoKHR,
    api_types::VkPipelineExecutableInternalRepresentationKHR,
    api_types::VkPipelineExecutablePropertiesKHR,
    api_types::VkPipelineExecutableStatisticKHR,
    api_types::VkPipelineExecutableStatisticValueKHR,
    api_types::VkPipelineFragmentDensityMapLayeredCreateInfoVALVE,
    api_types::VkPipelineFragmentShadingRateEnumStateCreateInfoNV,
    api_types::VkPipelineFragmentShadingRateStateCreateInfoKHR,
    api_types::VkPipelineIndirectDeviceAddressInfoNV,
    api_types::VkPipelineInfoKHR,
    api_types::VkPipelineInputAssemblyStateCreateInfo,
    api_types::VkPipelineLayoutCreateInfo,
    api_types::VkPipelineLibraryCreateInfoKHR,
    api_types::VkPipelineMultisampleStateCreateInfo,
    api_types::VkPipelineRasterizationConservativeStateCreateInfoEXT,
    api_types::VkPipelineRasterizationDepthClipStateCreateInfoEXT,
    api_types::VkPipelineRasterizationLineStateCreateInfo,
    api_types::VkPipelineRasterizationProvokingVertexStateCreateInfoEXT,
    api_types::VkPipelineRasterizationStateCreateInfo,
    api_types::VkPipelineRasterizationStateRasterizationOrderAMD,
    api_types::VkPipelineRasterizationStateStreamCreateInfoEXT,
    api_types::VkPipelineRenderingCreateInfo,
    api_types::VkPipelineRepresentativeFragmentTestStateCreateInfoNV,
    api_types::VkPipelineRobustnessCreateInfo,
    api_types::VkPipelineSampleLocationsStateCreateInfoEXT,
    api_types::VkPipelineShaderStageCreateInfo,
    api_types::VkPipelineShaderStageModuleIdentifierCreateInfoEXT,
    api_types::VkPipelineShaderStageRequiredSubgroupSizeCreateInfo,
    api_types::VkPipelineTessellationDomainOriginStateCreateInfo,
    api_types::VkPipelineTessellationStateCreateInfo,
    api_types::VkPipelineVertexInputDivisorStateCreateInfo,
    api_types::VkPipelineVertexInputStateCreateInfo,
    api_types::VkPipelineViewportCoarseSampleOrderStateCreateInfoNV,
    api_types::VkPipelineViewportDepthClampControlCreateInfoEXT,
    api_types::VkPipelineViewportDepthClipControlCreateInfoEXT,
    api_types::VkPipelineViewportExclusiveScissorStateCreateInfoNV,
    api_types::VkPipelineViewportShadingRateImageStateCreateInfoNV,
    api_types::VkPipelineViewportStateCreateInfo,
    api_types::VkPipelineViewportSwizzleStateCreateInfoNV,
    api_types::VkPipelineViewportWScalingStateCreateInfoNV,
    api_types::VkPresentFrameTokenGGP,
    api_types::VkPresentId2KHR,
    api_types::VkPresentIdKHR,
    api_types::VkPresentInfoKHR,
    api_types::VkPresentRegionKHR,
    api_types::VkPresentRegionsKHR,
    api_types::VkPresentStageTimeEXT,
    api_types::VkPresentTimeGOOGLE,
    api_types::VkPresentTimesInfoGOOGLE,
    api_types::VkPresentTimingInfoEXT,
    api_types::VkPresentTimingSurfaceCapabilitiesEXT,
    api_types::VkPresentTimingsInfoEXT,
    api_types::VkPresentWait2InfoKHR,
    api_types::VkPrivateDataSlotCreateInfo,
    api_types::VkProtectedSubmitInfo,
    api_types::VkPushConstantBankInfoNV,
    api_types::VkPushConstantRange,
    api_types::VkPushConstantsInfo,
    api_types::VkPushDescriptorSetInfo,
    api_types::VkPushDescriptorSetWithTemplateInfo,
    api_types::VkQueryPoolCreateInfo,
    api_types::VkQueryPoolPerformanceCreateInfoKHR,
    api_types::VkQueryPoolPerformanceQueryCreateInfoINTEL,
    api_types::VkQueryPoolVideoEncodeFeedbackCreateInfoKHR,
    api_types::VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR,
    api_types::VkQueueFamilyCheckpointProperties2NV,
    api_types::VkQueueFamilyCheckpointPropertiesNV,
    api_types::VkQueueFamilyDataGraphOpticalFlowPropertiesARM,
    api_types::VkQueueFamilyDataGraphProcessingEnginePropertiesARM,
    api_types::VkQueueFamilyDataGraphPropertiesARM,
    api_types::VkQueueFamilyGlobalPriorityProperties,
    api_types::VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR,
    api_types::VkQueueFamilyOwnershipTransferPropertiesKHR,
    api_types::VkQueueFamilyProperties,
    api_types::VkQueueFamilyProperties2,
    api_types::VkQueueFamilyQueryResultStatusPropertiesKHR,
    api_types::VkQueueFamilyVideoPropertiesKHR,
    api_types::VkRayTracingPipelineCreateInfoKHR,
    api_types::VkRayTracingPipelineCreateInfoNV,
    api_types::VkRayTracingPipelineInterfaceCreateInfoKHR,
    api_types::VkRayTracingShaderGroupCreateInfoKHR,
    api_types::VkRayTracingShaderGroupCreateInfoNV,
    api_types::VkRect2D,
    api_types::VkRectLayerKHR,
    api_types::VkRefreshCycleDurationGOOGLE,
    api_types::VkReleaseCapturedPipelineDataInfoKHR,
    api_types::VkReleaseSwapchainImagesInfoKHR,
    api_types::VkRenderPassAttachmentBeginInfo,
    api_types::VkRenderPassBeginInfo,
    api_types::VkRenderPassCreateInfo,
    api_types::VkRenderPassCreateInfo2,
    api_types::VkRenderPassCreationControlEXT,
    api_types::VkRenderPassCreationFeedbackCreateInfoEXT,
    api_types::VkRenderPassCreationFeedbackInfoEXT,
    api_types::VkRenderPassFragmentDensityMapCreateInfoEXT,
    api_types::VkRenderPassFragmentDensityMapOffsetEndInfoEXT,
    api_types::VkRenderPassInputAttachmentAspectCreateInfo,
    api_types::VkRenderPassMultiviewCreateInfo,
    api_types::VkRenderPassPerformanceCountersByRegionBeginInfoARM,
    api_types::VkRenderPassSampleLocationsBeginInfoEXT,
    api_types::VkRenderPassStripeBeginInfoARM,
    api_types::VkRenderPassStripeInfoARM,
    api_types::VkRenderPassStripeSubmitInfoARM,
    api_types::VkRenderPassSubpassFeedbackCreateInfoEXT,
    api_types::VkRenderPassSubpassFeedbackInfoEXT,
    api_types::VkRenderPassTileShadingCreateInfoQCOM,
    api_types::VkRenderPassTransformBeginInfoQCOM,
    api_types::VkRenderingAreaInfo,
    api_types::VkRenderingAttachmentFlagsInfoKHR,
    api_types::VkRenderingAttachmentInfo,
    api_types::VkRenderingAttachmentLocationInfo,
    api_types::VkRenderingEndInfoKHR,
    api_types::VkRenderingFragmentDensityMapAttachmentInfoEXT,
    api_types::VkRenderingFragmentShadingRateAttachmentInfoKHR,
    api_types::VkRenderingInfo,
    api_types::VkRenderingInputAttachmentIndexInfo,
    api_types::VkResolveImageInfo2,
    api_types::VkResolveImageModeInfoKHR,
    api_types::VkSRTDataNV,
    api_types::VkSampleLocationEXT,
    api_types::VkSampleLocationsInfoEXT,
    api_types::VkSamplerBlockMatchWindowCreateInfoQCOM,
    api_types::VkSamplerBorderColorComponentMappingCreateInfoEXT,
    api_types::VkSamplerCaptureDescriptorDataInfoEXT,
    api_types::VkSamplerCreateInfo,
    api_types::VkSamplerCubicWeightsCreateInfoQCOM,
    api_types::VkSamplerCustomBorderColorCreateInfoEXT,
    api_types::VkSamplerReductionModeCreateInfo,
    api_types::VkSamplerYcbcrConversionCreateInfo,
    api_types::VkSamplerYcbcrConversionImageFormatProperties,
    api_types::VkSamplerYcbcrConversionInfo,
    api_types::VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM,
    api_types::VkScreenSurfaceCreateInfoQNX,
    api_types::VkSemaphoreCreateInfo,
    api_types::VkSemaphoreGetFdInfoKHR,
    api_types::VkSemaphoreGetWin32HandleInfoKHR,
    api_types::VkSemaphoreGetZirconHandleInfoFUCHSIA,
    api_types::VkSemaphoreSignalInfo,
    api_types::VkSemaphoreSubmitInfo,
    api_types::VkSemaphoreTypeCreateInfo,
    api_types::VkSemaphoreWaitInfo,
    api_types::VkSetDescriptorBufferOffsetsInfoEXT,
    api_types::VkSetLatencyMarkerInfoNV,
    api_types::VkSetPresentConfigNV,
    api_types::VkSetStateFlagsIndirectCommandNV,
    api_types::VkShaderCreateInfoEXT,
    api_types::VkShaderModuleCreateInfo,
    api_types::VkShaderModuleIdentifierEXT,
    api_types::VkShaderModuleValidationCacheCreateInfoEXT,
    api_types::VkShaderResourceUsageAMD,
    api_types::VkShaderStatisticsInfoAMD,
    api_types::VkShadingRatePaletteNV,
    api_types::VkSharedPresentSurfaceCapabilities2KHR,
    api_types::VkSharedPresentSurfaceCapabilitiesKHR,
    api_types::VkSparseBufferMemoryBindInfo,
    api_types::VkSparseImageFormatProperties,
    api_types::VkSparseImageFormatProperties2,
    api_types::VkSparseImageMemoryBind,
    api_types::VkSparseImageMemoryBindInfo,
    api_types::VkSparseImageMemoryRequirements,
    api_types::VkSparseImageMemoryRequirements2,
    api_types::VkSparseImageOpaqueMemoryBindInfo,
    api_types::VkSparseMemoryBind,
    api_types::VkSpecializationInfo,
    api_types::VkSpecializationMapEntry,
    api_types::VkStencilOpState,
    api_types::VkStreamDescriptorSurfaceCreateInfoGGP,
    api_types::VkStridedDeviceAddressNV,
    api_types::VkStridedDeviceAddressRangeKHR,
    api_types::VkStridedDeviceAddressRegionKHR,
    api_types::VkSubmitInfo,
    api_types::VkSubmitInfo2,
    api_types::VkSubpassBeginInfo,
    api_types::VkSubpassDependency,
    api_types::VkSubpassDependency2,
    api_types::VkSubpassDescription,
    api_types::VkSubpassDescription2,
    api_types::VkSubpassDescriptionDepthStencilResolve,
    api_types::VkSubpassEndInfo,
    api_types::VkSubpassResolvePerformanceQueryEXT,
    api_types::VkSubpassSampleLocationsEXT,
    api_types::VkSubresourceHostMemcpySize,
    api_types::VkSubresourceLayout,
    api_types::VkSubresourceLayout2,
    api_types::VkSurfaceCapabilities2EXT,
    api_types::VkSurfaceCapabilities2KHR,
    api_types::VkSurfaceCapabilitiesFullScreenExclusiveEXT,
    api_types::VkSurfaceCapabilitiesKHR,
    api_types::VkSurfaceCapabilitiesPresentBarrierNV,
    api_types::VkSurfaceCapabilitiesPresentId2KHR,
    api_types::VkSurfaceCapabilitiesPresentWait2KHR,
    api_types::VkSurfaceFormat2KHR,
    api_types::VkSurfaceFormatKHR,
    api_types::VkSurfaceFullScreenExclusiveInfoEXT,
    api_types::VkSurfaceFullScreenExclusiveWin32InfoEXT,
    api_types::VkSurfacePresentModeCompatibilityKHR,
    api_types::VkSurfacePresentModeKHR,
    api_types::VkSurfacePresentScalingCapabilitiesKHR,
    api_types::VkSurfaceProtectedCapabilitiesKHR,
    api_types::VkSwapchainCalibratedTimestampInfoEXT,
    api_types::VkSwapchainCounterCreateInfoEXT,
    api_types::VkSwapchainCreateInfoKHR,
    api_types::VkSwapchainDisplayNativeHdrCreateInfoAMD,
    api_types::VkSwapchainFlagsSurfaceCapabilitiesEXT,
    api_types::VkSwapchainLatencyCreateInfoNV,
    api_types::VkSwapchainPresentBarrierCreateInfoNV,
    api_types::VkSwapchainPresentFenceInfoKHR,
    api_types::VkSwapchainPresentModeInfoKHR,
    api_types::VkSwapchainPresentModesCreateInfoKHR,
    api_types::VkSwapchainPresentScalingCreateInfoKHR,
    api_types::VkSwapchainTimeDomainPropertiesEXT,
    api_types::VkSwapchainTimingPropertiesEXT,
    api_types::VkTensorCaptureDescriptorDataInfoARM,
    api_types::VkTensorCopyARM,
    api_types::VkTensorCreateInfoARM,
    api_types::VkTensorDependencyInfoARM,
    api_types::VkTensorDescriptionARM,
    api_types::VkTensorExplicitTilingFormatPropertiesARM,
    api_types::VkTensorFormatPropertiesARM,
    api_types::VkTensorMemoryBarrierARM,
    api_types::VkTensorMemoryRequirementsInfoARM,
    api_types::VkTensorRollingBackingCreateInfoARM,
    api_types::VkTensorViewCaptureDescriptorDataInfoARM,
    api_types::VkTensorViewCreateInfoARM,
    api_types::VkTextureLODGatherFormatPropertiesAMD,
    api_types::VkThrottleHintSubmitInfoSEC,
    api_types::VkTileMemoryBindInfoQCOM,
    api_types::VkTileMemoryRequirementsQCOM,
    api_types::VkTileMemorySizeInfoQCOM,
    api_types::VkTilePropertiesQCOM,
    api_types::VkTimelineSemaphoreSubmitInfo,
    api_types::VkTraceRaysIndirectCommand2KHR,
    api_types::VkTraceRaysIndirectCommandKHR,
    api_types::VkTransformMatrixKHR,
    api_types::VkValidationCacheCreateInfoEXT,
    api_types::VkValidationFeaturesEXT,
    api_types::VkValidationFlagsEXT,
    api_types::VkVertexInputAttributeDescription,
    api_types::VkVertexInputAttributeDescription2EXT,
    api_types::VkVertexInputBindingDescription,
    api_types::VkVertexInputBindingDescription2EXT,
    api_types::VkVertexInputBindingDivisorDescription,
    api_types::VkViSurfaceCreateInfoNN,
    api_types::VkVideoBeginCodingInfoKHR,
    api_types::VkVideoCapabilitiesKHR,
    api_types::VkVideoCodingControlInfoKHR,
    api_types::VkVideoDecodeAV1CapabilitiesKHR,
    api_types::VkVideoDecodeAV1DpbSlotInfoKHR,
    api_types::VkVideoDecodeAV1PictureInfoKHR,
    api_types::VkVideoDecodeAV1ProfileInfoKHR,
    api_types::VkVideoDecodeAV1SessionParametersCreateInfoKHR,
    api_types::VkVideoDecodeCapabilitiesKHR,
    api_types::VkVideoDecodeH264CapabilitiesKHR,
    api_types::VkVideoDecodeH264DpbSlotInfoKHR,
    api_types::VkVideoDecodeH264PictureInfoKHR,
    api_types::VkVideoDecodeH264ProfileInfoKHR,
    api_types::VkVideoDecodeH264SessionParametersAddInfoKHR,
    api_types::VkVideoDecodeH264SessionParametersCreateInfoKHR,
    api_types::VkVideoDecodeInfoKHR,
    api_types::VkVideoDecodeUsageInfoKHR,
    api_types::VkVideoDecodeVP9CapabilitiesKHR,
    api_types::VkVideoDecodeVP9PictureInfoKHR,
    api_types::VkVideoDecodeVP9ProfileInfoKHR,
    api_types::VkVideoEncodeAV1CapabilitiesKHR,
    api_types::VkVideoEncodeAV1DpbSlotInfoKHR,
    api_types::VkVideoEncodeAV1FrameSizeKHR,
    api_types::VkVideoEncodeAV1GopRemainingFrameInfoKHR,
    api_types::VkVideoEncodeAV1PictureInfoKHR,
    api_types::VkVideoEncodeAV1ProfileInfoKHR,
    api_types::VkVideoEncodeAV1QIndexKHR,
    api_types::VkVideoEncodeAV1QualityLevelPropertiesKHR,
    api_types::VkVideoEncodeAV1QuantizationMapCapabilitiesKHR,
    api_types::VkVideoEncodeAV1RateControlInfoKHR,
    api_types::VkVideoEncodeAV1RateControlLayerInfoKHR,
    api_types::VkVideoEncodeAV1SessionCreateInfoKHR,
    api_types::VkVideoEncodeAV1SessionParametersCreateInfoKHR,
    api_types::VkVideoEncodeCapabilitiesKHR,
    api_types::VkVideoEncodeFeedback2CapabilitiesKHR,
    api_types::VkVideoEncodeH264CapabilitiesKHR,
    api_types::VkVideoEncodeH264DpbSlotInfoKHR,
    api_types::VkVideoEncodeH264FrameSizeKHR,
    api_types::VkVideoEncodeH264GopRemainingFrameInfoKHR,
    api_types::VkVideoEncodeH264NaluSliceInfoKHR,
    api_types::VkVideoEncodeH264PictureInfoKHR,
    api_types::VkVideoEncodeH264ProfileInfoKHR,
    api_types::VkVideoEncodeH264QpKHR,
    api_types::VkVideoEncodeH264QualityLevelPropertiesKHR,
    api_types::VkVideoEncodeH264QuantizationMapCapabilitiesKHR,
    api_types::VkVideoEncodeH264RateControlInfoKHR,
    api_types::VkVideoEncodeH264RateControlLayerInfoKHR,
    api_types::VkVideoEncodeH264SessionCreateInfoKHR,
    api_types::VkVideoEncodeH264SessionParametersAddInfoKHR,
    api_types::VkVideoEncodeH264SessionParametersCreateInfoKHR,
    api_types::VkVideoEncodeH264SessionParametersFeedbackInfoKHR,
    api_types::VkVideoEncodeH264SessionParametersGetInfoKHR,
    api_types::VkVideoEncodeH265QuantizationMapCapabilitiesKHR,
    api_types::VkVideoEncodeInfoKHR,
    api_types::VkVideoEncodeIntraRefreshCapabilitiesKHR,
    api_types::VkVideoEncodeIntraRefreshInfoKHR,
    api_types::VkVideoEncodeProfileRgbConversionInfoVALVE,
    api_types::VkVideoEncodeQualityLevelInfoKHR,
    api_types::VkVideoEncodeQualityLevelPropertiesKHR,
    api_types::VkVideoEncodeQuantizationMapCapabilitiesKHR,
    api_types::VkVideoEncodeQuantizationMapInfoKHR,
    api_types::VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR,
    api_types::VkVideoEncodeRateControlInfoKHR,
    api_types::VkVideoEncodeRateControlLayerInfoKHR,
    api_types::VkVideoEncodeRgbConversionCapabilitiesVALVE,
    api_types::VkVideoEncodeSessionIntraRefreshCreateInfoKHR,
    api_types::VkVideoEncodeSessionParametersFeedbackInfoKHR,
    api_types::VkVideoEncodeSessionParametersGetInfoKHR,
    api_types::VkVideoEncodeSessionRgbConversionCreateInfoVALVE,
    api_types::VkVideoEncodeUsageInfoKHR,
    api_types::VkVideoEndCodingInfoKHR,
    api_types::VkVideoFormatAV1QuantizationMapPropertiesKHR,
    api_types::VkVideoFormatH265QuantizationMapPropertiesKHR,
    api_types::VkVideoFormatPropertiesKHR,
    api_types::VkVideoFormatQuantizationMapPropertiesKHR,
    api_types::VkVideoInlineQueryInfoKHR,
    api_types::VkVideoPictureResourceInfoKHR,
    api_types::VkVideoProfileInfoKHR,
    api_types::VkVideoProfileListInfoKHR,
    api_types::VkVideoReferenceIntraRefreshInfoKHR,
    api_types::VkVideoReferenceSlotInfoKHR,
    api_types::VkVideoSessionCreateInfoKHR,
    api_types::VkVideoSessionMemoryRequirementsKHR,
    api_types::VkVideoSessionParametersCreateInfoKHR,
    api_types::VkVideoSessionParametersUpdateInfoKHR,
    api_types::VkViewport,
    api_types::VkViewportSwizzleNV,
    api_types::VkViewportWScalingNV,
    api_types::VkWaylandSurfaceCreateInfoKHR,
    api_types::VkWin32KeyedMutexAcquireReleaseInfoKHR,
    api_types::VkWin32KeyedMutexAcquireReleaseInfoNV,
    api_types::VkWin32SurfaceCreateInfoKHR,
    api_types::VkWriteDescriptorSet,
    api_types::VkWriteDescriptorSetAccelerationStructureKHR,
    api_types::VkWriteDescriptorSetAccelerationStructureNV,
    api_types::VkWriteDescriptorSetInlineUniformBlock,
    api_types::VkWriteDescriptorSetPartitionedAccelerationStructureNV,
    api_types::VkWriteDescriptorSetTensorARM,
    api_types::VkWriteIndirectExecutionSetPipelineEXT,
    api_types::VkWriteIndirectExecutionSetShaderEXT,
    api_types::VkXYColorEXT,
    api_types::VkXcbSurfaceCreateInfoKHR,
    api_types::VkXlibSurfaceCreateInfoKHR>;

// The structures a pNext chain can hold: every descriptor with a structure_type.
using extensible_structures = util::TypeList<
    api_types::VkAccelerationStructureBuildGeometryInfoKHR,
    api_types::VkAccelerationStructureBuildSizesInfoKHR,
    api_types::VkAccelerationStructureCaptureDescriptorDataInfoEXT,
    api_types::VkAccelerationStructureCreateInfo2KHR,
    api_types::VkAccelerationStructureCreateInfoKHR,
    api_types::VkAccelerationStructureCreateInfoNV,
    api_types::VkAccelerationStructureDeviceAddressInfoKHR,
    api_types::VkAccelerationStructureGeometryAabbsDataKHR,
    api_types::VkAccelerationStructureGeometryInstancesDataKHR,
    api_types::VkAccelerationStructureGeometryKHR,
    api_types::VkAccelerationStructureGeometryLinearSweptSpheresDataNV,
    api_types::VkAccelerationStructureGeometryMicromapDataKHR,
    api_types::VkAccelerationStructureGeometryMotionTrianglesDataNV,
    api_types::VkAccelerationStructureGeometrySpheresDataNV,
    api_types::VkAccelerationStructureGeometryTrianglesDataKHR,
    api_types::VkAccelerationStructureInfoNV,
    api_types::VkAccelerationStructureMemoryRequirementsInfoNV,
    api_types::VkAccelerationStructureMotionInfoNV,
    api_types::VkAccelerationStructureTrianglesDisplacementMicromapNV,
    api_types::VkAccelerationStructureTrianglesOpacityMicromapEXT,
    api_types::VkAccelerationStructureTrianglesOpacityMicromapKHR,
    api_types::VkAccelerationStructureVersionInfoKHR,
    api_types::VkAcquireNextImageInfoKHR,
    api_types::VkAcquireProfilingLockInfoKHR,
    api_types::VkAmigoProfilingSubmitInfoSEC,
    api_types::VkAndroidHardwareBufferFormatProperties2ANDROID,
    api_types::VkAndroidHardwareBufferFormatPropertiesANDROID,
    api_types::VkAndroidHardwareBufferFormatResolvePropertiesANDROID,
    api_types::VkAndroidHardwareBufferPropertiesANDROID,
    api_types::VkAndroidHardwareBufferUsageANDROID,
    api_types::VkAndroidSurfaceCreateInfoKHR,
    api_types::VkAntiLagDataAMD,
    api_types::VkAntiLagPresentationInfoAMD,
    api_types::VkApplicationInfo,
    api_types::VkAttachmentDescription2,
    api_types::VkAttachmentDescriptionStencilLayout,
    api_types::VkAttachmentFeedbackLoopInfoEXT,
    api_types::VkAttachmentReference2,
    api_types::VkAttachmentReferenceStencilLayout,
    api_types::VkAttachmentSampleCountInfoAMD,
    api_types::VkBeginCustomResolveInfoEXT,
    api_types::VkBindAccelerationStructureMemoryInfoNV,
    api_types::VkBindBufferMemoryDeviceGroupInfo,
    api_types::VkBindBufferMemoryInfo,
    api_types::VkBindDataGraphPipelineSessionMemoryInfoARM,
    api_types::VkBindDescriptorBufferEmbeddedSamplersInfoEXT,
    api_types::VkBindDescriptorSetsInfo,
    api_types::VkBindImageMemoryDeviceGroupInfo,
    api_types::VkBindImageMemoryInfo,
    api_types::VkBindImageMemorySwapchainInfoKHR,
    api_types::VkBindImagePlaneMemoryInfo,
    api_types::VkBindIndexBuffer3InfoKHR,
    api_types::VkBindMemoryStatus,
    api_types::VkBindSparseInfo,
    api_types::VkBindTensorMemoryInfoARM,
    api_types::VkBindTransformFeedbackBuffer2InfoEXT,
    api_types::VkBindVertexBuffer3InfoKHR,
    api_types::VkBindVideoSessionMemoryInfoKHR,
    api_types::VkBlitImageCubicWeightsInfoQCOM,
    api_types::VkBlitImageInfo2,
    api_types::VkBufferCaptureDescriptorDataInfoEXT,
    api_types::VkBufferCopy2,
    api_types::VkBufferCreateInfo,
    api_types::VkBufferDeviceAddressAlignmentAllocateInfoVALVE,
    api_types::VkBufferDeviceAddressCreateInfoEXT,
    api_types::VkBufferDeviceAddressInfo,
    api_types::VkBufferImageCopy2,
    api_types::VkBufferMemoryBarrier,
    api_types::VkBufferMemoryBarrier2,
    api_types::VkBufferMemoryRequirementsInfo2,
    api_types::VkBufferOpaqueCaptureAddressCreateInfo,
    api_types::VkBufferUsageFlags2CreateInfo,
    api_types::VkBufferViewCreateInfo,
    api_types::VkBuildPartitionedAccelerationStructureInfoNV,
    api_types::VkCalibratedTimestampInfoKHR,
    api_types::VkCheckpointData2NV,
    api_types::VkCheckpointDataNV,
    api_types::VkCommandBufferAllocateInfo,
    api_types::VkCommandBufferBeginInfo,
    api_types::VkCommandBufferInheritanceConditionalRenderingInfoEXT,
    api_types::VkCommandBufferInheritanceInfo,
    api_types::VkCommandBufferInheritanceRenderPassTransformInfoQCOM,
    api_types::VkCommandBufferInheritanceRenderingInfo,
    api_types::VkCommandBufferInheritanceViewportScissorInfoNV,
    api_types::VkCommandBufferSubmitInfo,
    api_types::VkCommandPoolCreateInfo,
    api_types::VkComputeOccupancyPriorityParametersNV,
    api_types::VkComputePipelineCreateInfo,
    api_types::VkComputePipelineIndirectBufferInfoNV,
    api_types::VkConditionalRenderingBeginInfo2EXT,
    api_types::VkConditionalRenderingBeginInfoEXT,
    api_types::VkConvertCooperativeVectorMatrixInfoNV,
    api_types::VkCooperativeMatrixFlexibleDimensionsPropertiesNV,
    api_types::VkCooperativeMatrixProperties2EXT,
    api_types::VkCooperativeMatrixPropertiesKHR,
    api_types::VkCooperativeMatrixPropertiesNV,
    api_types::VkCooperativeVectorPropertiesNV,
    api_types::VkCopyAccelerationStructureInfoKHR,
    api_types::VkCopyAccelerationStructureToMemoryInfoKHR,
    api_types::VkCopyBufferInfo2,
    api_types::VkCopyBufferToImageInfo2,
    api_types::VkCopyCommandTransformInfoQCOM,
    api_types::VkCopyDescriptorSet,
    api_types::VkCopyDeviceMemoryImageInfoKHR,
    api_types::VkCopyDeviceMemoryInfoKHR,
    api_types::VkCopyImageInfo2,
    api_types::VkCopyImageToBufferInfo2,
    api_types::VkCopyImageToImageInfo,
    api_types::VkCopyImageToMemoryInfo,
    api_types::VkCopyMemoryIndirectInfoKHR,
    api_types::VkCopyMemoryToAccelerationStructureInfoKHR,
    api_types::VkCopyMemoryToImageIndirectInfoKHR,
    api_types::VkCopyMemoryToImageInfo,
    api_types::VkCopyMemoryToMicromapInfoEXT,
    api_types::VkCopyMicromapInfoEXT,
    api_types::VkCopyMicromapToMemoryInfoEXT,
    api_types::VkCopyTensorInfoARM,
    api_types::VkCustomResolveCreateInfoEXT,
    api_types::VkD3D12FenceSubmitInfoKHR,
    api_types::VkDataGraphOpticalFlowImageFormatInfoARM,
    api_types::VkDataGraphOpticalFlowImageFormatPropertiesARM,
    api_types::VkDataGraphPipelineBuiltinModelCreateInfoQCOM,
    api_types::VkDataGraphPipelineCompilerControlCreateInfoARM,
    api_types::VkDataGraphPipelineConstantARM,
    api_types::VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM,
    api_types::VkDataGraphPipelineCreateInfoARM,
    api_types::VkDataGraphPipelineDispatchInfoARM,
    api_types::VkDataGraphPipelineIdentifierCreateInfoARM,
    api_types::VkDataGraphPipelineInfoARM,
    api_types::VkDataGraphPipelineNeuralStatisticsCreateInfoARM,
    api_types::VkDataGraphPipelineOpticalFlowCreateInfoARM,
    api_types::VkDataGraphPipelineOpticalFlowDispatchInfoARM,
    api_types::VkDataGraphPipelinePropertyQueryResultARM,
    api_types::VkDataGraphPipelineResourceInfoARM,
    api_types::VkDataGraphPipelineResourceInfoImageLayoutARM,
    api_types::VkDataGraphPipelineSessionBindPointRequirementARM,
    api_types::VkDataGraphPipelineSessionBindPointRequirementsInfoARM,
    api_types::VkDataGraphPipelineSessionCreateInfoARM,
    api_types::VkDataGraphPipelineSessionMemoryRequirementsInfoARM,
    api_types::VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM,
    api_types::VkDataGraphPipelineShaderModuleCreateInfoARM,
    api_types::VkDataGraphPipelineSingleNodeConnectionARM,
    api_types::VkDataGraphPipelineSingleNodeCreateInfoARM,
    api_types::VkDataGraphProcessingEngineCreateInfoARM,
    api_types::VkDebugMarkerMarkerInfoEXT,
    api_types::VkDebugMarkerObjectNameInfoEXT,
    api_types::VkDebugMarkerObjectTagInfoEXT,
    api_types::VkDebugReportCallbackCreateInfoEXT,
    api_types::VkDebugUtilsLabelEXT,
    api_types::VkDebugUtilsMessengerCallbackDataEXT,
    api_types::VkDebugUtilsMessengerCreateInfoEXT,
    api_types::VkDebugUtilsObjectNameInfoEXT,
    api_types::VkDebugUtilsObjectTagInfoEXT,
    api_types::VkDecompressMemoryInfoEXT,
    api_types::VkDedicatedAllocationBufferCreateInfoNV,
    api_types::VkDedicatedAllocationImageCreateInfoNV,
    api_types::VkDedicatedAllocationMemoryAllocateInfoNV,
    api_types::VkDependencyInfo,
    api_types::VkDepthBiasInfoEXT,
    api_types::VkDepthBiasRepresentationInfoEXT,
    api_types::VkDescriptorAddressInfoEXT,
    api_types::VkDescriptorBufferBindingInfoEXT,
    api_types::VkDescriptorBufferBindingPushDescriptorBufferHandleEXT,
    api_types::VkDescriptorGetInfoEXT,
    api_types::VkDescriptorGetTensorInfoARM,
    api_types::VkDescriptorPoolCreateInfo,
    api_types::VkDescriptorPoolInlineUniformBlockCreateInfo,
    api_types::VkDescriptorSetAllocateInfo,
    api_types::VkDescriptorSetBindingReferenceVALVE,
    api_types::VkDescriptorSetLayoutBindingFlagsCreateInfo,
    api_types::VkDescriptorSetLayoutCreateInfo,
    api_types::VkDescriptorSetLayoutHostMappingInfoVALVE,
    api_types::VkDescriptorSetLayoutSupport,
    api_types::VkDescriptorSetVariableDescriptorCountAllocateInfo,
    api_types::VkDescriptorSetVariableDescriptorCountLayoutSupport,
    api_types::VkDescriptorUpdateTemplateCreateInfo,
    api_types::VkDeviceAddressBindingCallbackDataEXT,
    api_types::VkDeviceBufferMemoryRequirements,
    api_types::VkDeviceCreateInfo,
    api_types::VkDeviceDeviceMemoryReportCreateInfoEXT,
    api_types::VkDeviceDiagnosticsConfigCreateInfoNV,
    api_types::VkDeviceEventInfoEXT,
    api_types::VkDeviceFaultCountsEXT,
    api_types::VkDeviceFaultDebugInfoKHR,
    api_types::VkDeviceFaultInfoEXT,
    api_types::VkDeviceFaultInfoKHR,
    api_types::VkDeviceFaultShaderAbortMessageInfoKHR,
    api_types::VkDeviceGroupBindSparseInfo,
    api_types::VkDeviceGroupCommandBufferBeginInfo,
    api_types::VkDeviceGroupDeviceCreateInfo,
    api_types::VkDeviceGroupPresentCapabilitiesKHR,
    api_types::VkDeviceGroupPresentInfoKHR,
    api_types::VkDeviceGroupRenderPassBeginInfo,
    api_types::VkDeviceGroupSubmitInfo,
    api_types::VkDeviceGroupSwapchainCreateInfoKHR,
    api_types::VkDeviceImageMemoryRequirements,
    api_types::VkDeviceImageSubresourceInfo,
    api_types::VkDeviceMemoryCopyKHR,
    api_types::VkDeviceMemoryImageCopyKHR,
    api_types::VkDeviceMemoryOpaqueCaptureAddressInfo,
    api_types::VkDeviceMemoryOverallocationCreateInfoAMD,
    api_types::VkDeviceMemoryReportCallbackDataEXT,
    api_types::VkDevicePipelineBinaryInternalCacheControlKHR,
    api_types::VkDevicePrivateDataCreateInfo,
    api_types::VkDeviceQueueCreateInfo,
    api_types::VkDeviceQueueGlobalPriorityCreateInfo,
    api_types::VkDeviceQueueInfo2,
    api_types::VkDeviceQueueShaderCoreControlCreateInfoARM,
    api_types::VkDeviceTensorMemoryRequirementsARM,
    api_types::VkDirectDriverLoadingInfoLUNARG,
    api_types::VkDirectDriverLoadingListLUNARG,
    api_types::VkDirectFBSurfaceCreateInfoEXT,
    api_types::VkDispatchIndirect2InfoKHR,
    api_types::VkDispatchParametersARM,
    api_types::VkDispatchTileInfoQCOM,
    api_types::VkDisplayEventInfoEXT,
    api_types::VkDisplayModeCreateInfoKHR,
    api_types::VkDisplayModeProperties2KHR,
    api_types::VkDisplayModeStereoPropertiesNV,
    api_types::VkDisplayNativeHdrSurfaceCapabilitiesAMD,
    api_types::VkDisplayPlaneCapabilities2KHR,
    api_types::VkDisplayPlaneInfo2KHR,
    api_types::VkDisplayPlaneProperties2KHR,
    api_types::VkDisplayPowerInfoEXT,
    api_types::VkDisplayPresentInfoKHR,
    api_types::VkDisplayProperties2KHR,
    api_types::VkDisplaySurfaceCreateInfoKHR,
    api_types::VkDisplaySurfaceStereoCreateInfoNV,
    api_types::VkDrawIndirect2InfoKHR,
    api_types::VkDrawIndirectCount2InfoKHR,
    api_types::VkDrmFormatModifierPropertiesList2EXT,
    api_types::VkDrmFormatModifierPropertiesListEXT,
    api_types::VkEventCreateInfo,
    api_types::VkExportFenceCreateInfo,
    api_types::VkExportFenceWin32HandleInfoKHR,
    api_types::VkExportMemoryAllocateInfo,
    api_types::VkExportMemoryAllocateInfoNV,
    api_types::VkExportMemoryWin32HandleInfoKHR,
    api_types::VkExportMemoryWin32HandleInfoNV,
    api_types::VkExportSemaphoreCreateInfo,
    api_types::VkExportSemaphoreWin32HandleInfoKHR,
    api_types::VkExternalBufferProperties,
    api_types::VkExternalFenceProperties,
    api_types::VkExternalFormatANDROID,
    api_types::VkExternalImageFormatProperties,
    api_types::VkExternalMemoryAcquireUnmodifiedEXT,
    api_types::VkExternalMemoryBufferCreateInfo,
    api_types::VkExternalMemoryImageCreateInfo,
    api_types::VkExternalMemoryImageCreateInfoNV,
    api_types::VkExternalMemoryTensorCreateInfoARM,
    api_types::VkExternalSemaphoreProperties,
    api_types::VkExternalTensorPropertiesARM,
    api_types::VkFenceCreateInfo,
    api_types::VkFenceGetFdInfoKHR,
    api_types::VkFenceGetWin32HandleInfoKHR,
    api_types::VkFilterCubicImageViewImageFormatPropertiesEXT,
    api_types::VkFormatProperties2,
    api_types::VkFormatProperties3,
    api_types::VkFormatProperties4KHR,
    api_types::VkFragmentShadingRateAttachmentInfoKHR,
    api_types::VkFrameBoundaryEXT,
    api_types::VkFrameBoundaryTensorsARM,
    api_types::VkFramebufferAttachmentImageInfo,
    api_types::VkFramebufferAttachmentsCreateInfo,
    api_types::VkFramebufferCreateInfo,
    api_types::VkFramebufferMixedSamplesCombinationNV,
    api_types::VkGeneratedCommandsInfoEXT,
    api_types::VkGeneratedCommandsInfoNV,
    api_types::VkGeneratedCommandsMemoryRequirementsInfoEXT,
    api_types::VkGeneratedCommandsMemoryRequirementsInfoNV,
    api_types::VkGeneratedCommandsPipelineInfoEXT,
    api_types::VkGeneratedCommandsShaderInfoEXT,
    api_types::VkGeometryAABBNV,
    api_types::VkGeometryNV,
    api_types::VkGeometryTrianglesNV,
    api_types::VkGetLatencyMarkerInfoNV,
    api_types::VkGpaDeviceClockModeInfoAMD,
    api_types::VkGpaDeviceGetClockInfoAMD,
    api_types::VkGpaSampleBeginInfoAMD,
    api_types::VkGpaSessionCreateInfoAMD,
    api_types::VkGraphicsPipelineCreateInfo,
    api_types::VkGraphicsPipelineLibraryCreateInfoEXT,
    api_types::VkGraphicsPipelineShaderGroupsCreateInfoNV,
    api_types::VkGraphicsShaderGroupCreateInfoNV,
    api_types::VkHdrMetadataEXT,
    api_types::VkHdrVividDynamicMetadataHUAWEI,
    api_types::VkHeadlessSurfaceCreateInfoEXT,
    api_types::VkHostImageCopyDevicePerformanceQuery,
    api_types::VkHostImageLayoutTransitionInfo,
    api_types::VkIOSSurfaceCreateInfoMVK,
    api_types::VkImageAlignmentControlCreateInfoMESA,
    api_types::VkImageBlit2,
    api_types::VkImageCaptureDescriptorDataInfoEXT,
    api_types::VkImageCompressionControlEXT,
    api_types::VkImageCompressionPropertiesEXT,
    api_types::VkImageCopy2,
    api_types::VkImageCreateFlags2CreateInfoKHR,
    api_types::VkImageCreateInfo,
    api_types::VkImageDrmFormatModifierExplicitCreateInfoEXT,
    api_types::VkImageDrmFormatModifierListCreateInfoEXT,
    api_types::VkImageDrmFormatModifierPropertiesEXT,
    api_types::VkImageFormatListCreateInfo,
    api_types::VkImageFormatProperties2,
    api_types::VkImageMemoryBarrier,
    api_types::VkImageMemoryBarrier2,
    api_types::VkImageMemoryRequirementsInfo2,
    api_types::VkImagePipeSurfaceCreateInfoFUCHSIA,
    api_types::VkImagePlaneMemoryRequirementsInfo,
    api_types::VkImageResolve2,
    api_types::VkImageSparseMemoryRequirementsInfo2,
    api_types::VkImageStencilUsage2CreateInfoKHR,
    api_types::VkImageStencilUsageCreateInfo,
    api_types::VkImageSubresource2,
    api_types::VkImageSwapchainCreateInfoKHR,
    api_types::VkImageTilingControlCreateInfoEXT,
    api_types::VkImageToMemoryCopy,
    api_types::VkImageUsageFlags2CreateInfoKHR,
    api_types::VkImageViewASTCDecodeModeEXT,
    api_types::VkImageViewAddressPropertiesNVX,
    api_types::VkImageViewCaptureDescriptorDataInfoEXT,
    api_types::VkImageViewCreateInfo,
    api_types::VkImageViewHandleInfoNVX,
    api_types::VkImageViewMinLodCreateInfoEXT,
    api_types::VkImageViewSampleWeightCreateInfoQCOM,
    api_types::VkImageViewSlicedCreateInfoEXT,
    api_types::VkImageViewUsage2CreateInfoKHR,
    api_types::VkImageViewUsageCreateInfo,
    api_types::VkImportAndroidHardwareBufferInfoANDROID,
    api_types::VkImportFenceFdInfoKHR,
    api_types::VkImportFenceWin32HandleInfoKHR,
    api_types::VkImportMemoryFdInfoKHR,
    api_types::VkImportMemoryHostPointerInfoEXT,
    api_types::VkImportMemoryMetalHandleInfoEXT,
    api_types::VkImportMemoryWin32HandleInfoKHR,
    api_types::VkImportMemoryWin32HandleInfoNV,
    api_types::VkImportMemoryZirconHandleInfoFUCHSIA,
    api_types::VkImportSemaphoreFdInfoKHR,
    api_types::VkImportSemaphoreWin32HandleInfoKHR,
    api_types::VkImportSemaphoreZirconHandleInfoFUCHSIA,
    api_types::VkIndirectCommandsLayoutCreateInfoEXT,
    api_types::VkIndirectCommandsLayoutCreateInfoNV,
    api_types::VkIndirectCommandsLayoutTokenEXT,
    api_types::VkIndirectCommandsLayoutTokenNV,
    api_types::VkIndirectExecutionSetCreateInfoEXT,
    api_types::VkIndirectExecutionSetPipelineInfoEXT,
    api_types::VkIndirectExecutionSetShaderInfoEXT,
    api_types::VkIndirectExecutionSetShaderLayoutInfoEXT,
    api_types::VkInitializePerformanceApiInfoINTEL,
    api_types::VkInstanceCreateInfo,
    api_types::VkLatencySleepInfoNV,
    api_types::VkLatencySleepModeInfoNV,
    api_types::VkLatencySubmissionPresentIdNV,
    api_types::VkLatencySurfaceCapabilitiesNV,
    api_types::VkLatencyTimingsFrameReportNV,
    api_types::VkLayerSettingsCreateInfoEXT,
    api_types::VkMacOSSurfaceCreateInfoMVK,
    api_types::VkMappedMemoryRange,
    api_types::VkMemoryAllocateFlagsInfo,
    api_types::VkMemoryAllocateInfo,
    api_types::VkMemoryBarrier,
    api_types::VkMemoryBarrier2,
    api_types::VkMemoryBarrierAccessFlags3KHR,
    api_types::VkMemoryDedicatedAllocateInfo,
    api_types::VkMemoryDedicatedAllocateInfoTensorARM,
    api_types::VkMemoryDedicatedRequirements,
    api_types::VkMemoryFdPropertiesKHR,
    api_types::VkMemoryGetAndroidHardwareBufferInfoANDROID,
    api_types::VkMemoryGetFdInfoKHR,
    api_types::VkMemoryGetMetalHandleInfoEXT,
    api_types::VkMemoryGetRemoteAddressInfoNV,
    api_types::VkMemoryGetWin32HandleInfoKHR,
    api_types::VkMemoryGetZirconHandleInfoFUCHSIA,
    api_types::VkMemoryHostPointerPropertiesEXT,
    api_types::VkMemoryMapInfo,
    api_types::VkMemoryMapPlacedInfoEXT,
    api_types::VkMemoryMarkerInfoAMD,
    api_types::VkMemoryMetalHandlePropertiesEXT,
    api_types::VkMemoryOpaqueCaptureAddressAllocateInfo,
    api_types::VkMemoryPriorityAllocateInfoEXT,
    api_types::VkMemoryRangeBarrierKHR,
    api_types::VkMemoryRangeBarriersInfoKHR,
    api_types::VkMemoryRequirements2,
    api_types::VkMemoryToImageCopy,
    api_types::VkMemoryUnmapInfo,
    api_types::VkMemoryWin32HandlePropertiesKHR,
    api_types::VkMemoryZirconHandlePropertiesFUCHSIA,
    api_types::VkMetalSurfaceCreateInfoEXT,
    api_types::VkMicromapBuildInfoEXT,
    api_types::VkMicromapBuildSizesInfoEXT,
    api_types::VkMicromapCreateInfoEXT,
    api_types::VkMicromapVersionInfoEXT,
    api_types::VkMultisamplePropertiesEXT,
    api_types::VkMultisampledRenderToSingleSampledInfoEXT,
    api_types::VkMultiviewPerViewAttributesInfoNVX,
    api_types::VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM,
    api_types::VkMutableDescriptorTypeCreateInfoEXT,
    api_types::VkOpaqueCaptureDescriptorDataCreateInfoEXT,
    api_types::VkOpticalFlowExecuteInfoNV,
    api_types::VkOpticalFlowImageFormatInfoNV,
    api_types::VkOpticalFlowImageFormatPropertiesNV,
    api_types::VkOpticalFlowSessionCreateInfoNV,
    api_types::VkOpticalFlowSessionCreatePrivateDataInfoNV,
    api_types::VkOutOfBandQueueTypeInfoNV,
    api_types::VkPartitionedAccelerationStructureFlagsNV,
    api_types::VkPartitionedAccelerationStructureInstancesInputNV,
    api_types::VkPastPresentationTimingEXT,
    api_types::VkPastPresentationTimingInfoEXT,
    api_types::VkPastPresentationTimingPropertiesEXT,
    api_types::VkPerTileBeginInfoQCOM,
    api_types::VkPerTileEndInfoQCOM,
    api_types::VkPerfHintInfoQCOM,
    api_types::VkPerformanceConfigurationAcquireInfoINTEL,
    api_types::VkPerformanceCounterARM,
    api_types::VkPerformanceCounterDescriptionARM,
    api_types::VkPerformanceCounterDescriptionKHR,
    api_types::VkPerformanceCounterKHR,
    api_types::VkPerformanceMarkerInfoINTEL,
    api_types::VkPerformanceOverrideInfoINTEL,
    api_types::VkPerformanceQuerySubmitInfoKHR,
    api_types::VkPerformanceStreamMarkerInfoINTEL,
    api_types::VkPhysicalDevice16BitStorageFeatures,
    api_types::VkPhysicalDevice4444FormatsFeaturesEXT,
    api_types::VkPhysicalDevice8BitStorageFeatures,
    api_types::VkPhysicalDeviceASTCDecodeFeaturesEXT,
    api_types::VkPhysicalDeviceAccelerationStructureFeaturesKHR,
    api_types::VkPhysicalDeviceAccelerationStructurePropertiesKHR,
    api_types::VkPhysicalDeviceAddressBindingReportFeaturesEXT,
    api_types::VkPhysicalDeviceAmigoProfilingFeaturesSEC,
    api_types::VkPhysicalDeviceAntiLagFeaturesAMD,
    api_types::VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT,
    api_types::VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT,
    api_types::VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT,
    api_types::VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT,
    api_types::VkPhysicalDeviceBorderColorSwizzleFeaturesEXT,
    api_types::VkPhysicalDeviceBufferDeviceAddressAllocationAlignmentFeaturesVALVE,
    api_types::VkPhysicalDeviceBufferDeviceAddressAllocationAlignmentPropertiesVALVE,
    api_types::VkPhysicalDeviceBufferDeviceAddressFeatures,
    api_types::VkPhysicalDeviceBufferDeviceAddressFeaturesEXT,
    api_types::VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI,
    api_types::VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI,
    api_types::VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI,
    api_types::VkPhysicalDeviceCoherentMemoryFeaturesAMD,
    api_types::VkPhysicalDeviceColorWriteEnableFeaturesEXT,
    api_types::VkPhysicalDeviceCommandBufferInheritanceFeaturesNV,
    api_types::VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV,
    api_types::VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR,
    api_types::VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR,
    api_types::VkPhysicalDeviceConditionalRenderingFeaturesEXT,
    api_types::VkPhysicalDeviceConservativeRasterizationPropertiesEXT,
    api_types::VkPhysicalDeviceCooperativeMatrix2FeaturesNV,
    api_types::VkPhysicalDeviceCooperativeMatrix2PropertiesNV,
    api_types::VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM,
    api_types::VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV,
    api_types::VkPhysicalDeviceCooperativeMatrixFeaturesKHR,
    api_types::VkPhysicalDeviceCooperativeMatrixFeaturesNV,
    api_types::VkPhysicalDeviceCooperativeMatrixInfo2EXT,
    api_types::VkPhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT,
    api_types::VkPhysicalDeviceCooperativeMatrixPropertiesKHR,
    api_types::VkPhysicalDeviceCooperativeMatrixPropertiesNV,
    api_types::VkPhysicalDeviceCooperativeVectorFeaturesNV,
    api_types::VkPhysicalDeviceCooperativeVectorPropertiesNV,
    api_types::VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR,
    api_types::VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR,
    api_types::VkPhysicalDeviceCornerSampledImageFeaturesNV,
    api_types::VkPhysicalDeviceCoverageReductionModeFeaturesNV,
    api_types::VkPhysicalDeviceCubicClampFeaturesQCOM,
    api_types::VkPhysicalDeviceCubicWeightsFeaturesQCOM,
    api_types::VkPhysicalDeviceCustomBorderColorFeaturesEXT,
    api_types::VkPhysicalDeviceCustomBorderColorPropertiesEXT,
    api_types::VkPhysicalDeviceCustomResolveFeaturesEXT,
    api_types::VkPhysicalDeviceDataGraphFeaturesARM,
    api_types::VkPhysicalDeviceDataGraphModelFeaturesQCOM,
    api_types::VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM,
    api_types::VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM,
    api_types::VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV,
    api_types::VkPhysicalDeviceDepthBiasControlFeaturesEXT,
    api_types::VkPhysicalDeviceDepthClampControlFeaturesEXT,
    api_types::VkPhysicalDeviceDepthClampZeroOneFeaturesKHR,
    api_types::VkPhysicalDeviceDepthClipControlFeaturesEXT,
    api_types::VkPhysicalDeviceDepthClipEnableFeaturesEXT,
    api_types::VkPhysicalDeviceDepthStencilResolveProperties,
    api_types::VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT,
    api_types::VkPhysicalDeviceDescriptorBufferFeaturesEXT,
    api_types::VkPhysicalDeviceDescriptorBufferPropertiesEXT,
    api_types::VkPhysicalDeviceDescriptorBufferTensorFeaturesARM,
    api_types::VkPhysicalDeviceDescriptorBufferTensorPropertiesARM,
    api_types::VkPhysicalDeviceDescriptorIndexingFeatures,
    api_types::VkPhysicalDeviceDescriptorIndexingProperties,
    api_types::VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV,
    api_types::VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE,
    api_types::VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR,
    api_types::VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV,
    api_types::VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT,
    api_types::VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV,
    api_types::VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT,
    api_types::VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV,
    api_types::VkPhysicalDeviceDeviceMemoryReportFeaturesEXT,
    api_types::VkPhysicalDeviceDiagnosticsConfigFeaturesNV,
    api_types::VkPhysicalDeviceDiscardRectanglePropertiesEXT,
    api_types::VkPhysicalDeviceDisplacementMicromapFeaturesNV,
    api_types::VkPhysicalDeviceDisplacementMicromapPropertiesNV,
    api_types::VkPhysicalDeviceDriverProperties,
    api_types::VkPhysicalDeviceDrmPropertiesEXT,
    api_types::VkPhysicalDeviceDynamicRenderingFeatures,
    api_types::VkPhysicalDeviceDynamicRenderingLocalReadFeatures,
    api_types::VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT,
    api_types::VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM,
    api_types::VkPhysicalDeviceExclusiveScissorFeaturesNV,
    api_types::VkPhysicalDeviceExtendedDynamicState2FeaturesEXT,
    api_types::VkPhysicalDeviceExtendedDynamicState3FeaturesEXT,
    api_types::VkPhysicalDeviceExtendedDynamicState3PropertiesEXT,
    api_types::VkPhysicalDeviceExtendedDynamicStateFeaturesEXT,
    api_types::VkPhysicalDeviceExtendedFlagsFeaturesKHR,
    api_types::VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV,
    api_types::VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV,
    api_types::VkPhysicalDeviceExternalBufferInfo,
    api_types::VkPhysicalDeviceExternalFenceInfo,
    api_types::VkPhysicalDeviceExternalFormatResolveFeaturesANDROID,
    api_types::VkPhysicalDeviceExternalFormatResolvePropertiesANDROID,
    api_types::VkPhysicalDeviceExternalImageFormatInfo,
    api_types::VkPhysicalDeviceExternalMemoryHostPropertiesEXT,
    api_types::VkPhysicalDeviceExternalMemoryRDMAFeaturesNV,
    api_types::VkPhysicalDeviceExternalSemaphoreInfo,
    api_types::VkPhysicalDeviceExternalTensorInfoARM,
    api_types::VkPhysicalDeviceFaultFeaturesEXT,
    api_types::VkPhysicalDeviceFaultFeaturesKHR,
    api_types::VkPhysicalDeviceFaultPropertiesKHR,
    api_types::VkPhysicalDeviceFeatures2,
    api_types::VkPhysicalDeviceFloatControlsProperties,
    api_types::VkPhysicalDeviceFormatPackFeaturesARM,
    api_types::VkPhysicalDeviceFragmentDensityMap2FeaturesEXT,
    api_types::VkPhysicalDeviceFragmentDensityMap2PropertiesEXT,
    api_types::VkPhysicalDeviceFragmentDensityMapFeaturesEXT,
    api_types::VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE,
    api_types::VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE,
    api_types::VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT,
    api_types::VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT,
    api_types::VkPhysicalDeviceFragmentDensityMapPropertiesEXT,
    api_types::VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR,
    api_types::VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR,
    api_types::VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT,
    api_types::VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV,
    api_types::VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV,
    api_types::VkPhysicalDeviceFragmentShadingRateFeaturesKHR,
    api_types::VkPhysicalDeviceFragmentShadingRateKHR,
    api_types::VkPhysicalDeviceFragmentShadingRatePropertiesKHR,
    api_types::VkPhysicalDeviceFrameBoundaryFeaturesEXT,
    api_types::VkPhysicalDeviceGlobalPriorityQueryFeatures,
    api_types::VkPhysicalDeviceGpaFeaturesAMD,
    api_types::VkPhysicalDeviceGpaProperties2AMD,
    api_types::VkPhysicalDeviceGpaPropertiesAMD,
    api_types::VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT,
    api_types::VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT,
    api_types::VkPhysicalDeviceGroupProperties,
    api_types::VkPhysicalDeviceHdrVividFeaturesHUAWEI,
    api_types::VkPhysicalDeviceHostImageCopyFeatures,
    api_types::VkPhysicalDeviceHostImageCopyProperties,
    api_types::VkPhysicalDeviceHostQueryResetFeatures,
    api_types::VkPhysicalDeviceIDProperties,
    api_types::VkPhysicalDeviceImage2DViewOf3DFeaturesEXT,
    api_types::VkPhysicalDeviceImageAlignmentControlFeaturesMESA,
    api_types::VkPhysicalDeviceImageAlignmentControlPropertiesMESA,
    api_types::VkPhysicalDeviceImageCompressionControlFeaturesEXT,
    api_types::VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT,
    api_types::VkPhysicalDeviceImageDrmFormatModifierInfoEXT,
    api_types::VkPhysicalDeviceImageFormatInfo2,
    api_types::VkPhysicalDeviceImageProcessing2FeaturesQCOM,
    api_types::VkPhysicalDeviceImageProcessing2PropertiesQCOM,
    api_types::VkPhysicalDeviceImageProcessing3FeaturesQCOM,
    api_types::VkPhysicalDeviceImageProcessingFeaturesQCOM,
    api_types::VkPhysicalDeviceImageProcessingPropertiesQCOM,
    api_types::VkPhysicalDeviceImageRobustnessFeatures,
    api_types::VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT,
    api_types::VkPhysicalDeviceImageTilingControlFeaturesEXT,
    api_types::VkPhysicalDeviceImageViewImageFormatInfoEXT,
    api_types::VkPhysicalDeviceImageViewMinLodFeaturesEXT,
    api_types::VkPhysicalDeviceImagelessFramebufferFeatures,
    api_types::VkPhysicalDeviceIndexTypeUint8Features,
    api_types::VkPhysicalDeviceInfoPropertiesINTEL,
    api_types::VkPhysicalDeviceInheritedViewportScissorFeaturesNV,
    api_types::VkPhysicalDeviceInlineUniformBlockFeatures,
    api_types::VkPhysicalDeviceInlineUniformBlockProperties,
    api_types::VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR,
    api_types::VkPhysicalDeviceInvocationMaskFeaturesHUAWEI,
    api_types::VkPhysicalDeviceLayeredApiPropertiesKHR,
    api_types::VkPhysicalDeviceLayeredApiPropertiesListKHR,
    api_types::VkPhysicalDeviceLayeredApiVulkanPropertiesKHR,
    api_types::VkPhysicalDeviceLayeredDriverPropertiesMSFT,
    api_types::VkPhysicalDeviceLegacyDitheringFeaturesEXT,
    api_types::VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT,
    api_types::VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT,
    api_types::VkPhysicalDeviceLineRasterizationFeatures,
    api_types::VkPhysicalDeviceLineRasterizationProperties,
    api_types::VkPhysicalDeviceLinearColorAttachmentFeaturesNV,
    api_types::VkPhysicalDeviceMaintenance10FeaturesKHR,
    api_types::VkPhysicalDeviceMaintenance10PropertiesKHR,
    api_types::VkPhysicalDeviceMaintenance11FeaturesKHR,
    api_types::VkPhysicalDeviceMaintenance3Properties,
    api_types::VkPhysicalDeviceMaintenance4Features,
    api_types::VkPhysicalDeviceMaintenance4Properties,
    api_types::VkPhysicalDeviceMaintenance5Features,
    api_types::VkPhysicalDeviceMaintenance5Properties,
    api_types::VkPhysicalDeviceMaintenance6Features,
    api_types::VkPhysicalDeviceMaintenance6Properties,
    api_types::VkPhysicalDeviceMaintenance7FeaturesKHR,
    api_types::VkPhysicalDeviceMaintenance7PropertiesKHR,
    api_types::VkPhysicalDeviceMaintenance8FeaturesKHR,
    api_types::VkPhysicalDeviceMaintenance9FeaturesKHR,
    api_types::VkPhysicalDeviceMaintenance9PropertiesKHR,
    api_types::VkPhysicalDeviceMapMemoryPlacedFeaturesEXT,
    api_types::VkPhysicalDeviceMapMemoryPlacedPropertiesEXT,
    api_types::VkPhysicalDeviceMemoryBudgetPropertiesEXT,
    api_types::VkPhysicalDeviceMemoryDecompressionFeaturesEXT,
    api_types::VkPhysicalDeviceMemoryDecompressionPropertiesEXT,
    api_types::VkPhysicalDeviceMemoryPriorityFeaturesEXT,
    api_types::VkPhysicalDeviceMemoryProperties2,
    api_types::VkPhysicalDeviceMeshShaderFeaturesEXT,
    api_types::VkPhysicalDeviceMeshShaderFeaturesNV,
    api_types::VkPhysicalDeviceMeshShaderPropertiesEXT,
    api_types::VkPhysicalDeviceMeshShaderPropertiesNV,
    api_types::VkPhysicalDeviceMultiDrawFeaturesEXT,
    api_types::VkPhysicalDeviceMultiDrawPropertiesEXT,
    api_types::VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT,
    api_types::VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT,
    api_types::VkPhysicalDeviceMultiviewFeatures,
    api_types::VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX,
    api_types::VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM,
    api_types::VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM,
    api_types::VkPhysicalDeviceMultiviewProperties,
    api_types::VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT,
    api_types::VkPhysicalDeviceNestedCommandBufferFeaturesEXT,
    api_types::VkPhysicalDeviceNestedCommandBufferPropertiesEXT,
    api_types::VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT,
    api_types::VkPhysicalDeviceOpacityMicromapFeaturesEXT,
    api_types::VkPhysicalDeviceOpacityMicromapFeaturesKHR,
    api_types::VkPhysicalDeviceOpacityMicromapPropertiesEXT,
    api_types::VkPhysicalDeviceOpacityMicromapPropertiesKHR,
    api_types::VkPhysicalDeviceOpticalFlowFeaturesNV,
    api_types::VkPhysicalDeviceOpticalFlowPropertiesNV,
    api_types::VkPhysicalDevicePCIBusInfoPropertiesEXT,
    api_types::VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT,
    api_types::VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV,
    api_types::VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV,
    api_types::VkPhysicalDevicePerStageDescriptorSetFeaturesNV,
    api_types::VkPhysicalDevicePerformanceCountersByRegionFeaturesARM,
    api_types::VkPhysicalDevicePerformanceCountersByRegionPropertiesARM,
    api_types::VkPhysicalDevicePerformanceQueryFeaturesKHR,
    api_types::VkPhysicalDevicePerformanceQueryPropertiesKHR,
    api_types::VkPhysicalDevicePipelineBinaryFeaturesKHR,
    api_types::VkPhysicalDevicePipelineBinaryPropertiesKHR,
    api_types::VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC,
    api_types::VkPhysicalDevicePipelineCreationCacheControlFeatures,
    api_types::VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR,
    api_types::VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesKHR,
    api_types::VkPhysicalDevicePipelineOpacityMicromapFeaturesARM,
    api_types::VkPhysicalDevicePipelineProtectedAccessFeatures,
    api_types::VkPhysicalDevicePipelineRobustnessFeatures,
    api_types::VkPhysicalDevicePipelineRobustnessProperties,
    api_types::VkPhysicalDevicePointClippingProperties,
    api_types::VkPhysicalDevicePortabilitySubsetFeaturesKHR,
    api_types::VkPhysicalDevicePortabilitySubsetPropertiesKHR,
    api_types::VkPhysicalDevicePresentBarrierFeaturesNV,
    api_types::VkPhysicalDevicePresentId2FeaturesKHR,
    api_types::VkPhysicalDevicePresentIdFeaturesKHR,
    api_types::VkPhysicalDevicePresentMeteringFeaturesNV,
    api_types::VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR,
    api_types::VkPhysicalDevicePresentTimingFeaturesEXT,
    api_types::VkPhysicalDevicePresentWait2FeaturesKHR,
    api_types::VkPhysicalDevicePresentWaitFeaturesKHR,
    api_types::VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT,
    api_types::VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT,
    api_types::VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT,
    api_types::VkPhysicalDevicePrivateDataBaseHandleFeaturesNV,
    api_types::VkPhysicalDevicePrivateDataFeatures,
    api_types::VkPhysicalDeviceProperties2,
    api_types::VkPhysicalDeviceProtectedMemoryFeatures,
    api_types::VkPhysicalDeviceProtectedMemoryProperties,
    api_types::VkPhysicalDeviceProvokingVertexFeaturesEXT,
    api_types::VkPhysicalDeviceProvokingVertexPropertiesEXT,
    api_types::VkPhysicalDevicePushConstantBankFeaturesNV,
    api_types::VkPhysicalDevicePushConstantBankPropertiesNV,
    api_types::VkPhysicalDevicePushDescriptorProperties,
    api_types::VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM,
    api_types::VkPhysicalDeviceQueuePerfHintFeaturesQCOM,
    api_types::VkPhysicalDeviceQueuePerfHintPropertiesQCOM,
    api_types::VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT,
    api_types::VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT,
    api_types::VkPhysicalDeviceRawAccessChainsFeaturesNV,
    api_types::VkPhysicalDeviceRayQueryFeaturesKHR,
    api_types::VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT,
    api_types::VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV,
    api_types::VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT,
    api_types::VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV,
    api_types::VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV,
    api_types::VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR,
    api_types::VkPhysicalDeviceRayTracingMotionBlurFeaturesNV,
    api_types::VkPhysicalDeviceRayTracingPipelineFeaturesKHR,
    api_types::VkPhysicalDeviceRayTracingPipelinePropertiesKHR,
    api_types::VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR,
    api_types::VkPhysicalDeviceRayTracingPropertiesNV,
    api_types::VkPhysicalDeviceRayTracingValidationFeaturesNV,
    api_types::VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG,
    api_types::VkPhysicalDeviceRenderPassStripedFeaturesARM,
    api_types::VkPhysicalDeviceRenderPassStripedPropertiesARM,
    api_types::VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV,
    api_types::VkPhysicalDeviceRobustness2FeaturesKHR,
    api_types::VkPhysicalDeviceRobustness2PropertiesKHR,
    api_types::VkPhysicalDeviceSampleLocationsPropertiesEXT,
    api_types::VkPhysicalDeviceSamplerFilterMinmaxProperties,
    api_types::VkPhysicalDeviceSamplerYcbcrConversionFeatures,
    api_types::VkPhysicalDeviceScalarBlockLayoutFeatures,
    api_types::VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM,
    api_types::VkPhysicalDeviceSchedulingControlsFeaturesARM,
    api_types::VkPhysicalDeviceSchedulingControlsPropertiesARM,
    api_types::VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures,
    api_types::VkPhysicalDeviceShader64BitIndexingFeaturesEXT,
    api_types::VkPhysicalDeviceShaderAbortFeaturesKHR,
    api_types::VkPhysicalDeviceShaderAbortPropertiesKHR,
    api_types::VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV,
    api_types::VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT,
    api_types::VkPhysicalDeviceShaderAtomicFloatFeaturesEXT,
    api_types::VkPhysicalDeviceShaderAtomicInt64Features,
    api_types::VkPhysicalDeviceShaderBfloat16FeaturesKHR,
    api_types::VkPhysicalDeviceShaderClockFeaturesKHR,
    api_types::VkPhysicalDeviceShaderConstantDataFeaturesKHR,
    api_types::VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM,
    api_types::VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM,
    api_types::VkPhysicalDeviceShaderCoreProperties2AMD,
    api_types::VkPhysicalDeviceShaderCorePropertiesAMD,
    api_types::VkPhysicalDeviceShaderCorePropertiesARM,
    api_types::VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures,
    api_types::VkPhysicalDeviceShaderDrawParametersFeatures,
    api_types::VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD,
    api_types::VkPhysicalDeviceShaderExpectAssumeFeatures,
    api_types::VkPhysicalDeviceShaderFloat16Int8Features,
    api_types::VkPhysicalDeviceShaderFloat8FeaturesEXT,
    api_types::VkPhysicalDeviceShaderFloatControls2Features,
    api_types::VkPhysicalDeviceShaderFmaFeaturesKHR,
    api_types::VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT,
    api_types::VkPhysicalDeviceShaderImageFootprintFeaturesNV,
    api_types::VkPhysicalDeviceShaderIntegerDotProductFeatures,
    api_types::VkPhysicalDeviceShaderIntegerDotProductProperties,
    api_types::VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL,
    api_types::VkPhysicalDeviceShaderLongVectorFeaturesEXT,
    api_types::VkPhysicalDeviceShaderLongVectorPropertiesEXT,
    api_types::VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR,
    api_types::VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE,
    api_types::VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT,
    api_types::VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT,
    api_types::VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM,
    api_types::VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM,
    api_types::VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT,
    api_types::VkPhysicalDeviceShaderObjectFeaturesEXT,
    api_types::VkPhysicalDeviceShaderObjectPropertiesEXT,
    api_types::VkPhysicalDeviceShaderQuadControlFeaturesKHR,
    api_types::VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR,
    api_types::VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT,
    api_types::VkPhysicalDeviceShaderSMBuiltinsFeaturesNV,
    api_types::VkPhysicalDeviceShaderSMBuiltinsPropertiesNV,
    api_types::VkPhysicalDeviceShaderSplitBarrierFeaturesEXT,
    api_types::VkPhysicalDeviceShaderSplitBarrierPropertiesEXT,
    api_types::VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures,
    api_types::VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT,
    api_types::VkPhysicalDeviceShaderSubgroupRotateFeatures,
    api_types::VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR,
    api_types::VkPhysicalDeviceShaderTerminateInvocationFeatures,
    api_types::VkPhysicalDeviceShaderTileImageFeaturesEXT,
    api_types::VkPhysicalDeviceShaderTileImagePropertiesEXT,
    api_types::VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT,
    api_types::VkPhysicalDeviceShaderUntypedPointersFeaturesKHR,
    api_types::VkPhysicalDeviceShadingRateImageFeaturesNV,
    api_types::VkPhysicalDeviceShadingRateImagePropertiesNV,
    api_types::VkPhysicalDeviceSparseImageFormatInfo2,
    api_types::VkPhysicalDeviceSubgroupProperties,
    api_types::VkPhysicalDeviceSubgroupSizeControlFeatures,
    api_types::VkPhysicalDeviceSubgroupSizeControlProperties,
    api_types::VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT,
    api_types::VkPhysicalDeviceSurfaceInfo2KHR,
    api_types::VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR,
    api_types::VkPhysicalDeviceSynchronization2Features,
    api_types::VkPhysicalDeviceTensorFeaturesARM,
    api_types::VkPhysicalDeviceTensorPropertiesARM,
    api_types::VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT,
    api_types::VkPhysicalDeviceTexelBufferAlignmentProperties,
    api_types::VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT,
    api_types::VkPhysicalDeviceTextureCompressionASTCHDRFeatures,
    api_types::VkPhysicalDeviceThrottleHintFeaturesSEC,
    api_types::VkPhysicalDeviceTileMemoryHeapFeaturesQCOM,
    api_types::VkPhysicalDeviceTileMemoryHeapPropertiesQCOM,
    api_types::VkPhysicalDeviceTilePropertiesFeaturesQCOM,
    api_types::VkPhysicalDeviceTileShadingFeaturesQCOM,
    api_types::VkPhysicalDeviceTileShadingPropertiesQCOM,
    api_types::VkPhysicalDeviceTimelineSemaphoreFeatures,
    api_types::VkPhysicalDeviceTimelineSemaphoreProperties,
    api_types::VkPhysicalDeviceToolProperties,
    api_types::VkPhysicalDeviceTransformFeedbackFeaturesEXT,
    api_types::VkPhysicalDeviceTransformFeedbackPropertiesEXT,
    api_types::VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR,
    api_types::VkPhysicalDeviceUniformBufferStandardLayoutFeatures,
    api_types::VkPhysicalDeviceVariablePointersFeatures,
    api_types::VkPhysicalDeviceVertexAttributeDivisorFeatures,
    api_types::VkPhysicalDeviceVertexAttributeDivisorProperties,
    api_types::VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT,
    api_types::VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT,
    api_types::VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT,
    api_types::VkPhysicalDeviceVideoDecodeVP9FeaturesKHR,
    api_types::VkPhysicalDeviceVideoEncodeAV1FeaturesKHR,
    api_types::VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR,
    api_types::VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR,
    api_types::VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR,
    api_types::VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR,
    api_types::VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE,
    api_types::VkPhysicalDeviceVideoFormatInfoKHR,
    api_types::VkPhysicalDeviceVideoMaintenance1FeaturesKHR,
    api_types::VkPhysicalDeviceVulkan11Features,
    api_types::VkPhysicalDeviceVulkan11Properties,
    api_types::VkPhysicalDeviceVulkan12Features,
    api_types::VkPhysicalDeviceVulkan12Properties,
    api_types::VkPhysicalDeviceVulkan13Features,
    api_types::VkPhysicalDeviceVulkan13Properties,
    api_types::VkPhysicalDeviceVulkan14Features,
    api_types::VkPhysicalDeviceVulkan14Properties,
    api_types::VkPhysicalDeviceVulkanMemoryModelFeatures,
    api_types::VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR,
    api_types::VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT,
    api_types::VkPhysicalDeviceYcbcrDegammaFeaturesQCOM,
    api_types::VkPhysicalDeviceYcbcrImageArraysFeaturesEXT,
    api_types::VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT,
    api_types::VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures,
    api_types::VkPipelineBinaryCreateInfoKHR,
    api_types::VkPipelineBinaryDataInfoKHR,
    api_types::VkPipelineBinaryHandlesInfoKHR,
    api_types::VkPipelineBinaryInfoKHR,
    api_types::VkPipelineBinaryKeyKHR,
    api_types::VkPipelineCacheCreateInfo,
    api_types::VkPipelineColorBlendAdvancedStateCreateInfoEXT,
    api_types::VkPipelineColorBlendStateCreateInfo,
    api_types::VkPipelineColorWriteCreateInfoEXT,
    api_types::VkPipelineCompilerControlCreateInfoAMD,
    api_types::VkPipelineCoverageModulationStateCreateInfoNV,
    api_types::VkPipelineCoverageReductionStateCreateInfoNV,
    api_types::VkPipelineCoverageToColorStateCreateInfoNV,
    api_types::VkPipelineCreateFlags2CreateInfo,
    api_types::VkPipelineCreateInfoKHR,
    api_types::VkPipelineCreationFeedbackCreateInfo,
    api_types::VkPipelineDepthStencilStateCreateInfo,
    api_types::VkPipelineDiscardRectangleStateCreateInfoEXT,
    api_types::VkPipelineDynamicStateCreateInfo,
    api_types::VkPipelineExecutableInfoKHR,
    api_types::VkPipelineExecutableInternalRepresentationKHR,
    api_types::VkPipelineExecutablePropertiesKHR,
    api_types::VkPipelineExecutableStatisticKHR,
    api_types::VkPipelineFragmentDensityMapLayeredCreateInfoVALVE,
    api_types::VkPipelineFragmentShadingRateEnumStateCreateInfoNV,
    api_types::VkPipelineFragmentShadingRateStateCreateInfoKHR,
    api_types::VkPipelineIndirectDeviceAddressInfoNV,
    api_types::VkPipelineInfoKHR,
    api_types::VkPipelineInputAssemblyStateCreateInfo,
    api_types::VkPipelineLayoutCreateInfo,
    api_types::VkPipelineLibraryCreateInfoKHR,
    api_types::VkPipelineMultisampleStateCreateInfo,
    api_types::VkPipelineRasterizationConservativeStateCreateInfoEXT,
    api_types::VkPipelineRasterizationDepthClipStateCreateInfoEXT,
    api_types::VkPipelineRasterizationLineStateCreateInfo,
    api_types::VkPipelineRasterizationProvokingVertexStateCreateInfoEXT,
    api_types::VkPipelineRasterizationStateCreateInfo,
    api_types::VkPipelineRasterizationStateRasterizationOrderAMD,
    api_types::VkPipelineRasterizationStateStreamCreateInfoEXT,
    api_types::VkPipelineRenderingCreateInfo,
    api_types::VkPipelineRepresentativeFragmentTestStateCreateInfoNV,
    api_types::VkPipelineRobustnessCreateInfo,
    api_types::VkPipelineSampleLocationsStateCreateInfoEXT,
    api_types::VkPipelineShaderStageCreateInfo,
    api_types::VkPipelineShaderStageModuleIdentifierCreateInfoEXT,
    api_types::VkPipelineShaderStageRequiredSubgroupSizeCreateInfo,
    api_types::VkPipelineTessellationDomainOriginStateCreateInfo,
    api_types::VkPipelineTessellationStateCreateInfo,
    api_types::VkPipelineVertexInputDivisorStateCreateInfo,
    api_types::VkPipelineVertexInputStateCreateInfo,
    api_types::VkPipelineViewportCoarseSampleOrderStateCreateInfoNV,
    api_types::VkPipelineViewportDepthClampControlCreateInfoEXT,
    api_types::VkPipelineViewportDepthClipControlCreateInfoEXT,
    api_types::VkPipelineViewportExclusiveScissorStateCreateInfoNV,
    api_types::VkPipelineViewportShadingRateImageStateCreateInfoNV,
    api_types::VkPipelineViewportStateCreateInfo,
    api_types::VkPipelineViewportSwizzleStateCreateInfoNV,
    api_types::VkPipelineViewportWScalingStateCreateInfoNV,
    api_types::VkPresentFrameTokenGGP,
    api_types::VkPresentId2KHR,
    api_types::VkPresentIdKHR,
    api_types::VkPresentInfoKHR,
    api_types::VkPresentRegionsKHR,
    api_types::VkPresentTimesInfoGOOGLE,
    api_types::VkPresentTimingInfoEXT,
    api_types::VkPresentTimingSurfaceCapabilitiesEXT,
    api_types::VkPresentTimingsInfoEXT,
    api_types::VkPresentWait2InfoKHR,
    api_types::VkPrivateDataSlotCreateInfo,
    api_types::VkProtectedSubmitInfo,
    api_types::VkPushConstantBankInfoNV,
    api_types::VkPushConstantsInfo,
    api_types::VkPushDescriptorSetInfo,
    api_types::VkPushDescriptorSetWithTemplateInfo,
    api_types::VkQueryPoolCreateInfo,
    api_types::VkQueryPoolPerformanceCreateInfoKHR,
    api_types::VkQueryPoolPerformanceQueryCreateInfoINTEL,
    api_types::VkQueryPoolVideoEncodeFeedbackCreateInfoKHR,
    api_types::VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR,
    api_types::VkQueueFamilyCheckpointProperties2NV,
    api_types::VkQueueFamilyCheckpointPropertiesNV,
    api_types::VkQueueFamilyDataGraphOpticalFlowPropertiesARM,
    api_types::VkQueueFamilyDataGraphProcessingEnginePropertiesARM,
    api_types::VkQueueFamilyDataGraphPropertiesARM,
    api_types::VkQueueFamilyGlobalPriorityProperties,
    api_types::VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR,
    api_types::VkQueueFamilyOwnershipTransferPropertiesKHR,
    api_types::VkQueueFamilyProperties2,
    api_types::VkQueueFamilyQueryResultStatusPropertiesKHR,
    api_types::VkQueueFamilyVideoPropertiesKHR,
    api_types::VkRayTracingPipelineCreateInfoKHR,
    api_types::VkRayTracingPipelineCreateInfoNV,
    api_types::VkRayTracingPipelineInterfaceCreateInfoKHR,
    api_types::VkRayTracingShaderGroupCreateInfoKHR,
    api_types::VkRayTracingShaderGroupCreateInfoNV,
    api_types::VkReleaseCapturedPipelineDataInfoKHR,
    api_types::VkReleaseSwapchainImagesInfoKHR,
    api_types::VkRenderPassAttachmentBeginInfo,
    api_types::VkRenderPassBeginInfo,
    api_types::VkRenderPassCreateInfo,
    api_types::VkRenderPassCreateInfo2,
    api_types::VkRenderPassCreationControlEXT,
    api_types::VkRenderPassCreationFeedbackCreateInfoEXT,
    api_types::VkRenderPassFragmentDensityMapCreateInfoEXT,
    api_types::VkRenderPassFragmentDensityMapOffsetEndInfoEXT,
    api_types::VkRenderPassInputAttachmentAspectCreateInfo,
    api_types::VkRenderPassMultiviewCreateInfo,
    api_types::VkRenderPassPerformanceCountersByRegionBeginInfoARM,
    api_types::VkRenderPassSampleLocationsBeginInfoEXT,
    api_types::VkRenderPassStripeBeginInfoARM,
    api_types::VkRenderPassStripeInfoARM,
    api_types::VkRenderPassStripeSubmitInfoARM,
    api_types::VkRenderPassSubpassFeedbackCreateInfoEXT,
    api_types::VkRenderPassTileShadingCreateInfoQCOM,
    api_types::VkRenderPassTransformBeginInfoQCOM,
    api_types::VkRenderingAreaInfo,
    api_types::VkRenderingAttachmentFlagsInfoKHR,
    api_types::VkRenderingAttachmentInfo,
    api_types::VkRenderingAttachmentLocationInfo,
    api_types::VkRenderingEndInfoKHR,
    api_types::VkRenderingFragmentDensityMapAttachmentInfoEXT,
    api_types::VkRenderingFragmentShadingRateAttachmentInfoKHR,
    api_types::VkRenderingInfo,
    api_types::VkRenderingInputAttachmentIndexInfo,
    api_types::VkResolveImageInfo2,
    api_types::VkResolveImageModeInfoKHR,
    api_types::VkSampleLocationsInfoEXT,
    api_types::VkSamplerBlockMatchWindowCreateInfoQCOM,
    api_types::VkSamplerBorderColorComponentMappingCreateInfoEXT,
    api_types::VkSamplerCaptureDescriptorDataInfoEXT,
    api_types::VkSamplerCreateInfo,
    api_types::VkSamplerCubicWeightsCreateInfoQCOM,
    api_types::VkSamplerCustomBorderColorCreateInfoEXT,
    api_types::VkSamplerReductionModeCreateInfo,
    api_types::VkSamplerYcbcrConversionCreateInfo,
    api_types::VkSamplerYcbcrConversionImageFormatProperties,
    api_types::VkSamplerYcbcrConversionInfo,
    api_types::VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM,
    api_types::VkScreenSurfaceCreateInfoQNX,
    api_types::VkSemaphoreCreateInfo,
    api_types::VkSemaphoreGetFdInfoKHR,
    api_types::VkSemaphoreGetWin32HandleInfoKHR,
    api_types::VkSemaphoreGetZirconHandleInfoFUCHSIA,
    api_types::VkSemaphoreSignalInfo,
    api_types::VkSemaphoreSubmitInfo,
    api_types::VkSemaphoreTypeCreateInfo,
    api_types::VkSemaphoreWaitInfo,
    api_types::VkSetDescriptorBufferOffsetsInfoEXT,
    api_types::VkSetLatencyMarkerInfoNV,
    api_types::VkSetPresentConfigNV,
    api_types::VkShaderCreateInfoEXT,
    api_types::VkShaderModuleCreateInfo,
    api_types::VkShaderModuleIdentifierEXT,
    api_types::VkShaderModuleValidationCacheCreateInfoEXT,
    api_types::VkSharedPresentSurfaceCapabilities2KHR,
    api_types::VkSharedPresentSurfaceCapabilitiesKHR,
    api_types::VkSparseImageFormatProperties2,
    api_types::VkSparseImageMemoryRequirements2,
    api_types::VkStreamDescriptorSurfaceCreateInfoGGP,
    api_types::VkSubmitInfo,
    api_types::VkSubmitInfo2,
    api_types::VkSubpassBeginInfo,
    api_types::VkSubpassDependency2,
    api_types::VkSubpassDescription2,
    api_types::VkSubpassDescriptionDepthStencilResolve,
    api_types::VkSubpassEndInfo,
    api_types::VkSubpassResolvePerformanceQueryEXT,
    api_types::VkSubresourceHostMemcpySize,
    api_types::VkSubresourceLayout2,
    api_types::VkSurfaceCapabilities2EXT,
    api_types::VkSurfaceCapabilities2KHR,
    api_types::VkSurfaceCapabilitiesFullScreenExclusiveEXT,
    api_types::VkSurfaceCapabilitiesPresentBarrierNV,
    api_types::VkSurfaceCapabilitiesPresentId2KHR,
    api_types::VkSurfaceCapabilitiesPresentWait2KHR,
    api_types::VkSurfaceFormat2KHR,
    api_types::VkSurfaceFullScreenExclusiveInfoEXT,
    api_types::VkSurfaceFullScreenExclusiveWin32InfoEXT,
    api_types::VkSurfacePresentModeCompatibilityKHR,
    api_types::VkSurfacePresentModeKHR,
    api_types::VkSurfacePresentScalingCapabilitiesKHR,
    api_types::VkSurfaceProtectedCapabilitiesKHR,
    api_types::VkSwapchainCalibratedTimestampInfoEXT,
    api_types::VkSwapchainCounterCreateInfoEXT,
    api_types::VkSwapchainCreateInfoKHR,
    api_types::VkSwapchainDisplayNativeHdrCreateInfoAMD,
    api_types::VkSwapchainFlagsSurfaceCapabilitiesEXT,
    api_types::VkSwapchainLatencyCreateInfoNV,
    api_types::VkSwapchainPresentBarrierCreateInfoNV,
    api_types::VkSwapchainPresentFenceInfoKHR,
    api_types::VkSwapchainPresentModeInfoKHR,
    api_types::VkSwapchainPresentModesCreateInfoKHR,
    api_types::VkSwapchainPresentScalingCreateInfoKHR,
    api_types::VkSwapchainTimeDomainPropertiesEXT,
    api_types::VkSwapchainTimingPropertiesEXT,
    api_types::VkTensorCaptureDescriptorDataInfoARM,
    api_types::VkTensorCopyARM,
    api_types::VkTensorCreateInfoARM,
    api_types::VkTensorDependencyInfoARM,
    api_types::VkTensorDescriptionARM,
    api_types::VkTensorExplicitTilingFormatPropertiesARM,
    api_types::VkTensorFormatPropertiesARM,
    api_types::VkTensorMemoryBarrierARM,
    api_types::VkTensorMemoryRequirementsInfoARM,
    api_types::VkTensorRollingBackingCreateInfoARM,
    api_types::VkTensorViewCaptureDescriptorDataInfoARM,
    api_types::VkTensorViewCreateInfoARM,
    api_types::VkTextureLODGatherFormatPropertiesAMD,
    api_types::VkThrottleHintSubmitInfoSEC,
    api_types::VkTileMemoryBindInfoQCOM,
    api_types::VkTileMemoryRequirementsQCOM,
    api_types::VkTileMemorySizeInfoQCOM,
    api_types::VkTilePropertiesQCOM,
    api_types::VkTimelineSemaphoreSubmitInfo,
    api_types::VkValidationCacheCreateInfoEXT,
    api_types::VkValidationFeaturesEXT,
    api_types::VkValidationFlagsEXT,
    api_types::VkVertexInputAttributeDescription2EXT,
    api_types::VkVertexInputBindingDescription2EXT,
    api_types::VkViSurfaceCreateInfoNN,
    api_types::VkVideoBeginCodingInfoKHR,
    api_types::VkVideoCapabilitiesKHR,
    api_types::VkVideoCodingControlInfoKHR,
    api_types::VkVideoDecodeAV1CapabilitiesKHR,
    api_types::VkVideoDecodeAV1DpbSlotInfoKHR,
    api_types::VkVideoDecodeAV1PictureInfoKHR,
    api_types::VkVideoDecodeAV1ProfileInfoKHR,
    api_types::VkVideoDecodeAV1SessionParametersCreateInfoKHR,
    api_types::VkVideoDecodeCapabilitiesKHR,
    api_types::VkVideoDecodeH264CapabilitiesKHR,
    api_types::VkVideoDecodeH264DpbSlotInfoKHR,
    api_types::VkVideoDecodeH264PictureInfoKHR,
    api_types::VkVideoDecodeH264ProfileInfoKHR,
    api_types::VkVideoDecodeH264SessionParametersAddInfoKHR,
    api_types::VkVideoDecodeH264SessionParametersCreateInfoKHR,
    api_types::VkVideoDecodeInfoKHR,
    api_types::VkVideoDecodeUsageInfoKHR,
    api_types::VkVideoDecodeVP9CapabilitiesKHR,
    api_types::VkVideoDecodeVP9PictureInfoKHR,
    api_types::VkVideoDecodeVP9ProfileInfoKHR,
    api_types::VkVideoEncodeAV1CapabilitiesKHR,
    api_types::VkVideoEncodeAV1DpbSlotInfoKHR,
    api_types::VkVideoEncodeAV1GopRemainingFrameInfoKHR,
    api_types::VkVideoEncodeAV1PictureInfoKHR,
    api_types::VkVideoEncodeAV1ProfileInfoKHR,
    api_types::VkVideoEncodeAV1QualityLevelPropertiesKHR,
    api_types::VkVideoEncodeAV1QuantizationMapCapabilitiesKHR,
    api_types::VkVideoEncodeAV1RateControlInfoKHR,
    api_types::VkVideoEncodeAV1RateControlLayerInfoKHR,
    api_types::VkVideoEncodeAV1SessionCreateInfoKHR,
    api_types::VkVideoEncodeAV1SessionParametersCreateInfoKHR,
    api_types::VkVideoEncodeCapabilitiesKHR,
    api_types::VkVideoEncodeFeedback2CapabilitiesKHR,
    api_types::VkVideoEncodeH264CapabilitiesKHR,
    api_types::VkVideoEncodeH264DpbSlotInfoKHR,
    api_types::VkVideoEncodeH264GopRemainingFrameInfoKHR,
    api_types::VkVideoEncodeH264NaluSliceInfoKHR,
    api_types::VkVideoEncodeH264PictureInfoKHR,
    api_types::VkVideoEncodeH264ProfileInfoKHR,
    api_types::VkVideoEncodeH264QualityLevelPropertiesKHR,
    api_types::VkVideoEncodeH264QuantizationMapCapabilitiesKHR,
    api_types::VkVideoEncodeH264RateControlInfoKHR,
    api_types::VkVideoEncodeH264RateControlLayerInfoKHR,
    api_types::VkVideoEncodeH264SessionCreateInfoKHR,
    api_types::VkVideoEncodeH264SessionParametersAddInfoKHR,
    api_types::VkVideoEncodeH264SessionParametersCreateInfoKHR,
    api_types::VkVideoEncodeH264SessionParametersFeedbackInfoKHR,
    api_types::VkVideoEncodeH264SessionParametersGetInfoKHR,
    api_types::VkVideoEncodeH265QuantizationMapCapabilitiesKHR,
    api_types::VkVideoEncodeInfoKHR,
    api_types::VkVideoEncodeIntraRefreshCapabilitiesKHR,
    api_types::VkVideoEncodeIntraRefreshInfoKHR,
    api_types::VkVideoEncodeProfileRgbConversionInfoVALVE,
    api_types::VkVideoEncodeQualityLevelInfoKHR,
    api_types::VkVideoEncodeQualityLevelPropertiesKHR,
    api_types::VkVideoEncodeQuantizationMapCapabilitiesKHR,
    api_types::VkVideoEncodeQuantizationMapInfoKHR,
    api_types::VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR,
    api_types::VkVideoEncodeRateControlInfoKHR,
    api_types::VkVideoEncodeRateControlLayerInfoKHR,
    api_types::VkVideoEncodeRgbConversionCapabilitiesVALVE,
    api_types::VkVideoEncodeSessionIntraRefreshCreateInfoKHR,
    api_types::VkVideoEncodeSessionParametersFeedbackInfoKHR,
    api_types::VkVideoEncodeSessionParametersGetInfoKHR,
    api_types::VkVideoEncodeSessionRgbConversionCreateInfoVALVE,
    api_types::VkVideoEncodeUsageInfoKHR,
    api_types::VkVideoEndCodingInfoKHR,
    api_types::VkVideoFormatAV1QuantizationMapPropertiesKHR,
    api_types::VkVideoFormatH265QuantizationMapPropertiesKHR,
    api_types::VkVideoFormatPropertiesKHR,
    api_types::VkVideoFormatQuantizationMapPropertiesKHR,
    api_types::VkVideoInlineQueryInfoKHR,
    api_types::VkVideoPictureResourceInfoKHR,
    api_types::VkVideoProfileInfoKHR,
    api_types::VkVideoProfileListInfoKHR,
    api_types::VkVideoReferenceIntraRefreshInfoKHR,
    api_types::VkVideoReferenceSlotInfoKHR,
    api_types::VkVideoSessionCreateInfoKHR,
    api_types::VkVideoSessionMemoryRequirementsKHR,
    api_types::VkVideoSessionParametersCreateInfoKHR,
    api_types::VkVideoSessionParametersUpdateInfoKHR,
    api_types::VkWaylandSurfaceCreateInfoKHR,
    api_types::VkWin32KeyedMutexAcquireReleaseInfoKHR,
    api_types::VkWin32KeyedMutexAcquireReleaseInfoNV,
    api_types::VkWin32SurfaceCreateInfoKHR,
    api_types::VkWriteDescriptorSet,
    api_types::VkWriteDescriptorSetAccelerationStructureKHR,
    api_types::VkWriteDescriptorSetAccelerationStructureNV,
    api_types::VkWriteDescriptorSetInlineUniformBlock,
    api_types::VkWriteDescriptorSetPartitionedAccelerationStructureNV,
    api_types::VkWriteDescriptorSetTensorARM,
    api_types::VkWriteIndirectExecutionSetPipelineEXT,
    api_types::VkWriteIndirectExecutionSetShaderEXT,
    api_types::VkXcbSurfaceCreateInfoKHR,
    api_types::VkXlibSurfaceCreateInfoKHR>;

GFXRECON_END_NAMESPACE(catalog)
GFXRECON_END_NAMESPACE(vulkan)

// Command tags. A command tag is a schema key and a traits key. It carries no members of its own.
GFXRECON_BEGIN_NAMESPACE(vulkan)
GFXRECON_BEGIN_NAMESPACE(commands)
struct CreateInstance {};
struct DestroyInstance {};
struct EnumeratePhysicalDevices {};
struct GetPhysicalDeviceFeatures {};
struct GetPhysicalDeviceFormatProperties {};
struct GetPhysicalDeviceImageFormatProperties {};
struct GetPhysicalDeviceProperties {};
struct GetPhysicalDeviceQueueFamilyProperties {};
struct GetPhysicalDeviceMemoryProperties {};
struct CreateDevice {};
struct DestroyDevice {};
struct GetDeviceQueue {};
struct QueueSubmit {};
struct QueueWaitIdle {};
struct DeviceWaitIdle {};
struct AllocateMemory {};
struct FreeMemory {};
struct MapMemory {};
struct UnmapMemory {};
struct FlushMappedMemoryRanges {};
struct InvalidateMappedMemoryRanges {};
struct GetDeviceMemoryCommitment {};
struct BindBufferMemory {};
struct BindImageMemory {};
struct GetBufferMemoryRequirements {};
struct GetImageMemoryRequirements {};
struct GetImageSparseMemoryRequirements {};
struct GetPhysicalDeviceSparseImageFormatProperties {};
struct QueueBindSparse {};
struct CreateFence {};
struct DestroyFence {};
struct ResetFences {};
struct GetFenceStatus {};
struct WaitForFences {};
struct CreateSemaphore {};
struct DestroySemaphore {};
struct CreateQueryPool {};
struct DestroyQueryPool {};
struct GetQueryPoolResults {};
struct CreateBuffer {};
struct DestroyBuffer {};
struct CreateImage {};
struct DestroyImage {};
struct GetImageSubresourceLayout {};
struct CreateImageView {};
struct DestroyImageView {};
struct CreateCommandPool {};
struct DestroyCommandPool {};
struct ResetCommandPool {};
struct AllocateCommandBuffers {};
struct FreeCommandBuffers {};
struct BeginCommandBuffer {};
struct EndCommandBuffer {};
struct ResetCommandBuffer {};
struct CmdCopyBuffer {};
struct CmdCopyImage {};
struct CmdCopyBufferToImage {};
struct CmdCopyImageToBuffer {};
struct CmdUpdateBuffer {};
struct CmdFillBuffer {};
struct CmdPipelineBarrier {};
struct CmdBeginQuery {};
struct CmdEndQuery {};
struct CmdResetQueryPool {};
struct CmdWriteTimestamp {};
struct CmdCopyQueryPoolResults {};
struct CmdExecuteCommands {};
struct CreateEvent {};
struct DestroyEvent {};
struct GetEventStatus {};
struct SetEvent {};
struct ResetEvent {};
struct CreateBufferView {};
struct DestroyBufferView {};
struct CreateShaderModule {};
struct DestroyShaderModule {};
struct CreatePipelineCache {};
struct DestroyPipelineCache {};
struct GetPipelineCacheData {};
struct MergePipelineCaches {};
struct CreateComputePipelines {};
struct DestroyPipeline {};
struct CreatePipelineLayout {};
struct DestroyPipelineLayout {};
struct CreateSampler {};
struct DestroySampler {};
struct CreateDescriptorSetLayout {};
struct DestroyDescriptorSetLayout {};
struct CreateDescriptorPool {};
struct DestroyDescriptorPool {};
struct ResetDescriptorPool {};
struct AllocateDescriptorSets {};
struct FreeDescriptorSets {};
struct UpdateDescriptorSets {};
struct CmdBindPipeline {};
struct CmdBindDescriptorSets {};
struct CmdClearColorImage {};
struct CmdDispatch {};
struct CmdDispatchIndirect {};
struct CmdSetEvent {};
struct CmdResetEvent {};
struct CmdWaitEvents {};
struct CmdPushConstants {};
struct CreateGraphicsPipelines {};
struct CreateFramebuffer {};
struct DestroyFramebuffer {};
struct CreateRenderPass {};
struct DestroyRenderPass {};
struct GetRenderAreaGranularity {};
struct CmdSetViewport {};
struct CmdSetScissor {};
struct CmdSetLineWidth {};
struct CmdSetDepthBias {};
struct CmdSetBlendConstants {};
struct CmdSetDepthBounds {};
struct CmdSetStencilCompareMask {};
struct CmdSetStencilWriteMask {};
struct CmdSetStencilReference {};
struct CmdBindIndexBuffer {};
struct CmdBindVertexBuffers {};
struct CmdDraw {};
struct CmdDrawIndexed {};
struct CmdDrawIndirect {};
struct CmdDrawIndexedIndirect {};
struct CmdBlitImage {};
struct CmdClearDepthStencilImage {};
struct CmdClearAttachments {};
struct CmdResolveImage {};
struct CmdBeginRenderPass {};
struct CmdNextSubpass {};
struct CmdEndRenderPass {};
struct BindBufferMemory2 {};
struct BindImageMemory2 {};
struct GetDeviceGroupPeerMemoryFeatures {};
struct CmdSetDeviceMask {};
struct EnumeratePhysicalDeviceGroups {};
struct GetImageMemoryRequirements2 {};
struct GetBufferMemoryRequirements2 {};
struct GetImageSparseMemoryRequirements2 {};
struct GetPhysicalDeviceFeatures2 {};
struct GetPhysicalDeviceProperties2 {};
struct GetPhysicalDeviceFormatProperties2 {};
struct GetPhysicalDeviceImageFormatProperties2 {};
struct GetPhysicalDeviceQueueFamilyProperties2 {};
struct GetPhysicalDeviceMemoryProperties2 {};
struct GetPhysicalDeviceSparseImageFormatProperties2 {};
struct TrimCommandPool {};
struct GetDeviceQueue2 {};
struct GetPhysicalDeviceExternalBufferProperties {};
struct GetPhysicalDeviceExternalFenceProperties {};
struct GetPhysicalDeviceExternalSemaphoreProperties {};
struct CmdDispatchBase {};
struct CreateDescriptorUpdateTemplate {};
struct DestroyDescriptorUpdateTemplate {};
struct GetDescriptorSetLayoutSupport {};
struct CreateSamplerYcbcrConversion {};
struct DestroySamplerYcbcrConversion {};
struct ResetQueryPool {};
struct GetSemaphoreCounterValue {};
struct WaitSemaphores {};
struct SignalSemaphore {};
struct GetBufferDeviceAddress {};
struct GetBufferOpaqueCaptureAddress {};
struct GetDeviceMemoryOpaqueCaptureAddress {};
struct CmdDrawIndirectCount {};
struct CmdDrawIndexedIndirectCount {};
struct CreateRenderPass2 {};
struct CmdBeginRenderPass2 {};
struct CmdNextSubpass2 {};
struct CmdEndRenderPass2 {};
struct GetPhysicalDeviceToolProperties {};
struct CreatePrivateDataSlot {};
struct DestroyPrivateDataSlot {};
struct SetPrivateData {};
struct GetPrivateData {};
struct CmdPipelineBarrier2 {};
struct CmdWriteTimestamp2 {};
struct QueueSubmit2 {};
struct CmdCopyBuffer2 {};
struct CmdCopyImage2 {};
struct CmdCopyBufferToImage2 {};
struct CmdCopyImageToBuffer2 {};
struct GetDeviceBufferMemoryRequirements {};
struct GetDeviceImageMemoryRequirements {};
struct GetDeviceImageSparseMemoryRequirements {};
struct CmdSetEvent2 {};
struct CmdResetEvent2 {};
struct CmdWaitEvents2 {};
struct CmdBlitImage2 {};
struct CmdResolveImage2 {};
struct CmdBeginRendering {};
struct CmdEndRendering {};
struct CmdSetCullMode {};
struct CmdSetFrontFace {};
struct CmdSetPrimitiveTopology {};
struct CmdSetViewportWithCount {};
struct CmdSetScissorWithCount {};
struct CmdBindVertexBuffers2 {};
struct CmdSetDepthTestEnable {};
struct CmdSetDepthWriteEnable {};
struct CmdSetDepthCompareOp {};
struct CmdSetDepthBoundsTestEnable {};
struct CmdSetStencilTestEnable {};
struct CmdSetStencilOp {};
struct CmdSetRasterizerDiscardEnable {};
struct CmdSetDepthBiasEnable {};
struct CmdSetPrimitiveRestartEnable {};
struct MapMemory2 {};
struct UnmapMemory2 {};
struct GetDeviceImageSubresourceLayout {};
struct GetImageSubresourceLayout2 {};
struct CopyMemoryToImage {};
struct CopyImageToMemory {};
struct CopyImageToImage {};
struct TransitionImageLayout {};
struct CmdPushDescriptorSet {};
struct CmdBindDescriptorSets2 {};
struct CmdPushConstants2 {};
struct CmdPushDescriptorSet2 {};
struct CmdSetLineStipple {};
struct CmdBindIndexBuffer2 {};
struct GetRenderingAreaGranularity {};
struct CmdSetRenderingAttachmentLocations {};
struct CmdSetRenderingInputAttachmentIndices {};
struct DestroySurfaceKHR {};
struct GetPhysicalDeviceSurfaceSupportKHR {};
struct GetPhysicalDeviceSurfaceCapabilitiesKHR {};
struct GetPhysicalDeviceSurfaceFormatsKHR {};
struct GetPhysicalDeviceSurfacePresentModesKHR {};
struct CreateSwapchainKHR {};
struct DestroySwapchainKHR {};
struct GetSwapchainImagesKHR {};
struct AcquireNextImageKHR {};
struct QueuePresentKHR {};
struct GetDeviceGroupPresentCapabilitiesKHR {};
struct GetDeviceGroupSurfacePresentModesKHR {};
struct GetPhysicalDevicePresentRectanglesKHR {};
struct AcquireNextImage2KHR {};
struct GetPhysicalDeviceDisplayPropertiesKHR {};
struct GetPhysicalDeviceDisplayPlanePropertiesKHR {};
struct GetDisplayPlaneSupportedDisplaysKHR {};
struct GetDisplayModePropertiesKHR {};
struct CreateDisplayModeKHR {};
struct GetDisplayPlaneCapabilitiesKHR {};
struct CreateDisplayPlaneSurfaceKHR {};
struct CreateSharedSwapchainsKHR {};
struct CreateXlibSurfaceKHR {};
struct GetPhysicalDeviceXlibPresentationSupportKHR {};
struct CreateXcbSurfaceKHR {};
struct GetPhysicalDeviceXcbPresentationSupportKHR {};
struct CreateWaylandSurfaceKHR {};
struct GetPhysicalDeviceWaylandPresentationSupportKHR {};
struct CreateAndroidSurfaceKHR {};
struct CreateWin32SurfaceKHR {};
struct GetPhysicalDeviceWin32PresentationSupportKHR {};
struct GetPhysicalDeviceVideoCapabilitiesKHR {};
struct GetPhysicalDeviceVideoFormatPropertiesKHR {};
struct CreateVideoSessionKHR {};
struct DestroyVideoSessionKHR {};
struct GetVideoSessionMemoryRequirementsKHR {};
struct BindVideoSessionMemoryKHR {};
struct CreateVideoSessionParametersKHR {};
struct UpdateVideoSessionParametersKHR {};
struct DestroyVideoSessionParametersKHR {};
struct CmdBeginVideoCodingKHR {};
struct CmdEndVideoCodingKHR {};
struct CmdControlVideoCodingKHR {};
struct CmdDecodeVideoKHR {};
struct CmdBeginRenderingKHR {};
struct CmdEndRenderingKHR {};
struct GetPhysicalDeviceFeatures2KHR {};
struct GetPhysicalDeviceProperties2KHR {};
struct GetPhysicalDeviceFormatProperties2KHR {};
struct GetPhysicalDeviceImageFormatProperties2KHR {};
struct GetPhysicalDeviceQueueFamilyProperties2KHR {};
struct GetPhysicalDeviceMemoryProperties2KHR {};
struct GetPhysicalDeviceSparseImageFormatProperties2KHR {};
struct GetDeviceGroupPeerMemoryFeaturesKHR {};
struct CmdSetDeviceMaskKHR {};
struct CmdDispatchBaseKHR {};
struct TrimCommandPoolKHR {};
struct EnumeratePhysicalDeviceGroupsKHR {};
struct GetPhysicalDeviceExternalBufferPropertiesKHR {};
struct GetMemoryWin32HandleKHR {};
struct GetMemoryWin32HandlePropertiesKHR {};
struct GetMemoryFdKHR {};
struct GetMemoryFdPropertiesKHR {};
struct GetPhysicalDeviceExternalSemaphorePropertiesKHR {};
struct ImportSemaphoreWin32HandleKHR {};
struct GetSemaphoreWin32HandleKHR {};
struct ImportSemaphoreFdKHR {};
struct GetSemaphoreFdKHR {};
struct CmdPushDescriptorSetKHR {};
struct CreateDescriptorUpdateTemplateKHR {};
struct DestroyDescriptorUpdateTemplateKHR {};
struct CreateRenderPass2KHR {};
struct CmdBeginRenderPass2KHR {};
struct CmdNextSubpass2KHR {};
struct CmdEndRenderPass2KHR {};
struct GetSwapchainStatusKHR {};
struct GetPhysicalDeviceExternalFencePropertiesKHR {};
struct ImportFenceWin32HandleKHR {};
struct GetFenceWin32HandleKHR {};
struct ImportFenceFdKHR {};
struct GetFenceFdKHR {};
struct EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR {};
struct GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR {};
struct AcquireProfilingLockKHR {};
struct ReleaseProfilingLockKHR {};
struct GetPhysicalDeviceSurfaceCapabilities2KHR {};
struct GetPhysicalDeviceSurfaceFormats2KHR {};
struct GetPhysicalDeviceDisplayProperties2KHR {};
struct GetPhysicalDeviceDisplayPlaneProperties2KHR {};
struct GetDisplayModeProperties2KHR {};
struct GetDisplayPlaneCapabilities2KHR {};
struct GetImageMemoryRequirements2KHR {};
struct GetBufferMemoryRequirements2KHR {};
struct GetImageSparseMemoryRequirements2KHR {};
struct CreateSamplerYcbcrConversionKHR {};
struct DestroySamplerYcbcrConversionKHR {};
struct BindBufferMemory2KHR {};
struct BindImageMemory2KHR {};
struct GetDescriptorSetLayoutSupportKHR {};
struct CmdDrawIndirectCountKHR {};
struct CmdDrawIndexedIndirectCountKHR {};
struct GetSemaphoreCounterValueKHR {};
struct WaitSemaphoresKHR {};
struct SignalSemaphoreKHR {};
struct GetPhysicalDeviceFragmentShadingRatesKHR {};
struct CmdSetFragmentShadingRateKHR {};
struct CmdSetRenderingAttachmentLocationsKHR {};
struct CmdSetRenderingInputAttachmentIndicesKHR {};
struct WaitForPresentKHR {};
struct GetBufferDeviceAddressKHR {};
struct GetBufferOpaqueCaptureAddressKHR {};
struct GetDeviceMemoryOpaqueCaptureAddressKHR {};
struct CreateDeferredOperationKHR {};
struct DestroyDeferredOperationKHR {};
struct GetDeferredOperationMaxConcurrencyKHR {};
struct GetDeferredOperationResultKHR {};
struct DeferredOperationJoinKHR {};
struct GetPipelineExecutablePropertiesKHR {};
struct GetPipelineExecutableStatisticsKHR {};
struct GetPipelineExecutableInternalRepresentationsKHR {};
struct MapMemory2KHR {};
struct UnmapMemory2KHR {};
struct GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR {};
struct GetEncodedVideoSessionParametersKHR {};
struct CmdEncodeVideoKHR {};
struct CmdSetEvent2KHR {};
struct CmdResetEvent2KHR {};
struct CmdWaitEvents2KHR {};
struct CmdPipelineBarrier2KHR {};
struct CmdWriteTimestamp2KHR {};
struct QueueSubmit2KHR {};
struct CmdBindIndexBuffer3KHR {};
struct CmdBindVertexBuffers3KHR {};
struct CmdDrawIndirect2KHR {};
struct CmdDrawIndexedIndirect2KHR {};
struct CmdDispatchIndirect2KHR {};
struct CmdCopyMemoryKHR {};
struct CmdCopyMemoryToImageKHR {};
struct CmdCopyImageToMemoryKHR {};
struct CmdUpdateMemoryKHR {};
struct CmdFillMemoryKHR {};
struct CmdCopyQueryPoolResultsToMemoryKHR {};
struct CmdDrawIndirectCount2KHR {};
struct CmdDrawIndexedIndirectCount2KHR {};
struct CmdBeginConditionalRendering2EXT {};
struct CmdBindTransformFeedbackBuffers2EXT {};
struct CmdBeginTransformFeedback2EXT {};
struct CmdEndTransformFeedback2EXT {};
struct CmdDrawIndirectByteCount2EXT {};
struct CmdDrawMeshTasksIndirect2EXT {};
struct CmdDrawMeshTasksIndirectCount2EXT {};
struct CmdWriteMarkerToMemoryAMD {};
struct CreateAccelerationStructure2KHR {};
struct CmdCopyBuffer2KHR {};
struct CmdCopyImage2KHR {};
struct CmdCopyBufferToImage2KHR {};
struct CmdCopyImageToBuffer2KHR {};
struct CmdBlitImage2KHR {};
struct CmdResolveImage2KHR {};
struct CmdTraceRaysIndirect2KHR {};
struct GetDeviceBufferMemoryRequirementsKHR {};
struct GetDeviceImageMemoryRequirementsKHR {};
struct GetDeviceImageSparseMemoryRequirementsKHR {};
struct CmdBindIndexBuffer2KHR {};
struct GetRenderingAreaGranularityKHR {};
struct GetDeviceImageSubresourceLayoutKHR {};
struct GetImageSubresourceLayout2KHR {};
struct WaitForPresent2KHR {};
struct CreatePipelineBinariesKHR {};
struct DestroyPipelineBinaryKHR {};
struct GetPipelineKeyKHR {};
struct GetPipelineBinaryDataKHR {};
struct ReleaseCapturedPipelineDataKHR {};
struct ReleaseSwapchainImagesKHR {};
struct GetPhysicalDeviceCooperativeMatrixPropertiesKHR {};
struct CmdSetLineStippleKHR {};
struct GetPhysicalDeviceCalibrateableTimeDomainsKHR {};
struct GetCalibratedTimestampsKHR {};
struct CmdBindDescriptorSets2KHR {};
struct CmdPushConstants2KHR {};
struct CmdPushDescriptorSet2KHR {};
struct CmdSetDescriptorBufferOffsets2EXT {};
struct CmdBindDescriptorBufferEmbeddedSamplers2EXT {};
struct CmdCopyMemoryIndirectKHR {};
struct CmdCopyMemoryToImageIndirectKHR {};
struct GetDeviceFaultReportsKHR {};
struct GetDeviceFaultDebugInfoKHR {};
struct CmdEndRendering2KHR {};
struct FrameBoundaryANDROID {};
struct CreateDebugReportCallbackEXT {};
struct DestroyDebugReportCallbackEXT {};
struct DebugReportMessageEXT {};
struct DebugMarkerSetObjectTagEXT {};
struct DebugMarkerSetObjectNameEXT {};
struct CmdDebugMarkerBeginEXT {};
struct CmdDebugMarkerEndEXT {};
struct CmdDebugMarkerInsertEXT {};
struct CmdBindTransformFeedbackBuffersEXT {};
struct CmdBeginTransformFeedbackEXT {};
struct CmdEndTransformFeedbackEXT {};
struct CmdBeginQueryIndexedEXT {};
struct CmdEndQueryIndexedEXT {};
struct CmdDrawIndirectByteCountEXT {};
struct GetImageViewHandleNVX {};
struct GetImageViewHandle64NVX {};
struct GetImageViewAddressNVX {};
struct GetDeviceCombinedImageSamplerIndexNVX {};
struct CmdDrawIndirectCountAMD {};
struct CmdDrawIndexedIndirectCountAMD {};
struct GetShaderInfoAMD {};
struct CreateStreamDescriptorSurfaceGGP {};
struct GetPhysicalDeviceExternalImageFormatPropertiesNV {};
struct GetMemoryWin32HandleNV {};
struct CreateViSurfaceNN {};
struct CmdBeginConditionalRenderingEXT {};
struct CmdEndConditionalRenderingEXT {};
struct CmdSetViewportWScalingNV {};
struct ReleaseDisplayEXT {};
struct AcquireXlibDisplayEXT {};
struct GetRandROutputDisplayEXT {};
struct GetPhysicalDeviceSurfaceCapabilities2EXT {};
struct DisplayPowerControlEXT {};
struct RegisterDeviceEventEXT {};
struct RegisterDisplayEventEXT {};
struct GetSwapchainCounterEXT {};
struct GetRefreshCycleDurationGOOGLE {};
struct GetPastPresentationTimingGOOGLE {};
struct CmdSetDiscardRectangleEXT {};
struct CmdSetDiscardRectangleEnableEXT {};
struct CmdSetDiscardRectangleModeEXT {};
struct SetHdrMetadataEXT {};
struct CreateIOSSurfaceMVK {};
struct CreateMacOSSurfaceMVK {};
struct SetDebugUtilsObjectNameEXT {};
struct SetDebugUtilsObjectTagEXT {};
struct QueueBeginDebugUtilsLabelEXT {};
struct QueueEndDebugUtilsLabelEXT {};
struct QueueInsertDebugUtilsLabelEXT {};
struct CmdBeginDebugUtilsLabelEXT {};
struct CmdEndDebugUtilsLabelEXT {};
struct CmdInsertDebugUtilsLabelEXT {};
struct CreateDebugUtilsMessengerEXT {};
struct DestroyDebugUtilsMessengerEXT {};
struct SubmitDebugUtilsMessageEXT {};
struct GetAndroidHardwareBufferPropertiesANDROID {};
struct GetMemoryAndroidHardwareBufferANDROID {};
struct CreateGpaSessionAMD {};
struct DestroyGpaSessionAMD {};
struct SetGpaDeviceClockModeAMD {};
struct GetGpaDeviceClockInfoAMD {};
struct CmdBeginGpaSessionAMD {};
struct CmdEndGpaSessionAMD {};
struct CmdBeginGpaSampleAMD {};
struct CmdEndGpaSampleAMD {};
struct GetGpaSessionStatusAMD {};
struct GetGpaSessionResultsAMD {};
struct ResetGpaSessionAMD {};
struct CmdCopyGpaSessionResultsAMD {};
struct CmdSetSampleLocationsEXT {};
struct GetPhysicalDeviceMultisamplePropertiesEXT {};
struct GetImageDrmFormatModifierPropertiesEXT {};
struct CreateValidationCacheEXT {};
struct DestroyValidationCacheEXT {};
struct MergeValidationCachesEXT {};
struct GetValidationCacheDataEXT {};
struct CmdBindShadingRateImageNV {};
struct CmdSetViewportShadingRatePaletteNV {};
struct CmdSetCoarseSampleOrderNV {};
struct CreateAccelerationStructureNV {};
struct DestroyAccelerationStructureNV {};
struct GetAccelerationStructureMemoryRequirementsNV {};
struct BindAccelerationStructureMemoryNV {};
struct CmdBuildAccelerationStructureNV {};
struct CmdCopyAccelerationStructureNV {};
struct CmdTraceRaysNV {};
struct CreateRayTracingPipelinesNV {};
struct GetRayTracingShaderGroupHandlesKHR {};
struct GetRayTracingShaderGroupHandlesNV {};
struct GetAccelerationStructureHandleNV {};
struct CmdWriteAccelerationStructuresPropertiesNV {};
struct CompileDeferredNV {};
struct GetMemoryHostPointerPropertiesEXT {};
struct CmdWriteBufferMarkerAMD {};
struct CmdWriteBufferMarker2AMD {};
struct GetPhysicalDeviceCalibrateableTimeDomainsEXT {};
struct GetCalibratedTimestampsEXT {};
struct CmdDrawMeshTasksNV {};
struct CmdDrawMeshTasksIndirectNV {};
struct CmdDrawMeshTasksIndirectCountNV {};
struct CmdSetExclusiveScissorEnableNV {};
struct CmdSetExclusiveScissorNV {};
struct CmdSetCheckpointNV {};
struct GetQueueCheckpointDataNV {};
struct GetQueueCheckpointData2NV {};
struct SetSwapchainPresentTimingQueueSizeEXT {};
struct GetSwapchainTimingPropertiesEXT {};
struct GetSwapchainTimeDomainPropertiesEXT {};
struct GetPastPresentationTimingEXT {};
struct InitializePerformanceApiINTEL {};
struct UninitializePerformanceApiINTEL {};
struct CmdSetPerformanceMarkerINTEL {};
struct CmdSetPerformanceStreamMarkerINTEL {};
struct CmdSetPerformanceOverrideINTEL {};
struct AcquirePerformanceConfigurationINTEL {};
struct ReleasePerformanceConfigurationINTEL {};
struct QueueSetPerformanceConfigurationINTEL {};
struct GetPerformanceParameterINTEL {};
struct SetLocalDimmingAMD {};
struct CreateImagePipeSurfaceFUCHSIA {};
struct CreateMetalSurfaceEXT {};
struct GetBufferDeviceAddressEXT {};
struct GetPhysicalDeviceToolPropertiesEXT {};
struct GetPhysicalDeviceCooperativeMatrixPropertiesNV {};
struct GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV {};
struct GetPhysicalDeviceSurfacePresentModes2EXT {};
struct AcquireFullScreenExclusiveModeEXT {};
struct ReleaseFullScreenExclusiveModeEXT {};
struct GetDeviceGroupSurfacePresentModes2EXT {};
struct CreateHeadlessSurfaceEXT {};
struct CmdSetLineStippleEXT {};
struct ResetQueryPoolEXT {};
struct CmdSetCullModeEXT {};
struct CmdSetFrontFaceEXT {};
struct CmdSetPrimitiveTopologyEXT {};
struct CmdSetViewportWithCountEXT {};
struct CmdSetScissorWithCountEXT {};
struct CmdBindVertexBuffers2EXT {};
struct CmdSetDepthTestEnableEXT {};
struct CmdSetDepthWriteEnableEXT {};
struct CmdSetDepthCompareOpEXT {};
struct CmdSetDepthBoundsTestEnableEXT {};
struct CmdSetStencilTestEnableEXT {};
struct CmdSetStencilOpEXT {};
struct CopyMemoryToImageEXT {};
struct CopyImageToMemoryEXT {};
struct CopyImageToImageEXT {};
struct TransitionImageLayoutEXT {};
struct GetImageSubresourceLayout2EXT {};
struct ReleaseSwapchainImagesEXT {};
struct GetGeneratedCommandsMemoryRequirementsNV {};
struct CmdPreprocessGeneratedCommandsNV {};
struct CmdExecuteGeneratedCommandsNV {};
struct CmdBindPipelineShaderGroupNV {};
struct CreateIndirectCommandsLayoutNV {};
struct DestroyIndirectCommandsLayoutNV {};
struct CmdSetDepthBias2EXT {};
struct AcquireDrmDisplayEXT {};
struct GetDrmDisplayEXT {};
struct CreatePrivateDataSlotEXT {};
struct DestroyPrivateDataSlotEXT {};
struct SetPrivateDataEXT {};
struct GetPrivateDataEXT {};
struct QueueSetPerfHintQCOM {};
struct CmdDispatchTileQCOM {};
struct CmdBeginPerTileExecutionQCOM {};
struct CmdEndPerTileExecutionQCOM {};
struct GetDescriptorSetLayoutSizeEXT {};
struct GetDescriptorSetLayoutBindingOffsetEXT {};
struct GetDescriptorEXT {};
struct CmdBindDescriptorBuffersEXT {};
struct CmdSetDescriptorBufferOffsetsEXT {};
struct CmdBindDescriptorBufferEmbeddedSamplersEXT {};
struct CmdSetFragmentShadingRateEnumNV {};
struct GetDeviceFaultInfoEXT {};
struct AcquireWinrtDisplayNV {};
struct GetWinrtDisplayNV {};
struct CreateDirectFBSurfaceEXT {};
struct GetPhysicalDeviceDirectFBPresentationSupportEXT {};
struct CmdSetVertexInputEXT {};
struct GetMemoryZirconHandleFUCHSIA {};
struct GetMemoryZirconHandlePropertiesFUCHSIA {};
struct ImportSemaphoreZirconHandleFUCHSIA {};
struct GetSemaphoreZirconHandleFUCHSIA {};
struct CmdBindInvocationMaskHUAWEI {};
struct GetMemoryRemoteAddressNV {};
struct CmdSetPatchControlPointsEXT {};
struct CmdSetRasterizerDiscardEnableEXT {};
struct CmdSetDepthBiasEnableEXT {};
struct CmdSetLogicOpEXT {};
struct CmdSetPrimitiveRestartEnableEXT {};
struct CreateScreenSurfaceQNX {};
struct GetPhysicalDeviceScreenPresentationSupportQNX {};
struct CmdSetColorWriteEnableEXT {};
struct CmdDrawMultiEXT {};
struct CmdDrawMultiIndexedEXT {};
struct CreateMicromapEXT {};
struct DestroyMicromapEXT {};
struct CmdBuildMicromapsEXT {};
struct BuildMicromapsEXT {};
struct CopyMicromapEXT {};
struct CopyMicromapToMemoryEXT {};
struct CopyMemoryToMicromapEXT {};
struct WriteMicromapsPropertiesEXT {};
struct CmdCopyMicromapEXT {};
struct CmdCopyMicromapToMemoryEXT {};
struct CmdCopyMemoryToMicromapEXT {};
struct CmdWriteMicromapsPropertiesEXT {};
struct GetDeviceMicromapCompatibilityEXT {};
struct GetMicromapBuildSizesEXT {};
struct CmdDrawClusterHUAWEI {};
struct CmdDrawClusterIndirectHUAWEI {};
struct SetDeviceMemoryPriorityEXT {};
struct CmdSetDispatchParametersARM {};
struct GetDescriptorSetLayoutHostMappingInfoVALVE {};
struct GetDescriptorSetHostMappingVALVE {};
struct GetPipelineIndirectMemoryRequirementsNV {};
struct CmdUpdatePipelineIndirectBufferNV {};
struct GetPipelineIndirectDeviceAddressNV {};
struct CmdSetDepthClampEnableEXT {};
struct CmdSetPolygonModeEXT {};
struct CmdSetRasterizationSamplesEXT {};
struct CmdSetSampleMaskEXT {};
struct CmdSetAlphaToCoverageEnableEXT {};
struct CmdSetAlphaToOneEnableEXT {};
struct CmdSetLogicOpEnableEXT {};
struct CmdSetColorBlendEnableEXT {};
struct CmdSetColorBlendEquationEXT {};
struct CmdSetColorWriteMaskEXT {};
struct CmdSetTessellationDomainOriginEXT {};
struct CmdSetRasterizationStreamEXT {};
struct CmdSetConservativeRasterizationModeEXT {};
struct CmdSetExtraPrimitiveOverestimationSizeEXT {};
struct CmdSetDepthClipEnableEXT {};
struct CmdSetSampleLocationsEnableEXT {};
struct CmdSetColorBlendAdvancedEXT {};
struct CmdSetProvokingVertexModeEXT {};
struct CmdSetLineRasterizationModeEXT {};
struct CmdSetLineStippleEnableEXT {};
struct CmdSetDepthClipNegativeOneToOneEXT {};
struct CmdSetViewportWScalingEnableNV {};
struct CmdSetViewportSwizzleNV {};
struct CmdSetCoverageToColorEnableNV {};
struct CmdSetCoverageToColorLocationNV {};
struct CmdSetCoverageModulationModeNV {};
struct CmdSetCoverageModulationTableEnableNV {};
struct CmdSetCoverageModulationTableNV {};
struct CmdSetShadingRateImageEnableNV {};
struct CmdSetRepresentativeFragmentTestEnableNV {};
struct CmdSetCoverageReductionModeNV {};
struct CreateTensorARM {};
struct DestroyTensorARM {};
struct CreateTensorViewARM {};
struct DestroyTensorViewARM {};
struct GetTensorMemoryRequirementsARM {};
struct BindTensorMemoryARM {};
struct GetDeviceTensorMemoryRequirementsARM {};
struct CmdCopyTensorARM {};
struct GetPhysicalDeviceExternalTensorPropertiesARM {};
struct GetShaderModuleIdentifierEXT {};
struct GetShaderModuleCreateInfoIdentifierEXT {};
struct GetPhysicalDeviceOpticalFlowImageFormatsNV {};
struct CreateOpticalFlowSessionNV {};
struct DestroyOpticalFlowSessionNV {};
struct BindOpticalFlowSessionImageNV {};
struct CmdOpticalFlowExecuteNV {};
struct AntiLagUpdateAMD {};
struct CreateShadersEXT {};
struct DestroyShaderEXT {};
struct GetShaderBinaryDataEXT {};
struct CmdBindShadersEXT {};
struct CmdSetDepthClampRangeEXT {};
struct GetFramebufferTilePropertiesQCOM {};
struct GetDynamicRenderingTilePropertiesQCOM {};
struct GetPhysicalDeviceCooperativeVectorPropertiesNV {};
struct ConvertCooperativeVectorMatrixNV {};
struct CmdConvertCooperativeVectorMatrixNV {};
struct SetLatencySleepModeNV {};
struct LatencySleepNV {};
struct SetLatencyMarkerNV {};
struct GetLatencyTimingsNV {};
struct QueueNotifyOutOfBandNV {};
struct CreateDataGraphPipelinesARM {};
struct CreateDataGraphPipelineSessionARM {};
struct GetDataGraphPipelineSessionBindPointRequirementsARM {};
struct GetDataGraphPipelineSessionMemoryRequirementsARM {};
struct BindDataGraphPipelineSessionMemoryARM {};
struct DestroyDataGraphPipelineSessionARM {};
struct CmdDispatchDataGraphARM {};
struct GetDataGraphPipelineAvailablePropertiesARM {};
struct GetDataGraphPipelinePropertiesARM {};
struct GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM {};
struct GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM {};
struct CmdSetAttachmentFeedbackLoopEnableEXT {};
struct CmdBindTileMemoryQCOM {};
struct CmdDecompressMemoryEXT {};
struct CmdDecompressMemoryIndirectCountEXT {};
struct GetPartitionedAccelerationStructuresBuildSizesNV {};
struct CmdBuildPartitionedAccelerationStructuresNV {};
struct GetGeneratedCommandsMemoryRequirementsEXT {};
struct CmdPreprocessGeneratedCommandsEXT {};
struct CmdExecuteGeneratedCommandsEXT {};
struct CreateIndirectCommandsLayoutEXT {};
struct DestroyIndirectCommandsLayoutEXT {};
struct CreateIndirectExecutionSetEXT {};
struct DestroyIndirectExecutionSetEXT {};
struct UpdateIndirectExecutionSetPipelineEXT {};
struct UpdateIndirectExecutionSetShaderEXT {};
struct GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV {};
struct GetMemoryMetalHandleEXT {};
struct GetMemoryMetalHandlePropertiesEXT {};
struct EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM {};
struct CmdEndRendering2EXT {};
struct CmdBeginCustomResolveEXT {};
struct GetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM {};
struct GetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM {};
struct CmdSetComputeOccupancyPriorityNV {};
struct GetPhysicalDeviceCooperativeMatrixProperties2EXT {};
struct CmdSetPrimitiveRestartIndexEXT {};
struct CreateAccelerationStructureKHR {};
struct DestroyAccelerationStructureKHR {};
struct CmdBuildAccelerationStructuresKHR {};
struct CmdBuildAccelerationStructuresIndirectKHR {};
struct CopyAccelerationStructureToMemoryKHR {};
struct CopyMemoryToAccelerationStructureKHR {};
struct WriteAccelerationStructuresPropertiesKHR {};
struct CmdCopyAccelerationStructureKHR {};
struct CmdCopyAccelerationStructureToMemoryKHR {};
struct CmdCopyMemoryToAccelerationStructureKHR {};
struct GetAccelerationStructureDeviceAddressKHR {};
struct CmdWriteAccelerationStructuresPropertiesKHR {};
struct GetDeviceAccelerationStructureCompatibilityKHR {};
struct GetAccelerationStructureBuildSizesKHR {};
struct CmdTraceRaysKHR {};
struct GetRayTracingCaptureReplayShaderGroupHandlesKHR {};
struct CmdTraceRaysIndirectKHR {};
struct GetRayTracingShaderGroupStackSizeKHR {};
struct CmdSetRayTracingPipelineStackSizeKHR {};
struct CmdDrawMeshTasksEXT {};
struct CmdDrawMeshTasksIndirectEXT {};
struct CmdDrawMeshTasksIndirectCountEXT {};
GFXRECON_END_NAMESPACE(commands)
GFXRECON_END_NAMESPACE(vulkan)

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_SCHEMA_TYPES_H
