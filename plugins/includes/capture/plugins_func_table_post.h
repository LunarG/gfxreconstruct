/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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

#ifndef GFXRECON_PLUGINS_CAPTURE_FUNC_TABLE_POST_H
#define GFXRECON_PLUGINS_CAPTURE_FUNC_TABLE_POST_H

#include "format/platform_types.h"
#include "util/defines.h"
#include "util/platform.h"

#include "vulkan/vk_layer.h"
#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugins)
GFXRECON_BEGIN_NAMESPACE(capture)

// clang-format off

typedef void (VKAPI_PTR *PFN_CreateInstance_PostCall)(uint64_t block_index, VkResult result, const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
typedef void (VKAPI_PTR *PFN_DestroyInstance_PostCall)(uint64_t block_index,VkInstance instance, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_EnumeratePhysicalDevices_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFeatures_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFormatProperties_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceImageFormatProperties_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceProperties_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceQueueFamilyProperties_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceMemoryProperties_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties);
typedef void (VKAPI_PTR *PFN_GetInstanceProcAddr_PostCall)(uint64_t block_index, PFN_vkVoidFunction result, VkInstance instance, const char* pName);
typedef void (VKAPI_PTR *PFN_GetDeviceProcAddr_PostCall)(uint64_t block_index, PFN_vkVoidFunction result, VkDevice device, const char* pName);
typedef void (VKAPI_PTR *PFN_CreateDevice_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice);
typedef void (VKAPI_PTR *PFN_DestroyDevice_PostCall)(uint64_t block_index,VkDevice device, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_EnumerateInstanceExtensionProperties_PostCall)(uint64_t block_index, VkResult result, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
typedef void (VKAPI_PTR *PFN_EnumerateDeviceExtensionProperties_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
typedef void (VKAPI_PTR *PFN_EnumerateInstanceLayerProperties_PostCall)(uint64_t block_index, VkResult result, uint32_t* pPropertyCount, VkLayerProperties* pProperties);
typedef void (VKAPI_PTR *PFN_EnumerateDeviceLayerProperties_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties);
typedef void (VKAPI_PTR *PFN_GetDeviceQueue_PostCall)(uint64_t block_index,VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
typedef void (VKAPI_PTR *PFN_QueueSubmit_PostCall)(uint64_t block_index, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
typedef void (VKAPI_PTR *PFN_QueueWaitIdle_PostCall)(uint64_t block_index, VkResult result, VkQueue queue);
typedef void (VKAPI_PTR *PFN_DeviceWaitIdle_PostCall)(uint64_t block_index, VkResult result, VkDevice device);
typedef void (VKAPI_PTR *PFN_AllocateMemory_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);
typedef void (VKAPI_PTR *PFN_FreeMemory_PostCall)(uint64_t block_index,VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_MapMemory_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);
typedef void (VKAPI_PTR *PFN_UnmapMemory_PostCall)(uint64_t block_index,VkDevice device, VkDeviceMemory memory);
typedef void (VKAPI_PTR *PFN_FlushMappedMemoryRanges_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
typedef void (VKAPI_PTR *PFN_InvalidateMappedMemoryRanges_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
typedef void (VKAPI_PTR *PFN_GetDeviceMemoryCommitment_PostCall)(uint64_t block_index,VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);
typedef void (VKAPI_PTR *PFN_BindBufferMemory_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
typedef void (VKAPI_PTR *PFN_BindImageMemory_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
typedef void (VKAPI_PTR *PFN_GetBufferMemoryRequirements_PostCall)(uint64_t block_index,VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetImageMemoryRequirements_PostCall)(uint64_t block_index,VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetImageSparseMemoryRequirements_PostCall)(uint64_t block_index,VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSparseImageFormatProperties_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties);
typedef void (VKAPI_PTR *PFN_QueueBindSparse_PostCall)(uint64_t block_index, VkResult result, VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);
typedef void (VKAPI_PTR *PFN_CreateFence_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
typedef void (VKAPI_PTR *PFN_DestroyFence_PostCall)(uint64_t block_index,VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_ResetFences_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t fenceCount, const VkFence* pFences);
typedef void (VKAPI_PTR *PFN_GetFenceStatus_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkFence fence);
typedef void (VKAPI_PTR *PFN_WaitForFences_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);
typedef void (VKAPI_PTR *PFN_CreateSemaphore_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
typedef void (VKAPI_PTR *PFN_DestroySemaphore_PostCall)(uint64_t block_index,VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateEvent_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent);
typedef void (VKAPI_PTR *PFN_DestroyEvent_PostCall)(uint64_t block_index,VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetEventStatus_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkEvent event);
typedef void (VKAPI_PTR *PFN_SetEvent_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkEvent event);
typedef void (VKAPI_PTR *PFN_ResetEvent_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkEvent event);
typedef void (VKAPI_PTR *PFN_CreateQueryPool_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);
typedef void (VKAPI_PTR *PFN_DestroyQueryPool_PostCall)(uint64_t block_index,VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetQueryPoolResults_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags);
typedef void (VKAPI_PTR *PFN_CreateBuffer_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
typedef void (VKAPI_PTR *PFN_DestroyBuffer_PostCall)(uint64_t block_index,VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateBufferView_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView);
typedef void (VKAPI_PTR *PFN_DestroyBufferView_PostCall)(uint64_t block_index,VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateImage_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage);
typedef void (VKAPI_PTR *PFN_DestroyImage_PostCall)(uint64_t block_index,VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetImageSubresourceLayout_PostCall)(uint64_t block_index,VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout);
typedef void (VKAPI_PTR *PFN_CreateImageView_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView);
typedef void (VKAPI_PTR *PFN_DestroyImageView_PostCall)(uint64_t block_index,VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateShaderModule_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule);
typedef void (VKAPI_PTR *PFN_DestroyShaderModule_PostCall)(uint64_t block_index,VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreatePipelineCache_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache);
typedef void (VKAPI_PTR *PFN_DestroyPipelineCache_PostCall)(uint64_t block_index,VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetPipelineCacheData_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);
typedef void (VKAPI_PTR *PFN_MergePipelineCaches_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches);
typedef void (VKAPI_PTR *PFN_CreateGraphicsPipelines_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
typedef void (VKAPI_PTR *PFN_CreateComputePipelines_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
typedef void (VKAPI_PTR *PFN_DestroyPipeline_PostCall)(uint64_t block_index,VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreatePipelineLayout_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout);
typedef void (VKAPI_PTR *PFN_DestroyPipelineLayout_PostCall)(uint64_t block_index,VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateSampler_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler);
typedef void (VKAPI_PTR *PFN_DestroySampler_PostCall)(uint64_t block_index,VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateDescriptorSetLayout_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout);
typedef void (VKAPI_PTR *PFN_DestroyDescriptorSetLayout_PostCall)(uint64_t block_index,VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateDescriptorPool_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);
typedef void (VKAPI_PTR *PFN_DestroyDescriptorPool_PostCall)(uint64_t block_index,VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_ResetDescriptorPool_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags);
typedef void (VKAPI_PTR *PFN_AllocateDescriptorSets_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets);
typedef void (VKAPI_PTR *PFN_FreeDescriptorSets_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);
typedef void (VKAPI_PTR *PFN_UpdateDescriptorSets_PostCall)(uint64_t block_index,VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies);
typedef void (VKAPI_PTR *PFN_CreateFramebuffer_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);
typedef void (VKAPI_PTR *PFN_DestroyFramebuffer_PostCall)(uint64_t block_index,VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateRenderPass_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
typedef void (VKAPI_PTR *PFN_DestroyRenderPass_PostCall)(uint64_t block_index,VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetRenderAreaGranularity_PostCall)(uint64_t block_index,VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity);
typedef void (VKAPI_PTR *PFN_CreateCommandPool_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
typedef void (VKAPI_PTR *PFN_DestroyCommandPool_PostCall)(uint64_t block_index,VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_ResetCommandPool_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags);
typedef void (VKAPI_PTR *PFN_AllocateCommandBuffers_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);
typedef void (VKAPI_PTR *PFN_FreeCommandBuffers_PostCall)(uint64_t block_index,VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
typedef void (VKAPI_PTR *PFN_BeginCommandBuffer_PostCall)(uint64_t block_index, VkResult result, VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);
typedef void (VKAPI_PTR *PFN_EndCommandBuffer_PostCall)(uint64_t block_index, VkResult result, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_ResetCommandBuffer_PostCall)(uint64_t block_index, VkResult result, VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);
typedef void (VKAPI_PTR *PFN_CmdBindPipeline_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
typedef void (VKAPI_PTR *PFN_CmdSetViewport_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports);
typedef void (VKAPI_PTR *PFN_CmdSetScissor_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors);
typedef void (VKAPI_PTR *PFN_CmdSetLineWidth_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, float lineWidth);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBias_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
typedef void (VKAPI_PTR *PFN_CmdSetBlendConstants_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const float blendConstants[4]);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBounds_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);
typedef void (VKAPI_PTR *PFN_CmdSetStencilCompareMask_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);
typedef void (VKAPI_PTR *PFN_CmdSetStencilWriteMask_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);
typedef void (VKAPI_PTR *PFN_CmdSetStencilReference_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);
typedef void (VKAPI_PTR *PFN_CmdBindDescriptorSets_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets);
typedef void (VKAPI_PTR *PFN_CmdBindIndexBuffer_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
typedef void (VKAPI_PTR *PFN_CmdBindVertexBuffers_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);
typedef void (VKAPI_PTR *PFN_CmdDraw_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexed_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirect_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexedIndirect_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDispatch_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_CmdDispatchIndirect_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
typedef void (VKAPI_PTR *PFN_CmdCopyBuffer_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions);
typedef void (VKAPI_PTR *PFN_CmdCopyImage_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions);
typedef void (VKAPI_PTR *PFN_CmdBlitImage_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter);
typedef void (VKAPI_PTR *PFN_CmdCopyBufferToImage_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);
typedef void (VKAPI_PTR *PFN_CmdCopyImageToBuffer_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);
typedef void (VKAPI_PTR *PFN_CmdUpdateBuffer_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData);
typedef void (VKAPI_PTR *PFN_CmdFillBuffer_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);
typedef void (VKAPI_PTR *PFN_CmdClearColorImage_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
typedef void (VKAPI_PTR *PFN_CmdClearDepthStencilImage_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
typedef void (VKAPI_PTR *PFN_CmdClearAttachments_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects);
typedef void (VKAPI_PTR *PFN_CmdResolveImage_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions);
typedef void (VKAPI_PTR *PFN_CmdSetEvent_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
typedef void (VKAPI_PTR *PFN_CmdResetEvent_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
typedef void (VKAPI_PTR *PFN_CmdWaitEvents_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
typedef void (VKAPI_PTR *PFN_CmdPipelineBarrier_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
typedef void (VKAPI_PTR *PFN_CmdBeginQuery_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);
typedef void (VKAPI_PTR *PFN_CmdEndQuery_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);
typedef void (VKAPI_PTR *PFN_CmdResetQueryPool_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_PTR *PFN_CmdWriteTimestamp_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query);
typedef void (VKAPI_PTR *PFN_CmdCopyQueryPoolResults_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);
typedef void (VKAPI_PTR *PFN_CmdPushConstants_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues);
typedef void (VKAPI_PTR *PFN_CmdBeginRenderPass_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents);
typedef void (VKAPI_PTR *PFN_CmdNextSubpass_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkSubpassContents contents);
typedef void (VKAPI_PTR *PFN_CmdEndRenderPass_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdExecuteCommands_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
typedef void (VKAPI_PTR *PFN_EnumerateInstanceVersion_PostCall)(uint64_t block_index, VkResult result, uint32_t* pApiVersion);
typedef void (VKAPI_PTR *PFN_BindBufferMemory2_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);
typedef void (VKAPI_PTR *PFN_BindImageMemory2_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);
typedef void (VKAPI_PTR *PFN_GetDeviceGroupPeerMemoryFeatures_PostCall)(uint64_t block_index,VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);
typedef void (VKAPI_PTR *PFN_CmdSetDeviceMask_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t deviceMask);
typedef void (VKAPI_PTR *PFN_CmdDispatchBase_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_EnumeratePhysicalDeviceGroups_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);
typedef void (VKAPI_PTR *PFN_GetImageMemoryRequirements2_PostCall)(uint64_t block_index,VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetBufferMemoryRequirements2_PostCall)(uint64_t block_index,VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetImageSparseMemoryRequirements2_PostCall)(uint64_t block_index,VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFeatures2_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceProperties2_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFormatProperties2_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceImageFormatProperties2_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceQueueFamilyProperties2_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceMemoryProperties2_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSparseImageFormatProperties2_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);
typedef void (VKAPI_PTR *PFN_TrimCommandPool_PostCall)(uint64_t block_index,VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
typedef void (VKAPI_PTR *PFN_GetDeviceQueue2_PostCall)(uint64_t block_index,VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue);
typedef void (VKAPI_PTR *PFN_CreateSamplerYcbcrConversion_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);
typedef void (VKAPI_PTR *PFN_DestroySamplerYcbcrConversion_PostCall)(uint64_t block_index,VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateDescriptorUpdateTemplate_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);
typedef void (VKAPI_PTR *PFN_DestroyDescriptorUpdateTemplate_PostCall)(uint64_t block_index,VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_UpdateDescriptorSetWithTemplate_PostCall)(uint64_t block_index,VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalBufferProperties_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalFenceProperties_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalSemaphoreProperties_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);
typedef void (VKAPI_PTR *PFN_GetDescriptorSetLayoutSupport_PostCall)(uint64_t block_index,VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirectCount_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexedIndirectCount_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CreateRenderPass2_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
typedef void (VKAPI_PTR *PFN_CmdBeginRenderPass2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo);
typedef void (VKAPI_PTR *PFN_CmdNextSubpass2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo);
typedef void (VKAPI_PTR *PFN_CmdEndRenderPass2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);
typedef void (VKAPI_PTR *PFN_ResetQueryPool_PostCall)(uint64_t block_index,VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_PTR *PFN_GetSemaphoreCounterValue_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkSemaphore semaphore, uint64_t* pValue);
typedef void (VKAPI_PTR *PFN_WaitSemaphores_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);
typedef void (VKAPI_PTR *PFN_SignalSemaphore_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo);
typedef void (VKAPI_PTR *PFN_GetBufferDeviceAddress_PostCall)(uint64_t block_index, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_GetBufferOpaqueCaptureAddress_PostCall)(uint64_t block_index, uint64_t result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_GetDeviceMemoryOpaqueCaptureAddress_PostCall)(uint64_t block_index, uint64_t result, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceToolProperties_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties);
typedef void (VKAPI_PTR *PFN_CreatePrivateDataSlot_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot);
typedef void (VKAPI_PTR *PFN_DestroyPrivateDataSlot_PostCall)(uint64_t block_index,VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_SetPrivateData_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);
typedef void (VKAPI_PTR *PFN_GetPrivateData_PostCall)(uint64_t block_index,VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData);
typedef void (VKAPI_PTR *PFN_CmdSetEvent2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);
typedef void (VKAPI_PTR *PFN_CmdResetEvent2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);
typedef void (VKAPI_PTR *PFN_CmdWaitEvents2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);
typedef void (VKAPI_PTR *PFN_CmdPipelineBarrier2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
typedef void (VKAPI_PTR *PFN_CmdWriteTimestamp2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query);
typedef void (VKAPI_PTR *PFN_QueueSubmit2_PostCall)(uint64_t block_index, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);
typedef void (VKAPI_PTR *PFN_CmdCopyBuffer2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyImage2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyBufferToImage2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyImageToBuffer2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
typedef void (VKAPI_PTR *PFN_CmdBlitImage2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
typedef void (VKAPI_PTR *PFN_CmdResolveImage2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
typedef void (VKAPI_PTR *PFN_CmdBeginRendering_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);
typedef void (VKAPI_PTR *PFN_CmdEndRendering_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdSetCullMode_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
typedef void (VKAPI_PTR *PFN_CmdSetFrontFace_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkFrontFace frontFace);
typedef void (VKAPI_PTR *PFN_CmdSetPrimitiveTopology_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
typedef void (VKAPI_PTR *PFN_CmdSetViewportWithCount_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);
typedef void (VKAPI_PTR *PFN_CmdSetScissorWithCount_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);
typedef void (VKAPI_PTR *PFN_CmdBindVertexBuffers2_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);
typedef void (VKAPI_PTR *PFN_CmdSetDepthTestEnable_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthWriteEnable_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthCompareOp_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBoundsTestEnable_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetStencilTestEnable_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetStencilOp_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
typedef void (VKAPI_PTR *PFN_CmdSetRasterizerDiscardEnable_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBiasEnable_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);
typedef void (VKAPI_PTR *PFN_CmdSetPrimitiveRestartEnable_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);
typedef void (VKAPI_PTR *PFN_GetDeviceBufferMemoryRequirements_PostCall)(uint64_t block_index,VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetDeviceImageMemoryRequirements_PostCall)(uint64_t block_index,VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetDeviceImageSparseMemoryRequirements_PostCall)(uint64_t block_index,VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
typedef void (VKAPI_PTR *PFN_DestroySurfaceKHR_PostCall)(uint64_t block_index,VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceSupportKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceFormatsKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfacePresentModesKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
typedef void (VKAPI_PTR *PFN_CreateSwapchainKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
typedef void (VKAPI_PTR *PFN_DestroySwapchainKHR_PostCall)(uint64_t block_index,VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetSwapchainImagesKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);
typedef void (VKAPI_PTR *PFN_AcquireNextImageKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);
typedef void (VKAPI_PTR *PFN_QueuePresentKHR_PostCall)(uint64_t block_index, VkResult result, VkQueue queue, const VkPresentInfoKHR* pPresentInfo);
typedef void (VKAPI_PTR *PFN_GetDeviceGroupPresentCapabilitiesKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities);
typedef void (VKAPI_PTR *PFN_GetDeviceGroupSurfacePresentModesKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes);
typedef void (VKAPI_PTR *PFN_GetPhysicalDevicePresentRectanglesKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects);
typedef void (VKAPI_PTR *PFN_AcquireNextImage2KHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceDisplayPropertiesKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties);
typedef void (VKAPI_PTR *PFN_GetDisplayPlaneSupportedDisplaysKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays);
typedef void (VKAPI_PTR *PFN_GetDisplayModePropertiesKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties);
typedef void (VKAPI_PTR *PFN_CreateDisplayModeKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode);
typedef void (VKAPI_PTR *PFN_GetDisplayPlaneCapabilitiesKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities);
typedef void (VKAPI_PTR *PFN_CreateDisplayPlaneSurfaceKHR_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CreateSharedSwapchainsKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains);
typedef void (VKAPI_PTR *PFN_CreateXlibSurfaceKHR_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceXlibPresentationSupportKHR_PostCall)(uint64_t block_index, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID);
typedef void (VKAPI_PTR *PFN_CreateXcbSurfaceKHR_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceXcbPresentationSupportKHR_PostCall)(uint64_t block_index, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id);
typedef void (VKAPI_PTR *PFN_CreateWaylandSurfaceKHR_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall)(uint64_t block_index, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display);
typedef void (VKAPI_PTR *PFN_CreateAndroidSurfaceKHR_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CreateWin32SurfaceKHR_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceWin32PresentationSupportKHR_PostCall)(uint64_t block_index, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceVideoCapabilitiesKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties);
typedef void (VKAPI_PTR *PFN_CreateVideoSessionKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession);
typedef void (VKAPI_PTR *PFN_DestroyVideoSessionKHR_PostCall)(uint64_t block_index,VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetVideoSessionMemoryRequirementsKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_BindVideoSessionMemoryKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos);
typedef void (VKAPI_PTR *PFN_CreateVideoSessionParametersKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters);
typedef void (VKAPI_PTR *PFN_UpdateVideoSessionParametersKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo);
typedef void (VKAPI_PTR *PFN_DestroyVideoSessionParametersKHR_PostCall)(uint64_t block_index,VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CmdBeginVideoCodingKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo);
typedef void (VKAPI_PTR *PFN_CmdEndVideoCodingKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo);
typedef void (VKAPI_PTR *PFN_CmdControlVideoCodingKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo);
typedef void (VKAPI_PTR *PFN_CmdDecodeVideoKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo);
typedef void (VKAPI_PTR *PFN_CmdBeginRenderingKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);
typedef void (VKAPI_PTR *PFN_CmdEndRenderingKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFeatures2KHR_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceProperties2KHR_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFormatProperties2KHR_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceImageFormatProperties2KHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceMemoryProperties2KHR_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);
typedef void (VKAPI_PTR *PFN_GetDeviceGroupPeerMemoryFeaturesKHR_PostCall)(uint64_t block_index,VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);
typedef void (VKAPI_PTR *PFN_CmdSetDeviceMaskKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t deviceMask);
typedef void (VKAPI_PTR *PFN_CmdDispatchBaseKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_TrimCommandPoolKHR_PostCall)(uint64_t block_index,VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
typedef void (VKAPI_PTR *PFN_EnumeratePhysicalDeviceGroupsKHR_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);
typedef void (VKAPI_PTR *PFN_GetMemoryWin32HandleKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);
typedef void (VKAPI_PTR *PFN_GetMemoryWin32HandlePropertiesKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties);
typedef void (VKAPI_PTR *PFN_GetMemoryFdKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd);
typedef void (VKAPI_PTR *PFN_GetMemoryFdPropertiesKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);
typedef void (VKAPI_PTR *PFN_ImportSemaphoreWin32HandleKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo);
typedef void (VKAPI_PTR *PFN_GetSemaphoreWin32HandleKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);
typedef void (VKAPI_PTR *PFN_ImportSemaphoreFdKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo);
typedef void (VKAPI_PTR *PFN_GetSemaphoreFdKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd);
typedef void (VKAPI_PTR *PFN_CmdPushDescriptorSetKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites);
typedef void (VKAPI_PTR *PFN_CmdPushDescriptorSetWithTemplateKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData);
typedef void (VKAPI_PTR *PFN_CreateDescriptorUpdateTemplateKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);
typedef void (VKAPI_PTR *PFN_DestroyDescriptorUpdateTemplateKHR_PostCall)(uint64_t block_index,VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_UpdateDescriptorSetWithTemplateKHR_PostCall)(uint64_t block_index,VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData);
typedef void (VKAPI_PTR *PFN_CreateRenderPass2KHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
typedef void (VKAPI_PTR *PFN_CmdBeginRenderPass2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo);
typedef void (VKAPI_PTR *PFN_CmdNextSubpass2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo);
typedef void (VKAPI_PTR *PFN_CmdEndRenderPass2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);
typedef void (VKAPI_PTR *PFN_GetSwapchainStatusKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalFencePropertiesKHR_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);
typedef void (VKAPI_PTR *PFN_ImportFenceWin32HandleKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo);
typedef void (VKAPI_PTR *PFN_GetFenceWin32HandleKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);
typedef void (VKAPI_PTR *PFN_ImportFenceFdKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo);
typedef void (VKAPI_PTR *PFN_GetFenceFdKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd);
typedef void (VKAPI_PTR *PFN_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses);
typedef void (VKAPI_PTR *PFN_AcquireProfilingLockKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_ReleaseProfilingLockKHR_PostCall)(uint64_t block_index,VkDevice device);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceFormats2KHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceDisplayProperties2KHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties);
typedef void (VKAPI_PTR *PFN_GetDisplayModeProperties2KHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties);
typedef void (VKAPI_PTR *PFN_GetDisplayPlaneCapabilities2KHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities);
typedef void (VKAPI_PTR *PFN_GetImageMemoryRequirements2KHR_PostCall)(uint64_t block_index,VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetBufferMemoryRequirements2KHR_PostCall)(uint64_t block_index,VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetImageSparseMemoryRequirements2KHR_PostCall)(uint64_t block_index,VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
typedef void (VKAPI_PTR *PFN_CreateSamplerYcbcrConversionKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);
typedef void (VKAPI_PTR *PFN_DestroySamplerYcbcrConversionKHR_PostCall)(uint64_t block_index,VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_BindBufferMemory2KHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);
typedef void (VKAPI_PTR *PFN_BindImageMemory2KHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);
typedef void (VKAPI_PTR *PFN_GetDescriptorSetLayoutSupportKHR_PostCall)(uint64_t block_index,VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirectCountKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexedIndirectCountKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_GetSemaphoreCounterValueKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkSemaphore semaphore, uint64_t* pValue);
typedef void (VKAPI_PTR *PFN_WaitSemaphoresKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);
typedef void (VKAPI_PTR *PFN_SignalSemaphoreKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFragmentShadingRatesKHR_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates);
typedef void (VKAPI_PTR *PFN_CmdSetFragmentShadingRateKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);
typedef void (VKAPI_PTR *PFN_WaitForPresentKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout);
typedef void (VKAPI_PTR *PFN_GetBufferDeviceAddressKHR_PostCall)(uint64_t block_index, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_GetBufferOpaqueCaptureAddressKHR_PostCall)(uint64_t block_index, uint64_t result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall)(uint64_t block_index, uint64_t result, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_CreateDeferredOperationKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation);
typedef void (VKAPI_PTR *PFN_DestroyDeferredOperationKHR_PostCall)(uint64_t block_index,VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetDeferredOperationMaxConcurrencyKHR_PostCall)(uint64_t block_index, uint32_t result, VkDevice device, VkDeferredOperationKHR operation);
typedef void (VKAPI_PTR *PFN_GetDeferredOperationResultKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR operation);
typedef void (VKAPI_PTR *PFN_DeferredOperationJoinKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR operation);
typedef void (VKAPI_PTR *PFN_GetPipelineExecutablePropertiesKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties);
typedef void (VKAPI_PTR *PFN_GetPipelineExecutableStatisticsKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics);
typedef void (VKAPI_PTR *PFN_GetPipelineExecutableInternalRepresentationsKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations);
typedef void (VKAPI_PTR *PFN_MapMemory2KHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryMapInfoKHR* pMemoryMapInfo, void** ppData);
typedef void (VKAPI_PTR *PFN_UnmapMemory2KHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryUnmapInfoKHR* pMemoryUnmapInfo);
typedef void (VKAPI_PTR *PFN_CmdEncodeVideoKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo);
typedef void (VKAPI_PTR *PFN_CmdSetEvent2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);
typedef void (VKAPI_PTR *PFN_CmdResetEvent2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);
typedef void (VKAPI_PTR *PFN_CmdWaitEvents2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);
typedef void (VKAPI_PTR *PFN_CmdPipelineBarrier2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
typedef void (VKAPI_PTR *PFN_CmdWriteTimestamp2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query);
typedef void (VKAPI_PTR *PFN_QueueSubmit2KHR_PostCall)(uint64_t block_index, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);
typedef void (VKAPI_PTR *PFN_CmdWriteBufferMarker2AMD_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);
typedef void (VKAPI_PTR *PFN_GetQueueCheckpointData2NV_PostCall)(uint64_t block_index,VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData);
typedef void (VKAPI_PTR *PFN_CmdCopyBuffer2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyImage2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyBufferToImage2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyImageToBuffer2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
typedef void (VKAPI_PTR *PFN_CmdBlitImage2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
typedef void (VKAPI_PTR *PFN_CmdResolveImage2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
typedef void (VKAPI_PTR *PFN_CmdTraceRaysIndirect2KHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress);
typedef void (VKAPI_PTR *PFN_GetDeviceBufferMemoryRequirementsKHR_PostCall)(uint64_t block_index,VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetDeviceImageMemoryRequirementsKHR_PostCall)(uint64_t block_index,VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetDeviceImageSparseMemoryRequirementsKHR_PostCall)(uint64_t block_index,VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
typedef void (VKAPI_PTR *PFN_CreateDebugReportCallbackEXT_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);
typedef void (VKAPI_PTR *PFN_DestroyDebugReportCallbackEXT_PostCall)(uint64_t block_index,VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_DebugReportMessageEXT_PostCall)(uint64_t block_index,VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage);
typedef void (VKAPI_PTR *PFN_DebugMarkerSetObjectTagEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo);
typedef void (VKAPI_PTR *PFN_DebugMarkerSetObjectNameEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo);
typedef void (VKAPI_PTR *PFN_CmdDebugMarkerBeginEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);
typedef void (VKAPI_PTR *PFN_CmdDebugMarkerEndEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdDebugMarkerInsertEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);
typedef void (VKAPI_PTR *PFN_CmdBindTransformFeedbackBuffersEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes);
typedef void (VKAPI_PTR *PFN_CmdBeginTransformFeedbackEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets);
typedef void (VKAPI_PTR *PFN_CmdEndTransformFeedbackEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets);
typedef void (VKAPI_PTR *PFN_CmdBeginQueryIndexedEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index);
typedef void (VKAPI_PTR *PFN_CmdEndQueryIndexedEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirectByteCountEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride);
typedef void (VKAPI_PTR *PFN_GetImageViewHandleNVX_PostCall)(uint64_t block_index, uint32_t result, VkDevice device, const VkImageViewHandleInfoNVX* pInfo);
typedef void (VKAPI_PTR *PFN_GetImageViewAddressNVX_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirectCountAMD_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexedIndirectCountAMD_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_GetShaderInfoAMD_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo);
typedef void (VKAPI_PTR *PFN_CreateStreamDescriptorSurfaceGGP_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties);
typedef void (VKAPI_PTR *PFN_GetMemoryWin32HandleNV_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle);
typedef void (VKAPI_PTR *PFN_CreateViSurfaceNN_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CmdBeginConditionalRenderingEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);
typedef void (VKAPI_PTR *PFN_CmdEndConditionalRenderingEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdSetViewportWScalingNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings);
typedef void (VKAPI_PTR *PFN_ReleaseDisplayEXT_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display);
typedef void (VKAPI_PTR *PFN_AcquireXlibDisplayEXT_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display);
typedef void (VKAPI_PTR *PFN_GetRandROutputDisplayEXT_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities);
typedef void (VKAPI_PTR *PFN_DisplayPowerControlEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo);
typedef void (VKAPI_PTR *PFN_RegisterDeviceEventEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
typedef void (VKAPI_PTR *PFN_RegisterDisplayEventEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
typedef void (VKAPI_PTR *PFN_GetSwapchainCounterEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue);
typedef void (VKAPI_PTR *PFN_GetRefreshCycleDurationGOOGLE_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties);
typedef void (VKAPI_PTR *PFN_GetPastPresentationTimingGOOGLE_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings);
typedef void (VKAPI_PTR *PFN_CmdSetDiscardRectangleEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles);
typedef void (VKAPI_PTR *PFN_CmdSetDiscardRectangleEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDiscardRectangleModeEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode);
typedef void (VKAPI_PTR *PFN_SetHdrMetadataEXT_PostCall)(uint64_t block_index,VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata);
typedef void (VKAPI_PTR *PFN_CreateIOSSurfaceMVK_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CreateMacOSSurfaceMVK_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_SetDebugUtilsObjectNameEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo);
typedef void (VKAPI_PTR *PFN_SetDebugUtilsObjectTagEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo);
typedef void (VKAPI_PTR *PFN_QueueBeginDebugUtilsLabelEXT_PostCall)(uint64_t block_index,VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
typedef void (VKAPI_PTR *PFN_QueueEndDebugUtilsLabelEXT_PostCall)(uint64_t block_index,VkQueue queue);
typedef void (VKAPI_PTR *PFN_QueueInsertDebugUtilsLabelEXT_PostCall)(uint64_t block_index,VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
typedef void (VKAPI_PTR *PFN_CmdBeginDebugUtilsLabelEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
typedef void (VKAPI_PTR *PFN_CmdEndDebugUtilsLabelEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdInsertDebugUtilsLabelEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
typedef void (VKAPI_PTR *PFN_CreateDebugUtilsMessengerEXT_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger);
typedef void (VKAPI_PTR *PFN_DestroyDebugUtilsMessengerEXT_PostCall)(uint64_t block_index,VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_SubmitDebugUtilsMessageEXT_PostCall)(uint64_t block_index,VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData);
typedef void (VKAPI_PTR *PFN_GetAndroidHardwareBufferPropertiesANDROID_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties);
typedef void (VKAPI_PTR *PFN_GetMemoryAndroidHardwareBufferANDROID_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer);
typedef void (VKAPI_PTR *PFN_CmdSetSampleLocationsEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceMultisamplePropertiesEXT_PostCall)(uint64_t block_index,VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties);
typedef void (VKAPI_PTR *PFN_GetImageDrmFormatModifierPropertiesEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties);
typedef void (VKAPI_PTR *PFN_CreateValidationCacheEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache);
typedef void (VKAPI_PTR *PFN_DestroyValidationCacheEXT_PostCall)(uint64_t block_index,VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_MergeValidationCachesEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches);
typedef void (VKAPI_PTR *PFN_GetValidationCacheDataEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData);
typedef void (VKAPI_PTR *PFN_CmdBindShadingRateImageNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);
typedef void (VKAPI_PTR *PFN_CmdSetViewportShadingRatePaletteNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes);
typedef void (VKAPI_PTR *PFN_CmdSetCoarseSampleOrderNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders);
typedef void (VKAPI_PTR *PFN_CreateAccelerationStructureNV_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure);
typedef void (VKAPI_PTR *PFN_DestroyAccelerationStructureNV_PostCall)(uint64_t block_index,VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetAccelerationStructureMemoryRequirementsNV_PostCall)(uint64_t block_index,VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_BindAccelerationStructureMemoryNV_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos);
typedef void (VKAPI_PTR *PFN_CmdBuildAccelerationStructureNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset);
typedef void (VKAPI_PTR *PFN_CmdCopyAccelerationStructureNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode);
typedef void (VKAPI_PTR *PFN_CmdTraceRaysNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth);
typedef void (VKAPI_PTR *PFN_CreateRayTracingPipelinesNV_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
typedef void (VKAPI_PTR *PFN_GetRayTracingShaderGroupHandlesKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);
typedef void (VKAPI_PTR *PFN_GetRayTracingShaderGroupHandlesNV_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);
typedef void (VKAPI_PTR *PFN_GetAccelerationStructureHandleNV_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData);
typedef void (VKAPI_PTR *PFN_CmdWriteAccelerationStructuresPropertiesNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);
typedef void (VKAPI_PTR *PFN_CompileDeferredNV_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t shader);
typedef void (VKAPI_PTR *PFN_GetMemoryHostPointerPropertiesEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties);
typedef void (VKAPI_PTR *PFN_CmdWriteBufferMarkerAMD_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainEXT* pTimeDomains);
typedef void (VKAPI_PTR *PFN_GetCalibratedTimestampsEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksIndirectNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksIndirectCountNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdSetExclusiveScissorEnableNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables);
typedef void (VKAPI_PTR *PFN_CmdSetExclusiveScissorNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors);
typedef void (VKAPI_PTR *PFN_CmdSetCheckpointNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const void* pCheckpointMarker);
typedef void (VKAPI_PTR *PFN_GetQueueCheckpointDataNV_PostCall)(uint64_t block_index,VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData);
typedef void (VKAPI_PTR *PFN_InitializePerformanceApiINTEL_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo);
typedef void (VKAPI_PTR *PFN_UninitializePerformanceApiINTEL_PostCall)(uint64_t block_index,VkDevice device);
typedef void (VKAPI_PTR *PFN_CmdSetPerformanceMarkerINTEL_PostCall)(uint64_t block_index, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo);
typedef void (VKAPI_PTR *PFN_CmdSetPerformanceStreamMarkerINTEL_PostCall)(uint64_t block_index, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo);
typedef void (VKAPI_PTR *PFN_CmdSetPerformanceOverrideINTEL_PostCall)(uint64_t block_index, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo);
typedef void (VKAPI_PTR *PFN_AcquirePerformanceConfigurationINTEL_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration);
typedef void (VKAPI_PTR *PFN_ReleasePerformanceConfigurationINTEL_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkPerformanceConfigurationINTEL configuration);
typedef void (VKAPI_PTR *PFN_QueueSetPerformanceConfigurationINTEL_PostCall)(uint64_t block_index, VkResult result, VkQueue queue, VkPerformanceConfigurationINTEL configuration);
typedef void (VKAPI_PTR *PFN_GetPerformanceParameterINTEL_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue);
typedef void (VKAPI_PTR *PFN_SetLocalDimmingAMD_PostCall)(uint64_t block_index,VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable);
typedef void (VKAPI_PTR *PFN_CreateImagePipeSurfaceFUCHSIA_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CreateMetalSurfaceEXT_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetBufferDeviceAddressEXT_PostCall)(uint64_t block_index, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceToolPropertiesEXT_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfacePresentModes2EXT_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
typedef void (VKAPI_PTR *PFN_AcquireFullScreenExclusiveModeEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain);
typedef void (VKAPI_PTR *PFN_ReleaseFullScreenExclusiveModeEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain);
typedef void (VKAPI_PTR *PFN_GetDeviceGroupSurfacePresentModes2EXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes);
typedef void (VKAPI_PTR *PFN_CreateHeadlessSurfaceEXT_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CmdSetLineStippleEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);
typedef void (VKAPI_PTR *PFN_ResetQueryPoolEXT_PostCall)(uint64_t block_index,VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_PTR *PFN_CmdSetCullModeEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
typedef void (VKAPI_PTR *PFN_CmdSetFrontFaceEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkFrontFace frontFace);
typedef void (VKAPI_PTR *PFN_CmdSetPrimitiveTopologyEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
typedef void (VKAPI_PTR *PFN_CmdSetViewportWithCountEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);
typedef void (VKAPI_PTR *PFN_CmdSetScissorWithCountEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);
typedef void (VKAPI_PTR *PFN_CmdBindVertexBuffers2EXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);
typedef void (VKAPI_PTR *PFN_CmdSetDepthTestEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthWriteEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthCompareOpEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBoundsTestEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetStencilTestEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetStencilOpEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
typedef void (VKAPI_PTR *PFN_ReleaseSwapchainImagesEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkReleaseSwapchainImagesInfoEXT* pReleaseInfo);
typedef void (VKAPI_PTR *PFN_GetGeneratedCommandsMemoryRequirementsNV_PostCall)(uint64_t block_index,VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_CmdPreprocessGeneratedCommandsNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);
typedef void (VKAPI_PTR *PFN_CmdExecuteGeneratedCommandsNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);
typedef void (VKAPI_PTR *PFN_CmdBindPipelineShaderGroupNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex);
typedef void (VKAPI_PTR *PFN_CreateIndirectCommandsLayoutNV_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout);
typedef void (VKAPI_PTR *PFN_DestroyIndirectCommandsLayoutNV_PostCall)(uint64_t block_index,VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_AcquireDrmDisplayEXT_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display);
typedef void (VKAPI_PTR *PFN_GetDrmDisplayEXT_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display);
typedef void (VKAPI_PTR *PFN_CreatePrivateDataSlotEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot);
typedef void (VKAPI_PTR *PFN_DestroyPrivateDataSlotEXT_PostCall)(uint64_t block_index,VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_SetPrivateDataEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);
typedef void (VKAPI_PTR *PFN_GetPrivateDataEXT_PostCall)(uint64_t block_index,VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData);
typedef void (VKAPI_PTR *PFN_CmdSetFragmentShadingRateEnumNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);
typedef void (VKAPI_PTR *PFN_GetImageSubresourceLayout2EXT_PostCall)(uint64_t block_index,VkDevice device, VkImage image, const VkImageSubresource2EXT* pSubresource, VkSubresourceLayout2EXT* pLayout);
typedef void (VKAPI_PTR *PFN_GetDeviceFaultInfoEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo);
typedef void (VKAPI_PTR *PFN_AcquireWinrtDisplayNV_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display);
typedef void (VKAPI_PTR *PFN_GetWinrtDisplayNV_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay);
typedef void (VKAPI_PTR *PFN_CreateDirectFBSurfaceEXT_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall)(uint64_t block_index, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb);
typedef void (VKAPI_PTR *PFN_CmdSetVertexInputEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);
typedef void (VKAPI_PTR *PFN_GetMemoryZirconHandleFUCHSIA_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);
typedef void (VKAPI_PTR *PFN_GetMemoryZirconHandlePropertiesFUCHSIA_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties);
typedef void (VKAPI_PTR *PFN_ImportSemaphoreZirconHandleFUCHSIA_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo);
typedef void (VKAPI_PTR *PFN_GetSemaphoreZirconHandleFUCHSIA_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);
typedef void (VKAPI_PTR *PFN_CmdBindInvocationMaskHUAWEI_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);
typedef void (VKAPI_PTR *PFN_GetMemoryRemoteAddressNV_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress);
typedef void (VKAPI_PTR *PFN_CmdSetPatchControlPointsEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t patchControlPoints);
typedef void (VKAPI_PTR *PFN_CmdSetRasterizerDiscardEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBiasEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);
typedef void (VKAPI_PTR *PFN_CmdSetLogicOpEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkLogicOp logicOp);
typedef void (VKAPI_PTR *PFN_CmdSetPrimitiveRestartEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);
typedef void (VKAPI_PTR *PFN_CreateScreenSurfaceQNX_PostCall)(uint64_t block_index, VkResult result, VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceScreenPresentationSupportQNX_PostCall)(uint64_t block_index, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window);
typedef void (VKAPI_PTR *PFN_CmdSetColorWriteEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables);
typedef void (VKAPI_PTR *PFN_CmdDrawMultiEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawMultiIndexedEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset);
typedef void (VKAPI_PTR *PFN_CreateMicromapEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap);
typedef void (VKAPI_PTR *PFN_DestroyMicromapEXT_PostCall)(uint64_t block_index,VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CmdBuildMicromapsEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);
typedef void (VKAPI_PTR *PFN_BuildMicromapsEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);
typedef void (VKAPI_PTR *PFN_CopyMicromapEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_CopyMicromapToMemoryEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_CopyMemoryToMicromapEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_WriteMicromapsPropertiesEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, size_t dataSize, void* pData, size_t stride);
typedef void (VKAPI_PTR *PFN_CmdCopyMicromapEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyMicromapToMemoryEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyMemoryToMicromapEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_CmdWriteMicromapsPropertiesEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);
typedef void (VKAPI_PTR *PFN_GetDeviceMicromapCompatibilityEXT_PostCall)(uint64_t block_index,VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility);
typedef void (VKAPI_PTR *PFN_GetMicromapBuildSizesEXT_PostCall)(uint64_t block_index,VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT* pBuildInfo, VkMicromapBuildSizesInfoEXT* pSizeInfo);
typedef void (VKAPI_PTR *PFN_CmdDrawClusterHUAWEI_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_CmdDrawClusterIndirectHUAWEI_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
typedef void (VKAPI_PTR *PFN_SetDeviceMemoryPriorityEXT_PostCall)(uint64_t block_index,VkDevice device, VkDeviceMemory memory, float priority);
typedef void (VKAPI_PTR *PFN_GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall)(uint64_t block_index,VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping);
typedef void (VKAPI_PTR *PFN_GetDescriptorSetHostMappingVALVE_PostCall)(uint64_t block_index,VkDevice device, VkDescriptorSet descriptorSet, void** ppData);
typedef void (VKAPI_PTR *PFN_CmdSetTessellationDomainOriginEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin);
typedef void (VKAPI_PTR *PFN_CmdSetDepthClampEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthClampEnable);
typedef void (VKAPI_PTR *PFN_CmdSetPolygonModeEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkPolygonMode polygonMode);
typedef void (VKAPI_PTR *PFN_CmdSetRasterizationSamplesEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples);
typedef void (VKAPI_PTR *PFN_CmdSetSampleMaskEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples, const VkSampleMask* pSampleMask);
typedef void (VKAPI_PTR *PFN_CmdSetAlphaToCoverageEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable);
typedef void (VKAPI_PTR *PFN_CmdSetAlphaToOneEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable);
typedef void (VKAPI_PTR *PFN_CmdSetLogicOpEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 logicOpEnable);
typedef void (VKAPI_PTR *PFN_CmdSetColorBlendEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables);
typedef void (VKAPI_PTR *PFN_CmdSetColorBlendEquationEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations);
typedef void (VKAPI_PTR *PFN_CmdSetColorWriteMaskEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks);
typedef void (VKAPI_PTR *PFN_CmdSetRasterizationStreamEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t rasterizationStream);
typedef void (VKAPI_PTR *PFN_CmdSetConservativeRasterizationModeEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode);
typedef void (VKAPI_PTR *PFN_CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize);
typedef void (VKAPI_PTR *PFN_CmdSetDepthClipEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthClipEnable);
typedef void (VKAPI_PTR *PFN_CmdSetSampleLocationsEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable);
typedef void (VKAPI_PTR *PFN_CmdSetColorBlendAdvancedEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced);
typedef void (VKAPI_PTR *PFN_CmdSetProvokingVertexModeEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode);
typedef void (VKAPI_PTR *PFN_CmdSetLineRasterizationModeEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode);
typedef void (VKAPI_PTR *PFN_CmdSetLineStippleEnableEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthClipNegativeOneToOneEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne);
typedef void (VKAPI_PTR *PFN_CmdSetViewportWScalingEnableNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable);
typedef void (VKAPI_PTR *PFN_CmdSetViewportSwizzleNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageToColorEnableNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageToColorLocationNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageModulationModeNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageModulationTableEnableNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageModulationTableNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable);
typedef void (VKAPI_PTR *PFN_CmdSetShadingRateImageEnableNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable);
typedef void (VKAPI_PTR *PFN_CmdSetRepresentativeFragmentTestEnableNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageReductionModeNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode);
typedef void (VKAPI_PTR *PFN_GetShaderModuleIdentifierEXT_PostCall)(uint64_t block_index,VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier);
typedef void (VKAPI_PTR *PFN_GetShaderModuleCreateInfoIdentifierEXT_PostCall)(uint64_t block_index,VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall)(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties);
typedef void (VKAPI_PTR *PFN_CreateOpticalFlowSessionNV_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession);
typedef void (VKAPI_PTR *PFN_DestroyOpticalFlowSessionNV_PostCall)(uint64_t block_index,VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_BindOpticalFlowSessionImageNV_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout);
typedef void (VKAPI_PTR *PFN_CmdOpticalFlowExecuteNV_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo);
typedef void (VKAPI_PTR *PFN_CreateShadersEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t createInfoCount, const VkShaderCreateInfoEXT* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkShaderEXT* pShaders);
typedef void (VKAPI_PTR *PFN_DestroyShaderEXT_PostCall)(uint64_t block_index,VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetShaderBinaryDataEXT_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkShaderEXT shader, size_t* pDataSize, void* pData);
typedef void (VKAPI_PTR *PFN_CmdBindShadersEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders);
typedef void (VKAPI_PTR *PFN_GetFramebufferTilePropertiesQCOM_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties);
typedef void (VKAPI_PTR *PFN_GetDynamicRenderingTilePropertiesQCOM_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties);
typedef void (VKAPI_PTR *PFN_CreateAccelerationStructureKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure);
typedef void (VKAPI_PTR *PFN_DestroyAccelerationStructureKHR_PostCall)(uint64_t block_index,VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CmdBuildAccelerationStructuresKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);
typedef void (VKAPI_PTR *PFN_CmdBuildAccelerationStructuresIndirectKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts);
typedef void (VKAPI_PTR *PFN_BuildAccelerationStructuresKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);
typedef void (VKAPI_PTR *PFN_CopyAccelerationStructureKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_CopyAccelerationStructureToMemoryKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_CopyMemoryToAccelerationStructureKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_WriteAccelerationStructuresPropertiesKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride);
typedef void (VKAPI_PTR *PFN_CmdCopyAccelerationStructureKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyAccelerationStructureToMemoryKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyMemoryToAccelerationStructureKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_GetAccelerationStructureDeviceAddressKHR_PostCall)(uint64_t block_index, VkDeviceAddress result, VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_CmdWriteAccelerationStructuresPropertiesKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);
typedef void (VKAPI_PTR *PFN_GetDeviceAccelerationStructureCompatibilityKHR_PostCall)(uint64_t block_index,VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility);
typedef void (VKAPI_PTR *PFN_GetAccelerationStructureBuildSizesKHR_PostCall)(uint64_t block_index,VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo);
typedef void (VKAPI_PTR *PFN_CmdTraceRaysKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth);
typedef void (VKAPI_PTR *PFN_CreateRayTracingPipelinesKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
typedef void (VKAPI_PTR *PFN_GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall)(uint64_t block_index, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);
typedef void (VKAPI_PTR *PFN_CmdTraceRaysIndirectKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress);
typedef void (VKAPI_PTR *PFN_GetRayTracingShaderGroupStackSizeKHR_PostCall)(uint64_t block_index, VkDeviceSize result, VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader);
typedef void (VKAPI_PTR *PFN_CmdSetRayTracingPipelineStackSizeKHR_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t pipelineStackSize);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksIndirectEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksIndirectCountEXT_PostCall)(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);


GFXRECON_BEGIN_NAMESPACE(noop)
static VKAPI_ATTR void VKAPI_CALL CreateInstance_PostCall(uint64_t block_index, VkResult result, const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) { }
static VKAPI_ATTR void VKAPI_CALL DestroyInstance_PostCall(uint64_t block_index,VkInstance instance, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDevices_PostCall(uint64_t block_index, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetInstanceProcAddr_PostCall(uint64_t block_index, PFN_vkVoidFunction result, VkInstance instance, const char* pName) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceProcAddr_PostCall(uint64_t block_index, PFN_vkVoidFunction result, VkDevice device, const char* pName) { }
static VKAPI_ATTR void VKAPI_CALL CreateDevice_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDevice_PostCall(uint64_t block_index,VkDevice device, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL EnumerateInstanceExtensionProperties_PostCall(uint64_t block_index, VkResult result, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL EnumerateDeviceExtensionProperties_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL EnumerateInstanceLayerProperties_PostCall(uint64_t block_index, VkResult result, uint32_t* pPropertyCount, VkLayerProperties* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL EnumerateDeviceLayerProperties_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceQueue_PostCall(uint64_t block_index,VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) { }
static VKAPI_ATTR void VKAPI_CALL QueueSubmit_PostCall(uint64_t block_index, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) { }
static VKAPI_ATTR void VKAPI_CALL QueueWaitIdle_PostCall(uint64_t block_index, VkResult result, VkQueue queue) { }
static VKAPI_ATTR void VKAPI_CALL DeviceWaitIdle_PostCall(uint64_t block_index, VkResult result, VkDevice device) { }
static VKAPI_ATTR void VKAPI_CALL AllocateMemory_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) { }
static VKAPI_ATTR void VKAPI_CALL FreeMemory_PostCall(uint64_t block_index,VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL MapMemory_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) { }
static VKAPI_ATTR void VKAPI_CALL UnmapMemory_PostCall(uint64_t block_index,VkDevice device, VkDeviceMemory memory) { }
static VKAPI_ATTR void VKAPI_CALL FlushMappedMemoryRanges_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) { }
static VKAPI_ATTR void VKAPI_CALL InvalidateMappedMemoryRanges_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment_PostCall(uint64_t block_index,VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) { }
static VKAPI_ATTR void VKAPI_CALL BindBufferMemory_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) { }
static VKAPI_ATTR void VKAPI_CALL BindImageMemory_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements_PostCall(uint64_t block_index,VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements_PostCall(uint64_t block_index,VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements_PostCall(uint64_t block_index,VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL QueueBindSparse_PostCall(uint64_t block_index, VkResult result, VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence) { }
static VKAPI_ATTR void VKAPI_CALL CreateFence_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) { }
static VKAPI_ATTR void VKAPI_CALL DestroyFence_PostCall(uint64_t block_index,VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL ResetFences_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t fenceCount, const VkFence* pFences) { }
static VKAPI_ATTR void VKAPI_CALL GetFenceStatus_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkFence fence) { }
static VKAPI_ATTR void VKAPI_CALL WaitForFences_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) { }
static VKAPI_ATTR void VKAPI_CALL CreateSemaphore_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) { }
static VKAPI_ATTR void VKAPI_CALL DestroySemaphore_PostCall(uint64_t block_index,VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateEvent_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) { }
static VKAPI_ATTR void VKAPI_CALL DestroyEvent_PostCall(uint64_t block_index,VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetEventStatus_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkEvent event) { }
static VKAPI_ATTR void VKAPI_CALL SetEvent_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkEvent event) { }
static VKAPI_ATTR void VKAPI_CALL ResetEvent_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkEvent event) { }
static VKAPI_ATTR void VKAPI_CALL CreateQueryPool_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) { }
static VKAPI_ATTR void VKAPI_CALL DestroyQueryPool_PostCall(uint64_t block_index,VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetQueryPoolResults_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL CreateBuffer_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) { }
static VKAPI_ATTR void VKAPI_CALL DestroyBuffer_PostCall(uint64_t block_index,VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateBufferView_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) { }
static VKAPI_ATTR void VKAPI_CALL DestroyBufferView_PostCall(uint64_t block_index,VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateImage_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) { }
static VKAPI_ATTR void VKAPI_CALL DestroyImage_PostCall(uint64_t block_index,VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout_PostCall(uint64_t block_index,VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) { }
static VKAPI_ATTR void VKAPI_CALL CreateImageView_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) { }
static VKAPI_ATTR void VKAPI_CALL DestroyImageView_PostCall(uint64_t block_index,VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateShaderModule_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) { }
static VKAPI_ATTR void VKAPI_CALL DestroyShaderModule_PostCall(uint64_t block_index,VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreatePipelineCache_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache_PostCall(uint64_t block_index,VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetPipelineCacheData_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData) { }
static VKAPI_ATTR void VKAPI_CALL MergePipelineCaches_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches) { }
static VKAPI_ATTR void VKAPI_CALL CreateGraphicsPipelines_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) { }
static VKAPI_ATTR void VKAPI_CALL CreateComputePipelines_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPipeline_PostCall(uint64_t block_index,VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreatePipelineLayout_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout_PostCall(uint64_t block_index,VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateSampler_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) { }
static VKAPI_ATTR void VKAPI_CALL DestroySampler_PostCall(uint64_t block_index,VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateDescriptorSetLayout_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout_PostCall(uint64_t block_index,VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateDescriptorPool_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool_PostCall(uint64_t block_index,VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL ResetDescriptorPool_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL AllocateDescriptorSets_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) { }
static VKAPI_ATTR void VKAPI_CALL FreeDescriptorSets_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) { }
static VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets_PostCall(uint64_t block_index,VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) { }
static VKAPI_ATTR void VKAPI_CALL CreateFramebuffer_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) { }
static VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer_PostCall(uint64_t block_index,VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateRenderPass_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) { }
static VKAPI_ATTR void VKAPI_CALL DestroyRenderPass_PostCall(uint64_t block_index,VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity_PostCall(uint64_t block_index,VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) { }
static VKAPI_ATTR void VKAPI_CALL CreateCommandPool_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) { }
static VKAPI_ATTR void VKAPI_CALL DestroyCommandPool_PostCall(uint64_t block_index,VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL ResetCommandPool_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL AllocateCommandBuffers_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) { }
static VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers_PostCall(uint64_t block_index,VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) { }
static VKAPI_ATTR void VKAPI_CALL BeginCommandBuffer_PostCall(uint64_t block_index, VkResult result, VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) { }
static VKAPI_ATTR void VKAPI_CALL EndCommandBuffer_PostCall(uint64_t block_index, VkResult result, VkCommandBuffer commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL ResetCommandBuffer_PostCall(uint64_t block_index, VkResult result, VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindPipeline_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewport_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissor_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, float lineWidth) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const float blendConstants[4]) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) { }
static VKAPI_ATTR void VKAPI_CALL CmdDraw_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDispatch_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdFillBuffer_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) { }
static VKAPI_ATTR void VKAPI_CALL CmdClearColorImage_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) { }
static VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) { }
static VKAPI_ATTR void VKAPI_CALL CmdClearAttachments_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) { }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) { }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginQuery_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndQuery_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) { }
static VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL CmdPushConstants_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) { }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkSubpassContents contents) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) { }
static VKAPI_ATTR void VKAPI_CALL EnumerateInstanceVersion_PostCall(uint64_t block_index, VkResult result, uint32_t* pApiVersion) { }
static VKAPI_ATTR void VKAPI_CALL BindBufferMemory2_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL BindImageMemory2_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures_PostCall(uint64_t block_index,VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t deviceMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchBase_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceGroups_PostCall(uint64_t block_index, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2_PostCall(uint64_t block_index,VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2_PostCall(uint64_t block_index,VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2_PostCall(uint64_t block_index,VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties2_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL TrimCommandPool_PostCall(uint64_t block_index,VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2_PostCall(uint64_t block_index,VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) { }
static VKAPI_ATTR void VKAPI_CALL CreateSamplerYcbcrConversion_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) { }
static VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion_PostCall(uint64_t block_index,VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateDescriptorUpdateTemplate_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate_PostCall(uint64_t block_index,VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplate_PostCall(uint64_t block_index,VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport_PostCall(uint64_t block_index,VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CreateRenderPass2_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) { }
static VKAPI_ATTR void VKAPI_CALL ResetQueryPool_PostCall(uint64_t block_index,VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreCounterValue_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkSemaphore semaphore, uint64_t* pValue) { }
static VKAPI_ATTR void VKAPI_CALL WaitSemaphores_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) { }
static VKAPI_ATTR void VKAPI_CALL SignalSemaphore_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddress_PostCall(uint64_t block_index, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferOpaqueCaptureAddress_PostCall(uint64_t block_index, uint64_t result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress_PostCall(uint64_t block_index, uint64_t result, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceToolProperties_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreatePrivateDataSlot_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot_PostCall(uint64_t block_index,VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL SetPrivateData_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) { }
static VKAPI_ATTR void VKAPI_CALL GetPrivateData_PostCall(uint64_t block_index,VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) { }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) { }
static VKAPI_ATTR void VKAPI_CALL QueueSubmit2_PostCall(uint64_t block_index, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRendering_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRendering_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCullMode_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkFrontFace frontFace) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirements_PostCall(uint64_t block_index,VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirements_PostCall(uint64_t block_index,VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements_PostCall(uint64_t block_index,VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR_PostCall(uint64_t block_index,VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) { }
static VKAPI_ATTR void VKAPI_CALL CreateSwapchainKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) { }
static VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR_PostCall(uint64_t block_index,VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetSwapchainImagesKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) { }
static VKAPI_ATTR void VKAPI_CALL AcquireNextImageKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) { }
static VKAPI_ATTR void VKAPI_CALL QueuePresentKHR_PostCall(uint64_t block_index, VkResult result, VkQueue queue, const VkPresentInfoKHR* pPresentInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects) { }
static VKAPI_ATTR void VKAPI_CALL AcquireNextImage2KHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayModePropertiesKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateDisplayModeKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneCapabilitiesKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL CreateDisplayPlaneSurfaceKHR_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CreateSharedSwapchainsKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) { }
static VKAPI_ATTR void VKAPI_CALL CreateXlibSurfaceKHR_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR_PostCall(uint64_t block_index, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID) { }
static VKAPI_ATTR void VKAPI_CALL CreateXcbSurfaceKHR_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR_PostCall(uint64_t block_index, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id) { }
static VKAPI_ATTR void VKAPI_CALL CreateWaylandSurfaceKHR_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall(uint64_t block_index, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display) { }
static VKAPI_ATTR void VKAPI_CALL CreateAndroidSurfaceKHR_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CreateWin32SurfaceKHR_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR_PostCall(uint64_t block_index, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceVideoCapabilitiesKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateVideoSessionKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession) { }
static VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionKHR_PostCall(uint64_t block_index,VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetVideoSessionMemoryRequirementsKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL BindVideoSessionMemoryKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos) { }
static VKAPI_ATTR void VKAPI_CALL CreateVideoSessionParametersKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters) { }
static VKAPI_ATTR void VKAPI_CALL UpdateVideoSessionParametersKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo) { }
static VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionParametersKHR_PostCall(uint64_t block_index,VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginVideoCodingKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndVideoCodingKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdControlVideoCodingKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdDecodeVideoKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderingKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderingKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR_PostCall(uint64_t block_index,VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t deviceMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchBaseKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR_PostCall(uint64_t block_index,VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR_PostCall(uint64_t block_index, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandleKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandlePropertiesKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryFdKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryFdPropertiesKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) { }
static VKAPI_ATTR void VKAPI_CALL ImportSemaphoreWin32HandleKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreWin32HandleKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) { }
static VKAPI_ATTR void VKAPI_CALL ImportSemaphoreFdKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreFdKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) { }
static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) { }
static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetWithTemplateKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) { }
static VKAPI_ATTR void VKAPI_CALL CreateDescriptorUpdateTemplateKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR_PostCall(uint64_t block_index,VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplateKHR_PostCall(uint64_t block_index,VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) { }
static VKAPI_ATTR void VKAPI_CALL CreateRenderPass2KHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetSwapchainStatusKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) { }
static VKAPI_ATTR void VKAPI_CALL ImportFenceWin32HandleKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetFenceWin32HandleKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) { }
static VKAPI_ATTR void VKAPI_CALL ImportFenceFdKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetFenceFdKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) { }
static VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses) { }
static VKAPI_ATTR void VKAPI_CALL AcquireProfilingLockKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR_PostCall(uint64_t block_index,VkDevice device) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayModeProperties2KHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneCapabilities2KHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR_PostCall(uint64_t block_index,VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR_PostCall(uint64_t block_index,VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR_PostCall(uint64_t block_index,VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL CreateSamplerYcbcrConversionKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) { }
static VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR_PostCall(uint64_t block_index,VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL BindBufferMemory2KHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL BindImageMemory2KHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR_PostCall(uint64_t block_index,VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreCounterValueKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkSemaphore semaphore, uint64_t* pValue) { }
static VKAPI_ATTR void VKAPI_CALL WaitSemaphoresKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) { }
static VKAPI_ATTR void VKAPI_CALL SignalSemaphoreKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFragmentShadingRatesKHR_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) { }
static VKAPI_ATTR void VKAPI_CALL WaitForPresentKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddressKHR_PostCall(uint64_t block_index, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferOpaqueCaptureAddressKHR_PostCall(uint64_t block_index, uint64_t result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall(uint64_t block_index, uint64_t result, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CreateDeferredOperationKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDeferredOperationKHR_PostCall(uint64_t block_index,VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetDeferredOperationMaxConcurrencyKHR_PostCall(uint64_t block_index, uint32_t result, VkDevice device, VkDeferredOperationKHR operation) { }
static VKAPI_ATTR void VKAPI_CALL GetDeferredOperationResultKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR operation) { }
static VKAPI_ATTR void VKAPI_CALL DeferredOperationJoinKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR operation) { }
static VKAPI_ATTR void VKAPI_CALL GetPipelineExecutablePropertiesKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPipelineExecutableStatisticsKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics) { }
static VKAPI_ATTR void VKAPI_CALL GetPipelineExecutableInternalRepresentationsKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) { }
static VKAPI_ATTR void VKAPI_CALL MapMemory2KHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryMapInfoKHR* pMemoryMapInfo, void** ppData) { }
static VKAPI_ATTR void VKAPI_CALL UnmapMemory2KHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryUnmapInfoKHR* pMemoryUnmapInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEncodeVideoKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) { }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) { }
static VKAPI_ATTR void VKAPI_CALL QueueSubmit2KHR_PostCall(uint64_t block_index, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarker2AMD_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) { }
static VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointData2NV_PostCall(uint64_t block_index,VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirect2KHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirementsKHR_PostCall(uint64_t block_index,VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirementsKHR_PostCall(uint64_t block_index,VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirementsKHR_PostCall(uint64_t block_index,VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL CreateDebugReportCallbackEXT_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT_PostCall(uint64_t block_index,VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL DebugReportMessageEXT_PostCall(uint64_t block_index,VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage) { }
static VKAPI_ATTR void VKAPI_CALL DebugMarkerSetObjectTagEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo) { }
static VKAPI_ATTR void VKAPI_CALL DebugMarkerSetObjectNameEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindTransformFeedbackBuffersEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginTransformFeedbackEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndTransformFeedbackEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginQueryIndexedEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndQueryIndexedEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectByteCountEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) { }
static VKAPI_ATTR void VKAPI_CALL GetImageViewHandleNVX_PostCall(uint64_t block_index, uint32_t result, VkDevice device, const VkImageViewHandleInfoNVX* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetImageViewAddressNVX_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountAMD_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountAMD_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL GetShaderInfoAMD_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CreateStreamDescriptorSurfaceGGP_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandleNV_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle) { }
static VKAPI_ATTR void VKAPI_CALL CreateViSurfaceNN_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) { }
static VKAPI_ATTR void VKAPI_CALL ReleaseDisplayEXT_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display) { }
static VKAPI_ATTR void VKAPI_CALL AcquireXlibDisplayEXT_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display) { }
static VKAPI_ATTR void VKAPI_CALL GetRandROutputDisplayEXT_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL DisplayPowerControlEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) { }
static VKAPI_ATTR void VKAPI_CALL RegisterDeviceEventEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) { }
static VKAPI_ATTR void VKAPI_CALL RegisterDisplayEventEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) { }
static VKAPI_ATTR void VKAPI_CALL GetSwapchainCounterEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) { }
static VKAPI_ATTR void VKAPI_CALL GetRefreshCycleDurationGOOGLE_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPastPresentationTimingGOOGLE_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleModeEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode) { }
static VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT_PostCall(uint64_t block_index,VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) { }
static VKAPI_ATTR void VKAPI_CALL CreateIOSSurfaceMVK_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CreateMacOSSurfaceMVK_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL SetDebugUtilsObjectNameEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) { }
static VKAPI_ATTR void VKAPI_CALL SetDebugUtilsObjectTagEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) { }
static VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT_PostCall(uint64_t block_index,VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) { }
static VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT_PostCall(uint64_t block_index,VkQueue queue) { }
static VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT_PostCall(uint64_t block_index,VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) { }
static VKAPI_ATTR void VKAPI_CALL CreateDebugUtilsMessengerEXT_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT_PostCall(uint64_t block_index,VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT_PostCall(uint64_t block_index,VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) { }
static VKAPI_ATTR void VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID_PostCall(uint64_t block_index, VkResult result, VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT_PostCall(uint64_t block_index,VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateValidationCacheEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache) { }
static VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT_PostCall(uint64_t block_index,VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL MergeValidationCachesEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches) { }
static VKAPI_ATTR void VKAPI_CALL GetValidationCacheDataEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindShadingRateImageNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportShadingRatePaletteNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoarseSampleOrderNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) { }
static VKAPI_ATTR void VKAPI_CALL CreateAccelerationStructureNV_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure) { }
static VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNV_PostCall(uint64_t block_index,VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNV_PostCall(uint64_t block_index,VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL BindAccelerationStructureMemoryNV_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructureNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) { }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) { }
static VKAPI_ATTR void VKAPI_CALL CreateRayTracingPipelinesNV_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) { }
static VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupHandlesKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) { }
static VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupHandlesNV_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) { }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureHandleNV_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) { }
static VKAPI_ATTR void VKAPI_CALL CompileDeferredNV_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t shader) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryHostPointerPropertiesEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainEXT* pTimeDomains) { }
static VKAPI_ATTR void VKAPI_CALL GetCalibratedTimestampsEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorEnableNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCheckpointNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const void* pCheckpointMarker) { }
static VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV_PostCall(uint64_t block_index,VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) { }
static VKAPI_ATTR void VKAPI_CALL InitializePerformanceApiINTEL_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo) { }
static VKAPI_ATTR void VKAPI_CALL UninitializePerformanceApiINTEL_PostCall(uint64_t block_index,VkDevice device) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceMarkerINTEL_PostCall(uint64_t block_index, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceStreamMarkerINTEL_PostCall(uint64_t block_index, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceOverrideINTEL_PostCall(uint64_t block_index, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) { }
static VKAPI_ATTR void VKAPI_CALL AcquirePerformanceConfigurationINTEL_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration) { }
static VKAPI_ATTR void VKAPI_CALL ReleasePerformanceConfigurationINTEL_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkPerformanceConfigurationINTEL configuration) { }
static VKAPI_ATTR void VKAPI_CALL QueueSetPerformanceConfigurationINTEL_PostCall(uint64_t block_index, VkResult result, VkQueue queue, VkPerformanceConfigurationINTEL configuration) { }
static VKAPI_ATTR void VKAPI_CALL GetPerformanceParameterINTEL_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue) { }
static VKAPI_ATTR void VKAPI_CALL SetLocalDimmingAMD_PostCall(uint64_t block_index,VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) { }
static VKAPI_ATTR void VKAPI_CALL CreateImagePipeSurfaceFUCHSIA_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CreateMetalSurfaceEXT_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddressEXT_PostCall(uint64_t block_index, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfacePresentModes2EXT_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) { }
static VKAPI_ATTR void VKAPI_CALL AcquireFullScreenExclusiveModeEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain) { }
static VKAPI_ATTR void VKAPI_CALL ReleaseFullScreenExclusiveModeEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkSwapchainKHR swapchain) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupSurfacePresentModes2EXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) { }
static VKAPI_ATTR void VKAPI_CALL CreateHeadlessSurfaceEXT_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) { }
static VKAPI_ATTR void VKAPI_CALL ResetQueryPoolEXT_PostCall(uint64_t block_index,VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkFrontFace frontFace) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) { }
static VKAPI_ATTR void VKAPI_CALL ReleaseSwapchainImagesEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkReleaseSwapchainImagesInfoEXT* pReleaseInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetGeneratedCommandsMemoryRequirementsNV_PostCall(uint64_t block_index,VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL CmdPreprocessGeneratedCommandsNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdExecuteGeneratedCommandsNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindPipelineShaderGroupNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) { }
static VKAPI_ATTR void VKAPI_CALL CreateIndirectCommandsLayoutNV_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout) { }
static VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNV_PostCall(uint64_t block_index,VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL AcquireDrmDisplayEXT_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display) { }
static VKAPI_ATTR void VKAPI_CALL GetDrmDisplayEXT_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display) { }
static VKAPI_ATTR void VKAPI_CALL CreatePrivateDataSlotEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlotEXT_PostCall(uint64_t block_index,VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL SetPrivateDataEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) { }
static VKAPI_ATTR void VKAPI_CALL GetPrivateDataEXT_PostCall(uint64_t block_index,VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateEnumNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2EXT_PostCall(uint64_t block_index,VkDevice device, VkImage image, const VkImageSubresource2EXT* pSubresource, VkSubresourceLayout2EXT* pLayout) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceFaultInfoEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo) { }
static VKAPI_ATTR void VKAPI_CALL AcquireWinrtDisplayNV_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display) { }
static VKAPI_ATTR void VKAPI_CALL GetWinrtDisplayNV_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay) { }
static VKAPI_ATTR void VKAPI_CALL CreateDirectFBSurfaceEXT_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall(uint64_t block_index, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryZirconHandleFUCHSIA_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryZirconHandlePropertiesFUCHSIA_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties) { }
static VKAPI_ATTR void VKAPI_CALL ImportSemaphoreZirconHandleFUCHSIA_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreZirconHandleFUCHSIA_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindInvocationMaskHUAWEI_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryRemoteAddressNV_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t patchControlPoints) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkLogicOp logicOp) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) { }
static VKAPI_ATTR void VKAPI_CALL CreateScreenSurfaceQNX_PostCall(uint64_t block_index, VkResult result, VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceScreenPresentationSupportQNX_PostCall(uint64_t block_index, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMultiEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMultiIndexedEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) { }
static VKAPI_ATTR void VKAPI_CALL CreateMicromapEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap) { }
static VKAPI_ATTR void VKAPI_CALL DestroyMicromapEXT_PostCall(uint64_t block_index,VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CmdBuildMicromapsEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) { }
static VKAPI_ATTR void VKAPI_CALL BuildMicromapsEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) { }
static VKAPI_ATTR void VKAPI_CALL CopyMicromapEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CopyMicromapToMemoryEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CopyMemoryToMicromapEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL WriteMicromapsPropertiesEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapToMemoryEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToMicromapEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteMicromapsPropertiesEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMicromapCompatibilityEXT_PostCall(uint64_t block_index,VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) { }
static VKAPI_ATTR void VKAPI_CALL GetMicromapBuildSizesEXT_PostCall(uint64_t block_index,VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT* pBuildInfo, VkMicromapBuildSizesInfoEXT* pSizeInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawClusterHUAWEI_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawClusterIndirectHUAWEI_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) { }
static VKAPI_ATTR void VKAPI_CALL SetDeviceMemoryPriorityEXT_PostCall(uint64_t block_index,VkDevice device, VkDeviceMemory memory, float priority) { }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall(uint64_t block_index,VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping) { }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetHostMappingVALVE_PostCall(uint64_t block_index,VkDevice device, VkDescriptorSet descriptorSet, void** ppData) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetTessellationDomainOriginEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthClampEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPolygonModeEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationSamplesEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleMaskEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples, const VkSampleMask* pSampleMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToCoverageEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToOneEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEquationEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteMaskEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationStreamEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t rasterizationStream) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetConservativeRasterizationModeEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendAdvancedEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetProvokingVertexModeEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineRasterizationModeEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEnableEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipNegativeOneToOneEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingEnableNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportSwizzleNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorEnableNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorLocationNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationModeNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableEnableNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetShadingRateImageEnableNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRepresentativeFragmentTestEnableNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageReductionModeNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode) { }
static VKAPI_ATTR void VKAPI_CALL GetShaderModuleIdentifierEXT_PostCall(uint64_t block_index,VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier) { }
static VKAPI_ATTR void VKAPI_CALL GetShaderModuleCreateInfoIdentifierEXT_PostCall(uint64_t block_index,VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall(uint64_t block_index, VkResult result, VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateOpticalFlowSessionNV_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession) { }
static VKAPI_ATTR void VKAPI_CALL DestroyOpticalFlowSessionNV_PostCall(uint64_t block_index,VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL BindOpticalFlowSessionImageNV_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout) { }
static VKAPI_ATTR void VKAPI_CALL CmdOpticalFlowExecuteNV_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo) { }
static VKAPI_ATTR void VKAPI_CALL CreateShadersEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t createInfoCount, const VkShaderCreateInfoEXT* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkShaderEXT* pShaders) { }
static VKAPI_ATTR void VKAPI_CALL DestroyShaderEXT_PostCall(uint64_t block_index,VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetShaderBinaryDataEXT_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkShaderEXT shader, size_t* pDataSize, void* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindShadersEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) { }
static VKAPI_ATTR void VKAPI_CALL GetFramebufferTilePropertiesQCOM_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDynamicRenderingTilePropertiesQCOM_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateAccelerationStructureKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure) { }
static VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureKHR_PostCall(uint64_t block_index,VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) { }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresIndirectKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts) { }
static VKAPI_ATTR void VKAPI_CALL BuildAccelerationStructuresKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) { }
static VKAPI_ATTR void VKAPI_CALL CopyAccelerationStructureKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CopyAccelerationStructureToMemoryKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CopyMemoryToAccelerationStructureKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL WriteAccelerationStructuresPropertiesKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureToMemoryKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToAccelerationStructureKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureDeviceAddressKHR_PostCall(uint64_t block_index, VkDeviceAddress result, VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceAccelerationStructureCompatibilityKHR_PostCall(uint64_t block_index,VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) { }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureBuildSizesKHR_PostCall(uint64_t block_index,VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) { }
static VKAPI_ATTR void VKAPI_CALL CreateRayTracingPipelinesKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) { }
static VKAPI_ATTR void VKAPI_CALL GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall(uint64_t block_index, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirectKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) { }
static VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupStackSizeKHR_PostCall(uint64_t block_index, VkDeviceSize result, VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRayTracingPipelineStackSizeKHR_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountEXT_PostCall(uint64_t block_index,VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
GFXRECON_END_NAMESPACE(noop)

struct plugin_func_table_post
{
    PFN_CreateInstance_PostCall CreateInstance_PostCall { noop::CreateInstance_PostCall };
    PFN_DestroyInstance_PostCall DestroyInstance_PostCall { noop::DestroyInstance_PostCall };
    PFN_EnumeratePhysicalDevices_PostCall EnumeratePhysicalDevices_PostCall { noop::EnumeratePhysicalDevices_PostCall };
    PFN_GetPhysicalDeviceFeatures_PostCall GetPhysicalDeviceFeatures_PostCall { noop::GetPhysicalDeviceFeatures_PostCall };
    PFN_GetPhysicalDeviceFormatProperties_PostCall GetPhysicalDeviceFormatProperties_PostCall { noop::GetPhysicalDeviceFormatProperties_PostCall };
    PFN_GetPhysicalDeviceImageFormatProperties_PostCall GetPhysicalDeviceImageFormatProperties_PostCall { noop::GetPhysicalDeviceImageFormatProperties_PostCall };
    PFN_GetPhysicalDeviceProperties_PostCall GetPhysicalDeviceProperties_PostCall { noop::GetPhysicalDeviceProperties_PostCall };
    PFN_GetPhysicalDeviceQueueFamilyProperties_PostCall GetPhysicalDeviceQueueFamilyProperties_PostCall { noop::GetPhysicalDeviceQueueFamilyProperties_PostCall };
    PFN_GetPhysicalDeviceMemoryProperties_PostCall GetPhysicalDeviceMemoryProperties_PostCall { noop::GetPhysicalDeviceMemoryProperties_PostCall };
    PFN_GetInstanceProcAddr_PostCall GetInstanceProcAddr_PostCall { noop::GetInstanceProcAddr_PostCall };
    PFN_GetDeviceProcAddr_PostCall GetDeviceProcAddr_PostCall { noop::GetDeviceProcAddr_PostCall };
    PFN_CreateDevice_PostCall CreateDevice_PostCall { noop::CreateDevice_PostCall };
    PFN_DestroyDevice_PostCall DestroyDevice_PostCall { noop::DestroyDevice_PostCall };
    PFN_EnumerateInstanceExtensionProperties_PostCall EnumerateInstanceExtensionProperties_PostCall { noop::EnumerateInstanceExtensionProperties_PostCall };
    PFN_EnumerateDeviceExtensionProperties_PostCall EnumerateDeviceExtensionProperties_PostCall { noop::EnumerateDeviceExtensionProperties_PostCall };
    PFN_EnumerateInstanceLayerProperties_PostCall EnumerateInstanceLayerProperties_PostCall { noop::EnumerateInstanceLayerProperties_PostCall };
    PFN_EnumerateDeviceLayerProperties_PostCall EnumerateDeviceLayerProperties_PostCall { noop::EnumerateDeviceLayerProperties_PostCall };
    PFN_GetDeviceQueue_PostCall GetDeviceQueue_PostCall { noop::GetDeviceQueue_PostCall };
    PFN_QueueSubmit_PostCall QueueSubmit_PostCall { noop::QueueSubmit_PostCall };
    PFN_QueueWaitIdle_PostCall QueueWaitIdle_PostCall { noop::QueueWaitIdle_PostCall };
    PFN_DeviceWaitIdle_PostCall DeviceWaitIdle_PostCall { noop::DeviceWaitIdle_PostCall };
    PFN_AllocateMemory_PostCall AllocateMemory_PostCall { noop::AllocateMemory_PostCall };
    PFN_FreeMemory_PostCall FreeMemory_PostCall { noop::FreeMemory_PostCall };
    PFN_MapMemory_PostCall MapMemory_PostCall { noop::MapMemory_PostCall };
    PFN_UnmapMemory_PostCall UnmapMemory_PostCall { noop::UnmapMemory_PostCall };
    PFN_FlushMappedMemoryRanges_PostCall FlushMappedMemoryRanges_PostCall { noop::FlushMappedMemoryRanges_PostCall };
    PFN_InvalidateMappedMemoryRanges_PostCall InvalidateMappedMemoryRanges_PostCall { noop::InvalidateMappedMemoryRanges_PostCall };
    PFN_GetDeviceMemoryCommitment_PostCall GetDeviceMemoryCommitment_PostCall { noop::GetDeviceMemoryCommitment_PostCall };
    PFN_BindBufferMemory_PostCall BindBufferMemory_PostCall { noop::BindBufferMemory_PostCall };
    PFN_BindImageMemory_PostCall BindImageMemory_PostCall { noop::BindImageMemory_PostCall };
    PFN_GetBufferMemoryRequirements_PostCall GetBufferMemoryRequirements_PostCall { noop::GetBufferMemoryRequirements_PostCall };
    PFN_GetImageMemoryRequirements_PostCall GetImageMemoryRequirements_PostCall { noop::GetImageMemoryRequirements_PostCall };
    PFN_GetImageSparseMemoryRequirements_PostCall GetImageSparseMemoryRequirements_PostCall { noop::GetImageSparseMemoryRequirements_PostCall };
    PFN_GetPhysicalDeviceSparseImageFormatProperties_PostCall GetPhysicalDeviceSparseImageFormatProperties_PostCall { noop::GetPhysicalDeviceSparseImageFormatProperties_PostCall };
    PFN_QueueBindSparse_PostCall QueueBindSparse_PostCall { noop::QueueBindSparse_PostCall };
    PFN_CreateFence_PostCall CreateFence_PostCall { noop::CreateFence_PostCall };
    PFN_DestroyFence_PostCall DestroyFence_PostCall { noop::DestroyFence_PostCall };
    PFN_ResetFences_PostCall ResetFences_PostCall { noop::ResetFences_PostCall };
    PFN_GetFenceStatus_PostCall GetFenceStatus_PostCall { noop::GetFenceStatus_PostCall };
    PFN_WaitForFences_PostCall WaitForFences_PostCall { noop::WaitForFences_PostCall };
    PFN_CreateSemaphore_PostCall CreateSemaphore_PostCall { noop::CreateSemaphore_PostCall };
    PFN_DestroySemaphore_PostCall DestroySemaphore_PostCall { noop::DestroySemaphore_PostCall };
    PFN_CreateEvent_PostCall CreateEvent_PostCall { noop::CreateEvent_PostCall };
    PFN_DestroyEvent_PostCall DestroyEvent_PostCall { noop::DestroyEvent_PostCall };
    PFN_GetEventStatus_PostCall GetEventStatus_PostCall { noop::GetEventStatus_PostCall };
    PFN_SetEvent_PostCall SetEvent_PostCall { noop::SetEvent_PostCall };
    PFN_ResetEvent_PostCall ResetEvent_PostCall { noop::ResetEvent_PostCall };
    PFN_CreateQueryPool_PostCall CreateQueryPool_PostCall { noop::CreateQueryPool_PostCall };
    PFN_DestroyQueryPool_PostCall DestroyQueryPool_PostCall { noop::DestroyQueryPool_PostCall };
    PFN_GetQueryPoolResults_PostCall GetQueryPoolResults_PostCall { noop::GetQueryPoolResults_PostCall };
    PFN_CreateBuffer_PostCall CreateBuffer_PostCall { noop::CreateBuffer_PostCall };
    PFN_DestroyBuffer_PostCall DestroyBuffer_PostCall { noop::DestroyBuffer_PostCall };
    PFN_CreateBufferView_PostCall CreateBufferView_PostCall { noop::CreateBufferView_PostCall };
    PFN_DestroyBufferView_PostCall DestroyBufferView_PostCall { noop::DestroyBufferView_PostCall };
    PFN_CreateImage_PostCall CreateImage_PostCall { noop::CreateImage_PostCall };
    PFN_DestroyImage_PostCall DestroyImage_PostCall { noop::DestroyImage_PostCall };
    PFN_GetImageSubresourceLayout_PostCall GetImageSubresourceLayout_PostCall { noop::GetImageSubresourceLayout_PostCall };
    PFN_CreateImageView_PostCall CreateImageView_PostCall { noop::CreateImageView_PostCall };
    PFN_DestroyImageView_PostCall DestroyImageView_PostCall { noop::DestroyImageView_PostCall };
    PFN_CreateShaderModule_PostCall CreateShaderModule_PostCall { noop::CreateShaderModule_PostCall };
    PFN_DestroyShaderModule_PostCall DestroyShaderModule_PostCall { noop::DestroyShaderModule_PostCall };
    PFN_CreatePipelineCache_PostCall CreatePipelineCache_PostCall { noop::CreatePipelineCache_PostCall };
    PFN_DestroyPipelineCache_PostCall DestroyPipelineCache_PostCall { noop::DestroyPipelineCache_PostCall };
    PFN_GetPipelineCacheData_PostCall GetPipelineCacheData_PostCall { noop::GetPipelineCacheData_PostCall };
    PFN_MergePipelineCaches_PostCall MergePipelineCaches_PostCall { noop::MergePipelineCaches_PostCall };
    PFN_CreateGraphicsPipelines_PostCall CreateGraphicsPipelines_PostCall { noop::CreateGraphicsPipelines_PostCall };
    PFN_CreateComputePipelines_PostCall CreateComputePipelines_PostCall { noop::CreateComputePipelines_PostCall };
    PFN_DestroyPipeline_PostCall DestroyPipeline_PostCall { noop::DestroyPipeline_PostCall };
    PFN_CreatePipelineLayout_PostCall CreatePipelineLayout_PostCall { noop::CreatePipelineLayout_PostCall };
    PFN_DestroyPipelineLayout_PostCall DestroyPipelineLayout_PostCall { noop::DestroyPipelineLayout_PostCall };
    PFN_CreateSampler_PostCall CreateSampler_PostCall { noop::CreateSampler_PostCall };
    PFN_DestroySampler_PostCall DestroySampler_PostCall { noop::DestroySampler_PostCall };
    PFN_CreateDescriptorSetLayout_PostCall CreateDescriptorSetLayout_PostCall { noop::CreateDescriptorSetLayout_PostCall };
    PFN_DestroyDescriptorSetLayout_PostCall DestroyDescriptorSetLayout_PostCall { noop::DestroyDescriptorSetLayout_PostCall };
    PFN_CreateDescriptorPool_PostCall CreateDescriptorPool_PostCall { noop::CreateDescriptorPool_PostCall };
    PFN_DestroyDescriptorPool_PostCall DestroyDescriptorPool_PostCall { noop::DestroyDescriptorPool_PostCall };
    PFN_ResetDescriptorPool_PostCall ResetDescriptorPool_PostCall { noop::ResetDescriptorPool_PostCall };
    PFN_AllocateDescriptorSets_PostCall AllocateDescriptorSets_PostCall { noop::AllocateDescriptorSets_PostCall };
    PFN_FreeDescriptorSets_PostCall FreeDescriptorSets_PostCall { noop::FreeDescriptorSets_PostCall };
    PFN_UpdateDescriptorSets_PostCall UpdateDescriptorSets_PostCall { noop::UpdateDescriptorSets_PostCall };
    PFN_CreateFramebuffer_PostCall CreateFramebuffer_PostCall { noop::CreateFramebuffer_PostCall };
    PFN_DestroyFramebuffer_PostCall DestroyFramebuffer_PostCall { noop::DestroyFramebuffer_PostCall };
    PFN_CreateRenderPass_PostCall CreateRenderPass_PostCall { noop::CreateRenderPass_PostCall };
    PFN_DestroyRenderPass_PostCall DestroyRenderPass_PostCall { noop::DestroyRenderPass_PostCall };
    PFN_GetRenderAreaGranularity_PostCall GetRenderAreaGranularity_PostCall { noop::GetRenderAreaGranularity_PostCall };
    PFN_CreateCommandPool_PostCall CreateCommandPool_PostCall { noop::CreateCommandPool_PostCall };
    PFN_DestroyCommandPool_PostCall DestroyCommandPool_PostCall { noop::DestroyCommandPool_PostCall };
    PFN_ResetCommandPool_PostCall ResetCommandPool_PostCall { noop::ResetCommandPool_PostCall };
    PFN_AllocateCommandBuffers_PostCall AllocateCommandBuffers_PostCall { noop::AllocateCommandBuffers_PostCall };
    PFN_FreeCommandBuffers_PostCall FreeCommandBuffers_PostCall { noop::FreeCommandBuffers_PostCall };
    PFN_BeginCommandBuffer_PostCall BeginCommandBuffer_PostCall { noop::BeginCommandBuffer_PostCall };
    PFN_EndCommandBuffer_PostCall EndCommandBuffer_PostCall { noop::EndCommandBuffer_PostCall };
    PFN_ResetCommandBuffer_PostCall ResetCommandBuffer_PostCall { noop::ResetCommandBuffer_PostCall };
    PFN_CmdBindPipeline_PostCall CmdBindPipeline_PostCall { noop::CmdBindPipeline_PostCall };
    PFN_CmdSetViewport_PostCall CmdSetViewport_PostCall { noop::CmdSetViewport_PostCall };
    PFN_CmdSetScissor_PostCall CmdSetScissor_PostCall { noop::CmdSetScissor_PostCall };
    PFN_CmdSetLineWidth_PostCall CmdSetLineWidth_PostCall { noop::CmdSetLineWidth_PostCall };
    PFN_CmdSetDepthBias_PostCall CmdSetDepthBias_PostCall { noop::CmdSetDepthBias_PostCall };
    PFN_CmdSetBlendConstants_PostCall CmdSetBlendConstants_PostCall { noop::CmdSetBlendConstants_PostCall };
    PFN_CmdSetDepthBounds_PostCall CmdSetDepthBounds_PostCall { noop::CmdSetDepthBounds_PostCall };
    PFN_CmdSetStencilCompareMask_PostCall CmdSetStencilCompareMask_PostCall { noop::CmdSetStencilCompareMask_PostCall };
    PFN_CmdSetStencilWriteMask_PostCall CmdSetStencilWriteMask_PostCall { noop::CmdSetStencilWriteMask_PostCall };
    PFN_CmdSetStencilReference_PostCall CmdSetStencilReference_PostCall { noop::CmdSetStencilReference_PostCall };
    PFN_CmdBindDescriptorSets_PostCall CmdBindDescriptorSets_PostCall { noop::CmdBindDescriptorSets_PostCall };
    PFN_CmdBindIndexBuffer_PostCall CmdBindIndexBuffer_PostCall { noop::CmdBindIndexBuffer_PostCall };
    PFN_CmdBindVertexBuffers_PostCall CmdBindVertexBuffers_PostCall { noop::CmdBindVertexBuffers_PostCall };
    PFN_CmdDraw_PostCall CmdDraw_PostCall { noop::CmdDraw_PostCall };
    PFN_CmdDrawIndexed_PostCall CmdDrawIndexed_PostCall { noop::CmdDrawIndexed_PostCall };
    PFN_CmdDrawIndirect_PostCall CmdDrawIndirect_PostCall { noop::CmdDrawIndirect_PostCall };
    PFN_CmdDrawIndexedIndirect_PostCall CmdDrawIndexedIndirect_PostCall { noop::CmdDrawIndexedIndirect_PostCall };
    PFN_CmdDispatch_PostCall CmdDispatch_PostCall { noop::CmdDispatch_PostCall };
    PFN_CmdDispatchIndirect_PostCall CmdDispatchIndirect_PostCall { noop::CmdDispatchIndirect_PostCall };
    PFN_CmdCopyBuffer_PostCall CmdCopyBuffer_PostCall { noop::CmdCopyBuffer_PostCall };
    PFN_CmdCopyImage_PostCall CmdCopyImage_PostCall { noop::CmdCopyImage_PostCall };
    PFN_CmdBlitImage_PostCall CmdBlitImage_PostCall { noop::CmdBlitImage_PostCall };
    PFN_CmdCopyBufferToImage_PostCall CmdCopyBufferToImage_PostCall { noop::CmdCopyBufferToImage_PostCall };
    PFN_CmdCopyImageToBuffer_PostCall CmdCopyImageToBuffer_PostCall { noop::CmdCopyImageToBuffer_PostCall };
    PFN_CmdUpdateBuffer_PostCall CmdUpdateBuffer_PostCall { noop::CmdUpdateBuffer_PostCall };
    PFN_CmdFillBuffer_PostCall CmdFillBuffer_PostCall { noop::CmdFillBuffer_PostCall };
    PFN_CmdClearColorImage_PostCall CmdClearColorImage_PostCall { noop::CmdClearColorImage_PostCall };
    PFN_CmdClearDepthStencilImage_PostCall CmdClearDepthStencilImage_PostCall { noop::CmdClearDepthStencilImage_PostCall };
    PFN_CmdClearAttachments_PostCall CmdClearAttachments_PostCall { noop::CmdClearAttachments_PostCall };
    PFN_CmdResolveImage_PostCall CmdResolveImage_PostCall { noop::CmdResolveImage_PostCall };
    PFN_CmdSetEvent_PostCall CmdSetEvent_PostCall { noop::CmdSetEvent_PostCall };
    PFN_CmdResetEvent_PostCall CmdResetEvent_PostCall { noop::CmdResetEvent_PostCall };
    PFN_CmdWaitEvents_PostCall CmdWaitEvents_PostCall { noop::CmdWaitEvents_PostCall };
    PFN_CmdPipelineBarrier_PostCall CmdPipelineBarrier_PostCall { noop::CmdPipelineBarrier_PostCall };
    PFN_CmdBeginQuery_PostCall CmdBeginQuery_PostCall { noop::CmdBeginQuery_PostCall };
    PFN_CmdEndQuery_PostCall CmdEndQuery_PostCall { noop::CmdEndQuery_PostCall };
    PFN_CmdResetQueryPool_PostCall CmdResetQueryPool_PostCall { noop::CmdResetQueryPool_PostCall };
    PFN_CmdWriteTimestamp_PostCall CmdWriteTimestamp_PostCall { noop::CmdWriteTimestamp_PostCall };
    PFN_CmdCopyQueryPoolResults_PostCall CmdCopyQueryPoolResults_PostCall { noop::CmdCopyQueryPoolResults_PostCall };
    PFN_CmdPushConstants_PostCall CmdPushConstants_PostCall { noop::CmdPushConstants_PostCall };
    PFN_CmdBeginRenderPass_PostCall CmdBeginRenderPass_PostCall { noop::CmdBeginRenderPass_PostCall };
    PFN_CmdNextSubpass_PostCall CmdNextSubpass_PostCall { noop::CmdNextSubpass_PostCall };
    PFN_CmdEndRenderPass_PostCall CmdEndRenderPass_PostCall { noop::CmdEndRenderPass_PostCall };
    PFN_CmdExecuteCommands_PostCall CmdExecuteCommands_PostCall { noop::CmdExecuteCommands_PostCall };
    PFN_EnumerateInstanceVersion_PostCall EnumerateInstanceVersion_PostCall { noop::EnumerateInstanceVersion_PostCall };
    PFN_BindBufferMemory2_PostCall BindBufferMemory2_PostCall { noop::BindBufferMemory2_PostCall };
    PFN_BindImageMemory2_PostCall BindImageMemory2_PostCall { noop::BindImageMemory2_PostCall };
    PFN_GetDeviceGroupPeerMemoryFeatures_PostCall GetDeviceGroupPeerMemoryFeatures_PostCall { noop::GetDeviceGroupPeerMemoryFeatures_PostCall };
    PFN_CmdSetDeviceMask_PostCall CmdSetDeviceMask_PostCall { noop::CmdSetDeviceMask_PostCall };
    PFN_CmdDispatchBase_PostCall CmdDispatchBase_PostCall { noop::CmdDispatchBase_PostCall };
    PFN_EnumeratePhysicalDeviceGroups_PostCall EnumeratePhysicalDeviceGroups_PostCall { noop::EnumeratePhysicalDeviceGroups_PostCall };
    PFN_GetImageMemoryRequirements2_PostCall GetImageMemoryRequirements2_PostCall { noop::GetImageMemoryRequirements2_PostCall };
    PFN_GetBufferMemoryRequirements2_PostCall GetBufferMemoryRequirements2_PostCall { noop::GetBufferMemoryRequirements2_PostCall };
    PFN_GetImageSparseMemoryRequirements2_PostCall GetImageSparseMemoryRequirements2_PostCall { noop::GetImageSparseMemoryRequirements2_PostCall };
    PFN_GetPhysicalDeviceFeatures2_PostCall GetPhysicalDeviceFeatures2_PostCall { noop::GetPhysicalDeviceFeatures2_PostCall };
    PFN_GetPhysicalDeviceProperties2_PostCall GetPhysicalDeviceProperties2_PostCall { noop::GetPhysicalDeviceProperties2_PostCall };
    PFN_GetPhysicalDeviceFormatProperties2_PostCall GetPhysicalDeviceFormatProperties2_PostCall { noop::GetPhysicalDeviceFormatProperties2_PostCall };
    PFN_GetPhysicalDeviceImageFormatProperties2_PostCall GetPhysicalDeviceImageFormatProperties2_PostCall { noop::GetPhysicalDeviceImageFormatProperties2_PostCall };
    PFN_GetPhysicalDeviceQueueFamilyProperties2_PostCall GetPhysicalDeviceQueueFamilyProperties2_PostCall { noop::GetPhysicalDeviceQueueFamilyProperties2_PostCall };
    PFN_GetPhysicalDeviceMemoryProperties2_PostCall GetPhysicalDeviceMemoryProperties2_PostCall { noop::GetPhysicalDeviceMemoryProperties2_PostCall };
    PFN_GetPhysicalDeviceSparseImageFormatProperties2_PostCall GetPhysicalDeviceSparseImageFormatProperties2_PostCall { noop::GetPhysicalDeviceSparseImageFormatProperties2_PostCall };
    PFN_TrimCommandPool_PostCall TrimCommandPool_PostCall { noop::TrimCommandPool_PostCall };
    PFN_GetDeviceQueue2_PostCall GetDeviceQueue2_PostCall { noop::GetDeviceQueue2_PostCall };
    PFN_CreateSamplerYcbcrConversion_PostCall CreateSamplerYcbcrConversion_PostCall { noop::CreateSamplerYcbcrConversion_PostCall };
    PFN_DestroySamplerYcbcrConversion_PostCall DestroySamplerYcbcrConversion_PostCall { noop::DestroySamplerYcbcrConversion_PostCall };
    PFN_CreateDescriptorUpdateTemplate_PostCall CreateDescriptorUpdateTemplate_PostCall { noop::CreateDescriptorUpdateTemplate_PostCall };
    PFN_DestroyDescriptorUpdateTemplate_PostCall DestroyDescriptorUpdateTemplate_PostCall { noop::DestroyDescriptorUpdateTemplate_PostCall };
    PFN_UpdateDescriptorSetWithTemplate_PostCall UpdateDescriptorSetWithTemplate_PostCall { noop::UpdateDescriptorSetWithTemplate_PostCall };
    PFN_GetPhysicalDeviceExternalBufferProperties_PostCall GetPhysicalDeviceExternalBufferProperties_PostCall { noop::GetPhysicalDeviceExternalBufferProperties_PostCall };
    PFN_GetPhysicalDeviceExternalFenceProperties_PostCall GetPhysicalDeviceExternalFenceProperties_PostCall { noop::GetPhysicalDeviceExternalFenceProperties_PostCall };
    PFN_GetPhysicalDeviceExternalSemaphoreProperties_PostCall GetPhysicalDeviceExternalSemaphoreProperties_PostCall { noop::GetPhysicalDeviceExternalSemaphoreProperties_PostCall };
    PFN_GetDescriptorSetLayoutSupport_PostCall GetDescriptorSetLayoutSupport_PostCall { noop::GetDescriptorSetLayoutSupport_PostCall };
    PFN_CmdDrawIndirectCount_PostCall CmdDrawIndirectCount_PostCall { noop::CmdDrawIndirectCount_PostCall };
    PFN_CmdDrawIndexedIndirectCount_PostCall CmdDrawIndexedIndirectCount_PostCall { noop::CmdDrawIndexedIndirectCount_PostCall };
    PFN_CreateRenderPass2_PostCall CreateRenderPass2_PostCall { noop::CreateRenderPass2_PostCall };
    PFN_CmdBeginRenderPass2_PostCall CmdBeginRenderPass2_PostCall { noop::CmdBeginRenderPass2_PostCall };
    PFN_CmdNextSubpass2_PostCall CmdNextSubpass2_PostCall { noop::CmdNextSubpass2_PostCall };
    PFN_CmdEndRenderPass2_PostCall CmdEndRenderPass2_PostCall { noop::CmdEndRenderPass2_PostCall };
    PFN_ResetQueryPool_PostCall ResetQueryPool_PostCall { noop::ResetQueryPool_PostCall };
    PFN_GetSemaphoreCounterValue_PostCall GetSemaphoreCounterValue_PostCall { noop::GetSemaphoreCounterValue_PostCall };
    PFN_WaitSemaphores_PostCall WaitSemaphores_PostCall { noop::WaitSemaphores_PostCall };
    PFN_SignalSemaphore_PostCall SignalSemaphore_PostCall { noop::SignalSemaphore_PostCall };
    PFN_GetBufferDeviceAddress_PostCall GetBufferDeviceAddress_PostCall { noop::GetBufferDeviceAddress_PostCall };
    PFN_GetBufferOpaqueCaptureAddress_PostCall GetBufferOpaqueCaptureAddress_PostCall { noop::GetBufferOpaqueCaptureAddress_PostCall };
    PFN_GetDeviceMemoryOpaqueCaptureAddress_PostCall GetDeviceMemoryOpaqueCaptureAddress_PostCall { noop::GetDeviceMemoryOpaqueCaptureAddress_PostCall };
    PFN_GetPhysicalDeviceToolProperties_PostCall GetPhysicalDeviceToolProperties_PostCall { noop::GetPhysicalDeviceToolProperties_PostCall };
    PFN_CreatePrivateDataSlot_PostCall CreatePrivateDataSlot_PostCall { noop::CreatePrivateDataSlot_PostCall };
    PFN_DestroyPrivateDataSlot_PostCall DestroyPrivateDataSlot_PostCall { noop::DestroyPrivateDataSlot_PostCall };
    PFN_SetPrivateData_PostCall SetPrivateData_PostCall { noop::SetPrivateData_PostCall };
    PFN_GetPrivateData_PostCall GetPrivateData_PostCall { noop::GetPrivateData_PostCall };
    PFN_CmdSetEvent2_PostCall CmdSetEvent2_PostCall { noop::CmdSetEvent2_PostCall };
    PFN_CmdResetEvent2_PostCall CmdResetEvent2_PostCall { noop::CmdResetEvent2_PostCall };
    PFN_CmdWaitEvents2_PostCall CmdWaitEvents2_PostCall { noop::CmdWaitEvents2_PostCall };
    PFN_CmdPipelineBarrier2_PostCall CmdPipelineBarrier2_PostCall { noop::CmdPipelineBarrier2_PostCall };
    PFN_CmdWriteTimestamp2_PostCall CmdWriteTimestamp2_PostCall { noop::CmdWriteTimestamp2_PostCall };
    PFN_QueueSubmit2_PostCall QueueSubmit2_PostCall { noop::QueueSubmit2_PostCall };
    PFN_CmdCopyBuffer2_PostCall CmdCopyBuffer2_PostCall { noop::CmdCopyBuffer2_PostCall };
    PFN_CmdCopyImage2_PostCall CmdCopyImage2_PostCall { noop::CmdCopyImage2_PostCall };
    PFN_CmdCopyBufferToImage2_PostCall CmdCopyBufferToImage2_PostCall { noop::CmdCopyBufferToImage2_PostCall };
    PFN_CmdCopyImageToBuffer2_PostCall CmdCopyImageToBuffer2_PostCall { noop::CmdCopyImageToBuffer2_PostCall };
    PFN_CmdBlitImage2_PostCall CmdBlitImage2_PostCall { noop::CmdBlitImage2_PostCall };
    PFN_CmdResolveImage2_PostCall CmdResolveImage2_PostCall { noop::CmdResolveImage2_PostCall };
    PFN_CmdBeginRendering_PostCall CmdBeginRendering_PostCall { noop::CmdBeginRendering_PostCall };
    PFN_CmdEndRendering_PostCall CmdEndRendering_PostCall { noop::CmdEndRendering_PostCall };
    PFN_CmdSetCullMode_PostCall CmdSetCullMode_PostCall { noop::CmdSetCullMode_PostCall };
    PFN_CmdSetFrontFace_PostCall CmdSetFrontFace_PostCall { noop::CmdSetFrontFace_PostCall };
    PFN_CmdSetPrimitiveTopology_PostCall CmdSetPrimitiveTopology_PostCall { noop::CmdSetPrimitiveTopology_PostCall };
    PFN_CmdSetViewportWithCount_PostCall CmdSetViewportWithCount_PostCall { noop::CmdSetViewportWithCount_PostCall };
    PFN_CmdSetScissorWithCount_PostCall CmdSetScissorWithCount_PostCall { noop::CmdSetScissorWithCount_PostCall };
    PFN_CmdBindVertexBuffers2_PostCall CmdBindVertexBuffers2_PostCall { noop::CmdBindVertexBuffers2_PostCall };
    PFN_CmdSetDepthTestEnable_PostCall CmdSetDepthTestEnable_PostCall { noop::CmdSetDepthTestEnable_PostCall };
    PFN_CmdSetDepthWriteEnable_PostCall CmdSetDepthWriteEnable_PostCall { noop::CmdSetDepthWriteEnable_PostCall };
    PFN_CmdSetDepthCompareOp_PostCall CmdSetDepthCompareOp_PostCall { noop::CmdSetDepthCompareOp_PostCall };
    PFN_CmdSetDepthBoundsTestEnable_PostCall CmdSetDepthBoundsTestEnable_PostCall { noop::CmdSetDepthBoundsTestEnable_PostCall };
    PFN_CmdSetStencilTestEnable_PostCall CmdSetStencilTestEnable_PostCall { noop::CmdSetStencilTestEnable_PostCall };
    PFN_CmdSetStencilOp_PostCall CmdSetStencilOp_PostCall { noop::CmdSetStencilOp_PostCall };
    PFN_CmdSetRasterizerDiscardEnable_PostCall CmdSetRasterizerDiscardEnable_PostCall { noop::CmdSetRasterizerDiscardEnable_PostCall };
    PFN_CmdSetDepthBiasEnable_PostCall CmdSetDepthBiasEnable_PostCall { noop::CmdSetDepthBiasEnable_PostCall };
    PFN_CmdSetPrimitiveRestartEnable_PostCall CmdSetPrimitiveRestartEnable_PostCall { noop::CmdSetPrimitiveRestartEnable_PostCall };
    PFN_GetDeviceBufferMemoryRequirements_PostCall GetDeviceBufferMemoryRequirements_PostCall { noop::GetDeviceBufferMemoryRequirements_PostCall };
    PFN_GetDeviceImageMemoryRequirements_PostCall GetDeviceImageMemoryRequirements_PostCall { noop::GetDeviceImageMemoryRequirements_PostCall };
    PFN_GetDeviceImageSparseMemoryRequirements_PostCall GetDeviceImageSparseMemoryRequirements_PostCall { noop::GetDeviceImageSparseMemoryRequirements_PostCall };
    PFN_DestroySurfaceKHR_PostCall DestroySurfaceKHR_PostCall { noop::DestroySurfaceKHR_PostCall };
    PFN_GetPhysicalDeviceSurfaceSupportKHR_PostCall GetPhysicalDeviceSurfaceSupportKHR_PostCall { noop::GetPhysicalDeviceSurfaceSupportKHR_PostCall };
    PFN_GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall { noop::GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall };
    PFN_GetPhysicalDeviceSurfaceFormatsKHR_PostCall GetPhysicalDeviceSurfaceFormatsKHR_PostCall { noop::GetPhysicalDeviceSurfaceFormatsKHR_PostCall };
    PFN_GetPhysicalDeviceSurfacePresentModesKHR_PostCall GetPhysicalDeviceSurfacePresentModesKHR_PostCall { noop::GetPhysicalDeviceSurfacePresentModesKHR_PostCall };
    PFN_CreateSwapchainKHR_PostCall CreateSwapchainKHR_PostCall { noop::CreateSwapchainKHR_PostCall };
    PFN_DestroySwapchainKHR_PostCall DestroySwapchainKHR_PostCall { noop::DestroySwapchainKHR_PostCall };
    PFN_GetSwapchainImagesKHR_PostCall GetSwapchainImagesKHR_PostCall { noop::GetSwapchainImagesKHR_PostCall };
    PFN_AcquireNextImageKHR_PostCall AcquireNextImageKHR_PostCall { noop::AcquireNextImageKHR_PostCall };
    PFN_QueuePresentKHR_PostCall QueuePresentKHR_PostCall { noop::QueuePresentKHR_PostCall };
    PFN_GetDeviceGroupPresentCapabilitiesKHR_PostCall GetDeviceGroupPresentCapabilitiesKHR_PostCall { noop::GetDeviceGroupPresentCapabilitiesKHR_PostCall };
    PFN_GetDeviceGroupSurfacePresentModesKHR_PostCall GetDeviceGroupSurfacePresentModesKHR_PostCall { noop::GetDeviceGroupSurfacePresentModesKHR_PostCall };
    PFN_GetPhysicalDevicePresentRectanglesKHR_PostCall GetPhysicalDevicePresentRectanglesKHR_PostCall { noop::GetPhysicalDevicePresentRectanglesKHR_PostCall };
    PFN_AcquireNextImage2KHR_PostCall AcquireNextImage2KHR_PostCall { noop::AcquireNextImage2KHR_PostCall };
    PFN_GetPhysicalDeviceDisplayPropertiesKHR_PostCall GetPhysicalDeviceDisplayPropertiesKHR_PostCall { noop::GetPhysicalDeviceDisplayPropertiesKHR_PostCall };
    PFN_GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall { noop::GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall };
    PFN_GetDisplayPlaneSupportedDisplaysKHR_PostCall GetDisplayPlaneSupportedDisplaysKHR_PostCall { noop::GetDisplayPlaneSupportedDisplaysKHR_PostCall };
    PFN_GetDisplayModePropertiesKHR_PostCall GetDisplayModePropertiesKHR_PostCall { noop::GetDisplayModePropertiesKHR_PostCall };
    PFN_CreateDisplayModeKHR_PostCall CreateDisplayModeKHR_PostCall { noop::CreateDisplayModeKHR_PostCall };
    PFN_GetDisplayPlaneCapabilitiesKHR_PostCall GetDisplayPlaneCapabilitiesKHR_PostCall { noop::GetDisplayPlaneCapabilitiesKHR_PostCall };
    PFN_CreateDisplayPlaneSurfaceKHR_PostCall CreateDisplayPlaneSurfaceKHR_PostCall { noop::CreateDisplayPlaneSurfaceKHR_PostCall };
    PFN_CreateSharedSwapchainsKHR_PostCall CreateSharedSwapchainsKHR_PostCall { noop::CreateSharedSwapchainsKHR_PostCall };
    PFN_CreateXlibSurfaceKHR_PostCall CreateXlibSurfaceKHR_PostCall { noop::CreateXlibSurfaceKHR_PostCall };
    PFN_GetPhysicalDeviceXlibPresentationSupportKHR_PostCall GetPhysicalDeviceXlibPresentationSupportKHR_PostCall { noop::GetPhysicalDeviceXlibPresentationSupportKHR_PostCall };
    PFN_CreateXcbSurfaceKHR_PostCall CreateXcbSurfaceKHR_PostCall { noop::CreateXcbSurfaceKHR_PostCall };
    PFN_GetPhysicalDeviceXcbPresentationSupportKHR_PostCall GetPhysicalDeviceXcbPresentationSupportKHR_PostCall { noop::GetPhysicalDeviceXcbPresentationSupportKHR_PostCall };
    PFN_CreateWaylandSurfaceKHR_PostCall CreateWaylandSurfaceKHR_PostCall { noop::CreateWaylandSurfaceKHR_PostCall };
    PFN_GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall { noop::GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall };
    PFN_CreateAndroidSurfaceKHR_PostCall CreateAndroidSurfaceKHR_PostCall { noop::CreateAndroidSurfaceKHR_PostCall };
    PFN_CreateWin32SurfaceKHR_PostCall CreateWin32SurfaceKHR_PostCall { noop::CreateWin32SurfaceKHR_PostCall };
    PFN_GetPhysicalDeviceWin32PresentationSupportKHR_PostCall GetPhysicalDeviceWin32PresentationSupportKHR_PostCall { noop::GetPhysicalDeviceWin32PresentationSupportKHR_PostCall };
    PFN_GetPhysicalDeviceVideoCapabilitiesKHR_PostCall GetPhysicalDeviceVideoCapabilitiesKHR_PostCall { noop::GetPhysicalDeviceVideoCapabilitiesKHR_PostCall };
    PFN_GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall { noop::GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall };
    PFN_CreateVideoSessionKHR_PostCall CreateVideoSessionKHR_PostCall { noop::CreateVideoSessionKHR_PostCall };
    PFN_DestroyVideoSessionKHR_PostCall DestroyVideoSessionKHR_PostCall { noop::DestroyVideoSessionKHR_PostCall };
    PFN_GetVideoSessionMemoryRequirementsKHR_PostCall GetVideoSessionMemoryRequirementsKHR_PostCall { noop::GetVideoSessionMemoryRequirementsKHR_PostCall };
    PFN_BindVideoSessionMemoryKHR_PostCall BindVideoSessionMemoryKHR_PostCall { noop::BindVideoSessionMemoryKHR_PostCall };
    PFN_CreateVideoSessionParametersKHR_PostCall CreateVideoSessionParametersKHR_PostCall { noop::CreateVideoSessionParametersKHR_PostCall };
    PFN_UpdateVideoSessionParametersKHR_PostCall UpdateVideoSessionParametersKHR_PostCall { noop::UpdateVideoSessionParametersKHR_PostCall };
    PFN_DestroyVideoSessionParametersKHR_PostCall DestroyVideoSessionParametersKHR_PostCall { noop::DestroyVideoSessionParametersKHR_PostCall };
    PFN_CmdBeginVideoCodingKHR_PostCall CmdBeginVideoCodingKHR_PostCall { noop::CmdBeginVideoCodingKHR_PostCall };
    PFN_CmdEndVideoCodingKHR_PostCall CmdEndVideoCodingKHR_PostCall { noop::CmdEndVideoCodingKHR_PostCall };
    PFN_CmdControlVideoCodingKHR_PostCall CmdControlVideoCodingKHR_PostCall { noop::CmdControlVideoCodingKHR_PostCall };
    PFN_CmdDecodeVideoKHR_PostCall CmdDecodeVideoKHR_PostCall { noop::CmdDecodeVideoKHR_PostCall };
    PFN_CmdBeginRenderingKHR_PostCall CmdBeginRenderingKHR_PostCall { noop::CmdBeginRenderingKHR_PostCall };
    PFN_CmdEndRenderingKHR_PostCall CmdEndRenderingKHR_PostCall { noop::CmdEndRenderingKHR_PostCall };
    PFN_GetPhysicalDeviceFeatures2KHR_PostCall GetPhysicalDeviceFeatures2KHR_PostCall { noop::GetPhysicalDeviceFeatures2KHR_PostCall };
    PFN_GetPhysicalDeviceProperties2KHR_PostCall GetPhysicalDeviceProperties2KHR_PostCall { noop::GetPhysicalDeviceProperties2KHR_PostCall };
    PFN_GetPhysicalDeviceFormatProperties2KHR_PostCall GetPhysicalDeviceFormatProperties2KHR_PostCall { noop::GetPhysicalDeviceFormatProperties2KHR_PostCall };
    PFN_GetPhysicalDeviceImageFormatProperties2KHR_PostCall GetPhysicalDeviceImageFormatProperties2KHR_PostCall { noop::GetPhysicalDeviceImageFormatProperties2KHR_PostCall };
    PFN_GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall { noop::GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall };
    PFN_GetPhysicalDeviceMemoryProperties2KHR_PostCall GetPhysicalDeviceMemoryProperties2KHR_PostCall { noop::GetPhysicalDeviceMemoryProperties2KHR_PostCall };
    PFN_GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall { noop::GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall };
    PFN_GetDeviceGroupPeerMemoryFeaturesKHR_PostCall GetDeviceGroupPeerMemoryFeaturesKHR_PostCall { noop::GetDeviceGroupPeerMemoryFeaturesKHR_PostCall };
    PFN_CmdSetDeviceMaskKHR_PostCall CmdSetDeviceMaskKHR_PostCall { noop::CmdSetDeviceMaskKHR_PostCall };
    PFN_CmdDispatchBaseKHR_PostCall CmdDispatchBaseKHR_PostCall { noop::CmdDispatchBaseKHR_PostCall };
    PFN_TrimCommandPoolKHR_PostCall TrimCommandPoolKHR_PostCall { noop::TrimCommandPoolKHR_PostCall };
    PFN_EnumeratePhysicalDeviceGroupsKHR_PostCall EnumeratePhysicalDeviceGroupsKHR_PostCall { noop::EnumeratePhysicalDeviceGroupsKHR_PostCall };
    PFN_GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall { noop::GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall };
    PFN_GetMemoryWin32HandleKHR_PostCall GetMemoryWin32HandleKHR_PostCall { noop::GetMemoryWin32HandleKHR_PostCall };
    PFN_GetMemoryWin32HandlePropertiesKHR_PostCall GetMemoryWin32HandlePropertiesKHR_PostCall { noop::GetMemoryWin32HandlePropertiesKHR_PostCall };
    PFN_GetMemoryFdKHR_PostCall GetMemoryFdKHR_PostCall { noop::GetMemoryFdKHR_PostCall };
    PFN_GetMemoryFdPropertiesKHR_PostCall GetMemoryFdPropertiesKHR_PostCall { noop::GetMemoryFdPropertiesKHR_PostCall };
    PFN_GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall { noop::GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall };
    PFN_ImportSemaphoreWin32HandleKHR_PostCall ImportSemaphoreWin32HandleKHR_PostCall { noop::ImportSemaphoreWin32HandleKHR_PostCall };
    PFN_GetSemaphoreWin32HandleKHR_PostCall GetSemaphoreWin32HandleKHR_PostCall { noop::GetSemaphoreWin32HandleKHR_PostCall };
    PFN_ImportSemaphoreFdKHR_PostCall ImportSemaphoreFdKHR_PostCall { noop::ImportSemaphoreFdKHR_PostCall };
    PFN_GetSemaphoreFdKHR_PostCall GetSemaphoreFdKHR_PostCall { noop::GetSemaphoreFdKHR_PostCall };
    PFN_CmdPushDescriptorSetKHR_PostCall CmdPushDescriptorSetKHR_PostCall { noop::CmdPushDescriptorSetKHR_PostCall };
    PFN_CmdPushDescriptorSetWithTemplateKHR_PostCall CmdPushDescriptorSetWithTemplateKHR_PostCall { noop::CmdPushDescriptorSetWithTemplateKHR_PostCall };
    PFN_CreateDescriptorUpdateTemplateKHR_PostCall CreateDescriptorUpdateTemplateKHR_PostCall { noop::CreateDescriptorUpdateTemplateKHR_PostCall };
    PFN_DestroyDescriptorUpdateTemplateKHR_PostCall DestroyDescriptorUpdateTemplateKHR_PostCall { noop::DestroyDescriptorUpdateTemplateKHR_PostCall };
    PFN_UpdateDescriptorSetWithTemplateKHR_PostCall UpdateDescriptorSetWithTemplateKHR_PostCall { noop::UpdateDescriptorSetWithTemplateKHR_PostCall };
    PFN_CreateRenderPass2KHR_PostCall CreateRenderPass2KHR_PostCall { noop::CreateRenderPass2KHR_PostCall };
    PFN_CmdBeginRenderPass2KHR_PostCall CmdBeginRenderPass2KHR_PostCall { noop::CmdBeginRenderPass2KHR_PostCall };
    PFN_CmdNextSubpass2KHR_PostCall CmdNextSubpass2KHR_PostCall { noop::CmdNextSubpass2KHR_PostCall };
    PFN_CmdEndRenderPass2KHR_PostCall CmdEndRenderPass2KHR_PostCall { noop::CmdEndRenderPass2KHR_PostCall };
    PFN_GetSwapchainStatusKHR_PostCall GetSwapchainStatusKHR_PostCall { noop::GetSwapchainStatusKHR_PostCall };
    PFN_GetPhysicalDeviceExternalFencePropertiesKHR_PostCall GetPhysicalDeviceExternalFencePropertiesKHR_PostCall { noop::GetPhysicalDeviceExternalFencePropertiesKHR_PostCall };
    PFN_ImportFenceWin32HandleKHR_PostCall ImportFenceWin32HandleKHR_PostCall { noop::ImportFenceWin32HandleKHR_PostCall };
    PFN_GetFenceWin32HandleKHR_PostCall GetFenceWin32HandleKHR_PostCall { noop::GetFenceWin32HandleKHR_PostCall };
    PFN_ImportFenceFdKHR_PostCall ImportFenceFdKHR_PostCall { noop::ImportFenceFdKHR_PostCall };
    PFN_GetFenceFdKHR_PostCall GetFenceFdKHR_PostCall { noop::GetFenceFdKHR_PostCall };
    PFN_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall { noop::EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall };
    PFN_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall { noop::GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall };
    PFN_AcquireProfilingLockKHR_PostCall AcquireProfilingLockKHR_PostCall { noop::AcquireProfilingLockKHR_PostCall };
    PFN_ReleaseProfilingLockKHR_PostCall ReleaseProfilingLockKHR_PostCall { noop::ReleaseProfilingLockKHR_PostCall };
    PFN_GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall { noop::GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall };
    PFN_GetPhysicalDeviceSurfaceFormats2KHR_PostCall GetPhysicalDeviceSurfaceFormats2KHR_PostCall { noop::GetPhysicalDeviceSurfaceFormats2KHR_PostCall };
    PFN_GetPhysicalDeviceDisplayProperties2KHR_PostCall GetPhysicalDeviceDisplayProperties2KHR_PostCall { noop::GetPhysicalDeviceDisplayProperties2KHR_PostCall };
    PFN_GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall { noop::GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall };
    PFN_GetDisplayModeProperties2KHR_PostCall GetDisplayModeProperties2KHR_PostCall { noop::GetDisplayModeProperties2KHR_PostCall };
    PFN_GetDisplayPlaneCapabilities2KHR_PostCall GetDisplayPlaneCapabilities2KHR_PostCall { noop::GetDisplayPlaneCapabilities2KHR_PostCall };
    PFN_GetImageMemoryRequirements2KHR_PostCall GetImageMemoryRequirements2KHR_PostCall { noop::GetImageMemoryRequirements2KHR_PostCall };
    PFN_GetBufferMemoryRequirements2KHR_PostCall GetBufferMemoryRequirements2KHR_PostCall { noop::GetBufferMemoryRequirements2KHR_PostCall };
    PFN_GetImageSparseMemoryRequirements2KHR_PostCall GetImageSparseMemoryRequirements2KHR_PostCall { noop::GetImageSparseMemoryRequirements2KHR_PostCall };
    PFN_CreateSamplerYcbcrConversionKHR_PostCall CreateSamplerYcbcrConversionKHR_PostCall { noop::CreateSamplerYcbcrConversionKHR_PostCall };
    PFN_DestroySamplerYcbcrConversionKHR_PostCall DestroySamplerYcbcrConversionKHR_PostCall { noop::DestroySamplerYcbcrConversionKHR_PostCall };
    PFN_BindBufferMemory2KHR_PostCall BindBufferMemory2KHR_PostCall { noop::BindBufferMemory2KHR_PostCall };
    PFN_BindImageMemory2KHR_PostCall BindImageMemory2KHR_PostCall { noop::BindImageMemory2KHR_PostCall };
    PFN_GetDescriptorSetLayoutSupportKHR_PostCall GetDescriptorSetLayoutSupportKHR_PostCall { noop::GetDescriptorSetLayoutSupportKHR_PostCall };
    PFN_CmdDrawIndirectCountKHR_PostCall CmdDrawIndirectCountKHR_PostCall { noop::CmdDrawIndirectCountKHR_PostCall };
    PFN_CmdDrawIndexedIndirectCountKHR_PostCall CmdDrawIndexedIndirectCountKHR_PostCall { noop::CmdDrawIndexedIndirectCountKHR_PostCall };
    PFN_GetSemaphoreCounterValueKHR_PostCall GetSemaphoreCounterValueKHR_PostCall { noop::GetSemaphoreCounterValueKHR_PostCall };
    PFN_WaitSemaphoresKHR_PostCall WaitSemaphoresKHR_PostCall { noop::WaitSemaphoresKHR_PostCall };
    PFN_SignalSemaphoreKHR_PostCall SignalSemaphoreKHR_PostCall { noop::SignalSemaphoreKHR_PostCall };
    PFN_GetPhysicalDeviceFragmentShadingRatesKHR_PostCall GetPhysicalDeviceFragmentShadingRatesKHR_PostCall { noop::GetPhysicalDeviceFragmentShadingRatesKHR_PostCall };
    PFN_CmdSetFragmentShadingRateKHR_PostCall CmdSetFragmentShadingRateKHR_PostCall { noop::CmdSetFragmentShadingRateKHR_PostCall };
    PFN_WaitForPresentKHR_PostCall WaitForPresentKHR_PostCall { noop::WaitForPresentKHR_PostCall };
    PFN_GetBufferDeviceAddressKHR_PostCall GetBufferDeviceAddressKHR_PostCall { noop::GetBufferDeviceAddressKHR_PostCall };
    PFN_GetBufferOpaqueCaptureAddressKHR_PostCall GetBufferOpaqueCaptureAddressKHR_PostCall { noop::GetBufferOpaqueCaptureAddressKHR_PostCall };
    PFN_GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall { noop::GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall };
    PFN_CreateDeferredOperationKHR_PostCall CreateDeferredOperationKHR_PostCall { noop::CreateDeferredOperationKHR_PostCall };
    PFN_DestroyDeferredOperationKHR_PostCall DestroyDeferredOperationKHR_PostCall { noop::DestroyDeferredOperationKHR_PostCall };
    PFN_GetDeferredOperationMaxConcurrencyKHR_PostCall GetDeferredOperationMaxConcurrencyKHR_PostCall { noop::GetDeferredOperationMaxConcurrencyKHR_PostCall };
    PFN_GetDeferredOperationResultKHR_PostCall GetDeferredOperationResultKHR_PostCall { noop::GetDeferredOperationResultKHR_PostCall };
    PFN_DeferredOperationJoinKHR_PostCall DeferredOperationJoinKHR_PostCall { noop::DeferredOperationJoinKHR_PostCall };
    PFN_GetPipelineExecutablePropertiesKHR_PostCall GetPipelineExecutablePropertiesKHR_PostCall { noop::GetPipelineExecutablePropertiesKHR_PostCall };
    PFN_GetPipelineExecutableStatisticsKHR_PostCall GetPipelineExecutableStatisticsKHR_PostCall { noop::GetPipelineExecutableStatisticsKHR_PostCall };
    PFN_GetPipelineExecutableInternalRepresentationsKHR_PostCall GetPipelineExecutableInternalRepresentationsKHR_PostCall { noop::GetPipelineExecutableInternalRepresentationsKHR_PostCall };
    PFN_MapMemory2KHR_PostCall MapMemory2KHR_PostCall { noop::MapMemory2KHR_PostCall };
    PFN_UnmapMemory2KHR_PostCall UnmapMemory2KHR_PostCall { noop::UnmapMemory2KHR_PostCall };
    PFN_CmdEncodeVideoKHR_PostCall CmdEncodeVideoKHR_PostCall { noop::CmdEncodeVideoKHR_PostCall };
    PFN_CmdSetEvent2KHR_PostCall CmdSetEvent2KHR_PostCall { noop::CmdSetEvent2KHR_PostCall };
    PFN_CmdResetEvent2KHR_PostCall CmdResetEvent2KHR_PostCall { noop::CmdResetEvent2KHR_PostCall };
    PFN_CmdWaitEvents2KHR_PostCall CmdWaitEvents2KHR_PostCall { noop::CmdWaitEvents2KHR_PostCall };
    PFN_CmdPipelineBarrier2KHR_PostCall CmdPipelineBarrier2KHR_PostCall { noop::CmdPipelineBarrier2KHR_PostCall };
    PFN_CmdWriteTimestamp2KHR_PostCall CmdWriteTimestamp2KHR_PostCall { noop::CmdWriteTimestamp2KHR_PostCall };
    PFN_QueueSubmit2KHR_PostCall QueueSubmit2KHR_PostCall { noop::QueueSubmit2KHR_PostCall };
    PFN_CmdWriteBufferMarker2AMD_PostCall CmdWriteBufferMarker2AMD_PostCall { noop::CmdWriteBufferMarker2AMD_PostCall };
    PFN_GetQueueCheckpointData2NV_PostCall GetQueueCheckpointData2NV_PostCall { noop::GetQueueCheckpointData2NV_PostCall };
    PFN_CmdCopyBuffer2KHR_PostCall CmdCopyBuffer2KHR_PostCall { noop::CmdCopyBuffer2KHR_PostCall };
    PFN_CmdCopyImage2KHR_PostCall CmdCopyImage2KHR_PostCall { noop::CmdCopyImage2KHR_PostCall };
    PFN_CmdCopyBufferToImage2KHR_PostCall CmdCopyBufferToImage2KHR_PostCall { noop::CmdCopyBufferToImage2KHR_PostCall };
    PFN_CmdCopyImageToBuffer2KHR_PostCall CmdCopyImageToBuffer2KHR_PostCall { noop::CmdCopyImageToBuffer2KHR_PostCall };
    PFN_CmdBlitImage2KHR_PostCall CmdBlitImage2KHR_PostCall { noop::CmdBlitImage2KHR_PostCall };
    PFN_CmdResolveImage2KHR_PostCall CmdResolveImage2KHR_PostCall { noop::CmdResolveImage2KHR_PostCall };
    PFN_CmdTraceRaysIndirect2KHR_PostCall CmdTraceRaysIndirect2KHR_PostCall { noop::CmdTraceRaysIndirect2KHR_PostCall };
    PFN_GetDeviceBufferMemoryRequirementsKHR_PostCall GetDeviceBufferMemoryRequirementsKHR_PostCall { noop::GetDeviceBufferMemoryRequirementsKHR_PostCall };
    PFN_GetDeviceImageMemoryRequirementsKHR_PostCall GetDeviceImageMemoryRequirementsKHR_PostCall { noop::GetDeviceImageMemoryRequirementsKHR_PostCall };
    PFN_GetDeviceImageSparseMemoryRequirementsKHR_PostCall GetDeviceImageSparseMemoryRequirementsKHR_PostCall { noop::GetDeviceImageSparseMemoryRequirementsKHR_PostCall };
    PFN_CreateDebugReportCallbackEXT_PostCall CreateDebugReportCallbackEXT_PostCall { noop::CreateDebugReportCallbackEXT_PostCall };
    PFN_DestroyDebugReportCallbackEXT_PostCall DestroyDebugReportCallbackEXT_PostCall { noop::DestroyDebugReportCallbackEXT_PostCall };
    PFN_DebugReportMessageEXT_PostCall DebugReportMessageEXT_PostCall { noop::DebugReportMessageEXT_PostCall };
    PFN_DebugMarkerSetObjectTagEXT_PostCall DebugMarkerSetObjectTagEXT_PostCall { noop::DebugMarkerSetObjectTagEXT_PostCall };
    PFN_DebugMarkerSetObjectNameEXT_PostCall DebugMarkerSetObjectNameEXT_PostCall { noop::DebugMarkerSetObjectNameEXT_PostCall };
    PFN_CmdDebugMarkerBeginEXT_PostCall CmdDebugMarkerBeginEXT_PostCall { noop::CmdDebugMarkerBeginEXT_PostCall };
    PFN_CmdDebugMarkerEndEXT_PostCall CmdDebugMarkerEndEXT_PostCall { noop::CmdDebugMarkerEndEXT_PostCall };
    PFN_CmdDebugMarkerInsertEXT_PostCall CmdDebugMarkerInsertEXT_PostCall { noop::CmdDebugMarkerInsertEXT_PostCall };
    PFN_CmdBindTransformFeedbackBuffersEXT_PostCall CmdBindTransformFeedbackBuffersEXT_PostCall { noop::CmdBindTransformFeedbackBuffersEXT_PostCall };
    PFN_CmdBeginTransformFeedbackEXT_PostCall CmdBeginTransformFeedbackEXT_PostCall { noop::CmdBeginTransformFeedbackEXT_PostCall };
    PFN_CmdEndTransformFeedbackEXT_PostCall CmdEndTransformFeedbackEXT_PostCall { noop::CmdEndTransformFeedbackEXT_PostCall };
    PFN_CmdBeginQueryIndexedEXT_PostCall CmdBeginQueryIndexedEXT_PostCall { noop::CmdBeginQueryIndexedEXT_PostCall };
    PFN_CmdEndQueryIndexedEXT_PostCall CmdEndQueryIndexedEXT_PostCall { noop::CmdEndQueryIndexedEXT_PostCall };
    PFN_CmdDrawIndirectByteCountEXT_PostCall CmdDrawIndirectByteCountEXT_PostCall { noop::CmdDrawIndirectByteCountEXT_PostCall };
    PFN_GetImageViewHandleNVX_PostCall GetImageViewHandleNVX_PostCall { noop::GetImageViewHandleNVX_PostCall };
    PFN_GetImageViewAddressNVX_PostCall GetImageViewAddressNVX_PostCall { noop::GetImageViewAddressNVX_PostCall };
    PFN_CmdDrawIndirectCountAMD_PostCall CmdDrawIndirectCountAMD_PostCall { noop::CmdDrawIndirectCountAMD_PostCall };
    PFN_CmdDrawIndexedIndirectCountAMD_PostCall CmdDrawIndexedIndirectCountAMD_PostCall { noop::CmdDrawIndexedIndirectCountAMD_PostCall };
    PFN_GetShaderInfoAMD_PostCall GetShaderInfoAMD_PostCall { noop::GetShaderInfoAMD_PostCall };
    PFN_CreateStreamDescriptorSurfaceGGP_PostCall CreateStreamDescriptorSurfaceGGP_PostCall { noop::CreateStreamDescriptorSurfaceGGP_PostCall };
    PFN_GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall { noop::GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall };
    PFN_GetMemoryWin32HandleNV_PostCall GetMemoryWin32HandleNV_PostCall { noop::GetMemoryWin32HandleNV_PostCall };
    PFN_CreateViSurfaceNN_PostCall CreateViSurfaceNN_PostCall { noop::CreateViSurfaceNN_PostCall };
    PFN_CmdBeginConditionalRenderingEXT_PostCall CmdBeginConditionalRenderingEXT_PostCall { noop::CmdBeginConditionalRenderingEXT_PostCall };
    PFN_CmdEndConditionalRenderingEXT_PostCall CmdEndConditionalRenderingEXT_PostCall { noop::CmdEndConditionalRenderingEXT_PostCall };
    PFN_CmdSetViewportWScalingNV_PostCall CmdSetViewportWScalingNV_PostCall { noop::CmdSetViewportWScalingNV_PostCall };
    PFN_ReleaseDisplayEXT_PostCall ReleaseDisplayEXT_PostCall { noop::ReleaseDisplayEXT_PostCall };
    PFN_AcquireXlibDisplayEXT_PostCall AcquireXlibDisplayEXT_PostCall { noop::AcquireXlibDisplayEXT_PostCall };
    PFN_GetRandROutputDisplayEXT_PostCall GetRandROutputDisplayEXT_PostCall { noop::GetRandROutputDisplayEXT_PostCall };
    PFN_GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall { noop::GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall };
    PFN_DisplayPowerControlEXT_PostCall DisplayPowerControlEXT_PostCall { noop::DisplayPowerControlEXT_PostCall };
    PFN_RegisterDeviceEventEXT_PostCall RegisterDeviceEventEXT_PostCall { noop::RegisterDeviceEventEXT_PostCall };
    PFN_RegisterDisplayEventEXT_PostCall RegisterDisplayEventEXT_PostCall { noop::RegisterDisplayEventEXT_PostCall };
    PFN_GetSwapchainCounterEXT_PostCall GetSwapchainCounterEXT_PostCall { noop::GetSwapchainCounterEXT_PostCall };
    PFN_GetRefreshCycleDurationGOOGLE_PostCall GetRefreshCycleDurationGOOGLE_PostCall { noop::GetRefreshCycleDurationGOOGLE_PostCall };
    PFN_GetPastPresentationTimingGOOGLE_PostCall GetPastPresentationTimingGOOGLE_PostCall { noop::GetPastPresentationTimingGOOGLE_PostCall };
    PFN_CmdSetDiscardRectangleEXT_PostCall CmdSetDiscardRectangleEXT_PostCall { noop::CmdSetDiscardRectangleEXT_PostCall };
    PFN_CmdSetDiscardRectangleEnableEXT_PostCall CmdSetDiscardRectangleEnableEXT_PostCall { noop::CmdSetDiscardRectangleEnableEXT_PostCall };
    PFN_CmdSetDiscardRectangleModeEXT_PostCall CmdSetDiscardRectangleModeEXT_PostCall { noop::CmdSetDiscardRectangleModeEXT_PostCall };
    PFN_SetHdrMetadataEXT_PostCall SetHdrMetadataEXT_PostCall { noop::SetHdrMetadataEXT_PostCall };
    PFN_CreateIOSSurfaceMVK_PostCall CreateIOSSurfaceMVK_PostCall { noop::CreateIOSSurfaceMVK_PostCall };
    PFN_CreateMacOSSurfaceMVK_PostCall CreateMacOSSurfaceMVK_PostCall { noop::CreateMacOSSurfaceMVK_PostCall };
    PFN_SetDebugUtilsObjectNameEXT_PostCall SetDebugUtilsObjectNameEXT_PostCall { noop::SetDebugUtilsObjectNameEXT_PostCall };
    PFN_SetDebugUtilsObjectTagEXT_PostCall SetDebugUtilsObjectTagEXT_PostCall { noop::SetDebugUtilsObjectTagEXT_PostCall };
    PFN_QueueBeginDebugUtilsLabelEXT_PostCall QueueBeginDebugUtilsLabelEXT_PostCall { noop::QueueBeginDebugUtilsLabelEXT_PostCall };
    PFN_QueueEndDebugUtilsLabelEXT_PostCall QueueEndDebugUtilsLabelEXT_PostCall { noop::QueueEndDebugUtilsLabelEXT_PostCall };
    PFN_QueueInsertDebugUtilsLabelEXT_PostCall QueueInsertDebugUtilsLabelEXT_PostCall { noop::QueueInsertDebugUtilsLabelEXT_PostCall };
    PFN_CmdBeginDebugUtilsLabelEXT_PostCall CmdBeginDebugUtilsLabelEXT_PostCall { noop::CmdBeginDebugUtilsLabelEXT_PostCall };
    PFN_CmdEndDebugUtilsLabelEXT_PostCall CmdEndDebugUtilsLabelEXT_PostCall { noop::CmdEndDebugUtilsLabelEXT_PostCall };
    PFN_CmdInsertDebugUtilsLabelEXT_PostCall CmdInsertDebugUtilsLabelEXT_PostCall { noop::CmdInsertDebugUtilsLabelEXT_PostCall };
    PFN_CreateDebugUtilsMessengerEXT_PostCall CreateDebugUtilsMessengerEXT_PostCall { noop::CreateDebugUtilsMessengerEXT_PostCall };
    PFN_DestroyDebugUtilsMessengerEXT_PostCall DestroyDebugUtilsMessengerEXT_PostCall { noop::DestroyDebugUtilsMessengerEXT_PostCall };
    PFN_SubmitDebugUtilsMessageEXT_PostCall SubmitDebugUtilsMessageEXT_PostCall { noop::SubmitDebugUtilsMessageEXT_PostCall };
    PFN_GetAndroidHardwareBufferPropertiesANDROID_PostCall GetAndroidHardwareBufferPropertiesANDROID_PostCall { noop::GetAndroidHardwareBufferPropertiesANDROID_PostCall };
    PFN_GetMemoryAndroidHardwareBufferANDROID_PostCall GetMemoryAndroidHardwareBufferANDROID_PostCall { noop::GetMemoryAndroidHardwareBufferANDROID_PostCall };
    PFN_CmdSetSampleLocationsEXT_PostCall CmdSetSampleLocationsEXT_PostCall { noop::CmdSetSampleLocationsEXT_PostCall };
    PFN_GetPhysicalDeviceMultisamplePropertiesEXT_PostCall GetPhysicalDeviceMultisamplePropertiesEXT_PostCall { noop::GetPhysicalDeviceMultisamplePropertiesEXT_PostCall };
    PFN_GetImageDrmFormatModifierPropertiesEXT_PostCall GetImageDrmFormatModifierPropertiesEXT_PostCall { noop::GetImageDrmFormatModifierPropertiesEXT_PostCall };
    PFN_CreateValidationCacheEXT_PostCall CreateValidationCacheEXT_PostCall { noop::CreateValidationCacheEXT_PostCall };
    PFN_DestroyValidationCacheEXT_PostCall DestroyValidationCacheEXT_PostCall { noop::DestroyValidationCacheEXT_PostCall };
    PFN_MergeValidationCachesEXT_PostCall MergeValidationCachesEXT_PostCall { noop::MergeValidationCachesEXT_PostCall };
    PFN_GetValidationCacheDataEXT_PostCall GetValidationCacheDataEXT_PostCall { noop::GetValidationCacheDataEXT_PostCall };
    PFN_CmdBindShadingRateImageNV_PostCall CmdBindShadingRateImageNV_PostCall { noop::CmdBindShadingRateImageNV_PostCall };
    PFN_CmdSetViewportShadingRatePaletteNV_PostCall CmdSetViewportShadingRatePaletteNV_PostCall { noop::CmdSetViewportShadingRatePaletteNV_PostCall };
    PFN_CmdSetCoarseSampleOrderNV_PostCall CmdSetCoarseSampleOrderNV_PostCall { noop::CmdSetCoarseSampleOrderNV_PostCall };
    PFN_CreateAccelerationStructureNV_PostCall CreateAccelerationStructureNV_PostCall { noop::CreateAccelerationStructureNV_PostCall };
    PFN_DestroyAccelerationStructureNV_PostCall DestroyAccelerationStructureNV_PostCall { noop::DestroyAccelerationStructureNV_PostCall };
    PFN_GetAccelerationStructureMemoryRequirementsNV_PostCall GetAccelerationStructureMemoryRequirementsNV_PostCall { noop::GetAccelerationStructureMemoryRequirementsNV_PostCall };
    PFN_BindAccelerationStructureMemoryNV_PostCall BindAccelerationStructureMemoryNV_PostCall { noop::BindAccelerationStructureMemoryNV_PostCall };
    PFN_CmdBuildAccelerationStructureNV_PostCall CmdBuildAccelerationStructureNV_PostCall { noop::CmdBuildAccelerationStructureNV_PostCall };
    PFN_CmdCopyAccelerationStructureNV_PostCall CmdCopyAccelerationStructureNV_PostCall { noop::CmdCopyAccelerationStructureNV_PostCall };
    PFN_CmdTraceRaysNV_PostCall CmdTraceRaysNV_PostCall { noop::CmdTraceRaysNV_PostCall };
    PFN_CreateRayTracingPipelinesNV_PostCall CreateRayTracingPipelinesNV_PostCall { noop::CreateRayTracingPipelinesNV_PostCall };
    PFN_GetRayTracingShaderGroupHandlesKHR_PostCall GetRayTracingShaderGroupHandlesKHR_PostCall { noop::GetRayTracingShaderGroupHandlesKHR_PostCall };
    PFN_GetRayTracingShaderGroupHandlesNV_PostCall GetRayTracingShaderGroupHandlesNV_PostCall { noop::GetRayTracingShaderGroupHandlesNV_PostCall };
    PFN_GetAccelerationStructureHandleNV_PostCall GetAccelerationStructureHandleNV_PostCall { noop::GetAccelerationStructureHandleNV_PostCall };
    PFN_CmdWriteAccelerationStructuresPropertiesNV_PostCall CmdWriteAccelerationStructuresPropertiesNV_PostCall { noop::CmdWriteAccelerationStructuresPropertiesNV_PostCall };
    PFN_CompileDeferredNV_PostCall CompileDeferredNV_PostCall { noop::CompileDeferredNV_PostCall };
    PFN_GetMemoryHostPointerPropertiesEXT_PostCall GetMemoryHostPointerPropertiesEXT_PostCall { noop::GetMemoryHostPointerPropertiesEXT_PostCall };
    PFN_CmdWriteBufferMarkerAMD_PostCall CmdWriteBufferMarkerAMD_PostCall { noop::CmdWriteBufferMarkerAMD_PostCall };
    PFN_GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall { noop::GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall };
    PFN_GetCalibratedTimestampsEXT_PostCall GetCalibratedTimestampsEXT_PostCall { noop::GetCalibratedTimestampsEXT_PostCall };
    PFN_CmdDrawMeshTasksNV_PostCall CmdDrawMeshTasksNV_PostCall { noop::CmdDrawMeshTasksNV_PostCall };
    PFN_CmdDrawMeshTasksIndirectNV_PostCall CmdDrawMeshTasksIndirectNV_PostCall { noop::CmdDrawMeshTasksIndirectNV_PostCall };
    PFN_CmdDrawMeshTasksIndirectCountNV_PostCall CmdDrawMeshTasksIndirectCountNV_PostCall { noop::CmdDrawMeshTasksIndirectCountNV_PostCall };
    PFN_CmdSetExclusiveScissorEnableNV_PostCall CmdSetExclusiveScissorEnableNV_PostCall { noop::CmdSetExclusiveScissorEnableNV_PostCall };
    PFN_CmdSetExclusiveScissorNV_PostCall CmdSetExclusiveScissorNV_PostCall { noop::CmdSetExclusiveScissorNV_PostCall };
    PFN_CmdSetCheckpointNV_PostCall CmdSetCheckpointNV_PostCall { noop::CmdSetCheckpointNV_PostCall };
    PFN_GetQueueCheckpointDataNV_PostCall GetQueueCheckpointDataNV_PostCall { noop::GetQueueCheckpointDataNV_PostCall };
    PFN_InitializePerformanceApiINTEL_PostCall InitializePerformanceApiINTEL_PostCall { noop::InitializePerformanceApiINTEL_PostCall };
    PFN_UninitializePerformanceApiINTEL_PostCall UninitializePerformanceApiINTEL_PostCall { noop::UninitializePerformanceApiINTEL_PostCall };
    PFN_CmdSetPerformanceMarkerINTEL_PostCall CmdSetPerformanceMarkerINTEL_PostCall { noop::CmdSetPerformanceMarkerINTEL_PostCall };
    PFN_CmdSetPerformanceStreamMarkerINTEL_PostCall CmdSetPerformanceStreamMarkerINTEL_PostCall { noop::CmdSetPerformanceStreamMarkerINTEL_PostCall };
    PFN_CmdSetPerformanceOverrideINTEL_PostCall CmdSetPerformanceOverrideINTEL_PostCall { noop::CmdSetPerformanceOverrideINTEL_PostCall };
    PFN_AcquirePerformanceConfigurationINTEL_PostCall AcquirePerformanceConfigurationINTEL_PostCall { noop::AcquirePerformanceConfigurationINTEL_PostCall };
    PFN_ReleasePerformanceConfigurationINTEL_PostCall ReleasePerformanceConfigurationINTEL_PostCall { noop::ReleasePerformanceConfigurationINTEL_PostCall };
    PFN_QueueSetPerformanceConfigurationINTEL_PostCall QueueSetPerformanceConfigurationINTEL_PostCall { noop::QueueSetPerformanceConfigurationINTEL_PostCall };
    PFN_GetPerformanceParameterINTEL_PostCall GetPerformanceParameterINTEL_PostCall { noop::GetPerformanceParameterINTEL_PostCall };
    PFN_SetLocalDimmingAMD_PostCall SetLocalDimmingAMD_PostCall { noop::SetLocalDimmingAMD_PostCall };
    PFN_CreateImagePipeSurfaceFUCHSIA_PostCall CreateImagePipeSurfaceFUCHSIA_PostCall { noop::CreateImagePipeSurfaceFUCHSIA_PostCall };
    PFN_CreateMetalSurfaceEXT_PostCall CreateMetalSurfaceEXT_PostCall { noop::CreateMetalSurfaceEXT_PostCall };
    PFN_GetBufferDeviceAddressEXT_PostCall GetBufferDeviceAddressEXT_PostCall { noop::GetBufferDeviceAddressEXT_PostCall };
    PFN_GetPhysicalDeviceToolPropertiesEXT_PostCall GetPhysicalDeviceToolPropertiesEXT_PostCall { noop::GetPhysicalDeviceToolPropertiesEXT_PostCall };
    PFN_GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall { noop::GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall };
    PFN_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall { noop::GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall };
    PFN_GetPhysicalDeviceSurfacePresentModes2EXT_PostCall GetPhysicalDeviceSurfacePresentModes2EXT_PostCall { noop::GetPhysicalDeviceSurfacePresentModes2EXT_PostCall };
    PFN_AcquireFullScreenExclusiveModeEXT_PostCall AcquireFullScreenExclusiveModeEXT_PostCall { noop::AcquireFullScreenExclusiveModeEXT_PostCall };
    PFN_ReleaseFullScreenExclusiveModeEXT_PostCall ReleaseFullScreenExclusiveModeEXT_PostCall { noop::ReleaseFullScreenExclusiveModeEXT_PostCall };
    PFN_GetDeviceGroupSurfacePresentModes2EXT_PostCall GetDeviceGroupSurfacePresentModes2EXT_PostCall { noop::GetDeviceGroupSurfacePresentModes2EXT_PostCall };
    PFN_CreateHeadlessSurfaceEXT_PostCall CreateHeadlessSurfaceEXT_PostCall { noop::CreateHeadlessSurfaceEXT_PostCall };
    PFN_CmdSetLineStippleEXT_PostCall CmdSetLineStippleEXT_PostCall { noop::CmdSetLineStippleEXT_PostCall };
    PFN_ResetQueryPoolEXT_PostCall ResetQueryPoolEXT_PostCall { noop::ResetQueryPoolEXT_PostCall };
    PFN_CmdSetCullModeEXT_PostCall CmdSetCullModeEXT_PostCall { noop::CmdSetCullModeEXT_PostCall };
    PFN_CmdSetFrontFaceEXT_PostCall CmdSetFrontFaceEXT_PostCall { noop::CmdSetFrontFaceEXT_PostCall };
    PFN_CmdSetPrimitiveTopologyEXT_PostCall CmdSetPrimitiveTopologyEXT_PostCall { noop::CmdSetPrimitiveTopologyEXT_PostCall };
    PFN_CmdSetViewportWithCountEXT_PostCall CmdSetViewportWithCountEXT_PostCall { noop::CmdSetViewportWithCountEXT_PostCall };
    PFN_CmdSetScissorWithCountEXT_PostCall CmdSetScissorWithCountEXT_PostCall { noop::CmdSetScissorWithCountEXT_PostCall };
    PFN_CmdBindVertexBuffers2EXT_PostCall CmdBindVertexBuffers2EXT_PostCall { noop::CmdBindVertexBuffers2EXT_PostCall };
    PFN_CmdSetDepthTestEnableEXT_PostCall CmdSetDepthTestEnableEXT_PostCall { noop::CmdSetDepthTestEnableEXT_PostCall };
    PFN_CmdSetDepthWriteEnableEXT_PostCall CmdSetDepthWriteEnableEXT_PostCall { noop::CmdSetDepthWriteEnableEXT_PostCall };
    PFN_CmdSetDepthCompareOpEXT_PostCall CmdSetDepthCompareOpEXT_PostCall { noop::CmdSetDepthCompareOpEXT_PostCall };
    PFN_CmdSetDepthBoundsTestEnableEXT_PostCall CmdSetDepthBoundsTestEnableEXT_PostCall { noop::CmdSetDepthBoundsTestEnableEXT_PostCall };
    PFN_CmdSetStencilTestEnableEXT_PostCall CmdSetStencilTestEnableEXT_PostCall { noop::CmdSetStencilTestEnableEXT_PostCall };
    PFN_CmdSetStencilOpEXT_PostCall CmdSetStencilOpEXT_PostCall { noop::CmdSetStencilOpEXT_PostCall };
    PFN_ReleaseSwapchainImagesEXT_PostCall ReleaseSwapchainImagesEXT_PostCall { noop::ReleaseSwapchainImagesEXT_PostCall };
    PFN_GetGeneratedCommandsMemoryRequirementsNV_PostCall GetGeneratedCommandsMemoryRequirementsNV_PostCall { noop::GetGeneratedCommandsMemoryRequirementsNV_PostCall };
    PFN_CmdPreprocessGeneratedCommandsNV_PostCall CmdPreprocessGeneratedCommandsNV_PostCall { noop::CmdPreprocessGeneratedCommandsNV_PostCall };
    PFN_CmdExecuteGeneratedCommandsNV_PostCall CmdExecuteGeneratedCommandsNV_PostCall { noop::CmdExecuteGeneratedCommandsNV_PostCall };
    PFN_CmdBindPipelineShaderGroupNV_PostCall CmdBindPipelineShaderGroupNV_PostCall { noop::CmdBindPipelineShaderGroupNV_PostCall };
    PFN_CreateIndirectCommandsLayoutNV_PostCall CreateIndirectCommandsLayoutNV_PostCall { noop::CreateIndirectCommandsLayoutNV_PostCall };
    PFN_DestroyIndirectCommandsLayoutNV_PostCall DestroyIndirectCommandsLayoutNV_PostCall { noop::DestroyIndirectCommandsLayoutNV_PostCall };
    PFN_AcquireDrmDisplayEXT_PostCall AcquireDrmDisplayEXT_PostCall { noop::AcquireDrmDisplayEXT_PostCall };
    PFN_GetDrmDisplayEXT_PostCall GetDrmDisplayEXT_PostCall { noop::GetDrmDisplayEXT_PostCall };
    PFN_CreatePrivateDataSlotEXT_PostCall CreatePrivateDataSlotEXT_PostCall { noop::CreatePrivateDataSlotEXT_PostCall };
    PFN_DestroyPrivateDataSlotEXT_PostCall DestroyPrivateDataSlotEXT_PostCall { noop::DestroyPrivateDataSlotEXT_PostCall };
    PFN_SetPrivateDataEXT_PostCall SetPrivateDataEXT_PostCall { noop::SetPrivateDataEXT_PostCall };
    PFN_GetPrivateDataEXT_PostCall GetPrivateDataEXT_PostCall { noop::GetPrivateDataEXT_PostCall };
    PFN_CmdSetFragmentShadingRateEnumNV_PostCall CmdSetFragmentShadingRateEnumNV_PostCall { noop::CmdSetFragmentShadingRateEnumNV_PostCall };
    PFN_GetImageSubresourceLayout2EXT_PostCall GetImageSubresourceLayout2EXT_PostCall { noop::GetImageSubresourceLayout2EXT_PostCall };
    PFN_GetDeviceFaultInfoEXT_PostCall GetDeviceFaultInfoEXT_PostCall { noop::GetDeviceFaultInfoEXT_PostCall };
    PFN_AcquireWinrtDisplayNV_PostCall AcquireWinrtDisplayNV_PostCall { noop::AcquireWinrtDisplayNV_PostCall };
    PFN_GetWinrtDisplayNV_PostCall GetWinrtDisplayNV_PostCall { noop::GetWinrtDisplayNV_PostCall };
    PFN_CreateDirectFBSurfaceEXT_PostCall CreateDirectFBSurfaceEXT_PostCall { noop::CreateDirectFBSurfaceEXT_PostCall };
    PFN_GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall { noop::GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall };
    PFN_CmdSetVertexInputEXT_PostCall CmdSetVertexInputEXT_PostCall { noop::CmdSetVertexInputEXT_PostCall };
    PFN_GetMemoryZirconHandleFUCHSIA_PostCall GetMemoryZirconHandleFUCHSIA_PostCall { noop::GetMemoryZirconHandleFUCHSIA_PostCall };
    PFN_GetMemoryZirconHandlePropertiesFUCHSIA_PostCall GetMemoryZirconHandlePropertiesFUCHSIA_PostCall { noop::GetMemoryZirconHandlePropertiesFUCHSIA_PostCall };
    PFN_ImportSemaphoreZirconHandleFUCHSIA_PostCall ImportSemaphoreZirconHandleFUCHSIA_PostCall { noop::ImportSemaphoreZirconHandleFUCHSIA_PostCall };
    PFN_GetSemaphoreZirconHandleFUCHSIA_PostCall GetSemaphoreZirconHandleFUCHSIA_PostCall { noop::GetSemaphoreZirconHandleFUCHSIA_PostCall };
    PFN_CmdBindInvocationMaskHUAWEI_PostCall CmdBindInvocationMaskHUAWEI_PostCall { noop::CmdBindInvocationMaskHUAWEI_PostCall };
    PFN_GetMemoryRemoteAddressNV_PostCall GetMemoryRemoteAddressNV_PostCall { noop::GetMemoryRemoteAddressNV_PostCall };
    PFN_CmdSetPatchControlPointsEXT_PostCall CmdSetPatchControlPointsEXT_PostCall { noop::CmdSetPatchControlPointsEXT_PostCall };
    PFN_CmdSetRasterizerDiscardEnableEXT_PostCall CmdSetRasterizerDiscardEnableEXT_PostCall { noop::CmdSetRasterizerDiscardEnableEXT_PostCall };
    PFN_CmdSetDepthBiasEnableEXT_PostCall CmdSetDepthBiasEnableEXT_PostCall { noop::CmdSetDepthBiasEnableEXT_PostCall };
    PFN_CmdSetLogicOpEXT_PostCall CmdSetLogicOpEXT_PostCall { noop::CmdSetLogicOpEXT_PostCall };
    PFN_CmdSetPrimitiveRestartEnableEXT_PostCall CmdSetPrimitiveRestartEnableEXT_PostCall { noop::CmdSetPrimitiveRestartEnableEXT_PostCall };
    PFN_CreateScreenSurfaceQNX_PostCall CreateScreenSurfaceQNX_PostCall { noop::CreateScreenSurfaceQNX_PostCall };
    PFN_GetPhysicalDeviceScreenPresentationSupportQNX_PostCall GetPhysicalDeviceScreenPresentationSupportQNX_PostCall { noop::GetPhysicalDeviceScreenPresentationSupportQNX_PostCall };
    PFN_CmdSetColorWriteEnableEXT_PostCall CmdSetColorWriteEnableEXT_PostCall { noop::CmdSetColorWriteEnableEXT_PostCall };
    PFN_CmdDrawMultiEXT_PostCall CmdDrawMultiEXT_PostCall { noop::CmdDrawMultiEXT_PostCall };
    PFN_CmdDrawMultiIndexedEXT_PostCall CmdDrawMultiIndexedEXT_PostCall { noop::CmdDrawMultiIndexedEXT_PostCall };
    PFN_CreateMicromapEXT_PostCall CreateMicromapEXT_PostCall { noop::CreateMicromapEXT_PostCall };
    PFN_DestroyMicromapEXT_PostCall DestroyMicromapEXT_PostCall { noop::DestroyMicromapEXT_PostCall };
    PFN_CmdBuildMicromapsEXT_PostCall CmdBuildMicromapsEXT_PostCall { noop::CmdBuildMicromapsEXT_PostCall };
    PFN_BuildMicromapsEXT_PostCall BuildMicromapsEXT_PostCall { noop::BuildMicromapsEXT_PostCall };
    PFN_CopyMicromapEXT_PostCall CopyMicromapEXT_PostCall { noop::CopyMicromapEXT_PostCall };
    PFN_CopyMicromapToMemoryEXT_PostCall CopyMicromapToMemoryEXT_PostCall { noop::CopyMicromapToMemoryEXT_PostCall };
    PFN_CopyMemoryToMicromapEXT_PostCall CopyMemoryToMicromapEXT_PostCall { noop::CopyMemoryToMicromapEXT_PostCall };
    PFN_WriteMicromapsPropertiesEXT_PostCall WriteMicromapsPropertiesEXT_PostCall { noop::WriteMicromapsPropertiesEXT_PostCall };
    PFN_CmdCopyMicromapEXT_PostCall CmdCopyMicromapEXT_PostCall { noop::CmdCopyMicromapEXT_PostCall };
    PFN_CmdCopyMicromapToMemoryEXT_PostCall CmdCopyMicromapToMemoryEXT_PostCall { noop::CmdCopyMicromapToMemoryEXT_PostCall };
    PFN_CmdCopyMemoryToMicromapEXT_PostCall CmdCopyMemoryToMicromapEXT_PostCall { noop::CmdCopyMemoryToMicromapEXT_PostCall };
    PFN_CmdWriteMicromapsPropertiesEXT_PostCall CmdWriteMicromapsPropertiesEXT_PostCall { noop::CmdWriteMicromapsPropertiesEXT_PostCall };
    PFN_GetDeviceMicromapCompatibilityEXT_PostCall GetDeviceMicromapCompatibilityEXT_PostCall { noop::GetDeviceMicromapCompatibilityEXT_PostCall };
    PFN_GetMicromapBuildSizesEXT_PostCall GetMicromapBuildSizesEXT_PostCall { noop::GetMicromapBuildSizesEXT_PostCall };
    PFN_CmdDrawClusterHUAWEI_PostCall CmdDrawClusterHUAWEI_PostCall { noop::CmdDrawClusterHUAWEI_PostCall };
    PFN_CmdDrawClusterIndirectHUAWEI_PostCall CmdDrawClusterIndirectHUAWEI_PostCall { noop::CmdDrawClusterIndirectHUAWEI_PostCall };
    PFN_SetDeviceMemoryPriorityEXT_PostCall SetDeviceMemoryPriorityEXT_PostCall { noop::SetDeviceMemoryPriorityEXT_PostCall };
    PFN_GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall { noop::GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall };
    PFN_GetDescriptorSetHostMappingVALVE_PostCall GetDescriptorSetHostMappingVALVE_PostCall { noop::GetDescriptorSetHostMappingVALVE_PostCall };
    PFN_CmdSetTessellationDomainOriginEXT_PostCall CmdSetTessellationDomainOriginEXT_PostCall { noop::CmdSetTessellationDomainOriginEXT_PostCall };
    PFN_CmdSetDepthClampEnableEXT_PostCall CmdSetDepthClampEnableEXT_PostCall { noop::CmdSetDepthClampEnableEXT_PostCall };
    PFN_CmdSetPolygonModeEXT_PostCall CmdSetPolygonModeEXT_PostCall { noop::CmdSetPolygonModeEXT_PostCall };
    PFN_CmdSetRasterizationSamplesEXT_PostCall CmdSetRasterizationSamplesEXT_PostCall { noop::CmdSetRasterizationSamplesEXT_PostCall };
    PFN_CmdSetSampleMaskEXT_PostCall CmdSetSampleMaskEXT_PostCall { noop::CmdSetSampleMaskEXT_PostCall };
    PFN_CmdSetAlphaToCoverageEnableEXT_PostCall CmdSetAlphaToCoverageEnableEXT_PostCall { noop::CmdSetAlphaToCoverageEnableEXT_PostCall };
    PFN_CmdSetAlphaToOneEnableEXT_PostCall CmdSetAlphaToOneEnableEXT_PostCall { noop::CmdSetAlphaToOneEnableEXT_PostCall };
    PFN_CmdSetLogicOpEnableEXT_PostCall CmdSetLogicOpEnableEXT_PostCall { noop::CmdSetLogicOpEnableEXT_PostCall };
    PFN_CmdSetColorBlendEnableEXT_PostCall CmdSetColorBlendEnableEXT_PostCall { noop::CmdSetColorBlendEnableEXT_PostCall };
    PFN_CmdSetColorBlendEquationEXT_PostCall CmdSetColorBlendEquationEXT_PostCall { noop::CmdSetColorBlendEquationEXT_PostCall };
    PFN_CmdSetColorWriteMaskEXT_PostCall CmdSetColorWriteMaskEXT_PostCall { noop::CmdSetColorWriteMaskEXT_PostCall };
    PFN_CmdSetRasterizationStreamEXT_PostCall CmdSetRasterizationStreamEXT_PostCall { noop::CmdSetRasterizationStreamEXT_PostCall };
    PFN_CmdSetConservativeRasterizationModeEXT_PostCall CmdSetConservativeRasterizationModeEXT_PostCall { noop::CmdSetConservativeRasterizationModeEXT_PostCall };
    PFN_CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall { noop::CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall };
    PFN_CmdSetDepthClipEnableEXT_PostCall CmdSetDepthClipEnableEXT_PostCall { noop::CmdSetDepthClipEnableEXT_PostCall };
    PFN_CmdSetSampleLocationsEnableEXT_PostCall CmdSetSampleLocationsEnableEXT_PostCall { noop::CmdSetSampleLocationsEnableEXT_PostCall };
    PFN_CmdSetColorBlendAdvancedEXT_PostCall CmdSetColorBlendAdvancedEXT_PostCall { noop::CmdSetColorBlendAdvancedEXT_PostCall };
    PFN_CmdSetProvokingVertexModeEXT_PostCall CmdSetProvokingVertexModeEXT_PostCall { noop::CmdSetProvokingVertexModeEXT_PostCall };
    PFN_CmdSetLineRasterizationModeEXT_PostCall CmdSetLineRasterizationModeEXT_PostCall { noop::CmdSetLineRasterizationModeEXT_PostCall };
    PFN_CmdSetLineStippleEnableEXT_PostCall CmdSetLineStippleEnableEXT_PostCall { noop::CmdSetLineStippleEnableEXT_PostCall };
    PFN_CmdSetDepthClipNegativeOneToOneEXT_PostCall CmdSetDepthClipNegativeOneToOneEXT_PostCall { noop::CmdSetDepthClipNegativeOneToOneEXT_PostCall };
    PFN_CmdSetViewportWScalingEnableNV_PostCall CmdSetViewportWScalingEnableNV_PostCall { noop::CmdSetViewportWScalingEnableNV_PostCall };
    PFN_CmdSetViewportSwizzleNV_PostCall CmdSetViewportSwizzleNV_PostCall { noop::CmdSetViewportSwizzleNV_PostCall };
    PFN_CmdSetCoverageToColorEnableNV_PostCall CmdSetCoverageToColorEnableNV_PostCall { noop::CmdSetCoverageToColorEnableNV_PostCall };
    PFN_CmdSetCoverageToColorLocationNV_PostCall CmdSetCoverageToColorLocationNV_PostCall { noop::CmdSetCoverageToColorLocationNV_PostCall };
    PFN_CmdSetCoverageModulationModeNV_PostCall CmdSetCoverageModulationModeNV_PostCall { noop::CmdSetCoverageModulationModeNV_PostCall };
    PFN_CmdSetCoverageModulationTableEnableNV_PostCall CmdSetCoverageModulationTableEnableNV_PostCall { noop::CmdSetCoverageModulationTableEnableNV_PostCall };
    PFN_CmdSetCoverageModulationTableNV_PostCall CmdSetCoverageModulationTableNV_PostCall { noop::CmdSetCoverageModulationTableNV_PostCall };
    PFN_CmdSetShadingRateImageEnableNV_PostCall CmdSetShadingRateImageEnableNV_PostCall { noop::CmdSetShadingRateImageEnableNV_PostCall };
    PFN_CmdSetRepresentativeFragmentTestEnableNV_PostCall CmdSetRepresentativeFragmentTestEnableNV_PostCall { noop::CmdSetRepresentativeFragmentTestEnableNV_PostCall };
    PFN_CmdSetCoverageReductionModeNV_PostCall CmdSetCoverageReductionModeNV_PostCall { noop::CmdSetCoverageReductionModeNV_PostCall };
    PFN_GetShaderModuleIdentifierEXT_PostCall GetShaderModuleIdentifierEXT_PostCall { noop::GetShaderModuleIdentifierEXT_PostCall };
    PFN_GetShaderModuleCreateInfoIdentifierEXT_PostCall GetShaderModuleCreateInfoIdentifierEXT_PostCall { noop::GetShaderModuleCreateInfoIdentifierEXT_PostCall };
    PFN_GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall { noop::GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall };
    PFN_CreateOpticalFlowSessionNV_PostCall CreateOpticalFlowSessionNV_PostCall { noop::CreateOpticalFlowSessionNV_PostCall };
    PFN_DestroyOpticalFlowSessionNV_PostCall DestroyOpticalFlowSessionNV_PostCall { noop::DestroyOpticalFlowSessionNV_PostCall };
    PFN_BindOpticalFlowSessionImageNV_PostCall BindOpticalFlowSessionImageNV_PostCall { noop::BindOpticalFlowSessionImageNV_PostCall };
    PFN_CmdOpticalFlowExecuteNV_PostCall CmdOpticalFlowExecuteNV_PostCall { noop::CmdOpticalFlowExecuteNV_PostCall };
    PFN_CreateShadersEXT_PostCall CreateShadersEXT_PostCall { noop::CreateShadersEXT_PostCall };
    PFN_DestroyShaderEXT_PostCall DestroyShaderEXT_PostCall { noop::DestroyShaderEXT_PostCall };
    PFN_GetShaderBinaryDataEXT_PostCall GetShaderBinaryDataEXT_PostCall { noop::GetShaderBinaryDataEXT_PostCall };
    PFN_CmdBindShadersEXT_PostCall CmdBindShadersEXT_PostCall { noop::CmdBindShadersEXT_PostCall };
    PFN_GetFramebufferTilePropertiesQCOM_PostCall GetFramebufferTilePropertiesQCOM_PostCall { noop::GetFramebufferTilePropertiesQCOM_PostCall };
    PFN_GetDynamicRenderingTilePropertiesQCOM_PostCall GetDynamicRenderingTilePropertiesQCOM_PostCall { noop::GetDynamicRenderingTilePropertiesQCOM_PostCall };
    PFN_CreateAccelerationStructureKHR_PostCall CreateAccelerationStructureKHR_PostCall { noop::CreateAccelerationStructureKHR_PostCall };
    PFN_DestroyAccelerationStructureKHR_PostCall DestroyAccelerationStructureKHR_PostCall { noop::DestroyAccelerationStructureKHR_PostCall };
    PFN_CmdBuildAccelerationStructuresKHR_PostCall CmdBuildAccelerationStructuresKHR_PostCall { noop::CmdBuildAccelerationStructuresKHR_PostCall };
    PFN_CmdBuildAccelerationStructuresIndirectKHR_PostCall CmdBuildAccelerationStructuresIndirectKHR_PostCall { noop::CmdBuildAccelerationStructuresIndirectKHR_PostCall };
    PFN_BuildAccelerationStructuresKHR_PostCall BuildAccelerationStructuresKHR_PostCall { noop::BuildAccelerationStructuresKHR_PostCall };
    PFN_CopyAccelerationStructureKHR_PostCall CopyAccelerationStructureKHR_PostCall { noop::CopyAccelerationStructureKHR_PostCall };
    PFN_CopyAccelerationStructureToMemoryKHR_PostCall CopyAccelerationStructureToMemoryKHR_PostCall { noop::CopyAccelerationStructureToMemoryKHR_PostCall };
    PFN_CopyMemoryToAccelerationStructureKHR_PostCall CopyMemoryToAccelerationStructureKHR_PostCall { noop::CopyMemoryToAccelerationStructureKHR_PostCall };
    PFN_WriteAccelerationStructuresPropertiesKHR_PostCall WriteAccelerationStructuresPropertiesKHR_PostCall { noop::WriteAccelerationStructuresPropertiesKHR_PostCall };
    PFN_CmdCopyAccelerationStructureKHR_PostCall CmdCopyAccelerationStructureKHR_PostCall { noop::CmdCopyAccelerationStructureKHR_PostCall };
    PFN_CmdCopyAccelerationStructureToMemoryKHR_PostCall CmdCopyAccelerationStructureToMemoryKHR_PostCall { noop::CmdCopyAccelerationStructureToMemoryKHR_PostCall };
    PFN_CmdCopyMemoryToAccelerationStructureKHR_PostCall CmdCopyMemoryToAccelerationStructureKHR_PostCall { noop::CmdCopyMemoryToAccelerationStructureKHR_PostCall };
    PFN_GetAccelerationStructureDeviceAddressKHR_PostCall GetAccelerationStructureDeviceAddressKHR_PostCall { noop::GetAccelerationStructureDeviceAddressKHR_PostCall };
    PFN_CmdWriteAccelerationStructuresPropertiesKHR_PostCall CmdWriteAccelerationStructuresPropertiesKHR_PostCall { noop::CmdWriteAccelerationStructuresPropertiesKHR_PostCall };
    PFN_GetDeviceAccelerationStructureCompatibilityKHR_PostCall GetDeviceAccelerationStructureCompatibilityKHR_PostCall { noop::GetDeviceAccelerationStructureCompatibilityKHR_PostCall };
    PFN_GetAccelerationStructureBuildSizesKHR_PostCall GetAccelerationStructureBuildSizesKHR_PostCall { noop::GetAccelerationStructureBuildSizesKHR_PostCall };
    PFN_CmdTraceRaysKHR_PostCall CmdTraceRaysKHR_PostCall { noop::CmdTraceRaysKHR_PostCall };
    PFN_CreateRayTracingPipelinesKHR_PostCall CreateRayTracingPipelinesKHR_PostCall { noop::CreateRayTracingPipelinesKHR_PostCall };
    PFN_GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall { noop::GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall };
    PFN_CmdTraceRaysIndirectKHR_PostCall CmdTraceRaysIndirectKHR_PostCall { noop::CmdTraceRaysIndirectKHR_PostCall };
    PFN_GetRayTracingShaderGroupStackSizeKHR_PostCall GetRayTracingShaderGroupStackSizeKHR_PostCall { noop::GetRayTracingShaderGroupStackSizeKHR_PostCall };
    PFN_CmdSetRayTracingPipelineStackSizeKHR_PostCall CmdSetRayTracingPipelineStackSizeKHR_PostCall { noop::CmdSetRayTracingPipelineStackSizeKHR_PostCall };
    PFN_CmdDrawMeshTasksEXT_PostCall CmdDrawMeshTasksEXT_PostCall { noop::CmdDrawMeshTasksEXT_PostCall };
    PFN_CmdDrawMeshTasksIndirectEXT_PostCall CmdDrawMeshTasksIndirectEXT_PostCall { noop::CmdDrawMeshTasksIndirectEXT_PostCall };
    PFN_CmdDrawMeshTasksIndirectCountEXT_PostCall CmdDrawMeshTasksIndirectCountEXT_PostCall { noop::CmdDrawMeshTasksIndirectCountEXT_PostCall };
};

template <typename FuncP>
static void LoadPostFunction(util::platform::GetProcAddress_t gpa, util::platform::LibraryHandle handle, const char* name, FuncP* funcp)
{
    FuncP result = reinterpret_cast<FuncP>(gpa(handle, name));
    if (result)
    {
        *funcp = result;
    }
}

static void LoadPostFunctionTable(util::platform::GetProcAddress_t gpa, util::platform::LibraryHandle handle, plugin_func_table_post *table)
{
    assert(gpa);
    assert(handle);
    assert(table);

    LoadPostFunction(gpa, handle, "CreateInstance_PostCall", &table->CreateInstance_PostCall);
    LoadPostFunction(gpa, handle, "DestroyInstance_PostCall", &table->DestroyInstance_PostCall);
    LoadPostFunction(gpa, handle, "EnumeratePhysicalDevices_PostCall", &table->EnumeratePhysicalDevices_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFeatures_PostCall", &table->GetPhysicalDeviceFeatures_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFormatProperties_PostCall", &table->GetPhysicalDeviceFormatProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceImageFormatProperties_PostCall", &table->GetPhysicalDeviceImageFormatProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceProperties_PostCall", &table->GetPhysicalDeviceProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceQueueFamilyProperties_PostCall", &table->GetPhysicalDeviceQueueFamilyProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceMemoryProperties_PostCall", &table->GetPhysicalDeviceMemoryProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetInstanceProcAddr_PostCall", &table->GetInstanceProcAddr_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceProcAddr_PostCall", &table->GetDeviceProcAddr_PostCall);
    LoadPostFunction(gpa, handle, "CreateDevice_PostCall", &table->CreateDevice_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDevice_PostCall", &table->DestroyDevice_PostCall);
    LoadPostFunction(gpa, handle, "EnumerateInstanceExtensionProperties_PostCall", &table->EnumerateInstanceExtensionProperties_PostCall);
    LoadPostFunction(gpa, handle, "EnumerateDeviceExtensionProperties_PostCall", &table->EnumerateDeviceExtensionProperties_PostCall);
    LoadPostFunction(gpa, handle, "EnumerateInstanceLayerProperties_PostCall", &table->EnumerateInstanceLayerProperties_PostCall);
    LoadPostFunction(gpa, handle, "EnumerateDeviceLayerProperties_PostCall", &table->EnumerateDeviceLayerProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceQueue_PostCall", &table->GetDeviceQueue_PostCall);
    LoadPostFunction(gpa, handle, "QueueSubmit_PostCall", &table->QueueSubmit_PostCall);
    LoadPostFunction(gpa, handle, "QueueWaitIdle_PostCall", &table->QueueWaitIdle_PostCall);
    LoadPostFunction(gpa, handle, "DeviceWaitIdle_PostCall", &table->DeviceWaitIdle_PostCall);
    LoadPostFunction(gpa, handle, "AllocateMemory_PostCall", &table->AllocateMemory_PostCall);
    LoadPostFunction(gpa, handle, "FreeMemory_PostCall", &table->FreeMemory_PostCall);
    LoadPostFunction(gpa, handle, "MapMemory_PostCall", &table->MapMemory_PostCall);
    LoadPostFunction(gpa, handle, "UnmapMemory_PostCall", &table->UnmapMemory_PostCall);
    LoadPostFunction(gpa, handle, "FlushMappedMemoryRanges_PostCall", &table->FlushMappedMemoryRanges_PostCall);
    LoadPostFunction(gpa, handle, "InvalidateMappedMemoryRanges_PostCall", &table->InvalidateMappedMemoryRanges_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceMemoryCommitment_PostCall", &table->GetDeviceMemoryCommitment_PostCall);
    LoadPostFunction(gpa, handle, "BindBufferMemory_PostCall", &table->BindBufferMemory_PostCall);
    LoadPostFunction(gpa, handle, "BindImageMemory_PostCall", &table->BindImageMemory_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferMemoryRequirements_PostCall", &table->GetBufferMemoryRequirements_PostCall);
    LoadPostFunction(gpa, handle, "GetImageMemoryRequirements_PostCall", &table->GetImageMemoryRequirements_PostCall);
    LoadPostFunction(gpa, handle, "GetImageSparseMemoryRequirements_PostCall", &table->GetImageSparseMemoryRequirements_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSparseImageFormatProperties_PostCall", &table->GetPhysicalDeviceSparseImageFormatProperties_PostCall);
    LoadPostFunction(gpa, handle, "QueueBindSparse_PostCall", &table->QueueBindSparse_PostCall);
    LoadPostFunction(gpa, handle, "CreateFence_PostCall", &table->CreateFence_PostCall);
    LoadPostFunction(gpa, handle, "DestroyFence_PostCall", &table->DestroyFence_PostCall);
    LoadPostFunction(gpa, handle, "ResetFences_PostCall", &table->ResetFences_PostCall);
    LoadPostFunction(gpa, handle, "GetFenceStatus_PostCall", &table->GetFenceStatus_PostCall);
    LoadPostFunction(gpa, handle, "WaitForFences_PostCall", &table->WaitForFences_PostCall);
    LoadPostFunction(gpa, handle, "CreateSemaphore_PostCall", &table->CreateSemaphore_PostCall);
    LoadPostFunction(gpa, handle, "DestroySemaphore_PostCall", &table->DestroySemaphore_PostCall);
    LoadPostFunction(gpa, handle, "CreateEvent_PostCall", &table->CreateEvent_PostCall);
    LoadPostFunction(gpa, handle, "DestroyEvent_PostCall", &table->DestroyEvent_PostCall);
    LoadPostFunction(gpa, handle, "GetEventStatus_PostCall", &table->GetEventStatus_PostCall);
    LoadPostFunction(gpa, handle, "SetEvent_PostCall", &table->SetEvent_PostCall);
    LoadPostFunction(gpa, handle, "ResetEvent_PostCall", &table->ResetEvent_PostCall);
    LoadPostFunction(gpa, handle, "CreateQueryPool_PostCall", &table->CreateQueryPool_PostCall);
    LoadPostFunction(gpa, handle, "DestroyQueryPool_PostCall", &table->DestroyQueryPool_PostCall);
    LoadPostFunction(gpa, handle, "GetQueryPoolResults_PostCall", &table->GetQueryPoolResults_PostCall);
    LoadPostFunction(gpa, handle, "CreateBuffer_PostCall", &table->CreateBuffer_PostCall);
    LoadPostFunction(gpa, handle, "DestroyBuffer_PostCall", &table->DestroyBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CreateBufferView_PostCall", &table->CreateBufferView_PostCall);
    LoadPostFunction(gpa, handle, "DestroyBufferView_PostCall", &table->DestroyBufferView_PostCall);
    LoadPostFunction(gpa, handle, "CreateImage_PostCall", &table->CreateImage_PostCall);
    LoadPostFunction(gpa, handle, "DestroyImage_PostCall", &table->DestroyImage_PostCall);
    LoadPostFunction(gpa, handle, "GetImageSubresourceLayout_PostCall", &table->GetImageSubresourceLayout_PostCall);
    LoadPostFunction(gpa, handle, "CreateImageView_PostCall", &table->CreateImageView_PostCall);
    LoadPostFunction(gpa, handle, "DestroyImageView_PostCall", &table->DestroyImageView_PostCall);
    LoadPostFunction(gpa, handle, "CreateShaderModule_PostCall", &table->CreateShaderModule_PostCall);
    LoadPostFunction(gpa, handle, "DestroyShaderModule_PostCall", &table->DestroyShaderModule_PostCall);
    LoadPostFunction(gpa, handle, "CreatePipelineCache_PostCall", &table->CreatePipelineCache_PostCall);
    LoadPostFunction(gpa, handle, "DestroyPipelineCache_PostCall", &table->DestroyPipelineCache_PostCall);
    LoadPostFunction(gpa, handle, "GetPipelineCacheData_PostCall", &table->GetPipelineCacheData_PostCall);
    LoadPostFunction(gpa, handle, "MergePipelineCaches_PostCall", &table->MergePipelineCaches_PostCall);
    LoadPostFunction(gpa, handle, "CreateGraphicsPipelines_PostCall", &table->CreateGraphicsPipelines_PostCall);
    LoadPostFunction(gpa, handle, "CreateComputePipelines_PostCall", &table->CreateComputePipelines_PostCall);
    LoadPostFunction(gpa, handle, "DestroyPipeline_PostCall", &table->DestroyPipeline_PostCall);
    LoadPostFunction(gpa, handle, "CreatePipelineLayout_PostCall", &table->CreatePipelineLayout_PostCall);
    LoadPostFunction(gpa, handle, "DestroyPipelineLayout_PostCall", &table->DestroyPipelineLayout_PostCall);
    LoadPostFunction(gpa, handle, "CreateSampler_PostCall", &table->CreateSampler_PostCall);
    LoadPostFunction(gpa, handle, "DestroySampler_PostCall", &table->DestroySampler_PostCall);
    LoadPostFunction(gpa, handle, "CreateDescriptorSetLayout_PostCall", &table->CreateDescriptorSetLayout_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDescriptorSetLayout_PostCall", &table->DestroyDescriptorSetLayout_PostCall);
    LoadPostFunction(gpa, handle, "CreateDescriptorPool_PostCall", &table->CreateDescriptorPool_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDescriptorPool_PostCall", &table->DestroyDescriptorPool_PostCall);
    LoadPostFunction(gpa, handle, "ResetDescriptorPool_PostCall", &table->ResetDescriptorPool_PostCall);
    LoadPostFunction(gpa, handle, "AllocateDescriptorSets_PostCall", &table->AllocateDescriptorSets_PostCall);
    LoadPostFunction(gpa, handle, "FreeDescriptorSets_PostCall", &table->FreeDescriptorSets_PostCall);
    LoadPostFunction(gpa, handle, "UpdateDescriptorSets_PostCall", &table->UpdateDescriptorSets_PostCall);
    LoadPostFunction(gpa, handle, "CreateFramebuffer_PostCall", &table->CreateFramebuffer_PostCall);
    LoadPostFunction(gpa, handle, "DestroyFramebuffer_PostCall", &table->DestroyFramebuffer_PostCall);
    LoadPostFunction(gpa, handle, "CreateRenderPass_PostCall", &table->CreateRenderPass_PostCall);
    LoadPostFunction(gpa, handle, "DestroyRenderPass_PostCall", &table->DestroyRenderPass_PostCall);
    LoadPostFunction(gpa, handle, "GetRenderAreaGranularity_PostCall", &table->GetRenderAreaGranularity_PostCall);
    LoadPostFunction(gpa, handle, "CreateCommandPool_PostCall", &table->CreateCommandPool_PostCall);
    LoadPostFunction(gpa, handle, "DestroyCommandPool_PostCall", &table->DestroyCommandPool_PostCall);
    LoadPostFunction(gpa, handle, "ResetCommandPool_PostCall", &table->ResetCommandPool_PostCall);
    LoadPostFunction(gpa, handle, "AllocateCommandBuffers_PostCall", &table->AllocateCommandBuffers_PostCall);
    LoadPostFunction(gpa, handle, "FreeCommandBuffers_PostCall", &table->FreeCommandBuffers_PostCall);
    LoadPostFunction(gpa, handle, "BeginCommandBuffer_PostCall", &table->BeginCommandBuffer_PostCall);
    LoadPostFunction(gpa, handle, "EndCommandBuffer_PostCall", &table->EndCommandBuffer_PostCall);
    LoadPostFunction(gpa, handle, "ResetCommandBuffer_PostCall", &table->ResetCommandBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindPipeline_PostCall", &table->CmdBindPipeline_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewport_PostCall", &table->CmdSetViewport_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetScissor_PostCall", &table->CmdSetScissor_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetLineWidth_PostCall", &table->CmdSetLineWidth_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthBias_PostCall", &table->CmdSetDepthBias_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetBlendConstants_PostCall", &table->CmdSetBlendConstants_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthBounds_PostCall", &table->CmdSetDepthBounds_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilCompareMask_PostCall", &table->CmdSetStencilCompareMask_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilWriteMask_PostCall", &table->CmdSetStencilWriteMask_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilReference_PostCall", &table->CmdSetStencilReference_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindDescriptorSets_PostCall", &table->CmdBindDescriptorSets_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindIndexBuffer_PostCall", &table->CmdBindIndexBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindVertexBuffers_PostCall", &table->CmdBindVertexBuffers_PostCall);
    LoadPostFunction(gpa, handle, "CmdDraw_PostCall", &table->CmdDraw_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndexed_PostCall", &table->CmdDrawIndexed_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndirect_PostCall", &table->CmdDrawIndirect_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndexedIndirect_PostCall", &table->CmdDrawIndexedIndirect_PostCall);
    LoadPostFunction(gpa, handle, "CmdDispatch_PostCall", &table->CmdDispatch_PostCall);
    LoadPostFunction(gpa, handle, "CmdDispatchIndirect_PostCall", &table->CmdDispatchIndirect_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyBuffer_PostCall", &table->CmdCopyBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyImage_PostCall", &table->CmdCopyImage_PostCall);
    LoadPostFunction(gpa, handle, "CmdBlitImage_PostCall", &table->CmdBlitImage_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyBufferToImage_PostCall", &table->CmdCopyBufferToImage_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyImageToBuffer_PostCall", &table->CmdCopyImageToBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CmdUpdateBuffer_PostCall", &table->CmdUpdateBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CmdFillBuffer_PostCall", &table->CmdFillBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CmdClearColorImage_PostCall", &table->CmdClearColorImage_PostCall);
    LoadPostFunction(gpa, handle, "CmdClearDepthStencilImage_PostCall", &table->CmdClearDepthStencilImage_PostCall);
    LoadPostFunction(gpa, handle, "CmdClearAttachments_PostCall", &table->CmdClearAttachments_PostCall);
    LoadPostFunction(gpa, handle, "CmdResolveImage_PostCall", &table->CmdResolveImage_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetEvent_PostCall", &table->CmdSetEvent_PostCall);
    LoadPostFunction(gpa, handle, "CmdResetEvent_PostCall", &table->CmdResetEvent_PostCall);
    LoadPostFunction(gpa, handle, "CmdWaitEvents_PostCall", &table->CmdWaitEvents_PostCall);
    LoadPostFunction(gpa, handle, "CmdPipelineBarrier_PostCall", &table->CmdPipelineBarrier_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginQuery_PostCall", &table->CmdBeginQuery_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndQuery_PostCall", &table->CmdEndQuery_PostCall);
    LoadPostFunction(gpa, handle, "CmdResetQueryPool_PostCall", &table->CmdResetQueryPool_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteTimestamp_PostCall", &table->CmdWriteTimestamp_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyQueryPoolResults_PostCall", &table->CmdCopyQueryPoolResults_PostCall);
    LoadPostFunction(gpa, handle, "CmdPushConstants_PostCall", &table->CmdPushConstants_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginRenderPass_PostCall", &table->CmdBeginRenderPass_PostCall);
    LoadPostFunction(gpa, handle, "CmdNextSubpass_PostCall", &table->CmdNextSubpass_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndRenderPass_PostCall", &table->CmdEndRenderPass_PostCall);
    LoadPostFunction(gpa, handle, "CmdExecuteCommands_PostCall", &table->CmdExecuteCommands_PostCall);
    LoadPostFunction(gpa, handle, "EnumerateInstanceVersion_PostCall", &table->EnumerateInstanceVersion_PostCall);
    LoadPostFunction(gpa, handle, "BindBufferMemory2_PostCall", &table->BindBufferMemory2_PostCall);
    LoadPostFunction(gpa, handle, "BindImageMemory2_PostCall", &table->BindImageMemory2_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceGroupPeerMemoryFeatures_PostCall", &table->GetDeviceGroupPeerMemoryFeatures_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDeviceMask_PostCall", &table->CmdSetDeviceMask_PostCall);
    LoadPostFunction(gpa, handle, "CmdDispatchBase_PostCall", &table->CmdDispatchBase_PostCall);
    LoadPostFunction(gpa, handle, "EnumeratePhysicalDeviceGroups_PostCall", &table->EnumeratePhysicalDeviceGroups_PostCall);
    LoadPostFunction(gpa, handle, "GetImageMemoryRequirements2_PostCall", &table->GetImageMemoryRequirements2_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferMemoryRequirements2_PostCall", &table->GetBufferMemoryRequirements2_PostCall);
    LoadPostFunction(gpa, handle, "GetImageSparseMemoryRequirements2_PostCall", &table->GetImageSparseMemoryRequirements2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFeatures2_PostCall", &table->GetPhysicalDeviceFeatures2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceProperties2_PostCall", &table->GetPhysicalDeviceProperties2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFormatProperties2_PostCall", &table->GetPhysicalDeviceFormatProperties2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceImageFormatProperties2_PostCall", &table->GetPhysicalDeviceImageFormatProperties2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceQueueFamilyProperties2_PostCall", &table->GetPhysicalDeviceQueueFamilyProperties2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceMemoryProperties2_PostCall", &table->GetPhysicalDeviceMemoryProperties2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSparseImageFormatProperties2_PostCall", &table->GetPhysicalDeviceSparseImageFormatProperties2_PostCall);
    LoadPostFunction(gpa, handle, "TrimCommandPool_PostCall", &table->TrimCommandPool_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceQueue2_PostCall", &table->GetDeviceQueue2_PostCall);
    LoadPostFunction(gpa, handle, "CreateSamplerYcbcrConversion_PostCall", &table->CreateSamplerYcbcrConversion_PostCall);
    LoadPostFunction(gpa, handle, "DestroySamplerYcbcrConversion_PostCall", &table->DestroySamplerYcbcrConversion_PostCall);
    LoadPostFunction(gpa, handle, "CreateDescriptorUpdateTemplate_PostCall", &table->CreateDescriptorUpdateTemplate_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDescriptorUpdateTemplate_PostCall", &table->DestroyDescriptorUpdateTemplate_PostCall);
    LoadPostFunction(gpa, handle, "UpdateDescriptorSetWithTemplate_PostCall", &table->UpdateDescriptorSetWithTemplate_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalBufferProperties_PostCall", &table->GetPhysicalDeviceExternalBufferProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalFenceProperties_PostCall", &table->GetPhysicalDeviceExternalFenceProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalSemaphoreProperties_PostCall", &table->GetPhysicalDeviceExternalSemaphoreProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetDescriptorSetLayoutSupport_PostCall", &table->GetDescriptorSetLayoutSupport_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndirectCount_PostCall", &table->CmdDrawIndirectCount_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndexedIndirectCount_PostCall", &table->CmdDrawIndexedIndirectCount_PostCall);
    LoadPostFunction(gpa, handle, "CreateRenderPass2_PostCall", &table->CreateRenderPass2_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginRenderPass2_PostCall", &table->CmdBeginRenderPass2_PostCall);
    LoadPostFunction(gpa, handle, "CmdNextSubpass2_PostCall", &table->CmdNextSubpass2_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndRenderPass2_PostCall", &table->CmdEndRenderPass2_PostCall);
    LoadPostFunction(gpa, handle, "ResetQueryPool_PostCall", &table->ResetQueryPool_PostCall);
    LoadPostFunction(gpa, handle, "GetSemaphoreCounterValue_PostCall", &table->GetSemaphoreCounterValue_PostCall);
    LoadPostFunction(gpa, handle, "WaitSemaphores_PostCall", &table->WaitSemaphores_PostCall);
    LoadPostFunction(gpa, handle, "SignalSemaphore_PostCall", &table->SignalSemaphore_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferDeviceAddress_PostCall", &table->GetBufferDeviceAddress_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferOpaqueCaptureAddress_PostCall", &table->GetBufferOpaqueCaptureAddress_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceMemoryOpaqueCaptureAddress_PostCall", &table->GetDeviceMemoryOpaqueCaptureAddress_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceToolProperties_PostCall", &table->GetPhysicalDeviceToolProperties_PostCall);
    LoadPostFunction(gpa, handle, "CreatePrivateDataSlot_PostCall", &table->CreatePrivateDataSlot_PostCall);
    LoadPostFunction(gpa, handle, "DestroyPrivateDataSlot_PostCall", &table->DestroyPrivateDataSlot_PostCall);
    LoadPostFunction(gpa, handle, "SetPrivateData_PostCall", &table->SetPrivateData_PostCall);
    LoadPostFunction(gpa, handle, "GetPrivateData_PostCall", &table->GetPrivateData_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetEvent2_PostCall", &table->CmdSetEvent2_PostCall);
    LoadPostFunction(gpa, handle, "CmdResetEvent2_PostCall", &table->CmdResetEvent2_PostCall);
    LoadPostFunction(gpa, handle, "CmdWaitEvents2_PostCall", &table->CmdWaitEvents2_PostCall);
    LoadPostFunction(gpa, handle, "CmdPipelineBarrier2_PostCall", &table->CmdPipelineBarrier2_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteTimestamp2_PostCall", &table->CmdWriteTimestamp2_PostCall);
    LoadPostFunction(gpa, handle, "QueueSubmit2_PostCall", &table->QueueSubmit2_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyBuffer2_PostCall", &table->CmdCopyBuffer2_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyImage2_PostCall", &table->CmdCopyImage2_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyBufferToImage2_PostCall", &table->CmdCopyBufferToImage2_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyImageToBuffer2_PostCall", &table->CmdCopyImageToBuffer2_PostCall);
    LoadPostFunction(gpa, handle, "CmdBlitImage2_PostCall", &table->CmdBlitImage2_PostCall);
    LoadPostFunction(gpa, handle, "CmdResolveImage2_PostCall", &table->CmdResolveImage2_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginRendering_PostCall", &table->CmdBeginRendering_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndRendering_PostCall", &table->CmdEndRendering_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCullMode_PostCall", &table->CmdSetCullMode_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetFrontFace_PostCall", &table->CmdSetFrontFace_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPrimitiveTopology_PostCall", &table->CmdSetPrimitiveTopology_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewportWithCount_PostCall", &table->CmdSetViewportWithCount_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetScissorWithCount_PostCall", &table->CmdSetScissorWithCount_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindVertexBuffers2_PostCall", &table->CmdBindVertexBuffers2_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthTestEnable_PostCall", &table->CmdSetDepthTestEnable_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthWriteEnable_PostCall", &table->CmdSetDepthWriteEnable_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthCompareOp_PostCall", &table->CmdSetDepthCompareOp_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthBoundsTestEnable_PostCall", &table->CmdSetDepthBoundsTestEnable_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilTestEnable_PostCall", &table->CmdSetStencilTestEnable_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilOp_PostCall", &table->CmdSetStencilOp_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetRasterizerDiscardEnable_PostCall", &table->CmdSetRasterizerDiscardEnable_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthBiasEnable_PostCall", &table->CmdSetDepthBiasEnable_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPrimitiveRestartEnable_PostCall", &table->CmdSetPrimitiveRestartEnable_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceBufferMemoryRequirements_PostCall", &table->GetDeviceBufferMemoryRequirements_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceImageMemoryRequirements_PostCall", &table->GetDeviceImageMemoryRequirements_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceImageSparseMemoryRequirements_PostCall", &table->GetDeviceImageSparseMemoryRequirements_PostCall);
    LoadPostFunction(gpa, handle, "DestroySurfaceKHR_PostCall", &table->DestroySurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfaceSupportKHR_PostCall", &table->GetPhysicalDeviceSurfaceSupportKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall", &table->GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfaceFormatsKHR_PostCall", &table->GetPhysicalDeviceSurfaceFormatsKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfacePresentModesKHR_PostCall", &table->GetPhysicalDeviceSurfacePresentModesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateSwapchainKHR_PostCall", &table->CreateSwapchainKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroySwapchainKHR_PostCall", &table->DestroySwapchainKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetSwapchainImagesKHR_PostCall", &table->GetSwapchainImagesKHR_PostCall);
    LoadPostFunction(gpa, handle, "AcquireNextImageKHR_PostCall", &table->AcquireNextImageKHR_PostCall);
    LoadPostFunction(gpa, handle, "QueuePresentKHR_PostCall", &table->QueuePresentKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceGroupPresentCapabilitiesKHR_PostCall", &table->GetDeviceGroupPresentCapabilitiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceGroupSurfacePresentModesKHR_PostCall", &table->GetDeviceGroupSurfacePresentModesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDevicePresentRectanglesKHR_PostCall", &table->GetPhysicalDevicePresentRectanglesKHR_PostCall);
    LoadPostFunction(gpa, handle, "AcquireNextImage2KHR_PostCall", &table->AcquireNextImage2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceDisplayPropertiesKHR_PostCall", &table->GetPhysicalDeviceDisplayPropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall", &table->GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDisplayPlaneSupportedDisplaysKHR_PostCall", &table->GetDisplayPlaneSupportedDisplaysKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDisplayModePropertiesKHR_PostCall", &table->GetDisplayModePropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateDisplayModeKHR_PostCall", &table->CreateDisplayModeKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDisplayPlaneCapabilitiesKHR_PostCall", &table->GetDisplayPlaneCapabilitiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateDisplayPlaneSurfaceKHR_PostCall", &table->CreateDisplayPlaneSurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateSharedSwapchainsKHR_PostCall", &table->CreateSharedSwapchainsKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateXlibSurfaceKHR_PostCall", &table->CreateXlibSurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceXlibPresentationSupportKHR_PostCall", &table->GetPhysicalDeviceXlibPresentationSupportKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateXcbSurfaceKHR_PostCall", &table->CreateXcbSurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceXcbPresentationSupportKHR_PostCall", &table->GetPhysicalDeviceXcbPresentationSupportKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateWaylandSurfaceKHR_PostCall", &table->CreateWaylandSurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall", &table->GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateAndroidSurfaceKHR_PostCall", &table->CreateAndroidSurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateWin32SurfaceKHR_PostCall", &table->CreateWin32SurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceWin32PresentationSupportKHR_PostCall", &table->GetPhysicalDeviceWin32PresentationSupportKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceVideoCapabilitiesKHR_PostCall", &table->GetPhysicalDeviceVideoCapabilitiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall", &table->GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateVideoSessionKHR_PostCall", &table->CreateVideoSessionKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroyVideoSessionKHR_PostCall", &table->DestroyVideoSessionKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetVideoSessionMemoryRequirementsKHR_PostCall", &table->GetVideoSessionMemoryRequirementsKHR_PostCall);
    LoadPostFunction(gpa, handle, "BindVideoSessionMemoryKHR_PostCall", &table->BindVideoSessionMemoryKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateVideoSessionParametersKHR_PostCall", &table->CreateVideoSessionParametersKHR_PostCall);
    LoadPostFunction(gpa, handle, "UpdateVideoSessionParametersKHR_PostCall", &table->UpdateVideoSessionParametersKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroyVideoSessionParametersKHR_PostCall", &table->DestroyVideoSessionParametersKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginVideoCodingKHR_PostCall", &table->CmdBeginVideoCodingKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndVideoCodingKHR_PostCall", &table->CmdEndVideoCodingKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdControlVideoCodingKHR_PostCall", &table->CmdControlVideoCodingKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdDecodeVideoKHR_PostCall", &table->CmdDecodeVideoKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginRenderingKHR_PostCall", &table->CmdBeginRenderingKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndRenderingKHR_PostCall", &table->CmdEndRenderingKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFeatures2KHR_PostCall", &table->GetPhysicalDeviceFeatures2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceProperties2KHR_PostCall", &table->GetPhysicalDeviceProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFormatProperties2KHR_PostCall", &table->GetPhysicalDeviceFormatProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceImageFormatProperties2KHR_PostCall", &table->GetPhysicalDeviceImageFormatProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall", &table->GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceMemoryProperties2KHR_PostCall", &table->GetPhysicalDeviceMemoryProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall", &table->GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceGroupPeerMemoryFeaturesKHR_PostCall", &table->GetDeviceGroupPeerMemoryFeaturesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDeviceMaskKHR_PostCall", &table->CmdSetDeviceMaskKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdDispatchBaseKHR_PostCall", &table->CmdDispatchBaseKHR_PostCall);
    LoadPostFunction(gpa, handle, "TrimCommandPoolKHR_PostCall", &table->TrimCommandPoolKHR_PostCall);
    LoadPostFunction(gpa, handle, "EnumeratePhysicalDeviceGroupsKHR_PostCall", &table->EnumeratePhysicalDeviceGroupsKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall", &table->GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryWin32HandleKHR_PostCall", &table->GetMemoryWin32HandleKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryWin32HandlePropertiesKHR_PostCall", &table->GetMemoryWin32HandlePropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryFdKHR_PostCall", &table->GetMemoryFdKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryFdPropertiesKHR_PostCall", &table->GetMemoryFdPropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall", &table->GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "ImportSemaphoreWin32HandleKHR_PostCall", &table->ImportSemaphoreWin32HandleKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetSemaphoreWin32HandleKHR_PostCall", &table->GetSemaphoreWin32HandleKHR_PostCall);
    LoadPostFunction(gpa, handle, "ImportSemaphoreFdKHR_PostCall", &table->ImportSemaphoreFdKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetSemaphoreFdKHR_PostCall", &table->GetSemaphoreFdKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdPushDescriptorSetKHR_PostCall", &table->CmdPushDescriptorSetKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdPushDescriptorSetWithTemplateKHR_PostCall", &table->CmdPushDescriptorSetWithTemplateKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateDescriptorUpdateTemplateKHR_PostCall", &table->CreateDescriptorUpdateTemplateKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDescriptorUpdateTemplateKHR_PostCall", &table->DestroyDescriptorUpdateTemplateKHR_PostCall);
    LoadPostFunction(gpa, handle, "UpdateDescriptorSetWithTemplateKHR_PostCall", &table->UpdateDescriptorSetWithTemplateKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateRenderPass2KHR_PostCall", &table->CreateRenderPass2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginRenderPass2KHR_PostCall", &table->CmdBeginRenderPass2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdNextSubpass2KHR_PostCall", &table->CmdNextSubpass2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndRenderPass2KHR_PostCall", &table->CmdEndRenderPass2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetSwapchainStatusKHR_PostCall", &table->GetSwapchainStatusKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalFencePropertiesKHR_PostCall", &table->GetPhysicalDeviceExternalFencePropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "ImportFenceWin32HandleKHR_PostCall", &table->ImportFenceWin32HandleKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetFenceWin32HandleKHR_PostCall", &table->GetFenceWin32HandleKHR_PostCall);
    LoadPostFunction(gpa, handle, "ImportFenceFdKHR_PostCall", &table->ImportFenceFdKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetFenceFdKHR_PostCall", &table->GetFenceFdKHR_PostCall);
    LoadPostFunction(gpa, handle, "EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall", &table->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall", &table->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall);
    LoadPostFunction(gpa, handle, "AcquireProfilingLockKHR_PostCall", &table->AcquireProfilingLockKHR_PostCall);
    LoadPostFunction(gpa, handle, "ReleaseProfilingLockKHR_PostCall", &table->ReleaseProfilingLockKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall", &table->GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfaceFormats2KHR_PostCall", &table->GetPhysicalDeviceSurfaceFormats2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceDisplayProperties2KHR_PostCall", &table->GetPhysicalDeviceDisplayProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall", &table->GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDisplayModeProperties2KHR_PostCall", &table->GetDisplayModeProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDisplayPlaneCapabilities2KHR_PostCall", &table->GetDisplayPlaneCapabilities2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetImageMemoryRequirements2KHR_PostCall", &table->GetImageMemoryRequirements2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferMemoryRequirements2KHR_PostCall", &table->GetBufferMemoryRequirements2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetImageSparseMemoryRequirements2KHR_PostCall", &table->GetImageSparseMemoryRequirements2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateSamplerYcbcrConversionKHR_PostCall", &table->CreateSamplerYcbcrConversionKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroySamplerYcbcrConversionKHR_PostCall", &table->DestroySamplerYcbcrConversionKHR_PostCall);
    LoadPostFunction(gpa, handle, "BindBufferMemory2KHR_PostCall", &table->BindBufferMemory2KHR_PostCall);
    LoadPostFunction(gpa, handle, "BindImageMemory2KHR_PostCall", &table->BindImageMemory2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDescriptorSetLayoutSupportKHR_PostCall", &table->GetDescriptorSetLayoutSupportKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndirectCountKHR_PostCall", &table->CmdDrawIndirectCountKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndexedIndirectCountKHR_PostCall", &table->CmdDrawIndexedIndirectCountKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetSemaphoreCounterValueKHR_PostCall", &table->GetSemaphoreCounterValueKHR_PostCall);
    LoadPostFunction(gpa, handle, "WaitSemaphoresKHR_PostCall", &table->WaitSemaphoresKHR_PostCall);
    LoadPostFunction(gpa, handle, "SignalSemaphoreKHR_PostCall", &table->SignalSemaphoreKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFragmentShadingRatesKHR_PostCall", &table->GetPhysicalDeviceFragmentShadingRatesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetFragmentShadingRateKHR_PostCall", &table->CmdSetFragmentShadingRateKHR_PostCall);
    LoadPostFunction(gpa, handle, "WaitForPresentKHR_PostCall", &table->WaitForPresentKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferDeviceAddressKHR_PostCall", &table->GetBufferDeviceAddressKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferOpaqueCaptureAddressKHR_PostCall", &table->GetBufferOpaqueCaptureAddressKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall", &table->GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateDeferredOperationKHR_PostCall", &table->CreateDeferredOperationKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDeferredOperationKHR_PostCall", &table->DestroyDeferredOperationKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeferredOperationMaxConcurrencyKHR_PostCall", &table->GetDeferredOperationMaxConcurrencyKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeferredOperationResultKHR_PostCall", &table->GetDeferredOperationResultKHR_PostCall);
    LoadPostFunction(gpa, handle, "DeferredOperationJoinKHR_PostCall", &table->DeferredOperationJoinKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPipelineExecutablePropertiesKHR_PostCall", &table->GetPipelineExecutablePropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPipelineExecutableStatisticsKHR_PostCall", &table->GetPipelineExecutableStatisticsKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPipelineExecutableInternalRepresentationsKHR_PostCall", &table->GetPipelineExecutableInternalRepresentationsKHR_PostCall);
    LoadPostFunction(gpa, handle, "MapMemory2KHR_PostCall", &table->MapMemory2KHR_PostCall);
    LoadPostFunction(gpa, handle, "UnmapMemory2KHR_PostCall", &table->UnmapMemory2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdEncodeVideoKHR_PostCall", &table->CmdEncodeVideoKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetEvent2KHR_PostCall", &table->CmdSetEvent2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdResetEvent2KHR_PostCall", &table->CmdResetEvent2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdWaitEvents2KHR_PostCall", &table->CmdWaitEvents2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdPipelineBarrier2KHR_PostCall", &table->CmdPipelineBarrier2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteTimestamp2KHR_PostCall", &table->CmdWriteTimestamp2KHR_PostCall);
    LoadPostFunction(gpa, handle, "QueueSubmit2KHR_PostCall", &table->QueueSubmit2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteBufferMarker2AMD_PostCall", &table->CmdWriteBufferMarker2AMD_PostCall);
    LoadPostFunction(gpa, handle, "GetQueueCheckpointData2NV_PostCall", &table->GetQueueCheckpointData2NV_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyBuffer2KHR_PostCall", &table->CmdCopyBuffer2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyImage2KHR_PostCall", &table->CmdCopyImage2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyBufferToImage2KHR_PostCall", &table->CmdCopyBufferToImage2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyImageToBuffer2KHR_PostCall", &table->CmdCopyImageToBuffer2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdBlitImage2KHR_PostCall", &table->CmdBlitImage2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdResolveImage2KHR_PostCall", &table->CmdResolveImage2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdTraceRaysIndirect2KHR_PostCall", &table->CmdTraceRaysIndirect2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceBufferMemoryRequirementsKHR_PostCall", &table->GetDeviceBufferMemoryRequirementsKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceImageMemoryRequirementsKHR_PostCall", &table->GetDeviceImageMemoryRequirementsKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceImageSparseMemoryRequirementsKHR_PostCall", &table->GetDeviceImageSparseMemoryRequirementsKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateDebugReportCallbackEXT_PostCall", &table->CreateDebugReportCallbackEXT_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDebugReportCallbackEXT_PostCall", &table->DestroyDebugReportCallbackEXT_PostCall);
    LoadPostFunction(gpa, handle, "DebugReportMessageEXT_PostCall", &table->DebugReportMessageEXT_PostCall);
    LoadPostFunction(gpa, handle, "DebugMarkerSetObjectTagEXT_PostCall", &table->DebugMarkerSetObjectTagEXT_PostCall);
    LoadPostFunction(gpa, handle, "DebugMarkerSetObjectNameEXT_PostCall", &table->DebugMarkerSetObjectNameEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDebugMarkerBeginEXT_PostCall", &table->CmdDebugMarkerBeginEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDebugMarkerEndEXT_PostCall", &table->CmdDebugMarkerEndEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDebugMarkerInsertEXT_PostCall", &table->CmdDebugMarkerInsertEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindTransformFeedbackBuffersEXT_PostCall", &table->CmdBindTransformFeedbackBuffersEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginTransformFeedbackEXT_PostCall", &table->CmdBeginTransformFeedbackEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndTransformFeedbackEXT_PostCall", &table->CmdEndTransformFeedbackEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginQueryIndexedEXT_PostCall", &table->CmdBeginQueryIndexedEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndQueryIndexedEXT_PostCall", &table->CmdEndQueryIndexedEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndirectByteCountEXT_PostCall", &table->CmdDrawIndirectByteCountEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetImageViewHandleNVX_PostCall", &table->GetImageViewHandleNVX_PostCall);
    LoadPostFunction(gpa, handle, "GetImageViewAddressNVX_PostCall", &table->GetImageViewAddressNVX_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndirectCountAMD_PostCall", &table->CmdDrawIndirectCountAMD_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndexedIndirectCountAMD_PostCall", &table->CmdDrawIndexedIndirectCountAMD_PostCall);
    LoadPostFunction(gpa, handle, "GetShaderInfoAMD_PostCall", &table->GetShaderInfoAMD_PostCall);
    LoadPostFunction(gpa, handle, "CreateStreamDescriptorSurfaceGGP_PostCall", &table->CreateStreamDescriptorSurfaceGGP_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall", &table->GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryWin32HandleNV_PostCall", &table->GetMemoryWin32HandleNV_PostCall);
    LoadPostFunction(gpa, handle, "CreateViSurfaceNN_PostCall", &table->CreateViSurfaceNN_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginConditionalRenderingEXT_PostCall", &table->CmdBeginConditionalRenderingEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndConditionalRenderingEXT_PostCall", &table->CmdEndConditionalRenderingEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewportWScalingNV_PostCall", &table->CmdSetViewportWScalingNV_PostCall);
    LoadPostFunction(gpa, handle, "ReleaseDisplayEXT_PostCall", &table->ReleaseDisplayEXT_PostCall);
    LoadPostFunction(gpa, handle, "AcquireXlibDisplayEXT_PostCall", &table->AcquireXlibDisplayEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetRandROutputDisplayEXT_PostCall", &table->GetRandROutputDisplayEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall", &table->GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall);
    LoadPostFunction(gpa, handle, "DisplayPowerControlEXT_PostCall", &table->DisplayPowerControlEXT_PostCall);
    LoadPostFunction(gpa, handle, "RegisterDeviceEventEXT_PostCall", &table->RegisterDeviceEventEXT_PostCall);
    LoadPostFunction(gpa, handle, "RegisterDisplayEventEXT_PostCall", &table->RegisterDisplayEventEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetSwapchainCounterEXT_PostCall", &table->GetSwapchainCounterEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetRefreshCycleDurationGOOGLE_PostCall", &table->GetRefreshCycleDurationGOOGLE_PostCall);
    LoadPostFunction(gpa, handle, "GetPastPresentationTimingGOOGLE_PostCall", &table->GetPastPresentationTimingGOOGLE_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDiscardRectangleEXT_PostCall", &table->CmdSetDiscardRectangleEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDiscardRectangleEnableEXT_PostCall", &table->CmdSetDiscardRectangleEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDiscardRectangleModeEXT_PostCall", &table->CmdSetDiscardRectangleModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "SetHdrMetadataEXT_PostCall", &table->SetHdrMetadataEXT_PostCall);
    LoadPostFunction(gpa, handle, "CreateIOSSurfaceMVK_PostCall", &table->CreateIOSSurfaceMVK_PostCall);
    LoadPostFunction(gpa, handle, "CreateMacOSSurfaceMVK_PostCall", &table->CreateMacOSSurfaceMVK_PostCall);
    LoadPostFunction(gpa, handle, "SetDebugUtilsObjectNameEXT_PostCall", &table->SetDebugUtilsObjectNameEXT_PostCall);
    LoadPostFunction(gpa, handle, "SetDebugUtilsObjectTagEXT_PostCall", &table->SetDebugUtilsObjectTagEXT_PostCall);
    LoadPostFunction(gpa, handle, "QueueBeginDebugUtilsLabelEXT_PostCall", &table->QueueBeginDebugUtilsLabelEXT_PostCall);
    LoadPostFunction(gpa, handle, "QueueEndDebugUtilsLabelEXT_PostCall", &table->QueueEndDebugUtilsLabelEXT_PostCall);
    LoadPostFunction(gpa, handle, "QueueInsertDebugUtilsLabelEXT_PostCall", &table->QueueInsertDebugUtilsLabelEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginDebugUtilsLabelEXT_PostCall", &table->CmdBeginDebugUtilsLabelEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndDebugUtilsLabelEXT_PostCall", &table->CmdEndDebugUtilsLabelEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdInsertDebugUtilsLabelEXT_PostCall", &table->CmdInsertDebugUtilsLabelEXT_PostCall);
    LoadPostFunction(gpa, handle, "CreateDebugUtilsMessengerEXT_PostCall", &table->CreateDebugUtilsMessengerEXT_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDebugUtilsMessengerEXT_PostCall", &table->DestroyDebugUtilsMessengerEXT_PostCall);
    LoadPostFunction(gpa, handle, "SubmitDebugUtilsMessageEXT_PostCall", &table->SubmitDebugUtilsMessageEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetAndroidHardwareBufferPropertiesANDROID_PostCall", &table->GetAndroidHardwareBufferPropertiesANDROID_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryAndroidHardwareBufferANDROID_PostCall", &table->GetMemoryAndroidHardwareBufferANDROID_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetSampleLocationsEXT_PostCall", &table->CmdSetSampleLocationsEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceMultisamplePropertiesEXT_PostCall", &table->GetPhysicalDeviceMultisamplePropertiesEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetImageDrmFormatModifierPropertiesEXT_PostCall", &table->GetImageDrmFormatModifierPropertiesEXT_PostCall);
    LoadPostFunction(gpa, handle, "CreateValidationCacheEXT_PostCall", &table->CreateValidationCacheEXT_PostCall);
    LoadPostFunction(gpa, handle, "DestroyValidationCacheEXT_PostCall", &table->DestroyValidationCacheEXT_PostCall);
    LoadPostFunction(gpa, handle, "MergeValidationCachesEXT_PostCall", &table->MergeValidationCachesEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetValidationCacheDataEXT_PostCall", &table->GetValidationCacheDataEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindShadingRateImageNV_PostCall", &table->CmdBindShadingRateImageNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewportShadingRatePaletteNV_PostCall", &table->CmdSetViewportShadingRatePaletteNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoarseSampleOrderNV_PostCall", &table->CmdSetCoarseSampleOrderNV_PostCall);
    LoadPostFunction(gpa, handle, "CreateAccelerationStructureNV_PostCall", &table->CreateAccelerationStructureNV_PostCall);
    LoadPostFunction(gpa, handle, "DestroyAccelerationStructureNV_PostCall", &table->DestroyAccelerationStructureNV_PostCall);
    LoadPostFunction(gpa, handle, "GetAccelerationStructureMemoryRequirementsNV_PostCall", &table->GetAccelerationStructureMemoryRequirementsNV_PostCall);
    LoadPostFunction(gpa, handle, "BindAccelerationStructureMemoryNV_PostCall", &table->BindAccelerationStructureMemoryNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdBuildAccelerationStructureNV_PostCall", &table->CmdBuildAccelerationStructureNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyAccelerationStructureNV_PostCall", &table->CmdCopyAccelerationStructureNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdTraceRaysNV_PostCall", &table->CmdTraceRaysNV_PostCall);
    LoadPostFunction(gpa, handle, "CreateRayTracingPipelinesNV_PostCall", &table->CreateRayTracingPipelinesNV_PostCall);
    LoadPostFunction(gpa, handle, "GetRayTracingShaderGroupHandlesKHR_PostCall", &table->GetRayTracingShaderGroupHandlesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetRayTracingShaderGroupHandlesNV_PostCall", &table->GetRayTracingShaderGroupHandlesNV_PostCall);
    LoadPostFunction(gpa, handle, "GetAccelerationStructureHandleNV_PostCall", &table->GetAccelerationStructureHandleNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteAccelerationStructuresPropertiesNV_PostCall", &table->CmdWriteAccelerationStructuresPropertiesNV_PostCall);
    LoadPostFunction(gpa, handle, "CompileDeferredNV_PostCall", &table->CompileDeferredNV_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryHostPointerPropertiesEXT_PostCall", &table->GetMemoryHostPointerPropertiesEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteBufferMarkerAMD_PostCall", &table->CmdWriteBufferMarkerAMD_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall", &table->GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetCalibratedTimestampsEXT_PostCall", &table->GetCalibratedTimestampsEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMeshTasksNV_PostCall", &table->CmdDrawMeshTasksNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMeshTasksIndirectNV_PostCall", &table->CmdDrawMeshTasksIndirectNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMeshTasksIndirectCountNV_PostCall", &table->CmdDrawMeshTasksIndirectCountNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetExclusiveScissorEnableNV_PostCall", &table->CmdSetExclusiveScissorEnableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetExclusiveScissorNV_PostCall", &table->CmdSetExclusiveScissorNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCheckpointNV_PostCall", &table->CmdSetCheckpointNV_PostCall);
    LoadPostFunction(gpa, handle, "GetQueueCheckpointDataNV_PostCall", &table->GetQueueCheckpointDataNV_PostCall);
    LoadPostFunction(gpa, handle, "InitializePerformanceApiINTEL_PostCall", &table->InitializePerformanceApiINTEL_PostCall);
    LoadPostFunction(gpa, handle, "UninitializePerformanceApiINTEL_PostCall", &table->UninitializePerformanceApiINTEL_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPerformanceMarkerINTEL_PostCall", &table->CmdSetPerformanceMarkerINTEL_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPerformanceStreamMarkerINTEL_PostCall", &table->CmdSetPerformanceStreamMarkerINTEL_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPerformanceOverrideINTEL_PostCall", &table->CmdSetPerformanceOverrideINTEL_PostCall);
    LoadPostFunction(gpa, handle, "AcquirePerformanceConfigurationINTEL_PostCall", &table->AcquirePerformanceConfigurationINTEL_PostCall);
    LoadPostFunction(gpa, handle, "ReleasePerformanceConfigurationINTEL_PostCall", &table->ReleasePerformanceConfigurationINTEL_PostCall);
    LoadPostFunction(gpa, handle, "QueueSetPerformanceConfigurationINTEL_PostCall", &table->QueueSetPerformanceConfigurationINTEL_PostCall);
    LoadPostFunction(gpa, handle, "GetPerformanceParameterINTEL_PostCall", &table->GetPerformanceParameterINTEL_PostCall);
    LoadPostFunction(gpa, handle, "SetLocalDimmingAMD_PostCall", &table->SetLocalDimmingAMD_PostCall);
    LoadPostFunction(gpa, handle, "CreateImagePipeSurfaceFUCHSIA_PostCall", &table->CreateImagePipeSurfaceFUCHSIA_PostCall);
    LoadPostFunction(gpa, handle, "CreateMetalSurfaceEXT_PostCall", &table->CreateMetalSurfaceEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferDeviceAddressEXT_PostCall", &table->GetBufferDeviceAddressEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceToolPropertiesEXT_PostCall", &table->GetPhysicalDeviceToolPropertiesEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall", &table->GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall", &table->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfacePresentModes2EXT_PostCall", &table->GetPhysicalDeviceSurfacePresentModes2EXT_PostCall);
    LoadPostFunction(gpa, handle, "AcquireFullScreenExclusiveModeEXT_PostCall", &table->AcquireFullScreenExclusiveModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "ReleaseFullScreenExclusiveModeEXT_PostCall", &table->ReleaseFullScreenExclusiveModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceGroupSurfacePresentModes2EXT_PostCall", &table->GetDeviceGroupSurfacePresentModes2EXT_PostCall);
    LoadPostFunction(gpa, handle, "CreateHeadlessSurfaceEXT_PostCall", &table->CreateHeadlessSurfaceEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetLineStippleEXT_PostCall", &table->CmdSetLineStippleEXT_PostCall);
    LoadPostFunction(gpa, handle, "ResetQueryPoolEXT_PostCall", &table->ResetQueryPoolEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCullModeEXT_PostCall", &table->CmdSetCullModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetFrontFaceEXT_PostCall", &table->CmdSetFrontFaceEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPrimitiveTopologyEXT_PostCall", &table->CmdSetPrimitiveTopologyEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewportWithCountEXT_PostCall", &table->CmdSetViewportWithCountEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetScissorWithCountEXT_PostCall", &table->CmdSetScissorWithCountEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindVertexBuffers2EXT_PostCall", &table->CmdBindVertexBuffers2EXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthTestEnableEXT_PostCall", &table->CmdSetDepthTestEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthWriteEnableEXT_PostCall", &table->CmdSetDepthWriteEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthCompareOpEXT_PostCall", &table->CmdSetDepthCompareOpEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthBoundsTestEnableEXT_PostCall", &table->CmdSetDepthBoundsTestEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilTestEnableEXT_PostCall", &table->CmdSetStencilTestEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilOpEXT_PostCall", &table->CmdSetStencilOpEXT_PostCall);
    LoadPostFunction(gpa, handle, "ReleaseSwapchainImagesEXT_PostCall", &table->ReleaseSwapchainImagesEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetGeneratedCommandsMemoryRequirementsNV_PostCall", &table->GetGeneratedCommandsMemoryRequirementsNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdPreprocessGeneratedCommandsNV_PostCall", &table->CmdPreprocessGeneratedCommandsNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdExecuteGeneratedCommandsNV_PostCall", &table->CmdExecuteGeneratedCommandsNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindPipelineShaderGroupNV_PostCall", &table->CmdBindPipelineShaderGroupNV_PostCall);
    LoadPostFunction(gpa, handle, "CreateIndirectCommandsLayoutNV_PostCall", &table->CreateIndirectCommandsLayoutNV_PostCall);
    LoadPostFunction(gpa, handle, "DestroyIndirectCommandsLayoutNV_PostCall", &table->DestroyIndirectCommandsLayoutNV_PostCall);
    LoadPostFunction(gpa, handle, "AcquireDrmDisplayEXT_PostCall", &table->AcquireDrmDisplayEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetDrmDisplayEXT_PostCall", &table->GetDrmDisplayEXT_PostCall);
    LoadPostFunction(gpa, handle, "CreatePrivateDataSlotEXT_PostCall", &table->CreatePrivateDataSlotEXT_PostCall);
    LoadPostFunction(gpa, handle, "DestroyPrivateDataSlotEXT_PostCall", &table->DestroyPrivateDataSlotEXT_PostCall);
    LoadPostFunction(gpa, handle, "SetPrivateDataEXT_PostCall", &table->SetPrivateDataEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPrivateDataEXT_PostCall", &table->GetPrivateDataEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetFragmentShadingRateEnumNV_PostCall", &table->CmdSetFragmentShadingRateEnumNV_PostCall);
    LoadPostFunction(gpa, handle, "GetImageSubresourceLayout2EXT_PostCall", &table->GetImageSubresourceLayout2EXT_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceFaultInfoEXT_PostCall", &table->GetDeviceFaultInfoEXT_PostCall);
    LoadPostFunction(gpa, handle, "AcquireWinrtDisplayNV_PostCall", &table->AcquireWinrtDisplayNV_PostCall);
    LoadPostFunction(gpa, handle, "GetWinrtDisplayNV_PostCall", &table->GetWinrtDisplayNV_PostCall);
    LoadPostFunction(gpa, handle, "CreateDirectFBSurfaceEXT_PostCall", &table->CreateDirectFBSurfaceEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall", &table->GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetVertexInputEXT_PostCall", &table->CmdSetVertexInputEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryZirconHandleFUCHSIA_PostCall", &table->GetMemoryZirconHandleFUCHSIA_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryZirconHandlePropertiesFUCHSIA_PostCall", &table->GetMemoryZirconHandlePropertiesFUCHSIA_PostCall);
    LoadPostFunction(gpa, handle, "ImportSemaphoreZirconHandleFUCHSIA_PostCall", &table->ImportSemaphoreZirconHandleFUCHSIA_PostCall);
    LoadPostFunction(gpa, handle, "GetSemaphoreZirconHandleFUCHSIA_PostCall", &table->GetSemaphoreZirconHandleFUCHSIA_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindInvocationMaskHUAWEI_PostCall", &table->CmdBindInvocationMaskHUAWEI_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryRemoteAddressNV_PostCall", &table->GetMemoryRemoteAddressNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPatchControlPointsEXT_PostCall", &table->CmdSetPatchControlPointsEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetRasterizerDiscardEnableEXT_PostCall", &table->CmdSetRasterizerDiscardEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthBiasEnableEXT_PostCall", &table->CmdSetDepthBiasEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetLogicOpEXT_PostCall", &table->CmdSetLogicOpEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPrimitiveRestartEnableEXT_PostCall", &table->CmdSetPrimitiveRestartEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CreateScreenSurfaceQNX_PostCall", &table->CreateScreenSurfaceQNX_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceScreenPresentationSupportQNX_PostCall", &table->GetPhysicalDeviceScreenPresentationSupportQNX_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetColorWriteEnableEXT_PostCall", &table->CmdSetColorWriteEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMultiEXT_PostCall", &table->CmdDrawMultiEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMultiIndexedEXT_PostCall", &table->CmdDrawMultiIndexedEXT_PostCall);
    LoadPostFunction(gpa, handle, "CreateMicromapEXT_PostCall", &table->CreateMicromapEXT_PostCall);
    LoadPostFunction(gpa, handle, "DestroyMicromapEXT_PostCall", &table->DestroyMicromapEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBuildMicromapsEXT_PostCall", &table->CmdBuildMicromapsEXT_PostCall);
    LoadPostFunction(gpa, handle, "BuildMicromapsEXT_PostCall", &table->BuildMicromapsEXT_PostCall);
    LoadPostFunction(gpa, handle, "CopyMicromapEXT_PostCall", &table->CopyMicromapEXT_PostCall);
    LoadPostFunction(gpa, handle, "CopyMicromapToMemoryEXT_PostCall", &table->CopyMicromapToMemoryEXT_PostCall);
    LoadPostFunction(gpa, handle, "CopyMemoryToMicromapEXT_PostCall", &table->CopyMemoryToMicromapEXT_PostCall);
    LoadPostFunction(gpa, handle, "WriteMicromapsPropertiesEXT_PostCall", &table->WriteMicromapsPropertiesEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyMicromapEXT_PostCall", &table->CmdCopyMicromapEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyMicromapToMemoryEXT_PostCall", &table->CmdCopyMicromapToMemoryEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyMemoryToMicromapEXT_PostCall", &table->CmdCopyMemoryToMicromapEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteMicromapsPropertiesEXT_PostCall", &table->CmdWriteMicromapsPropertiesEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceMicromapCompatibilityEXT_PostCall", &table->GetDeviceMicromapCompatibilityEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetMicromapBuildSizesEXT_PostCall", &table->GetMicromapBuildSizesEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawClusterHUAWEI_PostCall", &table->CmdDrawClusterHUAWEI_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawClusterIndirectHUAWEI_PostCall", &table->CmdDrawClusterIndirectHUAWEI_PostCall);
    LoadPostFunction(gpa, handle, "SetDeviceMemoryPriorityEXT_PostCall", &table->SetDeviceMemoryPriorityEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall", &table->GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall);
    LoadPostFunction(gpa, handle, "GetDescriptorSetHostMappingVALVE_PostCall", &table->GetDescriptorSetHostMappingVALVE_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetTessellationDomainOriginEXT_PostCall", &table->CmdSetTessellationDomainOriginEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthClampEnableEXT_PostCall", &table->CmdSetDepthClampEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPolygonModeEXT_PostCall", &table->CmdSetPolygonModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetRasterizationSamplesEXT_PostCall", &table->CmdSetRasterizationSamplesEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetSampleMaskEXT_PostCall", &table->CmdSetSampleMaskEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetAlphaToCoverageEnableEXT_PostCall", &table->CmdSetAlphaToCoverageEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetAlphaToOneEnableEXT_PostCall", &table->CmdSetAlphaToOneEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetLogicOpEnableEXT_PostCall", &table->CmdSetLogicOpEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetColorBlendEnableEXT_PostCall", &table->CmdSetColorBlendEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetColorBlendEquationEXT_PostCall", &table->CmdSetColorBlendEquationEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetColorWriteMaskEXT_PostCall", &table->CmdSetColorWriteMaskEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetRasterizationStreamEXT_PostCall", &table->CmdSetRasterizationStreamEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetConservativeRasterizationModeEXT_PostCall", &table->CmdSetConservativeRasterizationModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall", &table->CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthClipEnableEXT_PostCall", &table->CmdSetDepthClipEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetSampleLocationsEnableEXT_PostCall", &table->CmdSetSampleLocationsEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetColorBlendAdvancedEXT_PostCall", &table->CmdSetColorBlendAdvancedEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetProvokingVertexModeEXT_PostCall", &table->CmdSetProvokingVertexModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetLineRasterizationModeEXT_PostCall", &table->CmdSetLineRasterizationModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetLineStippleEnableEXT_PostCall", &table->CmdSetLineStippleEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthClipNegativeOneToOneEXT_PostCall", &table->CmdSetDepthClipNegativeOneToOneEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewportWScalingEnableNV_PostCall", &table->CmdSetViewportWScalingEnableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewportSwizzleNV_PostCall", &table->CmdSetViewportSwizzleNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoverageToColorEnableNV_PostCall", &table->CmdSetCoverageToColorEnableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoverageToColorLocationNV_PostCall", &table->CmdSetCoverageToColorLocationNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoverageModulationModeNV_PostCall", &table->CmdSetCoverageModulationModeNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoverageModulationTableEnableNV_PostCall", &table->CmdSetCoverageModulationTableEnableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoverageModulationTableNV_PostCall", &table->CmdSetCoverageModulationTableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetShadingRateImageEnableNV_PostCall", &table->CmdSetShadingRateImageEnableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetRepresentativeFragmentTestEnableNV_PostCall", &table->CmdSetRepresentativeFragmentTestEnableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoverageReductionModeNV_PostCall", &table->CmdSetCoverageReductionModeNV_PostCall);
    LoadPostFunction(gpa, handle, "GetShaderModuleIdentifierEXT_PostCall", &table->GetShaderModuleIdentifierEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetShaderModuleCreateInfoIdentifierEXT_PostCall", &table->GetShaderModuleCreateInfoIdentifierEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall", &table->GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall);
    LoadPostFunction(gpa, handle, "CreateOpticalFlowSessionNV_PostCall", &table->CreateOpticalFlowSessionNV_PostCall);
    LoadPostFunction(gpa, handle, "DestroyOpticalFlowSessionNV_PostCall", &table->DestroyOpticalFlowSessionNV_PostCall);
    LoadPostFunction(gpa, handle, "BindOpticalFlowSessionImageNV_PostCall", &table->BindOpticalFlowSessionImageNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdOpticalFlowExecuteNV_PostCall", &table->CmdOpticalFlowExecuteNV_PostCall);
    LoadPostFunction(gpa, handle, "CreateShadersEXT_PostCall", &table->CreateShadersEXT_PostCall);
    LoadPostFunction(gpa, handle, "DestroyShaderEXT_PostCall", &table->DestroyShaderEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetShaderBinaryDataEXT_PostCall", &table->GetShaderBinaryDataEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindShadersEXT_PostCall", &table->CmdBindShadersEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetFramebufferTilePropertiesQCOM_PostCall", &table->GetFramebufferTilePropertiesQCOM_PostCall);
    LoadPostFunction(gpa, handle, "GetDynamicRenderingTilePropertiesQCOM_PostCall", &table->GetDynamicRenderingTilePropertiesQCOM_PostCall);
    LoadPostFunction(gpa, handle, "CreateAccelerationStructureKHR_PostCall", &table->CreateAccelerationStructureKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroyAccelerationStructureKHR_PostCall", &table->DestroyAccelerationStructureKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdBuildAccelerationStructuresKHR_PostCall", &table->CmdBuildAccelerationStructuresKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdBuildAccelerationStructuresIndirectKHR_PostCall", &table->CmdBuildAccelerationStructuresIndirectKHR_PostCall);
    LoadPostFunction(gpa, handle, "BuildAccelerationStructuresKHR_PostCall", &table->BuildAccelerationStructuresKHR_PostCall);
    LoadPostFunction(gpa, handle, "CopyAccelerationStructureKHR_PostCall", &table->CopyAccelerationStructureKHR_PostCall);
    LoadPostFunction(gpa, handle, "CopyAccelerationStructureToMemoryKHR_PostCall", &table->CopyAccelerationStructureToMemoryKHR_PostCall);
    LoadPostFunction(gpa, handle, "CopyMemoryToAccelerationStructureKHR_PostCall", &table->CopyMemoryToAccelerationStructureKHR_PostCall);
    LoadPostFunction(gpa, handle, "WriteAccelerationStructuresPropertiesKHR_PostCall", &table->WriteAccelerationStructuresPropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyAccelerationStructureKHR_PostCall", &table->CmdCopyAccelerationStructureKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyAccelerationStructureToMemoryKHR_PostCall", &table->CmdCopyAccelerationStructureToMemoryKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyMemoryToAccelerationStructureKHR_PostCall", &table->CmdCopyMemoryToAccelerationStructureKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetAccelerationStructureDeviceAddressKHR_PostCall", &table->GetAccelerationStructureDeviceAddressKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteAccelerationStructuresPropertiesKHR_PostCall", &table->CmdWriteAccelerationStructuresPropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceAccelerationStructureCompatibilityKHR_PostCall", &table->GetDeviceAccelerationStructureCompatibilityKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetAccelerationStructureBuildSizesKHR_PostCall", &table->GetAccelerationStructureBuildSizesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdTraceRaysKHR_PostCall", &table->CmdTraceRaysKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateRayTracingPipelinesKHR_PostCall", &table->CreateRayTracingPipelinesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall", &table->GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdTraceRaysIndirectKHR_PostCall", &table->CmdTraceRaysIndirectKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetRayTracingShaderGroupStackSizeKHR_PostCall", &table->GetRayTracingShaderGroupStackSizeKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetRayTracingPipelineStackSizeKHR_PostCall", &table->CmdSetRayTracingPipelineStackSizeKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMeshTasksEXT_PostCall", &table->CmdDrawMeshTasksEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMeshTasksIndirectEXT_PostCall", &table->CmdDrawMeshTasksIndirectEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMeshTasksIndirectCountEXT_PostCall", &table->CmdDrawMeshTasksIndirectCountEXT_PostCall);
}

// clang-format off

GFXRECON_END_NAMESPACE(capture)
GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_PLUGINS_CAPTURE_FUNC_TABLE_POST_H

