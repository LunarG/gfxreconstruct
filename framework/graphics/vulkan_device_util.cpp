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

#include "graphics/vulkan_device_util.h"
#include "decode/vulkan_object_info.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

// Query specific physical device features struct
// Requires Vulkan version >= 1.1 or VK_KHR_get_physical_device_properties2
// feature_struct sType must be set, pNext must be nullptr
template <typename T>
static void GetPhysicalDeviceFeatures(uint32_t                           instance_api_version,
                                      const encode::VulkanInstanceTable* instance_table,
                                      const VkPhysicalDevice             physical_device,
                                      T&                                 feature_struct)
{
    assert((feature_struct.sType != 0) && (feature_struct.pNext == nullptr));
    feature_struct.pNext = nullptr;
    VkPhysicalDeviceFeatures2 features2{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2 };
    features2.pNext = &feature_struct;
    if (instance_api_version >= VK_MAKE_VERSION(1, 1, 0))
    {
        instance_table->GetPhysicalDeviceFeatures2(physical_device, &features2);
    }
    else
    {
        instance_table->GetPhysicalDeviceFeatures2KHR(physical_device, &features2);
    }
}

// Query physical device properties struct
// Requires Vulkan version >= 1.1 or VK_KHR_get_physical_device_properties2
// properties_struct sType must be set, pNext must be nullptr
template <typename T>
static void GetPhysicalDeviceProperties(uint32_t                           instance_api_version,
                                        const encode::VulkanInstanceTable* instance_table,
                                        const VkPhysicalDevice             physical_device,
                                        T&                                 properties_struct)
{
    assert((properties_struct.sType != 0) && (properties_struct.pNext == nullptr));
    properties_struct.pNext = nullptr;
    VkPhysicalDeviceProperties2 properties2{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2 };
    properties2.pNext = &properties_struct;
    if (instance_api_version >= VK_MAKE_VERSION(1, 1, 0))
    {
        instance_table->GetPhysicalDeviceProperties2(physical_device, &properties2);
    }
    else
    {
        instance_table->GetPhysicalDeviceProperties2KHR(physical_device, &properties2);
    }
}

template <typename T>
VkBool32 VulkanDeviceUtil::EnableRequiredBufferDeviceAddressFeatures(uint32_t instance_api_version,
                                                                     const encode::VulkanInstanceTable* instance_table,
                                                                     const VkPhysicalDevice             physical_device,
                                                                     T*                                 feature_struct)
{
    // Type must be feature struct type that contains bufferDeviceAddress and bufferDeviceAddressCaptureReplay
    static_assert(std::is_same<T, VkPhysicalDeviceVulkan12Features>::value ||
                      std::is_same<T, VkPhysicalDeviceBufferDeviceAddressFeatures>::value,
                  "Unexpected type for EnableRequiredBufferDeviceAddressFeatures");

    // Only one device address feature struct should be present, so bufferDeviceAddressCaptureReplay_ptr should not have
    // been set yet
    assert(bufferDeviceAddressCaptureReplay_ptr == nullptr);
    if (bufferDeviceAddressCaptureReplay_ptr != nullptr)
    {
        return VK_FALSE;
    }

    // Save original application's feature state
    bufferDeviceAddressCaptureReplay_original = feature_struct->bufferDeviceAddressCaptureReplay;
    bufferDeviceAddressCaptureReplay_ptr      = (&feature_struct->bufferDeviceAddressCaptureReplay);

    // Enable the capture replay flag device addresses if bufferDeviceAddress is enabled and the capture replay feature
    // is supported by the device
    if (feature_struct->bufferDeviceAddress && !feature_struct->bufferDeviceAddressCaptureReplay)
    {
        // Get buffer_address properties
        T supported_features{ feature_struct->sType, nullptr };
        GetPhysicalDeviceFeatures(instance_api_version, instance_table, physical_device, supported_features);

        // Enable bufferDeviceAddressCaptureReplay if it is supported
        if (supported_features.bufferDeviceAddressCaptureReplay)
        {
            feature_struct->bufferDeviceAddressCaptureReplay = VK_TRUE;
        }
    }

    return feature_struct->bufferDeviceAddressCaptureReplay;
}

VulkanDevicePropertyFeatureInfo
VulkanDeviceUtil::EnableRequiredPhysicalDeviceFeatures(uint32_t                           instance_api_version,
                                                       const encode::VulkanInstanceTable* instance_table,
                                                       const VkPhysicalDevice             physical_device,
                                                       const VkDeviceCreateInfo*          create_info)
{
    VulkanDevicePropertyFeatureInfo result;
    VkBaseOutStructure*             current_struct = reinterpret_cast<const VkBaseOutStructure*>(create_info)->pNext;
    while (current_struct != nullptr)
    {
        switch (current_struct->sType)
        {
            // Enable bufferDeviceAddressCaptureReplay if bufferDeviceAddress feature is enabled
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            {
                auto vulkan_1_2_features = reinterpret_cast<VkPhysicalDeviceVulkan12Features*>(current_struct);
                result.feature_bufferDeviceAddressCaptureReplay = EnableRequiredBufferDeviceAddressFeatures(
                    instance_api_version, instance_table, physical_device, vulkan_1_2_features);
            }
            break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            {
                auto buffer_address_features =
                    reinterpret_cast<VkPhysicalDeviceBufferDeviceAddressFeatures*>(current_struct);
                result.feature_bufferDeviceAddressCaptureReplay = EnableRequiredBufferDeviceAddressFeatures(
                    instance_api_version, instance_table, physical_device, buffer_address_features);
            }
            break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            {
                // Enable accelerationStructureCaptureReplay
                auto accel_struct_features =
                    reinterpret_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(current_struct);

                accelerationStructureCaptureReplay_ptr = (&accel_struct_features->accelerationStructureCaptureReplay);
                accelerationStructureCaptureReplay_original = accel_struct_features->accelerationStructureCaptureReplay;

                if (accel_struct_features->accelerationStructure &&
                    !accel_struct_features->accelerationStructureCaptureReplay)
                {
                    // Get acceleration struct properties
                    VkPhysicalDeviceAccelerationStructureFeaturesKHR supported_features{
                        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR, nullptr
                    };
                    GetPhysicalDeviceFeatures(
                        instance_api_version, instance_table, physical_device, supported_features);

                    // Enable accelerationStructureCaptureReplay if it is supported
                    if (supported_features.accelerationStructureCaptureReplay)
                    {
                        accel_struct_features->accelerationStructureCaptureReplay = VK_TRUE;
                    }
                }

                result.feature_accelerationStructureCaptureReplay =
                    accel_struct_features->accelerationStructureCaptureReplay;
            }
            break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            {
                // Enable rayTracingPipelineShaderGroupHandleCaptureReplay
                auto rt_pipeline_features =
                    reinterpret_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(current_struct);

                rayTracingPipelineShaderGroupHandleCaptureReplay_ptr =
                    (&rt_pipeline_features->rayTracingPipelineShaderGroupHandleCaptureReplay);
                rayTracingPipelineShaderGroupHandleCaptureReplay_original =
                    rt_pipeline_features->rayTracingPipelineShaderGroupHandleCaptureReplay;

                if (rt_pipeline_features->rayTracingPipeline &&
                    !rt_pipeline_features->rayTracingPipelineShaderGroupHandleCaptureReplay)
                {
                    VkPhysicalDeviceRayTracingPipelineFeaturesKHR supported_features{
                        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR, nullptr
                    };
                    GetPhysicalDeviceFeatures(
                        instance_api_version, instance_table, physical_device, supported_features);

                    rt_pipeline_features->rayTracingPipelineShaderGroupHandleCaptureReplay =
                        supported_features.rayTracingPipelineShaderGroupHandleCaptureReplay;
                }

                result.feature_rayTracingPipelineShaderGroupHandleCaptureReplay =
                    rt_pipeline_features->rayTracingPipelineShaderGroupHandleCaptureReplay;
                if (result.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
                {
                    VkPhysicalDeviceRayTracingPipelinePropertiesKHR rt_properties{
                        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR, nullptr
                    };
                    GetPhysicalDeviceProperties(instance_api_version, instance_table, physical_device, rt_properties);

                    result.property_shaderGroupHandleCaptureReplaySize =
                        rt_properties.shaderGroupHandleCaptureReplaySize;
                }
            }
            break;
            default:
                break;
        }
        current_struct = current_struct->pNext;
    }

    return result;
}

void VulkanDeviceUtil::RestoreModifiedPhysicalDeviceFeatures()
{
    if (bufferDeviceAddressCaptureReplay_ptr != nullptr)
    {
        (*bufferDeviceAddressCaptureReplay_ptr) = bufferDeviceAddressCaptureReplay_original;
        bufferDeviceAddressCaptureReplay_ptr    = nullptr;
    }
    if (accelerationStructureCaptureReplay_ptr != nullptr)
    {
        (*accelerationStructureCaptureReplay_ptr) = accelerationStructureCaptureReplay_original;
        accelerationStructureCaptureReplay_ptr    = nullptr;
    }
    if (rayTracingPipelineShaderGroupHandleCaptureReplay_ptr != nullptr)
    {
        (*rayTracingPipelineShaderGroupHandleCaptureReplay_ptr) =
            rayTracingPipelineShaderGroupHandleCaptureReplay_original;
        rayTracingPipelineShaderGroupHandleCaptureReplay_ptr = nullptr;
    }
}

void VulkanDeviceUtil::GetReplayDeviceProperties(uint32_t                           instance_api_version,
                                                 const encode::VulkanInstanceTable* instance_table,
                                                 VkPhysicalDevice                   physical_device,
                                                 decode::VulkanReplayDeviceInfo*    replay_device_info)
{
    GFXRECON_ASSERT(instance_table != nullptr);
    GFXRECON_ASSERT(replay_device_info != nullptr);

    VkPhysicalDeviceProperties2 device_properties2;
    device_properties2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;

    if (instance_api_version >= VK_MAKE_VERSION(1, 1, 0))
    {
        // pNext-chaining
        VkPhysicalDeviceRayTracingPipelinePropertiesKHR raytracing_properties;
        raytracing_properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR;
        raytracing_properties.pNext = nullptr;
        device_properties2.pNext    = &raytracing_properties;

        instance_table->GetPhysicalDeviceProperties2(physical_device, &device_properties2);
        replay_device_info->raytracing_properties = raytracing_properties;
    }
    else
    {
        instance_table->GetPhysicalDeviceProperties(physical_device, &device_properties2.properties);
    }
    replay_device_info->properties = device_properties2.properties;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
