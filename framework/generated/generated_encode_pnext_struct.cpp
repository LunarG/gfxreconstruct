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

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"

#include "generated/generated_vulkan_struct_encoders.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(encode)

void encode_pnext_struct(ParameterEncoder* encoder, const void* value)
{
    assert(encoder != nullptr);

    const VkBaseInStructure* header = reinterpret_cast<const VkBaseInStructure*>(value);

    // Ignore the structures added to the pnext chain by the loader.
    if ((header != nullptr) &&
        (header->sType != VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) &&
        (header->sType != VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO))
    {
        switch (header->sType)
        {
        default:
            // TODO: Write metadata message with unrecongized sType?
            // pNext is unrecongized.  Write an encoding for a NULL pointer.
            encoder->EncodeStructPtrPreamble(nullptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryDedicatedRequirements*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupSubmitInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceFeatures2*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkImageViewUsageCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceVariablePointerFeatures*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkProtectedSubmitInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(value));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkExternalImageFormatProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceIDProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkExportMemoryAllocateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkExportFenceCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            encode_struct_ptr(encoder, reinterpret_cast<const VkExportSemaphoreCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderDrawParameterFeatures*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDisplayPresentInfoKHR*>(value));
            break;
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkImportMemoryFdInfoKHR*>(value));
            break;
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDevicePushDescriptorPropertiesKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPresentRegionsKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(value));
            break;
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkImageFormatListCreateInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDevice8BitStorageFeaturesKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            encode_struct_ptr(encoder, reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            encode_struct_ptr(encoder, reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            encode_struct_ptr(encoder, reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(value));
            break;
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            encode_struct_ptr(encoder, reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            encode_struct_ptr(encoder, reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(value));
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            encode_struct_ptr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(value));
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkValidationFlagsEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(value));
            break;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            encode_struct_ptr(encoder, reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(value));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            encode_struct_ptr(encoder, reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            encode_struct_ptr(encoder, reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            encode_struct_ptr(encoder, reinterpret_cast<const VkExternalFormatANDROID*>(value));
            break;
#endif /* VK_USE_PLATFORM_ANDROID_KHR */
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkSamplerReductionModeCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkSampleLocationsInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeaturesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupportEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:
            encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfoEXT*>(value));
            break;
        }
    }
    else
    {
        // pNext was either NULL or an ignored loader specific struct.  Write an encoding for a NULL pointer.
        encoder->EncodeStructPtrPreamble(nullptr);
    }
}

BRIMSTONE_END_NAMESPACE(encode)
BRIMSTONE_END_NAMESPACE(brimstone)
