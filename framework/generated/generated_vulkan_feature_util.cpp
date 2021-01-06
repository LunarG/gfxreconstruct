/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR:
            {
                const VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR*>(next);
                VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderTerminateInvocation == VK_TRUE) && (query.shaderTerminateInvocation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderTerminateInvocation, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR*>(currentNext)->shaderTerminateInvocation = VK_FALSE;
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT:
            {
                const VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT*>(next);
                VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->textureCompressionASTC_HDR == VK_TRUE) && (query.textureCompressionASTC_HDR == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature textureCompressionASTC_HDR, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT*>(currentNext)->textureCompressionASTC_HDR = VK_FALSE;
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT:
            {
                const VkPhysicalDeviceInlineUniformBlockFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeaturesEXT*>(next);
                VkPhysicalDeviceInlineUniformBlockFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->inlineUniformBlock == VK_TRUE) && (query.inlineUniformBlock == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature inlineUniformBlock, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceInlineUniformBlockFeaturesEXT*>(currentNext)->inlineUniformBlock = VK_FALSE;
                }
                if ((currentNext->descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE) && (query.descriptorBindingInlineUniformBlockUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingInlineUniformBlockUpdateAfterBind, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceInlineUniformBlockFeaturesEXT*>(currentNext)->descriptorBindingInlineUniformBlockUpdateAfterBind = VK_FALSE;
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV:
            {
                const VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV*>(next);
                VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->fragmentShaderBarycentric == VK_TRUE) && (query.fragmentShaderBarycentric == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentShaderBarycentric, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV*>(currentNext)->fragmentShaderBarycentric = VK_FALSE;
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT:
            {
                const VkPhysicalDeviceSubgroupSizeControlFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeaturesEXT*>(next);
                VkPhysicalDeviceSubgroupSizeControlFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->subgroupSizeControl == VK_TRUE) && (query.subgroupSizeControl == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature subgroupSizeControl, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceSubgroupSizeControlFeaturesEXT*>(currentNext)->subgroupSizeControl = VK_FALSE;
                }
                if ((currentNext->computeFullSubgroups == VK_TRUE) && (query.computeFullSubgroups == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature computeFullSubgroups, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceSubgroupSizeControlFeaturesEXT*>(currentNext)->computeFullSubgroups = VK_FALSE;
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT:
            {
                const VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT*>(next);
                VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderDemoteToHelperInvocation == VK_TRUE) && (query.shaderDemoteToHelperInvocation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderDemoteToHelperInvocation, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT*>(currentNext)->shaderDemoteToHelperInvocation = VK_FALSE;
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES_EXT:
            {
                const VkPhysicalDevicePrivateDataFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDevicePrivateDataFeaturesEXT*>(next);
                VkPhysicalDevicePrivateDataFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->privateData == VK_TRUE) && (query.privateData == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature privateData, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePrivateDataFeaturesEXT*>(currentNext)->privateData = VK_FALSE;
                }
                break;
             }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT:
            {
                const VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT*>(next);
                VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->pipelineCreationCacheControl == VK_TRUE) && (query.pipelineCreationCacheControl == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature pipelineCreationCacheControl, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT*>(currentNext)->pipelineCreationCacheControl = VK_FALSE;
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT:
            {
                const VkPhysicalDeviceImageRobustnessFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeaturesEXT*>(next);
                VkPhysicalDeviceImageRobustnessFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->robustImageAccess == VK_TRUE) && (query.robustImageAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature robustImageAccess, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceImageRobustnessFeaturesEXT*>(currentNext)->robustImageAccess = VK_FALSE;
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_VALVE:
            {
                const VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE* currentNext = reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE*>(next);
                VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_VALVE, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->mutableDescriptorType == VK_TRUE) && (query.mutableDescriptorType == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature mutableDescriptorType, which is not supported by the replay device, will not be enabled");
                    const_cast<VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE*>(currentNext)->mutableDescriptorType = VK_FALSE;
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
