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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include <cmath>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/custom_struct_encoders.h"
#include "format/parameter_encoder.h"
#include "format/struct_pointer_encoder.h"

#include "generated/generated_struct_encoder_declarations.inc"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)

size_t encode_pnext_struct(format::ParameterEncoder* encoder, const void* value);

size_t encode_struct(format::ParameterEncoder* encoder, const VkApplicationInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeString(value.pApplicationName);
    result += encoder->EncodeUInt32Value(value.applicationVersion);
    result += encoder->EncodeString(value.pEngineName);
    result += encoder->EncodeUInt32Value(value.engineVersion);
    result += encoder->EncodeUInt32Value(value.apiVersion);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkInstanceCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encode_struct_ptr(encoder, value.pApplicationInfo);
    result += encoder->EncodeUInt32Value(value.enabledLayerCount);
    result += encoder->EncodeStringArray(value.ppEnabledLayerNames, value.enabledLayerCount);
    result += encoder->EncodeUInt32Value(value.enabledExtensionCount);
    result += encoder->EncodeStringArray(value.ppEnabledExtensionNames, value.enabledExtensionCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkAllocationCallbacks& value)
{
    size_t result = 0;
    result += encoder->EncodeVoidPtr(value.pUserData);
    result += encoder->EncodeFunctionPtr(value.pfnAllocation);
    result += encoder->EncodeFunctionPtr(value.pfnReallocation);
    result += encoder->EncodeFunctionPtr(value.pfnFree);
    result += encoder->EncodeFunctionPtr(value.pfnInternalAllocation);
    result += encoder->EncodeFunctionPtr(value.pfnInternalFree);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceFeatures& value)
{
    size_t result = 0;
    result += encoder->EncodeVkBool32Value(value.robustBufferAccess);
    result += encoder->EncodeVkBool32Value(value.fullDrawIndexUint32);
    result += encoder->EncodeVkBool32Value(value.imageCubeArray);
    result += encoder->EncodeVkBool32Value(value.independentBlend);
    result += encoder->EncodeVkBool32Value(value.geometryShader);
    result += encoder->EncodeVkBool32Value(value.tessellationShader);
    result += encoder->EncodeVkBool32Value(value.sampleRateShading);
    result += encoder->EncodeVkBool32Value(value.dualSrcBlend);
    result += encoder->EncodeVkBool32Value(value.logicOp);
    result += encoder->EncodeVkBool32Value(value.multiDrawIndirect);
    result += encoder->EncodeVkBool32Value(value.drawIndirectFirstInstance);
    result += encoder->EncodeVkBool32Value(value.depthClamp);
    result += encoder->EncodeVkBool32Value(value.depthBiasClamp);
    result += encoder->EncodeVkBool32Value(value.fillModeNonSolid);
    result += encoder->EncodeVkBool32Value(value.depthBounds);
    result += encoder->EncodeVkBool32Value(value.wideLines);
    result += encoder->EncodeVkBool32Value(value.largePoints);
    result += encoder->EncodeVkBool32Value(value.alphaToOne);
    result += encoder->EncodeVkBool32Value(value.multiViewport);
    result += encoder->EncodeVkBool32Value(value.samplerAnisotropy);
    result += encoder->EncodeVkBool32Value(value.textureCompressionETC2);
    result += encoder->EncodeVkBool32Value(value.textureCompressionASTC_LDR);
    result += encoder->EncodeVkBool32Value(value.textureCompressionBC);
    result += encoder->EncodeVkBool32Value(value.occlusionQueryPrecise);
    result += encoder->EncodeVkBool32Value(value.pipelineStatisticsQuery);
    result += encoder->EncodeVkBool32Value(value.vertexPipelineStoresAndAtomics);
    result += encoder->EncodeVkBool32Value(value.fragmentStoresAndAtomics);
    result += encoder->EncodeVkBool32Value(value.shaderTessellationAndGeometryPointSize);
    result += encoder->EncodeVkBool32Value(value.shaderImageGatherExtended);
    result += encoder->EncodeVkBool32Value(value.shaderStorageImageExtendedFormats);
    result += encoder->EncodeVkBool32Value(value.shaderStorageImageMultisample);
    result += encoder->EncodeVkBool32Value(value.shaderStorageImageReadWithoutFormat);
    result += encoder->EncodeVkBool32Value(value.shaderStorageImageWriteWithoutFormat);
    result += encoder->EncodeVkBool32Value(value.shaderUniformBufferArrayDynamicIndexing);
    result += encoder->EncodeVkBool32Value(value.shaderSampledImageArrayDynamicIndexing);
    result += encoder->EncodeVkBool32Value(value.shaderStorageBufferArrayDynamicIndexing);
    result += encoder->EncodeVkBool32Value(value.shaderStorageImageArrayDynamicIndexing);
    result += encoder->EncodeVkBool32Value(value.shaderClipDistance);
    result += encoder->EncodeVkBool32Value(value.shaderCullDistance);
    result += encoder->EncodeVkBool32Value(value.shaderFloat64);
    result += encoder->EncodeVkBool32Value(value.shaderInt64);
    result += encoder->EncodeVkBool32Value(value.shaderInt16);
    result += encoder->EncodeVkBool32Value(value.shaderResourceResidency);
    result += encoder->EncodeVkBool32Value(value.shaderResourceMinLod);
    result += encoder->EncodeVkBool32Value(value.sparseBinding);
    result += encoder->EncodeVkBool32Value(value.sparseResidencyBuffer);
    result += encoder->EncodeVkBool32Value(value.sparseResidencyImage2D);
    result += encoder->EncodeVkBool32Value(value.sparseResidencyImage3D);
    result += encoder->EncodeVkBool32Value(value.sparseResidency2Samples);
    result += encoder->EncodeVkBool32Value(value.sparseResidency4Samples);
    result += encoder->EncodeVkBool32Value(value.sparseResidency8Samples);
    result += encoder->EncodeVkBool32Value(value.sparseResidency16Samples);
    result += encoder->EncodeVkBool32Value(value.sparseResidencyAliased);
    result += encoder->EncodeVkBool32Value(value.variableMultisampleRate);
    result += encoder->EncodeVkBool32Value(value.inheritedQueries);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkFormatProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.linearTilingFeatures);
    result += encoder->EncodeFlagsValue(value.optimalTilingFeatures);
    result += encoder->EncodeFlagsValue(value.bufferFeatures);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExtent3D& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.width);
    result += encoder->EncodeUInt32Value(value.height);
    result += encoder->EncodeUInt32Value(value.depth);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageFormatProperties& value)
{
    size_t result = 0;
    result += encode_struct(encoder, value.maxExtent);
    result += encoder->EncodeUInt32Value(value.maxMipLevels);
    result += encoder->EncodeUInt32Value(value.maxArrayLayers);
    result += encoder->EncodeFlagsValue(value.sampleCounts);
    result += encoder->EncodeVkDeviceSizeValue(value.maxResourceSize);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceLimits& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.maxImageDimension1D);
    result += encoder->EncodeUInt32Value(value.maxImageDimension2D);
    result += encoder->EncodeUInt32Value(value.maxImageDimension3D);
    result += encoder->EncodeUInt32Value(value.maxImageDimensionCube);
    result += encoder->EncodeUInt32Value(value.maxImageArrayLayers);
    result += encoder->EncodeUInt32Value(value.maxTexelBufferElements);
    result += encoder->EncodeUInt32Value(value.maxUniformBufferRange);
    result += encoder->EncodeUInt32Value(value.maxStorageBufferRange);
    result += encoder->EncodeUInt32Value(value.maxPushConstantsSize);
    result += encoder->EncodeUInt32Value(value.maxMemoryAllocationCount);
    result += encoder->EncodeUInt32Value(value.maxSamplerAllocationCount);
    result += encoder->EncodeVkDeviceSizeValue(value.bufferImageGranularity);
    result += encoder->EncodeVkDeviceSizeValue(value.sparseAddressSpaceSize);
    result += encoder->EncodeUInt32Value(value.maxBoundDescriptorSets);
    result += encoder->EncodeUInt32Value(value.maxPerStageDescriptorSamplers);
    result += encoder->EncodeUInt32Value(value.maxPerStageDescriptorUniformBuffers);
    result += encoder->EncodeUInt32Value(value.maxPerStageDescriptorStorageBuffers);
    result += encoder->EncodeUInt32Value(value.maxPerStageDescriptorSampledImages);
    result += encoder->EncodeUInt32Value(value.maxPerStageDescriptorStorageImages);
    result += encoder->EncodeUInt32Value(value.maxPerStageDescriptorInputAttachments);
    result += encoder->EncodeUInt32Value(value.maxPerStageResources);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetSamplers);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetUniformBuffers);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetUniformBuffersDynamic);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetStorageBuffers);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetStorageBuffersDynamic);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetSampledImages);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetStorageImages);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetInputAttachments);
    result += encoder->EncodeUInt32Value(value.maxVertexInputAttributes);
    result += encoder->EncodeUInt32Value(value.maxVertexInputBindings);
    result += encoder->EncodeUInt32Value(value.maxVertexInputAttributeOffset);
    result += encoder->EncodeUInt32Value(value.maxVertexInputBindingStride);
    result += encoder->EncodeUInt32Value(value.maxVertexOutputComponents);
    result += encoder->EncodeUInt32Value(value.maxTessellationGenerationLevel);
    result += encoder->EncodeUInt32Value(value.maxTessellationPatchSize);
    result += encoder->EncodeUInt32Value(value.maxTessellationControlPerVertexInputComponents);
    result += encoder->EncodeUInt32Value(value.maxTessellationControlPerVertexOutputComponents);
    result += encoder->EncodeUInt32Value(value.maxTessellationControlPerPatchOutputComponents);
    result += encoder->EncodeUInt32Value(value.maxTessellationControlTotalOutputComponents);
    result += encoder->EncodeUInt32Value(value.maxTessellationEvaluationInputComponents);
    result += encoder->EncodeUInt32Value(value.maxTessellationEvaluationOutputComponents);
    result += encoder->EncodeUInt32Value(value.maxGeometryShaderInvocations);
    result += encoder->EncodeUInt32Value(value.maxGeometryInputComponents);
    result += encoder->EncodeUInt32Value(value.maxGeometryOutputComponents);
    result += encoder->EncodeUInt32Value(value.maxGeometryOutputVertices);
    result += encoder->EncodeUInt32Value(value.maxGeometryTotalOutputComponents);
    result += encoder->EncodeUInt32Value(value.maxFragmentInputComponents);
    result += encoder->EncodeUInt32Value(value.maxFragmentOutputAttachments);
    result += encoder->EncodeUInt32Value(value.maxFragmentDualSrcAttachments);
    result += encoder->EncodeUInt32Value(value.maxFragmentCombinedOutputResources);
    result += encoder->EncodeUInt32Value(value.maxComputeSharedMemorySize);
    result += encoder->EncodeUInt32Array(value.maxComputeWorkGroupCount, 3);
    result += encoder->EncodeUInt32Value(value.maxComputeWorkGroupInvocations);
    result += encoder->EncodeUInt32Array(value.maxComputeWorkGroupSize, 3);
    result += encoder->EncodeUInt32Value(value.subPixelPrecisionBits);
    result += encoder->EncodeUInt32Value(value.subTexelPrecisionBits);
    result += encoder->EncodeUInt32Value(value.mipmapPrecisionBits);
    result += encoder->EncodeUInt32Value(value.maxDrawIndexedIndexValue);
    result += encoder->EncodeUInt32Value(value.maxDrawIndirectCount);
    result += encoder->EncodeFloatValue(value.maxSamplerLodBias);
    result += encoder->EncodeFloatValue(value.maxSamplerAnisotropy);
    result += encoder->EncodeUInt32Value(value.maxViewports);
    result += encoder->EncodeUInt32Array(value.maxViewportDimensions, 2);
    result += encoder->EncodeFloatArray(value.viewportBoundsRange, 2);
    result += encoder->EncodeUInt32Value(value.viewportSubPixelBits);
    result += encoder->EncodeSizeTValue(value.minMemoryMapAlignment);
    result += encoder->EncodeVkDeviceSizeValue(value.minTexelBufferOffsetAlignment);
    result += encoder->EncodeVkDeviceSizeValue(value.minUniformBufferOffsetAlignment);
    result += encoder->EncodeVkDeviceSizeValue(value.minStorageBufferOffsetAlignment);
    result += encoder->EncodeInt32Value(value.minTexelOffset);
    result += encoder->EncodeUInt32Value(value.maxTexelOffset);
    result += encoder->EncodeInt32Value(value.minTexelGatherOffset);
    result += encoder->EncodeUInt32Value(value.maxTexelGatherOffset);
    result += encoder->EncodeFloatValue(value.minInterpolationOffset);
    result += encoder->EncodeFloatValue(value.maxInterpolationOffset);
    result += encoder->EncodeUInt32Value(value.subPixelInterpolationOffsetBits);
    result += encoder->EncodeUInt32Value(value.maxFramebufferWidth);
    result += encoder->EncodeUInt32Value(value.maxFramebufferHeight);
    result += encoder->EncodeUInt32Value(value.maxFramebufferLayers);
    result += encoder->EncodeFlagsValue(value.framebufferColorSampleCounts);
    result += encoder->EncodeFlagsValue(value.framebufferDepthSampleCounts);
    result += encoder->EncodeFlagsValue(value.framebufferStencilSampleCounts);
    result += encoder->EncodeFlagsValue(value.framebufferNoAttachmentsSampleCounts);
    result += encoder->EncodeUInt32Value(value.maxColorAttachments);
    result += encoder->EncodeFlagsValue(value.sampledImageColorSampleCounts);
    result += encoder->EncodeFlagsValue(value.sampledImageIntegerSampleCounts);
    result += encoder->EncodeFlagsValue(value.sampledImageDepthSampleCounts);
    result += encoder->EncodeFlagsValue(value.sampledImageStencilSampleCounts);
    result += encoder->EncodeFlagsValue(value.storageImageSampleCounts);
    result += encoder->EncodeUInt32Value(value.maxSampleMaskWords);
    result += encoder->EncodeVkBool32Value(value.timestampComputeAndGraphics);
    result += encoder->EncodeFloatValue(value.timestampPeriod);
    result += encoder->EncodeUInt32Value(value.maxClipDistances);
    result += encoder->EncodeUInt32Value(value.maxCullDistances);
    result += encoder->EncodeUInt32Value(value.maxCombinedClipAndCullDistances);
    result += encoder->EncodeUInt32Value(value.discreteQueuePriorities);
    result += encoder->EncodeFloatArray(value.pointSizeRange, 2);
    result += encoder->EncodeFloatArray(value.lineWidthRange, 2);
    result += encoder->EncodeFloatValue(value.pointSizeGranularity);
    result += encoder->EncodeFloatValue(value.lineWidthGranularity);
    result += encoder->EncodeVkBool32Value(value.strictLines);
    result += encoder->EncodeVkBool32Value(value.standardSampleLocations);
    result += encoder->EncodeVkDeviceSizeValue(value.optimalBufferCopyOffsetAlignment);
    result += encoder->EncodeVkDeviceSizeValue(value.optimalBufferCopyRowPitchAlignment);
    result += encoder->EncodeVkDeviceSizeValue(value.nonCoherentAtomSize);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSparseProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeVkBool32Value(value.residencyStandard2DBlockShape);
    result += encoder->EncodeVkBool32Value(value.residencyStandard2DMultisampleBlockShape);
    result += encoder->EncodeVkBool32Value(value.residencyStandard3DBlockShape);
    result += encoder->EncodeVkBool32Value(value.residencyAlignedMipSize);
    result += encoder->EncodeVkBool32Value(value.residencyNonResidentStrict);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.apiVersion);
    result += encoder->EncodeUInt32Value(value.driverVersion);
    result += encoder->EncodeUInt32Value(value.vendorID);
    result += encoder->EncodeUInt32Value(value.deviceID);
    result += encoder->EncodeEnumValue(value.deviceType);
    result += encoder->EncodeString(value.deviceName);
    result += encoder->EncodeUInt8Array(value.pipelineCacheUUID, VK_UUID_SIZE);
    result += encode_struct(encoder, value.limits);
    result += encode_struct(encoder, value.sparseProperties);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkQueueFamilyProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.queueFlags);
    result += encoder->EncodeUInt32Value(value.queueCount);
    result += encoder->EncodeUInt32Value(value.timestampValidBits);
    result += encode_struct(encoder, value.minImageTransferGranularity);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryType& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.propertyFlags);
    result += encoder->EncodeUInt32Value(value.heapIndex);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryHeap& value)
{
    size_t result = 0;
    result += encoder->EncodeVkDeviceSizeValue(value.size);
    result += encoder->EncodeFlagsValue(value.flags);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMemoryProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.memoryTypeCount);
    result += encode_struct_array(encoder, value.memoryTypes, value.memoryTypeCount);
    result += encoder->EncodeUInt32Value(value.memoryHeapCount);
    result += encode_struct_array(encoder, value.memoryHeaps, value.memoryHeapCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceQueueCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.queueFamilyIndex);
    result += encoder->EncodeUInt32Value(value.queueCount);
    result += encoder->EncodeFloatArray(value.pQueuePriorities, value.queueCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.queueCreateInfoCount);
    result += encode_struct_array(encoder, value.pQueueCreateInfos, value.queueCreateInfoCount);
    result += encoder->EncodeUInt32Value(value.enabledLayerCount);
    result += encoder->EncodeStringArray(value.ppEnabledLayerNames, value.enabledLayerCount);
    result += encoder->EncodeUInt32Value(value.enabledExtensionCount);
    result += encoder->EncodeStringArray(value.ppEnabledExtensionNames, value.enabledExtensionCount);
    result += encode_struct_ptr(encoder, value.pEnabledFeatures);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExtensionProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeString(value.extensionName);
    result += encoder->EncodeUInt32Value(value.specVersion);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkLayerProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeString(value.layerName);
    result += encoder->EncodeUInt32Value(value.specVersion);
    result += encoder->EncodeUInt32Value(value.implementationVersion);
    result += encoder->EncodeString(value.description);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSubmitInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.waitSemaphoreCount);
    result += encoder->EncodeHandleIdArray(value.pWaitSemaphores, value.waitSemaphoreCount);
    result += encoder->EncodeFlagsArray(value.pWaitDstStageMask, value.waitSemaphoreCount);
    result += encoder->EncodeUInt32Value(value.commandBufferCount);
    result += encoder->EncodeHandleIdArray(value.pCommandBuffers, value.commandBufferCount);
    result += encoder->EncodeUInt32Value(value.signalSemaphoreCount);
    result += encoder->EncodeHandleIdArray(value.pSignalSemaphores, value.signalSemaphoreCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryAllocateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkDeviceSizeValue(value.allocationSize);
    result += encoder->EncodeUInt32Value(value.memoryTypeIndex);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMappedMemoryRange& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.memory);
    result += encoder->EncodeVkDeviceSizeValue(value.offset);
    result += encoder->EncodeVkDeviceSizeValue(value.size);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryRequirements& value)
{
    size_t result = 0;
    result += encoder->EncodeVkDeviceSizeValue(value.size);
    result += encoder->EncodeVkDeviceSizeValue(value.alignment);
    result += encoder->EncodeUInt32Value(value.memoryTypeBits);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageFormatProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.aspectMask);
    result += encode_struct(encoder, value.imageGranularity);
    result += encoder->EncodeFlagsValue(value.flags);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageMemoryRequirements& value)
{
    size_t result = 0;
    result += encode_struct(encoder, value.formatProperties);
    result += encoder->EncodeUInt32Value(value.imageMipTailFirstLod);
    result += encoder->EncodeVkDeviceSizeValue(value.imageMipTailSize);
    result += encoder->EncodeVkDeviceSizeValue(value.imageMipTailOffset);
    result += encoder->EncodeVkDeviceSizeValue(value.imageMipTailStride);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseMemoryBind& value)
{
    size_t result = 0;
    result += encoder->EncodeVkDeviceSizeValue(value.resourceOffset);
    result += encoder->EncodeVkDeviceSizeValue(value.size);
    result += encoder->EncodeHandleIdValue(value.memory);
    result += encoder->EncodeVkDeviceSizeValue(value.memoryOffset);
    result += encoder->EncodeFlagsValue(value.flags);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseBufferMemoryBindInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeHandleIdValue(value.buffer);
    result += encoder->EncodeUInt32Value(value.bindCount);
    result += encode_struct_array(encoder, value.pBinds, value.bindCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageOpaqueMemoryBindInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeHandleIdValue(value.image);
    result += encoder->EncodeUInt32Value(value.bindCount);
    result += encode_struct_array(encoder, value.pBinds, value.bindCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageSubresource& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.aspectMask);
    result += encoder->EncodeUInt32Value(value.mipLevel);
    result += encoder->EncodeUInt32Value(value.arrayLayer);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkOffset3D& value)
{
    size_t result = 0;
    result += encoder->EncodeInt32Value(value.x);
    result += encoder->EncodeInt32Value(value.y);
    result += encoder->EncodeInt32Value(value.z);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageMemoryBind& value)
{
    size_t result = 0;
    result += encode_struct(encoder, value.subresource);
    result += encode_struct(encoder, value.offset);
    result += encode_struct(encoder, value.extent);
    result += encoder->EncodeHandleIdValue(value.memory);
    result += encoder->EncodeVkDeviceSizeValue(value.memoryOffset);
    result += encoder->EncodeFlagsValue(value.flags);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageMemoryBindInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeHandleIdValue(value.image);
    result += encoder->EncodeUInt32Value(value.bindCount);
    result += encode_struct_array(encoder, value.pBinds, value.bindCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkBindSparseInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.waitSemaphoreCount);
    result += encoder->EncodeHandleIdArray(value.pWaitSemaphores, value.waitSemaphoreCount);
    result += encoder->EncodeUInt32Value(value.bufferBindCount);
    result += encode_struct_array(encoder, value.pBufferBinds, value.bufferBindCount);
    result += encoder->EncodeUInt32Value(value.imageOpaqueBindCount);
    result += encode_struct_array(encoder, value.pImageOpaqueBinds, value.imageOpaqueBindCount);
    result += encoder->EncodeUInt32Value(value.imageBindCount);
    result += encode_struct_array(encoder, value.pImageBinds, value.imageBindCount);
    result += encoder->EncodeUInt32Value(value.signalSemaphoreCount);
    result += encoder->EncodeHandleIdArray(value.pSignalSemaphores, value.signalSemaphoreCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkFenceCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSemaphoreCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkEventCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkQueryPoolCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.queryType);
    result += encoder->EncodeUInt32Value(value.queryCount);
    result += encoder->EncodeFlagsValue(value.pipelineStatistics);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkBufferCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVkDeviceSizeValue(value.size);
    result += encoder->EncodeFlagsValue(value.usage);
    result += encoder->EncodeEnumValue(value.sharingMode);
    result += encoder->EncodeUInt32Value(value.queueFamilyIndexCount);
    result += encoder->EncodeUInt32Array(value.pQueueFamilyIndices, value.queueFamilyIndexCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkBufferViewCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeHandleIdValue(value.buffer);
    result += encoder->EncodeEnumValue(value.format);
    result += encoder->EncodeVkDeviceSizeValue(value.offset);
    result += encoder->EncodeVkDeviceSizeValue(value.range);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.imageType);
    result += encoder->EncodeEnumValue(value.format);
    result += encode_struct(encoder, value.extent);
    result += encoder->EncodeUInt32Value(value.mipLevels);
    result += encoder->EncodeUInt32Value(value.arrayLayers);
    result += encoder->EncodeEnumValue(value.samples);
    result += encoder->EncodeEnumValue(value.tiling);
    result += encoder->EncodeFlagsValue(value.usage);
    result += encoder->EncodeEnumValue(value.sharingMode);
    result += encoder->EncodeUInt32Value(value.queueFamilyIndexCount);
    result += encoder->EncodeUInt32Array(value.pQueueFamilyIndices, value.queueFamilyIndexCount);
    result += encoder->EncodeEnumValue(value.initialLayout);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSubresourceLayout& value)
{
    size_t result = 0;
    result += encoder->EncodeVkDeviceSizeValue(value.offset);
    result += encoder->EncodeVkDeviceSizeValue(value.size);
    result += encoder->EncodeVkDeviceSizeValue(value.rowPitch);
    result += encoder->EncodeVkDeviceSizeValue(value.arrayPitch);
    result += encoder->EncodeVkDeviceSizeValue(value.depthPitch);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkComponentMapping& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.r);
    result += encoder->EncodeEnumValue(value.g);
    result += encoder->EncodeEnumValue(value.b);
    result += encoder->EncodeEnumValue(value.a);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageSubresourceRange& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.aspectMask);
    result += encoder->EncodeUInt32Value(value.baseMipLevel);
    result += encoder->EncodeUInt32Value(value.levelCount);
    result += encoder->EncodeUInt32Value(value.baseArrayLayer);
    result += encoder->EncodeUInt32Value(value.layerCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageViewCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeHandleIdValue(value.image);
    result += encoder->EncodeEnumValue(value.viewType);
    result += encoder->EncodeEnumValue(value.format);
    result += encode_struct(encoder, value.components);
    result += encode_struct(encoder, value.subresourceRange);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkShaderModuleCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeSizeTValue(value.codeSize);
    result += encoder->EncodeUInt32Array(value.pCode, value.codeSize/4);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineCacheCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeSizeTValue(value.initialDataSize);
    result += encoder->EncodeVoidArray(value.pInitialData, value.initialDataSize);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSpecializationMapEntry& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.constantID);
    result += encoder->EncodeUInt32Value(value.offset);
    result += encoder->EncodeSizeTValue(value.size);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSpecializationInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.mapEntryCount);
    result += encode_struct_array(encoder, value.pMapEntries, value.mapEntryCount);
    result += encoder->EncodeSizeTValue(value.dataSize);
    result += encoder->EncodeVoidArray(value.pData, value.dataSize);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineShaderStageCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.stage);
    result += encoder->EncodeHandleIdValue(value.module);
    result += encoder->EncodeString(value.pName);
    result += encode_struct_ptr(encoder, value.pSpecializationInfo);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkVertexInputBindingDescription& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.binding);
    result += encoder->EncodeUInt32Value(value.stride);
    result += encoder->EncodeEnumValue(value.inputRate);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkVertexInputAttributeDescription& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.location);
    result += encoder->EncodeUInt32Value(value.binding);
    result += encoder->EncodeEnumValue(value.format);
    result += encoder->EncodeUInt32Value(value.offset);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineVertexInputStateCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.vertexBindingDescriptionCount);
    result += encode_struct_array(encoder, value.pVertexBindingDescriptions, value.vertexBindingDescriptionCount);
    result += encoder->EncodeUInt32Value(value.vertexAttributeDescriptionCount);
    result += encode_struct_array(encoder, value.pVertexAttributeDescriptions, value.vertexAttributeDescriptionCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineInputAssemblyStateCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.topology);
    result += encoder->EncodeVkBool32Value(value.primitiveRestartEnable);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineTessellationStateCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.patchControlPoints);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkViewport& value)
{
    size_t result = 0;
    result += encoder->EncodeFloatValue(value.x);
    result += encoder->EncodeFloatValue(value.y);
    result += encoder->EncodeFloatValue(value.width);
    result += encoder->EncodeFloatValue(value.height);
    result += encoder->EncodeFloatValue(value.minDepth);
    result += encoder->EncodeFloatValue(value.maxDepth);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkOffset2D& value)
{
    size_t result = 0;
    result += encoder->EncodeInt32Value(value.x);
    result += encoder->EncodeInt32Value(value.y);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExtent2D& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.width);
    result += encoder->EncodeUInt32Value(value.height);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkRect2D& value)
{
    size_t result = 0;
    result += encode_struct(encoder, value.offset);
    result += encode_struct(encoder, value.extent);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineViewportStateCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.viewportCount);
    result += encode_struct_array(encoder, value.pViewports, value.viewportCount);
    result += encoder->EncodeUInt32Value(value.scissorCount);
    result += encode_struct_array(encoder, value.pScissors, value.scissorCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineRasterizationStateCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVkBool32Value(value.depthClampEnable);
    result += encoder->EncodeVkBool32Value(value.rasterizerDiscardEnable);
    result += encoder->EncodeEnumValue(value.polygonMode);
    result += encoder->EncodeFlagsValue(value.cullMode);
    result += encoder->EncodeEnumValue(value.frontFace);
    result += encoder->EncodeVkBool32Value(value.depthBiasEnable);
    result += encoder->EncodeFloatValue(value.depthBiasConstantFactor);
    result += encoder->EncodeFloatValue(value.depthBiasClamp);
    result += encoder->EncodeFloatValue(value.depthBiasSlopeFactor);
    result += encoder->EncodeFloatValue(value.lineWidth);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineMultisampleStateCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.rasterizationSamples);
    result += encoder->EncodeVkBool32Value(value.sampleShadingEnable);
    result += encoder->EncodeFloatValue(value.minSampleShading);
    result += encoder->EncodeVkSampleMaskArray(value.pSampleMask, static_cast<size_t>(ceil(static_cast<double>(value.rasterizationSamples)/static_cast<double>(32))));
    result += encoder->EncodeVkBool32Value(value.alphaToCoverageEnable);
    result += encoder->EncodeVkBool32Value(value.alphaToOneEnable);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkStencilOpState& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.failOp);
    result += encoder->EncodeEnumValue(value.passOp);
    result += encoder->EncodeEnumValue(value.depthFailOp);
    result += encoder->EncodeEnumValue(value.compareOp);
    result += encoder->EncodeUInt32Value(value.compareMask);
    result += encoder->EncodeUInt32Value(value.writeMask);
    result += encoder->EncodeUInt32Value(value.reference);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineDepthStencilStateCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVkBool32Value(value.depthTestEnable);
    result += encoder->EncodeVkBool32Value(value.depthWriteEnable);
    result += encoder->EncodeEnumValue(value.depthCompareOp);
    result += encoder->EncodeVkBool32Value(value.depthBoundsTestEnable);
    result += encoder->EncodeVkBool32Value(value.stencilTestEnable);
    result += encode_struct(encoder, value.front);
    result += encode_struct(encoder, value.back);
    result += encoder->EncodeFloatValue(value.minDepthBounds);
    result += encoder->EncodeFloatValue(value.maxDepthBounds);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineColorBlendAttachmentState& value)
{
    size_t result = 0;
    result += encoder->EncodeVkBool32Value(value.blendEnable);
    result += encoder->EncodeEnumValue(value.srcColorBlendFactor);
    result += encoder->EncodeEnumValue(value.dstColorBlendFactor);
    result += encoder->EncodeEnumValue(value.colorBlendOp);
    result += encoder->EncodeEnumValue(value.srcAlphaBlendFactor);
    result += encoder->EncodeEnumValue(value.dstAlphaBlendFactor);
    result += encoder->EncodeEnumValue(value.alphaBlendOp);
    result += encoder->EncodeFlagsValue(value.colorWriteMask);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineColorBlendStateCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVkBool32Value(value.logicOpEnable);
    result += encoder->EncodeEnumValue(value.logicOp);
    result += encoder->EncodeUInt32Value(value.attachmentCount);
    result += encode_struct_array(encoder, value.pAttachments, value.attachmentCount);
    result += encoder->EncodeFloatArray(value.blendConstants, 4);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineDynamicStateCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.dynamicStateCount);
    result += encoder->EncodeEnumArray(value.pDynamicStates, value.dynamicStateCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkGraphicsPipelineCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.stageCount);
    result += encode_struct_array(encoder, value.pStages, value.stageCount);
    result += encode_struct_ptr(encoder, value.pVertexInputState);
    result += encode_struct_ptr(encoder, value.pInputAssemblyState);
    result += encode_struct_ptr(encoder, value.pTessellationState);
    result += encode_struct_ptr(encoder, value.pViewportState);
    result += encode_struct_ptr(encoder, value.pRasterizationState);
    result += encode_struct_ptr(encoder, value.pMultisampleState);
    result += encode_struct_ptr(encoder, value.pDepthStencilState);
    result += encode_struct_ptr(encoder, value.pColorBlendState);
    result += encode_struct_ptr(encoder, value.pDynamicState);
    result += encoder->EncodeHandleIdValue(value.layout);
    result += encoder->EncodeHandleIdValue(value.renderPass);
    result += encoder->EncodeUInt32Value(value.subpass);
    result += encoder->EncodeHandleIdValue(value.basePipelineHandle);
    result += encoder->EncodeInt32Value(value.basePipelineIndex);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkComputePipelineCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encode_struct(encoder, value.stage);
    result += encoder->EncodeHandleIdValue(value.layout);
    result += encoder->EncodeHandleIdValue(value.basePipelineHandle);
    result += encoder->EncodeInt32Value(value.basePipelineIndex);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPushConstantRange& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.stageFlags);
    result += encoder->EncodeUInt32Value(value.offset);
    result += encoder->EncodeUInt32Value(value.size);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineLayoutCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.setLayoutCount);
    result += encoder->EncodeHandleIdArray(value.pSetLayouts, value.setLayoutCount);
    result += encoder->EncodeUInt32Value(value.pushConstantRangeCount);
    result += encode_struct_array(encoder, value.pPushConstantRanges, value.pushConstantRangeCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSamplerCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.magFilter);
    result += encoder->EncodeEnumValue(value.minFilter);
    result += encoder->EncodeEnumValue(value.mipmapMode);
    result += encoder->EncodeEnumValue(value.addressModeU);
    result += encoder->EncodeEnumValue(value.addressModeV);
    result += encoder->EncodeEnumValue(value.addressModeW);
    result += encoder->EncodeFloatValue(value.mipLodBias);
    result += encoder->EncodeVkBool32Value(value.anisotropyEnable);
    result += encoder->EncodeFloatValue(value.maxAnisotropy);
    result += encoder->EncodeVkBool32Value(value.compareEnable);
    result += encoder->EncodeEnumValue(value.compareOp);
    result += encoder->EncodeFloatValue(value.minLod);
    result += encoder->EncodeFloatValue(value.maxLod);
    result += encoder->EncodeEnumValue(value.borderColor);
    result += encoder->EncodeVkBool32Value(value.unnormalizedCoordinates);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetLayoutBinding& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.binding);
    result += encoder->EncodeEnumValue(value.descriptorType);
    result += encoder->EncodeUInt32Value(value.descriptorCount);
    result += encoder->EncodeFlagsValue(value.stageFlags);
    result += encoder->EncodeHandleIdArray(value.pImmutableSamplers, value.descriptorCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetLayoutCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.bindingCount);
    result += encode_struct_array(encoder, value.pBindings, value.bindingCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorPoolSize& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.type);
    result += encoder->EncodeUInt32Value(value.descriptorCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorPoolCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.maxSets);
    result += encoder->EncodeUInt32Value(value.poolSizeCount);
    result += encode_struct_array(encoder, value.pPoolSizes, value.poolSizeCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetAllocateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.descriptorPool);
    result += encoder->EncodeUInt32Value(value.descriptorSetCount);
    result += encoder->EncodeHandleIdArray(value.pSetLayouts, value.descriptorSetCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorImageInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeHandleIdValue(value.sampler);
    result += encoder->EncodeHandleIdValue(value.imageView);
    result += encoder->EncodeEnumValue(value.imageLayout);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorBufferInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeHandleIdValue(value.buffer);
    result += encoder->EncodeVkDeviceSizeValue(value.offset);
    result += encoder->EncodeVkDeviceSizeValue(value.range);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkWriteDescriptorSet& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.dstSet);
    result += encoder->EncodeUInt32Value(value.dstBinding);
    result += encoder->EncodeUInt32Value(value.dstArrayElement);
    result += encoder->EncodeUInt32Value(value.descriptorCount);
    result += encoder->EncodeEnumValue(value.descriptorType);
    result += encode_struct_array(encoder, value.pImageInfo, value.descriptorCount);
    result += encode_struct_array(encoder, value.pBufferInfo, value.descriptorCount);
    result += encoder->EncodeHandleIdArray(value.pTexelBufferView, value.descriptorCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkCopyDescriptorSet& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.srcSet);
    result += encoder->EncodeUInt32Value(value.srcBinding);
    result += encoder->EncodeUInt32Value(value.srcArrayElement);
    result += encoder->EncodeHandleIdValue(value.dstSet);
    result += encoder->EncodeUInt32Value(value.dstBinding);
    result += encoder->EncodeUInt32Value(value.dstArrayElement);
    result += encoder->EncodeUInt32Value(value.descriptorCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkFramebufferCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeHandleIdValue(value.renderPass);
    result += encoder->EncodeUInt32Value(value.attachmentCount);
    result += encoder->EncodeHandleIdArray(value.pAttachments, value.attachmentCount);
    result += encoder->EncodeUInt32Value(value.width);
    result += encoder->EncodeUInt32Value(value.height);
    result += encoder->EncodeUInt32Value(value.layers);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkAttachmentDescription& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.format);
    result += encoder->EncodeEnumValue(value.samples);
    result += encoder->EncodeEnumValue(value.loadOp);
    result += encoder->EncodeEnumValue(value.storeOp);
    result += encoder->EncodeEnumValue(value.stencilLoadOp);
    result += encoder->EncodeEnumValue(value.stencilStoreOp);
    result += encoder->EncodeEnumValue(value.initialLayout);
    result += encoder->EncodeEnumValue(value.finalLayout);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkAttachmentReference& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.attachment);
    result += encoder->EncodeEnumValue(value.layout);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassDescription& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.pipelineBindPoint);
    result += encoder->EncodeUInt32Value(value.inputAttachmentCount);
    result += encode_struct_array(encoder, value.pInputAttachments, value.inputAttachmentCount);
    result += encoder->EncodeUInt32Value(value.colorAttachmentCount);
    result += encode_struct_array(encoder, value.pColorAttachments, value.colorAttachmentCount);
    result += encode_struct_array(encoder, value.pResolveAttachments, value.colorAttachmentCount);
    result += encode_struct_ptr(encoder, value.pDepthStencilAttachment);
    result += encoder->EncodeUInt32Value(value.preserveAttachmentCount);
    result += encoder->EncodeUInt32Array(value.pPreserveAttachments, value.preserveAttachmentCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassDependency& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.srcSubpass);
    result += encoder->EncodeUInt32Value(value.dstSubpass);
    result += encoder->EncodeFlagsValue(value.srcStageMask);
    result += encoder->EncodeFlagsValue(value.dstStageMask);
    result += encoder->EncodeFlagsValue(value.srcAccessMask);
    result += encoder->EncodeFlagsValue(value.dstAccessMask);
    result += encoder->EncodeFlagsValue(value.dependencyFlags);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkRenderPassCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.attachmentCount);
    result += encode_struct_array(encoder, value.pAttachments, value.attachmentCount);
    result += encoder->EncodeUInt32Value(value.subpassCount);
    result += encode_struct_array(encoder, value.pSubpasses, value.subpassCount);
    result += encoder->EncodeUInt32Value(value.dependencyCount);
    result += encode_struct_array(encoder, value.pDependencies, value.dependencyCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkCommandPoolCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.queueFamilyIndex);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkCommandBufferAllocateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.commandPool);
    result += encoder->EncodeEnumValue(value.level);
    result += encoder->EncodeUInt32Value(value.commandBufferCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkCommandBufferInheritanceInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.renderPass);
    result += encoder->EncodeUInt32Value(value.subpass);
    result += encoder->EncodeHandleIdValue(value.framebuffer);
    result += encoder->EncodeVkBool32Value(value.occlusionQueryEnable);
    result += encoder->EncodeFlagsValue(value.queryFlags);
    result += encoder->EncodeFlagsValue(value.pipelineStatistics);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkCommandBufferBeginInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encode_struct_ptr(encoder, value.pInheritanceInfo);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkBufferCopy& value)
{
    size_t result = 0;
    result += encoder->EncodeVkDeviceSizeValue(value.srcOffset);
    result += encoder->EncodeVkDeviceSizeValue(value.dstOffset);
    result += encoder->EncodeVkDeviceSizeValue(value.size);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageSubresourceLayers& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.aspectMask);
    result += encoder->EncodeUInt32Value(value.mipLevel);
    result += encoder->EncodeUInt32Value(value.baseArrayLayer);
    result += encoder->EncodeUInt32Value(value.layerCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageCopy& value)
{
    size_t result = 0;
    result += encode_struct(encoder, value.srcSubresource);
    result += encode_struct(encoder, value.srcOffset);
    result += encode_struct(encoder, value.dstSubresource);
    result += encode_struct(encoder, value.dstOffset);
    result += encode_struct(encoder, value.extent);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageBlit& value)
{
    size_t result = 0;
    result += encode_struct(encoder, value.srcSubresource);
    result += encode_struct_array(encoder, value.srcOffsets, 2);
    result += encode_struct(encoder, value.dstSubresource);
    result += encode_struct_array(encoder, value.dstOffsets, 2);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkBufferImageCopy& value)
{
    size_t result = 0;
    result += encoder->EncodeVkDeviceSizeValue(value.bufferOffset);
    result += encoder->EncodeUInt32Value(value.bufferRowLength);
    result += encoder->EncodeUInt32Value(value.bufferImageHeight);
    result += encode_struct(encoder, value.imageSubresource);
    result += encode_struct(encoder, value.imageOffset);
    result += encode_struct(encoder, value.imageExtent);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkClearDepthStencilValue& value)
{
    size_t result = 0;
    result += encoder->EncodeFloatValue(value.depth);
    result += encoder->EncodeUInt32Value(value.stencil);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkClearAttachment& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.aspectMask);
    result += encoder->EncodeUInt32Value(value.colorAttachment);
    result += encode_struct(encoder, value.clearValue);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkClearRect& value)
{
    size_t result = 0;
    result += encode_struct(encoder, value.rect);
    result += encoder->EncodeUInt32Value(value.baseArrayLayer);
    result += encoder->EncodeUInt32Value(value.layerCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageResolve& value)
{
    size_t result = 0;
    result += encode_struct(encoder, value.srcSubresource);
    result += encode_struct(encoder, value.srcOffset);
    result += encode_struct(encoder, value.dstSubresource);
    result += encode_struct(encoder, value.dstOffset);
    result += encode_struct(encoder, value.extent);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryBarrier& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.srcAccessMask);
    result += encoder->EncodeFlagsValue(value.dstAccessMask);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkBufferMemoryBarrier& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.srcAccessMask);
    result += encoder->EncodeFlagsValue(value.dstAccessMask);
    result += encoder->EncodeUInt32Value(value.srcQueueFamilyIndex);
    result += encoder->EncodeUInt32Value(value.dstQueueFamilyIndex);
    result += encoder->EncodeHandleIdValue(value.buffer);
    result += encoder->EncodeVkDeviceSizeValue(value.offset);
    result += encoder->EncodeVkDeviceSizeValue(value.size);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageMemoryBarrier& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.srcAccessMask);
    result += encoder->EncodeFlagsValue(value.dstAccessMask);
    result += encoder->EncodeEnumValue(value.oldLayout);
    result += encoder->EncodeEnumValue(value.newLayout);
    result += encoder->EncodeUInt32Value(value.srcQueueFamilyIndex);
    result += encoder->EncodeUInt32Value(value.dstQueueFamilyIndex);
    result += encoder->EncodeHandleIdValue(value.image);
    result += encode_struct(encoder, value.subresourceRange);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkRenderPassBeginInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.renderPass);
    result += encoder->EncodeHandleIdValue(value.framebuffer);
    result += encode_struct(encoder, value.renderArea);
    result += encoder->EncodeUInt32Value(value.clearValueCount);
    result += encode_struct_array(encoder, value.pClearValues, value.clearValueCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDispatchIndirectCommand& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.x);
    result += encoder->EncodeUInt32Value(value.y);
    result += encoder->EncodeUInt32Value(value.z);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDrawIndexedIndirectCommand& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.indexCount);
    result += encoder->EncodeUInt32Value(value.instanceCount);
    result += encoder->EncodeUInt32Value(value.firstIndex);
    result += encoder->EncodeInt32Value(value.vertexOffset);
    result += encoder->EncodeUInt32Value(value.firstInstance);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDrawIndirectCommand& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.vertexCount);
    result += encoder->EncodeUInt32Value(value.instanceCount);
    result += encoder->EncodeUInt32Value(value.firstVertex);
    result += encoder->EncodeUInt32Value(value.firstInstance);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSubgroupProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.subgroupSize);
    result += encoder->EncodeFlagsValue(value.supportedStages);
    result += encoder->EncodeFlagsValue(value.supportedOperations);
    result += encoder->EncodeVkBool32Value(value.quadOperationsInAllStages);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkBindBufferMemoryInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.buffer);
    result += encoder->EncodeHandleIdValue(value.memory);
    result += encoder->EncodeVkDeviceSizeValue(value.memoryOffset);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkBindImageMemoryInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.image);
    result += encoder->EncodeHandleIdValue(value.memory);
    result += encoder->EncodeVkDeviceSizeValue(value.memoryOffset);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDevice16BitStorageFeatures& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.storageBuffer16BitAccess);
    result += encoder->EncodeVkBool32Value(value.uniformAndStorageBuffer16BitAccess);
    result += encoder->EncodeVkBool32Value(value.storagePushConstant16);
    result += encoder->EncodeVkBool32Value(value.storageInputOutput16);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryDedicatedRequirements& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.prefersDedicatedAllocation);
    result += encoder->EncodeVkBool32Value(value.requiresDedicatedAllocation);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryDedicatedAllocateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.image);
    result += encoder->EncodeHandleIdValue(value.buffer);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryAllocateFlagsInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.deviceMask);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupRenderPassBeginInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.deviceMask);
    result += encoder->EncodeUInt32Value(value.deviceRenderAreaCount);
    result += encode_struct_array(encoder, value.pDeviceRenderAreas, value.deviceRenderAreaCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupCommandBufferBeginInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.deviceMask);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupSubmitInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.waitSemaphoreCount);
    result += encoder->EncodeUInt32Array(value.pWaitSemaphoreDeviceIndices, value.waitSemaphoreCount);
    result += encoder->EncodeUInt32Value(value.commandBufferCount);
    result += encoder->EncodeUInt32Array(value.pCommandBufferDeviceMasks, value.commandBufferCount);
    result += encoder->EncodeUInt32Value(value.signalSemaphoreCount);
    result += encoder->EncodeUInt32Array(value.pSignalSemaphoreDeviceIndices, value.signalSemaphoreCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupBindSparseInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.resourceDeviceIndex);
    result += encoder->EncodeUInt32Value(value.memoryDeviceIndex);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkBindBufferMemoryDeviceGroupInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.deviceIndexCount);
    result += encoder->EncodeUInt32Array(value.pDeviceIndices, value.deviceIndexCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkBindImageMemoryDeviceGroupInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.deviceIndexCount);
    result += encoder->EncodeUInt32Array(value.pDeviceIndices, value.deviceIndexCount);
    result += encoder->EncodeUInt32Value(value.splitInstanceBindRegionCount);
    result += encode_struct_array(encoder, value.pSplitInstanceBindRegions, value.splitInstanceBindRegionCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceGroupProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.physicalDeviceCount);
    result += encoder->EncodeHandleIdArray(value.physicalDevices, value.physicalDeviceCount);
    result += encoder->EncodeVkBool32Value(value.subsetAllocation);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupDeviceCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.physicalDeviceCount);
    result += encoder->EncodeHandleIdArray(value.pPhysicalDevices, value.physicalDeviceCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkBufferMemoryRequirementsInfo2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.buffer);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageMemoryRequirementsInfo2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.image);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageSparseMemoryRequirementsInfo2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.image);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryRequirements2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.memoryRequirements);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageMemoryRequirements2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.memoryRequirements);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceFeatures2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.features);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceProperties2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.properties);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkFormatProperties2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.formatProperties);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageFormatProperties2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.imageFormatProperties);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceImageFormatInfo2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.format);
    result += encoder->EncodeEnumValue(value.type);
    result += encoder->EncodeEnumValue(value.tiling);
    result += encoder->EncodeFlagsValue(value.usage);
    result += encoder->EncodeFlagsValue(value.flags);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkQueueFamilyProperties2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.queueFamilyProperties);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMemoryProperties2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.memoryProperties);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSparseImageFormatProperties2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.properties);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSparseImageFormatInfo2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.format);
    result += encoder->EncodeEnumValue(value.type);
    result += encoder->EncodeEnumValue(value.samples);
    result += encoder->EncodeFlagsValue(value.usage);
    result += encoder->EncodeEnumValue(value.tiling);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDevicePointClippingProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.pointClippingBehavior);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkInputAttachmentAspectReference& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.subpass);
    result += encoder->EncodeUInt32Value(value.inputAttachmentIndex);
    result += encoder->EncodeFlagsValue(value.aspectMask);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkRenderPassInputAttachmentAspectCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.aspectReferenceCount);
    result += encode_struct_array(encoder, value.pAspectReferences, value.aspectReferenceCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageViewUsageCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.usage);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineTessellationDomainOriginStateCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.domainOrigin);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkRenderPassMultiviewCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.subpassCount);
    result += encoder->EncodeUInt32Array(value.pViewMasks, value.subpassCount);
    result += encoder->EncodeUInt32Value(value.dependencyCount);
    result += encoder->EncodeInt32Array(value.pViewOffsets, value.dependencyCount);
    result += encoder->EncodeUInt32Value(value.correlationMaskCount);
    result += encoder->EncodeUInt32Array(value.pCorrelationMasks, value.correlationMaskCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewFeatures& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.multiview);
    result += encoder->EncodeVkBool32Value(value.multiviewGeometryShader);
    result += encoder->EncodeVkBool32Value(value.multiviewTessellationShader);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.maxMultiviewViewCount);
    result += encoder->EncodeUInt32Value(value.maxMultiviewInstanceIndex);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceVariablePointerFeatures& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.variablePointersStorageBuffer);
    result += encoder->EncodeVkBool32Value(value.variablePointers);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceProtectedMemoryFeatures& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.protectedMemory);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceProtectedMemoryProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.protectedNoFault);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceQueueInfo2& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.queueFamilyIndex);
    result += encoder->EncodeUInt32Value(value.queueIndex);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkProtectedSubmitInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.protectedSubmit);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSamplerYcbcrConversionCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.format);
    result += encoder->EncodeEnumValue(value.ycbcrModel);
    result += encoder->EncodeEnumValue(value.ycbcrRange);
    result += encode_struct(encoder, value.components);
    result += encoder->EncodeEnumValue(value.xChromaOffset);
    result += encoder->EncodeEnumValue(value.yChromaOffset);
    result += encoder->EncodeEnumValue(value.chromaFilter);
    result += encoder->EncodeVkBool32Value(value.forceExplicitReconstruction);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSamplerYcbcrConversionInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.conversion);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkBindImagePlaneMemoryInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.planeAspect);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImagePlaneMemoryRequirementsInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.planeAspect);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSamplerYcbcrConversionFeatures& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.samplerYcbcrConversion);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSamplerYcbcrConversionImageFormatProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.combinedImageSamplerDescriptorCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorUpdateTemplateEntry& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.dstBinding);
    result += encoder->EncodeUInt32Value(value.dstArrayElement);
    result += encoder->EncodeUInt32Value(value.descriptorCount);
    result += encoder->EncodeEnumValue(value.descriptorType);
    result += encoder->EncodeSizeTValue(value.offset);
    result += encoder->EncodeSizeTValue(value.stride);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorUpdateTemplateCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.descriptorUpdateEntryCount);
    result += encode_struct_array(encoder, value.pDescriptorUpdateEntries, value.descriptorUpdateEntryCount);
    result += encoder->EncodeEnumValue(value.templateType);
    result += encoder->EncodeHandleIdValue(value.descriptorSetLayout);
    result += encoder->EncodeEnumValue(value.pipelineBindPoint);
    result += encoder->EncodeHandleIdValue(value.pipelineLayout);
    result += encoder->EncodeUInt32Value(value.set);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalMemoryProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.externalMemoryFeatures);
    result += encoder->EncodeFlagsValue(value.exportFromImportedHandleTypes);
    result += encoder->EncodeFlagsValue(value.compatibleHandleTypes);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalImageFormatInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.handleType);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalImageFormatProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.externalMemoryProperties);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalBufferInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeFlagsValue(value.usage);
    result += encoder->EncodeEnumValue(value.handleType);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalBufferProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.externalMemoryProperties);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceIDProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt8Array(value.deviceUUID, VK_UUID_SIZE);
    result += encoder->EncodeUInt8Array(value.driverUUID, VK_UUID_SIZE);
    result += encoder->EncodeUInt8Array(value.deviceLUID, VK_LUID_SIZE);
    result += encoder->EncodeUInt32Value(value.deviceNodeMask);
    result += encoder->EncodeVkBool32Value(value.deviceLUIDValid);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalMemoryImageCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.handleTypes);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalMemoryBufferCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.handleTypes);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExportMemoryAllocateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.handleTypes);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalFenceInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.handleType);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalFenceProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.exportFromImportedHandleTypes);
    result += encoder->EncodeFlagsValue(value.compatibleHandleTypes);
    result += encoder->EncodeFlagsValue(value.externalFenceFeatures);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExportFenceCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.handleTypes);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExportSemaphoreCreateInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.handleTypes);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalSemaphoreInfo& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.handleType);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalSemaphoreProperties& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.exportFromImportedHandleTypes);
    result += encoder->EncodeFlagsValue(value.compatibleHandleTypes);
    result += encoder->EncodeFlagsValue(value.externalSemaphoreFeatures);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMaintenance3Properties& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.maxPerSetDescriptors);
    result += encoder->EncodeVkDeviceSizeValue(value.maxMemoryAllocationSize);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetLayoutSupport& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.supported);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceShaderDrawParameterFeatures& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.shaderDrawParameters);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSurfaceCapabilitiesKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.minImageCount);
    result += encoder->EncodeUInt32Value(value.maxImageCount);
    result += encode_struct(encoder, value.currentExtent);
    result += encode_struct(encoder, value.minImageExtent);
    result += encode_struct(encoder, value.maxImageExtent);
    result += encoder->EncodeUInt32Value(value.maxImageArrayLayers);
    result += encoder->EncodeFlagsValue(value.supportedTransforms);
    result += encoder->EncodeEnumValue(value.currentTransform);
    result += encoder->EncodeFlagsValue(value.supportedCompositeAlpha);
    result += encoder->EncodeFlagsValue(value.supportedUsageFlags);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSurfaceFormatKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.format);
    result += encoder->EncodeEnumValue(value.colorSpace);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSwapchainCreateInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeHandleIdValue(value.surface);
    result += encoder->EncodeUInt32Value(value.minImageCount);
    result += encoder->EncodeEnumValue(value.imageFormat);
    result += encoder->EncodeEnumValue(value.imageColorSpace);
    result += encode_struct(encoder, value.imageExtent);
    result += encoder->EncodeUInt32Value(value.imageArrayLayers);
    result += encoder->EncodeFlagsValue(value.imageUsage);
    result += encoder->EncodeEnumValue(value.imageSharingMode);
    result += encoder->EncodeUInt32Value(value.queueFamilyIndexCount);
    result += encoder->EncodeUInt32Array(value.pQueueFamilyIndices, value.queueFamilyIndexCount);
    result += encoder->EncodeEnumValue(value.preTransform);
    result += encoder->EncodeEnumValue(value.compositeAlpha);
    result += encoder->EncodeEnumValue(value.presentMode);
    result += encoder->EncodeVkBool32Value(value.clipped);
    result += encoder->EncodeHandleIdValue(value.oldSwapchain);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPresentInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.waitSemaphoreCount);
    result += encoder->EncodeHandleIdArray(value.pWaitSemaphores, value.waitSemaphoreCount);
    result += encoder->EncodeUInt32Value(value.swapchainCount);
    result += encoder->EncodeHandleIdArray(value.pSwapchains, value.swapchainCount);
    result += encoder->EncodeUInt32Array(value.pImageIndices, value.swapchainCount);
    result += encoder->EncodeEnumArray(value.pResults, value.swapchainCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageSwapchainCreateInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.swapchain);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkBindImageMemorySwapchainInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.swapchain);
    result += encoder->EncodeUInt32Value(value.imageIndex);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkAcquireNextImageInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.swapchain);
    result += encoder->EncodeUInt64Value(value.timeout);
    result += encoder->EncodeHandleIdValue(value.semaphore);
    result += encoder->EncodeHandleIdValue(value.fence);
    result += encoder->EncodeUInt32Value(value.deviceMask);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupPresentCapabilitiesKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Array(value.presentMask, VK_MAX_DEVICE_GROUP_SIZE);
    result += encoder->EncodeFlagsValue(value.modes);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupPresentInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.swapchainCount);
    result += encoder->EncodeUInt32Array(value.pDeviceMasks, value.swapchainCount);
    result += encoder->EncodeEnumValue(value.mode);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGroupSwapchainCreateInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.modes);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPropertiesKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeHandleIdValue(value.display);
    result += encoder->EncodeString(value.displayName);
    result += encode_struct(encoder, value.physicalDimensions);
    result += encode_struct(encoder, value.physicalResolution);
    result += encoder->EncodeFlagsValue(value.supportedTransforms);
    result += encoder->EncodeVkBool32Value(value.planeReorderPossible);
    result += encoder->EncodeVkBool32Value(value.persistentContent);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayModeParametersKHR& value)
{
    size_t result = 0;
    result += encode_struct(encoder, value.visibleRegion);
    result += encoder->EncodeUInt32Value(value.refreshRate);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayModePropertiesKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeHandleIdValue(value.displayMode);
    result += encode_struct(encoder, value.parameters);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayModeCreateInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encode_struct(encoder, value.parameters);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlaneCapabilitiesKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.supportedAlpha);
    result += encode_struct(encoder, value.minSrcPosition);
    result += encode_struct(encoder, value.maxSrcPosition);
    result += encode_struct(encoder, value.minSrcExtent);
    result += encode_struct(encoder, value.maxSrcExtent);
    result += encode_struct(encoder, value.minDstPosition);
    result += encode_struct(encoder, value.maxDstPosition);
    result += encode_struct(encoder, value.minDstExtent);
    result += encode_struct(encoder, value.maxDstExtent);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlanePropertiesKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeHandleIdValue(value.currentDisplay);
    result += encoder->EncodeUInt32Value(value.currentStackIndex);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplaySurfaceCreateInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeHandleIdValue(value.displayMode);
    result += encoder->EncodeUInt32Value(value.planeIndex);
    result += encoder->EncodeUInt32Value(value.planeStackIndex);
    result += encoder->EncodeEnumValue(value.transform);
    result += encoder->EncodeFloatValue(value.globalAlpha);
    result += encoder->EncodeEnumValue(value.alphaMode);
    result += encode_struct(encoder, value.imageExtent);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPresentInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.srcRect);
    result += encode_struct(encoder, value.dstRect);
    result += encoder->EncodeVkBool32Value(value.persistent);
    return result;
}


#ifdef VK_USE_PLATFORM_XLIB_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkXlibSurfaceCreateInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVoidPtr(value.dpy);
    result += encoder->EncodeUInt32Value(value.window);
    return result;
}

#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkXcbSurfaceCreateInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVoidPtr(value.connection);
    result += encoder->EncodeUInt32Value(value.window);
    return result;
}

#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkWaylandSurfaceCreateInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVoidPtr(value.display);
    result += encoder->EncodeVoidPtr(value.surface);
    return result;
}

#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkMirSurfaceCreateInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVoidPtr(value.connection);
    result += encoder->EncodeVoidPtr(value.mirSurface);
    return result;
}

#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkAndroidSurfaceCreateInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVoidPtr(value.window);
    return result;
}

#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkWin32SurfaceCreateInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVoidPtr(value.hinstance);
    result += encoder->EncodeVoidPtr(value.hwnd);
    return result;
}

#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkImportMemoryWin32HandleInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.handleType);
    result += encoder->EncodeVoidPtr(value.handle);
    result += encoder->EncodeWString(value.name);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExportMemoryWin32HandleInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct_ptr(encoder, value.pAttributes);
    result += encoder->EncodeUInt32Value(value.dwAccess);
    result += encoder->EncodeWString(value.name);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryWin32HandlePropertiesKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.memoryTypeBits);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryGetWin32HandleInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.memory);
    result += encoder->EncodeEnumValue(value.handleType);
    return result;
}

#endif /* VK_USE_PLATFORM_WIN32_KHR */

size_t encode_struct(format::ParameterEncoder* encoder, const VkImportMemoryFdInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.handleType);
    result += encoder->EncodeInt32Value(value.fd);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryFdPropertiesKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.memoryTypeBits);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryGetFdInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.memory);
    result += encoder->EncodeEnumValue(value.handleType);
    return result;
}


#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkWin32KeyedMutexAcquireReleaseInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.acquireCount);
    result += encoder->EncodeHandleIdArray(value.pAcquireSyncs, value.acquireCount);
    result += encoder->EncodeUInt64Array(value.pAcquireKeys, value.acquireCount);
    result += encoder->EncodeUInt32Array(value.pAcquireTimeouts, value.acquireCount);
    result += encoder->EncodeUInt32Value(value.releaseCount);
    result += encoder->EncodeHandleIdArray(value.pReleaseSyncs, value.releaseCount);
    result += encoder->EncodeUInt64Array(value.pReleaseKeys, value.releaseCount);
    return result;
}

#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkImportSemaphoreWin32HandleInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.semaphore);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.handleType);
    result += encoder->EncodeVoidPtr(value.handle);
    result += encoder->EncodeWString(value.name);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExportSemaphoreWin32HandleInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct_ptr(encoder, value.pAttributes);
    result += encoder->EncodeUInt32Value(value.dwAccess);
    result += encoder->EncodeWString(value.name);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkD3D12FenceSubmitInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.waitSemaphoreValuesCount);
    result += encoder->EncodeUInt64Array(value.pWaitSemaphoreValues, value.waitSemaphoreValuesCount);
    result += encoder->EncodeUInt32Value(value.signalSemaphoreValuesCount);
    result += encoder->EncodeUInt64Array(value.pSignalSemaphoreValues, value.signalSemaphoreValuesCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSemaphoreGetWin32HandleInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.semaphore);
    result += encoder->EncodeEnumValue(value.handleType);
    return result;
}

#endif /* VK_USE_PLATFORM_WIN32_KHR */

size_t encode_struct(format::ParameterEncoder* encoder, const VkImportSemaphoreFdInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.semaphore);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.handleType);
    result += encoder->EncodeInt32Value(value.fd);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSemaphoreGetFdInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.semaphore);
    result += encoder->EncodeEnumValue(value.handleType);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDevicePushDescriptorPropertiesKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.maxPushDescriptors);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkRectLayerKHR& value)
{
    size_t result = 0;
    result += encode_struct(encoder, value.offset);
    result += encode_struct(encoder, value.extent);
    result += encoder->EncodeUInt32Value(value.layer);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPresentRegionKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.rectangleCount);
    result += encode_struct_array(encoder, value.pRectangles, value.rectangleCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPresentRegionsKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.swapchainCount);
    result += encode_struct_array(encoder, value.pRegions, value.swapchainCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkAttachmentDescription2KHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.format);
    result += encoder->EncodeEnumValue(value.samples);
    result += encoder->EncodeEnumValue(value.loadOp);
    result += encoder->EncodeEnumValue(value.storeOp);
    result += encoder->EncodeEnumValue(value.stencilLoadOp);
    result += encoder->EncodeEnumValue(value.stencilStoreOp);
    result += encoder->EncodeEnumValue(value.initialLayout);
    result += encoder->EncodeEnumValue(value.finalLayout);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkAttachmentReference2KHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.attachment);
    result += encoder->EncodeEnumValue(value.layout);
    result += encoder->EncodeFlagsValue(value.aspectMask);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassDescription2KHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.pipelineBindPoint);
    result += encoder->EncodeUInt32Value(value.viewMask);
    result += encoder->EncodeUInt32Value(value.inputAttachmentCount);
    result += encode_struct_array(encoder, value.pInputAttachments, value.inputAttachmentCount);
    result += encoder->EncodeUInt32Value(value.colorAttachmentCount);
    result += encode_struct_array(encoder, value.pColorAttachments, value.colorAttachmentCount);
    result += encode_struct_array(encoder, value.pResolveAttachments, value.colorAttachmentCount);
    result += encode_struct_ptr(encoder, value.pDepthStencilAttachment);
    result += encoder->EncodeUInt32Value(value.preserveAttachmentCount);
    result += encoder->EncodeUInt32Array(value.pPreserveAttachments, value.preserveAttachmentCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassDependency2KHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.srcSubpass);
    result += encoder->EncodeUInt32Value(value.dstSubpass);
    result += encoder->EncodeFlagsValue(value.srcStageMask);
    result += encoder->EncodeFlagsValue(value.dstStageMask);
    result += encoder->EncodeFlagsValue(value.srcAccessMask);
    result += encoder->EncodeFlagsValue(value.dstAccessMask);
    result += encoder->EncodeFlagsValue(value.dependencyFlags);
    result += encoder->EncodeInt32Value(value.viewOffset);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkRenderPassCreateInfo2KHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.attachmentCount);
    result += encode_struct_array(encoder, value.pAttachments, value.attachmentCount);
    result += encoder->EncodeUInt32Value(value.subpassCount);
    result += encode_struct_array(encoder, value.pSubpasses, value.subpassCount);
    result += encoder->EncodeUInt32Value(value.dependencyCount);
    result += encode_struct_array(encoder, value.pDependencies, value.dependencyCount);
    result += encoder->EncodeUInt32Value(value.correlatedViewMaskCount);
    result += encoder->EncodeUInt32Array(value.pCorrelatedViewMasks, value.correlatedViewMaskCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassBeginInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.contents);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassEndInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSharedPresentSurfaceCapabilitiesKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.sharedPresentSupportedUsageFlags);
    return result;
}


#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkImportFenceWin32HandleInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.fence);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.handleType);
    result += encoder->EncodeVoidPtr(value.handle);
    result += encoder->EncodeWString(value.name);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExportFenceWin32HandleInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct_ptr(encoder, value.pAttributes);
    result += encoder->EncodeUInt32Value(value.dwAccess);
    result += encoder->EncodeWString(value.name);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkFenceGetWin32HandleInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.fence);
    result += encoder->EncodeEnumValue(value.handleType);
    return result;
}

#endif /* VK_USE_PLATFORM_WIN32_KHR */

size_t encode_struct(format::ParameterEncoder* encoder, const VkImportFenceFdInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.fence);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.handleType);
    result += encoder->EncodeInt32Value(value.fd);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkFenceGetFdInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.fence);
    result += encoder->EncodeEnumValue(value.handleType);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSurfaceInfo2KHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.surface);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSurfaceCapabilities2KHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.surfaceCapabilities);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSurfaceFormat2KHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.surfaceFormat);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayProperties2KHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.displayProperties);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlaneProperties2KHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.displayPlaneProperties);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayModeProperties2KHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.displayModeProperties);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlaneInfo2KHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.mode);
    result += encoder->EncodeUInt32Value(value.planeIndex);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPlaneCapabilities2KHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.capabilities);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImageFormatListCreateInfoKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.viewFormatCount);
    result += encoder->EncodeEnumArray(value.pViewFormats, value.viewFormatCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDevice8BitStorageFeaturesKHR& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.storageBuffer8BitAccess);
    result += encoder->EncodeVkBool32Value(value.uniformAndStorageBuffer8BitAccess);
    result += encoder->EncodeVkBool32Value(value.storagePushConstant8);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugReportCallbackCreateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeFunctionPtr(value.pfnCallback);
    result += encoder->EncodeVoidPtr(value.pUserData);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineRasterizationStateRasterizationOrderAMD& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.rasterizationOrder);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugMarkerObjectNameInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.objectType);
    result += encoder->EncodeUInt64Value(value.object);
    result += encoder->EncodeString(value.pObjectName);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugMarkerObjectTagInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.objectType);
    result += encoder->EncodeUInt64Value(value.object);
    result += encoder->EncodeUInt64Value(value.tagName);
    result += encoder->EncodeSizeTValue(value.tagSize);
    result += encoder->EncodeVoidArray(value.pTag, value.tagSize);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugMarkerMarkerInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeString(value.pMarkerName);
    result += encoder->EncodeFloatArray(value.color, 4);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDedicatedAllocationImageCreateInfoNV& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.dedicatedAllocation);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDedicatedAllocationBufferCreateInfoNV& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.dedicatedAllocation);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDedicatedAllocationMemoryAllocateInfoNV& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.image);
    result += encoder->EncodeHandleIdValue(value.buffer);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkTextureLODGatherFormatPropertiesAMD& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.supportsTextureGatherLODBiasAMD);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkShaderResourceUsageAMD& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.numUsedVgprs);
    result += encoder->EncodeUInt32Value(value.numUsedSgprs);
    result += encoder->EncodeUInt32Value(value.ldsSizePerLocalWorkGroup);
    result += encoder->EncodeSizeTValue(value.ldsUsageSizeInBytes);
    result += encoder->EncodeSizeTValue(value.scratchMemUsageInBytes);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkShaderStatisticsInfoAMD& value)
{
    size_t result = 0;
    result += encoder->EncodeFlagsValue(value.shaderStageMask);
    result += encode_struct(encoder, value.resourceUsage);
    result += encoder->EncodeUInt32Value(value.numPhysicalVgprs);
    result += encoder->EncodeUInt32Value(value.numPhysicalSgprs);
    result += encoder->EncodeUInt32Value(value.numAvailableVgprs);
    result += encoder->EncodeUInt32Value(value.numAvailableSgprs);
    result += encoder->EncodeUInt32Array(value.computeWorkGroupSize, 3);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalImageFormatPropertiesNV& value)
{
    size_t result = 0;
    result += encode_struct(encoder, value.imageFormatProperties);
    result += encoder->EncodeFlagsValue(value.externalMemoryFeatures);
    result += encoder->EncodeFlagsValue(value.exportFromImportedHandleTypes);
    result += encoder->EncodeFlagsValue(value.compatibleHandleTypes);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalMemoryImageCreateInfoNV& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.handleTypes);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExportMemoryAllocateInfoNV& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.handleTypes);
    return result;
}


#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkImportMemoryWin32HandleInfoNV& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.handleType);
    result += encoder->EncodeVoidPtr(value.handle);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExportMemoryWin32HandleInfoNV& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct_ptr(encoder, value.pAttributes);
    result += encoder->EncodeUInt32Value(value.dwAccess);
    return result;
}

#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkWin32KeyedMutexAcquireReleaseInfoNV& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.acquireCount);
    result += encoder->EncodeHandleIdArray(value.pAcquireSyncs, value.acquireCount);
    result += encoder->EncodeUInt64Array(value.pAcquireKeys, value.acquireCount);
    result += encoder->EncodeUInt32Array(value.pAcquireTimeoutMilliseconds, value.acquireCount);
    result += encoder->EncodeUInt32Value(value.releaseCount);
    result += encoder->EncodeHandleIdArray(value.pReleaseSyncs, value.releaseCount);
    result += encoder->EncodeUInt64Array(value.pReleaseKeys, value.releaseCount);
    return result;
}

#endif /* VK_USE_PLATFORM_WIN32_KHR */

size_t encode_struct(format::ParameterEncoder* encoder, const VkValidationFlagsEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.disabledValidationCheckCount);
    result += encoder->EncodeEnumArray(value.pDisabledValidationChecks, value.disabledValidationCheckCount);
    return result;
}


#ifdef VK_USE_PLATFORM_VI_NN
size_t encode_struct(format::ParameterEncoder* encoder, const VkViSurfaceCreateInfoNN& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVoidPtr(value.window);
    return result;
}

#endif /* VK_USE_PLATFORM_VI_NN */

size_t encode_struct(format::ParameterEncoder* encoder, const VkConditionalRenderingBeginInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.buffer);
    result += encoder->EncodeVkDeviceSizeValue(value.offset);
    result += encoder->EncodeFlagsValue(value.flags);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceConditionalRenderingFeaturesEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.conditionalRendering);
    result += encoder->EncodeVkBool32Value(value.inheritedConditionalRendering);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkCommandBufferInheritanceConditionalRenderingInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.conditionalRenderingEnable);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGeneratedCommandsFeaturesNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.computeBindingPointSupport);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceGeneratedCommandsLimitsNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.maxIndirectCommandsLayoutTokenCount);
    result += encoder->EncodeUInt32Value(value.maxObjectEntryCounts);
    result += encoder->EncodeUInt32Value(value.minSequenceCountBufferOffsetAlignment);
    result += encoder->EncodeUInt32Value(value.minSequenceIndexBufferOffsetAlignment);
    result += encoder->EncodeUInt32Value(value.minCommandsTokenBufferOffsetAlignment);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkIndirectCommandsTokenNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.tokenType);
    result += encoder->EncodeHandleIdValue(value.buffer);
    result += encoder->EncodeVkDeviceSizeValue(value.offset);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkIndirectCommandsLayoutTokenNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.tokenType);
    result += encoder->EncodeUInt32Value(value.bindingUnit);
    result += encoder->EncodeUInt32Value(value.dynamicCount);
    result += encoder->EncodeUInt32Value(value.divisor);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkIndirectCommandsLayoutCreateInfoNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.pipelineBindPoint);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.tokenCount);
    result += encode_struct_array(encoder, value.pTokens, value.tokenCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkCmdProcessCommandsInfoNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.objectTable);
    result += encoder->EncodeHandleIdValue(value.indirectCommandsLayout);
    result += encoder->EncodeUInt32Value(value.indirectCommandsTokenCount);
    result += encode_struct_array(encoder, value.pIndirectCommandsTokens, value.indirectCommandsTokenCount);
    result += encoder->EncodeUInt32Value(value.maxSequencesCount);
    result += encoder->EncodeHandleIdValue(value.targetCommandBuffer);
    result += encoder->EncodeHandleIdValue(value.sequencesCountBuffer);
    result += encoder->EncodeVkDeviceSizeValue(value.sequencesCountOffset);
    result += encoder->EncodeHandleIdValue(value.sequencesIndexBuffer);
    result += encoder->EncodeVkDeviceSizeValue(value.sequencesIndexOffset);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkCmdReserveSpaceForCommandsInfoNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.objectTable);
    result += encoder->EncodeHandleIdValue(value.indirectCommandsLayout);
    result += encoder->EncodeUInt32Value(value.maxSequencesCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkObjectTableCreateInfoNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.objectCount);
    result += encoder->EncodeEnumArray(value.pObjectEntryTypes, value.objectCount);
    result += encoder->EncodeUInt32Array(value.pObjectEntryCounts, value.objectCount);
    result += encoder->EncodeFlagsArray(value.pObjectEntryUsageFlags, value.objectCount);
    result += encoder->EncodeUInt32Value(value.maxUniformBuffersPerDescriptor);
    result += encoder->EncodeUInt32Value(value.maxStorageBuffersPerDescriptor);
    result += encoder->EncodeUInt32Value(value.maxStorageImagesPerDescriptor);
    result += encoder->EncodeUInt32Value(value.maxSampledImagesPerDescriptor);
    result += encoder->EncodeUInt32Value(value.maxPipelineLayouts);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkObjectTablePipelineEntryNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.type);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeHandleIdValue(value.pipeline);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkObjectTableDescriptorSetEntryNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.type);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeHandleIdValue(value.pipelineLayout);
    result += encoder->EncodeHandleIdValue(value.descriptorSet);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkObjectTableVertexBufferEntryNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.type);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeHandleIdValue(value.buffer);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkObjectTableIndexBufferEntryNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.type);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeHandleIdValue(value.buffer);
    result += encoder->EncodeEnumValue(value.indexType);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkObjectTablePushConstantEntryNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.type);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeHandleIdValue(value.pipelineLayout);
    result += encoder->EncodeFlagsValue(value.stageFlags);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkViewportWScalingNV& value)
{
    size_t result = 0;
    result += encoder->EncodeFloatValue(value.xcoeff);
    result += encoder->EncodeFloatValue(value.ycoeff);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineViewportWScalingStateCreateInfoNV& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.viewportWScalingEnable);
    result += encoder->EncodeUInt32Value(value.viewportCount);
    result += encode_struct_array(encoder, value.pViewportWScalings, value.viewportCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSurfaceCapabilities2EXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.minImageCount);
    result += encoder->EncodeUInt32Value(value.maxImageCount);
    result += encode_struct(encoder, value.currentExtent);
    result += encode_struct(encoder, value.minImageExtent);
    result += encode_struct(encoder, value.maxImageExtent);
    result += encoder->EncodeUInt32Value(value.maxImageArrayLayers);
    result += encoder->EncodeFlagsValue(value.supportedTransforms);
    result += encoder->EncodeEnumValue(value.currentTransform);
    result += encoder->EncodeFlagsValue(value.supportedCompositeAlpha);
    result += encoder->EncodeFlagsValue(value.supportedUsageFlags);
    result += encoder->EncodeFlagsValue(value.supportedSurfaceCounters);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayPowerInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.powerState);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceEventInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.deviceEvent);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDisplayEventInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.displayEvent);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSwapchainCounterCreateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.surfaceCounters);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkRefreshCycleDurationGOOGLE& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt64Value(value.refreshDuration);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPastPresentationTimingGOOGLE& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.presentID);
    result += encoder->EncodeUInt64Value(value.desiredPresentTime);
    result += encoder->EncodeUInt64Value(value.actualPresentTime);
    result += encoder->EncodeUInt64Value(value.earliestPresentTime);
    result += encoder->EncodeUInt64Value(value.presentMargin);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPresentTimeGOOGLE& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.presentID);
    result += encoder->EncodeUInt64Value(value.desiredPresentTime);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPresentTimesInfoGOOGLE& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.swapchainCount);
    result += encode_struct_array(encoder, value.pTimes, value.swapchainCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.perViewPositionAllComponents);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkViewportSwizzleNV& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.x);
    result += encoder->EncodeEnumValue(value.y);
    result += encoder->EncodeEnumValue(value.z);
    result += encoder->EncodeEnumValue(value.w);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineViewportSwizzleStateCreateInfoNV& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeUInt32Value(value.viewportCount);
    result += encode_struct_array(encoder, value.pViewportSwizzles, value.viewportCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceDiscardRectanglePropertiesEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.maxDiscardRectangles);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineDiscardRectangleStateCreateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.discardRectangleMode);
    result += encoder->EncodeUInt32Value(value.discardRectangleCount);
    result += encode_struct_array(encoder, value.pDiscardRectangles, value.discardRectangleCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceConservativeRasterizationPropertiesEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFloatValue(value.primitiveOverestimationSize);
    result += encoder->EncodeFloatValue(value.maxExtraPrimitiveOverestimationSize);
    result += encoder->EncodeFloatValue(value.extraPrimitiveOverestimationSizeGranularity);
    result += encoder->EncodeVkBool32Value(value.primitiveUnderestimation);
    result += encoder->EncodeVkBool32Value(value.conservativePointAndLineRasterization);
    result += encoder->EncodeVkBool32Value(value.degenerateTrianglesRasterized);
    result += encoder->EncodeVkBool32Value(value.degenerateLinesRasterized);
    result += encoder->EncodeVkBool32Value(value.fullyCoveredFragmentShaderInputVariable);
    result += encoder->EncodeVkBool32Value(value.conservativeRasterizationPostDepthCoverage);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineRasterizationConservativeStateCreateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.conservativeRasterizationMode);
    result += encoder->EncodeFloatValue(value.extraPrimitiveOverestimationSize);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkXYColorEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeFloatValue(value.x);
    result += encoder->EncodeFloatValue(value.y);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkHdrMetadataEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.displayPrimaryRed);
    result += encode_struct(encoder, value.displayPrimaryGreen);
    result += encode_struct(encoder, value.displayPrimaryBlue);
    result += encode_struct(encoder, value.whitePoint);
    result += encoder->EncodeFloatValue(value.maxLuminance);
    result += encoder->EncodeFloatValue(value.minLuminance);
    result += encoder->EncodeFloatValue(value.maxContentLightLevel);
    result += encoder->EncodeFloatValue(value.maxFrameAverageLightLevel);
    return result;
}


#ifdef VK_USE_PLATFORM_IOS_MVK
size_t encode_struct(format::ParameterEncoder* encoder, const VkIOSSurfaceCreateInfoMVK& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVoidPtr(value.pView);
    return result;
}

#endif /* VK_USE_PLATFORM_IOS_MVK */

#ifdef VK_USE_PLATFORM_MACOS_MVK
size_t encode_struct(format::ParameterEncoder* encoder, const VkMacOSSurfaceCreateInfoMVK& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVoidPtr(value.pView);
    return result;
}

#endif /* VK_USE_PLATFORM_MACOS_MVK */

size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsObjectNameInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.objectType);
    result += encoder->EncodeUInt64Value(value.objectHandle);
    result += encoder->EncodeString(value.pObjectName);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsObjectTagInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.objectType);
    result += encoder->EncodeUInt64Value(value.objectHandle);
    result += encoder->EncodeUInt64Value(value.tagName);
    result += encoder->EncodeSizeTValue(value.tagSize);
    result += encoder->EncodeVoidArray(value.pTag, value.tagSize);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsLabelEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeString(value.pLabelName);
    result += encoder->EncodeFloatArray(value.color, 4);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsMessengerCallbackDataEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeString(value.pMessageIdName);
    result += encoder->EncodeInt32Value(value.messageIdNumber);
    result += encoder->EncodeString(value.pMessage);
    result += encoder->EncodeUInt32Value(value.queueLabelCount);
    result += encode_struct_array(encoder, value.pQueueLabels, value.queueLabelCount);
    result += encoder->EncodeUInt32Value(value.cmdBufLabelCount);
    result += encode_struct_array(encoder, value.pCmdBufLabels, value.cmdBufLabelCount);
    result += encoder->EncodeUInt32Value(value.objectCount);
    result += encode_struct_array(encoder, value.pObjects, value.objectCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDebugUtilsMessengerCreateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeFlagsValue(value.messageSeverity);
    result += encoder->EncodeFlagsValue(value.messageType);
    result += encoder->EncodeFunctionPtr(value.pfnUserCallback);
    result += encoder->EncodeVoidPtr(value.pUserData);
    return result;
}


#ifdef VK_USE_PLATFORM_ANDROID_KHR
size_t encode_struct(format::ParameterEncoder* encoder, const VkAndroidHardwareBufferUsageANDROID& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt64Value(value.androidHardwareBufferUsage);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkAndroidHardwareBufferPropertiesANDROID& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkDeviceSizeValue(value.allocationSize);
    result += encoder->EncodeUInt32Value(value.memoryTypeBits);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkAndroidHardwareBufferFormatPropertiesANDROID& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.format);
    result += encoder->EncodeUInt64Value(value.externalFormat);
    result += encoder->EncodeFlagsValue(value.formatFeatures);
    result += encode_struct(encoder, value.samplerYcbcrConversionComponents);
    result += encoder->EncodeEnumValue(value.suggestedYcbcrModel);
    result += encoder->EncodeEnumValue(value.suggestedYcbcrRange);
    result += encoder->EncodeEnumValue(value.suggestedXChromaOffset);
    result += encoder->EncodeEnumValue(value.suggestedYChromaOffset);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImportAndroidHardwareBufferInfoANDROID& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVoidPtr(value.buffer);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryGetAndroidHardwareBufferInfoANDROID& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.memory);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkExternalFormatANDROID& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt64Value(value.externalFormat);
    return result;
}

#endif /* VK_USE_PLATFORM_ANDROID_KHR */

size_t encode_struct(format::ParameterEncoder* encoder, const VkSamplerReductionModeCreateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.reductionMode);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.filterMinmaxSingleComponentFormats);
    result += encoder->EncodeVkBool32Value(value.filterMinmaxImageComponentMapping);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSampleLocationEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeFloatValue(value.x);
    result += encoder->EncodeFloatValue(value.y);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSampleLocationsInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.sampleLocationsPerPixel);
    result += encode_struct(encoder, value.sampleLocationGridSize);
    result += encoder->EncodeUInt32Value(value.sampleLocationsCount);
    result += encode_struct_array(encoder, value.pSampleLocations, value.sampleLocationsCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkAttachmentSampleLocationsEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.attachmentIndex);
    result += encode_struct(encoder, value.sampleLocationsInfo);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkSubpassSampleLocationsEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.subpassIndex);
    result += encode_struct(encoder, value.sampleLocationsInfo);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkRenderPassSampleLocationsBeginInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.attachmentInitialSampleLocationsCount);
    result += encode_struct_array(encoder, value.pAttachmentInitialSampleLocations, value.attachmentInitialSampleLocationsCount);
    result += encoder->EncodeUInt32Value(value.postSubpassSampleLocationsCount);
    result += encode_struct_array(encoder, value.pPostSubpassSampleLocations, value.postSubpassSampleLocationsCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineSampleLocationsStateCreateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.sampleLocationsEnable);
    result += encode_struct(encoder, value.sampleLocationsInfo);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceSampleLocationsPropertiesEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.sampleLocationSampleCounts);
    result += encode_struct(encoder, value.maxSampleLocationGridSize);
    result += encoder->EncodeFloatArray(value.sampleLocationCoordinateRange, 2);
    result += encoder->EncodeUInt32Value(value.sampleLocationSubPixelBits);
    result += encoder->EncodeVkBool32Value(value.variableSampleLocations);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMultisamplePropertiesEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encode_struct(encoder, value.maxSampleLocationGridSize);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.advancedBlendCoherentOperations);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.advancedBlendMaxColorAttachments);
    result += encoder->EncodeVkBool32Value(value.advancedBlendIndependentBlend);
    result += encoder->EncodeVkBool32Value(value.advancedBlendNonPremultipliedSrcColor);
    result += encoder->EncodeVkBool32Value(value.advancedBlendNonPremultipliedDstColor);
    result += encoder->EncodeVkBool32Value(value.advancedBlendCorrelatedOverlap);
    result += encoder->EncodeVkBool32Value(value.advancedBlendAllOperations);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineColorBlendAdvancedStateCreateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.srcPremultiplied);
    result += encoder->EncodeVkBool32Value(value.dstPremultiplied);
    result += encoder->EncodeEnumValue(value.blendOverlap);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineCoverageToColorStateCreateInfoNV& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeVkBool32Value(value.coverageToColorEnable);
    result += encoder->EncodeUInt32Value(value.coverageToColorLocation);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineCoverageModulationStateCreateInfoNV& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeEnumValue(value.coverageModulationMode);
    result += encoder->EncodeVkBool32Value(value.coverageModulationTableEnable);
    result += encoder->EncodeUInt32Value(value.coverageModulationTableCount);
    result += encoder->EncodeFloatArray(value.pCoverageModulationTable, value.coverageModulationTableCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkValidationCacheCreateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeFlagsValue(value.flags);
    result += encoder->EncodeSizeTValue(value.initialDataSize);
    result += encoder->EncodeVoidArray(value.pInitialData, value.initialDataSize);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkShaderModuleValidationCacheCreateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeHandleIdValue(value.validationCache);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetLayoutBindingFlagsCreateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.bindingCount);
    result += encoder->EncodeFlagsArray(value.pBindingFlags, value.bindingCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorIndexingFeaturesEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkBool32Value(value.shaderInputAttachmentArrayDynamicIndexing);
    result += encoder->EncodeVkBool32Value(value.shaderUniformTexelBufferArrayDynamicIndexing);
    result += encoder->EncodeVkBool32Value(value.shaderStorageTexelBufferArrayDynamicIndexing);
    result += encoder->EncodeVkBool32Value(value.shaderUniformBufferArrayNonUniformIndexing);
    result += encoder->EncodeVkBool32Value(value.shaderSampledImageArrayNonUniformIndexing);
    result += encoder->EncodeVkBool32Value(value.shaderStorageBufferArrayNonUniformIndexing);
    result += encoder->EncodeVkBool32Value(value.shaderStorageImageArrayNonUniformIndexing);
    result += encoder->EncodeVkBool32Value(value.shaderInputAttachmentArrayNonUniformIndexing);
    result += encoder->EncodeVkBool32Value(value.shaderUniformTexelBufferArrayNonUniformIndexing);
    result += encoder->EncodeVkBool32Value(value.shaderStorageTexelBufferArrayNonUniformIndexing);
    result += encoder->EncodeVkBool32Value(value.descriptorBindingUniformBufferUpdateAfterBind);
    result += encoder->EncodeVkBool32Value(value.descriptorBindingSampledImageUpdateAfterBind);
    result += encoder->EncodeVkBool32Value(value.descriptorBindingStorageImageUpdateAfterBind);
    result += encoder->EncodeVkBool32Value(value.descriptorBindingStorageBufferUpdateAfterBind);
    result += encoder->EncodeVkBool32Value(value.descriptorBindingUniformTexelBufferUpdateAfterBind);
    result += encoder->EncodeVkBool32Value(value.descriptorBindingStorageTexelBufferUpdateAfterBind);
    result += encoder->EncodeVkBool32Value(value.descriptorBindingUpdateUnusedWhilePending);
    result += encoder->EncodeVkBool32Value(value.descriptorBindingPartiallyBound);
    result += encoder->EncodeVkBool32Value(value.descriptorBindingVariableDescriptorCount);
    result += encoder->EncodeVkBool32Value(value.runtimeDescriptorArray);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorIndexingPropertiesEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.maxUpdateAfterBindDescriptorsInAllPools);
    result += encoder->EncodeVkBool32Value(value.shaderUniformBufferArrayNonUniformIndexingNative);
    result += encoder->EncodeVkBool32Value(value.shaderSampledImageArrayNonUniformIndexingNative);
    result += encoder->EncodeVkBool32Value(value.shaderStorageBufferArrayNonUniformIndexingNative);
    result += encoder->EncodeVkBool32Value(value.shaderStorageImageArrayNonUniformIndexingNative);
    result += encoder->EncodeVkBool32Value(value.shaderInputAttachmentArrayNonUniformIndexingNative);
    result += encoder->EncodeVkBool32Value(value.robustBufferAccessUpdateAfterBind);
    result += encoder->EncodeVkBool32Value(value.quadDivergentImplicitLod);
    result += encoder->EncodeUInt32Value(value.maxPerStageDescriptorUpdateAfterBindSamplers);
    result += encoder->EncodeUInt32Value(value.maxPerStageDescriptorUpdateAfterBindUniformBuffers);
    result += encoder->EncodeUInt32Value(value.maxPerStageDescriptorUpdateAfterBindStorageBuffers);
    result += encoder->EncodeUInt32Value(value.maxPerStageDescriptorUpdateAfterBindSampledImages);
    result += encoder->EncodeUInt32Value(value.maxPerStageDescriptorUpdateAfterBindStorageImages);
    result += encoder->EncodeUInt32Value(value.maxPerStageDescriptorUpdateAfterBindInputAttachments);
    result += encoder->EncodeUInt32Value(value.maxPerStageUpdateAfterBindResources);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindSamplers);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindUniformBuffers);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindStorageBuffers);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindSampledImages);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindStorageImages);
    result += encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindInputAttachments);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetVariableDescriptorCountAllocateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.descriptorSetCount);
    result += encoder->EncodeUInt32Array(value.pDescriptorCounts, value.descriptorSetCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDescriptorSetVariableDescriptorCountLayoutSupportEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.maxVariableDescriptorCount);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkDeviceQueueGlobalPriorityCreateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.globalPriority);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkImportMemoryHostPointerInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeEnumValue(value.handleType);
    result += encoder->EncodeVoidPtr(value.pHostPointer);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkMemoryHostPointerPropertiesEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.memoryTypeBits);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceExternalMemoryHostPropertiesEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeVkDeviceSizeValue(value.minImportedHostPointerAlignment);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceShaderCorePropertiesAMD& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.shaderEngineCount);
    result += encoder->EncodeUInt32Value(value.shaderArraysPerEngineCount);
    result += encoder->EncodeUInt32Value(value.computeUnitsPerShaderArray);
    result += encoder->EncodeUInt32Value(value.simdPerComputeUnit);
    result += encoder->EncodeUInt32Value(value.wavefrontsPerSimd);
    result += encoder->EncodeUInt32Value(value.wavefrontSize);
    result += encoder->EncodeUInt32Value(value.sgprsPerSimd);
    result += encoder->EncodeUInt32Value(value.minSgprAllocation);
    result += encoder->EncodeUInt32Value(value.maxSgprAllocation);
    result += encoder->EncodeUInt32Value(value.sgprAllocationGranularity);
    result += encoder->EncodeUInt32Value(value.vgprsPerSimd);
    result += encoder->EncodeUInt32Value(value.minVgprAllocation);
    result += encoder->EncodeUInt32Value(value.maxVgprAllocation);
    result += encoder->EncodeUInt32Value(value.vgprAllocationGranularity);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.maxVertexAttribDivisor);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkVertexInputBindingDivisorDescriptionEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(value.binding);
    result += encoder->EncodeUInt32Value(value.divisor);
    return result;
}


size_t encode_struct(format::ParameterEncoder* encoder, const VkPipelineVertexInputDivisorStateCreateInfoEXT& value)
{
    size_t result = 0;
    result += encoder->EncodeEnumValue(value.sType);
    result += encode_pnext_struct(encoder, value.pNext);
    result += encoder->EncodeUInt32Value(value.vertexBindingDivisorCount);
    result += encode_struct_array(encoder, value.pVertexBindingDivisors, value.vertexBindingDivisorCount);
    return result;
}


BRIMSTONE_END_NAMESPACE(brimstone)
