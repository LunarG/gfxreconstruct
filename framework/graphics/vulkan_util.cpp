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

#include "graphics/vulkan_util.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

// Query for supported features from the given features struct type T, result is saved to feature_struct
template <typename T>
static void GetSupportedPhysicalDeviceFeatures(uint32_t                     instance_api_version,
                                               const encode::InstanceTable* instance_table,
                                               const VkPhysicalDevice       physical_device,
                                               T*                           feature_struct)
{
    VkPhysicalDeviceFeatures2 features2{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2 };
    features2.pNext = feature_struct;
    if (instance_api_version >= VK_MAKE_VERSION(1, 1, 0))
    {
        instance_table->GetPhysicalDeviceFeatures2(physical_device, &features2);
    }
    else
    {
        instance_table->GetPhysicalDeviceFeatures2KHR(physical_device, &features2);
    }
}

template <typename T>
static void EnableRequiredBufferDeviceAddressFeatures(uint32_t                        instance_api_version,
                                                      const encode::InstanceTable*    instance_table,
                                                      const VkPhysicalDevice          physical_device,
                                                      T*                              feature_struct,
                                                      ModifiedPhysicalDeviceFeatures& modified_features)
{
    // Type must be feature struct type that contains bufferDeviceAddress and bufferDeviceAddressCaptureReplay
    static_assert(std::is_same<T, VkPhysicalDeviceVulkan12Features>::value ||
                      std::is_same<T, VkPhysicalDeviceBufferDeviceAddressFeatures>::value,
                  "Unexpected type for EnableRequiredBufferDeviceAddressFeatures");

    // Only one device address feature struct should be present, so bufferDeviceAddressCaptureReplay_ptr should not have
    // been set yet
    assert(modified_features.bufferDeviceAddressCaptureReplay_ptr == nullptr);
    if (modified_features.bufferDeviceAddressCaptureReplay_ptr != nullptr)
    {
        return;
    }

    // Save original application's feature state
    modified_features.bufferDeviceAddressCaptureReplay_original = feature_struct->bufferDeviceAddressCaptureReplay;
    modified_features.bufferDeviceAddressCaptureReplay_ptr      = (&feature_struct->bufferDeviceAddressCaptureReplay);

    // Enable the capture replay flag device addresses if bufferDeviceAddress is enabled and the capture replay feature
    // is supported by the device
    if (feature_struct->bufferDeviceAddress && !feature_struct->bufferDeviceAddressCaptureReplay)
    {
        // Get buffer_address properties
        T supported_features{ feature_struct->sType };
        GetSupportedPhysicalDeviceFeatures<T>(
            instance_api_version, instance_table, physical_device, &supported_features);

        // Enable bufferDeviceAddressCaptureReplay if it is supported
        if (supported_features.bufferDeviceAddressCaptureReplay)
        {
            feature_struct->bufferDeviceAddressCaptureReplay = VK_TRUE;
        }
    }
}

void EnableRequiredPhysicalDeviceFeatures(uint32_t                        instance_api_version,
                                          const encode::InstanceTable*    instance_table,
                                          const VkPhysicalDevice          physical_device,
                                          const VkDeviceCreateInfo*       create_info,
                                          ModifiedPhysicalDeviceFeatures& modified_features)
{
    VkBaseOutStructure* current_struct = reinterpret_cast<const VkBaseOutStructure*>(create_info)->pNext;
    while (current_struct != nullptr)
    {
        switch (current_struct->sType)
        {
            // Enable bufferDeviceAddressCaptureReplay if bufferDeviceAddress feature is enabled
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            {
                auto vulkan_1_2_features = reinterpret_cast<VkPhysicalDeviceVulkan12Features*>(current_struct);
                EnableRequiredBufferDeviceAddressFeatures<VkPhysicalDeviceVulkan12Features>(
                    instance_api_version, instance_table, physical_device, vulkan_1_2_features, modified_features);
            }
            break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            {
                auto buffer_address_features =
                    reinterpret_cast<VkPhysicalDeviceBufferDeviceAddressFeatures*>(current_struct);
                EnableRequiredBufferDeviceAddressFeatures<VkPhysicalDeviceBufferDeviceAddressFeatures>(
                    instance_api_version, instance_table, physical_device, buffer_address_features, modified_features);
            }
            break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            {
                GFXRECON_LOG_ERROR("Extension %s is not supported by GFXReconstruct.",
                                   VK_EXT_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME);
            }
            break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            {
                // Enable accelerationStructureCaptureReplay
                auto accel_struct_features =
                    reinterpret_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(current_struct);

                modified_features.accelerationStructureCaptureReplay_ptr =
                    (&accel_struct_features->accelerationStructureCaptureReplay);
                modified_features.accelerationStructureCaptureReplay_original =
                    accel_struct_features->accelerationStructureCaptureReplay;

                if (accel_struct_features->accelerationStructure &&
                    !accel_struct_features->accelerationStructureCaptureReplay)
                {
                    // Get acceleration struct properties
                    VkPhysicalDeviceAccelerationStructureFeaturesKHR supported_features{
                        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR
                    };
                    GetSupportedPhysicalDeviceFeatures<VkPhysicalDeviceAccelerationStructureFeaturesKHR>(
                        instance_api_version, instance_table, physical_device, &supported_features);

                    // Enable accelerationStructureCaptureReplay if it is supported
                    if (supported_features.accelerationStructureCaptureReplay)
                    {
                        accel_struct_features->accelerationStructureCaptureReplay = VK_TRUE;
                    }
                }
            }
            break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            {
                // Enable rayTracingPipelineShaderGroupHandleCaptureReplay
                auto rt_pipeline_features =
                    reinterpret_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(current_struct);

                modified_features.rayTracingPipelineShaderGroupHandleCaptureReplay_ptr =
                    (&rt_pipeline_features->rayTracingPipelineShaderGroupHandleCaptureReplay);
                modified_features.rayTracingPipelineShaderGroupHandleCaptureReplay_original =
                    rt_pipeline_features->rayTracingPipelineShaderGroupHandleCaptureReplay;

                if (rt_pipeline_features->rayTracingPipeline &&
                    !rt_pipeline_features->rayTracingPipelineShaderGroupHandleCaptureReplay)
                {
                    VkPhysicalDeviceRayTracingPipelineFeaturesKHR supported_features{
                        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR
                    };
                    GetSupportedPhysicalDeviceFeatures<VkPhysicalDeviceRayTracingPipelineFeaturesKHR>(
                        instance_api_version, instance_table, physical_device, &supported_features);

                    if (supported_features.rayTracingPipelineShaderGroupHandleCaptureReplay)
                    {
                        rt_pipeline_features->rayTracingPipelineShaderGroupHandleCaptureReplay = VK_TRUE;
                    }
                }
            }
            break;
            default:
                break;
        }
        current_struct = current_struct->pNext;
    }
}

void RestoreModifiedPhysicalDeviceFeatures(const ModifiedPhysicalDeviceFeatures& modified_features)
{
    if (modified_features.bufferDeviceAddressCaptureReplay_ptr != nullptr)
    {
        (*modified_features.bufferDeviceAddressCaptureReplay_ptr) =
            modified_features.bufferDeviceAddressCaptureReplay_original;
    }
    if (modified_features.accelerationStructureCaptureReplay_ptr != nullptr)
    {
        (*modified_features.accelerationStructureCaptureReplay_ptr) =
            modified_features.accelerationStructureCaptureReplay_original;
    }
    if (modified_features.rayTracingPipelineShaderGroupHandleCaptureReplay_ptr != nullptr)
    {
        (*modified_features.rayTracingPipelineShaderGroupHandleCaptureReplay_ptr) =
            modified_features.rayTracingPipelineShaderGroupHandleCaptureReplay_original;
    }
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
