/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
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

#include "decode/vulkan_feature_util.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(feature_util)

void RemoveUnsupportedFeatures(VkPhysicalDevice physicalDevice, PFN_vkGetPhysicalDeviceFeatures GetPhysicalDeviceFeatures, PFN_vkGetPhysicalDeviceFeatures2 GetPhysicalDeviceFeatures2, const void* pNext, const VkPhysicalDeviceFeatures* pEnabledFeatures)
{
    // If the pNext chain includes a VkPhysicalDeviceFeatures2 structure, then pEnabledFeatures must be NULL
    const VkPhysicalDeviceFeatures* physicalDeviceFeatures = nullptr;
    if (pEnabledFeatures != nullptr)
    {
        physicalDeviceFeatures = pEnabledFeatures;
    }

    if (GetPhysicalDeviceFeatures2 != nullptr)
    {
        VkPhysicalDeviceFeatures2 physicalDeviceFeatures2 = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, nullptr };
        const VkDeviceCreateInfo* next = reinterpret_cast<const VkDeviceCreateInfo*>(pNext);
        while (next != nullptr)
        {
            switch (next->sType)
            {
            // Special case to set VkPhysicalDeviceFeatures if passed in pNext
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
                physicalDeviceFeatures = &reinterpret_cast<const VkPhysicalDeviceFeatures2*>(next)->features;
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            {
                const VkPhysicalDevice16BitStorageFeatures* currentNext = reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(next);
                VkPhysicalDevice16BitStorageFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->storageBuffer16BitAccess == VK_TRUE) && (query.storageBuffer16BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storageBuffer16BitAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevice16BitStorageFeatures*>(currentNext)->storageBuffer16BitAccess = VK_FALSE;
                }
                if ((currentNext->uniformAndStorageBuffer16BitAccess == VK_TRUE) && (query.uniformAndStorageBuffer16BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature uniformAndStorageBuffer16BitAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevice16BitStorageFeatures*>(currentNext)->uniformAndStorageBuffer16BitAccess = VK_FALSE;
                }
                if ((currentNext->storagePushConstant16 == VK_TRUE) && (query.storagePushConstant16 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storagePushConstant16, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevice16BitStorageFeatures*>(currentNext)->storagePushConstant16 = VK_FALSE;
                }
                if ((currentNext->storageInputOutput16 == VK_TRUE) && (query.storageInputOutput16 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storageInputOutput16, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevice16BitStorageFeatures*>(currentNext)->storageInputOutput16 = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            {
                const VkPhysicalDeviceMultiviewFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(next);
                VkPhysicalDeviceMultiviewFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->multiview == VK_TRUE) && (query.multiview == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiview, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMultiviewFeatures*>(currentNext)->multiview = VK_FALSE;
                }
                if ((currentNext->multiviewGeometryShader == VK_TRUE) && (query.multiviewGeometryShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiviewGeometryShader, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMultiviewFeatures*>(currentNext)->multiviewGeometryShader = VK_FALSE;
                }
                if ((currentNext->multiviewTessellationShader == VK_TRUE) && (query.multiviewTessellationShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiviewTessellationShader, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMultiviewFeatures*>(currentNext)->multiviewTessellationShader = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            {
                const VkPhysicalDeviceVariablePointersFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(next);
                VkPhysicalDeviceVariablePointersFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->variablePointersStorageBuffer == VK_TRUE) && (query.variablePointersStorageBuffer == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature variablePointersStorageBuffer, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVariablePointersFeatures*>(currentNext)->variablePointersStorageBuffer = VK_FALSE;
                }
                if ((currentNext->variablePointers == VK_TRUE) && (query.variablePointers == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature variablePointers, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVariablePointersFeatures*>(currentNext)->variablePointers = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            {
                const VkPhysicalDeviceProtectedMemoryFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(next);
                VkPhysicalDeviceProtectedMemoryFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->protectedMemory == VK_TRUE) && (query.protectedMemory == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature protectedMemory, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceProtectedMemoryFeatures*>(currentNext)->protectedMemory = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            {
                const VkPhysicalDeviceSamplerYcbcrConversionFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(next);
                VkPhysicalDeviceSamplerYcbcrConversionFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->samplerYcbcrConversion == VK_TRUE) && (query.samplerYcbcrConversion == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature samplerYcbcrConversion, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(currentNext)->samplerYcbcrConversion = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            {
                const VkPhysicalDeviceShaderDrawParametersFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(next);
                VkPhysicalDeviceShaderDrawParametersFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderDrawParameters == VK_TRUE) && (query.shaderDrawParameters == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderDrawParameters, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderDrawParametersFeatures*>(currentNext)->shaderDrawParameters = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            {
                const VkPhysicalDeviceVulkan11Features* currentNext = reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(next);
                VkPhysicalDeviceVulkan11Features query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->storageBuffer16BitAccess == VK_TRUE) && (query.storageBuffer16BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storageBuffer16BitAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->storageBuffer16BitAccess = VK_FALSE;
                }
                if ((currentNext->uniformAndStorageBuffer16BitAccess == VK_TRUE) && (query.uniformAndStorageBuffer16BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature uniformAndStorageBuffer16BitAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->uniformAndStorageBuffer16BitAccess = VK_FALSE;
                }
                if ((currentNext->storagePushConstant16 == VK_TRUE) && (query.storagePushConstant16 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storagePushConstant16, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->storagePushConstant16 = VK_FALSE;
                }
                if ((currentNext->storageInputOutput16 == VK_TRUE) && (query.storageInputOutput16 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storageInputOutput16, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->storageInputOutput16 = VK_FALSE;
                }
                if ((currentNext->multiview == VK_TRUE) && (query.multiview == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiview, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->multiview = VK_FALSE;
                }
                if ((currentNext->multiviewGeometryShader == VK_TRUE) && (query.multiviewGeometryShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiviewGeometryShader, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->multiviewGeometryShader = VK_FALSE;
                }
                if ((currentNext->multiviewTessellationShader == VK_TRUE) && (query.multiviewTessellationShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiviewTessellationShader, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->multiviewTessellationShader = VK_FALSE;
                }
                if ((currentNext->variablePointersStorageBuffer == VK_TRUE) && (query.variablePointersStorageBuffer == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature variablePointersStorageBuffer, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->variablePointersStorageBuffer = VK_FALSE;
                }
                if ((currentNext->variablePointers == VK_TRUE) && (query.variablePointers == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature variablePointers, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->variablePointers = VK_FALSE;
                }
                if ((currentNext->protectedMemory == VK_TRUE) && (query.protectedMemory == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature protectedMemory, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->protectedMemory = VK_FALSE;
                }
                if ((currentNext->samplerYcbcrConversion == VK_TRUE) && (query.samplerYcbcrConversion == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature samplerYcbcrConversion, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->samplerYcbcrConversion = VK_FALSE;
                }
                if ((currentNext->shaderDrawParameters == VK_TRUE) && (query.shaderDrawParameters == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderDrawParameters, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->shaderDrawParameters = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            {
                const VkPhysicalDeviceVulkan12Features* currentNext = reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(next);
                VkPhysicalDeviceVulkan12Features query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->samplerMirrorClampToEdge == VK_TRUE) && (query.samplerMirrorClampToEdge == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature samplerMirrorClampToEdge, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->samplerMirrorClampToEdge = VK_FALSE;
                }
                if ((currentNext->drawIndirectCount == VK_TRUE) && (query.drawIndirectCount == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature drawIndirectCount, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->drawIndirectCount = VK_FALSE;
                }
                if ((currentNext->storageBuffer8BitAccess == VK_TRUE) && (query.storageBuffer8BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storageBuffer8BitAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->storageBuffer8BitAccess = VK_FALSE;
                }
                if ((currentNext->uniformAndStorageBuffer8BitAccess == VK_TRUE) && (query.uniformAndStorageBuffer8BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature uniformAndStorageBuffer8BitAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->uniformAndStorageBuffer8BitAccess = VK_FALSE;
                }
                if ((currentNext->storagePushConstant8 == VK_TRUE) && (query.storagePushConstant8 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storagePushConstant8, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->storagePushConstant8 = VK_FALSE;
                }
                if ((currentNext->shaderBufferInt64Atomics == VK_TRUE) && (query.shaderBufferInt64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferInt64Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderBufferInt64Atomics = VK_FALSE;
                }
                if ((currentNext->shaderSharedInt64Atomics == VK_TRUE) && (query.shaderSharedInt64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedInt64Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderSharedInt64Atomics = VK_FALSE;
                }
                if ((currentNext->shaderFloat16 == VK_TRUE) && (query.shaderFloat16 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderFloat16, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderFloat16 = VK_FALSE;
                }
                if ((currentNext->shaderInt8 == VK_TRUE) && (query.shaderInt8 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderInt8, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderInt8 = VK_FALSE;
                }
                if ((currentNext->descriptorIndexing == VK_TRUE) && (query.descriptorIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorIndexing = VK_FALSE;
                }
                if ((currentNext->shaderInputAttachmentArrayDynamicIndexing == VK_TRUE) && (query.shaderInputAttachmentArrayDynamicIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderInputAttachmentArrayDynamicIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderInputAttachmentArrayDynamicIndexing = VK_FALSE;
                }
                if ((currentNext->shaderUniformTexelBufferArrayDynamicIndexing == VK_TRUE) && (query.shaderUniformTexelBufferArrayDynamicIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderUniformTexelBufferArrayDynamicIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderUniformTexelBufferArrayDynamicIndexing = VK_FALSE;
                }
                if ((currentNext->shaderStorageTexelBufferArrayDynamicIndexing == VK_TRUE) && (query.shaderStorageTexelBufferArrayDynamicIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageTexelBufferArrayDynamicIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderStorageTexelBufferArrayDynamicIndexing = VK_FALSE;
                }
                if ((currentNext->shaderUniformBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderUniformBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderUniformBufferArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderUniformBufferArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->shaderSampledImageArrayNonUniformIndexing == VK_TRUE) && (query.shaderSampledImageArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSampledImageArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderSampledImageArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->shaderStorageBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderStorageBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageBufferArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderStorageBufferArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->shaderStorageImageArrayNonUniformIndexing == VK_TRUE) && (query.shaderStorageImageArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageImageArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderStorageImageArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->shaderInputAttachmentArrayNonUniformIndexing == VK_TRUE) && (query.shaderInputAttachmentArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderInputAttachmentArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderInputAttachmentArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->shaderUniformTexelBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderUniformTexelBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderUniformTexelBufferArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderUniformTexelBufferArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->shaderStorageTexelBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderStorageTexelBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageTexelBufferArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderStorageTexelBufferArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->descriptorBindingUniformBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingUniformBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingUniformBufferUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingUniformBufferUpdateAfterBind = VK_FALSE;
                }
                if ((currentNext->descriptorBindingSampledImageUpdateAfterBind == VK_TRUE) && (query.descriptorBindingSampledImageUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingSampledImageUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingSampledImageUpdateAfterBind = VK_FALSE;
                }
                if ((currentNext->descriptorBindingStorageImageUpdateAfterBind == VK_TRUE) && (query.descriptorBindingStorageImageUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingStorageImageUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingStorageImageUpdateAfterBind = VK_FALSE;
                }
                if ((currentNext->descriptorBindingStorageBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingStorageBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingStorageBufferUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingStorageBufferUpdateAfterBind = VK_FALSE;
                }
                if ((currentNext->descriptorBindingUniformTexelBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingUniformTexelBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingUniformTexelBufferUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingUniformTexelBufferUpdateAfterBind = VK_FALSE;
                }
                if ((currentNext->descriptorBindingStorageTexelBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingStorageTexelBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingStorageTexelBufferUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingStorageTexelBufferUpdateAfterBind = VK_FALSE;
                }
                if ((currentNext->descriptorBindingUpdateUnusedWhilePending == VK_TRUE) && (query.descriptorBindingUpdateUnusedWhilePending == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingUpdateUnusedWhilePending, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingUpdateUnusedWhilePending = VK_FALSE;
                }
                if ((currentNext->descriptorBindingPartiallyBound == VK_TRUE) && (query.descriptorBindingPartiallyBound == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingPartiallyBound, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingPartiallyBound = VK_FALSE;
                }
                if ((currentNext->descriptorBindingVariableDescriptorCount == VK_TRUE) && (query.descriptorBindingVariableDescriptorCount == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingVariableDescriptorCount, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingVariableDescriptorCount = VK_FALSE;
                }
                if ((currentNext->runtimeDescriptorArray == VK_TRUE) && (query.runtimeDescriptorArray == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature runtimeDescriptorArray, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->runtimeDescriptorArray = VK_FALSE;
                }
                if ((currentNext->samplerFilterMinmax == VK_TRUE) && (query.samplerFilterMinmax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature samplerFilterMinmax, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->samplerFilterMinmax = VK_FALSE;
                }
                if ((currentNext->scalarBlockLayout == VK_TRUE) && (query.scalarBlockLayout == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature scalarBlockLayout, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->scalarBlockLayout = VK_FALSE;
                }
                if ((currentNext->imagelessFramebuffer == VK_TRUE) && (query.imagelessFramebuffer == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature imagelessFramebuffer, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->imagelessFramebuffer = VK_FALSE;
                }
                if ((currentNext->uniformBufferStandardLayout == VK_TRUE) && (query.uniformBufferStandardLayout == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature uniformBufferStandardLayout, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->uniformBufferStandardLayout = VK_FALSE;
                }
                if ((currentNext->shaderSubgroupExtendedTypes == VK_TRUE) && (query.shaderSubgroupExtendedTypes == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSubgroupExtendedTypes, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderSubgroupExtendedTypes = VK_FALSE;
                }
                if ((currentNext->separateDepthStencilLayouts == VK_TRUE) && (query.separateDepthStencilLayouts == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature separateDepthStencilLayouts, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->separateDepthStencilLayouts = VK_FALSE;
                }
                if ((currentNext->hostQueryReset == VK_TRUE) && (query.hostQueryReset == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature hostQueryReset, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->hostQueryReset = VK_FALSE;
                }
                if ((currentNext->timelineSemaphore == VK_TRUE) && (query.timelineSemaphore == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature timelineSemaphore, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->timelineSemaphore = VK_FALSE;
                }
                if ((currentNext->bufferDeviceAddress == VK_TRUE) && (query.bufferDeviceAddress == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddress, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->bufferDeviceAddress = VK_FALSE;
                }
                if ((currentNext->bufferDeviceAddressCaptureReplay == VK_TRUE) && (query.bufferDeviceAddressCaptureReplay == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddressCaptureReplay, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->bufferDeviceAddressCaptureReplay = VK_FALSE;
                }
                if ((currentNext->bufferDeviceAddressMultiDevice == VK_TRUE) && (query.bufferDeviceAddressMultiDevice == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddressMultiDevice, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->bufferDeviceAddressMultiDevice = VK_FALSE;
                }
                if ((currentNext->vulkanMemoryModel == VK_TRUE) && (query.vulkanMemoryModel == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vulkanMemoryModel, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->vulkanMemoryModel = VK_FALSE;
                }
                if ((currentNext->vulkanMemoryModelDeviceScope == VK_TRUE) && (query.vulkanMemoryModelDeviceScope == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vulkanMemoryModelDeviceScope, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->vulkanMemoryModelDeviceScope = VK_FALSE;
                }
                if ((currentNext->vulkanMemoryModelAvailabilityVisibilityChains == VK_TRUE) && (query.vulkanMemoryModelAvailabilityVisibilityChains == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vulkanMemoryModelAvailabilityVisibilityChains, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->vulkanMemoryModelAvailabilityVisibilityChains = VK_FALSE;
                }
                if ((currentNext->shaderOutputViewportIndex == VK_TRUE) && (query.shaderOutputViewportIndex == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderOutputViewportIndex, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderOutputViewportIndex = VK_FALSE;
                }
                if ((currentNext->shaderOutputLayer == VK_TRUE) && (query.shaderOutputLayer == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderOutputLayer, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderOutputLayer = VK_FALSE;
                }
                if ((currentNext->subgroupBroadcastDynamicId == VK_TRUE) && (query.subgroupBroadcastDynamicId == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature subgroupBroadcastDynamicId, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->subgroupBroadcastDynamicId = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            {
                const VkPhysicalDevice8BitStorageFeatures* currentNext = reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(next);
                VkPhysicalDevice8BitStorageFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->storageBuffer8BitAccess == VK_TRUE) && (query.storageBuffer8BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storageBuffer8BitAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevice8BitStorageFeatures*>(currentNext)->storageBuffer8BitAccess = VK_FALSE;
                }
                if ((currentNext->uniformAndStorageBuffer8BitAccess == VK_TRUE) && (query.uniformAndStorageBuffer8BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature uniformAndStorageBuffer8BitAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevice8BitStorageFeatures*>(currentNext)->uniformAndStorageBuffer8BitAccess = VK_FALSE;
                }
                if ((currentNext->storagePushConstant8 == VK_TRUE) && (query.storagePushConstant8 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storagePushConstant8, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevice8BitStorageFeatures*>(currentNext)->storagePushConstant8 = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            {
                const VkPhysicalDeviceShaderAtomicInt64Features* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(next);
                VkPhysicalDeviceShaderAtomicInt64Features query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderBufferInt64Atomics == VK_TRUE) && (query.shaderBufferInt64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferInt64Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicInt64Features*>(currentNext)->shaderBufferInt64Atomics = VK_FALSE;
                }
                if ((currentNext->shaderSharedInt64Atomics == VK_TRUE) && (query.shaderSharedInt64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedInt64Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicInt64Features*>(currentNext)->shaderSharedInt64Atomics = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            {
                const VkPhysicalDeviceShaderFloat16Int8Features* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(next);
                VkPhysicalDeviceShaderFloat16Int8Features query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderFloat16 == VK_TRUE) && (query.shaderFloat16 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderFloat16, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderFloat16Int8Features*>(currentNext)->shaderFloat16 = VK_FALSE;
                }
                if ((currentNext->shaderInt8 == VK_TRUE) && (query.shaderInt8 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderInt8, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderFloat16Int8Features*>(currentNext)->shaderInt8 = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            {
                const VkPhysicalDeviceDescriptorIndexingFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(next);
                VkPhysicalDeviceDescriptorIndexingFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderInputAttachmentArrayDynamicIndexing == VK_TRUE) && (query.shaderInputAttachmentArrayDynamicIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderInputAttachmentArrayDynamicIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderInputAttachmentArrayDynamicIndexing = VK_FALSE;
                }
                if ((currentNext->shaderUniformTexelBufferArrayDynamicIndexing == VK_TRUE) && (query.shaderUniformTexelBufferArrayDynamicIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderUniformTexelBufferArrayDynamicIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderUniformTexelBufferArrayDynamicIndexing = VK_FALSE;
                }
                if ((currentNext->shaderStorageTexelBufferArrayDynamicIndexing == VK_TRUE) && (query.shaderStorageTexelBufferArrayDynamicIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageTexelBufferArrayDynamicIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderStorageTexelBufferArrayDynamicIndexing = VK_FALSE;
                }
                if ((currentNext->shaderUniformBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderUniformBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderUniformBufferArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderUniformBufferArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->shaderSampledImageArrayNonUniformIndexing == VK_TRUE) && (query.shaderSampledImageArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSampledImageArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderSampledImageArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->shaderStorageBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderStorageBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageBufferArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderStorageBufferArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->shaderStorageImageArrayNonUniformIndexing == VK_TRUE) && (query.shaderStorageImageArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageImageArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderStorageImageArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->shaderInputAttachmentArrayNonUniformIndexing == VK_TRUE) && (query.shaderInputAttachmentArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderInputAttachmentArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderInputAttachmentArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->shaderUniformTexelBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderUniformTexelBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderUniformTexelBufferArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderUniformTexelBufferArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->shaderStorageTexelBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderStorageTexelBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageTexelBufferArrayNonUniformIndexing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderStorageTexelBufferArrayNonUniformIndexing = VK_FALSE;
                }
                if ((currentNext->descriptorBindingUniformBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingUniformBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingUniformBufferUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingUniformBufferUpdateAfterBind = VK_FALSE;
                }
                if ((currentNext->descriptorBindingSampledImageUpdateAfterBind == VK_TRUE) && (query.descriptorBindingSampledImageUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingSampledImageUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingSampledImageUpdateAfterBind = VK_FALSE;
                }
                if ((currentNext->descriptorBindingStorageImageUpdateAfterBind == VK_TRUE) && (query.descriptorBindingStorageImageUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingStorageImageUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingStorageImageUpdateAfterBind = VK_FALSE;
                }
                if ((currentNext->descriptorBindingStorageBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingStorageBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingStorageBufferUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingStorageBufferUpdateAfterBind = VK_FALSE;
                }
                if ((currentNext->descriptorBindingUniformTexelBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingUniformTexelBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingUniformTexelBufferUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingUniformTexelBufferUpdateAfterBind = VK_FALSE;
                }
                if ((currentNext->descriptorBindingStorageTexelBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingStorageTexelBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingStorageTexelBufferUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingStorageTexelBufferUpdateAfterBind = VK_FALSE;
                }
                if ((currentNext->descriptorBindingUpdateUnusedWhilePending == VK_TRUE) && (query.descriptorBindingUpdateUnusedWhilePending == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingUpdateUnusedWhilePending, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingUpdateUnusedWhilePending = VK_FALSE;
                }
                if ((currentNext->descriptorBindingPartiallyBound == VK_TRUE) && (query.descriptorBindingPartiallyBound == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingPartiallyBound, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingPartiallyBound = VK_FALSE;
                }
                if ((currentNext->descriptorBindingVariableDescriptorCount == VK_TRUE) && (query.descriptorBindingVariableDescriptorCount == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingVariableDescriptorCount, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingVariableDescriptorCount = VK_FALSE;
                }
                if ((currentNext->runtimeDescriptorArray == VK_TRUE) && (query.runtimeDescriptorArray == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature runtimeDescriptorArray, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->runtimeDescriptorArray = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            {
                const VkPhysicalDeviceScalarBlockLayoutFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(next);
                VkPhysicalDeviceScalarBlockLayoutFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->scalarBlockLayout == VK_TRUE) && (query.scalarBlockLayout == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature scalarBlockLayout, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceScalarBlockLayoutFeatures*>(currentNext)->scalarBlockLayout = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            {
                const VkPhysicalDeviceVulkanMemoryModelFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(next);
                VkPhysicalDeviceVulkanMemoryModelFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->vulkanMemoryModel == VK_TRUE) && (query.vulkanMemoryModel == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vulkanMemoryModel, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkanMemoryModelFeatures*>(currentNext)->vulkanMemoryModel = VK_FALSE;
                }
                if ((currentNext->vulkanMemoryModelDeviceScope == VK_TRUE) && (query.vulkanMemoryModelDeviceScope == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vulkanMemoryModelDeviceScope, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkanMemoryModelFeatures*>(currentNext)->vulkanMemoryModelDeviceScope = VK_FALSE;
                }
                if ((currentNext->vulkanMemoryModelAvailabilityVisibilityChains == VK_TRUE) && (query.vulkanMemoryModelAvailabilityVisibilityChains == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vulkanMemoryModelAvailabilityVisibilityChains, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkanMemoryModelFeatures*>(currentNext)->vulkanMemoryModelAvailabilityVisibilityChains = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            {
                const VkPhysicalDeviceImagelessFramebufferFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(next);
                VkPhysicalDeviceImagelessFramebufferFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->imagelessFramebuffer == VK_TRUE) && (query.imagelessFramebuffer == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature imagelessFramebuffer, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceImagelessFramebufferFeatures*>(currentNext)->imagelessFramebuffer = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            {
                const VkPhysicalDeviceUniformBufferStandardLayoutFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(next);
                VkPhysicalDeviceUniformBufferStandardLayoutFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->uniformBufferStandardLayout == VK_TRUE) && (query.uniformBufferStandardLayout == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature uniformBufferStandardLayout, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(currentNext)->uniformBufferStandardLayout = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            {
                const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(next);
                VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderSubgroupExtendedTypes == VK_TRUE) && (query.shaderSubgroupExtendedTypes == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSubgroupExtendedTypes, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(currentNext)->shaderSubgroupExtendedTypes = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            {
                const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(next);
                VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->separateDepthStencilLayouts == VK_TRUE) && (query.separateDepthStencilLayouts == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature separateDepthStencilLayouts, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(currentNext)->separateDepthStencilLayouts = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            {
                const VkPhysicalDeviceHostQueryResetFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(next);
                VkPhysicalDeviceHostQueryResetFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->hostQueryReset == VK_TRUE) && (query.hostQueryReset == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature hostQueryReset, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceHostQueryResetFeatures*>(currentNext)->hostQueryReset = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            {
                const VkPhysicalDeviceTimelineSemaphoreFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(next);
                VkPhysicalDeviceTimelineSemaphoreFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->timelineSemaphore == VK_TRUE) && (query.timelineSemaphore == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature timelineSemaphore, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceTimelineSemaphoreFeatures*>(currentNext)->timelineSemaphore = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            {
                const VkPhysicalDeviceBufferDeviceAddressFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(next);
                VkPhysicalDeviceBufferDeviceAddressFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->bufferDeviceAddress == VK_TRUE) && (query.bufferDeviceAddress == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddress, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceBufferDeviceAddressFeatures*>(currentNext)->bufferDeviceAddress = VK_FALSE;
                }
                if ((currentNext->bufferDeviceAddressCaptureReplay == VK_TRUE) && (query.bufferDeviceAddressCaptureReplay == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddressCaptureReplay, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceBufferDeviceAddressFeatures*>(currentNext)->bufferDeviceAddressCaptureReplay = VK_FALSE;
                }
                if ((currentNext->bufferDeviceAddressMultiDevice == VK_TRUE) && (query.bufferDeviceAddressMultiDevice == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddressMultiDevice, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceBufferDeviceAddressFeatures*>(currentNext)->bufferDeviceAddressMultiDevice = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
            {
                const VkPhysicalDeviceVulkan13Features* currentNext = reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(next);
                VkPhysicalDeviceVulkan13Features query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->robustImageAccess == VK_TRUE) && (query.robustImageAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature robustImageAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->robustImageAccess = VK_FALSE;
                }
                if ((currentNext->inlineUniformBlock == VK_TRUE) && (query.inlineUniformBlock == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature inlineUniformBlock, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->inlineUniformBlock = VK_FALSE;
                }
                if ((currentNext->descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE) && (query.descriptorBindingInlineUniformBlockUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingInlineUniformBlockUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->descriptorBindingInlineUniformBlockUpdateAfterBind = VK_FALSE;
                }
                if ((currentNext->pipelineCreationCacheControl == VK_TRUE) && (query.pipelineCreationCacheControl == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature pipelineCreationCacheControl, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->pipelineCreationCacheControl = VK_FALSE;
                }
                if ((currentNext->privateData == VK_TRUE) && (query.privateData == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature privateData, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->privateData = VK_FALSE;
                }
                if ((currentNext->shaderDemoteToHelperInvocation == VK_TRUE) && (query.shaderDemoteToHelperInvocation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderDemoteToHelperInvocation, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->shaderDemoteToHelperInvocation = VK_FALSE;
                }
                if ((currentNext->shaderTerminateInvocation == VK_TRUE) && (query.shaderTerminateInvocation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderTerminateInvocation, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->shaderTerminateInvocation = VK_FALSE;
                }
                if ((currentNext->subgroupSizeControl == VK_TRUE) && (query.subgroupSizeControl == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature subgroupSizeControl, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->subgroupSizeControl = VK_FALSE;
                }
                if ((currentNext->computeFullSubgroups == VK_TRUE) && (query.computeFullSubgroups == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature computeFullSubgroups, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->computeFullSubgroups = VK_FALSE;
                }
                if ((currentNext->synchronization2 == VK_TRUE) && (query.synchronization2 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature synchronization2, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->synchronization2 = VK_FALSE;
                }
                if ((currentNext->textureCompressionASTC_HDR == VK_TRUE) && (query.textureCompressionASTC_HDR == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature textureCompressionASTC_HDR, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->textureCompressionASTC_HDR = VK_FALSE;
                }
                if ((currentNext->shaderZeroInitializeWorkgroupMemory == VK_TRUE) && (query.shaderZeroInitializeWorkgroupMemory == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderZeroInitializeWorkgroupMemory, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->shaderZeroInitializeWorkgroupMemory = VK_FALSE;
                }
                if ((currentNext->dynamicRendering == VK_TRUE) && (query.dynamicRendering == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature dynamicRendering, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->dynamicRendering = VK_FALSE;
                }
                if ((currentNext->shaderIntegerDotProduct == VK_TRUE) && (query.shaderIntegerDotProduct == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderIntegerDotProduct, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->shaderIntegerDotProduct = VK_FALSE;
                }
                if ((currentNext->maintenance4 == VK_TRUE) && (query.maintenance4 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature maintenance4, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->maintenance4 = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
            {
                const VkPhysicalDeviceShaderTerminateInvocationFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(next);
                VkPhysicalDeviceShaderTerminateInvocationFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderTerminateInvocation == VK_TRUE) && (query.shaderTerminateInvocation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderTerminateInvocation, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderTerminateInvocationFeatures*>(currentNext)->shaderTerminateInvocation = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            {
                const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(next);
                VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderDemoteToHelperInvocation == VK_TRUE) && (query.shaderDemoteToHelperInvocation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderDemoteToHelperInvocation, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(currentNext)->shaderDemoteToHelperInvocation = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
            {
                const VkPhysicalDevicePrivateDataFeatures* currentNext = reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(next);
                VkPhysicalDevicePrivateDataFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->privateData == VK_TRUE) && (query.privateData == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature privateData, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePrivateDataFeatures*>(currentNext)->privateData = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            {
                const VkPhysicalDevicePipelineCreationCacheControlFeatures* currentNext = reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(next);
                VkPhysicalDevicePipelineCreationCacheControlFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->pipelineCreationCacheControl == VK_TRUE) && (query.pipelineCreationCacheControl == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature pipelineCreationCacheControl, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePipelineCreationCacheControlFeatures*>(currentNext)->pipelineCreationCacheControl = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
            {
                const VkPhysicalDeviceSynchronization2Features* currentNext = reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(next);
                VkPhysicalDeviceSynchronization2Features query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->synchronization2 == VK_TRUE) && (query.synchronization2 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature synchronization2, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceSynchronization2Features*>(currentNext)->synchronization2 = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
            {
                const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(next);
                VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderZeroInitializeWorkgroupMemory == VK_TRUE) && (query.shaderZeroInitializeWorkgroupMemory == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderZeroInitializeWorkgroupMemory, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(currentNext)->shaderZeroInitializeWorkgroupMemory = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
            {
                const VkPhysicalDeviceImageRobustnessFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(next);
                VkPhysicalDeviceImageRobustnessFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->robustImageAccess == VK_TRUE) && (query.robustImageAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature robustImageAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceImageRobustnessFeatures*>(currentNext)->robustImageAccess = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
            {
                const VkPhysicalDeviceSubgroupSizeControlFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(next);
                VkPhysicalDeviceSubgroupSizeControlFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->subgroupSizeControl == VK_TRUE) && (query.subgroupSizeControl == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature subgroupSizeControl, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceSubgroupSizeControlFeatures*>(currentNext)->subgroupSizeControl = VK_FALSE;
                }
                if ((currentNext->computeFullSubgroups == VK_TRUE) && (query.computeFullSubgroups == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature computeFullSubgroups, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceSubgroupSizeControlFeatures*>(currentNext)->computeFullSubgroups = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
            {
                const VkPhysicalDeviceInlineUniformBlockFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(next);
                VkPhysicalDeviceInlineUniformBlockFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->inlineUniformBlock == VK_TRUE) && (query.inlineUniformBlock == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature inlineUniformBlock, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceInlineUniformBlockFeatures*>(currentNext)->inlineUniformBlock = VK_FALSE;
                }
                if ((currentNext->descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE) && (query.descriptorBindingInlineUniformBlockUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingInlineUniformBlockUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceInlineUniformBlockFeatures*>(currentNext)->descriptorBindingInlineUniformBlockUpdateAfterBind = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            {
                const VkPhysicalDeviceTextureCompressionASTCHDRFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(next);
                VkPhysicalDeviceTextureCompressionASTCHDRFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->textureCompressionASTC_HDR == VK_TRUE) && (query.textureCompressionASTC_HDR == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature textureCompressionASTC_HDR, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(currentNext)->textureCompressionASTC_HDR = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
            {
                const VkPhysicalDeviceDynamicRenderingFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(next);
                VkPhysicalDeviceDynamicRenderingFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->dynamicRendering == VK_TRUE) && (query.dynamicRendering == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature dynamicRendering, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDynamicRenderingFeatures*>(currentNext)->dynamicRendering = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
            {
                const VkPhysicalDeviceShaderIntegerDotProductFeatures* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(next);
                VkPhysicalDeviceShaderIntegerDotProductFeatures query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderIntegerDotProduct == VK_TRUE) && (query.shaderIntegerDotProduct == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderIntegerDotProduct, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderIntegerDotProductFeatures*>(currentNext)->shaderIntegerDotProduct = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
            {
                const VkPhysicalDeviceMaintenance4Features* currentNext = reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(next);
                VkPhysicalDeviceMaintenance4Features query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->maintenance4 == VK_TRUE) && (query.maintenance4 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature maintenance4, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMaintenance4Features*>(currentNext)->maintenance4 = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            {
                const VkPhysicalDevicePerformanceQueryFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(next);
                VkPhysicalDevicePerformanceQueryFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->performanceCounterQueryPools == VK_TRUE) && (query.performanceCounterQueryPools == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature performanceCounterQueryPools, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePerformanceQueryFeaturesKHR*>(currentNext)->performanceCounterQueryPools = VK_FALSE;
                }
                if ((currentNext->performanceCounterMultipleQueryPools == VK_TRUE) && (query.performanceCounterMultipleQueryPools == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature performanceCounterMultipleQueryPools, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePerformanceQueryFeaturesKHR*>(currentNext)->performanceCounterMultipleQueryPools = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            {
                const VkPhysicalDevicePortabilitySubsetFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(next);
                VkPhysicalDevicePortabilitySubsetFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->constantAlphaColorBlendFactors == VK_TRUE) && (query.constantAlphaColorBlendFactors == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature constantAlphaColorBlendFactors, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->constantAlphaColorBlendFactors = VK_FALSE;
                }
                if ((currentNext->events == VK_TRUE) && (query.events == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature events, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->events = VK_FALSE;
                }
                if ((currentNext->imageViewFormatReinterpretation == VK_TRUE) && (query.imageViewFormatReinterpretation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature imageViewFormatReinterpretation, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->imageViewFormatReinterpretation = VK_FALSE;
                }
                if ((currentNext->imageViewFormatSwizzle == VK_TRUE) && (query.imageViewFormatSwizzle == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature imageViewFormatSwizzle, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->imageViewFormatSwizzle = VK_FALSE;
                }
                if ((currentNext->imageView2DOn3DImage == VK_TRUE) && (query.imageView2DOn3DImage == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature imageView2DOn3DImage, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->imageView2DOn3DImage = VK_FALSE;
                }
                if ((currentNext->multisampleArrayImage == VK_TRUE) && (query.multisampleArrayImage == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multisampleArrayImage, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->multisampleArrayImage = VK_FALSE;
                }
                if ((currentNext->mutableComparisonSamplers == VK_TRUE) && (query.mutableComparisonSamplers == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature mutableComparisonSamplers, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->mutableComparisonSamplers = VK_FALSE;
                }
                if ((currentNext->pointPolygons == VK_TRUE) && (query.pointPolygons == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature pointPolygons, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->pointPolygons = VK_FALSE;
                }
                if ((currentNext->samplerMipLodBias == VK_TRUE) && (query.samplerMipLodBias == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature samplerMipLodBias, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->samplerMipLodBias = VK_FALSE;
                }
                if ((currentNext->separateStencilMaskRef == VK_TRUE) && (query.separateStencilMaskRef == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature separateStencilMaskRef, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->separateStencilMaskRef = VK_FALSE;
                }
                if ((currentNext->shaderSampleRateInterpolationFunctions == VK_TRUE) && (query.shaderSampleRateInterpolationFunctions == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSampleRateInterpolationFunctions, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->shaderSampleRateInterpolationFunctions = VK_FALSE;
                }
                if ((currentNext->tessellationIsolines == VK_TRUE) && (query.tessellationIsolines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature tessellationIsolines, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->tessellationIsolines = VK_FALSE;
                }
                if ((currentNext->tessellationPointMode == VK_TRUE) && (query.tessellationPointMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature tessellationPointMode, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->tessellationPointMode = VK_FALSE;
                }
                if ((currentNext->triangleFans == VK_TRUE) && (query.triangleFans == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature triangleFans, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->triangleFans = VK_FALSE;
                }
                if ((currentNext->vertexAttributeAccessBeyondStride == VK_TRUE) && (query.vertexAttributeAccessBeyondStride == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vertexAttributeAccessBeyondStride, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->vertexAttributeAccessBeyondStride = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            {
                const VkPhysicalDeviceShaderClockFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(next);
                VkPhysicalDeviceShaderClockFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderSubgroupClock == VK_TRUE) && (query.shaderSubgroupClock == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSubgroupClock, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderClockFeaturesKHR*>(currentNext)->shaderSubgroupClock = VK_FALSE;
                }
                if ((currentNext->shaderDeviceClock == VK_TRUE) && (query.shaderDeviceClock == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderDeviceClock, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderClockFeaturesKHR*>(currentNext)->shaderDeviceClock = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR:
            {
                const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(next);
                VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->globalPriorityQuery == VK_TRUE) && (query.globalPriorityQuery == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature globalPriorityQuery, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(currentNext)->globalPriorityQuery = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            {
                const VkPhysicalDeviceFragmentShadingRateFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(next);
                VkPhysicalDeviceFragmentShadingRateFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->pipelineFragmentShadingRate == VK_TRUE) && (query.pipelineFragmentShadingRate == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature pipelineFragmentShadingRate, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(currentNext)->pipelineFragmentShadingRate = VK_FALSE;
                }
                if ((currentNext->primitiveFragmentShadingRate == VK_TRUE) && (query.primitiveFragmentShadingRate == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature primitiveFragmentShadingRate, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(currentNext)->primitiveFragmentShadingRate = VK_FALSE;
                }
                if ((currentNext->attachmentFragmentShadingRate == VK_TRUE) && (query.attachmentFragmentShadingRate == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature attachmentFragmentShadingRate, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(currentNext)->attachmentFragmentShadingRate = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            {
                const VkPhysicalDevicePresentWaitFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(next);
                VkPhysicalDevicePresentWaitFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->presentWait == VK_TRUE) && (query.presentWait == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature presentWait, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePresentWaitFeaturesKHR*>(currentNext)->presentWait = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            {
                const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(next);
                VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->pipelineExecutableInfo == VK_TRUE) && (query.pipelineExecutableInfo == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature pipelineExecutableInfo, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(currentNext)->pipelineExecutableInfo = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            {
                const VkPhysicalDevicePresentIdFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(next);
                VkPhysicalDevicePresentIdFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->presentId == VK_TRUE) && (query.presentId == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature presentId, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePresentIdFeaturesKHR*>(currentNext)->presentId = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
            {
                const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(next);
                VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->fragmentShaderBarycentric == VK_TRUE) && (query.fragmentShaderBarycentric == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentShaderBarycentric, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(currentNext)->fragmentShaderBarycentric = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            {
                const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(next);
                VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderSubgroupUniformControlFlow == VK_TRUE) && (query.shaderSubgroupUniformControlFlow == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSubgroupUniformControlFlow, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(currentNext)->shaderSubgroupUniformControlFlow = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            {
                const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(next);
                VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->workgroupMemoryExplicitLayout == VK_TRUE) && (query.workgroupMemoryExplicitLayout == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature workgroupMemoryExplicitLayout, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(currentNext)->workgroupMemoryExplicitLayout = VK_FALSE;
                }
                if ((currentNext->workgroupMemoryExplicitLayoutScalarBlockLayout == VK_TRUE) && (query.workgroupMemoryExplicitLayoutScalarBlockLayout == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature workgroupMemoryExplicitLayoutScalarBlockLayout, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(currentNext)->workgroupMemoryExplicitLayoutScalarBlockLayout = VK_FALSE;
                }
                if ((currentNext->workgroupMemoryExplicitLayout8BitAccess == VK_TRUE) && (query.workgroupMemoryExplicitLayout8BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature workgroupMemoryExplicitLayout8BitAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(currentNext)->workgroupMemoryExplicitLayout8BitAccess = VK_FALSE;
                }
                if ((currentNext->workgroupMemoryExplicitLayout16BitAccess == VK_TRUE) && (query.workgroupMemoryExplicitLayout16BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature workgroupMemoryExplicitLayout16BitAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(currentNext)->workgroupMemoryExplicitLayout16BitAccess = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            {
                const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(next);
                VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->rayTracingMaintenance1 == VK_TRUE) && (query.rayTracingMaintenance1 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingMaintenance1, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(currentNext)->rayTracingMaintenance1 = VK_FALSE;
                }
                if ((currentNext->rayTracingPipelineTraceRaysIndirect2 == VK_TRUE) && (query.rayTracingPipelineTraceRaysIndirect2 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingPipelineTraceRaysIndirect2, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(currentNext)->rayTracingPipelineTraceRaysIndirect2 = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            {
                const VkPhysicalDeviceTransformFeedbackFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(next);
                VkPhysicalDeviceTransformFeedbackFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->transformFeedback == VK_TRUE) && (query.transformFeedback == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature transformFeedback, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(currentNext)->transformFeedback = VK_FALSE;
                }
                if ((currentNext->geometryStreams == VK_TRUE) && (query.geometryStreams == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature geometryStreams, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(currentNext)->geometryStreams = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            {
                const VkPhysicalDeviceCornerSampledImageFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(next);
                VkPhysicalDeviceCornerSampledImageFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->cornerSampledImage == VK_TRUE) && (query.cornerSampledImage == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature cornerSampledImage, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceCornerSampledImageFeaturesNV*>(currentNext)->cornerSampledImage = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            {
                const VkPhysicalDeviceASTCDecodeFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(next);
                VkPhysicalDeviceASTCDecodeFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->decodeModeSharedExponent == VK_TRUE) && (query.decodeModeSharedExponent == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature decodeModeSharedExponent, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceASTCDecodeFeaturesEXT*>(currentNext)->decodeModeSharedExponent = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT:
            {
                const VkPhysicalDevicePipelineRobustnessFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDevicePipelineRobustnessFeaturesEXT*>(next);
                VkPhysicalDevicePipelineRobustnessFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->pipelineRobustness == VK_TRUE) && (query.pipelineRobustness == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature pipelineRobustness, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePipelineRobustnessFeaturesEXT*>(currentNext)->pipelineRobustness = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            {
                const VkPhysicalDeviceConditionalRenderingFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(next);
                VkPhysicalDeviceConditionalRenderingFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->conditionalRendering == VK_TRUE) && (query.conditionalRendering == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature conditionalRendering, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(currentNext)->conditionalRendering = VK_FALSE;
                }
                if ((currentNext->inheritedConditionalRendering == VK_TRUE) && (query.inheritedConditionalRendering == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature inheritedConditionalRendering, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(currentNext)->inheritedConditionalRendering = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            {
                const VkPhysicalDeviceDepthClipEnableFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(next);
                VkPhysicalDeviceDepthClipEnableFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->depthClipEnable == VK_TRUE) && (query.depthClipEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature depthClipEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(currentNext)->depthClipEnable = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            {
                const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(next);
                VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->advancedBlendCoherentOperations == VK_TRUE) && (query.advancedBlendCoherentOperations == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature advancedBlendCoherentOperations, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(currentNext)->advancedBlendCoherentOperations = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            {
                const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(next);
                VkPhysicalDeviceShaderSMBuiltinsFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderSMBuiltins == VK_TRUE) && (query.shaderSMBuiltins == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSMBuiltins, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(currentNext)->shaderSMBuiltins = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            {
                const VkPhysicalDeviceShadingRateImageFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(next);
                VkPhysicalDeviceShadingRateImageFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shadingRateImage == VK_TRUE) && (query.shadingRateImage == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shadingRateImage, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShadingRateImageFeaturesNV*>(currentNext)->shadingRateImage = VK_FALSE;
                }
                if ((currentNext->shadingRateCoarseSampleOrder == VK_TRUE) && (query.shadingRateCoarseSampleOrder == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shadingRateCoarseSampleOrder, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShadingRateImageFeaturesNV*>(currentNext)->shadingRateCoarseSampleOrder = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            {
                const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(next);
                VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->representativeFragmentTest == VK_TRUE) && (query.representativeFragmentTest == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature representativeFragmentTest, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(currentNext)->representativeFragmentTest = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:
            {
                const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(next);
                VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->vertexAttributeInstanceRateDivisor == VK_TRUE) && (query.vertexAttributeInstanceRateDivisor == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vertexAttributeInstanceRateDivisor, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(currentNext)->vertexAttributeInstanceRateDivisor = VK_FALSE;
                }
                if ((currentNext->vertexAttributeInstanceRateZeroDivisor == VK_TRUE) && (query.vertexAttributeInstanceRateZeroDivisor == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vertexAttributeInstanceRateZeroDivisor, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(currentNext)->vertexAttributeInstanceRateZeroDivisor = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
            {
                const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(next);
                VkPhysicalDeviceComputeShaderDerivativesFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->computeDerivativeGroupQuads == VK_TRUE) && (query.computeDerivativeGroupQuads == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature computeDerivativeGroupQuads, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(currentNext)->computeDerivativeGroupQuads = VK_FALSE;
                }
                if ((currentNext->computeDerivativeGroupLinear == VK_TRUE) && (query.computeDerivativeGroupLinear == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature computeDerivativeGroupLinear, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(currentNext)->computeDerivativeGroupLinear = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            {
                const VkPhysicalDeviceMeshShaderFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(next);
                VkPhysicalDeviceMeshShaderFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->taskShader == VK_TRUE) && (query.taskShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature taskShader, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesNV*>(currentNext)->taskShader = VK_FALSE;
                }
                if ((currentNext->meshShader == VK_TRUE) && (query.meshShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature meshShader, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesNV*>(currentNext)->meshShader = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            {
                const VkPhysicalDeviceShaderImageFootprintFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(next);
                VkPhysicalDeviceShaderImageFootprintFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->imageFootprint == VK_TRUE) && (query.imageFootprint == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature imageFootprint, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(currentNext)->imageFootprint = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            {
                const VkPhysicalDeviceExclusiveScissorFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(next);
                VkPhysicalDeviceExclusiveScissorFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->exclusiveScissor == VK_TRUE) && (query.exclusiveScissor == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature exclusiveScissor, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExclusiveScissorFeaturesNV*>(currentNext)->exclusiveScissor = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            {
                const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(next);
                VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderIntegerFunctions2 == VK_TRUE) && (query.shaderIntegerFunctions2 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderIntegerFunctions2, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(currentNext)->shaderIntegerFunctions2 = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            {
                const VkPhysicalDeviceFragmentDensityMapFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(next);
                VkPhysicalDeviceFragmentDensityMapFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->fragmentDensityMap == VK_TRUE) && (query.fragmentDensityMap == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentDensityMap, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(currentNext)->fragmentDensityMap = VK_FALSE;
                }
                if ((currentNext->fragmentDensityMapDynamic == VK_TRUE) && (query.fragmentDensityMapDynamic == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentDensityMapDynamic, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(currentNext)->fragmentDensityMapDynamic = VK_FALSE;
                }
                if ((currentNext->fragmentDensityMapNonSubsampledImages == VK_TRUE) && (query.fragmentDensityMapNonSubsampledImages == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentDensityMapNonSubsampledImages, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(currentNext)->fragmentDensityMapNonSubsampledImages = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            {
                const VkPhysicalDeviceCoherentMemoryFeaturesAMD* currentNext = reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(next);
                VkPhysicalDeviceCoherentMemoryFeaturesAMD query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->deviceCoherentMemory == VK_TRUE) && (query.deviceCoherentMemory == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature deviceCoherentMemory, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(currentNext)->deviceCoherentMemory = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            {
                const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(next);
                VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderImageInt64Atomics == VK_TRUE) && (query.shaderImageInt64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderImageInt64Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(currentNext)->shaderImageInt64Atomics = VK_FALSE;
                }
                if ((currentNext->sparseImageInt64Atomics == VK_TRUE) && (query.sparseImageInt64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature sparseImageInt64Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(currentNext)->sparseImageInt64Atomics = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            {
                const VkPhysicalDeviceMemoryPriorityFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(next);
                VkPhysicalDeviceMemoryPriorityFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->memoryPriority == VK_TRUE) && (query.memoryPriority == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature memoryPriority, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(currentNext)->memoryPriority = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            {
                const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(next);
                VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->dedicatedAllocationImageAliasing == VK_TRUE) && (query.dedicatedAllocationImageAliasing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature dedicatedAllocationImageAliasing, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(currentNext)->dedicatedAllocationImageAliasing = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            {
                const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(next);
                VkPhysicalDeviceBufferDeviceAddressFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->bufferDeviceAddress == VK_TRUE) && (query.bufferDeviceAddress == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddress, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(currentNext)->bufferDeviceAddress = VK_FALSE;
                }
                if ((currentNext->bufferDeviceAddressCaptureReplay == VK_TRUE) && (query.bufferDeviceAddressCaptureReplay == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddressCaptureReplay, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(currentNext)->bufferDeviceAddressCaptureReplay = VK_FALSE;
                }
                if ((currentNext->bufferDeviceAddressMultiDevice == VK_TRUE) && (query.bufferDeviceAddressMultiDevice == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddressMultiDevice, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(currentNext)->bufferDeviceAddressMultiDevice = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            {
                const VkPhysicalDeviceCooperativeMatrixFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(next);
                VkPhysicalDeviceCooperativeMatrixFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->cooperativeMatrix == VK_TRUE) && (query.cooperativeMatrix == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature cooperativeMatrix, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(currentNext)->cooperativeMatrix = VK_FALSE;
                }
                if ((currentNext->cooperativeMatrixRobustBufferAccess == VK_TRUE) && (query.cooperativeMatrixRobustBufferAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature cooperativeMatrixRobustBufferAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(currentNext)->cooperativeMatrixRobustBufferAccess = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            {
                const VkPhysicalDeviceCoverageReductionModeFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(next);
                VkPhysicalDeviceCoverageReductionModeFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->coverageReductionMode == VK_TRUE) && (query.coverageReductionMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature coverageReductionMode, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(currentNext)->coverageReductionMode = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            {
                const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(next);
                VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->fragmentShaderSampleInterlock == VK_TRUE) && (query.fragmentShaderSampleInterlock == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentShaderSampleInterlock, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(currentNext)->fragmentShaderSampleInterlock = VK_FALSE;
                }
                if ((currentNext->fragmentShaderPixelInterlock == VK_TRUE) && (query.fragmentShaderPixelInterlock == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentShaderPixelInterlock, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(currentNext)->fragmentShaderPixelInterlock = VK_FALSE;
                }
                if ((currentNext->fragmentShaderShadingRateInterlock == VK_TRUE) && (query.fragmentShaderShadingRateInterlock == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentShaderShadingRateInterlock, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(currentNext)->fragmentShaderShadingRateInterlock = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            {
                const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(next);
                VkPhysicalDeviceYcbcrImageArraysFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->ycbcrImageArrays == VK_TRUE) && (query.ycbcrImageArrays == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature ycbcrImageArrays, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(currentNext)->ycbcrImageArrays = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            {
                const VkPhysicalDeviceProvokingVertexFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(next);
                VkPhysicalDeviceProvokingVertexFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->provokingVertexLast == VK_TRUE) && (query.provokingVertexLast == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature provokingVertexLast, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceProvokingVertexFeaturesEXT*>(currentNext)->provokingVertexLast = VK_FALSE;
                }
                if ((currentNext->transformFeedbackPreservesProvokingVertex == VK_TRUE) && (query.transformFeedbackPreservesProvokingVertex == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature transformFeedbackPreservesProvokingVertex, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceProvokingVertexFeaturesEXT*>(currentNext)->transformFeedbackPreservesProvokingVertex = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT:
            {
                const VkPhysicalDeviceLineRasterizationFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeaturesEXT*>(next);
                VkPhysicalDeviceLineRasterizationFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->rectangularLines == VK_TRUE) && (query.rectangularLines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rectangularLines, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT*>(currentNext)->rectangularLines = VK_FALSE;
                }
                if ((currentNext->bresenhamLines == VK_TRUE) && (query.bresenhamLines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bresenhamLines, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT*>(currentNext)->bresenhamLines = VK_FALSE;
                }
                if ((currentNext->smoothLines == VK_TRUE) && (query.smoothLines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature smoothLines, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT*>(currentNext)->smoothLines = VK_FALSE;
                }
                if ((currentNext->stippledRectangularLines == VK_TRUE) && (query.stippledRectangularLines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature stippledRectangularLines, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT*>(currentNext)->stippledRectangularLines = VK_FALSE;
                }
                if ((currentNext->stippledBresenhamLines == VK_TRUE) && (query.stippledBresenhamLines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature stippledBresenhamLines, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT*>(currentNext)->stippledBresenhamLines = VK_FALSE;
                }
                if ((currentNext->stippledSmoothLines == VK_TRUE) && (query.stippledSmoothLines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature stippledSmoothLines, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT*>(currentNext)->stippledSmoothLines = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            {
                const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(next);
                VkPhysicalDeviceShaderAtomicFloatFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderBufferFloat32Atomics == VK_TRUE) && (query.shaderBufferFloat32Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat32Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderBufferFloat32Atomics = VK_FALSE;
                }
                if ((currentNext->shaderBufferFloat32AtomicAdd == VK_TRUE) && (query.shaderBufferFloat32AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat32AtomicAdd, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderBufferFloat32AtomicAdd = VK_FALSE;
                }
                if ((currentNext->shaderBufferFloat64Atomics == VK_TRUE) && (query.shaderBufferFloat64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat64Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderBufferFloat64Atomics = VK_FALSE;
                }
                if ((currentNext->shaderBufferFloat64AtomicAdd == VK_TRUE) && (query.shaderBufferFloat64AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat64AtomicAdd, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderBufferFloat64AtomicAdd = VK_FALSE;
                }
                if ((currentNext->shaderSharedFloat32Atomics == VK_TRUE) && (query.shaderSharedFloat32Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat32Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderSharedFloat32Atomics = VK_FALSE;
                }
                if ((currentNext->shaderSharedFloat32AtomicAdd == VK_TRUE) && (query.shaderSharedFloat32AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat32AtomicAdd, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderSharedFloat32AtomicAdd = VK_FALSE;
                }
                if ((currentNext->shaderSharedFloat64Atomics == VK_TRUE) && (query.shaderSharedFloat64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat64Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderSharedFloat64Atomics = VK_FALSE;
                }
                if ((currentNext->shaderSharedFloat64AtomicAdd == VK_TRUE) && (query.shaderSharedFloat64AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat64AtomicAdd, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderSharedFloat64AtomicAdd = VK_FALSE;
                }
                if ((currentNext->shaderImageFloat32Atomics == VK_TRUE) && (query.shaderImageFloat32Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderImageFloat32Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderImageFloat32Atomics = VK_FALSE;
                }
                if ((currentNext->shaderImageFloat32AtomicAdd == VK_TRUE) && (query.shaderImageFloat32AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderImageFloat32AtomicAdd, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderImageFloat32AtomicAdd = VK_FALSE;
                }
                if ((currentNext->sparseImageFloat32Atomics == VK_TRUE) && (query.sparseImageFloat32Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature sparseImageFloat32Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->sparseImageFloat32Atomics = VK_FALSE;
                }
                if ((currentNext->sparseImageFloat32AtomicAdd == VK_TRUE) && (query.sparseImageFloat32AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature sparseImageFloat32AtomicAdd, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->sparseImageFloat32AtomicAdd = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:
            {
                const VkPhysicalDeviceIndexTypeUint8FeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(next);
                VkPhysicalDeviceIndexTypeUint8FeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->indexTypeUint8 == VK_TRUE) && (query.indexTypeUint8 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature indexTypeUint8, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(currentNext)->indexTypeUint8 = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            {
                const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(next);
                VkPhysicalDeviceExtendedDynamicStateFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->extendedDynamicState == VK_TRUE) && (query.extendedDynamicState == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(currentNext)->extendedDynamicState = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            {
                const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(next);
                VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderBufferFloat16Atomics == VK_TRUE) && (query.shaderBufferFloat16Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat16Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderBufferFloat16Atomics = VK_FALSE;
                }
                if ((currentNext->shaderBufferFloat16AtomicAdd == VK_TRUE) && (query.shaderBufferFloat16AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat16AtomicAdd, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderBufferFloat16AtomicAdd = VK_FALSE;
                }
                if ((currentNext->shaderBufferFloat16AtomicMinMax == VK_TRUE) && (query.shaderBufferFloat16AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat16AtomicMinMax, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderBufferFloat16AtomicMinMax = VK_FALSE;
                }
                if ((currentNext->shaderBufferFloat32AtomicMinMax == VK_TRUE) && (query.shaderBufferFloat32AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat32AtomicMinMax, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderBufferFloat32AtomicMinMax = VK_FALSE;
                }
                if ((currentNext->shaderBufferFloat64AtomicMinMax == VK_TRUE) && (query.shaderBufferFloat64AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat64AtomicMinMax, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderBufferFloat64AtomicMinMax = VK_FALSE;
                }
                if ((currentNext->shaderSharedFloat16Atomics == VK_TRUE) && (query.shaderSharedFloat16Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat16Atomics, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderSharedFloat16Atomics = VK_FALSE;
                }
                if ((currentNext->shaderSharedFloat16AtomicAdd == VK_TRUE) && (query.shaderSharedFloat16AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat16AtomicAdd, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderSharedFloat16AtomicAdd = VK_FALSE;
                }
                if ((currentNext->shaderSharedFloat16AtomicMinMax == VK_TRUE) && (query.shaderSharedFloat16AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat16AtomicMinMax, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderSharedFloat16AtomicMinMax = VK_FALSE;
                }
                if ((currentNext->shaderSharedFloat32AtomicMinMax == VK_TRUE) && (query.shaderSharedFloat32AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat32AtomicMinMax, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderSharedFloat32AtomicMinMax = VK_FALSE;
                }
                if ((currentNext->shaderSharedFloat64AtomicMinMax == VK_TRUE) && (query.shaderSharedFloat64AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat64AtomicMinMax, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderSharedFloat64AtomicMinMax = VK_FALSE;
                }
                if ((currentNext->shaderImageFloat32AtomicMinMax == VK_TRUE) && (query.shaderImageFloat32AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderImageFloat32AtomicMinMax, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderImageFloat32AtomicMinMax = VK_FALSE;
                }
                if ((currentNext->sparseImageFloat32AtomicMinMax == VK_TRUE) && (query.sparseImageFloat32AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature sparseImageFloat32AtomicMinMax, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->sparseImageFloat32AtomicMinMax = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            {
                const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(next);
                VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->deviceGeneratedCommands == VK_TRUE) && (query.deviceGeneratedCommands == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature deviceGeneratedCommands, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(currentNext)->deviceGeneratedCommands = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            {
                const VkPhysicalDeviceInheritedViewportScissorFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(next);
                VkPhysicalDeviceInheritedViewportScissorFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->inheritedViewportScissor2D == VK_TRUE) && (query.inheritedViewportScissor2D == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature inheritedViewportScissor2D, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(currentNext)->inheritedViewportScissor2D = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            {
                const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(next);
                VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->texelBufferAlignment == VK_TRUE) && (query.texelBufferAlignment == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature texelBufferAlignment, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(currentNext)->texelBufferAlignment = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            {
                const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(next);
                VkPhysicalDeviceDeviceMemoryReportFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->deviceMemoryReport == VK_TRUE) && (query.deviceMemoryReport == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature deviceMemoryReport, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(currentNext)->deviceMemoryReport = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
            {
                const VkPhysicalDeviceRobustness2FeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesEXT*>(next);
                VkPhysicalDeviceRobustness2FeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->robustBufferAccess2 == VK_TRUE) && (query.robustBufferAccess2 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature robustBufferAccess2, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRobustness2FeaturesEXT*>(currentNext)->robustBufferAccess2 = VK_FALSE;
                }
                if ((currentNext->robustImageAccess2 == VK_TRUE) && (query.robustImageAccess2 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature robustImageAccess2, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRobustness2FeaturesEXT*>(currentNext)->robustImageAccess2 = VK_FALSE;
                }
                if ((currentNext->nullDescriptor == VK_TRUE) && (query.nullDescriptor == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature nullDescriptor, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRobustness2FeaturesEXT*>(currentNext)->nullDescriptor = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            {
                const VkPhysicalDeviceCustomBorderColorFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(next);
                VkPhysicalDeviceCustomBorderColorFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->customBorderColors == VK_TRUE) && (query.customBorderColors == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature customBorderColors, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(currentNext)->customBorderColors = VK_FALSE;
                }
                if ((currentNext->customBorderColorWithoutFormat == VK_TRUE) && (query.customBorderColorWithoutFormat == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature customBorderColorWithoutFormat, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(currentNext)->customBorderColorWithoutFormat = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            {
                const VkPhysicalDevicePresentBarrierFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDevicePresentBarrierFeaturesNV*>(next);
                VkPhysicalDevicePresentBarrierFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->presentBarrier == VK_TRUE) && (query.presentBarrier == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature presentBarrier, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePresentBarrierFeaturesNV*>(currentNext)->presentBarrier = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            {
                const VkPhysicalDeviceDiagnosticsConfigFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(next);
                VkPhysicalDeviceDiagnosticsConfigFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->diagnosticsConfig == VK_TRUE) && (query.diagnosticsConfig == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature diagnosticsConfig, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(currentNext)->diagnosticsConfig = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            {
                const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(next);
                VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->graphicsPipelineLibrary == VK_TRUE) && (query.graphicsPipelineLibrary == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature graphicsPipelineLibrary, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(currentNext)->graphicsPipelineLibrary = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            {
                const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(next);
                VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderEarlyAndLateFragmentTests == VK_TRUE) && (query.shaderEarlyAndLateFragmentTests == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderEarlyAndLateFragmentTests, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(currentNext)->shaderEarlyAndLateFragmentTests = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            {
                const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(next);
                VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->fragmentShadingRateEnums == VK_TRUE) && (query.fragmentShadingRateEnums == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentShadingRateEnums, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(currentNext)->fragmentShadingRateEnums = VK_FALSE;
                }
                if ((currentNext->supersampleFragmentShadingRates == VK_TRUE) && (query.supersampleFragmentShadingRates == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature supersampleFragmentShadingRates, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(currentNext)->supersampleFragmentShadingRates = VK_FALSE;
                }
                if ((currentNext->noInvocationFragmentShadingRates == VK_TRUE) && (query.noInvocationFragmentShadingRates == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature noInvocationFragmentShadingRates, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(currentNext)->noInvocationFragmentShadingRates = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            {
                const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(next);
                VkPhysicalDeviceRayTracingMotionBlurFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->rayTracingMotionBlur == VK_TRUE) && (query.rayTracingMotionBlur == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingMotionBlur, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(currentNext)->rayTracingMotionBlur = VK_FALSE;
                }
                if ((currentNext->rayTracingMotionBlurPipelineTraceRaysIndirect == VK_TRUE) && (query.rayTracingMotionBlurPipelineTraceRaysIndirect == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingMotionBlurPipelineTraceRaysIndirect, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(currentNext)->rayTracingMotionBlurPipelineTraceRaysIndirect = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            {
                const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(next);
                VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->ycbcr2plane444Formats == VK_TRUE) && (query.ycbcr2plane444Formats == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature ycbcr2plane444Formats, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(currentNext)->ycbcr2plane444Formats = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            {
                const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(next);
                VkPhysicalDeviceFragmentDensityMap2FeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->fragmentDensityMapDeferred == VK_TRUE) && (query.fragmentDensityMapDeferred == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentDensityMapDeferred, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(currentNext)->fragmentDensityMapDeferred = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            {
                const VkPhysicalDeviceImageCompressionControlFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(next);
                VkPhysicalDeviceImageCompressionControlFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->imageCompressionControl == VK_TRUE) && (query.imageCompressionControl == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature imageCompressionControl, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(currentNext)->imageCompressionControl = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            {
                const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(next);
                VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->attachmentFeedbackLoopLayout == VK_TRUE) && (query.attachmentFeedbackLoopLayout == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature attachmentFeedbackLoopLayout, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(currentNext)->attachmentFeedbackLoopLayout = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            {
                const VkPhysicalDevice4444FormatsFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(next);
                VkPhysicalDevice4444FormatsFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->formatA4R4G4B4 == VK_TRUE) && (query.formatA4R4G4B4 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature formatA4R4G4B4, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevice4444FormatsFeaturesEXT*>(currentNext)->formatA4R4G4B4 = VK_FALSE;
                }
                if ((currentNext->formatA4B4G4R4 == VK_TRUE) && (query.formatA4B4G4R4 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature formatA4B4G4R4, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevice4444FormatsFeaturesEXT*>(currentNext)->formatA4B4G4R4 = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            {
                const VkPhysicalDeviceFaultFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceFaultFeaturesEXT*>(next);
                VkPhysicalDeviceFaultFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->deviceFault == VK_TRUE) && (query.deviceFault == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature deviceFault, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFaultFeaturesEXT*>(currentNext)->deviceFault = VK_FALSE;
                }
                if ((currentNext->deviceFaultVendorBinary == VK_TRUE) && (query.deviceFaultVendorBinary == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature deviceFaultVendorBinary, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFaultFeaturesEXT*>(currentNext)->deviceFaultVendorBinary = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
            {
                const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(next);
                VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->rasterizationOrderColorAttachmentAccess == VK_TRUE) && (query.rasterizationOrderColorAttachmentAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rasterizationOrderColorAttachmentAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(currentNext)->rasterizationOrderColorAttachmentAccess = VK_FALSE;
                }
                if ((currentNext->rasterizationOrderDepthAttachmentAccess == VK_TRUE) && (query.rasterizationOrderDepthAttachmentAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rasterizationOrderDepthAttachmentAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(currentNext)->rasterizationOrderDepthAttachmentAccess = VK_FALSE;
                }
                if ((currentNext->rasterizationOrderStencilAttachmentAccess == VK_TRUE) && (query.rasterizationOrderStencilAttachmentAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rasterizationOrderStencilAttachmentAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(currentNext)->rasterizationOrderStencilAttachmentAccess = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            {
                const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(next);
                VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->formatRgba10x6WithoutYCbCrSampler == VK_TRUE) && (query.formatRgba10x6WithoutYCbCrSampler == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature formatRgba10x6WithoutYCbCrSampler, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(currentNext)->formatRgba10x6WithoutYCbCrSampler = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
            {
                const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(next);
                VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->mutableDescriptorType == VK_TRUE) && (query.mutableDescriptorType == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature mutableDescriptorType, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(currentNext)->mutableDescriptorType = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            {
                const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(next);
                VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->vertexInputDynamicState == VK_TRUE) && (query.vertexInputDynamicState == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vertexInputDynamicState, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(currentNext)->vertexInputDynamicState = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            {
                const VkPhysicalDeviceAddressBindingReportFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(next);
                VkPhysicalDeviceAddressBindingReportFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->reportAddressBinding == VK_TRUE) && (query.reportAddressBinding == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature reportAddressBinding, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(currentNext)->reportAddressBinding = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            {
                const VkPhysicalDeviceDepthClipControlFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(next);
                VkPhysicalDeviceDepthClipControlFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->depthClipControl == VK_TRUE) && (query.depthClipControl == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature depthClipControl, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDepthClipControlFeaturesEXT*>(currentNext)->depthClipControl = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            {
                const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(next);
                VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->primitiveTopologyListRestart == VK_TRUE) && (query.primitiveTopologyListRestart == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature primitiveTopologyListRestart, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(currentNext)->primitiveTopologyListRestart = VK_FALSE;
                }
                if ((currentNext->primitiveTopologyPatchListRestart == VK_TRUE) && (query.primitiveTopologyPatchListRestart == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature primitiveTopologyPatchListRestart, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(currentNext)->primitiveTopologyPatchListRestart = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            {
                const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* currentNext = reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(next);
                VkPhysicalDeviceInvocationMaskFeaturesHUAWEI query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->invocationMask == VK_TRUE) && (query.invocationMask == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature invocationMask, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(currentNext)->invocationMask = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            {
                const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(next);
                VkPhysicalDeviceExternalMemoryRDMAFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->externalMemoryRDMA == VK_TRUE) && (query.externalMemoryRDMA == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature externalMemoryRDMA, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(currentNext)->externalMemoryRDMA = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            {
                const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(next);
                VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->multisampledRenderToSingleSampled == VK_TRUE) && (query.multisampledRenderToSingleSampled == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multisampledRenderToSingleSampled, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(currentNext)->multisampledRenderToSingleSampled = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            {
                const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(next);
                VkPhysicalDeviceExtendedDynamicState2FeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->extendedDynamicState2 == VK_TRUE) && (query.extendedDynamicState2 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState2, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(currentNext)->extendedDynamicState2 = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState2LogicOp == VK_TRUE) && (query.extendedDynamicState2LogicOp == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState2LogicOp, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(currentNext)->extendedDynamicState2LogicOp = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState2PatchControlPoints == VK_TRUE) && (query.extendedDynamicState2PatchControlPoints == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState2PatchControlPoints, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(currentNext)->extendedDynamicState2PatchControlPoints = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            {
                const VkPhysicalDeviceColorWriteEnableFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(next);
                VkPhysicalDeviceColorWriteEnableFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->colorWriteEnable == VK_TRUE) && (query.colorWriteEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature colorWriteEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(currentNext)->colorWriteEnable = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            {
                const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(next);
                VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->primitivesGeneratedQuery == VK_TRUE) && (query.primitivesGeneratedQuery == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature primitivesGeneratedQuery, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(currentNext)->primitivesGeneratedQuery = VK_FALSE;
                }
                if ((currentNext->primitivesGeneratedQueryWithRasterizerDiscard == VK_TRUE) && (query.primitivesGeneratedQueryWithRasterizerDiscard == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature primitivesGeneratedQueryWithRasterizerDiscard, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(currentNext)->primitivesGeneratedQueryWithRasterizerDiscard = VK_FALSE;
                }
                if ((currentNext->primitivesGeneratedQueryWithNonZeroStreams == VK_TRUE) && (query.primitivesGeneratedQueryWithNonZeroStreams == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature primitivesGeneratedQueryWithNonZeroStreams, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(currentNext)->primitivesGeneratedQueryWithNonZeroStreams = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            {
                const VkPhysicalDeviceImageViewMinLodFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(next);
                VkPhysicalDeviceImageViewMinLodFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->minLod == VK_TRUE) && (query.minLod == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature minLod, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(currentNext)->minLod = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            {
                const VkPhysicalDeviceMultiDrawFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(next);
                VkPhysicalDeviceMultiDrawFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->multiDraw == VK_TRUE) && (query.multiDraw == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiDraw, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMultiDrawFeaturesEXT*>(currentNext)->multiDraw = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            {
                const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(next);
                VkPhysicalDeviceImage2DViewOf3DFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->image2DViewOf3D == VK_TRUE) && (query.image2DViewOf3D == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature image2DViewOf3D, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(currentNext)->image2DViewOf3D = VK_FALSE;
                }
                if ((currentNext->sampler2DViewOf3D == VK_TRUE) && (query.sampler2DViewOf3D == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature sampler2DViewOf3D, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(currentNext)->sampler2DViewOf3D = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
            {
                const VkPhysicalDeviceOpacityMicromapFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(next);
                VkPhysicalDeviceOpacityMicromapFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->micromap == VK_TRUE) && (query.micromap == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature micromap, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(currentNext)->micromap = VK_FALSE;
                }
                if ((currentNext->micromapCaptureReplay == VK_TRUE) && (query.micromapCaptureReplay == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature micromapCaptureReplay, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(currentNext)->micromapCaptureReplay = VK_FALSE;
                }
                if ((currentNext->micromapHostCommands == VK_TRUE) && (query.micromapHostCommands == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature micromapHostCommands, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(currentNext)->micromapHostCommands = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            {
                const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(next);
                VkPhysicalDeviceBorderColorSwizzleFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->borderColorSwizzle == VK_TRUE) && (query.borderColorSwizzle == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature borderColorSwizzle, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(currentNext)->borderColorSwizzle = VK_FALSE;
                }
                if ((currentNext->borderColorSwizzleFromImage == VK_TRUE) && (query.borderColorSwizzleFromImage == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature borderColorSwizzleFromImage, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(currentNext)->borderColorSwizzleFromImage = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            {
                const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(next);
                VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->pageableDeviceLocalMemory == VK_TRUE) && (query.pageableDeviceLocalMemory == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature pageableDeviceLocalMemory, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(currentNext)->pageableDeviceLocalMemory = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            {
                const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* currentNext = reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(next);
                VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->descriptorSetHostMapping == VK_TRUE) && (query.descriptorSetHostMapping == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorSetHostMapping, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(currentNext)->descriptorSetHostMapping = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT:
            {
                const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT*>(next);
                VkPhysicalDeviceDepthClampZeroOneFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->depthClampZeroOne == VK_TRUE) && (query.depthClampZeroOne == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature depthClampZeroOne, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceDepthClampZeroOneFeaturesEXT*>(currentNext)->depthClampZeroOne = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            {
                const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(next);
                VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->nonSeamlessCubeMap == VK_TRUE) && (query.nonSeamlessCubeMap == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature nonSeamlessCubeMap, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(currentNext)->nonSeamlessCubeMap = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM:
            {
                const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* currentNext = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM*>(next);
                VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->fragmentDensityMapOffset == VK_TRUE) && (query.fragmentDensityMapOffset == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentDensityMapOffset, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM*>(currentNext)->fragmentDensityMapOffset = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            {
                const VkPhysicalDeviceLinearColorAttachmentFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(next);
                VkPhysicalDeviceLinearColorAttachmentFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->linearColorAttachment == VK_TRUE) && (query.linearColorAttachment == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature linearColorAttachment, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(currentNext)->linearColorAttachment = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            {
                const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(next);
                VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->imageCompressionControlSwapchain == VK_TRUE) && (query.imageCompressionControlSwapchain == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature imageCompressionControlSwapchain, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(currentNext)->imageCompressionControlSwapchain = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
            {
                const VkPhysicalDeviceImageProcessingFeaturesQCOM* currentNext = reinterpret_cast<const VkPhysicalDeviceImageProcessingFeaturesQCOM*>(next);
                VkPhysicalDeviceImageProcessingFeaturesQCOM query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->textureSampleWeighted == VK_TRUE) && (query.textureSampleWeighted == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature textureSampleWeighted, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceImageProcessingFeaturesQCOM*>(currentNext)->textureSampleWeighted = VK_FALSE;
                }
                if ((currentNext->textureBoxFilter == VK_TRUE) && (query.textureBoxFilter == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature textureBoxFilter, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceImageProcessingFeaturesQCOM*>(currentNext)->textureBoxFilter = VK_FALSE;
                }
                if ((currentNext->textureBlockMatch == VK_TRUE) && (query.textureBlockMatch == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature textureBlockMatch, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceImageProcessingFeaturesQCOM*>(currentNext)->textureBlockMatch = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
            {
                const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(next);
                VkPhysicalDeviceExtendedDynamicState3FeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->extendedDynamicState3TessellationDomainOrigin == VK_TRUE) && (query.extendedDynamicState3TessellationDomainOrigin == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3TessellationDomainOrigin, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3TessellationDomainOrigin = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3DepthClampEnable == VK_TRUE) && (query.extendedDynamicState3DepthClampEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3DepthClampEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3DepthClampEnable = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3PolygonMode == VK_TRUE) && (query.extendedDynamicState3PolygonMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3PolygonMode, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3PolygonMode = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3RasterizationSamples == VK_TRUE) && (query.extendedDynamicState3RasterizationSamples == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3RasterizationSamples, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3RasterizationSamples = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3SampleMask == VK_TRUE) && (query.extendedDynamicState3SampleMask == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3SampleMask, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3SampleMask = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3AlphaToCoverageEnable == VK_TRUE) && (query.extendedDynamicState3AlphaToCoverageEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3AlphaToCoverageEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3AlphaToCoverageEnable = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3AlphaToOneEnable == VK_TRUE) && (query.extendedDynamicState3AlphaToOneEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3AlphaToOneEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3AlphaToOneEnable = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3LogicOpEnable == VK_TRUE) && (query.extendedDynamicState3LogicOpEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3LogicOpEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3LogicOpEnable = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3ColorBlendEnable == VK_TRUE) && (query.extendedDynamicState3ColorBlendEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ColorBlendEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ColorBlendEnable = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3ColorBlendEquation == VK_TRUE) && (query.extendedDynamicState3ColorBlendEquation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ColorBlendEquation, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ColorBlendEquation = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3ColorWriteMask == VK_TRUE) && (query.extendedDynamicState3ColorWriteMask == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ColorWriteMask, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ColorWriteMask = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3RasterizationStream == VK_TRUE) && (query.extendedDynamicState3RasterizationStream == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3RasterizationStream, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3RasterizationStream = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3ConservativeRasterizationMode == VK_TRUE) && (query.extendedDynamicState3ConservativeRasterizationMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ConservativeRasterizationMode, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ConservativeRasterizationMode = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3ExtraPrimitiveOverestimationSize == VK_TRUE) && (query.extendedDynamicState3ExtraPrimitiveOverestimationSize == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ExtraPrimitiveOverestimationSize, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ExtraPrimitiveOverestimationSize = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3DepthClipEnable == VK_TRUE) && (query.extendedDynamicState3DepthClipEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3DepthClipEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3DepthClipEnable = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3SampleLocationsEnable == VK_TRUE) && (query.extendedDynamicState3SampleLocationsEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3SampleLocationsEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3SampleLocationsEnable = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3ColorBlendAdvanced == VK_TRUE) && (query.extendedDynamicState3ColorBlendAdvanced == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ColorBlendAdvanced, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ColorBlendAdvanced = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3ProvokingVertexMode == VK_TRUE) && (query.extendedDynamicState3ProvokingVertexMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ProvokingVertexMode, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ProvokingVertexMode = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3LineRasterizationMode == VK_TRUE) && (query.extendedDynamicState3LineRasterizationMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3LineRasterizationMode, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3LineRasterizationMode = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3LineStippleEnable == VK_TRUE) && (query.extendedDynamicState3LineStippleEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3LineStippleEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3LineStippleEnable = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3DepthClipNegativeOneToOne == VK_TRUE) && (query.extendedDynamicState3DepthClipNegativeOneToOne == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3DepthClipNegativeOneToOne, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3DepthClipNegativeOneToOne = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3ViewportWScalingEnable == VK_TRUE) && (query.extendedDynamicState3ViewportWScalingEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ViewportWScalingEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ViewportWScalingEnable = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3ViewportSwizzle == VK_TRUE) && (query.extendedDynamicState3ViewportSwizzle == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ViewportSwizzle, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ViewportSwizzle = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3CoverageToColorEnable == VK_TRUE) && (query.extendedDynamicState3CoverageToColorEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3CoverageToColorEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3CoverageToColorEnable = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3CoverageToColorLocation == VK_TRUE) && (query.extendedDynamicState3CoverageToColorLocation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3CoverageToColorLocation, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3CoverageToColorLocation = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3CoverageModulationMode == VK_TRUE) && (query.extendedDynamicState3CoverageModulationMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3CoverageModulationMode, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3CoverageModulationMode = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3CoverageModulationTableEnable == VK_TRUE) && (query.extendedDynamicState3CoverageModulationTableEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3CoverageModulationTableEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3CoverageModulationTableEnable = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3CoverageModulationTable == VK_TRUE) && (query.extendedDynamicState3CoverageModulationTable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3CoverageModulationTable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3CoverageModulationTable = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3CoverageReductionMode == VK_TRUE) && (query.extendedDynamicState3CoverageReductionMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3CoverageReductionMode, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3CoverageReductionMode = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3RepresentativeFragmentTestEnable == VK_TRUE) && (query.extendedDynamicState3RepresentativeFragmentTestEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3RepresentativeFragmentTestEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3RepresentativeFragmentTestEnable = VK_FALSE;
                }
                if ((currentNext->extendedDynamicState3ShadingRateImageEnable == VK_TRUE) && (query.extendedDynamicState3ShadingRateImageEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ShadingRateImageEnable, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ShadingRateImageEnable = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            {
                const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(next);
                VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->subpassMergeFeedback == VK_TRUE) && (query.subpassMergeFeedback == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature subpassMergeFeedback, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(currentNext)->subpassMergeFeedback = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
            {
                const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(next);
                VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderModuleIdentifier == VK_TRUE) && (query.shaderModuleIdentifier == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderModuleIdentifier, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(currentNext)->shaderModuleIdentifier = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
            {
                const VkPhysicalDeviceOpticalFlowFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceOpticalFlowFeaturesNV*>(next);
                VkPhysicalDeviceOpticalFlowFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->opticalFlow == VK_TRUE) && (query.opticalFlow == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature opticalFlow, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceOpticalFlowFeaturesNV*>(currentNext)->opticalFlow = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            {
                const VkPhysicalDeviceLegacyDitheringFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(next);
                VkPhysicalDeviceLegacyDitheringFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->legacyDithering == VK_TRUE) && (query.legacyDithering == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature legacyDithering, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(currentNext)->legacyDithering = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT:
            {
                const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT*>(next);
                VkPhysicalDevicePipelineProtectedAccessFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->pipelineProtectedAccess == VK_TRUE) && (query.pipelineProtectedAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature pipelineProtectedAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePipelineProtectedAccessFeaturesEXT*>(currentNext)->pipelineProtectedAccess = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            {
                const VkPhysicalDeviceTilePropertiesFeaturesQCOM* currentNext = reinterpret_cast<const VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(next);
                VkPhysicalDeviceTilePropertiesFeaturesQCOM query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->tileProperties == VK_TRUE) && (query.tileProperties == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature tileProperties, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(currentNext)->tileProperties = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            {
                const VkPhysicalDeviceAmigoProfilingFeaturesSEC* currentNext = reinterpret_cast<const VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(next);
                VkPhysicalDeviceAmigoProfilingFeaturesSEC query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->amigoProfiling == VK_TRUE) && (query.amigoProfiling == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature amigoProfiling, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(currentNext)->amigoProfiling = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
            {
                const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(next);
                VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderCoreBuiltins == VK_TRUE) && (query.shaderCoreBuiltins == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderCoreBuiltins, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(currentNext)->shaderCoreBuiltins = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            {
                const VkPhysicalDeviceAccelerationStructureFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(next);
                VkPhysicalDeviceAccelerationStructureFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->accelerationStructure == VK_TRUE) && (query.accelerationStructure == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature accelerationStructure, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(currentNext)->accelerationStructure = VK_FALSE;
                }
                if ((currentNext->accelerationStructureCaptureReplay == VK_TRUE) && (query.accelerationStructureCaptureReplay == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature accelerationStructureCaptureReplay, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(currentNext)->accelerationStructureCaptureReplay = VK_FALSE;
                }
                if ((currentNext->accelerationStructureIndirectBuild == VK_TRUE) && (query.accelerationStructureIndirectBuild == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature accelerationStructureIndirectBuild, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(currentNext)->accelerationStructureIndirectBuild = VK_FALSE;
                }
                if ((currentNext->accelerationStructureHostCommands == VK_TRUE) && (query.accelerationStructureHostCommands == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature accelerationStructureHostCommands, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(currentNext)->accelerationStructureHostCommands = VK_FALSE;
                }
                if ((currentNext->descriptorBindingAccelerationStructureUpdateAfterBind == VK_TRUE) && (query.descriptorBindingAccelerationStructureUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingAccelerationStructureUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(currentNext)->descriptorBindingAccelerationStructureUpdateAfterBind = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            {
                const VkPhysicalDeviceRayTracingPipelineFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(next);
                VkPhysicalDeviceRayTracingPipelineFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->rayTracingPipeline == VK_TRUE) && (query.rayTracingPipeline == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingPipeline, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(currentNext)->rayTracingPipeline = VK_FALSE;
                }
                if ((currentNext->rayTracingPipelineShaderGroupHandleCaptureReplay == VK_TRUE) && (query.rayTracingPipelineShaderGroupHandleCaptureReplay == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingPipelineShaderGroupHandleCaptureReplay, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(currentNext)->rayTracingPipelineShaderGroupHandleCaptureReplay = VK_FALSE;
                }
                if ((currentNext->rayTracingPipelineShaderGroupHandleCaptureReplayMixed == VK_TRUE) && (query.rayTracingPipelineShaderGroupHandleCaptureReplayMixed == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingPipelineShaderGroupHandleCaptureReplayMixed, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(currentNext)->rayTracingPipelineShaderGroupHandleCaptureReplayMixed = VK_FALSE;
                }
                if ((currentNext->rayTracingPipelineTraceRaysIndirect == VK_TRUE) && (query.rayTracingPipelineTraceRaysIndirect == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingPipelineTraceRaysIndirect, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(currentNext)->rayTracingPipelineTraceRaysIndirect = VK_FALSE;
                }
                if ((currentNext->rayTraversalPrimitiveCulling == VK_TRUE) && (query.rayTraversalPrimitiveCulling == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTraversalPrimitiveCulling, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(currentNext)->rayTraversalPrimitiveCulling = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            {
                const VkPhysicalDeviceRayQueryFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(next);
                VkPhysicalDeviceRayQueryFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->rayQuery == VK_TRUE) && (query.rayQuery == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayQuery, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceRayQueryFeaturesKHR*>(currentNext)->rayQuery = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            {
                const VkPhysicalDeviceMeshShaderFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesEXT*>(next);
                VkPhysicalDeviceMeshShaderFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->taskShader == VK_TRUE) && (query.taskShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature taskShader, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesEXT*>(currentNext)->taskShader = VK_FALSE;
                }
                if ((currentNext->meshShader == VK_TRUE) && (query.meshShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature meshShader, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesEXT*>(currentNext)->meshShader = VK_FALSE;
                }
                if ((currentNext->multiviewMeshShader == VK_TRUE) && (query.multiviewMeshShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiviewMeshShader, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesEXT*>(currentNext)->multiviewMeshShader = VK_FALSE;
                }
                if ((currentNext->primitiveFragmentShadingRateMeshShader == VK_TRUE) && (query.primitiveFragmentShadingRateMeshShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature primitiveFragmentShadingRateMeshShader, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesEXT*>(currentNext)->primitiveFragmentShadingRateMeshShader = VK_FALSE;
                }
                if ((currentNext->meshShaderQueries == VK_TRUE) && (query.meshShaderQueries == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature meshShaderQueries, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesEXT*>(currentNext)->meshShaderQueries = VK_FALSE;
                }
                break;
             }
             default:
                break;
            }
            next = reinterpret_cast<const VkDeviceCreateInfo*>(next->pNext);
        }
    }

    if ((GetPhysicalDeviceFeatures != nullptr) && (physicalDeviceFeatures != nullptr))
    {
        VkPhysicalDeviceFeatures query = {};
        GetPhysicalDeviceFeatures(physicalDevice, &query);
        if ((physicalDeviceFeatures->robustBufferAccess == VK_TRUE) && (query.robustBufferAccess == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature robustBufferAccess, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->robustBufferAccess = VK_FALSE;
        }
        if ((physicalDeviceFeatures->fullDrawIndexUint32 == VK_TRUE) && (query.fullDrawIndexUint32 == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature fullDrawIndexUint32, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->fullDrawIndexUint32 = VK_FALSE;
        }
        if ((physicalDeviceFeatures->imageCubeArray == VK_TRUE) && (query.imageCubeArray == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature imageCubeArray, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->imageCubeArray = VK_FALSE;
        }
        if ((physicalDeviceFeatures->independentBlend == VK_TRUE) && (query.independentBlend == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature independentBlend, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->independentBlend = VK_FALSE;
        }
        if ((physicalDeviceFeatures->geometryShader == VK_TRUE) && (query.geometryShader == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature geometryShader, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->geometryShader = VK_FALSE;
        }
        if ((physicalDeviceFeatures->tessellationShader == VK_TRUE) && (query.tessellationShader == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature tessellationShader, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->tessellationShader = VK_FALSE;
        }
        if ((physicalDeviceFeatures->sampleRateShading == VK_TRUE) && (query.sampleRateShading == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sampleRateShading, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sampleRateShading = VK_FALSE;
        }
        if ((physicalDeviceFeatures->dualSrcBlend == VK_TRUE) && (query.dualSrcBlend == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature dualSrcBlend, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->dualSrcBlend = VK_FALSE;
        }
        if ((physicalDeviceFeatures->logicOp == VK_TRUE) && (query.logicOp == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature logicOp, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->logicOp = VK_FALSE;
        }
        if ((physicalDeviceFeatures->multiDrawIndirect == VK_TRUE) && (query.multiDrawIndirect == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature multiDrawIndirect, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->multiDrawIndirect = VK_FALSE;
        }
        if ((physicalDeviceFeatures->drawIndirectFirstInstance == VK_TRUE) && (query.drawIndirectFirstInstance == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature drawIndirectFirstInstance, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->drawIndirectFirstInstance = VK_FALSE;
        }
        if ((physicalDeviceFeatures->depthClamp == VK_TRUE) && (query.depthClamp == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature depthClamp, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->depthClamp = VK_FALSE;
        }
        if ((physicalDeviceFeatures->depthBiasClamp == VK_TRUE) && (query.depthBiasClamp == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature depthBiasClamp, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->depthBiasClamp = VK_FALSE;
        }
        if ((physicalDeviceFeatures->fillModeNonSolid == VK_TRUE) && (query.fillModeNonSolid == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature fillModeNonSolid, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->fillModeNonSolid = VK_FALSE;
        }
        if ((physicalDeviceFeatures->depthBounds == VK_TRUE) && (query.depthBounds == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature depthBounds, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->depthBounds = VK_FALSE;
        }
        if ((physicalDeviceFeatures->wideLines == VK_TRUE) && (query.wideLines == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature wideLines, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->wideLines = VK_FALSE;
        }
        if ((physicalDeviceFeatures->largePoints == VK_TRUE) && (query.largePoints == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature largePoints, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->largePoints = VK_FALSE;
        }
        if ((physicalDeviceFeatures->alphaToOne == VK_TRUE) && (query.alphaToOne == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature alphaToOne, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->alphaToOne = VK_FALSE;
        }
        if ((physicalDeviceFeatures->multiViewport == VK_TRUE) && (query.multiViewport == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature multiViewport, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->multiViewport = VK_FALSE;
        }
        if ((physicalDeviceFeatures->samplerAnisotropy == VK_TRUE) && (query.samplerAnisotropy == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature samplerAnisotropy, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->samplerAnisotropy = VK_FALSE;
        }
        if ((physicalDeviceFeatures->textureCompressionETC2 == VK_TRUE) && (query.textureCompressionETC2 == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature textureCompressionETC2, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->textureCompressionETC2 = VK_FALSE;
        }
        if ((physicalDeviceFeatures->textureCompressionASTC_LDR == VK_TRUE) && (query.textureCompressionASTC_LDR == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature textureCompressionASTC_LDR, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->textureCompressionASTC_LDR = VK_FALSE;
        }
        if ((physicalDeviceFeatures->textureCompressionBC == VK_TRUE) && (query.textureCompressionBC == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature textureCompressionBC, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->textureCompressionBC = VK_FALSE;
        }
        if ((physicalDeviceFeatures->occlusionQueryPrecise == VK_TRUE) && (query.occlusionQueryPrecise == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature occlusionQueryPrecise, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->occlusionQueryPrecise = VK_FALSE;
        }
        if ((physicalDeviceFeatures->pipelineStatisticsQuery == VK_TRUE) && (query.pipelineStatisticsQuery == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature pipelineStatisticsQuery, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->pipelineStatisticsQuery = VK_FALSE;
        }
        if ((physicalDeviceFeatures->vertexPipelineStoresAndAtomics == VK_TRUE) && (query.vertexPipelineStoresAndAtomics == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature vertexPipelineStoresAndAtomics, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->vertexPipelineStoresAndAtomics = VK_FALSE;
        }
        if ((physicalDeviceFeatures->fragmentStoresAndAtomics == VK_TRUE) && (query.fragmentStoresAndAtomics == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature fragmentStoresAndAtomics, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->fragmentStoresAndAtomics = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderTessellationAndGeometryPointSize == VK_TRUE) && (query.shaderTessellationAndGeometryPointSize == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderTessellationAndGeometryPointSize, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderTessellationAndGeometryPointSize = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderImageGatherExtended == VK_TRUE) && (query.shaderImageGatherExtended == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderImageGatherExtended, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderImageGatherExtended = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderStorageImageExtendedFormats == VK_TRUE) && (query.shaderStorageImageExtendedFormats == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderStorageImageExtendedFormats, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderStorageImageExtendedFormats = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderStorageImageMultisample == VK_TRUE) && (query.shaderStorageImageMultisample == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderStorageImageMultisample, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderStorageImageMultisample = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderStorageImageReadWithoutFormat == VK_TRUE) && (query.shaderStorageImageReadWithoutFormat == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderStorageImageReadWithoutFormat, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderStorageImageReadWithoutFormat = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderStorageImageWriteWithoutFormat == VK_TRUE) && (query.shaderStorageImageWriteWithoutFormat == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderStorageImageWriteWithoutFormat, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderStorageImageWriteWithoutFormat = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderUniformBufferArrayDynamicIndexing == VK_TRUE) && (query.shaderUniformBufferArrayDynamicIndexing == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderUniformBufferArrayDynamicIndexing, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderUniformBufferArrayDynamicIndexing = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderSampledImageArrayDynamicIndexing == VK_TRUE) && (query.shaderSampledImageArrayDynamicIndexing == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderSampledImageArrayDynamicIndexing, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderSampledImageArrayDynamicIndexing = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderStorageBufferArrayDynamicIndexing == VK_TRUE) && (query.shaderStorageBufferArrayDynamicIndexing == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderStorageBufferArrayDynamicIndexing, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderStorageBufferArrayDynamicIndexing = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderStorageImageArrayDynamicIndexing == VK_TRUE) && (query.shaderStorageImageArrayDynamicIndexing == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderStorageImageArrayDynamicIndexing, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderStorageImageArrayDynamicIndexing = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderClipDistance == VK_TRUE) && (query.shaderClipDistance == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderClipDistance, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderClipDistance = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderCullDistance == VK_TRUE) && (query.shaderCullDistance == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderCullDistance, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderCullDistance = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderFloat64 == VK_TRUE) && (query.shaderFloat64 == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderFloat64, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderFloat64 = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderInt64 == VK_TRUE) && (query.shaderInt64 == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderInt64, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderInt64 = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderInt16 == VK_TRUE) && (query.shaderInt16 == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderInt16, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderInt16 = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderResourceResidency == VK_TRUE) && (query.shaderResourceResidency == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderResourceResidency, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderResourceResidency = VK_FALSE;
        }
        if ((physicalDeviceFeatures->shaderResourceMinLod == VK_TRUE) && (query.shaderResourceMinLod == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderResourceMinLod, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderResourceMinLod = VK_FALSE;
        }
        if ((physicalDeviceFeatures->sparseBinding == VK_TRUE) && (query.sparseBinding == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseBinding, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseBinding = VK_FALSE;
        }
        if ((physicalDeviceFeatures->sparseResidencyBuffer == VK_TRUE) && (query.sparseResidencyBuffer == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidencyBuffer, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidencyBuffer = VK_FALSE;
        }
        if ((physicalDeviceFeatures->sparseResidencyImage2D == VK_TRUE) && (query.sparseResidencyImage2D == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidencyImage2D, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidencyImage2D = VK_FALSE;
        }
        if ((physicalDeviceFeatures->sparseResidencyImage3D == VK_TRUE) && (query.sparseResidencyImage3D == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidencyImage3D, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidencyImage3D = VK_FALSE;
        }
        if ((physicalDeviceFeatures->sparseResidency2Samples == VK_TRUE) && (query.sparseResidency2Samples == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidency2Samples, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidency2Samples = VK_FALSE;
        }
        if ((physicalDeviceFeatures->sparseResidency4Samples == VK_TRUE) && (query.sparseResidency4Samples == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidency4Samples, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidency4Samples = VK_FALSE;
        }
        if ((physicalDeviceFeatures->sparseResidency8Samples == VK_TRUE) && (query.sparseResidency8Samples == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidency8Samples, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidency8Samples = VK_FALSE;
        }
        if ((physicalDeviceFeatures->sparseResidency16Samples == VK_TRUE) && (query.sparseResidency16Samples == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidency16Samples, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidency16Samples = VK_FALSE;
        }
        if ((physicalDeviceFeatures->sparseResidencyAliased == VK_TRUE) && (query.sparseResidencyAliased == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidencyAliased, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidencyAliased = VK_FALSE;
        }
        if ((physicalDeviceFeatures->variableMultisampleRate == VK_TRUE) && (query.variableMultisampleRate == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature variableMultisampleRate, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->variableMultisampleRate = VK_FALSE;
        }
        if ((physicalDeviceFeatures->inheritedQueries == VK_TRUE) && (query.inheritedQueries == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature inheritedQueries, which is not supported by the replay device, will not be enabled");
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->inheritedQueries = VK_FALSE;
        }
    }
}

GFXRECON_END_NAMESPACE(feature_util)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
