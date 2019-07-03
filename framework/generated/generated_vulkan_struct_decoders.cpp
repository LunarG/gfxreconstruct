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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include "generated/generated_vulkan_struct_decoders.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t DecodePNextStruct(const uint8_t* buffer, size_t buffer_size, std::unique_ptr<PNextNode>* pNext);

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkApplicationInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkApplicationInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += wrapper->pApplicationName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pApplicationName = wrapper->pApplicationName.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->applicationVersion));
    bytes_read += wrapper->pEngineName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pEngineName = wrapper->pEngineName.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->engineVersion));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->apiVersion));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkInstanceCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkInstanceCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    wrapper->pApplicationInfo = std::make_unique<StructPointerDecoder<Decoded_VkApplicationInfo>>();
    bytes_read += wrapper->pApplicationInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pApplicationInfo = wrapper->pApplicationInfo->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabledLayerCount));
    bytes_read += wrapper->ppEnabledLayerNames.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ppEnabledLayerNames = wrapper->ppEnabledLayerNames.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabledExtensionCount));
    bytes_read += wrapper->ppEnabledExtensionNames.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ppEnabledExtensionNames = wrapper->ppEnabledExtensionNames.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAllocationCallbacks* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAllocationCallbacks* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pUserData));
    value->pUserData = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pfnAllocation));
    value->pfnAllocation = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pfnReallocation));
    value->pfnReallocation = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pfnFree));
    value->pfnFree = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pfnInternalAllocation));
    value->pfnInternalAllocation = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pfnInternalFree));
    value->pfnInternalFree = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFeatures* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceFeatures* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->robustBufferAccess));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fullDrawIndexUint32));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageCubeArray));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->independentBlend));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->geometryShader));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->tessellationShader));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleRateShading));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dualSrcBlend));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->logicOp));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->multiDrawIndirect));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->drawIndirectFirstInstance));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthClamp));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthBiasClamp));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fillModeNonSolid));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthBounds));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->wideLines));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->largePoints));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->alphaToOne));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->multiViewport));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->samplerAnisotropy));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->textureCompressionETC2));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->textureCompressionASTC_LDR));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->textureCompressionBC));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->occlusionQueryPrecise));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->pipelineStatisticsQuery));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexPipelineStoresAndAtomics));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fragmentStoresAndAtomics));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderTessellationAndGeometryPointSize));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderImageGatherExtended));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStorageImageExtendedFormats));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStorageImageMultisample));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStorageImageReadWithoutFormat));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStorageImageWriteWithoutFormat));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderUniformBufferArrayDynamicIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderSampledImageArrayDynamicIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStorageBufferArrayDynamicIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStorageImageArrayDynamicIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderClipDistance));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderCullDistance));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderFloat64));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderInt64));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderInt16));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderResourceResidency));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderResourceMinLod));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sparseBinding));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sparseResidencyBuffer));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sparseResidencyImage2D));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sparseResidencyImage3D));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sparseResidency2Samples));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sparseResidency4Samples));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sparseResidency8Samples));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sparseResidency16Samples));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sparseResidencyAliased));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->variableMultisampleRate));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->inheritedQueries));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFormatProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFormatProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->linearTilingFeatures));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->optimalTilingFeatures));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferFeatures));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExtent3D* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExtent3D* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depth));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageFormatProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageFormatProperties* value = wrapper->value;

    wrapper->maxExtent = std::make_unique<Decoded_VkExtent3D>();
    wrapper->maxExtent->value = &(value->maxExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->maxExtent.get());
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMipLevels));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxArrayLayers));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleCounts));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxResourceSize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceLimits* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceLimits* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageDimension1D));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageDimension2D));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageDimension3D));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageDimensionCube));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageArrayLayers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTexelBufferElements));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxUniformBufferRange));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxStorageBufferRange));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPushConstantsSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMemoryAllocationCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSamplerAllocationCount));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferImageGranularity));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sparseAddressSpaceSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxBoundDescriptorSets));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorSamplers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorUniformBuffers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorStorageBuffers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorSampledImages));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorStorageImages));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorInputAttachments));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageResources));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetSamplers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetUniformBuffers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetUniformBuffersDynamic));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetStorageBuffers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetStorageBuffersDynamic));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetSampledImages));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetStorageImages));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetInputAttachments));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxVertexInputAttributes));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxVertexInputBindings));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxVertexInputAttributeOffset));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxVertexInputBindingStride));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxVertexOutputComponents));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTessellationGenerationLevel));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTessellationPatchSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTessellationControlPerVertexInputComponents));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTessellationControlPerVertexOutputComponents));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTessellationControlPerPatchOutputComponents));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTessellationControlTotalOutputComponents));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTessellationEvaluationInputComponents));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTessellationEvaluationOutputComponents));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxGeometryShaderInvocations));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxGeometryInputComponents));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxGeometryOutputComponents));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxGeometryOutputVertices));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxGeometryTotalOutputComponents));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxFragmentInputComponents));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxFragmentOutputAttachments));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxFragmentDualSrcAttachments));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxFragmentCombinedOutputResources));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxComputeSharedMemorySize));
    wrapper->maxComputeWorkGroupCount.SetExternalMemory(value->maxComputeWorkGroupCount, 3);
    bytes_read += wrapper->maxComputeWorkGroupCount.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxComputeWorkGroupInvocations));
    wrapper->maxComputeWorkGroupSize.SetExternalMemory(value->maxComputeWorkGroupSize, 3);
    bytes_read += wrapper->maxComputeWorkGroupSize.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subPixelPrecisionBits));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subTexelPrecisionBits));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->mipmapPrecisionBits));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDrawIndexedIndexValue));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDrawIndirectCount));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSamplerLodBias));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSamplerAnisotropy));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxViewports));
    wrapper->maxViewportDimensions.SetExternalMemory(value->maxViewportDimensions, 2);
    bytes_read += wrapper->maxViewportDimensions.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->viewportBoundsRange.SetExternalMemory(value->viewportBoundsRange, 2);
    bytes_read += wrapper->viewportBoundsRange.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewportSubPixelBits));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minMemoryMapAlignment));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minTexelBufferOffsetAlignment));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minUniformBufferOffsetAlignment));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minStorageBufferOffsetAlignment));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minTexelOffset));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTexelOffset));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minTexelGatherOffset));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTexelGatherOffset));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minInterpolationOffset));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxInterpolationOffset));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subPixelInterpolationOffsetBits));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxFramebufferWidth));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxFramebufferHeight));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxFramebufferLayers));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->framebufferColorSampleCounts));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->framebufferDepthSampleCounts));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->framebufferStencilSampleCounts));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->framebufferNoAttachmentsSampleCounts));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxColorAttachments));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampledImageColorSampleCounts));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampledImageIntegerSampleCounts));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampledImageDepthSampleCounts));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampledImageStencilSampleCounts));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->storageImageSampleCounts));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSampleMaskWords));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->timestampComputeAndGraphics));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->timestampPeriod));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxClipDistances));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxCullDistances));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxCombinedClipAndCullDistances));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->discreteQueuePriorities));
    wrapper->pointSizeRange.SetExternalMemory(value->pointSizeRange, 2);
    bytes_read += wrapper->pointSizeRange.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->lineWidthRange.SetExternalMemory(value->lineWidthRange, 2);
    bytes_read += wrapper->lineWidthRange.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pointSizeGranularity));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->lineWidthGranularity));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->strictLines));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->standardSampleLocations));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->optimalBufferCopyOffsetAlignment));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->optimalBufferCopyRowPitchAlignment));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->nonCoherentAtomSize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSparseProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceSparseProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->residencyStandard2DBlockShape));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->residencyStandard2DMultisampleBlockShape));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->residencyStandard3DBlockShape));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->residencyAlignedMipSize));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->residencyNonResidentStrict));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->apiVersion));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->driverVersion));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vendorID));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceID));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceType));
    wrapper->deviceName.SetExternalMemory(value->deviceName, VK_MAX_PHYSICAL_DEVICE_NAME_SIZE);
    bytes_read += wrapper->deviceName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->pipelineCacheUUID.SetExternalMemory(value->pipelineCacheUUID, VK_UUID_SIZE);
    bytes_read += wrapper->pipelineCacheUUID.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->limits = std::make_unique<Decoded_VkPhysicalDeviceLimits>();
    wrapper->limits->value = &(value->limits);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->limits.get());
    wrapper->sparseProperties = std::make_unique<Decoded_VkPhysicalDeviceSparseProperties>();
    wrapper->sparseProperties->value = &(value->sparseProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->sparseProperties.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkQueueFamilyProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkQueueFamilyProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFlags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->timestampValidBits));
    wrapper->minImageTransferGranularity = std::make_unique<Decoded_VkExtent3D>();
    wrapper->minImageTransferGranularity->value = &(value->minImageTransferGranularity);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->minImageTransferGranularity.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryType* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryType* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->propertyFlags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->heapIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryHeap* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryHeap* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMemoryProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeCount));
    wrapper->memoryTypes = std::make_unique<StructPointerDecoder<Decoded_VkMemoryType>>();
    wrapper->memoryTypes->SetExternalMemory(value->memoryTypes, VK_MAX_MEMORY_TYPES);
    bytes_read += wrapper->memoryTypes->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryHeapCount));
    wrapper->memoryHeaps = std::make_unique<StructPointerDecoder<Decoded_VkMemoryHeap>>();
    wrapper->memoryHeaps->SetExternalMemory(value->memoryHeaps, VK_MAX_MEMORY_HEAPS);
    bytes_read += wrapper->memoryHeaps->Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceQueueCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceQueueCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFamilyIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueCount));
    bytes_read += wrapper->pQueuePriorities.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    value->pQueuePriorities = wrapper->pQueuePriorities.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueCreateInfoCount));
    wrapper->pQueueCreateInfos = std::make_unique<StructPointerDecoder<Decoded_VkDeviceQueueCreateInfo>>();
    bytes_read += wrapper->pQueueCreateInfos->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pQueueCreateInfos = wrapper->pQueueCreateInfos->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabledLayerCount));
    bytes_read += wrapper->ppEnabledLayerNames.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ppEnabledLayerNames = wrapper->ppEnabledLayerNames.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabledExtensionCount));
    bytes_read += wrapper->ppEnabledExtensionNames.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ppEnabledExtensionNames = wrapper->ppEnabledExtensionNames.GetPointer();
    wrapper->pEnabledFeatures = std::make_unique<StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>>();
    bytes_read += wrapper->pEnabledFeatures->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pEnabledFeatures = wrapper->pEnabledFeatures->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExtensionProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExtensionProperties* value = wrapper->value;

    wrapper->extensionName.SetExternalMemory(value->extensionName, VK_MAX_EXTENSION_NAME_SIZE);
    bytes_read += wrapper->extensionName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->specVersion));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkLayerProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkLayerProperties* value = wrapper->value;

    wrapper->layerName.SetExternalMemory(value->layerName, VK_MAX_EXTENSION_NAME_SIZE);
    bytes_read += wrapper->layerName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->specVersion));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->implementationVersion));
    wrapper->description.SetExternalMemory(value->description, VK_MAX_DESCRIPTION_SIZE);
    bytes_read += wrapper->description.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubmitInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubmitInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->waitSemaphoreCount));
    bytes_read += wrapper->pWaitSemaphores.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pWaitSemaphores = wrapper->pWaitSemaphores.GetHandlePointer();
    bytes_read += wrapper->pWaitDstStageMask.DecodeFlags((buffer + bytes_read), (buffer_size - bytes_read));
    value->pWaitDstStageMask = wrapper->pWaitDstStageMask.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->commandBufferCount));
    bytes_read += wrapper->pCommandBuffers.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCommandBuffers = wrapper->pCommandBuffers.GetHandlePointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->signalSemaphoreCount));
    bytes_read += wrapper->pSignalSemaphores.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSignalSemaphores = wrapper->pSignalSemaphores.GetHandlePointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryAllocateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryAllocateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->allocationSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMappedMemoryRange* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMappedMemoryRange* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryRequirements* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryRequirements* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->alignment));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeBits));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageFormatProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageFormatProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectMask));
    wrapper->imageGranularity = std::make_unique<Decoded_VkExtent3D>();
    wrapper->imageGranularity->value = &(value->imageGranularity);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageGranularity.get());
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageMemoryRequirements* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageMemoryRequirements* value = wrapper->value;

    wrapper->formatProperties = std::make_unique<Decoded_VkSparseImageFormatProperties>();
    wrapper->formatProperties->value = &(value->formatProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->formatProperties.get());
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageMipTailFirstLod));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageMipTailSize));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageMipTailOffset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageMipTailStride));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseMemoryBind* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseMemoryBind* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->resourceOffset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryOffset));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseBufferMemoryBindInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseBufferMemoryBindInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bindCount));
    wrapper->pBinds = std::make_unique<StructPointerDecoder<Decoded_VkSparseMemoryBind>>();
    bytes_read += wrapper->pBinds->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBinds = wrapper->pBinds->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageOpaqueMemoryBindInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bindCount));
    wrapper->pBinds = std::make_unique<StructPointerDecoder<Decoded_VkSparseMemoryBind>>();
    bytes_read += wrapper->pBinds->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBinds = wrapper->pBinds->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageSubresource* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageSubresource* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->mipLevel));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->arrayLayer));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkOffset3D* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkOffset3D* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->z));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageMemoryBind* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageMemoryBind* value = wrapper->value;

    wrapper->subresource = std::make_unique<Decoded_VkImageSubresource>();
    wrapper->subresource->value = &(value->subresource);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->subresource.get());
    wrapper->offset = std::make_unique<Decoded_VkOffset3D>();
    wrapper->offset->value = &(value->offset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->offset.get());
    wrapper->extent = std::make_unique<Decoded_VkExtent3D>();
    wrapper->extent->value = &(value->extent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->extent.get());
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryOffset));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageMemoryBindInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageMemoryBindInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bindCount));
    wrapper->pBinds = std::make_unique<StructPointerDecoder<Decoded_VkSparseImageMemoryBind>>();
    bytes_read += wrapper->pBinds->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBinds = wrapper->pBinds->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindSparseInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindSparseInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->waitSemaphoreCount));
    bytes_read += wrapper->pWaitSemaphores.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pWaitSemaphores = wrapper->pWaitSemaphores.GetHandlePointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferBindCount));
    wrapper->pBufferBinds = std::make_unique<StructPointerDecoder<Decoded_VkSparseBufferMemoryBindInfo>>();
    bytes_read += wrapper->pBufferBinds->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBufferBinds = wrapper->pBufferBinds->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageOpaqueBindCount));
    wrapper->pImageOpaqueBinds = std::make_unique<StructPointerDecoder<Decoded_VkSparseImageOpaqueMemoryBindInfo>>();
    bytes_read += wrapper->pImageOpaqueBinds->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pImageOpaqueBinds = wrapper->pImageOpaqueBinds->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageBindCount));
    wrapper->pImageBinds = std::make_unique<StructPointerDecoder<Decoded_VkSparseImageMemoryBindInfo>>();
    bytes_read += wrapper->pImageBinds->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pImageBinds = wrapper->pImageBinds->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->signalSemaphoreCount));
    bytes_read += wrapper->pSignalSemaphores.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSignalSemaphores = wrapper->pSignalSemaphores.GetHandlePointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFenceCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFenceCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSemaphoreCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSemaphoreCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkEventCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkEventCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkQueryPoolCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkQueryPoolCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->queryType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queryCount));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pipelineStatistics));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->usage));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sharingMode));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFamilyIndexCount));
    bytes_read += wrapper->pQueueFamilyIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pQueueFamilyIndices = wrapper->pQueueFamilyIndices.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferViewCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferViewCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->range));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageType));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    wrapper->extent = std::make_unique<Decoded_VkExtent3D>();
    wrapper->extent->value = &(value->extent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->extent.get());
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->mipLevels));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->arrayLayers));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->samples));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->tiling));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->usage));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sharingMode));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFamilyIndexCount));
    bytes_read += wrapper->pQueueFamilyIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pQueueFamilyIndices = wrapper->pQueueFamilyIndices.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->initialLayout));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubresourceLayout* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubresourceLayout* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->rowPitch));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->arrayPitch));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthPitch));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkComponentMapping* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkComponentMapping* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->r));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->g));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->b));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->a));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageSubresourceRange* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageSubresourceRange* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->baseMipLevel));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->levelCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->baseArrayLayer));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageViewCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageViewCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewType));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    wrapper->components = std::make_unique<Decoded_VkComponentMapping>();
    wrapper->components->value = &(value->components);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->components.get());
    wrapper->subresourceRange = std::make_unique<Decoded_VkImageSubresourceRange>();
    wrapper->subresourceRange->value = &(value->subresourceRange);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->subresourceRange.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkShaderModuleCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkShaderModuleCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->codeSize));
    bytes_read += wrapper->pCode.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCode = wrapper->pCode.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineCacheCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineCacheCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->initialDataSize));
    bytes_read += wrapper->pInitialData.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pInitialData = wrapper->pInitialData.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSpecializationMapEntry* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSpecializationMapEntry* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->constantID));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSpecializationInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSpecializationInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->mapEntryCount));
    wrapper->pMapEntries = std::make_unique<StructPointerDecoder<Decoded_VkSpecializationMapEntry>>();
    bytes_read += wrapper->pMapEntries->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pMapEntries = wrapper->pMapEntries->GetPointer();
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dataSize));
    bytes_read += wrapper->pData.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pData = wrapper->pData.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineShaderStageCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineShaderStageCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stage));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->module));
    value->module = VK_NULL_HANDLE;
    bytes_read += wrapper->pName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pName = wrapper->pName.GetPointer();
    wrapper->pSpecializationInfo = std::make_unique<StructPointerDecoder<Decoded_VkSpecializationInfo>>();
    bytes_read += wrapper->pSpecializationInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSpecializationInfo = wrapper->pSpecializationInfo->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkVertexInputBindingDescription* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkVertexInputBindingDescription* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->binding));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->stride));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->inputRate));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkVertexInputAttributeDescription* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkVertexInputAttributeDescription* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->location));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->binding));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineVertexInputStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineVertexInputStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexBindingDescriptionCount));
    wrapper->pVertexBindingDescriptions = std::make_unique<StructPointerDecoder<Decoded_VkVertexInputBindingDescription>>();
    bytes_read += wrapper->pVertexBindingDescriptions->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pVertexBindingDescriptions = wrapper->pVertexBindingDescriptions->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexAttributeDescriptionCount));
    wrapper->pVertexAttributeDescriptions = std::make_unique<StructPointerDecoder<Decoded_VkVertexInputAttributeDescription>>();
    bytes_read += wrapper->pVertexAttributeDescriptions->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pVertexAttributeDescriptions = wrapper->pVertexAttributeDescriptions->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineInputAssemblyStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineInputAssemblyStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->topology));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->primitiveRestartEnable));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineTessellationStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineTessellationStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->patchControlPoints));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkViewport* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkViewport* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minDepth));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDepth));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkOffset2D* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkOffset2D* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExtent2D* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExtent2D* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRect2D* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRect2D* value = wrapper->value;

    wrapper->offset = std::make_unique<Decoded_VkOffset2D>();
    wrapper->offset->value = &(value->offset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->offset.get());
    wrapper->extent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->extent->value = &(value->extent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->extent.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineViewportStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineViewportStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewportCount));
    wrapper->pViewports = std::make_unique<StructPointerDecoder<Decoded_VkViewport>>();
    bytes_read += wrapper->pViewports->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pViewports = wrapper->pViewports->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->scissorCount));
    wrapper->pScissors = std::make_unique<StructPointerDecoder<Decoded_VkRect2D>>();
    bytes_read += wrapper->pScissors->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pScissors = wrapper->pScissors->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineRasterizationStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineRasterizationStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthClampEnable));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->rasterizerDiscardEnable));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->polygonMode));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->cullMode));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->frontFace));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthBiasEnable));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthBiasConstantFactor));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthBiasClamp));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthBiasSlopeFactor));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->lineWidth));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineMultisampleStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineMultisampleStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->rasterizationSamples));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleShadingEnable));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minSampleShading));
    bytes_read += wrapper->pSampleMask.DecodeVkSampleMask((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSampleMask = wrapper->pSampleMask.GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->alphaToCoverageEnable));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->alphaToOneEnable));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkStencilOpState* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkStencilOpState* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->failOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->passOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthFailOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->compareOp));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->compareMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->writeMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->reference));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineDepthStencilStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineDepthStencilStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthTestEnable));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthWriteEnable));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthCompareOp));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthBoundsTestEnable));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->stencilTestEnable));
    wrapper->front = std::make_unique<Decoded_VkStencilOpState>();
    wrapper->front->value = &(value->front);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->front.get());
    wrapper->back = std::make_unique<Decoded_VkStencilOpState>();
    wrapper->back->value = &(value->back);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->back.get());
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minDepthBounds));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDepthBounds));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineColorBlendAttachmentState* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineColorBlendAttachmentState* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->blendEnable));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcColorBlendFactor));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstColorBlendFactor));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->colorBlendOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcAlphaBlendFactor));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstAlphaBlendFactor));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->alphaBlendOp));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->colorWriteMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineColorBlendStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineColorBlendStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->logicOpEnable));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->logicOp));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachmentCount));
    wrapper->pAttachments = std::make_unique<StructPointerDecoder<Decoded_VkPipelineColorBlendAttachmentState>>();
    bytes_read += wrapper->pAttachments->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttachments = wrapper->pAttachments->GetPointer();
    wrapper->blendConstants.SetExternalMemory(value->blendConstants, 4);
    bytes_read += wrapper->blendConstants.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineDynamicStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineDynamicStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dynamicStateCount));
    bytes_read += wrapper->pDynamicStates.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDynamicStates = wrapper->pDynamicStates.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkGraphicsPipelineCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkGraphicsPipelineCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->stageCount));
    wrapper->pStages = std::make_unique<StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo>>();
    bytes_read += wrapper->pStages->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pStages = wrapper->pStages->GetPointer();
    wrapper->pVertexInputState = std::make_unique<StructPointerDecoder<Decoded_VkPipelineVertexInputStateCreateInfo>>();
    bytes_read += wrapper->pVertexInputState->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pVertexInputState = wrapper->pVertexInputState->GetPointer();
    wrapper->pInputAssemblyState = std::make_unique<StructPointerDecoder<Decoded_VkPipelineInputAssemblyStateCreateInfo>>();
    bytes_read += wrapper->pInputAssemblyState->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pInputAssemblyState = wrapper->pInputAssemblyState->GetPointer();
    wrapper->pTessellationState = std::make_unique<StructPointerDecoder<Decoded_VkPipelineTessellationStateCreateInfo>>();
    bytes_read += wrapper->pTessellationState->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTessellationState = wrapper->pTessellationState->GetPointer();
    wrapper->pViewportState = std::make_unique<StructPointerDecoder<Decoded_VkPipelineViewportStateCreateInfo>>();
    bytes_read += wrapper->pViewportState->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pViewportState = wrapper->pViewportState->GetPointer();
    wrapper->pRasterizationState = std::make_unique<StructPointerDecoder<Decoded_VkPipelineRasterizationStateCreateInfo>>();
    bytes_read += wrapper->pRasterizationState->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pRasterizationState = wrapper->pRasterizationState->GetPointer();
    wrapper->pMultisampleState = std::make_unique<StructPointerDecoder<Decoded_VkPipelineMultisampleStateCreateInfo>>();
    bytes_read += wrapper->pMultisampleState->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pMultisampleState = wrapper->pMultisampleState->GetPointer();
    wrapper->pDepthStencilState = std::make_unique<StructPointerDecoder<Decoded_VkPipelineDepthStencilStateCreateInfo>>();
    bytes_read += wrapper->pDepthStencilState->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDepthStencilState = wrapper->pDepthStencilState->GetPointer();
    wrapper->pColorBlendState = std::make_unique<StructPointerDecoder<Decoded_VkPipelineColorBlendStateCreateInfo>>();
    bytes_read += wrapper->pColorBlendState->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pColorBlendState = wrapper->pColorBlendState->GetPointer();
    wrapper->pDynamicState = std::make_unique<StructPointerDecoder<Decoded_VkPipelineDynamicStateCreateInfo>>();
    bytes_read += wrapper->pDynamicState->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDynamicState = wrapper->pDynamicState->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->layout));
    value->layout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->renderPass));
    value->renderPass = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subpass));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->basePipelineHandle));
    value->basePipelineHandle = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->basePipelineIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkComputePipelineCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkComputePipelineCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    wrapper->stage = std::make_unique<Decoded_VkPipelineShaderStageCreateInfo>();
    wrapper->stage->value = &(value->stage);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->stage.get());
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->layout));
    value->layout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->basePipelineHandle));
    value->basePipelineHandle = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->basePipelineIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPushConstantRange* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPushConstantRange* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stageFlags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineLayoutCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineLayoutCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->setLayoutCount));
    bytes_read += wrapper->pSetLayouts.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSetLayouts = wrapper->pSetLayouts.GetHandlePointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->pushConstantRangeCount));
    wrapper->pPushConstantRanges = std::make_unique<StructPointerDecoder<Decoded_VkPushConstantRange>>();
    bytes_read += wrapper->pPushConstantRanges->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPushConstantRanges = wrapper->pPushConstantRanges->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSamplerCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSamplerCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->magFilter));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minFilter));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->mipmapMode));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->addressModeU));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->addressModeV));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->addressModeW));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->mipLodBias));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->anisotropyEnable));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxAnisotropy));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->compareEnable));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->compareOp));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minLod));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxLod));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->borderColor));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->unnormalizedCoordinates));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutBinding* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetLayoutBinding* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->binding));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorCount));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stageFlags));
    bytes_read += wrapper->pImmutableSamplers.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pImmutableSamplers = wrapper->pImmutableSamplers.GetHandlePointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetLayoutCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bindingCount));
    wrapper->pBindings = std::make_unique<StructPointerDecoder<Decoded_VkDescriptorSetLayoutBinding>>();
    bytes_read += wrapper->pBindings->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBindings = wrapper->pBindings->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorPoolSize* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorPoolSize* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorPoolCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorPoolCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSets));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->poolSizeCount));
    wrapper->pPoolSizes = std::make_unique<StructPointerDecoder<Decoded_VkDescriptorPoolSize>>();
    bytes_read += wrapper->pPoolSizes->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPoolSizes = wrapper->pPoolSizes->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetAllocateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetAllocateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->descriptorPool));
    value->descriptorPool = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorSetCount));
    bytes_read += wrapper->pSetLayouts.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSetLayouts = wrapper->pSetLayouts.GetHandlePointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorImageInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorImageInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->sampler));
    value->sampler = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->imageView));
    value->imageView = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageLayout));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorBufferInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorBufferInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->range));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkWriteDescriptorSet* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkWriteDescriptorSet* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->dstSet));
    value->dstSet = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstBinding));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstArrayElement));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorCount));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorType));
    wrapper->pImageInfo = std::make_unique<StructPointerDecoder<Decoded_VkDescriptorImageInfo>>();
    bytes_read += wrapper->pImageInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pImageInfo = wrapper->pImageInfo->GetPointer();
    wrapper->pBufferInfo = std::make_unique<StructPointerDecoder<Decoded_VkDescriptorBufferInfo>>();
    bytes_read += wrapper->pBufferInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBufferInfo = wrapper->pBufferInfo->GetPointer();
    bytes_read += wrapper->pTexelBufferView.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTexelBufferView = wrapper->pTexelBufferView.GetHandlePointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCopyDescriptorSet* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCopyDescriptorSet* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->srcSet));
    value->srcSet = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcBinding));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcArrayElement));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->dstSet));
    value->dstSet = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstBinding));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstArrayElement));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFramebufferCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFramebufferCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->renderPass));
    value->renderPass = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachmentCount));
    bytes_read += wrapper->pAttachments.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttachments = wrapper->pAttachments.GetHandlePointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layers));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAttachmentDescription* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAttachmentDescription* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->samples));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->loadOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->storeOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stencilLoadOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stencilStoreOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->initialLayout));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->finalLayout));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAttachmentReference* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAttachmentReference* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachment));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->layout));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassDescription* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassDescription* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pipelineBindPoint));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->inputAttachmentCount));
    wrapper->pInputAttachments = std::make_unique<StructPointerDecoder<Decoded_VkAttachmentReference>>();
    bytes_read += wrapper->pInputAttachments->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pInputAttachments = wrapper->pInputAttachments->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->colorAttachmentCount));
    wrapper->pColorAttachments = std::make_unique<StructPointerDecoder<Decoded_VkAttachmentReference>>();
    bytes_read += wrapper->pColorAttachments->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pColorAttachments = wrapper->pColorAttachments->GetPointer();
    wrapper->pResolveAttachments = std::make_unique<StructPointerDecoder<Decoded_VkAttachmentReference>>();
    bytes_read += wrapper->pResolveAttachments->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pResolveAttachments = wrapper->pResolveAttachments->GetPointer();
    wrapper->pDepthStencilAttachment = std::make_unique<StructPointerDecoder<Decoded_VkAttachmentReference>>();
    bytes_read += wrapper->pDepthStencilAttachment->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDepthStencilAttachment = wrapper->pDepthStencilAttachment->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->preserveAttachmentCount));
    bytes_read += wrapper->pPreserveAttachments.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPreserveAttachments = wrapper->pPreserveAttachments.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassDependency* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassDependency* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcSubpass));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstSubpass));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcStageMask));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstStageMask));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcAccessMask));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstAccessMask));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dependencyFlags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRenderPassCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRenderPassCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachmentCount));
    wrapper->pAttachments = std::make_unique<StructPointerDecoder<Decoded_VkAttachmentDescription>>();
    bytes_read += wrapper->pAttachments->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttachments = wrapper->pAttachments->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subpassCount));
    wrapper->pSubpasses = std::make_unique<StructPointerDecoder<Decoded_VkSubpassDescription>>();
    bytes_read += wrapper->pSubpasses->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSubpasses = wrapper->pSubpasses->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dependencyCount));
    wrapper->pDependencies = std::make_unique<StructPointerDecoder<Decoded_VkSubpassDependency>>();
    bytes_read += wrapper->pDependencies->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDependencies = wrapper->pDependencies->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCommandPoolCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCommandPoolCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFamilyIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCommandBufferAllocateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCommandBufferAllocateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->commandPool));
    value->commandPool = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->level));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->commandBufferCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCommandBufferInheritanceInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCommandBufferInheritanceInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->renderPass));
    value->renderPass = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subpass));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->framebuffer));
    value->framebuffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->occlusionQueryEnable));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->queryFlags));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pipelineStatistics));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCommandBufferBeginInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCommandBufferBeginInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    wrapper->pInheritanceInfo = std::make_unique<StructPointerDecoder<Decoded_VkCommandBufferInheritanceInfo>>();
    bytes_read += wrapper->pInheritanceInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pInheritanceInfo = wrapper->pInheritanceInfo->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferCopy* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferCopy* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcOffset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstOffset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageSubresourceLayers* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageSubresourceLayers* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->mipLevel));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->baseArrayLayer));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageCopy* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageCopy* value = wrapper->value;

    wrapper->srcSubresource = std::make_unique<Decoded_VkImageSubresourceLayers>();
    wrapper->srcSubresource->value = &(value->srcSubresource);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->srcSubresource.get());
    wrapper->srcOffset = std::make_unique<Decoded_VkOffset3D>();
    wrapper->srcOffset->value = &(value->srcOffset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->srcOffset.get());
    wrapper->dstSubresource = std::make_unique<Decoded_VkImageSubresourceLayers>();
    wrapper->dstSubresource->value = &(value->dstSubresource);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->dstSubresource.get());
    wrapper->dstOffset = std::make_unique<Decoded_VkOffset3D>();
    wrapper->dstOffset->value = &(value->dstOffset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->dstOffset.get());
    wrapper->extent = std::make_unique<Decoded_VkExtent3D>();
    wrapper->extent->value = &(value->extent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->extent.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageBlit* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageBlit* value = wrapper->value;

    wrapper->srcSubresource = std::make_unique<Decoded_VkImageSubresourceLayers>();
    wrapper->srcSubresource->value = &(value->srcSubresource);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->srcSubresource.get());
    wrapper->srcOffsets = std::make_unique<StructPointerDecoder<Decoded_VkOffset3D>>();
    wrapper->srcOffsets->SetExternalMemory(value->srcOffsets, 2);
    bytes_read += wrapper->srcOffsets->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->dstSubresource = std::make_unique<Decoded_VkImageSubresourceLayers>();
    wrapper->dstSubresource->value = &(value->dstSubresource);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->dstSubresource.get());
    wrapper->dstOffsets = std::make_unique<StructPointerDecoder<Decoded_VkOffset3D>>();
    wrapper->dstOffsets->SetExternalMemory(value->dstOffsets, 2);
    bytes_read += wrapper->dstOffsets->Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferImageCopy* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferImageCopy* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferOffset));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferRowLength));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferImageHeight));
    wrapper->imageSubresource = std::make_unique<Decoded_VkImageSubresourceLayers>();
    wrapper->imageSubresource->value = &(value->imageSubresource);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageSubresource.get());
    wrapper->imageOffset = std::make_unique<Decoded_VkOffset3D>();
    wrapper->imageOffset->value = &(value->imageOffset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageOffset.get());
    wrapper->imageExtent = std::make_unique<Decoded_VkExtent3D>();
    wrapper->imageExtent->value = &(value->imageExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageExtent.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearDepthStencilValue* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkClearDepthStencilValue* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depth));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->stencil));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearAttachment* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkClearAttachment* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->colorAttachment));
    wrapper->clearValue = std::make_unique<Decoded_VkClearValue>();
    wrapper->clearValue->value = &(value->clearValue);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->clearValue.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearRect* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkClearRect* value = wrapper->value;

    wrapper->rect = std::make_unique<Decoded_VkRect2D>();
    wrapper->rect->value = &(value->rect);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->rect.get());
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->baseArrayLayer));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageResolve* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageResolve* value = wrapper->value;

    wrapper->srcSubresource = std::make_unique<Decoded_VkImageSubresourceLayers>();
    wrapper->srcSubresource->value = &(value->srcSubresource);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->srcSubresource.get());
    wrapper->srcOffset = std::make_unique<Decoded_VkOffset3D>();
    wrapper->srcOffset->value = &(value->srcOffset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->srcOffset.get());
    wrapper->dstSubresource = std::make_unique<Decoded_VkImageSubresourceLayers>();
    wrapper->dstSubresource->value = &(value->dstSubresource);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->dstSubresource.get());
    wrapper->dstOffset = std::make_unique<Decoded_VkOffset3D>();
    wrapper->dstOffset->value = &(value->dstOffset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->dstOffset.get());
    wrapper->extent = std::make_unique<Decoded_VkExtent3D>();
    wrapper->extent->value = &(value->extent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->extent.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryBarrier* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryBarrier* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcAccessMask));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstAccessMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferMemoryBarrier* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferMemoryBarrier* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcAccessMask));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstAccessMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcQueueFamilyIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstQueueFamilyIndex));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageMemoryBarrier* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageMemoryBarrier* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcAccessMask));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstAccessMask));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->oldLayout));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->newLayout));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcQueueFamilyIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstQueueFamilyIndex));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    wrapper->subresourceRange = std::make_unique<Decoded_VkImageSubresourceRange>();
    wrapper->subresourceRange->value = &(value->subresourceRange);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->subresourceRange.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRenderPassBeginInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRenderPassBeginInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->renderPass));
    value->renderPass = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->framebuffer));
    value->framebuffer = VK_NULL_HANDLE;
    wrapper->renderArea = std::make_unique<Decoded_VkRect2D>();
    wrapper->renderArea->value = &(value->renderArea);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->renderArea.get());
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->clearValueCount));
    wrapper->pClearValues = std::make_unique<StructPointerDecoder<Decoded_VkClearValue>>();
    bytes_read += wrapper->pClearValues->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pClearValues = wrapper->pClearValues->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDispatchIndirectCommand* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDispatchIndirectCommand* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->z));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDrawIndexedIndirectCommand* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDrawIndexedIndirectCommand* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->instanceCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->firstIndex));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexOffset));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->firstInstance));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDrawIndirectCommand* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDrawIndirectCommand* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->instanceCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->firstVertex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->firstInstance));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSubgroupProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceSubgroupProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subgroupSize));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedStages));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedOperations));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->quadOperationsInAllStages));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindBufferMemoryInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindBufferMemoryInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryOffset));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindImageMemoryInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindImageMemoryInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryOffset));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDevice16BitStorageFeatures* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDevice16BitStorageFeatures* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->storageBuffer16BitAccess));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->uniformAndStorageBuffer16BitAccess));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->storagePushConstant16));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->storageInputOutput16));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryDedicatedRequirements* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryDedicatedRequirements* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->prefersDedicatedAllocation));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->requiresDedicatedAllocation));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryDedicatedAllocateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryDedicatedAllocateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryAllocateFlagsInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryAllocateFlagsInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupRenderPassBeginInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupRenderPassBeginInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceRenderAreaCount));
    wrapper->pDeviceRenderAreas = std::make_unique<StructPointerDecoder<Decoded_VkRect2D>>();
    bytes_read += wrapper->pDeviceRenderAreas->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDeviceRenderAreas = wrapper->pDeviceRenderAreas->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupCommandBufferBeginInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupCommandBufferBeginInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupSubmitInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupSubmitInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->waitSemaphoreCount));
    bytes_read += wrapper->pWaitSemaphoreDeviceIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pWaitSemaphoreDeviceIndices = wrapper->pWaitSemaphoreDeviceIndices.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->commandBufferCount));
    bytes_read += wrapper->pCommandBufferDeviceMasks.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCommandBufferDeviceMasks = wrapper->pCommandBufferDeviceMasks.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->signalSemaphoreCount));
    bytes_read += wrapper->pSignalSemaphoreDeviceIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSignalSemaphoreDeviceIndices = wrapper->pSignalSemaphoreDeviceIndices.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupBindSparseInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupBindSparseInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->resourceDeviceIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryDeviceIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindBufferMemoryDeviceGroupInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindBufferMemoryDeviceGroupInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceIndexCount));
    bytes_read += wrapper->pDeviceIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDeviceIndices = wrapper->pDeviceIndices.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindImageMemoryDeviceGroupInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindImageMemoryDeviceGroupInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceIndexCount));
    bytes_read += wrapper->pDeviceIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDeviceIndices = wrapper->pDeviceIndices.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->splitInstanceBindRegionCount));
    wrapper->pSplitInstanceBindRegions = std::make_unique<StructPointerDecoder<Decoded_VkRect2D>>();
    bytes_read += wrapper->pSplitInstanceBindRegions->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSplitInstanceBindRegions = wrapper->pSplitInstanceBindRegions->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceGroupProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceGroupProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->physicalDeviceCount));
    wrapper->physicalDevices.SetExternalMemory(value->physicalDevices, VK_MAX_DEVICE_GROUP_SIZE);
    bytes_read += wrapper->physicalDevices.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subsetAllocation));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupDeviceCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupDeviceCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->physicalDeviceCount));
    bytes_read += wrapper->pPhysicalDevices.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPhysicalDevices = wrapper->pPhysicalDevices.GetHandlePointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferMemoryRequirementsInfo2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferMemoryRequirementsInfo2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageMemoryRequirementsInfo2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageMemoryRequirementsInfo2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageSparseMemoryRequirementsInfo2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryRequirements2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryRequirements2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->memoryRequirements = std::make_unique<Decoded_VkMemoryRequirements>();
    wrapper->memoryRequirements->value = &(value->memoryRequirements);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->memoryRequirements.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageMemoryRequirements2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageMemoryRequirements2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->memoryRequirements = std::make_unique<Decoded_VkSparseImageMemoryRequirements>();
    wrapper->memoryRequirements->value = &(value->memoryRequirements);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->memoryRequirements.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFeatures2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceFeatures2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->features = std::make_unique<Decoded_VkPhysicalDeviceFeatures>();
    wrapper->features->value = &(value->features);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->features.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProperties2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceProperties2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->properties = std::make_unique<Decoded_VkPhysicalDeviceProperties>();
    wrapper->properties->value = &(value->properties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->properties.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFormatProperties2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFormatProperties2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->formatProperties = std::make_unique<Decoded_VkFormatProperties>();
    wrapper->formatProperties->value = &(value->formatProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->formatProperties.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageFormatProperties2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageFormatProperties2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->imageFormatProperties = std::make_unique<Decoded_VkImageFormatProperties>();
    wrapper->imageFormatProperties->value = &(value->imageFormatProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageFormatProperties.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageFormatInfo2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceImageFormatInfo2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->tiling));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->usage));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkQueueFamilyProperties2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkQueueFamilyProperties2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->queueFamilyProperties = std::make_unique<Decoded_VkQueueFamilyProperties>();
    wrapper->queueFamilyProperties->value = &(value->queueFamilyProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->queueFamilyProperties.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryProperties2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMemoryProperties2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->memoryProperties = std::make_unique<Decoded_VkPhysicalDeviceMemoryProperties>();
    wrapper->memoryProperties->value = &(value->memoryProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->memoryProperties.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageFormatProperties2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageFormatProperties2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->properties = std::make_unique<Decoded_VkSparseImageFormatProperties>();
    wrapper->properties->value = &(value->properties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->properties.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSparseImageFormatInfo2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceSparseImageFormatInfo2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->samples));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->usage));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->tiling));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDevicePointClippingProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDevicePointClippingProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pointClippingBehavior));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkInputAttachmentAspectReference* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkInputAttachmentAspectReference* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subpass));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->inputAttachmentIndex));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRenderPassInputAttachmentAspectCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRenderPassInputAttachmentAspectCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectReferenceCount));
    wrapper->pAspectReferences = std::make_unique<StructPointerDecoder<Decoded_VkInputAttachmentAspectReference>>();
    bytes_read += wrapper->pAspectReferences->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAspectReferences = wrapper->pAspectReferences->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageViewUsageCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageViewUsageCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->usage));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineTessellationDomainOriginStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineTessellationDomainOriginStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->domainOrigin));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRenderPassMultiviewCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRenderPassMultiviewCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subpassCount));
    bytes_read += wrapper->pViewMasks.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pViewMasks = wrapper->pViewMasks.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dependencyCount));
    bytes_read += wrapper->pViewOffsets.DecodeInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pViewOffsets = wrapper->pViewOffsets.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->correlationMaskCount));
    bytes_read += wrapper->pCorrelationMasks.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCorrelationMasks = wrapper->pCorrelationMasks.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewFeatures* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMultiviewFeatures* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->multiview));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->multiviewGeometryShader));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->multiviewTessellationShader));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMultiviewProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMultiviewViewCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMultiviewInstanceIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVariablePointersFeatures* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceVariablePointersFeatures* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->variablePointersStorageBuffer));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->variablePointers));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProtectedMemoryFeatures* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceProtectedMemoryFeatures* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->protectedMemory));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProtectedMemoryProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceProtectedMemoryProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->protectedNoFault));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceQueueInfo2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceQueueInfo2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFamilyIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkProtectedSubmitInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkProtectedSubmitInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->protectedSubmit));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSamplerYcbcrConversionCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSamplerYcbcrConversionCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ycbcrModel));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ycbcrRange));
    wrapper->components = std::make_unique<Decoded_VkComponentMapping>();
    wrapper->components->value = &(value->components);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->components.get());
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->xChromaOffset));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->yChromaOffset));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->chromaFilter));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->forceExplicitReconstruction));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSamplerYcbcrConversionInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSamplerYcbcrConversionInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->conversion));
    value->conversion = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindImagePlaneMemoryInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindImagePlaneMemoryInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeAspect));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImagePlaneMemoryRequirementsInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImagePlaneMemoryRequirementsInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeAspect));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceSamplerYcbcrConversionFeatures* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->samplerYcbcrConversion));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSamplerYcbcrConversionImageFormatProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSamplerYcbcrConversionImageFormatProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->combinedImageSamplerDescriptorCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorUpdateTemplateEntry* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorUpdateTemplateEntry* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstBinding));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstArrayElement));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorCount));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorType));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stride));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorUpdateTemplateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorUpdateEntryCount));
    wrapper->pDescriptorUpdateEntries = std::make_unique<StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateEntry>>();
    bytes_read += wrapper->pDescriptorUpdateEntries->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDescriptorUpdateEntries = wrapper->pDescriptorUpdateEntries->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->templateType));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->descriptorSetLayout));
    value->descriptorSetLayout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pipelineBindPoint));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pipelineLayout));
    value->pipelineLayout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->set));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalMemoryProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalMemoryProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->externalMemoryFeatures));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->exportFromImportedHandleTypes));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->compatibleHandleTypes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalImageFormatInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceExternalImageFormatInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalImageFormatProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalImageFormatProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->externalMemoryProperties = std::make_unique<Decoded_VkExternalMemoryProperties>();
    wrapper->externalMemoryProperties->value = &(value->externalMemoryProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->externalMemoryProperties.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalBufferInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceExternalBufferInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->usage));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalBufferProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalBufferProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->externalMemoryProperties = std::make_unique<Decoded_VkExternalMemoryProperties>();
    wrapper->externalMemoryProperties->value = &(value->externalMemoryProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->externalMemoryProperties.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceIDProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceIDProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->deviceUUID.SetExternalMemory(value->deviceUUID, VK_UUID_SIZE);
    bytes_read += wrapper->deviceUUID.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->driverUUID.SetExternalMemory(value->driverUUID, VK_UUID_SIZE);
    bytes_read += wrapper->driverUUID.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->deviceLUID.SetExternalMemory(value->deviceLUID, VK_LUID_SIZE);
    bytes_read += wrapper->deviceLUID.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceNodeMask));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceLUIDValid));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalMemoryImageCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalMemoryImageCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalMemoryBufferCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalMemoryBufferCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportMemoryAllocateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportMemoryAllocateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalFenceInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceExternalFenceInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalFenceProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalFenceProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->exportFromImportedHandleTypes));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->compatibleHandleTypes));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->externalFenceFeatures));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportFenceCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportFenceCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportSemaphoreCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportSemaphoreCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalSemaphoreInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceExternalSemaphoreInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalSemaphoreProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalSemaphoreProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->exportFromImportedHandleTypes));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->compatibleHandleTypes));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->externalSemaphoreFeatures));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMaintenance3Properties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMaintenance3Properties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerSetDescriptors));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMemoryAllocationSize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutSupport* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetLayoutSupport* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderDrawParametersFeatures* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceShaderDrawParametersFeatures* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderDrawParameters));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceCapabilitiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceCapabilitiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minImageCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageCount));
    wrapper->currentExtent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->currentExtent->value = &(value->currentExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->currentExtent.get());
    wrapper->minImageExtent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->minImageExtent->value = &(value->minImageExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->minImageExtent.get());
    wrapper->maxImageExtent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->maxImageExtent->value = &(value->maxImageExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->maxImageExtent.get());
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageArrayLayers));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedTransforms));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->currentTransform));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedCompositeAlpha));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedUsageFlags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceFormatKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceFormatKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->colorSpace));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSwapchainCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSwapchainCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->surface));
    value->surface = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minImageCount));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageFormat));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageColorSpace));
    wrapper->imageExtent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->imageExtent->value = &(value->imageExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageExtent.get());
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageArrayLayers));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageUsage));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageSharingMode));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFamilyIndexCount));
    bytes_read += wrapper->pQueueFamilyIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pQueueFamilyIndices = wrapper->pQueueFamilyIndices.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->preTransform));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->compositeAlpha));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->presentMode));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->clipped));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->oldSwapchain));
    value->oldSwapchain = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPresentInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPresentInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->waitSemaphoreCount));
    bytes_read += wrapper->pWaitSemaphores.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pWaitSemaphores = wrapper->pWaitSemaphores.GetHandlePointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->swapchainCount));
    bytes_read += wrapper->pSwapchains.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSwapchains = wrapper->pSwapchains.GetHandlePointer();
    bytes_read += wrapper->pImageIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pImageIndices = wrapper->pImageIndices.GetPointer();
    bytes_read += wrapper->pResults.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pResults = wrapper->pResults.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageSwapchainCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageSwapchainCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->swapchain));
    value->swapchain = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindImageMemorySwapchainInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->swapchain));
    value->swapchain = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAcquireNextImageInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAcquireNextImageInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->swapchain));
    value->swapchain = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->timeout));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->semaphore));
    value->semaphore = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->fence));
    value->fence = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupPresentCapabilitiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupPresentCapabilitiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->presentMask.SetExternalMemory(value->presentMask, VK_MAX_DEVICE_GROUP_SIZE);
    bytes_read += wrapper->presentMask.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->modes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupPresentInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupPresentInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->swapchainCount));
    bytes_read += wrapper->pDeviceMasks.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDeviceMasks = wrapper->pDeviceMasks.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->mode));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupSwapchainCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupSwapchainCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->modes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->display));
    value->display = VK_NULL_HANDLE;
    bytes_read += wrapper->displayName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->displayName = wrapper->displayName.GetPointer();
    wrapper->physicalDimensions = std::make_unique<Decoded_VkExtent2D>();
    wrapper->physicalDimensions->value = &(value->physicalDimensions);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->physicalDimensions.get());
    wrapper->physicalResolution = std::make_unique<Decoded_VkExtent2D>();
    wrapper->physicalResolution->value = &(value->physicalResolution);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->physicalResolution.get());
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedTransforms));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeReorderPossible));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->persistentContent));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayModeParametersKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayModeParametersKHR* value = wrapper->value;

    wrapper->visibleRegion = std::make_unique<Decoded_VkExtent2D>();
    wrapper->visibleRegion->value = &(value->visibleRegion);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->visibleRegion.get());
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->refreshRate));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayModePropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayModePropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->displayMode));
    value->displayMode = VK_NULL_HANDLE;
    wrapper->parameters = std::make_unique<Decoded_VkDisplayModeParametersKHR>();
    wrapper->parameters->value = &(value->parameters);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->parameters.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayModeCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayModeCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    wrapper->parameters = std::make_unique<Decoded_VkDisplayModeParametersKHR>();
    wrapper->parameters->value = &(value->parameters);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->parameters.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPlaneCapabilitiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPlaneCapabilitiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedAlpha));
    wrapper->minSrcPosition = std::make_unique<Decoded_VkOffset2D>();
    wrapper->minSrcPosition->value = &(value->minSrcPosition);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->minSrcPosition.get());
    wrapper->maxSrcPosition = std::make_unique<Decoded_VkOffset2D>();
    wrapper->maxSrcPosition->value = &(value->maxSrcPosition);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->maxSrcPosition.get());
    wrapper->minSrcExtent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->minSrcExtent->value = &(value->minSrcExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->minSrcExtent.get());
    wrapper->maxSrcExtent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->maxSrcExtent->value = &(value->maxSrcExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->maxSrcExtent.get());
    wrapper->minDstPosition = std::make_unique<Decoded_VkOffset2D>();
    wrapper->minDstPosition->value = &(value->minDstPosition);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->minDstPosition.get());
    wrapper->maxDstPosition = std::make_unique<Decoded_VkOffset2D>();
    wrapper->maxDstPosition->value = &(value->maxDstPosition);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->maxDstPosition.get());
    wrapper->minDstExtent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->minDstExtent->value = &(value->minDstExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->minDstExtent.get());
    wrapper->maxDstExtent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->maxDstExtent->value = &(value->maxDstExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->maxDstExtent.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPlanePropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPlanePropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->currentDisplay));
    value->currentDisplay = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->currentStackIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplaySurfaceCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->displayMode));
    value->displayMode = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeStackIndex));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->transform));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->globalAlpha));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->alphaMode));
    wrapper->imageExtent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->imageExtent->value = &(value->imageExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageExtent.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPresentInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPresentInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->srcRect = std::make_unique<Decoded_VkRect2D>();
    wrapper->srcRect->value = &(value->srcRect);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->srcRect.get());
    wrapper->dstRect = std::make_unique<Decoded_VkRect2D>();
    wrapper->dstRect->value = &(value->dstRect);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->dstRect.get());
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->persistent));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkXlibSurfaceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkXlibSurfaceCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->dpy));
    value->dpy = nullptr;
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->window));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkXcbSurfaceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkXcbSurfaceCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->connection));
    value->connection = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->window));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkWaylandSurfaceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkWaylandSurfaceCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->display));
    value->display = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->surface));
    value->surface = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAndroidSurfaceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAndroidSurfaceCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->window));
    value->window = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkWin32SurfaceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkWin32SurfaceCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->hinstance));
    value->hinstance = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->hwnd));
    value->hwnd = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportMemoryWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportMemoryWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->handle));
    value->handle = nullptr;
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->name = wrapper->name.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportMemoryWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportMemoryWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->pAttributes = std::make_unique<StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>>();
    bytes_read += wrapper->pAttributes->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttributes = wrapper->pAttributes->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dwAccess));
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->name = wrapper->name.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryWin32HandlePropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryWin32HandlePropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeBits));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryGetWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportMemoryFdInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportMemoryFdInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fd));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryFdPropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryFdPropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeBits));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryGetFdInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryGetFdInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkWin32KeyedMutexAcquireReleaseInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->acquireCount));
    bytes_read += wrapper->pAcquireSyncs.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAcquireSyncs = wrapper->pAcquireSyncs.GetHandlePointer();
    bytes_read += wrapper->pAcquireKeys.DecodeUInt64((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAcquireKeys = wrapper->pAcquireKeys.GetPointer();
    bytes_read += wrapper->pAcquireTimeouts.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAcquireTimeouts = wrapper->pAcquireTimeouts.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->releaseCount));
    bytes_read += wrapper->pReleaseSyncs.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pReleaseSyncs = wrapper->pReleaseSyncs.GetHandlePointer();
    bytes_read += wrapper->pReleaseKeys.DecodeUInt64((buffer + bytes_read), (buffer_size - bytes_read));
    value->pReleaseKeys = wrapper->pReleaseKeys.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportSemaphoreWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->semaphore));
    value->semaphore = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->handle));
    value->handle = nullptr;
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->name = wrapper->name.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportSemaphoreWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportSemaphoreWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->pAttributes = std::make_unique<StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>>();
    bytes_read += wrapper->pAttributes->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttributes = wrapper->pAttributes->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dwAccess));
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->name = wrapper->name.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkD3D12FenceSubmitInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkD3D12FenceSubmitInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->waitSemaphoreValuesCount));
    bytes_read += wrapper->pWaitSemaphoreValues.DecodeUInt64((buffer + bytes_read), (buffer_size - bytes_read));
    value->pWaitSemaphoreValues = wrapper->pWaitSemaphoreValues.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->signalSemaphoreValuesCount));
    bytes_read += wrapper->pSignalSemaphoreValues.DecodeUInt64((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSignalSemaphoreValues = wrapper->pSignalSemaphoreValues.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSemaphoreGetWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->semaphore));
    value->semaphore = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportSemaphoreFdInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportSemaphoreFdInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->semaphore));
    value->semaphore = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fd));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSemaphoreGetFdInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSemaphoreGetFdInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->semaphore));
    value->semaphore = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDevicePushDescriptorPropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPushDescriptors));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFloat16Int8FeaturesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceFloat16Int8FeaturesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderFloat16));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderInt8));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRectLayerKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRectLayerKHR* value = wrapper->value;

    wrapper->offset = std::make_unique<Decoded_VkOffset2D>();
    wrapper->offset->value = &(value->offset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->offset.get());
    wrapper->extent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->extent->value = &(value->extent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->extent.get());
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layer));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPresentRegionKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPresentRegionKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->rectangleCount));
    wrapper->pRectangles = std::make_unique<StructPointerDecoder<Decoded_VkRectLayerKHR>>();
    bytes_read += wrapper->pRectangles->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pRectangles = wrapper->pRectangles->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPresentRegionsKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPresentRegionsKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->swapchainCount));
    wrapper->pRegions = std::make_unique<StructPointerDecoder<Decoded_VkPresentRegionKHR>>();
    bytes_read += wrapper->pRegions->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pRegions = wrapper->pRegions->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAttachmentDescription2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAttachmentDescription2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->samples));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->loadOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->storeOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stencilLoadOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stencilStoreOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->initialLayout));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->finalLayout));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAttachmentReference2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAttachmentReference2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachment));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->layout));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassDescription2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassDescription2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pipelineBindPoint));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->inputAttachmentCount));
    wrapper->pInputAttachments = std::make_unique<StructPointerDecoder<Decoded_VkAttachmentReference2KHR>>();
    bytes_read += wrapper->pInputAttachments->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pInputAttachments = wrapper->pInputAttachments->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->colorAttachmentCount));
    wrapper->pColorAttachments = std::make_unique<StructPointerDecoder<Decoded_VkAttachmentReference2KHR>>();
    bytes_read += wrapper->pColorAttachments->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pColorAttachments = wrapper->pColorAttachments->GetPointer();
    wrapper->pResolveAttachments = std::make_unique<StructPointerDecoder<Decoded_VkAttachmentReference2KHR>>();
    bytes_read += wrapper->pResolveAttachments->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pResolveAttachments = wrapper->pResolveAttachments->GetPointer();
    wrapper->pDepthStencilAttachment = std::make_unique<StructPointerDecoder<Decoded_VkAttachmentReference2KHR>>();
    bytes_read += wrapper->pDepthStencilAttachment->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDepthStencilAttachment = wrapper->pDepthStencilAttachment->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->preserveAttachmentCount));
    bytes_read += wrapper->pPreserveAttachments.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPreserveAttachments = wrapper->pPreserveAttachments.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassDependency2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassDependency2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcSubpass));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstSubpass));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcStageMask));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstStageMask));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcAccessMask));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstAccessMask));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dependencyFlags));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewOffset));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRenderPassCreateInfo2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRenderPassCreateInfo2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachmentCount));
    wrapper->pAttachments = std::make_unique<StructPointerDecoder<Decoded_VkAttachmentDescription2KHR>>();
    bytes_read += wrapper->pAttachments->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttachments = wrapper->pAttachments->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subpassCount));
    wrapper->pSubpasses = std::make_unique<StructPointerDecoder<Decoded_VkSubpassDescription2KHR>>();
    bytes_read += wrapper->pSubpasses->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSubpasses = wrapper->pSubpasses->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dependencyCount));
    wrapper->pDependencies = std::make_unique<StructPointerDecoder<Decoded_VkSubpassDependency2KHR>>();
    bytes_read += wrapper->pDependencies->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDependencies = wrapper->pDependencies->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->correlatedViewMaskCount));
    bytes_read += wrapper->pCorrelatedViewMasks.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCorrelatedViewMasks = wrapper->pCorrelatedViewMasks.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassBeginInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassBeginInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->contents));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassEndInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassEndInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSharedPresentSurfaceCapabilitiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSharedPresentSurfaceCapabilitiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sharedPresentSupportedUsageFlags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportFenceWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportFenceWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->fence));
    value->fence = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->handle));
    value->handle = nullptr;
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->name = wrapper->name.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportFenceWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportFenceWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->pAttributes = std::make_unique<StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>>();
    bytes_read += wrapper->pAttributes->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttributes = wrapper->pAttributes->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dwAccess));
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->name = wrapper->name.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFenceGetWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFenceGetWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->fence));
    value->fence = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportFenceFdInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportFenceFdInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->fence));
    value->fence = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fd));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFenceGetFdInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFenceGetFdInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->fence));
    value->fence = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceSurfaceInfo2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->surface));
    value->surface = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceCapabilities2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceCapabilities2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->surfaceCapabilities = std::make_unique<Decoded_VkSurfaceCapabilitiesKHR>();
    wrapper->surfaceCapabilities->value = &(value->surfaceCapabilities);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->surfaceCapabilities.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceFormat2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceFormat2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->surfaceFormat = std::make_unique<Decoded_VkSurfaceFormatKHR>();
    wrapper->surfaceFormat->value = &(value->surfaceFormat);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->surfaceFormat.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayProperties2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayProperties2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->displayProperties = std::make_unique<Decoded_VkDisplayPropertiesKHR>();
    wrapper->displayProperties->value = &(value->displayProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->displayProperties.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPlaneProperties2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPlaneProperties2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->displayPlaneProperties = std::make_unique<Decoded_VkDisplayPlanePropertiesKHR>();
    wrapper->displayPlaneProperties->value = &(value->displayPlaneProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->displayPlaneProperties.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayModeProperties2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayModeProperties2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->displayModeProperties = std::make_unique<Decoded_VkDisplayModePropertiesKHR>();
    wrapper->displayModeProperties->value = &(value->displayModeProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->displayModeProperties.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPlaneInfo2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPlaneInfo2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->mode));
    value->mode = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPlaneCapabilities2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPlaneCapabilities2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->capabilities = std::make_unique<Decoded_VkDisplayPlaneCapabilitiesKHR>();
    wrapper->capabilities->value = &(value->capabilities);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->capabilities.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageFormatListCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageFormatListCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewFormatCount));
    bytes_read += wrapper->pViewFormats.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pViewFormats = wrapper->pViewFormats.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDevice8BitStorageFeaturesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDevice8BitStorageFeaturesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->storageBuffer8BitAccess));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->uniformAndStorageBuffer8BitAccess));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->storagePushConstant8));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderAtomicInt64FeaturesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceShaderAtomicInt64FeaturesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderBufferInt64Atomics));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderSharedInt64Atomics));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkConformanceVersionKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkConformanceVersionKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->major));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minor));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subminor));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->patch));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDriverPropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceDriverPropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->driverID));
    wrapper->driverName.SetExternalMemory(value->driverName, VK_MAX_DRIVER_NAME_SIZE_KHR);
    bytes_read += wrapper->driverName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->driverInfo.SetExternalMemory(value->driverInfo, VK_MAX_DRIVER_INFO_SIZE_KHR);
    bytes_read += wrapper->driverInfo.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->conformanceVersion = std::make_unique<Decoded_VkConformanceVersionKHR>();
    wrapper->conformanceVersion->value = &(value->conformanceVersion);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->conformanceVersion.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFloatControlsPropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceFloatControlsPropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->separateDenormSettings));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->separateRoundingModeSettings));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderSignedZeroInfNanPreserveFloat16));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderSignedZeroInfNanPreserveFloat32));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderSignedZeroInfNanPreserveFloat64));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderDenormPreserveFloat16));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderDenormPreserveFloat32));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderDenormPreserveFloat64));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderDenormFlushToZeroFloat16));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderDenormFlushToZeroFloat32));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderDenormFlushToZeroFloat64));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderRoundingModeRTEFloat16));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderRoundingModeRTEFloat32));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderRoundingModeRTEFloat64));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderRoundingModeRTZFloat16));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderRoundingModeRTZFloat32));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderRoundingModeRTZFloat64));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassDescriptionDepthStencilResolveKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassDescriptionDepthStencilResolveKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthResolveMode));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stencilResolveMode));
    wrapper->pDepthStencilResolveAttachment = std::make_unique<StructPointerDecoder<Decoded_VkAttachmentReference2KHR>>();
    bytes_read += wrapper->pDepthStencilResolveAttachment->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDepthStencilResolveAttachment = wrapper->pDepthStencilResolveAttachment->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDepthStencilResolvePropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceDepthStencilResolvePropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedDepthResolveModes));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedStencilResolveModes));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->independentResolveNone));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->independentResolve));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVulkanMemoryModelFeaturesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceVulkanMemoryModelFeaturesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vulkanMemoryModel));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vulkanMemoryModelDeviceScope));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vulkanMemoryModelAvailabilityVisibilityChains));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceProtectedCapabilitiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceProtectedCapabilitiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsProtected));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->uniformBufferStandardLayout));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugReportCallbackCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugReportCallbackCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pfnCallback));
    value->pfnCallback = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pUserData));
    value->pUserData = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineRasterizationStateRasterizationOrderAMD* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineRasterizationStateRasterizationOrderAMD* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->rasterizationOrder));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugMarkerObjectNameInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugMarkerObjectNameInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectType));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->object));
    bytes_read += wrapper->pObjectName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pObjectName = wrapper->pObjectName.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugMarkerObjectTagInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugMarkerObjectTagInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectType));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->object));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->tagName));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->tagSize));
    bytes_read += wrapper->pTag.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTag = wrapper->pTag.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugMarkerMarkerInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugMarkerMarkerInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += wrapper->pMarkerName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pMarkerName = wrapper->pMarkerName.GetPointer();
    wrapper->color.SetExternalMemory(value->color, 4);
    bytes_read += wrapper->color.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDedicatedAllocationImageCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDedicatedAllocationImageCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dedicatedAllocation));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDedicatedAllocationBufferCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDedicatedAllocationBufferCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dedicatedAllocation));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDedicatedAllocationMemoryAllocateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceTransformFeedbackFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->transformFeedback));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->geometryStreams));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceTransformFeedbackPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTransformFeedbackStreams));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTransformFeedbackBuffers));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTransformFeedbackBufferSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTransformFeedbackStreamDataSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTransformFeedbackBufferDataSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTransformFeedbackBufferDataStride));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->transformFeedbackQueries));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->transformFeedbackStreamsLinesTriangles));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->transformFeedbackRasterizationStreamSelect));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->transformFeedbackDraw));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineRasterizationStateStreamCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->rasterizationStream));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageViewHandleInfoNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageViewHandleInfoNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->imageView));
    value->imageView = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorType));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->sampler));
    value->sampler = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkTextureLODGatherFormatPropertiesAMD* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkTextureLODGatherFormatPropertiesAMD* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsTextureGatherLODBiasAMD));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkShaderResourceUsageAMD* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkShaderResourceUsageAMD* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->numUsedVgprs));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->numUsedSgprs));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ldsSizePerLocalWorkGroup));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ldsUsageSizeInBytes));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->scratchMemUsageInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkShaderStatisticsInfoAMD* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkShaderStatisticsInfoAMD* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStageMask));
    wrapper->resourceUsage = std::make_unique<Decoded_VkShaderResourceUsageAMD>();
    wrapper->resourceUsage->value = &(value->resourceUsage);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->resourceUsage.get());
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->numPhysicalVgprs));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->numPhysicalSgprs));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->numAvailableVgprs));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->numAvailableSgprs));
    wrapper->computeWorkGroupSize.SetExternalMemory(value->computeWorkGroupSize, 3);
    bytes_read += wrapper->computeWorkGroupSize.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkStreamDescriptorSurfaceCreateInfoGGP* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkStreamDescriptorSurfaceCreateInfoGGP* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->streamDescriptor));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceCornerSampledImageFeaturesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->cornerSampledImage));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalImageFormatPropertiesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalImageFormatPropertiesNV* value = wrapper->value;

    wrapper->imageFormatProperties = std::make_unique<Decoded_VkImageFormatProperties>();
    wrapper->imageFormatProperties->value = &(value->imageFormatProperties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageFormatProperties.get());
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->externalMemoryFeatures));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->exportFromImportedHandleTypes));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->compatibleHandleTypes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalMemoryImageCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalMemoryImageCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportMemoryAllocateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportMemoryAllocateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportMemoryWin32HandleInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportMemoryWin32HandleInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->handle));
    value->handle = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportMemoryWin32HandleInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportMemoryWin32HandleInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->pAttributes = std::make_unique<StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>>();
    bytes_read += wrapper->pAttributes->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttributes = wrapper->pAttributes->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dwAccess));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkWin32KeyedMutexAcquireReleaseInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->acquireCount));
    bytes_read += wrapper->pAcquireSyncs.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAcquireSyncs = wrapper->pAcquireSyncs.GetHandlePointer();
    bytes_read += wrapper->pAcquireKeys.DecodeUInt64((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAcquireKeys = wrapper->pAcquireKeys.GetPointer();
    bytes_read += wrapper->pAcquireTimeoutMilliseconds.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAcquireTimeoutMilliseconds = wrapper->pAcquireTimeoutMilliseconds.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->releaseCount));
    bytes_read += wrapper->pReleaseSyncs.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pReleaseSyncs = wrapper->pReleaseSyncs.GetHandlePointer();
    bytes_read += wrapper->pReleaseKeys.DecodeUInt64((buffer + bytes_read), (buffer_size - bytes_read));
    value->pReleaseKeys = wrapper->pReleaseKeys.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkValidationFlagsEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkValidationFlagsEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->disabledValidationCheckCount));
    bytes_read += wrapper->pDisabledValidationChecks.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDisabledValidationChecks = wrapper->pDisabledValidationChecks.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkViSurfaceCreateInfoNN* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkViSurfaceCreateInfoNN* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->window));
    value->window = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageViewASTCDecodeModeEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageViewASTCDecodeModeEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->decodeMode));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceASTCDecodeFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->decodeModeSharedExponent));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkConditionalRenderingBeginInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkConditionalRenderingBeginInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceConditionalRenderingFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->conditionalRendering));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->inheritedConditionalRendering));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCommandBufferInheritanceConditionalRenderingInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->conditionalRenderingEnable));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGeneratedCommandsFeaturesNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGeneratedCommandsFeaturesNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->computeBindingPointSupport));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGeneratedCommandsLimitsNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGeneratedCommandsLimitsNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxIndirectCommandsLayoutTokenCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxObjectEntryCounts));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minSequenceCountBufferOffsetAlignment));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minSequenceIndexBufferOffsetAlignment));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minCommandsTokenBufferOffsetAlignment));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkIndirectCommandsTokenNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkIndirectCommandsTokenNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->tokenType));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkIndirectCommandsLayoutTokenNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkIndirectCommandsLayoutTokenNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->tokenType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bindingUnit));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dynamicCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->divisor));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkIndirectCommandsLayoutCreateInfoNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkIndirectCommandsLayoutCreateInfoNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pipelineBindPoint));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->tokenCount));
    wrapper->pTokens = std::make_unique<StructPointerDecoder<Decoded_VkIndirectCommandsLayoutTokenNVX>>();
    bytes_read += wrapper->pTokens->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTokens = wrapper->pTokens->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCmdProcessCommandsInfoNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCmdProcessCommandsInfoNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->objectTable));
    value->objectTable = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->indirectCommandsLayout));
    value->indirectCommandsLayout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indirectCommandsTokenCount));
    wrapper->pIndirectCommandsTokens = std::make_unique<StructPointerDecoder<Decoded_VkIndirectCommandsTokenNVX>>();
    bytes_read += wrapper->pIndirectCommandsTokens->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pIndirectCommandsTokens = wrapper->pIndirectCommandsTokens->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSequencesCount));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->targetCommandBuffer));
    value->targetCommandBuffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->sequencesCountBuffer));
    value->sequencesCountBuffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sequencesCountOffset));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->sequencesIndexBuffer));
    value->sequencesIndexBuffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sequencesIndexOffset));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCmdReserveSpaceForCommandsInfoNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCmdReserveSpaceForCommandsInfoNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->objectTable));
    value->objectTable = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->indirectCommandsLayout));
    value->indirectCommandsLayout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSequencesCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkObjectTableCreateInfoNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkObjectTableCreateInfoNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectCount));
    bytes_read += wrapper->pObjectEntryTypes.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pObjectEntryTypes = wrapper->pObjectEntryTypes.GetPointer();
    bytes_read += wrapper->pObjectEntryCounts.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pObjectEntryCounts = wrapper->pObjectEntryCounts.GetPointer();
    bytes_read += wrapper->pObjectEntryUsageFlags.DecodeFlags((buffer + bytes_read), (buffer_size - bytes_read));
    value->pObjectEntryUsageFlags = wrapper->pObjectEntryUsageFlags.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxUniformBuffersPerDescriptor));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxStorageBuffersPerDescriptor));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxStorageImagesPerDescriptor));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSampledImagesPerDescriptor));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPipelineLayouts));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkObjectTablePipelineEntryNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkObjectTablePipelineEntryNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pipeline));
    value->pipeline = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkObjectTableDescriptorSetEntryNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkObjectTableDescriptorSetEntryNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pipelineLayout));
    value->pipelineLayout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->descriptorSet));
    value->descriptorSet = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkObjectTableVertexBufferEntryNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkObjectTableVertexBufferEntryNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkObjectTableIndexBufferEntryNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkObjectTableIndexBufferEntryNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkObjectTablePushConstantEntryNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkObjectTablePushConstantEntryNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pipelineLayout));
    value->pipelineLayout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stageFlags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkViewportWScalingNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkViewportWScalingNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->xcoeff));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ycoeff));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineViewportWScalingStateCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineViewportWScalingStateCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewportWScalingEnable));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewportCount));
    wrapper->pViewportWScalings = std::make_unique<StructPointerDecoder<Decoded_VkViewportWScalingNV>>();
    bytes_read += wrapper->pViewportWScalings->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pViewportWScalings = wrapper->pViewportWScalings->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceCapabilities2EXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceCapabilities2EXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minImageCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageCount));
    wrapper->currentExtent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->currentExtent->value = &(value->currentExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->currentExtent.get());
    wrapper->minImageExtent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->minImageExtent->value = &(value->minImageExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->minImageExtent.get());
    wrapper->maxImageExtent = std::make_unique<Decoded_VkExtent2D>();
    wrapper->maxImageExtent->value = &(value->maxImageExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->maxImageExtent.get());
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageArrayLayers));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedTransforms));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->currentTransform));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedCompositeAlpha));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedUsageFlags));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedSurfaceCounters));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPowerInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPowerInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->powerState));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceEventInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceEventInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceEvent));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayEventInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayEventInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->displayEvent));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSwapchainCounterCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSwapchainCounterCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->surfaceCounters));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRefreshCycleDurationGOOGLE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRefreshCycleDurationGOOGLE* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->refreshDuration));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPastPresentationTimingGOOGLE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPastPresentationTimingGOOGLE* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->presentID));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->desiredPresentTime));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->actualPresentTime));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->earliestPresentTime));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->presentMargin));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPresentTimeGOOGLE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPresentTimeGOOGLE* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->presentID));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->desiredPresentTime));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPresentTimesInfoGOOGLE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPresentTimesInfoGOOGLE* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->swapchainCount));
    wrapper->pTimes = std::make_unique<StructPointerDecoder<Decoded_VkPresentTimeGOOGLE>>();
    bytes_read += wrapper->pTimes->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTimes = wrapper->pTimes->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->perViewPositionAllComponents));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkViewportSwizzleNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkViewportSwizzleNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->z));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->w));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineViewportSwizzleStateCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineViewportSwizzleStateCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewportCount));
    wrapper->pViewportSwizzles = std::make_unique<StructPointerDecoder<Decoded_VkViewportSwizzleNV>>();
    bytes_read += wrapper->pViewportSwizzles->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pViewportSwizzles = wrapper->pViewportSwizzles->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceDiscardRectanglePropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDiscardRectangles));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineDiscardRectangleStateCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->discardRectangleMode));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->discardRectangleCount));
    wrapper->pDiscardRectangles = std::make_unique<StructPointerDecoder<Decoded_VkRect2D>>();
    bytes_read += wrapper->pDiscardRectangles->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDiscardRectangles = wrapper->pDiscardRectangles->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceConservativeRasterizationPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->primitiveOverestimationSize));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxExtraPrimitiveOverestimationSize));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->extraPrimitiveOverestimationSizeGranularity));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->primitiveUnderestimation));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->conservativePointAndLineRasterization));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->degenerateTrianglesRasterized));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->degenerateLinesRasterized));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fullyCoveredFragmentShaderInputVariable));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->conservativeRasterizationPostDepthCoverage));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineRasterizationConservativeStateCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->conservativeRasterizationMode));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->extraPrimitiveOverestimationSize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceDepthClipEnableFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthClipEnable));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineRasterizationDepthClipStateCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthClipEnable));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkXYColorEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkXYColorEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkHdrMetadataEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkHdrMetadataEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->displayPrimaryRed = std::make_unique<Decoded_VkXYColorEXT>();
    wrapper->displayPrimaryRed->value = &(value->displayPrimaryRed);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->displayPrimaryRed.get());
    wrapper->displayPrimaryGreen = std::make_unique<Decoded_VkXYColorEXT>();
    wrapper->displayPrimaryGreen->value = &(value->displayPrimaryGreen);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->displayPrimaryGreen.get());
    wrapper->displayPrimaryBlue = std::make_unique<Decoded_VkXYColorEXT>();
    wrapper->displayPrimaryBlue->value = &(value->displayPrimaryBlue);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->displayPrimaryBlue.get());
    wrapper->whitePoint = std::make_unique<Decoded_VkXYColorEXT>();
    wrapper->whitePoint->value = &(value->whitePoint);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->whitePoint.get());
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxLuminance));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minLuminance));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxContentLightLevel));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxFrameAverageLightLevel));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkIOSSurfaceCreateInfoMVK* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkIOSSurfaceCreateInfoMVK* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pView));
    value->pView = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMacOSSurfaceCreateInfoMVK* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMacOSSurfaceCreateInfoMVK* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pView));
    value->pView = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugUtilsObjectNameInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugUtilsObjectNameInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectType));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectHandle));
    bytes_read += wrapper->pObjectName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pObjectName = wrapper->pObjectName.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugUtilsObjectTagInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugUtilsObjectTagInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectType));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectHandle));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->tagName));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->tagSize));
    bytes_read += wrapper->pTag.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTag = wrapper->pTag.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugUtilsLabelEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugUtilsLabelEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += wrapper->pLabelName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pLabelName = wrapper->pLabelName.GetPointer();
    wrapper->color.SetExternalMemory(value->color, 4);
    bytes_read += wrapper->color.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugUtilsMessengerCallbackDataEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugUtilsMessengerCallbackDataEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += wrapper->pMessageIdName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pMessageIdName = wrapper->pMessageIdName.GetPointer();
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->messageIdNumber));
    bytes_read += wrapper->pMessage.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pMessage = wrapper->pMessage.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueLabelCount));
    wrapper->pQueueLabels = std::make_unique<StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>>();
    bytes_read += wrapper->pQueueLabels->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pQueueLabels = wrapper->pQueueLabels->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->cmdBufLabelCount));
    wrapper->pCmdBufLabels = std::make_unique<StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>>();
    bytes_read += wrapper->pCmdBufLabels->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCmdBufLabels = wrapper->pCmdBufLabels->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectCount));
    wrapper->pObjects = std::make_unique<StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>>();
    bytes_read += wrapper->pObjects->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pObjects = wrapper->pObjects->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugUtilsMessengerCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugUtilsMessengerCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->messageSeverity));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->messageType));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pfnUserCallback));
    value->pfnUserCallback = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pUserData));
    value->pUserData = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferUsageANDROID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAndroidHardwareBufferUsageANDROID* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->androidHardwareBufferUsage));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferPropertiesANDROID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAndroidHardwareBufferPropertiesANDROID* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->allocationSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeBits));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAndroidHardwareBufferFormatPropertiesANDROID* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->externalFormat));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->formatFeatures));
    wrapper->samplerYcbcrConversionComponents = std::make_unique<Decoded_VkComponentMapping>();
    wrapper->samplerYcbcrConversionComponents->value = &(value->samplerYcbcrConversionComponents);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->samplerYcbcrConversionComponents.get());
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->suggestedYcbcrModel));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->suggestedYcbcrRange));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->suggestedXChromaOffset));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->suggestedYChromaOffset));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportAndroidHardwareBufferInfoANDROID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportAndroidHardwareBufferInfoANDROID* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryGetAndroidHardwareBufferInfoANDROID* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalFormatANDROID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalFormatANDROID* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->externalFormat));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSamplerReductionModeCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSamplerReductionModeCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->reductionMode));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->filterMinmaxSingleComponentFormats));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->filterMinmaxImageComponentMapping));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceInlineUniformBlockFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceInlineUniformBlockFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->inlineUniformBlock));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorBindingInlineUniformBlockUpdateAfterBind));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceInlineUniformBlockPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceInlineUniformBlockPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxInlineUniformBlockSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorInlineUniformBlocks));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetInlineUniformBlocks));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetUpdateAfterBindInlineUniformBlocks));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkWriteDescriptorSetInlineUniformBlockEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkWriteDescriptorSetInlineUniformBlockEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dataSize));
    bytes_read += wrapper->pData.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pData = wrapper->pData.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorPoolInlineUniformBlockCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorPoolInlineUniformBlockCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxInlineUniformBlockBindings));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSampleLocationEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSampleLocationEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSampleLocationsInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSampleLocationsInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleLocationsPerPixel));
    wrapper->sampleLocationGridSize = std::make_unique<Decoded_VkExtent2D>();
    wrapper->sampleLocationGridSize->value = &(value->sampleLocationGridSize);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->sampleLocationGridSize.get());
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleLocationsCount));
    wrapper->pSampleLocations = std::make_unique<StructPointerDecoder<Decoded_VkSampleLocationEXT>>();
    bytes_read += wrapper->pSampleLocations->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSampleLocations = wrapper->pSampleLocations->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAttachmentSampleLocationsEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAttachmentSampleLocationsEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachmentIndex));
    wrapper->sampleLocationsInfo = std::make_unique<Decoded_VkSampleLocationsInfoEXT>();
    wrapper->sampleLocationsInfo->value = &(value->sampleLocationsInfo);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->sampleLocationsInfo.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassSampleLocationsEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassSampleLocationsEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subpassIndex));
    wrapper->sampleLocationsInfo = std::make_unique<Decoded_VkSampleLocationsInfoEXT>();
    wrapper->sampleLocationsInfo->value = &(value->sampleLocationsInfo);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->sampleLocationsInfo.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRenderPassSampleLocationsBeginInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRenderPassSampleLocationsBeginInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachmentInitialSampleLocationsCount));
    wrapper->pAttachmentInitialSampleLocations = std::make_unique<StructPointerDecoder<Decoded_VkAttachmentSampleLocationsEXT>>();
    bytes_read += wrapper->pAttachmentInitialSampleLocations->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttachmentInitialSampleLocations = wrapper->pAttachmentInitialSampleLocations->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->postSubpassSampleLocationsCount));
    wrapper->pPostSubpassSampleLocations = std::make_unique<StructPointerDecoder<Decoded_VkSubpassSampleLocationsEXT>>();
    bytes_read += wrapper->pPostSubpassSampleLocations->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPostSubpassSampleLocations = wrapper->pPostSubpassSampleLocations->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineSampleLocationsStateCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineSampleLocationsStateCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleLocationsEnable));
    wrapper->sampleLocationsInfo = std::make_unique<Decoded_VkSampleLocationsInfoEXT>();
    wrapper->sampleLocationsInfo->value = &(value->sampleLocationsInfo);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->sampleLocationsInfo.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceSampleLocationsPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleLocationSampleCounts));
    wrapper->maxSampleLocationGridSize = std::make_unique<Decoded_VkExtent2D>();
    wrapper->maxSampleLocationGridSize->value = &(value->maxSampleLocationGridSize);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->maxSampleLocationGridSize.get());
    wrapper->sampleLocationCoordinateRange.SetExternalMemory(value->sampleLocationCoordinateRange, 2);
    bytes_read += wrapper->sampleLocationCoordinateRange.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleLocationSubPixelBits));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->variableSampleLocations));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMultisamplePropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMultisamplePropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->maxSampleLocationGridSize = std::make_unique<Decoded_VkExtent2D>();
    wrapper->maxSampleLocationGridSize->value = &(value->maxSampleLocationGridSize);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->maxSampleLocationGridSize.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendCoherentOperations));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendMaxColorAttachments));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendIndependentBlend));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendNonPremultipliedSrcColor));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendNonPremultipliedDstColor));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendCorrelatedOverlap));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendAllOperations));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineColorBlendAdvancedStateCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcPremultiplied));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstPremultiplied));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->blendOverlap));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineCoverageToColorStateCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineCoverageToColorStateCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->coverageToColorEnable));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->coverageToColorLocation));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineCoverageModulationStateCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineCoverageModulationStateCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->coverageModulationMode));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->coverageModulationTableEnable));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->coverageModulationTableCount));
    bytes_read += wrapper->pCoverageModulationTable.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCoverageModulationTable = wrapper->pCoverageModulationTable.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDrmFormatModifierPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDrmFormatModifierPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->drmFormatModifier));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->drmFormatModifierPlaneCount));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->drmFormatModifierTilingFeatures));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDrmFormatModifierPropertiesListEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDrmFormatModifierPropertiesListEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->drmFormatModifierCount));
    wrapper->pDrmFormatModifierProperties = std::make_unique<StructPointerDecoder<Decoded_VkDrmFormatModifierPropertiesEXT>>();
    bytes_read += wrapper->pDrmFormatModifierProperties->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDrmFormatModifierProperties = wrapper->pDrmFormatModifierProperties->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceImageDrmFormatModifierInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->drmFormatModifier));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sharingMode));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFamilyIndexCount));
    bytes_read += wrapper->pQueueFamilyIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pQueueFamilyIndices = wrapper->pQueueFamilyIndices.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageDrmFormatModifierListCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageDrmFormatModifierListCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->drmFormatModifierCount));
    bytes_read += wrapper->pDrmFormatModifiers.DecodeUInt64((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDrmFormatModifiers = wrapper->pDrmFormatModifiers.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageDrmFormatModifierExplicitCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->drmFormatModifier));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->drmFormatModifierPlaneCount));
    wrapper->pPlaneLayouts = std::make_unique<StructPointerDecoder<Decoded_VkSubresourceLayout>>();
    bytes_read += wrapper->pPlaneLayouts->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPlaneLayouts = wrapper->pPlaneLayouts->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageDrmFormatModifierPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageDrmFormatModifierPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->drmFormatModifier));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkValidationCacheCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkValidationCacheCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->initialDataSize));
    bytes_read += wrapper->pInitialData.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pInitialData = wrapper->pInitialData.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkShaderModuleValidationCacheCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->validationCache));
    value->validationCache = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetLayoutBindingFlagsCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bindingCount));
    bytes_read += wrapper->pBindingFlags.DecodeFlags((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBindingFlags = wrapper->pBindingFlags.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDescriptorIndexingFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceDescriptorIndexingFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderInputAttachmentArrayDynamicIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderUniformTexelBufferArrayDynamicIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStorageTexelBufferArrayDynamicIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderUniformBufferArrayNonUniformIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderSampledImageArrayNonUniformIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStorageBufferArrayNonUniformIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStorageImageArrayNonUniformIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderInputAttachmentArrayNonUniformIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderUniformTexelBufferArrayNonUniformIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStorageTexelBufferArrayNonUniformIndexing));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorBindingUniformBufferUpdateAfterBind));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorBindingSampledImageUpdateAfterBind));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorBindingStorageImageUpdateAfterBind));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorBindingStorageBufferUpdateAfterBind));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorBindingUniformTexelBufferUpdateAfterBind));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorBindingStorageTexelBufferUpdateAfterBind));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorBindingUpdateUnusedWhilePending));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorBindingPartiallyBound));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorBindingVariableDescriptorCount));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->runtimeDescriptorArray));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDescriptorIndexingPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceDescriptorIndexingPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxUpdateAfterBindDescriptorsInAllPools));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderUniformBufferArrayNonUniformIndexingNative));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderSampledImageArrayNonUniformIndexingNative));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStorageBufferArrayNonUniformIndexingNative));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStorageImageArrayNonUniformIndexingNative));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderInputAttachmentArrayNonUniformIndexingNative));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->robustBufferAccessUpdateAfterBind));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->quadDivergentImplicitLod));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorUpdateAfterBindSamplers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorUpdateAfterBindUniformBuffers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorUpdateAfterBindStorageBuffers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorUpdateAfterBindSampledImages));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorUpdateAfterBindStorageImages));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageDescriptorUpdateAfterBindInputAttachments));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerStageUpdateAfterBindResources));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetUpdateAfterBindSamplers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetUpdateAfterBindUniformBuffers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetUpdateAfterBindStorageBuffers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetUpdateAfterBindSampledImages));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetUpdateAfterBindStorageImages));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetUpdateAfterBindInputAttachments));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetVariableDescriptorCountAllocateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorSetCount));
    bytes_read += wrapper->pDescriptorCounts.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDescriptorCounts = wrapper->pDescriptorCounts.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupportEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetVariableDescriptorCountLayoutSupportEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxVariableDescriptorCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkShadingRatePaletteNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkShadingRatePaletteNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shadingRatePaletteEntryCount));
    bytes_read += wrapper->pShadingRatePaletteEntries.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pShadingRatePaletteEntries = wrapper->pShadingRatePaletteEntries.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineViewportShadingRateImageStateCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shadingRateImageEnable));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewportCount));
    wrapper->pShadingRatePalettes = std::make_unique<StructPointerDecoder<Decoded_VkShadingRatePaletteNV>>();
    bytes_read += wrapper->pShadingRatePalettes->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pShadingRatePalettes = wrapper->pShadingRatePalettes->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceShadingRateImageFeaturesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shadingRateImage));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shadingRateCoarseSampleOrder));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceShadingRateImagePropertiesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->shadingRateTexelSize = std::make_unique<Decoded_VkExtent2D>();
    wrapper->shadingRateTexelSize->value = &(value->shadingRateTexelSize);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->shadingRateTexelSize.get());
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shadingRatePaletteSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shadingRateMaxCoarseSamples));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCoarseSampleLocationNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCoarseSampleLocationNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->pixelX));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->pixelY));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sample));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCoarseSampleOrderCustomNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCoarseSampleOrderCustomNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->shadingRate));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleLocationCount));
    wrapper->pSampleLocations = std::make_unique<StructPointerDecoder<Decoded_VkCoarseSampleLocationNV>>();
    bytes_read += wrapper->pSampleLocations->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSampleLocations = wrapper->pSampleLocations->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleOrderType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->customSampleOrderCount));
    wrapper->pCustomSampleOrders = std::make_unique<StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>>();
    bytes_read += wrapper->pCustomSampleOrders->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCustomSampleOrders = wrapper->pCustomSampleOrders->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRayTracingShaderGroupCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRayTracingShaderGroupCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->generalShader));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->closestHitShader));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->anyHitShader));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->intersectionShader));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRayTracingPipelineCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRayTracingPipelineCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->stageCount));
    wrapper->pStages = std::make_unique<StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo>>();
    bytes_read += wrapper->pStages->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pStages = wrapper->pStages->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->groupCount));
    wrapper->pGroups = std::make_unique<StructPointerDecoder<Decoded_VkRayTracingShaderGroupCreateInfoNV>>();
    bytes_read += wrapper->pGroups->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pGroups = wrapper->pGroups->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxRecursionDepth));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->layout));
    value->layout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->basePipelineHandle));
    value->basePipelineHandle = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->basePipelineIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkGeometryTrianglesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkGeometryTrianglesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->vertexData));
    value->vertexData = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexOffset));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexCount));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexStride));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexFormat));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->indexData));
    value->indexData = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexOffset));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexCount));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->indexType));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->transformData));
    value->transformData = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->transformOffset));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkGeometryAABBNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkGeometryAABBNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->aabbData));
    value->aabbData = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->numAABBs));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->stride));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkGeometryDataNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkGeometryDataNV* value = wrapper->value;

    wrapper->triangles = std::make_unique<Decoded_VkGeometryTrianglesNV>();
    wrapper->triangles->value = &(value->triangles);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->triangles.get());
    wrapper->aabbs = std::make_unique<Decoded_VkGeometryAABBNV>();
    wrapper->aabbs->value = &(value->aabbs);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->aabbs.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkGeometryNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkGeometryNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->geometryType));
    wrapper->geometry = std::make_unique<Decoded_VkGeometryDataNV>();
    wrapper->geometry->value = &(value->geometry);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->geometry.get());
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAccelerationStructureInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAccelerationStructureInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->instanceCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->geometryCount));
    wrapper->pGeometries = std::make_unique<StructPointerDecoder<Decoded_VkGeometryNV>>();
    bytes_read += wrapper->pGeometries->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pGeometries = wrapper->pGeometries->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAccelerationStructureCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAccelerationStructureCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->compactedSize));
    wrapper->info = std::make_unique<Decoded_VkAccelerationStructureInfoNV>();
    wrapper->info->value = &(value->info);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->info.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindAccelerationStructureMemoryInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindAccelerationStructureMemoryInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->accelerationStructure));
    value->accelerationStructure = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryOffset));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceIndexCount));
    bytes_read += wrapper->pDeviceIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDeviceIndices = wrapper->pDeviceIndices.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkWriteDescriptorSetAccelerationStructureNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkWriteDescriptorSetAccelerationStructureNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->accelerationStructureCount));
    bytes_read += wrapper->pAccelerationStructures.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAccelerationStructures = wrapper->pAccelerationStructures.GetHandlePointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAccelerationStructureMemoryRequirementsInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->accelerationStructure));
    value->accelerationStructure = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRayTracingPropertiesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceRayTracingPropertiesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderGroupHandleSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxRecursionDepth));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxShaderGroupStride));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderGroupBaseAlignment));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxGeometryCount));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxInstanceCount));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTriangleCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDescriptorSetAccelerationStructures));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->representativeFragmentTest));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineRepresentativeFragmentTestStateCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->representativeFragmentTestEnable));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceImageViewImageFormatInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageViewType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFilterCubicImageViewImageFormatPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->filterCubic));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->filterCubicMinmax));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceQueueGlobalPriorityCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceQueueGlobalPriorityCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->globalPriority));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportMemoryHostPointerInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportMemoryHostPointerInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pHostPointer));
    value->pHostPointer = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryHostPointerPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryHostPointerPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeBits));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceExternalMemoryHostPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minImportedHostPointerAlignment));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCalibratedTimestampInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCalibratedTimestampInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->timeDomain));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderCorePropertiesAMD* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceShaderCorePropertiesAMD* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderEngineCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderArraysPerEngineCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->computeUnitsPerShaderArray));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->simdPerComputeUnit));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->wavefrontsPerSimd));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->wavefrontSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sgprsPerSimd));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minSgprAllocation));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSgprAllocation));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sgprAllocationGranularity));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vgprsPerSimd));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minVgprAllocation));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxVgprAllocation));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vgprAllocationGranularity));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceMemoryOverallocationCreateInfoAMD* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceMemoryOverallocationCreateInfoAMD* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->overallocationBehavior));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxVertexAttribDivisor));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkVertexInputBindingDivisorDescriptionEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkVertexInputBindingDivisorDescriptionEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->binding));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->divisor));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineVertexInputDivisorStateCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexBindingDivisorCount));
    wrapper->pVertexBindingDivisors = std::make_unique<StructPointerDecoder<Decoded_VkVertexInputBindingDivisorDescriptionEXT>>();
    bytes_read += wrapper->pVertexBindingDivisors->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pVertexBindingDivisors = wrapper->pVertexBindingDivisors->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexAttributeInstanceRateDivisor));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexAttributeInstanceRateZeroDivisor));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPresentFrameTokenGGP* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPresentFrameTokenGGP* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->frameToken));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineCreationFeedbackEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineCreationFeedbackEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->duration));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineCreationFeedbackCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineCreationFeedbackCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->pPipelineCreationFeedback = std::make_unique<StructPointerDecoder<Decoded_VkPipelineCreationFeedbackEXT>>();
    bytes_read += wrapper->pPipelineCreationFeedback->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPipelineCreationFeedback = wrapper->pPipelineCreationFeedback->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->pipelineStageCreationFeedbackCount));
    wrapper->pPipelineStageCreationFeedbacks = std::make_unique<StructPointerDecoder<Decoded_VkPipelineCreationFeedbackEXT>>();
    bytes_read += wrapper->pPipelineStageCreationFeedbacks->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPipelineStageCreationFeedbacks = wrapper->pPipelineStageCreationFeedbacks->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->computeDerivativeGroupQuads));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->computeDerivativeGroupLinear));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMeshShaderFeaturesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMeshShaderFeaturesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->taskShader));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->meshShader));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMeshShaderPropertiesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMeshShaderPropertiesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDrawMeshTasksCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTaskWorkGroupInvocations));
    wrapper->maxTaskWorkGroupSize.SetExternalMemory(value->maxTaskWorkGroupSize, 3);
    bytes_read += wrapper->maxTaskWorkGroupSize.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTaskTotalMemorySize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxTaskOutputCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMeshWorkGroupInvocations));
    wrapper->maxMeshWorkGroupSize.SetExternalMemory(value->maxMeshWorkGroupSize, 3);
    bytes_read += wrapper->maxMeshWorkGroupSize.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMeshTotalMemorySize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMeshOutputVertices));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMeshOutputPrimitives));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMeshMultiviewViewCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->meshOutputPerVertexGranularity));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->meshOutputPerPrimitiveGranularity));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDrawMeshTasksIndirectCommandNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDrawMeshTasksIndirectCommandNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->taskCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->firstTask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fragmentShaderBarycentric));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceShaderImageFootprintFeaturesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageFootprint));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineViewportExclusiveScissorStateCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->exclusiveScissorCount));
    wrapper->pExclusiveScissors = std::make_unique<StructPointerDecoder<Decoded_VkRect2D>>();
    bytes_read += wrapper->pExclusiveScissors->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pExclusiveScissors = wrapper->pExclusiveScissors->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceExclusiveScissorFeaturesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->exclusiveScissor));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkQueueFamilyCheckpointPropertiesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkQueueFamilyCheckpointPropertiesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->checkpointExecutionStageMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCheckpointDataNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCheckpointDataNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stage));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pCheckpointMarker));
    value->pCheckpointMarker = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDevicePCIBusInfoPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->pciDomain));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->pciBus));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->pciDevice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->pciFunction));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayNativeHdrSurfaceCapabilitiesAMD* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->localDimmingSupport));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSwapchainDisplayNativeHdrCreateInfoAMD* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->localDimmingEnable));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImagePipeSurfaceCreateInfoFUCHSIA* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imagePipeHandle));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMetalSurfaceCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMetalSurfaceCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pLayer));
    value->pLayer = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceFragmentDensityMapFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fragmentDensityMap));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fragmentDensityMapDynamic));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fragmentDensityMapNonSubsampledImages));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceFragmentDensityMapPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->minFragmentDensityTexelSize = std::make_unique<Decoded_VkExtent2D>();
    wrapper->minFragmentDensityTexelSize->value = &(value->minFragmentDensityTexelSize);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->minFragmentDensityTexelSize.get());
    wrapper->maxFragmentDensityTexelSize = std::make_unique<Decoded_VkExtent2D>();
    wrapper->maxFragmentDensityTexelSize->value = &(value->maxFragmentDensityTexelSize);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->maxFragmentDensityTexelSize.get());
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fragmentDensityInvocations));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRenderPassFragmentDensityMapCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->fragmentDensityMapAttachment = std::make_unique<Decoded_VkAttachmentReference>();
    wrapper->fragmentDensityMapAttachment->value = &(value->fragmentDensityMapAttachment);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->fragmentDensityMapAttachment.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceScalarBlockLayoutFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceScalarBlockLayoutFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->scalarBlockLayout));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMemoryBudgetPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    wrapper->heapBudget.SetExternalMemory(value->heapBudget, VK_MAX_MEMORY_HEAPS);
    bytes_read += wrapper->heapBudget.DecodeVkDeviceSize((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->heapUsage.SetExternalMemory(value->heapUsage, VK_MAX_MEMORY_HEAPS);
    bytes_read += wrapper->heapUsage.DecodeVkDeviceSize((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMemoryPriorityFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryPriority));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryPriorityAllocateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryPriorityAllocateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->priority));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dedicatedAllocationImageAliasing));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferDeviceAddress));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferDeviceAddressCaptureReplay));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferDeviceAddressMultiDevice));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferDeviceAddressInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferDeviceAddressInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferDeviceAddressCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferDeviceAddressCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkDeviceAddressValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceAddress));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageStencilUsageCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageStencilUsageCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stencilUsage));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkValidationFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkValidationFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabledValidationFeatureCount));
    bytes_read += wrapper->pEnabledValidationFeatures.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pEnabledValidationFeatures = wrapper->pEnabledValidationFeatures.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->disabledValidationFeatureCount));
    bytes_read += wrapper->pDisabledValidationFeatures.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDisabledValidationFeatures = wrapper->pDisabledValidationFeatures.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCooperativeMatrixPropertiesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCooperativeMatrixPropertiesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->KSize));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AType));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->BType));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->CType));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DType));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->scope));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceCooperativeMatrixFeaturesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->cooperativeMatrix));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->cooperativeMatrixRobustBufferAccess));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceCooperativeMatrixPropertiesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->cooperativeMatrixSupportedStages));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceCoverageReductionModeFeaturesNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->coverageReductionMode));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineCoverageReductionStateCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineCoverageReductionStateCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->coverageReductionMode));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFramebufferMixedSamplesCombinationNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFramebufferMixedSamplesCombinationNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->coverageReductionMode));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->rasterizationSamples));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthStencilSamples));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->colorSamples));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ycbcrImageArrays));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceFullScreenExclusiveInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceFullScreenExclusiveInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->fullScreenExclusive));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceCapabilitiesFullScreenExclusiveEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fullScreenExclusiveSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceFullScreenExclusiveWin32InfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->hmonitor));
    value->hmonitor = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkHeadlessSurfaceCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkHeadlessSurfaceCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceHostQueryResetFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceHostQueryResetFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->hostQueryReset));

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
