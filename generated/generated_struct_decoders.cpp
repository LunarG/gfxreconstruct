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

#include <cassert>
#include <memory>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/custom_struct_decoders.h"
#include "format/platform_types.h"
#include "format/pnext_node.h"
#include "format/pointer_decoder.h"
#include "format/string_array_decoder.h"
#include "format/string_decoder.h"
#include "format/struct_pointer_decoder.h"
#include "format/value_decoder.h"

#include "generated/generated_struct_decoders.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

size_t decode_pnext_struct(const uint8_t* buffer, size_t buffer_size, std::unique_ptr<PNextNode>* pNext);

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkApplicationInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkApplicationInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += wrapper->pApplicationName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pApplicationName = wrapper->pApplicationName.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->applicationVersion));
    bytes_read += wrapper->pEngineName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pEngineName = wrapper->pEngineName.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->engineVersion));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->apiVersion));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkInstanceCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkInstanceCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += wrapper->pApplicationInfo.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pApplicationInfo = wrapper->pApplicationInfo.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabledLayerCount));
    bytes_read += wrapper->ppEnabledLayerNames.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ppEnabledLayerNames = wrapper->ppEnabledLayerNames.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabledExtensionCount));
    bytes_read += wrapper->ppEnabledExtensionNames.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ppEnabledExtensionNames = wrapper->ppEnabledExtensionNames.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAllocationCallbacks* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFeatures* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFormatProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFormatProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->linearTilingFeatures));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->optimalTilingFeatures));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferFeatures));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExtent3D* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExtent3D* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depth));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageFormatProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageFormatProperties* value = wrapper->value;

    wrapper->maxExtent.value = &(value->maxExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->maxExtent));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMipLevels));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxArrayLayers));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleCounts));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxResourceSize));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceLimits* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSparseProperties* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProperties* wrapper)
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
    wrapper->limits.value = &(value->limits);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->limits));
    wrapper->sparseProperties.value = &(value->sparseProperties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->sparseProperties));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkQueueFamilyProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkQueueFamilyProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFlags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->timestampValidBits));
    wrapper->minImageTransferGranularity.value = &(value->minImageTransferGranularity);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->minImageTransferGranularity));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryType* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryType* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->propertyFlags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->heapIndex));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryHeap* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryHeap* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMemoryProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeCount));
    wrapper->memoryTypes.SetExternalMemory(value->memoryTypes, VK_MAX_MEMORY_TYPES);
    bytes_read += wrapper->memoryTypes.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryHeapCount));
    wrapper->memoryHeaps.SetExternalMemory(value->memoryHeaps, VK_MAX_MEMORY_HEAPS);
    bytes_read += wrapper->memoryHeaps.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceQueueCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceQueueCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFamilyIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueCount));
    bytes_read += wrapper->pQueuePriorities.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    value->pQueuePriorities = wrapper->pQueuePriorities.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueCreateInfoCount));
    bytes_read += wrapper->pQueueCreateInfos.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pQueueCreateInfos = wrapper->pQueueCreateInfos.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabledLayerCount));
    bytes_read += wrapper->ppEnabledLayerNames.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ppEnabledLayerNames = wrapper->ppEnabledLayerNames.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->enabledExtensionCount));
    bytes_read += wrapper->ppEnabledExtensionNames.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ppEnabledExtensionNames = wrapper->ppEnabledExtensionNames.GetPointer();
    bytes_read += wrapper->pEnabledFeatures.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pEnabledFeatures = wrapper->pEnabledFeatures.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExtensionProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExtensionProperties* value = wrapper->value;

    wrapper->extensionName.SetExternalMemory(value->extensionName, VK_MAX_EXTENSION_NAME_SIZE);
    bytes_read += wrapper->extensionName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->specVersion));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkLayerProperties* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubmitInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubmitInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->waitSemaphoreCount));
    bytes_read += wrapper->pWaitSemaphores.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pWaitSemaphores = nullptr;
    bytes_read += wrapper->pWaitDstStageMask.DecodeFlags((buffer + bytes_read), (buffer_size - bytes_read));
    value->pWaitDstStageMask = wrapper->pWaitDstStageMask.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->commandBufferCount));
    bytes_read += wrapper->pCommandBuffers.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCommandBuffers = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->signalSemaphoreCount));
    bytes_read += wrapper->pSignalSemaphores.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSignalSemaphores = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryAllocateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryAllocateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->allocationSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeIndex));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMappedMemoryRange* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMappedMemoryRange* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryRequirements* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryRequirements* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->alignment));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeBits));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageFormatProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageFormatProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectMask));
    wrapper->imageGranularity.value = &(value->imageGranularity);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->imageGranularity));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageMemoryRequirements* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageMemoryRequirements* value = wrapper->value;

    wrapper->formatProperties.value = &(value->formatProperties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->formatProperties));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageMipTailFirstLod));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageMipTailSize));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageMipTailOffset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageMipTailStride));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseMemoryBind* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseBufferMemoryBindInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseBufferMemoryBindInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bindCount));
    bytes_read += wrapper->pBinds.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBinds = wrapper->pBinds.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageOpaqueMemoryBindInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bindCount));
    bytes_read += wrapper->pBinds.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBinds = wrapper->pBinds.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageSubresource* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageSubresource* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->mipLevel));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->arrayLayer));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkOffset3D* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkOffset3D* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->z));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageMemoryBind* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageMemoryBind* value = wrapper->value;

    wrapper->subresource.value = &(value->subresource);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->subresource));
    wrapper->offset.value = &(value->offset);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->offset));
    wrapper->extent.value = &(value->extent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->extent));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryOffset));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageMemoryBindInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageMemoryBindInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bindCount));
    bytes_read += wrapper->pBinds.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBinds = wrapper->pBinds.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindSparseInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindSparseInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->waitSemaphoreCount));
    bytes_read += wrapper->pWaitSemaphores.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pWaitSemaphores = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferBindCount));
    bytes_read += wrapper->pBufferBinds.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBufferBinds = wrapper->pBufferBinds.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageOpaqueBindCount));
    bytes_read += wrapper->pImageOpaqueBinds.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pImageOpaqueBinds = wrapper->pImageOpaqueBinds.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageBindCount));
    bytes_read += wrapper->pImageBinds.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pImageBinds = wrapper->pImageBinds.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->signalSemaphoreCount));
    bytes_read += wrapper->pSignalSemaphores.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSignalSemaphores = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFenceCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFenceCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSemaphoreCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSemaphoreCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkEventCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkEventCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkQueryPoolCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkQueryPoolCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->queryType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queryCount));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pipelineStatistics));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->usage));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sharingMode));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFamilyIndexCount));
    bytes_read += wrapper->pQueueFamilyIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pQueueFamilyIndices = wrapper->pQueueFamilyIndices.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferViewCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferViewCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->range));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageType));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    wrapper->extent.value = &(value->extent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->extent));
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubresourceLayout* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkComponentMapping* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageSubresourceRange* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageViewCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageViewCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewType));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    wrapper->components.value = &(value->components);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->components));
    wrapper->subresourceRange.value = &(value->subresourceRange);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->subresourceRange));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkShaderModuleCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkShaderModuleCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->codeSize));
    bytes_read += wrapper->pCode.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCode = wrapper->pCode.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineCacheCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineCacheCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->initialDataSize));
    bytes_read += wrapper->pInitialData.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pInitialData = wrapper->pInitialData.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSpecializationMapEntry* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSpecializationMapEntry* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->constantID));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSpecializationInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSpecializationInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->mapEntryCount));
    bytes_read += wrapper->pMapEntries.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pMapEntries = wrapper->pMapEntries.GetPointer();
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dataSize));
    bytes_read += wrapper->pData.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pData = wrapper->pData.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineShaderStageCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineShaderStageCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stage));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->module));
    value->module = VK_NULL_HANDLE;
    bytes_read += wrapper->pName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pName = wrapper->pName.GetPointer();
    bytes_read += wrapper->pSpecializationInfo.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSpecializationInfo = wrapper->pSpecializationInfo.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkVertexInputBindingDescription* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkVertexInputBindingDescription* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->binding));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->stride));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->inputRate));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkVertexInputAttributeDescription* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineVertexInputStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineVertexInputStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexBindingDescriptionCount));
    bytes_read += wrapper->pVertexBindingDescriptions.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pVertexBindingDescriptions = wrapper->pVertexBindingDescriptions.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexAttributeDescriptionCount));
    bytes_read += wrapper->pVertexAttributeDescriptions.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pVertexAttributeDescriptions = wrapper->pVertexAttributeDescriptions.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineInputAssemblyStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineInputAssemblyStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->topology));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->primitiveRestartEnable));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineTessellationStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineTessellationStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->patchControlPoints));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkViewport* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkOffset2D* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkOffset2D* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExtent2D* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExtent2D* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRect2D* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRect2D* value = wrapper->value;

    wrapper->offset.value = &(value->offset);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->offset));
    wrapper->extent.value = &(value->extent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->extent));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineViewportStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineViewportStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewportCount));
    bytes_read += wrapper->pViewports.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pViewports = wrapper->pViewports.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->scissorCount));
    bytes_read += wrapper->pScissors.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pScissors = wrapper->pScissors.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineRasterizationStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineRasterizationStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineMultisampleStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineMultisampleStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkStencilOpState* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineDepthStencilStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineDepthStencilStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthTestEnable));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthWriteEnable));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthCompareOp));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->depthBoundsTestEnable));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->stencilTestEnable));
    wrapper->front.value = &(value->front);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->front));
    wrapper->back.value = &(value->back);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->back));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minDepthBounds));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDepthBounds));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineColorBlendAttachmentState* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineColorBlendStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineColorBlendStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->logicOpEnable));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->logicOp));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachmentCount));
    bytes_read += wrapper->pAttachments.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttachments = wrapper->pAttachments.GetPointer();
    wrapper->blendConstants.SetExternalMemory(value->blendConstants, 4);
    bytes_read += wrapper->blendConstants.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineDynamicStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineDynamicStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dynamicStateCount));
    bytes_read += wrapper->pDynamicStates.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDynamicStates = wrapper->pDynamicStates.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkGraphicsPipelineCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkGraphicsPipelineCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->stageCount));
    bytes_read += wrapper->pStages.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pStages = wrapper->pStages.GetPointer();
    bytes_read += wrapper->pVertexInputState.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pVertexInputState = wrapper->pVertexInputState.GetPointer();
    bytes_read += wrapper->pInputAssemblyState.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pInputAssemblyState = wrapper->pInputAssemblyState.GetPointer();
    bytes_read += wrapper->pTessellationState.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTessellationState = wrapper->pTessellationState.GetPointer();
    bytes_read += wrapper->pViewportState.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pViewportState = wrapper->pViewportState.GetPointer();
    bytes_read += wrapper->pRasterizationState.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pRasterizationState = wrapper->pRasterizationState.GetPointer();
    bytes_read += wrapper->pMultisampleState.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pMultisampleState = wrapper->pMultisampleState.GetPointer();
    bytes_read += wrapper->pDepthStencilState.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDepthStencilState = wrapper->pDepthStencilState.GetPointer();
    bytes_read += wrapper->pColorBlendState.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pColorBlendState = wrapper->pColorBlendState.GetPointer();
    bytes_read += wrapper->pDynamicState.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDynamicState = wrapper->pDynamicState.GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkComputePipelineCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkComputePipelineCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    wrapper->stage.value = &(value->stage);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->stage));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->layout));
    value->layout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->basePipelineHandle));
    value->basePipelineHandle = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->basePipelineIndex));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPushConstantRange* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPushConstantRange* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stageFlags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineLayoutCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineLayoutCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->setLayoutCount));
    bytes_read += wrapper->pSetLayouts.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSetLayouts = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->pushConstantRangeCount));
    bytes_read += wrapper->pPushConstantRanges.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPushConstantRanges = wrapper->pPushConstantRanges.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSamplerCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSamplerCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutBinding* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetLayoutBinding* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->binding));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorCount));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->stageFlags));
    bytes_read += wrapper->pImmutableSamplers.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pImmutableSamplers = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetLayoutCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bindingCount));
    bytes_read += wrapper->pBindings.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBindings = wrapper->pBindings.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorPoolSize* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorPoolSize* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorCount));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorPoolCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorPoolCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSets));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->poolSizeCount));
    bytes_read += wrapper->pPoolSizes.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPoolSizes = wrapper->pPoolSizes.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetAllocateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetAllocateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->descriptorPool));
    value->descriptorPool = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorSetCount));
    bytes_read += wrapper->pSetLayouts.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSetLayouts = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorImageInfo* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorBufferInfo* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkWriteDescriptorSet* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkWriteDescriptorSet* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->dstSet));
    value->dstSet = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstBinding));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstArrayElement));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorCount));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorType));
    bytes_read += wrapper->pImageInfo.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pImageInfo = wrapper->pImageInfo.GetPointer();
    bytes_read += wrapper->pBufferInfo.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBufferInfo = wrapper->pBufferInfo.GetPointer();
    bytes_read += wrapper->pTexelBufferView.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTexelBufferView = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCopyDescriptorSet* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCopyDescriptorSet* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFramebufferCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFramebufferCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->renderPass));
    value->renderPass = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachmentCount));
    bytes_read += wrapper->pAttachments.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttachments = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->height));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layers));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAttachmentDescription* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAttachmentReference* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAttachmentReference* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachment));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->layout));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassDescription* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassDescription* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pipelineBindPoint));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->inputAttachmentCount));
    bytes_read += wrapper->pInputAttachments.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pInputAttachments = wrapper->pInputAttachments.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->colorAttachmentCount));
    bytes_read += wrapper->pColorAttachments.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pColorAttachments = wrapper->pColorAttachments.GetPointer();
    bytes_read += wrapper->pResolveAttachments.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pResolveAttachments = wrapper->pResolveAttachments.GetPointer();
    bytes_read += wrapper->pDepthStencilAttachment.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDepthStencilAttachment = wrapper->pDepthStencilAttachment.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->preserveAttachmentCount));
    bytes_read += wrapper->pPreserveAttachments.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPreserveAttachments = wrapper->pPreserveAttachments.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassDependency* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRenderPassCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRenderPassCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachmentCount));
    bytes_read += wrapper->pAttachments.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttachments = wrapper->pAttachments.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subpassCount));
    bytes_read += wrapper->pSubpasses.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSubpasses = wrapper->pSubpasses.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dependencyCount));
    bytes_read += wrapper->pDependencies.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDependencies = wrapper->pDependencies.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCommandPoolCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCommandPoolCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFamilyIndex));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCommandBufferAllocateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCommandBufferAllocateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->commandPool));
    value->commandPool = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->level));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->commandBufferCount));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCommandBufferInheritanceInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCommandBufferInheritanceInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCommandBufferBeginInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCommandBufferBeginInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += wrapper->pInheritanceInfo.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pInheritanceInfo = wrapper->pInheritanceInfo.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferCopy* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferCopy* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcOffset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstOffset));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->size));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageSubresourceLayers* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageCopy* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageCopy* value = wrapper->value;

    wrapper->srcSubresource.value = &(value->srcSubresource);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->srcSubresource));
    wrapper->srcOffset.value = &(value->srcOffset);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->srcOffset));
    wrapper->dstSubresource.value = &(value->dstSubresource);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->dstSubresource));
    wrapper->dstOffset.value = &(value->dstOffset);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->dstOffset));
    wrapper->extent.value = &(value->extent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->extent));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageBlit* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageBlit* value = wrapper->value;

    wrapper->srcSubresource.value = &(value->srcSubresource);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->srcSubresource));
    wrapper->srcOffsets.SetExternalMemory(value->srcOffsets, 2);
    bytes_read += wrapper->srcOffsets.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->dstSubresource.value = &(value->dstSubresource);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->dstSubresource));
    wrapper->dstOffsets.SetExternalMemory(value->dstOffsets, 2);
    bytes_read += wrapper->dstOffsets.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferImageCopy* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferImageCopy* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferOffset));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferRowLength));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bufferImageHeight));
    wrapper->imageSubresource.value = &(value->imageSubresource);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->imageSubresource));
    wrapper->imageOffset.value = &(value->imageOffset);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->imageOffset));
    wrapper->imageExtent.value = &(value->imageExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->imageExtent));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearDepthStencilValue* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkClearDepthStencilValue* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->depth));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->stencil));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearAttachment* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkClearAttachment* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->colorAttachment));
    wrapper->clearValue.value = &(value->clearValue);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->clearValue));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearRect* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkClearRect* value = wrapper->value;

    wrapper->rect.value = &(value->rect);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->rect));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->baseArrayLayer));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layerCount));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageResolve* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageResolve* value = wrapper->value;

    wrapper->srcSubresource.value = &(value->srcSubresource);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->srcSubresource));
    wrapper->srcOffset.value = &(value->srcOffset);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->srcOffset));
    wrapper->dstSubresource.value = &(value->dstSubresource);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->dstSubresource));
    wrapper->dstOffset.value = &(value->dstOffset);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->dstOffset));
    wrapper->extent.value = &(value->extent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->extent));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryBarrier* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryBarrier* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcAccessMask));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstAccessMask));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferMemoryBarrier* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferMemoryBarrier* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageMemoryBarrier* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageMemoryBarrier* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcAccessMask));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstAccessMask));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->oldLayout));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->newLayout));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcQueueFamilyIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstQueueFamilyIndex));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    wrapper->subresourceRange.value = &(value->subresourceRange);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->subresourceRange));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRenderPassBeginInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRenderPassBeginInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->renderPass));
    value->renderPass = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->framebuffer));
    value->framebuffer = VK_NULL_HANDLE;
    wrapper->renderArea.value = &(value->renderArea);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->renderArea));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->clearValueCount));
    bytes_read += wrapper->pClearValues.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pClearValues = wrapper->pClearValues.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDispatchIndirectCommand* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDispatchIndirectCommand* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->z));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDrawIndexedIndirectCommand* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDrawIndirectCommand* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSubgroupProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceSubgroupProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subgroupSize));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedStages));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedOperations));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->quadOperationsInAllStages));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindBufferMemoryInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindBufferMemoryInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryOffset));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindImageMemoryInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindImageMemoryInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryOffset));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDevice16BitStorageFeatures* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDevice16BitStorageFeatures* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->storageBuffer16BitAccess));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->uniformAndStorageBuffer16BitAccess));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->storagePushConstant16));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->storageInputOutput16));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryDedicatedRequirements* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryDedicatedRequirements* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->prefersDedicatedAllocation));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->requiresDedicatedAllocation));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryDedicatedAllocateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryDedicatedAllocateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryAllocateFlagsInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryAllocateFlagsInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceMask));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupRenderPassBeginInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupRenderPassBeginInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceRenderAreaCount));
    bytes_read += wrapper->pDeviceRenderAreas.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDeviceRenderAreas = wrapper->pDeviceRenderAreas.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupCommandBufferBeginInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupCommandBufferBeginInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceMask));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupSubmitInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupSubmitInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupBindSparseInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupBindSparseInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->resourceDeviceIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryDeviceIndex));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindBufferMemoryDeviceGroupInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindBufferMemoryDeviceGroupInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceIndexCount));
    bytes_read += wrapper->pDeviceIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDeviceIndices = wrapper->pDeviceIndices.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindImageMemoryDeviceGroupInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindImageMemoryDeviceGroupInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceIndexCount));
    bytes_read += wrapper->pDeviceIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDeviceIndices = wrapper->pDeviceIndices.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->splitInstanceBindRegionCount));
    bytes_read += wrapper->pSplitInstanceBindRegions.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSplitInstanceBindRegions = wrapper->pSplitInstanceBindRegions.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceGroupProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceGroupProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->physicalDeviceCount));
    bytes_read += wrapper->physicalDevices.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subsetAllocation));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupDeviceCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupDeviceCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->physicalDeviceCount));
    bytes_read += wrapper->pPhysicalDevices.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPhysicalDevices = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBufferMemoryRequirementsInfo2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBufferMemoryRequirementsInfo2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageMemoryRequirementsInfo2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageMemoryRequirementsInfo2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageSparseMemoryRequirementsInfo2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryRequirements2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryRequirements2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->memoryRequirements.value = &(value->memoryRequirements);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memoryRequirements));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageMemoryRequirements2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageMemoryRequirements2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->memoryRequirements.value = &(value->memoryRequirements);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memoryRequirements));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFeatures2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceFeatures2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->features.value = &(value->features);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->features));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProperties2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceProperties2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->properties.value = &(value->properties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->properties));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFormatProperties2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFormatProperties2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->formatProperties.value = &(value->formatProperties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->formatProperties));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageFormatProperties2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageFormatProperties2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->imageFormatProperties.value = &(value->imageFormatProperties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->imageFormatProperties));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageFormatInfo2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceImageFormatInfo2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->tiling));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->usage));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkQueueFamilyProperties2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkQueueFamilyProperties2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->queueFamilyProperties.value = &(value->queueFamilyProperties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->queueFamilyProperties));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryProperties2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMemoryProperties2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->memoryProperties.value = &(value->memoryProperties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memoryProperties));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSparseImageFormatProperties2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSparseImageFormatProperties2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->properties.value = &(value->properties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->properties));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSparseImageFormatInfo2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceSparseImageFormatInfo2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->samples));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->usage));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->tiling));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDevicePointClippingProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDevicePointClippingProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pointClippingBehavior));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkInputAttachmentAspectReference* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkInputAttachmentAspectReference* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subpass));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->inputAttachmentIndex));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectMask));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRenderPassInputAttachmentAspectCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRenderPassInputAttachmentAspectCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectReferenceCount));
    bytes_read += wrapper->pAspectReferences.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAspectReferences = wrapper->pAspectReferences.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageViewUsageCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageViewUsageCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->usage));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineTessellationDomainOriginStateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineTessellationDomainOriginStateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->domainOrigin));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRenderPassMultiviewCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRenderPassMultiviewCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewFeatures* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMultiviewFeatures* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->multiview));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->multiviewGeometryShader));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->multiviewTessellationShader));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMultiviewProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMultiviewViewCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMultiviewInstanceIndex));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVariablePointerFeatures* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceVariablePointerFeatures* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->variablePointersStorageBuffer));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->variablePointers));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProtectedMemoryFeatures* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceProtectedMemoryFeatures* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->protectedMemory));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProtectedMemoryProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceProtectedMemoryProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->protectedNoFault));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceQueueInfo2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceQueueInfo2* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueFamilyIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueIndex));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkProtectedSubmitInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkProtectedSubmitInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->protectedSubmit));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSamplerYcbcrConversionCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSamplerYcbcrConversionCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ycbcrModel));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ycbcrRange));
    wrapper->components.value = &(value->components);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->components));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->xChromaOffset));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->yChromaOffset));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->chromaFilter));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->forceExplicitReconstruction));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSamplerYcbcrConversionInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSamplerYcbcrConversionInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->conversion));
    value->conversion = VK_NULL_HANDLE;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindImagePlaneMemoryInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindImagePlaneMemoryInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeAspect));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImagePlaneMemoryRequirementsInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImagePlaneMemoryRequirementsInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeAspect));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceSamplerYcbcrConversionFeatures* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->samplerYcbcrConversion));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSamplerYcbcrConversionImageFormatProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSamplerYcbcrConversionImageFormatProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->combinedImageSamplerDescriptorCount));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorUpdateTemplateEntry* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorUpdateTemplateCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorUpdateEntryCount));
    bytes_read += wrapper->pDescriptorUpdateEntries.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDescriptorUpdateEntries = wrapper->pDescriptorUpdateEntries.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->templateType));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->descriptorSetLayout));
    value->descriptorSetLayout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pipelineBindPoint));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pipelineLayout));
    value->pipelineLayout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->set));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalMemoryProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalMemoryProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->externalMemoryFeatures));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->exportFromImportedHandleTypes));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->compatibleHandleTypes));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalImageFormatInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceExternalImageFormatInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalImageFormatProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalImageFormatProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->externalMemoryProperties.value = &(value->externalMemoryProperties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->externalMemoryProperties));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalBufferInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceExternalBufferInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->usage));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalBufferProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalBufferProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->externalMemoryProperties.value = &(value->externalMemoryProperties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->externalMemoryProperties));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceIDProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceIDProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalMemoryImageCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalMemoryImageCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalMemoryBufferCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalMemoryBufferCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportMemoryAllocateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportMemoryAllocateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalFenceInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceExternalFenceInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalFenceProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalFenceProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->exportFromImportedHandleTypes));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->compatibleHandleTypes));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->externalFenceFeatures));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportFenceCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportFenceCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportSemaphoreCreateInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportSemaphoreCreateInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalSemaphoreInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceExternalSemaphoreInfo* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalSemaphoreProperties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalSemaphoreProperties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->exportFromImportedHandleTypes));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->compatibleHandleTypes));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->externalSemaphoreFeatures));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMaintenance3Properties* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMaintenance3Properties* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPerSetDescriptors));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxMemoryAllocationSize));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutSupport* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetLayoutSupport* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supported));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderDrawParameterFeatures* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceShaderDrawParameterFeatures* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderDrawParameters));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceCapabilitiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceCapabilitiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minImageCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageCount));
    wrapper->currentExtent.value = &(value->currentExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->currentExtent));
    wrapper->minImageExtent.value = &(value->minImageExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->minImageExtent));
    wrapper->maxImageExtent.value = &(value->maxImageExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->maxImageExtent));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageArrayLayers));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedTransforms));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->currentTransform));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedCompositeAlpha));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedUsageFlags));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceFormatKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceFormatKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->colorSpace));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSwapchainCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSwapchainCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->surface));
    value->surface = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minImageCount));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageFormat));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageColorSpace));
    wrapper->imageExtent.value = &(value->imageExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->imageExtent));
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPresentInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPresentInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->waitSemaphoreCount));
    bytes_read += wrapper->pWaitSemaphores.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pWaitSemaphores = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->swapchainCount));
    bytes_read += wrapper->pSwapchains.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSwapchains = nullptr;
    bytes_read += wrapper->pImageIndices.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pImageIndices = wrapper->pImageIndices.GetPointer();
    bytes_read += wrapper->pResults.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pResults = wrapper->pResults.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageSwapchainCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageSwapchainCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->swapchain));
    value->swapchain = VK_NULL_HANDLE;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkBindImageMemorySwapchainInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->swapchain));
    value->swapchain = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageIndex));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAcquireNextImageInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAcquireNextImageInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupPresentCapabilitiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupPresentCapabilitiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->presentMask.SetExternalMemory(value->presentMask, VK_MAX_DEVICE_GROUP_SIZE);
    bytes_read += wrapper->presentMask.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->modes));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupPresentInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupPresentInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->swapchainCount));
    bytes_read += wrapper->pDeviceMasks.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDeviceMasks = wrapper->pDeviceMasks.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->mode));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGroupSwapchainCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGroupSwapchainCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->modes));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->display));
    value->display = VK_NULL_HANDLE;
    bytes_read += wrapper->displayName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->displayName = wrapper->displayName.GetPointer();
    wrapper->physicalDimensions.value = &(value->physicalDimensions);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->physicalDimensions));
    wrapper->physicalResolution.value = &(value->physicalResolution);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->physicalResolution));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedTransforms));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeReorderPossible));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->persistentContent));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayModeParametersKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayModeParametersKHR* value = wrapper->value;

    wrapper->visibleRegion.value = &(value->visibleRegion);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->visibleRegion));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->refreshRate));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayModePropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayModePropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->displayMode));
    value->displayMode = VK_NULL_HANDLE;
    wrapper->parameters.value = &(value->parameters);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->parameters));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayModeCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayModeCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    wrapper->parameters.value = &(value->parameters);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->parameters));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPlaneCapabilitiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPlaneCapabilitiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedAlpha));
    wrapper->minSrcPosition.value = &(value->minSrcPosition);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->minSrcPosition));
    wrapper->maxSrcPosition.value = &(value->maxSrcPosition);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->maxSrcPosition));
    wrapper->minSrcExtent.value = &(value->minSrcExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->minSrcExtent));
    wrapper->maxSrcExtent.value = &(value->maxSrcExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->maxSrcExtent));
    wrapper->minDstPosition.value = &(value->minDstPosition);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->minDstPosition));
    wrapper->maxDstPosition.value = &(value->maxDstPosition);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->maxDstPosition));
    wrapper->minDstExtent.value = &(value->minDstExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->minDstExtent));
    wrapper->maxDstExtent.value = &(value->maxDstExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->maxDstExtent));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPlanePropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPlanePropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->currentDisplay));
    value->currentDisplay = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->currentStackIndex));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplaySurfaceCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->displayMode));
    value->displayMode = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeStackIndex));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->transform));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->globalAlpha));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->alphaMode));
    wrapper->imageExtent.value = &(value->imageExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->imageExtent));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPresentInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPresentInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->srcRect.value = &(value->srcRect);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->srcRect));
    wrapper->dstRect.value = &(value->dstRect);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->dstRect));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->persistent));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkXlibSurfaceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkXlibSurfaceCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->dpy));
    value->dpy = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->window));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkXcbSurfaceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkXcbSurfaceCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->connection));
    value->connection = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->window));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkWaylandSurfaceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkWaylandSurfaceCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->display));
    value->display = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->surface));
    value->surface = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMirSurfaceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMirSurfaceCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->connection));
    value->connection = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->mirSurface));
    value->mirSurface = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAndroidSurfaceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAndroidSurfaceCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->window));
    value->window = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkWin32SurfaceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkWin32SurfaceCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->hinstance));
    value->hinstance = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->hwnd));
    value->hwnd = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportMemoryWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportMemoryWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->handle));
    value->handle = nullptr;
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->name = wrapper->name.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportMemoryWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportMemoryWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += wrapper->pAttributes.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttributes = wrapper->pAttributes.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dwAccess));
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->name = wrapper->name.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryWin32HandlePropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryWin32HandlePropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeBits));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryGetWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportMemoryFdInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportMemoryFdInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fd));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryFdPropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryFdPropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeBits));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryGetFdInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryGetFdInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkWin32KeyedMutexAcquireReleaseInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->acquireCount));
    bytes_read += wrapper->pAcquireSyncs.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAcquireSyncs = nullptr;
    bytes_read += wrapper->pAcquireKeys.DecodeUInt64((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAcquireKeys = wrapper->pAcquireKeys.GetPointer();
    bytes_read += wrapper->pAcquireTimeouts.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAcquireTimeouts = wrapper->pAcquireTimeouts.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->releaseCount));
    bytes_read += wrapper->pReleaseSyncs.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pReleaseSyncs = nullptr;
    bytes_read += wrapper->pReleaseKeys.DecodeUInt64((buffer + bytes_read), (buffer_size - bytes_read));
    value->pReleaseKeys = wrapper->pReleaseKeys.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportSemaphoreWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportSemaphoreWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportSemaphoreWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += wrapper->pAttributes.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttributes = wrapper->pAttributes.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dwAccess));
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->name = wrapper->name.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkD3D12FenceSubmitInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkD3D12FenceSubmitInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->waitSemaphoreValuesCount));
    bytes_read += wrapper->pWaitSemaphoreValues.DecodeUInt64((buffer + bytes_read), (buffer_size - bytes_read));
    value->pWaitSemaphoreValues = wrapper->pWaitSemaphoreValues.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->signalSemaphoreValuesCount));
    bytes_read += wrapper->pSignalSemaphoreValues.DecodeUInt64((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSignalSemaphoreValues = wrapper->pSignalSemaphoreValues.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSemaphoreGetWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->semaphore));
    value->semaphore = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportSemaphoreFdInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportSemaphoreFdInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->semaphore));
    value->semaphore = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fd));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSemaphoreGetFdInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSemaphoreGetFdInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->semaphore));
    value->semaphore = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDevicePushDescriptorPropertiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxPushDescriptors));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRectLayerKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRectLayerKHR* value = wrapper->value;

    wrapper->offset.value = &(value->offset);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->offset));
    wrapper->extent.value = &(value->extent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->extent));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->layer));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPresentRegionKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPresentRegionKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->rectangleCount));
    bytes_read += wrapper->pRectangles.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pRectangles = wrapper->pRectangles.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPresentRegionsKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPresentRegionsKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->swapchainCount));
    bytes_read += wrapper->pRegions.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pRegions = wrapper->pRegions.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAttachmentDescription2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAttachmentDescription2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAttachmentReference2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAttachmentReference2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachment));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->layout));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->aspectMask));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassDescription2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassDescription2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pipelineBindPoint));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->inputAttachmentCount));
    bytes_read += wrapper->pInputAttachments.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pInputAttachments = wrapper->pInputAttachments.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->colorAttachmentCount));
    bytes_read += wrapper->pColorAttachments.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pColorAttachments = wrapper->pColorAttachments.GetPointer();
    bytes_read += wrapper->pResolveAttachments.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pResolveAttachments = wrapper->pResolveAttachments.GetPointer();
    bytes_read += wrapper->pDepthStencilAttachment.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDepthStencilAttachment = wrapper->pDepthStencilAttachment.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->preserveAttachmentCount));
    bytes_read += wrapper->pPreserveAttachments.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPreserveAttachments = wrapper->pPreserveAttachments.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassDependency2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassDependency2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRenderPassCreateInfo2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRenderPassCreateInfo2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachmentCount));
    bytes_read += wrapper->pAttachments.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttachments = wrapper->pAttachments.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subpassCount));
    bytes_read += wrapper->pSubpasses.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSubpasses = wrapper->pSubpasses.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dependencyCount));
    bytes_read += wrapper->pDependencies.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDependencies = wrapper->pDependencies.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->correlatedViewMaskCount));
    bytes_read += wrapper->pCorrelatedViewMasks.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCorrelatedViewMasks = wrapper->pCorrelatedViewMasks.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassBeginInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassBeginInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->contents));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassEndInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassEndInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSharedPresentSurfaceCapabilitiesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSharedPresentSurfaceCapabilitiesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sharedPresentSupportedUsageFlags));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportFenceWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportFenceWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportFenceWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportFenceWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += wrapper->pAttributes.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttributes = wrapper->pAttributes.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dwAccess));
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->name = wrapper->name.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFenceGetWin32HandleInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFenceGetWin32HandleInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->fence));
    value->fence = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportFenceFdInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportFenceFdInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->fence));
    value->fence = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->fd));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkFenceGetFdInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkFenceGetFdInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->fence));
    value->fence = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceSurfaceInfo2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->surface));
    value->surface = VK_NULL_HANDLE;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceCapabilities2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceCapabilities2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->surfaceCapabilities.value = &(value->surfaceCapabilities);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->surfaceCapabilities));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceFormat2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceFormat2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->surfaceFormat.value = &(value->surfaceFormat);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->surfaceFormat));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayProperties2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayProperties2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->displayProperties.value = &(value->displayProperties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->displayProperties));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPlaneProperties2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPlaneProperties2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->displayPlaneProperties.value = &(value->displayPlaneProperties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->displayPlaneProperties));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayModeProperties2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayModeProperties2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->displayModeProperties.value = &(value->displayModeProperties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->displayModeProperties));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPlaneInfo2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPlaneInfo2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->mode));
    value->mode = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->planeIndex));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPlaneCapabilities2KHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPlaneCapabilities2KHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->capabilities.value = &(value->capabilities);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->capabilities));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageFormatListCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImageFormatListCreateInfoKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewFormatCount));
    bytes_read += wrapper->pViewFormats.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pViewFormats = wrapper->pViewFormats.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDevice8BitStorageFeaturesKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDevice8BitStorageFeaturesKHR* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->storageBuffer8BitAccess));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->uniformAndStorageBuffer8BitAccess));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->storagePushConstant8));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugReportCallbackCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugReportCallbackCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pfnCallback));
    value->pfnCallback = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pUserData));
    value->pUserData = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineRasterizationStateRasterizationOrderAMD* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineRasterizationStateRasterizationOrderAMD* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->rasterizationOrder));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugMarkerObjectNameInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugMarkerObjectNameInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectType));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->object));
    bytes_read += wrapper->pObjectName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pObjectName = wrapper->pObjectName.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugMarkerObjectTagInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugMarkerObjectTagInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectType));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->object));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->tagName));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->tagSize));
    bytes_read += wrapper->pTag.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTag = wrapper->pTag.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugMarkerMarkerInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugMarkerMarkerInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += wrapper->pMarkerName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pMarkerName = wrapper->pMarkerName.GetPointer();
    wrapper->color.SetExternalMemory(value->color, 4);
    bytes_read += wrapper->color.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDedicatedAllocationImageCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDedicatedAllocationImageCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dedicatedAllocation));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDedicatedAllocationBufferCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDedicatedAllocationBufferCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dedicatedAllocation));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDedicatedAllocationMemoryAllocateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->image));
    value->image = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkTextureLODGatherFormatPropertiesAMD* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkTextureLODGatherFormatPropertiesAMD* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportsTextureGatherLODBiasAMD));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkShaderResourceUsageAMD* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkShaderStatisticsInfoAMD* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkShaderStatisticsInfoAMD* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->shaderStageMask));
    wrapper->resourceUsage.value = &(value->resourceUsage);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->resourceUsage));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->numPhysicalVgprs));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->numPhysicalSgprs));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->numAvailableVgprs));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->numAvailableSgprs));
    wrapper->computeWorkGroupSize.SetExternalMemory(value->computeWorkGroupSize, 3);
    bytes_read += wrapper->computeWorkGroupSize.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalImageFormatPropertiesNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalImageFormatPropertiesNV* value = wrapper->value;

    wrapper->imageFormatProperties.value = &(value->imageFormatProperties);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->imageFormatProperties));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->externalMemoryFeatures));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->exportFromImportedHandleTypes));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->compatibleHandleTypes));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalMemoryImageCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalMemoryImageCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportMemoryAllocateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportMemoryAllocateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleTypes));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportMemoryWin32HandleInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportMemoryWin32HandleInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->handle));
    value->handle = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExportMemoryWin32HandleInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExportMemoryWin32HandleInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += wrapper->pAttributes.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttributes = wrapper->pAttributes.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dwAccess));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkWin32KeyedMutexAcquireReleaseInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->acquireCount));
    bytes_read += wrapper->pAcquireSyncs.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAcquireSyncs = nullptr;
    bytes_read += wrapper->pAcquireKeys.DecodeUInt64((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAcquireKeys = wrapper->pAcquireKeys.GetPointer();
    bytes_read += wrapper->pAcquireTimeoutMilliseconds.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAcquireTimeoutMilliseconds = wrapper->pAcquireTimeoutMilliseconds.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->releaseCount));
    bytes_read += wrapper->pReleaseSyncs.DecodeHandleId((buffer + bytes_read), (buffer_size - bytes_read));
    value->pReleaseSyncs = nullptr;
    bytes_read += wrapper->pReleaseKeys.DecodeUInt64((buffer + bytes_read), (buffer_size - bytes_read));
    value->pReleaseKeys = wrapper->pReleaseKeys.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkValidationFlagsEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkValidationFlagsEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->disabledValidationCheckCount));
    bytes_read += wrapper->pDisabledValidationChecks.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDisabledValidationChecks = wrapper->pDisabledValidationChecks.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkViSurfaceCreateInfoNN* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkViSurfaceCreateInfoNN* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->window));
    value->window = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkConditionalRenderingBeginInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkConditionalRenderingBeginInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->offset));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceConditionalRenderingFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->conditionalRendering));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->inheritedConditionalRendering));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCommandBufferInheritanceConditionalRenderingInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->conditionalRenderingEnable));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGeneratedCommandsFeaturesNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGeneratedCommandsFeaturesNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->computeBindingPointSupport));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceGeneratedCommandsLimitsNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceGeneratedCommandsLimitsNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxIndirectCommandsLayoutTokenCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxObjectEntryCounts));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minSequenceCountBufferOffsetAlignment));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minSequenceIndexBufferOffsetAlignment));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minCommandsTokenBufferOffsetAlignment));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkIndirectCommandsTokenNVX* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkIndirectCommandsLayoutTokenNVX* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkIndirectCommandsLayoutCreateInfoNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkIndirectCommandsLayoutCreateInfoNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->pipelineBindPoint));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->tokenCount));
    bytes_read += wrapper->pTokens.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTokens = wrapper->pTokens.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCmdProcessCommandsInfoNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCmdProcessCommandsInfoNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->objectTable));
    value->objectTable = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->indirectCommandsLayout));
    value->indirectCommandsLayout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->indirectCommandsTokenCount));
    bytes_read += wrapper->pIndirectCommandsTokens.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pIndirectCommandsTokens = wrapper->pIndirectCommandsTokens.GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCmdReserveSpaceForCommandsInfoNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkCmdReserveSpaceForCommandsInfoNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->objectTable));
    value->objectTable = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->indirectCommandsLayout));
    value->indirectCommandsLayout = VK_NULL_HANDLE;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxSequencesCount));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkObjectTableCreateInfoNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkObjectTableCreateInfoNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkObjectTablePipelineEntryNVX* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkObjectTableDescriptorSetEntryNVX* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkObjectTableVertexBufferEntryNVX* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkObjectTableIndexBufferEntryNVX* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkObjectTablePushConstantEntryNVX* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkViewportWScalingNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkViewportWScalingNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->xcoeff));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ycoeff));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineViewportWScalingStateCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineViewportWScalingStateCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewportWScalingEnable));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewportCount));
    bytes_read += wrapper->pViewportWScalings.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pViewportWScalings = wrapper->pViewportWScalings.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSurfaceCapabilities2EXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSurfaceCapabilities2EXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->minImageCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageCount));
    wrapper->currentExtent.value = &(value->currentExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->currentExtent));
    wrapper->minImageExtent.value = &(value->minImageExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->minImageExtent));
    wrapper->maxImageExtent.value = &(value->maxImageExtent);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->maxImageExtent));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxImageArrayLayers));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedTransforms));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->currentTransform));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedCompositeAlpha));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedUsageFlags));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->supportedSurfaceCounters));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayPowerInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayPowerInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->powerState));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceEventInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceEventInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceEvent));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDisplayEventInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDisplayEventInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->displayEvent));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSwapchainCounterCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSwapchainCounterCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->surfaceCounters));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRefreshCycleDurationGOOGLE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRefreshCycleDurationGOOGLE* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->refreshDuration));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPastPresentationTimingGOOGLE* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPresentTimeGOOGLE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPresentTimeGOOGLE* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->presentID));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->desiredPresentTime));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPresentTimesInfoGOOGLE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPresentTimesInfoGOOGLE* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->swapchainCount));
    bytes_read += wrapper->pTimes.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTimes = wrapper->pTimes.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->perViewPositionAllComponents));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkViewportSwizzleNV* wrapper)
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineViewportSwizzleStateCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineViewportSwizzleStateCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->viewportCount));
    bytes_read += wrapper->pViewportSwizzles.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pViewportSwizzles = wrapper->pViewportSwizzles.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceDiscardRectanglePropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxDiscardRectangles));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineDiscardRectangleStateCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->discardRectangleMode));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->discardRectangleCount));
    bytes_read += wrapper->pDiscardRectangles.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDiscardRectangles = wrapper->pDiscardRectangles.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceConservativeRasterizationPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineRasterizationConservativeStateCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->conservativeRasterizationMode));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->extraPrimitiveOverestimationSize));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkXYColorEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkXYColorEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkHdrMetadataEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkHdrMetadataEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->displayPrimaryRed.value = &(value->displayPrimaryRed);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->displayPrimaryRed));
    wrapper->displayPrimaryGreen.value = &(value->displayPrimaryGreen);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->displayPrimaryGreen));
    wrapper->displayPrimaryBlue.value = &(value->displayPrimaryBlue);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->displayPrimaryBlue));
    wrapper->whitePoint.value = &(value->whitePoint);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->whitePoint));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxLuminance));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minLuminance));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxContentLightLevel));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxFrameAverageLightLevel));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkIOSSurfaceCreateInfoMVK* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkIOSSurfaceCreateInfoMVK* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pView));
    value->pView = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMacOSSurfaceCreateInfoMVK* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMacOSSurfaceCreateInfoMVK* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pView));
    value->pView = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugUtilsObjectNameInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugUtilsObjectNameInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectType));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectHandle));
    bytes_read += wrapper->pObjectName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pObjectName = wrapper->pObjectName.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugUtilsObjectTagInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugUtilsObjectTagInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectType));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectHandle));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->tagName));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->tagSize));
    bytes_read += wrapper->pTag.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTag = wrapper->pTag.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugUtilsLabelEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugUtilsLabelEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += wrapper->pLabelName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pLabelName = wrapper->pLabelName.GetPointer();
    wrapper->color.SetExternalMemory(value->color, 4);
    bytes_read += wrapper->color.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugUtilsMessengerCallbackDataEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugUtilsMessengerCallbackDataEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += wrapper->pMessageIdName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pMessageIdName = wrapper->pMessageIdName.GetPointer();
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->messageIdNumber));
    bytes_read += wrapper->pMessage.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pMessage = wrapper->pMessage.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->queueLabelCount));
    bytes_read += wrapper->pQueueLabels.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pQueueLabels = wrapper->pQueueLabels.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->cmdBufLabelCount));
    bytes_read += wrapper->pCmdBufLabels.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCmdBufLabels = wrapper->pCmdBufLabels.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->objectCount));
    bytes_read += wrapper->pObjects.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pObjects = wrapper->pObjects.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDebugUtilsMessengerCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDebugUtilsMessengerCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->messageSeverity));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->messageType));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pfnUserCallback));
    value->pfnUserCallback = nullptr;
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pUserData));
    value->pUserData = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferUsageANDROID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAndroidHardwareBufferUsageANDROID* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->androidHardwareBufferUsage));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferPropertiesANDROID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAndroidHardwareBufferPropertiesANDROID* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->allocationSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeBits));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAndroidHardwareBufferFormatPropertiesANDROID* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->format));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->externalFormat));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->formatFeatures));
    wrapper->samplerYcbcrConversionComponents.value = &(value->samplerYcbcrConversionComponents);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->samplerYcbcrConversionComponents));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->suggestedYcbcrModel));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->suggestedYcbcrRange));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->suggestedXChromaOffset));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->suggestedYChromaOffset));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportAndroidHardwareBufferInfoANDROID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportAndroidHardwareBufferInfoANDROID* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->buffer));
    value->buffer = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryGetAndroidHardwareBufferInfoANDROID* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->memory));
    value->memory = VK_NULL_HANDLE;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkExternalFormatANDROID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkExternalFormatANDROID* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->externalFormat));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSamplerReductionModeCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSamplerReductionModeCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->reductionMode));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->filterMinmaxSingleComponentFormats));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->filterMinmaxImageComponentMapping));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSampleLocationEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSampleLocationEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSampleLocationsInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSampleLocationsInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleLocationsPerPixel));
    wrapper->sampleLocationGridSize.value = &(value->sampleLocationGridSize);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->sampleLocationGridSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleLocationsCount));
    bytes_read += wrapper->pSampleLocations.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSampleLocations = wrapper->pSampleLocations.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAttachmentSampleLocationsEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkAttachmentSampleLocationsEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachmentIndex));
    wrapper->sampleLocationsInfo.value = &(value->sampleLocationsInfo);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->sampleLocationsInfo));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkSubpassSampleLocationsEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkSubpassSampleLocationsEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->subpassIndex));
    wrapper->sampleLocationsInfo.value = &(value->sampleLocationsInfo);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->sampleLocationsInfo));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkRenderPassSampleLocationsBeginInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkRenderPassSampleLocationsBeginInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->attachmentInitialSampleLocationsCount));
    bytes_read += wrapper->pAttachmentInitialSampleLocations.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pAttachmentInitialSampleLocations = wrapper->pAttachmentInitialSampleLocations.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->postSubpassSampleLocationsCount));
    bytes_read += wrapper->pPostSubpassSampleLocations.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pPostSubpassSampleLocations = wrapper->pPostSubpassSampleLocations.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineSampleLocationsStateCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineSampleLocationsStateCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleLocationsEnable));
    wrapper->sampleLocationsInfo.value = &(value->sampleLocationsInfo);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->sampleLocationsInfo));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceSampleLocationsPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleLocationSampleCounts));
    wrapper->maxSampleLocationGridSize.value = &(value->maxSampleLocationGridSize);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->maxSampleLocationGridSize));
    wrapper->sampleLocationCoordinateRange.SetExternalMemory(value->sampleLocationCoordinateRange, 2);
    bytes_read += wrapper->sampleLocationCoordinateRange.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->sampleLocationSubPixelBits));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->variableSampleLocations));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMultisamplePropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMultisamplePropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    wrapper->maxSampleLocationGridSize.value = &(value->maxSampleLocationGridSize);
    bytes_read += decode_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->maxSampleLocationGridSize));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendCoherentOperations));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendMaxColorAttachments));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendIndependentBlend));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendNonPremultipliedSrcColor));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendNonPremultipliedDstColor));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendCorrelatedOverlap));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->advancedBlendAllOperations));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineColorBlendAdvancedStateCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcPremultiplied));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstPremultiplied));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->blendOverlap));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineCoverageToColorStateCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineCoverageToColorStateCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->coverageToColorEnable));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->coverageToColorLocation));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineCoverageModulationStateCreateInfoNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineCoverageModulationStateCreateInfoNV* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->coverageModulationMode));
    bytes_read += ValueDecoder::DecodeVkBool32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->coverageModulationTableEnable));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->coverageModulationTableCount));
    bytes_read += wrapper->pCoverageModulationTable.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCoverageModulationTable = wrapper->pCoverageModulationTable.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkValidationCacheCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkValidationCacheCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->initialDataSize));
    bytes_read += wrapper->pInitialData.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pInitialData = wrapper->pInitialData.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkShaderModuleValidationCacheCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->validationCache));
    value->validationCache = VK_NULL_HANDLE;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetLayoutBindingFlagsCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bindingCount));
    bytes_read += wrapper->pBindingFlags.DecodeFlags((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBindingFlags = wrapper->pBindingFlags.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDescriptorIndexingFeaturesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceDescriptorIndexingFeaturesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDescriptorIndexingPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceDescriptorIndexingPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetVariableDescriptorCountAllocateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorSetCount));
    bytes_read += wrapper->pDescriptorCounts.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDescriptorCounts = wrapper->pDescriptorCounts.GetPointer();

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupportEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDescriptorSetVariableDescriptorCountLayoutSupportEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxVariableDescriptorCount));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceQueueGlobalPriorityCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkDeviceQueueGlobalPriorityCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->globalPriority));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImportMemoryHostPointerInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkImportMemoryHostPointerInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->handleType));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pHostPointer));
    value->pHostPointer = nullptr;

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryHostPointerPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkMemoryHostPointerPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryTypeBits));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceExternalMemoryHostPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->minImportedHostPointerAlignment));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderCorePropertiesAMD* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceShaderCorePropertiesAMD* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
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

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->maxVertexAttribDivisor));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkVertexInputBindingDivisorDescriptionEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkVertexInputBindingDivisorDescriptionEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->binding));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->divisor));

    return bytes_read;
}

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));

    size_t bytes_read = 0;
    VkPipelineVertexInputDivisorStateCreateInfoEXT* value = wrapper->value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += decode_pnext_struct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vertexBindingDivisorCount));
    bytes_read += wrapper->pVertexBindingDivisors.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pVertexBindingDivisors = wrapper->pVertexBindingDivisors.GetPointer();

    return bytes_read;
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
