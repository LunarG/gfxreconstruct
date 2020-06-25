/*
** Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved**
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

#include "generated/generated_vulkan_resource_tracking_consumer.h"

#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanResourceTrackingConsumer::Process_vkCreateInstance(
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    OverrideCreateInstance(pCreateInfo, pAllocator, pInstance);
}

void VulkanResourceTrackingConsumer::Process_vkDestroyInstance(
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    OverrideDestroyInstance(instance, pAllocator);
}

void VulkanResourceTrackingConsumer::Process_vkEnumeratePhysicalDevices(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices)
{
    OverrideEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceFeatures(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    //printf("%s\n", "vkGetPhysicalDeviceFeatures");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceFormatProperties");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceImageFormatProperties");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceProperties");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceQueueFamilyProperties");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceMemoryProperties");
}

void VulkanResourceTrackingConsumer::Process_vkCreateDevice(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*             pDevice)
{
    OverrideCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
}

void VulkanResourceTrackingConsumer::Process_vkDestroyDevice(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    OverrideDestroyDevice(device, pAllocator);
}

void VulkanResourceTrackingConsumer::Process_vkGetDeviceQueue(
    format::HandleId                            device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    //printf("%s\n", "vkGetDeviceQueue");
}

void VulkanResourceTrackingConsumer::Process_vkQueueSubmit(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
    format::HandleId                            fence)
{
    //printf("%s\n", "vkQueueSubmit");
}

void VulkanResourceTrackingConsumer::Process_vkQueueWaitIdle(
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    //printf("%s\n", "vkQueueWaitIdle");
}

void VulkanResourceTrackingConsumer::Process_vkDeviceWaitIdle(
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    //printf("%s\n", "vkDeviceWaitIdle");
}

void VulkanResourceTrackingConsumer::Process_vkAllocateMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*       pMemory)
{
    OverrideAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
}

void VulkanResourceTrackingConsumer::Process_vkFreeMemory(
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkFreeMemory");
}

void VulkanResourceTrackingConsumer::Process_vkMapMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    OverrideMapMemory(device, memory, offset, size, flags, ppData);
}

void VulkanResourceTrackingConsumer::Process_vkUnmapMemory(
    format::HandleId                            device,
    format::HandleId                            memory)
{
    //printf("%s\n", "vkUnmapMemory");
}

void VulkanResourceTrackingConsumer::Process_vkFlushMappedMemoryRanges(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    //printf("%s\n", "vkFlushMappedMemoryRanges");
}

void VulkanResourceTrackingConsumer::Process_vkInvalidateMappedMemoryRanges(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    //printf("%s\n", "vkInvalidateMappedMemoryRanges");
}

void VulkanResourceTrackingConsumer::Process_vkGetDeviceMemoryCommitment(
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    //printf("%s\n", "vkGetDeviceMemoryCommitment");
}

void VulkanResourceTrackingConsumer::Process_vkBindBufferMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            buffer,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    OverrideBindBufferMemory(device, buffer, memory, memoryOffset);
}

void VulkanResourceTrackingConsumer::Process_vkBindImageMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    OverrideBindImageMemory(device, image, memory, memoryOffset);
}

void VulkanResourceTrackingConsumer::Process_vkGetBufferMemoryRequirements(
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    OverrideGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
}

void VulkanResourceTrackingConsumer::Process_vkGetImageMemoryRequirements(
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    OverrideGetImageMemoryRequirements(device, image, pMemoryRequirements);
}

void VulkanResourceTrackingConsumer::Process_vkGetImageSparseMemoryRequirements(
    format::HandleId                            device,
    format::HandleId                            image,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    //printf("%s\n", "vkGetImageSparseMemoryRequirements");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceSparseImageFormatProperties");
}

void VulkanResourceTrackingConsumer::Process_vkQueueBindSparse(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
    format::HandleId                            fence)
{
    //printf("%s\n", "vkQueueBindSparse");
}

void VulkanResourceTrackingConsumer::Process_vkCreateFence(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    //printf("%s\n", "vkCreateFence");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyFence(
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyFence");
}

void VulkanResourceTrackingConsumer::Process_vkResetFences(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences)
{
    //printf("%s\n", "vkResetFences");
}

void VulkanResourceTrackingConsumer::Process_vkGetFenceStatus(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    //printf("%s\n", "vkGetFenceStatus");
}

void VulkanResourceTrackingConsumer::Process_vkWaitForFences(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    //printf("%s\n", "vkWaitForFences");
}

void VulkanResourceTrackingConsumer::Process_vkCreateSemaphore(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSemaphore>*          pSemaphore)
{
    //printf("%s\n", "vkCreateSemaphore");
}

void VulkanResourceTrackingConsumer::Process_vkDestroySemaphore(
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroySemaphore");
}

void VulkanResourceTrackingConsumer::Process_vkCreateEvent(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkEvent>*              pEvent)
{
    //printf("%s\n", "vkCreateEvent");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyEvent(
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyEvent");
}

void VulkanResourceTrackingConsumer::Process_vkGetEventStatus(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    //printf("%s\n", "vkGetEventStatus");
}

void VulkanResourceTrackingConsumer::Process_vkSetEvent(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    //printf("%s\n", "vkSetEvent");
}

void VulkanResourceTrackingConsumer::Process_vkResetEvent(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    //printf("%s\n", "vkResetEvent");
}

void VulkanResourceTrackingConsumer::Process_vkCreateQueryPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkQueryPool>*          pQueryPool)
{
    //printf("%s\n", "vkCreateQueryPool");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyQueryPool(
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyQueryPool");
}

void VulkanResourceTrackingConsumer::Process_vkGetQueryPoolResults(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    //printf("%s\n", "vkGetQueryPoolResults");
}

void VulkanResourceTrackingConsumer::Process_vkCreateBuffer(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*             pBuffer)
{
    OverrideCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
}

void VulkanResourceTrackingConsumer::Process_vkDestroyBuffer(
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    OverrideDestroyBuffer(device, buffer, pAllocator);
}

void VulkanResourceTrackingConsumer::Process_vkCreateBufferView(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBufferView>*         pView)
{
    //printf("%s\n", "vkCreateBufferView");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyBufferView(
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyBufferView");
}

void VulkanResourceTrackingConsumer::Process_vkCreateImage(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*              pImage)
{
    OverrideCreateImage(device, pCreateInfo, pAllocator, pImage);
}

void VulkanResourceTrackingConsumer::Process_vkDestroyImage(
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    OverrideDestroyImage(device, image, pAllocator);
}

void VulkanResourceTrackingConsumer::Process_vkGetImageSubresourceLayout(
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout)
{
    //printf("%s\n", "vkGetImageSubresourceLayout");
}

void VulkanResourceTrackingConsumer::Process_vkCreateImageView(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImageView>*          pView)
{
    //printf("%s\n", "vkCreateImageView");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyImageView(
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyImageView");
}

void VulkanResourceTrackingConsumer::Process_vkCreateShaderModule(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderModule>*       pShaderModule)
{
    //printf("%s\n", "vkCreateShaderModule");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyShaderModule(
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyShaderModule");
}

void VulkanResourceTrackingConsumer::Process_vkCreatePipelineCache(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineCache>*      pPipelineCache)
{
    //printf("%s\n", "vkCreatePipelineCache");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyPipelineCache(
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyPipelineCache");
}

void VulkanResourceTrackingConsumer::Process_vkGetPipelineCacheData(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    //printf("%s\n", "vkGetPipelineCacheData");
}

void VulkanResourceTrackingConsumer::Process_vkMergePipelineCaches(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkPipelineCache>*      pSrcCaches)
{
    //printf("%s\n", "vkMergePipelineCaches");
}

void VulkanResourceTrackingConsumer::Process_vkCreateGraphicsPipelines(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    //printf("%s\n", "vkCreateGraphicsPipelines");
}

void VulkanResourceTrackingConsumer::Process_vkCreateComputePipelines(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    //printf("%s\n", "vkCreateComputePipelines");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyPipeline(
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyPipeline");
}

void VulkanResourceTrackingConsumer::Process_vkCreatePipelineLayout(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout)
{
    //printf("%s\n", "vkCreatePipelineLayout");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyPipelineLayout(
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyPipelineLayout");
}

void VulkanResourceTrackingConsumer::Process_vkCreateSampler(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSampler>*            pSampler)
{
    //printf("%s\n", "vkCreateSampler");
}

void VulkanResourceTrackingConsumer::Process_vkDestroySampler(
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroySampler");
}

void VulkanResourceTrackingConsumer::Process_vkCreateDescriptorSetLayout(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout)
{
    //printf("%s\n", "vkCreateDescriptorSetLayout");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyDescriptorSetLayout(
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyDescriptorSetLayout");
}

void VulkanResourceTrackingConsumer::Process_vkCreateDescriptorPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool)
{
    //printf("%s\n", "vkCreateDescriptorPool");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyDescriptorPool(
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyDescriptorPool");
}

void VulkanResourceTrackingConsumer::Process_vkResetDescriptorPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    //printf("%s\n", "vkResetDescriptorPool");
}

void VulkanResourceTrackingConsumer::Process_vkAllocateDescriptorSets(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    //printf("%s\n", "vkAllocateDescriptorSets");
}

void VulkanResourceTrackingConsumer::Process_vkFreeDescriptorSets(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    //printf("%s\n", "vkFreeDescriptorSets");
}

void VulkanResourceTrackingConsumer::Process_vkUpdateDescriptorSets(
    format::HandleId                            device,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies)
{
    //printf("%s\n", "vkUpdateDescriptorSets");
}

void VulkanResourceTrackingConsumer::Process_vkCreateFramebuffer(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFramebuffer>*        pFramebuffer)
{
    //printf("%s\n", "vkCreateFramebuffer");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyFramebuffer(
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyFramebuffer");
}

void VulkanResourceTrackingConsumer::Process_vkCreateRenderPass(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    //printf("%s\n", "vkCreateRenderPass");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyRenderPass(
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyRenderPass");
}

void VulkanResourceTrackingConsumer::Process_vkGetRenderAreaGranularity(
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    //printf("%s\n", "vkGetRenderAreaGranularity");
}

void VulkanResourceTrackingConsumer::Process_vkCreateCommandPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkCommandPool>*        pCommandPool)
{
    //printf("%s\n", "vkCreateCommandPool");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyCommandPool(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyCommandPool");
}

void VulkanResourceTrackingConsumer::Process_vkResetCommandPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolResetFlags                     flags)
{
    //printf("%s\n", "vkResetCommandPool");
}

void VulkanResourceTrackingConsumer::Process_vkAllocateCommandBuffers(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    //printf("%s\n", "vkAllocateCommandBuffers");
}

void VulkanResourceTrackingConsumer::Process_vkFreeCommandBuffers(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    //printf("%s\n", "vkFreeCommandBuffers");
}

void VulkanResourceTrackingConsumer::Process_vkBeginCommandBuffer(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    //printf("%s\n", "vkBeginCommandBuffer");
}

void VulkanResourceTrackingConsumer::Process_vkEndCommandBuffer(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    //printf("%s\n", "vkEndCommandBuffer");
}

void VulkanResourceTrackingConsumer::Process_vkResetCommandBuffer(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    //printf("%s\n", "vkResetCommandBuffer");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBindPipeline(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    //printf("%s\n", "vkCmdBindPipeline");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetViewport(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    //printf("%s\n", "vkCmdSetViewport");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetScissor(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    //printf("%s\n", "vkCmdSetScissor");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetLineWidth(
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    //printf("%s\n", "vkCmdSetLineWidth");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetDepthBias(
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    //printf("%s\n", "vkCmdSetDepthBias");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetBlendConstants(
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    //printf("%s\n", "vkCmdSetBlendConstants");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetDepthBounds(
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    //printf("%s\n", "vkCmdSetDepthBounds");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetStencilCompareMask(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    //printf("%s\n", "vkCmdSetStencilCompareMask");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetStencilWriteMask(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    //printf("%s\n", "vkCmdSetStencilWriteMask");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetStencilReference(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    //printf("%s\n", "vkCmdSetStencilReference");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBindDescriptorSets(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    PointerDecoder<uint32_t>*                   pDynamicOffsets)
{
    //printf("%s\n", "vkCmdBindDescriptorSets");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBindIndexBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    //printf("%s\n", "vkCmdBindIndexBuffer");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBindVertexBuffers(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    //printf("%s\n", "vkCmdBindVertexBuffers");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDraw(
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    //printf("%s\n", "vkCmdDraw");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDrawIndexed(
    format::HandleId                            commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    //printf("%s\n", "vkCmdDrawIndexed");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDrawIndirect(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    //printf("%s\n", "vkCmdDrawIndirect");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDrawIndexedIndirect(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    //printf("%s\n", "vkCmdDrawIndexedIndirect");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDispatch(
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    //printf("%s\n", "vkCmdDispatch");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDispatchIndirect(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    //printf("%s\n", "vkCmdDispatchIndirect");
}

void VulkanResourceTrackingConsumer::Process_vkCmdCopyBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{
    //printf("%s\n", "vkCmdCopyBuffer");
}

void VulkanResourceTrackingConsumer::Process_vkCmdCopyImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageCopy>*  pRegions)
{
    //printf("%s\n", "vkCmdCopyImage");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBlitImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageBlit>*  pRegions,
    VkFilter                                    filter)
{
    //printf("%s\n", "vkCmdBlitImage");
}

void VulkanResourceTrackingConsumer::Process_vkCmdCopyBufferToImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    //printf("%s\n", "vkCmdCopyBufferToImage");
}

void VulkanResourceTrackingConsumer::Process_vkCmdCopyImageToBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    //printf("%s\n", "vkCmdCopyImageToBuffer");
}

void VulkanResourceTrackingConsumer::Process_vkCmdUpdateBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    //printf("%s\n", "vkCmdUpdateBuffer");
}

void VulkanResourceTrackingConsumer::Process_vkCmdFillBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    //printf("%s\n", "vkCmdFillBuffer");
}

void VulkanResourceTrackingConsumer::Process_vkCmdClearColorImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    //printf("%s\n", "vkCmdClearColorImage");
}

void VulkanResourceTrackingConsumer::Process_vkCmdClearDepthStencilImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    //printf("%s\n", "vkCmdClearDepthStencilImage");
}

void VulkanResourceTrackingConsumer::Process_vkCmdClearAttachments(
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
    uint32_t                                    rectCount,
    StructPointerDecoder<Decoded_VkClearRect>*  pRects)
{
    //printf("%s\n", "vkCmdClearAttachments");
}

void VulkanResourceTrackingConsumer::Process_vkCmdResolveImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageResolve>* pRegions)
{
    //printf("%s\n", "vkCmdResolveImage");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetEvent(
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    //printf("%s\n", "vkCmdSetEvent");
}

void VulkanResourceTrackingConsumer::Process_vkCmdResetEvent(
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    //printf("%s\n", "vkCmdResetEvent");
}

void VulkanResourceTrackingConsumer::Process_vkCmdWaitEvents(
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
    StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers)
{
    //printf("%s\n", "vkCmdWaitEvents");
}

void VulkanResourceTrackingConsumer::Process_vkCmdPipelineBarrier(
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers)
{
    //printf("%s\n", "vkCmdPipelineBarrier");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBeginQuery(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    //printf("%s\n", "vkCmdBeginQuery");
}

void VulkanResourceTrackingConsumer::Process_vkCmdEndQuery(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    //printf("%s\n", "vkCmdEndQuery");
}

void VulkanResourceTrackingConsumer::Process_vkCmdResetQueryPool(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    //printf("%s\n", "vkCmdResetQueryPool");
}

void VulkanResourceTrackingConsumer::Process_vkCmdWriteTimestamp(
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    //printf("%s\n", "vkCmdWriteTimestamp");
}

void VulkanResourceTrackingConsumer::Process_vkCmdCopyQueryPoolResults(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    //printf("%s\n", "vkCmdCopyQueryPoolResults");
}

void VulkanResourceTrackingConsumer::Process_vkCmdPushConstants(
    format::HandleId                            commandBuffer,
    format::HandleId                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    PointerDecoder<uint8_t>*                    pValues)
{
    //printf("%s\n", "vkCmdPushConstants");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBeginRenderPass(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    //printf("%s\n", "vkCmdBeginRenderPass");
}

void VulkanResourceTrackingConsumer::Process_vkCmdNextSubpass(
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    //printf("%s\n", "vkCmdNextSubpass");
}

void VulkanResourceTrackingConsumer::Process_vkCmdEndRenderPass(
    format::HandleId                            commandBuffer)
{
    //printf("%s\n", "vkCmdEndRenderPass");
}

void VulkanResourceTrackingConsumer::Process_vkCmdExecuteCommands(
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    //printf("%s\n", "vkCmdExecuteCommands");
}

void VulkanResourceTrackingConsumer::Process_vkBindBufferMemory2(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    OverrideBindBufferMemory2(device, bindInfoCount, pBindInfos);
}

void VulkanResourceTrackingConsumer::Process_vkBindImageMemory2(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    OverrideBindImageMemory2(device, bindInfoCount, pBindInfos);
}

void VulkanResourceTrackingConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    //printf("%s\n", "vkGetDeviceGroupPeerMemoryFeatures");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetDeviceMask(
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    //printf("%s\n", "vkCmdSetDeviceMask");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDispatchBase(
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    //printf("%s\n", "vkCmdDispatchBase");
}

void VulkanResourceTrackingConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    //printf("%s\n", "vkEnumeratePhysicalDeviceGroups");
}

void VulkanResourceTrackingConsumer::Process_vkGetImageMemoryRequirements2(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    //printf("%s\n", "vkGetImageMemoryRequirements2");
}

void VulkanResourceTrackingConsumer::Process_vkGetBufferMemoryRequirements2(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    //printf("%s\n", "vkGetBufferMemoryRequirements2");
}

void VulkanResourceTrackingConsumer::Process_vkGetImageSparseMemoryRequirements2(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    //printf("%s\n", "vkGetImageSparseMemoryRequirements2");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceFeatures2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    //printf("%s\n", "vkGetPhysicalDeviceFeatures2");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceProperties2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceProperties2");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceFormatProperties2");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceImageFormatProperties2");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceQueueFamilyProperties2");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceMemoryProperties2");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceSparseImageFormatProperties2");
}

void VulkanResourceTrackingConsumer::Process_vkTrimCommandPool(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    //printf("%s\n", "vkTrimCommandPool");
}

void VulkanResourceTrackingConsumer::Process_vkGetDeviceQueue2(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    //printf("%s\n", "vkGetDeviceQueue2");
}

void VulkanResourceTrackingConsumer::Process_vkCreateSamplerYcbcrConversion(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    //printf("%s\n", "vkCreateSamplerYcbcrConversion");
}

void VulkanResourceTrackingConsumer::Process_vkDestroySamplerYcbcrConversion(
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroySamplerYcbcrConversion");
}

void VulkanResourceTrackingConsumer::Process_vkCreateDescriptorUpdateTemplate(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    //printf("%s\n", "vkCreateDescriptorUpdateTemplate");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyDescriptorUpdateTemplate");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceExternalBufferProperties");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceExternalFenceProperties");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceExternalSemaphoreProperties");
}

void VulkanResourceTrackingConsumer::Process_vkGetDescriptorSetLayoutSupport(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    //printf("%s\n", "vkGetDescriptorSetLayoutSupport");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDrawIndirectCount(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    //printf("%s\n", "vkCmdDrawIndirectCount");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDrawIndexedIndirectCount(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    //printf("%s\n", "vkCmdDrawIndexedIndirectCount");
}

void VulkanResourceTrackingConsumer::Process_vkCreateRenderPass2(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    //printf("%s\n", "vkCreateRenderPass2");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBeginRenderPass2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    //printf("%s\n", "vkCmdBeginRenderPass2");
}

void VulkanResourceTrackingConsumer::Process_vkCmdNextSubpass2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    //printf("%s\n", "vkCmdNextSubpass2");
}

void VulkanResourceTrackingConsumer::Process_vkCmdEndRenderPass2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    //printf("%s\n", "vkCmdEndRenderPass2");
}

void VulkanResourceTrackingConsumer::Process_vkResetQueryPool(
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    //printf("%s\n", "vkResetQueryPool");
}

void VulkanResourceTrackingConsumer::Process_vkGetSemaphoreCounterValue(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    //printf("%s\n", "vkGetSemaphoreCounterValue");
}

void VulkanResourceTrackingConsumer::Process_vkWaitSemaphores(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    //printf("%s\n", "vkWaitSemaphores");
}

void VulkanResourceTrackingConsumer::Process_vkSignalSemaphore(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    //printf("%s\n", "vkSignalSemaphore");
}

void VulkanResourceTrackingConsumer::Process_vkGetBufferDeviceAddress(
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    //printf("%s\n", "vkGetBufferDeviceAddress");
}

void VulkanResourceTrackingConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    //printf("%s\n", "vkGetBufferOpaqueCaptureAddress");
}

void VulkanResourceTrackingConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    //printf("%s\n", "vkGetDeviceMemoryOpaqueCaptureAddress");
}

void VulkanResourceTrackingConsumer::Process_vkDestroySurfaceKHR(
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroySurfaceKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    format::HandleId                            surface,
    PointerDecoder<VkBool32>*                   pSupported)
{
    //printf("%s\n", "vkGetPhysicalDeviceSurfaceSupportKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    //printf("%s\n", "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats)
{
    //printf("%s\n", "vkGetPhysicalDeviceSurfaceFormatsKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    //printf("%s\n", "vkGetPhysicalDeviceSurfacePresentModesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateSwapchainKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain)
{
    //printf("%s\n", "vkCreateSwapchainKHR");
}

void VulkanResourceTrackingConsumer::Process_vkDestroySwapchainKHR(
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroySwapchainKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetSwapchainImagesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pSwapchainImageCount,
    HandlePointerDecoder<VkImage>*              pSwapchainImages)
{
    //printf("%s\n", "vkGetSwapchainImagesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkAcquireNextImageKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    timeout,
    format::HandleId                            semaphore,
    format::HandleId                            fence,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    //printf("%s\n", "vkAcquireNextImageKHR");
}

void VulkanResourceTrackingConsumer::Process_vkQueuePresentKHR(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    //printf("%s\n", "vkQueuePresentKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    //printf("%s\n", "vkGetDeviceGroupPresentCapabilitiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            surface,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    //printf("%s\n", "vkGetDeviceGroupSurfacePresentModesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pRectCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pRects)
{
    //printf("%s\n", "vkGetPhysicalDevicePresentRectanglesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkAcquireNextImage2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    //printf("%s\n", "vkAcquireNextImage2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceDisplayPropertiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    planeIndex,
    PointerDecoder<uint32_t>*                   pDisplayCount,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplays)
{
    //printf("%s\n", "vkGetDisplayPlaneSupportedDisplaysKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetDisplayModePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties)
{
    //printf("%s\n", "vkGetDisplayModePropertiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateDisplayModeKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDisplayModeKHR>*     pMode)
{
    //printf("%s\n", "vkCreateDisplayModeKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            mode,
    uint32_t                                    planeIndex,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities)
{
    //printf("%s\n", "vkGetDisplayPlaneCapabilitiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    //printf("%s\n", "vkCreateDisplayPlaneSurfaceKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateSharedSwapchainsKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains)
{
    //printf("%s\n", "vkCreateSharedSwapchainsKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateXlibSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    //printf("%s\n", "vkCreateXlibSurfaceKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dpy,
    size_t                                      visualID)
{
    //printf("%s\n", "vkGetPhysicalDeviceXlibPresentationSupportKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateXcbSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    //printf("%s\n", "vkCreateXcbSurfaceKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    connection,
    uint32_t                                    visual_id)
{
    //printf("%s\n", "vkGetPhysicalDeviceXcbPresentationSupportKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateWaylandSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    //printf("%s\n", "vkCreateWaylandSurfaceKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    display)
{
    //printf("%s\n", "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateAndroidSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    //printf("%s\n", "vkCreateAndroidSurfaceKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateWin32SurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    //printf("%s\n", "vkCreateWin32SurfaceKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    //printf("%s\n", "vkGetPhysicalDeviceWin32PresentationSupportKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    //printf("%s\n", "vkGetPhysicalDeviceFeatures2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceProperties2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceFormatProperties2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceImageFormatProperties2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceMemoryProperties2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    //printf("%s\n", "vkGetDeviceGroupPeerMemoryFeaturesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetDeviceMaskKHR(
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    //printf("%s\n", "vkCmdSetDeviceMaskKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDispatchBaseKHR(
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    //printf("%s\n", "vkCmdDispatchBaseKHR");
}

void VulkanResourceTrackingConsumer::Process_vkTrimCommandPoolKHR(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    //printf("%s\n", "vkTrimCommandPoolKHR");
}

void VulkanResourceTrackingConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    //printf("%s\n", "vkEnumeratePhysicalDeviceGroupsKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetMemoryWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    //printf("%s\n", "vkGetMemoryWin32HandleKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    handle,
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties)
{
    //printf("%s\n", "vkGetMemoryWin32HandlePropertiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetMemoryFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    //printf("%s\n", "vkGetMemoryFdKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetMemoryFdPropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties)
{
    //printf("%s\n", "vkGetMemoryFdPropertiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    //printf("%s\n", "vkImportSemaphoreWin32HandleKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    //printf("%s\n", "vkGetSemaphoreWin32HandleKHR");
}

void VulkanResourceTrackingConsumer::Process_vkImportSemaphoreFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    //printf("%s\n", "vkImportSemaphoreFdKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetSemaphoreFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    //printf("%s\n", "vkGetSemaphoreFdKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdPushDescriptorSetKHR(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    //printf("%s\n", "vkCmdPushDescriptorSetKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    //printf("%s\n", "vkCreateDescriptorUpdateTemplateKHR");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyDescriptorUpdateTemplateKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateRenderPass2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    //printf("%s\n", "vkCreateRenderPass2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBeginRenderPass2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    //printf("%s\n", "vkCmdBeginRenderPass2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdNextSubpass2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    //printf("%s\n", "vkCmdNextSubpass2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdEndRenderPass2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    //printf("%s\n", "vkCmdEndRenderPass2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetSwapchainStatusKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    //printf("%s\n", "vkGetSwapchainStatusKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceExternalFencePropertiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkImportFenceWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    //printf("%s\n", "vkImportFenceWin32HandleKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetFenceWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    //printf("%s\n", "vkGetFenceWin32HandleKHR");
}

void VulkanResourceTrackingConsumer::Process_vkImportFenceFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    //printf("%s\n", "vkImportFenceFdKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetFenceFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    //printf("%s\n", "vkGetFenceFdKHR");
}

void VulkanResourceTrackingConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    PointerDecoder<uint32_t>*                   pCounterCount,
    StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters,
    StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions)
{
    //printf("%s\n", "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    //printf("%s\n", "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkAcquireProfilingLockKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    //printf("%s\n", "vkAcquireProfilingLockKHR");
}

void VulkanResourceTrackingConsumer::Process_vkReleaseProfilingLockKHR(
    format::HandleId                            device)
{
    //printf("%s\n", "vkReleaseProfilingLockKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities)
{
    //printf("%s\n", "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats)
{
    //printf("%s\n", "vkGetPhysicalDeviceSurfaceFormats2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceDisplayProperties2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetDisplayModeProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties)
{
    //printf("%s\n", "vkGetDisplayModeProperties2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities)
{
    //printf("%s\n", "vkGetDisplayPlaneCapabilities2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetImageMemoryRequirements2KHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    //printf("%s\n", "vkGetImageMemoryRequirements2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    //printf("%s\n", "vkGetBufferMemoryRequirements2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    //printf("%s\n", "vkGetImageSparseMemoryRequirements2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    //printf("%s\n", "vkCreateSamplerYcbcrConversionKHR");
}

void VulkanResourceTrackingConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroySamplerYcbcrConversionKHR");
}

void VulkanResourceTrackingConsumer::Process_vkBindBufferMemory2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    //printf("%s\n", "vkBindBufferMemory2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkBindImageMemory2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    //printf("%s\n", "vkBindImageMemory2KHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    //printf("%s\n", "vkGetDescriptorSetLayoutSupportKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDrawIndirectCountKHR(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    //printf("%s\n", "vkCmdDrawIndirectCountKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    //printf("%s\n", "vkCmdDrawIndexedIndirectCountKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetSemaphoreCounterValueKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    //printf("%s\n", "vkGetSemaphoreCounterValueKHR");
}

void VulkanResourceTrackingConsumer::Process_vkWaitSemaphoresKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    //printf("%s\n", "vkWaitSemaphoresKHR");
}

void VulkanResourceTrackingConsumer::Process_vkSignalSemaphoreKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    //printf("%s\n", "vkSignalSemaphoreKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetBufferDeviceAddressKHR(
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    //printf("%s\n", "vkGetBufferDeviceAddressKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    //printf("%s\n", "vkGetBufferOpaqueCaptureAddressKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    //printf("%s\n", "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateDeferredOperationKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation)
{
    //printf("%s\n", "vkCreateDeferredOperationKHR");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyDeferredOperationKHR(
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyDeferredOperationKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    //printf("%s\n", "vkGetDeferredOperationMaxConcurrencyKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetDeferredOperationResultKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    //printf("%s\n", "vkGetDeferredOperationResultKHR");
}

void VulkanResourceTrackingConsumer::Process_vkDeferredOperationJoinKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    //printf("%s\n", "vkDeferredOperationJoinKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo,
    PointerDecoder<uint32_t>*                   pExecutableCount,
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties)
{
    //printf("%s\n", "vkGetPipelineExecutablePropertiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pStatisticCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics)
{
    //printf("%s\n", "vkGetPipelineExecutableStatisticsKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations)
{
    //printf("%s\n", "vkGetPipelineExecutableInternalRepresentationsKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateDebugReportCallbackEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback)
{
    //printf("%s\n", "vkCreateDebugReportCallbackEXT");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyDebugReportCallbackEXT(
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyDebugReportCallbackEXT");
}

void VulkanResourceTrackingConsumer::Process_vkDebugReportMessageEXT(
    format::HandleId                            instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    StringDecoder*                              pLayerPrefix,
    StringDecoder*                              pMessage)
{
    //printf("%s\n", "vkDebugReportMessageEXT");
}

void VulkanResourceTrackingConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo)
{
    //printf("%s\n", "vkDebugMarkerSetObjectTagEXT");
}

void VulkanResourceTrackingConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    //printf("%s\n", "vkDebugMarkerSetObjectNameEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDebugMarkerBeginEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    //printf("%s\n", "vkCmdDebugMarkerBeginEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDebugMarkerEndEXT(
    format::HandleId                            commandBuffer)
{
    //printf("%s\n", "vkCmdDebugMarkerEndEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDebugMarkerInsertEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    //printf("%s\n", "vkCmdDebugMarkerInsertEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes)
{
    //printf("%s\n", "vkCmdBindTransformFeedbackBuffersEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    //printf("%s\n", "vkCmdBeginTransformFeedbackEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdEndTransformFeedbackEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    //printf("%s\n", "vkCmdEndTransformFeedbackEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBeginQueryIndexedEXT(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    //printf("%s\n", "vkCmdBeginQueryIndexedEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdEndQueryIndexedEXT(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    //printf("%s\n", "vkCmdEndQueryIndexedEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    format::HandleId                            counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    //printf("%s\n", "vkCmdDrawIndirectByteCountEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetImageViewHandleNVX(
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    //printf("%s\n", "vkGetImageViewHandleNVX");
}

void VulkanResourceTrackingConsumer::Process_vkGetImageViewAddressNVX(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties)
{
    //printf("%s\n", "vkGetImageViewAddressNVX");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDrawIndirectCountAMD(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    //printf("%s\n", "vkCmdDrawIndirectCountAMD");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    //printf("%s\n", "vkCmdDrawIndexedIndirectCountAMD");
}

void VulkanResourceTrackingConsumer::Process_vkGetShaderInfoAMD(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    PointerDecoder<size_t>*                     pInfoSize,
    PointerDecoder<uint8_t>*                    pInfo)
{
    //printf("%s\n", "vkGetShaderInfoAMD");
}

void VulkanResourceTrackingConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    //printf("%s\n", "vkCreateStreamDescriptorSurfaceGGP");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
    StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>* pExternalImageFormatProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
}

void VulkanResourceTrackingConsumer::Process_vkGetMemoryWin32HandleNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    //printf("%s\n", "vkGetMemoryWin32HandleNV");
}

void VulkanResourceTrackingConsumer::Process_vkCreateViSurfaceNN(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    //printf("%s\n", "vkCreateViSurfaceNN");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    //printf("%s\n", "vkCmdBeginConditionalRenderingEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdEndConditionalRenderingEXT(
    format::HandleId                            commandBuffer)
{
    //printf("%s\n", "vkCmdEndConditionalRenderingEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetViewportWScalingNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings)
{
    //printf("%s\n", "vkCmdSetViewportWScalingNV");
}

void VulkanResourceTrackingConsumer::Process_vkReleaseDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    //printf("%s\n", "vkReleaseDisplayEXT");
}

void VulkanResourceTrackingConsumer::Process_vkAcquireXlibDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    format::HandleId                            display)
{
    //printf("%s\n", "vkAcquireXlibDisplayEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetRandROutputDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    size_t                                      rrOutput,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    //printf("%s\n", "vkGetRandROutputDisplayEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities)
{
    //printf("%s\n", "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
}

void VulkanResourceTrackingConsumer::Process_vkDisplayPowerControlEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo)
{
    //printf("%s\n", "vkDisplayPowerControlEXT");
}

void VulkanResourceTrackingConsumer::Process_vkRegisterDeviceEventEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    //printf("%s\n", "vkRegisterDeviceEventEXT");
}

void VulkanResourceTrackingConsumer::Process_vkRegisterDisplayEventEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    //printf("%s\n", "vkRegisterDisplayEventEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetSwapchainCounterEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    PointerDecoder<uint64_t>*                   pCounterValue)
{
    //printf("%s\n", "vkGetSwapchainCounterEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties)
{
    //printf("%s\n", "vkGetRefreshCycleDurationGOOGLE");
}

void VulkanResourceTrackingConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pPresentationTimingCount,
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings)
{
    //printf("%s\n", "vkGetPastPresentationTimingGOOGLE");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetDiscardRectangleEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    //printf("%s\n", "vkCmdSetDiscardRectangleEXT");
}

void VulkanResourceTrackingConsumer::Process_vkSetHdrMetadataEXT(
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains,
    StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata)
{
    //printf("%s\n", "vkSetHdrMetadataEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCreateIOSSurfaceMVK(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    //printf("%s\n", "vkCreateIOSSurfaceMVK");
}

void VulkanResourceTrackingConsumer::Process_vkCreateMacOSSurfaceMVK(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    //printf("%s\n", "vkCreateMacOSSurfaceMVK");
}

void VulkanResourceTrackingConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    //printf("%s\n", "vkSetDebugUtilsObjectNameEXT");
}

void VulkanResourceTrackingConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    //printf("%s\n", "vkSetDebugUtilsObjectTagEXT");
}

void VulkanResourceTrackingConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    //printf("%s\n", "vkQueueBeginDebugUtilsLabelEXT");
}

void VulkanResourceTrackingConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    format::HandleId                            queue)
{
    //printf("%s\n", "vkQueueEndDebugUtilsLabelEXT");
}

void VulkanResourceTrackingConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    //printf("%s\n", "vkQueueInsertDebugUtilsLabelEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    //printf("%s\n", "vkCmdBeginDebugUtilsLabelEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    format::HandleId                            commandBuffer)
{
    //printf("%s\n", "vkCmdEndDebugUtilsLabelEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    //printf("%s\n", "vkCmdInsertDebugUtilsLabelEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger)
{
    //printf("%s\n", "vkCreateDebugUtilsMessengerEXT");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyDebugUtilsMessengerEXT");
}

void VulkanResourceTrackingConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    format::HandleId                            instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData)
{
    //printf("%s\n", "vkSubmitDebugUtilsMessageEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    //printf("%s\n", "vkGetAndroidHardwareBufferPropertiesANDROID");
}

void VulkanResourceTrackingConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    //printf("%s\n", "vkGetMemoryAndroidHardwareBufferANDROID");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetSampleLocationsEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    //printf("%s\n", "vkCmdSetSampleLocationsEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceMultisamplePropertiesEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties)
{
    //printf("%s\n", "vkGetImageDrmFormatModifierPropertiesEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCreateValidationCacheEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache)
{
    //printf("%s\n", "vkCreateValidationCacheEXT");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyValidationCacheEXT(
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyValidationCacheEXT");
}

void VulkanResourceTrackingConsumer::Process_vkMergeValidationCachesEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches)
{
    //printf("%s\n", "vkMergeValidationCachesEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetValidationCacheDataEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    //printf("%s\n", "vkGetValidationCacheDataEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBindShadingRateImageNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    //printf("%s\n", "vkCmdBindShadingRateImageNV");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes)
{
    //printf("%s\n", "vkCmdSetViewportShadingRatePaletteNV");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders)
{
    //printf("%s\n", "vkCmdSetCoarseSampleOrderNV");
}

void VulkanResourceTrackingConsumer::Process_vkCreateAccelerationStructureNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure)
{
    //printf("%s\n", "vkCreateAccelerationStructureNV");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyAccelerationStructureKHR(
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyAccelerationStructureKHR");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyAccelerationStructureNV(
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyAccelerationStructureNV");
}

void VulkanResourceTrackingConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements)
{
    //printf("%s\n", "vkGetAccelerationStructureMemoryRequirementsNV");
}

void VulkanResourceTrackingConsumer::Process_vkBindAccelerationStructureMemoryKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoKHR>* pBindInfos)
{
    //printf("%s\n", "vkBindAccelerationStructureMemoryKHR");
}

void VulkanResourceTrackingConsumer::Process_vkBindAccelerationStructureMemoryNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoKHR>* pBindInfos)
{
    //printf("%s\n", "vkBindAccelerationStructureMemoryNV");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBuildAccelerationStructureNV(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV>* pInfo,
    format::HandleId                            instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    format::HandleId                            dst,
    format::HandleId                            src,
    format::HandleId                            scratch,
    VkDeviceSize                                scratchOffset)
{
    //printf("%s\n", "vkCmdBuildAccelerationStructureNV");
}

void VulkanResourceTrackingConsumer::Process_vkCmdCopyAccelerationStructureNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    //printf("%s\n", "vkCmdCopyAccelerationStructureNV");
}

void VulkanResourceTrackingConsumer::Process_vkCmdTraceRaysNV(
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
    uint32_t                                    depth)
{
    //printf("%s\n", "vkCmdTraceRaysNV");
}

void VulkanResourceTrackingConsumer::Process_vkCreateRayTracingPipelinesNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    //printf("%s\n", "vkCreateRayTracingPipelinesNV");
}

void VulkanResourceTrackingConsumer::Process_vkGetRayTracingShaderGroupHandlesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    //printf("%s\n", "vkGetRayTracingShaderGroupHandlesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetRayTracingShaderGroupHandlesNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    //printf("%s\n", "vkGetRayTracingShaderGroupHandlesNV");
}

void VulkanResourceTrackingConsumer::Process_vkGetAccelerationStructureHandleNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    //printf("%s\n", "vkGetAccelerationStructureHandleNV");
}

void VulkanResourceTrackingConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    //printf("%s\n", "vkCmdWriteAccelerationStructuresPropertiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    //printf("%s\n", "vkCmdWriteAccelerationStructuresPropertiesNV");
}

void VulkanResourceTrackingConsumer::Process_vkCompileDeferredNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    shader)
{
    //printf("%s\n", "vkCompileDeferredNV");
}

void VulkanResourceTrackingConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties)
{
    //printf("%s\n", "vkGetMemoryHostPointerPropertiesEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdWriteBufferMarkerAMD(
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    //printf("%s\n", "vkCmdWriteBufferMarkerAMD");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainEXT>*            pTimeDomains)
{
    //printf("%s\n", "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetCalibratedTimestampsEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    //printf("%s\n", "vkGetCalibratedTimestampsEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDrawMeshTasksNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    //printf("%s\n", "vkCmdDrawMeshTasksNV");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    //printf("%s\n", "vkCmdDrawMeshTasksIndirectNV");
}

void VulkanResourceTrackingConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    //printf("%s\n", "vkCmdDrawMeshTasksIndirectCountNV");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetExclusiveScissorNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors)
{
    //printf("%s\n", "vkCmdSetExclusiveScissorNV");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetCheckpointNV(
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    //printf("%s\n", "vkCmdSetCheckpointNV");
}

void VulkanResourceTrackingConsumer::Process_vkGetQueueCheckpointDataNV(
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    //printf("%s\n", "vkGetQueueCheckpointDataNV");
}

void VulkanResourceTrackingConsumer::Process_vkInitializePerformanceApiINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    //printf("%s\n", "vkInitializePerformanceApiINTEL");
}

void VulkanResourceTrackingConsumer::Process_vkUninitializePerformanceApiINTEL(
    format::HandleId                            device)
{
    //printf("%s\n", "vkUninitializePerformanceApiINTEL");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    //printf("%s\n", "vkCmdSetPerformanceMarkerINTEL");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    //printf("%s\n", "vkCmdSetPerformanceStreamMarkerINTEL");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    //printf("%s\n", "vkCmdSetPerformanceOverrideINTEL");
}

void VulkanResourceTrackingConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
    HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration)
{
    //printf("%s\n", "vkAcquirePerformanceConfigurationINTEL");
}

void VulkanResourceTrackingConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    //printf("%s\n", "vkReleasePerformanceConfigurationINTEL");
}

void VulkanResourceTrackingConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    //printf("%s\n", "vkQueueSetPerformanceConfigurationINTEL");
}

void VulkanResourceTrackingConsumer::Process_vkGetPerformanceParameterINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkPerformanceParameterTypeINTEL             parameter,
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue)
{
    //printf("%s\n", "vkGetPerformanceParameterINTEL");
}

void VulkanResourceTrackingConsumer::Process_vkSetLocalDimmingAMD(
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    //printf("%s\n", "vkSetLocalDimmingAMD");
}

void VulkanResourceTrackingConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    //printf("%s\n", "vkCreateImagePipeSurfaceFUCHSIA");
}

void VulkanResourceTrackingConsumer::Process_vkCreateMetalSurfaceEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    //printf("%s\n", "vkCreateMetalSurfaceEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetBufferDeviceAddressEXT(
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    //printf("%s\n", "vkGetBufferDeviceAddressEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolPropertiesEXT>* pToolProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceToolPropertiesEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties)
{
    //printf("%s\n", "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pCombinationCount,
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations)
{
    //printf("%s\n", "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
}

void VulkanResourceTrackingConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    //printf("%s\n", "vkGetPhysicalDeviceSurfacePresentModes2EXT");
}

void VulkanResourceTrackingConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    //printf("%s\n", "vkAcquireFullScreenExclusiveModeEXT");
}

void VulkanResourceTrackingConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    //printf("%s\n", "vkReleaseFullScreenExclusiveModeEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    //printf("%s\n", "vkGetDeviceGroupSurfacePresentModes2EXT");
}

void VulkanResourceTrackingConsumer::Process_vkCreateHeadlessSurfaceEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    //printf("%s\n", "vkCreateHeadlessSurfaceEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCmdSetLineStippleEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    //printf("%s\n", "vkCmdSetLineStippleEXT");
}

void VulkanResourceTrackingConsumer::Process_vkResetQueryPoolEXT(
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    //printf("%s\n", "vkResetQueryPoolEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    //printf("%s\n", "vkGetGeneratedCommandsMemoryRequirementsNV");
}

void VulkanResourceTrackingConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    //printf("%s\n", "vkCmdPreprocessGeneratedCommandsNV");
}

void VulkanResourceTrackingConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    //printf("%s\n", "vkCmdExecuteGeneratedCommandsNV");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline,
    uint32_t                                    groupIndex)
{
    //printf("%s\n", "vkCmdBindPipelineShaderGroupNV");
}

void VulkanResourceTrackingConsumer::Process_vkCreateIndirectCommandsLayoutNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout)
{
    //printf("%s\n", "vkCreateIndirectCommandsLayoutNV");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyIndirectCommandsLayoutNV");
}

void VulkanResourceTrackingConsumer::Process_vkCreatePrivateDataSlotEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlotEXT>* pPrivateDataSlot)
{
    //printf("%s\n", "vkCreatePrivateDataSlotEXT");
}

void VulkanResourceTrackingConsumer::Process_vkDestroyPrivateDataSlotEXT(
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    //printf("%s\n", "vkDestroyPrivateDataSlotEXT");
}

void VulkanResourceTrackingConsumer::Process_vkSetPrivateDataEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    //printf("%s\n", "vkSetPrivateDataEXT");
}

void VulkanResourceTrackingConsumer::Process_vkGetPrivateDataEXT(
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    //printf("%s\n", "vkGetPrivateDataEXT");
}

void VulkanResourceTrackingConsumer::Process_vkCreateAccelerationStructureKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure)
{
    //printf("%s\n", "vkCreateAccelerationStructureKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetAccelerationStructureMemoryRequirementsKHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoKHR>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    //printf("%s\n", "vkGetAccelerationStructureMemoryRequirementsKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdBuildAccelerationStructureIndirectKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfo,
    format::HandleId                            indirectBuffer,
    VkDeviceSize                                indirectOffset,
    uint32_t                                    indirectStride)
{
    //printf("%s\n", "vkCmdBuildAccelerationStructureIndirectKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCopyAccelerationStructureKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    //printf("%s\n", "vkCopyAccelerationStructureKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    //printf("%s\n", "vkCopyAccelerationStructureToMemoryKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    //printf("%s\n", "vkCopyMemoryToAccelerationStructureKHR");
}

void VulkanResourceTrackingConsumer::Process_vkWriteAccelerationStructuresPropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    size_t                                      stride)
{
    //printf("%s\n", "vkWriteAccelerationStructuresPropertiesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    //printf("%s\n", "vkCmdCopyAccelerationStructureKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    //printf("%s\n", "vkCmdCopyAccelerationStructureToMemoryKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    //printf("%s\n", "vkCmdCopyMemoryToAccelerationStructureKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdTraceRaysKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    //printf("%s\n", "vkCmdTraceRaysKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCreateRayTracingPipelinesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    //printf("%s\n", "vkCreateRayTracingPipelinesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    //printf("%s\n", "vkGetAccelerationStructureDeviceAddressKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    //printf("%s\n", "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
}

void VulkanResourceTrackingConsumer::Process_vkCmdTraceRaysIndirectKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pCallableShaderBindingTable,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    //printf("%s\n", "vkCmdTraceRaysIndirectKHR");
}

void VulkanResourceTrackingConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionKHR>* version)
{
    //printf("%s\n", "vkGetDeviceAccelerationStructureCompatibilityKHR");
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
