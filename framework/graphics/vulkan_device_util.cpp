/*
** Copyright (c) 2021-2025 LunarG, Inc.
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
#include "graphics/vulkan_instance_util.h"
#include "decode/vulkan_object_info.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

uint32_t GetMemoryTypeIndex(const VkPhysicalDeviceMemoryProperties& memory_properties,
                            uint32_t                                type_bits,
                            VkMemoryPropertyFlags                   property_flags)
{
    uint32_t memory_type_index = std::numeric_limits<uint32_t>::max();

    for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
    {
        if ((type_bits & (1 << i)) &&
            ((memory_properties.memoryTypes[i].propertyFlags & property_flags) == property_flags))
        {
            memory_type_index = i;
            break;
        }
    }

    return memory_type_index;
}

// Query specific physical device features struct
// Requires Vulkan version >= 1.1 or VK_KHR_get_physical_device_properties2
// feature_struct sType must be set, pNext must be nullptr
template <typename T>
static void GetPhysicalDeviceFeatures(const VulkanInstanceUtilInfo& instance_info,
                                      const VulkanInstanceTable*    instance_table,
                                      const VkPhysicalDevice        physical_device,
                                      T&                            feature_struct)
{
    assert((feature_struct.sType != 0) && (feature_struct.pNext == nullptr));
    feature_struct.pNext = nullptr;
    VkPhysicalDeviceFeatures2 features2{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2 };
    features2.pNext = &feature_struct;
    if (instance_info.api_version >= VK_MAKE_VERSION(1, 1, 0))
    {
        instance_table->GetPhysicalDeviceFeatures2(physical_device, &features2);
    }
    else if (instance_info.IsEnabledExtension(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME))
    {
        instance_table->GetPhysicalDeviceFeatures2KHR(physical_device, &features2);
    }
}

// Query physical device properties struct
// Requires Vulkan version >= 1.1 or VK_KHR_get_physical_device_properties2
// properties_struct sType must be set, pNext must be nullptr
template <typename T>
static void GetPhysicalDeviceProperties(const VulkanInstanceUtilInfo& instance_info,
                                        const VulkanInstanceTable*    instance_table,
                                        const VkPhysicalDevice        physical_device,
                                        T&                            properties_struct)
{
    assert((properties_struct.sType != 0) && (properties_struct.pNext == nullptr));
    properties_struct.pNext = nullptr;
    VkPhysicalDeviceProperties2 properties2{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2 };
    properties2.pNext = &properties_struct;
    if (instance_info.api_version >= VK_MAKE_VERSION(1, 1, 0))
    {
        instance_table->GetPhysicalDeviceProperties2(physical_device, &properties2);
    }
    else if (instance_info.IsEnabledExtension(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME))
    {
        instance_table->GetPhysicalDeviceProperties2KHR(physical_device, &properties2);
    }
}

template <typename T>
VkBool32 VulkanDeviceUtil::EnableRequiredBufferDeviceAddressFeatures(const VulkanInstanceUtilInfo& instance_info,
                                                                     const VulkanInstanceTable*    instance_table,
                                                                     const VkPhysicalDevice        physical_device,
                                                                     T*                            feature_struct)
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
        GetPhysicalDeviceFeatures(instance_info, instance_table, physical_device, supported_features);

        // Enable bufferDeviceAddressCaptureReplay if it is supported
        if (supported_features.bufferDeviceAddressCaptureReplay)
        {
            feature_struct->bufferDeviceAddressCaptureReplay = VK_TRUE;
        }
    }

    return feature_struct->bufferDeviceAddressCaptureReplay;
}

template <typename T>
VkBool32 VulkanDeviceUtil::EnableSamplerYcbcrConversionFeatures(const VulkanInstanceUtilInfo& instance_info,
                                                                const VulkanInstanceTable*    instance_table,
                                                                const VkPhysicalDevice        physical_device,
                                                                T*                            feature_struct)
{
    // Type must be feature struct type that contains samplerYcbcrConversion
    static_assert(std::is_same<T, VkPhysicalDeviceVulkan11Features>::value ||
                      std::is_same<T, VkPhysicalDeviceSamplerYcbcrConversionFeatures>::value,
                  "Unexpected type for EnableSamplerYcbcrConversionFeatures");

    // Save original application's feature state
    samplerYcbcrConversion_original = feature_struct->samplerYcbcrConversion;
    samplerYcbcrConversion_ptr      = (&feature_struct->samplerYcbcrConversion);

    // Enable the sampler Ycbcr conversion feature if it supported by the device
    if (!feature_struct->samplerYcbcrConversion)
    {
        T supported_features{ feature_struct->sType, nullptr };
        GetPhysicalDeviceFeatures(instance_info, instance_table, physical_device, supported_features);

        if (supported_features.samplerYcbcrConversion)
        {
            feature_struct->samplerYcbcrConversion = VK_TRUE;
        }
    }

    return feature_struct->samplerYcbcrConversion;
}

VulkanDevicePropertyFeatureInfo
VulkanDeviceUtil::EnableRequiredPhysicalDeviceFeatures(const VulkanInstanceUtilInfo& instance_info,
                                                       const VulkanInstanceTable*    instance_table,
                                                       const VkPhysicalDevice        physical_device,
                                                       const VkDeviceCreateInfo*     create_info)
{
    VulkanDevicePropertyFeatureInfo result;
    GFXRECON_ASSERT(create_info != nullptr);
    VkBaseOutStructure* current_struct =
        const_cast<VkBaseOutStructure*>(reinterpret_cast<const VkBaseOutStructure*>(create_info));

    // If the pNext chain includes a VkPhysicalDeviceVulkan11Features structure, then it must not include a
    // VkPhysicalDeviceSamplerYcbcrConversionFeatures structure
    bool vulkan_1_1_features_found               = false;
    bool sampler_ycbcr_conversion_features_found = false;

    while (current_struct->pNext != nullptr)
    {
        current_struct = current_struct->pNext;
        switch (current_struct->sType)
        {
            // Enable bufferDeviceAddressCaptureReplay if bufferDeviceAddress feature is enabled
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            {
                auto vulkan_1_2_features = reinterpret_cast<VkPhysicalDeviceVulkan12Features*>(current_struct);
                result.feature_bufferDeviceAddressCaptureReplay = EnableRequiredBufferDeviceAddressFeatures(
                    instance_info, instance_table, physical_device, vulkan_1_2_features);
            }
            break;
            // samplerYcbcrConversion is required for sampling images with external format
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            {
                sampler_ycbcr_conversion_features_found = true;
                auto* sampler_ycbcr_conversion_features =
                    reinterpret_cast<VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(current_struct);
                result.feature_samplerYcbcrConversion = EnableSamplerYcbcrConversionFeatures(
                    instance_info, instance_table, physical_device, sampler_ycbcr_conversion_features);
            }
            break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            {
                vulkan_1_1_features_found = true;
                auto* vulkan_1_1_features = reinterpret_cast<VkPhysicalDeviceVulkan11Features*>(current_struct);
                result.feature_samplerYcbcrConversion = EnableSamplerYcbcrConversionFeatures(
                    instance_info, instance_table, physical_device, vulkan_1_1_features);
            }
            break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            {
                auto buffer_address_features =
                    reinterpret_cast<VkPhysicalDeviceBufferDeviceAddressFeatures*>(current_struct);
                result.feature_bufferDeviceAddressCaptureReplay = EnableRequiredBufferDeviceAddressFeatures(
                    instance_info, instance_table, physical_device, buffer_address_features);
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
                    GetPhysicalDeviceFeatures(instance_info, instance_table, physical_device, supported_features);

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
                    GetPhysicalDeviceFeatures(instance_info, instance_table, physical_device, supported_features);

                    rt_pipeline_features->rayTracingPipelineShaderGroupHandleCaptureReplay =
                        supported_features.rayTracingPipelineShaderGroupHandleCaptureReplay;
                }

                result.feature_rayTracingPipelineShaderGroupHandleCaptureReplay =
                    rt_pipeline_features->rayTracingPipelineShaderGroupHandleCaptureReplay;

                // retrieve raytracing-pipeline-properties
                VkPhysicalDeviceRayTracingPipelinePropertiesKHR rt_properties{
                    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR, nullptr
                };
                GetPhysicalDeviceProperties(instance_info, instance_table, physical_device, rt_properties);
                result.property_shaderGroupHandleSize = rt_properties.shaderGroupHandleSize;

                if (result.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
                {
                    result.property_shaderGroupHandleCaptureReplaySize =
                        rt_properties.shaderGroupHandleCaptureReplaySize;
                }
            }
            break;
            default:
                break;
        }
    }

    if (!vulkan_1_1_features_found && !sampler_ycbcr_conversion_features_found)
    {
        // If the app is not requesting any Vulkan 1.1 feature or sampler YCbCr conversion feature, inject our own.
        static VkPhysicalDeviceSamplerYcbcrConversionFeatures sampler_ycbcr_conversion_features = {
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES
        };
        result.feature_samplerYcbcrConversion = EnableSamplerYcbcrConversionFeatures(
            instance_info, instance_table, physical_device, &sampler_ycbcr_conversion_features);
        if (result.feature_samplerYcbcrConversion == VK_TRUE)
        {
            current_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(&sampler_ycbcr_conversion_features);
        }
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

void VulkanDeviceUtil::GetReplayDeviceProperties(const VulkanInstanceUtilInfo&   instance_info,
                                                 const VulkanInstanceTable*      instance_table,
                                                 VkPhysicalDevice                physical_device,
                                                 decode::VulkanReplayDeviceInfo* replay_device_info)
{
    GFXRECON_ASSERT(instance_table != nullptr);
    GFXRECON_ASSERT(replay_device_info != nullptr);

    VkPhysicalDeviceProperties2 device_properties2;
    device_properties2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;

    if (instance_info.api_version >= VK_MAKE_VERSION(1, 1, 0))
    {
        // pNext-chaining
        VkPhysicalDeviceDriverProperties driver_properties = {};
        driver_properties.sType                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES;

        VkPhysicalDeviceRayTracingPipelinePropertiesKHR raytracing_properties = {};
        raytracing_properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR;

        raytracing_properties.pNext = &driver_properties;
        device_properties2.pNext    = &raytracing_properties;

        instance_table->GetPhysicalDeviceProperties2(physical_device, &device_properties2);
        replay_device_info->raytracing_properties = raytracing_properties;
        replay_device_info->driver_properties     = driver_properties;
    }
    else
    {
        instance_table->GetPhysicalDeviceProperties(physical_device, &device_properties2.properties);
    }
    replay_device_info->properties = device_properties2.properties;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
