/*
** Copyright (c) 2026 Arm Limited <open-source-office@arm.com>
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

#ifndef  GFXRECON_GENERATED_VULKAN_NATIVE_CALL_CONSUMER_H
#define  GFXRECON_GENERATED_VULKAN_NATIVE_CALL_CONSUMER_H

#include "decode/vulkan_native_call_consumer_base.h"
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
class VulkanNativeCallConsumer : public VulkanNativeCallConsumerBase
{
  public:
    explicit VulkanNativeCallConsumer(VulkanNativeCallCallbacks& callbacks) :
        VulkanNativeCallConsumerBase(callbacks)
    {}
    ~VulkanNativeCallConsumer() override = default;

    void Process_vkAllocateCommandBuffers(
        const ApiCallInfo&                          call_info,
        args::AllocateCommandBuffers&               args) override;

    void Process_vkAllocateDescriptorSets(
        const ApiCallInfo&                          call_info,
        args::AllocateDescriptorSets&               args) override;

    void Process_vkAllocateMemory(
        const ApiCallInfo&                          call_info,
        args::AllocateMemory&                       args) override;

    void Process_vkBeginCommandBuffer(
        const ApiCallInfo&                          call_info,
        args::BeginCommandBuffer&                   args) override;

    void Process_vkBindBufferMemory(
        const ApiCallInfo&                          call_info,
        args::BindBufferMemory&                     args) override;

    void Process_vkBindImageMemory(
        const ApiCallInfo&                          call_info,
        args::BindImageMemory&                      args) override;

    void Process_vkCmdBeginQuery(
        const ApiCallInfo&                          call_info,
        args::CmdBeginQuery&                        args) override;

    void Process_vkCmdBeginRenderPass(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderPass&                   args) override;

    void Process_vkCmdBindDescriptorSets(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorSets&                args) override;

    void Process_vkCmdBindIndexBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer&                   args) override;

    void Process_vkCmdBindPipeline(
        const ApiCallInfo&                          call_info,
        args::CmdBindPipeline&                      args) override;

    void Process_vkCmdBindVertexBuffers(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers&                 args) override;

    void Process_vkCmdBlitImage(
        const ApiCallInfo&                          call_info,
        args::CmdBlitImage&                         args) override;

    void Process_vkCmdClearAttachments(
        const ApiCallInfo&                          call_info,
        args::CmdClearAttachments&                  args) override;

    void Process_vkCmdClearColorImage(
        const ApiCallInfo&                          call_info,
        args::CmdClearColorImage&                   args) override;

    void Process_vkCmdClearDepthStencilImage(
        const ApiCallInfo&                          call_info,
        args::CmdClearDepthStencilImage&            args) override;

    void Process_vkCmdCopyBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBuffer&                        args) override;

    void Process_vkCmdCopyBufferToImage(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBufferToImage&                 args) override;

    void Process_vkCmdCopyImage(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImage&                         args) override;

    void Process_vkCmdCopyImageToBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToBuffer&                 args) override;

    void Process_vkCmdCopyQueryPoolResults(
        const ApiCallInfo&                          call_info,
        args::CmdCopyQueryPoolResults&              args) override;

    void Process_vkCmdDispatch(
        const ApiCallInfo&                          call_info,
        args::CmdDispatch&                          args) override;

    void Process_vkCmdDispatchIndirect(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchIndirect&                  args) override;

    void Process_vkCmdDraw(
        const ApiCallInfo&                          call_info,
        args::CmdDraw&                              args) override;

    void Process_vkCmdDrawIndexed(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexed&                       args) override;

    void Process_vkCmdDrawIndexedIndirect(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirect&               args) override;

    void Process_vkCmdDrawIndirect(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirect&                      args) override;

    void Process_vkCmdEndQuery(
        const ApiCallInfo&                          call_info,
        args::CmdEndQuery&                          args) override;

    void Process_vkCmdEndRenderPass(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderPass&                     args) override;

    void Process_vkCmdExecuteCommands(
        const ApiCallInfo&                          call_info,
        args::CmdExecuteCommands&                   args) override;

    void Process_vkCmdFillBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdFillBuffer&                        args) override;

    void Process_vkCmdNextSubpass(
        const ApiCallInfo&                          call_info,
        args::CmdNextSubpass&                       args) override;

    void Process_vkCmdPipelineBarrier(
        const ApiCallInfo&                          call_info,
        args::CmdPipelineBarrier&                   args) override;

    void Process_vkCmdPushConstants(
        const ApiCallInfo&                          call_info,
        args::CmdPushConstants&                     args) override;

    void Process_vkCmdResetEvent(
        const ApiCallInfo&                          call_info,
        args::CmdResetEvent&                        args) override;

    void Process_vkCmdResetQueryPool(
        const ApiCallInfo&                          call_info,
        args::CmdResetQueryPool&                    args) override;

    void Process_vkCmdResolveImage(
        const ApiCallInfo&                          call_info,
        args::CmdResolveImage&                      args) override;

    void Process_vkCmdSetBlendConstants(
        const ApiCallInfo&                          call_info,
        args::CmdSetBlendConstants&                 args) override;

    void Process_vkCmdSetDepthBias(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBias&                      args) override;

    void Process_vkCmdSetDepthBounds(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBounds&                    args) override;

    void Process_vkCmdSetEvent(
        const ApiCallInfo&                          call_info,
        args::CmdSetEvent&                          args) override;

    void Process_vkCmdSetLineWidth(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineWidth&                      args) override;

    void Process_vkCmdSetScissor(
        const ApiCallInfo&                          call_info,
        args::CmdSetScissor&                        args) override;

    void Process_vkCmdSetStencilCompareMask(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilCompareMask&             args) override;

    void Process_vkCmdSetStencilReference(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilReference&               args) override;

    void Process_vkCmdSetStencilWriteMask(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilWriteMask&               args) override;

    void Process_vkCmdSetViewport(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewport&                       args) override;

    void Process_vkCmdUpdateBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdUpdateBuffer&                      args) override;

    void Process_vkCmdWaitEvents(
        const ApiCallInfo&                          call_info,
        args::CmdWaitEvents&                        args) override;

    void Process_vkCmdWriteTimestamp(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp&                    args) override;

    void Process_vkCreateBuffer(
        const ApiCallInfo&                          call_info,
        args::CreateBuffer&                         args) override;

    void Process_vkCreateBufferView(
        const ApiCallInfo&                          call_info,
        args::CreateBufferView&                     args) override;

    void Process_vkCreateCommandPool(
        const ApiCallInfo&                          call_info,
        args::CreateCommandPool&                    args) override;

    void Process_vkCreateComputePipelines(
        const ApiCallInfo&                          call_info,
        args::CreateComputePipelines&               args) override;

    void Process_vkCreateDescriptorPool(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorPool&                 args) override;

    void Process_vkCreateDescriptorSetLayout(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorSetLayout&            args) override;

    void Process_vkCreateDevice(
        const ApiCallInfo&                          call_info,
        args::CreateDevice&                         args) override;

    void Process_vkCreateEvent(
        const ApiCallInfo&                          call_info,
        args::CreateEvent&                          args) override;

    void Process_vkCreateFence(
        const ApiCallInfo&                          call_info,
        args::CreateFence&                          args) override;

    void Process_vkCreateFramebuffer(
        const ApiCallInfo&                          call_info,
        args::CreateFramebuffer&                    args) override;

    void Process_vkCreateGraphicsPipelines(
        const ApiCallInfo&                          call_info,
        args::CreateGraphicsPipelines&              args) override;

    void Process_vkCreateImage(
        const ApiCallInfo&                          call_info,
        args::CreateImage&                          args) override;

    void Process_vkCreateImageView(
        const ApiCallInfo&                          call_info,
        args::CreateImageView&                      args) override;

    void Process_vkCreateInstance(
        const ApiCallInfo&                          call_info,
        args::CreateInstance&                       args) override;

    void Process_vkCreatePipelineCache(
        const ApiCallInfo&                          call_info,
        args::CreatePipelineCache&                  args) override;

    void Process_vkCreatePipelineLayout(
        const ApiCallInfo&                          call_info,
        args::CreatePipelineLayout&                 args) override;

    void Process_vkCreateQueryPool(
        const ApiCallInfo&                          call_info,
        args::CreateQueryPool&                      args) override;

    void Process_vkCreateRenderPass(
        const ApiCallInfo&                          call_info,
        args::CreateRenderPass&                     args) override;

    void Process_vkCreateSampler(
        const ApiCallInfo&                          call_info,
        args::CreateSampler&                        args) override;

    void Process_vkCreateSemaphore(
        const ApiCallInfo&                          call_info,
        args::CreateSemaphore&                      args) override;

    void Process_vkCreateShaderModule(
        const ApiCallInfo&                          call_info,
        args::CreateShaderModule&                   args) override;

    void Process_vkDestroyBuffer(
        const ApiCallInfo&                          call_info,
        args::DestroyBuffer&                        args) override;

    void Process_vkDestroyBufferView(
        const ApiCallInfo&                          call_info,
        args::DestroyBufferView&                    args) override;

    void Process_vkDestroyCommandPool(
        const ApiCallInfo&                          call_info,
        args::DestroyCommandPool&                   args) override;

    void Process_vkDestroyDescriptorPool(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorPool&                args) override;

    void Process_vkDestroyDescriptorSetLayout(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorSetLayout&           args) override;

    void Process_vkDestroyDevice(
        const ApiCallInfo&                          call_info,
        args::DestroyDevice&                        args) override;

    void Process_vkDestroyEvent(
        const ApiCallInfo&                          call_info,
        args::DestroyEvent&                         args) override;

    void Process_vkDestroyFence(
        const ApiCallInfo&                          call_info,
        args::DestroyFence&                         args) override;

    void Process_vkDestroyFramebuffer(
        const ApiCallInfo&                          call_info,
        args::DestroyFramebuffer&                   args) override;

    void Process_vkDestroyImage(
        const ApiCallInfo&                          call_info,
        args::DestroyImage&                         args) override;

    void Process_vkDestroyImageView(
        const ApiCallInfo&                          call_info,
        args::DestroyImageView&                     args) override;

    void Process_vkDestroyInstance(
        const ApiCallInfo&                          call_info,
        args::DestroyInstance&                      args) override;

    void Process_vkDestroyPipeline(
        const ApiCallInfo&                          call_info,
        args::DestroyPipeline&                      args) override;

    void Process_vkDestroyPipelineCache(
        const ApiCallInfo&                          call_info,
        args::DestroyPipelineCache&                 args) override;

    void Process_vkDestroyPipelineLayout(
        const ApiCallInfo&                          call_info,
        args::DestroyPipelineLayout&                args) override;

    void Process_vkDestroyQueryPool(
        const ApiCallInfo&                          call_info,
        args::DestroyQueryPool&                     args) override;

    void Process_vkDestroyRenderPass(
        const ApiCallInfo&                          call_info,
        args::DestroyRenderPass&                    args) override;

    void Process_vkDestroySampler(
        const ApiCallInfo&                          call_info,
        args::DestroySampler&                       args) override;

    void Process_vkDestroySemaphore(
        const ApiCallInfo&                          call_info,
        args::DestroySemaphore&                     args) override;

    void Process_vkDestroyShaderModule(
        const ApiCallInfo&                          call_info,
        args::DestroyShaderModule&                  args) override;

    void Process_vkDeviceWaitIdle(
        const ApiCallInfo&                          call_info,
        args::DeviceWaitIdle&                       args) override;

    void Process_vkEndCommandBuffer(
        const ApiCallInfo&                          call_info,
        args::EndCommandBuffer&                     args) override;

    void Process_vkEnumeratePhysicalDevices(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDevices&             args) override;

    void Process_vkFlushMappedMemoryRanges(
        const ApiCallInfo&                          call_info,
        args::FlushMappedMemoryRanges&              args) override;

    void Process_vkFreeCommandBuffers(
        const ApiCallInfo&                          call_info,
        args::FreeCommandBuffers&                   args) override;

    void Process_vkFreeDescriptorSets(
        const ApiCallInfo&                          call_info,
        args::FreeDescriptorSets&                   args) override;

    void Process_vkFreeMemory(
        const ApiCallInfo&                          call_info,
        args::FreeMemory&                           args) override;

    void Process_vkGetBufferMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetBufferMemoryRequirements&          args) override;

    void Process_vkGetDeviceMemoryCommitment(
        const ApiCallInfo&                          call_info,
        args::GetDeviceMemoryCommitment&            args) override;

    void Process_vkGetDeviceQueue(
        const ApiCallInfo&                          call_info,
        args::GetDeviceQueue&                       args) override;

    void Process_vkGetEventStatus(
        const ApiCallInfo&                          call_info,
        args::GetEventStatus&                       args) override;

    void Process_vkGetFenceStatus(
        const ApiCallInfo&                          call_info,
        args::GetFenceStatus&                       args) override;

    void Process_vkGetImageMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetImageMemoryRequirements&           args) override;

    void Process_vkGetImageSparseMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetImageSparseMemoryRequirements&     args) override;

    void Process_vkGetImageSubresourceLayout(
        const ApiCallInfo&                          call_info,
        args::GetImageSubresourceLayout&            args) override;

    void Process_vkGetPhysicalDeviceFeatures(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFeatures&            args) override;

    void Process_vkGetPhysicalDeviceFormatProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFormatProperties&    args) override;

    void Process_vkGetPhysicalDeviceImageFormatProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceImageFormatProperties& args) override;

    void Process_vkGetPhysicalDeviceMemoryProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceMemoryProperties&    args) override;

    void Process_vkGetPhysicalDeviceProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceProperties&          args) override;

    void Process_vkGetPhysicalDeviceQueueFamilyProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyProperties& args) override;

    void Process_vkGetPhysicalDeviceSparseImageFormatProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSparseImageFormatProperties& args) override;

    void Process_vkGetPipelineCacheData(
        const ApiCallInfo&                          call_info,
        args::GetPipelineCacheData&                 args) override;

    void Process_vkGetQueryPoolResults(
        const ApiCallInfo&                          call_info,
        args::GetQueryPoolResults&                  args) override;

    void Process_vkGetRenderAreaGranularity(
        const ApiCallInfo&                          call_info,
        args::GetRenderAreaGranularity&             args) override;

    void Process_vkInvalidateMappedMemoryRanges(
        const ApiCallInfo&                          call_info,
        args::InvalidateMappedMemoryRanges&         args) override;

    void Process_vkMapMemory(
        const ApiCallInfo&                          call_info,
        args::MapMemory&                            args) override;

    void Process_vkMergePipelineCaches(
        const ApiCallInfo&                          call_info,
        args::MergePipelineCaches&                  args) override;

    void Process_vkQueueBindSparse(
        const ApiCallInfo&                          call_info,
        args::QueueBindSparse&                      args) override;

    void Process_vkQueueSubmit(
        const ApiCallInfo&                          call_info,
        args::QueueSubmit&                          args) override;

    void Process_vkQueueWaitIdle(
        const ApiCallInfo&                          call_info,
        args::QueueWaitIdle&                        args) override;

    void Process_vkResetCommandBuffer(
        const ApiCallInfo&                          call_info,
        args::ResetCommandBuffer&                   args) override;

    void Process_vkResetCommandPool(
        const ApiCallInfo&                          call_info,
        args::ResetCommandPool&                     args) override;

    void Process_vkResetDescriptorPool(
        const ApiCallInfo&                          call_info,
        args::ResetDescriptorPool&                  args) override;

    void Process_vkResetEvent(
        const ApiCallInfo&                          call_info,
        args::ResetEvent&                           args) override;

    void Process_vkResetFences(
        const ApiCallInfo&                          call_info,
        args::ResetFences&                          args) override;

    void Process_vkSetEvent(
        const ApiCallInfo&                          call_info,
        args::SetEvent&                             args) override;

    void Process_vkUnmapMemory(
        const ApiCallInfo&                          call_info,
        args::UnmapMemory&                          args) override;

    void Process_vkUpdateDescriptorSets(
        const ApiCallInfo&                          call_info,
        args::UpdateDescriptorSets&                 args) override;

    void Process_vkWaitForFences(
        const ApiCallInfo&                          call_info,
        args::WaitForFences&                        args) override;

    void Process_vkUpdateDescriptorSetWithTemplate(
        const ApiCallInfo&               call_info,
        args::UpdateDescriptorSetWithTemplate& args) override;

    void Process_vkBindBufferMemory2(
        const ApiCallInfo&                          call_info,
        args::BindBufferMemory2&                    args) override;

    void Process_vkBindImageMemory2(
        const ApiCallInfo&                          call_info,
        args::BindImageMemory2&                     args) override;

    void Process_vkCmdDispatchBase(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchBase&                      args) override;

    void Process_vkCmdSetDeviceMask(
        const ApiCallInfo&                          call_info,
        args::CmdSetDeviceMask&                     args) override;

    void Process_vkCreateDescriptorUpdateTemplate(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorUpdateTemplate&       args) override;

    void Process_vkCreateSamplerYcbcrConversion(
        const ApiCallInfo&                          call_info,
        args::CreateSamplerYcbcrConversion&         args) override;

    void Process_vkDestroyDescriptorUpdateTemplate(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorUpdateTemplate&      args) override;

    void Process_vkDestroySamplerYcbcrConversion(
        const ApiCallInfo&                          call_info,
        args::DestroySamplerYcbcrConversion&        args) override;

    void Process_vkEnumeratePhysicalDeviceGroups(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDeviceGroups&        args) override;

    void Process_vkGetBufferMemoryRequirements2(
        const ApiCallInfo&                          call_info,
        args::GetBufferMemoryRequirements2&         args) override;

    void Process_vkGetDescriptorSetLayoutSupport(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutSupport&        args) override;

    void Process_vkGetDeviceGroupPeerMemoryFeatures(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupPeerMemoryFeatures&     args) override;

    void Process_vkGetDeviceQueue2(
        const ApiCallInfo&                          call_info,
        args::GetDeviceQueue2&                      args) override;

    void Process_vkGetImageMemoryRequirements2(
        const ApiCallInfo&                          call_info,
        args::GetImageMemoryRequirements2&          args) override;

    void Process_vkGetImageSparseMemoryRequirements2(
        const ApiCallInfo&                          call_info,
        args::GetImageSparseMemoryRequirements2&    args) override;

    void Process_vkGetPhysicalDeviceExternalBufferProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalBufferProperties& args) override;

    void Process_vkGetPhysicalDeviceExternalFenceProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalFenceProperties& args) override;

    void Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalSemaphoreProperties& args) override;

    void Process_vkGetPhysicalDeviceFeatures2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFeatures2&           args) override;

    void Process_vkGetPhysicalDeviceFormatProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFormatProperties2&   args) override;

    void Process_vkGetPhysicalDeviceImageFormatProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceImageFormatProperties2& args) override;

    void Process_vkGetPhysicalDeviceMemoryProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceMemoryProperties2&   args) override;

    void Process_vkGetPhysicalDeviceProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceProperties2&         args) override;

    void Process_vkGetPhysicalDeviceQueueFamilyProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyProperties2& args) override;

    void Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSparseImageFormatProperties2& args) override;

    void Process_vkTrimCommandPool(
        const ApiCallInfo&                          call_info,
        args::TrimCommandPool&                      args) override;

    void Process_vkCmdBeginRenderPass2(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderPass2&                  args) override;

    void Process_vkCmdDrawIndexedIndirectCount(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCount&          args) override;

    void Process_vkCmdDrawIndirectCount(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCount&                 args) override;

    void Process_vkCmdEndRenderPass2(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderPass2&                    args) override;

    void Process_vkCmdNextSubpass2(
        const ApiCallInfo&                          call_info,
        args::CmdNextSubpass2&                      args) override;

    void Process_vkCreateRenderPass2(
        const ApiCallInfo&                          call_info,
        args::CreateRenderPass2&                    args) override;

    void Process_vkGetBufferDeviceAddress(
        const ApiCallInfo&                          call_info,
        args::GetBufferDeviceAddress&               args) override;

    void Process_vkGetBufferOpaqueCaptureAddress(
        const ApiCallInfo&                          call_info,
        args::GetBufferOpaqueCaptureAddress&        args) override;

    void Process_vkGetDeviceMemoryOpaqueCaptureAddress(
        const ApiCallInfo&                          call_info,
        args::GetDeviceMemoryOpaqueCaptureAddress&  args) override;

    void Process_vkGetSemaphoreCounterValue(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreCounterValue&             args) override;

    void Process_vkResetQueryPool(
        const ApiCallInfo&                          call_info,
        args::ResetQueryPool&                       args) override;

    void Process_vkSignalSemaphore(
        const ApiCallInfo&                          call_info,
        args::SignalSemaphore&                      args) override;

    void Process_vkWaitSemaphores(
        const ApiCallInfo&                          call_info,
        args::WaitSemaphores&                       args) override;

    void Process_vkCmdBeginRendering(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRendering&                    args) override;

    void Process_vkCmdBindVertexBuffers2(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers2&                args) override;

    void Process_vkCmdBlitImage2(
        const ApiCallInfo&                          call_info,
        args::CmdBlitImage2&                        args) override;

    void Process_vkCmdCopyBuffer2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBuffer2&                       args) override;

    void Process_vkCmdCopyBufferToImage2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBufferToImage2&                args) override;

    void Process_vkCmdCopyImage2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImage2&                        args) override;

    void Process_vkCmdCopyImageToBuffer2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToBuffer2&                args) override;

    void Process_vkCmdEndRendering(
        const ApiCallInfo&                          call_info,
        args::CmdEndRendering&                      args) override;

    void Process_vkCmdPipelineBarrier2(
        const ApiCallInfo&                          call_info,
        args::CmdPipelineBarrier2&                  args) override;

    void Process_vkCmdResetEvent2(
        const ApiCallInfo&                          call_info,
        args::CmdResetEvent2&                       args) override;

    void Process_vkCmdResolveImage2(
        const ApiCallInfo&                          call_info,
        args::CmdResolveImage2&                     args) override;

    void Process_vkCmdSetCullMode(
        const ApiCallInfo&                          call_info,
        args::CmdSetCullMode&                       args) override;

    void Process_vkCmdSetDepthBiasEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBiasEnable&                args) override;

    void Process_vkCmdSetDepthBoundsTestEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBoundsTestEnable&          args) override;

    void Process_vkCmdSetDepthCompareOp(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthCompareOp&                 args) override;

    void Process_vkCmdSetDepthTestEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthTestEnable&                args) override;

    void Process_vkCmdSetDepthWriteEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthWriteEnable&               args) override;

    void Process_vkCmdSetEvent2(
        const ApiCallInfo&                          call_info,
        args::CmdSetEvent2&                         args) override;

    void Process_vkCmdSetFrontFace(
        const ApiCallInfo&                          call_info,
        args::CmdSetFrontFace&                      args) override;

    void Process_vkCmdSetPrimitiveRestartEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveRestartEnable&         args) override;

    void Process_vkCmdSetPrimitiveTopology(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveTopology&              args) override;

    void Process_vkCmdSetRasterizerDiscardEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizerDiscardEnable&        args) override;

    void Process_vkCmdSetScissorWithCount(
        const ApiCallInfo&                          call_info,
        args::CmdSetScissorWithCount&               args) override;

    void Process_vkCmdSetStencilOp(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilOp&                      args) override;

    void Process_vkCmdSetStencilTestEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilTestEnable&              args) override;

    void Process_vkCmdSetViewportWithCount(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWithCount&              args) override;

    void Process_vkCmdWaitEvents2(
        const ApiCallInfo&                          call_info,
        args::CmdWaitEvents2&                       args) override;

    void Process_vkCmdWriteTimestamp2(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp2&                   args) override;

    void Process_vkCreatePrivateDataSlot(
        const ApiCallInfo&                          call_info,
        args::CreatePrivateDataSlot&                args) override;

    void Process_vkDestroyPrivateDataSlot(
        const ApiCallInfo&                          call_info,
        args::DestroyPrivateDataSlot&               args) override;

    void Process_vkGetDeviceBufferMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetDeviceBufferMemoryRequirements&    args) override;

    void Process_vkGetDeviceImageMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageMemoryRequirements&     args) override;

    void Process_vkGetDeviceImageSparseMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageSparseMemoryRequirements& args) override;

    void Process_vkGetPhysicalDeviceToolProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceToolProperties&      args) override;

    void Process_vkGetPrivateData(
        const ApiCallInfo&                          call_info,
        args::GetPrivateData&                       args) override;

    void Process_vkQueueSubmit2(
        const ApiCallInfo&                          call_info,
        args::QueueSubmit2&                         args) override;

    void Process_vkSetPrivateData(
        const ApiCallInfo&                          call_info,
        args::SetPrivateData&                       args) override;

    void Process_vkCmdBindDescriptorSets2(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorSets2&               args) override;

    void Process_vkCmdBindIndexBuffer2(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer2&                  args) override;

    void Process_vkCmdPushConstants2(
        const ApiCallInfo&                          call_info,
        args::CmdPushConstants2&                    args) override;

    void Process_vkCmdPushDescriptorSet(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSet&                 args) override;

    void Process_vkCmdPushDescriptorSet2(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSet2&                args) override;

    void Process_vkCmdSetLineStipple(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStipple&                    args) override;

    void Process_vkCmdSetRenderingAttachmentLocations(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingAttachmentLocations&   args) override;

    void Process_vkCmdSetRenderingInputAttachmentIndices(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingInputAttachmentIndices& args) override;

    void Process_vkCopyImageToImage(
        const ApiCallInfo&                          call_info,
        args::CopyImageToImage&                     args) override;

    void Process_vkCopyImageToMemory(
        const ApiCallInfo&                          call_info,
        args::CopyImageToMemory&                    args) override;

    void Process_vkCopyMemoryToImage(
        const ApiCallInfo&                          call_info,
        args::CopyMemoryToImage&                    args) override;

    void Process_vkGetDeviceImageSubresourceLayout(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageSubresourceLayout&      args) override;

    void Process_vkGetImageSubresourceLayout2(
        const ApiCallInfo&                          call_info,
        args::GetImageSubresourceLayout2&           args) override;

    void Process_vkGetRenderingAreaGranularity(
        const ApiCallInfo&                          call_info,
        args::GetRenderingAreaGranularity&          args) override;

    void Process_vkMapMemory2(
        const ApiCallInfo&                          call_info,
        args::MapMemory2&                           args) override;

    void Process_vkTransitionImageLayout(
        const ApiCallInfo&                          call_info,
        args::TransitionImageLayout&                args) override;

    void Process_vkUnmapMemory2(
        const ApiCallInfo&                          call_info,
        args::UnmapMemory2&                         args) override;

    void Process_vkDestroySurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::DestroySurfaceKHR&                    args) override;

    void Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceCapabilitiesKHR& args) override;

    void Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceFormatsKHR&   args) override;

    void Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfacePresentModesKHR& args) override;

    void Process_vkGetPhysicalDeviceSurfaceSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceSupportKHR&   args) override;

    void Process_vkAcquireNextImage2KHR(
        const ApiCallInfo&                          call_info,
        args::AcquireNextImage2KHR&                 args) override;

    void Process_vkAcquireNextImageKHR(
        const ApiCallInfo&                          call_info,
        args::AcquireNextImageKHR&                  args) override;

    void Process_vkCreateSwapchainKHR(
        const ApiCallInfo&                          call_info,
        args::CreateSwapchainKHR&                   args) override;

    void Process_vkDestroySwapchainKHR(
        const ApiCallInfo&                          call_info,
        args::DestroySwapchainKHR&                  args) override;

    void Process_vkGetDeviceGroupPresentCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupPresentCapabilitiesKHR& args) override;

    void Process_vkGetDeviceGroupSurfacePresentModesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupSurfacePresentModesKHR& args) override;

    void Process_vkGetPhysicalDevicePresentRectanglesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDevicePresentRectanglesKHR& args) override;

    void Process_vkGetSwapchainImagesKHR(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainImagesKHR&                args) override;

    void Process_vkQueuePresentKHR(
        const ApiCallInfo&                          call_info,
        args::QueuePresentKHR&                      args) override;

    void Process_vkCreateDisplayModeKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDisplayModeKHR&                 args) override;

    void Process_vkCreateDisplayPlaneSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDisplayPlaneSurfaceKHR&         args) override;

    void Process_vkGetDisplayModePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayModePropertiesKHR&          args) override;

    void Process_vkGetDisplayPlaneCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayPlaneCapabilitiesKHR&       args) override;

    void Process_vkGetDisplayPlaneSupportedDisplaysKHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayPlaneSupportedDisplaysKHR&  args) override;

    void Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDisplayPlanePropertiesKHR& args) override;

    void Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDisplayPropertiesKHR& args) override;

    void Process_vkCreateSharedSwapchainsKHR(
        const ApiCallInfo&                          call_info,
        args::CreateSharedSwapchainsKHR&            args) override;
#ifdef VK_USE_PLATFORM_XLIB_KHR

    void Process_vkCreateXlibSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateXlibSurfaceKHR&                 args) override;

    void Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceXlibPresentationSupportKHR& args) override;
#endif /* VK_USE_PLATFORM_XLIB_KHR */
#ifdef VK_USE_PLATFORM_XCB_KHR

    void Process_vkCreateXcbSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateXcbSurfaceKHR&                  args) override;

    void Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceXcbPresentationSupportKHR& args) override;
#endif /* VK_USE_PLATFORM_XCB_KHR */
#ifdef VK_USE_PLATFORM_WAYLAND_KHR

    void Process_vkCreateWaylandSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateWaylandSurfaceKHR&              args) override;

    void Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceWaylandPresentationSupportKHR& args) override;
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */
#ifdef VK_USE_PLATFORM_ANDROID_KHR

    void Process_vkCreateAndroidSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateAndroidSurfaceKHR&              args) override;
#endif /* VK_USE_PLATFORM_ANDROID_KHR */
#ifdef VK_USE_PLATFORM_WIN32_KHR

    void Process_vkCreateWin32SurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateWin32SurfaceKHR&                args) override;

    void Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceWin32PresentationSupportKHR& args) override;
#endif /* VK_USE_PLATFORM_WIN32_KHR */

    void Process_vkBindVideoSessionMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::BindVideoSessionMemoryKHR&            args) override;

    void Process_vkCmdBeginVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBeginVideoCodingKHR&               args) override;

    void Process_vkCmdControlVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdControlVideoCodingKHR&             args) override;

    void Process_vkCmdEndVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndVideoCodingKHR&                 args) override;

    void Process_vkCreateVideoSessionKHR(
        const ApiCallInfo&                          call_info,
        args::CreateVideoSessionKHR&                args) override;

    void Process_vkCreateVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::CreateVideoSessionParametersKHR&      args) override;

    void Process_vkDestroyVideoSessionKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyVideoSessionKHR&               args) override;

    void Process_vkDestroyVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyVideoSessionParametersKHR&     args) override;

    void Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceVideoCapabilitiesKHR& args) override;

    void Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceVideoFormatPropertiesKHR& args) override;

    void Process_vkGetVideoSessionMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        args::GetVideoSessionMemoryRequirementsKHR& args) override;

    void Process_vkUpdateVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::UpdateVideoSessionParametersKHR&      args) override;

    void Process_vkCmdDecodeVideoKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDecodeVideoKHR&                    args) override;

    void Process_vkCmdBeginRenderingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderingKHR&                 args) override;

    void Process_vkCmdEndRenderingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderingKHR&                   args) override;

    void Process_vkGetPhysicalDeviceFeatures2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFeatures2KHR&        args) override;

    void Process_vkGetPhysicalDeviceFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFormatProperties2KHR& args) override;

    void Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceImageFormatProperties2KHR& args) override;

    void Process_vkGetPhysicalDeviceMemoryProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceMemoryProperties2KHR& args) override;

    void Process_vkGetPhysicalDeviceProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceProperties2KHR&      args) override;

    void Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyProperties2KHR& args) override;

    void Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSparseImageFormatProperties2KHR& args) override;

    void Process_vkCmdDispatchBaseKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchBaseKHR&                   args) override;

    void Process_vkCmdSetDeviceMaskKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetDeviceMaskKHR&                  args) override;

    void Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupPeerMemoryFeaturesKHR&  args) override;

    void Process_vkTrimCommandPoolKHR(
        const ApiCallInfo&                          call_info,
        args::TrimCommandPoolKHR&                   args) override;

    void Process_vkEnumeratePhysicalDeviceGroupsKHR(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDeviceGroupsKHR&     args) override;

    void Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalBufferPropertiesKHR& args) override;
#ifdef VK_USE_PLATFORM_WIN32_KHR

    void Process_vkGetMemoryWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::GetMemoryWin32HandleKHR&              args) override;

    void Process_vkGetMemoryWin32HandlePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetMemoryWin32HandlePropertiesKHR&    args) override;
#endif /* VK_USE_PLATFORM_WIN32_KHR */

    void Process_vkGetMemoryFdKHR(
        const ApiCallInfo&                          call_info,
        args::GetMemoryFdKHR&                       args) override;

    void Process_vkGetMemoryFdPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetMemoryFdPropertiesKHR&             args) override;
#ifdef VK_USE_PLATFORM_WIN32_KHR
#endif /* VK_USE_PLATFORM_WIN32_KHR */

    void Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalSemaphorePropertiesKHR& args) override;
#ifdef VK_USE_PLATFORM_WIN32_KHR

    void Process_vkGetSemaphoreWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreWin32HandleKHR&           args) override;

    void Process_vkImportSemaphoreWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::ImportSemaphoreWin32HandleKHR&        args) override;
#endif /* VK_USE_PLATFORM_WIN32_KHR */

    void Process_vkGetSemaphoreFdKHR(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreFdKHR&                    args) override;

    void Process_vkImportSemaphoreFdKHR(
        const ApiCallInfo&                          call_info,
        args::ImportSemaphoreFdKHR&                 args) override;

    void Process_vkCmdPushDescriptorSetKHR(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSetKHR&              args) override;

    void Process_vkUpdateDescriptorSetWithTemplateKHR(
        const ApiCallInfo&               call_info,
        args::UpdateDescriptorSetWithTemplateKHR& args) override;

    void Process_vkCreateDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorUpdateTemplateKHR&    args) override;

    void Process_vkDestroyDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorUpdateTemplateKHR&   args) override;

    void Process_vkCmdBeginRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderPass2KHR&               args) override;

    void Process_vkCmdEndRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderPass2KHR&                 args) override;

    void Process_vkCmdNextSubpass2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdNextSubpass2KHR&                   args) override;

    void Process_vkCreateRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        args::CreateRenderPass2KHR&                 args) override;

    void Process_vkGetSwapchainStatusKHR(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainStatusKHR&                args) override;

    void Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalFencePropertiesKHR& args) override;
#ifdef VK_USE_PLATFORM_WIN32_KHR

    void Process_vkGetFenceWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::GetFenceWin32HandleKHR&               args) override;

    void Process_vkImportFenceWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::ImportFenceWin32HandleKHR&            args) override;
#endif /* VK_USE_PLATFORM_WIN32_KHR */

    void Process_vkGetFenceFdKHR(
        const ApiCallInfo&                          call_info,
        args::GetFenceFdKHR&                        args) override;

    void Process_vkImportFenceFdKHR(
        const ApiCallInfo&                          call_info,
        args::ImportFenceFdKHR&                     args) override;

    void Process_vkAcquireProfilingLockKHR(
        const ApiCallInfo&                          call_info,
        args::AcquireProfilingLockKHR&              args) override;

    void Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR& args) override;

    void Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR& args) override;

    void Process_vkReleaseProfilingLockKHR(
        const ApiCallInfo&                          call_info,
        args::ReleaseProfilingLockKHR&              args) override;

    void Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceCapabilities2KHR& args) override;

    void Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceFormats2KHR&  args) override;

    void Process_vkGetDisplayModeProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayModeProperties2KHR&         args) override;

    void Process_vkGetDisplayPlaneCapabilities2KHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayPlaneCapabilities2KHR&      args) override;

    void Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDisplayPlaneProperties2KHR& args) override;

    void Process_vkGetPhysicalDeviceDisplayProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDisplayProperties2KHR& args) override;

    void Process_vkGetBufferMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        args::GetBufferMemoryRequirements2KHR&      args) override;

    void Process_vkGetImageMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        args::GetImageMemoryRequirements2KHR&       args) override;

    void Process_vkGetImageSparseMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        args::GetImageSparseMemoryRequirements2KHR& args) override;

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

    void Process_vkGetDescriptorSetLayoutSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutSupportKHR&     args) override;

    void Process_vkCmdDrawIndexedIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCountKHR&       args) override;

    void Process_vkCmdDrawIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCountKHR&              args) override;

    void Process_vkGetSemaphoreCounterValueKHR(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreCounterValueKHR&          args) override;

    void Process_vkSignalSemaphoreKHR(
        const ApiCallInfo&                          call_info,
        args::SignalSemaphoreKHR&                   args) override;

    void Process_vkWaitSemaphoresKHR(
        const ApiCallInfo&                          call_info,
        args::WaitSemaphoresKHR&                    args) override;

    void Process_vkCmdSetFragmentShadingRateKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetFragmentShadingRateKHR&         args) override;

    void Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFragmentShadingRatesKHR& args) override;

    void Process_vkCmdSetRenderingAttachmentLocationsKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingAttachmentLocationsKHR& args) override;

    void Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingInputAttachmentIndicesKHR& args) override;

    void Process_vkWaitForPresentKHR(
        const ApiCallInfo&                          call_info,
        args::WaitForPresentKHR&                    args) override;

    void Process_vkGetBufferDeviceAddressKHR(
        const ApiCallInfo&                          call_info,
        args::GetBufferDeviceAddressKHR&            args) override;

    void Process_vkGetBufferOpaqueCaptureAddressKHR(
        const ApiCallInfo&                          call_info,
        args::GetBufferOpaqueCaptureAddressKHR&     args) override;

    void Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceMemoryOpaqueCaptureAddressKHR& args) override;

    void Process_vkCreateDeferredOperationKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDeferredOperationKHR&           args) override;

    void Process_vkDeferredOperationJoinKHR(
        const ApiCallInfo&                          call_info,
        args::DeferredOperationJoinKHR&             args) override;

    void Process_vkDestroyDeferredOperationKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyDeferredOperationKHR&          args) override;

    void Process_vkGetDeferredOperationMaxConcurrencyKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeferredOperationMaxConcurrencyKHR& args) override;

    void Process_vkGetDeferredOperationResultKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeferredOperationResultKHR&        args) override;

    void Process_vkGetPipelineExecutableInternalRepresentationsKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineExecutableInternalRepresentationsKHR& args) override;

    void Process_vkGetPipelineExecutablePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineExecutablePropertiesKHR&   args) override;

    void Process_vkGetPipelineExecutableStatisticsKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineExecutableStatisticsKHR&   args) override;

    void Process_vkMapMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::MapMemory2KHR&                        args) override;

    void Process_vkUnmapMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::UnmapMemory2KHR&                      args) override;

    void Process_vkCmdEncodeVideoKHR(
        const ApiCallInfo&                          call_info,
        args::CmdEncodeVideoKHR&                    args) override;

    void Process_vkGetEncodedVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::GetEncodedVideoSessionParametersKHR&  args) override;

    void Process_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR& args) override;

    void Process_vkCmdPipelineBarrier2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdPipelineBarrier2KHR&               args) override;

    void Process_vkCmdResetEvent2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdResetEvent2KHR&                    args) override;

    void Process_vkCmdSetEvent2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetEvent2KHR&                      args) override;

    void Process_vkCmdWaitEvents2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdWaitEvents2KHR&                    args) override;

    void Process_vkCmdWriteTimestamp2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp2KHR&                args) override;

    void Process_vkQueueSubmit2KHR(
        const ApiCallInfo&                          call_info,
        args::QueueSubmit2KHR&                      args) override;

    void Process_vkCmdBeginConditionalRendering2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginConditionalRendering2EXT&     args) override;

    void Process_vkCmdBeginTransformFeedback2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginTransformFeedback2EXT&        args) override;

    void Process_vkCmdBindIndexBuffer3KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer3KHR&               args) override;

    void Process_vkCmdBindTransformFeedbackBuffers2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindTransformFeedbackBuffers2EXT&  args) override;

    void Process_vkCmdBindVertexBuffers3KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers3KHR&             args) override;

    void Process_vkCmdCopyImageToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToMemoryKHR&              args) override;

    void Process_vkCmdCopyMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryKHR&                     args) override;

    void Process_vkCmdCopyMemoryToImageKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToImageKHR&              args) override;

    void Process_vkCmdCopyQueryPoolResultsToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyQueryPoolResultsToMemoryKHR&   args) override;

    void Process_vkCmdDispatchIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchIndirect2KHR&              args) override;

    void Process_vkCmdDrawIndexedIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirect2KHR&           args) override;

    void Process_vkCmdDrawIndexedIndirectCount2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCount2KHR&      args) override;

    void Process_vkCmdDrawIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirect2KHR&                  args) override;

    void Process_vkCmdDrawIndirectByteCount2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectByteCount2EXT&         args) override;

    void Process_vkCmdDrawIndirectCount2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCount2KHR&             args) override;

    void Process_vkCmdDrawMeshTasksIndirect2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirect2EXT&         args) override;

    void Process_vkCmdDrawMeshTasksIndirectCount2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectCount2EXT&    args) override;

    void Process_vkCmdEndTransformFeedback2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndTransformFeedback2EXT&          args) override;

    void Process_vkCmdFillMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdFillMemoryKHR&                     args) override;

    void Process_vkCmdUpdateMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdUpdateMemoryKHR&                   args) override;

    void Process_vkCmdWriteMarkerToMemoryAMD(
        const ApiCallInfo&                          call_info,
        args::CmdWriteMarkerToMemoryAMD&            args) override;

    void Process_vkCreateAccelerationStructure2KHR(
        const ApiCallInfo&                          call_info,
        args::CreateAccelerationStructure2KHR&      args) override;

    void Process_vkCmdBlitImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBlitImage2KHR&                     args) override;

    void Process_vkCmdCopyBuffer2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBuffer2KHR&                    args) override;

    void Process_vkCmdCopyBufferToImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBufferToImage2KHR&             args) override;

    void Process_vkCmdCopyImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImage2KHR&                     args) override;

    void Process_vkCmdCopyImageToBuffer2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToBuffer2KHR&             args) override;

    void Process_vkCmdResolveImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdResolveImage2KHR&                  args) override;

    void Process_vkCmdTraceRaysIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysIndirect2KHR&             args) override;

    void Process_vkGetDeviceBufferMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceBufferMemoryRequirementsKHR& args) override;

    void Process_vkGetDeviceImageMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageMemoryRequirementsKHR&  args) override;

    void Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageSparseMemoryRequirementsKHR& args) override;

    void Process_vkCmdBindIndexBuffer2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer2KHR&               args) override;

    void Process_vkGetDeviceImageSubresourceLayoutKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageSubresourceLayoutKHR&   args) override;

    void Process_vkGetImageSubresourceLayout2KHR(
        const ApiCallInfo&                          call_info,
        args::GetImageSubresourceLayout2KHR&        args) override;

    void Process_vkGetRenderingAreaGranularityKHR(
        const ApiCallInfo&                          call_info,
        args::GetRenderingAreaGranularityKHR&       args) override;

    void Process_vkWaitForPresent2KHR(
        const ApiCallInfo&                          call_info,
        args::WaitForPresent2KHR&                   args) override;

    void Process_vkCreatePipelineBinariesKHR(
        const ApiCallInfo&                          call_info,
        args::CreatePipelineBinariesKHR&            args) override;

    void Process_vkDestroyPipelineBinaryKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyPipelineBinaryKHR&             args) override;

    void Process_vkGetPipelineBinaryDataKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineBinaryDataKHR&             args) override;

    void Process_vkGetPipelineKeyKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineKeyKHR&                    args) override;

    void Process_vkReleaseCapturedPipelineDataKHR(
        const ApiCallInfo&                          call_info,
        args::ReleaseCapturedPipelineDataKHR&       args) override;

    void Process_vkReleaseSwapchainImagesKHR(
        const ApiCallInfo&                          call_info,
        args::ReleaseSwapchainImagesKHR&            args) override;

    void Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCooperativeMatrixPropertiesKHR& args) override;

    void Process_vkCmdSetLineStippleKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStippleKHR&                 args) override;

    void Process_vkGetCalibratedTimestampsKHR(
        const ApiCallInfo&                          call_info,
        args::GetCalibratedTimestampsKHR&           args) override;

    void Process_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCalibrateableTimeDomainsKHR& args) override;

    void Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorBufferEmbeddedSamplers2EXT& args) override;

    void Process_vkCmdBindDescriptorSets2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorSets2KHR&            args) override;

    void Process_vkCmdPushConstants2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdPushConstants2KHR&                 args) override;

    void Process_vkCmdPushDescriptorSet2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSet2KHR&             args) override;

    void Process_vkCmdSetDescriptorBufferOffsets2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDescriptorBufferOffsets2EXT&    args) override;

    void Process_vkCmdCopyMemoryIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryIndirectKHR&             args) override;

    void Process_vkCmdCopyMemoryToImageIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToImageIndirectKHR&      args) override;

    void Process_vkGetDeviceFaultDebugInfoKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceFaultDebugInfoKHR&           args) override;

    void Process_vkGetDeviceFaultReportsKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceFaultReportsKHR&             args) override;

    void Process_vkCmdEndRendering2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndRendering2KHR&                  args) override;
#ifdef VK_USE_PLATFORM_ANDROID_KHR

    void Process_vkFrameBoundaryANDROID(
        const ApiCallInfo&                          call_info,
        args::FrameBoundaryANDROID&                 args) override;
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

    void Process_vkCreateDebugReportCallbackEXT(
        const ApiCallInfo&                          call_info,
        args::CreateDebugReportCallbackEXT&         args) override;

    void Process_vkDebugReportMessageEXT(
        const ApiCallInfo&                          call_info,
        args::DebugReportMessageEXT&                args) override;

    void Process_vkDestroyDebugReportCallbackEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyDebugReportCallbackEXT&        args) override;

    void Process_vkCmdDebugMarkerBeginEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDebugMarkerBeginEXT&               args) override;

    void Process_vkCmdDebugMarkerEndEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDebugMarkerEndEXT&                 args) override;

    void Process_vkCmdDebugMarkerInsertEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDebugMarkerInsertEXT&              args) override;

    void Process_vkDebugMarkerSetObjectNameEXT(
        const ApiCallInfo&                          call_info,
        args::DebugMarkerSetObjectNameEXT&          args) override;

    void Process_vkDebugMarkerSetObjectTagEXT(
        const ApiCallInfo&                          call_info,
        args::DebugMarkerSetObjectTagEXT&           args) override;

    void Process_vkCmdBeginQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginQueryIndexedEXT&              args) override;

    void Process_vkCmdBeginTransformFeedbackEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginTransformFeedbackEXT&         args) override;

    void Process_vkCmdBindTransformFeedbackBuffersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindTransformFeedbackBuffersEXT&   args) override;

    void Process_vkCmdDrawIndirectByteCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectByteCountEXT&          args) override;

    void Process_vkCmdEndQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndQueryIndexedEXT&                args) override;

    void Process_vkCmdEndTransformFeedbackEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndTransformFeedbackEXT&           args) override;

    void Process_vkGetDeviceCombinedImageSamplerIndexNVX(
        const ApiCallInfo&                          call_info,
        args::GetDeviceCombinedImageSamplerIndexNVX& args) override;

    void Process_vkGetImageViewAddressNVX(
        const ApiCallInfo&                          call_info,
        args::GetImageViewAddressNVX&               args) override;

    void Process_vkGetImageViewHandle64NVX(
        const ApiCallInfo&                          call_info,
        args::GetImageViewHandle64NVX&              args) override;

    void Process_vkGetImageViewHandleNVX(
        const ApiCallInfo&                          call_info,
        args::GetImageViewHandleNVX&                args) override;

    void Process_vkCmdDrawIndexedIndirectCountAMD(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCountAMD&       args) override;

    void Process_vkCmdDrawIndirectCountAMD(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCountAMD&              args) override;

    void Process_vkGetShaderInfoAMD(
        const ApiCallInfo&                          call_info,
        args::GetShaderInfoAMD&                     args) override;
#ifdef VK_USE_PLATFORM_GGP

    void Process_vkCreateStreamDescriptorSurfaceGGP(
        const ApiCallInfo&                          call_info,
        args::CreateStreamDescriptorSurfaceGGP&     args) override;
#endif /* VK_USE_PLATFORM_GGP */

    void Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalImageFormatPropertiesNV& args) override;
#ifdef VK_USE_PLATFORM_WIN32_KHR

    void Process_vkGetMemoryWin32HandleNV(
        const ApiCallInfo&                          call_info,
        args::GetMemoryWin32HandleNV&               args) override;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
#ifdef VK_USE_PLATFORM_WIN32_KHR
#endif /* VK_USE_PLATFORM_WIN32_KHR */
#ifdef VK_USE_PLATFORM_VI_NN

    void Process_vkCreateViSurfaceNN(
        const ApiCallInfo&                          call_info,
        args::CreateViSurfaceNN&                    args) override;
#endif /* VK_USE_PLATFORM_VI_NN */

    void Process_vkCmdBeginConditionalRenderingEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginConditionalRenderingEXT&      args) override;

    void Process_vkCmdEndConditionalRenderingEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndConditionalRenderingEXT&        args) override;

    void Process_vkCmdSetViewportWScalingNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWScalingNV&             args) override;

    void Process_vkReleaseDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::ReleaseDisplayEXT&                    args) override;
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT

    void Process_vkAcquireXlibDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::AcquireXlibDisplayEXT&                args) override;

    void Process_vkGetRandROutputDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::GetRandROutputDisplayEXT&             args) override;
#endif /* VK_USE_PLATFORM_XLIB_XRANDR_EXT */

    void Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceCapabilities2EXT& args) override;

    void Process_vkDisplayPowerControlEXT(
        const ApiCallInfo&                          call_info,
        args::DisplayPowerControlEXT&               args) override;

    void Process_vkGetSwapchainCounterEXT(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainCounterEXT&               args) override;

    void Process_vkRegisterDeviceEventEXT(
        const ApiCallInfo&                          call_info,
        args::RegisterDeviceEventEXT&               args) override;

    void Process_vkRegisterDisplayEventEXT(
        const ApiCallInfo&                          call_info,
        args::RegisterDisplayEventEXT&              args) override;

    void Process_vkGetPastPresentationTimingGOOGLE(
        const ApiCallInfo&                          call_info,
        args::GetPastPresentationTimingGOOGLE&      args) override;

    void Process_vkGetRefreshCycleDurationGOOGLE(
        const ApiCallInfo&                          call_info,
        args::GetRefreshCycleDurationGOOGLE&        args) override;

    void Process_vkCmdSetDiscardRectangleEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDiscardRectangleEXT&            args) override;

    void Process_vkCmdSetDiscardRectangleEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDiscardRectangleEnableEXT&      args) override;

    void Process_vkCmdSetDiscardRectangleModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDiscardRectangleModeEXT&        args) override;

    void Process_vkSetHdrMetadataEXT(
        const ApiCallInfo&                          call_info,
        args::SetHdrMetadataEXT&                    args) override;
#ifdef VK_USE_PLATFORM_IOS_MVK

    void Process_vkCreateIOSSurfaceMVK(
        const ApiCallInfo&                          call_info,
        args::CreateIOSSurfaceMVK&                  args) override;
#endif /* VK_USE_PLATFORM_IOS_MVK */
#ifdef VK_USE_PLATFORM_MACOS_MVK

    void Process_vkCreateMacOSSurfaceMVK(
        const ApiCallInfo&                          call_info,
        args::CreateMacOSSurfaceMVK&                args) override;
#endif /* VK_USE_PLATFORM_MACOS_MVK */

    void Process_vkCmdBeginDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginDebugUtilsLabelEXT&           args) override;

    void Process_vkCmdEndDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndDebugUtilsLabelEXT&             args) override;

    void Process_vkCmdInsertDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::CmdInsertDebugUtilsLabelEXT&          args) override;

    void Process_vkCreateDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        args::CreateDebugUtilsMessengerEXT&         args) override;

    void Process_vkDestroyDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyDebugUtilsMessengerEXT&        args) override;

    void Process_vkQueueBeginDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::QueueBeginDebugUtilsLabelEXT&         args) override;

    void Process_vkQueueEndDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::QueueEndDebugUtilsLabelEXT&           args) override;

    void Process_vkQueueInsertDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::QueueInsertDebugUtilsLabelEXT&        args) override;

    void Process_vkSetDebugUtilsObjectNameEXT(
        const ApiCallInfo&                          call_info,
        args::SetDebugUtilsObjectNameEXT&           args) override;

    void Process_vkSetDebugUtilsObjectTagEXT(
        const ApiCallInfo&                          call_info,
        args::SetDebugUtilsObjectTagEXT&            args) override;

    void Process_vkSubmitDebugUtilsMessageEXT(
        const ApiCallInfo&                          call_info,
        args::SubmitDebugUtilsMessageEXT&           args) override;
#ifdef VK_USE_PLATFORM_ANDROID_KHR

    void Process_vkGetAndroidHardwareBufferPropertiesANDROID(
        const ApiCallInfo&                          call_info,
        args::GetAndroidHardwareBufferPropertiesANDROID& args) override;

    void Process_vkGetMemoryAndroidHardwareBufferANDROID(
        const ApiCallInfo&                          call_info,
        args::GetMemoryAndroidHardwareBufferANDROID& args) override;
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

    void Process_vkCmdSetSampleLocationsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetSampleLocationsEXT&             args) override;

    void Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceMultisamplePropertiesEXT& args) override;

    void Process_vkGetImageDrmFormatModifierPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetImageDrmFormatModifierPropertiesEXT& args) override;

    void Process_vkCreateValidationCacheEXT(
        const ApiCallInfo&                          call_info,
        args::CreateValidationCacheEXT&             args) override;

    void Process_vkDestroyValidationCacheEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyValidationCacheEXT&            args) override;

    void Process_vkGetValidationCacheDataEXT(
        const ApiCallInfo&                          call_info,
        args::GetValidationCacheDataEXT&            args) override;

    void Process_vkMergeValidationCachesEXT(
        const ApiCallInfo&                          call_info,
        args::MergeValidationCachesEXT&             args) override;

    void Process_vkCmdBindShadingRateImageNV(
        const ApiCallInfo&                          call_info,
        args::CmdBindShadingRateImageNV&            args) override;

    void Process_vkCmdSetCoarseSampleOrderNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoarseSampleOrderNV&            args) override;

    void Process_vkCmdSetViewportShadingRatePaletteNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportShadingRatePaletteNV&   args) override;

    void Process_vkBindAccelerationStructureMemoryNV(
        const ApiCallInfo&                          call_info,
        args::BindAccelerationStructureMemoryNV&    args) override;

    void Process_vkCmdBuildAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::CmdBuildAccelerationStructureNV&      args) override;

    void Process_vkCmdCopyAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::CmdCopyAccelerationStructureNV&       args) override;

    void Process_vkCmdTraceRaysNV(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysNV&                       args) override;

    void Process_vkCmdWriteAccelerationStructuresPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::CmdWriteAccelerationStructuresPropertiesNV& args) override;

    void Process_vkCompileDeferredNV(
        const ApiCallInfo&                          call_info,
        args::CompileDeferredNV&                    args) override;

    void Process_vkCreateAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::CreateAccelerationStructureNV&        args) override;

    void Process_vkCreateRayTracingPipelinesNV(
        const ApiCallInfo&                          call_info,
        args::CreateRayTracingPipelinesNV&          args) override;

    void Process_vkDestroyAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::DestroyAccelerationStructureNV&       args) override;

    void Process_vkGetAccelerationStructureHandleNV(
        const ApiCallInfo&                          call_info,
        args::GetAccelerationStructureHandleNV&     args) override;

    void Process_vkGetAccelerationStructureMemoryRequirementsNV(
        const ApiCallInfo&                          call_info,
        args::GetAccelerationStructureMemoryRequirementsNV& args) override;

    void Process_vkGetRayTracingShaderGroupHandlesKHR(
        const ApiCallInfo&                          call_info,
        args::GetRayTracingShaderGroupHandlesKHR&   args) override;

    void Process_vkGetRayTracingShaderGroupHandlesNV(
        const ApiCallInfo&                          call_info,
        args::GetRayTracingShaderGroupHandlesNV&    args) override;

    void Process_vkGetMemoryHostPointerPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetMemoryHostPointerPropertiesEXT&    args) override;

    void Process_vkCmdWriteBufferMarker2AMD(
        const ApiCallInfo&                          call_info,
        args::CmdWriteBufferMarker2AMD&             args) override;

    void Process_vkCmdWriteBufferMarkerAMD(
        const ApiCallInfo&                          call_info,
        args::CmdWriteBufferMarkerAMD&              args) override;

    void Process_vkGetCalibratedTimestampsEXT(
        const ApiCallInfo&                          call_info,
        args::GetCalibratedTimestampsEXT&           args) override;

    void Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCalibrateableTimeDomainsEXT& args) override;
#ifdef VK_USE_PLATFORM_GGP
#endif /* VK_USE_PLATFORM_GGP */

    void Process_vkCmdDrawMeshTasksIndirectCountNV(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectCountNV&      args) override;

    void Process_vkCmdDrawMeshTasksIndirectNV(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectNV&           args) override;

    void Process_vkCmdDrawMeshTasksNV(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksNV&                   args) override;

    void Process_vkCmdSetExclusiveScissorEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetExclusiveScissorEnableNV&       args) override;

    void Process_vkCmdSetExclusiveScissorNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetExclusiveScissorNV&             args) override;

    void Process_vkCmdSetCheckpointNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCheckpointNV&                   args) override;

    void Process_vkGetQueueCheckpointData2NV(
        const ApiCallInfo&                          call_info,
        args::GetQueueCheckpointData2NV&            args) override;

    void Process_vkGetQueueCheckpointDataNV(
        const ApiCallInfo&                          call_info,
        args::GetQueueCheckpointDataNV&             args) override;

    void Process_vkGetPastPresentationTimingEXT(
        const ApiCallInfo&                          call_info,
        args::GetPastPresentationTimingEXT&         args) override;

    void Process_vkGetSwapchainTimeDomainPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainTimeDomainPropertiesEXT&  args) override;

    void Process_vkGetSwapchainTimingPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainTimingPropertiesEXT&      args) override;

    void Process_vkSetSwapchainPresentTimingQueueSizeEXT(
        const ApiCallInfo&                          call_info,
        args::SetSwapchainPresentTimingQueueSizeEXT& args) override;

    void Process_vkAcquirePerformanceConfigurationINTEL(
        const ApiCallInfo&                          call_info,
        args::AcquirePerformanceConfigurationINTEL& args) override;

    void Process_vkCmdSetPerformanceMarkerINTEL(
        const ApiCallInfo&                          call_info,
        args::CmdSetPerformanceMarkerINTEL&         args) override;

    void Process_vkCmdSetPerformanceOverrideINTEL(
        const ApiCallInfo&                          call_info,
        args::CmdSetPerformanceOverrideINTEL&       args) override;

    void Process_vkCmdSetPerformanceStreamMarkerINTEL(
        const ApiCallInfo&                          call_info,
        args::CmdSetPerformanceStreamMarkerINTEL&   args) override;

    void Process_vkGetPerformanceParameterINTEL(
        const ApiCallInfo&                          call_info,
        args::GetPerformanceParameterINTEL&         args) override;

    void Process_vkInitializePerformanceApiINTEL(
        const ApiCallInfo&                          call_info,
        args::InitializePerformanceApiINTEL&        args) override;

    void Process_vkQueueSetPerformanceConfigurationINTEL(
        const ApiCallInfo&                          call_info,
        args::QueueSetPerformanceConfigurationINTEL& args) override;

    void Process_vkReleasePerformanceConfigurationINTEL(
        const ApiCallInfo&                          call_info,
        args::ReleasePerformanceConfigurationINTEL& args) override;

    void Process_vkUninitializePerformanceApiINTEL(
        const ApiCallInfo&                          call_info,
        args::UninitializePerformanceApiINTEL&      args) override;

    void Process_vkSetLocalDimmingAMD(
        const ApiCallInfo&                          call_info,
        args::SetLocalDimmingAMD&                   args) override;
#ifdef VK_USE_PLATFORM_FUCHSIA

    void Process_vkCreateImagePipeSurfaceFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::CreateImagePipeSurfaceFUCHSIA&        args) override;
#endif /* VK_USE_PLATFORM_FUCHSIA */

    void Process_vkCreateMetalSurfaceEXT(
        const ApiCallInfo&                          call_info,
        args::CreateMetalSurfaceEXT&                args) override;

    void Process_vkGetBufferDeviceAddressEXT(
        const ApiCallInfo&                          call_info,
        args::GetBufferDeviceAddressEXT&            args) override;

    void Process_vkGetPhysicalDeviceToolPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceToolPropertiesEXT&   args) override;

    void Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCooperativeMatrixPropertiesNV& args) override;

    void Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV& args) override;
#ifdef VK_USE_PLATFORM_WIN32_KHR

    void Process_vkAcquireFullScreenExclusiveModeEXT(
        const ApiCallInfo&                          call_info,
        args::AcquireFullScreenExclusiveModeEXT&    args) override;

    void Process_vkGetDeviceGroupSurfacePresentModes2EXT(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupSurfacePresentModes2EXT& args) override;

    void Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfacePresentModes2EXT& args) override;

    void Process_vkReleaseFullScreenExclusiveModeEXT(
        const ApiCallInfo&                          call_info,
        args::ReleaseFullScreenExclusiveModeEXT&    args) override;
#endif /* VK_USE_PLATFORM_WIN32_KHR */

    void Process_vkCreateHeadlessSurfaceEXT(
        const ApiCallInfo&                          call_info,
        args::CreateHeadlessSurfaceEXT&             args) override;

    void Process_vkCmdSetLineStippleEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStippleEXT&                 args) override;

    void Process_vkResetQueryPoolEXT(
        const ApiCallInfo&                          call_info,
        args::ResetQueryPoolEXT&                    args) override;

    void Process_vkCmdBindVertexBuffers2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers2EXT&             args) override;

    void Process_vkCmdSetCullModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetCullModeEXT&                    args) override;

    void Process_vkCmdSetDepthBoundsTestEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBoundsTestEnableEXT&       args) override;

    void Process_vkCmdSetDepthCompareOpEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthCompareOpEXT&              args) override;

    void Process_vkCmdSetDepthTestEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthTestEnableEXT&             args) override;

    void Process_vkCmdSetDepthWriteEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthWriteEnableEXT&            args) override;

    void Process_vkCmdSetFrontFaceEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetFrontFaceEXT&                   args) override;

    void Process_vkCmdSetPrimitiveTopologyEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveTopologyEXT&           args) override;

    void Process_vkCmdSetScissorWithCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetScissorWithCountEXT&            args) override;

    void Process_vkCmdSetStencilOpEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilOpEXT&                   args) override;

    void Process_vkCmdSetStencilTestEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilTestEnableEXT&           args) override;

    void Process_vkCmdSetViewportWithCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWithCountEXT&           args) override;

    void Process_vkCopyImageToImageEXT(
        const ApiCallInfo&                          call_info,
        args::CopyImageToImageEXT&                  args) override;

    void Process_vkCopyImageToMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CopyImageToMemoryEXT&                 args) override;

    void Process_vkCopyMemoryToImageEXT(
        const ApiCallInfo&                          call_info,
        args::CopyMemoryToImageEXT&                 args) override;

    void Process_vkGetImageSubresourceLayout2EXT(
        const ApiCallInfo&                          call_info,
        args::GetImageSubresourceLayout2EXT&        args) override;

    void Process_vkTransitionImageLayoutEXT(
        const ApiCallInfo&                          call_info,
        args::TransitionImageLayoutEXT&             args) override;

    void Process_vkReleaseSwapchainImagesEXT(
        const ApiCallInfo&                          call_info,
        args::ReleaseSwapchainImagesEXT&            args) override;

    void Process_vkCmdBindPipelineShaderGroupNV(
        const ApiCallInfo&                          call_info,
        args::CmdBindPipelineShaderGroupNV&         args) override;

    void Process_vkCmdExecuteGeneratedCommandsNV(
        const ApiCallInfo&                          call_info,
        args::CmdExecuteGeneratedCommandsNV&        args) override;

    void Process_vkCmdPreprocessGeneratedCommandsNV(
        const ApiCallInfo&                          call_info,
        args::CmdPreprocessGeneratedCommandsNV&     args) override;

    void Process_vkCreateIndirectCommandsLayoutNV(
        const ApiCallInfo&                          call_info,
        args::CreateIndirectCommandsLayoutNV&       args) override;

    void Process_vkDestroyIndirectCommandsLayoutNV(
        const ApiCallInfo&                          call_info,
        args::DestroyIndirectCommandsLayoutNV&      args) override;

    void Process_vkGetGeneratedCommandsMemoryRequirementsNV(
        const ApiCallInfo&                          call_info,
        args::GetGeneratedCommandsMemoryRequirementsNV& args) override;

    void Process_vkCmdSetDepthBias2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBias2EXT&                  args) override;

    void Process_vkAcquireDrmDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::AcquireDrmDisplayEXT&                 args) override;

    void Process_vkGetDrmDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::GetDrmDisplayEXT&                     args) override;

    void Process_vkCreatePrivateDataSlotEXT(
        const ApiCallInfo&                          call_info,
        args::CreatePrivateDataSlotEXT&             args) override;

    void Process_vkDestroyPrivateDataSlotEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyPrivateDataSlotEXT&            args) override;

    void Process_vkGetPrivateDataEXT(
        const ApiCallInfo&                          call_info,
        args::GetPrivateDataEXT&                    args) override;

    void Process_vkSetPrivateDataEXT(
        const ApiCallInfo&                          call_info,
        args::SetPrivateDataEXT&                    args) override;

    void Process_vkQueueSetPerfHintQCOM(
        const ApiCallInfo&                          call_info,
        args::QueueSetPerfHintQCOM&                 args) override;

    void Process_vkCmdBeginPerTileExecutionQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdBeginPerTileExecutionQCOM&         args) override;

    void Process_vkCmdDispatchTileQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchTileQCOM&                  args) override;

    void Process_vkCmdEndPerTileExecutionQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdEndPerTileExecutionQCOM&           args) override;

    void Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorBufferEmbeddedSamplersEXT& args) override;

    void Process_vkCmdBindDescriptorBuffersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorBuffersEXT&          args) override;

    void Process_vkCmdSetDescriptorBufferOffsetsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDescriptorBufferOffsetsEXT&     args) override;

    void Process_vkGetDescriptorEXT(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorEXT&                     args) override;

    void Process_vkGetDescriptorSetLayoutBindingOffsetEXT(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutBindingOffsetEXT& args) override;

    void Process_vkGetDescriptorSetLayoutSizeEXT(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutSizeEXT&        args) override;

    void Process_vkCmdSetFragmentShadingRateEnumNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetFragmentShadingRateEnumNV&      args) override;

    void Process_vkGetDeviceFaultInfoEXT(
        const ApiCallInfo&                          call_info,
        args::GetDeviceFaultInfoEXT&                args) override;
#ifdef VK_USE_PLATFORM_WIN32_KHR

    void Process_vkAcquireWinrtDisplayNV(
        const ApiCallInfo&                          call_info,
        args::AcquireWinrtDisplayNV&                args) override;

    void Process_vkGetWinrtDisplayNV(
        const ApiCallInfo&                          call_info,
        args::GetWinrtDisplayNV&                    args) override;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT

    void Process_vkCreateDirectFBSurfaceEXT(
        const ApiCallInfo&                          call_info,
        args::CreateDirectFBSurfaceEXT&             args) override;

    void Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDirectFBPresentationSupportEXT& args) override;
#endif /* VK_USE_PLATFORM_DIRECTFB_EXT */

    void Process_vkCmdSetVertexInputEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetVertexInputEXT&                 args) override;
#ifdef VK_USE_PLATFORM_FUCHSIA

    void Process_vkGetMemoryZirconHandleFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::GetMemoryZirconHandleFUCHSIA&         args) override;

    void Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::GetMemoryZirconHandlePropertiesFUCHSIA& args) override;
#endif /* VK_USE_PLATFORM_FUCHSIA */
#ifdef VK_USE_PLATFORM_FUCHSIA

    void Process_vkGetSemaphoreZirconHandleFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreZirconHandleFUCHSIA&      args) override;

    void Process_vkImportSemaphoreZirconHandleFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::ImportSemaphoreZirconHandleFUCHSIA&   args) override;
#endif /* VK_USE_PLATFORM_FUCHSIA */

    void Process_vkCmdBindInvocationMaskHUAWEI(
        const ApiCallInfo&                          call_info,
        args::CmdBindInvocationMaskHUAWEI&          args) override;

    void Process_vkGetMemoryRemoteAddressNV(
        const ApiCallInfo&                          call_info,
        args::GetMemoryRemoteAddressNV&             args) override;

    void Process_vkCmdSetDepthBiasEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBiasEnableEXT&             args) override;

    void Process_vkCmdSetLogicOpEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLogicOpEXT&                     args) override;

    void Process_vkCmdSetPatchControlPointsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPatchControlPointsEXT&          args) override;

    void Process_vkCmdSetPrimitiveRestartEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveRestartEnableEXT&      args) override;

    void Process_vkCmdSetRasterizerDiscardEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizerDiscardEnableEXT&     args) override;

    void Process_vkCreateScreenSurfaceQNX(
        const ApiCallInfo&                          call_info,
        args::CreateScreenSurfaceQNX&               args) override;

    void Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceScreenPresentationSupportQNX& args) override;

    void Process_vkCmdSetColorWriteEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorWriteEnableEXT&            args) override;

    void Process_vkCmdDrawMultiEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMultiEXT&                      args) override;

    void Process_vkCmdDrawMultiIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMultiIndexedEXT&               args) override;

    void Process_vkBuildMicromapsEXT(
        const ApiCallInfo&                          call_info,
        args::BuildMicromapsEXT&                    args) override;

    void Process_vkCmdBuildMicromapsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBuildMicromapsEXT&                 args) override;

    void Process_vkCmdCopyMemoryToMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToMicromapEXT&           args) override;

    void Process_vkCmdCopyMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMicromapEXT&                   args) override;

    void Process_vkCmdCopyMicromapToMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMicromapToMemoryEXT&           args) override;

    void Process_vkCmdWriteMicromapsPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::CmdWriteMicromapsPropertiesEXT&       args) override;

    void Process_vkCopyMemoryToMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CopyMemoryToMicromapEXT&              args) override;

    void Process_vkCopyMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CopyMicromapEXT&                      args) override;

    void Process_vkCopyMicromapToMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CopyMicromapToMemoryEXT&              args) override;

    void Process_vkCreateMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CreateMicromapEXT&                    args) override;

    void Process_vkDestroyMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyMicromapEXT&                   args) override;

    void Process_vkGetDeviceMicromapCompatibilityEXT(
        const ApiCallInfo&                          call_info,
        args::GetDeviceMicromapCompatibilityEXT&    args) override;

    void Process_vkGetMicromapBuildSizesEXT(
        const ApiCallInfo&                          call_info,
        args::GetMicromapBuildSizesEXT&             args) override;

    void Process_vkWriteMicromapsPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::WriteMicromapsPropertiesEXT&          args) override;

    void Process_vkCmdDrawClusterHUAWEI(
        const ApiCallInfo&                          call_info,
        args::CmdDrawClusterHUAWEI&                 args) override;

    void Process_vkCmdDrawClusterIndirectHUAWEI(
        const ApiCallInfo&                          call_info,
        args::CmdDrawClusterIndirectHUAWEI&         args) override;

    void Process_vkSetDeviceMemoryPriorityEXT(
        const ApiCallInfo&                          call_info,
        args::SetDeviceMemoryPriorityEXT&           args) override;

    void Process_vkCmdSetDispatchParametersARM(
        const ApiCallInfo&                          call_info,
        args::CmdSetDispatchParametersARM&          args) override;

    void Process_vkGetDescriptorSetHostMappingVALVE(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetHostMappingVALVE&     args) override;

    void Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutHostMappingInfoVALVE& args) override;

    void Process_vkCmdUpdatePipelineIndirectBufferNV(
        const ApiCallInfo&                          call_info,
        args::CmdUpdatePipelineIndirectBufferNV&    args) override;

    void Process_vkGetPipelineIndirectDeviceAddressNV(
        const ApiCallInfo&                          call_info,
        args::GetPipelineIndirectDeviceAddressNV&   args) override;

    void Process_vkGetPipelineIndirectMemoryRequirementsNV(
        const ApiCallInfo&                          call_info,
        args::GetPipelineIndirectMemoryRequirementsNV& args) override;

    void Process_vkCmdSetAlphaToCoverageEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetAlphaToCoverageEnableEXT&       args) override;

    void Process_vkCmdSetAlphaToOneEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetAlphaToOneEnableEXT&            args) override;

    void Process_vkCmdSetColorBlendAdvancedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorBlendAdvancedEXT&          args) override;

    void Process_vkCmdSetColorBlendEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorBlendEnableEXT&            args) override;

    void Process_vkCmdSetColorBlendEquationEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorBlendEquationEXT&          args) override;

    void Process_vkCmdSetColorWriteMaskEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorWriteMaskEXT&              args) override;

    void Process_vkCmdSetConservativeRasterizationModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetConservativeRasterizationModeEXT& args) override;

    void Process_vkCmdSetCoverageModulationModeNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageModulationModeNV&       args) override;

    void Process_vkCmdSetCoverageModulationTableEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageModulationTableEnableNV& args) override;

    void Process_vkCmdSetCoverageModulationTableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageModulationTableNV&      args) override;

    void Process_vkCmdSetCoverageReductionModeNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageReductionModeNV&        args) override;

    void Process_vkCmdSetCoverageToColorEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageToColorEnableNV&        args) override;

    void Process_vkCmdSetCoverageToColorLocationNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageToColorLocationNV&      args) override;

    void Process_vkCmdSetDepthClampEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClampEnableEXT&            args) override;

    void Process_vkCmdSetDepthClipEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClipEnableEXT&             args) override;

    void Process_vkCmdSetDepthClipNegativeOneToOneEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClipNegativeOneToOneEXT&   args) override;

    void Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetExtraPrimitiveOverestimationSizeEXT& args) override;

    void Process_vkCmdSetLineRasterizationModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineRasterizationModeEXT&       args) override;

    void Process_vkCmdSetLineStippleEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStippleEnableEXT&           args) override;

    void Process_vkCmdSetLogicOpEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLogicOpEnableEXT&               args) override;

    void Process_vkCmdSetPolygonModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPolygonModeEXT&                 args) override;

    void Process_vkCmdSetProvokingVertexModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetProvokingVertexModeEXT&         args) override;

    void Process_vkCmdSetRasterizationSamplesEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizationSamplesEXT&        args) override;

    void Process_vkCmdSetRasterizationStreamEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizationStreamEXT&         args) override;

    void Process_vkCmdSetRepresentativeFragmentTestEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetRepresentativeFragmentTestEnableNV& args) override;

    void Process_vkCmdSetSampleLocationsEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetSampleLocationsEnableEXT&       args) override;

    void Process_vkCmdSetSampleMaskEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetSampleMaskEXT&                  args) override;

    void Process_vkCmdSetShadingRateImageEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetShadingRateImageEnableNV&       args) override;

    void Process_vkCmdSetTessellationDomainOriginEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetTessellationDomainOriginEXT&    args) override;

    void Process_vkCmdSetViewportSwizzleNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportSwizzleNV&              args) override;

    void Process_vkCmdSetViewportWScalingEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWScalingEnableNV&       args) override;

    void Process_vkBindTensorMemoryARM(
        const ApiCallInfo&                          call_info,
        args::BindTensorMemoryARM&                  args) override;

    void Process_vkCmdCopyTensorARM(
        const ApiCallInfo&                          call_info,
        args::CmdCopyTensorARM&                     args) override;

    void Process_vkCreateTensorARM(
        const ApiCallInfo&                          call_info,
        args::CreateTensorARM&                      args) override;

    void Process_vkCreateTensorViewARM(
        const ApiCallInfo&                          call_info,
        args::CreateTensorViewARM&                  args) override;

    void Process_vkDestroyTensorARM(
        const ApiCallInfo&                          call_info,
        args::DestroyTensorARM&                     args) override;

    void Process_vkDestroyTensorViewARM(
        const ApiCallInfo&                          call_info,
        args::DestroyTensorViewARM&                 args) override;

    void Process_vkGetDeviceTensorMemoryRequirementsARM(
        const ApiCallInfo&                          call_info,
        args::GetDeviceTensorMemoryRequirementsARM& args) override;

    void Process_vkGetPhysicalDeviceExternalTensorPropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalTensorPropertiesARM& args) override;

    void Process_vkGetTensorMemoryRequirementsARM(
        const ApiCallInfo&                          call_info,
        args::GetTensorMemoryRequirementsARM&       args) override;

    void Process_vkGetShaderModuleCreateInfoIdentifierEXT(
        const ApiCallInfo&                          call_info,
        args::GetShaderModuleCreateInfoIdentifierEXT& args) override;

    void Process_vkGetShaderModuleIdentifierEXT(
        const ApiCallInfo&                          call_info,
        args::GetShaderModuleIdentifierEXT&         args) override;

    void Process_vkBindOpticalFlowSessionImageNV(
        const ApiCallInfo&                          call_info,
        args::BindOpticalFlowSessionImageNV&        args) override;

    void Process_vkCmdOpticalFlowExecuteNV(
        const ApiCallInfo&                          call_info,
        args::CmdOpticalFlowExecuteNV&              args) override;

    void Process_vkCreateOpticalFlowSessionNV(
        const ApiCallInfo&                          call_info,
        args::CreateOpticalFlowSessionNV&           args) override;

    void Process_vkDestroyOpticalFlowSessionNV(
        const ApiCallInfo&                          call_info,
        args::DestroyOpticalFlowSessionNV&          args) override;

    void Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceOpticalFlowImageFormatsNV& args) override;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

    void Process_vkAntiLagUpdateAMD(
        const ApiCallInfo&                          call_info,
        args::AntiLagUpdateAMD&                     args) override;

    void Process_vkCmdBindShadersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindShadersEXT&                    args) override;

    void Process_vkCmdSetDepthClampRangeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClampRangeEXT&             args) override;

    void Process_vkCreateShadersEXT(
        const ApiCallInfo&                          call_info,
        args::CreateShadersEXT&                     args) override;

    void Process_vkDestroyShaderEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyShaderEXT&                     args) override;

    void Process_vkGetShaderBinaryDataEXT(
        const ApiCallInfo&                          call_info,
        args::GetShaderBinaryDataEXT&               args) override;

    void Process_vkGetDynamicRenderingTilePropertiesQCOM(
        const ApiCallInfo&                          call_info,
        args::GetDynamicRenderingTilePropertiesQCOM& args) override;

    void Process_vkGetFramebufferTilePropertiesQCOM(
        const ApiCallInfo&                          call_info,
        args::GetFramebufferTilePropertiesQCOM&     args) override;

    void Process_vkCmdConvertCooperativeVectorMatrixNV(
        const ApiCallInfo&                          call_info,
        args::CmdConvertCooperativeVectorMatrixNV&  args) override;

    void Process_vkConvertCooperativeVectorMatrixNV(
        const ApiCallInfo&                          call_info,
        args::ConvertCooperativeVectorMatrixNV&     args) override;

    void Process_vkGetPhysicalDeviceCooperativeVectorPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCooperativeVectorPropertiesNV& args) override;

    void Process_vkGetLatencyTimingsNV(
        const ApiCallInfo&                          call_info,
        args::GetLatencyTimingsNV&                  args) override;

    void Process_vkLatencySleepNV(
        const ApiCallInfo&                          call_info,
        args::LatencySleepNV&                       args) override;

    void Process_vkQueueNotifyOutOfBandNV(
        const ApiCallInfo&                          call_info,
        args::QueueNotifyOutOfBandNV&               args) override;

    void Process_vkSetLatencyMarkerNV(
        const ApiCallInfo&                          call_info,
        args::SetLatencyMarkerNV&                   args) override;

    void Process_vkSetLatencySleepModeNV(
        const ApiCallInfo&                          call_info,
        args::SetLatencySleepModeNV&                args) override;

    void Process_vkBindDataGraphPipelineSessionMemoryARM(
        const ApiCallInfo&                          call_info,
        args::BindDataGraphPipelineSessionMemoryARM& args) override;

    void Process_vkCmdDispatchDataGraphARM(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchDataGraphARM&              args) override;

    void Process_vkCreateDataGraphPipelineSessionARM(
        const ApiCallInfo&                          call_info,
        args::CreateDataGraphPipelineSessionARM&    args) override;

    void Process_vkCreateDataGraphPipelinesARM(
        const ApiCallInfo&                          call_info,
        args::CreateDataGraphPipelinesARM&          args) override;

    void Process_vkDestroyDataGraphPipelineSessionARM(
        const ApiCallInfo&                          call_info,
        args::DestroyDataGraphPipelineSessionARM&   args) override;

    void Process_vkGetDataGraphPipelineAvailablePropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetDataGraphPipelineAvailablePropertiesARM& args) override;

    void Process_vkGetDataGraphPipelinePropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetDataGraphPipelinePropertiesARM&    args) override;

    void Process_vkGetDataGraphPipelineSessionBindPointRequirementsARM(
        const ApiCallInfo&                          call_info,
        args::GetDataGraphPipelineSessionBindPointRequirementsARM& args) override;

    void Process_vkGetDataGraphPipelineSessionMemoryRequirementsARM(
        const ApiCallInfo&                          call_info,
        args::GetDataGraphPipelineSessionMemoryRequirementsARM& args) override;

    void Process_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM& args) override;

    void Process_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM& args) override;

    void Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetAttachmentFeedbackLoopEnableEXT& args) override;

    void Process_vkCmdBindTileMemoryQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdBindTileMemoryQCOM&                args) override;

    void Process_vkCmdDecompressMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDecompressMemoryEXT&               args) override;

    void Process_vkCmdDecompressMemoryIndirectCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDecompressMemoryIndirectCountEXT&  args) override;

    void Process_vkCmdBuildPartitionedAccelerationStructuresNV(
        const ApiCallInfo&                          call_info,
        args::CmdBuildPartitionedAccelerationStructuresNV& args) override;

    void Process_vkGetPartitionedAccelerationStructuresBuildSizesNV(
        const ApiCallInfo&                          call_info,
        args::GetPartitionedAccelerationStructuresBuildSizesNV& args) override;

    void Process_vkCmdExecuteGeneratedCommandsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdExecuteGeneratedCommandsEXT&       args) override;

    void Process_vkCmdPreprocessGeneratedCommandsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdPreprocessGeneratedCommandsEXT&    args) override;

    void Process_vkCreateIndirectCommandsLayoutEXT(
        const ApiCallInfo&                          call_info,
        args::CreateIndirectCommandsLayoutEXT&      args) override;

    void Process_vkCreateIndirectExecutionSetEXT(
        const ApiCallInfo&                          call_info,
        args::CreateIndirectExecutionSetEXT&        args) override;

    void Process_vkDestroyIndirectCommandsLayoutEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyIndirectCommandsLayoutEXT&     args) override;

    void Process_vkDestroyIndirectExecutionSetEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyIndirectExecutionSetEXT&       args) override;

    void Process_vkGetGeneratedCommandsMemoryRequirementsEXT(
        const ApiCallInfo&                          call_info,
        args::GetGeneratedCommandsMemoryRequirementsEXT& args) override;

    void Process_vkUpdateIndirectExecutionSetPipelineEXT(
        const ApiCallInfo&                          call_info,
        args::UpdateIndirectExecutionSetPipelineEXT& args) override;

    void Process_vkUpdateIndirectExecutionSetShaderEXT(
        const ApiCallInfo&                          call_info,
        args::UpdateIndirectExecutionSetShaderEXT&  args) override;

    void Process_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV& args) override;

    void Process_vkGetMemoryMetalHandleEXT(
        const ApiCallInfo&                          call_info,
        args::GetMemoryMetalHandleEXT&              args) override;

    void Process_vkGetMemoryMetalHandlePropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetMemoryMetalHandlePropertiesEXT&    args) override;

    void Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM& args) override;

    void Process_vkCmdEndRendering2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndRendering2EXT&                  args) override;

    void Process_vkCmdBeginCustomResolveEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginCustomResolveEXT&             args) override;

    void Process_vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM& args) override;

    void Process_vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM& args) override;

    void Process_vkCmdSetComputeOccupancyPriorityNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetComputeOccupancyPriorityNV&     args) override;

    void Process_vkGetPhysicalDeviceCooperativeMatrixProperties2EXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCooperativeMatrixProperties2EXT& args) override;

    void Process_vkCmdSetPrimitiveRestartIndexEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveRestartIndexEXT&       args) override;

    void Process_vkCmdBuildAccelerationStructuresIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBuildAccelerationStructuresIndirectKHR& args) override;

    void Process_vkCmdBuildAccelerationStructuresKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBuildAccelerationStructuresKHR&    args) override;

    void Process_vkCmdCopyAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyAccelerationStructureKHR&      args) override;

    void Process_vkCmdCopyAccelerationStructureToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyAccelerationStructureToMemoryKHR& args) override;

    void Process_vkCmdCopyMemoryToAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToAccelerationStructureKHR& args) override;

    void Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::CmdWriteAccelerationStructuresPropertiesKHR& args) override;

    void Process_vkCopyAccelerationStructureToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CopyAccelerationStructureToMemoryKHR& args) override;

    void Process_vkCopyMemoryToAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CopyMemoryToAccelerationStructureKHR& args) override;

    void Process_vkCreateAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CreateAccelerationStructureKHR&       args) override;

    void Process_vkDestroyAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyAccelerationStructureKHR&      args) override;

    void Process_vkGetAccelerationStructureBuildSizesKHR(
        const ApiCallInfo&                          call_info,
        args::GetAccelerationStructureBuildSizesKHR& args) override;

    void Process_vkGetAccelerationStructureDeviceAddressKHR(
        const ApiCallInfo&                          call_info,
        args::GetAccelerationStructureDeviceAddressKHR& args) override;

    void Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceAccelerationStructureCompatibilityKHR& args) override;

    void Process_vkWriteAccelerationStructuresPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::WriteAccelerationStructuresPropertiesKHR& args) override;

    void Process_vkCreateRayTracingPipelinesKHR(
        const ApiCallInfo&                  call_info,
        args::CreateRayTracingPipelinesKHR& args) override;

    void Process_vkCmdSetRayTracingPipelineStackSizeKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetRayTracingPipelineStackSizeKHR& args) override;

    void Process_vkCmdTraceRaysIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysIndirectKHR&              args) override;

    void Process_vkCmdTraceRaysKHR(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysKHR&                      args) override;

    void Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
        const ApiCallInfo&                          call_info,
        args::GetRayTracingCaptureReplayShaderGroupHandlesKHR& args) override;

    void Process_vkGetRayTracingShaderGroupStackSizeKHR(
        const ApiCallInfo&                          call_info,
        args::GetRayTracingShaderGroupStackSizeKHR& args) override;

    void Process_vkCmdDrawMeshTasksEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksEXT&                  args) override;

    void Process_vkCmdDrawMeshTasksIndirectCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectCountEXT&     args) override;

    void Process_vkCmdDrawMeshTasksIndirectEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectEXT&          args) override;

  private:
    VkAccelerationStructureKHR MaterializeVkAccelerationStructureKHR(format::HandleId id);
    VkAccelerationStructureNV MaterializeVkAccelerationStructureNV(format::HandleId id);
    VkBuffer MaterializeVkBuffer(format::HandleId id);
    VkBufferView MaterializeVkBufferView(format::HandleId id);
    VkCommandBuffer MaterializeVkCommandBuffer(format::HandleId id);
    VkCommandPool MaterializeVkCommandPool(format::HandleId id);
    VkDataGraphPipelineSessionARM MaterializeVkDataGraphPipelineSessionARM(format::HandleId id);
    VkDebugReportCallbackEXT MaterializeVkDebugReportCallbackEXT(format::HandleId id);
    VkDebugUtilsMessengerEXT MaterializeVkDebugUtilsMessengerEXT(format::HandleId id);
    VkDeferredOperationKHR MaterializeVkDeferredOperationKHR(format::HandleId id);
    VkDescriptorPool MaterializeVkDescriptorPool(format::HandleId id);
    VkDescriptorSet MaterializeVkDescriptorSet(format::HandleId id);
    VkDescriptorSetLayout MaterializeVkDescriptorSetLayout(format::HandleId id);
    VkDescriptorUpdateTemplate MaterializeVkDescriptorUpdateTemplate(format::HandleId id);
    VkDescriptorUpdateTemplateKHR MaterializeVkDescriptorUpdateTemplateKHR(format::HandleId id);
    VkDevice MaterializeVkDevice(format::HandleId id);
    VkDeviceMemory MaterializeVkDeviceMemory(format::HandleId id);
    VkDisplayKHR MaterializeVkDisplayKHR(format::HandleId id);
    VkDisplayModeKHR MaterializeVkDisplayModeKHR(format::HandleId id);
    VkEvent MaterializeVkEvent(format::HandleId id);
    VkFence MaterializeVkFence(format::HandleId id);
    VkFramebuffer MaterializeVkFramebuffer(format::HandleId id);
    VkImage MaterializeVkImage(format::HandleId id);
    VkImageView MaterializeVkImageView(format::HandleId id);
    VkIndirectCommandsLayoutEXT MaterializeVkIndirectCommandsLayoutEXT(format::HandleId id);
    VkIndirectCommandsLayoutNV MaterializeVkIndirectCommandsLayoutNV(format::HandleId id);
    VkIndirectExecutionSetEXT MaterializeVkIndirectExecutionSetEXT(format::HandleId id);
    VkInstance MaterializeVkInstance(format::HandleId id);
    VkMicromapEXT MaterializeVkMicromapEXT(format::HandleId id);
    VkOpticalFlowSessionNV MaterializeVkOpticalFlowSessionNV(format::HandleId id);
    VkPerformanceConfigurationINTEL MaterializeVkPerformanceConfigurationINTEL(format::HandleId id);
    VkPhysicalDevice MaterializeVkPhysicalDevice(format::HandleId id);
    VkPipeline MaterializeVkPipeline(format::HandleId id);
    VkPipelineBinaryKHR MaterializeVkPipelineBinaryKHR(format::HandleId id);
    VkPipelineCache MaterializeVkPipelineCache(format::HandleId id);
    VkPipelineLayout MaterializeVkPipelineLayout(format::HandleId id);
    VkPrivateDataSlot MaterializeVkPrivateDataSlot(format::HandleId id);
    VkPrivateDataSlotEXT MaterializeVkPrivateDataSlotEXT(format::HandleId id);
    VkQueryPool MaterializeVkQueryPool(format::HandleId id);
    VkQueue MaterializeVkQueue(format::HandleId id);
    VkRenderPass MaterializeVkRenderPass(format::HandleId id);
    VkSampler MaterializeVkSampler(format::HandleId id);
    VkSamplerYcbcrConversion MaterializeVkSamplerYcbcrConversion(format::HandleId id);
    VkSamplerYcbcrConversionKHR MaterializeVkSamplerYcbcrConversionKHR(format::HandleId id);
    VkSemaphore MaterializeVkSemaphore(format::HandleId id);
    VkShaderEXT MaterializeVkShaderEXT(format::HandleId id);
    VkShaderModule MaterializeVkShaderModule(format::HandleId id);
    VkSurfaceKHR MaterializeVkSurfaceKHR(format::HandleId id);
    VkSwapchainKHR MaterializeVkSwapchainKHR(format::HandleId id);
    VkTensorARM MaterializeVkTensorARM(format::HandleId id);
    VkTensorViewARM MaterializeVkTensorViewARM(format::HandleId id);
    VkValidationCacheEXT MaterializeVkValidationCacheEXT(format::HandleId id);
    VkVideoSessionKHR MaterializeVkVideoSessionKHR(format::HandleId id);
    VkVideoSessionParametersKHR MaterializeVkVideoSessionParametersKHR(format::HandleId id);
};

const VulkanNativeCommandInfo* GetVulkanNativeCommandInfo(const char* name);

const VulkanNativeCommandInfo* GetVulkanNativeCommandInfo(uint32_t call_id);

const char* GetVulkanApiCallName(uint32_t call_id);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_NATIVE_CALL_CONSUMER_H
