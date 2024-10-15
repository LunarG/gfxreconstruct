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

#ifndef  GFXRECON_GENERATED_VULKAN_PRELOAD_REPLAYER_H
#define  GFXRECON_GENERATED_VULKAN_PRELOAD_REPLAYER_H

#include "decode/vulkan_decoder_base.h"
#include "decode/vulkan_preload_replayer_base.h"
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

class VulkanPreloadReplayer : public VulkanPreloadReplayerBase
{
  public:
    VulkanPreloadReplayer() { }

    virtual ~VulkanPreloadReplayer() { }

    virtual void ReplayFunctionCall(format::PacketCallId& packet_call_id, void* packet);

  private:
    void Replay_vkCreateInstance(Packet_vkCreateInstance* packet);

    void Replay_vkDestroyInstance(Packet_vkDestroyInstance* packet);

    void Replay_vkEnumeratePhysicalDevices(Packet_vkEnumeratePhysicalDevices* packet);

    void Replay_vkGetPhysicalDeviceFeatures(Packet_vkGetPhysicalDeviceFeatures* packet);

    void Replay_vkGetPhysicalDeviceFormatProperties(Packet_vkGetPhysicalDeviceFormatProperties* packet);

    void Replay_vkGetPhysicalDeviceImageFormatProperties(Packet_vkGetPhysicalDeviceImageFormatProperties* packet);

    void Replay_vkGetPhysicalDeviceProperties(Packet_vkGetPhysicalDeviceProperties* packet);

    void Replay_vkGetPhysicalDeviceQueueFamilyProperties(Packet_vkGetPhysicalDeviceQueueFamilyProperties* packet);

    void Replay_vkGetPhysicalDeviceMemoryProperties(Packet_vkGetPhysicalDeviceMemoryProperties* packet);

    void Replay_vkCreateDevice(Packet_vkCreateDevice* packet);

    void Replay_vkDestroyDevice(Packet_vkDestroyDevice* packet);

    void Replay_vkGetDeviceQueue(Packet_vkGetDeviceQueue* packet);

    void Replay_vkQueueSubmit(Packet_vkQueueSubmit* packet);

    void Replay_vkQueueWaitIdle(Packet_vkQueueWaitIdle* packet);

    void Replay_vkDeviceWaitIdle(Packet_vkDeviceWaitIdle* packet);

    void Replay_vkAllocateMemory(Packet_vkAllocateMemory* packet);

    void Replay_vkFreeMemory(Packet_vkFreeMemory* packet);

    void Replay_vkMapMemory(Packet_vkMapMemory* packet);

    void Replay_vkUnmapMemory(Packet_vkUnmapMemory* packet);

    void Replay_vkFlushMappedMemoryRanges(Packet_vkFlushMappedMemoryRanges* packet);

    void Replay_vkInvalidateMappedMemoryRanges(Packet_vkInvalidateMappedMemoryRanges* packet);

    void Replay_vkGetDeviceMemoryCommitment(Packet_vkGetDeviceMemoryCommitment* packet);

    void Replay_vkBindBufferMemory(Packet_vkBindBufferMemory* packet);

    void Replay_vkBindImageMemory(Packet_vkBindImageMemory* packet);

    void Replay_vkGetBufferMemoryRequirements(Packet_vkGetBufferMemoryRequirements* packet);

    void Replay_vkGetImageMemoryRequirements(Packet_vkGetImageMemoryRequirements* packet);

    void Replay_vkGetImageSparseMemoryRequirements(Packet_vkGetImageSparseMemoryRequirements* packet);

    void Replay_vkGetPhysicalDeviceSparseImageFormatProperties(Packet_vkGetPhysicalDeviceSparseImageFormatProperties* packet);

    void Replay_vkQueueBindSparse(Packet_vkQueueBindSparse* packet);

    void Replay_vkCreateFence(Packet_vkCreateFence* packet);

    void Replay_vkDestroyFence(Packet_vkDestroyFence* packet);

    void Replay_vkResetFences(Packet_vkResetFences* packet);

    void Replay_vkGetFenceStatus(Packet_vkGetFenceStatus* packet);

    void Replay_vkWaitForFences(Packet_vkWaitForFences* packet);

    void Replay_vkCreateSemaphore(Packet_vkCreateSemaphore* packet);

    void Replay_vkDestroySemaphore(Packet_vkDestroySemaphore* packet);

    void Replay_vkCreateEvent(Packet_vkCreateEvent* packet);

    void Replay_vkDestroyEvent(Packet_vkDestroyEvent* packet);

    void Replay_vkGetEventStatus(Packet_vkGetEventStatus* packet);

    void Replay_vkSetEvent(Packet_vkSetEvent* packet);

    void Replay_vkResetEvent(Packet_vkResetEvent* packet);

    void Replay_vkCreateQueryPool(Packet_vkCreateQueryPool* packet);

    void Replay_vkDestroyQueryPool(Packet_vkDestroyQueryPool* packet);

    void Replay_vkGetQueryPoolResults(Packet_vkGetQueryPoolResults* packet);

    void Replay_vkCreateBuffer(Packet_vkCreateBuffer* packet);

    void Replay_vkDestroyBuffer(Packet_vkDestroyBuffer* packet);

    void Replay_vkCreateBufferView(Packet_vkCreateBufferView* packet);

    void Replay_vkDestroyBufferView(Packet_vkDestroyBufferView* packet);

    void Replay_vkCreateImage(Packet_vkCreateImage* packet);

    void Replay_vkDestroyImage(Packet_vkDestroyImage* packet);

    void Replay_vkGetImageSubresourceLayout(Packet_vkGetImageSubresourceLayout* packet);

    void Replay_vkCreateImageView(Packet_vkCreateImageView* packet);

    void Replay_vkDestroyImageView(Packet_vkDestroyImageView* packet);

    void Replay_vkCreateShaderModule(Packet_vkCreateShaderModule* packet);

    void Replay_vkDestroyShaderModule(Packet_vkDestroyShaderModule* packet);

    void Replay_vkCreatePipelineCache(Packet_vkCreatePipelineCache* packet);

    void Replay_vkDestroyPipelineCache(Packet_vkDestroyPipelineCache* packet);

    void Replay_vkGetPipelineCacheData(Packet_vkGetPipelineCacheData* packet);

    void Replay_vkMergePipelineCaches(Packet_vkMergePipelineCaches* packet);

    void Replay_vkCreateGraphicsPipelines(Packet_vkCreateGraphicsPipelines* packet);

    void Replay_vkCreateComputePipelines(Packet_vkCreateComputePipelines* packet);

    void Replay_vkDestroyPipeline(Packet_vkDestroyPipeline* packet);

    void Replay_vkCreatePipelineLayout(Packet_vkCreatePipelineLayout* packet);

    void Replay_vkDestroyPipelineLayout(Packet_vkDestroyPipelineLayout* packet);

    void Replay_vkCreateSampler(Packet_vkCreateSampler* packet);

    void Replay_vkDestroySampler(Packet_vkDestroySampler* packet);

    void Replay_vkCreateDescriptorSetLayout(Packet_vkCreateDescriptorSetLayout* packet);

    void Replay_vkDestroyDescriptorSetLayout(Packet_vkDestroyDescriptorSetLayout* packet);

    void Replay_vkCreateDescriptorPool(Packet_vkCreateDescriptorPool* packet);

    void Replay_vkDestroyDescriptorPool(Packet_vkDestroyDescriptorPool* packet);

    void Replay_vkResetDescriptorPool(Packet_vkResetDescriptorPool* packet);

    void Replay_vkAllocateDescriptorSets(Packet_vkAllocateDescriptorSets* packet);

    void Replay_vkFreeDescriptorSets(Packet_vkFreeDescriptorSets* packet);

    void Replay_vkUpdateDescriptorSets(Packet_vkUpdateDescriptorSets* packet);

    void Replay_vkCreateFramebuffer(Packet_vkCreateFramebuffer* packet);

    void Replay_vkDestroyFramebuffer(Packet_vkDestroyFramebuffer* packet);

    void Replay_vkCreateRenderPass(Packet_vkCreateRenderPass* packet);

    void Replay_vkDestroyRenderPass(Packet_vkDestroyRenderPass* packet);

    void Replay_vkGetRenderAreaGranularity(Packet_vkGetRenderAreaGranularity* packet);

    void Replay_vkCreateCommandPool(Packet_vkCreateCommandPool* packet);

    void Replay_vkDestroyCommandPool(Packet_vkDestroyCommandPool* packet);

    void Replay_vkResetCommandPool(Packet_vkResetCommandPool* packet);

    void Replay_vkAllocateCommandBuffers(Packet_vkAllocateCommandBuffers* packet);

    void Replay_vkFreeCommandBuffers(Packet_vkFreeCommandBuffers* packet);

    void Replay_vkBeginCommandBuffer(Packet_vkBeginCommandBuffer* packet);

    void Replay_vkEndCommandBuffer(Packet_vkEndCommandBuffer* packet);

    void Replay_vkResetCommandBuffer(Packet_vkResetCommandBuffer* packet);

    void Replay_vkCmdBindPipeline(Packet_vkCmdBindPipeline* packet);

    void Replay_vkCmdSetViewport(Packet_vkCmdSetViewport* packet);

    void Replay_vkCmdSetScissor(Packet_vkCmdSetScissor* packet);

    void Replay_vkCmdSetLineWidth(Packet_vkCmdSetLineWidth* packet);

    void Replay_vkCmdSetDepthBias(Packet_vkCmdSetDepthBias* packet);

    void Replay_vkCmdSetBlendConstants(Packet_vkCmdSetBlendConstants* packet);

    void Replay_vkCmdSetDepthBounds(Packet_vkCmdSetDepthBounds* packet);

    void Replay_vkCmdSetStencilCompareMask(Packet_vkCmdSetStencilCompareMask* packet);

    void Replay_vkCmdSetStencilWriteMask(Packet_vkCmdSetStencilWriteMask* packet);

    void Replay_vkCmdSetStencilReference(Packet_vkCmdSetStencilReference* packet);

    void Replay_vkCmdBindDescriptorSets(Packet_vkCmdBindDescriptorSets* packet);

    void Replay_vkCmdBindIndexBuffer(Packet_vkCmdBindIndexBuffer* packet);

    void Replay_vkCmdBindVertexBuffers(Packet_vkCmdBindVertexBuffers* packet);

    void Replay_vkCmdDraw(Packet_vkCmdDraw* packet);

    void Replay_vkCmdDrawIndexed(Packet_vkCmdDrawIndexed* packet);

    void Replay_vkCmdDrawIndirect(Packet_vkCmdDrawIndirect* packet);

    void Replay_vkCmdDrawIndexedIndirect(Packet_vkCmdDrawIndexedIndirect* packet);

    void Replay_vkCmdDispatch(Packet_vkCmdDispatch* packet);

    void Replay_vkCmdDispatchIndirect(Packet_vkCmdDispatchIndirect* packet);

    void Replay_vkCmdCopyBuffer(Packet_vkCmdCopyBuffer* packet);

    void Replay_vkCmdCopyImage(Packet_vkCmdCopyImage* packet);

    void Replay_vkCmdBlitImage(Packet_vkCmdBlitImage* packet);

    void Replay_vkCmdCopyBufferToImage(Packet_vkCmdCopyBufferToImage* packet);

    void Replay_vkCmdCopyImageToBuffer(Packet_vkCmdCopyImageToBuffer* packet);

    void Replay_vkCmdUpdateBuffer(Packet_vkCmdUpdateBuffer* packet);

    void Replay_vkCmdFillBuffer(Packet_vkCmdFillBuffer* packet);

    void Replay_vkCmdClearColorImage(Packet_vkCmdClearColorImage* packet);

    void Replay_vkCmdClearDepthStencilImage(Packet_vkCmdClearDepthStencilImage* packet);

    void Replay_vkCmdClearAttachments(Packet_vkCmdClearAttachments* packet);

    void Replay_vkCmdResolveImage(Packet_vkCmdResolveImage* packet);

    void Replay_vkCmdSetEvent(Packet_vkCmdSetEvent* packet);

    void Replay_vkCmdResetEvent(Packet_vkCmdResetEvent* packet);

    void Replay_vkCmdWaitEvents(Packet_vkCmdWaitEvents* packet);

    void Replay_vkCmdPipelineBarrier(Packet_vkCmdPipelineBarrier* packet);

    void Replay_vkCmdBeginQuery(Packet_vkCmdBeginQuery* packet);

    void Replay_vkCmdEndQuery(Packet_vkCmdEndQuery* packet);

    void Replay_vkCmdResetQueryPool(Packet_vkCmdResetQueryPool* packet);

    void Replay_vkCmdWriteTimestamp(Packet_vkCmdWriteTimestamp* packet);

    void Replay_vkCmdCopyQueryPoolResults(Packet_vkCmdCopyQueryPoolResults* packet);

    void Replay_vkCmdPushConstants(Packet_vkCmdPushConstants* packet);

    void Replay_vkCmdBeginRenderPass(Packet_vkCmdBeginRenderPass* packet);

    void Replay_vkCmdNextSubpass(Packet_vkCmdNextSubpass* packet);

    void Replay_vkCmdEndRenderPass(Packet_vkCmdEndRenderPass* packet);

    void Replay_vkCmdExecuteCommands(Packet_vkCmdExecuteCommands* packet);

    void Replay_vkBindBufferMemory2(Packet_vkBindBufferMemory2* packet);

    void Replay_vkBindImageMemory2(Packet_vkBindImageMemory2* packet);

    void Replay_vkGetDeviceGroupPeerMemoryFeatures(Packet_vkGetDeviceGroupPeerMemoryFeatures* packet);

    void Replay_vkCmdSetDeviceMask(Packet_vkCmdSetDeviceMask* packet);

    void Replay_vkCmdDispatchBase(Packet_vkCmdDispatchBase* packet);

    void Replay_vkEnumeratePhysicalDeviceGroups(Packet_vkEnumeratePhysicalDeviceGroups* packet);

    void Replay_vkGetImageMemoryRequirements2(Packet_vkGetImageMemoryRequirements2* packet);

    void Replay_vkGetBufferMemoryRequirements2(Packet_vkGetBufferMemoryRequirements2* packet);

    void Replay_vkGetImageSparseMemoryRequirements2(Packet_vkGetImageSparseMemoryRequirements2* packet);

    void Replay_vkGetPhysicalDeviceFeatures2(Packet_vkGetPhysicalDeviceFeatures2* packet);

    void Replay_vkGetPhysicalDeviceProperties2(Packet_vkGetPhysicalDeviceProperties2* packet);

    void Replay_vkGetPhysicalDeviceFormatProperties2(Packet_vkGetPhysicalDeviceFormatProperties2* packet);

    void Replay_vkGetPhysicalDeviceImageFormatProperties2(Packet_vkGetPhysicalDeviceImageFormatProperties2* packet);

    void Replay_vkGetPhysicalDeviceQueueFamilyProperties2(Packet_vkGetPhysicalDeviceQueueFamilyProperties2* packet);

    void Replay_vkGetPhysicalDeviceMemoryProperties2(Packet_vkGetPhysicalDeviceMemoryProperties2* packet);

    void Replay_vkGetPhysicalDeviceSparseImageFormatProperties2(Packet_vkGetPhysicalDeviceSparseImageFormatProperties2* packet);

    void Replay_vkTrimCommandPool(Packet_vkTrimCommandPool* packet);

    void Replay_vkGetDeviceQueue2(Packet_vkGetDeviceQueue2* packet);

    void Replay_vkCreateSamplerYcbcrConversion(Packet_vkCreateSamplerYcbcrConversion* packet);

    void Replay_vkDestroySamplerYcbcrConversion(Packet_vkDestroySamplerYcbcrConversion* packet);

    void Replay_vkCreateDescriptorUpdateTemplate(Packet_vkCreateDescriptorUpdateTemplate* packet);

    void Replay_vkDestroyDescriptorUpdateTemplate(Packet_vkDestroyDescriptorUpdateTemplate* packet);

    void Replay_vkGetPhysicalDeviceExternalBufferProperties(Packet_vkGetPhysicalDeviceExternalBufferProperties* packet);

    void Replay_vkGetPhysicalDeviceExternalFenceProperties(Packet_vkGetPhysicalDeviceExternalFenceProperties* packet);

    void Replay_vkGetPhysicalDeviceExternalSemaphoreProperties(Packet_vkGetPhysicalDeviceExternalSemaphoreProperties* packet);

    void Replay_vkGetDescriptorSetLayoutSupport(Packet_vkGetDescriptorSetLayoutSupport* packet);

    void Replay_vkCmdDrawIndirectCount(Packet_vkCmdDrawIndirectCount* packet);

    void Replay_vkCmdDrawIndexedIndirectCount(Packet_vkCmdDrawIndexedIndirectCount* packet);

    void Replay_vkCreateRenderPass2(Packet_vkCreateRenderPass2* packet);

    void Replay_vkCmdBeginRenderPass2(Packet_vkCmdBeginRenderPass2* packet);

    void Replay_vkCmdNextSubpass2(Packet_vkCmdNextSubpass2* packet);

    void Replay_vkCmdEndRenderPass2(Packet_vkCmdEndRenderPass2* packet);

    void Replay_vkResetQueryPool(Packet_vkResetQueryPool* packet);

    void Replay_vkGetSemaphoreCounterValue(Packet_vkGetSemaphoreCounterValue* packet);

    void Replay_vkWaitSemaphores(Packet_vkWaitSemaphores* packet);

    void Replay_vkSignalSemaphore(Packet_vkSignalSemaphore* packet);

    void Replay_vkGetBufferDeviceAddress(Packet_vkGetBufferDeviceAddress* packet);

    void Replay_vkGetBufferOpaqueCaptureAddress(Packet_vkGetBufferOpaqueCaptureAddress* packet);

    void Replay_vkGetDeviceMemoryOpaqueCaptureAddress(Packet_vkGetDeviceMemoryOpaqueCaptureAddress* packet);

    void Replay_vkGetPhysicalDeviceToolProperties(Packet_vkGetPhysicalDeviceToolProperties* packet);

    void Replay_vkCreatePrivateDataSlot(Packet_vkCreatePrivateDataSlot* packet);

    void Replay_vkDestroyPrivateDataSlot(Packet_vkDestroyPrivateDataSlot* packet);

    void Replay_vkSetPrivateData(Packet_vkSetPrivateData* packet);

    void Replay_vkGetPrivateData(Packet_vkGetPrivateData* packet);

    void Replay_vkCmdSetEvent2(Packet_vkCmdSetEvent2* packet);

    void Replay_vkCmdResetEvent2(Packet_vkCmdResetEvent2* packet);

    void Replay_vkCmdWaitEvents2(Packet_vkCmdWaitEvents2* packet);

    void Replay_vkCmdPipelineBarrier2(Packet_vkCmdPipelineBarrier2* packet);

    void Replay_vkCmdWriteTimestamp2(Packet_vkCmdWriteTimestamp2* packet);

    void Replay_vkQueueSubmit2(Packet_vkQueueSubmit2* packet);

    void Replay_vkCmdCopyBuffer2(Packet_vkCmdCopyBuffer2* packet);

    void Replay_vkCmdCopyImage2(Packet_vkCmdCopyImage2* packet);

    void Replay_vkCmdCopyBufferToImage2(Packet_vkCmdCopyBufferToImage2* packet);

    void Replay_vkCmdCopyImageToBuffer2(Packet_vkCmdCopyImageToBuffer2* packet);

    void Replay_vkCmdBlitImage2(Packet_vkCmdBlitImage2* packet);

    void Replay_vkCmdResolveImage2(Packet_vkCmdResolveImage2* packet);

    void Replay_vkCmdBeginRendering(Packet_vkCmdBeginRendering* packet);

    void Replay_vkCmdEndRendering(Packet_vkCmdEndRendering* packet);

    void Replay_vkCmdSetCullMode(Packet_vkCmdSetCullMode* packet);

    void Replay_vkCmdSetFrontFace(Packet_vkCmdSetFrontFace* packet);

    void Replay_vkCmdSetPrimitiveTopology(Packet_vkCmdSetPrimitiveTopology* packet);

    void Replay_vkCmdSetViewportWithCount(Packet_vkCmdSetViewportWithCount* packet);

    void Replay_vkCmdSetScissorWithCount(Packet_vkCmdSetScissorWithCount* packet);

    void Replay_vkCmdBindVertexBuffers2(Packet_vkCmdBindVertexBuffers2* packet);

    void Replay_vkCmdSetDepthTestEnable(Packet_vkCmdSetDepthTestEnable* packet);

    void Replay_vkCmdSetDepthWriteEnable(Packet_vkCmdSetDepthWriteEnable* packet);

    void Replay_vkCmdSetDepthCompareOp(Packet_vkCmdSetDepthCompareOp* packet);

    void Replay_vkCmdSetDepthBoundsTestEnable(Packet_vkCmdSetDepthBoundsTestEnable* packet);

    void Replay_vkCmdSetStencilTestEnable(Packet_vkCmdSetStencilTestEnable* packet);

    void Replay_vkCmdSetStencilOp(Packet_vkCmdSetStencilOp* packet);

    void Replay_vkCmdSetRasterizerDiscardEnable(Packet_vkCmdSetRasterizerDiscardEnable* packet);

    void Replay_vkCmdSetDepthBiasEnable(Packet_vkCmdSetDepthBiasEnable* packet);

    void Replay_vkCmdSetPrimitiveRestartEnable(Packet_vkCmdSetPrimitiveRestartEnable* packet);

    void Replay_vkGetDeviceBufferMemoryRequirements(Packet_vkGetDeviceBufferMemoryRequirements* packet);

    void Replay_vkGetDeviceImageMemoryRequirements(Packet_vkGetDeviceImageMemoryRequirements* packet);

    void Replay_vkGetDeviceImageSparseMemoryRequirements(Packet_vkGetDeviceImageSparseMemoryRequirements* packet);

    void Replay_vkDestroySurfaceKHR(Packet_vkDestroySurfaceKHR* packet);

    void Replay_vkGetPhysicalDeviceSurfaceSupportKHR(Packet_vkGetPhysicalDeviceSurfaceSupportKHR* packet);

    void Replay_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(Packet_vkGetPhysicalDeviceSurfaceCapabilitiesKHR* packet);

    void Replay_vkGetPhysicalDeviceSurfaceFormatsKHR(Packet_vkGetPhysicalDeviceSurfaceFormatsKHR* packet);

    void Replay_vkGetPhysicalDeviceSurfacePresentModesKHR(Packet_vkGetPhysicalDeviceSurfacePresentModesKHR* packet);

    void Replay_vkCreateSwapchainKHR(Packet_vkCreateSwapchainKHR* packet);

    void Replay_vkDestroySwapchainKHR(Packet_vkDestroySwapchainKHR* packet);

    void Replay_vkGetSwapchainImagesKHR(Packet_vkGetSwapchainImagesKHR* packet);

    void Replay_vkAcquireNextImageKHR(Packet_vkAcquireNextImageKHR* packet);

    void Replay_vkQueuePresentKHR(Packet_vkQueuePresentKHR* packet);

    void Replay_vkGetDeviceGroupPresentCapabilitiesKHR(Packet_vkGetDeviceGroupPresentCapabilitiesKHR* packet);

    void Replay_vkGetDeviceGroupSurfacePresentModesKHR(Packet_vkGetDeviceGroupSurfacePresentModesKHR* packet);

    void Replay_vkGetPhysicalDevicePresentRectanglesKHR(Packet_vkGetPhysicalDevicePresentRectanglesKHR* packet);

    void Replay_vkAcquireNextImage2KHR(Packet_vkAcquireNextImage2KHR* packet);

    void Replay_vkGetPhysicalDeviceDisplayPropertiesKHR(Packet_vkGetPhysicalDeviceDisplayPropertiesKHR* packet);

    void Replay_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(Packet_vkGetPhysicalDeviceDisplayPlanePropertiesKHR* packet);

    void Replay_vkGetDisplayPlaneSupportedDisplaysKHR(Packet_vkGetDisplayPlaneSupportedDisplaysKHR* packet);

    void Replay_vkGetDisplayModePropertiesKHR(Packet_vkGetDisplayModePropertiesKHR* packet);

    void Replay_vkCreateDisplayModeKHR(Packet_vkCreateDisplayModeKHR* packet);

    void Replay_vkGetDisplayPlaneCapabilitiesKHR(Packet_vkGetDisplayPlaneCapabilitiesKHR* packet);

    void Replay_vkCreateDisplayPlaneSurfaceKHR(Packet_vkCreateDisplayPlaneSurfaceKHR* packet);

    void Replay_vkCreateSharedSwapchainsKHR(Packet_vkCreateSharedSwapchainsKHR* packet);

    void Replay_vkCreateXlibSurfaceKHR(Packet_vkCreateXlibSurfaceKHR* packet);

    void Replay_vkGetPhysicalDeviceXlibPresentationSupportKHR(Packet_vkGetPhysicalDeviceXlibPresentationSupportKHR* packet);

    void Replay_vkCreateXcbSurfaceKHR(Packet_vkCreateXcbSurfaceKHR* packet);

    void Replay_vkGetPhysicalDeviceXcbPresentationSupportKHR(Packet_vkGetPhysicalDeviceXcbPresentationSupportKHR* packet);

    void Replay_vkCreateWaylandSurfaceKHR(Packet_vkCreateWaylandSurfaceKHR* packet);

    void Replay_vkGetPhysicalDeviceWaylandPresentationSupportKHR(Packet_vkGetPhysicalDeviceWaylandPresentationSupportKHR* packet);

    void Replay_vkCreateAndroidSurfaceKHR(Packet_vkCreateAndroidSurfaceKHR* packet);

    void Replay_vkCreateWin32SurfaceKHR(Packet_vkCreateWin32SurfaceKHR* packet);

    void Replay_vkGetPhysicalDeviceWin32PresentationSupportKHR(Packet_vkGetPhysicalDeviceWin32PresentationSupportKHR* packet);

    void Replay_vkGetPhysicalDeviceVideoCapabilitiesKHR(Packet_vkGetPhysicalDeviceVideoCapabilitiesKHR* packet);

    void Replay_vkGetPhysicalDeviceVideoFormatPropertiesKHR(Packet_vkGetPhysicalDeviceVideoFormatPropertiesKHR* packet);

    void Replay_vkCreateVideoSessionKHR(Packet_vkCreateVideoSessionKHR* packet);

    void Replay_vkDestroyVideoSessionKHR(Packet_vkDestroyVideoSessionKHR* packet);

    void Replay_vkGetVideoSessionMemoryRequirementsKHR(Packet_vkGetVideoSessionMemoryRequirementsKHR* packet);

    void Replay_vkBindVideoSessionMemoryKHR(Packet_vkBindVideoSessionMemoryKHR* packet);

    void Replay_vkCreateVideoSessionParametersKHR(Packet_vkCreateVideoSessionParametersKHR* packet);

    void Replay_vkUpdateVideoSessionParametersKHR(Packet_vkUpdateVideoSessionParametersKHR* packet);

    void Replay_vkDestroyVideoSessionParametersKHR(Packet_vkDestroyVideoSessionParametersKHR* packet);

    void Replay_vkCmdBeginVideoCodingKHR(Packet_vkCmdBeginVideoCodingKHR* packet);

    void Replay_vkCmdEndVideoCodingKHR(Packet_vkCmdEndVideoCodingKHR* packet);

    void Replay_vkCmdControlVideoCodingKHR(Packet_vkCmdControlVideoCodingKHR* packet);

    void Replay_vkCmdDecodeVideoKHR(Packet_vkCmdDecodeVideoKHR* packet);

    void Replay_vkCmdBeginRenderingKHR(Packet_vkCmdBeginRenderingKHR* packet);

    void Replay_vkCmdEndRenderingKHR(Packet_vkCmdEndRenderingKHR* packet);

    void Replay_vkGetPhysicalDeviceFeatures2KHR(Packet_vkGetPhysicalDeviceFeatures2KHR* packet);

    void Replay_vkGetPhysicalDeviceProperties2KHR(Packet_vkGetPhysicalDeviceProperties2KHR* packet);

    void Replay_vkGetPhysicalDeviceFormatProperties2KHR(Packet_vkGetPhysicalDeviceFormatProperties2KHR* packet);

    void Replay_vkGetPhysicalDeviceImageFormatProperties2KHR(Packet_vkGetPhysicalDeviceImageFormatProperties2KHR* packet);

    void Replay_vkGetPhysicalDeviceQueueFamilyProperties2KHR(Packet_vkGetPhysicalDeviceQueueFamilyProperties2KHR* packet);

    void Replay_vkGetPhysicalDeviceMemoryProperties2KHR(Packet_vkGetPhysicalDeviceMemoryProperties2KHR* packet);

    void Replay_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(Packet_vkGetPhysicalDeviceSparseImageFormatProperties2KHR* packet);

    void Replay_vkGetDeviceGroupPeerMemoryFeaturesKHR(Packet_vkGetDeviceGroupPeerMemoryFeaturesKHR* packet);

    void Replay_vkCmdSetDeviceMaskKHR(Packet_vkCmdSetDeviceMaskKHR* packet);

    void Replay_vkCmdDispatchBaseKHR(Packet_vkCmdDispatchBaseKHR* packet);

    void Replay_vkTrimCommandPoolKHR(Packet_vkTrimCommandPoolKHR* packet);

    void Replay_vkEnumeratePhysicalDeviceGroupsKHR(Packet_vkEnumeratePhysicalDeviceGroupsKHR* packet);

    void Replay_vkGetPhysicalDeviceExternalBufferPropertiesKHR(Packet_vkGetPhysicalDeviceExternalBufferPropertiesKHR* packet);

    void Replay_vkGetMemoryWin32HandleKHR(Packet_vkGetMemoryWin32HandleKHR* packet);

    void Replay_vkGetMemoryWin32HandlePropertiesKHR(Packet_vkGetMemoryWin32HandlePropertiesKHR* packet);

    void Replay_vkGetMemoryFdKHR(Packet_vkGetMemoryFdKHR* packet);

    void Replay_vkGetMemoryFdPropertiesKHR(Packet_vkGetMemoryFdPropertiesKHR* packet);

    void Replay_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(Packet_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR* packet);

    void Replay_vkImportSemaphoreWin32HandleKHR(Packet_vkImportSemaphoreWin32HandleKHR* packet);

    void Replay_vkGetSemaphoreWin32HandleKHR(Packet_vkGetSemaphoreWin32HandleKHR* packet);

    void Replay_vkImportSemaphoreFdKHR(Packet_vkImportSemaphoreFdKHR* packet);

    void Replay_vkGetSemaphoreFdKHR(Packet_vkGetSemaphoreFdKHR* packet);

    void Replay_vkCmdPushDescriptorSetKHR(Packet_vkCmdPushDescriptorSetKHR* packet);

    void Replay_vkCreateDescriptorUpdateTemplateKHR(Packet_vkCreateDescriptorUpdateTemplateKHR* packet);

    void Replay_vkDestroyDescriptorUpdateTemplateKHR(Packet_vkDestroyDescriptorUpdateTemplateKHR* packet);

    void Replay_vkCreateRenderPass2KHR(Packet_vkCreateRenderPass2KHR* packet);

    void Replay_vkCmdBeginRenderPass2KHR(Packet_vkCmdBeginRenderPass2KHR* packet);

    void Replay_vkCmdNextSubpass2KHR(Packet_vkCmdNextSubpass2KHR* packet);

    void Replay_vkCmdEndRenderPass2KHR(Packet_vkCmdEndRenderPass2KHR* packet);

    void Replay_vkGetSwapchainStatusKHR(Packet_vkGetSwapchainStatusKHR* packet);

    void Replay_vkGetPhysicalDeviceExternalFencePropertiesKHR(Packet_vkGetPhysicalDeviceExternalFencePropertiesKHR* packet);

    void Replay_vkImportFenceWin32HandleKHR(Packet_vkImportFenceWin32HandleKHR* packet);

    void Replay_vkGetFenceWin32HandleKHR(Packet_vkGetFenceWin32HandleKHR* packet);

    void Replay_vkImportFenceFdKHR(Packet_vkImportFenceFdKHR* packet);

    void Replay_vkGetFenceFdKHR(Packet_vkGetFenceFdKHR* packet);

    void Replay_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(Packet_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR* packet);

    void Replay_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(Packet_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR* packet);

    void Replay_vkAcquireProfilingLockKHR(Packet_vkAcquireProfilingLockKHR* packet);

    void Replay_vkReleaseProfilingLockKHR(Packet_vkReleaseProfilingLockKHR* packet);

    void Replay_vkGetPhysicalDeviceSurfaceCapabilities2KHR(Packet_vkGetPhysicalDeviceSurfaceCapabilities2KHR* packet);

    void Replay_vkGetPhysicalDeviceSurfaceFormats2KHR(Packet_vkGetPhysicalDeviceSurfaceFormats2KHR* packet);

    void Replay_vkGetPhysicalDeviceDisplayProperties2KHR(Packet_vkGetPhysicalDeviceDisplayProperties2KHR* packet);

    void Replay_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(Packet_vkGetPhysicalDeviceDisplayPlaneProperties2KHR* packet);

    void Replay_vkGetDisplayModeProperties2KHR(Packet_vkGetDisplayModeProperties2KHR* packet);

    void Replay_vkGetDisplayPlaneCapabilities2KHR(Packet_vkGetDisplayPlaneCapabilities2KHR* packet);

    void Replay_vkGetImageMemoryRequirements2KHR(Packet_vkGetImageMemoryRequirements2KHR* packet);

    void Replay_vkGetBufferMemoryRequirements2KHR(Packet_vkGetBufferMemoryRequirements2KHR* packet);

    void Replay_vkGetImageSparseMemoryRequirements2KHR(Packet_vkGetImageSparseMemoryRequirements2KHR* packet);

    void Replay_vkCreateSamplerYcbcrConversionKHR(Packet_vkCreateSamplerYcbcrConversionKHR* packet);

    void Replay_vkDestroySamplerYcbcrConversionKHR(Packet_vkDestroySamplerYcbcrConversionKHR* packet);

    void Replay_vkBindBufferMemory2KHR(Packet_vkBindBufferMemory2KHR* packet);

    void Replay_vkBindImageMemory2KHR(Packet_vkBindImageMemory2KHR* packet);

    void Replay_vkGetDescriptorSetLayoutSupportKHR(Packet_vkGetDescriptorSetLayoutSupportKHR* packet);

    void Replay_vkCmdDrawIndirectCountKHR(Packet_vkCmdDrawIndirectCountKHR* packet);

    void Replay_vkCmdDrawIndexedIndirectCountKHR(Packet_vkCmdDrawIndexedIndirectCountKHR* packet);

    void Replay_vkGetSemaphoreCounterValueKHR(Packet_vkGetSemaphoreCounterValueKHR* packet);

    void Replay_vkWaitSemaphoresKHR(Packet_vkWaitSemaphoresKHR* packet);

    void Replay_vkSignalSemaphoreKHR(Packet_vkSignalSemaphoreKHR* packet);

    void Replay_vkGetPhysicalDeviceFragmentShadingRatesKHR(Packet_vkGetPhysicalDeviceFragmentShadingRatesKHR* packet);

    void Replay_vkCmdSetFragmentShadingRateKHR(Packet_vkCmdSetFragmentShadingRateKHR* packet);

    void Replay_vkCmdSetRenderingAttachmentLocationsKHR(Packet_vkCmdSetRenderingAttachmentLocationsKHR* packet);

    void Replay_vkCmdSetRenderingInputAttachmentIndicesKHR(Packet_vkCmdSetRenderingInputAttachmentIndicesKHR* packet);

    void Replay_vkWaitForPresentKHR(Packet_vkWaitForPresentKHR* packet);

    void Replay_vkGetBufferDeviceAddressKHR(Packet_vkGetBufferDeviceAddressKHR* packet);

    void Replay_vkGetBufferOpaqueCaptureAddressKHR(Packet_vkGetBufferOpaqueCaptureAddressKHR* packet);

    void Replay_vkGetDeviceMemoryOpaqueCaptureAddressKHR(Packet_vkGetDeviceMemoryOpaqueCaptureAddressKHR* packet);

    void Replay_vkCreateDeferredOperationKHR(Packet_vkCreateDeferredOperationKHR* packet);

    void Replay_vkDestroyDeferredOperationKHR(Packet_vkDestroyDeferredOperationKHR* packet);

    void Replay_vkGetDeferredOperationMaxConcurrencyKHR(Packet_vkGetDeferredOperationMaxConcurrencyKHR* packet);

    void Replay_vkGetDeferredOperationResultKHR(Packet_vkGetDeferredOperationResultKHR* packet);

    void Replay_vkDeferredOperationJoinKHR(Packet_vkDeferredOperationJoinKHR* packet);

    void Replay_vkGetPipelineExecutablePropertiesKHR(Packet_vkGetPipelineExecutablePropertiesKHR* packet);

    void Replay_vkGetPipelineExecutableStatisticsKHR(Packet_vkGetPipelineExecutableStatisticsKHR* packet);

    void Replay_vkGetPipelineExecutableInternalRepresentationsKHR(Packet_vkGetPipelineExecutableInternalRepresentationsKHR* packet);

    void Replay_vkMapMemory2KHR(Packet_vkMapMemory2KHR* packet);

    void Replay_vkUnmapMemory2KHR(Packet_vkUnmapMemory2KHR* packet);

    void Replay_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(Packet_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR* packet);

    void Replay_vkGetEncodedVideoSessionParametersKHR(Packet_vkGetEncodedVideoSessionParametersKHR* packet);

    void Replay_vkCmdEncodeVideoKHR(Packet_vkCmdEncodeVideoKHR* packet);

    void Replay_vkCmdSetEvent2KHR(Packet_vkCmdSetEvent2KHR* packet);

    void Replay_vkCmdResetEvent2KHR(Packet_vkCmdResetEvent2KHR* packet);

    void Replay_vkCmdWaitEvents2KHR(Packet_vkCmdWaitEvents2KHR* packet);

    void Replay_vkCmdPipelineBarrier2KHR(Packet_vkCmdPipelineBarrier2KHR* packet);

    void Replay_vkCmdWriteTimestamp2KHR(Packet_vkCmdWriteTimestamp2KHR* packet);

    void Replay_vkQueueSubmit2KHR(Packet_vkQueueSubmit2KHR* packet);

    void Replay_vkCmdWriteBufferMarker2AMD(Packet_vkCmdWriteBufferMarker2AMD* packet);

    void Replay_vkGetQueueCheckpointData2NV(Packet_vkGetQueueCheckpointData2NV* packet);

    void Replay_vkCmdCopyBuffer2KHR(Packet_vkCmdCopyBuffer2KHR* packet);

    void Replay_vkCmdCopyImage2KHR(Packet_vkCmdCopyImage2KHR* packet);

    void Replay_vkCmdCopyBufferToImage2KHR(Packet_vkCmdCopyBufferToImage2KHR* packet);

    void Replay_vkCmdCopyImageToBuffer2KHR(Packet_vkCmdCopyImageToBuffer2KHR* packet);

    void Replay_vkCmdBlitImage2KHR(Packet_vkCmdBlitImage2KHR* packet);

    void Replay_vkCmdResolveImage2KHR(Packet_vkCmdResolveImage2KHR* packet);

    void Replay_vkCmdTraceRaysIndirect2KHR(Packet_vkCmdTraceRaysIndirect2KHR* packet);

    void Replay_vkGetDeviceBufferMemoryRequirementsKHR(Packet_vkGetDeviceBufferMemoryRequirementsKHR* packet);

    void Replay_vkGetDeviceImageMemoryRequirementsKHR(Packet_vkGetDeviceImageMemoryRequirementsKHR* packet);

    void Replay_vkGetDeviceImageSparseMemoryRequirementsKHR(Packet_vkGetDeviceImageSparseMemoryRequirementsKHR* packet);

    void Replay_vkCmdBindIndexBuffer2KHR(Packet_vkCmdBindIndexBuffer2KHR* packet);

    void Replay_vkGetRenderingAreaGranularityKHR(Packet_vkGetRenderingAreaGranularityKHR* packet);

    void Replay_vkGetDeviceImageSubresourceLayoutKHR(Packet_vkGetDeviceImageSubresourceLayoutKHR* packet);

    void Replay_vkGetImageSubresourceLayout2KHR(Packet_vkGetImageSubresourceLayout2KHR* packet);

    void Replay_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(Packet_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR* packet);

    void Replay_vkCmdSetLineStippleKHR(Packet_vkCmdSetLineStippleKHR* packet);

    void Replay_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(Packet_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR* packet);

    void Replay_vkGetCalibratedTimestampsKHR(Packet_vkGetCalibratedTimestampsKHR* packet);

    void Replay_vkCmdBindDescriptorSets2KHR(Packet_vkCmdBindDescriptorSets2KHR* packet);

    void Replay_vkCmdPushConstants2KHR(Packet_vkCmdPushConstants2KHR* packet);

    void Replay_vkCmdPushDescriptorSet2KHR(Packet_vkCmdPushDescriptorSet2KHR* packet);

    void Replay_vkCmdSetDescriptorBufferOffsets2EXT(Packet_vkCmdSetDescriptorBufferOffsets2EXT* packet);

    void Replay_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(Packet_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT* packet);

    void Replay_vkFrameBoundaryANDROID(Packet_vkFrameBoundaryANDROID* packet);

    void Replay_vkCreateDebugReportCallbackEXT(Packet_vkCreateDebugReportCallbackEXT* packet);

    void Replay_vkDestroyDebugReportCallbackEXT(Packet_vkDestroyDebugReportCallbackEXT* packet);

    void Replay_vkDebugReportMessageEXT(Packet_vkDebugReportMessageEXT* packet);

    void Replay_vkDebugMarkerSetObjectTagEXT(Packet_vkDebugMarkerSetObjectTagEXT* packet);

    void Replay_vkDebugMarkerSetObjectNameEXT(Packet_vkDebugMarkerSetObjectNameEXT* packet);

    void Replay_vkCmdDebugMarkerBeginEXT(Packet_vkCmdDebugMarkerBeginEXT* packet);

    void Replay_vkCmdDebugMarkerEndEXT(Packet_vkCmdDebugMarkerEndEXT* packet);

    void Replay_vkCmdDebugMarkerInsertEXT(Packet_vkCmdDebugMarkerInsertEXT* packet);

    void Replay_vkCmdBindTransformFeedbackBuffersEXT(Packet_vkCmdBindTransformFeedbackBuffersEXT* packet);

    void Replay_vkCmdBeginTransformFeedbackEXT(Packet_vkCmdBeginTransformFeedbackEXT* packet);

    void Replay_vkCmdEndTransformFeedbackEXT(Packet_vkCmdEndTransformFeedbackEXT* packet);

    void Replay_vkCmdBeginQueryIndexedEXT(Packet_vkCmdBeginQueryIndexedEXT* packet);

    void Replay_vkCmdEndQueryIndexedEXT(Packet_vkCmdEndQueryIndexedEXT* packet);

    void Replay_vkCmdDrawIndirectByteCountEXT(Packet_vkCmdDrawIndirectByteCountEXT* packet);

    void Replay_vkGetImageViewHandleNVX(Packet_vkGetImageViewHandleNVX* packet);

    void Replay_vkGetImageViewAddressNVX(Packet_vkGetImageViewAddressNVX* packet);

    void Replay_vkCmdDrawIndirectCountAMD(Packet_vkCmdDrawIndirectCountAMD* packet);

    void Replay_vkCmdDrawIndexedIndirectCountAMD(Packet_vkCmdDrawIndexedIndirectCountAMD* packet);

    void Replay_vkGetShaderInfoAMD(Packet_vkGetShaderInfoAMD* packet);

    void Replay_vkCreateStreamDescriptorSurfaceGGP(Packet_vkCreateStreamDescriptorSurfaceGGP* packet);

    void Replay_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(Packet_vkGetPhysicalDeviceExternalImageFormatPropertiesNV* packet);

    void Replay_vkGetMemoryWin32HandleNV(Packet_vkGetMemoryWin32HandleNV* packet);

    void Replay_vkCreateViSurfaceNN(Packet_vkCreateViSurfaceNN* packet);

    void Replay_vkCmdBeginConditionalRenderingEXT(Packet_vkCmdBeginConditionalRenderingEXT* packet);

    void Replay_vkCmdEndConditionalRenderingEXT(Packet_vkCmdEndConditionalRenderingEXT* packet);

    void Replay_vkCmdSetViewportWScalingNV(Packet_vkCmdSetViewportWScalingNV* packet);

    void Replay_vkReleaseDisplayEXT(Packet_vkReleaseDisplayEXT* packet);

    void Replay_vkAcquireXlibDisplayEXT(Packet_vkAcquireXlibDisplayEXT* packet);

    void Replay_vkGetRandROutputDisplayEXT(Packet_vkGetRandROutputDisplayEXT* packet);

    void Replay_vkGetPhysicalDeviceSurfaceCapabilities2EXT(Packet_vkGetPhysicalDeviceSurfaceCapabilities2EXT* packet);

    void Replay_vkDisplayPowerControlEXT(Packet_vkDisplayPowerControlEXT* packet);

    void Replay_vkRegisterDeviceEventEXT(Packet_vkRegisterDeviceEventEXT* packet);

    void Replay_vkRegisterDisplayEventEXT(Packet_vkRegisterDisplayEventEXT* packet);

    void Replay_vkGetSwapchainCounterEXT(Packet_vkGetSwapchainCounterEXT* packet);

    void Replay_vkGetRefreshCycleDurationGOOGLE(Packet_vkGetRefreshCycleDurationGOOGLE* packet);

    void Replay_vkGetPastPresentationTimingGOOGLE(Packet_vkGetPastPresentationTimingGOOGLE* packet);

    void Replay_vkCmdSetDiscardRectangleEXT(Packet_vkCmdSetDiscardRectangleEXT* packet);

    void Replay_vkCmdSetDiscardRectangleEnableEXT(Packet_vkCmdSetDiscardRectangleEnableEXT* packet);

    void Replay_vkCmdSetDiscardRectangleModeEXT(Packet_vkCmdSetDiscardRectangleModeEXT* packet);

    void Replay_vkSetHdrMetadataEXT(Packet_vkSetHdrMetadataEXT* packet);

    void Replay_vkCreateIOSSurfaceMVK(Packet_vkCreateIOSSurfaceMVK* packet);

    void Replay_vkCreateMacOSSurfaceMVK(Packet_vkCreateMacOSSurfaceMVK* packet);

    void Replay_vkSetDebugUtilsObjectNameEXT(Packet_vkSetDebugUtilsObjectNameEXT* packet);

    void Replay_vkSetDebugUtilsObjectTagEXT(Packet_vkSetDebugUtilsObjectTagEXT* packet);

    void Replay_vkQueueBeginDebugUtilsLabelEXT(Packet_vkQueueBeginDebugUtilsLabelEXT* packet);

    void Replay_vkQueueEndDebugUtilsLabelEXT(Packet_vkQueueEndDebugUtilsLabelEXT* packet);

    void Replay_vkQueueInsertDebugUtilsLabelEXT(Packet_vkQueueInsertDebugUtilsLabelEXT* packet);

    void Replay_vkCmdBeginDebugUtilsLabelEXT(Packet_vkCmdBeginDebugUtilsLabelEXT* packet);

    void Replay_vkCmdEndDebugUtilsLabelEXT(Packet_vkCmdEndDebugUtilsLabelEXT* packet);

    void Replay_vkCmdInsertDebugUtilsLabelEXT(Packet_vkCmdInsertDebugUtilsLabelEXT* packet);

    void Replay_vkCreateDebugUtilsMessengerEXT(Packet_vkCreateDebugUtilsMessengerEXT* packet);

    void Replay_vkDestroyDebugUtilsMessengerEXT(Packet_vkDestroyDebugUtilsMessengerEXT* packet);

    void Replay_vkSubmitDebugUtilsMessageEXT(Packet_vkSubmitDebugUtilsMessageEXT* packet);

    void Replay_vkGetAndroidHardwareBufferPropertiesANDROID(Packet_vkGetAndroidHardwareBufferPropertiesANDROID* packet);

    void Replay_vkGetMemoryAndroidHardwareBufferANDROID(Packet_vkGetMemoryAndroidHardwareBufferANDROID* packet);

    void Replay_vkCmdSetSampleLocationsEXT(Packet_vkCmdSetSampleLocationsEXT* packet);

    void Replay_vkGetPhysicalDeviceMultisamplePropertiesEXT(Packet_vkGetPhysicalDeviceMultisamplePropertiesEXT* packet);

    void Replay_vkGetImageDrmFormatModifierPropertiesEXT(Packet_vkGetImageDrmFormatModifierPropertiesEXT* packet);

    void Replay_vkCreateValidationCacheEXT(Packet_vkCreateValidationCacheEXT* packet);

    void Replay_vkDestroyValidationCacheEXT(Packet_vkDestroyValidationCacheEXT* packet);

    void Replay_vkMergeValidationCachesEXT(Packet_vkMergeValidationCachesEXT* packet);

    void Replay_vkGetValidationCacheDataEXT(Packet_vkGetValidationCacheDataEXT* packet);

    void Replay_vkCmdBindShadingRateImageNV(Packet_vkCmdBindShadingRateImageNV* packet);

    void Replay_vkCmdSetViewportShadingRatePaletteNV(Packet_vkCmdSetViewportShadingRatePaletteNV* packet);

    void Replay_vkCmdSetCoarseSampleOrderNV(Packet_vkCmdSetCoarseSampleOrderNV* packet);

    void Replay_vkCreateAccelerationStructureNV(Packet_vkCreateAccelerationStructureNV* packet);

    void Replay_vkDestroyAccelerationStructureNV(Packet_vkDestroyAccelerationStructureNV* packet);

    void Replay_vkGetAccelerationStructureMemoryRequirementsNV(Packet_vkGetAccelerationStructureMemoryRequirementsNV* packet);

    void Replay_vkBindAccelerationStructureMemoryNV(Packet_vkBindAccelerationStructureMemoryNV* packet);

    void Replay_vkCmdBuildAccelerationStructureNV(Packet_vkCmdBuildAccelerationStructureNV* packet);

    void Replay_vkCmdCopyAccelerationStructureNV(Packet_vkCmdCopyAccelerationStructureNV* packet);

    void Replay_vkCmdTraceRaysNV(Packet_vkCmdTraceRaysNV* packet);

    void Replay_vkCreateRayTracingPipelinesNV(Packet_vkCreateRayTracingPipelinesNV* packet);

    void Replay_vkGetRayTracingShaderGroupHandlesKHR(Packet_vkGetRayTracingShaderGroupHandlesKHR* packet);

    void Replay_vkGetRayTracingShaderGroupHandlesNV(Packet_vkGetRayTracingShaderGroupHandlesNV* packet);

    void Replay_vkGetAccelerationStructureHandleNV(Packet_vkGetAccelerationStructureHandleNV* packet);

    void Replay_vkCmdWriteAccelerationStructuresPropertiesNV(Packet_vkCmdWriteAccelerationStructuresPropertiesNV* packet);

    void Replay_vkCompileDeferredNV(Packet_vkCompileDeferredNV* packet);

    void Replay_vkGetMemoryHostPointerPropertiesEXT(Packet_vkGetMemoryHostPointerPropertiesEXT* packet);

    void Replay_vkCmdWriteBufferMarkerAMD(Packet_vkCmdWriteBufferMarkerAMD* packet);

    void Replay_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(Packet_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT* packet);

    void Replay_vkGetCalibratedTimestampsEXT(Packet_vkGetCalibratedTimestampsEXT* packet);

    void Replay_vkCmdDrawMeshTasksNV(Packet_vkCmdDrawMeshTasksNV* packet);

    void Replay_vkCmdDrawMeshTasksIndirectNV(Packet_vkCmdDrawMeshTasksIndirectNV* packet);

    void Replay_vkCmdDrawMeshTasksIndirectCountNV(Packet_vkCmdDrawMeshTasksIndirectCountNV* packet);

    void Replay_vkCmdSetExclusiveScissorEnableNV(Packet_vkCmdSetExclusiveScissorEnableNV* packet);

    void Replay_vkCmdSetExclusiveScissorNV(Packet_vkCmdSetExclusiveScissorNV* packet);

    void Replay_vkCmdSetCheckpointNV(Packet_vkCmdSetCheckpointNV* packet);

    void Replay_vkGetQueueCheckpointDataNV(Packet_vkGetQueueCheckpointDataNV* packet);

    void Replay_vkInitializePerformanceApiINTEL(Packet_vkInitializePerformanceApiINTEL* packet);

    void Replay_vkUninitializePerformanceApiINTEL(Packet_vkUninitializePerformanceApiINTEL* packet);

    void Replay_vkCmdSetPerformanceMarkerINTEL(Packet_vkCmdSetPerformanceMarkerINTEL* packet);

    void Replay_vkCmdSetPerformanceStreamMarkerINTEL(Packet_vkCmdSetPerformanceStreamMarkerINTEL* packet);

    void Replay_vkCmdSetPerformanceOverrideINTEL(Packet_vkCmdSetPerformanceOverrideINTEL* packet);

    void Replay_vkAcquirePerformanceConfigurationINTEL(Packet_vkAcquirePerformanceConfigurationINTEL* packet);

    void Replay_vkReleasePerformanceConfigurationINTEL(Packet_vkReleasePerformanceConfigurationINTEL* packet);

    void Replay_vkQueueSetPerformanceConfigurationINTEL(Packet_vkQueueSetPerformanceConfigurationINTEL* packet);

    void Replay_vkGetPerformanceParameterINTEL(Packet_vkGetPerformanceParameterINTEL* packet);

    void Replay_vkSetLocalDimmingAMD(Packet_vkSetLocalDimmingAMD* packet);

    void Replay_vkCreateImagePipeSurfaceFUCHSIA(Packet_vkCreateImagePipeSurfaceFUCHSIA* packet);

    void Replay_vkCreateMetalSurfaceEXT(Packet_vkCreateMetalSurfaceEXT* packet);

    void Replay_vkGetBufferDeviceAddressEXT(Packet_vkGetBufferDeviceAddressEXT* packet);

    void Replay_vkGetPhysicalDeviceToolPropertiesEXT(Packet_vkGetPhysicalDeviceToolPropertiesEXT* packet);

    void Replay_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(Packet_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV* packet);

    void Replay_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(Packet_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV* packet);

    void Replay_vkGetPhysicalDeviceSurfacePresentModes2EXT(Packet_vkGetPhysicalDeviceSurfacePresentModes2EXT* packet);

    void Replay_vkAcquireFullScreenExclusiveModeEXT(Packet_vkAcquireFullScreenExclusiveModeEXT* packet);

    void Replay_vkReleaseFullScreenExclusiveModeEXT(Packet_vkReleaseFullScreenExclusiveModeEXT* packet);

    void Replay_vkGetDeviceGroupSurfacePresentModes2EXT(Packet_vkGetDeviceGroupSurfacePresentModes2EXT* packet);

    void Replay_vkCreateHeadlessSurfaceEXT(Packet_vkCreateHeadlessSurfaceEXT* packet);

    void Replay_vkCmdSetLineStippleEXT(Packet_vkCmdSetLineStippleEXT* packet);

    void Replay_vkResetQueryPoolEXT(Packet_vkResetQueryPoolEXT* packet);

    void Replay_vkCmdSetCullModeEXT(Packet_vkCmdSetCullModeEXT* packet);

    void Replay_vkCmdSetFrontFaceEXT(Packet_vkCmdSetFrontFaceEXT* packet);

    void Replay_vkCmdSetPrimitiveTopologyEXT(Packet_vkCmdSetPrimitiveTopologyEXT* packet);

    void Replay_vkCmdSetViewportWithCountEXT(Packet_vkCmdSetViewportWithCountEXT* packet);

    void Replay_vkCmdSetScissorWithCountEXT(Packet_vkCmdSetScissorWithCountEXT* packet);

    void Replay_vkCmdBindVertexBuffers2EXT(Packet_vkCmdBindVertexBuffers2EXT* packet);

    void Replay_vkCmdSetDepthTestEnableEXT(Packet_vkCmdSetDepthTestEnableEXT* packet);

    void Replay_vkCmdSetDepthWriteEnableEXT(Packet_vkCmdSetDepthWriteEnableEXT* packet);

    void Replay_vkCmdSetDepthCompareOpEXT(Packet_vkCmdSetDepthCompareOpEXT* packet);

    void Replay_vkCmdSetDepthBoundsTestEnableEXT(Packet_vkCmdSetDepthBoundsTestEnableEXT* packet);

    void Replay_vkCmdSetStencilTestEnableEXT(Packet_vkCmdSetStencilTestEnableEXT* packet);

    void Replay_vkCmdSetStencilOpEXT(Packet_vkCmdSetStencilOpEXT* packet);

    void Replay_vkCopyMemoryToImageEXT(Packet_vkCopyMemoryToImageEXT* packet);

    void Replay_vkCopyImageToMemoryEXT(Packet_vkCopyImageToMemoryEXT* packet);

    void Replay_vkCopyImageToImageEXT(Packet_vkCopyImageToImageEXT* packet);

    void Replay_vkTransitionImageLayoutEXT(Packet_vkTransitionImageLayoutEXT* packet);

    void Replay_vkGetImageSubresourceLayout2EXT(Packet_vkGetImageSubresourceLayout2EXT* packet);

    void Replay_vkReleaseSwapchainImagesEXT(Packet_vkReleaseSwapchainImagesEXT* packet);

    void Replay_vkGetGeneratedCommandsMemoryRequirementsNV(Packet_vkGetGeneratedCommandsMemoryRequirementsNV* packet);

    void Replay_vkCmdPreprocessGeneratedCommandsNV(Packet_vkCmdPreprocessGeneratedCommandsNV* packet);

    void Replay_vkCmdExecuteGeneratedCommandsNV(Packet_vkCmdExecuteGeneratedCommandsNV* packet);

    void Replay_vkCmdBindPipelineShaderGroupNV(Packet_vkCmdBindPipelineShaderGroupNV* packet);

    void Replay_vkCreateIndirectCommandsLayoutNV(Packet_vkCreateIndirectCommandsLayoutNV* packet);

    void Replay_vkDestroyIndirectCommandsLayoutNV(Packet_vkDestroyIndirectCommandsLayoutNV* packet);

    void Replay_vkCmdSetDepthBias2EXT(Packet_vkCmdSetDepthBias2EXT* packet);

    void Replay_vkAcquireDrmDisplayEXT(Packet_vkAcquireDrmDisplayEXT* packet);

    void Replay_vkGetDrmDisplayEXT(Packet_vkGetDrmDisplayEXT* packet);

    void Replay_vkCreatePrivateDataSlotEXT(Packet_vkCreatePrivateDataSlotEXT* packet);

    void Replay_vkDestroyPrivateDataSlotEXT(Packet_vkDestroyPrivateDataSlotEXT* packet);

    void Replay_vkSetPrivateDataEXT(Packet_vkSetPrivateDataEXT* packet);

    void Replay_vkGetPrivateDataEXT(Packet_vkGetPrivateDataEXT* packet);

    void Replay_vkCmdSetFragmentShadingRateEnumNV(Packet_vkCmdSetFragmentShadingRateEnumNV* packet);

    void Replay_vkGetDeviceFaultInfoEXT(Packet_vkGetDeviceFaultInfoEXT* packet);

    void Replay_vkAcquireWinrtDisplayNV(Packet_vkAcquireWinrtDisplayNV* packet);

    void Replay_vkGetWinrtDisplayNV(Packet_vkGetWinrtDisplayNV* packet);

    void Replay_vkCreateDirectFBSurfaceEXT(Packet_vkCreateDirectFBSurfaceEXT* packet);

    void Replay_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(Packet_vkGetPhysicalDeviceDirectFBPresentationSupportEXT* packet);

    void Replay_vkCmdSetVertexInputEXT(Packet_vkCmdSetVertexInputEXT* packet);

    void Replay_vkGetMemoryZirconHandleFUCHSIA(Packet_vkGetMemoryZirconHandleFUCHSIA* packet);

    void Replay_vkGetMemoryZirconHandlePropertiesFUCHSIA(Packet_vkGetMemoryZirconHandlePropertiesFUCHSIA* packet);

    void Replay_vkImportSemaphoreZirconHandleFUCHSIA(Packet_vkImportSemaphoreZirconHandleFUCHSIA* packet);

    void Replay_vkGetSemaphoreZirconHandleFUCHSIA(Packet_vkGetSemaphoreZirconHandleFUCHSIA* packet);

    void Replay_vkCmdBindInvocationMaskHUAWEI(Packet_vkCmdBindInvocationMaskHUAWEI* packet);

    void Replay_vkGetMemoryRemoteAddressNV(Packet_vkGetMemoryRemoteAddressNV* packet);

    void Replay_vkCmdSetPatchControlPointsEXT(Packet_vkCmdSetPatchControlPointsEXT* packet);

    void Replay_vkCmdSetRasterizerDiscardEnableEXT(Packet_vkCmdSetRasterizerDiscardEnableEXT* packet);

    void Replay_vkCmdSetDepthBiasEnableEXT(Packet_vkCmdSetDepthBiasEnableEXT* packet);

    void Replay_vkCmdSetLogicOpEXT(Packet_vkCmdSetLogicOpEXT* packet);

    void Replay_vkCmdSetPrimitiveRestartEnableEXT(Packet_vkCmdSetPrimitiveRestartEnableEXT* packet);

    void Replay_vkCreateScreenSurfaceQNX(Packet_vkCreateScreenSurfaceQNX* packet);

    void Replay_vkGetPhysicalDeviceScreenPresentationSupportQNX(Packet_vkGetPhysicalDeviceScreenPresentationSupportQNX* packet);

    void Replay_vkCmdSetColorWriteEnableEXT(Packet_vkCmdSetColorWriteEnableEXT* packet);

    void Replay_vkCmdDrawMultiEXT(Packet_vkCmdDrawMultiEXT* packet);

    void Replay_vkCmdDrawMultiIndexedEXT(Packet_vkCmdDrawMultiIndexedEXT* packet);

    void Replay_vkCreateMicromapEXT(Packet_vkCreateMicromapEXT* packet);

    void Replay_vkDestroyMicromapEXT(Packet_vkDestroyMicromapEXT* packet);

    void Replay_vkCmdBuildMicromapsEXT(Packet_vkCmdBuildMicromapsEXT* packet);

    void Replay_vkBuildMicromapsEXT(Packet_vkBuildMicromapsEXT* packet);

    void Replay_vkCopyMicromapEXT(Packet_vkCopyMicromapEXT* packet);

    void Replay_vkCopyMicromapToMemoryEXT(Packet_vkCopyMicromapToMemoryEXT* packet);

    void Replay_vkCopyMemoryToMicromapEXT(Packet_vkCopyMemoryToMicromapEXT* packet);

    void Replay_vkWriteMicromapsPropertiesEXT(Packet_vkWriteMicromapsPropertiesEXT* packet);

    void Replay_vkCmdCopyMicromapEXT(Packet_vkCmdCopyMicromapEXT* packet);

    void Replay_vkCmdCopyMicromapToMemoryEXT(Packet_vkCmdCopyMicromapToMemoryEXT* packet);

    void Replay_vkCmdCopyMemoryToMicromapEXT(Packet_vkCmdCopyMemoryToMicromapEXT* packet);

    void Replay_vkCmdWriteMicromapsPropertiesEXT(Packet_vkCmdWriteMicromapsPropertiesEXT* packet);

    void Replay_vkGetDeviceMicromapCompatibilityEXT(Packet_vkGetDeviceMicromapCompatibilityEXT* packet);

    void Replay_vkGetMicromapBuildSizesEXT(Packet_vkGetMicromapBuildSizesEXT* packet);

    void Replay_vkCmdDrawClusterHUAWEI(Packet_vkCmdDrawClusterHUAWEI* packet);

    void Replay_vkCmdDrawClusterIndirectHUAWEI(Packet_vkCmdDrawClusterIndirectHUAWEI* packet);

    void Replay_vkSetDeviceMemoryPriorityEXT(Packet_vkSetDeviceMemoryPriorityEXT* packet);

    void Replay_vkGetDescriptorSetLayoutHostMappingInfoVALVE(Packet_vkGetDescriptorSetLayoutHostMappingInfoVALVE* packet);

    void Replay_vkGetDescriptorSetHostMappingVALVE(Packet_vkGetDescriptorSetHostMappingVALVE* packet);

    void Replay_vkGetPipelineIndirectMemoryRequirementsNV(Packet_vkGetPipelineIndirectMemoryRequirementsNV* packet);

    void Replay_vkCmdUpdatePipelineIndirectBufferNV(Packet_vkCmdUpdatePipelineIndirectBufferNV* packet);

    void Replay_vkGetPipelineIndirectDeviceAddressNV(Packet_vkGetPipelineIndirectDeviceAddressNV* packet);

    void Replay_vkCmdSetDepthClampEnableEXT(Packet_vkCmdSetDepthClampEnableEXT* packet);

    void Replay_vkCmdSetPolygonModeEXT(Packet_vkCmdSetPolygonModeEXT* packet);

    void Replay_vkCmdSetRasterizationSamplesEXT(Packet_vkCmdSetRasterizationSamplesEXT* packet);

    void Replay_vkCmdSetSampleMaskEXT(Packet_vkCmdSetSampleMaskEXT* packet);

    void Replay_vkCmdSetAlphaToCoverageEnableEXT(Packet_vkCmdSetAlphaToCoverageEnableEXT* packet);

    void Replay_vkCmdSetAlphaToOneEnableEXT(Packet_vkCmdSetAlphaToOneEnableEXT* packet);

    void Replay_vkCmdSetLogicOpEnableEXT(Packet_vkCmdSetLogicOpEnableEXT* packet);

    void Replay_vkCmdSetColorBlendEnableEXT(Packet_vkCmdSetColorBlendEnableEXT* packet);

    void Replay_vkCmdSetColorBlendEquationEXT(Packet_vkCmdSetColorBlendEquationEXT* packet);

    void Replay_vkCmdSetColorWriteMaskEXT(Packet_vkCmdSetColorWriteMaskEXT* packet);

    void Replay_vkCmdSetTessellationDomainOriginEXT(Packet_vkCmdSetTessellationDomainOriginEXT* packet);

    void Replay_vkCmdSetRasterizationStreamEXT(Packet_vkCmdSetRasterizationStreamEXT* packet);

    void Replay_vkCmdSetConservativeRasterizationModeEXT(Packet_vkCmdSetConservativeRasterizationModeEXT* packet);

    void Replay_vkCmdSetExtraPrimitiveOverestimationSizeEXT(Packet_vkCmdSetExtraPrimitiveOverestimationSizeEXT* packet);

    void Replay_vkCmdSetDepthClipEnableEXT(Packet_vkCmdSetDepthClipEnableEXT* packet);

    void Replay_vkCmdSetSampleLocationsEnableEXT(Packet_vkCmdSetSampleLocationsEnableEXT* packet);

    void Replay_vkCmdSetColorBlendAdvancedEXT(Packet_vkCmdSetColorBlendAdvancedEXT* packet);

    void Replay_vkCmdSetProvokingVertexModeEXT(Packet_vkCmdSetProvokingVertexModeEXT* packet);

    void Replay_vkCmdSetLineRasterizationModeEXT(Packet_vkCmdSetLineRasterizationModeEXT* packet);

    void Replay_vkCmdSetLineStippleEnableEXT(Packet_vkCmdSetLineStippleEnableEXT* packet);

    void Replay_vkCmdSetDepthClipNegativeOneToOneEXT(Packet_vkCmdSetDepthClipNegativeOneToOneEXT* packet);

    void Replay_vkCmdSetViewportWScalingEnableNV(Packet_vkCmdSetViewportWScalingEnableNV* packet);

    void Replay_vkCmdSetViewportSwizzleNV(Packet_vkCmdSetViewportSwizzleNV* packet);

    void Replay_vkCmdSetCoverageToColorEnableNV(Packet_vkCmdSetCoverageToColorEnableNV* packet);

    void Replay_vkCmdSetCoverageToColorLocationNV(Packet_vkCmdSetCoverageToColorLocationNV* packet);

    void Replay_vkCmdSetCoverageModulationModeNV(Packet_vkCmdSetCoverageModulationModeNV* packet);

    void Replay_vkCmdSetCoverageModulationTableEnableNV(Packet_vkCmdSetCoverageModulationTableEnableNV* packet);

    void Replay_vkCmdSetCoverageModulationTableNV(Packet_vkCmdSetCoverageModulationTableNV* packet);

    void Replay_vkCmdSetShadingRateImageEnableNV(Packet_vkCmdSetShadingRateImageEnableNV* packet);

    void Replay_vkCmdSetRepresentativeFragmentTestEnableNV(Packet_vkCmdSetRepresentativeFragmentTestEnableNV* packet);

    void Replay_vkCmdSetCoverageReductionModeNV(Packet_vkCmdSetCoverageReductionModeNV* packet);

    void Replay_vkGetShaderModuleIdentifierEXT(Packet_vkGetShaderModuleIdentifierEXT* packet);

    void Replay_vkGetShaderModuleCreateInfoIdentifierEXT(Packet_vkGetShaderModuleCreateInfoIdentifierEXT* packet);

    void Replay_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(Packet_vkGetPhysicalDeviceOpticalFlowImageFormatsNV* packet);

    void Replay_vkCreateOpticalFlowSessionNV(Packet_vkCreateOpticalFlowSessionNV* packet);

    void Replay_vkDestroyOpticalFlowSessionNV(Packet_vkDestroyOpticalFlowSessionNV* packet);

    void Replay_vkBindOpticalFlowSessionImageNV(Packet_vkBindOpticalFlowSessionImageNV* packet);

    void Replay_vkCmdOpticalFlowExecuteNV(Packet_vkCmdOpticalFlowExecuteNV* packet);

    void Replay_vkCreateShadersEXT(Packet_vkCreateShadersEXT* packet);

    void Replay_vkDestroyShaderEXT(Packet_vkDestroyShaderEXT* packet);

    void Replay_vkGetShaderBinaryDataEXT(Packet_vkGetShaderBinaryDataEXT* packet);

    void Replay_vkCmdBindShadersEXT(Packet_vkCmdBindShadersEXT* packet);

    void Replay_vkGetFramebufferTilePropertiesQCOM(Packet_vkGetFramebufferTilePropertiesQCOM* packet);

    void Replay_vkGetDynamicRenderingTilePropertiesQCOM(Packet_vkGetDynamicRenderingTilePropertiesQCOM* packet);

    void Replay_vkSetLatencySleepModeNV(Packet_vkSetLatencySleepModeNV* packet);

    void Replay_vkLatencySleepNV(Packet_vkLatencySleepNV* packet);

    void Replay_vkSetLatencyMarkerNV(Packet_vkSetLatencyMarkerNV* packet);

    void Replay_vkGetLatencyTimingsNV(Packet_vkGetLatencyTimingsNV* packet);

    void Replay_vkQueueNotifyOutOfBandNV(Packet_vkQueueNotifyOutOfBandNV* packet);

    void Replay_vkCmdSetAttachmentFeedbackLoopEnableEXT(Packet_vkCmdSetAttachmentFeedbackLoopEnableEXT* packet);

    void Replay_vkCreateAccelerationStructureKHR(Packet_vkCreateAccelerationStructureKHR* packet);

    void Replay_vkDestroyAccelerationStructureKHR(Packet_vkDestroyAccelerationStructureKHR* packet);

    void Replay_vkCmdBuildAccelerationStructuresKHR(Packet_vkCmdBuildAccelerationStructuresKHR* packet);

    void Replay_vkCmdBuildAccelerationStructuresIndirectKHR(Packet_vkCmdBuildAccelerationStructuresIndirectKHR* packet);

    void Replay_vkCopyAccelerationStructureToMemoryKHR(Packet_vkCopyAccelerationStructureToMemoryKHR* packet);

    void Replay_vkCopyMemoryToAccelerationStructureKHR(Packet_vkCopyMemoryToAccelerationStructureKHR* packet);

    void Replay_vkWriteAccelerationStructuresPropertiesKHR(Packet_vkWriteAccelerationStructuresPropertiesKHR* packet);

    void Replay_vkCmdCopyAccelerationStructureKHR(Packet_vkCmdCopyAccelerationStructureKHR* packet);

    void Replay_vkCmdCopyAccelerationStructureToMemoryKHR(Packet_vkCmdCopyAccelerationStructureToMemoryKHR* packet);

    void Replay_vkCmdCopyMemoryToAccelerationStructureKHR(Packet_vkCmdCopyMemoryToAccelerationStructureKHR* packet);

    void Replay_vkGetAccelerationStructureDeviceAddressKHR(Packet_vkGetAccelerationStructureDeviceAddressKHR* packet);

    void Replay_vkCmdWriteAccelerationStructuresPropertiesKHR(Packet_vkCmdWriteAccelerationStructuresPropertiesKHR* packet);

    void Replay_vkGetDeviceAccelerationStructureCompatibilityKHR(Packet_vkGetDeviceAccelerationStructureCompatibilityKHR* packet);

    void Replay_vkGetAccelerationStructureBuildSizesKHR(Packet_vkGetAccelerationStructureBuildSizesKHR* packet);

    void Replay_vkCmdTraceRaysKHR(Packet_vkCmdTraceRaysKHR* packet);

    void Replay_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(Packet_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR* packet);

    void Replay_vkCmdTraceRaysIndirectKHR(Packet_vkCmdTraceRaysIndirectKHR* packet);

    void Replay_vkGetRayTracingShaderGroupStackSizeKHR(Packet_vkGetRayTracingShaderGroupStackSizeKHR* packet);

    void Replay_vkCmdSetRayTracingPipelineStackSizeKHR(Packet_vkCmdSetRayTracingPipelineStackSizeKHR* packet);

    void Replay_vkCmdDrawMeshTasksEXT(Packet_vkCmdDrawMeshTasksEXT* packet);

    void Replay_vkCmdDrawMeshTasksIndirectEXT(Packet_vkCmdDrawMeshTasksIndirectEXT* packet);

    void Replay_vkCmdDrawMeshTasksIndirectCountEXT(Packet_vkCmdDrawMeshTasksIndirectCountEXT* packet);
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
