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

#include "generated/generated_vulkan_ascii_consumer.h"

#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanAsciiConsumer::Process_vkCreateInstance(
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    fprintf(GetFile(), "%s\n", "vkCreateInstance");
}

void VulkanAsciiConsumer::Process_vkDestroyInstance(
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyInstance");
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDevices(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices)
{
    fprintf(GetFile(), "%s\n", "vkEnumeratePhysicalDevices");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceFeatures");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceFormatProperties");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceImageFormatProperties");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceProperties");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceQueueFamilyProperties");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceMemoryProperties");
}

void VulkanAsciiConsumer::Process_vkCreateDevice(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*             pDevice)
{
    fprintf(GetFile(), "%s\n", "vkCreateDevice");
}

void VulkanAsciiConsumer::Process_vkDestroyDevice(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyDevice");
}

void VulkanAsciiConsumer::Process_vkGetDeviceQueue(
    format::HandleId                            device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    fprintf(GetFile(), "%s\n", "vkGetDeviceQueue");
}

void VulkanAsciiConsumer::Process_vkQueueSubmit(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
    format::HandleId                            fence)
{
    fprintf(GetFile(), "%s\n", "vkQueueSubmit");
}

void VulkanAsciiConsumer::Process_vkQueueWaitIdle(
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    fprintf(GetFile(), "%s\n", "vkQueueWaitIdle");
}

void VulkanAsciiConsumer::Process_vkDeviceWaitIdle(
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    fprintf(GetFile(), "%s\n", "vkDeviceWaitIdle");
}

void VulkanAsciiConsumer::Process_vkAllocateMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*       pMemory)
{
    fprintf(GetFile(), "%s\n", "vkAllocateMemory");
}

void VulkanAsciiConsumer::Process_vkFreeMemory(
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkFreeMemory");
}

void VulkanAsciiConsumer::Process_vkMapMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    fprintf(GetFile(), "%s\n", "vkMapMemory");
}

void VulkanAsciiConsumer::Process_vkUnmapMemory(
    format::HandleId                            device,
    format::HandleId                            memory)
{
    fprintf(GetFile(), "%s\n", "vkUnmapMemory");
}

void VulkanAsciiConsumer::Process_vkFlushMappedMemoryRanges(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    fprintf(GetFile(), "%s\n", "vkFlushMappedMemoryRanges");
}

void VulkanAsciiConsumer::Process_vkInvalidateMappedMemoryRanges(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    fprintf(GetFile(), "%s\n", "vkInvalidateMappedMemoryRanges");
}

void VulkanAsciiConsumer::Process_vkGetDeviceMemoryCommitment(
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    fprintf(GetFile(), "%s\n", "vkGetDeviceMemoryCommitment");
}

void VulkanAsciiConsumer::Process_vkBindBufferMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            buffer,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    fprintf(GetFile(), "%s\n", "vkBindBufferMemory");
}

void VulkanAsciiConsumer::Process_vkBindImageMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    fprintf(GetFile(), "%s\n", "vkBindImageMemory");
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements(
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    fprintf(GetFile(), "%s\n", "vkGetBufferMemoryRequirements");
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements(
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    fprintf(GetFile(), "%s\n", "vkGetImageMemoryRequirements");
}

void VulkanAsciiConsumer::Process_vkGetImageSparseMemoryRequirements(
    format::HandleId                            device,
    format::HandleId                            image,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    fprintf(GetFile(), "%s\n", "vkGetImageSparseMemoryRequirements");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceSparseImageFormatProperties");
}

void VulkanAsciiConsumer::Process_vkQueueBindSparse(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
    format::HandleId                            fence)
{
    fprintf(GetFile(), "%s\n", "vkQueueBindSparse");
}

void VulkanAsciiConsumer::Process_vkCreateFence(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    fprintf(GetFile(), "%s\n", "vkCreateFence");
}

void VulkanAsciiConsumer::Process_vkDestroyFence(
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyFence");
}

void VulkanAsciiConsumer::Process_vkResetFences(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences)
{
    fprintf(GetFile(), "%s\n", "vkResetFences");
}

void VulkanAsciiConsumer::Process_vkGetFenceStatus(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    fprintf(GetFile(), "%s\n", "vkGetFenceStatus");
}

void VulkanAsciiConsumer::Process_vkWaitForFences(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    fprintf(GetFile(), "%s\n", "vkWaitForFences");
}

void VulkanAsciiConsumer::Process_vkCreateSemaphore(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSemaphore>*          pSemaphore)
{
    fprintf(GetFile(), "%s\n", "vkCreateSemaphore");
}

void VulkanAsciiConsumer::Process_vkDestroySemaphore(
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroySemaphore");
}

void VulkanAsciiConsumer::Process_vkCreateEvent(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkEvent>*              pEvent)
{
    fprintf(GetFile(), "%s\n", "vkCreateEvent");
}

void VulkanAsciiConsumer::Process_vkDestroyEvent(
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyEvent");
}

void VulkanAsciiConsumer::Process_vkGetEventStatus(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    fprintf(GetFile(), "%s\n", "vkGetEventStatus");
}

void VulkanAsciiConsumer::Process_vkSetEvent(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    fprintf(GetFile(), "%s\n", "vkSetEvent");
}

void VulkanAsciiConsumer::Process_vkResetEvent(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    fprintf(GetFile(), "%s\n", "vkResetEvent");
}

void VulkanAsciiConsumer::Process_vkCreateQueryPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkQueryPool>*          pQueryPool)
{
    fprintf(GetFile(), "%s\n", "vkCreateQueryPool");
}

void VulkanAsciiConsumer::Process_vkDestroyQueryPool(
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyQueryPool");
}

void VulkanAsciiConsumer::Process_vkGetQueryPoolResults(
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
    fprintf(GetFile(), "%s\n", "vkGetQueryPoolResults");
}

void VulkanAsciiConsumer::Process_vkCreateBuffer(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*             pBuffer)
{
    fprintf(GetFile(), "%s\n", "vkCreateBuffer");
}

void VulkanAsciiConsumer::Process_vkDestroyBuffer(
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyBuffer");
}

void VulkanAsciiConsumer::Process_vkCreateBufferView(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBufferView>*         pView)
{
    fprintf(GetFile(), "%s\n", "vkCreateBufferView");
}

void VulkanAsciiConsumer::Process_vkDestroyBufferView(
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyBufferView");
}

void VulkanAsciiConsumer::Process_vkCreateImage(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*              pImage)
{
    fprintf(GetFile(), "%s\n", "vkCreateImage");
}

void VulkanAsciiConsumer::Process_vkDestroyImage(
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyImage");
}

void VulkanAsciiConsumer::Process_vkGetImageSubresourceLayout(
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout)
{
    fprintf(GetFile(), "%s\n", "vkGetImageSubresourceLayout");
}

void VulkanAsciiConsumer::Process_vkCreateImageView(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImageView>*          pView)
{
    fprintf(GetFile(), "%s\n", "vkCreateImageView");
}

void VulkanAsciiConsumer::Process_vkDestroyImageView(
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyImageView");
}

void VulkanAsciiConsumer::Process_vkCreateShaderModule(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderModule>*       pShaderModule)
{
    fprintf(GetFile(), "%s\n", "vkCreateShaderModule");
}

void VulkanAsciiConsumer::Process_vkDestroyShaderModule(
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyShaderModule");
}

void VulkanAsciiConsumer::Process_vkCreatePipelineCache(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineCache>*      pPipelineCache)
{
    fprintf(GetFile(), "%s\n", "vkCreatePipelineCache");
}

void VulkanAsciiConsumer::Process_vkDestroyPipelineCache(
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyPipelineCache");
}

void VulkanAsciiConsumer::Process_vkGetPipelineCacheData(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    fprintf(GetFile(), "%s\n", "vkGetPipelineCacheData");
}

void VulkanAsciiConsumer::Process_vkMergePipelineCaches(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkPipelineCache>*      pSrcCaches)
{
    fprintf(GetFile(), "%s\n", "vkMergePipelineCaches");
}

void VulkanAsciiConsumer::Process_vkCreateGraphicsPipelines(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    fprintf(GetFile(), "%s\n", "vkCreateGraphicsPipelines");
}

void VulkanAsciiConsumer::Process_vkCreateComputePipelines(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    fprintf(GetFile(), "%s\n", "vkCreateComputePipelines");
}

void VulkanAsciiConsumer::Process_vkDestroyPipeline(
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyPipeline");
}

void VulkanAsciiConsumer::Process_vkCreatePipelineLayout(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout)
{
    fprintf(GetFile(), "%s\n", "vkCreatePipelineLayout");
}

void VulkanAsciiConsumer::Process_vkDestroyPipelineLayout(
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyPipelineLayout");
}

void VulkanAsciiConsumer::Process_vkCreateSampler(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSampler>*            pSampler)
{
    fprintf(GetFile(), "%s\n", "vkCreateSampler");
}

void VulkanAsciiConsumer::Process_vkDestroySampler(
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroySampler");
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorSetLayout(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout)
{
    fprintf(GetFile(), "%s\n", "vkCreateDescriptorSetLayout");
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorSetLayout(
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyDescriptorSetLayout");
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool)
{
    fprintf(GetFile(), "%s\n", "vkCreateDescriptorPool");
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorPool(
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyDescriptorPool");
}

void VulkanAsciiConsumer::Process_vkResetDescriptorPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    fprintf(GetFile(), "%s\n", "vkResetDescriptorPool");
}

void VulkanAsciiConsumer::Process_vkAllocateDescriptorSets(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    fprintf(GetFile(), "%s\n", "vkAllocateDescriptorSets");
}

void VulkanAsciiConsumer::Process_vkFreeDescriptorSets(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    fprintf(GetFile(), "%s\n", "vkFreeDescriptorSets");
}

void VulkanAsciiConsumer::Process_vkUpdateDescriptorSets(
    format::HandleId                            device,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies)
{
    fprintf(GetFile(), "%s\n", "vkUpdateDescriptorSets");
}

void VulkanAsciiConsumer::Process_vkCreateFramebuffer(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFramebuffer>*        pFramebuffer)
{
    fprintf(GetFile(), "%s\n", "vkCreateFramebuffer");
}

void VulkanAsciiConsumer::Process_vkDestroyFramebuffer(
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyFramebuffer");
}

void VulkanAsciiConsumer::Process_vkCreateRenderPass(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    fprintf(GetFile(), "%s\n", "vkCreateRenderPass");
}

void VulkanAsciiConsumer::Process_vkDestroyRenderPass(
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyRenderPass");
}

void VulkanAsciiConsumer::Process_vkGetRenderAreaGranularity(
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    fprintf(GetFile(), "%s\n", "vkGetRenderAreaGranularity");
}

void VulkanAsciiConsumer::Process_vkCreateCommandPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkCommandPool>*        pCommandPool)
{
    fprintf(GetFile(), "%s\n", "vkCreateCommandPool");
}

void VulkanAsciiConsumer::Process_vkDestroyCommandPool(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyCommandPool");
}

void VulkanAsciiConsumer::Process_vkResetCommandPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolResetFlags                     flags)
{
    fprintf(GetFile(), "%s\n", "vkResetCommandPool");
}

void VulkanAsciiConsumer::Process_vkAllocateCommandBuffers(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    fprintf(GetFile(), "%s\n", "vkAllocateCommandBuffers");
}

void VulkanAsciiConsumer::Process_vkFreeCommandBuffers(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    fprintf(GetFile(), "%s\n", "vkFreeCommandBuffers");
}

void VulkanAsciiConsumer::Process_vkBeginCommandBuffer(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    fprintf(GetFile(), "%s\n", "vkBeginCommandBuffer");
}

void VulkanAsciiConsumer::Process_vkEndCommandBuffer(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    fprintf(GetFile(), "%s\n", "vkEndCommandBuffer");
}

void VulkanAsciiConsumer::Process_vkResetCommandBuffer(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    fprintf(GetFile(), "%s\n", "vkResetCommandBuffer");
}

void VulkanAsciiConsumer::Process_vkCmdBindPipeline(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    fprintf(GetFile(), "%s\n", "vkCmdBindPipeline");
}

void VulkanAsciiConsumer::Process_vkCmdSetViewport(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetViewport");
}

void VulkanAsciiConsumer::Process_vkCmdSetScissor(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetScissor");
}

void VulkanAsciiConsumer::Process_vkCmdSetLineWidth(
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetLineWidth");
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBias(
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetDepthBias");
}

void VulkanAsciiConsumer::Process_vkCmdSetBlendConstants(
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetBlendConstants");
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBounds(
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetDepthBounds");
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilCompareMask(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetStencilCompareMask");
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilWriteMask(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetStencilWriteMask");
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilReference(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetStencilReference");
}

void VulkanAsciiConsumer::Process_vkCmdBindDescriptorSets(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    PointerDecoder<uint32_t>*                   pDynamicOffsets)
{
    fprintf(GetFile(), "%s\n", "vkCmdBindDescriptorSets");
}

void VulkanAsciiConsumer::Process_vkCmdBindIndexBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    fprintf(GetFile(), "%s\n", "vkCmdBindIndexBuffer");
}

void VulkanAsciiConsumer::Process_vkCmdBindVertexBuffers(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    fprintf(GetFile(), "%s\n", "vkCmdBindVertexBuffers");
}

void VulkanAsciiConsumer::Process_vkCmdDraw(
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    fprintf(GetFile(), "%s\n", "vkCmdDraw");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexed(
    format::HandleId                            commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    fprintf(GetFile(), "%s\n", "vkCmdDrawIndexed");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirect(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    fprintf(GetFile(), "%s\n", "vkCmdDrawIndirect");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexedIndirect(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    fprintf(GetFile(), "%s\n", "vkCmdDrawIndexedIndirect");
}

void VulkanAsciiConsumer::Process_vkCmdDispatch(
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    fprintf(GetFile(), "%s\n", "vkCmdDispatch");
}

void VulkanAsciiConsumer::Process_vkCmdDispatchIndirect(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    fprintf(GetFile(), "%s\n", "vkCmdDispatchIndirect");
}

void VulkanAsciiConsumer::Process_vkCmdCopyBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{
    fprintf(GetFile(), "%s\n", "vkCmdCopyBuffer");
}

void VulkanAsciiConsumer::Process_vkCmdCopyImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageCopy>*  pRegions)
{
    fprintf(GetFile(), "%s\n", "vkCmdCopyImage");
}

void VulkanAsciiConsumer::Process_vkCmdBlitImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageBlit>*  pRegions,
    VkFilter                                    filter)
{
    fprintf(GetFile(), "%s\n", "vkCmdBlitImage");
}

void VulkanAsciiConsumer::Process_vkCmdCopyBufferToImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    fprintf(GetFile(), "%s\n", "vkCmdCopyBufferToImage");
}

void VulkanAsciiConsumer::Process_vkCmdCopyImageToBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    fprintf(GetFile(), "%s\n", "vkCmdCopyImageToBuffer");
}

void VulkanAsciiConsumer::Process_vkCmdUpdateBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    fprintf(GetFile(), "%s\n", "vkCmdUpdateBuffer");
}

void VulkanAsciiConsumer::Process_vkCmdFillBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    fprintf(GetFile(), "%s\n", "vkCmdFillBuffer");
}

void VulkanAsciiConsumer::Process_vkCmdClearColorImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    fprintf(GetFile(), "%s\n", "vkCmdClearColorImage");
}

void VulkanAsciiConsumer::Process_vkCmdClearDepthStencilImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    fprintf(GetFile(), "%s\n", "vkCmdClearDepthStencilImage");
}

void VulkanAsciiConsumer::Process_vkCmdClearAttachments(
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
    uint32_t                                    rectCount,
    StructPointerDecoder<Decoded_VkClearRect>*  pRects)
{
    fprintf(GetFile(), "%s\n", "vkCmdClearAttachments");
}

void VulkanAsciiConsumer::Process_vkCmdResolveImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageResolve>* pRegions)
{
    fprintf(GetFile(), "%s\n", "vkCmdResolveImage");
}

void VulkanAsciiConsumer::Process_vkCmdSetEvent(
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetEvent");
}

void VulkanAsciiConsumer::Process_vkCmdResetEvent(
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    fprintf(GetFile(), "%s\n", "vkCmdResetEvent");
}

void VulkanAsciiConsumer::Process_vkCmdWaitEvents(
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
    fprintf(GetFile(), "%s\n", "vkCmdWaitEvents");
}

void VulkanAsciiConsumer::Process_vkCmdPipelineBarrier(
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
    fprintf(GetFile(), "%s\n", "vkCmdPipelineBarrier");
}

void VulkanAsciiConsumer::Process_vkCmdBeginQuery(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    fprintf(GetFile(), "%s\n", "vkCmdBeginQuery");
}

void VulkanAsciiConsumer::Process_vkCmdEndQuery(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    fprintf(GetFile(), "%s\n", "vkCmdEndQuery");
}

void VulkanAsciiConsumer::Process_vkCmdResetQueryPool(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    fprintf(GetFile(), "%s\n", "vkCmdResetQueryPool");
}

void VulkanAsciiConsumer::Process_vkCmdWriteTimestamp(
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    fprintf(GetFile(), "%s\n", "vkCmdWriteTimestamp");
}

void VulkanAsciiConsumer::Process_vkCmdCopyQueryPoolResults(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    fprintf(GetFile(), "%s\n", "vkCmdCopyQueryPoolResults");
}

void VulkanAsciiConsumer::Process_vkCmdPushConstants(
    format::HandleId                            commandBuffer,
    format::HandleId                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    PointerDecoder<uint8_t>*                    pValues)
{
    fprintf(GetFile(), "%s\n", "vkCmdPushConstants");
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderPass(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    fprintf(GetFile(), "%s\n", "vkCmdBeginRenderPass");
}

void VulkanAsciiConsumer::Process_vkCmdNextSubpass(
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    fprintf(GetFile(), "%s\n", "vkCmdNextSubpass");
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderPass(
    format::HandleId                            commandBuffer)
{
    fprintf(GetFile(), "%s\n", "vkCmdEndRenderPass");
}

void VulkanAsciiConsumer::Process_vkCmdExecuteCommands(
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    fprintf(GetFile(), "%s\n", "vkCmdExecuteCommands");
}

void VulkanAsciiConsumer::Process_vkBindBufferMemory2(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    fprintf(GetFile(), "%s\n", "vkBindBufferMemory2");
}

void VulkanAsciiConsumer::Process_vkBindImageMemory2(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    fprintf(GetFile(), "%s\n", "vkBindImageMemory2");
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    fprintf(GetFile(), "%s\n", "vkGetDeviceGroupPeerMemoryFeatures");
}

void VulkanAsciiConsumer::Process_vkCmdSetDeviceMask(
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetDeviceMask");
}

void VulkanAsciiConsumer::Process_vkCmdDispatchBase(
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    fprintf(GetFile(), "%s\n", "vkCmdDispatchBase");
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    fprintf(GetFile(), "%s\n", "vkEnumeratePhysicalDeviceGroups");
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements2(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    fprintf(GetFile(), "%s\n", "vkGetImageMemoryRequirements2");
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements2(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    fprintf(GetFile(), "%s\n", "vkGetBufferMemoryRequirements2");
}

void VulkanAsciiConsumer::Process_vkGetImageSparseMemoryRequirements2(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    fprintf(GetFile(), "%s\n", "vkGetImageSparseMemoryRequirements2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceFeatures2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceProperties2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceFormatProperties2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceImageFormatProperties2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceQueueFamilyProperties2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceMemoryProperties2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceSparseImageFormatProperties2");
}

void VulkanAsciiConsumer::Process_vkTrimCommandPool(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    fprintf(GetFile(), "%s\n", "vkTrimCommandPool");
}

void VulkanAsciiConsumer::Process_vkGetDeviceQueue2(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    fprintf(GetFile(), "%s\n", "vkGetDeviceQueue2");
}

void VulkanAsciiConsumer::Process_vkCreateSamplerYcbcrConversion(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    fprintf(GetFile(), "%s\n", "vkCreateSamplerYcbcrConversion");
}

void VulkanAsciiConsumer::Process_vkDestroySamplerYcbcrConversion(
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroySamplerYcbcrConversion");
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorUpdateTemplate(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    fprintf(GetFile(), "%s\n", "vkCreateDescriptorUpdateTemplate");
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyDescriptorUpdateTemplate");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceExternalBufferProperties");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceExternalFenceProperties");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceExternalSemaphoreProperties");
}

void VulkanAsciiConsumer::Process_vkGetDescriptorSetLayoutSupport(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    fprintf(GetFile(), "%s\n", "vkGetDescriptorSetLayoutSupport");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirectCount(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    fprintf(GetFile(), "%s\n", "vkCmdDrawIndirectCount");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexedIndirectCount(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    fprintf(GetFile(), "%s\n", "vkCmdDrawIndexedIndirectCount");
}

void VulkanAsciiConsumer::Process_vkCreateRenderPass2(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    fprintf(GetFile(), "%s\n", "vkCreateRenderPass2");
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderPass2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdBeginRenderPass2");
}

void VulkanAsciiConsumer::Process_vkCmdNextSubpass2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdNextSubpass2");
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderPass2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdEndRenderPass2");
}

void VulkanAsciiConsumer::Process_vkResetQueryPool(
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    fprintf(GetFile(), "%s\n", "vkResetQueryPool");
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreCounterValue(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    fprintf(GetFile(), "%s\n", "vkGetSemaphoreCounterValue");
}

void VulkanAsciiConsumer::Process_vkWaitSemaphores(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    fprintf(GetFile(), "%s\n", "vkWaitSemaphores");
}

void VulkanAsciiConsumer::Process_vkSignalSemaphore(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    fprintf(GetFile(), "%s\n", "vkSignalSemaphore");
}

void VulkanAsciiConsumer::Process_vkGetBufferDeviceAddress(
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkGetBufferDeviceAddress");
}

void VulkanAsciiConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkGetBufferOpaqueCaptureAddress");
}

void VulkanAsciiConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkGetDeviceMemoryOpaqueCaptureAddress");
}

void VulkanAsciiConsumer::Process_vkDestroySurfaceKHR(
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroySurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    format::HandleId                            surface,
    PointerDecoder<VkBool32>*                   pSupported)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceSurfaceSupportKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceSurfaceFormatsKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceSurfacePresentModesKHR");
}

void VulkanAsciiConsumer::Process_vkCreateSwapchainKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain)
{
    fprintf(GetFile(), "%s\n", "vkCreateSwapchainKHR");
}

void VulkanAsciiConsumer::Process_vkDestroySwapchainKHR(
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroySwapchainKHR");
}

void VulkanAsciiConsumer::Process_vkGetSwapchainImagesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pSwapchainImageCount,
    HandlePointerDecoder<VkImage>*              pSwapchainImages)
{
    fprintf(GetFile(), "%s\n", "vkGetSwapchainImagesKHR");
}

void VulkanAsciiConsumer::Process_vkAcquireNextImageKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    timeout,
    format::HandleId                            semaphore,
    format::HandleId                            fence,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    fprintf(GetFile(), "%s\n", "vkAcquireNextImageKHR");
}

void VulkanAsciiConsumer::Process_vkQueuePresentKHR(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    fprintf(GetFile(), "%s\n", "vkQueuePresentKHR");
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    fprintf(GetFile(), "%s\n", "vkGetDeviceGroupPresentCapabilitiesKHR");
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            surface,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    fprintf(GetFile(), "%s\n", "vkGetDeviceGroupSurfacePresentModesKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pRectCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pRects)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDevicePresentRectanglesKHR");
}

void VulkanAsciiConsumer::Process_vkAcquireNextImage2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    fprintf(GetFile(), "%s\n", "vkAcquireNextImage2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceDisplayPropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    planeIndex,
    PointerDecoder<uint32_t>*                   pDisplayCount,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplays)
{
    fprintf(GetFile(), "%s\n", "vkGetDisplayPlaneSupportedDisplaysKHR");
}

void VulkanAsciiConsumer::Process_vkGetDisplayModePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetDisplayModePropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkCreateDisplayModeKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDisplayModeKHR>*     pMode)
{
    fprintf(GetFile(), "%s\n", "vkCreateDisplayModeKHR");
}

void VulkanAsciiConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            mode,
    uint32_t                                    planeIndex,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities)
{
    fprintf(GetFile(), "%s\n", "vkGetDisplayPlaneCapabilitiesKHR");
}

void VulkanAsciiConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateDisplayPlaneSurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkCreateSharedSwapchainsKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains)
{
    fprintf(GetFile(), "%s\n", "vkCreateSharedSwapchainsKHR");
}

void VulkanAsciiConsumer::Process_vkCreateXlibSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateXlibSurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dpy,
    size_t                                      visualID)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceXlibPresentationSupportKHR");
}

void VulkanAsciiConsumer::Process_vkCreateXcbSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateXcbSurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    connection,
    uint32_t                                    visual_id)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceXcbPresentationSupportKHR");
}

void VulkanAsciiConsumer::Process_vkCreateWaylandSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateWaylandSurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    display)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
}

void VulkanAsciiConsumer::Process_vkCreateAndroidSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateAndroidSurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkCreateWin32SurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateWin32SurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceWin32PresentationSupportKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceFeatures2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceFormatProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceImageFormatProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceMemoryProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    fprintf(GetFile(), "%s\n", "vkGetDeviceGroupPeerMemoryFeaturesKHR");
}

void VulkanAsciiConsumer::Process_vkCmdSetDeviceMaskKHR(
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetDeviceMaskKHR");
}

void VulkanAsciiConsumer::Process_vkCmdDispatchBaseKHR(
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    fprintf(GetFile(), "%s\n", "vkCmdDispatchBaseKHR");
}

void VulkanAsciiConsumer::Process_vkTrimCommandPoolKHR(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    fprintf(GetFile(), "%s\n", "vkTrimCommandPoolKHR");
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    fprintf(GetFile(), "%s\n", "vkEnumeratePhysicalDeviceGroupsKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkGetMemoryWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    fprintf(GetFile(), "%s\n", "vkGetMemoryWin32HandleKHR");
}

void VulkanAsciiConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    handle,
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetMemoryWin32HandlePropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkGetMemoryFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    fprintf(GetFile(), "%s\n", "vkGetMemoryFdKHR");
}

void VulkanAsciiConsumer::Process_vkGetMemoryFdPropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetMemoryFdPropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    fprintf(GetFile(), "%s\n", "vkImportSemaphoreWin32HandleKHR");
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    fprintf(GetFile(), "%s\n", "vkGetSemaphoreWin32HandleKHR");
}

void VulkanAsciiConsumer::Process_vkImportSemaphoreFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    fprintf(GetFile(), "%s\n", "vkImportSemaphoreFdKHR");
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    fprintf(GetFile(), "%s\n", "vkGetSemaphoreFdKHR");
}

void VulkanAsciiConsumer::Process_vkCmdPushDescriptorSetKHR(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    fprintf(GetFile(), "%s\n", "vkCmdPushDescriptorSetKHR");
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    fprintf(GetFile(), "%s\n", "vkCreateDescriptorUpdateTemplateKHR");
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyDescriptorUpdateTemplateKHR");
}

void VulkanAsciiConsumer::Process_vkCreateRenderPass2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    fprintf(GetFile(), "%s\n", "vkCreateRenderPass2KHR");
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderPass2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdBeginRenderPass2KHR");
}

void VulkanAsciiConsumer::Process_vkCmdNextSubpass2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdNextSubpass2KHR");
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderPass2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdEndRenderPass2KHR");
}

void VulkanAsciiConsumer::Process_vkGetSwapchainStatusKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    fprintf(GetFile(), "%s\n", "vkGetSwapchainStatusKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceExternalFencePropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkImportFenceWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    fprintf(GetFile(), "%s\n", "vkImportFenceWin32HandleKHR");
}

void VulkanAsciiConsumer::Process_vkGetFenceWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    fprintf(GetFile(), "%s\n", "vkGetFenceWin32HandleKHR");
}

void VulkanAsciiConsumer::Process_vkImportFenceFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    fprintf(GetFile(), "%s\n", "vkImportFenceFdKHR");
}

void VulkanAsciiConsumer::Process_vkGetFenceFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    fprintf(GetFile(), "%s\n", "vkGetFenceFdKHR");
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    PointerDecoder<uint32_t>*                   pCounterCount,
    StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters,
    StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions)
{
    fprintf(GetFile(), "%s\n", "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
}

void VulkanAsciiConsumer::Process_vkAcquireProfilingLockKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkAcquireProfilingLockKHR");
}

void VulkanAsciiConsumer::Process_vkReleaseProfilingLockKHR(
    format::HandleId                            device)
{
    fprintf(GetFile(), "%s\n", "vkReleaseProfilingLockKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceSurfaceFormats2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceDisplayProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetDisplayModeProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetDisplayModeProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities)
{
    fprintf(GetFile(), "%s\n", "vkGetDisplayPlaneCapabilities2KHR");
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements2KHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    fprintf(GetFile(), "%s\n", "vkGetImageMemoryRequirements2KHR");
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    fprintf(GetFile(), "%s\n", "vkGetBufferMemoryRequirements2KHR");
}

void VulkanAsciiConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    fprintf(GetFile(), "%s\n", "vkGetImageSparseMemoryRequirements2KHR");
}

void VulkanAsciiConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    fprintf(GetFile(), "%s\n", "vkCreateSamplerYcbcrConversionKHR");
}

void VulkanAsciiConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroySamplerYcbcrConversionKHR");
}

void VulkanAsciiConsumer::Process_vkBindBufferMemory2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    fprintf(GetFile(), "%s\n", "vkBindBufferMemory2KHR");
}

void VulkanAsciiConsumer::Process_vkBindImageMemory2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    fprintf(GetFile(), "%s\n", "vkBindImageMemory2KHR");
}

void VulkanAsciiConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    fprintf(GetFile(), "%s\n", "vkGetDescriptorSetLayoutSupportKHR");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirectCountKHR(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    fprintf(GetFile(), "%s\n", "vkCmdDrawIndirectCountKHR");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    fprintf(GetFile(), "%s\n", "vkCmdDrawIndexedIndirectCountKHR");
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreCounterValueKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    fprintf(GetFile(), "%s\n", "vkGetSemaphoreCounterValueKHR");
}

void VulkanAsciiConsumer::Process_vkWaitSemaphoresKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    fprintf(GetFile(), "%s\n", "vkWaitSemaphoresKHR");
}

void VulkanAsciiConsumer::Process_vkSignalSemaphoreKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    fprintf(GetFile(), "%s\n", "vkSignalSemaphoreKHR");
}

void VulkanAsciiConsumer::Process_vkGetBufferDeviceAddressKHR(
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkGetBufferDeviceAddressKHR");
}

void VulkanAsciiConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkGetBufferOpaqueCaptureAddressKHR");
}

void VulkanAsciiConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
}

void VulkanAsciiConsumer::Process_vkCreateDeferredOperationKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation)
{
    fprintf(GetFile(), "%s\n", "vkCreateDeferredOperationKHR");
}

void VulkanAsciiConsumer::Process_vkDestroyDeferredOperationKHR(
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyDeferredOperationKHR");
}

void VulkanAsciiConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    fprintf(GetFile(), "%s\n", "vkGetDeferredOperationMaxConcurrencyKHR");
}

void VulkanAsciiConsumer::Process_vkGetDeferredOperationResultKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    fprintf(GetFile(), "%s\n", "vkGetDeferredOperationResultKHR");
}

void VulkanAsciiConsumer::Process_vkDeferredOperationJoinKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    fprintf(GetFile(), "%s\n", "vkDeferredOperationJoinKHR");
}

void VulkanAsciiConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo,
    PointerDecoder<uint32_t>*                   pExecutableCount,
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPipelineExecutablePropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pStatisticCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics)
{
    fprintf(GetFile(), "%s\n", "vkGetPipelineExecutableStatisticsKHR");
}

void VulkanAsciiConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations)
{
    fprintf(GetFile(), "%s\n", "vkGetPipelineExecutableInternalRepresentationsKHR");
}

void VulkanAsciiConsumer::Process_vkCreateDebugReportCallbackEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback)
{
    fprintf(GetFile(), "%s\n", "vkCreateDebugReportCallbackEXT");
}

void VulkanAsciiConsumer::Process_vkDestroyDebugReportCallbackEXT(
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyDebugReportCallbackEXT");
}

void VulkanAsciiConsumer::Process_vkDebugReportMessageEXT(
    format::HandleId                            instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    StringDecoder*                              pLayerPrefix,
    StringDecoder*                              pMessage)
{
    fprintf(GetFile(), "%s\n", "vkDebugReportMessageEXT");
}

void VulkanAsciiConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo)
{
    fprintf(GetFile(), "%s\n", "vkDebugMarkerSetObjectTagEXT");
}

void VulkanAsciiConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    fprintf(GetFile(), "%s\n", "vkDebugMarkerSetObjectNameEXT");
}

void VulkanAsciiConsumer::Process_vkCmdDebugMarkerBeginEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdDebugMarkerBeginEXT");
}

void VulkanAsciiConsumer::Process_vkCmdDebugMarkerEndEXT(
    format::HandleId                            commandBuffer)
{
    fprintf(GetFile(), "%s\n", "vkCmdDebugMarkerEndEXT");
}

void VulkanAsciiConsumer::Process_vkCmdDebugMarkerInsertEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdDebugMarkerInsertEXT");
}

void VulkanAsciiConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes)
{
    fprintf(GetFile(), "%s\n", "vkCmdBindTransformFeedbackBuffersEXT");
}

void VulkanAsciiConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    fprintf(GetFile(), "%s\n", "vkCmdBeginTransformFeedbackEXT");
}

void VulkanAsciiConsumer::Process_vkCmdEndTransformFeedbackEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    fprintf(GetFile(), "%s\n", "vkCmdEndTransformFeedbackEXT");
}

void VulkanAsciiConsumer::Process_vkCmdBeginQueryIndexedEXT(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    fprintf(GetFile(), "%s\n", "vkCmdBeginQueryIndexedEXT");
}

void VulkanAsciiConsumer::Process_vkCmdEndQueryIndexedEXT(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    fprintf(GetFile(), "%s\n", "vkCmdEndQueryIndexedEXT");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    format::HandleId                            counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    fprintf(GetFile(), "%s\n", "vkCmdDrawIndirectByteCountEXT");
}

void VulkanAsciiConsumer::Process_vkGetImageViewHandleNVX(
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkGetImageViewHandleNVX");
}

void VulkanAsciiConsumer::Process_vkGetImageViewAddressNVX(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetImageViewAddressNVX");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirectCountAMD(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    fprintf(GetFile(), "%s\n", "vkCmdDrawIndirectCountAMD");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    fprintf(GetFile(), "%s\n", "vkCmdDrawIndexedIndirectCountAMD");
}

void VulkanAsciiConsumer::Process_vkGetShaderInfoAMD(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    PointerDecoder<size_t>*                     pInfoSize,
    PointerDecoder<uint8_t>*                    pInfo)
{
    fprintf(GetFile(), "%s\n", "vkGetShaderInfoAMD");
}

void VulkanAsciiConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateStreamDescriptorSurfaceGGP");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
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
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
}

void VulkanAsciiConsumer::Process_vkGetMemoryWin32HandleNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    fprintf(GetFile(), "%s\n", "vkGetMemoryWin32HandleNV");
}

void VulkanAsciiConsumer::Process_vkCreateViSurfaceNN(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateViSurfaceNN");
}

void VulkanAsciiConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    fprintf(GetFile(), "%s\n", "vkCmdBeginConditionalRenderingEXT");
}

void VulkanAsciiConsumer::Process_vkCmdEndConditionalRenderingEXT(
    format::HandleId                            commandBuffer)
{
    fprintf(GetFile(), "%s\n", "vkCmdEndConditionalRenderingEXT");
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportWScalingNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetViewportWScalingNV");
}

void VulkanAsciiConsumer::Process_vkReleaseDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    fprintf(GetFile(), "%s\n", "vkReleaseDisplayEXT");
}

void VulkanAsciiConsumer::Process_vkAcquireXlibDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    format::HandleId                            display)
{
    fprintf(GetFile(), "%s\n", "vkAcquireXlibDisplayEXT");
}

void VulkanAsciiConsumer::Process_vkGetRandROutputDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    size_t                                      rrOutput,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    fprintf(GetFile(), "%s\n", "vkGetRandROutputDisplayEXT");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
}

void VulkanAsciiConsumer::Process_vkDisplayPowerControlEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo)
{
    fprintf(GetFile(), "%s\n", "vkDisplayPowerControlEXT");
}

void VulkanAsciiConsumer::Process_vkRegisterDeviceEventEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    fprintf(GetFile(), "%s\n", "vkRegisterDeviceEventEXT");
}

void VulkanAsciiConsumer::Process_vkRegisterDisplayEventEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    fprintf(GetFile(), "%s\n", "vkRegisterDisplayEventEXT");
}

void VulkanAsciiConsumer::Process_vkGetSwapchainCounterEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    PointerDecoder<uint64_t>*                   pCounterValue)
{
    fprintf(GetFile(), "%s\n", "vkGetSwapchainCounterEXT");
}

void VulkanAsciiConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetRefreshCycleDurationGOOGLE");
}

void VulkanAsciiConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pPresentationTimingCount,
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings)
{
    fprintf(GetFile(), "%s\n", "vkGetPastPresentationTimingGOOGLE");
}

void VulkanAsciiConsumer::Process_vkCmdSetDiscardRectangleEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetDiscardRectangleEXT");
}

void VulkanAsciiConsumer::Process_vkSetHdrMetadataEXT(
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains,
    StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata)
{
    fprintf(GetFile(), "%s\n", "vkSetHdrMetadataEXT");
}

void VulkanAsciiConsumer::Process_vkCreateIOSSurfaceMVK(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateIOSSurfaceMVK");
}

void VulkanAsciiConsumer::Process_vkCreateMacOSSurfaceMVK(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateMacOSSurfaceMVK");
}

void VulkanAsciiConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    fprintf(GetFile(), "%s\n", "vkSetDebugUtilsObjectNameEXT");
}

void VulkanAsciiConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    fprintf(GetFile(), "%s\n", "vkSetDebugUtilsObjectTagEXT");
}

void VulkanAsciiConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    fprintf(GetFile(), "%s\n", "vkQueueBeginDebugUtilsLabelEXT");
}

void VulkanAsciiConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    format::HandleId                            queue)
{
    fprintf(GetFile(), "%s\n", "vkQueueEndDebugUtilsLabelEXT");
}

void VulkanAsciiConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    fprintf(GetFile(), "%s\n", "vkQueueInsertDebugUtilsLabelEXT");
}

void VulkanAsciiConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdBeginDebugUtilsLabelEXT");
}

void VulkanAsciiConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    format::HandleId                            commandBuffer)
{
    fprintf(GetFile(), "%s\n", "vkCmdEndDebugUtilsLabelEXT");
}

void VulkanAsciiConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdInsertDebugUtilsLabelEXT");
}

void VulkanAsciiConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger)
{
    fprintf(GetFile(), "%s\n", "vkCreateDebugUtilsMessengerEXT");
}

void VulkanAsciiConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyDebugUtilsMessengerEXT");
}

void VulkanAsciiConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    format::HandleId                            instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData)
{
    fprintf(GetFile(), "%s\n", "vkSubmitDebugUtilsMessageEXT");
}

void VulkanAsciiConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetAndroidHardwareBufferPropertiesANDROID");
}

void VulkanAsciiConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    fprintf(GetFile(), "%s\n", "vkGetMemoryAndroidHardwareBufferANDROID");
}

void VulkanAsciiConsumer::Process_vkCmdSetSampleLocationsEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetSampleLocationsEXT");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceMultisamplePropertiesEXT");
}

void VulkanAsciiConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetImageDrmFormatModifierPropertiesEXT");
}

void VulkanAsciiConsumer::Process_vkCreateValidationCacheEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache)
{
    fprintf(GetFile(), "%s\n", "vkCreateValidationCacheEXT");
}

void VulkanAsciiConsumer::Process_vkDestroyValidationCacheEXT(
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyValidationCacheEXT");
}

void VulkanAsciiConsumer::Process_vkMergeValidationCachesEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches)
{
    fprintf(GetFile(), "%s\n", "vkMergeValidationCachesEXT");
}

void VulkanAsciiConsumer::Process_vkGetValidationCacheDataEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    fprintf(GetFile(), "%s\n", "vkGetValidationCacheDataEXT");
}

void VulkanAsciiConsumer::Process_vkCmdBindShadingRateImageNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    fprintf(GetFile(), "%s\n", "vkCmdBindShadingRateImageNV");
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetViewportShadingRatePaletteNV");
}

void VulkanAsciiConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetCoarseSampleOrderNV");
}

void VulkanAsciiConsumer::Process_vkCreateAccelerationStructureNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure)
{
    fprintf(GetFile(), "%s\n", "vkCreateAccelerationStructureNV");
}

void VulkanAsciiConsumer::Process_vkDestroyAccelerationStructureKHR(
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyAccelerationStructureKHR");
}

void VulkanAsciiConsumer::Process_vkDestroyAccelerationStructureNV(
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyAccelerationStructureNV");
}

void VulkanAsciiConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements)
{
    fprintf(GetFile(), "%s\n", "vkGetAccelerationStructureMemoryRequirementsNV");
}

void VulkanAsciiConsumer::Process_vkBindAccelerationStructureMemoryKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoKHR>* pBindInfos)
{
    fprintf(GetFile(), "%s\n", "vkBindAccelerationStructureMemoryKHR");
}

void VulkanAsciiConsumer::Process_vkBindAccelerationStructureMemoryNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoKHR>* pBindInfos)
{
    fprintf(GetFile(), "%s\n", "vkBindAccelerationStructureMemoryNV");
}

void VulkanAsciiConsumer::Process_vkCmdBuildAccelerationStructureNV(
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
    fprintf(GetFile(), "%s\n", "vkCmdBuildAccelerationStructureNV");
}

void VulkanAsciiConsumer::Process_vkCmdCopyAccelerationStructureNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    fprintf(GetFile(), "%s\n", "vkCmdCopyAccelerationStructureNV");
}

void VulkanAsciiConsumer::Process_vkCmdTraceRaysNV(
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
    fprintf(GetFile(), "%s\n", "vkCmdTraceRaysNV");
}

void VulkanAsciiConsumer::Process_vkCreateRayTracingPipelinesNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    fprintf(GetFile(), "%s\n", "vkCreateRayTracingPipelinesNV");
}

void VulkanAsciiConsumer::Process_vkGetRayTracingShaderGroupHandlesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    fprintf(GetFile(), "%s\n", "vkGetRayTracingShaderGroupHandlesKHR");
}

void VulkanAsciiConsumer::Process_vkGetRayTracingShaderGroupHandlesNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    fprintf(GetFile(), "%s\n", "vkGetRayTracingShaderGroupHandlesNV");
}

void VulkanAsciiConsumer::Process_vkGetAccelerationStructureHandleNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    fprintf(GetFile(), "%s\n", "vkGetAccelerationStructureHandleNV");
}

void VulkanAsciiConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    fprintf(GetFile(), "%s\n", "vkCmdWriteAccelerationStructuresPropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    fprintf(GetFile(), "%s\n", "vkCmdWriteAccelerationStructuresPropertiesNV");
}

void VulkanAsciiConsumer::Process_vkCompileDeferredNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    shader)
{
    fprintf(GetFile(), "%s\n", "vkCompileDeferredNV");
}

void VulkanAsciiConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetMemoryHostPointerPropertiesEXT");
}

void VulkanAsciiConsumer::Process_vkCmdWriteBufferMarkerAMD(
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    fprintf(GetFile(), "%s\n", "vkCmdWriteBufferMarkerAMD");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainEXT>*            pTimeDomains)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
}

void VulkanAsciiConsumer::Process_vkGetCalibratedTimestampsEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    fprintf(GetFile(), "%s\n", "vkGetCalibratedTimestampsEXT");
}

void VulkanAsciiConsumer::Process_vkCmdDrawMeshTasksNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    fprintf(GetFile(), "%s\n", "vkCmdDrawMeshTasksNV");
}

void VulkanAsciiConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    fprintf(GetFile(), "%s\n", "vkCmdDrawMeshTasksIndirectNV");
}

void VulkanAsciiConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    fprintf(GetFile(), "%s\n", "vkCmdDrawMeshTasksIndirectCountNV");
}

void VulkanAsciiConsumer::Process_vkCmdSetExclusiveScissorNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetExclusiveScissorNV");
}

void VulkanAsciiConsumer::Process_vkCmdSetCheckpointNV(
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetCheckpointNV");
}

void VulkanAsciiConsumer::Process_vkGetQueueCheckpointDataNV(
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    fprintf(GetFile(), "%s\n", "vkGetQueueCheckpointDataNV");
}

void VulkanAsciiConsumer::Process_vkInitializePerformanceApiINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    fprintf(GetFile(), "%s\n", "vkInitializePerformanceApiINTEL");
}

void VulkanAsciiConsumer::Process_vkUninitializePerformanceApiINTEL(
    format::HandleId                            device)
{
    fprintf(GetFile(), "%s\n", "vkUninitializePerformanceApiINTEL");
}

void VulkanAsciiConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetPerformanceMarkerINTEL");
}

void VulkanAsciiConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetPerformanceStreamMarkerINTEL");
}

void VulkanAsciiConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetPerformanceOverrideINTEL");
}

void VulkanAsciiConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
    HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration)
{
    fprintf(GetFile(), "%s\n", "vkAcquirePerformanceConfigurationINTEL");
}

void VulkanAsciiConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    fprintf(GetFile(), "%s\n", "vkReleasePerformanceConfigurationINTEL");
}

void VulkanAsciiConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    fprintf(GetFile(), "%s\n", "vkQueueSetPerformanceConfigurationINTEL");
}

void VulkanAsciiConsumer::Process_vkGetPerformanceParameterINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkPerformanceParameterTypeINTEL             parameter,
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue)
{
    fprintf(GetFile(), "%s\n", "vkGetPerformanceParameterINTEL");
}

void VulkanAsciiConsumer::Process_vkSetLocalDimmingAMD(
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    fprintf(GetFile(), "%s\n", "vkSetLocalDimmingAMD");
}

void VulkanAsciiConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateImagePipeSurfaceFUCHSIA");
}

void VulkanAsciiConsumer::Process_vkCreateMetalSurfaceEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateMetalSurfaceEXT");
}

void VulkanAsciiConsumer::Process_vkGetBufferDeviceAddressEXT(
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkGetBufferDeviceAddressEXT");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolPropertiesEXT>* pToolProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceToolPropertiesEXT");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pCombinationCount,
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceSurfacePresentModes2EXT");
}

void VulkanAsciiConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    fprintf(GetFile(), "%s\n", "vkAcquireFullScreenExclusiveModeEXT");
}

void VulkanAsciiConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    fprintf(GetFile(), "%s\n", "vkReleaseFullScreenExclusiveModeEXT");
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    fprintf(GetFile(), "%s\n", "vkGetDeviceGroupSurfacePresentModes2EXT");
}

void VulkanAsciiConsumer::Process_vkCreateHeadlessSurfaceEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateHeadlessSurfaceEXT");
}

void VulkanAsciiConsumer::Process_vkCmdSetLineStippleEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetLineStippleEXT");
}

void VulkanAsciiConsumer::Process_vkResetQueryPoolEXT(
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    fprintf(GetFile(), "%s\n", "vkResetQueryPoolEXT");
}

void VulkanAsciiConsumer::Process_vkCmdSetCullModeEXT(
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetCullModeEXT");
}

void VulkanAsciiConsumer::Process_vkCmdSetFrontFaceEXT(
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetFrontFaceEXT");
}

void VulkanAsciiConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetPrimitiveTopologyEXT");
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportWithCountEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetViewportWithCountEXT");
}

void VulkanAsciiConsumer::Process_vkCmdSetScissorWithCountEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetScissorWithCountEXT");
}

void VulkanAsciiConsumer::Process_vkCmdBindVertexBuffers2EXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    fprintf(GetFile(), "%s\n", "vkCmdBindVertexBuffers2EXT");
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthTestEnableEXT(
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetDepthTestEnableEXT");
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetDepthWriteEnableEXT");
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthCompareOpEXT(
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetDepthCompareOpEXT");
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetDepthBoundsTestEnableEXT");
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilTestEnableEXT(
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetStencilTestEnableEXT");
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilOpEXT(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    fprintf(GetFile(), "%s\n", "vkCmdSetStencilOpEXT");
}

void VulkanAsciiConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    fprintf(GetFile(), "%s\n", "vkGetGeneratedCommandsMemoryRequirementsNV");
}

void VulkanAsciiConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdPreprocessGeneratedCommandsNV");
}

void VulkanAsciiConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdExecuteGeneratedCommandsNV");
}

void VulkanAsciiConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline,
    uint32_t                                    groupIndex)
{
    fprintf(GetFile(), "%s\n", "vkCmdBindPipelineShaderGroupNV");
}

void VulkanAsciiConsumer::Process_vkCreateIndirectCommandsLayoutNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout)
{
    fprintf(GetFile(), "%s\n", "vkCreateIndirectCommandsLayoutNV");
}

void VulkanAsciiConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyIndirectCommandsLayoutNV");
}

void VulkanAsciiConsumer::Process_vkCreatePrivateDataSlotEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlotEXT>* pPrivateDataSlot)
{
    fprintf(GetFile(), "%s\n", "vkCreatePrivateDataSlotEXT");
}

void VulkanAsciiConsumer::Process_vkDestroyPrivateDataSlotEXT(
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    fprintf(GetFile(), "%s\n", "vkDestroyPrivateDataSlotEXT");
}

void VulkanAsciiConsumer::Process_vkSetPrivateDataEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    fprintf(GetFile(), "%s\n", "vkSetPrivateDataEXT");
}

void VulkanAsciiConsumer::Process_vkGetPrivateDataEXT(
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    fprintf(GetFile(), "%s\n", "vkGetPrivateDataEXT");
}

void VulkanAsciiConsumer::Process_vkCreateDirectFBSurfaceEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    fprintf(GetFile(), "%s\n", "vkCreateDirectFBSurfaceEXT");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dfb)
{
    fprintf(GetFile(), "%s\n", "vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
}

void VulkanAsciiConsumer::Process_vkCreateAccelerationStructureKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure)
{
    fprintf(GetFile(), "%s\n", "vkCreateAccelerationStructureKHR");
}

void VulkanAsciiConsumer::Process_vkGetAccelerationStructureMemoryRequirementsKHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoKHR>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    fprintf(GetFile(), "%s\n", "vkGetAccelerationStructureMemoryRequirementsKHR");
}

void VulkanAsciiConsumer::Process_vkCmdBuildAccelerationStructureIndirectKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfo,
    format::HandleId                            indirectBuffer,
    VkDeviceSize                                indirectOffset,
    uint32_t                                    indirectStride)
{
    fprintf(GetFile(), "%s\n", "vkCmdBuildAccelerationStructureIndirectKHR");
}

void VulkanAsciiConsumer::Process_vkCopyAccelerationStructureKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkCopyAccelerationStructureKHR");
}

void VulkanAsciiConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkCopyAccelerationStructureToMemoryKHR");
}

void VulkanAsciiConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkCopyMemoryToAccelerationStructureKHR");
}

void VulkanAsciiConsumer::Process_vkWriteAccelerationStructuresPropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    size_t                                      stride)
{
    fprintf(GetFile(), "%s\n", "vkWriteAccelerationStructuresPropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdCopyAccelerationStructureKHR");
}

void VulkanAsciiConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdCopyAccelerationStructureToMemoryKHR");
}

void VulkanAsciiConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkCmdCopyMemoryToAccelerationStructureKHR");
}

void VulkanAsciiConsumer::Process_vkCmdTraceRaysKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    fprintf(GetFile(), "%s\n", "vkCmdTraceRaysKHR");
}

void VulkanAsciiConsumer::Process_vkCreateRayTracingPipelinesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    fprintf(GetFile(), "%s\n", "vkCreateRayTracingPipelinesKHR");
}

void VulkanAsciiConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    fprintf(GetFile(), "%s\n", "vkGetAccelerationStructureDeviceAddressKHR");
}

void VulkanAsciiConsumer::Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    fprintf(GetFile(), "%s\n", "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
}

void VulkanAsciiConsumer::Process_vkCmdTraceRaysIndirectKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pCallableShaderBindingTable,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    fprintf(GetFile(), "%s\n", "vkCmdTraceRaysIndirectKHR");
}

void VulkanAsciiConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionKHR>* version)
{
    fprintf(GetFile(), "%s\n", "vkGetDeviceAccelerationStructureCompatibilityKHR");
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
