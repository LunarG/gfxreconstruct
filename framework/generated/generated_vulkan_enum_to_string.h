/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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

#ifndef  GFXRECON_GENERATED_VULKAN_ENUM_TO_STRING_H
#define  GFXRECON_GENERATED_VULKAN_ENUM_TO_STRING_H

#include "format/platform_types.h"
#include "util/to_string.h"
#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
template <> std::string ToString<StdVideoAV1ChromaSamplePosition>(const StdVideoAV1ChromaSamplePosition& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoAV1ColorPrimaries>(const StdVideoAV1ColorPrimaries& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoAV1FrameRestorationType>(const StdVideoAV1FrameRestorationType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoAV1FrameType>(const StdVideoAV1FrameType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoAV1InterpolationFilter>(const StdVideoAV1InterpolationFilter& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoAV1Level>(const StdVideoAV1Level& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoAV1MatrixCoefficients>(const StdVideoAV1MatrixCoefficients& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoAV1Profile>(const StdVideoAV1Profile& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoAV1ReferenceName>(const StdVideoAV1ReferenceName& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoAV1TransferCharacteristics>(const StdVideoAV1TransferCharacteristics& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoAV1TxMode>(const StdVideoAV1TxMode& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoDecodeH264FieldOrderCount>(const StdVideoDecodeH264FieldOrderCount& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH264AspectRatioIdc>(const StdVideoH264AspectRatioIdc& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH264CabacInitIdc>(const StdVideoH264CabacInitIdc& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH264ChromaFormatIdc>(const StdVideoH264ChromaFormatIdc& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH264DisableDeblockingFilterIdc>(const StdVideoH264DisableDeblockingFilterIdc& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH264LevelIdc>(const StdVideoH264LevelIdc& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH264MemMgmtControlOp>(const StdVideoH264MemMgmtControlOp& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH264ModificationOfPicNumsIdc>(const StdVideoH264ModificationOfPicNumsIdc& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH264NonVclNaluType>(const StdVideoH264NonVclNaluType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH264PictureType>(const StdVideoH264PictureType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH264PocType>(const StdVideoH264PocType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH264ProfileIdc>(const StdVideoH264ProfileIdc& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH264SliceType>(const StdVideoH264SliceType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH264WeightedBipredIdc>(const StdVideoH264WeightedBipredIdc& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH265AspectRatioIdc>(const StdVideoH265AspectRatioIdc& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH265ChromaFormatIdc>(const StdVideoH265ChromaFormatIdc& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH265LevelIdc>(const StdVideoH265LevelIdc& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH265PictureType>(const StdVideoH265PictureType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH265ProfileIdc>(const StdVideoH265ProfileIdc& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<StdVideoH265SliceType>(const StdVideoH265SliceType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAccelerationStructureBuildTypeKHR>(const VkAccelerationStructureBuildTypeKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAccelerationStructureCompatibilityKHR>(const VkAccelerationStructureCompatibilityKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAccelerationStructureCreateFlagBitsKHR>(const VkAccelerationStructureCreateFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAccelerationStructureCreateFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAccelerationStructureMemoryRequirementsTypeNV>(const VkAccelerationStructureMemoryRequirementsTypeNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAccelerationStructureMotionInstanceTypeNV>(const VkAccelerationStructureMotionInstanceTypeNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAccelerationStructureTypeKHR>(const VkAccelerationStructureTypeKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAccessFlagBits>(const VkAccessFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAccessFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
std::string VkAccessFlagBits2ToString(const VkAccessFlagBits2 value);
std::string VkAccessFlags2ToString(VkFlags64 vkFlags);
template <> std::string ToString<VkAcquireProfilingLockFlagBitsKHR>(const VkAcquireProfilingLockFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAcquireProfilingLockFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAntiLagModeAMD>(const VkAntiLagModeAMD& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAntiLagStageAMD>(const VkAntiLagStageAMD& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAttachmentDescriptionFlagBits>(const VkAttachmentDescriptionFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAttachmentDescriptionFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAttachmentLoadOp>(const VkAttachmentLoadOp& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkAttachmentStoreOp>(const VkAttachmentStoreOp& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBlendFactor>(const VkBlendFactor& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBlendOp>(const VkBlendOp& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBlendOverlapEXT>(const VkBlendOverlapEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBlockMatchWindowCompareModeQCOM>(const VkBlockMatchWindowCompareModeQCOM& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBorderColor>(const VkBorderColor& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBufferCreateFlagBits>(const VkBufferCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBufferCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBufferUsageFlagBits>(const VkBufferUsageFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBufferUsageFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
std::string VkBufferUsageFlagBits2KHRToString(const VkBufferUsageFlagBits2KHR value);
std::string VkBufferUsageFlags2KHRToString(VkFlags64 vkFlags);
template <> std::string ToString<VkBuildAccelerationStructureFlagBitsKHR>(const VkBuildAccelerationStructureFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBuildAccelerationStructureFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBuildAccelerationStructureModeKHR>(const VkBuildAccelerationStructureModeKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBuildMicromapFlagBitsEXT>(const VkBuildMicromapFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBuildMicromapFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkBuildMicromapModeEXT>(const VkBuildMicromapModeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkChromaLocation>(const VkChromaLocation& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCoarseSampleOrderTypeNV>(const VkCoarseSampleOrderTypeNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkColorComponentFlagBits>(const VkColorComponentFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkColorComponentFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkColorSpaceKHR>(const VkColorSpaceKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCommandBufferLevel>(const VkCommandBufferLevel& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCommandBufferResetFlagBits>(const VkCommandBufferResetFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCommandBufferResetFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCommandBufferUsageFlagBits>(const VkCommandBufferUsageFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCommandBufferUsageFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCommandPoolCreateFlagBits>(const VkCommandPoolCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCommandPoolCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCommandPoolResetFlagBits>(const VkCommandPoolResetFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCommandPoolResetFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCompareOp>(const VkCompareOp& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkComponentSwizzle>(const VkComponentSwizzle& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkComponentTypeKHR>(const VkComponentTypeKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCompositeAlphaFlagBitsKHR>(const VkCompositeAlphaFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCompositeAlphaFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkConditionalRenderingFlagBitsEXT>(const VkConditionalRenderingFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkConditionalRenderingFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkConservativeRasterizationModeEXT>(const VkConservativeRasterizationModeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCopyAccelerationStructureModeKHR>(const VkCopyAccelerationStructureModeKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCopyMicromapModeEXT>(const VkCopyMicromapModeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCoverageModulationModeNV>(const VkCoverageModulationModeNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCoverageReductionModeNV>(const VkCoverageReductionModeNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCubicFilterWeightsQCOM>(const VkCubicFilterWeightsQCOM& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCullModeFlagBits>(const VkCullModeFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkCullModeFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDebugReportFlagBitsEXT>(const VkDebugReportFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDebugReportFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDebugReportObjectTypeEXT>(const VkDebugReportObjectTypeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDebugUtilsMessageSeverityFlagBitsEXT>(const VkDebugUtilsMessageSeverityFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDebugUtilsMessageSeverityFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDebugUtilsMessageTypeFlagBitsEXT>(const VkDebugUtilsMessageTypeFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDebugUtilsMessageTypeFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDependencyFlagBits>(const VkDependencyFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDependencyFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDepthBiasRepresentationEXT>(const VkDepthBiasRepresentationEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDepthClampModeEXT>(const VkDepthClampModeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDescriptorBindingFlagBits>(const VkDescriptorBindingFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDescriptorBindingFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDescriptorPoolCreateFlagBits>(const VkDescriptorPoolCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDescriptorPoolCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDescriptorSetLayoutCreateFlagBits>(const VkDescriptorSetLayoutCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDescriptorSetLayoutCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDescriptorType>(const VkDescriptorType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDescriptorUpdateTemplateType>(const VkDescriptorUpdateTemplateType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDeviceAddressBindingFlagBitsEXT>(const VkDeviceAddressBindingFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDeviceAddressBindingFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDeviceAddressBindingTypeEXT>(const VkDeviceAddressBindingTypeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDeviceDiagnosticsConfigFlagBitsNV>(const VkDeviceDiagnosticsConfigFlagBitsNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDeviceDiagnosticsConfigFlagBitsNV>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDeviceEventTypeEXT>(const VkDeviceEventTypeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDeviceFaultAddressTypeEXT>(const VkDeviceFaultAddressTypeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDeviceFaultVendorBinaryHeaderVersionEXT>(const VkDeviceFaultVendorBinaryHeaderVersionEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDeviceGroupPresentModeFlagBitsKHR>(const VkDeviceGroupPresentModeFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDeviceGroupPresentModeFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDeviceMemoryReportEventTypeEXT>(const VkDeviceMemoryReportEventTypeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDeviceQueueCreateFlagBits>(const VkDeviceQueueCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDeviceQueueCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDirectDriverLoadingModeLUNARG>(const VkDirectDriverLoadingModeLUNARG& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDiscardRectangleModeEXT>(const VkDiscardRectangleModeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDisplacementMicromapFormatNV>(const VkDisplacementMicromapFormatNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDisplayEventTypeEXT>(const VkDisplayEventTypeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDisplayPlaneAlphaFlagBitsKHR>(const VkDisplayPlaneAlphaFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDisplayPlaneAlphaFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDisplayPowerStateEXT>(const VkDisplayPowerStateEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDriverId>(const VkDriverId& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkDynamicState>(const VkDynamicState& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkEventCreateFlagBits>(const VkEventCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkEventCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalFenceFeatureFlagBits>(const VkExternalFenceFeatureFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalFenceFeatureFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalFenceHandleTypeFlagBits>(const VkExternalFenceHandleTypeFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalFenceHandleTypeFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalMemoryFeatureFlagBits>(const VkExternalMemoryFeatureFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalMemoryFeatureFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalMemoryFeatureFlagBitsNV>(const VkExternalMemoryFeatureFlagBitsNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalMemoryFeatureFlagBitsNV>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalMemoryHandleTypeFlagBits>(const VkExternalMemoryHandleTypeFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalMemoryHandleTypeFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalMemoryHandleTypeFlagBitsNV>(const VkExternalMemoryHandleTypeFlagBitsNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalMemoryHandleTypeFlagBitsNV>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalSemaphoreFeatureFlagBits>(const VkExternalSemaphoreFeatureFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalSemaphoreFeatureFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalSemaphoreHandleTypeFlagBits>(const VkExternalSemaphoreHandleTypeFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkExternalSemaphoreHandleTypeFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFenceCreateFlagBits>(const VkFenceCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFenceCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFenceImportFlagBits>(const VkFenceImportFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFenceImportFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFilter>(const VkFilter& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFormat>(const VkFormat& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFormatFeatureFlagBits>(const VkFormatFeatureFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFormatFeatureFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
std::string VkFormatFeatureFlagBits2ToString(const VkFormatFeatureFlagBits2 value);
std::string VkFormatFeatureFlags2ToString(VkFlags64 vkFlags);
template <> std::string ToString<VkFragmentShadingRateCombinerOpKHR>(const VkFragmentShadingRateCombinerOpKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFragmentShadingRateNV>(const VkFragmentShadingRateNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFragmentShadingRateTypeNV>(const VkFragmentShadingRateTypeNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFrameBoundaryFlagBitsEXT>(const VkFrameBoundaryFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFrameBoundaryFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFramebufferCreateFlagBits>(const VkFramebufferCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFramebufferCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFrontFace>(const VkFrontFace& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkFullScreenExclusiveEXT>(const VkFullScreenExclusiveEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkGeometryFlagBitsKHR>(const VkGeometryFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkGeometryFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkGeometryInstanceFlagBitsKHR>(const VkGeometryInstanceFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkGeometryInstanceFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkGeometryTypeKHR>(const VkGeometryTypeKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkGraphicsPipelineLibraryFlagBitsEXT>(const VkGraphicsPipelineLibraryFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkGraphicsPipelineLibraryFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkHostImageCopyFlagBitsEXT>(const VkHostImageCopyFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkHostImageCopyFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageAspectFlagBits>(const VkImageAspectFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageAspectFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageCompressionFixedRateFlagBitsEXT>(const VkImageCompressionFixedRateFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageCompressionFixedRateFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageCompressionFlagBitsEXT>(const VkImageCompressionFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageCompressionFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageCreateFlagBits>(const VkImageCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageLayout>(const VkImageLayout& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageTiling>(const VkImageTiling& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageType>(const VkImageType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageUsageFlagBits>(const VkImageUsageFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageUsageFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageViewCreateFlagBits>(const VkImageViewCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageViewCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkImageViewType>(const VkImageViewType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkIndexType>(const VkIndexType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkIndirectCommandsInputModeFlagBitsEXT>(const VkIndirectCommandsInputModeFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkIndirectCommandsInputModeFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkIndirectCommandsLayoutUsageFlagBitsEXT>(const VkIndirectCommandsLayoutUsageFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkIndirectCommandsLayoutUsageFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkIndirectCommandsLayoutUsageFlagBitsNV>(const VkIndirectCommandsLayoutUsageFlagBitsNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkIndirectCommandsLayoutUsageFlagBitsNV>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkIndirectCommandsTokenTypeEXT>(const VkIndirectCommandsTokenTypeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkIndirectCommandsTokenTypeNV>(const VkIndirectCommandsTokenTypeNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkIndirectExecutionSetInfoTypeEXT>(const VkIndirectExecutionSetInfoTypeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkIndirectStateFlagBitsNV>(const VkIndirectStateFlagBitsNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkIndirectStateFlagBitsNV>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkInstanceCreateFlagBits>(const VkInstanceCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkInstanceCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkInternalAllocationType>(const VkInternalAllocationType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkLatencyMarkerNV>(const VkLatencyMarkerNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkLayerSettingTypeEXT>(const VkLayerSettingTypeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkLayeredDriverUnderlyingApiMSFT>(const VkLayeredDriverUnderlyingApiMSFT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkLineRasterizationModeKHR>(const VkLineRasterizationModeKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkLogicOp>(const VkLogicOp& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMemoryAllocateFlagBits>(const VkMemoryAllocateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMemoryAllocateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMemoryHeapFlagBits>(const VkMemoryHeapFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMemoryHeapFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMemoryMapFlagBits>(const VkMemoryMapFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMemoryMapFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMemoryOverallocationBehaviorAMD>(const VkMemoryOverallocationBehaviorAMD& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMemoryPropertyFlagBits>(const VkMemoryPropertyFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMemoryPropertyFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMemoryUnmapFlagBitsKHR>(const VkMemoryUnmapFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMemoryUnmapFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMicromapCreateFlagBitsEXT>(const VkMicromapCreateFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMicromapCreateFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkMicromapTypeEXT>(const VkMicromapTypeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkObjectType>(const VkObjectType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkOpacityMicromapFormatEXT>(const VkOpacityMicromapFormatEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkOpacityMicromapSpecialIndexEXT>(const VkOpacityMicromapSpecialIndexEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkOpticalFlowExecuteFlagBitsNV>(const VkOpticalFlowExecuteFlagBitsNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkOpticalFlowExecuteFlagBitsNV>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkOpticalFlowGridSizeFlagBitsNV>(const VkOpticalFlowGridSizeFlagBitsNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkOpticalFlowGridSizeFlagBitsNV>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkOpticalFlowPerformanceLevelNV>(const VkOpticalFlowPerformanceLevelNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkOpticalFlowSessionBindingPointNV>(const VkOpticalFlowSessionBindingPointNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkOpticalFlowSessionCreateFlagBitsNV>(const VkOpticalFlowSessionCreateFlagBitsNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkOpticalFlowSessionCreateFlagBitsNV>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkOpticalFlowUsageFlagBitsNV>(const VkOpticalFlowUsageFlagBitsNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkOpticalFlowUsageFlagBitsNV>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkOutOfBandQueueTypeNV>(const VkOutOfBandQueueTypeNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPeerMemoryFeatureFlagBits>(const VkPeerMemoryFeatureFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPeerMemoryFeatureFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPerformanceConfigurationTypeINTEL>(const VkPerformanceConfigurationTypeINTEL& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPerformanceCounterDescriptionFlagBitsKHR>(const VkPerformanceCounterDescriptionFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPerformanceCounterDescriptionFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPerformanceCounterScopeKHR>(const VkPerformanceCounterScopeKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPerformanceCounterStorageKHR>(const VkPerformanceCounterStorageKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPerformanceCounterUnitKHR>(const VkPerformanceCounterUnitKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPerformanceOverrideTypeINTEL>(const VkPerformanceOverrideTypeINTEL& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPerformanceParameterTypeINTEL>(const VkPerformanceParameterTypeINTEL& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPerformanceValueTypeINTEL>(const VkPerformanceValueTypeINTEL& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPhysicalDeviceLayeredApiKHR>(const VkPhysicalDeviceLayeredApiKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPhysicalDeviceSchedulingControlsFlagBitsARM>(const VkPhysicalDeviceSchedulingControlsFlagBitsARM& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPhysicalDeviceSchedulingControlsFlagBitsARM>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPhysicalDeviceType>(const VkPhysicalDeviceType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineBindPoint>(const VkPipelineBindPoint& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineCacheCreateFlagBits>(const VkPipelineCacheCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineCacheCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineCacheHeaderVersion>(const VkPipelineCacheHeaderVersion& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineColorBlendStateCreateFlagBits>(const VkPipelineColorBlendStateCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineColorBlendStateCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineCompilerControlFlagBitsAMD>(const VkPipelineCompilerControlFlagBitsAMD& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineCompilerControlFlagBitsAMD>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineCreateFlagBits>(const VkPipelineCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
std::string VkPipelineCreateFlagBits2KHRToString(const VkPipelineCreateFlagBits2KHR value);
std::string VkPipelineCreateFlags2KHRToString(VkFlags64 vkFlags);
template <> std::string ToString<VkPipelineCreationFeedbackFlagBits>(const VkPipelineCreationFeedbackFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineCreationFeedbackFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineDepthStencilStateCreateFlagBits>(const VkPipelineDepthStencilStateCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineDepthStencilStateCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineExecutableStatisticFormatKHR>(const VkPipelineExecutableStatisticFormatKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineLayoutCreateFlagBits>(const VkPipelineLayoutCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineLayoutCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineRobustnessBufferBehaviorEXT>(const VkPipelineRobustnessBufferBehaviorEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineRobustnessImageBehaviorEXT>(const VkPipelineRobustnessImageBehaviorEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineShaderStageCreateFlagBits>(const VkPipelineShaderStageCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineShaderStageCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineStageFlagBits>(const VkPipelineStageFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPipelineStageFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
std::string VkPipelineStageFlagBits2ToString(const VkPipelineStageFlagBits2 value);
std::string VkPipelineStageFlags2ToString(VkFlags64 vkFlags);
template <> std::string ToString<VkPointClippingBehavior>(const VkPointClippingBehavior& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPolygonMode>(const VkPolygonMode& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPresentGravityFlagBitsEXT>(const VkPresentGravityFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPresentGravityFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPresentModeKHR>(const VkPresentModeKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPresentScalingFlagBitsEXT>(const VkPresentScalingFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPresentScalingFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkPrimitiveTopology>(const VkPrimitiveTopology& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkProvokingVertexModeEXT>(const VkProvokingVertexModeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkQueryControlFlagBits>(const VkQueryControlFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkQueryControlFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkQueryPipelineStatisticFlagBits>(const VkQueryPipelineStatisticFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkQueryPipelineStatisticFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkQueryPoolSamplingModeINTEL>(const VkQueryPoolSamplingModeINTEL& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkQueryResultFlagBits>(const VkQueryResultFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkQueryResultFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkQueryResultStatusKHR>(const VkQueryResultStatusKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkQueryType>(const VkQueryType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkQueueFlagBits>(const VkQueueFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkQueueFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkQueueGlobalPriorityKHR>(const VkQueueGlobalPriorityKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkRasterizationOrderAMD>(const VkRasterizationOrderAMD& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkRayTracingInvocationReorderModeNV>(const VkRayTracingInvocationReorderModeNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkRayTracingShaderGroupTypeKHR>(const VkRayTracingShaderGroupTypeKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkRenderPassCreateFlagBits>(const VkRenderPassCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkRenderPassCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkRenderingFlagBits>(const VkRenderingFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkRenderingFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkResolveModeFlagBits>(const VkResolveModeFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkResolveModeFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkResult>(const VkResult& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSampleCountFlagBits>(const VkSampleCountFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSampleCountFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSamplerAddressMode>(const VkSamplerAddressMode& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSamplerCreateFlagBits>(const VkSamplerCreateFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSamplerCreateFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSamplerMipmapMode>(const VkSamplerMipmapMode& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSamplerReductionMode>(const VkSamplerReductionMode& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSamplerYcbcrModelConversion>(const VkSamplerYcbcrModelConversion& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSamplerYcbcrRange>(const VkSamplerYcbcrRange& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkScopeKHR>(const VkScopeKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSemaphoreImportFlagBits>(const VkSemaphoreImportFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSemaphoreImportFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSemaphoreType>(const VkSemaphoreType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSemaphoreWaitFlagBits>(const VkSemaphoreWaitFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSemaphoreWaitFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkShaderCodeTypeEXT>(const VkShaderCodeTypeEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkShaderCorePropertiesFlagBitsAMD>(const VkShaderCorePropertiesFlagBitsAMD& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkShaderCorePropertiesFlagBitsAMD>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkShaderCreateFlagBitsEXT>(const VkShaderCreateFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkShaderCreateFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkShaderFloatControlsIndependence>(const VkShaderFloatControlsIndependence& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkShaderGroupShaderKHR>(const VkShaderGroupShaderKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkShaderInfoTypeAMD>(const VkShaderInfoTypeAMD& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkShaderStageFlagBits>(const VkShaderStageFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkShaderStageFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkShadingRatePaletteEntryNV>(const VkShadingRatePaletteEntryNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSharingMode>(const VkSharingMode& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSparseImageFormatFlagBits>(const VkSparseImageFormatFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSparseImageFormatFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSparseMemoryBindFlagBits>(const VkSparseMemoryBindFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSparseMemoryBindFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkStencilFaceFlagBits>(const VkStencilFaceFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkStencilFaceFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkStencilOp>(const VkStencilOp& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkStructureType>(const VkStructureType& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSubgroupFeatureFlagBits>(const VkSubgroupFeatureFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSubgroupFeatureFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSubmitFlagBits>(const VkSubmitFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSubmitFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSubpassContents>(const VkSubpassContents& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSubpassDescriptionFlagBits>(const VkSubpassDescriptionFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSubpassDescriptionFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSubpassMergeStatusEXT>(const VkSubpassMergeStatusEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSurfaceCounterFlagBitsEXT>(const VkSurfaceCounterFlagBitsEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSurfaceCounterFlagBitsEXT>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSurfaceTransformFlagBitsKHR>(const VkSurfaceTransformFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSurfaceTransformFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSwapchainCreateFlagBitsKHR>(const VkSwapchainCreateFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSwapchainCreateFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkSystemAllocationScope>(const VkSystemAllocationScope& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkTessellationDomainOrigin>(const VkTessellationDomainOrigin& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkTimeDomainKHR>(const VkTimeDomainKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkToolPurposeFlagBits>(const VkToolPurposeFlagBits& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkToolPurposeFlagBits>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkValidationCacheHeaderVersionEXT>(const VkValidationCacheHeaderVersionEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkValidationCheckEXT>(const VkValidationCheckEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkValidationFeatureDisableEXT>(const VkValidationFeatureDisableEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkValidationFeatureEnableEXT>(const VkValidationFeatureEnableEXT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVendorId>(const VkVendorId& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVertexInputRate>(const VkVertexInputRate& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoCapabilityFlagBitsKHR>(const VkVideoCapabilityFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoCapabilityFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoChromaSubsamplingFlagBitsKHR>(const VkVideoChromaSubsamplingFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoChromaSubsamplingFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoCodecOperationFlagBitsKHR>(const VkVideoCodecOperationFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoCodecOperationFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoCodingControlFlagBitsKHR>(const VkVideoCodingControlFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoCodingControlFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoComponentBitDepthFlagBitsKHR>(const VkVideoComponentBitDepthFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoComponentBitDepthFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoDecodeCapabilityFlagBitsKHR>(const VkVideoDecodeCapabilityFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoDecodeCapabilityFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoDecodeH264PictureLayoutFlagBitsKHR>(const VkVideoDecodeH264PictureLayoutFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoDecodeH264PictureLayoutFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoDecodeUsageFlagBitsKHR>(const VkVideoDecodeUsageFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoDecodeUsageFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeCapabilityFlagBitsKHR>(const VkVideoEncodeCapabilityFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeCapabilityFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeContentFlagBitsKHR>(const VkVideoEncodeContentFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeContentFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeFeedbackFlagBitsKHR>(const VkVideoEncodeFeedbackFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeFeedbackFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH264CapabilityFlagBitsKHR>(const VkVideoEncodeH264CapabilityFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH264CapabilityFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH264RateControlFlagBitsKHR>(const VkVideoEncodeH264RateControlFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH264RateControlFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH264StdFlagBitsKHR>(const VkVideoEncodeH264StdFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH264StdFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH265CapabilityFlagBitsKHR>(const VkVideoEncodeH265CapabilityFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH265CapabilityFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH265CtbSizeFlagBitsKHR>(const VkVideoEncodeH265CtbSizeFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH265CtbSizeFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH265RateControlFlagBitsKHR>(const VkVideoEncodeH265RateControlFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH265RateControlFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH265StdFlagBitsKHR>(const VkVideoEncodeH265StdFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH265StdFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH265TransformBlockSizeFlagBitsKHR>(const VkVideoEncodeH265TransformBlockSizeFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeH265TransformBlockSizeFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeRateControlModeFlagBitsKHR>(const VkVideoEncodeRateControlModeFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeRateControlModeFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeTuningModeKHR>(const VkVideoEncodeTuningModeKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeUsageFlagBitsKHR>(const VkVideoEncodeUsageFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoEncodeUsageFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoSessionCreateFlagBitsKHR>(const VkVideoSessionCreateFlagBitsKHR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkVideoSessionCreateFlagBitsKHR>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<VkViewportCoordinateSwizzleNV>(const VkViewportCoordinateSwizzleNV& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
