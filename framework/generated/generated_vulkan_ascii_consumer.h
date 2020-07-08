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

#ifndef  GFXRECON_GENERATED_VULKAN_ASCII_CONSUMER_H
#define  GFXRECON_GENERATED_VULKAN_ASCII_CONSUMER_H

#include "decode/vulkan_ascii_consumer_base.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanAsciiConsumer : public VulkanAsciiConsumerBase
{
  public:
    VulkanAsciiConsumer() { }

    virtual ~VulkanAsciiConsumer() override { }

    virtual void Process_vkCreateInstance(
        VkResult                                    returnValue,
        StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkInstance>*           pInstance) override;

    virtual void Process_vkDestroyInstance(
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkEnumeratePhysicalDevices(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
        HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices) override;

    virtual void Process_vkGetPhysicalDeviceFeatures(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties(
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkImageTiling                               tiling,
        VkImageUsageFlags                           usage,
        VkImageCreateFlags                          flags,
        StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceProperties(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties(
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
        StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties) override;

    virtual void Process_vkCreateDevice(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDevice>*             pDevice) override;

    virtual void Process_vkDestroyDevice(
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetDeviceQueue(
        format::HandleId                            device,
        uint32_t                                    queueFamilyIndex,
        uint32_t                                    queueIndex,
        HandlePointerDecoder<VkQueue>*              pQueue) override;

    virtual void Process_vkQueueSubmit(
        VkResult                                    returnValue,
        format::HandleId                            queue,
        uint32_t                                    submitCount,
        StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
        format::HandleId                            fence) override;

    virtual void Process_vkQueueWaitIdle(
        VkResult                                    returnValue,
        format::HandleId                            queue) override;

    virtual void Process_vkDeviceWaitIdle(
        VkResult                                    returnValue,
        format::HandleId                            device) override;

    virtual void Process_vkAllocateMemory(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDeviceMemory>*       pMemory) override;

    virtual void Process_vkFreeMemory(
        format::HandleId                            device,
        format::HandleId                            memory,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkMapMemory(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            memory,
        VkDeviceSize                                offset,
        VkDeviceSize                                size,
        VkMemoryMapFlags                            flags,
        PointerDecoder<uint64_t, void*>*            ppData) override;

    virtual void Process_vkUnmapMemory(
        format::HandleId                            device,
        format::HandleId                            memory) override;

    virtual void Process_vkFlushMappedMemoryRanges(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    memoryRangeCount,
        StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges) override;

    virtual void Process_vkInvalidateMappedMemoryRanges(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    memoryRangeCount,
        StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges) override;

    virtual void Process_vkGetDeviceMemoryCommitment(
        format::HandleId                            device,
        format::HandleId                            memory,
        PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes) override;

    virtual void Process_vkBindBufferMemory(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            buffer,
        format::HandleId                            memory,
        VkDeviceSize                                memoryOffset) override;

    virtual void Process_vkBindImageMemory(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            image,
        format::HandleId                            memory,
        VkDeviceSize                                memoryOffset) override;

    virtual void Process_vkGetBufferMemoryRequirements(
        format::HandleId                            device,
        format::HandleId                            buffer,
        StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) override;

    virtual void Process_vkGetImageMemoryRequirements(
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) override;

    virtual void Process_vkGetImageSparseMemoryRequirements(
        format::HandleId                            device,
        format::HandleId                            image,
        PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties(
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkSampleCountFlagBits                       samples,
        VkImageUsageFlags                           usage,
        VkImageTiling                               tiling,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties) override;

    virtual void Process_vkQueueBindSparse(
        VkResult                                    returnValue,
        format::HandleId                            queue,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
        format::HandleId                            fence) override;

    virtual void Process_vkCreateFence(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkFence>*              pFence) override;

    virtual void Process_vkDestroyFence(
        format::HandleId                            device,
        format::HandleId                            fence,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkResetFences(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    fenceCount,
        HandlePointerDecoder<VkFence>*              pFences) override;

    virtual void Process_vkGetFenceStatus(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            fence) override;

    virtual void Process_vkWaitForFences(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    fenceCount,
        HandlePointerDecoder<VkFence>*              pFences,
        VkBool32                                    waitAll,
        uint64_t                                    timeout) override;

    virtual void Process_vkCreateSemaphore(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSemaphore>*          pSemaphore) override;

    virtual void Process_vkDestroySemaphore(
        format::HandleId                            device,
        format::HandleId                            semaphore,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateEvent(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkEvent>*              pEvent) override;

    virtual void Process_vkDestroyEvent(
        format::HandleId                            device,
        format::HandleId                            event,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetEventStatus(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            event) override;

    virtual void Process_vkSetEvent(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            event) override;

    virtual void Process_vkResetEvent(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            event) override;

    virtual void Process_vkCreateQueryPool(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkQueryPool>*          pQueryPool) override;

    virtual void Process_vkDestroyQueryPool(
        format::HandleId                            device,
        format::HandleId                            queryPool,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetQueryPoolResults(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData,
        VkDeviceSize                                stride,
        VkQueryResultFlags                          flags) override;

    virtual void Process_vkCreateBuffer(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkBuffer>*             pBuffer) override;

    virtual void Process_vkDestroyBuffer(
        format::HandleId                            device,
        format::HandleId                            buffer,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateBufferView(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkBufferView>*         pView) override;

    virtual void Process_vkDestroyBufferView(
        format::HandleId                            device,
        format::HandleId                            bufferView,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateImage(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkImage>*              pImage) override;

    virtual void Process_vkDestroyImage(
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetImageSubresourceLayout(
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
        StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout) override;

    virtual void Process_vkCreateImageView(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkImageView>*          pView) override;

    virtual void Process_vkDestroyImageView(
        format::HandleId                            device,
        format::HandleId                            imageView,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateShaderModule(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkShaderModule>*       pShaderModule) override;

    virtual void Process_vkDestroyShaderModule(
        format::HandleId                            device,
        format::HandleId                            shaderModule,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreatePipelineCache(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipelineCache>*      pPipelineCache) override;

    virtual void Process_vkDestroyPipelineCache(
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetPipelineCacheData(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        PointerDecoder<size_t>*                     pDataSize,
        PointerDecoder<uint8_t>*                    pData) override;

    virtual void Process_vkMergePipelineCaches(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            dstCache,
        uint32_t                                    srcCacheCount,
        HandlePointerDecoder<VkPipelineCache>*      pSrcCaches) override;

    virtual void Process_vkCreateGraphicsPipelines(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        uint32_t                                    createInfoCount,
        StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipeline>*           pPipelines) override;

    virtual void Process_vkCreateComputePipelines(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        uint32_t                                    createInfoCount,
        StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipeline>*           pPipelines) override;

    virtual void Process_vkDestroyPipeline(
        format::HandleId                            device,
        format::HandleId                            pipeline,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreatePipelineLayout(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout) override;

    virtual void Process_vkDestroyPipelineLayout(
        format::HandleId                            device,
        format::HandleId                            pipelineLayout,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateSampler(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSampler>*            pSampler) override;

    virtual void Process_vkDestroySampler(
        format::HandleId                            device,
        format::HandleId                            sampler,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateDescriptorSetLayout(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout) override;

    virtual void Process_vkDestroyDescriptorSetLayout(
        format::HandleId                            device,
        format::HandleId                            descriptorSetLayout,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateDescriptorPool(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool) override;

    virtual void Process_vkDestroyDescriptorPool(
        format::HandleId                            device,
        format::HandleId                            descriptorPool,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkResetDescriptorPool(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            descriptorPool,
        VkDescriptorPoolResetFlags                  flags) override;

    virtual void Process_vkAllocateDescriptorSets(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
        HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets) override;

    virtual void Process_vkFreeDescriptorSets(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            descriptorPool,
        uint32_t                                    descriptorSetCount,
        HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets) override;

    virtual void Process_vkUpdateDescriptorSets(
        format::HandleId                            device,
        uint32_t                                    descriptorWriteCount,
        StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
        uint32_t                                    descriptorCopyCount,
        StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies) override;

    virtual void Process_vkCreateFramebuffer(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkFramebuffer>*        pFramebuffer) override;

    virtual void Process_vkDestroyFramebuffer(
        format::HandleId                            device,
        format::HandleId                            framebuffer,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateRenderPass(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkRenderPass>*         pRenderPass) override;

    virtual void Process_vkDestroyRenderPass(
        format::HandleId                            device,
        format::HandleId                            renderPass,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetRenderAreaGranularity(
        format::HandleId                            device,
        format::HandleId                            renderPass,
        StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity) override;

    virtual void Process_vkCreateCommandPool(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkCommandPool>*        pCommandPool) override;

    virtual void Process_vkDestroyCommandPool(
        format::HandleId                            device,
        format::HandleId                            commandPool,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkResetCommandPool(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            commandPool,
        VkCommandPoolResetFlags                     flags) override;

    virtual void Process_vkAllocateCommandBuffers(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
        HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers) override;

    virtual void Process_vkFreeCommandBuffers(
        format::HandleId                            device,
        format::HandleId                            commandPool,
        uint32_t                                    commandBufferCount,
        HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers) override;

    virtual void Process_vkBeginCommandBuffer(
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) override;

    virtual void Process_vkEndCommandBuffer(
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer) override;

    virtual void Process_vkResetCommandBuffer(
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        VkCommandBufferResetFlags                   flags) override;

    virtual void Process_vkCmdBindPipeline(
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            pipeline) override;

    virtual void Process_vkCmdSetViewport(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewport>*   pViewports) override;

    virtual void Process_vkCmdSetScissor(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstScissor,
        uint32_t                                    scissorCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pScissors) override;

    virtual void Process_vkCmdSetLineWidth(
        format::HandleId                            commandBuffer,
        float                                       lineWidth) override;

    virtual void Process_vkCmdSetDepthBias(
        format::HandleId                            commandBuffer,
        float                                       depthBiasConstantFactor,
        float                                       depthBiasClamp,
        float                                       depthBiasSlopeFactor) override;

    virtual void Process_vkCmdSetBlendConstants(
        format::HandleId                            commandBuffer,
        PointerDecoder<float>*                      blendConstants) override;

    virtual void Process_vkCmdSetDepthBounds(
        format::HandleId                            commandBuffer,
        float                                       minDepthBounds,
        float                                       maxDepthBounds) override;

    virtual void Process_vkCmdSetStencilCompareMask(
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    compareMask) override;

    virtual void Process_vkCmdSetStencilWriteMask(
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    writeMask) override;

    virtual void Process_vkCmdSetStencilReference(
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    reference) override;

    virtual void Process_vkCmdBindDescriptorSets(
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            layout,
        uint32_t                                    firstSet,
        uint32_t                                    descriptorSetCount,
        HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
        uint32_t                                    dynamicOffsetCount,
        PointerDecoder<uint32_t>*                   pDynamicOffsets) override;

    virtual void Process_vkCmdBindIndexBuffer(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        VkIndexType                                 indexType) override;

    virtual void Process_vkCmdBindVertexBuffers(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        HandlePointerDecoder<VkBuffer>*             pBuffers,
        PointerDecoder<VkDeviceSize>*               pOffsets) override;

    virtual void Process_vkCmdDraw(
        format::HandleId                            commandBuffer,
        uint32_t                                    vertexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstVertex,
        uint32_t                                    firstInstance) override;

    virtual void Process_vkCmdDrawIndexed(
        format::HandleId                            commandBuffer,
        uint32_t                                    indexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstIndex,
        int32_t                                     vertexOffset,
        uint32_t                                    firstInstance) override;

    virtual void Process_vkCmdDrawIndirect(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDrawIndexedIndirect(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDispatch(
        format::HandleId                            commandBuffer,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    virtual void Process_vkCmdDispatchIndirect(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset) override;

    virtual void Process_vkCmdCopyBuffer(
        format::HandleId                            commandBuffer,
        format::HandleId                            srcBuffer,
        format::HandleId                            dstBuffer,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkBufferCopy>* pRegions) override;

    virtual void Process_vkCmdCopyImage(
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkImageCopy>*  pRegions) override;

    virtual void Process_vkCmdBlitImage(
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkImageBlit>*  pRegions,
        VkFilter                                    filter) override;

    virtual void Process_vkCmdCopyBufferToImage(
        format::HandleId                            commandBuffer,
        format::HandleId                            srcBuffer,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions) override;

    virtual void Process_vkCmdCopyImageToBuffer(
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstBuffer,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions) override;

    virtual void Process_vkCmdUpdateBuffer(
        format::HandleId                            commandBuffer,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                dataSize,
        PointerDecoder<uint8_t>*                    pData) override;

    virtual void Process_vkCmdFillBuffer(
        format::HandleId                            commandBuffer,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                size,
        uint32_t                                    data) override;

    virtual void Process_vkCmdClearColorImage(
        format::HandleId                            commandBuffer,
        format::HandleId                            image,
        VkImageLayout                               imageLayout,
        StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
        uint32_t                                    rangeCount,
        StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges) override;

    virtual void Process_vkCmdClearDepthStencilImage(
        format::HandleId                            commandBuffer,
        format::HandleId                            image,
        VkImageLayout                               imageLayout,
        StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
        uint32_t                                    rangeCount,
        StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges) override;

    virtual void Process_vkCmdClearAttachments(
        format::HandleId                            commandBuffer,
        uint32_t                                    attachmentCount,
        StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
        uint32_t                                    rectCount,
        StructPointerDecoder<Decoded_VkClearRect>*  pRects) override;

    virtual void Process_vkCmdResolveImage(
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkImageResolve>* pRegions) override;

    virtual void Process_vkCmdSetEvent(
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags                        stageMask) override;

    virtual void Process_vkCmdResetEvent(
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags                        stageMask) override;

    virtual void Process_vkCmdWaitEvents(
        format::HandleId                            commandBuffer,
        uint32_t                                    eventCount,
        HandlePointerDecoder<VkEvent>*              pEvents,
        VkPipelineStageFlags                        srcStageMask,
        VkPipelineStageFlags                        dstStageMask,
        uint32_t                                    memoryBarrierCount,
        StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers,
        uint32_t                                    bufferMemoryBarrierCount,
        StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
        uint32_t                                    imageMemoryBarrierCount,
        StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers) override;

    virtual void Process_vkCmdPipelineBarrier(
        format::HandleId                            commandBuffer,
        VkPipelineStageFlags                        srcStageMask,
        VkPipelineStageFlags                        dstStageMask,
        VkDependencyFlags                           dependencyFlags,
        uint32_t                                    memoryBarrierCount,
        StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers,
        uint32_t                                    bufferMemoryBarrierCount,
        StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
        uint32_t                                    imageMemoryBarrierCount,
        StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers) override;

    virtual void Process_vkCmdBeginQuery(
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query,
        VkQueryControlFlags                         flags) override;

    virtual void Process_vkCmdEndQuery(
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query) override;

    virtual void Process_vkCmdResetQueryPool(
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount) override;

    virtual void Process_vkCmdWriteTimestamp(
        format::HandleId                            commandBuffer,
        VkPipelineStageFlagBits                     pipelineStage,
        format::HandleId                            queryPool,
        uint32_t                                    query) override;

    virtual void Process_vkCmdCopyQueryPoolResults(
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                stride,
        VkQueryResultFlags                          flags) override;

    virtual void Process_vkCmdPushConstants(
        format::HandleId                            commandBuffer,
        format::HandleId                            layout,
        VkShaderStageFlags                          stageFlags,
        uint32_t                                    offset,
        uint32_t                                    size,
        PointerDecoder<uint8_t>*                    pValues) override;

    virtual void Process_vkCmdBeginRenderPass(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
        VkSubpassContents                           contents) override;

    virtual void Process_vkCmdNextSubpass(
        format::HandleId                            commandBuffer,
        VkSubpassContents                           contents) override;

    virtual void Process_vkCmdEndRenderPass(
        format::HandleId                            commandBuffer) override;

    virtual void Process_vkCmdExecuteCommands(
        format::HandleId                            commandBuffer,
        uint32_t                                    commandBufferCount,
        HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers) override;

    virtual void Process_vkBindBufferMemory2(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos) override;

    virtual void Process_vkBindImageMemory2(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos) override;

    virtual void Process_vkGetDeviceGroupPeerMemoryFeatures(
        format::HandleId                            device,
        uint32_t                                    heapIndex,
        uint32_t                                    localDeviceIndex,
        uint32_t                                    remoteDeviceIndex,
        PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures) override;

    virtual void Process_vkCmdSetDeviceMask(
        format::HandleId                            commandBuffer,
        uint32_t                                    deviceMask) override;

    virtual void Process_vkCmdDispatchBase(
        format::HandleId                            commandBuffer,
        uint32_t                                    baseGroupX,
        uint32_t                                    baseGroupY,
        uint32_t                                    baseGroupZ,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    virtual void Process_vkEnumeratePhysicalDeviceGroups(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties) override;

    virtual void Process_vkGetImageMemoryRequirements2(
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) override;

    virtual void Process_vkGetBufferMemoryRequirements2(
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) override;

    virtual void Process_vkGetImageSparseMemoryRequirements2(
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
        PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) override;

    virtual void Process_vkGetPhysicalDeviceFeatures2(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures) override;

    virtual void Process_vkGetPhysicalDeviceProperties2(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties2(
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
        StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2(
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
        StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties) override;

    virtual void Process_vkTrimCommandPool(
        format::HandleId                            device,
        format::HandleId                            commandPool,
        VkCommandPoolTrimFlags                      flags) override;

    virtual void Process_vkGetDeviceQueue2(
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
        HandlePointerDecoder<VkQueue>*              pQueue) override;

    virtual void Process_vkCreateSamplerYcbcrConversion(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion) override;

    virtual void Process_vkDestroySamplerYcbcrConversion(
        format::HandleId                            device,
        format::HandleId                            ycbcrConversion,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateDescriptorUpdateTemplate(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate) override;

    virtual void Process_vkDestroyDescriptorUpdateTemplate(
        format::HandleId                            device,
        format::HandleId                            descriptorUpdateTemplate,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetPhysicalDeviceExternalBufferProperties(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
        StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties) override;

    virtual void Process_vkGetPhysicalDeviceExternalFenceProperties(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
        StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties) override;

    virtual void Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
        StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties) override;

    virtual void Process_vkGetDescriptorSetLayoutSupport(
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport) override;

    virtual void Process_vkCmdDrawIndirectCount(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDrawIndexedIndirectCount(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCreateRenderPass2(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkRenderPass>*         pRenderPass) override;

    virtual void Process_vkCmdBeginRenderPass2(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo) override;

    virtual void Process_vkCmdNextSubpass2(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) override;

    virtual void Process_vkCmdEndRenderPass2(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) override;

    virtual void Process_vkResetQueryPool(
        format::HandleId                            device,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount) override;

    virtual void Process_vkGetSemaphoreCounterValue(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            semaphore,
        PointerDecoder<uint64_t>*                   pValue) override;

    virtual void Process_vkWaitSemaphores(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
        uint64_t                                    timeout) override;

    virtual void Process_vkSignalSemaphore(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo) override;

    virtual void Process_vkGetBufferDeviceAddress(
        VkDeviceAddress                             returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) override;

    virtual void Process_vkGetBufferOpaqueCaptureAddress(
        uint64_t                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) override;

    virtual void Process_vkGetDeviceMemoryOpaqueCaptureAddress(
        uint64_t                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo) override;

    virtual void Process_vkDestroySurfaceKHR(
        format::HandleId                            instance,
        format::HandleId                            surface,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceSupportKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        format::HandleId                            surface,
        PointerDecoder<VkBool32>*                   pSupported) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
        StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats) override;

    virtual void Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        PointerDecoder<uint32_t>*                   pPresentModeCount,
        PointerDecoder<VkPresentModeKHR>*           pPresentModes) override;

    virtual void Process_vkCreateSwapchainKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain) override;

    virtual void Process_vkDestroySwapchainKHR(
        format::HandleId                            device,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetSwapchainImagesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        PointerDecoder<uint32_t>*                   pSwapchainImageCount,
        HandlePointerDecoder<VkImage>*              pSwapchainImages) override;

    virtual void Process_vkAcquireNextImageKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        uint64_t                                    timeout,
        format::HandleId                            semaphore,
        format::HandleId                            fence,
        PointerDecoder<uint32_t>*                   pImageIndex) override;

    virtual void Process_vkQueuePresentKHR(
        VkResult                                    returnValue,
        format::HandleId                            queue,
        StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo) override;

    virtual void Process_vkGetDeviceGroupPresentCapabilitiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities) override;

    virtual void Process_vkGetDeviceGroupSurfacePresentModesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            surface,
        PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes) override;

    virtual void Process_vkGetPhysicalDevicePresentRectanglesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        PointerDecoder<uint32_t>*                   pRectCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pRects) override;

    virtual void Process_vkAcquireNextImage2KHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
        PointerDecoder<uint32_t>*                   pImageIndex) override;

    virtual void Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties) override;

    virtual void Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties) override;

    virtual void Process_vkGetDisplayPlaneSupportedDisplaysKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    planeIndex,
        PointerDecoder<uint32_t>*                   pDisplayCount,
        HandlePointerDecoder<VkDisplayKHR>*         pDisplays) override;

    virtual void Process_vkGetDisplayModePropertiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            display,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties) override;

    virtual void Process_vkCreateDisplayModeKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            display,
        StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDisplayModeKHR>*     pMode) override;

    virtual void Process_vkGetDisplayPlaneCapabilitiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            mode,
        uint32_t                                    planeIndex,
        StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities) override;

    virtual void Process_vkCreateDisplayPlaneSurfaceKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkCreateSharedSwapchainsKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    swapchainCount,
        StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains) override;

    virtual void Process_vkCreateXlibSurfaceKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    dpy,
        size_t                                      visualID) override;

    virtual void Process_vkCreateXcbSurfaceKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    connection,
        uint32_t                                    visual_id) override;

    virtual void Process_vkCreateWaylandSurfaceKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    display) override;

    virtual void Process_vkCreateAndroidSurfaceKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkCreateWin32SurfaceKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex) override;

    virtual void Process_vkGetPhysicalDeviceFeatures2KHR(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures) override;

    virtual void Process_vkGetPhysicalDeviceProperties2KHR(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties2KHR(
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
        StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
        StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2KHR(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties) override;

    virtual void Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
        format::HandleId                            device,
        uint32_t                                    heapIndex,
        uint32_t                                    localDeviceIndex,
        uint32_t                                    remoteDeviceIndex,
        PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures) override;

    virtual void Process_vkCmdSetDeviceMaskKHR(
        format::HandleId                            commandBuffer,
        uint32_t                                    deviceMask) override;

    virtual void Process_vkCmdDispatchBaseKHR(
        format::HandleId                            commandBuffer,
        uint32_t                                    baseGroupX,
        uint32_t                                    baseGroupY,
        uint32_t                                    baseGroupZ,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    virtual void Process_vkTrimCommandPoolKHR(
        format::HandleId                            device,
        format::HandleId                            commandPool,
        VkCommandPoolTrimFlags                      flags) override;

    virtual void Process_vkEnumeratePhysicalDeviceGroupsKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties) override;

    virtual void Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
        StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties) override;

    virtual void Process_vkGetMemoryWin32HandleKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
        PointerDecoder<uint64_t, void*>*            pHandle) override;

    virtual void Process_vkGetMemoryWin32HandlePropertiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        uint64_t                                    handle,
        StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties) override;

    virtual void Process_vkGetMemoryFdKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
        PointerDecoder<int>*                        pFd) override;

    virtual void Process_vkGetMemoryFdPropertiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        int                                         fd,
        StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties) override;

    virtual void Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
        StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties) override;

    virtual void Process_vkImportSemaphoreWin32HandleKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo) override;

    virtual void Process_vkGetSemaphoreWin32HandleKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
        PointerDecoder<uint64_t, void*>*            pHandle) override;

    virtual void Process_vkImportSemaphoreFdKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo) override;

    virtual void Process_vkGetSemaphoreFdKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
        PointerDecoder<int>*                        pFd) override;

    virtual void Process_vkCmdPushDescriptorSetKHR(
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            layout,
        uint32_t                                    set,
        uint32_t                                    descriptorWriteCount,
        StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites) override;

    virtual void Process_vkCreateDescriptorUpdateTemplateKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate) override;

    virtual void Process_vkDestroyDescriptorUpdateTemplateKHR(
        format::HandleId                            device,
        format::HandleId                            descriptorUpdateTemplate,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateRenderPass2KHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkRenderPass>*         pRenderPass) override;

    virtual void Process_vkCmdBeginRenderPass2KHR(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo) override;

    virtual void Process_vkCmdNextSubpass2KHR(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) override;

    virtual void Process_vkCmdEndRenderPass2KHR(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) override;

    virtual void Process_vkGetSwapchainStatusKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain) override;

    virtual void Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
        StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties) override;

    virtual void Process_vkImportFenceWin32HandleKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo) override;

    virtual void Process_vkGetFenceWin32HandleKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
        PointerDecoder<uint64_t, void*>*            pHandle) override;

    virtual void Process_vkImportFenceFdKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo) override;

    virtual void Process_vkGetFenceFdKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
        PointerDecoder<int>*                        pFd) override;

    virtual void Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        PointerDecoder<uint32_t>*                   pCounterCount,
        StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters,
        StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
        PointerDecoder<uint32_t>*                   pNumPasses) override;

    virtual void Process_vkAcquireProfilingLockKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo) override;

    virtual void Process_vkReleaseProfilingLockKHR(
        format::HandleId                            device) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
        StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
        PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
        StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats) override;

    virtual void Process_vkGetPhysicalDeviceDisplayProperties2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties) override;

    virtual void Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties) override;

    virtual void Process_vkGetDisplayModeProperties2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            display,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties) override;

    virtual void Process_vkGetDisplayPlaneCapabilities2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
        StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities) override;

    virtual void Process_vkGetImageMemoryRequirements2KHR(
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) override;

    virtual void Process_vkGetBufferMemoryRequirements2KHR(
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) override;

    virtual void Process_vkGetImageSparseMemoryRequirements2KHR(
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
        PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) override;

    virtual void Process_vkCreateSamplerYcbcrConversionKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion) override;

    virtual void Process_vkDestroySamplerYcbcrConversionKHR(
        format::HandleId                            device,
        format::HandleId                            ycbcrConversion,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkBindBufferMemory2KHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos) override;

    virtual void Process_vkBindImageMemory2KHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos) override;

    virtual void Process_vkGetDescriptorSetLayoutSupportKHR(
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport) override;

    virtual void Process_vkCmdDrawIndirectCountKHR(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDrawIndexedIndirectCountKHR(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkGetSemaphoreCounterValueKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            semaphore,
        PointerDecoder<uint64_t>*                   pValue) override;

    virtual void Process_vkWaitSemaphoresKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
        uint64_t                                    timeout) override;

    virtual void Process_vkSignalSemaphoreKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo) override;

    virtual void Process_vkGetBufferDeviceAddressKHR(
        VkDeviceAddress                             returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) override;

    virtual void Process_vkGetBufferOpaqueCaptureAddressKHR(
        uint64_t                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) override;

    virtual void Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
        uint64_t                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo) override;

    virtual void Process_vkCreateDeferredOperationKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation) override;

    virtual void Process_vkDestroyDeferredOperationKHR(
        format::HandleId                            device,
        format::HandleId                            operation,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetDeferredOperationMaxConcurrencyKHR(
        uint32_t                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            operation) override;

    virtual void Process_vkGetDeferredOperationResultKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            operation) override;

    virtual void Process_vkDeferredOperationJoinKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            operation) override;

    virtual void Process_vkGetPipelineExecutablePropertiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo,
        PointerDecoder<uint32_t>*                   pExecutableCount,
        StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties) override;

    virtual void Process_vkGetPipelineExecutableStatisticsKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
        PointerDecoder<uint32_t>*                   pStatisticCount,
        StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics) override;

    virtual void Process_vkGetPipelineExecutableInternalRepresentationsKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
        PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
        StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations) override;

    virtual void Process_vkCreateDebugReportCallbackEXT(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback) override;

    virtual void Process_vkDestroyDebugReportCallbackEXT(
        format::HandleId                            instance,
        format::HandleId                            callback,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkDebugReportMessageEXT(
        format::HandleId                            instance,
        VkDebugReportFlagsEXT                       flags,
        VkDebugReportObjectTypeEXT                  objectType,
        uint64_t                                    object,
        size_t                                      location,
        int32_t                                     messageCode,
        StringDecoder*                              pLayerPrefix,
        StringDecoder*                              pMessage) override;

    virtual void Process_vkDebugMarkerSetObjectTagEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo) override;

    virtual void Process_vkDebugMarkerSetObjectNameEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo) override;

    virtual void Process_vkCmdDebugMarkerBeginEXT(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo) override;

    virtual void Process_vkCmdDebugMarkerEndEXT(
        format::HandleId                            commandBuffer) override;

    virtual void Process_vkCmdDebugMarkerInsertEXT(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo) override;

    virtual void Process_vkCmdBindTransformFeedbackBuffersEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        HandlePointerDecoder<VkBuffer>*             pBuffers,
        PointerDecoder<VkDeviceSize>*               pOffsets,
        PointerDecoder<VkDeviceSize>*               pSizes) override;

    virtual void Process_vkCmdBeginTransformFeedbackEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstCounterBuffer,
        uint32_t                                    counterBufferCount,
        HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
        PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets) override;

    virtual void Process_vkCmdEndTransformFeedbackEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstCounterBuffer,
        uint32_t                                    counterBufferCount,
        HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
        PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets) override;

    virtual void Process_vkCmdBeginQueryIndexedEXT(
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query,
        VkQueryControlFlags                         flags,
        uint32_t                                    index) override;

    virtual void Process_vkCmdEndQueryIndexedEXT(
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query,
        uint32_t                                    index) override;

    virtual void Process_vkCmdDrawIndirectByteCountEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    instanceCount,
        uint32_t                                    firstInstance,
        format::HandleId                            counterBuffer,
        VkDeviceSize                                counterBufferOffset,
        uint32_t                                    counterOffset,
        uint32_t                                    vertexStride) override;

    virtual void Process_vkGetImageViewHandleNVX(
        uint32_t                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo) override;

    virtual void Process_vkGetImageViewAddressNVX(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            imageView,
        StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties) override;

    virtual void Process_vkCmdDrawIndirectCountAMD(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDrawIndexedIndirectCountAMD(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkGetShaderInfoAMD(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        VkShaderStageFlagBits                       shaderStage,
        VkShaderInfoTypeAMD                         infoType,
        PointerDecoder<size_t>*                     pInfoSize,
        PointerDecoder<uint8_t>*                    pInfo) override;

    virtual void Process_vkCreateStreamDescriptorSurfaceGGP(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkImageTiling                               tiling,
        VkImageUsageFlags                           usage,
        VkImageCreateFlags                          flags,
        VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
        StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>* pExternalImageFormatProperties) override;

    virtual void Process_vkGetMemoryWin32HandleNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            memory,
        VkExternalMemoryHandleTypeFlagsNV           handleType,
        PointerDecoder<uint64_t, void*>*            pHandle) override;

    virtual void Process_vkCreateViSurfaceNN(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkCmdBeginConditionalRenderingEXT(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin) override;

    virtual void Process_vkCmdEndConditionalRenderingEXT(
        format::HandleId                            commandBuffer) override;

    virtual void Process_vkCmdSetViewportWScalingNV(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings) override;

    virtual void Process_vkReleaseDisplayEXT(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            display) override;

    virtual void Process_vkAcquireXlibDisplayEXT(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint64_t                                    dpy,
        format::HandleId                            display) override;

    virtual void Process_vkGetRandROutputDisplayEXT(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint64_t                                    dpy,
        size_t                                      rrOutput,
        HandlePointerDecoder<VkDisplayKHR>*         pDisplay) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities) override;

    virtual void Process_vkDisplayPowerControlEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            display,
        StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo) override;

    virtual void Process_vkRegisterDeviceEventEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkFence>*              pFence) override;

    virtual void Process_vkRegisterDisplayEventEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            display,
        StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkFence>*              pFence) override;

    virtual void Process_vkGetSwapchainCounterEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        VkSurfaceCounterFlagBitsEXT                 counter,
        PointerDecoder<uint64_t>*                   pCounterValue) override;

    virtual void Process_vkGetRefreshCycleDurationGOOGLE(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties) override;

    virtual void Process_vkGetPastPresentationTimingGOOGLE(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        PointerDecoder<uint32_t>*                   pPresentationTimingCount,
        StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings) override;

    virtual void Process_vkCmdSetDiscardRectangleEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstDiscardRectangle,
        uint32_t                                    discardRectangleCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles) override;

    virtual void Process_vkSetHdrMetadataEXT(
        format::HandleId                            device,
        uint32_t                                    swapchainCount,
        HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains,
        StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata) override;

    virtual void Process_vkCreateIOSSurfaceMVK(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkCreateMacOSSurfaceMVK(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkSetDebugUtilsObjectNameEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo) override;

    virtual void Process_vkSetDebugUtilsObjectTagEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo) override;

    virtual void Process_vkQueueBeginDebugUtilsLabelEXT(
        format::HandleId                            queue,
        StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) override;

    virtual void Process_vkQueueEndDebugUtilsLabelEXT(
        format::HandleId                            queue) override;

    virtual void Process_vkQueueInsertDebugUtilsLabelEXT(
        format::HandleId                            queue,
        StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) override;

    virtual void Process_vkCmdBeginDebugUtilsLabelEXT(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) override;

    virtual void Process_vkCmdEndDebugUtilsLabelEXT(
        format::HandleId                            commandBuffer) override;

    virtual void Process_vkCmdInsertDebugUtilsLabelEXT(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) override;

    virtual void Process_vkCreateDebugUtilsMessengerEXT(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger) override;

    virtual void Process_vkDestroyDebugUtilsMessengerEXT(
        format::HandleId                            instance,
        format::HandleId                            messenger,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkSubmitDebugUtilsMessageEXT(
        format::HandleId                            instance,
        VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
        StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData) override;

    virtual void Process_vkGetAndroidHardwareBufferPropertiesANDROID(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint64_t                                    buffer,
        StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties) override;

    virtual void Process_vkGetMemoryAndroidHardwareBufferANDROID(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
        PointerDecoder<uint64_t, void*>*            pBuffer) override;

    virtual void Process_vkCmdSetSampleLocationsEXT(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo) override;

    virtual void Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
        format::HandleId                            physicalDevice,
        VkSampleCountFlagBits                       samples,
        StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties) override;

    virtual void Process_vkGetImageDrmFormatModifierPropertiesEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties) override;

    virtual void Process_vkCreateValidationCacheEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache) override;

    virtual void Process_vkDestroyValidationCacheEXT(
        format::HandleId                            device,
        format::HandleId                            validationCache,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkMergeValidationCachesEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            dstCache,
        uint32_t                                    srcCacheCount,
        HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches) override;

    virtual void Process_vkGetValidationCacheDataEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            validationCache,
        PointerDecoder<size_t>*                     pDataSize,
        PointerDecoder<uint8_t>*                    pData) override;

    virtual void Process_vkCmdBindShadingRateImageNV(
        format::HandleId                            commandBuffer,
        format::HandleId                            imageView,
        VkImageLayout                               imageLayout) override;

    virtual void Process_vkCmdSetViewportShadingRatePaletteNV(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes) override;

    virtual void Process_vkCmdSetCoarseSampleOrderNV(
        format::HandleId                            commandBuffer,
        VkCoarseSampleOrderTypeNV                   sampleOrderType,
        uint32_t                                    customSampleOrderCount,
        StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders) override;

    virtual void Process_vkCreateAccelerationStructureNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure) override;

    virtual void Process_vkDestroyAccelerationStructureKHR(
        format::HandleId                            device,
        format::HandleId                            accelerationStructure,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkDestroyAccelerationStructureNV(
        format::HandleId                            device,
        format::HandleId                            accelerationStructure,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetAccelerationStructureMemoryRequirementsNV(
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements) override;

    virtual void Process_vkBindAccelerationStructureMemoryKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoKHR>* pBindInfos) override;

    virtual void Process_vkBindAccelerationStructureMemoryNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoKHR>* pBindInfos) override;

    virtual void Process_vkCmdBuildAccelerationStructureNV(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV>* pInfo,
        format::HandleId                            instanceData,
        VkDeviceSize                                instanceOffset,
        VkBool32                                    update,
        format::HandleId                            dst,
        format::HandleId                            src,
        format::HandleId                            scratch,
        VkDeviceSize                                scratchOffset) override;

    virtual void Process_vkCmdCopyAccelerationStructureNV(
        format::HandleId                            commandBuffer,
        format::HandleId                            dst,
        format::HandleId                            src,
        VkCopyAccelerationStructureModeKHR          mode) override;

    virtual void Process_vkCmdTraceRaysNV(
        format::HandleId                            commandBuffer,
        format::HandleId                            raygenShaderBindingTableBuffer,
        VkDeviceSize                                raygenShaderBindingOffset,
        format::HandleId                            missShaderBindingTableBuffer,
        VkDeviceSize                                missShaderBindingOffset,
        VkDeviceSize                                missShaderBindingStride,
        format::HandleId                            hitShaderBindingTableBuffer,
        VkDeviceSize                                hitShaderBindingOffset,
        VkDeviceSize                                hitShaderBindingStride,
        format::HandleId                            callableShaderBindingTableBuffer,
        VkDeviceSize                                callableShaderBindingOffset,
        VkDeviceSize                                callableShaderBindingStride,
        uint32_t                                    width,
        uint32_t                                    height,
        uint32_t                                    depth) override;

    virtual void Process_vkCreateRayTracingPipelinesNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        uint32_t                                    createInfoCount,
        StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipeline>*           pPipelines) override;

    virtual void Process_vkGetRayTracingShaderGroupHandlesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        uint32_t                                    firstGroup,
        uint32_t                                    groupCount,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData) override;

    virtual void Process_vkGetRayTracingShaderGroupHandlesNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        uint32_t                                    firstGroup,
        uint32_t                                    groupCount,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData) override;

    virtual void Process_vkGetAccelerationStructureHandleNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            accelerationStructure,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData) override;

    virtual void Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
        format::HandleId                            commandBuffer,
        uint32_t                                    accelerationStructureCount,
        HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
        VkQueryType                                 queryType,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery) override;

    virtual void Process_vkCmdWriteAccelerationStructuresPropertiesNV(
        format::HandleId                            commandBuffer,
        uint32_t                                    accelerationStructureCount,
        HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
        VkQueryType                                 queryType,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery) override;

    virtual void Process_vkCompileDeferredNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        uint32_t                                    shader) override;

    virtual void Process_vkGetMemoryHostPointerPropertiesEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        uint64_t                                    pHostPointer,
        StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties) override;

    virtual void Process_vkCmdWriteBufferMarkerAMD(
        format::HandleId                            commandBuffer,
        VkPipelineStageFlagBits                     pipelineStage,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        uint32_t                                    marker) override;

    virtual void Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pTimeDomainCount,
        PointerDecoder<VkTimeDomainEXT>*            pTimeDomains) override;

    virtual void Process_vkGetCalibratedTimestampsEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    timestampCount,
        StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>* pTimestampInfos,
        PointerDecoder<uint64_t>*                   pTimestamps,
        PointerDecoder<uint64_t>*                   pMaxDeviation) override;

    virtual void Process_vkCmdDrawMeshTasksNV(
        format::HandleId                            commandBuffer,
        uint32_t                                    taskCount,
        uint32_t                                    firstTask) override;

    virtual void Process_vkCmdDrawMeshTasksIndirectNV(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDrawMeshTasksIndirectCountNV(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdSetExclusiveScissorNV(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstExclusiveScissor,
        uint32_t                                    exclusiveScissorCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors) override;

    virtual void Process_vkCmdSetCheckpointNV(
        format::HandleId                            commandBuffer,
        uint64_t                                    pCheckpointMarker) override;

    virtual void Process_vkGetQueueCheckpointDataNV(
        format::HandleId                            queue,
        PointerDecoder<uint32_t>*                   pCheckpointDataCount,
        StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData) override;

    virtual void Process_vkInitializePerformanceApiINTEL(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo) override;

    virtual void Process_vkUninitializePerformanceApiINTEL(
        format::HandleId                            device) override;

    virtual void Process_vkCmdSetPerformanceMarkerINTEL(
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo) override;

    virtual void Process_vkCmdSetPerformanceStreamMarkerINTEL(
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo) override;

    virtual void Process_vkCmdSetPerformanceOverrideINTEL(
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo) override;

    virtual void Process_vkAcquirePerformanceConfigurationINTEL(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
        HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration) override;

    virtual void Process_vkReleasePerformanceConfigurationINTEL(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            configuration) override;

    virtual void Process_vkQueueSetPerformanceConfigurationINTEL(
        VkResult                                    returnValue,
        format::HandleId                            queue,
        format::HandleId                            configuration) override;

    virtual void Process_vkGetPerformanceParameterINTEL(
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkPerformanceParameterTypeINTEL             parameter,
        StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue) override;

    virtual void Process_vkSetLocalDimmingAMD(
        format::HandleId                            device,
        format::HandleId                            swapChain,
        VkBool32                                    localDimmingEnable) override;

    virtual void Process_vkCreateImagePipeSurfaceFUCHSIA(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkCreateMetalSurfaceEXT(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkGetBufferDeviceAddressEXT(
        VkDeviceAddress                             returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) override;

    virtual void Process_vkGetPhysicalDeviceToolPropertiesEXT(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pToolCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceToolPropertiesEXT>* pToolProperties) override;

    virtual void Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties) override;

    virtual void Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pCombinationCount,
        StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations) override;

    virtual void Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
        PointerDecoder<uint32_t>*                   pPresentModeCount,
        PointerDecoder<VkPresentModeKHR>*           pPresentModes) override;

    virtual void Process_vkAcquireFullScreenExclusiveModeEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain) override;

    virtual void Process_vkReleaseFullScreenExclusiveModeEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain) override;

    virtual void Process_vkGetDeviceGroupSurfacePresentModes2EXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
        PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes) override;

    virtual void Process_vkCreateHeadlessSurfaceEXT(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkCmdSetLineStippleEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    lineStippleFactor,
        uint16_t                                    lineStipplePattern) override;

    virtual void Process_vkResetQueryPoolEXT(
        format::HandleId                            device,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount) override;

    virtual void Process_vkCmdSetCullModeEXT(
        format::HandleId                            commandBuffer,
        VkCullModeFlags                             cullMode) override;

    virtual void Process_vkCmdSetFrontFaceEXT(
        format::HandleId                            commandBuffer,
        VkFrontFace                                 frontFace) override;

    virtual void Process_vkCmdSetPrimitiveTopologyEXT(
        format::HandleId                            commandBuffer,
        VkPrimitiveTopology                         primitiveTopology) override;

    virtual void Process_vkCmdSetViewportWithCountEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewport>*   pViewports) override;

    virtual void Process_vkCmdSetScissorWithCountEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    scissorCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pScissors) override;

    virtual void Process_vkCmdBindVertexBuffers2EXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        HandlePointerDecoder<VkBuffer>*             pBuffers,
        PointerDecoder<VkDeviceSize>*               pOffsets,
        PointerDecoder<VkDeviceSize>*               pSizes,
        PointerDecoder<VkDeviceSize>*               pStrides) override;

    virtual void Process_vkCmdSetDepthTestEnableEXT(
        format::HandleId                            commandBuffer,
        VkBool32                                    depthTestEnable) override;

    virtual void Process_vkCmdSetDepthWriteEnableEXT(
        format::HandleId                            commandBuffer,
        VkBool32                                    depthWriteEnable) override;

    virtual void Process_vkCmdSetDepthCompareOpEXT(
        format::HandleId                            commandBuffer,
        VkCompareOp                                 depthCompareOp) override;

    virtual void Process_vkCmdSetDepthBoundsTestEnableEXT(
        format::HandleId                            commandBuffer,
        VkBool32                                    depthBoundsTestEnable) override;

    virtual void Process_vkCmdSetStencilTestEnableEXT(
        format::HandleId                            commandBuffer,
        VkBool32                                    stencilTestEnable) override;

    virtual void Process_vkCmdSetStencilOpEXT(
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        VkStencilOp                                 failOp,
        VkStencilOp                                 passOp,
        VkStencilOp                                 depthFailOp,
        VkCompareOp                                 compareOp) override;

    virtual void Process_vkGetGeneratedCommandsMemoryRequirementsNV(
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) override;

    virtual void Process_vkCmdPreprocessGeneratedCommandsNV(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo) override;

    virtual void Process_vkCmdExecuteGeneratedCommandsNV(
        format::HandleId                            commandBuffer,
        VkBool32                                    isPreprocessed,
        StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo) override;

    virtual void Process_vkCmdBindPipelineShaderGroupNV(
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            pipeline,
        uint32_t                                    groupIndex) override;

    virtual void Process_vkCreateIndirectCommandsLayoutNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout) override;

    virtual void Process_vkDestroyIndirectCommandsLayoutNV(
        format::HandleId                            device,
        format::HandleId                            indirectCommandsLayout,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreatePrivateDataSlotEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPrivateDataSlotEXT>* pPrivateDataSlot) override;

    virtual void Process_vkDestroyPrivateDataSlotEXT(
        format::HandleId                            device,
        format::HandleId                            privateDataSlot,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkSetPrivateDataEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkObjectType                                objectType,
        uint64_t                                    objectHandle,
        format::HandleId                            privateDataSlot,
        uint64_t                                    data) override;

    virtual void Process_vkGetPrivateDataEXT(
        format::HandleId                            device,
        VkObjectType                                objectType,
        uint64_t                                    objectHandle,
        format::HandleId                            privateDataSlot,
        PointerDecoder<uint64_t>*                   pData) override;

    virtual void Process_vkCreateDirectFBSurfaceEXT(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    dfb) override;

    virtual void Process_vkCreateAccelerationStructureKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure) override;

    virtual void Process_vkGetAccelerationStructureMemoryRequirementsKHR(
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoKHR>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) override;

    virtual void Process_vkCmdBuildAccelerationStructureIndirectKHR(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfo,
        format::HandleId                            indirectBuffer,
        VkDeviceSize                                indirectOffset,
        uint32_t                                    indirectStride) override;

    virtual void Process_vkCopyAccelerationStructureKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo) override;

    virtual void Process_vkCopyAccelerationStructureToMemoryKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo) override;

    virtual void Process_vkCopyMemoryToAccelerationStructureKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo) override;

    virtual void Process_vkWriteAccelerationStructuresPropertiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    accelerationStructureCount,
        HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
        VkQueryType                                 queryType,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData,
        size_t                                      stride) override;

    virtual void Process_vkCmdCopyAccelerationStructureKHR(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo) override;

    virtual void Process_vkCmdCopyAccelerationStructureToMemoryKHR(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo) override;

    virtual void Process_vkCmdCopyMemoryToAccelerationStructureKHR(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo) override;

    virtual void Process_vkCmdTraceRaysKHR(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pRaygenShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pMissShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pHitShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pCallableShaderBindingTable,
        uint32_t                                    width,
        uint32_t                                    height,
        uint32_t                                    depth) override;

    virtual void Process_vkCreateRayTracingPipelinesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        uint32_t                                    createInfoCount,
        StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipeline>*           pPipelines) override;

    virtual void Process_vkGetAccelerationStructureDeviceAddressKHR(
        VkDeviceAddress                             returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo) override;

    virtual void Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        uint32_t                                    firstGroup,
        uint32_t                                    groupCount,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData) override;

    virtual void Process_vkCmdTraceRaysIndirectKHR(
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pRaygenShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pMissShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pHitShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pCallableShaderBindingTable,
        format::HandleId                            buffer,
        VkDeviceSize                                offset) override;

    virtual void Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAccelerationStructureVersionKHR>* version) override;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
