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

#ifndef  GFXRECON_GENERATED_VULKAN_DECODER_H
#define  GFXRECON_GENERATED_VULKAN_DECODER_H

#include "decode/vulkan_decoder_base.h"
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

class VulkanDecoder : public VulkanDecoderBase
{
  public:
    VulkanDecoder() { }

    virtual ~VulkanDecoder() override { }

    virtual void DecodeFunctionCall(format::ApiCallId             call_id,
                                    const ApiCallInfo&            call_info,
                                    const uint8_t*                parameter_buffer,
                                    size_t                        buffer_size) override;

  private:
    size_t Decode_vkCreateInstance(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyInstance(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkEnumeratePhysicalDevices(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceFeatures(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceFormatProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceImageFormatProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceQueueFamilyProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceMemoryProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDevice(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDevice(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceQueue(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueSubmit(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueWaitIdle(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDeviceWaitIdle(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAllocateMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkFreeMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkMapMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkUnmapMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkFlushMappedMemoryRanges(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkInvalidateMappedMemoryRanges(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceMemoryCommitment(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindBufferMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindImageMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageSparseMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSparseImageFormatProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueBindSparse(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateFence(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyFence(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetFences(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetFenceStatus(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkWaitForFences(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateSemaphore(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroySemaphore(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetEventStatus(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateQueryPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyQueryPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetQueryPoolResults(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateBufferView(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyBufferView(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageSubresourceLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateImageView(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyImageView(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateShaderModule(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyShaderModule(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreatePipelineCache(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyPipelineCache(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPipelineCacheData(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkMergePipelineCaches(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateGraphicsPipelines(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateComputePipelines(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyPipeline(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreatePipelineLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyPipelineLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateSampler(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroySampler(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDescriptorSetLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDescriptorSetLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDescriptorPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDescriptorPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetDescriptorPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAllocateDescriptorSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkFreeDescriptorSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkUpdateDescriptorSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateFramebuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyFramebuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateRenderPass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyRenderPass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRenderAreaGranularity(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateCommandPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyCommandPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetCommandPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAllocateCommandBuffers(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkFreeCommandBuffers(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBeginCommandBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkEndCommandBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetCommandBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindPipeline(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetViewport(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetScissor(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetLineWidth(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthBias(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetBlendConstants(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthBounds(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetStencilCompareMask(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetStencilWriteMask(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetStencilReference(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindDescriptorSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindIndexBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindVertexBuffers(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDraw(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndexed(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndirect(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndexedIndirect(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDispatch(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDispatchIndirect(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBlitImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyBufferToImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyImageToBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdUpdateBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdFillBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdClearColorImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdClearDepthStencilImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdClearAttachments(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdResolveImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdResetEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWaitEvents(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPipelineBarrier(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginQuery(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndQuery(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdResetQueryPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWriteTimestamp(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyQueryPoolResults(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPushConstants(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginRenderPass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdNextSubpass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndRenderPass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdExecuteCommands(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindBufferMemory2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindImageMemory2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceGroupPeerMemoryFeatures(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDeviceMask(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDispatchBase(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkEnumeratePhysicalDeviceGroups(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageMemoryRequirements2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferMemoryRequirements2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageSparseMemoryRequirements2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceFeatures2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceFormatProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceImageFormatProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceQueueFamilyProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceMemoryProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSparseImageFormatProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkTrimCommandPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceQueue2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateSamplerYcbcrConversion(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroySamplerYcbcrConversion(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDescriptorUpdateTemplate(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDescriptorUpdateTemplate(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalBufferProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalFenceProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalSemaphoreProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDescriptorSetLayoutSupport(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndirectCount(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndexedIndirectCount(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateRenderPass2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginRenderPass2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdNextSubpass2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndRenderPass2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetQueryPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSemaphoreCounterValue(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkWaitSemaphores(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSignalSemaphore(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferDeviceAddress(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferOpaqueCaptureAddress(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceMemoryOpaqueCaptureAddress(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceToolProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreatePrivateDataSlot(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyPrivateDataSlot(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetPrivateData(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPrivateData(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetEvent2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdResetEvent2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWaitEvents2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPipelineBarrier2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWriteTimestamp2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueSubmit2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyBuffer2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyImage2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyBufferToImage2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyImageToBuffer2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBlitImage2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdResolveImage2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginRendering(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndRendering(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetCullMode(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetFrontFace(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetPrimitiveTopology(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetViewportWithCount(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetScissorWithCount(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindVertexBuffers2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthTestEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthWriteEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthCompareOp(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthBoundsTestEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetStencilTestEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetStencilOp(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetRasterizerDiscardEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthBiasEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetPrimitiveRestartEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceBufferMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceImageMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceImageSparseMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetLineStipple(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkMapMemory2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkUnmapMemory2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindIndexBuffer2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRenderingAreaGranularity(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceImageSubresourceLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageSubresourceLayout2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPushDescriptorSet(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetRenderingAttachmentLocations(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetRenderingInputAttachmentIndices(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindDescriptorSets2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPushConstants2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPushDescriptorSet2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyMemoryToImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyImageToMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyImageToImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkTransitionImageLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroySurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfaceSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfaceFormatsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfacePresentModesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateSwapchainKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroySwapchainKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSwapchainImagesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquireNextImageKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueuePresentKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceGroupPresentCapabilitiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceGroupSurfacePresentModesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDevicePresentRectanglesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquireNextImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceDisplayPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDisplayPlaneSupportedDisplaysKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDisplayModePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDisplayModeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDisplayPlaneCapabilitiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDisplayPlaneSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateSharedSwapchainsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateXlibSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceXlibPresentationSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateXcbSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceXcbPresentationSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateWaylandSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceWaylandPresentationSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateAndroidSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateWin32SurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceWin32PresentationSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceVideoCapabilitiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceVideoFormatPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateVideoSessionKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyVideoSessionKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetVideoSessionMemoryRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindVideoSessionMemoryKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateVideoSessionParametersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkUpdateVideoSessionParametersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyVideoSessionParametersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginVideoCodingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndVideoCodingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdControlVideoCodingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDecodeVideoKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginRenderingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndRenderingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceFeatures2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceFormatProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceImageFormatProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceQueueFamilyProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceMemoryProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceGroupPeerMemoryFeaturesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDeviceMaskKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDispatchBaseKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkTrimCommandPoolKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkEnumeratePhysicalDeviceGroupsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalBufferPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryWin32HandlePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryFdPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkImportSemaphoreWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSemaphoreWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkImportSemaphoreFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSemaphoreFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPushDescriptorSetKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDescriptorUpdateTemplateKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDescriptorUpdateTemplateKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateRenderPass2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginRenderPass2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdNextSubpass2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndRenderPass2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSwapchainStatusKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalFencePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkImportFenceWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetFenceWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkImportFenceFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetFenceFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquireProfilingLockKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkReleaseProfilingLockKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfaceCapabilities2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfaceFormats2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceDisplayProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDisplayModeProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDisplayPlaneCapabilities2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageMemoryRequirements2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferMemoryRequirements2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageSparseMemoryRequirements2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateSamplerYcbcrConversionKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroySamplerYcbcrConversionKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindBufferMemory2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindImageMemory2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDescriptorSetLayoutSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndirectCountKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndexedIndirectCountKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSemaphoreCounterValueKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkWaitSemaphoresKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSignalSemaphoreKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceFragmentShadingRatesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetFragmentShadingRateKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetRenderingAttachmentLocationsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetRenderingInputAttachmentIndicesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkWaitForPresentKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferDeviceAddressKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferOpaqueCaptureAddressKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceMemoryOpaqueCaptureAddressKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDeferredOperationKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDeferredOperationKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeferredOperationMaxConcurrencyKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeferredOperationResultKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPipelineExecutablePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPipelineExecutableStatisticsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPipelineExecutableInternalRepresentationsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkMapMemory2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkUnmapMemory2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetEncodedVideoSessionParametersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEncodeVideoKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetEvent2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdResetEvent2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWaitEvents2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPipelineBarrier2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWriteTimestamp2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueSubmit2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyBuffer2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyBufferToImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyImageToBuffer2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBlitImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdResolveImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdTraceRaysIndirect2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceBufferMemoryRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceImageMemoryRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceImageSparseMemoryRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindIndexBuffer2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRenderingAreaGranularityKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceImageSubresourceLayoutKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageSubresourceLayout2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreatePipelineBinariesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyPipelineBinaryKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPipelineKeyKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPipelineBinaryDataKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkReleaseCapturedPipelineDataKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetLineStippleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetCalibratedTimestampsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindDescriptorSets2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPushConstants2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPushDescriptorSet2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDescriptorBufferOffsets2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkFrameBoundaryANDROID(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDebugReportCallbackEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDebugReportCallbackEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDebugReportMessageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDebugMarkerSetObjectTagEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDebugMarkerSetObjectNameEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDebugMarkerBeginEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDebugMarkerEndEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDebugMarkerInsertEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindTransformFeedbackBuffersEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginTransformFeedbackEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndTransformFeedbackEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginQueryIndexedEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndQueryIndexedEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndirectByteCountEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageViewHandleNVX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageViewHandle64NVX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageViewAddressNVX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndirectCountAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndexedIndirectCountAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetShaderInfoAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateStreamDescriptorSurfaceGGP(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryWin32HandleNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateViSurfaceNN(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginConditionalRenderingEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndConditionalRenderingEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetViewportWScalingNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkReleaseDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquireXlibDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRandROutputDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfaceCapabilities2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDisplayPowerControlEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkRegisterDeviceEventEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkRegisterDisplayEventEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSwapchainCounterEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRefreshCycleDurationGOOGLE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPastPresentationTimingGOOGLE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDiscardRectangleEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDiscardRectangleEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDiscardRectangleModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetHdrMetadataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateIOSSurfaceMVK(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateMacOSSurfaceMVK(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetDebugUtilsObjectNameEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetDebugUtilsObjectTagEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueBeginDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueEndDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueInsertDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdInsertDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDebugUtilsMessengerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDebugUtilsMessengerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSubmitDebugUtilsMessageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetAndroidHardwareBufferPropertiesANDROID(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryAndroidHardwareBufferANDROID(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetSampleLocationsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceMultisamplePropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageDrmFormatModifierPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateValidationCacheEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyValidationCacheEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkMergeValidationCachesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetValidationCacheDataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindShadingRateImageNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetViewportShadingRatePaletteNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetCoarseSampleOrderNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateAccelerationStructureNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyAccelerationStructureNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetAccelerationStructureMemoryRequirementsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindAccelerationStructureMemoryNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBuildAccelerationStructureNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyAccelerationStructureNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdTraceRaysNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateRayTracingPipelinesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRayTracingShaderGroupHandlesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRayTracingShaderGroupHandlesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetAccelerationStructureHandleNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWriteAccelerationStructuresPropertiesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCompileDeferredNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryHostPointerPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWriteBufferMarkerAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWriteBufferMarker2AMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetCalibratedTimestampsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawMeshTasksNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawMeshTasksIndirectNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawMeshTasksIndirectCountNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetExclusiveScissorEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetExclusiveScissorNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetCheckpointNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetQueueCheckpointDataNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetQueueCheckpointData2NV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkInitializePerformanceApiINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkUninitializePerformanceApiINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetPerformanceMarkerINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetPerformanceStreamMarkerINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetPerformanceOverrideINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquirePerformanceConfigurationINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkReleasePerformanceConfigurationINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueSetPerformanceConfigurationINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPerformanceParameterINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetLocalDimmingAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateImagePipeSurfaceFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateMetalSurfaceEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferDeviceAddressEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceToolPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfacePresentModes2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquireFullScreenExclusiveModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkReleaseFullScreenExclusiveModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceGroupSurfacePresentModes2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateHeadlessSurfaceEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetLineStippleEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetQueryPoolEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetCullModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetFrontFaceEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetPrimitiveTopologyEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetViewportWithCountEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetScissorWithCountEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindVertexBuffers2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthTestEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthWriteEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthCompareOpEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthBoundsTestEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetStencilTestEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetStencilOpEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyMemoryToImageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyImageToMemoryEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyImageToImageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkTransitionImageLayoutEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageSubresourceLayout2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkReleaseSwapchainImagesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetGeneratedCommandsMemoryRequirementsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPreprocessGeneratedCommandsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdExecuteGeneratedCommandsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindPipelineShaderGroupNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateIndirectCommandsLayoutNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyIndirectCommandsLayoutNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthBias2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquireDrmDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDrmDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreatePrivateDataSlotEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyPrivateDataSlotEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetPrivateDataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPrivateDataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetFragmentShadingRateEnumNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceFaultInfoEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquireWinrtDisplayNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetWinrtDisplayNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDirectFBSurfaceEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetVertexInputEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryZirconHandleFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryZirconHandlePropertiesFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkImportSemaphoreZirconHandleFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSemaphoreZirconHandleFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindInvocationMaskHUAWEI(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryRemoteAddressNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetPatchControlPointsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetRasterizerDiscardEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthBiasEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetLogicOpEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetPrimitiveRestartEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateScreenSurfaceQNX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceScreenPresentationSupportQNX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetColorWriteEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawMultiEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawMultiIndexedEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBuildMicromapsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBuildMicromapsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyMicromapToMemoryEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyMemoryToMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkWriteMicromapsPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyMicromapToMemoryEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyMemoryToMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWriteMicromapsPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceMicromapCompatibilityEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMicromapBuildSizesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawClusterHUAWEI(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawClusterIndirectHUAWEI(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetDeviceMemoryPriorityEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDescriptorSetLayoutHostMappingInfoVALVE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDescriptorSetHostMappingVALVE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPipelineIndirectMemoryRequirementsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdUpdatePipelineIndirectBufferNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPipelineIndirectDeviceAddressNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthClampEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetPolygonModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetRasterizationSamplesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetSampleMaskEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetAlphaToCoverageEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetAlphaToOneEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetLogicOpEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetColorBlendEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetColorBlendEquationEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetColorWriteMaskEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetTessellationDomainOriginEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetRasterizationStreamEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetConservativeRasterizationModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetExtraPrimitiveOverestimationSizeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthClipEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetSampleLocationsEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetColorBlendAdvancedEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetProvokingVertexModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetLineRasterizationModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetLineStippleEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthClipNegativeOneToOneEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetViewportWScalingEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetViewportSwizzleNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetCoverageToColorEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetCoverageToColorLocationNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetCoverageModulationModeNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetCoverageModulationTableEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetCoverageModulationTableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetShadingRateImageEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetRepresentativeFragmentTestEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetCoverageReductionModeNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetShaderModuleIdentifierEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetShaderModuleCreateInfoIdentifierEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateOpticalFlowSessionNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyOpticalFlowSessionNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindOpticalFlowSessionImageNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdOpticalFlowExecuteNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAntiLagUpdateAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateShadersEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyShaderEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetShaderBinaryDataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindShadersEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthClampRangeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetFramebufferTilePropertiesQCOM(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDynamicRenderingTilePropertiesQCOM(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetLatencySleepModeNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkLatencySleepNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetLatencyMarkerNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetLatencyTimingsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueNotifyOutOfBandNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetAttachmentFeedbackLoopEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetGeneratedCommandsMemoryRequirementsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPreprocessGeneratedCommandsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdExecuteGeneratedCommandsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateIndirectCommandsLayoutEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyIndirectCommandsLayoutEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateIndirectExecutionSetEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyIndirectExecutionSetEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkUpdateIndirectExecutionSetPipelineEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkUpdateIndirectExecutionSetShaderEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBuildAccelerationStructuresKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBuildAccelerationStructuresIndirectKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyAccelerationStructureToMemoryKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyMemoryToAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkWriteAccelerationStructuresPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyAccelerationStructureToMemoryKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyMemoryToAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetAccelerationStructureDeviceAddressKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWriteAccelerationStructuresPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceAccelerationStructureCompatibilityKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetAccelerationStructureBuildSizesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdTraceRaysKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdTraceRaysIndirectKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRayTracingShaderGroupStackSizeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetRayTracingPipelineStackSizeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawMeshTasksEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawMeshTasksIndirectEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawMeshTasksIndirectCountEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
