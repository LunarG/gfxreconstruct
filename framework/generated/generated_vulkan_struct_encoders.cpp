/*
** Copyright (c) 2018 Valve Corporation
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

#include "generated/generated_vulkan_struct_encoders.h"

#include "encode/custom_vulkan_struct_encoders.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cmath>

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(encode)

void encode_struct(ParameterEncoder* encoder, const VkApplicationInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeString(value.pApplicationName);
    encoder->EncodeUInt32Value(value.applicationVersion);
    encoder->EncodeString(value.pEngineName);
    encoder->EncodeUInt32Value(value.engineVersion);
    encoder->EncodeUInt32Value(value.apiVersion);
}

void encode_struct(ParameterEncoder* encoder, const VkInstanceCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encode_struct_ptr(encoder, value.pApplicationInfo);
    encoder->EncodeUInt32Value(value.enabledLayerCount);
    encoder->EncodeStringArray(value.ppEnabledLayerNames, value.enabledLayerCount);
    encoder->EncodeUInt32Value(value.enabledExtensionCount);
    encoder->EncodeStringArray(value.ppEnabledExtensionNames, value.enabledExtensionCount);
}

void encode_struct(ParameterEncoder* encoder, const VkAllocationCallbacks& value)
{
    encoder->EncodeVoidPtr(value.pUserData);
    encoder->EncodeFunctionPtr(value.pfnAllocation);
    encoder->EncodeFunctionPtr(value.pfnReallocation);
    encoder->EncodeFunctionPtr(value.pfnFree);
    encoder->EncodeFunctionPtr(value.pfnInternalAllocation);
    encoder->EncodeFunctionPtr(value.pfnInternalFree);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceFeatures& value)
{
    encoder->EncodeVkBool32Value(value.robustBufferAccess);
    encoder->EncodeVkBool32Value(value.fullDrawIndexUint32);
    encoder->EncodeVkBool32Value(value.imageCubeArray);
    encoder->EncodeVkBool32Value(value.independentBlend);
    encoder->EncodeVkBool32Value(value.geometryShader);
    encoder->EncodeVkBool32Value(value.tessellationShader);
    encoder->EncodeVkBool32Value(value.sampleRateShading);
    encoder->EncodeVkBool32Value(value.dualSrcBlend);
    encoder->EncodeVkBool32Value(value.logicOp);
    encoder->EncodeVkBool32Value(value.multiDrawIndirect);
    encoder->EncodeVkBool32Value(value.drawIndirectFirstInstance);
    encoder->EncodeVkBool32Value(value.depthClamp);
    encoder->EncodeVkBool32Value(value.depthBiasClamp);
    encoder->EncodeVkBool32Value(value.fillModeNonSolid);
    encoder->EncodeVkBool32Value(value.depthBounds);
    encoder->EncodeVkBool32Value(value.wideLines);
    encoder->EncodeVkBool32Value(value.largePoints);
    encoder->EncodeVkBool32Value(value.alphaToOne);
    encoder->EncodeVkBool32Value(value.multiViewport);
    encoder->EncodeVkBool32Value(value.samplerAnisotropy);
    encoder->EncodeVkBool32Value(value.textureCompressionETC2);
    encoder->EncodeVkBool32Value(value.textureCompressionASTC_LDR);
    encoder->EncodeVkBool32Value(value.textureCompressionBC);
    encoder->EncodeVkBool32Value(value.occlusionQueryPrecise);
    encoder->EncodeVkBool32Value(value.pipelineStatisticsQuery);
    encoder->EncodeVkBool32Value(value.vertexPipelineStoresAndAtomics);
    encoder->EncodeVkBool32Value(value.fragmentStoresAndAtomics);
    encoder->EncodeVkBool32Value(value.shaderTessellationAndGeometryPointSize);
    encoder->EncodeVkBool32Value(value.shaderImageGatherExtended);
    encoder->EncodeVkBool32Value(value.shaderStorageImageExtendedFormats);
    encoder->EncodeVkBool32Value(value.shaderStorageImageMultisample);
    encoder->EncodeVkBool32Value(value.shaderStorageImageReadWithoutFormat);
    encoder->EncodeVkBool32Value(value.shaderStorageImageWriteWithoutFormat);
    encoder->EncodeVkBool32Value(value.shaderUniformBufferArrayDynamicIndexing);
    encoder->EncodeVkBool32Value(value.shaderSampledImageArrayDynamicIndexing);
    encoder->EncodeVkBool32Value(value.shaderStorageBufferArrayDynamicIndexing);
    encoder->EncodeVkBool32Value(value.shaderStorageImageArrayDynamicIndexing);
    encoder->EncodeVkBool32Value(value.shaderClipDistance);
    encoder->EncodeVkBool32Value(value.shaderCullDistance);
    encoder->EncodeVkBool32Value(value.shaderFloat64);
    encoder->EncodeVkBool32Value(value.shaderInt64);
    encoder->EncodeVkBool32Value(value.shaderInt16);
    encoder->EncodeVkBool32Value(value.shaderResourceResidency);
    encoder->EncodeVkBool32Value(value.shaderResourceMinLod);
    encoder->EncodeVkBool32Value(value.sparseBinding);
    encoder->EncodeVkBool32Value(value.sparseResidencyBuffer);
    encoder->EncodeVkBool32Value(value.sparseResidencyImage2D);
    encoder->EncodeVkBool32Value(value.sparseResidencyImage3D);
    encoder->EncodeVkBool32Value(value.sparseResidency2Samples);
    encoder->EncodeVkBool32Value(value.sparseResidency4Samples);
    encoder->EncodeVkBool32Value(value.sparseResidency8Samples);
    encoder->EncodeVkBool32Value(value.sparseResidency16Samples);
    encoder->EncodeVkBool32Value(value.sparseResidencyAliased);
    encoder->EncodeVkBool32Value(value.variableMultisampleRate);
    encoder->EncodeVkBool32Value(value.inheritedQueries);
}

void encode_struct(ParameterEncoder* encoder, const VkFormatProperties& value)
{
    encoder->EncodeFlagsValue(value.linearTilingFeatures);
    encoder->EncodeFlagsValue(value.optimalTilingFeatures);
    encoder->EncodeFlagsValue(value.bufferFeatures);
}

void encode_struct(ParameterEncoder* encoder, const VkExtent3D& value)
{
    encoder->EncodeUInt32Value(value.width);
    encoder->EncodeUInt32Value(value.height);
    encoder->EncodeUInt32Value(value.depth);
}

void encode_struct(ParameterEncoder* encoder, const VkImageFormatProperties& value)
{
    encode_struct(encoder, value.maxExtent);
    encoder->EncodeUInt32Value(value.maxMipLevels);
    encoder->EncodeUInt32Value(value.maxArrayLayers);
    encoder->EncodeFlagsValue(value.sampleCounts);
    encoder->EncodeVkDeviceSizeValue(value.maxResourceSize);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceLimits& value)
{
    encoder->EncodeUInt32Value(value.maxImageDimension1D);
    encoder->EncodeUInt32Value(value.maxImageDimension2D);
    encoder->EncodeUInt32Value(value.maxImageDimension3D);
    encoder->EncodeUInt32Value(value.maxImageDimensionCube);
    encoder->EncodeUInt32Value(value.maxImageArrayLayers);
    encoder->EncodeUInt32Value(value.maxTexelBufferElements);
    encoder->EncodeUInt32Value(value.maxUniformBufferRange);
    encoder->EncodeUInt32Value(value.maxStorageBufferRange);
    encoder->EncodeUInt32Value(value.maxPushConstantsSize);
    encoder->EncodeUInt32Value(value.maxMemoryAllocationCount);
    encoder->EncodeUInt32Value(value.maxSamplerAllocationCount);
    encoder->EncodeVkDeviceSizeValue(value.bufferImageGranularity);
    encoder->EncodeVkDeviceSizeValue(value.sparseAddressSpaceSize);
    encoder->EncodeUInt32Value(value.maxBoundDescriptorSets);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorSamplers);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorUniformBuffers);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorStorageBuffers);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorSampledImages);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorStorageImages);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorInputAttachments);
    encoder->EncodeUInt32Value(value.maxPerStageResources);
    encoder->EncodeUInt32Value(value.maxDescriptorSetSamplers);
    encoder->EncodeUInt32Value(value.maxDescriptorSetUniformBuffers);
    encoder->EncodeUInt32Value(value.maxDescriptorSetUniformBuffersDynamic);
    encoder->EncodeUInt32Value(value.maxDescriptorSetStorageBuffers);
    encoder->EncodeUInt32Value(value.maxDescriptorSetStorageBuffersDynamic);
    encoder->EncodeUInt32Value(value.maxDescriptorSetSampledImages);
    encoder->EncodeUInt32Value(value.maxDescriptorSetStorageImages);
    encoder->EncodeUInt32Value(value.maxDescriptorSetInputAttachments);
    encoder->EncodeUInt32Value(value.maxVertexInputAttributes);
    encoder->EncodeUInt32Value(value.maxVertexInputBindings);
    encoder->EncodeUInt32Value(value.maxVertexInputAttributeOffset);
    encoder->EncodeUInt32Value(value.maxVertexInputBindingStride);
    encoder->EncodeUInt32Value(value.maxVertexOutputComponents);
    encoder->EncodeUInt32Value(value.maxTessellationGenerationLevel);
    encoder->EncodeUInt32Value(value.maxTessellationPatchSize);
    encoder->EncodeUInt32Value(value.maxTessellationControlPerVertexInputComponents);
    encoder->EncodeUInt32Value(value.maxTessellationControlPerVertexOutputComponents);
    encoder->EncodeUInt32Value(value.maxTessellationControlPerPatchOutputComponents);
    encoder->EncodeUInt32Value(value.maxTessellationControlTotalOutputComponents);
    encoder->EncodeUInt32Value(value.maxTessellationEvaluationInputComponents);
    encoder->EncodeUInt32Value(value.maxTessellationEvaluationOutputComponents);
    encoder->EncodeUInt32Value(value.maxGeometryShaderInvocations);
    encoder->EncodeUInt32Value(value.maxGeometryInputComponents);
    encoder->EncodeUInt32Value(value.maxGeometryOutputComponents);
    encoder->EncodeUInt32Value(value.maxGeometryOutputVertices);
    encoder->EncodeUInt32Value(value.maxGeometryTotalOutputComponents);
    encoder->EncodeUInt32Value(value.maxFragmentInputComponents);
    encoder->EncodeUInt32Value(value.maxFragmentOutputAttachments);
    encoder->EncodeUInt32Value(value.maxFragmentDualSrcAttachments);
    encoder->EncodeUInt32Value(value.maxFragmentCombinedOutputResources);
    encoder->EncodeUInt32Value(value.maxComputeSharedMemorySize);
    encoder->EncodeUInt32Array(value.maxComputeWorkGroupCount, 3);
    encoder->EncodeUInt32Value(value.maxComputeWorkGroupInvocations);
    encoder->EncodeUInt32Array(value.maxComputeWorkGroupSize, 3);
    encoder->EncodeUInt32Value(value.subPixelPrecisionBits);
    encoder->EncodeUInt32Value(value.subTexelPrecisionBits);
    encoder->EncodeUInt32Value(value.mipmapPrecisionBits);
    encoder->EncodeUInt32Value(value.maxDrawIndexedIndexValue);
    encoder->EncodeUInt32Value(value.maxDrawIndirectCount);
    encoder->EncodeFloatValue(value.maxSamplerLodBias);
    encoder->EncodeFloatValue(value.maxSamplerAnisotropy);
    encoder->EncodeUInt32Value(value.maxViewports);
    encoder->EncodeUInt32Array(value.maxViewportDimensions, 2);
    encoder->EncodeFloatArray(value.viewportBoundsRange, 2);
    encoder->EncodeUInt32Value(value.viewportSubPixelBits);
    encoder->EncodeSizeTValue(value.minMemoryMapAlignment);
    encoder->EncodeVkDeviceSizeValue(value.minTexelBufferOffsetAlignment);
    encoder->EncodeVkDeviceSizeValue(value.minUniformBufferOffsetAlignment);
    encoder->EncodeVkDeviceSizeValue(value.minStorageBufferOffsetAlignment);
    encoder->EncodeInt32Value(value.minTexelOffset);
    encoder->EncodeUInt32Value(value.maxTexelOffset);
    encoder->EncodeInt32Value(value.minTexelGatherOffset);
    encoder->EncodeUInt32Value(value.maxTexelGatherOffset);
    encoder->EncodeFloatValue(value.minInterpolationOffset);
    encoder->EncodeFloatValue(value.maxInterpolationOffset);
    encoder->EncodeUInt32Value(value.subPixelInterpolationOffsetBits);
    encoder->EncodeUInt32Value(value.maxFramebufferWidth);
    encoder->EncodeUInt32Value(value.maxFramebufferHeight);
    encoder->EncodeUInt32Value(value.maxFramebufferLayers);
    encoder->EncodeFlagsValue(value.framebufferColorSampleCounts);
    encoder->EncodeFlagsValue(value.framebufferDepthSampleCounts);
    encoder->EncodeFlagsValue(value.framebufferStencilSampleCounts);
    encoder->EncodeFlagsValue(value.framebufferNoAttachmentsSampleCounts);
    encoder->EncodeUInt32Value(value.maxColorAttachments);
    encoder->EncodeFlagsValue(value.sampledImageColorSampleCounts);
    encoder->EncodeFlagsValue(value.sampledImageIntegerSampleCounts);
    encoder->EncodeFlagsValue(value.sampledImageDepthSampleCounts);
    encoder->EncodeFlagsValue(value.sampledImageStencilSampleCounts);
    encoder->EncodeFlagsValue(value.storageImageSampleCounts);
    encoder->EncodeUInt32Value(value.maxSampleMaskWords);
    encoder->EncodeVkBool32Value(value.timestampComputeAndGraphics);
    encoder->EncodeFloatValue(value.timestampPeriod);
    encoder->EncodeUInt32Value(value.maxClipDistances);
    encoder->EncodeUInt32Value(value.maxCullDistances);
    encoder->EncodeUInt32Value(value.maxCombinedClipAndCullDistances);
    encoder->EncodeUInt32Value(value.discreteQueuePriorities);
    encoder->EncodeFloatArray(value.pointSizeRange, 2);
    encoder->EncodeFloatArray(value.lineWidthRange, 2);
    encoder->EncodeFloatValue(value.pointSizeGranularity);
    encoder->EncodeFloatValue(value.lineWidthGranularity);
    encoder->EncodeVkBool32Value(value.strictLines);
    encoder->EncodeVkBool32Value(value.standardSampleLocations);
    encoder->EncodeVkDeviceSizeValue(value.optimalBufferCopyOffsetAlignment);
    encoder->EncodeVkDeviceSizeValue(value.optimalBufferCopyRowPitchAlignment);
    encoder->EncodeVkDeviceSizeValue(value.nonCoherentAtomSize);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceSparseProperties& value)
{
    encoder->EncodeVkBool32Value(value.residencyStandard2DBlockShape);
    encoder->EncodeVkBool32Value(value.residencyStandard2DMultisampleBlockShape);
    encoder->EncodeVkBool32Value(value.residencyStandard3DBlockShape);
    encoder->EncodeVkBool32Value(value.residencyAlignedMipSize);
    encoder->EncodeVkBool32Value(value.residencyNonResidentStrict);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceProperties& value)
{
    encoder->EncodeUInt32Value(value.apiVersion);
    encoder->EncodeUInt32Value(value.driverVersion);
    encoder->EncodeUInt32Value(value.vendorID);
    encoder->EncodeUInt32Value(value.deviceID);
    encoder->EncodeEnumValue(value.deviceType);
    encoder->EncodeString(value.deviceName);
    encoder->EncodeUInt8Array(value.pipelineCacheUUID, VK_UUID_SIZE);
    encode_struct(encoder, value.limits);
    encode_struct(encoder, value.sparseProperties);
}

void encode_struct(ParameterEncoder* encoder, const VkQueueFamilyProperties& value)
{
    encoder->EncodeFlagsValue(value.queueFlags);
    encoder->EncodeUInt32Value(value.queueCount);
    encoder->EncodeUInt32Value(value.timestampValidBits);
    encode_struct(encoder, value.minImageTransferGranularity);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryType& value)
{
    encoder->EncodeFlagsValue(value.propertyFlags);
    encoder->EncodeUInt32Value(value.heapIndex);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryHeap& value)
{
    encoder->EncodeVkDeviceSizeValue(value.size);
    encoder->EncodeFlagsValue(value.flags);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceMemoryProperties& value)
{
    encoder->EncodeUInt32Value(value.memoryTypeCount);
    encode_struct_array(encoder, value.memoryTypes, value.memoryTypeCount);
    encoder->EncodeUInt32Value(value.memoryHeapCount);
    encode_struct_array(encoder, value.memoryHeaps, value.memoryHeapCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceQueueCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.queueFamilyIndex);
    encoder->EncodeUInt32Value(value.queueCount);
    encoder->EncodeFloatArray(value.pQueuePriorities, value.queueCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.queueCreateInfoCount);
    encode_struct_array(encoder, value.pQueueCreateInfos, value.queueCreateInfoCount);
    encoder->EncodeUInt32Value(value.enabledLayerCount);
    encoder->EncodeStringArray(value.ppEnabledLayerNames, value.enabledLayerCount);
    encoder->EncodeUInt32Value(value.enabledExtensionCount);
    encoder->EncodeStringArray(value.ppEnabledExtensionNames, value.enabledExtensionCount);
    encode_struct_ptr(encoder, value.pEnabledFeatures);
}

void encode_struct(ParameterEncoder* encoder, const VkExtensionProperties& value)
{
    encoder->EncodeString(value.extensionName);
    encoder->EncodeUInt32Value(value.specVersion);
}

void encode_struct(ParameterEncoder* encoder, const VkLayerProperties& value)
{
    encoder->EncodeString(value.layerName);
    encoder->EncodeUInt32Value(value.specVersion);
    encoder->EncodeUInt32Value(value.implementationVersion);
    encoder->EncodeString(value.description);
}

void encode_struct(ParameterEncoder* encoder, const VkSubmitInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.waitSemaphoreCount);
    encoder->EncodeHandleIdArray(value.pWaitSemaphores, value.waitSemaphoreCount);
    encoder->EncodeFlagsArray(value.pWaitDstStageMask, value.waitSemaphoreCount);
    encoder->EncodeUInt32Value(value.commandBufferCount);
    encoder->EncodeHandleIdArray(value.pCommandBuffers, value.commandBufferCount);
    encoder->EncodeUInt32Value(value.signalSemaphoreCount);
    encoder->EncodeHandleIdArray(value.pSignalSemaphores, value.signalSemaphoreCount);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryAllocateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkDeviceSizeValue(value.allocationSize);
    encoder->EncodeUInt32Value(value.memoryTypeIndex);
}

void encode_struct(ParameterEncoder* encoder, const VkMappedMemoryRange& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.memory);
    encoder->EncodeVkDeviceSizeValue(value.offset);
    encoder->EncodeVkDeviceSizeValue(value.size);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryRequirements& value)
{
    encoder->EncodeVkDeviceSizeValue(value.size);
    encoder->EncodeVkDeviceSizeValue(value.alignment);
    encoder->EncodeUInt32Value(value.memoryTypeBits);
}

void encode_struct(ParameterEncoder* encoder, const VkSparseImageFormatProperties& value)
{
    encoder->EncodeFlagsValue(value.aspectMask);
    encode_struct(encoder, value.imageGranularity);
    encoder->EncodeFlagsValue(value.flags);
}

void encode_struct(ParameterEncoder* encoder, const VkSparseImageMemoryRequirements& value)
{
    encode_struct(encoder, value.formatProperties);
    encoder->EncodeUInt32Value(value.imageMipTailFirstLod);
    encoder->EncodeVkDeviceSizeValue(value.imageMipTailSize);
    encoder->EncodeVkDeviceSizeValue(value.imageMipTailOffset);
    encoder->EncodeVkDeviceSizeValue(value.imageMipTailStride);
}

void encode_struct(ParameterEncoder* encoder, const VkSparseMemoryBind& value)
{
    encoder->EncodeVkDeviceSizeValue(value.resourceOffset);
    encoder->EncodeVkDeviceSizeValue(value.size);
    encoder->EncodeHandleIdValue(value.memory);
    encoder->EncodeVkDeviceSizeValue(value.memoryOffset);
    encoder->EncodeFlagsValue(value.flags);
}

void encode_struct(ParameterEncoder* encoder, const VkSparseBufferMemoryBindInfo& value)
{
    encoder->EncodeHandleIdValue(value.buffer);
    encoder->EncodeUInt32Value(value.bindCount);
    encode_struct_array(encoder, value.pBinds, value.bindCount);
}

void encode_struct(ParameterEncoder* encoder, const VkSparseImageOpaqueMemoryBindInfo& value)
{
    encoder->EncodeHandleIdValue(value.image);
    encoder->EncodeUInt32Value(value.bindCount);
    encode_struct_array(encoder, value.pBinds, value.bindCount);
}

void encode_struct(ParameterEncoder* encoder, const VkImageSubresource& value)
{
    encoder->EncodeFlagsValue(value.aspectMask);
    encoder->EncodeUInt32Value(value.mipLevel);
    encoder->EncodeUInt32Value(value.arrayLayer);
}

void encode_struct(ParameterEncoder* encoder, const VkOffset3D& value)
{
    encoder->EncodeInt32Value(value.x);
    encoder->EncodeInt32Value(value.y);
    encoder->EncodeInt32Value(value.z);
}

void encode_struct(ParameterEncoder* encoder, const VkSparseImageMemoryBind& value)
{
    encode_struct(encoder, value.subresource);
    encode_struct(encoder, value.offset);
    encode_struct(encoder, value.extent);
    encoder->EncodeHandleIdValue(value.memory);
    encoder->EncodeVkDeviceSizeValue(value.memoryOffset);
    encoder->EncodeFlagsValue(value.flags);
}

void encode_struct(ParameterEncoder* encoder, const VkSparseImageMemoryBindInfo& value)
{
    encoder->EncodeHandleIdValue(value.image);
    encoder->EncodeUInt32Value(value.bindCount);
    encode_struct_array(encoder, value.pBinds, value.bindCount);
}

void encode_struct(ParameterEncoder* encoder, const VkBindSparseInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.waitSemaphoreCount);
    encoder->EncodeHandleIdArray(value.pWaitSemaphores, value.waitSemaphoreCount);
    encoder->EncodeUInt32Value(value.bufferBindCount);
    encode_struct_array(encoder, value.pBufferBinds, value.bufferBindCount);
    encoder->EncodeUInt32Value(value.imageOpaqueBindCount);
    encode_struct_array(encoder, value.pImageOpaqueBinds, value.imageOpaqueBindCount);
    encoder->EncodeUInt32Value(value.imageBindCount);
    encode_struct_array(encoder, value.pImageBinds, value.imageBindCount);
    encoder->EncodeUInt32Value(value.signalSemaphoreCount);
    encoder->EncodeHandleIdArray(value.pSignalSemaphores, value.signalSemaphoreCount);
}

void encode_struct(ParameterEncoder* encoder, const VkFenceCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
}

void encode_struct(ParameterEncoder* encoder, const VkSemaphoreCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
}

void encode_struct(ParameterEncoder* encoder, const VkEventCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
}

void encode_struct(ParameterEncoder* encoder, const VkQueryPoolCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.queryType);
    encoder->EncodeUInt32Value(value.queryCount);
    encoder->EncodeFlagsValue(value.pipelineStatistics);
}

void encode_struct(ParameterEncoder* encoder, const VkBufferCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVkDeviceSizeValue(value.size);
    encoder->EncodeFlagsValue(value.usage);
    encoder->EncodeEnumValue(value.sharingMode);
    encoder->EncodeUInt32Value(value.queueFamilyIndexCount);
    encoder->EncodeUInt32Array(value.pQueueFamilyIndices, value.queueFamilyIndexCount);
}

void encode_struct(ParameterEncoder* encoder, const VkBufferViewCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeHandleIdValue(value.buffer);
    encoder->EncodeEnumValue(value.format);
    encoder->EncodeVkDeviceSizeValue(value.offset);
    encoder->EncodeVkDeviceSizeValue(value.range);
}

void encode_struct(ParameterEncoder* encoder, const VkImageCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.imageType);
    encoder->EncodeEnumValue(value.format);
    encode_struct(encoder, value.extent);
    encoder->EncodeUInt32Value(value.mipLevels);
    encoder->EncodeUInt32Value(value.arrayLayers);
    encoder->EncodeEnumValue(value.samples);
    encoder->EncodeEnumValue(value.tiling);
    encoder->EncodeFlagsValue(value.usage);
    encoder->EncodeEnumValue(value.sharingMode);
    encoder->EncodeUInt32Value(value.queueFamilyIndexCount);
    encoder->EncodeUInt32Array(value.pQueueFamilyIndices, value.queueFamilyIndexCount);
    encoder->EncodeEnumValue(value.initialLayout);
}

void encode_struct(ParameterEncoder* encoder, const VkSubresourceLayout& value)
{
    encoder->EncodeVkDeviceSizeValue(value.offset);
    encoder->EncodeVkDeviceSizeValue(value.size);
    encoder->EncodeVkDeviceSizeValue(value.rowPitch);
    encoder->EncodeVkDeviceSizeValue(value.arrayPitch);
    encoder->EncodeVkDeviceSizeValue(value.depthPitch);
}

void encode_struct(ParameterEncoder* encoder, const VkComponentMapping& value)
{
    encoder->EncodeEnumValue(value.r);
    encoder->EncodeEnumValue(value.g);
    encoder->EncodeEnumValue(value.b);
    encoder->EncodeEnumValue(value.a);
}

void encode_struct(ParameterEncoder* encoder, const VkImageSubresourceRange& value)
{
    encoder->EncodeFlagsValue(value.aspectMask);
    encoder->EncodeUInt32Value(value.baseMipLevel);
    encoder->EncodeUInt32Value(value.levelCount);
    encoder->EncodeUInt32Value(value.baseArrayLayer);
    encoder->EncodeUInt32Value(value.layerCount);
}

void encode_struct(ParameterEncoder* encoder, const VkImageViewCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeHandleIdValue(value.image);
    encoder->EncodeEnumValue(value.viewType);
    encoder->EncodeEnumValue(value.format);
    encode_struct(encoder, value.components);
    encode_struct(encoder, value.subresourceRange);
}

void encode_struct(ParameterEncoder* encoder, const VkShaderModuleCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeSizeTValue(value.codeSize);
    encoder->EncodeUInt32Array(value.pCode, value.codeSize/4);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineCacheCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeSizeTValue(value.initialDataSize);
    encoder->EncodeVoidArray(value.pInitialData, value.initialDataSize);
}

void encode_struct(ParameterEncoder* encoder, const VkSpecializationMapEntry& value)
{
    encoder->EncodeUInt32Value(value.constantID);
    encoder->EncodeUInt32Value(value.offset);
    encoder->EncodeSizeTValue(value.size);
}

void encode_struct(ParameterEncoder* encoder, const VkSpecializationInfo& value)
{
    encoder->EncodeUInt32Value(value.mapEntryCount);
    encode_struct_array(encoder, value.pMapEntries, value.mapEntryCount);
    encoder->EncodeSizeTValue(value.dataSize);
    encoder->EncodeVoidArray(value.pData, value.dataSize);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineShaderStageCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.stage);
    encoder->EncodeHandleIdValue(value.module);
    encoder->EncodeString(value.pName);
    encode_struct_ptr(encoder, value.pSpecializationInfo);
}

void encode_struct(ParameterEncoder* encoder, const VkVertexInputBindingDescription& value)
{
    encoder->EncodeUInt32Value(value.binding);
    encoder->EncodeUInt32Value(value.stride);
    encoder->EncodeEnumValue(value.inputRate);
}

void encode_struct(ParameterEncoder* encoder, const VkVertexInputAttributeDescription& value)
{
    encoder->EncodeUInt32Value(value.location);
    encoder->EncodeUInt32Value(value.binding);
    encoder->EncodeEnumValue(value.format);
    encoder->EncodeUInt32Value(value.offset);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineVertexInputStateCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.vertexBindingDescriptionCount);
    encode_struct_array(encoder, value.pVertexBindingDescriptions, value.vertexBindingDescriptionCount);
    encoder->EncodeUInt32Value(value.vertexAttributeDescriptionCount);
    encode_struct_array(encoder, value.pVertexAttributeDescriptions, value.vertexAttributeDescriptionCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineInputAssemblyStateCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.topology);
    encoder->EncodeVkBool32Value(value.primitiveRestartEnable);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineTessellationStateCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.patchControlPoints);
}

void encode_struct(ParameterEncoder* encoder, const VkViewport& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
    encoder->EncodeFloatValue(value.width);
    encoder->EncodeFloatValue(value.height);
    encoder->EncodeFloatValue(value.minDepth);
    encoder->EncodeFloatValue(value.maxDepth);
}

void encode_struct(ParameterEncoder* encoder, const VkOffset2D& value)
{
    encoder->EncodeInt32Value(value.x);
    encoder->EncodeInt32Value(value.y);
}

void encode_struct(ParameterEncoder* encoder, const VkExtent2D& value)
{
    encoder->EncodeUInt32Value(value.width);
    encoder->EncodeUInt32Value(value.height);
}

void encode_struct(ParameterEncoder* encoder, const VkRect2D& value)
{
    encode_struct(encoder, value.offset);
    encode_struct(encoder, value.extent);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineViewportStateCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.viewportCount);
    encode_struct_array(encoder, value.pViewports, value.viewportCount);
    encoder->EncodeUInt32Value(value.scissorCount);
    encode_struct_array(encoder, value.pScissors, value.scissorCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineRasterizationStateCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVkBool32Value(value.depthClampEnable);
    encoder->EncodeVkBool32Value(value.rasterizerDiscardEnable);
    encoder->EncodeEnumValue(value.polygonMode);
    encoder->EncodeFlagsValue(value.cullMode);
    encoder->EncodeEnumValue(value.frontFace);
    encoder->EncodeVkBool32Value(value.depthBiasEnable);
    encoder->EncodeFloatValue(value.depthBiasConstantFactor);
    encoder->EncodeFloatValue(value.depthBiasClamp);
    encoder->EncodeFloatValue(value.depthBiasSlopeFactor);
    encoder->EncodeFloatValue(value.lineWidth);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineMultisampleStateCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.rasterizationSamples);
    encoder->EncodeVkBool32Value(value.sampleShadingEnable);
    encoder->EncodeFloatValue(value.minSampleShading);
    encoder->EncodeVkSampleMaskArray(value.pSampleMask, static_cast<size_t>(ceil(static_cast<double>(value.rasterizationSamples)/static_cast<double>(32))));
    encoder->EncodeVkBool32Value(value.alphaToCoverageEnable);
    encoder->EncodeVkBool32Value(value.alphaToOneEnable);
}

void encode_struct(ParameterEncoder* encoder, const VkStencilOpState& value)
{
    encoder->EncodeEnumValue(value.failOp);
    encoder->EncodeEnumValue(value.passOp);
    encoder->EncodeEnumValue(value.depthFailOp);
    encoder->EncodeEnumValue(value.compareOp);
    encoder->EncodeUInt32Value(value.compareMask);
    encoder->EncodeUInt32Value(value.writeMask);
    encoder->EncodeUInt32Value(value.reference);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineDepthStencilStateCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVkBool32Value(value.depthTestEnable);
    encoder->EncodeVkBool32Value(value.depthWriteEnable);
    encoder->EncodeEnumValue(value.depthCompareOp);
    encoder->EncodeVkBool32Value(value.depthBoundsTestEnable);
    encoder->EncodeVkBool32Value(value.stencilTestEnable);
    encode_struct(encoder, value.front);
    encode_struct(encoder, value.back);
    encoder->EncodeFloatValue(value.minDepthBounds);
    encoder->EncodeFloatValue(value.maxDepthBounds);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineColorBlendAttachmentState& value)
{
    encoder->EncodeVkBool32Value(value.blendEnable);
    encoder->EncodeEnumValue(value.srcColorBlendFactor);
    encoder->EncodeEnumValue(value.dstColorBlendFactor);
    encoder->EncodeEnumValue(value.colorBlendOp);
    encoder->EncodeEnumValue(value.srcAlphaBlendFactor);
    encoder->EncodeEnumValue(value.dstAlphaBlendFactor);
    encoder->EncodeEnumValue(value.alphaBlendOp);
    encoder->EncodeFlagsValue(value.colorWriteMask);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineColorBlendStateCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVkBool32Value(value.logicOpEnable);
    encoder->EncodeEnumValue(value.logicOp);
    encoder->EncodeUInt32Value(value.attachmentCount);
    encode_struct_array(encoder, value.pAttachments, value.attachmentCount);
    encoder->EncodeFloatArray(value.blendConstants, 4);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineDynamicStateCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.dynamicStateCount);
    encoder->EncodeEnumArray(value.pDynamicStates, value.dynamicStateCount);
}

void encode_struct(ParameterEncoder* encoder, const VkGraphicsPipelineCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.stageCount);
    encode_struct_array(encoder, value.pStages, value.stageCount);
    encode_struct_ptr(encoder, value.pVertexInputState);
    encode_struct_ptr(encoder, value.pInputAssemblyState);
    encode_struct_ptr(encoder, value.pTessellationState);
    encode_struct_ptr(encoder, value.pViewportState);
    encode_struct_ptr(encoder, value.pRasterizationState);
    encode_struct_ptr(encoder, value.pMultisampleState);
    encode_struct_ptr(encoder, value.pDepthStencilState);
    encode_struct_ptr(encoder, value.pColorBlendState);
    encode_struct_ptr(encoder, value.pDynamicState);
    encoder->EncodeHandleIdValue(value.layout);
    encoder->EncodeHandleIdValue(value.renderPass);
    encoder->EncodeUInt32Value(value.subpass);
    encoder->EncodeHandleIdValue(value.basePipelineHandle);
    encoder->EncodeInt32Value(value.basePipelineIndex);
}

void encode_struct(ParameterEncoder* encoder, const VkComputePipelineCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encode_struct(encoder, value.stage);
    encoder->EncodeHandleIdValue(value.layout);
    encoder->EncodeHandleIdValue(value.basePipelineHandle);
    encoder->EncodeInt32Value(value.basePipelineIndex);
}

void encode_struct(ParameterEncoder* encoder, const VkPushConstantRange& value)
{
    encoder->EncodeFlagsValue(value.stageFlags);
    encoder->EncodeUInt32Value(value.offset);
    encoder->EncodeUInt32Value(value.size);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineLayoutCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.setLayoutCount);
    encoder->EncodeHandleIdArray(value.pSetLayouts, value.setLayoutCount);
    encoder->EncodeUInt32Value(value.pushConstantRangeCount);
    encode_struct_array(encoder, value.pPushConstantRanges, value.pushConstantRangeCount);
}

void encode_struct(ParameterEncoder* encoder, const VkSamplerCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.magFilter);
    encoder->EncodeEnumValue(value.minFilter);
    encoder->EncodeEnumValue(value.mipmapMode);
    encoder->EncodeEnumValue(value.addressModeU);
    encoder->EncodeEnumValue(value.addressModeV);
    encoder->EncodeEnumValue(value.addressModeW);
    encoder->EncodeFloatValue(value.mipLodBias);
    encoder->EncodeVkBool32Value(value.anisotropyEnable);
    encoder->EncodeFloatValue(value.maxAnisotropy);
    encoder->EncodeVkBool32Value(value.compareEnable);
    encoder->EncodeEnumValue(value.compareOp);
    encoder->EncodeFloatValue(value.minLod);
    encoder->EncodeFloatValue(value.maxLod);
    encoder->EncodeEnumValue(value.borderColor);
    encoder->EncodeVkBool32Value(value.unnormalizedCoordinates);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorSetLayoutBinding& value)
{
    encoder->EncodeUInt32Value(value.binding);
    encoder->EncodeEnumValue(value.descriptorType);
    encoder->EncodeUInt32Value(value.descriptorCount);
    encoder->EncodeFlagsValue(value.stageFlags);
    encoder->EncodeHandleIdArray(value.pImmutableSamplers, value.descriptorCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorSetLayoutCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.bindingCount);
    encode_struct_array(encoder, value.pBindings, value.bindingCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorPoolSize& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeUInt32Value(value.descriptorCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorPoolCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.maxSets);
    encoder->EncodeUInt32Value(value.poolSizeCount);
    encode_struct_array(encoder, value.pPoolSizes, value.poolSizeCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorSetAllocateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.descriptorPool);
    encoder->EncodeUInt32Value(value.descriptorSetCount);
    encoder->EncodeHandleIdArray(value.pSetLayouts, value.descriptorSetCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorImageInfo& value)
{
    encoder->EncodeHandleIdValue(value.sampler);
    encoder->EncodeHandleIdValue(value.imageView);
    encoder->EncodeEnumValue(value.imageLayout);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorBufferInfo& value)
{
    encoder->EncodeHandleIdValue(value.buffer);
    encoder->EncodeVkDeviceSizeValue(value.offset);
    encoder->EncodeVkDeviceSizeValue(value.range);
}

void encode_struct(ParameterEncoder* encoder, const VkWriteDescriptorSet& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.dstSet);
    encoder->EncodeUInt32Value(value.dstBinding);
    encoder->EncodeUInt32Value(value.dstArrayElement);
    encoder->EncodeUInt32Value(value.descriptorCount);
    encoder->EncodeEnumValue(value.descriptorType);
    encode_struct_array(encoder, value.pImageInfo, value.descriptorCount);
    encode_struct_array(encoder, value.pBufferInfo, value.descriptorCount);
    encoder->EncodeHandleIdArray(value.pTexelBufferView, value.descriptorCount);
}

void encode_struct(ParameterEncoder* encoder, const VkCopyDescriptorSet& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.srcSet);
    encoder->EncodeUInt32Value(value.srcBinding);
    encoder->EncodeUInt32Value(value.srcArrayElement);
    encoder->EncodeHandleIdValue(value.dstSet);
    encoder->EncodeUInt32Value(value.dstBinding);
    encoder->EncodeUInt32Value(value.dstArrayElement);
    encoder->EncodeUInt32Value(value.descriptorCount);
}

void encode_struct(ParameterEncoder* encoder, const VkFramebufferCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeHandleIdValue(value.renderPass);
    encoder->EncodeUInt32Value(value.attachmentCount);
    encoder->EncodeHandleIdArray(value.pAttachments, value.attachmentCount);
    encoder->EncodeUInt32Value(value.width);
    encoder->EncodeUInt32Value(value.height);
    encoder->EncodeUInt32Value(value.layers);
}

void encode_struct(ParameterEncoder* encoder, const VkAttachmentDescription& value)
{
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.format);
    encoder->EncodeEnumValue(value.samples);
    encoder->EncodeEnumValue(value.loadOp);
    encoder->EncodeEnumValue(value.storeOp);
    encoder->EncodeEnumValue(value.stencilLoadOp);
    encoder->EncodeEnumValue(value.stencilStoreOp);
    encoder->EncodeEnumValue(value.initialLayout);
    encoder->EncodeEnumValue(value.finalLayout);
}

void encode_struct(ParameterEncoder* encoder, const VkAttachmentReference& value)
{
    encoder->EncodeUInt32Value(value.attachment);
    encoder->EncodeEnumValue(value.layout);
}

void encode_struct(ParameterEncoder* encoder, const VkSubpassDescription& value)
{
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.pipelineBindPoint);
    encoder->EncodeUInt32Value(value.inputAttachmentCount);
    encode_struct_array(encoder, value.pInputAttachments, value.inputAttachmentCount);
    encoder->EncodeUInt32Value(value.colorAttachmentCount);
    encode_struct_array(encoder, value.pColorAttachments, value.colorAttachmentCount);
    encode_struct_array(encoder, value.pResolveAttachments, value.colorAttachmentCount);
    encode_struct_ptr(encoder, value.pDepthStencilAttachment);
    encoder->EncodeUInt32Value(value.preserveAttachmentCount);
    encoder->EncodeUInt32Array(value.pPreserveAttachments, value.preserveAttachmentCount);
}

void encode_struct(ParameterEncoder* encoder, const VkSubpassDependency& value)
{
    encoder->EncodeUInt32Value(value.srcSubpass);
    encoder->EncodeUInt32Value(value.dstSubpass);
    encoder->EncodeFlagsValue(value.srcStageMask);
    encoder->EncodeFlagsValue(value.dstStageMask);
    encoder->EncodeFlagsValue(value.srcAccessMask);
    encoder->EncodeFlagsValue(value.dstAccessMask);
    encoder->EncodeFlagsValue(value.dependencyFlags);
}

void encode_struct(ParameterEncoder* encoder, const VkRenderPassCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.attachmentCount);
    encode_struct_array(encoder, value.pAttachments, value.attachmentCount);
    encoder->EncodeUInt32Value(value.subpassCount);
    encode_struct_array(encoder, value.pSubpasses, value.subpassCount);
    encoder->EncodeUInt32Value(value.dependencyCount);
    encode_struct_array(encoder, value.pDependencies, value.dependencyCount);
}

void encode_struct(ParameterEncoder* encoder, const VkCommandPoolCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.queueFamilyIndex);
}

void encode_struct(ParameterEncoder* encoder, const VkCommandBufferAllocateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.commandPool);
    encoder->EncodeEnumValue(value.level);
    encoder->EncodeUInt32Value(value.commandBufferCount);
}

void encode_struct(ParameterEncoder* encoder, const VkCommandBufferInheritanceInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.renderPass);
    encoder->EncodeUInt32Value(value.subpass);
    encoder->EncodeHandleIdValue(value.framebuffer);
    encoder->EncodeVkBool32Value(value.occlusionQueryEnable);
    encoder->EncodeFlagsValue(value.queryFlags);
    encoder->EncodeFlagsValue(value.pipelineStatistics);
}

void encode_struct(ParameterEncoder* encoder, const VkCommandBufferBeginInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encode_struct_ptr(encoder, value.pInheritanceInfo);
}

void encode_struct(ParameterEncoder* encoder, const VkBufferCopy& value)
{
    encoder->EncodeVkDeviceSizeValue(value.srcOffset);
    encoder->EncodeVkDeviceSizeValue(value.dstOffset);
    encoder->EncodeVkDeviceSizeValue(value.size);
}

void encode_struct(ParameterEncoder* encoder, const VkImageSubresourceLayers& value)
{
    encoder->EncodeFlagsValue(value.aspectMask);
    encoder->EncodeUInt32Value(value.mipLevel);
    encoder->EncodeUInt32Value(value.baseArrayLayer);
    encoder->EncodeUInt32Value(value.layerCount);
}

void encode_struct(ParameterEncoder* encoder, const VkImageCopy& value)
{
    encode_struct(encoder, value.srcSubresource);
    encode_struct(encoder, value.srcOffset);
    encode_struct(encoder, value.dstSubresource);
    encode_struct(encoder, value.dstOffset);
    encode_struct(encoder, value.extent);
}

void encode_struct(ParameterEncoder* encoder, const VkImageBlit& value)
{
    encode_struct(encoder, value.srcSubresource);
    encode_struct_array(encoder, value.srcOffsets, 2);
    encode_struct(encoder, value.dstSubresource);
    encode_struct_array(encoder, value.dstOffsets, 2);
}

void encode_struct(ParameterEncoder* encoder, const VkBufferImageCopy& value)
{
    encoder->EncodeVkDeviceSizeValue(value.bufferOffset);
    encoder->EncodeUInt32Value(value.bufferRowLength);
    encoder->EncodeUInt32Value(value.bufferImageHeight);
    encode_struct(encoder, value.imageSubresource);
    encode_struct(encoder, value.imageOffset);
    encode_struct(encoder, value.imageExtent);
}

void encode_struct(ParameterEncoder* encoder, const VkClearDepthStencilValue& value)
{
    encoder->EncodeFloatValue(value.depth);
    encoder->EncodeUInt32Value(value.stencil);
}

void encode_struct(ParameterEncoder* encoder, const VkClearAttachment& value)
{
    encoder->EncodeFlagsValue(value.aspectMask);
    encoder->EncodeUInt32Value(value.colorAttachment);
    encode_struct(encoder, value.clearValue);
}

void encode_struct(ParameterEncoder* encoder, const VkClearRect& value)
{
    encode_struct(encoder, value.rect);
    encoder->EncodeUInt32Value(value.baseArrayLayer);
    encoder->EncodeUInt32Value(value.layerCount);
}

void encode_struct(ParameterEncoder* encoder, const VkImageResolve& value)
{
    encode_struct(encoder, value.srcSubresource);
    encode_struct(encoder, value.srcOffset);
    encode_struct(encoder, value.dstSubresource);
    encode_struct(encoder, value.dstOffset);
    encode_struct(encoder, value.extent);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryBarrier& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.srcAccessMask);
    encoder->EncodeFlagsValue(value.dstAccessMask);
}

void encode_struct(ParameterEncoder* encoder, const VkBufferMemoryBarrier& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.srcAccessMask);
    encoder->EncodeFlagsValue(value.dstAccessMask);
    encoder->EncodeUInt32Value(value.srcQueueFamilyIndex);
    encoder->EncodeUInt32Value(value.dstQueueFamilyIndex);
    encoder->EncodeHandleIdValue(value.buffer);
    encoder->EncodeVkDeviceSizeValue(value.offset);
    encoder->EncodeVkDeviceSizeValue(value.size);
}

void encode_struct(ParameterEncoder* encoder, const VkImageMemoryBarrier& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.srcAccessMask);
    encoder->EncodeFlagsValue(value.dstAccessMask);
    encoder->EncodeEnumValue(value.oldLayout);
    encoder->EncodeEnumValue(value.newLayout);
    encoder->EncodeUInt32Value(value.srcQueueFamilyIndex);
    encoder->EncodeUInt32Value(value.dstQueueFamilyIndex);
    encoder->EncodeHandleIdValue(value.image);
    encode_struct(encoder, value.subresourceRange);
}

void encode_struct(ParameterEncoder* encoder, const VkRenderPassBeginInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.renderPass);
    encoder->EncodeHandleIdValue(value.framebuffer);
    encode_struct(encoder, value.renderArea);
    encoder->EncodeUInt32Value(value.clearValueCount);
    encode_struct_array(encoder, value.pClearValues, value.clearValueCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDispatchIndirectCommand& value)
{
    encoder->EncodeUInt32Value(value.x);
    encoder->EncodeUInt32Value(value.y);
    encoder->EncodeUInt32Value(value.z);
}

void encode_struct(ParameterEncoder* encoder, const VkDrawIndexedIndirectCommand& value)
{
    encoder->EncodeUInt32Value(value.indexCount);
    encoder->EncodeUInt32Value(value.instanceCount);
    encoder->EncodeUInt32Value(value.firstIndex);
    encoder->EncodeInt32Value(value.vertexOffset);
    encoder->EncodeUInt32Value(value.firstInstance);
}

void encode_struct(ParameterEncoder* encoder, const VkDrawIndirectCommand& value)
{
    encoder->EncodeUInt32Value(value.vertexCount);
    encoder->EncodeUInt32Value(value.instanceCount);
    encoder->EncodeUInt32Value(value.firstVertex);
    encoder->EncodeUInt32Value(value.firstInstance);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceSubgroupProperties& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.subgroupSize);
    encoder->EncodeFlagsValue(value.supportedStages);
    encoder->EncodeFlagsValue(value.supportedOperations);
    encoder->EncodeVkBool32Value(value.quadOperationsInAllStages);
}

void encode_struct(ParameterEncoder* encoder, const VkBindBufferMemoryInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.buffer);
    encoder->EncodeHandleIdValue(value.memory);
    encoder->EncodeVkDeviceSizeValue(value.memoryOffset);
}

void encode_struct(ParameterEncoder* encoder, const VkBindImageMemoryInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.image);
    encoder->EncodeHandleIdValue(value.memory);
    encoder->EncodeVkDeviceSizeValue(value.memoryOffset);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDevice16BitStorageFeatures& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.storageBuffer16BitAccess);
    encoder->EncodeVkBool32Value(value.uniformAndStorageBuffer16BitAccess);
    encoder->EncodeVkBool32Value(value.storagePushConstant16);
    encoder->EncodeVkBool32Value(value.storageInputOutput16);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryDedicatedRequirements& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.prefersDedicatedAllocation);
    encoder->EncodeVkBool32Value(value.requiresDedicatedAllocation);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryDedicatedAllocateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.image);
    encoder->EncodeHandleIdValue(value.buffer);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryAllocateFlagsInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.deviceMask);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceGroupRenderPassBeginInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.deviceMask);
    encoder->EncodeUInt32Value(value.deviceRenderAreaCount);
    encode_struct_array(encoder, value.pDeviceRenderAreas, value.deviceRenderAreaCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceGroupCommandBufferBeginInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.deviceMask);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceGroupSubmitInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.waitSemaphoreCount);
    encoder->EncodeUInt32Array(value.pWaitSemaphoreDeviceIndices, value.waitSemaphoreCount);
    encoder->EncodeUInt32Value(value.commandBufferCount);
    encoder->EncodeUInt32Array(value.pCommandBufferDeviceMasks, value.commandBufferCount);
    encoder->EncodeUInt32Value(value.signalSemaphoreCount);
    encoder->EncodeUInt32Array(value.pSignalSemaphoreDeviceIndices, value.signalSemaphoreCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceGroupBindSparseInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.resourceDeviceIndex);
    encoder->EncodeUInt32Value(value.memoryDeviceIndex);
}

void encode_struct(ParameterEncoder* encoder, const VkBindBufferMemoryDeviceGroupInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.deviceIndexCount);
    encoder->EncodeUInt32Array(value.pDeviceIndices, value.deviceIndexCount);
}

void encode_struct(ParameterEncoder* encoder, const VkBindImageMemoryDeviceGroupInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.deviceIndexCount);
    encoder->EncodeUInt32Array(value.pDeviceIndices, value.deviceIndexCount);
    encoder->EncodeUInt32Value(value.splitInstanceBindRegionCount);
    encode_struct_array(encoder, value.pSplitInstanceBindRegions, value.splitInstanceBindRegionCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceGroupProperties& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.physicalDeviceCount);
    encoder->EncodeHandleIdArray(value.physicalDevices, value.physicalDeviceCount);
    encoder->EncodeVkBool32Value(value.subsetAllocation);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceGroupDeviceCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.physicalDeviceCount);
    encoder->EncodeHandleIdArray(value.pPhysicalDevices, value.physicalDeviceCount);
}

void encode_struct(ParameterEncoder* encoder, const VkBufferMemoryRequirementsInfo2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.buffer);
}

void encode_struct(ParameterEncoder* encoder, const VkImageMemoryRequirementsInfo2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.image);
}

void encode_struct(ParameterEncoder* encoder, const VkImageSparseMemoryRequirementsInfo2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.image);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryRequirements2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.memoryRequirements);
}

void encode_struct(ParameterEncoder* encoder, const VkSparseImageMemoryRequirements2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.memoryRequirements);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceFeatures2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.features);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceProperties2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.properties);
}

void encode_struct(ParameterEncoder* encoder, const VkFormatProperties2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.formatProperties);
}

void encode_struct(ParameterEncoder* encoder, const VkImageFormatProperties2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.imageFormatProperties);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceImageFormatInfo2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.format);
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeEnumValue(value.tiling);
    encoder->EncodeFlagsValue(value.usage);
    encoder->EncodeFlagsValue(value.flags);
}

void encode_struct(ParameterEncoder* encoder, const VkQueueFamilyProperties2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.queueFamilyProperties);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceMemoryProperties2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.memoryProperties);
}

void encode_struct(ParameterEncoder* encoder, const VkSparseImageFormatProperties2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.properties);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceSparseImageFormatInfo2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.format);
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeEnumValue(value.samples);
    encoder->EncodeFlagsValue(value.usage);
    encoder->EncodeEnumValue(value.tiling);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDevicePointClippingProperties& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.pointClippingBehavior);
}

void encode_struct(ParameterEncoder* encoder, const VkInputAttachmentAspectReference& value)
{
    encoder->EncodeUInt32Value(value.subpass);
    encoder->EncodeUInt32Value(value.inputAttachmentIndex);
    encoder->EncodeFlagsValue(value.aspectMask);
}

void encode_struct(ParameterEncoder* encoder, const VkRenderPassInputAttachmentAspectCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.aspectReferenceCount);
    encode_struct_array(encoder, value.pAspectReferences, value.aspectReferenceCount);
}

void encode_struct(ParameterEncoder* encoder, const VkImageViewUsageCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.usage);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineTessellationDomainOriginStateCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.domainOrigin);
}

void encode_struct(ParameterEncoder* encoder, const VkRenderPassMultiviewCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.subpassCount);
    encoder->EncodeUInt32Array(value.pViewMasks, value.subpassCount);
    encoder->EncodeUInt32Value(value.dependencyCount);
    encoder->EncodeInt32Array(value.pViewOffsets, value.dependencyCount);
    encoder->EncodeUInt32Value(value.correlationMaskCount);
    encoder->EncodeUInt32Array(value.pCorrelationMasks, value.correlationMaskCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewFeatures& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.multiview);
    encoder->EncodeVkBool32Value(value.multiviewGeometryShader);
    encoder->EncodeVkBool32Value(value.multiviewTessellationShader);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewProperties& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.maxMultiviewViewCount);
    encoder->EncodeUInt32Value(value.maxMultiviewInstanceIndex);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceVariablePointerFeatures& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.variablePointersStorageBuffer);
    encoder->EncodeVkBool32Value(value.variablePointers);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceProtectedMemoryFeatures& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.protectedMemory);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceProtectedMemoryProperties& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.protectedNoFault);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceQueueInfo2& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.queueFamilyIndex);
    encoder->EncodeUInt32Value(value.queueIndex);
}

void encode_struct(ParameterEncoder* encoder, const VkProtectedSubmitInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.protectedSubmit);
}

void encode_struct(ParameterEncoder* encoder, const VkSamplerYcbcrConversionCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.format);
    encoder->EncodeEnumValue(value.ycbcrModel);
    encoder->EncodeEnumValue(value.ycbcrRange);
    encode_struct(encoder, value.components);
    encoder->EncodeEnumValue(value.xChromaOffset);
    encoder->EncodeEnumValue(value.yChromaOffset);
    encoder->EncodeEnumValue(value.chromaFilter);
    encoder->EncodeVkBool32Value(value.forceExplicitReconstruction);
}

void encode_struct(ParameterEncoder* encoder, const VkSamplerYcbcrConversionInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.conversion);
}

void encode_struct(ParameterEncoder* encoder, const VkBindImagePlaneMemoryInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.planeAspect);
}

void encode_struct(ParameterEncoder* encoder, const VkImagePlaneMemoryRequirementsInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.planeAspect);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceSamplerYcbcrConversionFeatures& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.samplerYcbcrConversion);
}

void encode_struct(ParameterEncoder* encoder, const VkSamplerYcbcrConversionImageFormatProperties& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.combinedImageSamplerDescriptorCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorUpdateTemplateEntry& value)
{
    encoder->EncodeUInt32Value(value.dstBinding);
    encoder->EncodeUInt32Value(value.dstArrayElement);
    encoder->EncodeUInt32Value(value.descriptorCount);
    encoder->EncodeEnumValue(value.descriptorType);
    encoder->EncodeSizeTValue(value.offset);
    encoder->EncodeSizeTValue(value.stride);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorUpdateTemplateCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.descriptorUpdateEntryCount);
    encode_struct_array(encoder, value.pDescriptorUpdateEntries, value.descriptorUpdateEntryCount);
    encoder->EncodeEnumValue(value.templateType);
    encoder->EncodeHandleIdValue(value.descriptorSetLayout);
    encoder->EncodeEnumValue(value.pipelineBindPoint);
    encoder->EncodeHandleIdValue(value.pipelineLayout);
    encoder->EncodeUInt32Value(value.set);
}

void encode_struct(ParameterEncoder* encoder, const VkExternalMemoryProperties& value)
{
    encoder->EncodeFlagsValue(value.externalMemoryFeatures);
    encoder->EncodeFlagsValue(value.exportFromImportedHandleTypes);
    encoder->EncodeFlagsValue(value.compatibleHandleTypes);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalImageFormatInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.handleType);
}

void encode_struct(ParameterEncoder* encoder, const VkExternalImageFormatProperties& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.externalMemoryProperties);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalBufferInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeFlagsValue(value.usage);
    encoder->EncodeEnumValue(value.handleType);
}

void encode_struct(ParameterEncoder* encoder, const VkExternalBufferProperties& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.externalMemoryProperties);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceIDProperties& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt8Array(value.deviceUUID, VK_UUID_SIZE);
    encoder->EncodeUInt8Array(value.driverUUID, VK_UUID_SIZE);
    encoder->EncodeUInt8Array(value.deviceLUID, VK_LUID_SIZE);
    encoder->EncodeUInt32Value(value.deviceNodeMask);
    encoder->EncodeVkBool32Value(value.deviceLUIDValid);
}

void encode_struct(ParameterEncoder* encoder, const VkExternalMemoryImageCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.handleTypes);
}

void encode_struct(ParameterEncoder* encoder, const VkExternalMemoryBufferCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.handleTypes);
}

void encode_struct(ParameterEncoder* encoder, const VkExportMemoryAllocateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.handleTypes);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalFenceInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.handleType);
}

void encode_struct(ParameterEncoder* encoder, const VkExternalFenceProperties& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.exportFromImportedHandleTypes);
    encoder->EncodeFlagsValue(value.compatibleHandleTypes);
    encoder->EncodeFlagsValue(value.externalFenceFeatures);
}

void encode_struct(ParameterEncoder* encoder, const VkExportFenceCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.handleTypes);
}

void encode_struct(ParameterEncoder* encoder, const VkExportSemaphoreCreateInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.handleTypes);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalSemaphoreInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.handleType);
}

void encode_struct(ParameterEncoder* encoder, const VkExternalSemaphoreProperties& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.exportFromImportedHandleTypes);
    encoder->EncodeFlagsValue(value.compatibleHandleTypes);
    encoder->EncodeFlagsValue(value.externalSemaphoreFeatures);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceMaintenance3Properties& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.maxPerSetDescriptors);
    encoder->EncodeVkDeviceSizeValue(value.maxMemoryAllocationSize);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorSetLayoutSupport& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.supported);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderDrawParameterFeatures& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.shaderDrawParameters);
}

void encode_struct(ParameterEncoder* encoder, const VkSurfaceCapabilitiesKHR& value)
{
    encoder->EncodeUInt32Value(value.minImageCount);
    encoder->EncodeUInt32Value(value.maxImageCount);
    encode_struct(encoder, value.currentExtent);
    encode_struct(encoder, value.minImageExtent);
    encode_struct(encoder, value.maxImageExtent);
    encoder->EncodeUInt32Value(value.maxImageArrayLayers);
    encoder->EncodeFlagsValue(value.supportedTransforms);
    encoder->EncodeEnumValue(value.currentTransform);
    encoder->EncodeFlagsValue(value.supportedCompositeAlpha);
    encoder->EncodeFlagsValue(value.supportedUsageFlags);
}

void encode_struct(ParameterEncoder* encoder, const VkSurfaceFormatKHR& value)
{
    encoder->EncodeEnumValue(value.format);
    encoder->EncodeEnumValue(value.colorSpace);
}

void encode_struct(ParameterEncoder* encoder, const VkSwapchainCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeHandleIdValue(value.surface);
    encoder->EncodeUInt32Value(value.minImageCount);
    encoder->EncodeEnumValue(value.imageFormat);
    encoder->EncodeEnumValue(value.imageColorSpace);
    encode_struct(encoder, value.imageExtent);
    encoder->EncodeUInt32Value(value.imageArrayLayers);
    encoder->EncodeFlagsValue(value.imageUsage);
    encoder->EncodeEnumValue(value.imageSharingMode);
    encoder->EncodeUInt32Value(value.queueFamilyIndexCount);
    encoder->EncodeUInt32Array(value.pQueueFamilyIndices, value.queueFamilyIndexCount);
    encoder->EncodeEnumValue(value.preTransform);
    encoder->EncodeEnumValue(value.compositeAlpha);
    encoder->EncodeEnumValue(value.presentMode);
    encoder->EncodeVkBool32Value(value.clipped);
    encoder->EncodeHandleIdValue(value.oldSwapchain);
}

void encode_struct(ParameterEncoder* encoder, const VkPresentInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.waitSemaphoreCount);
    encoder->EncodeHandleIdArray(value.pWaitSemaphores, value.waitSemaphoreCount);
    encoder->EncodeUInt32Value(value.swapchainCount);
    encoder->EncodeHandleIdArray(value.pSwapchains, value.swapchainCount);
    encoder->EncodeUInt32Array(value.pImageIndices, value.swapchainCount);
    encoder->EncodeEnumArray(value.pResults, value.swapchainCount);
}

void encode_struct(ParameterEncoder* encoder, const VkImageSwapchainCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.swapchain);
}

void encode_struct(ParameterEncoder* encoder, const VkBindImageMemorySwapchainInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.swapchain);
    encoder->EncodeUInt32Value(value.imageIndex);
}

void encode_struct(ParameterEncoder* encoder, const VkAcquireNextImageInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.swapchain);
    encoder->EncodeUInt64Value(value.timeout);
    encoder->EncodeHandleIdValue(value.semaphore);
    encoder->EncodeHandleIdValue(value.fence);
    encoder->EncodeUInt32Value(value.deviceMask);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceGroupPresentCapabilitiesKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Array(value.presentMask, VK_MAX_DEVICE_GROUP_SIZE);
    encoder->EncodeFlagsValue(value.modes);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceGroupPresentInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.swapchainCount);
    encoder->EncodeUInt32Array(value.pDeviceMasks, value.swapchainCount);
    encoder->EncodeEnumValue(value.mode);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceGroupSwapchainCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.modes);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayPropertiesKHR& value)
{
    encoder->EncodeHandleIdValue(value.display);
    encoder->EncodeString(value.displayName);
    encode_struct(encoder, value.physicalDimensions);
    encode_struct(encoder, value.physicalResolution);
    encoder->EncodeFlagsValue(value.supportedTransforms);
    encoder->EncodeVkBool32Value(value.planeReorderPossible);
    encoder->EncodeVkBool32Value(value.persistentContent);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayModeParametersKHR& value)
{
    encode_struct(encoder, value.visibleRegion);
    encoder->EncodeUInt32Value(value.refreshRate);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayModePropertiesKHR& value)
{
    encoder->EncodeHandleIdValue(value.displayMode);
    encode_struct(encoder, value.parameters);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayModeCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encode_struct(encoder, value.parameters);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayPlaneCapabilitiesKHR& value)
{
    encoder->EncodeFlagsValue(value.supportedAlpha);
    encode_struct(encoder, value.minSrcPosition);
    encode_struct(encoder, value.maxSrcPosition);
    encode_struct(encoder, value.minSrcExtent);
    encode_struct(encoder, value.maxSrcExtent);
    encode_struct(encoder, value.minDstPosition);
    encode_struct(encoder, value.maxDstPosition);
    encode_struct(encoder, value.minDstExtent);
    encode_struct(encoder, value.maxDstExtent);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayPlanePropertiesKHR& value)
{
    encoder->EncodeHandleIdValue(value.currentDisplay);
    encoder->EncodeUInt32Value(value.currentStackIndex);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplaySurfaceCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeHandleIdValue(value.displayMode);
    encoder->EncodeUInt32Value(value.planeIndex);
    encoder->EncodeUInt32Value(value.planeStackIndex);
    encoder->EncodeEnumValue(value.transform);
    encoder->EncodeFloatValue(value.globalAlpha);
    encoder->EncodeEnumValue(value.alphaMode);
    encode_struct(encoder, value.imageExtent);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayPresentInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.srcRect);
    encode_struct(encoder, value.dstRect);
    encoder->EncodeVkBool32Value(value.persistent);
}

#ifdef VK_USE_PLATFORM_XLIB_KHR
void encode_struct(ParameterEncoder* encoder, const VkXlibSurfaceCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVoidPtr(value.dpy);
    encoder->EncodeSizeTValue(value.window);
}
#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
void encode_struct(ParameterEncoder* encoder, const VkXcbSurfaceCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVoidPtr(value.connection);
    encoder->EncodeUInt32Value(value.window);
}
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
void encode_struct(ParameterEncoder* encoder, const VkWaylandSurfaceCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVoidPtr(value.display);
    encoder->EncodeVoidPtr(value.surface);
}
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
void encode_struct(ParameterEncoder* encoder, const VkMirSurfaceCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVoidPtr(value.connection);
    encoder->EncodeVoidPtr(value.mirSurface);
}
#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
void encode_struct(ParameterEncoder* encoder, const VkAndroidSurfaceCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVoidPtr(value.window);
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(ParameterEncoder* encoder, const VkWin32SurfaceCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVoidPtr(value.hinstance);
    encoder->EncodeVoidPtr(value.hwnd);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(ParameterEncoder* encoder, const VkImportMemoryWin32HandleInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.handleType);
    encoder->EncodeVoidPtr(value.handle);
    encoder->EncodeWString(value.name);
}

void encode_struct(ParameterEncoder* encoder, const VkExportMemoryWin32HandleInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct_ptr(encoder, value.pAttributes);
    encoder->EncodeUInt32Value(value.dwAccess);
    encoder->EncodeWString(value.name);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryWin32HandlePropertiesKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.memoryTypeBits);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryGetWin32HandleInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.memory);
    encoder->EncodeEnumValue(value.handleType);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void encode_struct(ParameterEncoder* encoder, const VkImportMemoryFdInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.handleType);
    encoder->EncodeInt32Value(value.fd);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryFdPropertiesKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.memoryTypeBits);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryGetFdInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.memory);
    encoder->EncodeEnumValue(value.handleType);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(ParameterEncoder* encoder, const VkWin32KeyedMutexAcquireReleaseInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.acquireCount);
    encoder->EncodeHandleIdArray(value.pAcquireSyncs, value.acquireCount);
    encoder->EncodeUInt64Array(value.pAcquireKeys, value.acquireCount);
    encoder->EncodeUInt32Array(value.pAcquireTimeouts, value.acquireCount);
    encoder->EncodeUInt32Value(value.releaseCount);
    encoder->EncodeHandleIdArray(value.pReleaseSyncs, value.releaseCount);
    encoder->EncodeUInt64Array(value.pReleaseKeys, value.releaseCount);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(ParameterEncoder* encoder, const VkImportSemaphoreWin32HandleInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.semaphore);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.handleType);
    encoder->EncodeVoidPtr(value.handle);
    encoder->EncodeWString(value.name);
}

void encode_struct(ParameterEncoder* encoder, const VkExportSemaphoreWin32HandleInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct_ptr(encoder, value.pAttributes);
    encoder->EncodeUInt32Value(value.dwAccess);
    encoder->EncodeWString(value.name);
}

void encode_struct(ParameterEncoder* encoder, const VkD3D12FenceSubmitInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.waitSemaphoreValuesCount);
    encoder->EncodeUInt64Array(value.pWaitSemaphoreValues, value.waitSemaphoreValuesCount);
    encoder->EncodeUInt32Value(value.signalSemaphoreValuesCount);
    encoder->EncodeUInt64Array(value.pSignalSemaphoreValues, value.signalSemaphoreValuesCount);
}

void encode_struct(ParameterEncoder* encoder, const VkSemaphoreGetWin32HandleInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.semaphore);
    encoder->EncodeEnumValue(value.handleType);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void encode_struct(ParameterEncoder* encoder, const VkImportSemaphoreFdInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.semaphore);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.handleType);
    encoder->EncodeInt32Value(value.fd);
}

void encode_struct(ParameterEncoder* encoder, const VkSemaphoreGetFdInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.semaphore);
    encoder->EncodeEnumValue(value.handleType);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDevicePushDescriptorPropertiesKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.maxPushDescriptors);
}

void encode_struct(ParameterEncoder* encoder, const VkRectLayerKHR& value)
{
    encode_struct(encoder, value.offset);
    encode_struct(encoder, value.extent);
    encoder->EncodeUInt32Value(value.layer);
}

void encode_struct(ParameterEncoder* encoder, const VkPresentRegionKHR& value)
{
    encoder->EncodeUInt32Value(value.rectangleCount);
    encode_struct_array(encoder, value.pRectangles, value.rectangleCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPresentRegionsKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.swapchainCount);
    encode_struct_array(encoder, value.pRegions, value.swapchainCount);
}

void encode_struct(ParameterEncoder* encoder, const VkAttachmentDescription2KHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.format);
    encoder->EncodeEnumValue(value.samples);
    encoder->EncodeEnumValue(value.loadOp);
    encoder->EncodeEnumValue(value.storeOp);
    encoder->EncodeEnumValue(value.stencilLoadOp);
    encoder->EncodeEnumValue(value.stencilStoreOp);
    encoder->EncodeEnumValue(value.initialLayout);
    encoder->EncodeEnumValue(value.finalLayout);
}

void encode_struct(ParameterEncoder* encoder, const VkAttachmentReference2KHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.attachment);
    encoder->EncodeEnumValue(value.layout);
    encoder->EncodeFlagsValue(value.aspectMask);
}

void encode_struct(ParameterEncoder* encoder, const VkSubpassDescription2KHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.pipelineBindPoint);
    encoder->EncodeUInt32Value(value.viewMask);
    encoder->EncodeUInt32Value(value.inputAttachmentCount);
    encode_struct_array(encoder, value.pInputAttachments, value.inputAttachmentCount);
    encoder->EncodeUInt32Value(value.colorAttachmentCount);
    encode_struct_array(encoder, value.pColorAttachments, value.colorAttachmentCount);
    encode_struct_array(encoder, value.pResolveAttachments, value.colorAttachmentCount);
    encode_struct_ptr(encoder, value.pDepthStencilAttachment);
    encoder->EncodeUInt32Value(value.preserveAttachmentCount);
    encoder->EncodeUInt32Array(value.pPreserveAttachments, value.preserveAttachmentCount);
}

void encode_struct(ParameterEncoder* encoder, const VkSubpassDependency2KHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.srcSubpass);
    encoder->EncodeUInt32Value(value.dstSubpass);
    encoder->EncodeFlagsValue(value.srcStageMask);
    encoder->EncodeFlagsValue(value.dstStageMask);
    encoder->EncodeFlagsValue(value.srcAccessMask);
    encoder->EncodeFlagsValue(value.dstAccessMask);
    encoder->EncodeFlagsValue(value.dependencyFlags);
    encoder->EncodeInt32Value(value.viewOffset);
}

void encode_struct(ParameterEncoder* encoder, const VkRenderPassCreateInfo2KHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.attachmentCount);
    encode_struct_array(encoder, value.pAttachments, value.attachmentCount);
    encoder->EncodeUInt32Value(value.subpassCount);
    encode_struct_array(encoder, value.pSubpasses, value.subpassCount);
    encoder->EncodeUInt32Value(value.dependencyCount);
    encode_struct_array(encoder, value.pDependencies, value.dependencyCount);
    encoder->EncodeUInt32Value(value.correlatedViewMaskCount);
    encoder->EncodeUInt32Array(value.pCorrelatedViewMasks, value.correlatedViewMaskCount);
}

void encode_struct(ParameterEncoder* encoder, const VkSubpassBeginInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.contents);
}

void encode_struct(ParameterEncoder* encoder, const VkSubpassEndInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
}

void encode_struct(ParameterEncoder* encoder, const VkSharedPresentSurfaceCapabilitiesKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.sharedPresentSupportedUsageFlags);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(ParameterEncoder* encoder, const VkImportFenceWin32HandleInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.fence);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.handleType);
    encoder->EncodeVoidPtr(value.handle);
    encoder->EncodeWString(value.name);
}

void encode_struct(ParameterEncoder* encoder, const VkExportFenceWin32HandleInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct_ptr(encoder, value.pAttributes);
    encoder->EncodeUInt32Value(value.dwAccess);
    encoder->EncodeWString(value.name);
}

void encode_struct(ParameterEncoder* encoder, const VkFenceGetWin32HandleInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.fence);
    encoder->EncodeEnumValue(value.handleType);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void encode_struct(ParameterEncoder* encoder, const VkImportFenceFdInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.fence);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.handleType);
    encoder->EncodeInt32Value(value.fd);
}

void encode_struct(ParameterEncoder* encoder, const VkFenceGetFdInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.fence);
    encoder->EncodeEnumValue(value.handleType);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceSurfaceInfo2KHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.surface);
}

void encode_struct(ParameterEncoder* encoder, const VkSurfaceCapabilities2KHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.surfaceCapabilities);
}

void encode_struct(ParameterEncoder* encoder, const VkSurfaceFormat2KHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.surfaceFormat);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayProperties2KHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.displayProperties);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayPlaneProperties2KHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.displayPlaneProperties);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayModeProperties2KHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.displayModeProperties);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayPlaneInfo2KHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.mode);
    encoder->EncodeUInt32Value(value.planeIndex);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayPlaneCapabilities2KHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.capabilities);
}

void encode_struct(ParameterEncoder* encoder, const VkImageFormatListCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.viewFormatCount);
    encoder->EncodeEnumArray(value.pViewFormats, value.viewFormatCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDevice8BitStorageFeaturesKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.storageBuffer8BitAccess);
    encoder->EncodeVkBool32Value(value.uniformAndStorageBuffer8BitAccess);
    encoder->EncodeVkBool32Value(value.storagePushConstant8);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderAtomicInt64FeaturesKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.shaderBufferInt64Atomics);
    encoder->EncodeVkBool32Value(value.shaderSharedInt64Atomics);
}

void encode_struct(ParameterEncoder* encoder, const VkConformanceVersionKHR& value)
{
    encoder->EncodeUInt8Value(value.major);
    encoder->EncodeUInt8Value(value.minor);
    encoder->EncodeUInt8Value(value.subminor);
    encoder->EncodeUInt8Value(value.patch);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceDriverPropertiesKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.driverID);
    encoder->EncodeString(value.driverName);
    encoder->EncodeString(value.driverInfo);
    encode_struct(encoder, value.conformanceVersion);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceVulkanMemoryModelFeaturesKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.vulkanMemoryModel);
    encoder->EncodeVkBool32Value(value.vulkanMemoryModelDeviceScope);
}

void encode_struct(ParameterEncoder* encoder, const VkDebugReportCallbackCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeFunctionPtr(value.pfnCallback);
    encoder->EncodeVoidPtr(value.pUserData);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineRasterizationStateRasterizationOrderAMD& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.rasterizationOrder);
}

void encode_struct(ParameterEncoder* encoder, const VkDebugMarkerObjectNameInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.objectType);
    encoder->EncodeUInt64Value(value.object);
    encoder->EncodeString(value.pObjectName);
}

void encode_struct(ParameterEncoder* encoder, const VkDebugMarkerObjectTagInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.objectType);
    encoder->EncodeUInt64Value(value.object);
    encoder->EncodeUInt64Value(value.tagName);
    encoder->EncodeSizeTValue(value.tagSize);
    encoder->EncodeVoidArray(value.pTag, value.tagSize);
}

void encode_struct(ParameterEncoder* encoder, const VkDebugMarkerMarkerInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeString(value.pMarkerName);
    encoder->EncodeFloatArray(value.color, 4);
}

void encode_struct(ParameterEncoder* encoder, const VkDedicatedAllocationImageCreateInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.dedicatedAllocation);
}

void encode_struct(ParameterEncoder* encoder, const VkDedicatedAllocationBufferCreateInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.dedicatedAllocation);
}

void encode_struct(ParameterEncoder* encoder, const VkDedicatedAllocationMemoryAllocateInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.image);
    encoder->EncodeHandleIdValue(value.buffer);
}

void encode_struct(ParameterEncoder* encoder, const VkTextureLODGatherFormatPropertiesAMD& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.supportsTextureGatherLODBiasAMD);
}

void encode_struct(ParameterEncoder* encoder, const VkShaderResourceUsageAMD& value)
{
    encoder->EncodeUInt32Value(value.numUsedVgprs);
    encoder->EncodeUInt32Value(value.numUsedSgprs);
    encoder->EncodeUInt32Value(value.ldsSizePerLocalWorkGroup);
    encoder->EncodeSizeTValue(value.ldsUsageSizeInBytes);
    encoder->EncodeSizeTValue(value.scratchMemUsageInBytes);
}

void encode_struct(ParameterEncoder* encoder, const VkShaderStatisticsInfoAMD& value)
{
    encoder->EncodeFlagsValue(value.shaderStageMask);
    encode_struct(encoder, value.resourceUsage);
    encoder->EncodeUInt32Value(value.numPhysicalVgprs);
    encoder->EncodeUInt32Value(value.numPhysicalSgprs);
    encoder->EncodeUInt32Value(value.numAvailableVgprs);
    encoder->EncodeUInt32Value(value.numAvailableSgprs);
    encoder->EncodeUInt32Array(value.computeWorkGroupSize, 3);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceCornerSampledImageFeaturesNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.cornerSampledImage);
}

void encode_struct(ParameterEncoder* encoder, const VkExternalImageFormatPropertiesNV& value)
{
    encode_struct(encoder, value.imageFormatProperties);
    encoder->EncodeFlagsValue(value.externalMemoryFeatures);
    encoder->EncodeFlagsValue(value.exportFromImportedHandleTypes);
    encoder->EncodeFlagsValue(value.compatibleHandleTypes);
}

void encode_struct(ParameterEncoder* encoder, const VkExternalMemoryImageCreateInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.handleTypes);
}

void encode_struct(ParameterEncoder* encoder, const VkExportMemoryAllocateInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.handleTypes);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(ParameterEncoder* encoder, const VkImportMemoryWin32HandleInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.handleType);
    encoder->EncodeVoidPtr(value.handle);
}

void encode_struct(ParameterEncoder* encoder, const VkExportMemoryWin32HandleInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct_ptr(encoder, value.pAttributes);
    encoder->EncodeUInt32Value(value.dwAccess);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
void encode_struct(ParameterEncoder* encoder, const VkWin32KeyedMutexAcquireReleaseInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.acquireCount);
    encoder->EncodeHandleIdArray(value.pAcquireSyncs, value.acquireCount);
    encoder->EncodeUInt64Array(value.pAcquireKeys, value.acquireCount);
    encoder->EncodeUInt32Array(value.pAcquireTimeoutMilliseconds, value.acquireCount);
    encoder->EncodeUInt32Value(value.releaseCount);
    encoder->EncodeHandleIdArray(value.pReleaseSyncs, value.releaseCount);
    encoder->EncodeUInt64Array(value.pReleaseKeys, value.releaseCount);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void encode_struct(ParameterEncoder* encoder, const VkValidationFlagsEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.disabledValidationCheckCount);
    encoder->EncodeEnumArray(value.pDisabledValidationChecks, value.disabledValidationCheckCount);
}

#ifdef VK_USE_PLATFORM_VI_NN
void encode_struct(ParameterEncoder* encoder, const VkViSurfaceCreateInfoNN& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVoidPtr(value.window);
}
#endif /* VK_USE_PLATFORM_VI_NN */

void encode_struct(ParameterEncoder* encoder, const VkImageViewASTCDecodeModeEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.decodeMode);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceASTCDecodeFeaturesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.decodeModeSharedExponent);
}

void encode_struct(ParameterEncoder* encoder, const VkConditionalRenderingBeginInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.buffer);
    encoder->EncodeVkDeviceSizeValue(value.offset);
    encoder->EncodeFlagsValue(value.flags);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceConditionalRenderingFeaturesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.conditionalRendering);
    encoder->EncodeVkBool32Value(value.inheritedConditionalRendering);
}

void encode_struct(ParameterEncoder* encoder, const VkCommandBufferInheritanceConditionalRenderingInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.conditionalRenderingEnable);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceGeneratedCommandsFeaturesNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.computeBindingPointSupport);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceGeneratedCommandsLimitsNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.maxIndirectCommandsLayoutTokenCount);
    encoder->EncodeUInt32Value(value.maxObjectEntryCounts);
    encoder->EncodeUInt32Value(value.minSequenceCountBufferOffsetAlignment);
    encoder->EncodeUInt32Value(value.minSequenceIndexBufferOffsetAlignment);
    encoder->EncodeUInt32Value(value.minCommandsTokenBufferOffsetAlignment);
}

void encode_struct(ParameterEncoder* encoder, const VkIndirectCommandsTokenNVX& value)
{
    encoder->EncodeEnumValue(value.tokenType);
    encoder->EncodeHandleIdValue(value.buffer);
    encoder->EncodeVkDeviceSizeValue(value.offset);
}

void encode_struct(ParameterEncoder* encoder, const VkIndirectCommandsLayoutTokenNVX& value)
{
    encoder->EncodeEnumValue(value.tokenType);
    encoder->EncodeUInt32Value(value.bindingUnit);
    encoder->EncodeUInt32Value(value.dynamicCount);
    encoder->EncodeUInt32Value(value.divisor);
}

void encode_struct(ParameterEncoder* encoder, const VkIndirectCommandsLayoutCreateInfoNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.pipelineBindPoint);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.tokenCount);
    encode_struct_array(encoder, value.pTokens, value.tokenCount);
}

void encode_struct(ParameterEncoder* encoder, const VkCmdProcessCommandsInfoNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.objectTable);
    encoder->EncodeHandleIdValue(value.indirectCommandsLayout);
    encoder->EncodeUInt32Value(value.indirectCommandsTokenCount);
    encode_struct_array(encoder, value.pIndirectCommandsTokens, value.indirectCommandsTokenCount);
    encoder->EncodeUInt32Value(value.maxSequencesCount);
    encoder->EncodeHandleIdValue(value.targetCommandBuffer);
    encoder->EncodeHandleIdValue(value.sequencesCountBuffer);
    encoder->EncodeVkDeviceSizeValue(value.sequencesCountOffset);
    encoder->EncodeHandleIdValue(value.sequencesIndexBuffer);
    encoder->EncodeVkDeviceSizeValue(value.sequencesIndexOffset);
}

void encode_struct(ParameterEncoder* encoder, const VkCmdReserveSpaceForCommandsInfoNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.objectTable);
    encoder->EncodeHandleIdValue(value.indirectCommandsLayout);
    encoder->EncodeUInt32Value(value.maxSequencesCount);
}

void encode_struct(ParameterEncoder* encoder, const VkObjectTableCreateInfoNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.objectCount);
    encoder->EncodeEnumArray(value.pObjectEntryTypes, value.objectCount);
    encoder->EncodeUInt32Array(value.pObjectEntryCounts, value.objectCount);
    encoder->EncodeFlagsArray(value.pObjectEntryUsageFlags, value.objectCount);
    encoder->EncodeUInt32Value(value.maxUniformBuffersPerDescriptor);
    encoder->EncodeUInt32Value(value.maxStorageBuffersPerDescriptor);
    encoder->EncodeUInt32Value(value.maxStorageImagesPerDescriptor);
    encoder->EncodeUInt32Value(value.maxSampledImagesPerDescriptor);
    encoder->EncodeUInt32Value(value.maxPipelineLayouts);
}

void encode_struct(ParameterEncoder* encoder, const VkObjectTablePipelineEntryNVX& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeHandleIdValue(value.pipeline);
}

void encode_struct(ParameterEncoder* encoder, const VkObjectTableDescriptorSetEntryNVX& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeHandleIdValue(value.pipelineLayout);
    encoder->EncodeHandleIdValue(value.descriptorSet);
}

void encode_struct(ParameterEncoder* encoder, const VkObjectTableVertexBufferEntryNVX& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeHandleIdValue(value.buffer);
}

void encode_struct(ParameterEncoder* encoder, const VkObjectTableIndexBufferEntryNVX& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeHandleIdValue(value.buffer);
    encoder->EncodeEnumValue(value.indexType);
}

void encode_struct(ParameterEncoder* encoder, const VkObjectTablePushConstantEntryNVX& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeHandleIdValue(value.pipelineLayout);
    encoder->EncodeFlagsValue(value.stageFlags);
}

void encode_struct(ParameterEncoder* encoder, const VkViewportWScalingNV& value)
{
    encoder->EncodeFloatValue(value.xcoeff);
    encoder->EncodeFloatValue(value.ycoeff);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineViewportWScalingStateCreateInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.viewportWScalingEnable);
    encoder->EncodeUInt32Value(value.viewportCount);
    encode_struct_array(encoder, value.pViewportWScalings, value.viewportCount);
}

void encode_struct(ParameterEncoder* encoder, const VkSurfaceCapabilities2EXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.minImageCount);
    encoder->EncodeUInt32Value(value.maxImageCount);
    encode_struct(encoder, value.currentExtent);
    encode_struct(encoder, value.minImageExtent);
    encode_struct(encoder, value.maxImageExtent);
    encoder->EncodeUInt32Value(value.maxImageArrayLayers);
    encoder->EncodeFlagsValue(value.supportedTransforms);
    encoder->EncodeEnumValue(value.currentTransform);
    encoder->EncodeFlagsValue(value.supportedCompositeAlpha);
    encoder->EncodeFlagsValue(value.supportedUsageFlags);
    encoder->EncodeFlagsValue(value.supportedSurfaceCounters);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayPowerInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.powerState);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceEventInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.deviceEvent);
}

void encode_struct(ParameterEncoder* encoder, const VkDisplayEventInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.displayEvent);
}

void encode_struct(ParameterEncoder* encoder, const VkSwapchainCounterCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.surfaceCounters);
}

void encode_struct(ParameterEncoder* encoder, const VkRefreshCycleDurationGOOGLE& value)
{
    encoder->EncodeUInt64Value(value.refreshDuration);
}

void encode_struct(ParameterEncoder* encoder, const VkPastPresentationTimingGOOGLE& value)
{
    encoder->EncodeUInt32Value(value.presentID);
    encoder->EncodeUInt64Value(value.desiredPresentTime);
    encoder->EncodeUInt64Value(value.actualPresentTime);
    encoder->EncodeUInt64Value(value.earliestPresentTime);
    encoder->EncodeUInt64Value(value.presentMargin);
}

void encode_struct(ParameterEncoder* encoder, const VkPresentTimeGOOGLE& value)
{
    encoder->EncodeUInt32Value(value.presentID);
    encoder->EncodeUInt64Value(value.desiredPresentTime);
}

void encode_struct(ParameterEncoder* encoder, const VkPresentTimesInfoGOOGLE& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.swapchainCount);
    encode_struct_array(encoder, value.pTimes, value.swapchainCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.perViewPositionAllComponents);
}

void encode_struct(ParameterEncoder* encoder, const VkViewportSwizzleNV& value)
{
    encoder->EncodeEnumValue(value.x);
    encoder->EncodeEnumValue(value.y);
    encoder->EncodeEnumValue(value.z);
    encoder->EncodeEnumValue(value.w);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineViewportSwizzleStateCreateInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.viewportCount);
    encode_struct_array(encoder, value.pViewportSwizzles, value.viewportCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceDiscardRectanglePropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.maxDiscardRectangles);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineDiscardRectangleStateCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.discardRectangleMode);
    encoder->EncodeUInt32Value(value.discardRectangleCount);
    encode_struct_array(encoder, value.pDiscardRectangles, value.discardRectangleCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceConservativeRasterizationPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFloatValue(value.primitiveOverestimationSize);
    encoder->EncodeFloatValue(value.maxExtraPrimitiveOverestimationSize);
    encoder->EncodeFloatValue(value.extraPrimitiveOverestimationSizeGranularity);
    encoder->EncodeVkBool32Value(value.primitiveUnderestimation);
    encoder->EncodeVkBool32Value(value.conservativePointAndLineRasterization);
    encoder->EncodeVkBool32Value(value.degenerateTrianglesRasterized);
    encoder->EncodeVkBool32Value(value.degenerateLinesRasterized);
    encoder->EncodeVkBool32Value(value.fullyCoveredFragmentShaderInputVariable);
    encoder->EncodeVkBool32Value(value.conservativeRasterizationPostDepthCoverage);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineRasterizationConservativeStateCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.conservativeRasterizationMode);
    encoder->EncodeFloatValue(value.extraPrimitiveOverestimationSize);
}

void encode_struct(ParameterEncoder* encoder, const VkXYColorEXT& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
}

void encode_struct(ParameterEncoder* encoder, const VkHdrMetadataEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.displayPrimaryRed);
    encode_struct(encoder, value.displayPrimaryGreen);
    encode_struct(encoder, value.displayPrimaryBlue);
    encode_struct(encoder, value.whitePoint);
    encoder->EncodeFloatValue(value.maxLuminance);
    encoder->EncodeFloatValue(value.minLuminance);
    encoder->EncodeFloatValue(value.maxContentLightLevel);
    encoder->EncodeFloatValue(value.maxFrameAverageLightLevel);
}

#ifdef VK_USE_PLATFORM_IOS_MVK
void encode_struct(ParameterEncoder* encoder, const VkIOSSurfaceCreateInfoMVK& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVoidPtr(value.pView);
}
#endif /* VK_USE_PLATFORM_IOS_MVK */

#ifdef VK_USE_PLATFORM_MACOS_MVK
void encode_struct(ParameterEncoder* encoder, const VkMacOSSurfaceCreateInfoMVK& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVoidPtr(value.pView);
}
#endif /* VK_USE_PLATFORM_MACOS_MVK */

void encode_struct(ParameterEncoder* encoder, const VkDebugUtilsObjectNameInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.objectType);
    encoder->EncodeUInt64Value(value.objectHandle);
    encoder->EncodeString(value.pObjectName);
}

void encode_struct(ParameterEncoder* encoder, const VkDebugUtilsObjectTagInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.objectType);
    encoder->EncodeUInt64Value(value.objectHandle);
    encoder->EncodeUInt64Value(value.tagName);
    encoder->EncodeSizeTValue(value.tagSize);
    encoder->EncodeVoidArray(value.pTag, value.tagSize);
}

void encode_struct(ParameterEncoder* encoder, const VkDebugUtilsLabelEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeString(value.pLabelName);
    encoder->EncodeFloatArray(value.color, 4);
}

void encode_struct(ParameterEncoder* encoder, const VkDebugUtilsMessengerCallbackDataEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeString(value.pMessageIdName);
    encoder->EncodeInt32Value(value.messageIdNumber);
    encoder->EncodeString(value.pMessage);
    encoder->EncodeUInt32Value(value.queueLabelCount);
    encode_struct_array(encoder, value.pQueueLabels, value.queueLabelCount);
    encoder->EncodeUInt32Value(value.cmdBufLabelCount);
    encode_struct_array(encoder, value.pCmdBufLabels, value.cmdBufLabelCount);
    encoder->EncodeUInt32Value(value.objectCount);
    encode_struct_array(encoder, value.pObjects, value.objectCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDebugUtilsMessengerCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeFlagsValue(value.messageSeverity);
    encoder->EncodeFlagsValue(value.messageType);
    encoder->EncodeFunctionPtr(value.pfnUserCallback);
    encoder->EncodeVoidPtr(value.pUserData);
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
void encode_struct(ParameterEncoder* encoder, const VkAndroidHardwareBufferUsageANDROID& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt64Value(value.androidHardwareBufferUsage);
}

void encode_struct(ParameterEncoder* encoder, const VkAndroidHardwareBufferPropertiesANDROID& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkDeviceSizeValue(value.allocationSize);
    encoder->EncodeUInt32Value(value.memoryTypeBits);
}

void encode_struct(ParameterEncoder* encoder, const VkAndroidHardwareBufferFormatPropertiesANDROID& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.format);
    encoder->EncodeUInt64Value(value.externalFormat);
    encoder->EncodeFlagsValue(value.formatFeatures);
    encode_struct(encoder, value.samplerYcbcrConversionComponents);
    encoder->EncodeEnumValue(value.suggestedYcbcrModel);
    encoder->EncodeEnumValue(value.suggestedYcbcrRange);
    encoder->EncodeEnumValue(value.suggestedXChromaOffset);
    encoder->EncodeEnumValue(value.suggestedYChromaOffset);
}

void encode_struct(ParameterEncoder* encoder, const VkImportAndroidHardwareBufferInfoANDROID& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVoidPtr(value.buffer);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryGetAndroidHardwareBufferInfoANDROID& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.memory);
}

void encode_struct(ParameterEncoder* encoder, const VkExternalFormatANDROID& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt64Value(value.externalFormat);
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

void encode_struct(ParameterEncoder* encoder, const VkSamplerReductionModeCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.reductionMode);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.filterMinmaxSingleComponentFormats);
    encoder->EncodeVkBool32Value(value.filterMinmaxImageComponentMapping);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceInlineUniformBlockFeaturesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.inlineUniformBlock);
    encoder->EncodeVkBool32Value(value.descriptorBindingInlineUniformBlockUpdateAfterBind);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceInlineUniformBlockPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.maxInlineUniformBlockSize);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorInlineUniformBlocks);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks);
    encoder->EncodeUInt32Value(value.maxDescriptorSetInlineUniformBlocks);
    encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindInlineUniformBlocks);
}

void encode_struct(ParameterEncoder* encoder, const VkWriteDescriptorSetInlineUniformBlockEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.dataSize);
    encoder->EncodeVoidArray(value.pData, value.dataSize);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorPoolInlineUniformBlockCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.maxInlineUniformBlockBindings);
}

void encode_struct(ParameterEncoder* encoder, const VkSampleLocationEXT& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
}

void encode_struct(ParameterEncoder* encoder, const VkSampleLocationsInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.sampleLocationsPerPixel);
    encode_struct(encoder, value.sampleLocationGridSize);
    encoder->EncodeUInt32Value(value.sampleLocationsCount);
    encode_struct_array(encoder, value.pSampleLocations, value.sampleLocationsCount);
}

void encode_struct(ParameterEncoder* encoder, const VkAttachmentSampleLocationsEXT& value)
{
    encoder->EncodeUInt32Value(value.attachmentIndex);
    encode_struct(encoder, value.sampleLocationsInfo);
}

void encode_struct(ParameterEncoder* encoder, const VkSubpassSampleLocationsEXT& value)
{
    encoder->EncodeUInt32Value(value.subpassIndex);
    encode_struct(encoder, value.sampleLocationsInfo);
}

void encode_struct(ParameterEncoder* encoder, const VkRenderPassSampleLocationsBeginInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.attachmentInitialSampleLocationsCount);
    encode_struct_array(encoder, value.pAttachmentInitialSampleLocations, value.attachmentInitialSampleLocationsCount);
    encoder->EncodeUInt32Value(value.postSubpassSampleLocationsCount);
    encode_struct_array(encoder, value.pPostSubpassSampleLocations, value.postSubpassSampleLocationsCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineSampleLocationsStateCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.sampleLocationsEnable);
    encode_struct(encoder, value.sampleLocationsInfo);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceSampleLocationsPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.sampleLocationSampleCounts);
    encode_struct(encoder, value.maxSampleLocationGridSize);
    encoder->EncodeFloatArray(value.sampleLocationCoordinateRange, 2);
    encoder->EncodeUInt32Value(value.sampleLocationSubPixelBits);
    encoder->EncodeVkBool32Value(value.variableSampleLocations);
}

void encode_struct(ParameterEncoder* encoder, const VkMultisamplePropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.maxSampleLocationGridSize);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.advancedBlendCoherentOperations);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.advancedBlendMaxColorAttachments);
    encoder->EncodeVkBool32Value(value.advancedBlendIndependentBlend);
    encoder->EncodeVkBool32Value(value.advancedBlendNonPremultipliedSrcColor);
    encoder->EncodeVkBool32Value(value.advancedBlendNonPremultipliedDstColor);
    encoder->EncodeVkBool32Value(value.advancedBlendCorrelatedOverlap);
    encoder->EncodeVkBool32Value(value.advancedBlendAllOperations);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineColorBlendAdvancedStateCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.srcPremultiplied);
    encoder->EncodeVkBool32Value(value.dstPremultiplied);
    encoder->EncodeEnumValue(value.blendOverlap);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineCoverageToColorStateCreateInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVkBool32Value(value.coverageToColorEnable);
    encoder->EncodeUInt32Value(value.coverageToColorLocation);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineCoverageModulationStateCreateInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeEnumValue(value.coverageModulationMode);
    encoder->EncodeVkBool32Value(value.coverageModulationTableEnable);
    encoder->EncodeUInt32Value(value.coverageModulationTableCount);
    encoder->EncodeFloatArray(value.pCoverageModulationTable, value.coverageModulationTableCount);
}

void encode_struct(ParameterEncoder* encoder, const VkValidationCacheCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeSizeTValue(value.initialDataSize);
    encoder->EncodeVoidArray(value.pInitialData, value.initialDataSize);
}

void encode_struct(ParameterEncoder* encoder, const VkShaderModuleValidationCacheCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.validationCache);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorSetLayoutBindingFlagsCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.bindingCount);
    encoder->EncodeFlagsArray(value.pBindingFlags, value.bindingCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorIndexingFeaturesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.shaderInputAttachmentArrayDynamicIndexing);
    encoder->EncodeVkBool32Value(value.shaderUniformTexelBufferArrayDynamicIndexing);
    encoder->EncodeVkBool32Value(value.shaderStorageTexelBufferArrayDynamicIndexing);
    encoder->EncodeVkBool32Value(value.shaderUniformBufferArrayNonUniformIndexing);
    encoder->EncodeVkBool32Value(value.shaderSampledImageArrayNonUniformIndexing);
    encoder->EncodeVkBool32Value(value.shaderStorageBufferArrayNonUniformIndexing);
    encoder->EncodeVkBool32Value(value.shaderStorageImageArrayNonUniformIndexing);
    encoder->EncodeVkBool32Value(value.shaderInputAttachmentArrayNonUniformIndexing);
    encoder->EncodeVkBool32Value(value.shaderUniformTexelBufferArrayNonUniformIndexing);
    encoder->EncodeVkBool32Value(value.shaderStorageTexelBufferArrayNonUniformIndexing);
    encoder->EncodeVkBool32Value(value.descriptorBindingUniformBufferUpdateAfterBind);
    encoder->EncodeVkBool32Value(value.descriptorBindingSampledImageUpdateAfterBind);
    encoder->EncodeVkBool32Value(value.descriptorBindingStorageImageUpdateAfterBind);
    encoder->EncodeVkBool32Value(value.descriptorBindingStorageBufferUpdateAfterBind);
    encoder->EncodeVkBool32Value(value.descriptorBindingUniformTexelBufferUpdateAfterBind);
    encoder->EncodeVkBool32Value(value.descriptorBindingStorageTexelBufferUpdateAfterBind);
    encoder->EncodeVkBool32Value(value.descriptorBindingUpdateUnusedWhilePending);
    encoder->EncodeVkBool32Value(value.descriptorBindingPartiallyBound);
    encoder->EncodeVkBool32Value(value.descriptorBindingVariableDescriptorCount);
    encoder->EncodeVkBool32Value(value.runtimeDescriptorArray);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorIndexingPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.maxUpdateAfterBindDescriptorsInAllPools);
    encoder->EncodeVkBool32Value(value.shaderUniformBufferArrayNonUniformIndexingNative);
    encoder->EncodeVkBool32Value(value.shaderSampledImageArrayNonUniformIndexingNative);
    encoder->EncodeVkBool32Value(value.shaderStorageBufferArrayNonUniformIndexingNative);
    encoder->EncodeVkBool32Value(value.shaderStorageImageArrayNonUniformIndexingNative);
    encoder->EncodeVkBool32Value(value.shaderInputAttachmentArrayNonUniformIndexingNative);
    encoder->EncodeVkBool32Value(value.robustBufferAccessUpdateAfterBind);
    encoder->EncodeVkBool32Value(value.quadDivergentImplicitLod);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorUpdateAfterBindSamplers);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorUpdateAfterBindUniformBuffers);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorUpdateAfterBindStorageBuffers);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorUpdateAfterBindSampledImages);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorUpdateAfterBindStorageImages);
    encoder->EncodeUInt32Value(value.maxPerStageDescriptorUpdateAfterBindInputAttachments);
    encoder->EncodeUInt32Value(value.maxPerStageUpdateAfterBindResources);
    encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindSamplers);
    encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindUniformBuffers);
    encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic);
    encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindStorageBuffers);
    encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic);
    encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindSampledImages);
    encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindStorageImages);
    encoder->EncodeUInt32Value(value.maxDescriptorSetUpdateAfterBindInputAttachments);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorSetVariableDescriptorCountAllocateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.descriptorSetCount);
    encoder->EncodeUInt32Array(value.pDescriptorCounts, value.descriptorSetCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorSetVariableDescriptorCountLayoutSupportEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.maxVariableDescriptorCount);
}

void encode_struct(ParameterEncoder* encoder, const VkShadingRatePaletteNV& value)
{
    encoder->EncodeUInt32Value(value.shadingRatePaletteEntryCount);
    encoder->EncodeEnumArray(value.pShadingRatePaletteEntries, value.shadingRatePaletteEntryCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineViewportShadingRateImageStateCreateInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.shadingRateImageEnable);
    encoder->EncodeUInt32Value(value.viewportCount);
    encode_struct_array(encoder, value.pShadingRatePalettes, value.viewportCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceShadingRateImageFeaturesNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.shadingRateImage);
    encoder->EncodeVkBool32Value(value.shadingRateCoarseSampleOrder);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceShadingRateImagePropertiesNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encode_struct(encoder, value.shadingRateTexelSize);
    encoder->EncodeUInt32Value(value.shadingRatePaletteSize);
    encoder->EncodeUInt32Value(value.shadingRateMaxCoarseSamples);
}

void encode_struct(ParameterEncoder* encoder, const VkCoarseSampleLocationNV& value)
{
    encoder->EncodeUInt32Value(value.pixelX);
    encoder->EncodeUInt32Value(value.pixelY);
    encoder->EncodeUInt32Value(value.sample);
}

void encode_struct(ParameterEncoder* encoder, const VkCoarseSampleOrderCustomNV& value)
{
    encoder->EncodeEnumValue(value.shadingRate);
    encoder->EncodeUInt32Value(value.sampleCount);
    encoder->EncodeUInt32Value(value.sampleLocationCount);
    encode_struct_array(encoder, value.pSampleLocations, value.sampleLocationCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.sampleOrderType);
    encoder->EncodeUInt32Value(value.customSampleOrderCount);
    encode_struct_array(encoder, value.pCustomSampleOrders, value.customSampleOrderCount);
}

void encode_struct(ParameterEncoder* encoder, const VkRaytracingPipelineCreateInfoNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.stageCount);
    encode_struct_array(encoder, value.pStages, value.stageCount);
    encoder->EncodeUInt32Array(value.pGroupNumbers, value.stageCount);
    encoder->EncodeUInt32Value(value.maxRecursionDepth);
    encoder->EncodeHandleIdValue(value.layout);
    encoder->EncodeHandleIdValue(value.basePipelineHandle);
    encoder->EncodeInt32Value(value.basePipelineIndex);
}

void encode_struct(ParameterEncoder* encoder, const VkGeometryTrianglesNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.vertexData);
    encoder->EncodeVkDeviceSizeValue(value.vertexOffset);
    encoder->EncodeUInt32Value(value.vertexCount);
    encoder->EncodeVkDeviceSizeValue(value.vertexStride);
    encoder->EncodeEnumValue(value.vertexFormat);
    encoder->EncodeHandleIdValue(value.indexData);
    encoder->EncodeVkDeviceSizeValue(value.indexOffset);
    encoder->EncodeUInt32Value(value.indexCount);
    encoder->EncodeEnumValue(value.indexType);
    encoder->EncodeHandleIdValue(value.transformData);
    encoder->EncodeVkDeviceSizeValue(value.transformOffset);
}

void encode_struct(ParameterEncoder* encoder, const VkGeometryAABBNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.aabbData);
    encoder->EncodeUInt32Value(value.numAABBs);
    encoder->EncodeUInt32Value(value.stride);
    encoder->EncodeVkDeviceSizeValue(value.offset);
}

void encode_struct(ParameterEncoder* encoder, const VkGeometryDataNVX& value)
{
    encode_struct(encoder, value.triangles);
    encode_struct(encoder, value.aabbs);
}

void encode_struct(ParameterEncoder* encoder, const VkGeometryNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.geometryType);
    encode_struct(encoder, value.geometry);
    encoder->EncodeFlagsValue(value.flags);
}

void encode_struct(ParameterEncoder* encoder, const VkAccelerationStructureCreateInfoNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVkDeviceSizeValue(value.compactedSize);
    encoder->EncodeUInt32Value(value.instanceCount);
    encoder->EncodeUInt32Value(value.geometryCount);
    encode_struct_array(encoder, value.pGeometries, value.geometryCount);
}

void encode_struct(ParameterEncoder* encoder, const VkBindAccelerationStructureMemoryInfoNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.accelerationStructure);
    encoder->EncodeHandleIdValue(value.memory);
    encoder->EncodeVkDeviceSizeValue(value.memoryOffset);
    encoder->EncodeUInt32Value(value.deviceIndexCount);
    encoder->EncodeUInt32Array(value.pDeviceIndices, value.deviceIndexCount);
}

void encode_struct(ParameterEncoder* encoder, const VkDescriptorAccelerationStructureInfoNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.accelerationStructureCount);
    encoder->EncodeHandleIdArray(value.pAccelerationStructures, value.accelerationStructureCount);
}

void encode_struct(ParameterEncoder* encoder, const VkAccelerationStructureMemoryRequirementsInfoNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeHandleIdValue(value.accelerationStructure);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceRaytracingPropertiesNVX& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.shaderHeaderSize);
    encoder->EncodeUInt32Value(value.maxRecursionDepth);
    encoder->EncodeUInt32Value(value.maxGeometryCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.representativeFragmentTest);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineRepresentativeFragmentTestStateCreateInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.representativeFragmentTestEnable);
}

void encode_struct(ParameterEncoder* encoder, const VkDeviceQueueGlobalPriorityCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.globalPriority);
}

void encode_struct(ParameterEncoder* encoder, const VkImportMemoryHostPointerInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.handleType);
    encoder->EncodeVoidPtr(value.pHostPointer);
}

void encode_struct(ParameterEncoder* encoder, const VkMemoryHostPointerPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.memoryTypeBits);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalMemoryHostPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkDeviceSizeValue(value.minImportedHostPointerAlignment);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderCorePropertiesAMD& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.shaderEngineCount);
    encoder->EncodeUInt32Value(value.shaderArraysPerEngineCount);
    encoder->EncodeUInt32Value(value.computeUnitsPerShaderArray);
    encoder->EncodeUInt32Value(value.simdPerComputeUnit);
    encoder->EncodeUInt32Value(value.wavefrontsPerSimd);
    encoder->EncodeUInt32Value(value.wavefrontSize);
    encoder->EncodeUInt32Value(value.sgprsPerSimd);
    encoder->EncodeUInt32Value(value.minSgprAllocation);
    encoder->EncodeUInt32Value(value.maxSgprAllocation);
    encoder->EncodeUInt32Value(value.sgprAllocationGranularity);
    encoder->EncodeUInt32Value(value.vgprsPerSimd);
    encoder->EncodeUInt32Value(value.minVgprAllocation);
    encoder->EncodeUInt32Value(value.maxVgprAllocation);
    encoder->EncodeUInt32Value(value.vgprAllocationGranularity);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.maxVertexAttribDivisor);
}

void encode_struct(ParameterEncoder* encoder, const VkVertexInputBindingDivisorDescriptionEXT& value)
{
    encoder->EncodeUInt32Value(value.binding);
    encoder->EncodeUInt32Value(value.divisor);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineVertexInputDivisorStateCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.vertexBindingDivisorCount);
    encode_struct_array(encoder, value.pVertexBindingDivisors, value.vertexBindingDivisorCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.vertexAttributeInstanceRateDivisor);
    encoder->EncodeVkBool32Value(value.vertexAttributeInstanceRateZeroDivisor);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.computeDerivativeGroupQuads);
    encoder->EncodeVkBool32Value(value.computeDerivativeGroupLinear);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceMeshShaderFeaturesNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.taskShader);
    encoder->EncodeVkBool32Value(value.meshShader);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceMeshShaderPropertiesNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.maxDrawMeshTasksCount);
    encoder->EncodeUInt32Value(value.maxTaskWorkGroupInvocations);
    encoder->EncodeUInt32Array(value.maxTaskWorkGroupSize, 3);
    encoder->EncodeUInt32Value(value.maxTaskTotalMemorySize);
    encoder->EncodeUInt32Value(value.maxTaskOutputCount);
    encoder->EncodeUInt32Value(value.maxMeshWorkGroupInvocations);
    encoder->EncodeUInt32Array(value.maxMeshWorkGroupSize, 3);
    encoder->EncodeUInt32Value(value.maxMeshTotalMemorySize);
    encoder->EncodeUInt32Value(value.maxMeshOutputVertices);
    encoder->EncodeUInt32Value(value.maxMeshOutputPrimitives);
    encoder->EncodeUInt32Value(value.maxMeshMultiviewViewCount);
    encoder->EncodeUInt32Value(value.meshOutputPerVertexGranularity);
    encoder->EncodeUInt32Value(value.meshOutputPerPrimitiveGranularity);
}

void encode_struct(ParameterEncoder* encoder, const VkDrawMeshTasksIndirectCommandNV& value)
{
    encoder->EncodeUInt32Value(value.taskCount);
    encoder->EncodeUInt32Value(value.firstTask);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.fragmentShaderBarycentric);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderImageFootprintFeaturesNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.imageFootprint);
}

void encode_struct(ParameterEncoder* encoder, const VkPipelineViewportExclusiveScissorStateCreateInfoNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.exclusiveScissorCount);
    encode_struct_array(encoder, value.pExclusiveScissors, value.exclusiveScissorCount);
}

void encode_struct(ParameterEncoder* encoder, const VkPhysicalDeviceExclusiveScissorFeaturesNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeVkBool32Value(value.exclusiveScissor);
}

void encode_struct(ParameterEncoder* encoder, const VkQueueFamilyCheckpointPropertiesNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.checkpointExecutionStageMask);
}

void encode_struct(ParameterEncoder* encoder, const VkCheckpointDataNV& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.stage);
    encoder->EncodeVoidPtr(value.pCheckpointMarker);
}

#ifdef VK_USE_PLATFORM_FUCHSIA
void encode_struct(ParameterEncoder* encoder, const VkImagePipeSurfaceCreateInfoFUCHSIA& value)
{
    encoder->EncodeEnumValue(value.sType);
    encode_pnext_struct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeUInt32Value(value.imagePipeHandle);
}
#endif /* VK_USE_PLATFORM_FUCHSIA */

BRIMSTONE_END_NAMESPACE(encode)
BRIMSTONE_END_NAMESPACE(brimstone)
