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

#ifndef  GFXRECON_GENERATED_VULKAN_DECODER_H
#define  GFXRECON_GENERATED_VULKAN_DECODER_H

#include "decode/vulkan_decoder_base.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

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
    size_t Decode_vkCreateInstance(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyInstance(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkEnumeratePhysicalDevices(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceFeatures(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceFormatProperties(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceImageFormatProperties(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceProperties(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceQueueFamilyProperties(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceMemoryProperties(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDevice(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDevice(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceQueue(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueSubmit(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueWaitIdle(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDeviceWaitIdle(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAllocateMemory(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkFreeMemory(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkMapMemory(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkUnmapMemory(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkFlushMappedMemoryRanges(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkInvalidateMappedMemoryRanges(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceMemoryCommitment(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindBufferMemory(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindImageMemory(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferMemoryRequirements(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageMemoryRequirements(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageSparseMemoryRequirements(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSparseImageFormatProperties(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueBindSparse(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateFence(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyFence(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetFences(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetFenceStatus(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkWaitForFences(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateSemaphore(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroySemaphore(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateEvent(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyEvent(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetEventStatus(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetEvent(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetEvent(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateQueryPool(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyQueryPool(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetQueryPoolResults(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateBuffer(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyBuffer(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateBufferView(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyBufferView(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateImage(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyImage(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageSubresourceLayout(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateImageView(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyImageView(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateShaderModule(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyShaderModule(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreatePipelineCache(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyPipelineCache(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPipelineCacheData(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkMergePipelineCaches(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateGraphicsPipelines(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateComputePipelines(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyPipeline(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreatePipelineLayout(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyPipelineLayout(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateSampler(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroySampler(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDescriptorSetLayout(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDescriptorSetLayout(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDescriptorPool(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDescriptorPool(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetDescriptorPool(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAllocateDescriptorSets(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkFreeDescriptorSets(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkUpdateDescriptorSets(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateFramebuffer(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyFramebuffer(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateRenderPass(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyRenderPass(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRenderAreaGranularity(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateCommandPool(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyCommandPool(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetCommandPool(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAllocateCommandBuffers(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkFreeCommandBuffers(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBeginCommandBuffer(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkEndCommandBuffer(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetCommandBuffer(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindPipeline(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetViewport(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetScissor(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetLineWidth(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthBias(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetBlendConstants(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthBounds(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetStencilCompareMask(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetStencilWriteMask(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetStencilReference(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindDescriptorSets(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindIndexBuffer(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindVertexBuffers(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDraw(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndexed(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndirect(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndexedIndirect(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDispatch(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDispatchIndirect(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyBuffer(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyImage(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBlitImage(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyBufferToImage(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyImageToBuffer(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdUpdateBuffer(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdFillBuffer(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdClearColorImage(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdClearDepthStencilImage(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdClearAttachments(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdResolveImage(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetEvent(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdResetEvent(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWaitEvents(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPipelineBarrier(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginQuery(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndQuery(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdResetQueryPool(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWriteTimestamp(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyQueryPoolResults(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPushConstants(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginRenderPass(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdNextSubpass(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndRenderPass(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdExecuteCommands(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindBufferMemory2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindImageMemory2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceGroupPeerMemoryFeatures(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDeviceMask(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDispatchBase(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkEnumeratePhysicalDeviceGroups(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageMemoryRequirements2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferMemoryRequirements2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageSparseMemoryRequirements2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceFeatures2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceProperties2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceFormatProperties2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceImageFormatProperties2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceQueueFamilyProperties2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceMemoryProperties2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSparseImageFormatProperties2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkTrimCommandPool(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceQueue2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateSamplerYcbcrConversion(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroySamplerYcbcrConversion(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDescriptorUpdateTemplate(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDescriptorUpdateTemplate(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalBufferProperties(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalFenceProperties(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalSemaphoreProperties(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDescriptorSetLayoutSupport(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndirectCount(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndexedIndirectCount(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateRenderPass2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginRenderPass2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdNextSubpass2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndRenderPass2(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetQueryPool(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSemaphoreCounterValue(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkWaitSemaphores(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSignalSemaphore(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferDeviceAddress(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferOpaqueCaptureAddress(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceMemoryOpaqueCaptureAddress(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroySurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfaceSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfaceFormatsKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfacePresentModesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateSwapchainKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroySwapchainKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSwapchainImagesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquireNextImageKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueuePresentKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceGroupPresentCapabilitiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceGroupSurfacePresentModesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDevicePresentRectanglesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquireNextImage2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceDisplayPropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDisplayPlaneSupportedDisplaysKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDisplayModePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDisplayModeKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDisplayPlaneCapabilitiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDisplayPlaneSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateSharedSwapchainsKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateXlibSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceXlibPresentationSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateXcbSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceXcbPresentationSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateWaylandSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceWaylandPresentationSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateAndroidSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateWin32SurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceWin32PresentationSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceFeatures2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceFormatProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceImageFormatProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceQueueFamilyProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceMemoryProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceGroupPeerMemoryFeaturesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDeviceMaskKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDispatchBaseKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkTrimCommandPoolKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkEnumeratePhysicalDeviceGroupsKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalBufferPropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryWin32HandlePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryFdKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryFdPropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkImportSemaphoreWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSemaphoreWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkImportSemaphoreFdKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSemaphoreFdKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPushDescriptorSetKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDescriptorUpdateTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDescriptorUpdateTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateRenderPass2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginRenderPass2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdNextSubpass2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndRenderPass2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSwapchainStatusKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalFencePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkImportFenceWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetFenceWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkImportFenceFdKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetFenceFdKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquireProfilingLockKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkReleaseProfilingLockKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfaceCapabilities2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfaceFormats2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceDisplayProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDisplayModeProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDisplayPlaneCapabilities2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageMemoryRequirements2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferMemoryRequirements2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageSparseMemoryRequirements2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateSamplerYcbcrConversionKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroySamplerYcbcrConversionKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindBufferMemory2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindImageMemory2KHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDescriptorSetLayoutSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndirectCountKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndexedIndirectCountKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSemaphoreCounterValueKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkWaitSemaphoresKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSignalSemaphoreKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferDeviceAddressKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferOpaqueCaptureAddressKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceMemoryOpaqueCaptureAddressKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDeferredOperationKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDeferredOperationKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeferredOperationMaxConcurrencyKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeferredOperationResultKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDeferredOperationJoinKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPipelineExecutablePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPipelineExecutableStatisticsKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPipelineExecutableInternalRepresentationsKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDebugReportCallbackEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDebugReportCallbackEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDebugReportMessageEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDebugMarkerSetObjectTagEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDebugMarkerSetObjectNameEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDebugMarkerBeginEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDebugMarkerEndEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDebugMarkerInsertEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindTransformFeedbackBuffersEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginTransformFeedbackEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndTransformFeedbackEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginQueryIndexedEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndQueryIndexedEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndirectByteCountEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageViewHandleNVX(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageViewAddressNVX(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndirectCountAMD(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawIndexedIndirectCountAMD(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetShaderInfoAMD(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateStreamDescriptorSurfaceGGP(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryWin32HandleNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateViSurfaceNN(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginConditionalRenderingEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndConditionalRenderingEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetViewportWScalingNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkReleaseDisplayEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquireXlibDisplayEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRandROutputDisplayEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfaceCapabilities2EXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDisplayPowerControlEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkRegisterDeviceEventEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkRegisterDisplayEventEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetSwapchainCounterEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRefreshCycleDurationGOOGLE(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPastPresentationTimingGOOGLE(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDiscardRectangleEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetHdrMetadataEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateIOSSurfaceMVK(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateMacOSSurfaceMVK(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetDebugUtilsObjectNameEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetDebugUtilsObjectTagEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueBeginDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueEndDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueInsertDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBeginDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdEndDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdInsertDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDebugUtilsMessengerEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyDebugUtilsMessengerEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSubmitDebugUtilsMessageEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetAndroidHardwareBufferPropertiesANDROID(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryAndroidHardwareBufferANDROID(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetSampleLocationsEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceMultisamplePropertiesEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetImageDrmFormatModifierPropertiesEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateValidationCacheEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyValidationCacheEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkMergeValidationCachesEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetValidationCacheDataEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindShadingRateImageNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetViewportShadingRatePaletteNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetCoarseSampleOrderNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateAccelerationStructureNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyAccelerationStructureKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyAccelerationStructureNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetAccelerationStructureMemoryRequirementsNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindAccelerationStructureMemoryKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkBindAccelerationStructureMemoryNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBuildAccelerationStructureNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyAccelerationStructureNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdTraceRaysNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateRayTracingPipelinesNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRayTracingShaderGroupHandlesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRayTracingShaderGroupHandlesNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetAccelerationStructureHandleNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWriteAccelerationStructuresPropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWriteAccelerationStructuresPropertiesNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCompileDeferredNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetMemoryHostPointerPropertiesEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdWriteBufferMarkerAMD(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetCalibratedTimestampsEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawMeshTasksNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawMeshTasksIndirectNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdDrawMeshTasksIndirectCountNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetExclusiveScissorNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetCheckpointNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetQueueCheckpointDataNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkInitializePerformanceApiINTEL(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkUninitializePerformanceApiINTEL(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetPerformanceMarkerINTEL(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetPerformanceStreamMarkerINTEL(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetPerformanceOverrideINTEL(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquirePerformanceConfigurationINTEL(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkReleasePerformanceConfigurationINTEL(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkQueueSetPerformanceConfigurationINTEL(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPerformanceParameterINTEL(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetLocalDimmingAMD(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateImagePipeSurfaceFUCHSIA(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateMetalSurfaceEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetBufferDeviceAddressEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceToolPropertiesEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceSurfacePresentModes2EXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkAcquireFullScreenExclusiveModeEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkReleaseFullScreenExclusiveModeEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceGroupSurfacePresentModes2EXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateHeadlessSurfaceEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetLineStippleEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkResetQueryPoolEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetCullModeEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetFrontFaceEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetPrimitiveTopologyEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetViewportWithCountEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetScissorWithCountEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindVertexBuffers2EXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthTestEnableEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthWriteEnableEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthCompareOpEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetDepthBoundsTestEnableEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetStencilTestEnableEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdSetStencilOpEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetGeneratedCommandsMemoryRequirementsNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPreprocessGeneratedCommandsNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdExecuteGeneratedCommandsNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBindPipelineShaderGroupNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateIndirectCommandsLayoutNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyIndirectCommandsLayoutNV(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreatePrivateDataSlotEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkDestroyPrivateDataSlotEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkSetPrivateDataEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPrivateDataEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateDirectFBSurfaceEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateAccelerationStructureKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetAccelerationStructureMemoryRequirementsKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdBuildAccelerationStructureIndirectKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyAccelerationStructureKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyAccelerationStructureToMemoryKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCopyMemoryToAccelerationStructureKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkWriteAccelerationStructuresPropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyAccelerationStructureKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyAccelerationStructureToMemoryKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdCopyMemoryToAccelerationStructureKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdTraceRaysKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCreateRayTracingPipelinesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetAccelerationStructureDeviceAddressKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdTraceRaysIndirectKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkGetDeviceAccelerationStructureCompatibilityKHR(const uint8_t* parameter_buffer, size_t buffer_size);
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
