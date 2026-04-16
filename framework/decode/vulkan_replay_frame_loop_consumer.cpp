/*
** Copyright (c) 2026 LunarG, Inc.
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

#include "decode/vulkan_replay_frame_loop_consumer.h"

#include "generated/generated_vulkan_replay_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// At one point, this file contained a function for each entry point that could
// potentially be skipped. The number of functions grew very large, so the skip
// check moved to the skip_while_looping function below. skip_while_looping
// is called from each function in the replay consumer, and if it returns
// true, the function body in the replay consumer is not executed. If for
// some reason, we wish to not use the replay consumer for a particular
// function, it can be implemented in this file and the function implemented
// in this looping consumer will be called rather than the function in the
// replay consumer.

bool skip_while_looping(const graphics::FrameLoopInfo*    frame_loop_info,
                        const ApiCallInfo&                call_info,
                        const gfxrecon::format::ApiCallId call_id)
{
    using namespace gfxrecon::format;

    // Examine the api call id and current looping state to determine whether the api
    // call should skipped.
    //
    // Returns true if the call should be skipped, false otherwise.
    //
    // In general, api calls that create objects or allocate resources are not skipped
    // the first time through the loop, and api calls that destroy objects or deallocate
    // resources are always skipped in the loop. This isn't 100% accurate, but it's an
    // attempt at handling these api calls correctly when looping.

    // call_info is passed in but not currently used. In the future we may want to use it in
    // determining whether an api call should be skipped. For example, gfxrecon-replay could
    // be enhanced to accept block indices that indicate which api calls should be skipped
    // or maybe even moved.

    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    // Set resource destroy API calls we always skip inside the looped frame
    static const std::set<ApiCallId> skipDestroy = {
        ApiCall_vkDestroyAccelerationStructureKHR,
        ApiCall_vkDestroyAccelerationStructureNV,
        ApiCall_vkDestroyBuffer,
        ApiCall_vkDestroyBufferView,
        ApiCall_vkDestroyCommandPool,
        ApiCall_vkDestroyDataGraphPipelineSessionARM,
        ApiCall_vkDestroyDebugReportCallbackEXT,
        ApiCall_vkDestroyDebugUtilsMessengerEXT,
        ApiCall_vkDestroyDeferredOperationKHR,
        ApiCall_vkDestroyDescriptorPool,
        ApiCall_vkDestroyDescriptorSetLayout,
        ApiCall_vkDestroyDescriptorUpdateTemplate,
        ApiCall_vkDestroyDescriptorUpdateTemplateKHR,
        ApiCall_vkDestroyDevice,
        ApiCall_vkDestroyEvent,
        ApiCall_vkDestroyFence,
        ApiCall_vkDestroyFramebuffer,
        ApiCall_vkDestroyImage,
        ApiCall_vkDestroyImageView,
        ApiCall_vkDestroyIndirectCommandsLayoutEXT,
        ApiCall_vkDestroyIndirectCommandsLayoutNV,
        ApiCall_vkDestroyIndirectCommandsLayoutNVX,
        ApiCall_vkDestroyIndirectExecutionSetEXT,
        ApiCall_vkDestroyInstance,
        ApiCall_vkDestroyMicromapEXT,
        ApiCall_vkDestroyObjectTableNVX,
        ApiCall_vkDestroyOpticalFlowSessionNV,
        ApiCall_vkDestroyPipeline,
        ApiCall_vkDestroyPipelineBinaryKHR,
        ApiCall_vkDestroyPipelineCache,
        ApiCall_vkDestroyPipelineLayout,
        ApiCall_vkDestroyPrivateDataSlot,
        ApiCall_vkDestroyPrivateDataSlotEXT,
        ApiCall_vkDestroyQueryPool,
        ApiCall_vkDestroyRenderPass,
        ApiCall_vkDestroySampler,
        ApiCall_vkDestroySamplerYcbcrConversion,
        ApiCall_vkDestroySamplerYcbcrConversionKHR,
        ApiCall_vkDestroySemaphore,
        ApiCall_vkDestroyShaderEXT,
        ApiCall_vkDestroyShaderModule,
        ApiCall_vkDestroySurfaceKHR,
        ApiCall_vkDestroySwapchainKHR,
        ApiCall_vkDestroyTensorARM,
        ApiCall_vkDestroyTensorViewARM,
        ApiCall_vkDestroyValidationCacheEXT,
        ApiCall_vkDestroyVideoSessionKHR,
        ApiCall_vkDestroyVideoSessionParametersKHR,
        ApiCall_vkFreeCommandBuffers,
        ApiCall_vkFreeDescriptorSets,
        ApiCall_vkFreeMemory,
        ApiCall_vkReleaseCapturedPipelineDataKHR,
        ApiCall_vkReleaseDisplayEXT,
        ApiCall_vkReleaseFullScreenExclusiveModeEXT,
        ApiCall_vkReleasePerformanceConfigurationINTEL,
        ApiCall_vkReleaseProfilingLockKHR,
        ApiCall_vkReleaseSwapchainImagesEXT,
        ApiCall_vkReleaseSwapchainImagesKHR,
        ApiCall_vkUnmapMemory,
        ApiCall_vkUnmapMemory2,
        ApiCall_vkUnmapMemory2KHR,
    };

    // Set of resource allocate API calls we execute the first time through the
    // looped frame, but skip in later loop iterations
    static const std::set<ApiCallId> skipAllocate = {
        ApiCall_vkAcquireProfilingLockKHR,
        ApiCall_vkAllocateCommandBuffers,
        ApiCall_vkAllocateDescriptorSets,
        ApiCall_vkAllocateMemory,
        ApiCall_vkBindAccelerationStructureMemoryKHR,
        ApiCall_vkBindAccelerationStructureMemoryNV,
        ApiCall_vkBindBufferMemory,
        ApiCall_vkBindBufferMemory2,
        ApiCall_vkBindBufferMemory2KHR,
        ApiCall_vkBindDataGraphPipelineSessionMemoryARM,
        ApiCall_vkBindImageMemory,
        ApiCall_vkBindImageMemory2,
        ApiCall_vkBindImageMemory2KHR,
        ApiCall_vkBindOpticalFlowSessionImageNV,
        ApiCall_vkBindTensorMemoryARM,
        ApiCall_vkBindVideoSessionMemoryKHR,
        ApiCall_vkCreateAccelerationStructureKHR,
        ApiCall_vkCreateAccelerationStructureNV,
        ApiCall_vkCreateAndroidSurfaceKHR,
        ApiCall_vkCreateBuffer,
        ApiCall_vkCreateBufferView,
        ApiCall_vkCreateCommandPool,
        ApiCall_vkCreateComputePipelines,
        ApiCall_vkCreateDataGraphPipelinesARM,
        ApiCall_vkCreateDataGraphPipelineSessionARM,
        ApiCall_vkCreateDebugReportCallbackEXT,
        ApiCall_vkCreateDebugUtilsMessengerEXT,
        ApiCall_vkCreateDeferredOperationKHR,
        ApiCall_vkCreateDescriptorPool,
        ApiCall_vkCreateDescriptorSetLayout,
        ApiCall_vkCreateDescriptorUpdateTemplate,
        ApiCall_vkCreateDescriptorUpdateTemplateKHR,
        ApiCall_vkCreateDevice,
        ApiCall_vkCreateDirectFBSurfaceEXT,
        ApiCall_vkCreateDisplayModeKHR,
        ApiCall_vkCreateDisplayPlaneSurfaceKHR,
        ApiCall_vkCreateEvent,
        ApiCall_vkCreateFence,
        ApiCall_vkCreateFramebuffer,
        ApiCall_vkCreateGraphicsPipelines,
        ApiCall_vkCreateHeadlessSurfaceEXT,
        ApiCall_vkCreateImage,
        ApiCall_vkCreateImagePipeSurfaceFUCHSIA,
        ApiCall_vkCreateImageView,
        ApiCall_vkCreateIndirectCommandsLayoutEXT,
        ApiCall_vkCreateIndirectCommandsLayoutNV,
        ApiCall_vkCreateIndirectCommandsLayoutNVX,
        ApiCall_vkCreateIndirectExecutionSetEXT,
        ApiCall_vkCreateInstance,
        ApiCall_vkCreateIOSSurfaceMVK,
        ApiCall_vkCreateMacOSSurfaceMVK,
        ApiCall_vkCreateMetalSurfaceEXT,
        ApiCall_vkCreateMicromapEXT,
        ApiCall_vkCreateMirSurfaceKHR,
        ApiCall_vkCreateObjectTableNVX,
        ApiCall_vkCreateOpticalFlowSessionNV,
        ApiCall_vkCreatePipelineBinariesKHR,
        ApiCall_vkCreatePipelineCache,
        ApiCall_vkCreatePipelineLayout,
        ApiCall_vkCreatePrivateDataSlot,
        ApiCall_vkCreatePrivateDataSlotEXT,
        ApiCall_vkCreateQueryPool,
        ApiCall_vkCreateRayTracingPipelinesKHR,
        ApiCall_vkCreateRayTracingPipelinesNV,
        ApiCall_vkCreateRenderPass,
        ApiCall_vkCreateRenderPass2,
        ApiCall_vkCreateRenderPass2KHR,
        ApiCall_vkCreateSampler,
        ApiCall_vkCreateSamplerYcbcrConversion,
        ApiCall_vkCreateSamplerYcbcrConversionKHR,
        ApiCall_vkCreateScreenSurfaceQNX,
        ApiCall_vkCreateSemaphore,
        ApiCall_vkCreateShaderModule,
        ApiCall_vkCreateShadersEXT,
        ApiCall_vkCreateSharedSwapchainsKHR,
        ApiCall_vkCreateStreamDescriptorSurfaceGGP,
        ApiCall_vkCreateSwapchainKHR,
        ApiCall_vkCreateTensorARM,
        ApiCall_vkCreateTensorViewARM,
        ApiCall_vkCreateValidationCacheEXT,
        ApiCall_vkCreateVideoSessionKHR,
        ApiCall_vkCreateVideoSessionParametersKHR,
        ApiCall_vkCreateViSurfaceNN,
        ApiCall_vkCreateWaylandSurfaceKHR,
        ApiCall_vkCreateWin32SurfaceKHR,
        ApiCall_vkCreateXcbSurfaceKHR,
        ApiCall_vkCreateXlibSurfaceKHR,
        ApiCall_vkImportFenceFdKHR,
        ApiCall_vkImportSemaphoreFdKHR,
        ApiCall_vkMapMemory,
        ApiCall_vkMapMemory2,
        ApiCall_vkMapMemory2KHR,
        ApiCall_vkMergePipelineCaches,
        ApiCall_vkQueueBindSparse,
        ApiCall_vkRegisterDeviceEventEXT,
        ApiCall_vkRegisterDisplayEventEXT,
        ApiCall_vkRegisterObjectsNVX,
        ApiCall_vkTransitionImageLayout,
    };

    // Don't skip if frame_loop_info is NULL. We're not looping.
    if (!frame_loop_info)
    {
        return false;
    }

    // Skip all resource destroy commands in first and subsequent iterations.
    if (skipDestroy.contains(call_id) && (frame_loop_info->IsFirstIteration() || frame_loop_info->IsLooping()))
    {
        return true;
    }

    // Don't skip if we're not in the first iteration or loop.
    if (!frame_loop_info->IsLooping())
    {
        return false;
    }

    // Skip resource create commands after the first loop iteration.
    if (!frame_loop_info->IsFirstIteration() && skipAllocate.contains(call_id))
        return true;

    return false;
}

// These are functions that are replayed that aren't Vulkan entry points
void VulkanReplayFrameLoopConsumer::ProcessCreateHardwareBufferCommand(
    format::HandleId                                    device_id,
    format::HandleId                                    memory_id,
    uint64_t                                            buffer_id,
    uint32_t                                            format,
    uint32_t                                            width,
    uint32_t                                            height,
    uint32_t                                            stride,
    uint64_t                                            usage,
    uint32_t                                            layers,
    const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{
    if (frame_loop_info_.IsLooping())
    {
        // Skip after the first loop
        return;
    }
    VulkanReplayConsumer::ProcessCreateHardwareBufferCommand(
        device_id, memory_id, buffer_id, format, width, height, stride, usage, layers, plane_info);
}

void VulkanReplayFrameLoopConsumer::ProcessDestroyHardwareBufferCommand(uint64_t buffer_id)
{
    if (frame_loop_info_.IsFirstIteration() || frame_loop_info_.IsLooping())
    {
        // Don't destroy resources on first or subseqent iterations of loop
        return;
    }
    VulkanReplayConsumer::ProcessDestroyHardwareBufferCommand(buffer_id);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
