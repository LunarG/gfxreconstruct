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

#ifndef  GFXRECON_GENERATED_VULKAN_CPP_PRE_PROCESS_CONSUMER_H
#define  GFXRECON_GENERATED_VULKAN_CPP_PRE_PROCESS_CONSUMER_H

#include "decode/vulkan_cpp_pre_process_consumer_base.h"
#include "util/defines.h"
#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanCppPreProcessConsumer : public VulkanCppPreProcessConsumerBase
{
  public:
    VulkanCppPreProcessConsumer() {}

    virtual ~VulkanCppPreProcessConsumer() override {}
    virtual void Process_vkCreateInstance(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkInstance>*           pInstance) override;

    virtual void Process_vkDestroyInstance(
        const ApiCallInfo&                          call_info,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkEnumeratePhysicalDevices(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
        HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices) override;

    virtual void Process_vkGetPhysicalDeviceFeatures(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkImageTiling                               tiling,
        VkImageUsageFlags                           usage,
        VkImageCreateFlags                          flags,
        StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceProperties(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
        StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties) override;

    virtual void Process_vkCreateDevice(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDevice>*             pDevice) override;

    virtual void Process_vkDestroyDevice(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetDeviceQueue(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        uint32_t                                    queueFamilyIndex,
        uint32_t                                    queueIndex,
        HandlePointerDecoder<VkQueue>*              pQueue) override;

    virtual void Process_vkQueueSubmit(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            queue,
        uint32_t                                    submitCount,
        StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
        format::HandleId                            fence) override;

    virtual void Process_vkQueueWaitIdle(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            queue) override;

    virtual void Process_vkDeviceWaitIdle(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device) override;

    virtual void Process_vkAllocateMemory(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDeviceMemory>*       pMemory) override;

    virtual void Process_vkFreeMemory(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            memory,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkMapMemory(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            memory,
        VkDeviceSize                                offset,
        VkDeviceSize                                size,
        VkMemoryMapFlags                            flags,
        PointerDecoder<uint64_t, void*>*            ppData) override;

    virtual void Process_vkUnmapMemory(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            memory) override;

    virtual void Process_vkFlushMappedMemoryRanges(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    memoryRangeCount,
        StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges) override;

    virtual void Process_vkInvalidateMappedMemoryRanges(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    memoryRangeCount,
        StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges) override;

    virtual void Process_vkGetDeviceMemoryCommitment(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            memory,
        PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes) override;

    virtual void Process_vkBindBufferMemory(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            buffer,
        format::HandleId                            memory,
        VkDeviceSize                                memoryOffset) override;

    virtual void Process_vkBindImageMemory(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            image,
        format::HandleId                            memory,
        VkDeviceSize                                memoryOffset) override;

    virtual void Process_vkGetBufferMemoryRequirements(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            buffer,
        StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) override;

    virtual void Process_vkGetImageMemoryRequirements(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) override;

    virtual void Process_vkGetImageSparseMemoryRequirements(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            image,
        PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkSampleCountFlagBits                       samples,
        VkImageUsageFlags                           usage,
        VkImageTiling                               tiling,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties) override;

    virtual void Process_vkQueueBindSparse(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            queue,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
        format::HandleId                            fence) override;

    virtual void Process_vkCreateFence(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkFence>*              pFence) override;

    virtual void Process_vkDestroyFence(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            fence,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkResetFences(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    fenceCount,
        HandlePointerDecoder<VkFence>*              pFences) override;

    virtual void Process_vkGetFenceStatus(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            fence) override;

    virtual void Process_vkWaitForFences(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    fenceCount,
        HandlePointerDecoder<VkFence>*              pFences,
        VkBool32                                    waitAll,
        uint64_t                                    timeout) override;

    virtual void Process_vkCreateSemaphore(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSemaphore>*          pSemaphore) override;

    virtual void Process_vkDestroySemaphore(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            semaphore,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateEvent(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkEvent>*              pEvent) override;

    virtual void Process_vkDestroyEvent(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            event,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetEventStatus(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            event) override;

    virtual void Process_vkSetEvent(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            event) override;

    virtual void Process_vkResetEvent(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            event) override;

    virtual void Process_vkCreateQueryPool(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkQueryPool>*          pQueryPool) override;

    virtual void Process_vkDestroyQueryPool(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            queryPool,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetQueryPoolResults(
        const ApiCallInfo&                          call_info,
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
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkBuffer>*             pBuffer) override;

    virtual void Process_vkDestroyBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            buffer,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateBufferView(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkBufferView>*         pView) override;

    virtual void Process_vkDestroyBufferView(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            bufferView,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateImage(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkImage>*              pImage) override;

    virtual void Process_vkDestroyImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetImageSubresourceLayout(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
        StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout) override;

    virtual void Process_vkCreateImageView(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkImageView>*          pView) override;

    virtual void Process_vkDestroyImageView(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            imageView,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateShaderModule(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkShaderModule>*       pShaderModule) override;

    virtual void Process_vkDestroyShaderModule(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            shaderModule,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreatePipelineCache(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipelineCache>*      pPipelineCache) override;

    virtual void Process_vkDestroyPipelineCache(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetPipelineCacheData(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        PointerDecoder<size_t>*                     pDataSize,
        PointerDecoder<uint8_t>*                    pData) override;

    virtual void Process_vkMergePipelineCaches(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            dstCache,
        uint32_t                                    srcCacheCount,
        HandlePointerDecoder<VkPipelineCache>*      pSrcCaches) override;

    virtual void Process_vkCreateGraphicsPipelines(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        uint32_t                                    createInfoCount,
        StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipeline>*           pPipelines) override;

    virtual void Process_vkCreateComputePipelines(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        uint32_t                                    createInfoCount,
        StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipeline>*           pPipelines) override;

    virtual void Process_vkDestroyPipeline(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreatePipelineLayout(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout) override;

    virtual void Process_vkDestroyPipelineLayout(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            pipelineLayout,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateSampler(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSampler>*            pSampler) override;

    virtual void Process_vkDestroySampler(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            sampler,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateDescriptorSetLayout(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout) override;

    virtual void Process_vkDestroyDescriptorSetLayout(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            descriptorSetLayout,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateDescriptorPool(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool) override;

    virtual void Process_vkDestroyDescriptorPool(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            descriptorPool,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkResetDescriptorPool(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            descriptorPool,
        VkDescriptorPoolResetFlags                  flags) override;

    virtual void Process_vkAllocateDescriptorSets(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
        HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets) override;

    virtual void Process_vkFreeDescriptorSets(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            descriptorPool,
        uint32_t                                    descriptorSetCount,
        HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets) override;

    virtual void Process_vkUpdateDescriptorSets(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        uint32_t                                    descriptorWriteCount,
        StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
        uint32_t                                    descriptorCopyCount,
        StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies) override;

    virtual void Process_vkCreateFramebuffer(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkFramebuffer>*        pFramebuffer) override;

    virtual void Process_vkDestroyFramebuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            framebuffer,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateRenderPass(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkRenderPass>*         pRenderPass) override;

    virtual void Process_vkDestroyRenderPass(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            renderPass,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetRenderAreaGranularity(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            renderPass,
        StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity) override;

    virtual void Process_vkCreateCommandPool(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkCommandPool>*        pCommandPool) override;

    virtual void Process_vkDestroyCommandPool(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            commandPool,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkResetCommandPool(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            commandPool,
        VkCommandPoolResetFlags                     flags) override;

    virtual void Process_vkAllocateCommandBuffers(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
        HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers) override;

    virtual void Process_vkFreeCommandBuffers(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            commandPool,
        uint32_t                                    commandBufferCount,
        HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers) override;

    virtual void Process_vkBeginCommandBuffer(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) override;

    virtual void Process_vkEndCommandBuffer(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer) override;

    virtual void Process_vkResetCommandBuffer(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        VkCommandBufferResetFlags                   flags) override;

    virtual void Process_vkCmdBindPipeline(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            pipeline) override;

    virtual void Process_vkCmdSetViewport(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewport>*   pViewports) override;

    virtual void Process_vkCmdSetScissor(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstScissor,
        uint32_t                                    scissorCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pScissors) override;

    virtual void Process_vkCmdSetLineWidth(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        float                                       lineWidth) override;

    virtual void Process_vkCmdSetDepthBias(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        float                                       depthBiasConstantFactor,
        float                                       depthBiasClamp,
        float                                       depthBiasSlopeFactor) override;

    virtual void Process_vkCmdSetBlendConstants(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        PointerDecoder<float>*                      blendConstants) override;

    virtual void Process_vkCmdSetDepthBounds(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        float                                       minDepthBounds,
        float                                       maxDepthBounds) override;

    virtual void Process_vkCmdSetStencilCompareMask(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    compareMask) override;

    virtual void Process_vkCmdSetStencilWriteMask(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    writeMask) override;

    virtual void Process_vkCmdSetStencilReference(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    reference) override;

    virtual void Process_vkCmdBindDescriptorSets(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            layout,
        uint32_t                                    firstSet,
        uint32_t                                    descriptorSetCount,
        HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
        uint32_t                                    dynamicOffsetCount,
        PointerDecoder<uint32_t>*                   pDynamicOffsets) override;

    virtual void Process_vkCmdBindIndexBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        VkIndexType                                 indexType) override;

    virtual void Process_vkCmdBindVertexBuffers(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        HandlePointerDecoder<VkBuffer>*             pBuffers,
        PointerDecoder<VkDeviceSize>*               pOffsets) override;

    virtual void Process_vkCmdDraw(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    vertexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstVertex,
        uint32_t                                    firstInstance) override;

    virtual void Process_vkCmdDrawIndexed(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    indexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstIndex,
        int32_t                                     vertexOffset,
        uint32_t                                    firstInstance) override;

    virtual void Process_vkCmdDrawIndirect(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDrawIndexedIndirect(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDispatch(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    virtual void Process_vkCmdDispatchIndirect(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset) override;

    virtual void Process_vkCmdCopyBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcBuffer,
        format::HandleId                            dstBuffer,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkBufferCopy>* pRegions) override;

    virtual void Process_vkCmdCopyImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkImageCopy>*  pRegions) override;

    virtual void Process_vkCmdBlitImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkImageBlit>*  pRegions,
        VkFilter                                    filter) override;

    virtual void Process_vkCmdCopyBufferToImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcBuffer,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions) override;

    virtual void Process_vkCmdCopyImageToBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstBuffer,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions) override;

    virtual void Process_vkCmdUpdateBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                dataSize,
        PointerDecoder<uint8_t>*                    pData) override;

    virtual void Process_vkCmdFillBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                size,
        uint32_t                                    data) override;

    virtual void Process_vkCmdClearColorImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            image,
        VkImageLayout                               imageLayout,
        StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
        uint32_t                                    rangeCount,
        StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges) override;

    virtual void Process_vkCmdClearDepthStencilImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            image,
        VkImageLayout                               imageLayout,
        StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
        uint32_t                                    rangeCount,
        StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges) override;

    virtual void Process_vkCmdClearAttachments(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    attachmentCount,
        StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
        uint32_t                                    rectCount,
        StructPointerDecoder<Decoded_VkClearRect>*  pRects) override;

    virtual void Process_vkCmdResolveImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkImageResolve>* pRegions) override;

    virtual void Process_vkCmdSetEvent(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags                        stageMask) override;

    virtual void Process_vkCmdResetEvent(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags                        stageMask) override;

    virtual void Process_vkCmdWaitEvents(
        const ApiCallInfo&                          call_info,
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
        const ApiCallInfo&                          call_info,
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
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query,
        VkQueryControlFlags                         flags) override;

    virtual void Process_vkCmdEndQuery(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query) override;

    virtual void Process_vkCmdResetQueryPool(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount) override;

    virtual void Process_vkCmdWriteTimestamp(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineStageFlagBits                     pipelineStage,
        format::HandleId                            queryPool,
        uint32_t                                    query) override;

    virtual void Process_vkCmdCopyQueryPoolResults(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                stride,
        VkQueryResultFlags                          flags) override;

    virtual void Process_vkCmdPushConstants(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            layout,
        VkShaderStageFlags                          stageFlags,
        uint32_t                                    offset,
        uint32_t                                    size,
        PointerDecoder<uint8_t>*                    pValues) override;

    virtual void Process_vkCmdBeginRenderPass(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
        VkSubpassContents                           contents) override;

    virtual void Process_vkCmdNextSubpass(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkSubpassContents                           contents) override;

    virtual void Process_vkCmdEndRenderPass(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer) override;

    virtual void Process_vkCmdExecuteCommands(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    commandBufferCount,
        HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers) override;
    virtual void Process_vkDestroySurfaceKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            instance,
        format::HandleId                            surface,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceSupportKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        format::HandleId                            surface,
        PointerDecoder<VkBool32>*                   pSupported) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities) override;

    virtual void Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
        StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats) override;

    virtual void Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        PointerDecoder<uint32_t>*                   pPresentModeCount,
        PointerDecoder<VkPresentModeKHR>*           pPresentModes) override;
    virtual void Process_vkCreateSwapchainKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain) override;

    virtual void Process_vkDestroySwapchainKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetSwapchainImagesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        PointerDecoder<uint32_t>*                   pSwapchainImageCount,
        HandlePointerDecoder<VkImage>*              pSwapchainImages) override;

    virtual void Process_vkAcquireNextImageKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        uint64_t                                    timeout,
        format::HandleId                            semaphore,
        format::HandleId                            fence,
        PointerDecoder<uint32_t>*                   pImageIndex) override;

    virtual void Process_vkQueuePresentKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            queue,
        StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo) override;

    virtual void Process_vkGetDeviceGroupPresentCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities) override;

    virtual void Process_vkGetDeviceGroupSurfacePresentModesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            surface,
        PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes) override;

    virtual void Process_vkGetPhysicalDevicePresentRectanglesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        PointerDecoder<uint32_t>*                   pRectCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pRects) override;

    virtual void Process_vkAcquireNextImage2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
        PointerDecoder<uint32_t>*                   pImageIndex) override;
    virtual void Process_vkCreateXcbSurfaceKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    connection,
        uint32_t                                    visual_id) override;
    virtual void Process_vkCreateWaylandSurfaceKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;

    virtual void Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    display) override;
    virtual void Process_vkCreateAndroidSurfaceKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) override;
    virtual void Process_vkGetPhysicalDeviceFeatures2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures) override;

    virtual void Process_vkGetPhysicalDeviceProperties2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties) override;

    virtual void Process_vkGetPhysicalDeviceFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
        StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties) override;

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
        StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties) override;

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties) override;

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties) override;
    virtual void Process_vkTrimCommandPoolKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            commandPool,
        VkCommandPoolTrimFlags                      flags) override;
    virtual void Process_vkCreateDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate) override;

    virtual void Process_vkDestroyDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            descriptorUpdateTemplate,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;
    virtual void Process_vkCreateRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkRenderPass>*         pRenderPass) override;

    virtual void Process_vkCmdBeginRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo) override;

    virtual void Process_vkCmdNextSubpass2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) override;

    virtual void Process_vkCmdEndRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) override;
    virtual void Process_vkGetImageMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) override;

    virtual void Process_vkGetBufferMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) override;

    virtual void Process_vkGetImageSparseMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
        PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) override;
    virtual void Process_vkCmdDrawIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    virtual void Process_vkCmdDrawIndexedIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
