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

#ifndef  GFXRECON_GENERATED_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_BASE_H
#define  GFXRECON_GENERATED_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_BASE_H

#include "decode/vulkan_replay_consumer_base.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
class VulkanReplayFrameLoopConsumerBase : public VulkanReplayConsumer
{
  public:
    VulkanReplayFrameLoopConsumerBase(std::shared_ptr<application::Application> application, const VulkanReplayOptions& options) :
        VulkanReplayConsumer(application, options)
    {}

    virtual ~VulkanReplayFrameLoopConsumerBase() override { }
    virtual graphics::FrameLoopInfo& getFrameLoopInfo() = 0;

    void Process_vkCreateInstance(
        const ApiCallInfo&                          call_info,
        args::CreateInstance&                       args) override;

    void Process_vkDestroyInstance(
        const ApiCallInfo&                          call_info,
        args::DestroyInstance&                      args) override;

    void Process_vkCreateDevice(
        const ApiCallInfo&                          call_info,
        args::CreateDevice&                         args) override;

    void Process_vkDestroyDevice(
        const ApiCallInfo&                          call_info,
        args::DestroyDevice&                        args) override;

    void Process_vkAllocateMemory(
        const ApiCallInfo&                          call_info,
        args::AllocateMemory&                       args) override;

    void Process_vkFreeMemory(
        const ApiCallInfo&                          call_info,
        args::FreeMemory&                           args) override;

    void Process_vkBindBufferMemory(
        const ApiCallInfo&                          call_info,
        args::BindBufferMemory&                     args) override;

    void Process_vkBindImageMemory(
        const ApiCallInfo&                          call_info,
        args::BindImageMemory&                      args) override;

    void Process_vkQueueBindSparse(
        const ApiCallInfo&                          call_info,
        args::QueueBindSparse&                      args) override;

    void Process_vkCreateFence(
        const ApiCallInfo&                          call_info,
        args::CreateFence&                          args) override;

    void Process_vkDestroyFence(
        const ApiCallInfo&                          call_info,
        args::DestroyFence&                         args) override;

    void Process_vkCreateSemaphore(
        const ApiCallInfo&                          call_info,
        args::CreateSemaphore&                      args) override;

    void Process_vkDestroySemaphore(
        const ApiCallInfo&                          call_info,
        args::DestroySemaphore&                     args) override;

    void Process_vkCreateQueryPool(
        const ApiCallInfo&                          call_info,
        args::CreateQueryPool&                      args) override;

    void Process_vkDestroyQueryPool(
        const ApiCallInfo&                          call_info,
        args::DestroyQueryPool&                     args) override;

    void Process_vkGetQueryPoolResults(
        const ApiCallInfo&                          call_info,
        args::GetQueryPoolResults&                  args) override;

    void Process_vkCreateBuffer(
        const ApiCallInfo&                          call_info,
        args::CreateBuffer&                         args) override;

    void Process_vkDestroyBuffer(
        const ApiCallInfo&                          call_info,
        args::DestroyBuffer&                        args) override;

    void Process_vkCreateImage(
        const ApiCallInfo&                          call_info,
        args::CreateImage&                          args) override;

    void Process_vkDestroyImage(
        const ApiCallInfo&                          call_info,
        args::DestroyImage&                         args) override;

    void Process_vkCreateImageView(
        const ApiCallInfo&                          call_info,
        args::CreateImageView&                      args) override;

    void Process_vkDestroyImageView(
        const ApiCallInfo&                          call_info,
        args::DestroyImageView&                     args) override;

    void Process_vkDestroyCommandPool(
        const ApiCallInfo&                          call_info,
        args::DestroyCommandPool&                   args) override;

    void Process_vkAllocateCommandBuffers(
        const ApiCallInfo&                          call_info,
        args::AllocateCommandBuffers&               args) override;

    void Process_vkFreeCommandBuffers(
        const ApiCallInfo&                          call_info,
        args::FreeCommandBuffers&                   args) override;

    void Process_vkCmdBeginQuery(
        const ApiCallInfo&                          call_info,
        args::CmdBeginQuery&                        args) override;

    void Process_vkCmdEndQuery(
        const ApiCallInfo&                          call_info,
        args::CmdEndQuery&                          args) override;

    void Process_vkCmdResetQueryPool(
        const ApiCallInfo&                          call_info,
        args::CmdResetQueryPool&                    args) override;

    void Process_vkCmdWriteTimestamp(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp&                    args) override;

    void Process_vkCmdCopyQueryPoolResults(
        const ApiCallInfo&                          call_info,
        args::CmdCopyQueryPoolResults&              args) override;

    void Process_vkCreateEvent(
        const ApiCallInfo&                          call_info,
        args::CreateEvent&                          args) override;

    void Process_vkDestroyEvent(
        const ApiCallInfo&                          call_info,
        args::DestroyEvent&                         args) override;

    void Process_vkCreateBufferView(
        const ApiCallInfo&                          call_info,
        args::CreateBufferView&                     args) override;

    void Process_vkDestroyBufferView(
        const ApiCallInfo&                          call_info,
        args::DestroyBufferView&                    args) override;

    void Process_vkCreateShaderModule(
        const ApiCallInfo&                          call_info,
        args::CreateShaderModule&                   args) override;

    void Process_vkDestroyShaderModule(
        const ApiCallInfo&                          call_info,
        args::DestroyShaderModule&                  args) override;

    void Process_vkCreatePipelineCache(
        const ApiCallInfo&                          call_info,
        args::CreatePipelineCache&                  args) override;

    void Process_vkDestroyPipelineCache(
        const ApiCallInfo&                          call_info,
        args::DestroyPipelineCache&                 args) override;

    void Process_vkMergePipelineCaches(
        const ApiCallInfo&                          call_info,
        args::MergePipelineCaches&                  args) override;

    void Process_vkCreateComputePipelines(
        const ApiCallInfo&                          call_info,
        args::CreateComputePipelines&               args) override;

    void Process_vkDestroyPipeline(
        const ApiCallInfo&                          call_info,
        args::DestroyPipeline&                      args) override;

    void Process_vkCreatePipelineLayout(
        const ApiCallInfo&                          call_info,
        args::CreatePipelineLayout&                 args) override;

    void Process_vkDestroyPipelineLayout(
        const ApiCallInfo&                          call_info,
        args::DestroyPipelineLayout&                args) override;

    void Process_vkCreateSampler(
        const ApiCallInfo&                          call_info,
        args::CreateSampler&                        args) override;

    void Process_vkDestroySampler(
        const ApiCallInfo&                          call_info,
        args::DestroySampler&                       args) override;

    void Process_vkCreateDescriptorSetLayout(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorSetLayout&            args) override;

    void Process_vkDestroyDescriptorSetLayout(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorSetLayout&           args) override;

    void Process_vkCreateDescriptorPool(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorPool&                 args) override;

    void Process_vkCreateGraphicsPipelines(
        const ApiCallInfo&                          call_info,
        args::CreateGraphicsPipelines&              args) override;

    void Process_vkCreateFramebuffer(
        const ApiCallInfo&                          call_info,
        args::CreateFramebuffer&                    args) override;

    void Process_vkDestroyFramebuffer(
        const ApiCallInfo&                          call_info,
        args::DestroyFramebuffer&                   args) override;

    void Process_vkCreateRenderPass(
        const ApiCallInfo&                          call_info,
        args::CreateRenderPass&                     args) override;

    void Process_vkDestroyRenderPass(
        const ApiCallInfo&                          call_info,
        args::DestroyRenderPass&                    args) override;

    void Process_vkBindBufferMemory2(
        const ApiCallInfo&                          call_info,
        args::BindBufferMemory2&                    args) override;

    void Process_vkBindImageMemory2(
        const ApiCallInfo&                          call_info,
        args::BindImageMemory2&                     args) override;

    void Process_vkCreateDescriptorUpdateTemplate(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorUpdateTemplate&       args) override;

    void Process_vkDestroyDescriptorUpdateTemplate(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorUpdateTemplate&      args) override;

    void Process_vkCreateSamplerYcbcrConversion(
        const ApiCallInfo&                          call_info,
        args::CreateSamplerYcbcrConversion&         args) override;

    void Process_vkDestroySamplerYcbcrConversion(
        const ApiCallInfo&                          call_info,
        args::DestroySamplerYcbcrConversion&        args) override;

    void Process_vkResetQueryPool(
        const ApiCallInfo&                          call_info,
        args::ResetQueryPool&                       args) override;

    void Process_vkCreateRenderPass2(
        const ApiCallInfo&                          call_info,
        args::CreateRenderPass2&                    args) override;

    void Process_vkCreatePrivateDataSlot(
        const ApiCallInfo&                          call_info,
        args::CreatePrivateDataSlot&                args) override;

    void Process_vkDestroyPrivateDataSlot(
        const ApiCallInfo&                          call_info,
        args::DestroyPrivateDataSlot&               args) override;

    void Process_vkCmdWriteTimestamp2(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp2&                   args) override;

    void Process_vkMapMemory2(
        const ApiCallInfo&                          call_info,
        args::MapMemory2&                           args) override;

    void Process_vkUnmapMemory2(
        const ApiCallInfo&                          call_info,
        args::UnmapMemory2&                         args) override;

    void Process_vkTransitionImageLayout(
        const ApiCallInfo&                          call_info,
        args::TransitionImageLayout&                args) override;

    void Process_vkDestroySurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::DestroySurfaceKHR&                    args) override;

    void Process_vkCreateSwapchainKHR(
        const ApiCallInfo&                          call_info,
        args::CreateSwapchainKHR&                   args) override;

    void Process_vkDestroySwapchainKHR(
        const ApiCallInfo&                          call_info,
        args::DestroySwapchainKHR&                  args) override;

    void Process_vkCreateDisplayModeKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDisplayModeKHR&                 args) override;

    void Process_vkCreateDisplayPlaneSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDisplayPlaneSurfaceKHR&         args) override;

    void Process_vkCreateSharedSwapchainsKHR(
        const ApiCallInfo&                          call_info,
        args::CreateSharedSwapchainsKHR&            args) override;

    void Process_vkCreateXlibSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateXlibSurfaceKHR&                 args) override;

    void Process_vkCreateXcbSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateXcbSurfaceKHR&                  args) override;

    void Process_vkCreateWaylandSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateWaylandSurfaceKHR&              args) override;

    void Process_vkCreateAndroidSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateAndroidSurfaceKHR&              args) override;

    void Process_vkCreateWin32SurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateWin32SurfaceKHR&                args) override;

    void Process_vkCreateVideoSessionKHR(
        const ApiCallInfo&                          call_info,
        args::CreateVideoSessionKHR&                args) override;

    void Process_vkDestroyVideoSessionKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyVideoSessionKHR&               args) override;

    void Process_vkBindVideoSessionMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::BindVideoSessionMemoryKHR&            args) override;

    void Process_vkCreateVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::CreateVideoSessionParametersKHR&      args) override;

    void Process_vkDestroyVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyVideoSessionParametersKHR&     args) override;

    void Process_vkImportSemaphoreFdKHR(
        const ApiCallInfo&                          call_info,
        args::ImportSemaphoreFdKHR&                 args) override;

    void Process_vkCreateDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorUpdateTemplateKHR&    args) override;

    void Process_vkDestroyDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorUpdateTemplateKHR&   args) override;

    void Process_vkCreateRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        args::CreateRenderPass2KHR&                 args) override;

    void Process_vkImportFenceFdKHR(
        const ApiCallInfo&                          call_info,
        args::ImportFenceFdKHR&                     args) override;

    void Process_vkCreateSamplerYcbcrConversionKHR(
        const ApiCallInfo&                          call_info,
        args::CreateSamplerYcbcrConversionKHR&      args) override;

    void Process_vkDestroySamplerYcbcrConversionKHR(
        const ApiCallInfo&                          call_info,
        args::DestroySamplerYcbcrConversionKHR&     args) override;

    void Process_vkBindBufferMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::BindBufferMemory2KHR&                 args) override;

    void Process_vkBindImageMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::BindImageMemory2KHR&                  args) override;

    void Process_vkCreateDeferredOperationKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDeferredOperationKHR&           args) override;

    void Process_vkDestroyDeferredOperationKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyDeferredOperationKHR&          args) override;

    void Process_vkMapMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::MapMemory2KHR&                        args) override;

    void Process_vkUnmapMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::UnmapMemory2KHR&                      args) override;

    void Process_vkCmdWriteTimestamp2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp2KHR&                args) override;

    void Process_vkCmdCopyQueryPoolResultsToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyQueryPoolResultsToMemoryKHR&   args) override;

    void Process_vkCreatePipelineBinariesKHR(
        const ApiCallInfo&                          call_info,
        args::CreatePipelineBinariesKHR&            args) override;

    void Process_vkDestroyPipelineBinaryKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyPipelineBinaryKHR&             args) override;

    void Process_vkReleaseCapturedPipelineDataKHR(
        const ApiCallInfo&                          call_info,
        args::ReleaseCapturedPipelineDataKHR&       args) override;

    void Process_vkReleaseSwapchainImagesKHR(
        const ApiCallInfo&                          call_info,
        args::ReleaseSwapchainImagesKHR&            args) override;

    void Process_vkCreateDebugReportCallbackEXT(
        const ApiCallInfo&                          call_info,
        args::CreateDebugReportCallbackEXT&         args) override;

    void Process_vkDestroyDebugReportCallbackEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyDebugReportCallbackEXT&        args) override;

    void Process_vkCmdBeginQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginQueryIndexedEXT&              args) override;

    void Process_vkCmdEndQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndQueryIndexedEXT&                args) override;

    void Process_vkCreateStreamDescriptorSurfaceGGP(
        const ApiCallInfo&                          call_info,
        args::CreateStreamDescriptorSurfaceGGP&     args) override;

    void Process_vkCreateViSurfaceNN(
        const ApiCallInfo&                          call_info,
        args::CreateViSurfaceNN&                    args) override;

    void Process_vkReleaseDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::ReleaseDisplayEXT&                    args) override;

    void Process_vkRegisterDeviceEventEXT(
        const ApiCallInfo&                          call_info,
        args::RegisterDeviceEventEXT&               args) override;

    void Process_vkRegisterDisplayEventEXT(
        const ApiCallInfo&                          call_info,
        args::RegisterDisplayEventEXT&              args) override;

    void Process_vkCreateIOSSurfaceMVK(
        const ApiCallInfo&                          call_info,
        args::CreateIOSSurfaceMVK&                  args) override;

    void Process_vkCreateMacOSSurfaceMVK(
        const ApiCallInfo&                          call_info,
        args::CreateMacOSSurfaceMVK&                args) override;

    void Process_vkCreateDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        args::CreateDebugUtilsMessengerEXT&         args) override;

    void Process_vkDestroyDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyDebugUtilsMessengerEXT&        args) override;

    void Process_vkCreateValidationCacheEXT(
        const ApiCallInfo&                          call_info,
        args::CreateValidationCacheEXT&             args) override;

    void Process_vkDestroyValidationCacheEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyValidationCacheEXT&            args) override;

    void Process_vkCreateAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::CreateAccelerationStructureNV&        args) override;

    void Process_vkDestroyAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::DestroyAccelerationStructureNV&       args) override;

    void Process_vkBindAccelerationStructureMemoryNV(
        const ApiCallInfo&                          call_info,
        args::BindAccelerationStructureMemoryNV&    args) override;

    void Process_vkCreateRayTracingPipelinesNV(
        const ApiCallInfo&                          call_info,
        args::CreateRayTracingPipelinesNV&          args) override;

    void Process_vkReleasePerformanceConfigurationINTEL(
        const ApiCallInfo&                          call_info,
        args::ReleasePerformanceConfigurationINTEL& args) override;

    void Process_vkCreateImagePipeSurfaceFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::CreateImagePipeSurfaceFUCHSIA&        args) override;

    void Process_vkCreateMetalSurfaceEXT(
        const ApiCallInfo&                          call_info,
        args::CreateMetalSurfaceEXT&                args) override;

    void Process_vkReleaseFullScreenExclusiveModeEXT(
        const ApiCallInfo&                          call_info,
        args::ReleaseFullScreenExclusiveModeEXT&    args) override;

    void Process_vkCreateHeadlessSurfaceEXT(
        const ApiCallInfo&                          call_info,
        args::CreateHeadlessSurfaceEXT&             args) override;

    void Process_vkResetQueryPoolEXT(
        const ApiCallInfo&                          call_info,
        args::ResetQueryPoolEXT&                    args) override;

    void Process_vkReleaseSwapchainImagesEXT(
        const ApiCallInfo&                          call_info,
        args::ReleaseSwapchainImagesEXT&            args) override;

    void Process_vkCreateIndirectCommandsLayoutNV(
        const ApiCallInfo&                          call_info,
        args::CreateIndirectCommandsLayoutNV&       args) override;

    void Process_vkDestroyIndirectCommandsLayoutNV(
        const ApiCallInfo&                          call_info,
        args::DestroyIndirectCommandsLayoutNV&      args) override;

    void Process_vkCreatePrivateDataSlotEXT(
        const ApiCallInfo&                          call_info,
        args::CreatePrivateDataSlotEXT&             args) override;

    void Process_vkDestroyPrivateDataSlotEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyPrivateDataSlotEXT&            args) override;

    void Process_vkCreateDirectFBSurfaceEXT(
        const ApiCallInfo&                          call_info,
        args::CreateDirectFBSurfaceEXT&             args) override;

    void Process_vkCreateScreenSurfaceQNX(
        const ApiCallInfo&                          call_info,
        args::CreateScreenSurfaceQNX&               args) override;

    void Process_vkCreateMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CreateMicromapEXT&                    args) override;

    void Process_vkDestroyMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyMicromapEXT&                   args) override;

    void Process_vkCreateTensorARM(
        const ApiCallInfo&                          call_info,
        args::CreateTensorARM&                      args) override;

    void Process_vkDestroyTensorARM(
        const ApiCallInfo&                          call_info,
        args::DestroyTensorARM&                     args) override;

    void Process_vkCreateTensorViewARM(
        const ApiCallInfo&                          call_info,
        args::CreateTensorViewARM&                  args) override;

    void Process_vkDestroyTensorViewARM(
        const ApiCallInfo&                          call_info,
        args::DestroyTensorViewARM&                 args) override;

    void Process_vkBindTensorMemoryARM(
        const ApiCallInfo&                          call_info,
        args::BindTensorMemoryARM&                  args) override;

    void Process_vkCreateOpticalFlowSessionNV(
        const ApiCallInfo&                          call_info,
        args::CreateOpticalFlowSessionNV&           args) override;

    void Process_vkDestroyOpticalFlowSessionNV(
        const ApiCallInfo&                          call_info,
        args::DestroyOpticalFlowSessionNV&          args) override;

    void Process_vkBindOpticalFlowSessionImageNV(
        const ApiCallInfo&                          call_info,
        args::BindOpticalFlowSessionImageNV&        args) override;

    void Process_vkCreateShadersEXT(
        const ApiCallInfo&                          call_info,
        args::CreateShadersEXT&                     args) override;

    void Process_vkDestroyShaderEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyShaderEXT&                     args) override;

    void Process_vkCreateDataGraphPipelinesARM(
        const ApiCallInfo&                          call_info,
        args::CreateDataGraphPipelinesARM&          args) override;

    void Process_vkCreateDataGraphPipelineSessionARM(
        const ApiCallInfo&                          call_info,
        args::CreateDataGraphPipelineSessionARM&    args) override;

    void Process_vkBindDataGraphPipelineSessionMemoryARM(
        const ApiCallInfo&                          call_info,
        args::BindDataGraphPipelineSessionMemoryARM& args) override;

    void Process_vkDestroyDataGraphPipelineSessionARM(
        const ApiCallInfo&                          call_info,
        args::DestroyDataGraphPipelineSessionARM&   args) override;

    void Process_vkCreateIndirectCommandsLayoutEXT(
        const ApiCallInfo&                          call_info,
        args::CreateIndirectCommandsLayoutEXT&      args) override;

    void Process_vkDestroyIndirectCommandsLayoutEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyIndirectCommandsLayoutEXT&     args) override;

    void Process_vkCreateIndirectExecutionSetEXT(
        const ApiCallInfo&                          call_info,
        args::CreateIndirectExecutionSetEXT&        args) override;

    void Process_vkDestroyIndirectExecutionSetEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyIndirectExecutionSetEXT&       args) override;

    void Process_vkCreateAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CreateAccelerationStructureKHR&       args) override;

    void Process_vkDestroyAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyAccelerationStructureKHR&      args) override;

    protected:
        std::set<format::HandleId> allocatedLoopResources;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_BASE_H
