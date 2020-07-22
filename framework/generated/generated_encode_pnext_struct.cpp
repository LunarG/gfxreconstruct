/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "generated/generated_vulkan_struct_encoders.h"

#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/trace_manager.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <cstdio>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodePNextStruct(ParameterEncoder* encoder, const void* value)
{
    assert(encoder != nullptr);

    auto base = reinterpret_cast<const VkBaseInStructure*>(value);

    // Ignore the structures added to the pnext chain by the loader.
    while ((base != nullptr) && ((base->sType == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) ||
                                 (base->sType == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO)))
    {
        base = base->pNext;
    }

    if (base != nullptr)
    {
        switch (base->sType)
        {
        default:
            {
                // pNext is unrecognized.  Write warning message to indicate it will be omitted from the capture and check to see if it points to a recognized value.
                int32_t message_size = std::snprintf(nullptr, 0, "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);
                std::unique_ptr<char[]> message = std::make_unique<char[]>(message_size + 1); // Add 1 for null-terminator.
                std::snprintf(message.get(), (message_size + 1), "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);
                TraceManager::Get()->WriteDisplayMessageCmd(message.get());
                GFXRECON_LOG_WARNING("%s", message.get());
                EncodePNextStruct(encoder, base->pNext);
            }
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryDedicatedRequirements*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFeatures2*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewUsageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkProtectedSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalImageFormatProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceIDProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportFenceCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportSemaphoreCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan11Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan12Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageFormatListCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDriverProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFloatControlsProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDepthStencilResolveProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageStencilUsageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerReductionModeCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayPresentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryFdInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePushDescriptorPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentRegionsKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEFERRED_OPERATION_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeferredOperationInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkValidationFlagsEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalFormatANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlockEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSampleLocationsInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentFrameTokenGGP*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCreationFeedbackCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkValidationFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLineRasterizationPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePrivateDataFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDevicePrivateDataCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesKHR*>(base));
            break;
        }
    }
    else
    {
        // pNext was either NULL or an ignored loader specific struct.  Write an encoding for a NULL pointer.
        encoder->EncodeStructPtrPreamble(nullptr);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
