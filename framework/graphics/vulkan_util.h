/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_GRAPHICS_VULKAN_UTIL_H
#define GFXRECON_GRAPHICS_VULKAN_UTIL_H

#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

// Search through the parent's pNext chain for the first struct with the requested struct_type. parent's struct type is
// not checked and parent won't be returned as a result. T and Parent_T must be Vulkan struct pointer types. Return
// nullptr if no matching struct found.
template <typename T, typename Parent_T>
static T* GetPNextStruct(const Parent_T* parent, VkStructureType struct_type)
{
    VkBaseOutStructure* current_struct = reinterpret_cast<const VkBaseOutStructure*>(parent)->pNext;
    while (current_struct != nullptr)
    {
        if (current_struct->sType == struct_type)
        {
            return reinterpret_cast<T*>(current_struct);
        }
    }
    return nullptr;
}

struct ModifiedPhysicalDeviceFeatures
{
    // VkPhysicalDeviceBufferDeviceAddressFeatures::bufferDeviceAddressCaptureReplay
    VkBool32* bufferDeviceAddressCaptureReplay_ptr{ nullptr };
    VkBool32  bufferDeviceAddressCaptureReplay_original{ VK_FALSE };

    // VkPhysicalDeviceAccelerationStructureFeaturesKHR::accelerationStructureCaptureReplay
    VkBool32* accelerationStructureCaptureReplay_ptr{ nullptr };
    VkBool32  accelerationStructureCaptureReplay_original{ VK_FALSE };

    // VkPhysicalDeviceRayTracingPipelineFeaturesKHR::rayTracingPipelineShaderGroupHandleCaptureReplay
    VkBool32* rayTracingPipelineShaderGroupHandleCaptureReplay_ptr{ nullptr };
    VkBool32  rayTracingPipelineShaderGroupHandleCaptureReplay_original{ VK_FALSE };

    // Store associated physical device capture replay properties

    // VkPhysicalDeviceRayTracingPipelinePropertiesKHR::shaderGroupHandleCaptureReplaySize
    uint32_t shaderGroupHandleCaptureReplaySize{ 0 };
};

// Try to enable the device features required for application capture and replay
void EnableRequiredPhysicalDeviceFeatures(uint32_t                        instance_api_version,
                                          const encode::InstanceTable*    instance_table,
                                          const VkPhysicalDevice          physical_device,
                                          const VkDeviceCreateInfo*       create_info,
                                          ModifiedPhysicalDeviceFeatures& modified_features);

// Restore feature values that may have been modified by EnableRequiredPhysicalDeviceFeatures().
void RestoreModifiedPhysicalDeviceFeatures(const ModifiedPhysicalDeviceFeatures& modified_features);

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_UTIL_H
