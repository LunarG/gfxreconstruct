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

#ifndef  GFXRECON_GENERATED_VULKAN_WIRE_TYPES_H
#define  GFXRECON_GENERATED_VULKAN_WIRE_TYPES_H

#include "binding/wire_type_of.h"
#include "format/format.h"
#include "generated/generated_vulkan_schema_types.h"
#include "util/defines.h"

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
// The Vulkan WireTypeOf rows: the format typedef each scalar and enum element is recorded as. A bitmask
// reads its width through its flags element, and a handle or an address is a partial specialization by
// category, both in binding/wire_type_of.h; a struct and a void have no width of their own.
GFXRECON_BEGIN_NAMESPACE(binding)

template <> struct WireTypeOf<schema::vulkan::api_elements::Char> { using type = format::CharEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::DWORD> { using type = format::UInt32EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::Double> { using type = format::DoubleEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::EmptyBitvalues> { using type = format::FlagsEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::EmptyBitvalues64> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::Float> { using type = format::FloatEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::GgpFrameToken> { using type = format::UInt64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::GgpStreamDescriptor> { using type = format::UInt64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::Int> { using type = format::Int32EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::Int16> { using type = format::Int16EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::Int32> { using type = format::Int32EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::Int64> { using type = format::Int64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::Int8> { using type = format::Int8EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::LPCWSTR> { using type = format::WCharEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::RROutput> { using type = format::SizeTEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::SizeT> { using type = format::SizeTEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoAV1ChromaSamplePosition> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoAV1ColorPrimaries> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoAV1FrameRestorationType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoAV1FrameType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoAV1InterpolationFilter> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoAV1Level> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoAV1MatrixCoefficients> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoAV1Profile> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoAV1ReferenceName> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoAV1TransferCharacteristics> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoAV1TxMode> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoDecodeH264FieldOrderCount> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoH264AspectRatioIdc> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoH264CabacInitIdc> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoH264ChromaFormatIdc> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoH264DisableDeblockingFilterIdc> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoH264LevelIdc> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoH264MemMgmtControlOp> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoH264ModificationOfPicNumsIdc> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoH264NonVclNaluType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoH264PictureType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoH264PocType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoH264ProfileIdc> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoH264SliceType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoH264WeightedBipredIdc> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoVP9ColorSpace> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoVP9FrameType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoVP9InterpolationFilter> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoVP9Level> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoVP9Profile> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::StdVideoVP9ReferenceName> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::UInt16> { using type = format::UInt16EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::UInt32> { using type = format::UInt32EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::UInt64> { using type = format::UInt64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::UInt8> { using type = format::UInt8EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VisualID> { using type = format::SizeTEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAccelerationStructureBuildTypeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAccelerationStructureCompatibilityKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAccelerationStructureCreateFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAccelerationStructureMemoryRequirementsTypeNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAccelerationStructureMotionInstanceTypeNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAccelerationStructureSerializedBlockTypeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAccelerationStructureTypeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAccessFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAccessFlagBits2> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAccessFlagBits3KHR> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAcquireProfilingLockFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAddressCommandFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAddressCopyFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAntiLagModeAMD> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAntiLagStageAMD> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAttachmentDescriptionFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAttachmentLoadOp> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkAttachmentStoreOp> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkBlendFactor> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkBlendOp> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkBlendOverlapEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkBlockMatchWindowCompareModeQCOM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkBool32> { using type = format::UInt32EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkBorderColor> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkBufferCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkBufferUsageFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkBufferUsageFlagBits2> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkBuildAccelerationStructureFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkBuildAccelerationStructureModeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkBuildMicromapFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkBuildMicromapModeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkChromaLocation> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCoarseSampleOrderTypeNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkColorComponentFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkColorSpaceKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCommandBufferLevel> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCommandBufferResetFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCommandBufferUsageFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCommandPoolCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCommandPoolResetFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCompareOp> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkComponentSwizzle> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkComponentTypeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCompositeAlphaFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkConditionalRenderingFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkConservativeRasterizationModeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCooperativeMatrixFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCooperativeVectorMatrixLayoutNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCopyAccelerationStructureModeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCopyMicromapModeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCoverageModulationModeNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCoverageReductionModeNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCubicFilterWeightsQCOM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkCullModeFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDataGraphModelCacheTypeQCOM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDataGraphOpticalFlowCreateFlagBitsARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDataGraphOpticalFlowExecuteFlagBitsARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDataGraphOpticalFlowGridSizeFlagBitsARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDataGraphOpticalFlowImageUsageFlagBitsARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDataGraphOpticalFlowPerformanceLevelARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDataGraphPipelineDispatchFlagBitsARM> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDataGraphPipelineNodeConnectionTypeARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDataGraphPipelineNodeTypeARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDataGraphPipelinePropertyARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDataGraphPipelineSessionBindPointARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDataGraphPipelineSessionBindPointTypeARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDataGraphPipelineSessionCreateFlagBitsARM> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDebugReportFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDebugReportObjectTypeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDebugUtilsMessageSeverityFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDebugUtilsMessageTypeFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDefaultVertexAttributeValueKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDependencyFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDepthBiasRepresentationEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDepthClampModeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDescriptorBindingFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDescriptorPoolCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDescriptorSetLayoutCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDescriptorType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDescriptorUpdateTemplateType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDeviceAddress> { using type = format::DeviceAddressEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDeviceAddressBindingFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDeviceAddressBindingTypeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDeviceDiagnosticsConfigFlagBitsNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDeviceEventTypeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDeviceFaultAddressTypeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDeviceFaultFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDeviceFaultVendorBinaryHeaderVersionKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDeviceGroupPresentModeFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDeviceMemoryReportEventTypeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDeviceQueueCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDeviceSize> { using type = format::DeviceSizeEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDirectDriverLoadingModeLUNARG> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDiscardRectangleModeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDisplacementMicromapFormatNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDisplayEventTypeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDisplayPlaneAlphaFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDisplayPowerStateEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDisplaySurfaceStereoTypeNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDriverId> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkDynamicState> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkEventCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkExternalFenceFeatureFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkExternalFenceHandleTypeFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkExternalMemoryFeatureFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkExternalMemoryFeatureFlagBitsNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkExternalMemoryHandleTypeFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkExternalMemoryHandleTypeFlagBitsNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkExternalSemaphoreFeatureFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkExternalSemaphoreHandleTypeFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFenceCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFenceImportFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFilter> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFlags> { using type = format::FlagsEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFlags64> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFormat> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFormatFeatureFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFormatFeatureFlagBits2> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFormatFeatureFlagBits4KHR> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFragmentShadingRateCombinerOpKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFragmentShadingRateNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFragmentShadingRateTypeNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFrameBoundaryFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFramebufferCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFrontFace> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkFullScreenExclusiveEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkGeometryFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkGeometryInstanceFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkGeometryTypeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkGpaDeviceClockModeAMD> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkGpaPerfBlockAMD> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkGpaSampleTypeAMD> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkGpaSqShaderStageFlagBitsAMD> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkGraphicsPipelineLibraryFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkHostImageCopyFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkImageAspectFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkImageCompressionFixedRateFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkImageCompressionFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkImageCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkImageCreateFlagBits2KHR> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkImageLayout> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkImageTiling> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkImageTilingControlEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkImageType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkImageUsageFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkImageUsageFlagBits2KHR> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkImageViewCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkImageViewType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkIndexType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkIndirectCommandsInputModeFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkIndirectCommandsLayoutUsageFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkIndirectCommandsLayoutUsageFlagBitsNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkIndirectCommandsTokenTypeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkIndirectCommandsTokenTypeNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkIndirectExecutionSetInfoTypeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkIndirectStateFlagBitsNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkInstanceCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkInternalAllocationType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkLatencyMarkerNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkLayerSettingTypeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkLayeredDriverUnderlyingApiMSFT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkLineRasterizationMode> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkLogicOp> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkMemoryAllocateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkMemoryDecompressionMethodFlagBitsEXT> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkMemoryHeapFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkMemoryMapFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkMemoryOverallocationBehaviorAMD> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkMemoryPropertyFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkMemoryUnmapFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkMicromapCreateFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkMicromapTypeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkNeuralAcceleratorStatisticsModeARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkObjectType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkOpacityMicromapFormatKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkOpacityMicromapSpecialIndexKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkOpticalFlowExecuteFlagBitsNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkOpticalFlowGridSizeFlagBitsNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkOpticalFlowPerformanceLevelNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkOpticalFlowSessionBindingPointNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkOpticalFlowSessionCreateFlagBitsNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkOpticalFlowUsageFlagBitsNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkOutOfBandQueueTypeNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPartitionedAccelerationStructureInstanceFlagBitsNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPartitionedAccelerationStructureOpTypeNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPastPresentationTimingFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPeerMemoryFeatureFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPerfHintTypeQCOM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPerformanceConfigurationTypeINTEL> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPerformanceCounterDescriptionFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPerformanceCounterScopeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPerformanceCounterStorageKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPerformanceCounterUnitKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPerformanceOverrideTypeINTEL> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPerformanceParameterTypeINTEL> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPerformanceValueTypeINTEL> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPhysicalDeviceDataGraphOperationTypeARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPhysicalDeviceDataGraphProcessingEngineTypeARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPhysicalDeviceLayeredApiKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPhysicalDeviceSchedulingControlsFlagBitsARM> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPhysicalDeviceType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineBindPoint> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineCacheCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineCacheHeaderVersion> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineColorBlendStateCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineCompilerControlFlagBitsAMD> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineCreateFlagBits2> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineCreationFeedbackFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineDepthStencilStateCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineExecutableStatisticFormatKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineLayoutCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineRobustnessBufferBehavior> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineRobustnessImageBehavior> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineShaderStageCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineStageFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPipelineStageFlagBits2> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPointClippingBehavior> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPolygonMode> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPresentGravityFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPresentModeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPresentScalingFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPresentStageFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPresentTimingInfoFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPrimitiveTopology> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkPrivateDataSlotCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkProvokingVertexModeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkQueryControlFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkQueryPipelineStatisticFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkQueryPoolCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkQueryPoolSamplingModeINTEL> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkQueryResultFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkQueryResultStatusKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkQueryType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkQueueFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkQueueGlobalPriority> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkRasterizationOrderAMD> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkRayTracingInvocationReorderModeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkRayTracingLssIndexingModeNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkRayTracingLssPrimitiveEndCapsModeNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkRayTracingShaderGroupTypeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkRenderPassCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkRenderingAttachmentFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkRenderingFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkResolveImageFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkResolveModeFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkResult> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSampleCountFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSampleMask> { using type = format::SampleMaskEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSamplerAddressMode> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSamplerCreateFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSamplerMipmapMode> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSamplerReductionMode> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSamplerYcbcrModelConversion> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSamplerYcbcrRange> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkScopeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSemaphoreImportFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSemaphoreType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSemaphoreWaitFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkShaderCodeTypeEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkShaderCorePropertiesFlagBitsAMD> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkShaderCreateFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkShaderFloatControlsIndependence> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkShaderGroupShaderKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkShaderInfoTypeAMD> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkShaderStageFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkShadingRatePaletteEntryNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSharingMode> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSparseImageFormatFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSparseMemoryBindFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkStencilFaceFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkStencilOp> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkStructureType> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSubgroupFeatureFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSubmitFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSubpassContents> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSubpassDescriptionFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSubpassMergeStatusEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSurfaceCounterFlagBitsEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSurfaceTransformFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSwapchainCreateFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkSystemAllocationScope> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkTensorCreateFlagBitsARM> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkTensorTilingARM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkTensorUsageFlagBitsARM> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkTensorViewCreateFlagBitsARM> { using type = format::Flags64EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkTessellationDomainOrigin> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkThrottleHintTypeSEC> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkTileShadingRenderPassFlagBitsQCOM> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkTimeDomainKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkToolPurposeFlagBits> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkValidationCacheHeaderVersionEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkValidationCheckEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkValidationFeatureDisableEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkValidationFeatureEnableEXT> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVendorId> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVertexInputRate> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoCapabilityFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoChromaSubsamplingFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoCodecOperationFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoCodingControlFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoComponentBitDepthFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoDecodeCapabilityFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoDecodeH264PictureLayoutFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoDecodeUsageFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeAV1CapabilityFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeAV1PredictionModeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeAV1RateControlFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeAV1RateControlGroupKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeAV1StdFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeAV1SuperblockSizeFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeCapabilityFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeContentFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeFeedbackFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeH264CapabilityFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeH264RateControlFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeH264StdFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeH265CtbSizeFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeIntraRefreshModeFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodePerPartitionFeedbackFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeRateControlModeFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeRgbChromaOffsetFlagBitsVALVE> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeRgbModelConversionFlagBitsVALVE> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeRgbRangeCompressionFlagBitsVALVE> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeTuningModeKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoEncodeUsageFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoSessionCreateFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkVideoSessionParametersCreateFlagBitsKHR> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::VkViewportCoordinateSwizzleNV> { using type = format::EnumEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::Window> { using type = format::SizeTEncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::xcb_visualid_t> { using type = format::UInt32EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::xcb_window_t> { using type = format::UInt32EncodeType; };
template <> struct WireTypeOf<schema::vulkan::api_elements::zx_handle_t> { using type = format::UInt32EncodeType; };

GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_WIRE_TYPES_H
