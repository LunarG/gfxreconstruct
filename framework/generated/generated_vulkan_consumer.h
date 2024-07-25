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

#ifndef  GFXRECON_GENERATED_VULKAN_CONSUMER_H
#define  GFXRECON_GENERATED_VULKAN_CONSUMER_H

#include "decode/vulkan_consumer_base.h"
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

class VulkanConsumer : public VulkanConsumerBase
{
  public:
    VulkanConsumer() { }

    virtual ~VulkanConsumer() override { }













































































































































    virtual void Process_vkCreateInstance(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkInstance>*           pInstance) {}

    virtual void Process_vkDestroyInstance(
        const ApiCallInfo&                          call_info,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkEnumeratePhysicalDevices(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
        HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices) {}

    virtual void Process_vkGetPhysicalDeviceFeatures(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures) {}

    virtual void Process_vkGetPhysicalDeviceFormatProperties(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties) {}

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkImageTiling                               tiling,
        VkImageUsageFlags                           usage,
        VkImageCreateFlags                          flags,
        StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties) {}

    virtual void Process_vkGetPhysicalDeviceProperties(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
        StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties) {}

    virtual void Process_vkGetPhysicalDeviceMemoryProperties(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties) {}

    virtual void Process_vkCreateDevice(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDevice>*             pDevice) {}

    virtual void Process_vkDestroyDevice(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkGetDeviceQueue(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        uint32_t                                    queueFamilyIndex,
        uint32_t                                    queueIndex,
        HandlePointerDecoder<VkQueue>*              pQueue) {}

    virtual void Process_vkQueueSubmit(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            queue,
        uint32_t                                    submitCount,
        StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
        format::HandleId                            fence) {}

    virtual void Process_vkQueueWaitIdle(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            queue) {}

    virtual void Process_vkDeviceWaitIdle(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device) {}

    virtual void Process_vkAllocateMemory(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDeviceMemory>*       pMemory) {}

    virtual void Process_vkFreeMemory(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            memory,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkMapMemory(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            memory,
        VkDeviceSize                                offset,
        VkDeviceSize                                size,
        VkMemoryMapFlags                            flags,
        PointerDecoder<uint64_t, void*>*            ppData) {}

    virtual void Process_vkUnmapMemory(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            memory) {}

    virtual void Process_vkFlushMappedMemoryRanges(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    memoryRangeCount,
        StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges) {}

    virtual void Process_vkInvalidateMappedMemoryRanges(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    memoryRangeCount,
        StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges) {}

    virtual void Process_vkGetDeviceMemoryCommitment(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            memory,
        PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes) {}

    virtual void Process_vkBindBufferMemory(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            buffer,
        format::HandleId                            memory,
        VkDeviceSize                                memoryOffset) {}

    virtual void Process_vkBindImageMemory(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            image,
        format::HandleId                            memory,
        VkDeviceSize                                memoryOffset) {}

    virtual void Process_vkGetBufferMemoryRequirements(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            buffer,
        StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) {}

    virtual void Process_vkGetImageMemoryRequirements(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) {}

    virtual void Process_vkGetImageSparseMemoryRequirements(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            image,
        PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements) {}

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkSampleCountFlagBits                       samples,
        VkImageUsageFlags                           usage,
        VkImageTiling                               tiling,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties) {}

    virtual void Process_vkQueueBindSparse(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            queue,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
        format::HandleId                            fence) {}

    virtual void Process_vkCreateFence(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkFence>*              pFence) {}

    virtual void Process_vkDestroyFence(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            fence,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkResetFences(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    fenceCount,
        HandlePointerDecoder<VkFence>*              pFences) {}

    virtual void Process_vkGetFenceStatus(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            fence) {}

    virtual void Process_vkWaitForFences(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    fenceCount,
        HandlePointerDecoder<VkFence>*              pFences,
        VkBool32                                    waitAll,
        uint64_t                                    timeout) {}

    virtual void Process_vkCreateSemaphore(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSemaphore>*          pSemaphore) {}

    virtual void Process_vkDestroySemaphore(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            semaphore,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCreateEvent(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkEvent>*              pEvent) {}

    virtual void Process_vkDestroyEvent(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            event,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkGetEventStatus(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            event) {}

    virtual void Process_vkSetEvent(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            event) {}

    virtual void Process_vkResetEvent(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            event) {}

    virtual void Process_vkCreateQueryPool(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkQueryPool>*          pQueryPool) {}

    virtual void Process_vkDestroyQueryPool(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            queryPool,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

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
        VkQueryResultFlags                          flags) {}

    virtual void Process_vkCreateBuffer(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkBuffer>*             pBuffer) {}

    virtual void Process_vkDestroyBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            buffer,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCreateBufferView(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkBufferView>*         pView) {}

    virtual void Process_vkDestroyBufferView(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            bufferView,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCreateImage(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkImage>*              pImage) {}

    virtual void Process_vkDestroyImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkGetImageSubresourceLayout(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
        StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout) {}

    virtual void Process_vkCreateImageView(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkImageView>*          pView) {}

    virtual void Process_vkDestroyImageView(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            imageView,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCreateShaderModule(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkShaderModule>*       pShaderModule) {}

    virtual void Process_vkDestroyShaderModule(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            shaderModule,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCreatePipelineCache(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipelineCache>*      pPipelineCache) {}

    virtual void Process_vkDestroyPipelineCache(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkGetPipelineCacheData(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        PointerDecoder<size_t>*                     pDataSize,
        PointerDecoder<uint8_t>*                    pData) {}

    virtual void Process_vkMergePipelineCaches(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            dstCache,
        uint32_t                                    srcCacheCount,
        HandlePointerDecoder<VkPipelineCache>*      pSrcCaches) {}

    virtual void Process_vkCreateGraphicsPipelines(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        uint32_t                                    createInfoCount,
        StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipeline>*           pPipelines) {}

    virtual void Process_vkCreateComputePipelines(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        uint32_t                                    createInfoCount,
        StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipeline>*           pPipelines) {}

    virtual void Process_vkDestroyPipeline(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCreatePipelineLayout(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout) {}

    virtual void Process_vkDestroyPipelineLayout(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            pipelineLayout,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCreateSampler(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSampler>*            pSampler) {}

    virtual void Process_vkDestroySampler(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            sampler,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCreateDescriptorSetLayout(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout) {}

    virtual void Process_vkDestroyDescriptorSetLayout(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            descriptorSetLayout,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCreateDescriptorPool(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool) {}

    virtual void Process_vkDestroyDescriptorPool(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            descriptorPool,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkResetDescriptorPool(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            descriptorPool,
        VkDescriptorPoolResetFlags                  flags) {}

    virtual void Process_vkAllocateDescriptorSets(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
        HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets) {}

    virtual void Process_vkFreeDescriptorSets(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            descriptorPool,
        uint32_t                                    descriptorSetCount,
        HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets) {}

    virtual void Process_vkUpdateDescriptorSets(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        uint32_t                                    descriptorWriteCount,
        StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
        uint32_t                                    descriptorCopyCount,
        StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies) {}

    virtual void Process_vkCreateFramebuffer(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkFramebuffer>*        pFramebuffer) {}

    virtual void Process_vkDestroyFramebuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            framebuffer,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCreateRenderPass(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkRenderPass>*         pRenderPass) {}

    virtual void Process_vkDestroyRenderPass(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            renderPass,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkGetRenderAreaGranularity(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            renderPass,
        StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity) {}

    virtual void Process_vkCreateCommandPool(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkCommandPool>*        pCommandPool) {}

    virtual void Process_vkDestroyCommandPool(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            commandPool,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkResetCommandPool(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            commandPool,
        VkCommandPoolResetFlags                     flags) {}

    virtual void Process_vkAllocateCommandBuffers(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
        HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers) {}

    virtual void Process_vkFreeCommandBuffers(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            commandPool,
        uint32_t                                    commandBufferCount,
        HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers) {}

    virtual void Process_vkBeginCommandBuffer(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) {}

    virtual void Process_vkEndCommandBuffer(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer) {}

    virtual void Process_vkResetCommandBuffer(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        VkCommandBufferResetFlags                   flags) {}

    virtual void Process_vkCmdBindPipeline(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            pipeline) {}

    virtual void Process_vkCmdSetViewport(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewport>*   pViewports) {}

    virtual void Process_vkCmdSetScissor(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstScissor,
        uint32_t                                    scissorCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pScissors) {}

    virtual void Process_vkCmdSetLineWidth(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        float                                       lineWidth) {}

    virtual void Process_vkCmdSetDepthBias(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        float                                       depthBiasConstantFactor,
        float                                       depthBiasClamp,
        float                                       depthBiasSlopeFactor) {}

    virtual void Process_vkCmdSetBlendConstants(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        PointerDecoder<float>*                      blendConstants) {}

    virtual void Process_vkCmdSetDepthBounds(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        float                                       minDepthBounds,
        float                                       maxDepthBounds) {}

    virtual void Process_vkCmdSetStencilCompareMask(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    compareMask) {}

    virtual void Process_vkCmdSetStencilWriteMask(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    writeMask) {}

    virtual void Process_vkCmdSetStencilReference(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    reference) {}

    virtual void Process_vkCmdBindDescriptorSets(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            layout,
        uint32_t                                    firstSet,
        uint32_t                                    descriptorSetCount,
        HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
        uint32_t                                    dynamicOffsetCount,
        PointerDecoder<uint32_t>*                   pDynamicOffsets) {}

    virtual void Process_vkCmdBindIndexBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        VkIndexType                                 indexType) {}

    virtual void Process_vkCmdBindVertexBuffers(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        HandlePointerDecoder<VkBuffer>*             pBuffers,
        PointerDecoder<VkDeviceSize>*               pOffsets) {}

    virtual void Process_vkCmdDraw(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    vertexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstVertex,
        uint32_t                                    firstInstance) {}

    virtual void Process_vkCmdDrawIndexed(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    indexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstIndex,
        int32_t                                     vertexOffset,
        uint32_t                                    firstInstance) {}

    virtual void Process_vkCmdDrawIndirect(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdDrawIndexedIndirect(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdDispatch(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) {}

    virtual void Process_vkCmdDispatchIndirect(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset) {}

    virtual void Process_vkCmdCopyBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcBuffer,
        format::HandleId                            dstBuffer,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkBufferCopy>* pRegions) {}

    virtual void Process_vkCmdCopyImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkImageCopy>*  pRegions) {}

    virtual void Process_vkCmdBlitImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkImageBlit>*  pRegions,
        VkFilter                                    filter) {}

    virtual void Process_vkCmdCopyBufferToImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcBuffer,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions) {}

    virtual void Process_vkCmdCopyImageToBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstBuffer,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions) {}

    virtual void Process_vkCmdUpdateBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                dataSize,
        PointerDecoder<uint8_t>*                    pData) {}

    virtual void Process_vkCmdFillBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                size,
        uint32_t                                    data) {}

    virtual void Process_vkCmdClearColorImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            image,
        VkImageLayout                               imageLayout,
        StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
        uint32_t                                    rangeCount,
        StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges) {}

    virtual void Process_vkCmdClearDepthStencilImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            image,
        VkImageLayout                               imageLayout,
        StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
        uint32_t                                    rangeCount,
        StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges) {}

    virtual void Process_vkCmdClearAttachments(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    attachmentCount,
        StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
        uint32_t                                    rectCount,
        StructPointerDecoder<Decoded_VkClearRect>*  pRects) {}

    virtual void Process_vkCmdResolveImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkImageResolve>* pRegions) {}

    virtual void Process_vkCmdSetEvent(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags                        stageMask) {}

    virtual void Process_vkCmdResetEvent(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags                        stageMask) {}

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
        StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers) {}

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
        StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers) {}

    virtual void Process_vkCmdBeginQuery(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query,
        VkQueryControlFlags                         flags) {}

    virtual void Process_vkCmdEndQuery(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query) {}

    virtual void Process_vkCmdResetQueryPool(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount) {}

    virtual void Process_vkCmdWriteTimestamp(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineStageFlagBits                     pipelineStage,
        format::HandleId                            queryPool,
        uint32_t                                    query) {}

    virtual void Process_vkCmdCopyQueryPoolResults(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                stride,
        VkQueryResultFlags                          flags) {}

    virtual void Process_vkCmdPushConstants(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            layout,
        VkShaderStageFlags                          stageFlags,
        uint32_t                                    offset,
        uint32_t                                    size,
        PointerDecoder<uint8_t>*                    pValues) {}

    virtual void Process_vkCmdBeginRenderPass(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
        VkSubpassContents                           contents) {}

    virtual void Process_vkCmdNextSubpass(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkSubpassContents                           contents) {}

    virtual void Process_vkCmdEndRenderPass(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer) {}

    virtual void Process_vkCmdExecuteCommands(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    commandBufferCount,
        HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers) {}

    virtual void Process_vkBindBufferMemory2(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos) {}

    virtual void Process_vkBindImageMemory2(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos) {}

    virtual void Process_vkGetDeviceGroupPeerMemoryFeatures(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        uint32_t                                    heapIndex,
        uint32_t                                    localDeviceIndex,
        uint32_t                                    remoteDeviceIndex,
        PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures) {}

    virtual void Process_vkCmdSetDeviceMask(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    deviceMask) {}

    virtual void Process_vkCmdDispatchBase(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    baseGroupX,
        uint32_t                                    baseGroupY,
        uint32_t                                    baseGroupZ,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) {}

    virtual void Process_vkEnumeratePhysicalDeviceGroups(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties) {}

    virtual void Process_vkGetImageMemoryRequirements2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkGetBufferMemoryRequirements2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkGetImageSparseMemoryRequirements2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
        PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) {}

    virtual void Process_vkGetPhysicalDeviceFeatures2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures) {}

    virtual void Process_vkGetPhysicalDeviceProperties2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties) {}

    virtual void Process_vkGetPhysicalDeviceFormatProperties2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties) {}

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
        StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
        StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties) {}

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties) {}

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties) {}

    virtual void Process_vkTrimCommandPool(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            commandPool,
        VkCommandPoolTrimFlags                      flags) {}

    virtual void Process_vkGetDeviceQueue2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
        HandlePointerDecoder<VkQueue>*              pQueue) {}

    virtual void Process_vkCreateSamplerYcbcrConversion(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion) {}

    virtual void Process_vkDestroySamplerYcbcrConversion(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            ycbcrConversion,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCreateDescriptorUpdateTemplate(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate) {}

    virtual void Process_vkDestroyDescriptorUpdateTemplate(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            descriptorUpdateTemplate,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkGetPhysicalDeviceExternalBufferProperties(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
        StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties) {}

    virtual void Process_vkGetPhysicalDeviceExternalFenceProperties(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
        StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties) {}

    virtual void Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
        StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties) {}

    virtual void Process_vkGetDescriptorSetLayoutSupport(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport) {}

    virtual void Process_vkCmdDrawIndirectCount(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdDrawIndexedIndirectCount(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCreateRenderPass2(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkRenderPass>*         pRenderPass) {}

    virtual void Process_vkCmdBeginRenderPass2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo) {}

    virtual void Process_vkCmdNextSubpass2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) {}

    virtual void Process_vkCmdEndRenderPass2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) {}

    virtual void Process_vkResetQueryPool(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount) {}

    virtual void Process_vkGetSemaphoreCounterValue(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            semaphore,
        PointerDecoder<uint64_t>*                   pValue) {}

    virtual void Process_vkWaitSemaphores(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
        uint64_t                                    timeout) {}

    virtual void Process_vkSignalSemaphore(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo) {}

    virtual void Process_vkGetBufferDeviceAddress(
        const ApiCallInfo&                          call_info,
        VkDeviceAddress                             returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) {}

    virtual void Process_vkGetBufferOpaqueCaptureAddress(
        const ApiCallInfo&                          call_info,
        uint64_t                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) {}

    virtual void Process_vkGetDeviceMemoryOpaqueCaptureAddress(
        const ApiCallInfo&                          call_info,
        uint64_t                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo) {}

    virtual void Process_vkGetPhysicalDeviceToolProperties(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pToolCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties) {}

    virtual void Process_vkCreatePrivateDataSlot(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot) {}

    virtual void Process_vkDestroyPrivateDataSlot(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            privateDataSlot,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkSetPrivateData(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkObjectType                                objectType,
        uint64_t                                    objectHandle,
        format::HandleId                            privateDataSlot,
        uint64_t                                    data) {}

    virtual void Process_vkGetPrivateData(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        VkObjectType                                objectType,
        uint64_t                                    objectHandle,
        format::HandleId                            privateDataSlot,
        PointerDecoder<uint64_t>*                   pData) {}

    virtual void Process_vkCmdSetEvent2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) {}

    virtual void Process_vkCmdResetEvent2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags2                       stageMask) {}

    virtual void Process_vkCmdWaitEvents2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    eventCount,
        HandlePointerDecoder<VkEvent>*              pEvents,
        StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos) {}

    virtual void Process_vkCmdPipelineBarrier2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) {}

    virtual void Process_vkCmdWriteTimestamp2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineStageFlags2                       stage,
        format::HandleId                            queryPool,
        uint32_t                                    query) {}

    virtual void Process_vkQueueSubmit2(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            queue,
        uint32_t                                    submitCount,
        StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
        format::HandleId                            fence) {}

    virtual void Process_vkCmdCopyBuffer2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo) {}

    virtual void Process_vkCmdCopyImage2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo) {}

    virtual void Process_vkCmdCopyBufferToImage2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo) {}

    virtual void Process_vkCmdCopyImageToBuffer2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo) {}

    virtual void Process_vkCmdBlitImage2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo) {}

    virtual void Process_vkCmdResolveImage2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo) {}

    virtual void Process_vkCmdBeginRendering(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo) {}

    virtual void Process_vkCmdEndRendering(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer) {}

    virtual void Process_vkCmdSetCullMode(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCullModeFlags                             cullMode) {}

    virtual void Process_vkCmdSetFrontFace(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkFrontFace                                 frontFace) {}

    virtual void Process_vkCmdSetPrimitiveTopology(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPrimitiveTopology                         primitiveTopology) {}

    virtual void Process_vkCmdSetViewportWithCount(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewport>*   pViewports) {}

    virtual void Process_vkCmdSetScissorWithCount(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    scissorCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pScissors) {}

    virtual void Process_vkCmdBindVertexBuffers2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        HandlePointerDecoder<VkBuffer>*             pBuffers,
        PointerDecoder<VkDeviceSize>*               pOffsets,
        PointerDecoder<VkDeviceSize>*               pSizes,
        PointerDecoder<VkDeviceSize>*               pStrides) {}

    virtual void Process_vkCmdSetDepthTestEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthTestEnable) {}

    virtual void Process_vkCmdSetDepthWriteEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthWriteEnable) {}

    virtual void Process_vkCmdSetDepthCompareOp(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCompareOp                                 depthCompareOp) {}

    virtual void Process_vkCmdSetDepthBoundsTestEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthBoundsTestEnable) {}

    virtual void Process_vkCmdSetStencilTestEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    stencilTestEnable) {}

    virtual void Process_vkCmdSetStencilOp(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        VkStencilOp                                 failOp,
        VkStencilOp                                 passOp,
        VkStencilOp                                 depthFailOp,
        VkCompareOp                                 compareOp) {}

    virtual void Process_vkCmdSetRasterizerDiscardEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    rasterizerDiscardEnable) {}

    virtual void Process_vkCmdSetDepthBiasEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthBiasEnable) {}

    virtual void Process_vkCmdSetPrimitiveRestartEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    primitiveRestartEnable) {}

    virtual void Process_vkGetDeviceBufferMemoryRequirements(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkGetDeviceImageMemoryRequirements(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkGetDeviceImageSparseMemoryRequirements(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
        PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) {}

    virtual void Process_vkDestroySurfaceKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            instance,
        format::HandleId                            surface,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceSupportKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        format::HandleId                            surface,
        PointerDecoder<VkBool32>*                   pSupported) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
        StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats) {}

    virtual void Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        PointerDecoder<uint32_t>*                   pPresentModeCount,
        PointerDecoder<VkPresentModeKHR>*           pPresentModes) {}

    virtual void Process_vkCreateSwapchainKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain) {}

    virtual void Process_vkDestroySwapchainKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkGetSwapchainImagesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        PointerDecoder<uint32_t>*                   pSwapchainImageCount,
        HandlePointerDecoder<VkImage>*              pSwapchainImages) {}

    virtual void Process_vkAcquireNextImageKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        uint64_t                                    timeout,
        format::HandleId                            semaphore,
        format::HandleId                            fence,
        PointerDecoder<uint32_t>*                   pImageIndex) {}

    virtual void Process_vkQueuePresentKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            queue,
        StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo) {}

    virtual void Process_vkGetDeviceGroupPresentCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities) {}

    virtual void Process_vkGetDeviceGroupSurfacePresentModesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            surface,
        PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes) {}

    virtual void Process_vkGetPhysicalDevicePresentRectanglesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        PointerDecoder<uint32_t>*                   pRectCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pRects) {}

    virtual void Process_vkAcquireNextImage2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
        PointerDecoder<uint32_t>*                   pImageIndex) {}

    virtual void Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties) {}

    virtual void Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties) {}

    virtual void Process_vkGetDisplayPlaneSupportedDisplaysKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    planeIndex,
        PointerDecoder<uint32_t>*                   pDisplayCount,
        HandlePointerDecoder<VkDisplayKHR>*         pDisplays) {}

    virtual void Process_vkGetDisplayModePropertiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            display,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties) {}

    virtual void Process_vkCreateDisplayModeKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            display,
        StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDisplayModeKHR>*     pMode) {}

    virtual void Process_vkGetDisplayPlaneCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            mode,
        uint32_t                                    planeIndex,
        StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities) {}

    virtual void Process_vkCreateDisplayPlaneSurfaceKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkCreateSharedSwapchainsKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    swapchainCount,
        StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains) {}

    virtual void Process_vkCreateXlibSurfaceKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    dpy,
        size_t                                      visualID) {}

    virtual void Process_vkCreateXcbSurfaceKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    connection,
        uint32_t                                    visual_id) {}

    virtual void Process_vkCreateWaylandSurfaceKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    display) {}

    virtual void Process_vkCreateAndroidSurfaceKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkCreateWin32SurfaceKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
        const ApiCallInfo&                          call_info,
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex) {}

    virtual void Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile,
        StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR>* pCapabilities) {}

    virtual void Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR>* pVideoFormatInfo,
        PointerDecoder<uint32_t>*                   pVideoFormatPropertyCount,
        StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR>* pVideoFormatProperties) {}

    virtual void Process_vkCreateVideoSessionKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkVideoSessionKHR>*    pVideoSession) {}

    virtual void Process_vkDestroyVideoSessionKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            videoSession,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkGetVideoSessionMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            videoSession,
        PointerDecoder<uint32_t>*                   pMemoryRequirementsCount,
        StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR>* pMemoryRequirements) {}

    virtual void Process_vkBindVideoSessionMemoryKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            videoSession,
        uint32_t                                    bindSessionMemoryInfoCount,
        StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos) {}

    virtual void Process_vkCreateVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkVideoSessionParametersKHR>* pVideoSessionParameters) {}

    virtual void Process_vkUpdateVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            videoSessionParameters,
        StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR>* pUpdateInfo) {}

    virtual void Process_vkDestroyVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            videoSessionParameters,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCmdBeginVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo) {}

    virtual void Process_vkCmdEndVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo) {}

    virtual void Process_vkCmdControlVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo) {}

    virtual void Process_vkCmdDecodeVideoKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo) {}

    virtual void Process_vkCmdBeginRenderingKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo) {}

    virtual void Process_vkCmdEndRenderingKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer) {}

    virtual void Process_vkGetPhysicalDeviceFeatures2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures) {}

    virtual void Process_vkGetPhysicalDeviceProperties2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties) {}

    virtual void Process_vkGetPhysicalDeviceFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties) {}

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
        StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
        StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties) {}

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties) {}

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties) {}

    virtual void Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        uint32_t                                    heapIndex,
        uint32_t                                    localDeviceIndex,
        uint32_t                                    remoteDeviceIndex,
        PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures) {}

    virtual void Process_vkCmdSetDeviceMaskKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    deviceMask) {}

    virtual void Process_vkCmdDispatchBaseKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    baseGroupX,
        uint32_t                                    baseGroupY,
        uint32_t                                    baseGroupZ,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) {}

    virtual void Process_vkTrimCommandPoolKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            commandPool,
        VkCommandPoolTrimFlags                      flags) {}

    virtual void Process_vkEnumeratePhysicalDeviceGroupsKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties) {}

    virtual void Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
        StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties) {}

    virtual void Process_vkGetMemoryWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
        PointerDecoder<uint64_t, void*>*            pHandle) {}

    virtual void Process_vkGetMemoryWin32HandlePropertiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        uint64_t                                    handle,
        StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties) {}

    virtual void Process_vkGetMemoryFdKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
        PointerDecoder<int>*                        pFd) {}

    virtual void Process_vkGetMemoryFdPropertiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        int                                         fd,
        StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties) {}

    virtual void Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
        StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties) {}

    virtual void Process_vkImportSemaphoreWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo) {}

    virtual void Process_vkGetSemaphoreWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
        PointerDecoder<uint64_t, void*>*            pHandle) {}

    virtual void Process_vkImportSemaphoreFdKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo) {}

    virtual void Process_vkGetSemaphoreFdKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
        PointerDecoder<int>*                        pFd) {}

    virtual void Process_vkCmdPushDescriptorSetKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            layout,
        uint32_t                                    set,
        uint32_t                                    descriptorWriteCount,
        StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites) {}

    virtual void Process_vkCreateDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate) {}

    virtual void Process_vkDestroyDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            descriptorUpdateTemplate,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCreateRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkRenderPass>*         pRenderPass) {}

    virtual void Process_vkCmdBeginRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo) {}

    virtual void Process_vkCmdNextSubpass2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) {}

    virtual void Process_vkCmdEndRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) {}

    virtual void Process_vkGetSwapchainStatusKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain) {}

    virtual void Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
        StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties) {}

    virtual void Process_vkImportFenceWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo) {}

    virtual void Process_vkGetFenceWin32HandleKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
        PointerDecoder<uint64_t, void*>*            pHandle) {}

    virtual void Process_vkImportFenceFdKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo) {}

    virtual void Process_vkGetFenceFdKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
        PointerDecoder<int>*                        pFd) {}

    virtual void Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        PointerDecoder<uint32_t>*                   pCounterCount,
        StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters,
        StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
        PointerDecoder<uint32_t>*                   pNumPasses) {}

    virtual void Process_vkAcquireProfilingLockKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo) {}

    virtual void Process_vkReleaseProfilingLockKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
        StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
        PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
        StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats) {}

    virtual void Process_vkGetPhysicalDeviceDisplayProperties2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties) {}

    virtual void Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties) {}

    virtual void Process_vkGetDisplayModeProperties2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            display,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties) {}

    virtual void Process_vkGetDisplayPlaneCapabilities2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
        StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities) {}

    virtual void Process_vkGetImageMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkGetBufferMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkGetImageSparseMemoryRequirements2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
        PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) {}

    virtual void Process_vkCreateSamplerYcbcrConversionKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion) {}

    virtual void Process_vkDestroySamplerYcbcrConversionKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            ycbcrConversion,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkBindBufferMemory2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos) {}

    virtual void Process_vkBindImageMemory2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos) {}

    virtual void Process_vkGetDescriptorSetLayoutSupportKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport) {}

    virtual void Process_vkCmdDrawIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdDrawIndexedIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkGetSemaphoreCounterValueKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            semaphore,
        PointerDecoder<uint64_t>*                   pValue) {}

    virtual void Process_vkWaitSemaphoresKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
        uint64_t                                    timeout) {}

    virtual void Process_vkSignalSemaphoreKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo) {}

    virtual void Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pFragmentShadingRateCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates) {}

    virtual void Process_vkCmdSetFragmentShadingRateKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
        PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps) {}

    virtual void Process_vkCmdSetRenderingAttachmentLocationsKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfoKHR>* pLocationInfo) {}

    virtual void Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfoKHR>* pInputAttachmentIndexInfo) {}

    virtual void Process_vkWaitForPresentKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        uint64_t                                    presentId,
        uint64_t                                    timeout) {}

    virtual void Process_vkGetBufferDeviceAddressKHR(
        const ApiCallInfo&                          call_info,
        VkDeviceAddress                             returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) {}

    virtual void Process_vkGetBufferOpaqueCaptureAddressKHR(
        const ApiCallInfo&                          call_info,
        uint64_t                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) {}

    virtual void Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
        const ApiCallInfo&                          call_info,
        uint64_t                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo) {}

    virtual void Process_vkCreateDeferredOperationKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation) {}

    virtual void Process_vkDestroyDeferredOperationKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            operation,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkGetDeferredOperationMaxConcurrencyKHR(
        const ApiCallInfo&                          call_info,
        uint32_t                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            operation) {}

    virtual void Process_vkGetDeferredOperationResultKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            operation) {}

    virtual void Process_vkDeferredOperationJoinKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            operation) {}

    virtual void Process_vkGetPipelineExecutablePropertiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo,
        PointerDecoder<uint32_t>*                   pExecutableCount,
        StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties) {}

    virtual void Process_vkGetPipelineExecutableStatisticsKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
        PointerDecoder<uint32_t>*                   pStatisticCount,
        StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics) {}

    virtual void Process_vkGetPipelineExecutableInternalRepresentationsKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
        PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
        StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations) {}

    virtual void Process_vkMapMemory2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMemoryMapInfoKHR>* pMemoryMapInfo,
        PointerDecoder<uint64_t, void*>*            ppData) {}

    virtual void Process_vkUnmapMemory2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMemoryUnmapInfoKHR>* pMemoryUnmapInfo) {}

    virtual void Process_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR>* pQualityLevelInfo,
        StructPointerDecoder<Decoded_VkVideoEncodeQualityLevelPropertiesKHR>* pQualityLevelProperties) {}

    virtual void Process_vkGetEncodedVideoSessionParametersKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersGetInfoKHR>* pVideoSessionParametersInfo,
        StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR>* pFeedbackInfo,
        PointerDecoder<size_t>*                     pDataSize,
        PointerDecoder<uint8_t>*                    pData) {}

    virtual void Process_vkCmdEncodeVideoKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo) {}

    virtual void Process_vkCmdSetEvent2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) {}

    virtual void Process_vkCmdResetEvent2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags2                       stageMask) {}

    virtual void Process_vkCmdWaitEvents2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    eventCount,
        HandlePointerDecoder<VkEvent>*              pEvents,
        StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos) {}

    virtual void Process_vkCmdPipelineBarrier2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) {}

    virtual void Process_vkCmdWriteTimestamp2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineStageFlags2                       stage,
        format::HandleId                            queryPool,
        uint32_t                                    query) {}

    virtual void Process_vkQueueSubmit2KHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            queue,
        uint32_t                                    submitCount,
        StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
        format::HandleId                            fence) {}

    virtual void Process_vkCmdWriteBufferMarker2AMD(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineStageFlags2                       stage,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        uint32_t                                    marker) {}

    virtual void Process_vkGetQueueCheckpointData2NV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            queue,
        PointerDecoder<uint32_t>*                   pCheckpointDataCount,
        StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData) {}

    virtual void Process_vkCmdCopyBuffer2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo) {}

    virtual void Process_vkCmdCopyImage2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo) {}

    virtual void Process_vkCmdCopyBufferToImage2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo) {}

    virtual void Process_vkCmdCopyImageToBuffer2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo) {}

    virtual void Process_vkCmdBlitImage2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo) {}

    virtual void Process_vkCmdResolveImage2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo) {}

    virtual void Process_vkCmdTraceRaysIndirect2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkDeviceAddress                             indirectDeviceAddress) {}

    virtual void Process_vkGetDeviceBufferMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkGetDeviceImageMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
        PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) {}

    virtual void Process_vkCmdBindIndexBuffer2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        VkDeviceSize                                size,
        VkIndexType                                 indexType) {}

    virtual void Process_vkGetRenderingAreaGranularityKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkRenderingAreaInfoKHR>* pRenderingAreaInfo,
        StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity) {}

    virtual void Process_vkGetDeviceImageSubresourceLayoutKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfoKHR>* pInfo,
        StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout) {}

    virtual void Process_vkGetImageSubresourceLayout2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkImageSubresource2KHR>* pSubresource,
        StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout) {}

    virtual void Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesKHR>* pProperties) {}

    virtual void Process_vkCmdSetLineStippleKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    lineStippleFactor,
        uint16_t                                    lineStipplePattern) {}

    virtual void Process_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pTimeDomainCount,
        PointerDecoder<VkTimeDomainKHR>*            pTimeDomains) {}

    virtual void Process_vkGetCalibratedTimestampsKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    timestampCount,
        StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR>* pTimestampInfos,
        PointerDecoder<uint64_t>*                   pTimestamps,
        PointerDecoder<uint64_t>*                   pMaxDeviation) {}

    virtual void Process_vkCmdBindDescriptorSets2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkBindDescriptorSetsInfoKHR>* pBindDescriptorSetsInfo) {}

    virtual void Process_vkCmdPushConstants2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPushConstantsInfoKHR>* pPushConstantsInfo) {}

    virtual void Process_vkCmdPushDescriptorSet2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPushDescriptorSetInfoKHR>* pPushDescriptorSetInfo) {}

    virtual void Process_vkCmdSetDescriptorBufferOffsets2EXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSetDescriptorBufferOffsetsInfoEXT>* pSetDescriptorBufferOffsetsInfo) {}

    virtual void Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT>* pBindDescriptorBufferEmbeddedSamplersInfo) {}

    virtual void Process_vkFrameBoundaryANDROID(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            semaphore,
        format::HandleId                            image) {}

    virtual void Process_vkCreateDebugReportCallbackEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback) {}

    virtual void Process_vkDestroyDebugReportCallbackEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            instance,
        format::HandleId                            callback,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkDebugReportMessageEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            instance,
        VkDebugReportFlagsEXT                       flags,
        VkDebugReportObjectTypeEXT                  objectType,
        uint64_t                                    object,
        size_t                                      location,
        int32_t                                     messageCode,
        StringDecoder*                              pLayerPrefix,
        StringDecoder*                              pMessage) {}

    virtual void Process_vkDebugMarkerSetObjectTagEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo) {}

    virtual void Process_vkDebugMarkerSetObjectNameEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo) {}

    virtual void Process_vkCmdDebugMarkerBeginEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo) {}

    virtual void Process_vkCmdDebugMarkerEndEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer) {}

    virtual void Process_vkCmdDebugMarkerInsertEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo) {}

    virtual void Process_vkCmdBindTransformFeedbackBuffersEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        HandlePointerDecoder<VkBuffer>*             pBuffers,
        PointerDecoder<VkDeviceSize>*               pOffsets,
        PointerDecoder<VkDeviceSize>*               pSizes) {}

    virtual void Process_vkCmdBeginTransformFeedbackEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstCounterBuffer,
        uint32_t                                    counterBufferCount,
        HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
        PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets) {}

    virtual void Process_vkCmdEndTransformFeedbackEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstCounterBuffer,
        uint32_t                                    counterBufferCount,
        HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
        PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets) {}

    virtual void Process_vkCmdBeginQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query,
        VkQueryControlFlags                         flags,
        uint32_t                                    index) {}

    virtual void Process_vkCmdEndQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query,
        uint32_t                                    index) {}

    virtual void Process_vkCmdDrawIndirectByteCountEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    instanceCount,
        uint32_t                                    firstInstance,
        format::HandleId                            counterBuffer,
        VkDeviceSize                                counterBufferOffset,
        uint32_t                                    counterOffset,
        uint32_t                                    vertexStride) {}

    virtual void Process_vkGetImageViewHandleNVX(
        const ApiCallInfo&                          call_info,
        uint32_t                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo) {}

    virtual void Process_vkGetImageViewAddressNVX(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            imageView,
        StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties) {}

    virtual void Process_vkCmdDrawIndirectCountAMD(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdDrawIndexedIndirectCountAMD(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkGetShaderInfoAMD(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        VkShaderStageFlagBits                       shaderStage,
        VkShaderInfoTypeAMD                         infoType,
        PointerDecoder<size_t>*                     pInfoSize,
        PointerDecoder<uint8_t>*                    pInfo) {}

    virtual void Process_vkCreateStreamDescriptorSurfaceGGP(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkImageTiling                               tiling,
        VkImageUsageFlags                           usage,
        VkImageCreateFlags                          flags,
        VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
        StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>* pExternalImageFormatProperties) {}

    virtual void Process_vkGetMemoryWin32HandleNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            memory,
        VkExternalMemoryHandleTypeFlagsNV           handleType,
        PointerDecoder<uint64_t, void*>*            pHandle) {}

    virtual void Process_vkCreateViSurfaceNN(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkCmdBeginConditionalRenderingEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin) {}

    virtual void Process_vkCmdEndConditionalRenderingEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer) {}

    virtual void Process_vkCmdSetViewportWScalingNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings) {}

    virtual void Process_vkReleaseDisplayEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            display) {}

    virtual void Process_vkAcquireXlibDisplayEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint64_t                                    dpy,
        format::HandleId                            display) {}

    virtual void Process_vkGetRandROutputDisplayEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint64_t                                    dpy,
        size_t                                      rrOutput,
        HandlePointerDecoder<VkDisplayKHR>*         pDisplay) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities) {}

    virtual void Process_vkDisplayPowerControlEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            display,
        StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo) {}

    virtual void Process_vkRegisterDeviceEventEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkFence>*              pFence) {}

    virtual void Process_vkRegisterDisplayEventEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            display,
        StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkFence>*              pFence) {}

    virtual void Process_vkGetSwapchainCounterEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        VkSurfaceCounterFlagBitsEXT                 counter,
        PointerDecoder<uint64_t>*                   pCounterValue) {}

    virtual void Process_vkGetRefreshCycleDurationGOOGLE(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties) {}

    virtual void Process_vkGetPastPresentationTimingGOOGLE(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        PointerDecoder<uint32_t>*                   pPresentationTimingCount,
        StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings) {}

    virtual void Process_vkCmdSetDiscardRectangleEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstDiscardRectangle,
        uint32_t                                    discardRectangleCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles) {}

    virtual void Process_vkCmdSetDiscardRectangleEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    discardRectangleEnable) {}

    virtual void Process_vkCmdSetDiscardRectangleModeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkDiscardRectangleModeEXT                   discardRectangleMode) {}

    virtual void Process_vkSetHdrMetadataEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        uint32_t                                    swapchainCount,
        HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains,
        StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata) {}

    virtual void Process_vkCreateIOSSurfaceMVK(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkCreateMacOSSurfaceMVK(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkSetDebugUtilsObjectNameEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo) {}

    virtual void Process_vkSetDebugUtilsObjectTagEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo) {}

    virtual void Process_vkQueueBeginDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            queue,
        StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) {}

    virtual void Process_vkQueueEndDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            queue) {}

    virtual void Process_vkQueueInsertDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            queue,
        StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) {}

    virtual void Process_vkCmdBeginDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) {}

    virtual void Process_vkCmdEndDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer) {}

    virtual void Process_vkCmdInsertDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) {}

    virtual void Process_vkCreateDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger) {}

    virtual void Process_vkDestroyDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            instance,
        format::HandleId                            messenger,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkSubmitDebugUtilsMessageEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            instance,
        VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
        StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData) {}

    virtual void Process_vkGetAndroidHardwareBufferPropertiesANDROID(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint64_t                                    buffer,
        StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties) {}

    virtual void Process_vkGetMemoryAndroidHardwareBufferANDROID(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
        PointerDecoder<uint64_t, void*>*            pBuffer) {}

    virtual void Process_vkCmdSetSampleLocationsEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo) {}

    virtual void Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            physicalDevice,
        VkSampleCountFlagBits                       samples,
        StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties) {}

    virtual void Process_vkGetImageDrmFormatModifierPropertiesEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties) {}

    virtual void Process_vkCreateValidationCacheEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache) {}

    virtual void Process_vkDestroyValidationCacheEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            validationCache,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkMergeValidationCachesEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            dstCache,
        uint32_t                                    srcCacheCount,
        HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches) {}

    virtual void Process_vkGetValidationCacheDataEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            validationCache,
        PointerDecoder<size_t>*                     pDataSize,
        PointerDecoder<uint8_t>*                    pData) {}

    virtual void Process_vkCmdBindShadingRateImageNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            imageView,
        VkImageLayout                               imageLayout) {}

    virtual void Process_vkCmdSetViewportShadingRatePaletteNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes) {}

    virtual void Process_vkCmdSetCoarseSampleOrderNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCoarseSampleOrderTypeNV                   sampleOrderType,
        uint32_t                                    customSampleOrderCount,
        StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders) {}

    virtual void Process_vkCreateAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure) {}

    virtual void Process_vkDestroyAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            accelerationStructure,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkGetAccelerationStructureMemoryRequirementsNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkBindAccelerationStructureMemoryNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos) {}

    virtual void Process_vkCmdBuildAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV>* pInfo,
        format::HandleId                            instanceData,
        VkDeviceSize                                instanceOffset,
        VkBool32                                    update,
        format::HandleId                            dst,
        format::HandleId                            src,
        format::HandleId                            scratch,
        VkDeviceSize                                scratchOffset) {}

    virtual void Process_vkCmdCopyAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            dst,
        format::HandleId                            src,
        VkCopyAccelerationStructureModeKHR          mode) {}

    virtual void Process_vkCmdTraceRaysNV(
        const ApiCallInfo&                          call_info,
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
        uint32_t                                    depth) {}

    virtual void Process_vkCreateRayTracingPipelinesNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        uint32_t                                    createInfoCount,
        StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPipeline>*           pPipelines) {}

    virtual void Process_vkGetRayTracingShaderGroupHandlesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        uint32_t                                    firstGroup,
        uint32_t                                    groupCount,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData) {}

    virtual void Process_vkGetRayTracingShaderGroupHandlesNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        uint32_t                                    firstGroup,
        uint32_t                                    groupCount,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData) {}

    virtual void Process_vkGetAccelerationStructureHandleNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            accelerationStructure,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData) {}

    virtual void Process_vkCmdWriteAccelerationStructuresPropertiesNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    accelerationStructureCount,
        HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures,
        VkQueryType                                 queryType,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery) {}

    virtual void Process_vkCompileDeferredNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        uint32_t                                    shader) {}

    virtual void Process_vkGetMemoryHostPointerPropertiesEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        uint64_t                                    pHostPointer,
        StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties) {}

    virtual void Process_vkCmdWriteBufferMarkerAMD(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineStageFlagBits                     pipelineStage,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        uint32_t                                    marker) {}

    virtual void Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pTimeDomainCount,
        PointerDecoder<VkTimeDomainKHR>*            pTimeDomains) {}

    virtual void Process_vkGetCalibratedTimestampsEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    timestampCount,
        StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR>* pTimestampInfos,
        PointerDecoder<uint64_t>*                   pTimestamps,
        PointerDecoder<uint64_t>*                   pMaxDeviation) {}

    virtual void Process_vkCmdDrawMeshTasksNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    taskCount,
        uint32_t                                    firstTask) {}

    virtual void Process_vkCmdDrawMeshTasksIndirectNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdDrawMeshTasksIndirectCountNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdSetExclusiveScissorEnableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstExclusiveScissor,
        uint32_t                                    exclusiveScissorCount,
        PointerDecoder<VkBool32>*                   pExclusiveScissorEnables) {}

    virtual void Process_vkCmdSetExclusiveScissorNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstExclusiveScissor,
        uint32_t                                    exclusiveScissorCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors) {}

    virtual void Process_vkCmdSetCheckpointNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint64_t                                    pCheckpointMarker) {}

    virtual void Process_vkGetQueueCheckpointDataNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            queue,
        PointerDecoder<uint32_t>*                   pCheckpointDataCount,
        StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData) {}

    virtual void Process_vkInitializePerformanceApiINTEL(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo) {}

    virtual void Process_vkUninitializePerformanceApiINTEL(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device) {}

    virtual void Process_vkCmdSetPerformanceMarkerINTEL(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo) {}

    virtual void Process_vkCmdSetPerformanceStreamMarkerINTEL(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo) {}

    virtual void Process_vkCmdSetPerformanceOverrideINTEL(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo) {}

    virtual void Process_vkAcquirePerformanceConfigurationINTEL(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
        HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration) {}

    virtual void Process_vkReleasePerformanceConfigurationINTEL(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            configuration) {}

    virtual void Process_vkQueueSetPerformanceConfigurationINTEL(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            queue,
        format::HandleId                            configuration) {}

    virtual void Process_vkGetPerformanceParameterINTEL(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkPerformanceParameterTypeINTEL             parameter,
        StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue) {}

    virtual void Process_vkSetLocalDimmingAMD(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            swapChain,
        VkBool32                                    localDimmingEnable) {}

    virtual void Process_vkCreateImagePipeSurfaceFUCHSIA(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkCreateMetalSurfaceEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetBufferDeviceAddressEXT(
        const ApiCallInfo&                          call_info,
        VkDeviceAddress                             returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) {}

    virtual void Process_vkGetPhysicalDeviceToolPropertiesEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pToolCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties) {}

    virtual void Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties) {}

    virtual void Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pCombinationCount,
        StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations) {}

    virtual void Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
        PointerDecoder<uint32_t>*                   pPresentModeCount,
        PointerDecoder<VkPresentModeKHR>*           pPresentModes) {}

    virtual void Process_vkAcquireFullScreenExclusiveModeEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain) {}

    virtual void Process_vkReleaseFullScreenExclusiveModeEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain) {}

    virtual void Process_vkGetDeviceGroupSurfacePresentModes2EXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
        PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes) {}

    virtual void Process_vkCreateHeadlessSurfaceEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkCmdSetLineStippleEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    lineStippleFactor,
        uint16_t                                    lineStipplePattern) {}

    virtual void Process_vkResetQueryPoolEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount) {}

    virtual void Process_vkCmdSetCullModeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCullModeFlags                             cullMode) {}

    virtual void Process_vkCmdSetFrontFaceEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkFrontFace                                 frontFace) {}

    virtual void Process_vkCmdSetPrimitiveTopologyEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPrimitiveTopology                         primitiveTopology) {}

    virtual void Process_vkCmdSetViewportWithCountEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewport>*   pViewports) {}

    virtual void Process_vkCmdSetScissorWithCountEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    scissorCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pScissors) {}

    virtual void Process_vkCmdBindVertexBuffers2EXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        HandlePointerDecoder<VkBuffer>*             pBuffers,
        PointerDecoder<VkDeviceSize>*               pOffsets,
        PointerDecoder<VkDeviceSize>*               pSizes,
        PointerDecoder<VkDeviceSize>*               pStrides) {}

    virtual void Process_vkCmdSetDepthTestEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthTestEnable) {}

    virtual void Process_vkCmdSetDepthWriteEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthWriteEnable) {}

    virtual void Process_vkCmdSetDepthCompareOpEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCompareOp                                 depthCompareOp) {}

    virtual void Process_vkCmdSetDepthBoundsTestEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthBoundsTestEnable) {}

    virtual void Process_vkCmdSetStencilTestEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    stencilTestEnable) {}

    virtual void Process_vkCmdSetStencilOpEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        VkStencilOp                                 failOp,
        VkStencilOp                                 passOp,
        VkStencilOp                                 depthFailOp,
        VkCompareOp                                 compareOp) {}

    virtual void Process_vkCopyMemoryToImageEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkCopyMemoryToImageInfoEXT>* pCopyMemoryToImageInfo) {}

    virtual void Process_vkCopyImageToMemoryEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkCopyImageToMemoryInfoEXT>* pCopyImageToMemoryInfo) {}

    virtual void Process_vkCopyImageToImageEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkCopyImageToImageInfoEXT>* pCopyImageToImageInfo) {}

    virtual void Process_vkTransitionImageLayoutEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    transitionCount,
        StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfoEXT>* pTransitions) {}

    virtual void Process_vkGetImageSubresourceLayout2EXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkImageSubresource2KHR>* pSubresource,
        StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout) {}

    virtual void Process_vkReleaseSwapchainImagesEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo) {}

    virtual void Process_vkGetGeneratedCommandsMemoryRequirementsNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkCmdPreprocessGeneratedCommandsNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo) {}

    virtual void Process_vkCmdExecuteGeneratedCommandsNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    isPreprocessed,
        StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo) {}

    virtual void Process_vkCmdBindPipelineShaderGroupNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            pipeline,
        uint32_t                                    groupIndex) {}

    virtual void Process_vkCreateIndirectCommandsLayoutNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout) {}

    virtual void Process_vkDestroyIndirectCommandsLayoutNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            indirectCommandsLayout,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCmdSetDepthBias2EXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDepthBiasInfoEXT>* pDepthBiasInfo) {}

    virtual void Process_vkAcquireDrmDisplayEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        int32_t                                     drmFd,
        format::HandleId                            display) {}

    virtual void Process_vkGetDrmDisplayEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        int32_t                                     drmFd,
        uint32_t                                    connectorId,
        HandlePointerDecoder<VkDisplayKHR>*         display) {}

    virtual void Process_vkCreatePrivateDataSlotEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot) {}

    virtual void Process_vkDestroyPrivateDataSlotEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            privateDataSlot,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkSetPrivateDataEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkObjectType                                objectType,
        uint64_t                                    objectHandle,
        format::HandleId                            privateDataSlot,
        uint64_t                                    data) {}

    virtual void Process_vkGetPrivateDataEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        VkObjectType                                objectType,
        uint64_t                                    objectHandle,
        format::HandleId                            privateDataSlot,
        PointerDecoder<uint64_t>*                   pData) {}

    virtual void Process_vkCmdSetFragmentShadingRateEnumNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkFragmentShadingRateNV                     shadingRate,
        PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps) {}

    virtual void Process_vkGetDeviceFaultInfoEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT>* pFaultCounts,
        StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT>* pFaultInfo) {}

    virtual void Process_vkAcquireWinrtDisplayNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            display) {}

    virtual void Process_vkGetWinrtDisplayNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    deviceRelativeId,
        HandlePointerDecoder<VkDisplayKHR>*         pDisplay) {}

    virtual void Process_vkCreateDirectFBSurfaceEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
        const ApiCallInfo&                          call_info,
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    dfb) {}

    virtual void Process_vkCmdSetVertexInputEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    vertexBindingDescriptionCount,
        StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions,
        uint32_t                                    vertexAttributeDescriptionCount,
        StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions) {}

    virtual void Process_vkGetMemoryZirconHandleFUCHSIA(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
        PointerDecoder<uint32_t>*                   pZirconHandle) {}

    virtual void Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        uint32_t                                    zirconHandle,
        StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA>* pMemoryZirconHandleProperties) {}

    virtual void Process_vkImportSemaphoreZirconHandleFUCHSIA(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo) {}

    virtual void Process_vkGetSemaphoreZirconHandleFUCHSIA(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
        PointerDecoder<uint32_t>*                   pZirconHandle) {}

    virtual void Process_vkCmdBindInvocationMaskHUAWEI(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            imageView,
        VkImageLayout                               imageLayout) {}

    virtual void Process_vkGetMemoryRemoteAddressNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo,
        PointerDecoder<uint64_t, void*>*            pAddress) {}

    virtual void Process_vkCmdSetPatchControlPointsEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    patchControlPoints) {}

    virtual void Process_vkCmdSetRasterizerDiscardEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    rasterizerDiscardEnable) {}

    virtual void Process_vkCmdSetDepthBiasEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthBiasEnable) {}

    virtual void Process_vkCmdSetLogicOpEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkLogicOp                                   logicOp) {}

    virtual void Process_vkCmdSetPrimitiveRestartEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    primitiveRestartEnable) {}

    virtual void Process_vkCreateScreenSurfaceQNX(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
        const ApiCallInfo&                          call_info,
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    window) {}

    virtual void Process_vkCmdSetColorWriteEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    attachmentCount,
        PointerDecoder<VkBool32>*                   pColorWriteEnables) {}

    virtual void Process_vkCmdDrawMultiEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    drawCount,
        StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo,
        uint32_t                                    instanceCount,
        uint32_t                                    firstInstance,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdDrawMultiIndexedEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    drawCount,
        StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo,
        uint32_t                                    instanceCount,
        uint32_t                                    firstInstance,
        uint32_t                                    stride,
        PointerDecoder<int32_t>*                    pVertexOffset) {}

    virtual void Process_vkCreateMicromapEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkMicromapEXT>*        pMicromap) {}

    virtual void Process_vkDestroyMicromapEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            micromap,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCmdBuildMicromapsEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    infoCount,
        StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos) {}

    virtual void Process_vkBuildMicromapsEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            deferredOperation,
        uint32_t                                    infoCount,
        StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos) {}

    virtual void Process_vkCopyMicromapEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            deferredOperation,
        StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo) {}

    virtual void Process_vkCopyMicromapToMemoryEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            deferredOperation,
        StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo) {}

    virtual void Process_vkCopyMemoryToMicromapEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            deferredOperation,
        StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo) {}

    virtual void Process_vkWriteMicromapsPropertiesEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    micromapCount,
        HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
        VkQueryType                                 queryType,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData,
        size_t                                      stride) {}

    virtual void Process_vkCmdCopyMicromapEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo) {}

    virtual void Process_vkCmdCopyMicromapToMemoryEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo) {}

    virtual void Process_vkCmdCopyMemoryToMicromapEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo) {}

    virtual void Process_vkCmdWriteMicromapsPropertiesEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    micromapCount,
        HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
        VkQueryType                                 queryType,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery) {}

    virtual void Process_vkGetDeviceMicromapCompatibilityEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo,
        PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility) {}

    virtual void Process_vkGetMicromapBuildSizesEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        VkAccelerationStructureBuildTypeKHR         buildType,
        StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pBuildInfo,
        StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT>* pSizeInfo) {}

    virtual void Process_vkCmdDrawClusterHUAWEI(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) {}

    virtual void Process_vkCmdDrawClusterIndirectHUAWEI(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset) {}

    virtual void Process_vkSetDeviceMemoryPriorityEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            memory,
        float                                       priority) {}

    virtual void Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping) {}

    virtual void Process_vkGetDescriptorSetHostMappingVALVE(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            descriptorSet,
        PointerDecoder<uint64_t, void*>*            ppData) {}

    virtual void Process_vkGetPipelineIndirectMemoryRequirementsNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkCmdUpdatePipelineIndirectBufferNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            pipeline) {}

    virtual void Process_vkGetPipelineIndirectDeviceAddressNV(
        const ApiCallInfo&                          call_info,
        VkDeviceAddress                             returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkPipelineIndirectDeviceAddressInfoNV>* pInfo) {}

    virtual void Process_vkCmdSetDepthClampEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthClampEnable) {}

    virtual void Process_vkCmdSetPolygonModeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPolygonMode                               polygonMode) {}

    virtual void Process_vkCmdSetRasterizationSamplesEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkSampleCountFlagBits                       rasterizationSamples) {}

    virtual void Process_vkCmdSetSampleMaskEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkSampleCountFlagBits                       samples,
        PointerDecoder<VkSampleMask>*               pSampleMask) {}

    virtual void Process_vkCmdSetAlphaToCoverageEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    alphaToCoverageEnable) {}

    virtual void Process_vkCmdSetAlphaToOneEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    alphaToOneEnable) {}

    virtual void Process_vkCmdSetLogicOpEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    logicOpEnable) {}

    virtual void Process_vkCmdSetColorBlendEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstAttachment,
        uint32_t                                    attachmentCount,
        PointerDecoder<VkBool32>*                   pColorBlendEnables) {}

    virtual void Process_vkCmdSetColorBlendEquationEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstAttachment,
        uint32_t                                    attachmentCount,
        StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations) {}

    virtual void Process_vkCmdSetColorWriteMaskEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstAttachment,
        uint32_t                                    attachmentCount,
        PointerDecoder<VkColorComponentFlags>*      pColorWriteMasks) {}

    virtual void Process_vkCmdSetTessellationDomainOriginEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkTessellationDomainOrigin                  domainOrigin) {}

    virtual void Process_vkCmdSetRasterizationStreamEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    rasterizationStream) {}

    virtual void Process_vkCmdSetConservativeRasterizationModeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkConservativeRasterizationModeEXT          conservativeRasterizationMode) {}

    virtual void Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        float                                       extraPrimitiveOverestimationSize) {}

    virtual void Process_vkCmdSetDepthClipEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthClipEnable) {}

    virtual void Process_vkCmdSetSampleLocationsEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    sampleLocationsEnable) {}

    virtual void Process_vkCmdSetColorBlendAdvancedEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstAttachment,
        uint32_t                                    attachmentCount,
        StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced) {}

    virtual void Process_vkCmdSetProvokingVertexModeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkProvokingVertexModeEXT                    provokingVertexMode) {}

    virtual void Process_vkCmdSetLineRasterizationModeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkLineRasterizationModeEXT                  lineRasterizationMode) {}

    virtual void Process_vkCmdSetLineStippleEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    stippledLineEnable) {}

    virtual void Process_vkCmdSetDepthClipNegativeOneToOneEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    negativeOneToOne) {}

    virtual void Process_vkCmdSetViewportWScalingEnableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    viewportWScalingEnable) {}

    virtual void Process_vkCmdSetViewportSwizzleNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles) {}

    virtual void Process_vkCmdSetCoverageToColorEnableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    coverageToColorEnable) {}

    virtual void Process_vkCmdSetCoverageToColorLocationNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    coverageToColorLocation) {}

    virtual void Process_vkCmdSetCoverageModulationModeNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCoverageModulationModeNV                  coverageModulationMode) {}

    virtual void Process_vkCmdSetCoverageModulationTableEnableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    coverageModulationTableEnable) {}

    virtual void Process_vkCmdSetCoverageModulationTableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    coverageModulationTableCount,
        PointerDecoder<float>*                      pCoverageModulationTable) {}

    virtual void Process_vkCmdSetShadingRateImageEnableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    shadingRateImageEnable) {}

    virtual void Process_vkCmdSetRepresentativeFragmentTestEnableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    representativeFragmentTestEnable) {}

    virtual void Process_vkCmdSetCoverageReductionModeNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCoverageReductionModeNV                   coverageReductionMode) {}

    virtual void Process_vkGetShaderModuleIdentifierEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            shaderModule,
        StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier) {}

    virtual void Process_vkGetShaderModuleCreateInfoIdentifierEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier) {}

    virtual void Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV>* pOpticalFlowImageFormatInfo,
        PointerDecoder<uint32_t>*                   pFormatCount,
        StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV>* pImageFormatProperties) {}

    virtual void Process_vkCreateOpticalFlowSessionNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession) {}

    virtual void Process_vkDestroyOpticalFlowSessionNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkBindOpticalFlowSessionImageNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            session,
        VkOpticalFlowSessionBindingPointNV          bindingPoint,
        format::HandleId                            view,
        VkImageLayout                               layout) {}

    virtual void Process_vkCmdOpticalFlowExecuteNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo) {}

    virtual void Process_vkCreateShadersEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    createInfoCount,
        StructPointerDecoder<Decoded_VkShaderCreateInfoEXT>* pCreateInfos,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkShaderEXT>*          pShaders) {}

    virtual void Process_vkDestroyShaderEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            shader,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkGetShaderBinaryDataEXT(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            shader,
        PointerDecoder<size_t>*                     pDataSize,
        PointerDecoder<uint8_t>*                    pData) {}

    virtual void Process_vkCmdBindShadersEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    stageCount,
        PointerDecoder<VkShaderStageFlagBits>*      pStages,
        HandlePointerDecoder<VkShaderEXT>*          pShaders) {}

    virtual void Process_vkGetFramebufferTilePropertiesQCOM(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            framebuffer,
        PointerDecoder<uint32_t>*                   pPropertiesCount,
        StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties) {}

    virtual void Process_vkGetDynamicRenderingTilePropertiesQCOM(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo,
        StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties) {}

    virtual void Process_vkSetLatencySleepModeNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_VkLatencySleepModeInfoNV>* pSleepModeInfo) {}

    virtual void Process_vkLatencySleepNV(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_VkLatencySleepInfoNV>* pSleepInfo) {}

    virtual void Process_vkSetLatencyMarkerNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_VkSetLatencyMarkerInfoNV>* pLatencyMarkerInfo) {}

    virtual void Process_vkGetLatencyTimingsNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_VkGetLatencyMarkerInfoNV>* pLatencyMarkerInfo) {}

    virtual void Process_vkQueueNotifyOutOfBandNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            queue,
        StructPointerDecoder<Decoded_VkOutOfBandQueueTypeInfoNV>* pQueueTypeInfo) {}

    virtual void Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkImageAspectFlags                          aspectMask) {}

    virtual void Process_vkCreateAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
        HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure) {}

    virtual void Process_vkDestroyAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        format::HandleId                            accelerationStructure,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) {}

    virtual void Process_vkCmdBuildAccelerationStructuresKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    infoCount,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos) {}

    virtual void Process_vkCmdBuildAccelerationStructuresIndirectKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    infoCount,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
        PointerDecoder<VkDeviceAddress>*            pIndirectDeviceAddresses,
        PointerDecoder<uint32_t>*                   pIndirectStrides,
        PointerDecoder<uint32_t*>*                  ppMaxPrimitiveCounts) {}

    virtual void Process_vkCopyAccelerationStructureToMemoryKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            deferredOperation,
        StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo) {}

    virtual void Process_vkCopyMemoryToAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            deferredOperation,
        StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo) {}

    virtual void Process_vkWriteAccelerationStructuresPropertiesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    accelerationStructureCount,
        HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
        VkQueryType                                 queryType,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData,
        size_t                                      stride) {}

    virtual void Process_vkCmdCopyAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo) {}

    virtual void Process_vkCmdCopyAccelerationStructureToMemoryKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo) {}

    virtual void Process_vkCmdCopyMemoryToAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo) {}

    virtual void Process_vkGetAccelerationStructureDeviceAddressKHR(
        const ApiCallInfo&                          call_info,
        VkDeviceAddress                             returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo) {}

    virtual void Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    accelerationStructureCount,
        HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
        VkQueryType                                 queryType,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery) {}

    virtual void Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo,
        PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility) {}

    virtual void Process_vkGetAccelerationStructureBuildSizesKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            device,
        VkAccelerationStructureBuildTypeKHR         buildType,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo,
        PointerDecoder<uint32_t>*                   pMaxPrimitiveCounts,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>* pSizeInfo) {}

    virtual void Process_vkCmdTraceRaysKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
        uint32_t                                    width,
        uint32_t                                    height,
        uint32_t                                    depth) {}

    virtual void Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        uint32_t                                    firstGroup,
        uint32_t                                    groupCount,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData) {}

    virtual void Process_vkCmdTraceRaysIndirectKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
        VkDeviceAddress                             indirectDeviceAddress) {}

    virtual void Process_vkGetRayTracingShaderGroupStackSizeKHR(
        const ApiCallInfo&                          call_info,
        VkDeviceSize                                returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        uint32_t                                    group,
        VkShaderGroupShaderKHR                      groupShader) {}

    virtual void Process_vkCmdSetRayTracingPipelineStackSizeKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    pipelineStackSize) {}

    virtual void Process_vkCmdDrawMeshTasksEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) {}

    virtual void Process_vkCmdDrawMeshTasksIndirectEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdDrawMeshTasksIndirectCountEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) {}
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
