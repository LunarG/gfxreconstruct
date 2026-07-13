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

#ifndef  GFXRECON_GENERATED_VULKAN_CONSUMER_H
#define  GFXRECON_GENERATED_VULKAN_CONSUMER_H

#include "decode/vulkan_consumer_base.h"
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
class VulkanConsumer : public VulkanConsumerBase
{
  public:
    VulkanConsumer() { }

    virtual ~VulkanConsumer() override { }

    virtual void Process_vkCreateInstance(
        const ApiCallInfo&                          call_info,
        args::CreateInstance&                       args) {}

    virtual void Process_vkDestroyInstance(
        const ApiCallInfo&                          call_info,
        args::DestroyInstance&                      args) {}

    virtual void Process_vkEnumeratePhysicalDevices(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDevices&             args) {}

    virtual void Process_vkGetPhysicalDeviceFeatures(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFeatures&            args) {}

    virtual void Process_vkGetPhysicalDeviceFormatProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFormatProperties&    args) {}

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceImageFormatProperties& args) {}

    virtual void Process_vkGetPhysicalDeviceProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceProperties&          args) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyProperties& args) {}

    virtual void Process_vkGetPhysicalDeviceMemoryProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceMemoryProperties&    args) {}

    virtual void Process_vkCreateDevice(
        const ApiCallInfo&                          call_info,
        args::CreateDevice&                         args) {}

    virtual void Process_vkDestroyDevice(
        const ApiCallInfo&                          call_info,
        args::DestroyDevice&                        args) {}

    virtual void Process_vkGetDeviceQueue(
        const ApiCallInfo&                          call_info,
        args::GetDeviceQueue&                       args) {}

    virtual void Process_vkQueueSubmit(
        const ApiCallInfo&                          call_info,
        args::QueueSubmit&                          args) {}

    virtual void Process_vkQueueWaitIdle(
        const ApiCallInfo&                          call_info,
        args::QueueWaitIdle&                        args) {}

    virtual void Process_vkDeviceWaitIdle(
        const ApiCallInfo&                          call_info,
        args::DeviceWaitIdle&                       args) {}

    virtual void Process_vkAllocateMemory(
        const ApiCallInfo&                          call_info,
        args::AllocateMemory&                       args) {}

    virtual void Process_vkFreeMemory(
        const ApiCallInfo&                          call_info,
        args::FreeMemory&                           args) {}

    virtual void Process_vkMapMemory(
        const ApiCallInfo&                          call_info,
        args::MapMemory&                            args) {}

    virtual void Process_vkUnmapMemory(
        const ApiCallInfo&                          call_info,
        args::UnmapMemory&                          args) {}

    virtual void Process_vkFlushMappedMemoryRanges(
        const ApiCallInfo&                          call_info,
        args::FlushMappedMemoryRanges&              args) {}

    virtual void Process_vkInvalidateMappedMemoryRanges(
        const ApiCallInfo&                          call_info,
        args::InvalidateMappedMemoryRanges&         args) {}

    virtual void Process_vkGetDeviceMemoryCommitment(
        const ApiCallInfo&                          call_info,
        args::GetDeviceMemoryCommitment&            args) {}

    virtual void Process_vkBindBufferMemory(
        const ApiCallInfo&                          call_info,
        args::BindBufferMemory&                     args) {}

    virtual void Process_vkBindImageMemory(
        const ApiCallInfo&                          call_info,
        args::BindImageMemory&                      args) {}

    virtual void Process_vkGetBufferMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetBufferMemoryRequirements&          args) {}

    virtual void Process_vkGetImageMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetImageMemoryRequirements&           args) {}

    virtual void Process_vkGetImageSparseMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetImageSparseMemoryRequirements&     args) {}

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSparseImageFormatProperties& args) {}

    virtual void Process_vkQueueBindSparse(
        const ApiCallInfo&                          call_info,
        args::QueueBindSparse&                      args) {}

    virtual void Process_vkCreateFence(
        const ApiCallInfo&                          call_info,
        args::CreateFence&                          args) {}

    virtual void Process_vkDestroyFence(
        const ApiCallInfo&                          call_info,
        args::DestroyFence&                         args) {}

    virtual void Process_vkResetFences(
        const ApiCallInfo&                          call_info,
        args::ResetFences&                          args) {}

    virtual void Process_vkGetFenceStatus(
        const ApiCallInfo&                          call_info,
        args::GetFenceStatus&                       args) {}

    virtual void Process_vkWaitForFences(
        const ApiCallInfo&                          call_info,
        args::WaitForFences&                        args) {}

    virtual void Process_vkCreateSemaphore(
        const ApiCallInfo&                          call_info,
        args::CreateSemaphore&                      args) {}

    virtual void Process_vkDestroySemaphore(
        const ApiCallInfo&                          call_info,
        args::DestroySemaphore&                     args) {}

    virtual void Process_vkCreateQueryPool(
        const ApiCallInfo&                          call_info,
        args::CreateQueryPool&                      args) {}

    virtual void Process_vkDestroyQueryPool(
        const ApiCallInfo&                          call_info,
        args::DestroyQueryPool&                     args) {}

    virtual void Process_vkGetQueryPoolResults(
        const ApiCallInfo&                          call_info,
        args::GetQueryPoolResults&                  args) {}

    virtual void Process_vkCreateBuffer(
        const ApiCallInfo&                          call_info,
        args::CreateBuffer&                         args) {}

    virtual void Process_vkDestroyBuffer(
        const ApiCallInfo&                          call_info,
        args::DestroyBuffer&                        args) {}

    virtual void Process_vkCreateImage(
        const ApiCallInfo&                          call_info,
        args::CreateImage&                          args) {}

    virtual void Process_vkDestroyImage(
        const ApiCallInfo&                          call_info,
        args::DestroyImage&                         args) {}

    virtual void Process_vkGetImageSubresourceLayout(
        const ApiCallInfo&                          call_info,
        args::GetImageSubresourceLayout&            args) {}

    virtual void Process_vkCreateImageView(
        const ApiCallInfo&                          call_info,
        args::CreateImageView&                      args) {}

    virtual void Process_vkDestroyImageView(
        const ApiCallInfo&                          call_info,
        args::DestroyImageView&                     args) {}

    virtual void Process_vkCreateCommandPool(
        const ApiCallInfo&                          call_info,
        args::CreateCommandPool&                    args) {}

    virtual void Process_vkDestroyCommandPool(
        const ApiCallInfo&                          call_info,
        args::DestroyCommandPool&                   args) {}

    virtual void Process_vkResetCommandPool(
        const ApiCallInfo&                          call_info,
        args::ResetCommandPool&                     args) {}

    virtual void Process_vkAllocateCommandBuffers(
        const ApiCallInfo&                          call_info,
        args::AllocateCommandBuffers&               args) {}

    virtual void Process_vkFreeCommandBuffers(
        const ApiCallInfo&                          call_info,
        args::FreeCommandBuffers&                   args) {}

    virtual void Process_vkBeginCommandBuffer(
        const ApiCallInfo&                          call_info,
        args::BeginCommandBuffer&                   args) {}

    virtual void Process_vkEndCommandBuffer(
        const ApiCallInfo&                          call_info,
        args::EndCommandBuffer&                     args) {}

    virtual void Process_vkResetCommandBuffer(
        const ApiCallInfo&                          call_info,
        args::ResetCommandBuffer&                   args) {}

    virtual void Process_vkCmdCopyBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBuffer&                        args) {}

    virtual void Process_vkCmdCopyImage(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImage&                         args) {}

    virtual void Process_vkCmdCopyBufferToImage(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBufferToImage&                 args) {}

    virtual void Process_vkCmdCopyImageToBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToBuffer&                 args) {}

    virtual void Process_vkCmdUpdateBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdUpdateBuffer&                      args) {}

    virtual void Process_vkCmdFillBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdFillBuffer&                        args) {}

    virtual void Process_vkCmdPipelineBarrier(
        const ApiCallInfo&                          call_info,
        args::CmdPipelineBarrier&                   args) {}

    virtual void Process_vkCmdBeginQuery(
        const ApiCallInfo&                          call_info,
        args::CmdBeginQuery&                        args) {}

    virtual void Process_vkCmdEndQuery(
        const ApiCallInfo&                          call_info,
        args::CmdEndQuery&                          args) {}

    virtual void Process_vkCmdResetQueryPool(
        const ApiCallInfo&                          call_info,
        args::CmdResetQueryPool&                    args) {}

    virtual void Process_vkCmdWriteTimestamp(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp&                    args) {}

    virtual void Process_vkCmdCopyQueryPoolResults(
        const ApiCallInfo&                          call_info,
        args::CmdCopyQueryPoolResults&              args) {}

    virtual void Process_vkCmdExecuteCommands(
        const ApiCallInfo&                          call_info,
        args::CmdExecuteCommands&                   args) {}

    virtual void Process_vkCreateEvent(
        const ApiCallInfo&                          call_info,
        args::CreateEvent&                          args) {}

    virtual void Process_vkDestroyEvent(
        const ApiCallInfo&                          call_info,
        args::DestroyEvent&                         args) {}

    virtual void Process_vkGetEventStatus(
        const ApiCallInfo&                          call_info,
        args::GetEventStatus&                       args) {}

    virtual void Process_vkSetEvent(
        const ApiCallInfo&                          call_info,
        args::SetEvent&                             args) {}

    virtual void Process_vkResetEvent(
        const ApiCallInfo&                          call_info,
        args::ResetEvent&                           args) {}

    virtual void Process_vkCreateBufferView(
        const ApiCallInfo&                          call_info,
        args::CreateBufferView&                     args) {}

    virtual void Process_vkDestroyBufferView(
        const ApiCallInfo&                          call_info,
        args::DestroyBufferView&                    args) {}

    virtual void Process_vkCreateShaderModule(
        const ApiCallInfo&                          call_info,
        args::CreateShaderModule&                   args) {}

    virtual void Process_vkDestroyShaderModule(
        const ApiCallInfo&                          call_info,
        args::DestroyShaderModule&                  args) {}

    virtual void Process_vkCreatePipelineCache(
        const ApiCallInfo&                          call_info,
        args::CreatePipelineCache&                  args) {}

    virtual void Process_vkDestroyPipelineCache(
        const ApiCallInfo&                          call_info,
        args::DestroyPipelineCache&                 args) {}

    virtual void Process_vkGetPipelineCacheData(
        const ApiCallInfo&                          call_info,
        args::GetPipelineCacheData&                 args) {}

    virtual void Process_vkMergePipelineCaches(
        const ApiCallInfo&                          call_info,
        args::MergePipelineCaches&                  args) {}

    virtual void Process_vkCreateComputePipelines(
        const ApiCallInfo&                          call_info,
        args::CreateComputePipelines&               args) {}

    virtual void Process_vkDestroyPipeline(
        const ApiCallInfo&                          call_info,
        args::DestroyPipeline&                      args) {}

    virtual void Process_vkCreatePipelineLayout(
        const ApiCallInfo&                          call_info,
        args::CreatePipelineLayout&                 args) {}

    virtual void Process_vkDestroyPipelineLayout(
        const ApiCallInfo&                          call_info,
        args::DestroyPipelineLayout&                args) {}

    virtual void Process_vkCreateSampler(
        const ApiCallInfo&                          call_info,
        args::CreateSampler&                        args) {}

    virtual void Process_vkDestroySampler(
        const ApiCallInfo&                          call_info,
        args::DestroySampler&                       args) {}

    virtual void Process_vkCreateDescriptorSetLayout(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorSetLayout&            args) {}

    virtual void Process_vkDestroyDescriptorSetLayout(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorSetLayout&           args) {}

    virtual void Process_vkCreateDescriptorPool(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorPool&                 args) {}

    virtual void Process_vkDestroyDescriptorPool(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorPool&                args) {}

    virtual void Process_vkResetDescriptorPool(
        const ApiCallInfo&                          call_info,
        args::ResetDescriptorPool&                  args) {}

    virtual void Process_vkAllocateDescriptorSets(
        const ApiCallInfo&                          call_info,
        args::AllocateDescriptorSets&               args) {}

    virtual void Process_vkFreeDescriptorSets(
        const ApiCallInfo&                          call_info,
        args::FreeDescriptorSets&                   args) {}

    virtual void Process_vkUpdateDescriptorSets(
        const ApiCallInfo&                          call_info,
        args::UpdateDescriptorSets&                 args) {}

    virtual void Process_vkCmdBindPipeline(
        const ApiCallInfo&                          call_info,
        args::CmdBindPipeline&                      args) {}

    virtual void Process_vkCmdBindDescriptorSets(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorSets&                args) {}

    virtual void Process_vkCmdClearColorImage(
        const ApiCallInfo&                          call_info,
        args::CmdClearColorImage&                   args) {}

    virtual void Process_vkCmdDispatch(
        const ApiCallInfo&                          call_info,
        args::CmdDispatch&                          args) {}

    virtual void Process_vkCmdDispatchIndirect(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchIndirect&                  args) {}

    virtual void Process_vkCmdSetEvent(
        const ApiCallInfo&                          call_info,
        args::CmdSetEvent&                          args) {}

    virtual void Process_vkCmdResetEvent(
        const ApiCallInfo&                          call_info,
        args::CmdResetEvent&                        args) {}

    virtual void Process_vkCmdWaitEvents(
        const ApiCallInfo&                          call_info,
        args::CmdWaitEvents&                        args) {}

    virtual void Process_vkCmdPushConstants(
        const ApiCallInfo&                          call_info,
        args::CmdPushConstants&                     args) {}

    virtual void Process_vkCreateGraphicsPipelines(
        const ApiCallInfo&                          call_info,
        args::CreateGraphicsPipelines&              args) {}

    virtual void Process_vkCreateFramebuffer(
        const ApiCallInfo&                          call_info,
        args::CreateFramebuffer&                    args) {}

    virtual void Process_vkDestroyFramebuffer(
        const ApiCallInfo&                          call_info,
        args::DestroyFramebuffer&                   args) {}

    virtual void Process_vkCreateRenderPass(
        const ApiCallInfo&                          call_info,
        args::CreateRenderPass&                     args) {}

    virtual void Process_vkDestroyRenderPass(
        const ApiCallInfo&                          call_info,
        args::DestroyRenderPass&                    args) {}

    virtual void Process_vkGetRenderAreaGranularity(
        const ApiCallInfo&                          call_info,
        args::GetRenderAreaGranularity&             args) {}

    virtual void Process_vkCmdSetViewport(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewport&                       args) {}

    virtual void Process_vkCmdSetScissor(
        const ApiCallInfo&                          call_info,
        args::CmdSetScissor&                        args) {}

    virtual void Process_vkCmdSetLineWidth(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineWidth&                      args) {}

    virtual void Process_vkCmdSetDepthBias(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBias&                      args) {}

    virtual void Process_vkCmdSetBlendConstants(
        const ApiCallInfo&                          call_info,
        args::CmdSetBlendConstants&                 args) {}

    virtual void Process_vkCmdSetDepthBounds(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBounds&                    args) {}

    virtual void Process_vkCmdSetStencilCompareMask(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilCompareMask&             args) {}

    virtual void Process_vkCmdSetStencilWriteMask(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilWriteMask&               args) {}

    virtual void Process_vkCmdSetStencilReference(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilReference&               args) {}

    virtual void Process_vkCmdBindIndexBuffer(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer&                   args) {}

    virtual void Process_vkCmdBindVertexBuffers(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers&                 args) {}

    virtual void Process_vkCmdDraw(
        const ApiCallInfo&                          call_info,
        args::CmdDraw&                              args) {}

    virtual void Process_vkCmdDrawIndexed(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexed&                       args) {}

    virtual void Process_vkCmdDrawIndirect(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirect&                      args) {}

    virtual void Process_vkCmdDrawIndexedIndirect(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirect&               args) {}

    virtual void Process_vkCmdBlitImage(
        const ApiCallInfo&                          call_info,
        args::CmdBlitImage&                         args) {}

    virtual void Process_vkCmdClearDepthStencilImage(
        const ApiCallInfo&                          call_info,
        args::CmdClearDepthStencilImage&            args) {}

    virtual void Process_vkCmdClearAttachments(
        const ApiCallInfo&                          call_info,
        args::CmdClearAttachments&                  args) {}

    virtual void Process_vkCmdResolveImage(
        const ApiCallInfo&                          call_info,
        args::CmdResolveImage&                      args) {}

    virtual void Process_vkCmdBeginRenderPass(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderPass&                   args) {}

    virtual void Process_vkCmdNextSubpass(
        const ApiCallInfo&                          call_info,
        args::CmdNextSubpass&                       args) {}

    virtual void Process_vkCmdEndRenderPass(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderPass&                     args) {}

    virtual void Process_vkBindBufferMemory2(
        const ApiCallInfo&                          call_info,
        args::BindBufferMemory2&                    args) {}

    virtual void Process_vkBindImageMemory2(
        const ApiCallInfo&                          call_info,
        args::BindImageMemory2&                     args) {}

    virtual void Process_vkGetDeviceGroupPeerMemoryFeatures(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupPeerMemoryFeatures&     args) {}

    virtual void Process_vkCmdSetDeviceMask(
        const ApiCallInfo&                          call_info,
        args::CmdSetDeviceMask&                     args) {}

    virtual void Process_vkEnumeratePhysicalDeviceGroups(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDeviceGroups&        args) {}

    virtual void Process_vkGetImageMemoryRequirements2(
        const ApiCallInfo&                          call_info,
        args::GetImageMemoryRequirements2&          args) {}

    virtual void Process_vkGetBufferMemoryRequirements2(
        const ApiCallInfo&                          call_info,
        args::GetBufferMemoryRequirements2&         args) {}

    virtual void Process_vkGetImageSparseMemoryRequirements2(
        const ApiCallInfo&                          call_info,
        args::GetImageSparseMemoryRequirements2&    args) {}

    virtual void Process_vkGetPhysicalDeviceFeatures2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFeatures2&           args) {}

    virtual void Process_vkGetPhysicalDeviceProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceProperties2&         args) {}

    virtual void Process_vkGetPhysicalDeviceFormatProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFormatProperties2&   args) {}

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceImageFormatProperties2& args) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyProperties2& args) {}

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceMemoryProperties2&   args) {}

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSparseImageFormatProperties2& args) {}

    virtual void Process_vkTrimCommandPool(
        const ApiCallInfo&                          call_info,
        args::TrimCommandPool&                      args) {}

    virtual void Process_vkGetDeviceQueue2(
        const ApiCallInfo&                          call_info,
        args::GetDeviceQueue2&                      args) {}

    virtual void Process_vkGetPhysicalDeviceExternalBufferProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalBufferProperties& args) {}

    virtual void Process_vkGetPhysicalDeviceExternalFenceProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalFenceProperties& args) {}

    virtual void Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalSemaphoreProperties& args) {}

    virtual void Process_vkCmdDispatchBase(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchBase&                      args) {}

    virtual void Process_vkCreateDescriptorUpdateTemplate(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorUpdateTemplate&       args) {}

    virtual void Process_vkDestroyDescriptorUpdateTemplate(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorUpdateTemplate&      args) {}

    virtual void Process_vkGetDescriptorSetLayoutSupport(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutSupport&        args) {}

    virtual void Process_vkCreateSamplerYcbcrConversion(
        const ApiCallInfo&                          call_info,
        args::CreateSamplerYcbcrConversion&         args) {}

    virtual void Process_vkDestroySamplerYcbcrConversion(
        const ApiCallInfo&                          call_info,
        args::DestroySamplerYcbcrConversion&        args) {}

    virtual void Process_vkResetQueryPool(
        const ApiCallInfo&                          call_info,
        args::ResetQueryPool&                       args) {}

    virtual void Process_vkGetSemaphoreCounterValue(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreCounterValue&             args) {}

    virtual void Process_vkWaitSemaphores(
        const ApiCallInfo&                          call_info,
        args::WaitSemaphores&                       args) {}

    virtual void Process_vkSignalSemaphore(
        const ApiCallInfo&                          call_info,
        args::SignalSemaphore&                      args) {}

    virtual void Process_vkGetBufferDeviceAddress(
        const ApiCallInfo&                          call_info,
        args::GetBufferDeviceAddress&               args) {}

    virtual void Process_vkGetBufferOpaqueCaptureAddress(
        const ApiCallInfo&                          call_info,
        args::GetBufferOpaqueCaptureAddress&        args) {}

    virtual void Process_vkGetDeviceMemoryOpaqueCaptureAddress(
        const ApiCallInfo&                          call_info,
        args::GetDeviceMemoryOpaqueCaptureAddress&  args) {}

    virtual void Process_vkCmdDrawIndirectCount(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCount&                 args) {}

    virtual void Process_vkCmdDrawIndexedIndirectCount(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCount&          args) {}

    virtual void Process_vkCreateRenderPass2(
        const ApiCallInfo&                          call_info,
        args::CreateRenderPass2&                    args) {}

    virtual void Process_vkCmdBeginRenderPass2(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderPass2&                  args) {}

    virtual void Process_vkCmdNextSubpass2(
        const ApiCallInfo&                          call_info,
        args::CmdNextSubpass2&                      args) {}

    virtual void Process_vkCmdEndRenderPass2(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderPass2&                    args) {}

    virtual void Process_vkGetPhysicalDeviceToolProperties(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceToolProperties&      args) {}

    virtual void Process_vkCreatePrivateDataSlot(
        const ApiCallInfo&                          call_info,
        args::CreatePrivateDataSlot&                args) {}

    virtual void Process_vkDestroyPrivateDataSlot(
        const ApiCallInfo&                          call_info,
        args::DestroyPrivateDataSlot&               args) {}

    virtual void Process_vkSetPrivateData(
        const ApiCallInfo&                          call_info,
        args::SetPrivateData&                       args) {}

    virtual void Process_vkGetPrivateData(
        const ApiCallInfo&                          call_info,
        args::GetPrivateData&                       args) {}

    virtual void Process_vkCmdPipelineBarrier2(
        const ApiCallInfo&                          call_info,
        args::CmdPipelineBarrier2&                  args) {}

    virtual void Process_vkCmdWriteTimestamp2(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp2&                   args) {}

    virtual void Process_vkQueueSubmit2(
        const ApiCallInfo&                          call_info,
        args::QueueSubmit2&                         args) {}

    virtual void Process_vkCmdCopyBuffer2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBuffer2&                       args) {}

    virtual void Process_vkCmdCopyImage2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImage2&                        args) {}

    virtual void Process_vkCmdCopyBufferToImage2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBufferToImage2&                args) {}

    virtual void Process_vkCmdCopyImageToBuffer2(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToBuffer2&                args) {}

    virtual void Process_vkGetDeviceBufferMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetDeviceBufferMemoryRequirements&    args) {}

    virtual void Process_vkGetDeviceImageMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageMemoryRequirements&     args) {}

    virtual void Process_vkGetDeviceImageSparseMemoryRequirements(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageSparseMemoryRequirements& args) {}

    virtual void Process_vkCmdSetEvent2(
        const ApiCallInfo&                          call_info,
        args::CmdSetEvent2&                         args) {}

    virtual void Process_vkCmdResetEvent2(
        const ApiCallInfo&                          call_info,
        args::CmdResetEvent2&                       args) {}

    virtual void Process_vkCmdWaitEvents2(
        const ApiCallInfo&                          call_info,
        args::CmdWaitEvents2&                       args) {}

    virtual void Process_vkCmdBlitImage2(
        const ApiCallInfo&                          call_info,
        args::CmdBlitImage2&                        args) {}

    virtual void Process_vkCmdResolveImage2(
        const ApiCallInfo&                          call_info,
        args::CmdResolveImage2&                     args) {}

    virtual void Process_vkCmdBeginRendering(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRendering&                    args) {}

    virtual void Process_vkCmdEndRendering(
        const ApiCallInfo&                          call_info,
        args::CmdEndRendering&                      args) {}

    virtual void Process_vkCmdSetCullMode(
        const ApiCallInfo&                          call_info,
        args::CmdSetCullMode&                       args) {}

    virtual void Process_vkCmdSetFrontFace(
        const ApiCallInfo&                          call_info,
        args::CmdSetFrontFace&                      args) {}

    virtual void Process_vkCmdSetPrimitiveTopology(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveTopology&              args) {}

    virtual void Process_vkCmdSetViewportWithCount(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWithCount&              args) {}

    virtual void Process_vkCmdSetScissorWithCount(
        const ApiCallInfo&                          call_info,
        args::CmdSetScissorWithCount&               args) {}

    virtual void Process_vkCmdBindVertexBuffers2(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers2&                args) {}

    virtual void Process_vkCmdSetDepthTestEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthTestEnable&                args) {}

    virtual void Process_vkCmdSetDepthWriteEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthWriteEnable&               args) {}

    virtual void Process_vkCmdSetDepthCompareOp(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthCompareOp&                 args) {}

    virtual void Process_vkCmdSetDepthBoundsTestEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBoundsTestEnable&          args) {}

    virtual void Process_vkCmdSetStencilTestEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilTestEnable&              args) {}

    virtual void Process_vkCmdSetStencilOp(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilOp&                      args) {}

    virtual void Process_vkCmdSetRasterizerDiscardEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizerDiscardEnable&        args) {}

    virtual void Process_vkCmdSetDepthBiasEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBiasEnable&                args) {}

    virtual void Process_vkCmdSetPrimitiveRestartEnable(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveRestartEnable&         args) {}

    virtual void Process_vkMapMemory2(
        const ApiCallInfo&                          call_info,
        args::MapMemory2&                           args) {}

    virtual void Process_vkUnmapMemory2(
        const ApiCallInfo&                          call_info,
        args::UnmapMemory2&                         args) {}

    virtual void Process_vkGetDeviceImageSubresourceLayout(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageSubresourceLayout&      args) {}

    virtual void Process_vkGetImageSubresourceLayout2(
        const ApiCallInfo&                          call_info,
        args::GetImageSubresourceLayout2&           args) {}

    virtual void Process_vkCopyMemoryToImage(
        const ApiCallInfo&                          call_info,
        args::CopyMemoryToImage&                    args) {}

    virtual void Process_vkCopyImageToMemory(
        const ApiCallInfo&                          call_info,
        args::CopyImageToMemory&                    args) {}

    virtual void Process_vkCopyImageToImage(
        const ApiCallInfo&                          call_info,
        args::CopyImageToImage&                     args) {}

    virtual void Process_vkTransitionImageLayout(
        const ApiCallInfo&                          call_info,
        args::TransitionImageLayout&                args) {}

    virtual void Process_vkCmdPushDescriptorSet(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSet&                 args) {}

    virtual void Process_vkCmdBindDescriptorSets2(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorSets2&               args) {}

    virtual void Process_vkCmdPushConstants2(
        const ApiCallInfo&                          call_info,
        args::CmdPushConstants2&                    args) {}

    virtual void Process_vkCmdPushDescriptorSet2(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSet2&                args) {}

    virtual void Process_vkCmdSetLineStipple(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStipple&                    args) {}

    virtual void Process_vkCmdBindIndexBuffer2(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer2&                  args) {}

    virtual void Process_vkGetRenderingAreaGranularity(
        const ApiCallInfo&                          call_info,
        args::GetRenderingAreaGranularity&          args) {}

    virtual void Process_vkCmdSetRenderingAttachmentLocations(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingAttachmentLocations&   args) {}

    virtual void Process_vkCmdSetRenderingInputAttachmentIndices(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingInputAttachmentIndices& args) {}

    virtual void Process_vkDestroySurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::DestroySurfaceKHR&                    args) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceSupportKHR&   args) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceCapabilitiesKHR& args) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceFormatsKHR&   args) {}

    virtual void Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfacePresentModesKHR& args) {}

    virtual void Process_vkCreateSwapchainKHR(
        const ApiCallInfo&                          call_info,
        args::CreateSwapchainKHR&                   args) {}

    virtual void Process_vkDestroySwapchainKHR(
        const ApiCallInfo&                          call_info,
        args::DestroySwapchainKHR&                  args) {}

    virtual void Process_vkGetSwapchainImagesKHR(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainImagesKHR&                args) {}

    virtual void Process_vkAcquireNextImageKHR(
        const ApiCallInfo&                          call_info,
        args::AcquireNextImageKHR&                  args) {}

    virtual void Process_vkQueuePresentKHR(
        const ApiCallInfo&                          call_info,
        args::QueuePresentKHR&                      args) {}

    virtual void Process_vkGetDeviceGroupPresentCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupPresentCapabilitiesKHR& args) {}

    virtual void Process_vkGetDeviceGroupSurfacePresentModesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupSurfacePresentModesKHR& args) {}

    virtual void Process_vkGetPhysicalDevicePresentRectanglesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDevicePresentRectanglesKHR& args) {}

    virtual void Process_vkAcquireNextImage2KHR(
        const ApiCallInfo&                          call_info,
        args::AcquireNextImage2KHR&                 args) {}

    virtual void Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDisplayPropertiesKHR& args) {}

    virtual void Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDisplayPlanePropertiesKHR& args) {}

    virtual void Process_vkGetDisplayPlaneSupportedDisplaysKHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayPlaneSupportedDisplaysKHR&  args) {}

    virtual void Process_vkGetDisplayModePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayModePropertiesKHR&          args) {}

    virtual void Process_vkCreateDisplayModeKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDisplayModeKHR&                 args) {}

    virtual void Process_vkGetDisplayPlaneCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayPlaneCapabilitiesKHR&       args) {}

    virtual void Process_vkCreateDisplayPlaneSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDisplayPlaneSurfaceKHR&         args) {}

    virtual void Process_vkCreateSharedSwapchainsKHR(
        const ApiCallInfo&                          call_info,
        args::CreateSharedSwapchainsKHR&            args) {}

    virtual void Process_vkCreateXlibSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateXlibSurfaceKHR&                 args) {}

    virtual void Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceXlibPresentationSupportKHR& args) {}

    virtual void Process_vkCreateXcbSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateXcbSurfaceKHR&                  args) {}

    virtual void Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceXcbPresentationSupportKHR& args) {}

    virtual void Process_vkCreateWaylandSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateWaylandSurfaceKHR&              args) {}

    virtual void Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceWaylandPresentationSupportKHR& args) {}

    virtual void Process_vkCreateAndroidSurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateAndroidSurfaceKHR&              args) {}

    virtual void Process_vkCreateWin32SurfaceKHR(
        const ApiCallInfo&                          call_info,
        args::CreateWin32SurfaceKHR&                args) {}

    virtual void Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceWin32PresentationSupportKHR& args) {}

    virtual void Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceVideoCapabilitiesKHR& args) {}

    virtual void Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceVideoFormatPropertiesKHR& args) {}

    virtual void Process_vkCreateVideoSessionKHR(
        const ApiCallInfo&                          call_info,
        args::CreateVideoSessionKHR&                args) {}

    virtual void Process_vkDestroyVideoSessionKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyVideoSessionKHR&               args) {}

    virtual void Process_vkGetVideoSessionMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        args::GetVideoSessionMemoryRequirementsKHR& args) {}

    virtual void Process_vkBindVideoSessionMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::BindVideoSessionMemoryKHR&            args) {}

    virtual void Process_vkCreateVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::CreateVideoSessionParametersKHR&      args) {}

    virtual void Process_vkUpdateVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::UpdateVideoSessionParametersKHR&      args) {}

    virtual void Process_vkDestroyVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyVideoSessionParametersKHR&     args) {}

    virtual void Process_vkCmdBeginVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBeginVideoCodingKHR&               args) {}

    virtual void Process_vkCmdEndVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndVideoCodingKHR&                 args) {}

    virtual void Process_vkCmdControlVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdControlVideoCodingKHR&             args) {}

    virtual void Process_vkCmdDecodeVideoKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDecodeVideoKHR&                    args) {}

    virtual void Process_vkCmdBeginRenderingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderingKHR&                 args) {}

    virtual void Process_vkCmdEndRenderingKHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderingKHR&                   args) {}

    virtual void Process_vkGetPhysicalDeviceFeatures2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFeatures2KHR&        args) {}

    virtual void Process_vkGetPhysicalDeviceProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceProperties2KHR&      args) {}

    virtual void Process_vkGetPhysicalDeviceFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFormatProperties2KHR& args) {}

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceImageFormatProperties2KHR& args) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyProperties2KHR& args) {}

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceMemoryProperties2KHR& args) {}

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSparseImageFormatProperties2KHR& args) {}

    virtual void Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupPeerMemoryFeaturesKHR&  args) {}

    virtual void Process_vkCmdSetDeviceMaskKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetDeviceMaskKHR&                  args) {}

    virtual void Process_vkCmdDispatchBaseKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchBaseKHR&                   args) {}

    virtual void Process_vkTrimCommandPoolKHR(
        const ApiCallInfo&                          call_info,
        args::TrimCommandPoolKHR&                   args) {}

    virtual void Process_vkEnumeratePhysicalDeviceGroupsKHR(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDeviceGroupsKHR&     args) {}

    virtual void Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalBufferPropertiesKHR& args) {}

    virtual void Process_vkGetMemoryWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::GetMemoryWin32HandleKHR&              args) {}

    virtual void Process_vkGetMemoryWin32HandlePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetMemoryWin32HandlePropertiesKHR&    args) {}

    virtual void Process_vkGetMemoryFdKHR(
        const ApiCallInfo&                          call_info,
        args::GetMemoryFdKHR&                       args) {}

    virtual void Process_vkGetMemoryFdPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetMemoryFdPropertiesKHR&             args) {}

    virtual void Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalSemaphorePropertiesKHR& args) {}

    virtual void Process_vkImportSemaphoreWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::ImportSemaphoreWin32HandleKHR&        args) {}

    virtual void Process_vkGetSemaphoreWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreWin32HandleKHR&           args) {}

    virtual void Process_vkImportSemaphoreFdKHR(
        const ApiCallInfo&                          call_info,
        args::ImportSemaphoreFdKHR&                 args) {}

    virtual void Process_vkGetSemaphoreFdKHR(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreFdKHR&                    args) {}

    virtual void Process_vkCmdPushDescriptorSetKHR(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSetKHR&              args) {}

    virtual void Process_vkCreateDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDescriptorUpdateTemplateKHR&    args) {}

    virtual void Process_vkDestroyDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyDescriptorUpdateTemplateKHR&   args) {}

    virtual void Process_vkCreateRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        args::CreateRenderPass2KHR&                 args) {}

    virtual void Process_vkCmdBeginRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBeginRenderPass2KHR&               args) {}

    virtual void Process_vkCmdNextSubpass2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdNextSubpass2KHR&                   args) {}

    virtual void Process_vkCmdEndRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndRenderPass2KHR&                 args) {}

    virtual void Process_vkGetSwapchainStatusKHR(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainStatusKHR&                args) {}

    virtual void Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalFencePropertiesKHR& args) {}

    virtual void Process_vkImportFenceWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::ImportFenceWin32HandleKHR&            args) {}

    virtual void Process_vkGetFenceWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        args::GetFenceWin32HandleKHR&               args) {}

    virtual void Process_vkImportFenceFdKHR(
        const ApiCallInfo&                          call_info,
        args::ImportFenceFdKHR&                     args) {}

    virtual void Process_vkGetFenceFdKHR(
        const ApiCallInfo&                          call_info,
        args::GetFenceFdKHR&                        args) {}

    virtual void Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR& args) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR& args) {}

    virtual void Process_vkAcquireProfilingLockKHR(
        const ApiCallInfo&                          call_info,
        args::AcquireProfilingLockKHR&              args) {}

    virtual void Process_vkReleaseProfilingLockKHR(
        const ApiCallInfo&                          call_info,
        args::ReleaseProfilingLockKHR&              args) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceCapabilities2KHR& args) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceFormats2KHR&  args) {}

    virtual void Process_vkGetPhysicalDeviceDisplayProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDisplayProperties2KHR& args) {}

    virtual void Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDisplayPlaneProperties2KHR& args) {}

    virtual void Process_vkGetDisplayModeProperties2KHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayModeProperties2KHR&         args) {}

    virtual void Process_vkGetDisplayPlaneCapabilities2KHR(
        const ApiCallInfo&                          call_info,
        args::GetDisplayPlaneCapabilities2KHR&      args) {}

    virtual void Process_vkGetImageMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        args::GetImageMemoryRequirements2KHR&       args) {}

    virtual void Process_vkGetBufferMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        args::GetBufferMemoryRequirements2KHR&      args) {}

    virtual void Process_vkGetImageSparseMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        args::GetImageSparseMemoryRequirements2KHR& args) {}

    virtual void Process_vkCreateSamplerYcbcrConversionKHR(
        const ApiCallInfo&                          call_info,
        args::CreateSamplerYcbcrConversionKHR&      args) {}

    virtual void Process_vkDestroySamplerYcbcrConversionKHR(
        const ApiCallInfo&                          call_info,
        args::DestroySamplerYcbcrConversionKHR&     args) {}

    virtual void Process_vkBindBufferMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::BindBufferMemory2KHR&                 args) {}

    virtual void Process_vkBindImageMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::BindImageMemory2KHR&                  args) {}

    virtual void Process_vkGetDescriptorSetLayoutSupportKHR(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutSupportKHR&     args) {}

    virtual void Process_vkCmdDrawIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCountKHR&              args) {}

    virtual void Process_vkCmdDrawIndexedIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCountKHR&       args) {}

    virtual void Process_vkGetSemaphoreCounterValueKHR(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreCounterValueKHR&          args) {}

    virtual void Process_vkWaitSemaphoresKHR(
        const ApiCallInfo&                          call_info,
        args::WaitSemaphoresKHR&                    args) {}

    virtual void Process_vkSignalSemaphoreKHR(
        const ApiCallInfo&                          call_info,
        args::SignalSemaphoreKHR&                   args) {}

    virtual void Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceFragmentShadingRatesKHR& args) {}

    virtual void Process_vkCmdSetFragmentShadingRateKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetFragmentShadingRateKHR&         args) {}

    virtual void Process_vkCmdSetRenderingAttachmentLocationsKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingAttachmentLocationsKHR& args) {}

    virtual void Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetRenderingInputAttachmentIndicesKHR& args) {}

    virtual void Process_vkWaitForPresentKHR(
        const ApiCallInfo&                          call_info,
        args::WaitForPresentKHR&                    args) {}

    virtual void Process_vkGetBufferDeviceAddressKHR(
        const ApiCallInfo&                          call_info,
        args::GetBufferDeviceAddressKHR&            args) {}

    virtual void Process_vkGetBufferOpaqueCaptureAddressKHR(
        const ApiCallInfo&                          call_info,
        args::GetBufferOpaqueCaptureAddressKHR&     args) {}

    virtual void Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceMemoryOpaqueCaptureAddressKHR& args) {}

    virtual void Process_vkCreateDeferredOperationKHR(
        const ApiCallInfo&                          call_info,
        args::CreateDeferredOperationKHR&           args) {}

    virtual void Process_vkDestroyDeferredOperationKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyDeferredOperationKHR&          args) {}

    virtual void Process_vkGetDeferredOperationMaxConcurrencyKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeferredOperationMaxConcurrencyKHR& args) {}

    virtual void Process_vkGetDeferredOperationResultKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeferredOperationResultKHR&        args) {}

    virtual void Process_vkDeferredOperationJoinKHR(
        const ApiCallInfo&                          call_info,
        args::DeferredOperationJoinKHR&             args) {}

    virtual void Process_vkGetPipelineExecutablePropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineExecutablePropertiesKHR&   args) {}

    virtual void Process_vkGetPipelineExecutableStatisticsKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineExecutableStatisticsKHR&   args) {}

    virtual void Process_vkGetPipelineExecutableInternalRepresentationsKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineExecutableInternalRepresentationsKHR& args) {}

    virtual void Process_vkMapMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::MapMemory2KHR&                        args) {}

    virtual void Process_vkUnmapMemory2KHR(
        const ApiCallInfo&                          call_info,
        args::UnmapMemory2KHR&                      args) {}

    virtual void Process_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR& args) {}

    virtual void Process_vkGetEncodedVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        args::GetEncodedVideoSessionParametersKHR&  args) {}

    virtual void Process_vkCmdEncodeVideoKHR(
        const ApiCallInfo&                          call_info,
        args::CmdEncodeVideoKHR&                    args) {}

    virtual void Process_vkCmdSetEvent2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetEvent2KHR&                      args) {}

    virtual void Process_vkCmdResetEvent2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdResetEvent2KHR&                    args) {}

    virtual void Process_vkCmdWaitEvents2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdWaitEvents2KHR&                    args) {}

    virtual void Process_vkCmdPipelineBarrier2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdPipelineBarrier2KHR&               args) {}

    virtual void Process_vkCmdWriteTimestamp2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdWriteTimestamp2KHR&                args) {}

    virtual void Process_vkQueueSubmit2KHR(
        const ApiCallInfo&                          call_info,
        args::QueueSubmit2KHR&                      args) {}

    virtual void Process_vkCmdBindIndexBuffer3KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer3KHR&               args) {}

    virtual void Process_vkCmdBindVertexBuffers3KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers3KHR&             args) {}

    virtual void Process_vkCmdDrawIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirect2KHR&                  args) {}

    virtual void Process_vkCmdDrawIndexedIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirect2KHR&           args) {}

    virtual void Process_vkCmdDispatchIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchIndirect2KHR&              args) {}

    virtual void Process_vkCmdCopyMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryKHR&                     args) {}

    virtual void Process_vkCmdCopyMemoryToImageKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToImageKHR&              args) {}

    virtual void Process_vkCmdCopyImageToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToMemoryKHR&              args) {}

    virtual void Process_vkCmdUpdateMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdUpdateMemoryKHR&                   args) {}

    virtual void Process_vkCmdFillMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdFillMemoryKHR&                     args) {}

    virtual void Process_vkCmdCopyQueryPoolResultsToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyQueryPoolResultsToMemoryKHR&   args) {}

    virtual void Process_vkCmdDrawIndirectCount2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCount2KHR&             args) {}

    virtual void Process_vkCmdDrawIndexedIndirectCount2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCount2KHR&      args) {}

    virtual void Process_vkCmdBeginConditionalRendering2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginConditionalRendering2EXT&     args) {}

    virtual void Process_vkCmdBindTransformFeedbackBuffers2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindTransformFeedbackBuffers2EXT&  args) {}

    virtual void Process_vkCmdBeginTransformFeedback2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginTransformFeedback2EXT&        args) {}

    virtual void Process_vkCmdEndTransformFeedback2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndTransformFeedback2EXT&          args) {}

    virtual void Process_vkCmdDrawIndirectByteCount2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectByteCount2EXT&         args) {}

    virtual void Process_vkCmdDrawMeshTasksIndirect2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirect2EXT&         args) {}

    virtual void Process_vkCmdDrawMeshTasksIndirectCount2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectCount2EXT&    args) {}

    virtual void Process_vkCmdWriteMarkerToMemoryAMD(
        const ApiCallInfo&                          call_info,
        args::CmdWriteMarkerToMemoryAMD&            args) {}

    virtual void Process_vkCreateAccelerationStructure2KHR(
        const ApiCallInfo&                          call_info,
        args::CreateAccelerationStructure2KHR&      args) {}

    virtual void Process_vkCmdCopyBuffer2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBuffer2KHR&                    args) {}

    virtual void Process_vkCmdCopyImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImage2KHR&                     args) {}

    virtual void Process_vkCmdCopyBufferToImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyBufferToImage2KHR&             args) {}

    virtual void Process_vkCmdCopyImageToBuffer2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyImageToBuffer2KHR&             args) {}

    virtual void Process_vkCmdBlitImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBlitImage2KHR&                     args) {}

    virtual void Process_vkCmdResolveImage2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdResolveImage2KHR&                  args) {}

    virtual void Process_vkCmdTraceRaysIndirect2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysIndirect2KHR&             args) {}

    virtual void Process_vkGetDeviceBufferMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceBufferMemoryRequirementsKHR& args) {}

    virtual void Process_vkGetDeviceImageMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageMemoryRequirementsKHR&  args) {}

    virtual void Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageSparseMemoryRequirementsKHR& args) {}

    virtual void Process_vkCmdBindIndexBuffer2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindIndexBuffer2KHR&               args) {}

    virtual void Process_vkGetRenderingAreaGranularityKHR(
        const ApiCallInfo&                          call_info,
        args::GetRenderingAreaGranularityKHR&       args) {}

    virtual void Process_vkGetDeviceImageSubresourceLayoutKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceImageSubresourceLayoutKHR&   args) {}

    virtual void Process_vkGetImageSubresourceLayout2KHR(
        const ApiCallInfo&                          call_info,
        args::GetImageSubresourceLayout2KHR&        args) {}

    virtual void Process_vkWaitForPresent2KHR(
        const ApiCallInfo&                          call_info,
        args::WaitForPresent2KHR&                   args) {}

    virtual void Process_vkCreatePipelineBinariesKHR(
        const ApiCallInfo&                          call_info,
        args::CreatePipelineBinariesKHR&            args) {}

    virtual void Process_vkDestroyPipelineBinaryKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyPipelineBinaryKHR&             args) {}

    virtual void Process_vkGetPipelineKeyKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineKeyKHR&                    args) {}

    virtual void Process_vkGetPipelineBinaryDataKHR(
        const ApiCallInfo&                          call_info,
        args::GetPipelineBinaryDataKHR&             args) {}

    virtual void Process_vkReleaseCapturedPipelineDataKHR(
        const ApiCallInfo&                          call_info,
        args::ReleaseCapturedPipelineDataKHR&       args) {}

    virtual void Process_vkReleaseSwapchainImagesKHR(
        const ApiCallInfo&                          call_info,
        args::ReleaseSwapchainImagesKHR&            args) {}

    virtual void Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCooperativeMatrixPropertiesKHR& args) {}

    virtual void Process_vkCmdSetLineStippleKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStippleKHR&                 args) {}

    virtual void Process_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCalibrateableTimeDomainsKHR& args) {}

    virtual void Process_vkGetCalibratedTimestampsKHR(
        const ApiCallInfo&                          call_info,
        args::GetCalibratedTimestampsKHR&           args) {}

    virtual void Process_vkCmdBindDescriptorSets2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorSets2KHR&            args) {}

    virtual void Process_vkCmdPushConstants2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdPushConstants2KHR&                 args) {}

    virtual void Process_vkCmdPushDescriptorSet2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdPushDescriptorSet2KHR&             args) {}

    virtual void Process_vkCmdSetDescriptorBufferOffsets2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDescriptorBufferOffsets2EXT&    args) {}

    virtual void Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorBufferEmbeddedSamplers2EXT& args) {}

    virtual void Process_vkCmdCopyMemoryIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryIndirectKHR&             args) {}

    virtual void Process_vkCmdCopyMemoryToImageIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToImageIndirectKHR&      args) {}

    virtual void Process_vkGetDeviceFaultReportsKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceFaultReportsKHR&             args) {}

    virtual void Process_vkGetDeviceFaultDebugInfoKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceFaultDebugInfoKHR&           args) {}

    virtual void Process_vkCmdEndRendering2KHR(
        const ApiCallInfo&                          call_info,
        args::CmdEndRendering2KHR&                  args) {}

    virtual void Process_vkFrameBoundaryANDROID(
        const ApiCallInfo&                          call_info,
        args::FrameBoundaryANDROID&                 args) {}

    virtual void Process_vkCreateDebugReportCallbackEXT(
        const ApiCallInfo&                          call_info,
        args::CreateDebugReportCallbackEXT&         args) {}

    virtual void Process_vkDestroyDebugReportCallbackEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyDebugReportCallbackEXT&        args) {}

    virtual void Process_vkDebugReportMessageEXT(
        const ApiCallInfo&                          call_info,
        args::DebugReportMessageEXT&                args) {}

    virtual void Process_vkDebugMarkerSetObjectTagEXT(
        const ApiCallInfo&                          call_info,
        args::DebugMarkerSetObjectTagEXT&           args) {}

    virtual void Process_vkDebugMarkerSetObjectNameEXT(
        const ApiCallInfo&                          call_info,
        args::DebugMarkerSetObjectNameEXT&          args) {}

    virtual void Process_vkCmdDebugMarkerBeginEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDebugMarkerBeginEXT&               args) {}

    virtual void Process_vkCmdDebugMarkerEndEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDebugMarkerEndEXT&                 args) {}

    virtual void Process_vkCmdDebugMarkerInsertEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDebugMarkerInsertEXT&              args) {}

    virtual void Process_vkCmdBindTransformFeedbackBuffersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindTransformFeedbackBuffersEXT&   args) {}

    virtual void Process_vkCmdBeginTransformFeedbackEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginTransformFeedbackEXT&         args) {}

    virtual void Process_vkCmdEndTransformFeedbackEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndTransformFeedbackEXT&           args) {}

    virtual void Process_vkCmdBeginQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginQueryIndexedEXT&              args) {}

    virtual void Process_vkCmdEndQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndQueryIndexedEXT&                args) {}

    virtual void Process_vkCmdDrawIndirectByteCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectByteCountEXT&          args) {}

    virtual void Process_vkGetImageViewHandleNVX(
        const ApiCallInfo&                          call_info,
        args::GetImageViewHandleNVX&                args) {}

    virtual void Process_vkGetImageViewHandle64NVX(
        const ApiCallInfo&                          call_info,
        args::GetImageViewHandle64NVX&              args) {}

    virtual void Process_vkGetImageViewAddressNVX(
        const ApiCallInfo&                          call_info,
        args::GetImageViewAddressNVX&               args) {}

    virtual void Process_vkGetDeviceCombinedImageSamplerIndexNVX(
        const ApiCallInfo&                          call_info,
        args::GetDeviceCombinedImageSamplerIndexNVX& args) {}

    virtual void Process_vkCmdDrawIndirectCountAMD(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndirectCountAMD&              args) {}

    virtual void Process_vkCmdDrawIndexedIndirectCountAMD(
        const ApiCallInfo&                          call_info,
        args::CmdDrawIndexedIndirectCountAMD&       args) {}

    virtual void Process_vkGetShaderInfoAMD(
        const ApiCallInfo&                          call_info,
        args::GetShaderInfoAMD&                     args) {}

    virtual void Process_vkCreateStreamDescriptorSurfaceGGP(
        const ApiCallInfo&                          call_info,
        args::CreateStreamDescriptorSurfaceGGP&     args) {}

    virtual void Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceExternalImageFormatPropertiesNV& args) {}

    virtual void Process_vkGetMemoryWin32HandleNV(
        const ApiCallInfo&                          call_info,
        args::GetMemoryWin32HandleNV&               args) {}

    virtual void Process_vkCreateViSurfaceNN(
        const ApiCallInfo&                          call_info,
        args::CreateViSurfaceNN&                    args) {}

    virtual void Process_vkCmdBeginConditionalRenderingEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginConditionalRenderingEXT&      args) {}

    virtual void Process_vkCmdEndConditionalRenderingEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndConditionalRenderingEXT&        args) {}

    virtual void Process_vkCmdSetViewportWScalingNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWScalingNV&             args) {}

    virtual void Process_vkReleaseDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::ReleaseDisplayEXT&                    args) {}

    virtual void Process_vkAcquireXlibDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::AcquireXlibDisplayEXT&                args) {}

    virtual void Process_vkGetRandROutputDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::GetRandROutputDisplayEXT&             args) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfaceCapabilities2EXT& args) {}

    virtual void Process_vkDisplayPowerControlEXT(
        const ApiCallInfo&                          call_info,
        args::DisplayPowerControlEXT&               args) {}

    virtual void Process_vkRegisterDeviceEventEXT(
        const ApiCallInfo&                          call_info,
        args::RegisterDeviceEventEXT&               args) {}

    virtual void Process_vkRegisterDisplayEventEXT(
        const ApiCallInfo&                          call_info,
        args::RegisterDisplayEventEXT&              args) {}

    virtual void Process_vkGetSwapchainCounterEXT(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainCounterEXT&               args) {}

    virtual void Process_vkGetRefreshCycleDurationGOOGLE(
        const ApiCallInfo&                          call_info,
        args::GetRefreshCycleDurationGOOGLE&        args) {}

    virtual void Process_vkGetPastPresentationTimingGOOGLE(
        const ApiCallInfo&                          call_info,
        args::GetPastPresentationTimingGOOGLE&      args) {}

    virtual void Process_vkCmdSetDiscardRectangleEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDiscardRectangleEXT&            args) {}

    virtual void Process_vkCmdSetDiscardRectangleEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDiscardRectangleEnableEXT&      args) {}

    virtual void Process_vkCmdSetDiscardRectangleModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDiscardRectangleModeEXT&        args) {}

    virtual void Process_vkSetHdrMetadataEXT(
        const ApiCallInfo&                          call_info,
        args::SetHdrMetadataEXT&                    args) {}

    virtual void Process_vkCreateIOSSurfaceMVK(
        const ApiCallInfo&                          call_info,
        args::CreateIOSSurfaceMVK&                  args) {}

    virtual void Process_vkCreateMacOSSurfaceMVK(
        const ApiCallInfo&                          call_info,
        args::CreateMacOSSurfaceMVK&                args) {}

    virtual void Process_vkSetDebugUtilsObjectNameEXT(
        const ApiCallInfo&                          call_info,
        args::SetDebugUtilsObjectNameEXT&           args) {}

    virtual void Process_vkSetDebugUtilsObjectTagEXT(
        const ApiCallInfo&                          call_info,
        args::SetDebugUtilsObjectTagEXT&            args) {}

    virtual void Process_vkQueueBeginDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::QueueBeginDebugUtilsLabelEXT&         args) {}

    virtual void Process_vkQueueEndDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::QueueEndDebugUtilsLabelEXT&           args) {}

    virtual void Process_vkQueueInsertDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::QueueInsertDebugUtilsLabelEXT&        args) {}

    virtual void Process_vkCmdBeginDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginDebugUtilsLabelEXT&           args) {}

    virtual void Process_vkCmdEndDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndDebugUtilsLabelEXT&             args) {}

    virtual void Process_vkCmdInsertDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        args::CmdInsertDebugUtilsLabelEXT&          args) {}

    virtual void Process_vkCreateDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        args::CreateDebugUtilsMessengerEXT&         args) {}

    virtual void Process_vkDestroyDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyDebugUtilsMessengerEXT&        args) {}

    virtual void Process_vkSubmitDebugUtilsMessageEXT(
        const ApiCallInfo&                          call_info,
        args::SubmitDebugUtilsMessageEXT&           args) {}

    virtual void Process_vkGetAndroidHardwareBufferPropertiesANDROID(
        const ApiCallInfo&                          call_info,
        args::GetAndroidHardwareBufferPropertiesANDROID& args) {}

    virtual void Process_vkGetMemoryAndroidHardwareBufferANDROID(
        const ApiCallInfo&                          call_info,
        args::GetMemoryAndroidHardwareBufferANDROID& args) {}

    virtual void Process_vkCreateGpaSessionAMD(
        const ApiCallInfo&                          call_info,
        args::CreateGpaSessionAMD&                  args) {}

    virtual void Process_vkDestroyGpaSessionAMD(
        const ApiCallInfo&                          call_info,
        args::DestroyGpaSessionAMD&                 args) {}

    virtual void Process_vkSetGpaDeviceClockModeAMD(
        const ApiCallInfo&                          call_info,
        args::SetGpaDeviceClockModeAMD&             args) {}

    virtual void Process_vkGetGpaDeviceClockInfoAMD(
        const ApiCallInfo&                          call_info,
        args::GetGpaDeviceClockInfoAMD&             args) {}

    virtual void Process_vkCmdBeginGpaSessionAMD(
        const ApiCallInfo&                          call_info,
        args::CmdBeginGpaSessionAMD&                args) {}

    virtual void Process_vkCmdEndGpaSessionAMD(
        const ApiCallInfo&                          call_info,
        args::CmdEndGpaSessionAMD&                  args) {}

    virtual void Process_vkCmdBeginGpaSampleAMD(
        const ApiCallInfo&                          call_info,
        args::CmdBeginGpaSampleAMD&                 args) {}

    virtual void Process_vkCmdEndGpaSampleAMD(
        const ApiCallInfo&                          call_info,
        args::CmdEndGpaSampleAMD&                   args) {}

    virtual void Process_vkGetGpaSessionStatusAMD(
        const ApiCallInfo&                          call_info,
        args::GetGpaSessionStatusAMD&               args) {}

    virtual void Process_vkGetGpaSessionResultsAMD(
        const ApiCallInfo&                          call_info,
        args::GetGpaSessionResultsAMD&              args) {}

    virtual void Process_vkResetGpaSessionAMD(
        const ApiCallInfo&                          call_info,
        args::ResetGpaSessionAMD&                   args) {}

    virtual void Process_vkCmdCopyGpaSessionResultsAMD(
        const ApiCallInfo&                          call_info,
        args::CmdCopyGpaSessionResultsAMD&          args) {}

    virtual void Process_vkCmdSetSampleLocationsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetSampleLocationsEXT&             args) {}

    virtual void Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceMultisamplePropertiesEXT& args) {}

    virtual void Process_vkGetImageDrmFormatModifierPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetImageDrmFormatModifierPropertiesEXT& args) {}

    virtual void Process_vkCreateValidationCacheEXT(
        const ApiCallInfo&                          call_info,
        args::CreateValidationCacheEXT&             args) {}

    virtual void Process_vkDestroyValidationCacheEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyValidationCacheEXT&            args) {}

    virtual void Process_vkMergeValidationCachesEXT(
        const ApiCallInfo&                          call_info,
        args::MergeValidationCachesEXT&             args) {}

    virtual void Process_vkGetValidationCacheDataEXT(
        const ApiCallInfo&                          call_info,
        args::GetValidationCacheDataEXT&            args) {}

    virtual void Process_vkCmdBindShadingRateImageNV(
        const ApiCallInfo&                          call_info,
        args::CmdBindShadingRateImageNV&            args) {}

    virtual void Process_vkCmdSetViewportShadingRatePaletteNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportShadingRatePaletteNV&   args) {}

    virtual void Process_vkCmdSetCoarseSampleOrderNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoarseSampleOrderNV&            args) {}

    virtual void Process_vkCreateAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::CreateAccelerationStructureNV&        args) {}

    virtual void Process_vkDestroyAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::DestroyAccelerationStructureNV&       args) {}

    virtual void Process_vkGetAccelerationStructureMemoryRequirementsNV(
        const ApiCallInfo&                          call_info,
        args::GetAccelerationStructureMemoryRequirementsNV& args) {}

    virtual void Process_vkBindAccelerationStructureMemoryNV(
        const ApiCallInfo&                          call_info,
        args::BindAccelerationStructureMemoryNV&    args) {}

    virtual void Process_vkCmdBuildAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::CmdBuildAccelerationStructureNV&      args) {}

    virtual void Process_vkCmdCopyAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        args::CmdCopyAccelerationStructureNV&       args) {}

    virtual void Process_vkCmdTraceRaysNV(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysNV&                       args) {}

    virtual void Process_vkCreateRayTracingPipelinesNV(
        const ApiCallInfo&                          call_info,
        args::CreateRayTracingPipelinesNV&          args) {}

    virtual void Process_vkGetRayTracingShaderGroupHandlesKHR(
        const ApiCallInfo&                          call_info,
        args::GetRayTracingShaderGroupHandlesKHR&   args) {}

    virtual void Process_vkGetRayTracingShaderGroupHandlesNV(
        const ApiCallInfo&                          call_info,
        args::GetRayTracingShaderGroupHandlesNV&    args) {}

    virtual void Process_vkGetAccelerationStructureHandleNV(
        const ApiCallInfo&                          call_info,
        args::GetAccelerationStructureHandleNV&     args) {}

    virtual void Process_vkCmdWriteAccelerationStructuresPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::CmdWriteAccelerationStructuresPropertiesNV& args) {}

    virtual void Process_vkCompileDeferredNV(
        const ApiCallInfo&                          call_info,
        args::CompileDeferredNV&                    args) {}

    virtual void Process_vkGetMemoryHostPointerPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetMemoryHostPointerPropertiesEXT&    args) {}

    virtual void Process_vkCmdWriteBufferMarkerAMD(
        const ApiCallInfo&                          call_info,
        args::CmdWriteBufferMarkerAMD&              args) {}

    virtual void Process_vkCmdWriteBufferMarker2AMD(
        const ApiCallInfo&                          call_info,
        args::CmdWriteBufferMarker2AMD&             args) {}

    virtual void Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCalibrateableTimeDomainsEXT& args) {}

    virtual void Process_vkGetCalibratedTimestampsEXT(
        const ApiCallInfo&                          call_info,
        args::GetCalibratedTimestampsEXT&           args) {}

    virtual void Process_vkCmdDrawMeshTasksNV(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksNV&                   args) {}

    virtual void Process_vkCmdDrawMeshTasksIndirectNV(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectNV&           args) {}

    virtual void Process_vkCmdDrawMeshTasksIndirectCountNV(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectCountNV&      args) {}

    virtual void Process_vkCmdSetExclusiveScissorEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetExclusiveScissorEnableNV&       args) {}

    virtual void Process_vkCmdSetExclusiveScissorNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetExclusiveScissorNV&             args) {}

    virtual void Process_vkCmdSetCheckpointNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCheckpointNV&                   args) {}

    virtual void Process_vkGetQueueCheckpointDataNV(
        const ApiCallInfo&                          call_info,
        args::GetQueueCheckpointDataNV&             args) {}

    virtual void Process_vkGetQueueCheckpointData2NV(
        const ApiCallInfo&                          call_info,
        args::GetQueueCheckpointData2NV&            args) {}

    virtual void Process_vkSetSwapchainPresentTimingQueueSizeEXT(
        const ApiCallInfo&                          call_info,
        args::SetSwapchainPresentTimingQueueSizeEXT& args) {}

    virtual void Process_vkGetSwapchainTimingPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainTimingPropertiesEXT&      args) {}

    virtual void Process_vkGetSwapchainTimeDomainPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetSwapchainTimeDomainPropertiesEXT&  args) {}

    virtual void Process_vkGetPastPresentationTimingEXT(
        const ApiCallInfo&                          call_info,
        args::GetPastPresentationTimingEXT&         args) {}

    virtual void Process_vkInitializePerformanceApiINTEL(
        const ApiCallInfo&                          call_info,
        args::InitializePerformanceApiINTEL&        args) {}

    virtual void Process_vkUninitializePerformanceApiINTEL(
        const ApiCallInfo&                          call_info,
        args::UninitializePerformanceApiINTEL&      args) {}

    virtual void Process_vkCmdSetPerformanceMarkerINTEL(
        const ApiCallInfo&                          call_info,
        args::CmdSetPerformanceMarkerINTEL&         args) {}

    virtual void Process_vkCmdSetPerformanceStreamMarkerINTEL(
        const ApiCallInfo&                          call_info,
        args::CmdSetPerformanceStreamMarkerINTEL&   args) {}

    virtual void Process_vkCmdSetPerformanceOverrideINTEL(
        const ApiCallInfo&                          call_info,
        args::CmdSetPerformanceOverrideINTEL&       args) {}

    virtual void Process_vkAcquirePerformanceConfigurationINTEL(
        const ApiCallInfo&                          call_info,
        args::AcquirePerformanceConfigurationINTEL& args) {}

    virtual void Process_vkReleasePerformanceConfigurationINTEL(
        const ApiCallInfo&                          call_info,
        args::ReleasePerformanceConfigurationINTEL& args) {}

    virtual void Process_vkQueueSetPerformanceConfigurationINTEL(
        const ApiCallInfo&                          call_info,
        args::QueueSetPerformanceConfigurationINTEL& args) {}

    virtual void Process_vkGetPerformanceParameterINTEL(
        const ApiCallInfo&                          call_info,
        args::GetPerformanceParameterINTEL&         args) {}

    virtual void Process_vkSetLocalDimmingAMD(
        const ApiCallInfo&                          call_info,
        args::SetLocalDimmingAMD&                   args) {}

    virtual void Process_vkCreateImagePipeSurfaceFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::CreateImagePipeSurfaceFUCHSIA&        args) {}

    virtual void Process_vkCreateMetalSurfaceEXT(
        const ApiCallInfo&                          call_info,
        args::CreateMetalSurfaceEXT&                args) {}

    virtual void Process_vkGetBufferDeviceAddressEXT(
        const ApiCallInfo&                          call_info,
        args::GetBufferDeviceAddressEXT&            args) {}

    virtual void Process_vkGetPhysicalDeviceToolPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceToolPropertiesEXT&   args) {}

    virtual void Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCooperativeMatrixPropertiesNV& args) {}

    virtual void Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV& args) {}

    virtual void Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceSurfacePresentModes2EXT& args) {}

    virtual void Process_vkAcquireFullScreenExclusiveModeEXT(
        const ApiCallInfo&                          call_info,
        args::AcquireFullScreenExclusiveModeEXT&    args) {}

    virtual void Process_vkReleaseFullScreenExclusiveModeEXT(
        const ApiCallInfo&                          call_info,
        args::ReleaseFullScreenExclusiveModeEXT&    args) {}

    virtual void Process_vkGetDeviceGroupSurfacePresentModes2EXT(
        const ApiCallInfo&                          call_info,
        args::GetDeviceGroupSurfacePresentModes2EXT& args) {}

    virtual void Process_vkCreateHeadlessSurfaceEXT(
        const ApiCallInfo&                          call_info,
        args::CreateHeadlessSurfaceEXT&             args) {}

    virtual void Process_vkCmdSetLineStippleEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStippleEXT&                 args) {}

    virtual void Process_vkResetQueryPoolEXT(
        const ApiCallInfo&                          call_info,
        args::ResetQueryPoolEXT&                    args) {}

    virtual void Process_vkCmdSetCullModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetCullModeEXT&                    args) {}

    virtual void Process_vkCmdSetFrontFaceEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetFrontFaceEXT&                   args) {}

    virtual void Process_vkCmdSetPrimitiveTopologyEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveTopologyEXT&           args) {}

    virtual void Process_vkCmdSetViewportWithCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWithCountEXT&           args) {}

    virtual void Process_vkCmdSetScissorWithCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetScissorWithCountEXT&            args) {}

    virtual void Process_vkCmdBindVertexBuffers2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindVertexBuffers2EXT&             args) {}

    virtual void Process_vkCmdSetDepthTestEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthTestEnableEXT&             args) {}

    virtual void Process_vkCmdSetDepthWriteEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthWriteEnableEXT&            args) {}

    virtual void Process_vkCmdSetDepthCompareOpEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthCompareOpEXT&              args) {}

    virtual void Process_vkCmdSetDepthBoundsTestEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBoundsTestEnableEXT&       args) {}

    virtual void Process_vkCmdSetStencilTestEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilTestEnableEXT&           args) {}

    virtual void Process_vkCmdSetStencilOpEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetStencilOpEXT&                   args) {}

    virtual void Process_vkCopyMemoryToImageEXT(
        const ApiCallInfo&                          call_info,
        args::CopyMemoryToImageEXT&                 args) {}

    virtual void Process_vkCopyImageToMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CopyImageToMemoryEXT&                 args) {}

    virtual void Process_vkCopyImageToImageEXT(
        const ApiCallInfo&                          call_info,
        args::CopyImageToImageEXT&                  args) {}

    virtual void Process_vkTransitionImageLayoutEXT(
        const ApiCallInfo&                          call_info,
        args::TransitionImageLayoutEXT&             args) {}

    virtual void Process_vkGetImageSubresourceLayout2EXT(
        const ApiCallInfo&                          call_info,
        args::GetImageSubresourceLayout2EXT&        args) {}

    virtual void Process_vkReleaseSwapchainImagesEXT(
        const ApiCallInfo&                          call_info,
        args::ReleaseSwapchainImagesEXT&            args) {}

    virtual void Process_vkGetGeneratedCommandsMemoryRequirementsNV(
        const ApiCallInfo&                          call_info,
        args::GetGeneratedCommandsMemoryRequirementsNV& args) {}

    virtual void Process_vkCmdPreprocessGeneratedCommandsNV(
        const ApiCallInfo&                          call_info,
        args::CmdPreprocessGeneratedCommandsNV&     args) {}

    virtual void Process_vkCmdExecuteGeneratedCommandsNV(
        const ApiCallInfo&                          call_info,
        args::CmdExecuteGeneratedCommandsNV&        args) {}

    virtual void Process_vkCmdBindPipelineShaderGroupNV(
        const ApiCallInfo&                          call_info,
        args::CmdBindPipelineShaderGroupNV&         args) {}

    virtual void Process_vkCreateIndirectCommandsLayoutNV(
        const ApiCallInfo&                          call_info,
        args::CreateIndirectCommandsLayoutNV&       args) {}

    virtual void Process_vkDestroyIndirectCommandsLayoutNV(
        const ApiCallInfo&                          call_info,
        args::DestroyIndirectCommandsLayoutNV&      args) {}

    virtual void Process_vkCmdSetDepthBias2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBias2EXT&                  args) {}

    virtual void Process_vkAcquireDrmDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::AcquireDrmDisplayEXT&                 args) {}

    virtual void Process_vkGetDrmDisplayEXT(
        const ApiCallInfo&                          call_info,
        args::GetDrmDisplayEXT&                     args) {}

    virtual void Process_vkCreatePrivateDataSlotEXT(
        const ApiCallInfo&                          call_info,
        args::CreatePrivateDataSlotEXT&             args) {}

    virtual void Process_vkDestroyPrivateDataSlotEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyPrivateDataSlotEXT&            args) {}

    virtual void Process_vkSetPrivateDataEXT(
        const ApiCallInfo&                          call_info,
        args::SetPrivateDataEXT&                    args) {}

    virtual void Process_vkGetPrivateDataEXT(
        const ApiCallInfo&                          call_info,
        args::GetPrivateDataEXT&                    args) {}

    virtual void Process_vkQueueSetPerfHintQCOM(
        const ApiCallInfo&                          call_info,
        args::QueueSetPerfHintQCOM&                 args) {}

    virtual void Process_vkCmdDispatchTileQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchTileQCOM&                  args) {}

    virtual void Process_vkCmdBeginPerTileExecutionQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdBeginPerTileExecutionQCOM&         args) {}

    virtual void Process_vkCmdEndPerTileExecutionQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdEndPerTileExecutionQCOM&           args) {}

    virtual void Process_vkGetDescriptorSetLayoutSizeEXT(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutSizeEXT&        args) {}

    virtual void Process_vkGetDescriptorSetLayoutBindingOffsetEXT(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutBindingOffsetEXT& args) {}

    virtual void Process_vkGetDescriptorEXT(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorEXT&                     args) {}

    virtual void Process_vkCmdBindDescriptorBuffersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorBuffersEXT&          args) {}

    virtual void Process_vkCmdSetDescriptorBufferOffsetsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDescriptorBufferOffsetsEXT&     args) {}

    virtual void Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindDescriptorBufferEmbeddedSamplersEXT& args) {}

    virtual void Process_vkCmdSetFragmentShadingRateEnumNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetFragmentShadingRateEnumNV&      args) {}

    virtual void Process_vkGetDeviceFaultInfoEXT(
        const ApiCallInfo&                          call_info,
        args::GetDeviceFaultInfoEXT&                args) {}

    virtual void Process_vkAcquireWinrtDisplayNV(
        const ApiCallInfo&                          call_info,
        args::AcquireWinrtDisplayNV&                args) {}

    virtual void Process_vkGetWinrtDisplayNV(
        const ApiCallInfo&                          call_info,
        args::GetWinrtDisplayNV&                    args) {}

    virtual void Process_vkCreateDirectFBSurfaceEXT(
        const ApiCallInfo&                          call_info,
        args::CreateDirectFBSurfaceEXT&             args) {}

    virtual void Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceDirectFBPresentationSupportEXT& args) {}

    virtual void Process_vkCmdSetVertexInputEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetVertexInputEXT&                 args) {}

    virtual void Process_vkGetMemoryZirconHandleFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::GetMemoryZirconHandleFUCHSIA&         args) {}

    virtual void Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::GetMemoryZirconHandlePropertiesFUCHSIA& args) {}

    virtual void Process_vkImportSemaphoreZirconHandleFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::ImportSemaphoreZirconHandleFUCHSIA&   args) {}

    virtual void Process_vkGetSemaphoreZirconHandleFUCHSIA(
        const ApiCallInfo&                          call_info,
        args::GetSemaphoreZirconHandleFUCHSIA&      args) {}

    virtual void Process_vkCmdBindInvocationMaskHUAWEI(
        const ApiCallInfo&                          call_info,
        args::CmdBindInvocationMaskHUAWEI&          args) {}

    virtual void Process_vkGetMemoryRemoteAddressNV(
        const ApiCallInfo&                          call_info,
        args::GetMemoryRemoteAddressNV&             args) {}

    virtual void Process_vkCmdSetPatchControlPointsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPatchControlPointsEXT&          args) {}

    virtual void Process_vkCmdSetRasterizerDiscardEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizerDiscardEnableEXT&     args) {}

    virtual void Process_vkCmdSetDepthBiasEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthBiasEnableEXT&             args) {}

    virtual void Process_vkCmdSetLogicOpEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLogicOpEXT&                     args) {}

    virtual void Process_vkCmdSetPrimitiveRestartEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveRestartEnableEXT&      args) {}

    virtual void Process_vkCreateScreenSurfaceQNX(
        const ApiCallInfo&                          call_info,
        args::CreateScreenSurfaceQNX&               args) {}

    virtual void Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceScreenPresentationSupportQNX& args) {}

    virtual void Process_vkCmdSetColorWriteEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorWriteEnableEXT&            args) {}

    virtual void Process_vkCmdDrawMultiEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMultiEXT&                      args) {}

    virtual void Process_vkCmdDrawMultiIndexedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMultiIndexedEXT&               args) {}

    virtual void Process_vkCreateMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CreateMicromapEXT&                    args) {}

    virtual void Process_vkDestroyMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyMicromapEXT&                   args) {}

    virtual void Process_vkCmdBuildMicromapsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBuildMicromapsEXT&                 args) {}

    virtual void Process_vkBuildMicromapsEXT(
        const ApiCallInfo&                          call_info,
        args::BuildMicromapsEXT&                    args) {}

    virtual void Process_vkCopyMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CopyMicromapEXT&                      args) {}

    virtual void Process_vkCopyMicromapToMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CopyMicromapToMemoryEXT&              args) {}

    virtual void Process_vkCopyMemoryToMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CopyMemoryToMicromapEXT&              args) {}

    virtual void Process_vkWriteMicromapsPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::WriteMicromapsPropertiesEXT&          args) {}

    virtual void Process_vkCmdCopyMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMicromapEXT&                   args) {}

    virtual void Process_vkCmdCopyMicromapToMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMicromapToMemoryEXT&           args) {}

    virtual void Process_vkCmdCopyMemoryToMicromapEXT(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToMicromapEXT&           args) {}

    virtual void Process_vkCmdWriteMicromapsPropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::CmdWriteMicromapsPropertiesEXT&       args) {}

    virtual void Process_vkGetDeviceMicromapCompatibilityEXT(
        const ApiCallInfo&                          call_info,
        args::GetDeviceMicromapCompatibilityEXT&    args) {}

    virtual void Process_vkGetMicromapBuildSizesEXT(
        const ApiCallInfo&                          call_info,
        args::GetMicromapBuildSizesEXT&             args) {}

    virtual void Process_vkCmdDrawClusterHUAWEI(
        const ApiCallInfo&                          call_info,
        args::CmdDrawClusterHUAWEI&                 args) {}

    virtual void Process_vkCmdDrawClusterIndirectHUAWEI(
        const ApiCallInfo&                          call_info,
        args::CmdDrawClusterIndirectHUAWEI&         args) {}

    virtual void Process_vkSetDeviceMemoryPriorityEXT(
        const ApiCallInfo&                          call_info,
        args::SetDeviceMemoryPriorityEXT&           args) {}

    virtual void Process_vkCmdSetDispatchParametersARM(
        const ApiCallInfo&                          call_info,
        args::CmdSetDispatchParametersARM&          args) {}

    virtual void Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetLayoutHostMappingInfoVALVE& args) {}

    virtual void Process_vkGetDescriptorSetHostMappingVALVE(
        const ApiCallInfo&                          call_info,
        args::GetDescriptorSetHostMappingVALVE&     args) {}

    virtual void Process_vkGetPipelineIndirectMemoryRequirementsNV(
        const ApiCallInfo&                          call_info,
        args::GetPipelineIndirectMemoryRequirementsNV& args) {}

    virtual void Process_vkCmdUpdatePipelineIndirectBufferNV(
        const ApiCallInfo&                          call_info,
        args::CmdUpdatePipelineIndirectBufferNV&    args) {}

    virtual void Process_vkGetPipelineIndirectDeviceAddressNV(
        const ApiCallInfo&                          call_info,
        args::GetPipelineIndirectDeviceAddressNV&   args) {}

    virtual void Process_vkCmdSetDepthClampEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClampEnableEXT&            args) {}

    virtual void Process_vkCmdSetPolygonModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPolygonModeEXT&                 args) {}

    virtual void Process_vkCmdSetRasterizationSamplesEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizationSamplesEXT&        args) {}

    virtual void Process_vkCmdSetSampleMaskEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetSampleMaskEXT&                  args) {}

    virtual void Process_vkCmdSetAlphaToCoverageEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetAlphaToCoverageEnableEXT&       args) {}

    virtual void Process_vkCmdSetAlphaToOneEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetAlphaToOneEnableEXT&            args) {}

    virtual void Process_vkCmdSetLogicOpEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLogicOpEnableEXT&               args) {}

    virtual void Process_vkCmdSetColorBlendEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorBlendEnableEXT&            args) {}

    virtual void Process_vkCmdSetColorBlendEquationEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorBlendEquationEXT&          args) {}

    virtual void Process_vkCmdSetColorWriteMaskEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorWriteMaskEXT&              args) {}

    virtual void Process_vkCmdSetTessellationDomainOriginEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetTessellationDomainOriginEXT&    args) {}

    virtual void Process_vkCmdSetRasterizationStreamEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetRasterizationStreamEXT&         args) {}

    virtual void Process_vkCmdSetConservativeRasterizationModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetConservativeRasterizationModeEXT& args) {}

    virtual void Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetExtraPrimitiveOverestimationSizeEXT& args) {}

    virtual void Process_vkCmdSetDepthClipEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClipEnableEXT&             args) {}

    virtual void Process_vkCmdSetSampleLocationsEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetSampleLocationsEnableEXT&       args) {}

    virtual void Process_vkCmdSetColorBlendAdvancedEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetColorBlendAdvancedEXT&          args) {}

    virtual void Process_vkCmdSetProvokingVertexModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetProvokingVertexModeEXT&         args) {}

    virtual void Process_vkCmdSetLineRasterizationModeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineRasterizationModeEXT&       args) {}

    virtual void Process_vkCmdSetLineStippleEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetLineStippleEnableEXT&           args) {}

    virtual void Process_vkCmdSetDepthClipNegativeOneToOneEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClipNegativeOneToOneEXT&   args) {}

    virtual void Process_vkCmdSetViewportWScalingEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportWScalingEnableNV&       args) {}

    virtual void Process_vkCmdSetViewportSwizzleNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetViewportSwizzleNV&              args) {}

    virtual void Process_vkCmdSetCoverageToColorEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageToColorEnableNV&        args) {}

    virtual void Process_vkCmdSetCoverageToColorLocationNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageToColorLocationNV&      args) {}

    virtual void Process_vkCmdSetCoverageModulationModeNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageModulationModeNV&       args) {}

    virtual void Process_vkCmdSetCoverageModulationTableEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageModulationTableEnableNV& args) {}

    virtual void Process_vkCmdSetCoverageModulationTableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageModulationTableNV&      args) {}

    virtual void Process_vkCmdSetShadingRateImageEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetShadingRateImageEnableNV&       args) {}

    virtual void Process_vkCmdSetRepresentativeFragmentTestEnableNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetRepresentativeFragmentTestEnableNV& args) {}

    virtual void Process_vkCmdSetCoverageReductionModeNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetCoverageReductionModeNV&        args) {}

    virtual void Process_vkCreateTensorARM(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkTensorCreateInfoARM>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkTensorARM>*          pTensor) {}

    virtual void Process_vkDestroyTensorARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            tensor,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCreateTensorViewARM(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkTensorViewCreateInfoARM>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkTensorViewARM>*      pView) {}

    virtual void Process_vkDestroyTensorViewARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            tensorView,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkGetTensorMemoryRequirementsARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkTensorMemoryRequirementsInfoARM>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkBindTensorMemoryARM(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindTensorMemoryInfoARM>* pBindInfos) {}

    virtual void Process_vkGetDeviceTensorMemoryRequirementsARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceTensorMemoryRequirementsARM>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkCmdCopyTensorARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyTensorInfoARM>* pCopyTensorInfo) {}

    virtual void Process_vkGetPhysicalDeviceExternalTensorPropertiesARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalTensorInfoARM>* pExternalTensorInfo,
        StructPointerDecoder<Decoded_VkExternalTensorPropertiesARM>* pExternalTensorProperties) {}

    virtual void Process_vkGetShaderModuleIdentifierEXT(
        const ApiCallInfo&                          call_info,
        args::GetShaderModuleIdentifierEXT&         args) {}

    virtual void Process_vkGetShaderModuleCreateInfoIdentifierEXT(
        const ApiCallInfo&                          call_info,
        args::GetShaderModuleCreateInfoIdentifierEXT& args) {}

    virtual void Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceOpticalFlowImageFormatsNV& args) {}

    virtual void Process_vkCreateOpticalFlowSessionNV(
        const ApiCallInfo&                          call_info,
        args::CreateOpticalFlowSessionNV&           args) {}

    virtual void Process_vkDestroyOpticalFlowSessionNV(
        const ApiCallInfo&                          call_info,
        args::DestroyOpticalFlowSessionNV&          args) {}

    virtual void Process_vkBindOpticalFlowSessionImageNV(
        const ApiCallInfo&                          call_info,
        args::BindOpticalFlowSessionImageNV&        args) {}

    virtual void Process_vkCmdOpticalFlowExecuteNV(
        const ApiCallInfo&                          call_info,
        args::CmdOpticalFlowExecuteNV&              args) {}

    virtual void Process_vkAntiLagUpdateAMD(
        const ApiCallInfo&                          call_info,
        args::AntiLagUpdateAMD&                     args) {}

    virtual void Process_vkCreateShadersEXT(
        const ApiCallInfo&                          call_info,
        args::CreateShadersEXT&                     args) {}

    virtual void Process_vkDestroyShaderEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyShaderEXT&                     args) {}

    virtual void Process_vkGetShaderBinaryDataEXT(
        const ApiCallInfo&                          call_info,
        args::GetShaderBinaryDataEXT&               args) {}

    virtual void Process_vkCmdBindShadersEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBindShadersEXT&                    args) {}

    virtual void Process_vkCmdSetDepthClampRangeEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetDepthClampRangeEXT&             args) {}

    virtual void Process_vkGetFramebufferTilePropertiesQCOM(
        const ApiCallInfo&                          call_info,
        args::GetFramebufferTilePropertiesQCOM&     args) {}

    virtual void Process_vkGetDynamicRenderingTilePropertiesQCOM(
        const ApiCallInfo&                          call_info,
        args::GetDynamicRenderingTilePropertiesQCOM& args) {}

    virtual void Process_vkGetPhysicalDeviceCooperativeVectorPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCooperativeVectorPropertiesNV& args) {}

    virtual void Process_vkConvertCooperativeVectorMatrixNV(
        const ApiCallInfo&                          call_info,
        args::ConvertCooperativeVectorMatrixNV&     args) {}

    virtual void Process_vkCmdConvertCooperativeVectorMatrixNV(
        const ApiCallInfo&                          call_info,
        args::CmdConvertCooperativeVectorMatrixNV&  args) {}

    virtual void Process_vkSetLatencySleepModeNV(
        const ApiCallInfo&                          call_info,
        args::SetLatencySleepModeNV&                args) {}

    virtual void Process_vkLatencySleepNV(
        const ApiCallInfo&                          call_info,
        args::LatencySleepNV&                       args) {}

    virtual void Process_vkSetLatencyMarkerNV(
        const ApiCallInfo&                          call_info,
        args::SetLatencyMarkerNV&                   args) {}

    virtual void Process_vkGetLatencyTimingsNV(
        const ApiCallInfo&                          call_info,
        args::GetLatencyTimingsNV&                  args) {}

    virtual void Process_vkQueueNotifyOutOfBandNV(
        const ApiCallInfo&                          call_info,
        args::QueueNotifyOutOfBandNV&               args) {}

    virtual void Process_vkCreateDataGraphPipelinesARM(
        const ApiCallInfo&                          call_info,
        args::CreateDataGraphPipelinesARM&          args) {}

    virtual void Process_vkCreateDataGraphPipelineSessionARM(
        const ApiCallInfo&                          call_info,
        args::CreateDataGraphPipelineSessionARM&    args) {}

    virtual void Process_vkGetDataGraphPipelineSessionBindPointRequirementsARM(
        const ApiCallInfo&                          call_info,
        args::GetDataGraphPipelineSessionBindPointRequirementsARM& args) {}

    virtual void Process_vkGetDataGraphPipelineSessionMemoryRequirementsARM(
        const ApiCallInfo&                          call_info,
        args::GetDataGraphPipelineSessionMemoryRequirementsARM& args) {}

    virtual void Process_vkBindDataGraphPipelineSessionMemoryARM(
        const ApiCallInfo&                          call_info,
        args::BindDataGraphPipelineSessionMemoryARM& args) {}

    virtual void Process_vkDestroyDataGraphPipelineSessionARM(
        const ApiCallInfo&                          call_info,
        args::DestroyDataGraphPipelineSessionARM&   args) {}

    virtual void Process_vkCmdDispatchDataGraphARM(
        const ApiCallInfo&                          call_info,
        args::CmdDispatchDataGraphARM&              args) {}

    virtual void Process_vkGetDataGraphPipelineAvailablePropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetDataGraphPipelineAvailablePropertiesARM& args) {}

    virtual void Process_vkGetDataGraphPipelinePropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetDataGraphPipelinePropertiesARM&    args) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM& args) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM& args) {}

    virtual void Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetAttachmentFeedbackLoopEnableEXT& args) {}

    virtual void Process_vkCmdBindTileMemoryQCOM(
        const ApiCallInfo&                          call_info,
        args::CmdBindTileMemoryQCOM&                args) {}

    virtual void Process_vkCmdDecompressMemoryEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDecompressMemoryEXT&               args) {}

    virtual void Process_vkCmdDecompressMemoryIndirectCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDecompressMemoryIndirectCountEXT&  args) {}

    virtual void Process_vkGetPartitionedAccelerationStructuresBuildSizesNV(
        const ApiCallInfo&                          call_info,
        args::GetPartitionedAccelerationStructuresBuildSizesNV& args) {}

    virtual void Process_vkCmdBuildPartitionedAccelerationStructuresNV(
        const ApiCallInfo&                          call_info,
        args::CmdBuildPartitionedAccelerationStructuresNV& args) {}

    virtual void Process_vkGetGeneratedCommandsMemoryRequirementsEXT(
        const ApiCallInfo&                          call_info,
        args::GetGeneratedCommandsMemoryRequirementsEXT& args) {}

    virtual void Process_vkCmdPreprocessGeneratedCommandsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdPreprocessGeneratedCommandsEXT&    args) {}

    virtual void Process_vkCmdExecuteGeneratedCommandsEXT(
        const ApiCallInfo&                          call_info,
        args::CmdExecuteGeneratedCommandsEXT&       args) {}

    virtual void Process_vkCreateIndirectCommandsLayoutEXT(
        const ApiCallInfo&                          call_info,
        args::CreateIndirectCommandsLayoutEXT&      args) {}

    virtual void Process_vkDestroyIndirectCommandsLayoutEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyIndirectCommandsLayoutEXT&     args) {}

    virtual void Process_vkCreateIndirectExecutionSetEXT(
        const ApiCallInfo&                          call_info,
        args::CreateIndirectExecutionSetEXT&        args) {}

    virtual void Process_vkDestroyIndirectExecutionSetEXT(
        const ApiCallInfo&                          call_info,
        args::DestroyIndirectExecutionSetEXT&       args) {}

    virtual void Process_vkUpdateIndirectExecutionSetPipelineEXT(
        const ApiCallInfo&                          call_info,
        args::UpdateIndirectExecutionSetPipelineEXT& args) {}

    virtual void Process_vkUpdateIndirectExecutionSetShaderEXT(
        const ApiCallInfo&                          call_info,
        args::UpdateIndirectExecutionSetShaderEXT&  args) {}

    virtual void Process_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(
        const ApiCallInfo&                          call_info,
        args::GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV& args) {}

    virtual void Process_vkGetMemoryMetalHandleEXT(
        const ApiCallInfo&                          call_info,
        args::GetMemoryMetalHandleEXT&              args) {}

    virtual void Process_vkGetMemoryMetalHandlePropertiesEXT(
        const ApiCallInfo&                          call_info,
        args::GetMemoryMetalHandlePropertiesEXT&    args) {}

    virtual void Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(
        const ApiCallInfo&                          call_info,
        args::EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM& args) {}

    virtual void Process_vkCmdEndRendering2EXT(
        const ApiCallInfo&                          call_info,
        args::CmdEndRendering2EXT&                  args) {}

    virtual void Process_vkCmdBeginCustomResolveEXT(
        const ApiCallInfo&                          call_info,
        args::CmdBeginCustomResolveEXT&             args) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        StructPointerDecoder<Decoded_VkQueueFamilyDataGraphPropertiesARM>* pQueueFamilyDataGraphProperties,
        StructPointerDecoder<Decoded_VkDataGraphOpticalFlowImageFormatInfoARM>* pOpticalFlowImageFormatInfo,
        PointerDecoder<uint32_t>*                   pFormatCount,
        StructPointerDecoder<Decoded_VkDataGraphOpticalFlowImageFormatPropertiesARM>* pImageFormatProperties) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        StructPointerDecoder<Decoded_VkQueueFamilyDataGraphPropertiesARM>* pQueueFamilyDataGraphProperties,
        StructPointerDecoder<Decoded_VkBaseOutStructure>* pProperties) {}

    virtual void Process_vkCmdSetComputeOccupancyPriorityNV(
        const ApiCallInfo&                          call_info,
        args::CmdSetComputeOccupancyPriorityNV&     args) {}

    virtual void Process_vkCmdSetPrimitiveRestartIndexEXT(
        const ApiCallInfo&                          call_info,
        args::CmdSetPrimitiveRestartIndexEXT&       args) {}

    virtual void Process_vkCreateAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CreateAccelerationStructureKHR&       args) {}

    virtual void Process_vkDestroyAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::DestroyAccelerationStructureKHR&      args) {}

    virtual void Process_vkCmdBuildAccelerationStructuresKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBuildAccelerationStructuresKHR&    args) {}

    virtual void Process_vkCmdBuildAccelerationStructuresIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdBuildAccelerationStructuresIndirectKHR& args) {}

    virtual void Process_vkCopyAccelerationStructureToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CopyAccelerationStructureToMemoryKHR& args) {}

    virtual void Process_vkCopyMemoryToAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CopyMemoryToAccelerationStructureKHR& args) {}

    virtual void Process_vkWriteAccelerationStructuresPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::WriteAccelerationStructuresPropertiesKHR& args) {}

    virtual void Process_vkCmdCopyAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyAccelerationStructureKHR&      args) {}

    virtual void Process_vkCmdCopyAccelerationStructureToMemoryKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyAccelerationStructureToMemoryKHR& args) {}

    virtual void Process_vkCmdCopyMemoryToAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        args::CmdCopyMemoryToAccelerationStructureKHR& args) {}

    virtual void Process_vkGetAccelerationStructureDeviceAddressKHR(
        const ApiCallInfo&                          call_info,
        args::GetAccelerationStructureDeviceAddressKHR& args) {}

    virtual void Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
        const ApiCallInfo&                          call_info,
        args::CmdWriteAccelerationStructuresPropertiesKHR& args) {}

    virtual void Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
        const ApiCallInfo&                          call_info,
        args::GetDeviceAccelerationStructureCompatibilityKHR& args) {}

    virtual void Process_vkGetAccelerationStructureBuildSizesKHR(
        const ApiCallInfo&                          call_info,
        args::GetAccelerationStructureBuildSizesKHR& args) {}

    virtual void Process_vkCmdTraceRaysKHR(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysKHR&                      args) {}

    virtual void Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
        const ApiCallInfo&                          call_info,
        args::GetRayTracingCaptureReplayShaderGroupHandlesKHR& args) {}

    virtual void Process_vkCmdTraceRaysIndirectKHR(
        const ApiCallInfo&                          call_info,
        args::CmdTraceRaysIndirectKHR&              args) {}

    virtual void Process_vkGetRayTracingShaderGroupStackSizeKHR(
        const ApiCallInfo&                          call_info,
        args::GetRayTracingShaderGroupStackSizeKHR& args) {}

    virtual void Process_vkCmdSetRayTracingPipelineStackSizeKHR(
        const ApiCallInfo&                          call_info,
        args::CmdSetRayTracingPipelineStackSizeKHR& args) {}

    virtual void Process_vkCmdDrawMeshTasksEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksEXT&                  args) {}

    virtual void Process_vkCmdDrawMeshTasksIndirectEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectEXT&          args) {}

    virtual void Process_vkCmdDrawMeshTasksIndirectCountEXT(
        const ApiCallInfo&                          call_info,
        args::CmdDrawMeshTasksIndirectCountEXT&     args) {}
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_CONSUMER_H
