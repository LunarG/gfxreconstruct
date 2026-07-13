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

#ifndef  GFXRECON_GENERATED_VULKAN_REPLAY_CONSUMER_H
#define  GFXRECON_GENERATED_VULKAN_REPLAY_CONSUMER_H

#include "decode/vulkan_replay_consumer_base.h"
#include "util/defines.h"
#include "generated/generated_vulkan_decoder_args.h"
#include "decode/vulkan_decoder_args.h"

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
class VulkanReplayConsumer : public VulkanReplayConsumerBase
{
  public:
    VulkanReplayConsumer(std::shared_ptr<application::Application> application, const VulkanReplayOptions& options) : VulkanReplayConsumerBase(application, options) { }

    virtual ~VulkanReplayConsumer() override { }

    virtual void Process_vkCreateInstance(
        const ApiCallInfo&                          call_info,
        args::CreateInstance&                       args) override;

    virtual void Process_vkDestroyInstance(
        const ApiCallInfo&                          call_info,
        args::DestroyInstance&                      args) override;

    virtual void Process_vkEnumeratePhysicalDevices(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDevices&             args) override;

    virtual void Process_vkGetPhysicalDeviceFeatures(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFeatures&            args) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFormatProperties&    args) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceImageFormatProperties& args) override;

    virtual void Process_vkGetPhysicalDeviceProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceProperties&          args) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyProperties& args) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceMemoryProperties&    args) override;

    virtual void Process_vkCreateDevice(
        const ApiCallInfo&                          call_info,
        args::CreateDevice&                         args) override;

    virtual void Process_vkDestroyDevice(
        const ApiCallInfo&                          call_info,
        args::DestroyDevice&                        args) override;

    virtual void Process_vkGetDeviceQueue(
        const ApiCallInfo&                          call_info,
        args::GetDeviceQueue&                       args) override;

    virtual void Process_vkQueueSubmit(
        const ApiCallInfo&                          call_info,
        args::QueueSubmit&                          args) override;

    virtual void Process_vkQueueWaitIdle(
        const ApiCallInfo&                          call_info,
        args::QueueWaitIdle&                        args) override;

    virtual void Process_vkDeviceWaitIdle(
        const ApiCallInfo&                          call_info,
        args::DeviceWaitIdle&                       args) override;

    virtual void Process_vkAllocateMemory(
        const ApiCallInfo&                          call_info,
        args::AllocateMemory&                       args) override;

    virtual void Process_vkFreeMemory(
        const ApiCallInfo&                          call_info,
        args::FreeMemory&                           args) override;

    virtual void Process_vkMapMemory(
        const ApiCallInfo&                          call_info,
        args::MapMemory&                            args) override;

    virtual void Process_vkUnmapMemory(
        const ApiCallInfo&                          call_info,
        args::UnmapMemory&                          args) override;

    virtual void Process_vkFlushMappedMemoryRanges(
        const ApiCallInfo&                          call_info,
        args::FlushMappedMemoryRanges&              args) override;

    virtual void Process_vkInvalidateMappedMemoryRanges(
        const ApiCallInfo&                          call_info,
        args::InvalidateMappedMemoryRanges&         args) override;

    virtual void Process_vkGetDeviceMemoryCommitment(
        const ApiCallInfo&                          call_info,
        args::GetDeviceMemoryCommitment&            args) override;

    virtual void Process_vkBindBufferMemory(
        const ApiCallInfo&                          call_info,
        args::BindBufferMemory&                     args) override;

    virtual void Process_vkBindImageMemory(
        const ApiCallInfo&                          call_info,
        args::BindImageMemory&                      args) override;

    virtual void Process_vkGetBufferMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetBufferMemoryRequirements&          args) override;

    virtual void Process_vkGetImageMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetImageMemoryRequirements&           args) override;

    virtual void Process_vkGetImageSparseMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetImageSparseMemoryRequirements&     args) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSparseImageFormatProperties& args) override;

    virtual void Process_vkQueueBindSparse(
        const ApiCallInfo&                          call_info,
        args::QueueBindSparse&                      args) override;

    virtual void Process_vkCreateFence(
        const ApiCallInfo&                          call_info,
        args::CreateFence&                          args) override;

    virtual void Process_vkDestroyFence(
        const ApiCallInfo&                          call_info,
        args::DestroyFence&                         args) override;

    virtual void Process_vkResetFences(
        const ApiCallInfo&                          call_info,
        args::ResetFences&                          args) override;

    virtual void Process_vkGetFenceStatus(
        const ApiCallInfo&                          call_info,
        args::GetFenceStatus&                       args) override;

    virtual void Process_vkWaitForFences(
        const ApiCallInfo&                          call_info,
        args::WaitForFences&                        args) override;

    virtual void Process_vkCreateSemaphore(
        const ApiCallInfo&                          call_info,
        args::CreateSemaphore&                      args) override;

    virtual void Process_vkDestroySemaphore(
        const ApiCallInfo&                          call_info,
        args::DestroySemaphore&                     args) override;

    virtual void Process_vkCreateQueryPool(
        const ApiCallInfo&                          call_info,
        args::CreateQueryPool&                      args) override;

    virtual void Process_vkDestroyQueryPool(
        const ApiCallInfo&                          call_info,
        args::DestroyQueryPool&                     args) override;

    virtual void Process_vkGetQueryPoolResults(
        const ApiCallInfo&                          call_info,
        args::GetQueryPoolResults&                  args) override;

    virtual void Process_vkCreateBuffer(
        const ApiCallInfo&                          call_info,
        args::CreateBuffer&                         args) override;

    virtual void Process_vkDestroyBuffer(
        const ApiCallInfo&                          call_info,
        args::DestroyBuffer&                        args) override;

    virtual void Process_vkCreateImage(
        const ApiCallInfo&                          call_info,
        args::CreateImage&                          args) override;

    virtual void Process_vkDestroyImage(
        const ApiCallInfo&                          call_info,
        args::DestroyImage&                         args) override;

    virtual void Process_vkGetImageSubresourceLayout(
        const ApiCallInfo&                          call_info,
        args::GetImageSubresourceLayout&            args) override;

    virtual void Process_vkCreateImageView(
        const ApiCallInfo&                          call_info,
        args::CreateImageView&                      args) override;

    virtual void Process_vkDestroyImageView(
        const ApiCallInfo&                          call_info,
        args::DestroyImageView&                     args) override;

    virtual void Process_vkCreateCommandPool(
        const ApiCallInfo&                          call_info,
        args::CreateCommandPool&                    args) override;

    virtual void Process_vkDestroyCommandPool(
        const ApiCallInfo&                          call_info,
        args::DestroyCommandPool&                   args) override;

    virtual void Process_vkResetCommandPool(
        const ApiCallInfo&                          call_info,
        args::ResetCommandPool&                     args) override;

    virtual void Process_vkAllocateCommandBuffers(
        const ApiCallInfo&                          call_info,
        args::AllocateCommandBuffers&               args) override;

    virtual void Process_vkFreeCommandBuffers(
        const ApiCallInfo&                          call_info,
        args::FreeCommandBuffers&                   args) override;

    virtual void Process_vkBeginCommandBuffer(
        const ApiCallInfo&                          call_info,
        args::BeginCommandBuffer&                   args) override;

    virtual void Process_vkEndCommandBuffer(
        const ApiCallInfo&                          call_info,
        args::EndCommandBuffer&                     args) override;

    virtual void Process_vkResetCommandBuffer(
        const ApiCallInfo&                          call_info,
        args::ResetCommandBuffer&                   args) override;

    virtual void Process_vkCmdCopyBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBuffer&                        args) override;

    virtual void Process_vkCmdCopyImage(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImage&                         args) override;

    virtual void Process_vkCmdCopyBufferToImage(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBufferToImage&                 args) override;

    virtual void Process_vkCmdCopyImageToBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToBuffer&                 args) override;

    virtual void Process_vkCmdUpdateBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdUpdateBuffer&                      args) override;

    virtual void Process_vkCmdFillBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdFillBuffer&                        args) override;

    virtual void Process_vkCmdPipelineBarrier(
        const ApiCallInfo&                          call_info,
        args::CmdPipelineBarrier&                   args) override;

    virtual void Process_vkCmdBeginQuery(
        const ApiCallInfo&                          call_info,
        args::CmdBeginQuery&                        args) override;

    virtual void Process_vkCmdEndQuery(
        const ApiCallInfo&                          call_info,
        args::CmdEndQuery&                          args) override;

    virtual void Process_vkCmdResetQueryPool(
        const ApiCallInfo&                          call_info,
        args::CmdResetQueryPool&                    args) override;

    virtual void Process_vkCmdWriteTimestamp(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp&                    args) override;

    virtual void Process_vkCmdCopyQueryPoolResults(
        const ApiCallInfo&                          call_info,
        args::CmdCopyQueryPoolResults&              args) override;

    virtual void Process_vkCmdExecuteCommands(
        const ApiCallInfo&                          call_info,
        args::CmdExecuteCommands&                   args) override;

    virtual void Process_vkCreateEvent(
        const ApiCallInfo&                          call_info,
        args::CreateEvent&                          args) override;

    virtual void Process_vkDestroyEvent(
        const ApiCallInfo&                          call_info,
        args::DestroyEvent&                         args) override;

    virtual void Process_vkGetEventStatus(
        const ApiCallInfo&                          call_info,
        args::GetEventStatus&                       args) override;

    virtual void Process_vkSetEvent(
        const ApiCallInfo&                          call_info,
        args::SetEvent&                             args) override;

    virtual void Process_vkResetEvent(
        const ApiCallInfo&                          call_info,
        args::ResetEvent&                           args) override;

    virtual void Process_vkCreateBufferView(
        const ApiCallInfo&                          call_info,
        args::CreateBufferView&                     args) override;

    virtual void Process_vkDestroyBufferView(
        const ApiCallInfo&                          call_info,
        args::DestroyBufferView&                    args) override;

    virtual void Process_vkCreateShaderModule(
        const ApiCallInfo&                          call_info,
        args::CreateShaderModule&                   args) override;

    virtual void Process_vkDestroyShaderModule(
        const ApiCallInfo&                          call_info,
        args::DestroyShaderModule&                  args) override;

    virtual void Process_vkCreatePipelineCache(
        const ApiCallInfo&                          call_info,
        args::CreatePipelineCache&                  args) override;

    virtual void Process_vkDestroyPipelineCache(
        const ApiCallInfo&                          call_info,
        args::DestroyPipelineCache&                 args) override;

    virtual void Process_vkGetPipelineCacheData(
        const ApiCallInfo&                          call_info,
        args::GetPipelineCacheData&                 args) override;

    virtual void Process_vkMergePipelineCaches(
        const ApiCallInfo&                          call_info,
        args::MergePipelineCaches&                  args) override;

    virtual void Process_vkCreateComputePipelines(
        const ApiCallInfo&                          call_info,
        args::CreateComputePipelines&               args) override;

    virtual void Process_vkDestroyPipeline(
        const ApiCallInfo&                          call_info,
        args::DestroyPipeline&                      args) override;

    virtual void Process_vkCreatePipelineLayout(
        const ApiCallInfo&                          call_info,
        args::CreatePipelineLayout&                 args) override;

    virtual void Process_vkDestroyPipelineLayout(
        const ApiCallInfo&                          call_info,
        args::DestroyPipelineLayout&                args) override;

    virtual void Process_vkCreateSampler(
        const ApiCallInfo&                          call_info,
        args::CreateSampler&                        args) override;

    virtual void Process_vkDestroySampler(
        const ApiCallInfo&                          call_info,
        args::DestroySampler&                       args) override;

    virtual void Process_vkCreateDescriptorSetLayout(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorSetLayout&            args) override;

    virtual void Process_vkDestroyDescriptorSetLayout(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorSetLayout&           args) override;

    virtual void Process_vkCreateDescriptorPool(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorPool&                 args) override;

    virtual void Process_vkDestroyDescriptorPool(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorPool&                args) override;

    virtual void Process_vkResetDescriptorPool(
        const ApiCallInfo&                          call_info,
        args::ResetDescriptorPool&                  args) override;

    virtual void Process_vkAllocateDescriptorSets(
        const ApiCallInfo&                          call_info,
        args::AllocateDescriptorSets&               args) override;

    virtual void Process_vkFreeDescriptorSets(
        const ApiCallInfo&                          call_info,
        args::FreeDescriptorSets&                   args) override;

    virtual void Process_vkUpdateDescriptorSets(
        const ApiCallInfo&                          call_info,
        args::UpdateDescriptorSets&                 args) override;

    virtual void Process_vkCmdBindPipeline(
        const ApiCallInfo&                          call_info,
        args::CmdBindPipeline&                      args) override;

    virtual void Process_vkCmdBindDescriptorSets(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorSets&                args) override;

    virtual void Process_vkCmdClearColorImage(
        const ApiCallInfo&                          call_info,
        args::CmdClearColorImage&                   args) override;

    virtual void Process_vkCmdDispatch(
        const ApiCallInfo&                          call_info,
        args::CmdDispatch&                          args) override;

    virtual void Process_vkCmdDispatchIndirect(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchIndirect&                  args) override;

    virtual void Process_vkCmdSetEvent(
        const ApiCallInfo&                          call_info,
        args::CmdSetEvent&                          args) override;

    virtual void Process_vkCmdResetEvent(
        const ApiCallInfo&                          call_info,
        args::CmdResetEvent&                        args) override;

    virtual void Process_vkCmdWaitEvents(
        const ApiCallInfo&                          call_info,
        args::CmdWaitEvents&                        args) override;

    virtual void Process_vkCmdPushConstants(
        const ApiCallInfo&                          call_info,
        args::CmdPushConstants&                     args) override;

    virtual void Process_vkCreateGraphicsPipelines(
        const ApiCallInfo&                          call_info,
        args::CreateGraphicsPipelines&              args) override;

    virtual void Process_vkCreateFramebuffer(
        const ApiCallInfo&                          call_info,
        args::CreateFramebuffer&                    args) override;

    virtual void Process_vkDestroyFramebuffer(
        const ApiCallInfo&                          call_info,
        args::DestroyFramebuffer&                   args) override;

    virtual void Process_vkCreateRenderPass(
        const ApiCallInfo&                          call_info,
        args::CreateRenderPass&                     args) override;

    virtual void Process_vkDestroyRenderPass(
        const ApiCallInfo&                          call_info,
        args::DestroyRenderPass&                    args) override;

    virtual void Process_vkGetRenderAreaGranularity(
        const ApiCallInfo&                          call_info,
        args::GetRenderAreaGranularity&             args) override;

    virtual void Process_vkCmdSetViewport(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewport&                       args) override;

    virtual void Process_vkCmdSetScissor(
        const ApiCallInfo&                          call_info,
        args::CmdSetScissor&                        args) override;

    virtual void Process_vkCmdSetLineWidth(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineWidth&                      args) override;

    virtual void Process_vkCmdSetDepthBias(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBias&                      args) override;

    virtual void Process_vkCmdSetBlendConstants(
        const ApiCallInfo&                          call_info,
        args::CmdSetBlendConstants&                 args) override;

    virtual void Process_vkCmdSetDepthBounds(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBounds&                    args) override;

    virtual void Process_vkCmdSetStencilCompareMask(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilCompareMask&             args) override;

    virtual void Process_vkCmdSetStencilWriteMask(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilWriteMask&               args) override;

    virtual void Process_vkCmdSetStencilReference(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilReference&               args) override;

    virtual void Process_vkCmdBindIndexBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer&                   args) override;

    virtual void Process_vkCmdBindVertexBuffers(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers&                 args) override;

    virtual void Process_vkCmdDraw(
        const ApiCallInfo&                          call_info,
        args::CmdDraw&                              args) override;

    virtual void Process_vkCmdDrawIndexed(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexed&                       args) override;

    virtual void Process_vkCmdDrawIndirect(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirect&                      args) override;

    virtual void Process_vkCmdDrawIndexedIndirect(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirect&               args) override;

    virtual void Process_vkCmdBlitImage(
        const ApiCallInfo&                          call_info,
        args::CmdBlitImage&                         args) override;

    virtual void Process_vkCmdClearDepthStencilImage(
        const ApiCallInfo&                          call_info,
        args::CmdClearDepthStencilImage&            args) override;

    virtual void Process_vkCmdClearAttachments(
        const ApiCallInfo&                          call_info,
        args::CmdClearAttachments&                  args) override;

    virtual void Process_vkCmdResolveImage(
        const ApiCallInfo&                          call_info,
        args::CmdResolveImage&                      args) override;

    virtual void Process_vkCmdBeginRenderPass(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderPass&                   args) override;

    virtual void Process_vkCmdNextSubpass(
        const ApiCallInfo&                          call_info,
        args::CmdNextSubpass&                       args) override;

    virtual void Process_vkCmdEndRenderPass(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderPass&                     args) override;

    virtual void Process_vkBindBufferMemory2(
        const ApiCallInfo&                          call_info,
        args::BindBufferMemory2&                    args) override;

    virtual void Process_vkBindImageMemory2(
        const ApiCallInfo&                          call_info,
        args::BindImageMemory2&                     args) override;

    virtual void Process_vkGetDeviceGroupPeerMemoryFeatures(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupPeerMemoryFeatures&     args) override;

    virtual void Process_vkCmdSetDeviceMask(
        const ApiCallInfo&                          call_info,
        args::CmdSetDeviceMask&                     args) override;

    virtual void Process_vkEnumeratePhysicalDeviceGroups(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDeviceGroups&        args) override;

    virtual void Process_vkGetImageMemoryRequirements2(
        const ApiCallInfo&                          call_info,
        args::GetImageMemoryRequirements2&          args) override;

    virtual void Process_vkGetBufferMemoryRequirements2(
        const ApiCallInfo&                          call_info,
        args::GetBufferMemoryRequirements2&         args) override;

    virtual void Process_vkGetImageSparseMemoryRequirements2(
        const ApiCallInfo&                          call_info,
        args::GetImageSparseMemoryRequirements2&    args) override;

    virtual void Process_vkGetPhysicalDeviceFeatures2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFeatures2&           args) override;

    virtual void Process_vkGetPhysicalDeviceProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceProperties2&         args) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFormatProperties2&   args) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceImageFormatProperties2& args) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyProperties2& args) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceMemoryProperties2&   args) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSparseImageFormatProperties2& args) override;

    virtual void Process_vkTrimCommandPool(
        const ApiCallInfo&                          call_info,
        args::TrimCommandPool&                      args) override;

    virtual void Process_vkGetDeviceQueue2(
        const ApiCallInfo&                          call_info,
        args::GetDeviceQueue2&                      args) override;

    virtual void Process_vkGetPhysicalDeviceExternalBufferProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalBufferProperties& args) override;

    virtual void Process_vkGetPhysicalDeviceExternalFenceProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalFenceProperties& args) override;

    virtual void Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalSemaphoreProperties& args) override;

    virtual void Process_vkCmdDispatchBase(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchBase&                      args) override;

    virtual void Process_vkCreateDescriptorUpdateTemplate(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorUpdateTemplate&       args) override;

    virtual void Process_vkDestroyDescriptorUpdateTemplate(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorUpdateTemplate&      args) override;

    virtual void Process_vkGetDescriptorSetLayoutSupport(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutSupport&        args) override;

    virtual void Process_vkCreateSamplerYcbcrConversion(
        const ApiCallInfo&                          call_info,
        args::CreateSamplerYcbcrConversion&         args) override;

    virtual void Process_vkDestroySamplerYcbcrConversion(
        const ApiCallInfo&                          call_info,
        args::DestroySamplerYcbcrConversion&        args) override;

    virtual void Process_vkResetQueryPool(
        const ApiCallInfo&                          call_info,
        args::ResetQueryPool&                       args) override;

    virtual void Process_vkGetSemaphoreCounterValue(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreCounterValue&             args) override;

    virtual void Process_vkWaitSemaphores(
        const ApiCallInfo&                          call_info,
        args::WaitSemaphores&                       args) override;

    virtual void Process_vkSignalSemaphore(
        const ApiCallInfo&                          call_info,
        args::SignalSemaphore&                      args) override;

    virtual void Process_vkGetBufferDeviceAddress(
        const ApiCallInfo&                          call_info,
        args::GetBufferDeviceAddress&               args) override;

    virtual void Process_vkGetBufferOpaqueCaptureAddress(
        const ApiCallInfo&                          call_info,
        args::GetBufferOpaqueCaptureAddress&        args) override;

    virtual void Process_vkGetDeviceMemoryOpaqueCaptureAddress(
        const ApiCallInfo&                          call_info,
        args::GetDeviceMemoryOpaqueCaptureAddress&  args) override;

    virtual void Process_vkCmdDrawIndirectCount(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCount&                 args) override;

    virtual void Process_vkCmdDrawIndexedIndirectCount(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCount&          args) override;

    virtual void Process_vkCreateRenderPass2(
        const ApiCallInfo&                          call_info,
        args::CreateRenderPass2&                    args) override;

    virtual void Process_vkCmdBeginRenderPass2(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderPass2&                  args) override;

    virtual void Process_vkCmdNextSubpass2(
        const ApiCallInfo&                          call_info,
        args::CmdNextSubpass2&                      args) override;

    virtual void Process_vkCmdEndRenderPass2(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderPass2&                    args) override;

    virtual void Process_vkGetPhysicalDeviceToolProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceToolProperties&      args) override;

    virtual void Process_vkCreatePrivateDataSlot(
        const ApiCallInfo&                          call_info,
        args::CreatePrivateDataSlot&                args) override;

    virtual void Process_vkDestroyPrivateDataSlot(
        const ApiCallInfo&                          call_info,
        args::DestroyPrivateDataSlot&               args) override;

    virtual void Process_vkSetPrivateData(
        const ApiCallInfo&                          call_info,
        args::SetPrivateData&                       args) override;

    virtual void Process_vkGetPrivateData(
        const ApiCallInfo&                          call_info,
        args::GetPrivateData&                       args) override;

    virtual void Process_vkCmdPipelineBarrier2(
        const ApiCallInfo&                          call_info,
        args::CmdPipelineBarrier2&                  args) override;

    virtual void Process_vkCmdWriteTimestamp2(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp2&                   args) override;

    virtual void Process_vkQueueSubmit2(
        const ApiCallInfo&                          call_info,
        args::QueueSubmit2&                         args) override;

    virtual void Process_vkCmdCopyBuffer2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBuffer2&                       args) override;

    virtual void Process_vkCmdCopyImage2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImage2&                        args) override;

    virtual void Process_vkCmdCopyBufferToImage2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBufferToImage2&                args) override;

    virtual void Process_vkCmdCopyImageToBuffer2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToBuffer2&                args) override;

    virtual void Process_vkGetDeviceBufferMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetDeviceBufferMemoryRequirements&    args) override;

    virtual void Process_vkGetDeviceImageMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageMemoryRequirements&     args) override;

    virtual void Process_vkGetDeviceImageSparseMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageSparseMemoryRequirements& args) override;

    virtual void Process_vkCmdSetEvent2(
        const ApiCallInfo&                          call_info,
        args::CmdSetEvent2&                         args) override;

    virtual void Process_vkCmdResetEvent2(
        const ApiCallInfo&                          call_info,
        args::CmdResetEvent2&                       args) override;

    virtual void Process_vkCmdWaitEvents2(
        const ApiCallInfo&                          call_info,
        args::CmdWaitEvents2&                       args) override;

    virtual void Process_vkCmdBlitImage2(
        const ApiCallInfo&                          call_info,
        args::CmdBlitImage2&                        args) override;

    virtual void Process_vkCmdResolveImage2(
        const ApiCallInfo&                          call_info,
        args::CmdResolveImage2&                     args) override;

    virtual void Process_vkCmdBeginRendering(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRendering&                    args) override;

    virtual void Process_vkCmdEndRendering(
        const ApiCallInfo&                          call_info,
        args::CmdEndRendering&                      args) override;

    virtual void Process_vkCmdSetCullMode(
        const ApiCallInfo&                          call_info,
        args::CmdSetCullMode&                       args) override;

    virtual void Process_vkCmdSetFrontFace(
        const ApiCallInfo&                          call_info,
        args::CmdSetFrontFace&                      args) override;

    virtual void Process_vkCmdSetPrimitiveTopology(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveTopology&              args) override;

    virtual void Process_vkCmdSetViewportWithCount(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWithCount&              args) override;

    virtual void Process_vkCmdSetScissorWithCount(
        const ApiCallInfo&                          call_info,
        args::CmdSetScissorWithCount&               args) override;

    virtual void Process_vkCmdBindVertexBuffers2(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers2&                args) override;

    virtual void Process_vkCmdSetDepthTestEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthTestEnable&                args) override;

    virtual void Process_vkCmdSetDepthWriteEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthWriteEnable&               args) override;

    virtual void Process_vkCmdSetDepthCompareOp(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthCompareOp&                 args) override;

    virtual void Process_vkCmdSetDepthBoundsTestEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBoundsTestEnable&          args) override;

    virtual void Process_vkCmdSetStencilTestEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilTestEnable&              args) override;

    virtual void Process_vkCmdSetStencilOp(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilOp&                      args) override;

    virtual void Process_vkCmdSetRasterizerDiscardEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizerDiscardEnable&        args) override;

    virtual void Process_vkCmdSetDepthBiasEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBiasEnable&                args) override;

    virtual void Process_vkCmdSetPrimitiveRestartEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveRestartEnable&         args) override;

    virtual void Process_vkMapMemory2(
        const ApiCallInfo&                          call_info,
        args::MapMemory2&                           args) override;

    virtual void Process_vkUnmapMemory2(
        const ApiCallInfo&                          call_info,
        args::UnmapMemory2&                         args) override;

    virtual void Process_vkGetDeviceImageSubresourceLayout(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageSubresourceLayout&      args) override;

    virtual void Process_vkGetImageSubresourceLayout2(
        const ApiCallInfo&                          call_info,
        args::GetImageSubresourceLayout2&           args) override;

    virtual void Process_vkCopyMemoryToImage(
        const ApiCallInfo&                          call_info,
        args::CopyMemoryToImage&                    args) override;

    virtual void Process_vkCopyImageToMemory(
        const ApiCallInfo&                          call_info,
        args::CopyImageToMemory&                    args) override;

    virtual void Process_vkCopyImageToImage(
        const ApiCallInfo&                          call_info,
        args::CopyImageToImage&                     args) override;

    virtual void Process_vkTransitionImageLayout(
        const ApiCallInfo&                          call_info,
        args::TransitionImageLayout&                args) override;

    virtual void Process_vkCmdPushDescriptorSet(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSet&                 args) override;

    virtual void Process_vkCmdBindDescriptorSets2(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorSets2&               args) override;

    virtual void Process_vkCmdPushConstants2(
        const ApiCallInfo&                          call_info,
        args::CmdPushConstants2&                    args) override;

    virtual void Process_vkCmdPushDescriptorSet2(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSet2&                args) override;

    virtual void Process_vkCmdSetLineStipple(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStipple&                    args) override;

    virtual void Process_vkCmdBindIndexBuffer2(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer2&                  args) override;

    virtual void Process_vkGetRenderingAreaGranularity(
        const ApiCallInfo&                          call_info,
        args::GetRenderingAreaGranularity&          args) override;

    virtual void Process_vkCmdSetRenderingAttachmentLocations(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingAttachmentLocations&   args) override;

    virtual void Process_vkCmdSetRenderingInputAttachmentIndices(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingInputAttachmentIndices& args) override;

    virtual void Process_vkDestroySurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::DestroySurfaceKHR&                    args) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceSupportKHR&   args) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceCapabilitiesKHR& args) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceFormatsKHR&   args) override;

    virtual void Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfacePresentModesKHR& args) override;

    virtual void Process_vkCreateSwapchainKHR(
        const ApiCallInfo&                          call_info,
        args::CreateSwapchainKHR&                   args) override;

    virtual void Process_vkDestroySwapchainKHR(
        const ApiCallInfo&                          call_info,
        args::DestroySwapchainKHR&                  args) override;

    virtual void Process_vkGetSwapchainImagesKHR(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainImagesKHR&                args) override;

    virtual void Process_vkAcquireNextImageKHR(
        const ApiCallInfo&                          call_info,
        args::AcquireNextImageKHR&                  args) override;

    virtual void Process_vkQueuePresentKHR(
        const ApiCallInfo&                          call_info,
        args::QueuePresentKHR&                      args) override;

    virtual void Process_vkGetDeviceGroupPresentCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupPresentCapabilitiesKHR& args) override;

    virtual void Process_vkGetDeviceGroupSurfacePresentModesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupSurfacePresentModesKHR& args) override;

    virtual void Process_vkGetPhysicalDevicePresentRectanglesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDevicePresentRectanglesKHR& args) override;

    virtual void Process_vkAcquireNextImage2KHR(
        const ApiCallInfo&                          call_info,
        args::AcquireNextImage2KHR&                 args) override;

    virtual void Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDisplayPropertiesKHR& args) override;

    virtual void Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDisplayPlanePropertiesKHR& args) override;

    virtual void Process_vkGetDisplayPlaneSupportedDisplaysKHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayPlaneSupportedDisplaysKHR&  args) override;

    virtual void Process_vkGetDisplayModePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayModePropertiesKHR&          args) override;

    virtual void Process_vkCreateDisplayModeKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDisplayModeKHR&                 args) override;

    virtual void Process_vkGetDisplayPlaneCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayPlaneCapabilitiesKHR&       args) override;

    virtual void Process_vkCreateDisplayPlaneSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDisplayPlaneSurfaceKHR&         args) override;

    virtual void Process_vkCreateSharedSwapchainsKHR(
        const ApiCallInfo&                          call_info,
        args::CreateSharedSwapchainsKHR&            args) override;

    virtual void Process_vkCreateXlibSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateXlibSurfaceKHR&                 args) override;

    virtual void Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceXlibPresentationSupportKHR& args) override;

    virtual void Process_vkCreateXcbSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateXcbSurfaceKHR&                  args) override;

    virtual void Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceXcbPresentationSupportKHR& args) override;

    virtual void Process_vkCreateWaylandSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateWaylandSurfaceKHR&              args) override;

    virtual void Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceWaylandPresentationSupportKHR& args) override;

    virtual void Process_vkCreateAndroidSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateAndroidSurfaceKHR&              args) override;

    virtual void Process_vkCreateWin32SurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateWin32SurfaceKHR&                args) override;

    virtual void Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceWin32PresentationSupportKHR& args) override;

    virtual void Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceVideoCapabilitiesKHR& args) override;

    virtual void Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceVideoFormatPropertiesKHR& args) override;

    virtual void Process_vkCreateVideoSessionKHR(
        const ApiCallInfo&                          call_info,
        args::CreateVideoSessionKHR&                args) override;

    virtual void Process_vkDestroyVideoSessionKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyVideoSessionKHR&               args) override;

    virtual void Process_vkGetVideoSessionMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        args::GetVideoSessionMemoryRequirementsKHR& args) override;

    virtual void Process_vkBindVideoSessionMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::BindVideoSessionMemoryKHR&            args) override;

    virtual void Process_vkCreateVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::CreateVideoSessionParametersKHR&      args) override;

    virtual void Process_vkUpdateVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::UpdateVideoSessionParametersKHR&      args) override;

    virtual void Process_vkDestroyVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyVideoSessionParametersKHR&     args) override;

    virtual void Process_vkCmdBeginVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBeginVideoCodingKHR&               args) override;

    virtual void Process_vkCmdEndVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndVideoCodingKHR&                 args) override;

    virtual void Process_vkCmdControlVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdControlVideoCodingKHR&             args) override;

    virtual void Process_vkCmdDecodeVideoKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDecodeVideoKHR&                    args) override;

    virtual void Process_vkCmdBeginRenderingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderingKHR&                 args) override;

    virtual void Process_vkCmdEndRenderingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderingKHR&                   args) override;

    virtual void Process_vkGetPhysicalDeviceFeatures2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFeatures2KHR&        args) override;

    virtual void Process_vkGetPhysicalDeviceProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceProperties2KHR&      args) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFormatProperties2KHR& args) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceImageFormatProperties2KHR& args) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyProperties2KHR& args) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceMemoryProperties2KHR& args) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSparseImageFormatProperties2KHR& args) override;

    virtual void Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupPeerMemoryFeaturesKHR&  args) override;

    virtual void Process_vkCmdSetDeviceMaskKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetDeviceMaskKHR&                  args) override;

    virtual void Process_vkCmdDispatchBaseKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchBaseKHR&                   args) override;

    virtual void Process_vkTrimCommandPoolKHR(
        const ApiCallInfo&                          call_info,
        args::TrimCommandPoolKHR&                   args) override;

    virtual void Process_vkEnumeratePhysicalDeviceGroupsKHR(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDeviceGroupsKHR&     args) override;

    virtual void Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalBufferPropertiesKHR& args) override;

    virtual void Process_vkGetMemoryWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::GetMemoryWin32HandleKHR&              args) override;

    virtual void Process_vkGetMemoryWin32HandlePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetMemoryWin32HandlePropertiesKHR&    args) override;

    virtual void Process_vkGetMemoryFdKHR(
        const ApiCallInfo&                          call_info,
        args::GetMemoryFdKHR&                       args) override;

    virtual void Process_vkGetMemoryFdPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetMemoryFdPropertiesKHR&             args) override;

    virtual void Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalSemaphorePropertiesKHR& args) override;

    virtual void Process_vkImportSemaphoreWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::ImportSemaphoreWin32HandleKHR&        args) override;

    virtual void Process_vkGetSemaphoreWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreWin32HandleKHR&           args) override;

    virtual void Process_vkImportSemaphoreFdKHR(
        const ApiCallInfo&                          call_info,
        args::ImportSemaphoreFdKHR&                 args) override;

    virtual void Process_vkGetSemaphoreFdKHR(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreFdKHR&                    args) override;

    virtual void Process_vkCmdPushDescriptorSetKHR(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSetKHR&              args) override;

    virtual void Process_vkCreateDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorUpdateTemplateKHR&    args) override;

    virtual void Process_vkDestroyDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorUpdateTemplateKHR&   args) override;

    virtual void Process_vkCreateRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        args::CreateRenderPass2KHR&                 args) override;

    virtual void Process_vkCmdBeginRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderPass2KHR&               args) override;

    virtual void Process_vkCmdNextSubpass2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdNextSubpass2KHR&                   args) override;

    virtual void Process_vkCmdEndRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderPass2KHR&                 args) override;

    virtual void Process_vkGetSwapchainStatusKHR(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainStatusKHR&                args) override;

    virtual void Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalFencePropertiesKHR& args) override;

    virtual void Process_vkImportFenceWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::ImportFenceWin32HandleKHR&            args) override;

    virtual void Process_vkGetFenceWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::GetFenceWin32HandleKHR&               args) override;

    virtual void Process_vkImportFenceFdKHR(
        const ApiCallInfo&                          call_info,
        args::ImportFenceFdKHR&                     args) override;

    virtual void Process_vkGetFenceFdKHR(
        const ApiCallInfo&                          call_info,
        args::GetFenceFdKHR&                        args) override;

    virtual void Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR& args) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR& args) override;

    virtual void Process_vkAcquireProfilingLockKHR(
        const ApiCallInfo&                          call_info,
        args::AcquireProfilingLockKHR&              args) override;

    virtual void Process_vkReleaseProfilingLockKHR(
        const ApiCallInfo&                          call_info,
        args::ReleaseProfilingLockKHR&              args) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceCapabilities2KHR& args) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceFormats2KHR&  args) override;

    virtual void Process_vkGetPhysicalDeviceDisplayProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDisplayProperties2KHR& args) override;

    virtual void Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDisplayPlaneProperties2KHR& args) override;

    virtual void Process_vkGetDisplayModeProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayModeProperties2KHR&         args) override;

    virtual void Process_vkGetDisplayPlaneCapabilities2KHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayPlaneCapabilities2KHR&      args) override;

    virtual void Process_vkGetImageMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        args::GetImageMemoryRequirements2KHR&       args) override;

    virtual void Process_vkGetBufferMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        args::GetBufferMemoryRequirements2KHR&      args) override;

    virtual void Process_vkGetImageSparseMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        args::GetImageSparseMemoryRequirements2KHR& args) override;

    virtual void Process_vkCreateSamplerYcbcrConversionKHR(
        const ApiCallInfo&                          call_info,
        args::CreateSamplerYcbcrConversionKHR&      args) override;

    virtual void Process_vkDestroySamplerYcbcrConversionKHR(
        const ApiCallInfo&                          call_info,
        args::DestroySamplerYcbcrConversionKHR&     args) override;

    virtual void Process_vkBindBufferMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::BindBufferMemory2KHR&                 args) override;

    virtual void Process_vkBindImageMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::BindImageMemory2KHR&                  args) override;

    virtual void Process_vkGetDescriptorSetLayoutSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutSupportKHR&     args) override;

    virtual void Process_vkCmdDrawIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCountKHR&              args) override;

    virtual void Process_vkCmdDrawIndexedIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCountKHR&       args) override;

    virtual void Process_vkGetSemaphoreCounterValueKHR(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreCounterValueKHR&          args) override;

    virtual void Process_vkWaitSemaphoresKHR(
        const ApiCallInfo&                          call_info,
        args::WaitSemaphoresKHR&                    args) override;

    virtual void Process_vkSignalSemaphoreKHR(
        const ApiCallInfo&                          call_info,
        args::SignalSemaphoreKHR&                   args) override;

    virtual void Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFragmentShadingRatesKHR& args) override;

    virtual void Process_vkCmdSetFragmentShadingRateKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetFragmentShadingRateKHR&         args) override;

    virtual void Process_vkCmdSetRenderingAttachmentLocationsKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingAttachmentLocationsKHR& args) override;

    virtual void Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingInputAttachmentIndicesKHR& args) override;

    virtual void Process_vkWaitForPresentKHR(
        const ApiCallInfo&                          call_info,
        args::WaitForPresentKHR&                    args) override;

    virtual void Process_vkGetBufferDeviceAddressKHR(
        const ApiCallInfo&                          call_info,
        args::GetBufferDeviceAddressKHR&            args) override;

    virtual void Process_vkGetBufferOpaqueCaptureAddressKHR(
        const ApiCallInfo&                          call_info,
        args::GetBufferOpaqueCaptureAddressKHR&     args) override;

    virtual void Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceMemoryOpaqueCaptureAddressKHR& args) override;

    virtual void Process_vkCreateDeferredOperationKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDeferredOperationKHR&           args) override;

    virtual void Process_vkDestroyDeferredOperationKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyDeferredOperationKHR&          args) override;

    virtual void Process_vkGetDeferredOperationMaxConcurrencyKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeferredOperationMaxConcurrencyKHR& args) override;

    virtual void Process_vkGetDeferredOperationResultKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeferredOperationResultKHR&        args) override;

    virtual void Process_vkDeferredOperationJoinKHR(
        const ApiCallInfo&                          call_info,
        args::DeferredOperationJoinKHR&             args) override;

    virtual void Process_vkGetPipelineExecutablePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineExecutablePropertiesKHR&   args) override;

    virtual void Process_vkGetPipelineExecutableStatisticsKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineExecutableStatisticsKHR&   args) override;

    virtual void Process_vkGetPipelineExecutableInternalRepresentationsKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineExecutableInternalRepresentationsKHR& args) override;

    virtual void Process_vkMapMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::MapMemory2KHR&                        args) override;

    virtual void Process_vkUnmapMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::UnmapMemory2KHR&                      args) override;

    virtual void Process_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR& args) override;

    virtual void Process_vkGetEncodedVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::GetEncodedVideoSessionParametersKHR&  args) override;

    virtual void Process_vkCmdEncodeVideoKHR(
        const ApiCallInfo&                          call_info,
        args::CmdEncodeVideoKHR&                    args) override;

    virtual void Process_vkCmdSetEvent2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetEvent2KHR&                      args) override;

    virtual void Process_vkCmdResetEvent2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdResetEvent2KHR&                    args) override;

    virtual void Process_vkCmdWaitEvents2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdWaitEvents2KHR&                    args) override;

    virtual void Process_vkCmdPipelineBarrier2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdPipelineBarrier2KHR&               args) override;

    virtual void Process_vkCmdWriteTimestamp2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp2KHR&                args) override;

    virtual void Process_vkQueueSubmit2KHR(
        const ApiCallInfo&                          call_info,
        args::QueueSubmit2KHR&                      args) override;

    virtual void Process_vkCmdBindIndexBuffer3KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer3KHR&               args) override;

    virtual void Process_vkCmdBindVertexBuffers3KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers3KHR&             args) override;

    virtual void Process_vkCmdDrawIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirect2KHR&                  args) override;

    virtual void Process_vkCmdDrawIndexedIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirect2KHR&           args) override;

    virtual void Process_vkCmdDispatchIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchIndirect2KHR&              args) override;

    virtual void Process_vkCmdCopyMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryKHR&                     args) override;

    virtual void Process_vkCmdCopyMemoryToImageKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToImageKHR&              args) override;

    virtual void Process_vkCmdCopyImageToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToMemoryKHR&              args) override;

    virtual void Process_vkCmdUpdateMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdUpdateMemoryKHR&                   args) override;

    virtual void Process_vkCmdFillMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdFillMemoryKHR&                     args) override;

    virtual void Process_vkCmdCopyQueryPoolResultsToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyQueryPoolResultsToMemoryKHR&   args) override;

    virtual void Process_vkCmdDrawIndirectCount2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCount2KHR&             args) override;

    virtual void Process_vkCmdDrawIndexedIndirectCount2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCount2KHR&      args) override;

    virtual void Process_vkCmdBeginConditionalRendering2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginConditionalRendering2EXT&     args) override;

    virtual void Process_vkCmdBindTransformFeedbackBuffers2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindTransformFeedbackBuffers2EXT&  args) override;

    virtual void Process_vkCmdBeginTransformFeedback2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginTransformFeedback2EXT&        args) override;

    virtual void Process_vkCmdEndTransformFeedback2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndTransformFeedback2EXT&          args) override;

    virtual void Process_vkCmdDrawIndirectByteCount2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectByteCount2EXT&         args) override;

    virtual void Process_vkCmdDrawMeshTasksIndirect2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirect2EXT&         args) override;

    virtual void Process_vkCmdDrawMeshTasksIndirectCount2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectCount2EXT&    args) override;

    virtual void Process_vkCmdWriteMarkerToMemoryAMD(
        const ApiCallInfo&                          call_info,
        args::CmdWriteMarkerToMemoryAMD&            args) override;

    virtual void Process_vkCreateAccelerationStructure2KHR(
        const ApiCallInfo&                          call_info,
        args::CreateAccelerationStructure2KHR&      args) override;

    virtual void Process_vkCmdCopyBuffer2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBuffer2KHR&                    args) override;

    virtual void Process_vkCmdCopyImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImage2KHR&                     args) override;

    virtual void Process_vkCmdCopyBufferToImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBufferToImage2KHR&             args) override;

    virtual void Process_vkCmdCopyImageToBuffer2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToBuffer2KHR&             args) override;

    virtual void Process_vkCmdBlitImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBlitImage2KHR&                     args) override;

    virtual void Process_vkCmdResolveImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdResolveImage2KHR&                  args) override;

    virtual void Process_vkCmdTraceRaysIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysIndirect2KHR&             args) override;

    virtual void Process_vkGetDeviceBufferMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceBufferMemoryRequirementsKHR& args) override;

    virtual void Process_vkGetDeviceImageMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageMemoryRequirementsKHR&  args) override;

    virtual void Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageSparseMemoryRequirementsKHR& args) override;

    virtual void Process_vkCmdBindIndexBuffer2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer2KHR&               args) override;

    virtual void Process_vkGetRenderingAreaGranularityKHR(
        const ApiCallInfo&                          call_info,
        args::GetRenderingAreaGranularityKHR&       args) override;

    virtual void Process_vkGetDeviceImageSubresourceLayoutKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageSubresourceLayoutKHR&   args) override;

    virtual void Process_vkGetImageSubresourceLayout2KHR(
        const ApiCallInfo&                          call_info,
        args::GetImageSubresourceLayout2KHR&        args) override;

    virtual void Process_vkWaitForPresent2KHR(
        const ApiCallInfo&                          call_info,
        args::WaitForPresent2KHR&                   args) override;

    virtual void Process_vkCreatePipelineBinariesKHR(
        const ApiCallInfo&                          call_info,
        args::CreatePipelineBinariesKHR&            args) override;

    virtual void Process_vkDestroyPipelineBinaryKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyPipelineBinaryKHR&             args) override;

    virtual void Process_vkGetPipelineKeyKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineKeyKHR&                    args) override;

    virtual void Process_vkGetPipelineBinaryDataKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineBinaryDataKHR&             args) override;

    virtual void Process_vkReleaseCapturedPipelineDataKHR(
        const ApiCallInfo&                          call_info,
        args::ReleaseCapturedPipelineDataKHR&       args) override;

    virtual void Process_vkReleaseSwapchainImagesKHR(
        const ApiCallInfo&                          call_info,
        args::ReleaseSwapchainImagesKHR&            args) override;

    virtual void Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCooperativeMatrixPropertiesKHR& args) override;

    virtual void Process_vkCmdSetLineStippleKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStippleKHR&                 args) override;

    virtual void Process_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCalibrateableTimeDomainsKHR& args) override;

    virtual void Process_vkGetCalibratedTimestampsKHR(
        const ApiCallInfo&                          call_info,
        args::GetCalibratedTimestampsKHR&           args) override;

    virtual void Process_vkCmdBindDescriptorSets2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorSets2KHR&            args) override;

    virtual void Process_vkCmdPushConstants2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdPushConstants2KHR&                 args) override;

    virtual void Process_vkCmdPushDescriptorSet2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSet2KHR&             args) override;

    virtual void Process_vkCmdSetDescriptorBufferOffsets2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDescriptorBufferOffsets2EXT&    args) override;

    virtual void Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorBufferEmbeddedSamplers2EXT& args) override;

    virtual void Process_vkCmdCopyMemoryIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryIndirectKHR&             args) override;

    virtual void Process_vkCmdCopyMemoryToImageIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToImageIndirectKHR&      args) override;

    virtual void Process_vkGetDeviceFaultReportsKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceFaultReportsKHR&             args) override;

    virtual void Process_vkGetDeviceFaultDebugInfoKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceFaultDebugInfoKHR&           args) override;

    virtual void Process_vkCmdEndRendering2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndRendering2KHR&                  args) override;

    virtual void Process_vkFrameBoundaryANDROID(
        const ApiCallInfo&                          call_info,
        args::FrameBoundaryANDROID&                 args) override;

    virtual void Process_vkCreateDebugReportCallbackEXT(
        const ApiCallInfo&                          call_info,
        args::CreateDebugReportCallbackEXT&         args) override;

    virtual void Process_vkDestroyDebugReportCallbackEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyDebugReportCallbackEXT&        args) override;

    virtual void Process_vkDebugReportMessageEXT(
        const ApiCallInfo&                          call_info,
        args::DebugReportMessageEXT&                args) override;

    virtual void Process_vkDebugMarkerSetObjectTagEXT(
        const ApiCallInfo&                          call_info,
        args::DebugMarkerSetObjectTagEXT&           args) override;

    virtual void Process_vkDebugMarkerSetObjectNameEXT(
        const ApiCallInfo&                          call_info,
        args::DebugMarkerSetObjectNameEXT&          args) override;

    virtual void Process_vkCmdDebugMarkerBeginEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDebugMarkerBeginEXT&               args) override;

    virtual void Process_vkCmdDebugMarkerEndEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDebugMarkerEndEXT&                 args) override;

    virtual void Process_vkCmdDebugMarkerInsertEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDebugMarkerInsertEXT&              args) override;

    virtual void Process_vkCmdBindTransformFeedbackBuffersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindTransformFeedbackBuffersEXT&   args) override;

    virtual void Process_vkCmdBeginTransformFeedbackEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginTransformFeedbackEXT&         args) override;

    virtual void Process_vkCmdEndTransformFeedbackEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndTransformFeedbackEXT&           args) override;

    virtual void Process_vkCmdBeginQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginQueryIndexedEXT&              args) override;

    virtual void Process_vkCmdEndQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndQueryIndexedEXT&                args) override;

    virtual void Process_vkCmdDrawIndirectByteCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectByteCountEXT&          args) override;

    virtual void Process_vkGetImageViewHandleNVX(
        const ApiCallInfo&                          call_info,
        args::GetImageViewHandleNVX&                args) override;

    virtual void Process_vkGetImageViewHandle64NVX(
        const ApiCallInfo&                          call_info,
        args::GetImageViewHandle64NVX&              args) override;

    virtual void Process_vkGetImageViewAddressNVX(
        const ApiCallInfo&                          call_info,
        args::GetImageViewAddressNVX&               args) override;

    virtual void Process_vkGetDeviceCombinedImageSamplerIndexNVX(
        const ApiCallInfo&                          call_info,
        args::GetDeviceCombinedImageSamplerIndexNVX& args) override;

    virtual void Process_vkCmdDrawIndirectCountAMD(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCountAMD&              args) override;

    virtual void Process_vkCmdDrawIndexedIndirectCountAMD(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCountAMD&       args) override;

    virtual void Process_vkGetShaderInfoAMD(
        const ApiCallInfo&                          call_info,
        args::GetShaderInfoAMD&                     args) override;

    virtual void Process_vkCreateStreamDescriptorSurfaceGGP(
        const ApiCallInfo&                          call_info,
        args::CreateStreamDescriptorSurfaceGGP&     args) override;

    virtual void Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalImageFormatPropertiesNV& args) override;

    virtual void Process_vkGetMemoryWin32HandleNV(
        const ApiCallInfo&                          call_info,
        args::GetMemoryWin32HandleNV&               args) override;

    virtual void Process_vkCreateViSurfaceNN(
        const ApiCallInfo&                          call_info,
        args::CreateViSurfaceNN&                    args) override;

    virtual void Process_vkCmdBeginConditionalRenderingEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginConditionalRenderingEXT&      args) override;

    virtual void Process_vkCmdEndConditionalRenderingEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndConditionalRenderingEXT&        args) override;

    virtual void Process_vkCmdSetViewportWScalingNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWScalingNV&             args) override;

    virtual void Process_vkReleaseDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::ReleaseDisplayEXT&                    args) override;

    virtual void Process_vkAcquireXlibDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::AcquireXlibDisplayEXT&                args) override;

    virtual void Process_vkGetRandROutputDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::GetRandROutputDisplayEXT&             args) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceCapabilities2EXT& args) override;

    virtual void Process_vkDisplayPowerControlEXT(
        const ApiCallInfo&                          call_info,
        args::DisplayPowerControlEXT&               args) override;

    virtual void Process_vkRegisterDeviceEventEXT(
        const ApiCallInfo&                          call_info,
        args::RegisterDeviceEventEXT&               args) override;

    virtual void Process_vkRegisterDisplayEventEXT(
        const ApiCallInfo&                          call_info,
        args::RegisterDisplayEventEXT&              args) override;

    virtual void Process_vkGetSwapchainCounterEXT(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainCounterEXT&               args) override;

    virtual void Process_vkGetRefreshCycleDurationGOOGLE(
        const ApiCallInfo&                          call_info,
        args::GetRefreshCycleDurationGOOGLE&        args) override;

    virtual void Process_vkGetPastPresentationTimingGOOGLE(
        const ApiCallInfo&                          call_info,
        args::GetPastPresentationTimingGOOGLE&      args) override;

    virtual void Process_vkCmdSetDiscardRectangleEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDiscardRectangleEXT&            args) override;

    virtual void Process_vkCmdSetDiscardRectangleEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDiscardRectangleEnableEXT&      args) override;

    virtual void Process_vkCmdSetDiscardRectangleModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDiscardRectangleModeEXT&        args) override;

    virtual void Process_vkSetHdrMetadataEXT(
        const ApiCallInfo&                          call_info,
        args::SetHdrMetadataEXT&                    args) override;

    virtual void Process_vkCreateIOSSurfaceMVK(
        const ApiCallInfo&                          call_info,
        args::CreateIOSSurfaceMVK&                  args) override;

    virtual void Process_vkCreateMacOSSurfaceMVK(
        const ApiCallInfo&                          call_info,
        args::CreateMacOSSurfaceMVK&                args) override;

    virtual void Process_vkSetDebugUtilsObjectNameEXT(
        const ApiCallInfo&                          call_info,
        args::SetDebugUtilsObjectNameEXT&           args) override;

    virtual void Process_vkSetDebugUtilsObjectTagEXT(
        const ApiCallInfo&                          call_info,
        args::SetDebugUtilsObjectTagEXT&            args) override;

    virtual void Process_vkQueueBeginDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::QueueBeginDebugUtilsLabelEXT&         args) override;

    virtual void Process_vkQueueEndDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::QueueEndDebugUtilsLabelEXT&           args) override;

    virtual void Process_vkQueueInsertDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::QueueInsertDebugUtilsLabelEXT&        args) override;

    virtual void Process_vkCmdBeginDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginDebugUtilsLabelEXT&           args) override;

    virtual void Process_vkCmdEndDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndDebugUtilsLabelEXT&             args) override;

    virtual void Process_vkCmdInsertDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::CmdInsertDebugUtilsLabelEXT&          args) override;

    virtual void Process_vkCreateDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        args::CreateDebugUtilsMessengerEXT&         args) override;

    virtual void Process_vkDestroyDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyDebugUtilsMessengerEXT&        args) override;

    virtual void Process_vkSubmitDebugUtilsMessageEXT(
        const ApiCallInfo&                          call_info,
        args::SubmitDebugUtilsMessageEXT&           args) override;

    virtual void Process_vkGetAndroidHardwareBufferPropertiesANDROID(
        const ApiCallInfo&                          call_info,
        args::GetAndroidHardwareBufferPropertiesANDROID& args) override;

    virtual void Process_vkGetMemoryAndroidHardwareBufferANDROID(
        const ApiCallInfo&                          call_info,
        args::GetMemoryAndroidHardwareBufferANDROID& args) override;

    virtual void Process_vkCreateGpaSessionAMD(
        const ApiCallInfo&                          call_info,
        args::CreateGpaSessionAMD&                  args) override;

    virtual void Process_vkDestroyGpaSessionAMD(
        const ApiCallInfo&                          call_info,
        args::DestroyGpaSessionAMD&                 args) override;

    virtual void Process_vkSetGpaDeviceClockModeAMD(
        const ApiCallInfo&                          call_info,
        args::SetGpaDeviceClockModeAMD&             args) override;

    virtual void Process_vkGetGpaDeviceClockInfoAMD(
        const ApiCallInfo&                          call_info,
        args::GetGpaDeviceClockInfoAMD&             args) override;

    virtual void Process_vkCmdBeginGpaSessionAMD(
        const ApiCallInfo&                          call_info,
        args::CmdBeginGpaSessionAMD&                args) override;

    virtual void Process_vkCmdEndGpaSessionAMD(
        const ApiCallInfo&                          call_info,
        args::CmdEndGpaSessionAMD&                  args) override;

    virtual void Process_vkCmdBeginGpaSampleAMD(
        const ApiCallInfo&                          call_info,
        args::CmdBeginGpaSampleAMD&                 args) override;

    virtual void Process_vkCmdEndGpaSampleAMD(
        const ApiCallInfo&                          call_info,
        args::CmdEndGpaSampleAMD&                   args) override;

    virtual void Process_vkGetGpaSessionStatusAMD(
        const ApiCallInfo&                          call_info,
        args::GetGpaSessionStatusAMD&               args) override;

    virtual void Process_vkGetGpaSessionResultsAMD(
        const ApiCallInfo&                          call_info,
        args::GetGpaSessionResultsAMD&              args) override;

    virtual void Process_vkResetGpaSessionAMD(
        const ApiCallInfo&                          call_info,
        args::ResetGpaSessionAMD&                   args) override;

    virtual void Process_vkCmdCopyGpaSessionResultsAMD(
        const ApiCallInfo&                          call_info,
        args::CmdCopyGpaSessionResultsAMD&          args) override;

    virtual void Process_vkCmdSetSampleLocationsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetSampleLocationsEXT&             args) override;

    virtual void Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceMultisamplePropertiesEXT& args) override;

    virtual void Process_vkGetImageDrmFormatModifierPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetImageDrmFormatModifierPropertiesEXT& args) override;

    virtual void Process_vkCreateValidationCacheEXT(
        const ApiCallInfo&                          call_info,
        args::CreateValidationCacheEXT&             args) override;

    virtual void Process_vkDestroyValidationCacheEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyValidationCacheEXT&            args) override;

    virtual void Process_vkMergeValidationCachesEXT(
        const ApiCallInfo&                          call_info,
        args::MergeValidationCachesEXT&             args) override;

    virtual void Process_vkGetValidationCacheDataEXT(
        const ApiCallInfo&                          call_info,
        args::GetValidationCacheDataEXT&            args) override;

    virtual void Process_vkCmdBindShadingRateImageNV(
        const ApiCallInfo&                          call_info,
        args::CmdBindShadingRateImageNV&            args) override;

    virtual void Process_vkCmdSetViewportShadingRatePaletteNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportShadingRatePaletteNV&   args) override;

    virtual void Process_vkCmdSetCoarseSampleOrderNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoarseSampleOrderNV&            args) override;

    virtual void Process_vkCreateAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::CreateAccelerationStructureNV&        args) override;

    virtual void Process_vkDestroyAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::DestroyAccelerationStructureNV&       args) override;

    virtual void Process_vkGetAccelerationStructureMemoryRequirementsNV(
        const ApiCallInfo&                          call_info,
        args::GetAccelerationStructureMemoryRequirementsNV& args) override;

    virtual void Process_vkBindAccelerationStructureMemoryNV(
        const ApiCallInfo&                          call_info,
        args::BindAccelerationStructureMemoryNV&    args) override;

    virtual void Process_vkCmdBuildAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::CmdBuildAccelerationStructureNV&      args) override;

    virtual void Process_vkCmdCopyAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::CmdCopyAccelerationStructureNV&       args) override;

    virtual void Process_vkCmdTraceRaysNV(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysNV&                       args) override;

    virtual void Process_vkCreateRayTracingPipelinesNV(
        const ApiCallInfo&                          call_info,
        args::CreateRayTracingPipelinesNV&          args) override;

    virtual void Process_vkGetRayTracingShaderGroupHandlesKHR(
        const ApiCallInfo&                          call_info,
        args::GetRayTracingShaderGroupHandlesKHR&   args) override;

    virtual void Process_vkGetRayTracingShaderGroupHandlesNV(
        const ApiCallInfo&                          call_info,
        args::GetRayTracingShaderGroupHandlesNV&    args) override;

    virtual void Process_vkGetAccelerationStructureHandleNV(
        const ApiCallInfo&                          call_info,
        args::GetAccelerationStructureHandleNV&     args) override;

    virtual void Process_vkCmdWriteAccelerationStructuresPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::CmdWriteAccelerationStructuresPropertiesNV& args) override;

    virtual void Process_vkCompileDeferredNV(
        const ApiCallInfo&                          call_info,
        args::CompileDeferredNV&                    args) override;

    virtual void Process_vkGetMemoryHostPointerPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetMemoryHostPointerPropertiesEXT&    args) override;

    virtual void Process_vkCmdWriteBufferMarkerAMD(
        const ApiCallInfo&                          call_info,
        args::CmdWriteBufferMarkerAMD&              args) override;

    virtual void Process_vkCmdWriteBufferMarker2AMD(
        const ApiCallInfo&                          call_info,
        args::CmdWriteBufferMarker2AMD&             args) override;

    virtual void Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCalibrateableTimeDomainsEXT& args) override;

    virtual void Process_vkGetCalibratedTimestampsEXT(
        const ApiCallInfo&                          call_info,
        args::GetCalibratedTimestampsEXT&           args) override;

    virtual void Process_vkCmdDrawMeshTasksNV(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksNV&                   args) override;

    virtual void Process_vkCmdDrawMeshTasksIndirectNV(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectNV&           args) override;

    virtual void Process_vkCmdDrawMeshTasksIndirectCountNV(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectCountNV&      args) override;

    virtual void Process_vkCmdSetExclusiveScissorEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetExclusiveScissorEnableNV&       args) override;

    virtual void Process_vkCmdSetExclusiveScissorNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetExclusiveScissorNV&             args) override;

    virtual void Process_vkCmdSetCheckpointNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCheckpointNV&                   args) override;

    virtual void Process_vkGetQueueCheckpointDataNV(
        const ApiCallInfo&                          call_info,
        args::GetQueueCheckpointDataNV&             args) override;

    virtual void Process_vkGetQueueCheckpointData2NV(
        const ApiCallInfo&                          call_info,
        args::GetQueueCheckpointData2NV&            args) override;

    virtual void Process_vkSetSwapchainPresentTimingQueueSizeEXT(
        const ApiCallInfo&                          call_info,
        args::SetSwapchainPresentTimingQueueSizeEXT& args) override;

    virtual void Process_vkGetSwapchainTimingPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainTimingPropertiesEXT&      args) override;

    virtual void Process_vkGetSwapchainTimeDomainPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainTimeDomainPropertiesEXT&  args) override;

    virtual void Process_vkGetPastPresentationTimingEXT(
        const ApiCallInfo&                          call_info,
        args::GetPastPresentationTimingEXT&         args) override;

    virtual void Process_vkInitializePerformanceApiINTEL(
        const ApiCallInfo&                          call_info,
        args::InitializePerformanceApiINTEL&        args) override;

    virtual void Process_vkUninitializePerformanceApiINTEL(
        const ApiCallInfo&                          call_info,
        args::UninitializePerformanceApiINTEL&      args) override;

    virtual void Process_vkCmdSetPerformanceMarkerINTEL(
        const ApiCallInfo&                          call_info,
        args::CmdSetPerformanceMarkerINTEL&         args) override;

    virtual void Process_vkCmdSetPerformanceStreamMarkerINTEL(
        const ApiCallInfo&                          call_info,
        args::CmdSetPerformanceStreamMarkerINTEL&   args) override;

    virtual void Process_vkCmdSetPerformanceOverrideINTEL(
        const ApiCallInfo&                          call_info,
        args::CmdSetPerformanceOverrideINTEL&       args) override;

    virtual void Process_vkAcquirePerformanceConfigurationINTEL(
        const ApiCallInfo&                          call_info,
        args::AcquirePerformanceConfigurationINTEL& args) override;

    virtual void Process_vkReleasePerformanceConfigurationINTEL(
        const ApiCallInfo&                          call_info,
        args::ReleasePerformanceConfigurationINTEL& args) override;

    virtual void Process_vkQueueSetPerformanceConfigurationINTEL(
        const ApiCallInfo&                          call_info,
        args::QueueSetPerformanceConfigurationINTEL& args) override;

    virtual void Process_vkGetPerformanceParameterINTEL(
        const ApiCallInfo&                          call_info,
        args::GetPerformanceParameterINTEL&         args) override;

    virtual void Process_vkSetLocalDimmingAMD(
        const ApiCallInfo&                          call_info,
        args::SetLocalDimmingAMD&                   args) override;

    virtual void Process_vkCreateImagePipeSurfaceFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::CreateImagePipeSurfaceFUCHSIA&        args) override;

    virtual void Process_vkCreateMetalSurfaceEXT(
        const ApiCallInfo&                          call_info,
        args::CreateMetalSurfaceEXT&                args) override;

    virtual void Process_vkGetBufferDeviceAddressEXT(
        const ApiCallInfo&                          call_info,
        args::GetBufferDeviceAddressEXT&            args) override;

    virtual void Process_vkGetPhysicalDeviceToolPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceToolPropertiesEXT&   args) override;

    virtual void Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCooperativeMatrixPropertiesNV& args) override;

    virtual void Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV& args) override;

    virtual void Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfacePresentModes2EXT& args) override;

    virtual void Process_vkAcquireFullScreenExclusiveModeEXT(
        const ApiCallInfo&                          call_info,
        args::AcquireFullScreenExclusiveModeEXT&    args) override;

    virtual void Process_vkReleaseFullScreenExclusiveModeEXT(
        const ApiCallInfo&                          call_info,
        args::ReleaseFullScreenExclusiveModeEXT&    args) override;

    virtual void Process_vkGetDeviceGroupSurfacePresentModes2EXT(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupSurfacePresentModes2EXT& args) override;

    virtual void Process_vkCreateHeadlessSurfaceEXT(
        const ApiCallInfo&                          call_info,
        args::CreateHeadlessSurfaceEXT&             args) override;

    virtual void Process_vkCmdSetLineStippleEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStippleEXT&                 args) override;

    virtual void Process_vkResetQueryPoolEXT(
        const ApiCallInfo&                          call_info,
        args::ResetQueryPoolEXT&                    args) override;

    virtual void Process_vkCmdSetCullModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetCullModeEXT&                    args) override;

    virtual void Process_vkCmdSetFrontFaceEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetFrontFaceEXT&                   args) override;

    virtual void Process_vkCmdSetPrimitiveTopologyEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveTopologyEXT&           args) override;

    virtual void Process_vkCmdSetViewportWithCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWithCountEXT&           args) override;

    virtual void Process_vkCmdSetScissorWithCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetScissorWithCountEXT&            args) override;

    virtual void Process_vkCmdBindVertexBuffers2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers2EXT&             args) override;

    virtual void Process_vkCmdSetDepthTestEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthTestEnableEXT&             args) override;

    virtual void Process_vkCmdSetDepthWriteEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthWriteEnableEXT&            args) override;

    virtual void Process_vkCmdSetDepthCompareOpEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthCompareOpEXT&              args) override;

    virtual void Process_vkCmdSetDepthBoundsTestEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBoundsTestEnableEXT&       args) override;

    virtual void Process_vkCmdSetStencilTestEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilTestEnableEXT&           args) override;

    virtual void Process_vkCmdSetStencilOpEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilOpEXT&                   args) override;

    virtual void Process_vkCopyMemoryToImageEXT(
        const ApiCallInfo&                          call_info,
        args::CopyMemoryToImageEXT&                 args) override;

    virtual void Process_vkCopyImageToMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CopyImageToMemoryEXT&                 args) override;

    virtual void Process_vkCopyImageToImageEXT(
        const ApiCallInfo&                          call_info,
        args::CopyImageToImageEXT&                  args) override;

    virtual void Process_vkTransitionImageLayoutEXT(
        const ApiCallInfo&                          call_info,
        args::TransitionImageLayoutEXT&             args) override;

    virtual void Process_vkGetImageSubresourceLayout2EXT(
        const ApiCallInfo&                          call_info,
        args::GetImageSubresourceLayout2EXT&        args) override;

    virtual void Process_vkReleaseSwapchainImagesEXT(
        const ApiCallInfo&                          call_info,
        args::ReleaseSwapchainImagesEXT&            args) override;

    virtual void Process_vkGetGeneratedCommandsMemoryRequirementsNV(
        const ApiCallInfo&                          call_info,
        args::GetGeneratedCommandsMemoryRequirementsNV& args) override;

    virtual void Process_vkCmdPreprocessGeneratedCommandsNV(
        const ApiCallInfo&                          call_info,
        args::CmdPreprocessGeneratedCommandsNV&     args) override;

    virtual void Process_vkCmdExecuteGeneratedCommandsNV(
        const ApiCallInfo&                          call_info,
        args::CmdExecuteGeneratedCommandsNV&        args) override;

    virtual void Process_vkCmdBindPipelineShaderGroupNV(
        const ApiCallInfo&                          call_info,
        args::CmdBindPipelineShaderGroupNV&         args) override;

    virtual void Process_vkCreateIndirectCommandsLayoutNV(
        const ApiCallInfo&                          call_info,
        args::CreateIndirectCommandsLayoutNV&       args) override;

    virtual void Process_vkDestroyIndirectCommandsLayoutNV(
        const ApiCallInfo&                          call_info,
        args::DestroyIndirectCommandsLayoutNV&      args) override;

    virtual void Process_vkCmdSetDepthBias2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBias2EXT&                  args) override;

    virtual void Process_vkAcquireDrmDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::AcquireDrmDisplayEXT&                 args) override;

    virtual void Process_vkGetDrmDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::GetDrmDisplayEXT&                     args) override;

    virtual void Process_vkCreatePrivateDataSlotEXT(
        const ApiCallInfo&                          call_info,
        args::CreatePrivateDataSlotEXT&             args) override;

    virtual void Process_vkDestroyPrivateDataSlotEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyPrivateDataSlotEXT&            args) override;

    virtual void Process_vkSetPrivateDataEXT(
        const ApiCallInfo&                          call_info,
        args::SetPrivateDataEXT&                    args) override;

    virtual void Process_vkGetPrivateDataEXT(
        const ApiCallInfo&                          call_info,
        args::GetPrivateDataEXT&                    args) override;

    virtual void Process_vkQueueSetPerfHintQCOM(
        const ApiCallInfo&                          call_info,
        args::QueueSetPerfHintQCOM&                 args) override;

    virtual void Process_vkCmdDispatchTileQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchTileQCOM&                  args) override;

    virtual void Process_vkCmdBeginPerTileExecutionQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdBeginPerTileExecutionQCOM&         args) override;

    virtual void Process_vkCmdEndPerTileExecutionQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdEndPerTileExecutionQCOM&           args) override;

    virtual void Process_vkGetDescriptorSetLayoutSizeEXT(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutSizeEXT&        args) override;

    virtual void Process_vkGetDescriptorSetLayoutBindingOffsetEXT(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutBindingOffsetEXT& args) override;

    virtual void Process_vkGetDescriptorEXT(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorEXT&                     args) override;

    virtual void Process_vkCmdBindDescriptorBuffersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorBuffersEXT&          args) override;

    virtual void Process_vkCmdSetDescriptorBufferOffsetsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDescriptorBufferOffsetsEXT&     args) override;

    virtual void Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorBufferEmbeddedSamplersEXT& args) override;

    virtual void Process_vkCmdSetFragmentShadingRateEnumNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetFragmentShadingRateEnumNV&      args) override;

    virtual void Process_vkGetDeviceFaultInfoEXT(
        const ApiCallInfo&                          call_info,
        args::GetDeviceFaultInfoEXT&                args) override;

    virtual void Process_vkAcquireWinrtDisplayNV(
        const ApiCallInfo&                          call_info,
        args::AcquireWinrtDisplayNV&                args) override;

    virtual void Process_vkGetWinrtDisplayNV(
        const ApiCallInfo&                          call_info,
        args::GetWinrtDisplayNV&                    args) override;

    virtual void Process_vkCreateDirectFBSurfaceEXT(
        const ApiCallInfo&                          call_info,
        args::CreateDirectFBSurfaceEXT&             args) override;

    virtual void Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDirectFBPresentationSupportEXT& args) override;

    virtual void Process_vkCmdSetVertexInputEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetVertexInputEXT&                 args) override;

    virtual void Process_vkGetMemoryZirconHandleFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::GetMemoryZirconHandleFUCHSIA&         args) override;

    virtual void Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::GetMemoryZirconHandlePropertiesFUCHSIA& args) override;

    virtual void Process_vkImportSemaphoreZirconHandleFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::ImportSemaphoreZirconHandleFUCHSIA&   args) override;

    virtual void Process_vkGetSemaphoreZirconHandleFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreZirconHandleFUCHSIA&      args) override;

    virtual void Process_vkCmdBindInvocationMaskHUAWEI(
        const ApiCallInfo&                          call_info,
        args::CmdBindInvocationMaskHUAWEI&          args) override;

    virtual void Process_vkGetMemoryRemoteAddressNV(
        const ApiCallInfo&                          call_info,
        args::GetMemoryRemoteAddressNV&             args) override;

    virtual void Process_vkCmdSetPatchControlPointsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPatchControlPointsEXT&          args) override;

    virtual void Process_vkCmdSetRasterizerDiscardEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizerDiscardEnableEXT&     args) override;

    virtual void Process_vkCmdSetDepthBiasEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBiasEnableEXT&             args) override;

    virtual void Process_vkCmdSetLogicOpEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLogicOpEXT&                     args) override;

    virtual void Process_vkCmdSetPrimitiveRestartEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveRestartEnableEXT&      args) override;

    virtual void Process_vkCreateScreenSurfaceQNX(
        const ApiCallInfo&                          call_info,
        args::CreateScreenSurfaceQNX&               args) override;

    virtual void Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceScreenPresentationSupportQNX& args) override;

    virtual void Process_vkCmdSetColorWriteEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorWriteEnableEXT&            args) override;

    virtual void Process_vkCmdDrawMultiEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMultiEXT&                      args) override;

    virtual void Process_vkCmdDrawMultiIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMultiIndexedEXT&               args) override;

    virtual void Process_vkCreateMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CreateMicromapEXT&                    args) override;

    virtual void Process_vkDestroyMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyMicromapEXT&                   args) override;

    virtual void Process_vkCmdBuildMicromapsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBuildMicromapsEXT&                 args) override;

    virtual void Process_vkBuildMicromapsEXT(
        const ApiCallInfo&                          call_info,
        args::BuildMicromapsEXT&                    args) override;

    virtual void Process_vkCopyMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CopyMicromapEXT&                      args) override;

    virtual void Process_vkCopyMicromapToMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CopyMicromapToMemoryEXT&              args) override;

    virtual void Process_vkCopyMemoryToMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CopyMemoryToMicromapEXT&              args) override;

    virtual void Process_vkWriteMicromapsPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::WriteMicromapsPropertiesEXT&          args) override;

    virtual void Process_vkCmdCopyMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMicromapEXT&                   args) override;

    virtual void Process_vkCmdCopyMicromapToMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMicromapToMemoryEXT&           args) override;

    virtual void Process_vkCmdCopyMemoryToMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToMicromapEXT&           args) override;

    virtual void Process_vkCmdWriteMicromapsPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::CmdWriteMicromapsPropertiesEXT&       args) override;

    virtual void Process_vkGetDeviceMicromapCompatibilityEXT(
        const ApiCallInfo&                          call_info,
        args::GetDeviceMicromapCompatibilityEXT&    args) override;

    virtual void Process_vkGetMicromapBuildSizesEXT(
        const ApiCallInfo&                          call_info,
        args::GetMicromapBuildSizesEXT&             args) override;

    virtual void Process_vkCmdDrawClusterHUAWEI(
        const ApiCallInfo&                          call_info,
        args::CmdDrawClusterHUAWEI&                 args) override;

    virtual void Process_vkCmdDrawClusterIndirectHUAWEI(
        const ApiCallInfo&                          call_info,
        args::CmdDrawClusterIndirectHUAWEI&         args) override;

    virtual void Process_vkSetDeviceMemoryPriorityEXT(
        const ApiCallInfo&                          call_info,
        args::SetDeviceMemoryPriorityEXT&           args) override;

    virtual void Process_vkCmdSetDispatchParametersARM(
        const ApiCallInfo&                          call_info,
        args::CmdSetDispatchParametersARM&          args) override;

    virtual void Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutHostMappingInfoVALVE& args) override;

    virtual void Process_vkGetDescriptorSetHostMappingVALVE(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetHostMappingVALVE&     args) override;

    virtual void Process_vkGetPipelineIndirectMemoryRequirementsNV(
        const ApiCallInfo&                          call_info,
        args::GetPipelineIndirectMemoryRequirementsNV& args) override;

    virtual void Process_vkCmdUpdatePipelineIndirectBufferNV(
        const ApiCallInfo&                          call_info,
        args::CmdUpdatePipelineIndirectBufferNV&    args) override;

    virtual void Process_vkGetPipelineIndirectDeviceAddressNV(
        const ApiCallInfo&                          call_info,
        args::GetPipelineIndirectDeviceAddressNV&   args) override;

    virtual void Process_vkCmdSetDepthClampEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClampEnableEXT&            args) override;

    virtual void Process_vkCmdSetPolygonModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPolygonModeEXT&                 args) override;

    virtual void Process_vkCmdSetRasterizationSamplesEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizationSamplesEXT&        args) override;

    virtual void Process_vkCmdSetSampleMaskEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetSampleMaskEXT&                  args) override;

    virtual void Process_vkCmdSetAlphaToCoverageEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetAlphaToCoverageEnableEXT&       args) override;

    virtual void Process_vkCmdSetAlphaToOneEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetAlphaToOneEnableEXT&            args) override;

    virtual void Process_vkCmdSetLogicOpEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLogicOpEnableEXT&               args) override;

    virtual void Process_vkCmdSetColorBlendEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorBlendEnableEXT&            args) override;

    virtual void Process_vkCmdSetColorBlendEquationEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorBlendEquationEXT&          args) override;

    virtual void Process_vkCmdSetColorWriteMaskEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorWriteMaskEXT&              args) override;

    virtual void Process_vkCmdSetTessellationDomainOriginEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetTessellationDomainOriginEXT&    args) override;

    virtual void Process_vkCmdSetRasterizationStreamEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizationStreamEXT&         args) override;

    virtual void Process_vkCmdSetConservativeRasterizationModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetConservativeRasterizationModeEXT& args) override;

    virtual void Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetExtraPrimitiveOverestimationSizeEXT& args) override;

    virtual void Process_vkCmdSetDepthClipEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClipEnableEXT&             args) override;

    virtual void Process_vkCmdSetSampleLocationsEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetSampleLocationsEnableEXT&       args) override;

    virtual void Process_vkCmdSetColorBlendAdvancedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorBlendAdvancedEXT&          args) override;

    virtual void Process_vkCmdSetProvokingVertexModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetProvokingVertexModeEXT&         args) override;

    virtual void Process_vkCmdSetLineRasterizationModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineRasterizationModeEXT&       args) override;

    virtual void Process_vkCmdSetLineStippleEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStippleEnableEXT&           args) override;

    virtual void Process_vkCmdSetDepthClipNegativeOneToOneEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClipNegativeOneToOneEXT&   args) override;

    virtual void Process_vkCmdSetViewportWScalingEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWScalingEnableNV&       args) override;

    virtual void Process_vkCmdSetViewportSwizzleNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportSwizzleNV&              args) override;

    virtual void Process_vkCmdSetCoverageToColorEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageToColorEnableNV&        args) override;

    virtual void Process_vkCmdSetCoverageToColorLocationNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageToColorLocationNV&      args) override;

    virtual void Process_vkCmdSetCoverageModulationModeNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageModulationModeNV&       args) override;

    virtual void Process_vkCmdSetCoverageModulationTableEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageModulationTableEnableNV& args) override;

    virtual void Process_vkCmdSetCoverageModulationTableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageModulationTableNV&      args) override;

    virtual void Process_vkCmdSetShadingRateImageEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetShadingRateImageEnableNV&       args) override;

    virtual void Process_vkCmdSetRepresentativeFragmentTestEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetRepresentativeFragmentTestEnableNV& args) override;

    virtual void Process_vkCmdSetCoverageReductionModeNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageReductionModeNV&        args) override;

    virtual void Process_vkCreateTensorARM(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkTensorCreateInfoARM>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkTensorARM>*          pTensor) override;

    virtual void Process_vkDestroyTensorARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            tensor,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateTensorViewARM(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkTensorViewCreateInfoARM>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkTensorViewARM>*      pView) override;

    virtual void Process_vkDestroyTensorViewARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            tensorView,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetTensorMemoryRequirementsARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkTensorMemoryRequirementsInfoARM>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) override;

    virtual void Process_vkBindTensorMemoryARM(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindTensorMemoryInfoARM>* pBindInfos) override;

    virtual void Process_vkGetDeviceTensorMemoryRequirementsARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceTensorMemoryRequirementsARM>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) override;

    virtual void Process_vkCmdCopyTensorARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyTensorInfoARM>* pCopyTensorInfo) override;

    virtual void Process_vkGetPhysicalDeviceExternalTensorPropertiesARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalTensorInfoARM>* pExternalTensorInfo,
        StructPointerDecoder<Decoded_VkExternalTensorPropertiesARM>* pExternalTensorProperties) override;

    virtual void Process_vkGetShaderModuleIdentifierEXT(
        const ApiCallInfo&                          call_info,
        args::GetShaderModuleIdentifierEXT&         args) override;

    virtual void Process_vkGetShaderModuleCreateInfoIdentifierEXT(
        const ApiCallInfo&                          call_info,
        args::GetShaderModuleCreateInfoIdentifierEXT& args) override;

    virtual void Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceOpticalFlowImageFormatsNV& args) override;

    virtual void Process_vkCreateOpticalFlowSessionNV(
        const ApiCallInfo&                          call_info,
        args::CreateOpticalFlowSessionNV&           args) override;

    virtual void Process_vkDestroyOpticalFlowSessionNV(
        const ApiCallInfo&                          call_info,
        args::DestroyOpticalFlowSessionNV&          args) override;

    virtual void Process_vkBindOpticalFlowSessionImageNV(
        const ApiCallInfo&                          call_info,
        args::BindOpticalFlowSessionImageNV&        args) override;

    virtual void Process_vkCmdOpticalFlowExecuteNV(
        const ApiCallInfo&                          call_info,
        args::CmdOpticalFlowExecuteNV&              args) override;

    virtual void Process_vkAntiLagUpdateAMD(
        const ApiCallInfo&                          call_info,
        args::AntiLagUpdateAMD&                     args) override;

    virtual void Process_vkCreateShadersEXT(
        const ApiCallInfo&                          call_info,
        args::CreateShadersEXT&                     args) override;

    virtual void Process_vkDestroyShaderEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyShaderEXT&                     args) override;

    virtual void Process_vkGetShaderBinaryDataEXT(
        const ApiCallInfo&                          call_info,
        args::GetShaderBinaryDataEXT&               args) override;

    virtual void Process_vkCmdBindShadersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindShadersEXT&                    args) override;

    virtual void Process_vkCmdSetDepthClampRangeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClampRangeEXT&             args) override;

    virtual void Process_vkGetFramebufferTilePropertiesQCOM(
        const ApiCallInfo&                          call_info,
        args::GetFramebufferTilePropertiesQCOM&     args) override;

    virtual void Process_vkGetDynamicRenderingTilePropertiesQCOM(
        const ApiCallInfo&                          call_info,
        args::GetDynamicRenderingTilePropertiesQCOM& args) override;

    virtual void Process_vkGetPhysicalDeviceCooperativeVectorPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCooperativeVectorPropertiesNV& args) override;

    virtual void Process_vkConvertCooperativeVectorMatrixNV(
        const ApiCallInfo&                          call_info,
        args::ConvertCooperativeVectorMatrixNV&     args) override;

    virtual void Process_vkCmdConvertCooperativeVectorMatrixNV(
        const ApiCallInfo&                          call_info,
        args::CmdConvertCooperativeVectorMatrixNV&  args) override;

    virtual void Process_vkSetLatencySleepModeNV(
        const ApiCallInfo&                          call_info,
        args::SetLatencySleepModeNV&                args) override;

    virtual void Process_vkLatencySleepNV(
        const ApiCallInfo&                          call_info,
        args::LatencySleepNV&                       args) override;

    virtual void Process_vkSetLatencyMarkerNV(
        const ApiCallInfo&                          call_info,
        args::SetLatencyMarkerNV&                   args) override;

    virtual void Process_vkGetLatencyTimingsNV(
        const ApiCallInfo&                          call_info,
        args::GetLatencyTimingsNV&                  args) override;

    virtual void Process_vkQueueNotifyOutOfBandNV(
        const ApiCallInfo&                          call_info,
        args::QueueNotifyOutOfBandNV&               args) override;

    virtual void Process_vkCreateDataGraphPipelinesARM(
        const ApiCallInfo&                          call_info,
        args::CreateDataGraphPipelinesARM&          args) override;

    virtual void Process_vkCreateDataGraphPipelineSessionARM(
        const ApiCallInfo&                          call_info,
        args::CreateDataGraphPipelineSessionARM&    args) override;

    virtual void Process_vkGetDataGraphPipelineSessionBindPointRequirementsARM(
        const ApiCallInfo&                          call_info,
        args::GetDataGraphPipelineSessionBindPointRequirementsARM& args) override;

    virtual void Process_vkGetDataGraphPipelineSessionMemoryRequirementsARM(
        const ApiCallInfo&                          call_info,
        args::GetDataGraphPipelineSessionMemoryRequirementsARM& args) override;

    virtual void Process_vkBindDataGraphPipelineSessionMemoryARM(
        const ApiCallInfo&                          call_info,
        args::BindDataGraphPipelineSessionMemoryARM& args) override;

    virtual void Process_vkDestroyDataGraphPipelineSessionARM(
        const ApiCallInfo&                          call_info,
        args::DestroyDataGraphPipelineSessionARM&   args) override;

    virtual void Process_vkCmdDispatchDataGraphARM(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchDataGraphARM&              args) override;

    virtual void Process_vkGetDataGraphPipelineAvailablePropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetDataGraphPipelineAvailablePropertiesARM& args) override;

    virtual void Process_vkGetDataGraphPipelinePropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetDataGraphPipelinePropertiesARM&    args) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM& args) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM& args) override;

    virtual void Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetAttachmentFeedbackLoopEnableEXT& args) override;

    virtual void Process_vkCmdBindTileMemoryQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdBindTileMemoryQCOM&                args) override;

    virtual void Process_vkCmdDecompressMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDecompressMemoryEXT&               args) override;

    virtual void Process_vkCmdDecompressMemoryIndirectCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDecompressMemoryIndirectCountEXT&  args) override;

    virtual void Process_vkGetPartitionedAccelerationStructuresBuildSizesNV(
        const ApiCallInfo&                          call_info,
        args::GetPartitionedAccelerationStructuresBuildSizesNV& args) override;

    virtual void Process_vkCmdBuildPartitionedAccelerationStructuresNV(
        const ApiCallInfo&                          call_info,
        args::CmdBuildPartitionedAccelerationStructuresNV& args) override;

    virtual void Process_vkGetGeneratedCommandsMemoryRequirementsEXT(
        const ApiCallInfo&                          call_info,
        args::GetGeneratedCommandsMemoryRequirementsEXT& args) override;

    virtual void Process_vkCmdPreprocessGeneratedCommandsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdPreprocessGeneratedCommandsEXT&    args) override;

    virtual void Process_vkCmdExecuteGeneratedCommandsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdExecuteGeneratedCommandsEXT&       args) override;

    virtual void Process_vkCreateIndirectCommandsLayoutEXT(
        const ApiCallInfo&                          call_info,
        args::CreateIndirectCommandsLayoutEXT&      args) override;

    virtual void Process_vkDestroyIndirectCommandsLayoutEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyIndirectCommandsLayoutEXT&     args) override;

    virtual void Process_vkCreateIndirectExecutionSetEXT(
        const ApiCallInfo&                          call_info,
        args::CreateIndirectExecutionSetEXT&        args) override;

    virtual void Process_vkDestroyIndirectExecutionSetEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyIndirectExecutionSetEXT&       args) override;

    virtual void Process_vkUpdateIndirectExecutionSetPipelineEXT(
        const ApiCallInfo&                          call_info,
        args::UpdateIndirectExecutionSetPipelineEXT& args) override;

    virtual void Process_vkUpdateIndirectExecutionSetShaderEXT(
        const ApiCallInfo&                          call_info,
        args::UpdateIndirectExecutionSetShaderEXT&  args) override;

    virtual void Process_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV& args) override;

    virtual void Process_vkGetMemoryMetalHandleEXT(
        const ApiCallInfo&                          call_info,
        args::GetMemoryMetalHandleEXT&              args) override;

    virtual void Process_vkGetMemoryMetalHandlePropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetMemoryMetalHandlePropertiesEXT&    args) override;

    virtual void Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM& args) override;

    virtual void Process_vkCmdEndRendering2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndRendering2EXT&                  args) override;

    virtual void Process_vkCmdBeginCustomResolveEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginCustomResolveEXT&             args) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        StructPointerDecoder<Decoded_VkQueueFamilyDataGraphPropertiesARM>* pQueueFamilyDataGraphProperties,
        StructPointerDecoder<Decoded_VkDataGraphOpticalFlowImageFormatInfoARM>* pOpticalFlowImageFormatInfo,
        PointerDecoder<uint32_t>*                   pFormatCount,
        StructPointerDecoder<Decoded_VkDataGraphOpticalFlowImageFormatPropertiesARM>* pImageFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        StructPointerDecoder<Decoded_VkQueueFamilyDataGraphPropertiesARM>* pQueueFamilyDataGraphProperties,
        StructPointerDecoder<Decoded_VkBaseOutStructure>* pProperties) override;

    virtual void Process_vkCmdSetComputeOccupancyPriorityNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetComputeOccupancyPriorityNV&     args) override;

    virtual void Process_vkCmdSetPrimitiveRestartIndexEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveRestartIndexEXT&       args) override;

    virtual void Process_vkCreateAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CreateAccelerationStructureKHR&       args) override;

    virtual void Process_vkDestroyAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyAccelerationStructureKHR&      args) override;

    virtual void Process_vkCmdBuildAccelerationStructuresKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBuildAccelerationStructuresKHR&    args) override;

    virtual void Process_vkCmdBuildAccelerationStructuresIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBuildAccelerationStructuresIndirectKHR& args) override;

    virtual void Process_vkCopyAccelerationStructureToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CopyAccelerationStructureToMemoryKHR& args) override;

    virtual void Process_vkCopyMemoryToAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CopyMemoryToAccelerationStructureKHR& args) override;

    virtual void Process_vkWriteAccelerationStructuresPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::WriteAccelerationStructuresPropertiesKHR& args) override;

    virtual void Process_vkCmdCopyAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyAccelerationStructureKHR&      args) override;

    virtual void Process_vkCmdCopyAccelerationStructureToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyAccelerationStructureToMemoryKHR& args) override;

    virtual void Process_vkCmdCopyMemoryToAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToAccelerationStructureKHR& args) override;

    virtual void Process_vkGetAccelerationStructureDeviceAddressKHR(
        const ApiCallInfo&                          call_info,
        args::GetAccelerationStructureDeviceAddressKHR& args) override;

    virtual void Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::CmdWriteAccelerationStructuresPropertiesKHR& args) override;

    virtual void Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceAccelerationStructureCompatibilityKHR& args) override;

    virtual void Process_vkGetAccelerationStructureBuildSizesKHR(
        const ApiCallInfo&                          call_info,
        args::GetAccelerationStructureBuildSizesKHR& args) override;

    virtual void Process_vkCmdTraceRaysKHR(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysKHR&                      args) override;

    virtual void Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
        const ApiCallInfo&                          call_info,
        args::GetRayTracingCaptureReplayShaderGroupHandlesKHR& args) override;

    virtual void Process_vkCmdTraceRaysIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysIndirectKHR&              args) override;

    virtual void Process_vkGetRayTracingShaderGroupStackSizeKHR(
        const ApiCallInfo&                          call_info,
        args::GetRayTracingShaderGroupStackSizeKHR& args) override;

    virtual void Process_vkCmdSetRayTracingPipelineStackSizeKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetRayTracingPipelineStackSizeKHR& args) override;

    virtual void Process_vkCmdDrawMeshTasksEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksEXT&                  args) override;

    virtual void Process_vkCmdDrawMeshTasksIndirectEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectEXT&          args) override;

    virtual void Process_vkCmdDrawMeshTasksIndirectCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectCountEXT&     args) override;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_REPLAY_CONSUMER_H
