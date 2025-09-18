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

#include "generated/generated_vulkan_struct_encoders.h"

#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_capture_manager.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#include <cassert>
#include <cstdio>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
void EncodePNextStruct(ParameterEncoder* encoder, const void* value)
{
    assert(encoder != nullptr);

    auto base = reinterpret_cast<const VkBaseInStructure*>(value);

    // Ignore the structures added to the pNext chain by the loader.
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
                VulkanCaptureManager::Get()->WriteDisplayMessageCmd(message.get());
                GFXRECON_LOG_WARNING("%s", message.get());
                EncodePNextStruct(encoder, base->pNext);
            }
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureGeometryLinearSweptSpheresDataNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureGeometryMotionTrianglesDataNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureGeometrySpheresDataNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureMotionInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureTrianglesDisplacementMicromapNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureTrianglesOpacityMicromapEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAmigoProfilingSubmitInfoSEC*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferFormatProperties2ANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferFormatResolvePropertiesANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentFeedbackLoopInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentSampleCountInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindMemoryStatus*>(base));
            break;
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBlitImageCubicWeightsInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferUsageFlags2CreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceRenderingInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceViewportScissorInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkComputePipelineIndirectBufferInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyCommandTransformInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDepthBiasRepresentationInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceAddressBindingCallbackDataEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDevicePipelineBinaryInternalCacheControlKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDevicePrivateDataCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceQueueShaderCoreControlCreateInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDirectDriverLoadingListLUNARG*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayModeStereoPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayPresentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplaySurfaceStereoCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDrmFormatModifierPropertiesList2EXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportFenceCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportSemaphoreCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalFormatANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalImageFormatProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalMemoryAcquireUnmodifiedEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFormatProperties3*>(base));
            break;
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFragmentShadingRateAttachmentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFrameBoundaryEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGeneratedCommandsPipelineInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGeneratedCommandsShaderInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGraphicsPipelineLibraryCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI:
            EncodeStructPtr(encoder, reinterpret_cast<const VkHdrVividDynamicMetadataHUAWEI*>(base));
            break;
        case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY:
            EncodeStructPtr(encoder, reinterpret_cast<const VkHostImageCopyDevicePerformanceQuery*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageAlignmentControlCreateInfoMESA*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageCompressionControlEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageCompressionPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageFormatListCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageStencilUsageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewMinLodCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewSampleWeightCreateInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewSlicedCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewUsageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryFdInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryMetalHandleInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryZirconHandleInfoFUCHSIA*>(base));
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkLatencySubmissionPresentIdNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkLatencySurfaceCapabilitiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkLayerSettingsCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryBarrier2*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryBarrierAccessFlags3KHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryDedicatedRequirements*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryMapPlacedInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMultisampledRenderToSingleSampledInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMultiviewPerViewAttributesInfoNVX*>(base));
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMutableDescriptorTypeCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkOpticalFlowImageFormatInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkOpticalFlowSessionCreatePrivateDataInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPartitionedAccelerationStructureFlagsNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceAntiLagFeaturesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeMatrix2FeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeMatrix2PropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeVectorFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeVectorPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCubicClampFeaturesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDepthClampControlFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDepthStencilResolveProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDriverProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDrmPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDynamicRenderingLocalReadFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFaultFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFeatures2*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFloatControlsProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFormatPackFeaturesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_PROPERTIES_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceHdrVividFeaturesHUAWEI*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceHostImageCopyFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceHostImageCopyProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceIDProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageAlignmentControlFeaturesMESA*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageAlignmentControlPropertiesMESA*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageProcessing2PropertiesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageProcessingFeaturesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageProcessingPropertiesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLayeredApiPropertiesListKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLayeredDriverPropertiesMSFT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLineRasterizationProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance4Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance5Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance5Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance6Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance6Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance7FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance7PropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance8FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance9FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance9PropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiDrawPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceOpticalFlowFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceOpticalFlowPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineBinaryFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineBinaryPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineProtectedAccessFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineRobustnessFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineRobustnessProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePresentBarrierFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePresentId2FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePresentMeteringFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePresentWait2FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProvokingVertexPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePushDescriptorProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRawAccessChainsFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingValidationFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRenderPassStripedFeaturesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRenderPassStripedPropertiesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSchedulingControlsFeaturesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSchedulingControlsPropertiesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderBfloat16FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderExpectAssumeFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderFloat8FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderFloatControls2Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderObjectFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderObjectPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSubgroupRotateFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderTileImageFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderTileImagePropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTileMemoryHeapPropertiesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTileShadingFeaturesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTileShadingPropertiesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan13Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan14Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan14Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineBinaryInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineColorWriteCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCreateFlags2CreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCreationFeedbackCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_DENSITY_MAP_LAYERED_CREATE_INFO_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineFragmentDensityMapLayeredCreateInfoVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineFragmentShadingRateStateCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineLayoutCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRenderingCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRobustnessCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportDepthClampControlCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportDepthClipControlCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentFrameTokenGGP*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_ID_2_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentId2KHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentIdKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentRegionsKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(base));
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkProtectedSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueryLowLatencySupportNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyCheckpointProperties2NV*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyGlobalPriorityProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OWNERSHIP_TRANSFER_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyOwnershipTransferPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyQueryResultStatusPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyVideoPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassCreationControlEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassCreationFeedbackCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassFragmentDensityMapOffsetEndInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassStripeBeginInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassStripeSubmitInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassSubpassFeedbackCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassTileShadingCreateInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingAttachmentLocationInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingInputAttachmentIndexInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSampleLocationsInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerBlockMatchWindowCreateInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerBorderColorComponentMappingCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerCubicWeightsCreateInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerReductionModeCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSetPresentConfigNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkShaderModuleCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubpassResolvePerformanceQueryEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubresourceHostMemcpySize*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceCapabilitiesPresentBarrierNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_ID_2_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceCapabilitiesPresentId2KHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_WAIT_2_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceCapabilitiesPresentWait2KHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfacePresentModeCompatibilityKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfacePresentModeKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfacePresentScalingCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainLatencyCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainPresentBarrierCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainPresentFenceInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainPresentModeInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainPresentModesCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainPresentScalingCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkTileMemoryBindInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_TILE_MEMORY_REQUIREMENTS_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkTileMemoryRequirementsQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkTileMemorySizeInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkValidationFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkValidationFlagsEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeAV1CapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeAV1DpbSlotInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeAV1PictureInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeAV1ProfileInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeAV1SessionParametersCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeH264CapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeH264DpbSlotInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeH264PictureInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeH264ProfileInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeH264SessionParametersAddInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeH264SessionParametersCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeUsageInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeVP9CapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeVP9PictureInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PROFILE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeVP9ProfileInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeAV1CapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeAV1DpbSlotInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeAV1GopRemainingFrameInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeAV1PictureInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeAV1ProfileInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeAV1QualityLevelPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeAV1QuantizationMapCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeAV1RateControlInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeAV1RateControlLayerInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeAV1SessionCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeAV1SessionParametersCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264CapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264DpbSlotInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264GopRemainingFrameInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264PictureInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264ProfileInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264QualityLevelPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264QuantizationMapCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264RateControlInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264RateControlLayerInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264SessionCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264SessionParametersAddInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264SessionParametersCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264SessionParametersFeedbackInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264SessionParametersGetInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH265QuantizationMapCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeIntraRefreshCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeIntraRefreshInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeQualityLevelInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeQuantizationMapCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeQuantizationMapInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeRateControlInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_INTRA_REFRESH_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeSessionIntraRefreshCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeUsageInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoFormatAV1QuantizationMapPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoFormatH265QuantizationMapPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoFormatQuantizationMapPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoInlineQueryInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoProfileInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoProfileListInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoReferenceIntraRefreshInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlock*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteDescriptorSetPartitionedAccelerationStructureNV*>(base));
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
