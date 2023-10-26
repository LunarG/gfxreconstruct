/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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

#include "generated_vulkan_enum_to_json.h"
#include "generated_vulkan_enum_to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)


void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoDecodeH264FieldOrderCount& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264AspectRatioIdc& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264CabacInitIdc& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264ChromaFormatIdc& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264DisableDeblockingFilterIdc& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264LevelIdc& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264MemMgmtControlOp& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264ModificationOfPicNumsIdc& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264NonVclNaluType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264PictureType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264PocType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264ProfileIdc& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264SliceType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264WeightedBipredIdc& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH265AspectRatioIdc& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH265ChromaFormatIdc& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH265LevelIdc& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH265PictureType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH265ProfileIdc& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH265SliceType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureBuildTypeKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureCompatibilityKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureCreateFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureMemoryRequirementsTypeNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureMotionInstanceTypeNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureTypeKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccessFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(VkAccessFlagBits2_t, nlohmann::ordered_json& jdata, const VkAccessFlagBits2& value, const JsonOptions& options)
{
    jdata = util::VkAccessFlagBits2ToString(static_cast<VkAccessFlagBits2>(value));
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAcquireProfilingLockFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAttachmentDescriptionFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAttachmentLoadOp& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAttachmentStoreOp& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBlendFactor& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBlendOp& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBlendOverlapEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBlockMatchWindowCompareModeQCOM& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBorderColor& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBufferCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBufferUsageFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(VkBufferUsageFlagBits2KHR_t, nlohmann::ordered_json& jdata, const VkBufferUsageFlagBits2KHR& value, const JsonOptions& options)
{
    jdata = util::VkBufferUsageFlagBits2KHRToString(static_cast<VkBufferUsageFlagBits2KHR>(value));
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBuildAccelerationStructureFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBuildAccelerationStructureModeKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBuildMicromapFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBuildMicromapModeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkChromaLocation& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCoarseSampleOrderTypeNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkColorComponentFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkColorSpaceKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCommandBufferLevel& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCommandBufferResetFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCommandBufferUsageFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCommandPoolCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCommandPoolResetFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCompareOp& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkComponentSwizzle& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkComponentTypeKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCompositeAlphaFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkConditionalRenderingFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkConservativeRasterizationModeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCopyAccelerationStructureModeKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCopyMicromapModeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCoverageModulationModeNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCoverageReductionModeNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCubicFilterWeightsQCOM& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCullModeFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDebugReportFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDebugReportObjectTypeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDebugUtilsMessageSeverityFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDebugUtilsMessageTypeFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDependencyFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDepthBiasRepresentationEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDescriptorBindingFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDescriptorPoolCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDescriptorSetLayoutCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDescriptorType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDescriptorUpdateTemplateType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceAddressBindingFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceAddressBindingTypeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceDiagnosticsConfigFlagBitsNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceEventTypeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceFaultAddressTypeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceFaultVendorBinaryHeaderVersionEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceGroupPresentModeFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceMemoryReportEventTypeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceQueueCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDirectDriverLoadingModeLUNARG& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDiscardRectangleModeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDisplacementMicromapFormatNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDisplayEventTypeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDisplayPlaneAlphaFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDisplayPowerStateEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDriverId& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDynamicState& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkEventCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalFenceFeatureFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalFenceHandleTypeFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalMemoryFeatureFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalMemoryFeatureFlagBitsNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalMemoryHandleTypeFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalMemoryHandleTypeFlagBitsNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalSemaphoreFeatureFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalSemaphoreHandleTypeFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFenceCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFenceImportFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFilter& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFormat& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFormatFeatureFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(VkFormatFeatureFlagBits2_t, nlohmann::ordered_json& jdata, const VkFormatFeatureFlagBits2& value, const JsonOptions& options)
{
    jdata = util::VkFormatFeatureFlagBits2ToString(static_cast<VkFormatFeatureFlagBits2>(value));
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFragmentShadingRateCombinerOpKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFragmentShadingRateNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFragmentShadingRateTypeNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFrameBoundaryFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFramebufferCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFrontFace& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFullScreenExclusiveEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkGeometryFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkGeometryInstanceFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkGeometryTypeKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkGraphicsPipelineLibraryFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkHostImageCopyFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageAspectFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageCompressionFixedRateFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageCompressionFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageLayout& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageTiling& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageUsageFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageViewCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageViewType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkIndexType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkIndirectCommandsLayoutUsageFlagBitsNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkIndirectCommandsTokenTypeNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkIndirectStateFlagBitsNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkInstanceCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkInternalAllocationType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkLayeredDriverUnderlyingApiMSFT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkLineRasterizationModeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkLogicOp& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMemoryAllocateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMemoryHeapFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMemoryOverallocationBehaviorAMD& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMemoryPropertyFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMicromapCreateFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMicromapTypeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkObjectType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpacityMicromapFormatEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpacityMicromapSpecialIndexEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowExecuteFlagBitsNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowGridSizeFlagBitsNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowPerformanceLevelNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowSessionBindingPointNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowSessionCreateFlagBitsNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowUsageFlagBitsNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPeerMemoryFeatureFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceConfigurationTypeINTEL& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceCounterDescriptionFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceCounterScopeKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceCounterStorageKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceCounterUnitKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceOverrideTypeINTEL& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceParameterTypeINTEL& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceValueTypeINTEL& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPhysicalDeviceType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineBindPoint& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineCacheCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineCacheHeaderVersion& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineColorBlendStateCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineCompilerControlFlagBitsAMD& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(VkPipelineCreateFlagBits2KHR_t, nlohmann::ordered_json& jdata, const VkPipelineCreateFlagBits2KHR& value, const JsonOptions& options)
{
    jdata = util::VkPipelineCreateFlagBits2KHRToString(static_cast<VkPipelineCreateFlagBits2KHR>(value));
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineCreationFeedbackFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineDepthStencilStateCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineExecutableStatisticFormatKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineLayoutCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineRobustnessBufferBehaviorEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineRobustnessImageBehaviorEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineShaderStageCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineStageFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(VkPipelineStageFlagBits2_t, nlohmann::ordered_json& jdata, const VkPipelineStageFlagBits2& value, const JsonOptions& options)
{
    jdata = util::VkPipelineStageFlagBits2ToString(static_cast<VkPipelineStageFlagBits2>(value));
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPointClippingBehavior& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPolygonMode& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPresentGravityFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPresentModeKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPresentScalingFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPrimitiveTopology& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkProvokingVertexModeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryControlFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryPipelineStatisticFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryPoolSamplingModeINTEL& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryResultFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryResultStatusKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueueFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueueGlobalPriorityKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkRasterizationOrderAMD& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkRayTracingInvocationReorderModeNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkRayTracingShaderGroupTypeKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkRenderPassCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkRenderingFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkResolveModeFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkResult& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSampleCountFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerAddressMode& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerCreateFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerMipmapMode& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerReductionMode& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerYcbcrModelConversion& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerYcbcrRange& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkScopeKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSemaphoreImportFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSemaphoreType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSemaphoreWaitFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderCodeTypeEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderCorePropertiesFlagBitsAMD& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderCreateFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderFloatControlsIndependence& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderGroupShaderKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderInfoTypeAMD& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderStageFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShadingRatePaletteEntryNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSharingMode& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSparseImageFormatFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSparseMemoryBindFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkStencilFaceFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkStencilOp& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkStructureType& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSubgroupFeatureFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSubmitFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSubpassContents& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSubpassDescriptionFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSubpassMergeStatusEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSurfaceCounterFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSurfaceTransformFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSwapchainCreateFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSystemAllocationScope& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkTessellationDomainOrigin& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkTimeDomainEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkToolPurposeFlagBits& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkValidationCacheHeaderVersionEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkValidationCheckEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkValidationFeatureDisableEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkValidationFeatureEnableEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVendorId& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVertexInputRate& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoCapabilityFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoChromaSubsamplingFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoCodecOperationFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoCodingControlFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoComponentBitDepthFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoDecodeCapabilityFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoDecodeH264PictureLayoutFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoDecodeUsageFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeCapabilityFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeContentFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeFeedbackFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH264CapabilityFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH264RateControlFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH264StdFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH265CapabilityFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH265CtbSizeFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH265RateControlFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH265StdFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH265TransformBlockSizeFlagBitsEXT& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeRateControlModeFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeTuningModeKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeUsageFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoSessionCreateFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkViewportCoordinateSwizzleNV& value, const JsonOptions& options)
{
    jdata = util::ToString(value);
}

void FieldToJson(VkAccelerationStructureCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkAccelerationStructureCreateFlagsKHR>(flags));
}

void FieldToJson(VkAccelerationStructureMotionInfoFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkAccelerationStructureMotionInfoFlagsNV>(flags));
}

void FieldToJson(VkAccelerationStructureMotionInstanceFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkAccelerationStructureMotionInstanceFlagsNV>(flags));
}

void FieldToJson(VkAccessFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkAccessFlags>(flags));
}

void FieldToJson(VkAccessFlags2_t, nlohmann::ordered_json& jdata, const VkFlags64 flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkAccessFlags2>(flags));
}

void FieldToJson(VkAcquireProfilingLockFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkAcquireProfilingLockFlagsKHR>(flags));
}

void FieldToJson(VkAndroidSurfaceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkAndroidSurfaceCreateFlagsKHR>(flags));
}

void FieldToJson(VkAttachmentDescriptionFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkAttachmentDescriptionFlags>(flags));
}

void FieldToJson(VkBufferCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkBufferCreateFlags>(flags));
}

void FieldToJson(VkBufferUsageFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkBufferUsageFlags>(flags));
}

void FieldToJson(VkBufferUsageFlags2KHR_t, nlohmann::ordered_json& jdata, const VkFlags64 flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkBufferUsageFlags2KHR>(flags));
}

void FieldToJson(VkBufferViewCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkBufferViewCreateFlags>(flags));
}

void FieldToJson(VkBuildAccelerationStructureFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkBuildAccelerationStructureFlagsKHR>(flags));
}

void FieldToJson(VkBuildMicromapFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkBuildMicromapFlagsEXT>(flags));
}

void FieldToJson(VkColorComponentFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkColorComponentFlags>(flags));
}

void FieldToJson(VkCommandBufferResetFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkCommandBufferResetFlags>(flags));
}

void FieldToJson(VkCommandBufferUsageFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkCommandBufferUsageFlags>(flags));
}

void FieldToJson(VkCommandPoolCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkCommandPoolCreateFlags>(flags));
}

void FieldToJson(VkCommandPoolResetFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkCommandPoolResetFlags>(flags));
}

void FieldToJson(VkCommandPoolTrimFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkCommandPoolTrimFlags>(flags));
}

void FieldToJson(VkCompositeAlphaFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkCompositeAlphaFlagsKHR>(flags));
}

void FieldToJson(VkConditionalRenderingFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkConditionalRenderingFlagsEXT>(flags));
}

void FieldToJson(VkCullModeFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkCullModeFlags>(flags));
}

void FieldToJson(VkDebugReportFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDebugReportFlagsEXT>(flags));
}

void FieldToJson(VkDebugUtilsMessageSeverityFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDebugUtilsMessageSeverityFlagsEXT>(flags));
}

void FieldToJson(VkDebugUtilsMessageTypeFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDebugUtilsMessageTypeFlagsEXT>(flags));
}

void FieldToJson(VkDebugUtilsMessengerCallbackDataFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDebugUtilsMessengerCallbackDataFlagsEXT>(flags));
}

void FieldToJson(VkDebugUtilsMessengerCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDebugUtilsMessengerCreateFlagsEXT>(flags));
}

void FieldToJson(VkDependencyFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDependencyFlags>(flags));
}

void FieldToJson(VkDescriptorBindingFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDescriptorBindingFlags>(flags));
}

void FieldToJson(VkDescriptorPoolCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDescriptorPoolCreateFlags>(flags));
}

void FieldToJson(VkDescriptorPoolResetFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDescriptorPoolResetFlags>(flags));
}

void FieldToJson(VkDescriptorSetLayoutCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDescriptorSetLayoutCreateFlags>(flags));
}

void FieldToJson(VkDescriptorUpdateTemplateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDescriptorUpdateTemplateCreateFlags>(flags));
}

void FieldToJson(VkDeviceAddressBindingFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDeviceAddressBindingFlagsEXT>(flags));
}

void FieldToJson(VkDeviceCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDeviceCreateFlags>(flags));
}

void FieldToJson(VkDeviceDiagnosticsConfigFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDeviceDiagnosticsConfigFlagsNV>(flags));
}

void FieldToJson(VkDeviceGroupPresentModeFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDeviceGroupPresentModeFlagsKHR>(flags));
}

void FieldToJson(VkDeviceMemoryReportFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDeviceMemoryReportFlagsEXT>(flags));
}

void FieldToJson(VkDeviceQueueCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDeviceQueueCreateFlags>(flags));
}

void FieldToJson(VkDirectDriverLoadingFlagsLUNARG_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDirectDriverLoadingFlagsLUNARG>(flags));
}

void FieldToJson(VkDirectFBSurfaceCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDirectFBSurfaceCreateFlagsEXT>(flags));
}

void FieldToJson(VkDisplayModeCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDisplayModeCreateFlagsKHR>(flags));
}

void FieldToJson(VkDisplayPlaneAlphaFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDisplayPlaneAlphaFlagsKHR>(flags));
}

void FieldToJson(VkDisplaySurfaceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkDisplaySurfaceCreateFlagsKHR>(flags));
}

void FieldToJson(VkEventCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkEventCreateFlags>(flags));
}

void FieldToJson(VkExternalFenceFeatureFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkExternalFenceFeatureFlags>(flags));
}

void FieldToJson(VkExternalFenceHandleTypeFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkExternalFenceHandleTypeFlags>(flags));
}

void FieldToJson(VkExternalMemoryFeatureFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkExternalMemoryFeatureFlags>(flags));
}

void FieldToJson(VkExternalMemoryFeatureFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkExternalMemoryFeatureFlagsNV>(flags));
}

void FieldToJson(VkExternalMemoryHandleTypeFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkExternalMemoryHandleTypeFlags>(flags));
}

void FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkExternalMemoryHandleTypeFlagsNV>(flags));
}

void FieldToJson(VkExternalSemaphoreFeatureFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkExternalSemaphoreFeatureFlags>(flags));
}

void FieldToJson(VkExternalSemaphoreHandleTypeFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkExternalSemaphoreHandleTypeFlags>(flags));
}

void FieldToJson(VkFenceCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkFenceCreateFlags>(flags));
}

void FieldToJson(VkFenceImportFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkFenceImportFlags>(flags));
}

void FieldToJson(VkFormatFeatureFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkFormatFeatureFlags>(flags));
}

void FieldToJson(VkFormatFeatureFlags2_t, nlohmann::ordered_json& jdata, const VkFlags64 flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkFormatFeatureFlags2>(flags));
}

void FieldToJson(VkFrameBoundaryFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkFrameBoundaryFlagsEXT>(flags));
}

void FieldToJson(VkFramebufferCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkFramebufferCreateFlags>(flags));
}

void FieldToJson(VkGeometryFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkGeometryFlagsKHR>(flags));
}

void FieldToJson(VkGeometryInstanceFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkGeometryInstanceFlagsKHR>(flags));
}

void FieldToJson(VkGraphicsPipelineLibraryFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkGraphicsPipelineLibraryFlagsEXT>(flags));
}

void FieldToJson(VkHeadlessSurfaceCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkHeadlessSurfaceCreateFlagsEXT>(flags));
}

void FieldToJson(VkHostImageCopyFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkHostImageCopyFlagsEXT>(flags));
}

void FieldToJson(VkIOSSurfaceCreateFlagsMVK_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkIOSSurfaceCreateFlagsMVK>(flags));
}

void FieldToJson(VkImageAspectFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkImageAspectFlags>(flags));
}

void FieldToJson(VkImageCompressionFixedRateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkImageCompressionFixedRateFlagsEXT>(flags));
}

void FieldToJson(VkImageCompressionFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkImageCompressionFlagsEXT>(flags));
}

void FieldToJson(VkImageCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkImageCreateFlags>(flags));
}

void FieldToJson(VkImagePipeSurfaceCreateFlagsFUCHSIA_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkImagePipeSurfaceCreateFlagsFUCHSIA>(flags));
}

void FieldToJson(VkImageUsageFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkImageUsageFlags>(flags));
}

void FieldToJson(VkImageViewCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkImageViewCreateFlags>(flags));
}

void FieldToJson(VkIndirectCommandsLayoutUsageFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkIndirectCommandsLayoutUsageFlagsNV>(flags));
}

void FieldToJson(VkIndirectStateFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkIndirectStateFlagsNV>(flags));
}

void FieldToJson(VkInstanceCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkInstanceCreateFlags>(flags));
}

void FieldToJson(VkMacOSSurfaceCreateFlagsMVK_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkMacOSSurfaceCreateFlagsMVK>(flags));
}

void FieldToJson(VkMemoryAllocateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkMemoryAllocateFlags>(flags));
}

void FieldToJson(VkMemoryHeapFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkMemoryHeapFlags>(flags));
}

void FieldToJson(VkMemoryMapFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkMemoryMapFlags>(flags));
}

void FieldToJson(VkMemoryPropertyFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkMemoryPropertyFlags>(flags));
}

void FieldToJson(VkMemoryUnmapFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkMemoryUnmapFlagsKHR>(flags));
}

void FieldToJson(VkMetalSurfaceCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkMetalSurfaceCreateFlagsEXT>(flags));
}

void FieldToJson(VkMicromapCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkMicromapCreateFlagsEXT>(flags));
}

void FieldToJson(VkOpticalFlowExecuteFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkOpticalFlowExecuteFlagsNV>(flags));
}

void FieldToJson(VkOpticalFlowGridSizeFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkOpticalFlowGridSizeFlagsNV>(flags));
}

void FieldToJson(VkOpticalFlowSessionCreateFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkOpticalFlowSessionCreateFlagsNV>(flags));
}

void FieldToJson(VkOpticalFlowUsageFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkOpticalFlowUsageFlagsNV>(flags));
}

void FieldToJson(VkPeerMemoryFeatureFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPeerMemoryFeatureFlags>(flags));
}

void FieldToJson(VkPerformanceCounterDescriptionFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPerformanceCounterDescriptionFlagsKHR>(flags));
}

void FieldToJson(VkPipelineCacheCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineCacheCreateFlags>(flags));
}

void FieldToJson(VkPipelineColorBlendStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineColorBlendStateCreateFlags>(flags));
}

void FieldToJson(VkPipelineCompilerControlFlagsAMD_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineCompilerControlFlagsAMD>(flags));
}

void FieldToJson(VkPipelineCoverageModulationStateCreateFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineCoverageModulationStateCreateFlagsNV>(flags));
}

void FieldToJson(VkPipelineCoverageReductionStateCreateFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineCoverageReductionStateCreateFlagsNV>(flags));
}

void FieldToJson(VkPipelineCoverageToColorStateCreateFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineCoverageToColorStateCreateFlagsNV>(flags));
}

void FieldToJson(VkPipelineCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineCreateFlags>(flags));
}

void FieldToJson(VkPipelineCreateFlags2KHR_t, nlohmann::ordered_json& jdata, const VkFlags64 flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineCreateFlags2KHR>(flags));
}

void FieldToJson(VkPipelineCreationFeedbackFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineCreationFeedbackFlags>(flags));
}

void FieldToJson(VkPipelineDepthStencilStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineDepthStencilStateCreateFlags>(flags));
}

void FieldToJson(VkPipelineDiscardRectangleStateCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineDiscardRectangleStateCreateFlagsEXT>(flags));
}

void FieldToJson(VkPipelineDynamicStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineDynamicStateCreateFlags>(flags));
}

void FieldToJson(VkPipelineInputAssemblyStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineInputAssemblyStateCreateFlags>(flags));
}

void FieldToJson(VkPipelineLayoutCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineLayoutCreateFlags>(flags));
}

void FieldToJson(VkPipelineMultisampleStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineMultisampleStateCreateFlags>(flags));
}

void FieldToJson(VkPipelineRasterizationConservativeStateCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineRasterizationConservativeStateCreateFlagsEXT>(flags));
}

void FieldToJson(VkPipelineRasterizationDepthClipStateCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineRasterizationDepthClipStateCreateFlagsEXT>(flags));
}

void FieldToJson(VkPipelineRasterizationStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineRasterizationStateCreateFlags>(flags));
}

void FieldToJson(VkPipelineRasterizationStateStreamCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineRasterizationStateStreamCreateFlagsEXT>(flags));
}

void FieldToJson(VkPipelineShaderStageCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineShaderStageCreateFlags>(flags));
}

void FieldToJson(VkPipelineStageFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineStageFlags>(flags));
}

void FieldToJson(VkPipelineStageFlags2_t, nlohmann::ordered_json& jdata, const VkFlags64 flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineStageFlags2>(flags));
}

void FieldToJson(VkPipelineTessellationStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineTessellationStateCreateFlags>(flags));
}

void FieldToJson(VkPipelineVertexInputStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineVertexInputStateCreateFlags>(flags));
}

void FieldToJson(VkPipelineViewportStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineViewportStateCreateFlags>(flags));
}

void FieldToJson(VkPipelineViewportSwizzleStateCreateFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPipelineViewportSwizzleStateCreateFlagsNV>(flags));
}

void FieldToJson(VkPresentGravityFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPresentGravityFlagsEXT>(flags));
}

void FieldToJson(VkPresentScalingFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPresentScalingFlagsEXT>(flags));
}

void FieldToJson(VkPrivateDataSlotCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkPrivateDataSlotCreateFlags>(flags));
}

void FieldToJson(VkQueryControlFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkQueryControlFlags>(flags));
}

void FieldToJson(VkQueryPipelineStatisticFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkQueryPipelineStatisticFlags>(flags));
}

void FieldToJson(VkQueryPoolCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkQueryPoolCreateFlags>(flags));
}

void FieldToJson(VkQueryResultFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkQueryResultFlags>(flags));
}

void FieldToJson(VkQueueFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkQueueFlags>(flags));
}

void FieldToJson(VkRenderPassCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkRenderPassCreateFlags>(flags));
}

void FieldToJson(VkRenderingFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkRenderingFlags>(flags));
}

void FieldToJson(VkResolveModeFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkResolveModeFlags>(flags));
}

void FieldToJson(VkSampleCountFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkSampleCountFlags>(flags));
}

void FieldToJson(VkSamplerCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkSamplerCreateFlags>(flags));
}

void FieldToJson(VkScreenSurfaceCreateFlagsQNX_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkScreenSurfaceCreateFlagsQNX>(flags));
}

void FieldToJson(VkSemaphoreCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkSemaphoreCreateFlags>(flags));
}

void FieldToJson(VkSemaphoreImportFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkSemaphoreImportFlags>(flags));
}

void FieldToJson(VkSemaphoreWaitFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkSemaphoreWaitFlags>(flags));
}

void FieldToJson(VkShaderCorePropertiesFlagsAMD_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkShaderCorePropertiesFlagsAMD>(flags));
}

void FieldToJson(VkShaderCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkShaderCreateFlagsEXT>(flags));
}

void FieldToJson(VkShaderModuleCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkShaderModuleCreateFlags>(flags));
}

void FieldToJson(VkShaderStageFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkShaderStageFlags>(flags));
}

void FieldToJson(VkSparseImageFormatFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkSparseImageFormatFlags>(flags));
}

void FieldToJson(VkSparseMemoryBindFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkSparseMemoryBindFlags>(flags));
}

void FieldToJson(VkStencilFaceFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkStencilFaceFlags>(flags));
}

void FieldToJson(VkStreamDescriptorSurfaceCreateFlagsGGP_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkStreamDescriptorSurfaceCreateFlagsGGP>(flags));
}

void FieldToJson(VkSubgroupFeatureFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkSubgroupFeatureFlags>(flags));
}

void FieldToJson(VkSubmitFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkSubmitFlags>(flags));
}

void FieldToJson(VkSubpassDescriptionFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkSubpassDescriptionFlags>(flags));
}

void FieldToJson(VkSurfaceCounterFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkSurfaceCounterFlagsEXT>(flags));
}

void FieldToJson(VkSurfaceTransformFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkSurfaceTransformFlagsKHR>(flags));
}

void FieldToJson(VkSwapchainCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkSwapchainCreateFlagsKHR>(flags));
}

void FieldToJson(VkToolPurposeFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkToolPurposeFlags>(flags));
}

void FieldToJson(VkValidationCacheCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkValidationCacheCreateFlagsEXT>(flags));
}

void FieldToJson(VkViSurfaceCreateFlagsNN_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkViSurfaceCreateFlagsNN>(flags));
}

void FieldToJson(VkVideoBeginCodingFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoBeginCodingFlagsKHR>(flags));
}

void FieldToJson(VkVideoCapabilityFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoCapabilityFlagsKHR>(flags));
}

void FieldToJson(VkVideoChromaSubsamplingFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoChromaSubsamplingFlagsKHR>(flags));
}

void FieldToJson(VkVideoCodecOperationFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoCodecOperationFlagsKHR>(flags));
}

void FieldToJson(VkVideoCodingControlFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoCodingControlFlagsKHR>(flags));
}

void FieldToJson(VkVideoComponentBitDepthFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoComponentBitDepthFlagsKHR>(flags));
}

void FieldToJson(VkVideoDecodeCapabilityFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoDecodeCapabilityFlagsKHR>(flags));
}

void FieldToJson(VkVideoDecodeFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoDecodeFlagsKHR>(flags));
}

void FieldToJson(VkVideoDecodeH264PictureLayoutFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoDecodeH264PictureLayoutFlagsKHR>(flags));
}

void FieldToJson(VkVideoDecodeUsageFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoDecodeUsageFlagsKHR>(flags));
}

void FieldToJson(VkVideoEncodeCapabilityFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeCapabilityFlagsKHR>(flags));
}

void FieldToJson(VkVideoEncodeContentFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeContentFlagsKHR>(flags));
}

void FieldToJson(VkVideoEncodeFeedbackFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeFeedbackFlagsKHR>(flags));
}

void FieldToJson(VkVideoEncodeFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeFlagsKHR>(flags));
}

void FieldToJson(VkVideoEncodeH264CapabilityFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeH264CapabilityFlagsEXT>(flags));
}

void FieldToJson(VkVideoEncodeH264RateControlFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeH264RateControlFlagsEXT>(flags));
}

void FieldToJson(VkVideoEncodeH264StdFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeH264StdFlagsEXT>(flags));
}

void FieldToJson(VkVideoEncodeH265CapabilityFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeH265CapabilityFlagsEXT>(flags));
}

void FieldToJson(VkVideoEncodeH265CtbSizeFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeH265CtbSizeFlagsEXT>(flags));
}

void FieldToJson(VkVideoEncodeH265RateControlFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeH265RateControlFlagsEXT>(flags));
}

void FieldToJson(VkVideoEncodeH265StdFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeH265StdFlagsEXT>(flags));
}

void FieldToJson(VkVideoEncodeH265TransformBlockSizeFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeH265TransformBlockSizeFlagsEXT>(flags));
}

void FieldToJson(VkVideoEncodeRateControlFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeRateControlFlagsKHR>(flags));
}

void FieldToJson(VkVideoEncodeRateControlModeFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeRateControlModeFlagsKHR>(flags));
}

void FieldToJson(VkVideoEncodeUsageFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEncodeUsageFlagsKHR>(flags));
}

void FieldToJson(VkVideoEndCodingFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoEndCodingFlagsKHR>(flags));
}

void FieldToJson(VkVideoSessionCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoSessionCreateFlagsKHR>(flags));
}

void FieldToJson(VkVideoSessionParametersCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkVideoSessionParametersCreateFlagsKHR>(flags));
}

void FieldToJson(VkWaylandSurfaceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkWaylandSurfaceCreateFlagsKHR>(flags));
}

void FieldToJson(VkWin32SurfaceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkWin32SurfaceCreateFlagsKHR>(flags));
}

void FieldToJson(VkXcbSurfaceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkXcbSurfaceCreateFlagsKHR>(flags));
}

void FieldToJson(VkXlibSurfaceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = util::ToString(static_cast<VkXlibSurfaceCreateFlagsKHR>(flags));
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
