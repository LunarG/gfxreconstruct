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

#ifndef GFXRECON_GRAPHICS_VULKAN_DEVICE_UTIL_H
#define GFXRECON_GRAPHICS_VULKAN_DEVICE_UTIL_H

#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

namespace gfxrecon::decode
{
//! forward declaration to avoid cyclic include
struct VulkanReplayDeviceInfo;
} // namespace gfxrecon::decode

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

struct VulkanDevicePropertyFeatureInfo
{
    uint32_t property_shaderGroupHandleCaptureReplaySize{ 0 };

    VkBool32 feature_bufferDeviceAddressCaptureReplay{ VK_FALSE };
    VkBool32 feature_accelerationStructureCaptureReplay{ VK_FALSE };
    VkBool32 feature_rayTracingPipelineShaderGroupHandleCaptureReplay{ VK_FALSE };
};

class VulkanDeviceUtil
{
  public:
    // Try to enable the device features required for application capture and replay
    // Incoming create_info data will be modified. Use RestoreModifiedPhysicalDeviceFeatures
    // to revert incoming data to original values (e.g., prior to writing to the capture file).
    // feature_* property_* members store the state of the features/properties after this call.
    VulkanDevicePropertyFeatureInfo
    EnableRequiredPhysicalDeviceFeatures(uint32_t                           instance_api_version,
                                         const encode::VulkanInstanceTable* instance_table,
                                         const VkPhysicalDevice             physical_device,
                                         const VkDeviceCreateInfo*          create_info);

    // Restore any incoming values that were modified in EnableRequiredPhysicalDeviceFeatures
    void RestoreModifiedPhysicalDeviceFeatures();

    // Populates various property-structs in the provided replay_device_info
    static void GetReplayDeviceProperties(uint32_t                           instance_api_version,
                                          const encode::VulkanInstanceTable* instance_table,
                                          VkPhysicalDevice                   physical_device,
                                          decode::VulkanReplayDeviceInfo*    replay_device_info);

  private:
    template <typename T>
    VkBool32 EnableRequiredBufferDeviceAddressFeatures(uint32_t                           instance_api_version,
                                                       const encode::VulkanInstanceTable* instance_table,
                                                       const VkPhysicalDevice             physical_device,
                                                       T*                                 feature_struct);

  private:
    // VkPhysicalDeviceBufferDeviceAddressFeatures::bufferDeviceAddressCaptureReplay
    VkBool32* bufferDeviceAddressCaptureReplay_ptr{ nullptr };
    VkBool32  bufferDeviceAddressCaptureReplay_original{ VK_FALSE };

    // VkPhysicalDeviceAccelerationStructureFeaturesKHR::accelerationStructureCaptureReplay
    VkBool32* accelerationStructureCaptureReplay_ptr{ nullptr };
    VkBool32  accelerationStructureCaptureReplay_original{ VK_FALSE };

    // VkPhysicalDeviceRayTracingPipelineFeaturesKHR::rayTracingPipelineShaderGroupHandleCaptureReplay
    VkBool32* rayTracingPipelineShaderGroupHandleCaptureReplay_ptr{ nullptr };
    VkBool32  rayTracingPipelineShaderGroupHandleCaptureReplay_original{ VK_FALSE };
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_DEVICE_UTIL_H
