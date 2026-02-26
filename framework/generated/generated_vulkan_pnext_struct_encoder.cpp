/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
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
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureBuildGeometryInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureBuildSizesInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureCaptureDescriptorDataInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureDeviceAddressInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureGeometryAabbsDataKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureGeometryInstancesDataKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureGeometryKHR*>(base));
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
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureGeometryTrianglesDataKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureMemoryRequirementsInfoNV*>(base));
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
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureVersionInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAcquireNextImageInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAcquireProfilingLockInfoKHR*>(base));
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
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferPropertiesANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidSurfaceCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANTI_LAG_DATA_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAntiLagDataAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANTI_LAG_PRESENTATION_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAntiLagPresentationInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_APPLICATION_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkApplicationInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentDescription2*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentFeedbackLoopInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentReference2*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentSampleCountInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_BEGIN_CUSTOM_RESOLVE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBeginCustomResolveInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindAccelerationStructureMemoryInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindBufferMemoryInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_DATA_GRAPH_PIPELINE_SESSION_MEMORY_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindDataGraphPipelineSessionMemoryInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindDescriptorBufferEmbeddedSamplersInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindDescriptorSetsInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImageMemoryInfo*>(base));
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
        case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindSparseInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindVideoSessionMemoryInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBlitImageCubicWeightsInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBlitImageInfo2*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferCaptureDescriptorDataInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_COPY_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferCopy2*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferDeviceAddressInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferImageCopy2*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferMemoryBarrier*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferMemoryBarrier2*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferMemoryRequirementsInfo2*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferUsageFlags2CreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferViewCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUILD_PARTITIONED_ACCELERATION_STRUCTURE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBuildPartitionedAccelerationStructureInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCalibratedTimestampInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCheckpointData2NV*>(base));
            break;
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCheckpointDataNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceInfo*>(base));
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
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandPoolCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_OCCUPANCY_PRIORITY_PARAMETERS_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkComputeOccupancyPriorityParametersNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkComputePipelineCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkComputePipelineIndirectBufferInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkConditionalRenderingBeginInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_CONVERT_COOPERATIVE_VECTOR_MATRIX_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkConvertCooperativeVectorMatrixInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCooperativeMatrixFlexibleDimensionsPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCooperativeMatrixPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCooperativeMatrixPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_VECTOR_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCooperativeVectorPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyAccelerationStructureInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyAccelerationStructureToMemoryInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyBufferInfo2*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyBufferToImageInfo2*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyCommandTransformInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyDescriptorSet*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyImageInfo2*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyImageToBufferInfo2*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyImageToImageInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyImageToMemoryInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_INDIRECT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyMemoryIndirectInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyMemoryToAccelerationStructureInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INDIRECT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyMemoryToImageIndirectInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyMemoryToImageInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyMemoryToMicromapInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyMicromapInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyMicromapToMemoryInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_CUSTOM_RESOLVE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCustomResolveCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_BUILTIN_MODEL_CREATE_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineBuiltinModelCreateInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_COMPILER_CONTROL_CREATE_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineCompilerControlCreateInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineConstantARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_TENSOR_SEMI_STRUCTURED_SPARSITY_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CREATE_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineCreateInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_DISPATCH_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineDispatchInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_IDENTIFIER_CREATE_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineIdentifierCreateInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_PROPERTY_QUERY_RESULT_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelinePropertyQueryResultARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineResourceInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENT_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineSessionBindPointRequirementARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENTS_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineSessionBindPointRequirementsInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_CREATE_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineSessionCreateInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_MEMORY_REQUIREMENTS_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineSessionMemoryRequirementsInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SHADER_MODULE_CREATE_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphPipelineShaderModuleCreateInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PROCESSING_ENGINE_CREATE_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDataGraphProcessingEngineCreateInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugMarkerMarkerInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugMarkerObjectNameInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugMarkerObjectTagInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugUtilsLabelEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugUtilsMessengerCallbackDataEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugUtilsObjectTagInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DECOMPRESS_MEMORY_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDecompressMemoryInfoEXT*>(base));
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
        case VK_STRUCTURE_TYPE_DEPENDENCY_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDependencyInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDepthBiasInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDepthBiasRepresentationInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorAddressInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorBufferBindingInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorBufferBindingPushDescriptorBufferHandleEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorGetInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorPoolCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetBindingReferenceVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetLayoutHostMappingInfoVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetLayoutSupport*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorUpdateTemplateCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceAddressBindingCallbackDataEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceBufferMemoryRequirements*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceEventInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceFaultCountsEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceFaultInfoEXT*>(base));
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
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupPresentCapabilitiesKHR*>(base));
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
        case VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceImageMemoryRequirements*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceImageSubresourceInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceMemoryOpaqueCaptureAddressInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceMemoryReportCallbackDataEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDevicePipelineBinaryInternalCacheControlKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDevicePrivateDataCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceQueueCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceQueueInfo2*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceQueueShaderCoreControlCreateInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDirectDriverLoadingInfoLUNARG*>(base));
            break;
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDirectDriverLoadingListLUNARG*>(base));
            break;
        case VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDirectFBSurfaceCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPATCH_TILE_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDispatchTileInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayEventInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayModeCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayModeProperties2KHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayModeStereoPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayPlaneCapabilities2KHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayPlaneInfo2KHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayPlaneProperties2KHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayPowerInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayPresentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayProperties2KHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplaySurfaceCreateInfoKHR*>(base));
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
        case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkEventCreateInfo*>(base));
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
        case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalBufferProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalFenceProperties*>(base));
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
        case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalSemaphoreProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFenceCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFenceGetFdInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFenceGetWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFormatProperties2*>(base));
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
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFramebufferAttachmentImageInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFramebufferCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFramebufferMixedSamplesCombinationNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGeneratedCommandsInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGeneratedCommandsInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGeneratedCommandsMemoryRequirementsInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGeneratedCommandsMemoryRequirementsInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGeneratedCommandsPipelineInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGeneratedCommandsShaderInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGeometryAABBNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGeometryNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGeometryTrianglesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGetLatencyMarkerInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGraphicsPipelineCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGraphicsPipelineLibraryCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGraphicsShaderGroupCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_HDR_METADATA_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkHdrMetadataEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI:
            EncodeStructPtr(encoder, reinterpret_cast<const VkHdrVividDynamicMetadataHUAWEI*>(base));
            break;
        case VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkHeadlessSurfaceCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY:
            EncodeStructPtr(encoder, reinterpret_cast<const VkHostImageCopyDevicePerformanceQuery*>(base));
            break;
        case VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkHostImageLayoutTransitionInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK:
            EncodeStructPtr(encoder, reinterpret_cast<const VkIOSSurfaceCreateInfoMVK*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageAlignmentControlCreateInfoMESA*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_BLIT_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageBlit2*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageCaptureDescriptorDataInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageCompressionControlEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageCompressionPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COPY_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageCopy2*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageDrmFormatModifierPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageFormatListCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageFormatProperties2*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageMemoryBarrier*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageMemoryBarrier2*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageMemoryRequirementsInfo2*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImagePipeSurfaceCreateInfoFUCHSIA*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageResolve2*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageSparseMemoryRequirementsInfo2*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageStencilUsageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageSubresource2*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageToMemoryCopy*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewAddressPropertiesNVX*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewCaptureDescriptorDataInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewHandleInfoNVX*>(base));
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
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportFenceFdInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportFenceWin32HandleInfoKHR*>(base));
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
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportSemaphoreFdInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportSemaphoreWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportSemaphoreZirconHandleInfoFUCHSIA*>(base));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkIndirectCommandsLayoutTokenEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkIndirectCommandsLayoutTokenNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkIndirectExecutionSetCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkIndirectExecutionSetPipelineInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkIndirectExecutionSetShaderInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkIndirectExecutionSetShaderLayoutInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL:
            EncodeStructPtr(encoder, reinterpret_cast<const VkInitializePerformanceApiInfoINTEL*>(base));
            break;
        case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkInstanceCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkLatencySleepInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkLatencySleepModeInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkLatencySubmissionPresentIdNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkLatencySurfaceCapabilitiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkLatencyTimingsFrameReportNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkLayerSettingsCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMacOSSurfaceCreateInfoMVK*>(base));
            break;
        case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMappedMemoryRange*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryBarrier*>(base));
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
        case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryFdPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryGetAndroidHardwareBufferInfoANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryGetFdInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryGetMetalHandleInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryGetRemoteAddressInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryGetWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryGetZirconHandleInfoFUCHSIA*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryHostPointerPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_MAP_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryMapInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryMapPlacedInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryMetalHandlePropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryRequirements2*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryToImageCopy*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryUnmapInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryWin32HandlePropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryZirconHandlePropertiesFUCHSIA*>(base));
            break;
        case VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMetalSurfaceCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMicromapBuildInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMicromapBuildSizesInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMicromapCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMicromapVersionInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMultisamplePropertiesEXT*>(base));
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
        case VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkOpaqueCaptureDescriptorDataCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkOpticalFlowExecuteInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkOpticalFlowImageFormatInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkOpticalFlowImageFormatPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkOpticalFlowSessionCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkOpticalFlowSessionCreatePrivateDataInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkOutOfBandQueueTypeInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPartitionedAccelerationStructureFlagsNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCES_INPUT_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPartitionedAccelerationStructureInstancesInputNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPastPresentationTimingEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPastPresentationTimingInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPastPresentationTimingPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PER_TILE_BEGIN_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerTileBeginInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PER_TILE_END_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerTileEndInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerformanceConfigurationAcquireInfoINTEL*>(base));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerformanceCounterARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerformanceCounterDescriptionARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerformanceCounterDescriptionKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerformanceCounterKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerformanceMarkerInfoINTEL*>(base));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerformanceOverrideInfoINTEL*>(base));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerformanceStreamMarkerInfoINTEL*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_OCCUPANCY_PRIORITY_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_RESOLVE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCustomResolveFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDataGraphFeaturesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_MODEL_FEATURES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDataGraphModelFeaturesQCOM*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorBufferFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorBufferPropertiesEXT*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalBufferInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalFenceInfo*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalSemaphoreInfo*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateKHR*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceGroupProperties*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageFormatInfo2*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INTERNALLY_SYNCHRONIZED_QUEUES_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLayeredApiPropertiesKHR*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance10FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance10PropertiesKHR*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMemoryDecompressionFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMemoryDecompressionPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMemoryProperties2*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_FEATURES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePerformanceCountersByRegionFeaturesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_PROPERTIES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePerformanceCountersByRegionPropertiesARM*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_TIMING_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePresentTimingFeaturesEXT*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProperties2*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePushConstantBankFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePushConstantBankPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePushDescriptorProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShader64BitIndexingFeaturesEXT*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderFmaFeaturesKHR*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderLongVectorFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderLongVectorPropertiesEXT*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_PARTITIONED_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_3D_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceToolProperties*>(base));
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
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVideoFormatInfoKHR*>(base));
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
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineBinaryCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineBinaryDataInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineBinaryHandlesInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineBinaryInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineBinaryKeyKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCacheCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineColorBlendStateCreateInfo*>(base));
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
        case VK_STRUCTURE_TYPE_PIPELINE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCreationFeedbackCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineDepthStencilStateCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineDynamicStateCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineExecutableInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineExecutableInternalRepresentationKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineExecutablePropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineExecutableStatisticKHR*>(base));
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
        case VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineIndirectDeviceAddressInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineInputAssemblyStateCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineLayoutCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineMultisampleStateCreateInfo*>(base));
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
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationStateCreateInfo*>(base));
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
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineShaderStageCreateInfo*>(base));
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
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineTessellationStateCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineVertexInputStateCreateInfo*>(base));
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
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportStateCreateInfo*>(base));
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
        case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentRegionsKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMING_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentTimingInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMING_SURFACE_CAPABILITIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentTimingSurfaceCapabilitiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMINGS_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentTimingsInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_WAIT_2_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentWait2InfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPrivateDataSlotCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkProtectedSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PUSH_CONSTANT_BANK_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPushConstantBankInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPushConstantsInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPushDescriptorSetInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPushDescriptorSetWithTemplateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueryLowLatencySupportNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueryPoolCreateInfo*>(base));
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
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyDataGraphProcessingEnginePropertiesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROPERTIES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyDataGraphPropertiesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyGlobalPriorityProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OWNERSHIP_TRANSFER_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyOwnershipTransferPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyProperties2*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyQueryResultStatusPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyVideoPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRayTracingPipelineCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRayTracingPipelineCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRayTracingPipelineInterfaceCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRayTracingShaderGroupCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRayTracingShaderGroupCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkReleaseCapturedPipelineDataInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkReleaseSwapchainImagesInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassCreateInfo2*>(base));
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
        case VK_STRUCTURE_TYPE_RENDER_PASS_PERFORMANCE_COUNTERS_BY_REGION_BEGIN_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassPerformanceCountersByRegionBeginInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassStripeBeginInfoARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassStripeInfoARM*>(base));
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
        case VK_STRUCTURE_TYPE_RENDERING_AREA_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingAreaInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_FLAGS_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingAttachmentFlagsInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingAttachmentInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingAttachmentLocationInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_END_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingEndInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingInputAttachmentIndexInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkResolveImageInfo2*>(base));
            break;
        case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_MODE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkResolveImageModeInfoKHR*>(base));
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
        case VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerCaptureDescriptorDataInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerCreateInfo*>(base));
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
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionCreateInfo*>(base));
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
        case VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX:
            EncodeStructPtr(encoder, reinterpret_cast<const VkScreenSurfaceCreateInfoQNX*>(base));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSemaphoreCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSemaphoreGetFdInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSemaphoreGetWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSemaphoreGetZirconHandleInfoFUCHSIA*>(base));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSemaphoreSignalInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSemaphoreSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSemaphoreWaitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSetDescriptorBufferOffsetsInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSetLatencyMarkerInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSetPresentConfigNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkShaderCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkShaderModuleCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkShaderModuleIdentifierEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSparseImageFormatProperties2*>(base));
            break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSparseImageMemoryRequirements2*>(base));
            break;
        case VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP:
            EncodeStructPtr(encoder, reinterpret_cast<const VkStreamDescriptorSurfaceCreateInfoGGP*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBMIT_INFO_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubmitInfo2*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubpassBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubpassDependency2*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubpassDescription2*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_END_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubpassEndInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubpassResolvePerformanceQueryEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubresourceHostMemcpySize*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubresourceLayout2*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceCapabilities2EXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceCapabilities2KHR*>(base));
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
        case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceFormat2KHR*>(base));
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
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CALIBRATED_TIMESTAMP_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainCalibratedTimestampInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainCreateInfoKHR*>(base));
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
        case VK_STRUCTURE_TYPE_SWAPCHAIN_TIME_DOMAIN_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainTimeDomainPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_TIMING_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainTimingPropertiesEXT*>(base));
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
        case VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkTilePropertiesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkValidationCacheCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkValidationFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkValidationFlagsEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVertexInputAttributeDescription2EXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVertexInputBindingDescription2EXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN:
            EncodeStructPtr(encoder, reinterpret_cast<const VkViSurfaceCreateInfoNN*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoBeginCodingInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoCodingControlInfoKHR*>(base));
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
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoDecodeInfoKHR*>(base));
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
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeH264NaluSliceInfoKHR*>(base));
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
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeIntraRefreshCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeIntraRefreshInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_PROFILE_RGB_CONVERSION_INFO_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeProfileRgbConversionInfoVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeQualityLevelInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeQualityLevelPropertiesKHR*>(base));
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
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeRateControlLayerInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RGB_CONVERSION_CAPABILITIES_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeRgbConversionCapabilitiesVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_INTRA_REFRESH_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeSessionIntraRefreshCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeSessionParametersFeedbackInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeSessionParametersGetInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_RGB_CONVERSION_CREATE_INFO_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeSessionRgbConversionCreateInfoVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEncodeUsageInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoEndCodingInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoFormatAV1QuantizationMapPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoFormatH265QuantizationMapPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoFormatPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoFormatQuantizationMapPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoInlineQueryInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoPictureResourceInfoKHR*>(base));
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
        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoReferenceSlotInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoSessionCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoSessionMemoryRequirementsKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoSessionParametersCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkVideoSessionParametersUpdateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWaylandSurfaceCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWin32SurfaceCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteDescriptorSet*>(base));
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
        case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_PIPELINE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteIndirectExecutionSetPipelineEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_SHADER_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteIndirectExecutionSetShaderEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkXcbSurfaceCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkXlibSurfaceCreateInfoKHR*>(base));
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
