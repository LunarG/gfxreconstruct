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

#include "decode/vulkan_feature_util.h"

#include "util/logging.h"

#include "format/platform_types.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(feature_util)

void CheckUnsupportedFeatures(VkPhysicalDevice physicalDevice,
                             PFN_vkGetPhysicalDeviceFeatures  GetPhysicalDeviceFeatures,
                             PFN_vkGetPhysicalDeviceFeatures2 GetPhysicalDeviceFeatures2,
                             const void*                      pNext,
                             const VkPhysicalDeviceFeatures*  pEnabledFeatures,
                             bool                             remove_unsupported)
{
    // If the pNext chain includes a VkPhysicalDeviceFeatures2 structure, then pEnabledFeatures must be NULL
    const VkPhysicalDeviceFeatures* physicalDeviceFeatures = nullptr;
    if (pEnabledFeatures != nullptr)
    {
        physicalDeviceFeatures = pEnabledFeatures;
    }

    bool found_unsupported = false;
    const char* warn_message =
        remove_unsupported ? "requested at capture is not supported by the replay device and it will not be enabled."
                           : "requested at capture is not supported by the replay device.";

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
                    GFXRECON_LOG_WARNING("Feature storageBuffer16BitAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevice16BitStorageFeatures*>(currentNext)->storageBuffer16BitAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->uniformAndStorageBuffer16BitAccess == VK_TRUE) && (query.uniformAndStorageBuffer16BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature uniformAndStorageBuffer16BitAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevice16BitStorageFeatures*>(currentNext)->uniformAndStorageBuffer16BitAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->storagePushConstant16 == VK_TRUE) && (query.storagePushConstant16 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storagePushConstant16 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevice16BitStorageFeatures*>(currentNext)->storagePushConstant16 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->storageInputOutput16 == VK_TRUE) && (query.storageInputOutput16 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storageInputOutput16 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevice16BitStorageFeatures*>(currentNext)->storageInputOutput16 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature multiview %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMultiviewFeatures*>(currentNext)->multiview =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->multiviewGeometryShader == VK_TRUE) && (query.multiviewGeometryShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiviewGeometryShader %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMultiviewFeatures*>(currentNext)->multiviewGeometryShader =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->multiviewTessellationShader == VK_TRUE) && (query.multiviewTessellationShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiviewTessellationShader %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMultiviewFeatures*>(currentNext)->multiviewTessellationShader =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature variablePointersStorageBuffer %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVariablePointersFeatures*>(currentNext)->variablePointersStorageBuffer =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->variablePointers == VK_TRUE) && (query.variablePointers == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature variablePointers %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVariablePointersFeatures*>(currentNext)->variablePointers =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature protectedMemory %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceProtectedMemoryFeatures*>(currentNext)->protectedMemory =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature samplerYcbcrConversion %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(currentNext)->samplerYcbcrConversion =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderDrawParameters %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderDrawParametersFeatures*>(currentNext)->shaderDrawParameters =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature storageBuffer16BitAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->storageBuffer16BitAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->uniformAndStorageBuffer16BitAccess == VK_TRUE) && (query.uniformAndStorageBuffer16BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature uniformAndStorageBuffer16BitAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->uniformAndStorageBuffer16BitAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->storagePushConstant16 == VK_TRUE) && (query.storagePushConstant16 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storagePushConstant16 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->storagePushConstant16 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->storageInputOutput16 == VK_TRUE) && (query.storageInputOutput16 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storageInputOutput16 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->storageInputOutput16 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->multiview == VK_TRUE) && (query.multiview == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiview %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->multiview =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->multiviewGeometryShader == VK_TRUE) && (query.multiviewGeometryShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiviewGeometryShader %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->multiviewGeometryShader =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->multiviewTessellationShader == VK_TRUE) && (query.multiviewTessellationShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiviewTessellationShader %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->multiviewTessellationShader =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->variablePointersStorageBuffer == VK_TRUE) && (query.variablePointersStorageBuffer == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature variablePointersStorageBuffer %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->variablePointersStorageBuffer =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->variablePointers == VK_TRUE) && (query.variablePointers == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature variablePointers %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->variablePointers =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->protectedMemory == VK_TRUE) && (query.protectedMemory == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature protectedMemory %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->protectedMemory =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->samplerYcbcrConversion == VK_TRUE) && (query.samplerYcbcrConversion == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature samplerYcbcrConversion %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->samplerYcbcrConversion =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderDrawParameters == VK_TRUE) && (query.shaderDrawParameters == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderDrawParameters %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan11Features*>(currentNext)->shaderDrawParameters =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature samplerMirrorClampToEdge %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->samplerMirrorClampToEdge =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->drawIndirectCount == VK_TRUE) && (query.drawIndirectCount == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature drawIndirectCount %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->drawIndirectCount =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->storageBuffer8BitAccess == VK_TRUE) && (query.storageBuffer8BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storageBuffer8BitAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->storageBuffer8BitAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->uniformAndStorageBuffer8BitAccess == VK_TRUE) && (query.uniformAndStorageBuffer8BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature uniformAndStorageBuffer8BitAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->uniformAndStorageBuffer8BitAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->storagePushConstant8 == VK_TRUE) && (query.storagePushConstant8 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storagePushConstant8 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->storagePushConstant8 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderBufferInt64Atomics == VK_TRUE) && (query.shaderBufferInt64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferInt64Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderBufferInt64Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSharedInt64Atomics == VK_TRUE) && (query.shaderSharedInt64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedInt64Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderSharedInt64Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderFloat16 == VK_TRUE) && (query.shaderFloat16 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderFloat16 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderFloat16 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderInt8 == VK_TRUE) && (query.shaderInt8 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderInt8 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderInt8 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorIndexing == VK_TRUE) && (query.descriptorIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderInputAttachmentArrayDynamicIndexing == VK_TRUE) && (query.shaderInputAttachmentArrayDynamicIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderInputAttachmentArrayDynamicIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderInputAttachmentArrayDynamicIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderUniformTexelBufferArrayDynamicIndexing == VK_TRUE) && (query.shaderUniformTexelBufferArrayDynamicIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderUniformTexelBufferArrayDynamicIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderUniformTexelBufferArrayDynamicIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderStorageTexelBufferArrayDynamicIndexing == VK_TRUE) && (query.shaderStorageTexelBufferArrayDynamicIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageTexelBufferArrayDynamicIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderStorageTexelBufferArrayDynamicIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderUniformBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderUniformBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderUniformBufferArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderUniformBufferArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSampledImageArrayNonUniformIndexing == VK_TRUE) && (query.shaderSampledImageArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSampledImageArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderSampledImageArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderStorageBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderStorageBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageBufferArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderStorageBufferArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderStorageImageArrayNonUniformIndexing == VK_TRUE) && (query.shaderStorageImageArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageImageArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderStorageImageArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderInputAttachmentArrayNonUniformIndexing == VK_TRUE) && (query.shaderInputAttachmentArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderInputAttachmentArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderInputAttachmentArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderUniformTexelBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderUniformTexelBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderUniformTexelBufferArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderUniformTexelBufferArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderStorageTexelBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderStorageTexelBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageTexelBufferArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderStorageTexelBufferArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingUniformBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingUniformBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingUniformBufferUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingUniformBufferUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingSampledImageUpdateAfterBind == VK_TRUE) && (query.descriptorBindingSampledImageUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingSampledImageUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingSampledImageUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingStorageImageUpdateAfterBind == VK_TRUE) && (query.descriptorBindingStorageImageUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingStorageImageUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingStorageImageUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingStorageBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingStorageBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingStorageBufferUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingStorageBufferUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingUniformTexelBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingUniformTexelBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingUniformTexelBufferUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingUniformTexelBufferUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingStorageTexelBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingStorageTexelBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingStorageTexelBufferUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingStorageTexelBufferUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingUpdateUnusedWhilePending == VK_TRUE) && (query.descriptorBindingUpdateUnusedWhilePending == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingUpdateUnusedWhilePending %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingUpdateUnusedWhilePending =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingPartiallyBound == VK_TRUE) && (query.descriptorBindingPartiallyBound == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingPartiallyBound %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingPartiallyBound =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingVariableDescriptorCount == VK_TRUE) && (query.descriptorBindingVariableDescriptorCount == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingVariableDescriptorCount %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->descriptorBindingVariableDescriptorCount =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->runtimeDescriptorArray == VK_TRUE) && (query.runtimeDescriptorArray == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature runtimeDescriptorArray %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->runtimeDescriptorArray =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->samplerFilterMinmax == VK_TRUE) && (query.samplerFilterMinmax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature samplerFilterMinmax %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->samplerFilterMinmax =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->scalarBlockLayout == VK_TRUE) && (query.scalarBlockLayout == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature scalarBlockLayout %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->scalarBlockLayout =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->imagelessFramebuffer == VK_TRUE) && (query.imagelessFramebuffer == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature imagelessFramebuffer %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->imagelessFramebuffer =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->uniformBufferStandardLayout == VK_TRUE) && (query.uniformBufferStandardLayout == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature uniformBufferStandardLayout %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->uniformBufferStandardLayout =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSubgroupExtendedTypes == VK_TRUE) && (query.shaderSubgroupExtendedTypes == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSubgroupExtendedTypes %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderSubgroupExtendedTypes =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->separateDepthStencilLayouts == VK_TRUE) && (query.separateDepthStencilLayouts == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature separateDepthStencilLayouts %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->separateDepthStencilLayouts =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->hostQueryReset == VK_TRUE) && (query.hostQueryReset == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature hostQueryReset %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->hostQueryReset =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->timelineSemaphore == VK_TRUE) && (query.timelineSemaphore == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature timelineSemaphore %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->timelineSemaphore =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->bufferDeviceAddress == VK_TRUE) && (query.bufferDeviceAddress == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddress %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->bufferDeviceAddress =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->bufferDeviceAddressCaptureReplay == VK_TRUE) && (query.bufferDeviceAddressCaptureReplay == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddressCaptureReplay %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->bufferDeviceAddressCaptureReplay =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->bufferDeviceAddressMultiDevice == VK_TRUE) && (query.bufferDeviceAddressMultiDevice == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddressMultiDevice %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->bufferDeviceAddressMultiDevice =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->vulkanMemoryModel == VK_TRUE) && (query.vulkanMemoryModel == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vulkanMemoryModel %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->vulkanMemoryModel =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->vulkanMemoryModelDeviceScope == VK_TRUE) && (query.vulkanMemoryModelDeviceScope == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vulkanMemoryModelDeviceScope %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->vulkanMemoryModelDeviceScope =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->vulkanMemoryModelAvailabilityVisibilityChains == VK_TRUE) && (query.vulkanMemoryModelAvailabilityVisibilityChains == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vulkanMemoryModelAvailabilityVisibilityChains %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->vulkanMemoryModelAvailabilityVisibilityChains =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderOutputViewportIndex == VK_TRUE) && (query.shaderOutputViewportIndex == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderOutputViewportIndex %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderOutputViewportIndex =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderOutputLayer == VK_TRUE) && (query.shaderOutputLayer == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderOutputLayer %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->shaderOutputLayer =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->subgroupBroadcastDynamicId == VK_TRUE) && (query.subgroupBroadcastDynamicId == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature subgroupBroadcastDynamicId %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan12Features*>(currentNext)->subgroupBroadcastDynamicId =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature storageBuffer8BitAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevice8BitStorageFeatures*>(currentNext)->storageBuffer8BitAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->uniformAndStorageBuffer8BitAccess == VK_TRUE) && (query.uniformAndStorageBuffer8BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature uniformAndStorageBuffer8BitAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevice8BitStorageFeatures*>(currentNext)->uniformAndStorageBuffer8BitAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->storagePushConstant8 == VK_TRUE) && (query.storagePushConstant8 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature storagePushConstant8 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevice8BitStorageFeatures*>(currentNext)->storagePushConstant8 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderBufferInt64Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicInt64Features*>(currentNext)->shaderBufferInt64Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSharedInt64Atomics == VK_TRUE) && (query.shaderSharedInt64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedInt64Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicInt64Features*>(currentNext)->shaderSharedInt64Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderFloat16 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderFloat16Int8Features*>(currentNext)->shaderFloat16 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderInt8 == VK_TRUE) && (query.shaderInt8 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderInt8 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderFloat16Int8Features*>(currentNext)->shaderInt8 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderInputAttachmentArrayDynamicIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderInputAttachmentArrayDynamicIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderUniformTexelBufferArrayDynamicIndexing == VK_TRUE) && (query.shaderUniformTexelBufferArrayDynamicIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderUniformTexelBufferArrayDynamicIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderUniformTexelBufferArrayDynamicIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderStorageTexelBufferArrayDynamicIndexing == VK_TRUE) && (query.shaderStorageTexelBufferArrayDynamicIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageTexelBufferArrayDynamicIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderStorageTexelBufferArrayDynamicIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderUniformBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderUniformBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderUniformBufferArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderUniformBufferArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSampledImageArrayNonUniformIndexing == VK_TRUE) && (query.shaderSampledImageArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSampledImageArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderSampledImageArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderStorageBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderStorageBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageBufferArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderStorageBufferArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderStorageImageArrayNonUniformIndexing == VK_TRUE) && (query.shaderStorageImageArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageImageArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderStorageImageArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderInputAttachmentArrayNonUniformIndexing == VK_TRUE) && (query.shaderInputAttachmentArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderInputAttachmentArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderInputAttachmentArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderUniformTexelBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderUniformTexelBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderUniformTexelBufferArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderUniformTexelBufferArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderStorageTexelBufferArrayNonUniformIndexing == VK_TRUE) && (query.shaderStorageTexelBufferArrayNonUniformIndexing == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderStorageTexelBufferArrayNonUniformIndexing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->shaderStorageTexelBufferArrayNonUniformIndexing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingUniformBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingUniformBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingUniformBufferUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingUniformBufferUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingSampledImageUpdateAfterBind == VK_TRUE) && (query.descriptorBindingSampledImageUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingSampledImageUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingSampledImageUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingStorageImageUpdateAfterBind == VK_TRUE) && (query.descriptorBindingStorageImageUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingStorageImageUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingStorageImageUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingStorageBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingStorageBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingStorageBufferUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingStorageBufferUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingUniformTexelBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingUniformTexelBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingUniformTexelBufferUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingUniformTexelBufferUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingStorageTexelBufferUpdateAfterBind == VK_TRUE) && (query.descriptorBindingStorageTexelBufferUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingStorageTexelBufferUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingStorageTexelBufferUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingUpdateUnusedWhilePending == VK_TRUE) && (query.descriptorBindingUpdateUnusedWhilePending == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingUpdateUnusedWhilePending %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingUpdateUnusedWhilePending =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingPartiallyBound == VK_TRUE) && (query.descriptorBindingPartiallyBound == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingPartiallyBound %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingPartiallyBound =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingVariableDescriptorCount == VK_TRUE) && (query.descriptorBindingVariableDescriptorCount == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingVariableDescriptorCount %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->descriptorBindingVariableDescriptorCount =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->runtimeDescriptorArray == VK_TRUE) && (query.runtimeDescriptorArray == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature runtimeDescriptorArray %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(currentNext)->runtimeDescriptorArray =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature scalarBlockLayout %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceScalarBlockLayoutFeatures*>(currentNext)->scalarBlockLayout =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature vulkanMemoryModel %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkanMemoryModelFeatures*>(currentNext)->vulkanMemoryModel =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->vulkanMemoryModelDeviceScope == VK_TRUE) && (query.vulkanMemoryModelDeviceScope == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vulkanMemoryModelDeviceScope %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkanMemoryModelFeatures*>(currentNext)->vulkanMemoryModelDeviceScope =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->vulkanMemoryModelAvailabilityVisibilityChains == VK_TRUE) && (query.vulkanMemoryModelAvailabilityVisibilityChains == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vulkanMemoryModelAvailabilityVisibilityChains %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkanMemoryModelFeatures*>(currentNext)->vulkanMemoryModelAvailabilityVisibilityChains =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature imagelessFramebuffer %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceImagelessFramebufferFeatures*>(currentNext)->imagelessFramebuffer =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature uniformBufferStandardLayout %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(currentNext)->uniformBufferStandardLayout =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderSubgroupExtendedTypes %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(currentNext)->shaderSubgroupExtendedTypes =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature separateDepthStencilLayouts %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(currentNext)->separateDepthStencilLayouts =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature hostQueryReset %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceHostQueryResetFeatures*>(currentNext)->hostQueryReset =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature timelineSemaphore %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceTimelineSemaphoreFeatures*>(currentNext)->timelineSemaphore =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddress %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceBufferDeviceAddressFeatures*>(currentNext)->bufferDeviceAddress =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->bufferDeviceAddressCaptureReplay == VK_TRUE) && (query.bufferDeviceAddressCaptureReplay == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddressCaptureReplay %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceBufferDeviceAddressFeatures*>(currentNext)->bufferDeviceAddressCaptureReplay =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->bufferDeviceAddressMultiDevice == VK_TRUE) && (query.bufferDeviceAddressMultiDevice == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddressMultiDevice %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceBufferDeviceAddressFeatures*>(currentNext)->bufferDeviceAddressMultiDevice =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature robustImageAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->robustImageAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->inlineUniformBlock == VK_TRUE) && (query.inlineUniformBlock == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature inlineUniformBlock %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->inlineUniformBlock =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE) && (query.descriptorBindingInlineUniformBlockUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingInlineUniformBlockUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->descriptorBindingInlineUniformBlockUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->pipelineCreationCacheControl == VK_TRUE) && (query.pipelineCreationCacheControl == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature pipelineCreationCacheControl %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->pipelineCreationCacheControl =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->privateData == VK_TRUE) && (query.privateData == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature privateData %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->privateData =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderDemoteToHelperInvocation == VK_TRUE) && (query.shaderDemoteToHelperInvocation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderDemoteToHelperInvocation %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->shaderDemoteToHelperInvocation =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderTerminateInvocation == VK_TRUE) && (query.shaderTerminateInvocation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderTerminateInvocation %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->shaderTerminateInvocation =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->subgroupSizeControl == VK_TRUE) && (query.subgroupSizeControl == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature subgroupSizeControl %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->subgroupSizeControl =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->computeFullSubgroups == VK_TRUE) && (query.computeFullSubgroups == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature computeFullSubgroups %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->computeFullSubgroups =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->synchronization2 == VK_TRUE) && (query.synchronization2 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature synchronization2 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->synchronization2 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->textureCompressionASTC_HDR == VK_TRUE) && (query.textureCompressionASTC_HDR == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature textureCompressionASTC_HDR %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->textureCompressionASTC_HDR =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderZeroInitializeWorkgroupMemory == VK_TRUE) && (query.shaderZeroInitializeWorkgroupMemory == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderZeroInitializeWorkgroupMemory %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->shaderZeroInitializeWorkgroupMemory =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->dynamicRendering == VK_TRUE) && (query.dynamicRendering == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature dynamicRendering %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->dynamicRendering =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderIntegerDotProduct == VK_TRUE) && (query.shaderIntegerDotProduct == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderIntegerDotProduct %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->shaderIntegerDotProduct =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->maintenance4 == VK_TRUE) && (query.maintenance4 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature maintenance4 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVulkan13Features*>(currentNext)->maintenance4 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderTerminateInvocation %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderTerminateInvocationFeatures*>(currentNext)->shaderTerminateInvocation =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderDemoteToHelperInvocation %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(currentNext)->shaderDemoteToHelperInvocation =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature privateData %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePrivateDataFeatures*>(currentNext)->privateData =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature pipelineCreationCacheControl %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePipelineCreationCacheControlFeatures*>(currentNext)->pipelineCreationCacheControl =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature synchronization2 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceSynchronization2Features*>(currentNext)->synchronization2 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderZeroInitializeWorkgroupMemory %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(currentNext)->shaderZeroInitializeWorkgroupMemory =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature robustImageAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceImageRobustnessFeatures*>(currentNext)->robustImageAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature subgroupSizeControl %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceSubgroupSizeControlFeatures*>(currentNext)->subgroupSizeControl =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->computeFullSubgroups == VK_TRUE) && (query.computeFullSubgroups == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature computeFullSubgroups %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceSubgroupSizeControlFeatures*>(currentNext)->computeFullSubgroups =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature inlineUniformBlock %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceInlineUniformBlockFeatures*>(currentNext)->inlineUniformBlock =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingInlineUniformBlockUpdateAfterBind == VK_TRUE) && (query.descriptorBindingInlineUniformBlockUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingInlineUniformBlockUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceInlineUniformBlockFeatures*>(currentNext)->descriptorBindingInlineUniformBlockUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature textureCompressionASTC_HDR %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(currentNext)->textureCompressionASTC_HDR =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature dynamicRendering %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDynamicRenderingFeatures*>(currentNext)->dynamicRendering =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderIntegerDotProduct %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderIntegerDotProductFeatures*>(currentNext)->shaderIntegerDotProduct =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature maintenance4 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMaintenance4Features*>(currentNext)->maintenance4 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature performanceCounterQueryPools %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePerformanceQueryFeaturesKHR*>(currentNext)->performanceCounterQueryPools =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->performanceCounterMultipleQueryPools == VK_TRUE) && (query.performanceCounterMultipleQueryPools == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature performanceCounterMultipleQueryPools %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePerformanceQueryFeaturesKHR*>(currentNext)->performanceCounterMultipleQueryPools =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature constantAlphaColorBlendFactors %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->constantAlphaColorBlendFactors =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->events == VK_TRUE) && (query.events == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature events %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->events =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->imageViewFormatReinterpretation == VK_TRUE) && (query.imageViewFormatReinterpretation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature imageViewFormatReinterpretation %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->imageViewFormatReinterpretation =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->imageViewFormatSwizzle == VK_TRUE) && (query.imageViewFormatSwizzle == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature imageViewFormatSwizzle %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->imageViewFormatSwizzle =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->imageView2DOn3DImage == VK_TRUE) && (query.imageView2DOn3DImage == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature imageView2DOn3DImage %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->imageView2DOn3DImage =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->multisampleArrayImage == VK_TRUE) && (query.multisampleArrayImage == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multisampleArrayImage %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->multisampleArrayImage =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->mutableComparisonSamplers == VK_TRUE) && (query.mutableComparisonSamplers == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature mutableComparisonSamplers %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->mutableComparisonSamplers =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->pointPolygons == VK_TRUE) && (query.pointPolygons == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature pointPolygons %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->pointPolygons =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->samplerMipLodBias == VK_TRUE) && (query.samplerMipLodBias == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature samplerMipLodBias %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->samplerMipLodBias =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->separateStencilMaskRef == VK_TRUE) && (query.separateStencilMaskRef == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature separateStencilMaskRef %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->separateStencilMaskRef =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSampleRateInterpolationFunctions == VK_TRUE) && (query.shaderSampleRateInterpolationFunctions == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSampleRateInterpolationFunctions %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->shaderSampleRateInterpolationFunctions =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->tessellationIsolines == VK_TRUE) && (query.tessellationIsolines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature tessellationIsolines %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->tessellationIsolines =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->tessellationPointMode == VK_TRUE) && (query.tessellationPointMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature tessellationPointMode %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->tessellationPointMode =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->triangleFans == VK_TRUE) && (query.triangleFans == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature triangleFans %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->triangleFans =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->vertexAttributeAccessBeyondStride == VK_TRUE) && (query.vertexAttributeAccessBeyondStride == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vertexAttributeAccessBeyondStride %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(currentNext)->vertexAttributeAccessBeyondStride =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderSubgroupClock %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderClockFeaturesKHR*>(currentNext)->shaderSubgroupClock =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderDeviceClock == VK_TRUE) && (query.shaderDeviceClock == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderDeviceClock %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderClockFeaturesKHR*>(currentNext)->shaderDeviceClock =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature globalPriorityQuery %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(currentNext)->globalPriorityQuery =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature pipelineFragmentShadingRate %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(currentNext)->pipelineFragmentShadingRate =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->primitiveFragmentShadingRate == VK_TRUE) && (query.primitiveFragmentShadingRate == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature primitiveFragmentShadingRate %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(currentNext)->primitiveFragmentShadingRate =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->attachmentFragmentShadingRate == VK_TRUE) && (query.attachmentFragmentShadingRate == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature attachmentFragmentShadingRate %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(currentNext)->attachmentFragmentShadingRate =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature presentWait %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePresentWaitFeaturesKHR*>(currentNext)->presentWait =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature pipelineExecutableInfo %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(currentNext)->pipelineExecutableInfo =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature presentId %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePresentIdFeaturesKHR*>(currentNext)->presentId =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature fragmentShaderBarycentric %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(currentNext)->fragmentShaderBarycentric =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderSubgroupUniformControlFlow %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(currentNext)->shaderSubgroupUniformControlFlow =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature workgroupMemoryExplicitLayout %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(currentNext)->workgroupMemoryExplicitLayout =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->workgroupMemoryExplicitLayoutScalarBlockLayout == VK_TRUE) && (query.workgroupMemoryExplicitLayoutScalarBlockLayout == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature workgroupMemoryExplicitLayoutScalarBlockLayout %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(currentNext)->workgroupMemoryExplicitLayoutScalarBlockLayout =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->workgroupMemoryExplicitLayout8BitAccess == VK_TRUE) && (query.workgroupMemoryExplicitLayout8BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature workgroupMemoryExplicitLayout8BitAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(currentNext)->workgroupMemoryExplicitLayout8BitAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->workgroupMemoryExplicitLayout16BitAccess == VK_TRUE) && (query.workgroupMemoryExplicitLayout16BitAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature workgroupMemoryExplicitLayout16BitAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(currentNext)->workgroupMemoryExplicitLayout16BitAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature rayTracingMaintenance1 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(currentNext)->rayTracingMaintenance1 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->rayTracingPipelineTraceRaysIndirect2 == VK_TRUE) && (query.rayTracingPipelineTraceRaysIndirect2 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingPipelineTraceRaysIndirect2 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(currentNext)->rayTracingPipelineTraceRaysIndirect2 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR:
            {
                const VkPhysicalDeviceMaintenance5FeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceMaintenance5FeaturesKHR*>(next);
                VkPhysicalDeviceMaintenance5FeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->maintenance5 == VK_TRUE) && (query.maintenance5 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature maintenance5 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMaintenance5FeaturesKHR*>(currentNext)->maintenance5 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
            {
                const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(next);
                VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->rayTracingPositionFetch == VK_TRUE) && (query.rayTracingPositionFetch == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingPositionFetch %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(currentNext)->rayTracingPositionFetch =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
            {
                const VkPhysicalDeviceCooperativeMatrixFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(next);
                VkPhysicalDeviceCooperativeMatrixFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->cooperativeMatrix == VK_TRUE) && (query.cooperativeMatrix == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature cooperativeMatrix %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(currentNext)->cooperativeMatrix =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->cooperativeMatrixRobustBufferAccess == VK_TRUE) && (query.cooperativeMatrixRobustBufferAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature cooperativeMatrixRobustBufferAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(currentNext)->cooperativeMatrixRobustBufferAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
            {
                const VkPhysicalDeviceVideoMaintenance1FeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(next);
                VkPhysicalDeviceVideoMaintenance1FeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->videoMaintenance1 == VK_TRUE) && (query.videoMaintenance1 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature videoMaintenance1 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(currentNext)->videoMaintenance1 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR:
            {
                const VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR*>(next);
                VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->vertexAttributeInstanceRateDivisor == VK_TRUE) && (query.vertexAttributeInstanceRateDivisor == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vertexAttributeInstanceRateDivisor %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR*>(currentNext)->vertexAttributeInstanceRateDivisor =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->vertexAttributeInstanceRateZeroDivisor == VK_TRUE) && (query.vertexAttributeInstanceRateZeroDivisor == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature vertexAttributeInstanceRateZeroDivisor %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR*>(currentNext)->vertexAttributeInstanceRateZeroDivisor =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR:
            {
                const VkPhysicalDeviceMaintenance6FeaturesKHR* currentNext = reinterpret_cast<const VkPhysicalDeviceMaintenance6FeaturesKHR*>(next);
                VkPhysicalDeviceMaintenance6FeaturesKHR query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->maintenance6 == VK_TRUE) && (query.maintenance6 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature maintenance6 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMaintenance6FeaturesKHR*>(currentNext)->maintenance6 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature transformFeedback %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(currentNext)->transformFeedback =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->geometryStreams == VK_TRUE) && (query.geometryStreams == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature geometryStreams %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(currentNext)->geometryStreams =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature cornerSampledImage %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceCornerSampledImageFeaturesNV*>(currentNext)->cornerSampledImage =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature decodeModeSharedExponent %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceASTCDecodeFeaturesEXT*>(currentNext)->decodeModeSharedExponent =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature pipelineRobustness %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePipelineRobustnessFeaturesEXT*>(currentNext)->pipelineRobustness =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature conditionalRendering %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(currentNext)->conditionalRendering =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->inheritedConditionalRendering == VK_TRUE) && (query.inheritedConditionalRendering == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature inheritedConditionalRendering %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(currentNext)->inheritedConditionalRendering =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature depthClipEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(currentNext)->depthClipEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
            {
                const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* currentNext = reinterpret_cast<const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(next);
                VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->relaxedLineRasterization == VK_TRUE) && (query.relaxedLineRasterization == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature relaxedLineRasterization %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(currentNext)->relaxedLineRasterization =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature advancedBlendCoherentOperations %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(currentNext)->advancedBlendCoherentOperations =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderSMBuiltins %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(currentNext)->shaderSMBuiltins =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shadingRateImage %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShadingRateImageFeaturesNV*>(currentNext)->shadingRateImage =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shadingRateCoarseSampleOrder == VK_TRUE) && (query.shadingRateCoarseSampleOrder == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shadingRateCoarseSampleOrder %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShadingRateImageFeaturesNV*>(currentNext)->shadingRateCoarseSampleOrder =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature representativeFragmentTest %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(currentNext)->representativeFragmentTest =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature computeDerivativeGroupQuads %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(currentNext)->computeDerivativeGroupQuads =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->computeDerivativeGroupLinear == VK_TRUE) && (query.computeDerivativeGroupLinear == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature computeDerivativeGroupLinear %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(currentNext)->computeDerivativeGroupLinear =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature taskShader %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesNV*>(currentNext)->taskShader =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->meshShader == VK_TRUE) && (query.meshShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature meshShader %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesNV*>(currentNext)->meshShader =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature imageFootprint %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(currentNext)->imageFootprint =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature exclusiveScissor %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExclusiveScissorFeaturesNV*>(currentNext)->exclusiveScissor =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderIntegerFunctions2 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(currentNext)->shaderIntegerFunctions2 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature fragmentDensityMap %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(currentNext)->fragmentDensityMap =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->fragmentDensityMapDynamic == VK_TRUE) && (query.fragmentDensityMapDynamic == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentDensityMapDynamic %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(currentNext)->fragmentDensityMapDynamic =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->fragmentDensityMapNonSubsampledImages == VK_TRUE) && (query.fragmentDensityMapNonSubsampledImages == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentDensityMapNonSubsampledImages %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(currentNext)->fragmentDensityMapNonSubsampledImages =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature deviceCoherentMemory %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(currentNext)->deviceCoherentMemory =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderImageInt64Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(currentNext)->shaderImageInt64Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->sparseImageInt64Atomics == VK_TRUE) && (query.sparseImageInt64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature sparseImageInt64Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(currentNext)->sparseImageInt64Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature memoryPriority %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(currentNext)->memoryPriority =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature dedicatedAllocationImageAliasing %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(currentNext)->dedicatedAllocationImageAliasing =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddress %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(currentNext)->bufferDeviceAddress =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->bufferDeviceAddressCaptureReplay == VK_TRUE) && (query.bufferDeviceAddressCaptureReplay == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddressCaptureReplay %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(currentNext)->bufferDeviceAddressCaptureReplay =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->bufferDeviceAddressMultiDevice == VK_TRUE) && (query.bufferDeviceAddressMultiDevice == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bufferDeviceAddressMultiDevice %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(currentNext)->bufferDeviceAddressMultiDevice =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature cooperativeMatrix %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(currentNext)->cooperativeMatrix =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->cooperativeMatrixRobustBufferAccess == VK_TRUE) && (query.cooperativeMatrixRobustBufferAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature cooperativeMatrixRobustBufferAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(currentNext)->cooperativeMatrixRobustBufferAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature coverageReductionMode %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(currentNext)->coverageReductionMode =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature fragmentShaderSampleInterlock %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(currentNext)->fragmentShaderSampleInterlock =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->fragmentShaderPixelInterlock == VK_TRUE) && (query.fragmentShaderPixelInterlock == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentShaderPixelInterlock %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(currentNext)->fragmentShaderPixelInterlock =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->fragmentShaderShadingRateInterlock == VK_TRUE) && (query.fragmentShaderShadingRateInterlock == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature fragmentShaderShadingRateInterlock %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(currentNext)->fragmentShaderShadingRateInterlock =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature ycbcrImageArrays %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(currentNext)->ycbcrImageArrays =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature provokingVertexLast %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceProvokingVertexFeaturesEXT*>(currentNext)->provokingVertexLast =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->transformFeedbackPreservesProvokingVertex == VK_TRUE) && (query.transformFeedbackPreservesProvokingVertex == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature transformFeedbackPreservesProvokingVertex %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceProvokingVertexFeaturesEXT*>(currentNext)->transformFeedbackPreservesProvokingVertex =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature rectangularLines %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT*>(currentNext)->rectangularLines =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->bresenhamLines == VK_TRUE) && (query.bresenhamLines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature bresenhamLines %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT*>(currentNext)->bresenhamLines =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->smoothLines == VK_TRUE) && (query.smoothLines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature smoothLines %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT*>(currentNext)->smoothLines =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->stippledRectangularLines == VK_TRUE) && (query.stippledRectangularLines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature stippledRectangularLines %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT*>(currentNext)->stippledRectangularLines =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->stippledBresenhamLines == VK_TRUE) && (query.stippledBresenhamLines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature stippledBresenhamLines %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT*>(currentNext)->stippledBresenhamLines =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->stippledSmoothLines == VK_TRUE) && (query.stippledSmoothLines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature stippledSmoothLines %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT*>(currentNext)->stippledSmoothLines =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat32Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderBufferFloat32Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderBufferFloat32AtomicAdd == VK_TRUE) && (query.shaderBufferFloat32AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat32AtomicAdd %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderBufferFloat32AtomicAdd =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderBufferFloat64Atomics == VK_TRUE) && (query.shaderBufferFloat64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat64Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderBufferFloat64Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderBufferFloat64AtomicAdd == VK_TRUE) && (query.shaderBufferFloat64AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat64AtomicAdd %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderBufferFloat64AtomicAdd =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSharedFloat32Atomics == VK_TRUE) && (query.shaderSharedFloat32Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat32Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderSharedFloat32Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSharedFloat32AtomicAdd == VK_TRUE) && (query.shaderSharedFloat32AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat32AtomicAdd %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderSharedFloat32AtomicAdd =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSharedFloat64Atomics == VK_TRUE) && (query.shaderSharedFloat64Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat64Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderSharedFloat64Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSharedFloat64AtomicAdd == VK_TRUE) && (query.shaderSharedFloat64AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat64AtomicAdd %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderSharedFloat64AtomicAdd =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderImageFloat32Atomics == VK_TRUE) && (query.shaderImageFloat32Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderImageFloat32Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderImageFloat32Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderImageFloat32AtomicAdd == VK_TRUE) && (query.shaderImageFloat32AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderImageFloat32AtomicAdd %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->shaderImageFloat32AtomicAdd =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->sparseImageFloat32Atomics == VK_TRUE) && (query.sparseImageFloat32Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature sparseImageFloat32Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->sparseImageFloat32Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->sparseImageFloat32AtomicAdd == VK_TRUE) && (query.sparseImageFloat32AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature sparseImageFloat32AtomicAdd %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(currentNext)->sparseImageFloat32AtomicAdd =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature indexTypeUint8 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(currentNext)->indexTypeUint8 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(currentNext)->extendedDynamicState =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT:
            {
                const VkPhysicalDeviceHostImageCopyFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceHostImageCopyFeaturesEXT*>(next);
                VkPhysicalDeviceHostImageCopyFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->hostImageCopy == VK_TRUE) && (query.hostImageCopy == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature hostImageCopy %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceHostImageCopyFeaturesEXT*>(currentNext)->hostImageCopy =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat16Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderBufferFloat16Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderBufferFloat16AtomicAdd == VK_TRUE) && (query.shaderBufferFloat16AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat16AtomicAdd %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderBufferFloat16AtomicAdd =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderBufferFloat16AtomicMinMax == VK_TRUE) && (query.shaderBufferFloat16AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat16AtomicMinMax %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderBufferFloat16AtomicMinMax =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderBufferFloat32AtomicMinMax == VK_TRUE) && (query.shaderBufferFloat32AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat32AtomicMinMax %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderBufferFloat32AtomicMinMax =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderBufferFloat64AtomicMinMax == VK_TRUE) && (query.shaderBufferFloat64AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderBufferFloat64AtomicMinMax %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderBufferFloat64AtomicMinMax =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSharedFloat16Atomics == VK_TRUE) && (query.shaderSharedFloat16Atomics == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat16Atomics %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderSharedFloat16Atomics =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSharedFloat16AtomicAdd == VK_TRUE) && (query.shaderSharedFloat16AtomicAdd == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat16AtomicAdd %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderSharedFloat16AtomicAdd =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSharedFloat16AtomicMinMax == VK_TRUE) && (query.shaderSharedFloat16AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat16AtomicMinMax %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderSharedFloat16AtomicMinMax =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSharedFloat32AtomicMinMax == VK_TRUE) && (query.shaderSharedFloat32AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat32AtomicMinMax %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderSharedFloat32AtomicMinMax =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderSharedFloat64AtomicMinMax == VK_TRUE) && (query.shaderSharedFloat64AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderSharedFloat64AtomicMinMax %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderSharedFloat64AtomicMinMax =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderImageFloat32AtomicMinMax == VK_TRUE) && (query.shaderImageFloat32AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderImageFloat32AtomicMinMax %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->shaderImageFloat32AtomicMinMax =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->sparseImageFloat32AtomicMinMax == VK_TRUE) && (query.sparseImageFloat32AtomicMinMax == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature sparseImageFloat32AtomicMinMax %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(currentNext)->sparseImageFloat32AtomicMinMax =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT:
            {
                const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT*>(next);
                VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->swapchainMaintenance1 == VK_TRUE) && (query.swapchainMaintenance1 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature swapchainMaintenance1 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT*>(currentNext)->swapchainMaintenance1 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature deviceGeneratedCommands %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(currentNext)->deviceGeneratedCommands =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature inheritedViewportScissor2D %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(currentNext)->inheritedViewportScissor2D =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature texelBufferAlignment %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(currentNext)->texelBufferAlignment =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
            {
                const VkPhysicalDeviceDepthBiasControlFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(next);
                VkPhysicalDeviceDepthBiasControlFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->depthBiasControl == VK_TRUE) && (query.depthBiasControl == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature depthBiasControl %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(currentNext)->depthBiasControl =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->leastRepresentableValueForceUnormRepresentation == VK_TRUE) && (query.leastRepresentableValueForceUnormRepresentation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature leastRepresentableValueForceUnormRepresentation %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(currentNext)->leastRepresentableValueForceUnormRepresentation =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->floatRepresentation == VK_TRUE) && (query.floatRepresentation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature floatRepresentation %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(currentNext)->floatRepresentation =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->depthBiasExact == VK_TRUE) && (query.depthBiasExact == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature depthBiasExact %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(currentNext)->depthBiasExact =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature deviceMemoryReport %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(currentNext)->deviceMemoryReport =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature robustBufferAccess2 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRobustness2FeaturesEXT*>(currentNext)->robustBufferAccess2 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->robustImageAccess2 == VK_TRUE) && (query.robustImageAccess2 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature robustImageAccess2 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRobustness2FeaturesEXT*>(currentNext)->robustImageAccess2 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->nullDescriptor == VK_TRUE) && (query.nullDescriptor == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature nullDescriptor %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRobustness2FeaturesEXT*>(currentNext)->nullDescriptor =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature customBorderColors %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(currentNext)->customBorderColors =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->customBorderColorWithoutFormat == VK_TRUE) && (query.customBorderColorWithoutFormat == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature customBorderColorWithoutFormat %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(currentNext)->customBorderColorWithoutFormat =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature presentBarrier %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePresentBarrierFeaturesNV*>(currentNext)->presentBarrier =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature diagnosticsConfig %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(currentNext)->diagnosticsConfig =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature graphicsPipelineLibrary %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(currentNext)->graphicsPipelineLibrary =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderEarlyAndLateFragmentTests %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(currentNext)->shaderEarlyAndLateFragmentTests =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature fragmentShadingRateEnums %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(currentNext)->fragmentShadingRateEnums =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->supersampleFragmentShadingRates == VK_TRUE) && (query.supersampleFragmentShadingRates == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature supersampleFragmentShadingRates %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(currentNext)->supersampleFragmentShadingRates =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->noInvocationFragmentShadingRates == VK_TRUE) && (query.noInvocationFragmentShadingRates == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature noInvocationFragmentShadingRates %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(currentNext)->noInvocationFragmentShadingRates =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature rayTracingMotionBlur %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(currentNext)->rayTracingMotionBlur =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->rayTracingMotionBlurPipelineTraceRaysIndirect == VK_TRUE) && (query.rayTracingMotionBlurPipelineTraceRaysIndirect == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingMotionBlurPipelineTraceRaysIndirect %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(currentNext)->rayTracingMotionBlurPipelineTraceRaysIndirect =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature ycbcr2plane444Formats %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(currentNext)->ycbcr2plane444Formats =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature fragmentDensityMapDeferred %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(currentNext)->fragmentDensityMapDeferred =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature imageCompressionControl %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(currentNext)->imageCompressionControl =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature attachmentFeedbackLoopLayout %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(currentNext)->attachmentFeedbackLoopLayout =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature formatA4R4G4B4 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevice4444FormatsFeaturesEXT*>(currentNext)->formatA4R4G4B4 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->formatA4B4G4R4 == VK_TRUE) && (query.formatA4B4G4R4 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature formatA4B4G4R4 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevice4444FormatsFeaturesEXT*>(currentNext)->formatA4B4G4R4 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature deviceFault %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFaultFeaturesEXT*>(currentNext)->deviceFault =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->deviceFaultVendorBinary == VK_TRUE) && (query.deviceFaultVendorBinary == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature deviceFaultVendorBinary %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFaultFeaturesEXT*>(currentNext)->deviceFaultVendorBinary =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature rasterizationOrderColorAttachmentAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(currentNext)->rasterizationOrderColorAttachmentAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->rasterizationOrderDepthAttachmentAccess == VK_TRUE) && (query.rasterizationOrderDepthAttachmentAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rasterizationOrderDepthAttachmentAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(currentNext)->rasterizationOrderDepthAttachmentAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->rasterizationOrderStencilAttachmentAccess == VK_TRUE) && (query.rasterizationOrderStencilAttachmentAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rasterizationOrderStencilAttachmentAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(currentNext)->rasterizationOrderStencilAttachmentAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature formatRgba10x6WithoutYCbCrSampler %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(currentNext)->formatRgba10x6WithoutYCbCrSampler =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature mutableDescriptorType %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(currentNext)->mutableDescriptorType =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature vertexInputDynamicState %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(currentNext)->vertexInputDynamicState =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature reportAddressBinding %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(currentNext)->reportAddressBinding =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature depthClipControl %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDepthClipControlFeaturesEXT*>(currentNext)->depthClipControl =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature primitiveTopologyListRestart %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(currentNext)->primitiveTopologyListRestart =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->primitiveTopologyPatchListRestart == VK_TRUE) && (query.primitiveTopologyPatchListRestart == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature primitiveTopologyPatchListRestart %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(currentNext)->primitiveTopologyPatchListRestart =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature invocationMask %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(currentNext)->invocationMask =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature externalMemoryRDMA %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(currentNext)->externalMemoryRDMA =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
            {
                const VkPhysicalDeviceFrameBoundaryFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(next);
                VkPhysicalDeviceFrameBoundaryFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->frameBoundary == VK_TRUE) && (query.frameBoundary == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature frameBoundary %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(currentNext)->frameBoundary =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature multisampledRenderToSingleSampled %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(currentNext)->multisampledRenderToSingleSampled =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState2 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(currentNext)->extendedDynamicState2 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState2LogicOp == VK_TRUE) && (query.extendedDynamicState2LogicOp == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState2LogicOp %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(currentNext)->extendedDynamicState2LogicOp =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState2PatchControlPoints == VK_TRUE) && (query.extendedDynamicState2PatchControlPoints == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState2PatchControlPoints %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(currentNext)->extendedDynamicState2PatchControlPoints =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature colorWriteEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(currentNext)->colorWriteEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature primitivesGeneratedQuery %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(currentNext)->primitivesGeneratedQuery =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->primitivesGeneratedQueryWithRasterizerDiscard == VK_TRUE) && (query.primitivesGeneratedQueryWithRasterizerDiscard == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature primitivesGeneratedQueryWithRasterizerDiscard %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(currentNext)->primitivesGeneratedQueryWithRasterizerDiscard =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->primitivesGeneratedQueryWithNonZeroStreams == VK_TRUE) && (query.primitivesGeneratedQueryWithNonZeroStreams == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature primitivesGeneratedQueryWithNonZeroStreams %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(currentNext)->primitivesGeneratedQueryWithNonZeroStreams =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature minLod %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(currentNext)->minLod =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature multiDraw %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMultiDrawFeaturesEXT*>(currentNext)->multiDraw =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature image2DViewOf3D %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(currentNext)->image2DViewOf3D =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->sampler2DViewOf3D == VK_TRUE) && (query.sampler2DViewOf3D == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature sampler2DViewOf3D %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(currentNext)->sampler2DViewOf3D =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
            {
                const VkPhysicalDeviceShaderTileImageFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderTileImageFeaturesEXT*>(next);
                VkPhysicalDeviceShaderTileImageFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderTileImageColorReadAccess == VK_TRUE) && (query.shaderTileImageColorReadAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderTileImageColorReadAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderTileImageFeaturesEXT*>(currentNext)->shaderTileImageColorReadAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderTileImageDepthReadAccess == VK_TRUE) && (query.shaderTileImageDepthReadAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderTileImageDepthReadAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderTileImageFeaturesEXT*>(currentNext)->shaderTileImageDepthReadAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->shaderTileImageStencilReadAccess == VK_TRUE) && (query.shaderTileImageStencilReadAccess == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderTileImageStencilReadAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderTileImageFeaturesEXT*>(currentNext)->shaderTileImageStencilReadAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature micromap %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(currentNext)->micromap =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->micromapCaptureReplay == VK_TRUE) && (query.micromapCaptureReplay == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature micromapCaptureReplay %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(currentNext)->micromapCaptureReplay =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->micromapHostCommands == VK_TRUE) && (query.micromapHostCommands == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature micromapHostCommands %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(currentNext)->micromapHostCommands =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV:
            {
                const VkPhysicalDeviceDisplacementMicromapFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(next);
                VkPhysicalDeviceDisplacementMicromapFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->displacementMicromap == VK_TRUE) && (query.displacementMicromap == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature displacementMicromap %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(currentNext)->displacementMicromap =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
            {
                const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* currentNext = reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(next);
                VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->clustercullingShader == VK_TRUE) && (query.clustercullingShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature clustercullingShader %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(currentNext)->clustercullingShader =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->multiviewClusterCullingShader == VK_TRUE) && (query.multiviewClusterCullingShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiviewClusterCullingShader %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(currentNext)->multiviewClusterCullingShader =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature borderColorSwizzle %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(currentNext)->borderColorSwizzle =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->borderColorSwizzleFromImage == VK_TRUE) && (query.borderColorSwizzleFromImage == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature borderColorSwizzleFromImage %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(currentNext)->borderColorSwizzleFromImage =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature pageableDeviceLocalMemory %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(currentNext)->pageableDeviceLocalMemory =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
            {
                const VkPhysicalDeviceSchedulingControlsFeaturesARM* currentNext = reinterpret_cast<const VkPhysicalDeviceSchedulingControlsFeaturesARM*>(next);
                VkPhysicalDeviceSchedulingControlsFeaturesARM query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->schedulingControls == VK_TRUE) && (query.schedulingControls == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature schedulingControls %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceSchedulingControlsFeaturesARM*>(currentNext)->schedulingControls =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
            {
                const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(next);
                VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->imageSlicedViewOf3D == VK_TRUE) && (query.imageSlicedViewOf3D == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature imageSlicedViewOf3D %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(currentNext)->imageSlicedViewOf3D =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature descriptorSetHostMapping %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(currentNext)->descriptorSetHostMapping =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature depthClampZeroOne %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDepthClampZeroOneFeaturesEXT*>(currentNext)->depthClampZeroOne =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature nonSeamlessCubeMap %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(currentNext)->nonSeamlessCubeMap =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
            {
                const VkPhysicalDeviceRenderPassStripedFeaturesARM* currentNext = reinterpret_cast<const VkPhysicalDeviceRenderPassStripedFeaturesARM*>(next);
                VkPhysicalDeviceRenderPassStripedFeaturesARM query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->renderPassStriped == VK_TRUE) && (query.renderPassStriped == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature renderPassStriped %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRenderPassStripedFeaturesARM*>(currentNext)->renderPassStriped =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature fragmentDensityMapOffset %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM*>(currentNext)->fragmentDensityMapOffset =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
            {
                const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(next);
                VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->deviceGeneratedCompute == VK_TRUE) && (query.deviceGeneratedCompute == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature deviceGeneratedCompute %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(currentNext)->deviceGeneratedCompute =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->deviceGeneratedComputePipelines == VK_TRUE) && (query.deviceGeneratedComputePipelines == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature deviceGeneratedComputePipelines %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(currentNext)->deviceGeneratedComputePipelines =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->deviceGeneratedComputeCaptureReplay == VK_TRUE) && (query.deviceGeneratedComputeCaptureReplay == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature deviceGeneratedComputeCaptureReplay %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(currentNext)->deviceGeneratedComputeCaptureReplay =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature linearColorAttachment %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(currentNext)->linearColorAttachment =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature imageCompressionControlSwapchain %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(currentNext)->imageCompressionControlSwapchain =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature textureSampleWeighted %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceImageProcessingFeaturesQCOM*>(currentNext)->textureSampleWeighted =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->textureBoxFilter == VK_TRUE) && (query.textureBoxFilter == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature textureBoxFilter %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceImageProcessingFeaturesQCOM*>(currentNext)->textureBoxFilter =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->textureBlockMatch == VK_TRUE) && (query.textureBlockMatch == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature textureBlockMatch %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceImageProcessingFeaturesQCOM*>(currentNext)->textureBlockMatch =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
            {
                const VkPhysicalDeviceNestedCommandBufferFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(next);
                VkPhysicalDeviceNestedCommandBufferFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->nestedCommandBuffer == VK_TRUE) && (query.nestedCommandBuffer == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature nestedCommandBuffer %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(currentNext)->nestedCommandBuffer =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->nestedCommandBufferRendering == VK_TRUE) && (query.nestedCommandBufferRendering == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature nestedCommandBufferRendering %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(currentNext)->nestedCommandBufferRendering =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->nestedCommandBufferSimultaneousUse == VK_TRUE) && (query.nestedCommandBufferSimultaneousUse == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature nestedCommandBufferSimultaneousUse %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(currentNext)->nestedCommandBufferSimultaneousUse =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3TessellationDomainOrigin %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3TessellationDomainOrigin =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3DepthClampEnable == VK_TRUE) && (query.extendedDynamicState3DepthClampEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3DepthClampEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3DepthClampEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3PolygonMode == VK_TRUE) && (query.extendedDynamicState3PolygonMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3PolygonMode %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3PolygonMode =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3RasterizationSamples == VK_TRUE) && (query.extendedDynamicState3RasterizationSamples == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3RasterizationSamples %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3RasterizationSamples =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3SampleMask == VK_TRUE) && (query.extendedDynamicState3SampleMask == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3SampleMask %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3SampleMask =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3AlphaToCoverageEnable == VK_TRUE) && (query.extendedDynamicState3AlphaToCoverageEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3AlphaToCoverageEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3AlphaToCoverageEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3AlphaToOneEnable == VK_TRUE) && (query.extendedDynamicState3AlphaToOneEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3AlphaToOneEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3AlphaToOneEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3LogicOpEnable == VK_TRUE) && (query.extendedDynamicState3LogicOpEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3LogicOpEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3LogicOpEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3ColorBlendEnable == VK_TRUE) && (query.extendedDynamicState3ColorBlendEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ColorBlendEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ColorBlendEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3ColorBlendEquation == VK_TRUE) && (query.extendedDynamicState3ColorBlendEquation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ColorBlendEquation %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ColorBlendEquation =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3ColorWriteMask == VK_TRUE) && (query.extendedDynamicState3ColorWriteMask == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ColorWriteMask %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ColorWriteMask =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3RasterizationStream == VK_TRUE) && (query.extendedDynamicState3RasterizationStream == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3RasterizationStream %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3RasterizationStream =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3ConservativeRasterizationMode == VK_TRUE) && (query.extendedDynamicState3ConservativeRasterizationMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ConservativeRasterizationMode %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ConservativeRasterizationMode =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3ExtraPrimitiveOverestimationSize == VK_TRUE) && (query.extendedDynamicState3ExtraPrimitiveOverestimationSize == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ExtraPrimitiveOverestimationSize %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ExtraPrimitiveOverestimationSize =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3DepthClipEnable == VK_TRUE) && (query.extendedDynamicState3DepthClipEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3DepthClipEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3DepthClipEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3SampleLocationsEnable == VK_TRUE) && (query.extendedDynamicState3SampleLocationsEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3SampleLocationsEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3SampleLocationsEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3ColorBlendAdvanced == VK_TRUE) && (query.extendedDynamicState3ColorBlendAdvanced == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ColorBlendAdvanced %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ColorBlendAdvanced =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3ProvokingVertexMode == VK_TRUE) && (query.extendedDynamicState3ProvokingVertexMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ProvokingVertexMode %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ProvokingVertexMode =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3LineRasterizationMode == VK_TRUE) && (query.extendedDynamicState3LineRasterizationMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3LineRasterizationMode %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3LineRasterizationMode =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3LineStippleEnable == VK_TRUE) && (query.extendedDynamicState3LineStippleEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3LineStippleEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3LineStippleEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3DepthClipNegativeOneToOne == VK_TRUE) && (query.extendedDynamicState3DepthClipNegativeOneToOne == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3DepthClipNegativeOneToOne %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3DepthClipNegativeOneToOne =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3ViewportWScalingEnable == VK_TRUE) && (query.extendedDynamicState3ViewportWScalingEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ViewportWScalingEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ViewportWScalingEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3ViewportSwizzle == VK_TRUE) && (query.extendedDynamicState3ViewportSwizzle == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ViewportSwizzle %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ViewportSwizzle =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3CoverageToColorEnable == VK_TRUE) && (query.extendedDynamicState3CoverageToColorEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3CoverageToColorEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3CoverageToColorEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3CoverageToColorLocation == VK_TRUE) && (query.extendedDynamicState3CoverageToColorLocation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3CoverageToColorLocation %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3CoverageToColorLocation =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3CoverageModulationMode == VK_TRUE) && (query.extendedDynamicState3CoverageModulationMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3CoverageModulationMode %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3CoverageModulationMode =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3CoverageModulationTableEnable == VK_TRUE) && (query.extendedDynamicState3CoverageModulationTableEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3CoverageModulationTableEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3CoverageModulationTableEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3CoverageModulationTable == VK_TRUE) && (query.extendedDynamicState3CoverageModulationTable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3CoverageModulationTable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3CoverageModulationTable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3CoverageReductionMode == VK_TRUE) && (query.extendedDynamicState3CoverageReductionMode == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3CoverageReductionMode %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3CoverageReductionMode =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3RepresentativeFragmentTestEnable == VK_TRUE) && (query.extendedDynamicState3RepresentativeFragmentTestEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3RepresentativeFragmentTestEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3RepresentativeFragmentTestEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->extendedDynamicState3ShadingRateImageEnable == VK_TRUE) && (query.extendedDynamicState3ShadingRateImageEnable == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedDynamicState3ShadingRateImageEnable %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(currentNext)->extendedDynamicState3ShadingRateImageEnable =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature subpassMergeFeedback %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(currentNext)->subpassMergeFeedback =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderModuleIdentifier %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(currentNext)->shaderModuleIdentifier =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature opticalFlow %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceOpticalFlowFeaturesNV*>(currentNext)->opticalFlow =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature legacyDithering %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(currentNext)->legacyDithering =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature pipelineProtectedAccess %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePipelineProtectedAccessFeaturesEXT*>(currentNext)->pipelineProtectedAccess =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
            {
                const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* currentNext = reinterpret_cast<const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(next);
                VkPhysicalDeviceExternalFormatResolveFeaturesANDROID query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->externalFormatResolve == VK_TRUE) && (query.externalFormatResolve == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature externalFormatResolve %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(currentNext)->externalFormatResolve =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
            {
                const VkPhysicalDeviceShaderObjectFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceShaderObjectFeaturesEXT*>(next);
                VkPhysicalDeviceShaderObjectFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->shaderObject == VK_TRUE) && (query.shaderObject == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature shaderObject %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderObjectFeaturesEXT*>(currentNext)->shaderObject =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature tileProperties %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(currentNext)->tileProperties =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature amigoProfiling %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(currentNext)->amigoProfiling =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
            {
                const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* currentNext = reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(next);
                VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->multiviewPerViewViewports == VK_TRUE) && (query.multiviewPerViewViewports == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiviewPerViewViewports %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(currentNext)->multiviewPerViewViewports =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
            {
                const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(next);
                VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->rayTracingInvocationReorder == VK_TRUE) && (query.rayTracingInvocationReorder == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingInvocationReorder %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(currentNext)->rayTracingInvocationReorder =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
            {
                const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(next);
                VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->extendedSparseAddressSpace == VK_TRUE) && (query.extendedSparseAddressSpace == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature extendedSparseAddressSpace %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(currentNext)->extendedSparseAddressSpace =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature shaderCoreBuiltins %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(currentNext)->shaderCoreBuiltins =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
            {
                const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(next);
                VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->pipelineLibraryGroupHandles == VK_TRUE) && (query.pipelineLibraryGroupHandles == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature pipelineLibraryGroupHandles %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(currentNext)->pipelineLibraryGroupHandles =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
            {
                const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(next);
                VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->dynamicRenderingUnusedAttachments == VK_TRUE) && (query.dynamicRenderingUnusedAttachments == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature dynamicRenderingUnusedAttachments %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(currentNext)->dynamicRenderingUnusedAttachments =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
            {
                const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* currentNext = reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(next);
                VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->multiviewPerViewRenderAreas == VK_TRUE) && (query.multiviewPerViewRenderAreas == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiviewPerViewRenderAreas %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(currentNext)->multiviewPerViewRenderAreas =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV:
            {
                const VkPhysicalDevicePerStageDescriptorSetFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(next);
                VkPhysicalDevicePerStageDescriptorSetFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->perStageDescriptorSet == VK_TRUE) && (query.perStageDescriptorSet == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature perStageDescriptorSet %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(currentNext)->perStageDescriptorSet =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->dynamicPipelineLayout == VK_TRUE) && (query.dynamicPipelineLayout == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature dynamicPipelineLayout %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(currentNext)->dynamicPipelineLayout =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
            {
                const VkPhysicalDeviceImageProcessing2FeaturesQCOM* currentNext = reinterpret_cast<const VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(next);
                VkPhysicalDeviceImageProcessing2FeaturesQCOM query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->textureBlockMatch2 == VK_TRUE) && (query.textureBlockMatch2 == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature textureBlockMatch2 %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(currentNext)->textureBlockMatch2 =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
            {
                const VkPhysicalDeviceCubicWeightsFeaturesQCOM* currentNext = reinterpret_cast<const VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(next);
                VkPhysicalDeviceCubicWeightsFeaturesQCOM query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->selectableCubicWeights == VK_TRUE) && (query.selectableCubicWeights == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature selectableCubicWeights %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(currentNext)->selectableCubicWeights =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
            {
                const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* currentNext = reinterpret_cast<const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(next);
                VkPhysicalDeviceYcbcrDegammaFeaturesQCOM query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->ycbcrDegamma == VK_TRUE) && (query.ycbcrDegamma == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature ycbcrDegamma %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(currentNext)->ycbcrDegamma =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
            {
                const VkPhysicalDeviceCubicClampFeaturesQCOM* currentNext = reinterpret_cast<const VkPhysicalDeviceCubicClampFeaturesQCOM*>(next);
                VkPhysicalDeviceCubicClampFeaturesQCOM query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->cubicRangeClamp == VK_TRUE) && (query.cubicRangeClamp == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature cubicRangeClamp %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceCubicClampFeaturesQCOM*>(currentNext)->cubicRangeClamp =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
            {
                const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* currentNext = reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(next);
                VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->attachmentFeedbackLoopDynamicState == VK_TRUE) && (query.attachmentFeedbackLoopDynamicState == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature attachmentFeedbackLoopDynamicState %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(currentNext)->attachmentFeedbackLoopDynamicState =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
            {
                const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* currentNext = reinterpret_cast<const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(next);
                VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV query = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV, nullptr };
                physicalDeviceFeatures2.pNext = &query;
                GetPhysicalDeviceFeatures2(physicalDevice, &physicalDeviceFeatures2);
                if ((currentNext->descriptorPoolOverallocation == VK_TRUE) && (query.descriptorPoolOverallocation == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorPoolOverallocation %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(currentNext)->descriptorPoolOverallocation =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature accelerationStructure %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(currentNext)->accelerationStructure =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->accelerationStructureCaptureReplay == VK_TRUE) && (query.accelerationStructureCaptureReplay == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature accelerationStructureCaptureReplay %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(currentNext)->accelerationStructureCaptureReplay =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->accelerationStructureIndirectBuild == VK_TRUE) && (query.accelerationStructureIndirectBuild == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature accelerationStructureIndirectBuild %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(currentNext)->accelerationStructureIndirectBuild =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->accelerationStructureHostCommands == VK_TRUE) && (query.accelerationStructureHostCommands == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature accelerationStructureHostCommands %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(currentNext)->accelerationStructureHostCommands =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->descriptorBindingAccelerationStructureUpdateAfterBind == VK_TRUE) && (query.descriptorBindingAccelerationStructureUpdateAfterBind == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature descriptorBindingAccelerationStructureUpdateAfterBind %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(currentNext)->descriptorBindingAccelerationStructureUpdateAfterBind =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature rayTracingPipeline %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(currentNext)->rayTracingPipeline =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->rayTracingPipelineShaderGroupHandleCaptureReplay == VK_TRUE) && (query.rayTracingPipelineShaderGroupHandleCaptureReplay == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingPipelineShaderGroupHandleCaptureReplay %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(currentNext)->rayTracingPipelineShaderGroupHandleCaptureReplay =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->rayTracingPipelineShaderGroupHandleCaptureReplayMixed == VK_TRUE) && (query.rayTracingPipelineShaderGroupHandleCaptureReplayMixed == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingPipelineShaderGroupHandleCaptureReplayMixed %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(currentNext)->rayTracingPipelineShaderGroupHandleCaptureReplayMixed =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->rayTracingPipelineTraceRaysIndirect == VK_TRUE) && (query.rayTracingPipelineTraceRaysIndirect == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTracingPipelineTraceRaysIndirect %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(currentNext)->rayTracingPipelineTraceRaysIndirect =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->rayTraversalPrimitiveCulling == VK_TRUE) && (query.rayTraversalPrimitiveCulling == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature rayTraversalPrimitiveCulling %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(currentNext)->rayTraversalPrimitiveCulling =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature rayQuery %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceRayQueryFeaturesKHR*>(currentNext)->rayQuery =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
                    GFXRECON_LOG_WARNING("Feature taskShader %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesEXT*>(currentNext)->taskShader =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->meshShader == VK_TRUE) && (query.meshShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature meshShader %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesEXT*>(currentNext)->meshShader =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->multiviewMeshShader == VK_TRUE) && (query.multiviewMeshShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature multiviewMeshShader %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesEXT*>(currentNext)->multiviewMeshShader =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->primitiveFragmentShadingRateMeshShader == VK_TRUE) && (query.primitiveFragmentShadingRateMeshShader == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature primitiveFragmentShadingRateMeshShader %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesEXT*>(currentNext)->primitiveFragmentShadingRateMeshShader =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
                }
                if ((currentNext->meshShaderQueries == VK_TRUE) && (query.meshShaderQueries == VK_FALSE))
                {
                    GFXRECON_LOG_WARNING("Feature meshShaderQueries %s", warn_message);
                    found_unsupported = true;
                    const_cast<VkPhysicalDeviceMeshShaderFeaturesEXT*>(currentNext)->meshShaderQueries =
                        remove_unsupported ? VK_FALSE : VK_TRUE;
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
            GFXRECON_LOG_WARNING("Feature robustBufferAccess %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->robustBufferAccess =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->fullDrawIndexUint32 == VK_TRUE) && (query.fullDrawIndexUint32 == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature fullDrawIndexUint32 %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->fullDrawIndexUint32 =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->imageCubeArray == VK_TRUE) && (query.imageCubeArray == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature imageCubeArray %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->imageCubeArray =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->independentBlend == VK_TRUE) && (query.independentBlend == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature independentBlend %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->independentBlend =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->geometryShader == VK_TRUE) && (query.geometryShader == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature geometryShader %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->geometryShader =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->tessellationShader == VK_TRUE) && (query.tessellationShader == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature tessellationShader %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->tessellationShader =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->sampleRateShading == VK_TRUE) && (query.sampleRateShading == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sampleRateShading %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sampleRateShading =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->dualSrcBlend == VK_TRUE) && (query.dualSrcBlend == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature dualSrcBlend %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->dualSrcBlend =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->logicOp == VK_TRUE) && (query.logicOp == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature logicOp %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->logicOp =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->multiDrawIndirect == VK_TRUE) && (query.multiDrawIndirect == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature multiDrawIndirect %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->multiDrawIndirect =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->drawIndirectFirstInstance == VK_TRUE) && (query.drawIndirectFirstInstance == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature drawIndirectFirstInstance %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->drawIndirectFirstInstance =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->depthClamp == VK_TRUE) && (query.depthClamp == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature depthClamp %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->depthClamp =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->depthBiasClamp == VK_TRUE) && (query.depthBiasClamp == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature depthBiasClamp %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->depthBiasClamp =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->fillModeNonSolid == VK_TRUE) && (query.fillModeNonSolid == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature fillModeNonSolid %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->fillModeNonSolid =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->depthBounds == VK_TRUE) && (query.depthBounds == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature depthBounds %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->depthBounds =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->wideLines == VK_TRUE) && (query.wideLines == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature wideLines %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->wideLines =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->largePoints == VK_TRUE) && (query.largePoints == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature largePoints %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->largePoints =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->alphaToOne == VK_TRUE) && (query.alphaToOne == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature alphaToOne %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->alphaToOne =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->multiViewport == VK_TRUE) && (query.multiViewport == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature multiViewport %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->multiViewport =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->samplerAnisotropy == VK_TRUE) && (query.samplerAnisotropy == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature samplerAnisotropy %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->samplerAnisotropy =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->textureCompressionETC2 == VK_TRUE) && (query.textureCompressionETC2 == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature textureCompressionETC2 %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->textureCompressionETC2 =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->textureCompressionASTC_LDR == VK_TRUE) && (query.textureCompressionASTC_LDR == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature textureCompressionASTC_LDR %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->textureCompressionASTC_LDR =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->textureCompressionBC == VK_TRUE) && (query.textureCompressionBC == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature textureCompressionBC %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->textureCompressionBC =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->occlusionQueryPrecise == VK_TRUE) && (query.occlusionQueryPrecise == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature occlusionQueryPrecise %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->occlusionQueryPrecise =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->pipelineStatisticsQuery == VK_TRUE) && (query.pipelineStatisticsQuery == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature pipelineStatisticsQuery %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->pipelineStatisticsQuery =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->vertexPipelineStoresAndAtomics == VK_TRUE) && (query.vertexPipelineStoresAndAtomics == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature vertexPipelineStoresAndAtomics %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->vertexPipelineStoresAndAtomics =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->fragmentStoresAndAtomics == VK_TRUE) && (query.fragmentStoresAndAtomics == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature fragmentStoresAndAtomics %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->fragmentStoresAndAtomics =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderTessellationAndGeometryPointSize == VK_TRUE) && (query.shaderTessellationAndGeometryPointSize == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderTessellationAndGeometryPointSize %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderTessellationAndGeometryPointSize =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderImageGatherExtended == VK_TRUE) && (query.shaderImageGatherExtended == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderImageGatherExtended %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderImageGatherExtended =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderStorageImageExtendedFormats == VK_TRUE) && (query.shaderStorageImageExtendedFormats == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderStorageImageExtendedFormats %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderStorageImageExtendedFormats =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderStorageImageMultisample == VK_TRUE) && (query.shaderStorageImageMultisample == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderStorageImageMultisample %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderStorageImageMultisample =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderStorageImageReadWithoutFormat == VK_TRUE) && (query.shaderStorageImageReadWithoutFormat == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderStorageImageReadWithoutFormat %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderStorageImageReadWithoutFormat =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderStorageImageWriteWithoutFormat == VK_TRUE) && (query.shaderStorageImageWriteWithoutFormat == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderStorageImageWriteWithoutFormat %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderStorageImageWriteWithoutFormat =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderUniformBufferArrayDynamicIndexing == VK_TRUE) && (query.shaderUniformBufferArrayDynamicIndexing == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderUniformBufferArrayDynamicIndexing %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderUniformBufferArrayDynamicIndexing =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderSampledImageArrayDynamicIndexing == VK_TRUE) && (query.shaderSampledImageArrayDynamicIndexing == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderSampledImageArrayDynamicIndexing %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderSampledImageArrayDynamicIndexing =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderStorageBufferArrayDynamicIndexing == VK_TRUE) && (query.shaderStorageBufferArrayDynamicIndexing == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderStorageBufferArrayDynamicIndexing %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderStorageBufferArrayDynamicIndexing =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderStorageImageArrayDynamicIndexing == VK_TRUE) && (query.shaderStorageImageArrayDynamicIndexing == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderStorageImageArrayDynamicIndexing %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderStorageImageArrayDynamicIndexing =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderClipDistance == VK_TRUE) && (query.shaderClipDistance == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderClipDistance %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderClipDistance =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderCullDistance == VK_TRUE) && (query.shaderCullDistance == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderCullDistance %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderCullDistance =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderFloat64 == VK_TRUE) && (query.shaderFloat64 == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderFloat64 %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderFloat64 =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderInt64 == VK_TRUE) && (query.shaderInt64 == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderInt64 %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderInt64 =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderInt16 == VK_TRUE) && (query.shaderInt16 == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderInt16 %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderInt16 =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderResourceResidency == VK_TRUE) && (query.shaderResourceResidency == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderResourceResidency %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderResourceResidency =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->shaderResourceMinLod == VK_TRUE) && (query.shaderResourceMinLod == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature shaderResourceMinLod %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->shaderResourceMinLod =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->sparseBinding == VK_TRUE) && (query.sparseBinding == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseBinding %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseBinding =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->sparseResidencyBuffer == VK_TRUE) && (query.sparseResidencyBuffer == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidencyBuffer %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidencyBuffer =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->sparseResidencyImage2D == VK_TRUE) && (query.sparseResidencyImage2D == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidencyImage2D %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidencyImage2D =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->sparseResidencyImage3D == VK_TRUE) && (query.sparseResidencyImage3D == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidencyImage3D %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidencyImage3D =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->sparseResidency2Samples == VK_TRUE) && (query.sparseResidency2Samples == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidency2Samples %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidency2Samples =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->sparseResidency4Samples == VK_TRUE) && (query.sparseResidency4Samples == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidency4Samples %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidency4Samples =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->sparseResidency8Samples == VK_TRUE) && (query.sparseResidency8Samples == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidency8Samples %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidency8Samples =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->sparseResidency16Samples == VK_TRUE) && (query.sparseResidency16Samples == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidency16Samples %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidency16Samples =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->sparseResidencyAliased == VK_TRUE) && (query.sparseResidencyAliased == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature sparseResidencyAliased %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->sparseResidencyAliased =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->variableMultisampleRate == VK_TRUE) && (query.variableMultisampleRate == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature variableMultisampleRate %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->variableMultisampleRate =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
        if ((physicalDeviceFeatures->inheritedQueries == VK_TRUE) && (query.inheritedQueries == VK_FALSE))
        {
            GFXRECON_LOG_WARNING("Feature inheritedQueries %s", warn_message);
            found_unsupported = true;
            const_cast<VkPhysicalDeviceFeatures*>(physicalDeviceFeatures)->inheritedQueries =
                remove_unsupported ? VK_FALSE : VK_TRUE;
        }
    }

    if (!remove_unsupported && found_unsupported)
    {
        GFXRECON_LOG_WARNING("Unsupported features were requested. This might cause vkCreateDevice to fail. Try \"--remove-unsupported\" option to remove those features at replay.");
    }
}

GFXRECON_END_NAMESPACE(feature_util)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
