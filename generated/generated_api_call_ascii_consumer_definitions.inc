/*
** Copyright (c) 2018 LunarG, Inc.
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


void VulkanAsciiConsumer::Process_vkCreateInstance(
    VkResult                                    returnValue,
    const StructPointerDecoder<Decoded_VkInstanceCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkInstance>&           pInstance)
{
    fprintf(m_file, "%s\n", "vkCreateInstance");
}

void VulkanAsciiConsumer::Process_vkDestroyInstance(
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyInstance");
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDevices(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const PointerDecoder<uint32_t>&             pPhysicalDeviceCount,
    const PointerDecoder<VkPhysicalDevice>&     pPhysicalDevices)
{
    fprintf(m_file, "%s\n", "vkEnumeratePhysicalDevices");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>& pFeatures)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceFeatures");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    const StructPointerDecoder<Decoded_VkFormatProperties>& pFormatProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceFormatProperties");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    const StructPointerDecoder<Decoded_VkImageFormatProperties>& pImageFormatProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceImageFormatProperties");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>& pProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceProperties");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
    const StructPointerDecoder<Decoded_VkQueueFamilyProperties>& pQueueFamilyProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceQueueFamilyProperties");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>& pMemoryProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceMemoryProperties");
}

void VulkanAsciiConsumer::Process_vkCreateDevice(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkDeviceCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDevice>&             pDevice)
{
    fprintf(m_file, "%s\n", "vkCreateDevice");
}

void VulkanAsciiConsumer::Process_vkDestroyDevice(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyDevice");
}

void VulkanAsciiConsumer::Process_vkGetDeviceQueue(
    VkDevice                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    const PointerDecoder<VkQueue>&              pQueue)
{
    fprintf(m_file, "%s\n", "vkGetDeviceQueue");
}

void VulkanAsciiConsumer::Process_vkQueueSubmit(
    VkResult                                    returnValue,
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const StructPointerDecoder<Decoded_VkSubmitInfo>& pSubmits,
    VkFence                                     fence)
{
    fprintf(m_file, "%s\n", "vkQueueSubmit");
}

void VulkanAsciiConsumer::Process_vkQueueWaitIdle(
    VkResult                                    returnValue,
    VkQueue                                     queue)
{
    fprintf(m_file, "%s\n", "vkQueueWaitIdle");
}

void VulkanAsciiConsumer::Process_vkDeviceWaitIdle(
    VkResult                                    returnValue,
    VkDevice                                    device)
{
    fprintf(m_file, "%s\n", "vkDeviceWaitIdle");
}

void VulkanAsciiConsumer::Process_vkAllocateMemory(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDeviceMemory>&       pMemory)
{
    fprintf(m_file, "%s\n", "vkAllocateMemory");
}

void VulkanAsciiConsumer::Process_vkFreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkFreeMemory");
}

void VulkanAsciiConsumer::Process_vkMapMemory(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    const PointerDecoder<uint64_t>&             ppData)
{
    fprintf(m_file, "%s\n", "vkMapMemory");
}

void VulkanAsciiConsumer::Process_vkUnmapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory)
{
    fprintf(m_file, "%s\n", "vkUnmapMemory");
}

void VulkanAsciiConsumer::Process_vkFlushMappedMemoryRanges(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges)
{
    fprintf(m_file, "%s\n", "vkFlushMappedMemoryRanges");
}

void VulkanAsciiConsumer::Process_vkInvalidateMappedMemoryRanges(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges)
{
    fprintf(m_file, "%s\n", "vkInvalidateMappedMemoryRanges");
}

void VulkanAsciiConsumer::Process_vkGetDeviceMemoryCommitment(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const PointerDecoder<VkDeviceSize>&         pCommittedMemoryInBytes)
{
    fprintf(m_file, "%s\n", "vkGetDeviceMemoryCommitment");
}

void VulkanAsciiConsumer::Process_vkBindBufferMemory(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    fprintf(m_file, "%s\n", "vkBindBufferMemory");
}

void VulkanAsciiConsumer::Process_vkBindImageMemory(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    fprintf(m_file, "%s\n", "vkBindImageMemory");
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const StructPointerDecoder<Decoded_VkMemoryRequirements>& pMemoryRequirements)
{
    fprintf(m_file, "%s\n", "vkGetBufferMemoryRequirements");
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    const StructPointerDecoder<Decoded_VkMemoryRequirements>& pMemoryRequirements)
{
    fprintf(m_file, "%s\n", "vkGetImageMemoryRequirements");
}

void VulkanAsciiConsumer::Process_vkGetImageSparseMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
    const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>& pSparseMemoryRequirements)
{
    fprintf(m_file, "%s\n", "vkGetImageSparseMemoryRequirements");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkSparseImageFormatProperties>& pProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceSparseImageFormatProperties");
}

void VulkanAsciiConsumer::Process_vkQueueBindSparse(
    VkResult                                    returnValue,
    VkQueue                                     queue,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindSparseInfo>& pBindInfo,
    VkFence                                     fence)
{
    fprintf(m_file, "%s\n", "vkQueueBindSparse");
}

void VulkanAsciiConsumer::Process_vkCreateFence(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkFenceCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkFence>&              pFence)
{
    fprintf(m_file, "%s\n", "vkCreateFence");
}

void VulkanAsciiConsumer::Process_vkDestroyFence(
    VkDevice                                    device,
    VkFence                                     fence,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyFence");
}

void VulkanAsciiConsumer::Process_vkResetFences(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const PointerDecoder<VkFence>&              pFences)
{
    fprintf(m_file, "%s\n", "vkResetFences");
}

void VulkanAsciiConsumer::Process_vkGetFenceStatus(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkFence                                     fence)
{
    fprintf(m_file, "%s\n", "vkGetFenceStatus");
}

void VulkanAsciiConsumer::Process_vkWaitForFences(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const PointerDecoder<VkFence>&              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    fprintf(m_file, "%s\n", "vkWaitForFences");
}

void VulkanAsciiConsumer::Process_vkCreateSemaphore(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSemaphore>&          pSemaphore)
{
    fprintf(m_file, "%s\n", "vkCreateSemaphore");
}

void VulkanAsciiConsumer::Process_vkDestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroySemaphore");
}

void VulkanAsciiConsumer::Process_vkCreateEvent(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkEventCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkEvent>&              pEvent)
{
    fprintf(m_file, "%s\n", "vkCreateEvent");
}

void VulkanAsciiConsumer::Process_vkDestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyEvent");
}

void VulkanAsciiConsumer::Process_vkGetEventStatus(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkEvent                                     event)
{
    fprintf(m_file, "%s\n", "vkGetEventStatus");
}

void VulkanAsciiConsumer::Process_vkSetEvent(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkEvent                                     event)
{
    fprintf(m_file, "%s\n", "vkSetEvent");
}

void VulkanAsciiConsumer::Process_vkResetEvent(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkEvent                                     event)
{
    fprintf(m_file, "%s\n", "vkResetEvent");
}

void VulkanAsciiConsumer::Process_vkCreateQueryPool(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkQueryPool>&          pQueryPool)
{
    fprintf(m_file, "%s\n", "vkCreateQueryPool");
}

void VulkanAsciiConsumer::Process_vkDestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyQueryPool");
}

void VulkanAsciiConsumer::Process_vkGetQueryPoolResults(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    const PointerDecoder<uint8_t>&              pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    fprintf(m_file, "%s\n", "vkGetQueryPoolResults");
}

void VulkanAsciiConsumer::Process_vkCreateBuffer(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkBufferCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkBuffer>&             pBuffer)
{
    fprintf(m_file, "%s\n", "vkCreateBuffer");
}

void VulkanAsciiConsumer::Process_vkDestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyBuffer");
}

void VulkanAsciiConsumer::Process_vkCreateBufferView(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkBufferViewCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkBufferView>&         pView)
{
    fprintf(m_file, "%s\n", "vkCreateBufferView");
}

void VulkanAsciiConsumer::Process_vkDestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyBufferView");
}

void VulkanAsciiConsumer::Process_vkCreateImage(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImageCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkImage>&              pImage)
{
    fprintf(m_file, "%s\n", "vkCreateImage");
}

void VulkanAsciiConsumer::Process_vkDestroyImage(
    VkDevice                                    device,
    VkImage                                     image,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyImage");
}

void VulkanAsciiConsumer::Process_vkGetImageSubresourceLayout(
    VkDevice                                    device,
    VkImage                                     image,
    const StructPointerDecoder<Decoded_VkImageSubresource>& pSubresource,
    const StructPointerDecoder<Decoded_VkSubresourceLayout>& pLayout)
{
    fprintf(m_file, "%s\n", "vkGetImageSubresourceLayout");
}

void VulkanAsciiConsumer::Process_vkCreateImageView(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImageViewCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkImageView>&          pView)
{
    fprintf(m_file, "%s\n", "vkCreateImageView");
}

void VulkanAsciiConsumer::Process_vkDestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyImageView");
}

void VulkanAsciiConsumer::Process_vkCreateShaderModule(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkShaderModule>&       pShaderModule)
{
    fprintf(m_file, "%s\n", "vkCreateShaderModule");
}

void VulkanAsciiConsumer::Process_vkDestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyShaderModule");
}

void VulkanAsciiConsumer::Process_vkCreatePipelineCache(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkPipelineCache>&      pPipelineCache)
{
    fprintf(m_file, "%s\n", "vkCreatePipelineCache");
}

void VulkanAsciiConsumer::Process_vkDestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyPipelineCache");
}

void VulkanAsciiConsumer::Process_vkGetPipelineCacheData(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const PointerDecoder<size_t>&               pDataSize,
    const PointerDecoder<uint8_t>&              pData)
{
    fprintf(m_file, "%s\n", "vkGetPipelineCacheData");
}

void VulkanAsciiConsumer::Process_vkMergePipelineCaches(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkPipelineCache                             dstCache,
    uint32_t                                    srcCacheCount,
    const PointerDecoder<VkPipelineCache>&      pSrcCaches)
{
    fprintf(m_file, "%s\n", "vkMergePipelineCaches");
}

void VulkanAsciiConsumer::Process_vkCreateGraphicsPipelines(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>& pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkPipeline>&           pPipelines)
{
    fprintf(m_file, "%s\n", "vkCreateGraphicsPipelines");
}

void VulkanAsciiConsumer::Process_vkCreateComputePipelines(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>& pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkPipeline>&           pPipelines)
{
    fprintf(m_file, "%s\n", "vkCreateComputePipelines");
}

void VulkanAsciiConsumer::Process_vkDestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyPipeline");
}

void VulkanAsciiConsumer::Process_vkCreatePipelineLayout(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkPipelineLayout>&     pPipelineLayout)
{
    fprintf(m_file, "%s\n", "vkCreatePipelineLayout");
}

void VulkanAsciiConsumer::Process_vkDestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyPipelineLayout");
}

void VulkanAsciiConsumer::Process_vkCreateSampler(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSamplerCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSampler>&            pSampler)
{
    fprintf(m_file, "%s\n", "vkCreateSampler");
}

void VulkanAsciiConsumer::Process_vkDestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroySampler");
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorSetLayout(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDescriptorSetLayout>& pSetLayout)
{
    fprintf(m_file, "%s\n", "vkCreateDescriptorSetLayout");
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyDescriptorSetLayout");
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorPool(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDescriptorPool>&     pDescriptorPool)
{
    fprintf(m_file, "%s\n", "vkCreateDescriptorPool");
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyDescriptorPool");
}

void VulkanAsciiConsumer::Process_vkResetDescriptorPool(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    fprintf(m_file, "%s\n", "vkResetDescriptorPool");
}

void VulkanAsciiConsumer::Process_vkAllocateDescriptorSets(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>& pAllocateInfo,
    const PointerDecoder<VkDescriptorSet>&      pDescriptorSets)
{
    fprintf(m_file, "%s\n", "vkAllocateDescriptorSets");
}

void VulkanAsciiConsumer::Process_vkFreeDescriptorSets(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    const PointerDecoder<VkDescriptorSet>&      pDescriptorSets)
{
    fprintf(m_file, "%s\n", "vkFreeDescriptorSets");
}

void VulkanAsciiConsumer::Process_vkUpdateDescriptorSets(
    VkDevice                                    device,
    uint32_t                                    descriptorWriteCount,
    const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    const StructPointerDecoder<Decoded_VkCopyDescriptorSet>& pDescriptorCopies)
{
    fprintf(m_file, "%s\n", "vkUpdateDescriptorSets");
}

void VulkanAsciiConsumer::Process_vkCreateFramebuffer(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkFramebufferCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkFramebuffer>&        pFramebuffer)
{
    fprintf(m_file, "%s\n", "vkCreateFramebuffer");
}

void VulkanAsciiConsumer::Process_vkDestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyFramebuffer");
}

void VulkanAsciiConsumer::Process_vkCreateRenderPass(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkRenderPass>&         pRenderPass)
{
    fprintf(m_file, "%s\n", "vkCreateRenderPass");
}

void VulkanAsciiConsumer::Process_vkDestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyRenderPass");
}

void VulkanAsciiConsumer::Process_vkGetRenderAreaGranularity(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const StructPointerDecoder<Decoded_VkExtent2D>& pGranularity)
{
    fprintf(m_file, "%s\n", "vkGetRenderAreaGranularity");
}

void VulkanAsciiConsumer::Process_vkCreateCommandPool(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkCommandPool>&        pCommandPool)
{
    fprintf(m_file, "%s\n", "vkCreateCommandPool");
}

void VulkanAsciiConsumer::Process_vkDestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyCommandPool");
}

void VulkanAsciiConsumer::Process_vkResetCommandPool(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags)
{
    fprintf(m_file, "%s\n", "vkResetCommandPool");
}

void VulkanAsciiConsumer::Process_vkAllocateCommandBuffers(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>& pAllocateInfo,
    const PointerDecoder<VkCommandBuffer>&      pCommandBuffers)
{
    fprintf(m_file, "%s\n", "vkAllocateCommandBuffers");
}

void VulkanAsciiConsumer::Process_vkFreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    uint32_t                                    commandBufferCount,
    const PointerDecoder<VkCommandBuffer>&      pCommandBuffers)
{
    fprintf(m_file, "%s\n", "vkFreeCommandBuffers");
}

void VulkanAsciiConsumer::Process_vkBeginCommandBuffer(
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>& pBeginInfo)
{
    fprintf(m_file, "%s\n", "vkBeginCommandBuffer");
}

void VulkanAsciiConsumer::Process_vkEndCommandBuffer(
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer)
{
    fprintf(m_file, "%s\n", "vkEndCommandBuffer");
}

void VulkanAsciiConsumer::Process_vkResetCommandBuffer(
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    fprintf(m_file, "%s\n", "vkResetCommandBuffer");
}

void VulkanAsciiConsumer::Process_vkCmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline)
{
    fprintf(m_file, "%s\n", "vkCmdBindPipeline");
}

void VulkanAsciiConsumer::Process_vkCmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const StructPointerDecoder<Decoded_VkViewport>& pViewports)
{
    fprintf(m_file, "%s\n", "vkCmdSetViewport");
}

void VulkanAsciiConsumer::Process_vkCmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const StructPointerDecoder<Decoded_VkRect2D>& pScissors)
{
    fprintf(m_file, "%s\n", "vkCmdSetScissor");
}

void VulkanAsciiConsumer::Process_vkCmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth)
{
    fprintf(m_file, "%s\n", "vkCmdSetLineWidth");
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    fprintf(m_file, "%s\n", "vkCmdSetDepthBias");
}

void VulkanAsciiConsumer::Process_vkCmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const PointerDecoder<float>&                blendConstants)
{
    fprintf(m_file, "%s\n", "vkCmdSetBlendConstants");
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    fprintf(m_file, "%s\n", "vkCmdSetDepthBounds");
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    fprintf(m_file, "%s\n", "vkCmdSetStencilCompareMask");
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    fprintf(m_file, "%s\n", "vkCmdSetStencilWriteMask");
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    fprintf(m_file, "%s\n", "vkCmdSetStencilReference");
}

void VulkanAsciiConsumer::Process_vkCmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const PointerDecoder<VkDescriptorSet>&      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const PointerDecoder<uint32_t>&             pDynamicOffsets)
{
    fprintf(m_file, "%s\n", "vkCmdBindDescriptorSets");
}

void VulkanAsciiConsumer::Process_vkCmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    fprintf(m_file, "%s\n", "vkCmdBindIndexBuffer");
}

void VulkanAsciiConsumer::Process_vkCmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const PointerDecoder<VkBuffer>&             pBuffers,
    const PointerDecoder<VkDeviceSize>&         pOffsets)
{
    fprintf(m_file, "%s\n", "vkCmdBindVertexBuffers");
}

void VulkanAsciiConsumer::Process_vkCmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    fprintf(m_file, "%s\n", "vkCmdDraw");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    fprintf(m_file, "%s\n", "vkCmdDrawIndexed");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    fprintf(m_file, "%s\n", "vkCmdDrawIndirect");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    fprintf(m_file, "%s\n", "vkCmdDrawIndexedIndirect");
}

void VulkanAsciiConsumer::Process_vkCmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    fprintf(m_file, "%s\n", "vkCmdDispatch");
}

void VulkanAsciiConsumer::Process_vkCmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{
    fprintf(m_file, "%s\n", "vkCmdDispatchIndirect");
}

void VulkanAsciiConsumer::Process_vkCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkBufferCopy>& pRegions)
{
    fprintf(m_file, "%s\n", "vkCmdCopyBuffer");
}

void VulkanAsciiConsumer::Process_vkCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkImageCopy>& pRegions)
{
    fprintf(m_file, "%s\n", "vkCmdCopyImage");
}

void VulkanAsciiConsumer::Process_vkCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkImageBlit>& pRegions,
    VkFilter                                    filter)
{
    fprintf(m_file, "%s\n", "vkCmdBlitImage");
}

void VulkanAsciiConsumer::Process_vkCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions)
{
    fprintf(m_file, "%s\n", "vkCmdCopyBufferToImage");
}

void VulkanAsciiConsumer::Process_vkCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions)
{
    fprintf(m_file, "%s\n", "vkCmdCopyImageToBuffer");
}

void VulkanAsciiConsumer::Process_vkCmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const PointerDecoder<uint8_t>&              pData)
{
    fprintf(m_file, "%s\n", "vkCmdUpdateBuffer");
}

void VulkanAsciiConsumer::Process_vkCmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    fprintf(m_file, "%s\n", "vkCmdFillBuffer");
}

void VulkanAsciiConsumer::Process_vkCmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const StructPointerDecoder<Decoded_VkClearColorValue>& pColor,
    uint32_t                                    rangeCount,
    const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges)
{
    fprintf(m_file, "%s\n", "vkCmdClearColorImage");
}

void VulkanAsciiConsumer::Process_vkCmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const StructPointerDecoder<Decoded_VkClearDepthStencilValue>& pDepthStencil,
    uint32_t                                    rangeCount,
    const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges)
{
    fprintf(m_file, "%s\n", "vkCmdClearDepthStencilImage");
}

void VulkanAsciiConsumer::Process_vkCmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const StructPointerDecoder<Decoded_VkClearAttachment>& pAttachments,
    uint32_t                                    rectCount,
    const StructPointerDecoder<Decoded_VkClearRect>& pRects)
{
    fprintf(m_file, "%s\n", "vkCmdClearAttachments");
}

void VulkanAsciiConsumer::Process_vkCmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkImageResolve>& pRegions)
{
    fprintf(m_file, "%s\n", "vkCmdResolveImage");
}

void VulkanAsciiConsumer::Process_vkCmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    fprintf(m_file, "%s\n", "vkCmdSetEvent");
}

void VulkanAsciiConsumer::Process_vkCmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    fprintf(m_file, "%s\n", "vkCmdResetEvent");
}

void VulkanAsciiConsumer::Process_vkCmdWaitEvents(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const PointerDecoder<VkEvent>&              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const StructPointerDecoder<Decoded_VkMemoryBarrier>& pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>& pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkImageMemoryBarrier>& pImageMemoryBarriers)
{
    fprintf(m_file, "%s\n", "vkCmdWaitEvents");
}

void VulkanAsciiConsumer::Process_vkCmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const StructPointerDecoder<Decoded_VkMemoryBarrier>& pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>& pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkImageMemoryBarrier>& pImageMemoryBarriers)
{
    fprintf(m_file, "%s\n", "vkCmdPipelineBarrier");
}

void VulkanAsciiConsumer::Process_vkCmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    fprintf(m_file, "%s\n", "vkCmdBeginQuery");
}

void VulkanAsciiConsumer::Process_vkCmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    fprintf(m_file, "%s\n", "vkCmdEndQuery");
}

void VulkanAsciiConsumer::Process_vkCmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    fprintf(m_file, "%s\n", "vkCmdResetQueryPool");
}

void VulkanAsciiConsumer::Process_vkCmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    fprintf(m_file, "%s\n", "vkCmdWriteTimestamp");
}

void VulkanAsciiConsumer::Process_vkCmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    fprintf(m_file, "%s\n", "vkCmdCopyQueryPoolResults");
}

void VulkanAsciiConsumer::Process_vkCmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const PointerDecoder<uint8_t>&              pValues)
{
    fprintf(m_file, "%s\n", "vkCmdPushConstants");
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
    VkSubpassContents                           contents)
{
    fprintf(m_file, "%s\n", "vkCmdBeginRenderPass");
}

void VulkanAsciiConsumer::Process_vkCmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents)
{
    fprintf(m_file, "%s\n", "vkCmdNextSubpass");
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderPass(
    VkCommandBuffer                             commandBuffer)
{
    fprintf(m_file, "%s\n", "vkCmdEndRenderPass");
}

void VulkanAsciiConsumer::Process_vkCmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const PointerDecoder<VkCommandBuffer>&      pCommandBuffers)
{
    fprintf(m_file, "%s\n", "vkCmdExecuteCommands");
}

void VulkanAsciiConsumer::Process_vkBindBufferMemory2(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos)
{
    fprintf(m_file, "%s\n", "vkBindBufferMemory2");
}

void VulkanAsciiConsumer::Process_vkBindImageMemory2(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos)
{
    fprintf(m_file, "%s\n", "vkBindImageMemory2");
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    const PointerDecoder<VkPeerMemoryFeatureFlags>& pPeerMemoryFeatures)
{
    fprintf(m_file, "%s\n", "vkGetDeviceGroupPeerMemoryFeatures");
}

void VulkanAsciiConsumer::Process_vkCmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    fprintf(m_file, "%s\n", "vkCmdSetDeviceMask");
}

void VulkanAsciiConsumer::Process_vkCmdDispatchBase(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    fprintf(m_file, "%s\n", "vkCmdDispatchBase");
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const PointerDecoder<uint32_t>&             pPhysicalDeviceGroupCount,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>& pPhysicalDeviceGroupProperties)
{
    fprintf(m_file, "%s\n", "vkEnumeratePhysicalDeviceGroups");
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements2(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
    const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements)
{
    fprintf(m_file, "%s\n", "vkGetImageMemoryRequirements2");
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements2(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
    const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements)
{
    fprintf(m_file, "%s\n", "vkGetBufferMemoryRequirements2");
}

void VulkanAsciiConsumer::Process_vkGetImageSparseMemoryRequirements2(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
    const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
    const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>& pSparseMemoryRequirements)
{
    fprintf(m_file, "%s\n", "vkGetImageSparseMemoryRequirements2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures2(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>& pFeatures)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceFeatures2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties2(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>& pProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceProperties2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    const StructPointerDecoder<Decoded_VkFormatProperties2>& pFormatProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceFormatProperties2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
    const StructPointerDecoder<Decoded_VkImageFormatProperties2>& pImageFormatProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceImageFormatProperties2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
    const StructPointerDecoder<Decoded_VkQueueFamilyProperties2>& pQueueFamilyProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceQueueFamilyProperties2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>& pMemoryProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceMemoryProperties2");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>& pProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceSparseImageFormatProperties2");
}

void VulkanAsciiConsumer::Process_vkTrimCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    fprintf(m_file, "%s\n", "vkTrimCommandPool");
}

void VulkanAsciiConsumer::Process_vkGetDeviceQueue2(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDeviceQueueInfo2>& pQueueInfo,
    const PointerDecoder<VkQueue>&              pQueue)
{
    fprintf(m_file, "%s\n", "vkGetDeviceQueue2");
}

void VulkanAsciiConsumer::Process_vkCreateSamplerYcbcrConversion(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSamplerYcbcrConversion>& pYcbcrConversion)
{
    fprintf(m_file, "%s\n", "vkCreateSamplerYcbcrConversion");
}

void VulkanAsciiConsumer::Process_vkDestroySamplerYcbcrConversion(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroySamplerYcbcrConversion");
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorUpdateTemplate(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDescriptorUpdateTemplate>& pDescriptorUpdateTemplate)
{
    fprintf(m_file, "%s\n", "vkCreateDescriptorUpdateTemplate");
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyDescriptorUpdateTemplate");
}

void VulkanAsciiConsumer::Process_vkUpdateDescriptorSetWithTemplate(
    VkDevice                                    device,
    VkDescriptorSet                             descriptorSet,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    uint64_t                                    pData)
{
    fprintf(m_file, "%s\n", "vkUpdateDescriptorSetWithTemplate");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
    const StructPointerDecoder<Decoded_VkExternalBufferProperties>& pExternalBufferProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceExternalBufferProperties");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
    const StructPointerDecoder<Decoded_VkExternalFenceProperties>& pExternalFenceProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceExternalFenceProperties");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
    const StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>& pExternalSemaphoreProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceExternalSemaphoreProperties");
}

void VulkanAsciiConsumer::Process_vkGetDescriptorSetLayoutSupport(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>& pSupport)
{
    fprintf(m_file, "%s\n", "vkGetDescriptorSetLayoutSupport");
}

void VulkanAsciiConsumer::Process_vkDestroySurfaceKHR(
    VkInstance                                  instance,
    VkSurfaceKHR                                surface,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroySurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    VkSurfaceKHR                                surface,
    const PointerDecoder<VkBool32>&             pSupported)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceSurfaceSupportKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    const StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>& pSurfaceCapabilities)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    const PointerDecoder<uint32_t>&             pSurfaceFormatCount,
    const StructPointerDecoder<Decoded_VkSurfaceFormatKHR>& pSurfaceFormats)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceSurfaceFormatsKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    const PointerDecoder<uint32_t>&             pPresentModeCount,
    const PointerDecoder<VkPresentModeKHR>&     pPresentModes)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceSurfacePresentModesKHR");
}

void VulkanAsciiConsumer::Process_vkCreateSwapchainKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSwapchainKHR>&       pSwapchain)
{
    fprintf(m_file, "%s\n", "vkCreateSwapchainKHR");
}

void VulkanAsciiConsumer::Process_vkDestroySwapchainKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroySwapchainKHR");
}

void VulkanAsciiConsumer::Process_vkGetSwapchainImagesKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const PointerDecoder<uint32_t>&             pSwapchainImageCount,
    const PointerDecoder<VkImage>&              pSwapchainImages)
{
    fprintf(m_file, "%s\n", "vkGetSwapchainImagesKHR");
}

void VulkanAsciiConsumer::Process_vkAcquireNextImageKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    timeout,
    VkSemaphore                                 semaphore,
    VkFence                                     fence,
    const PointerDecoder<uint32_t>&             pImageIndex)
{
    fprintf(m_file, "%s\n", "vkAcquireNextImageKHR");
}

void VulkanAsciiConsumer::Process_vkQueuePresentKHR(
    VkResult                                    returnValue,
    VkQueue                                     queue,
    const StructPointerDecoder<Decoded_VkPresentInfoKHR>& pPresentInfo)
{
    fprintf(m_file, "%s\n", "vkQueuePresentKHR");
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>& pDeviceGroupPresentCapabilities)
{
    fprintf(m_file, "%s\n", "vkGetDeviceGroupPresentCapabilitiesKHR");
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSurfaceKHR                                surface,
    const PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>& pModes)
{
    fprintf(m_file, "%s\n", "vkGetDeviceGroupSurfacePresentModesKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    const PointerDecoder<uint32_t>&             pRectCount,
    const StructPointerDecoder<Decoded_VkRect2D>& pRects)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDevicePresentRectanglesKHR");
}

void VulkanAsciiConsumer::Process_vkAcquireNextImage2KHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>& pAcquireInfo,
    const PointerDecoder<uint32_t>&             pImageIndex)
{
    fprintf(m_file, "%s\n", "vkAcquireNextImage2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>& pProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceDisplayPropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>& pProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    planeIndex,
    const PointerDecoder<uint32_t>&             pDisplayCount,
    const PointerDecoder<VkDisplayKHR>&         pDisplays)
{
    fprintf(m_file, "%s\n", "vkGetDisplayPlaneSupportedDisplaysKHR");
}

void VulkanAsciiConsumer::Process_vkGetDisplayModePropertiesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>& pProperties)
{
    fprintf(m_file, "%s\n", "vkGetDisplayModePropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkCreateDisplayModeKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDisplayModeKHR>&     pMode)
{
    fprintf(m_file, "%s\n", "vkCreateDisplayModeKHR");
}

void VulkanAsciiConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayModeKHR                            mode,
    uint32_t                                    planeIndex,
    const StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>& pCapabilities)
{
    fprintf(m_file, "%s\n", "vkGetDisplayPlaneCapabilitiesKHR");
}

void VulkanAsciiConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    fprintf(m_file, "%s\n", "vkCreateDisplayPlaneSurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkCreateSharedSwapchainsKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSwapchainKHR>&       pSwapchains)
{
    fprintf(m_file, "%s\n", "vkCreateSharedSwapchainsKHR");
}

#ifdef VK_USE_PLATFORM_XLIB_KHR
void VulkanAsciiConsumer::Process_vkCreateXlibSurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    fprintf(m_file, "%s\n", "vkCreateXlibSurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    VkBool32                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    const PointerDecoder<Display>&              dpy,
    VisualID                                    visualID)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceXlibPresentationSupportKHR");
}
#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
void VulkanAsciiConsumer::Process_vkCreateXcbSurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    fprintf(m_file, "%s\n", "vkCreateXcbSurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    VkBool32                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    const PointerDecoder<xcb_connection_t>&     connection,
    xcb_visualid_t                              visual_id)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceXcbPresentationSupportKHR");
}
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
void VulkanAsciiConsumer::Process_vkCreateWaylandSurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    fprintf(m_file, "%s\n", "vkCreateWaylandSurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    VkBool32                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    const PointerDecoder<wl_display>&           display)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
}
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
void VulkanAsciiConsumer::Process_vkCreateMirSurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkMirSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    fprintf(m_file, "%s\n", "vkCreateMirSurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMirPresentationSupportKHR(
    VkBool32                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    const PointerDecoder<MirConnection>&        connection)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceMirPresentationSupportKHR");
}
#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
void VulkanAsciiConsumer::Process_vkCreateAndroidSurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    fprintf(m_file, "%s\n", "vkCreateAndroidSurfaceKHR");
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanAsciiConsumer::Process_vkCreateWin32SurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    fprintf(m_file, "%s\n", "vkCreateWin32SurfaceKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    VkBool32                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceWin32PresentationSupportKHR");
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>& pFeatures)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceFeatures2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>& pProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    const StructPointerDecoder<Decoded_VkFormatProperties2>& pFormatProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceFormatProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
    const StructPointerDecoder<Decoded_VkImageFormatProperties2>& pImageFormatProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceImageFormatProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
    const StructPointerDecoder<Decoded_VkQueueFamilyProperties2>& pQueueFamilyProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>& pMemoryProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceMemoryProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>& pProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    const PointerDecoder<VkPeerMemoryFeatureFlags>& pPeerMemoryFeatures)
{
    fprintf(m_file, "%s\n", "vkGetDeviceGroupPeerMemoryFeaturesKHR");
}

void VulkanAsciiConsumer::Process_vkCmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    fprintf(m_file, "%s\n", "vkCmdSetDeviceMaskKHR");
}

void VulkanAsciiConsumer::Process_vkCmdDispatchBaseKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    fprintf(m_file, "%s\n", "vkCmdDispatchBaseKHR");
}

void VulkanAsciiConsumer::Process_vkTrimCommandPoolKHR(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    fprintf(m_file, "%s\n", "vkTrimCommandPoolKHR");
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const PointerDecoder<uint32_t>&             pPhysicalDeviceGroupCount,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>& pPhysicalDeviceGroupProperties)
{
    fprintf(m_file, "%s\n", "vkEnumeratePhysicalDeviceGroupsKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
    const StructPointerDecoder<Decoded_VkExternalBufferProperties>& pExternalBufferProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanAsciiConsumer::Process_vkGetMemoryWin32HandleKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
    const PointerDecoder<HANDLE>&               pHandle)
{
    fprintf(m_file, "%s\n", "vkGetMemoryWin32HandleKHR");
}

void VulkanAsciiConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    HANDLE                                      handle,
    const StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>& pMemoryWin32HandleProperties)
{
    fprintf(m_file, "%s\n", "vkGetMemoryWin32HandlePropertiesKHR");
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void VulkanAsciiConsumer::Process_vkGetMemoryFdKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>& pGetFdInfo,
    const PointerDecoder<int>&                  pFd)
{
    fprintf(m_file, "%s\n", "vkGetMemoryFdKHR");
}

void VulkanAsciiConsumer::Process_vkGetMemoryFdPropertiesKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    const StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>& pMemoryFdProperties)
{
    fprintf(m_file, "%s\n", "vkGetMemoryFdPropertiesKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
    const StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>& pExternalSemaphoreProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanAsciiConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>& pImportSemaphoreWin32HandleInfo)
{
    fprintf(m_file, "%s\n", "vkImportSemaphoreWin32HandleKHR");
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
    const PointerDecoder<HANDLE>&               pHandle)
{
    fprintf(m_file, "%s\n", "vkGetSemaphoreWin32HandleKHR");
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void VulkanAsciiConsumer::Process_vkImportSemaphoreFdKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>& pImportSemaphoreFdInfo)
{
    fprintf(m_file, "%s\n", "vkImportSemaphoreFdKHR");
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreFdKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>& pGetFdInfo,
    const PointerDecoder<int>&                  pFd)
{
    fprintf(m_file, "%s\n", "vkGetSemaphoreFdKHR");
}

void VulkanAsciiConsumer::Process_vkCmdPushDescriptorSetKHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites)
{
    fprintf(m_file, "%s\n", "vkCmdPushDescriptorSetKHR");
}

void VulkanAsciiConsumer::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    VkCommandBuffer                             commandBuffer,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint64_t                                    pData)
{
    fprintf(m_file, "%s\n", "vkCmdPushDescriptorSetWithTemplateKHR");
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDescriptorUpdateTemplate>& pDescriptorUpdateTemplate)
{
    fprintf(m_file, "%s\n", "vkCreateDescriptorUpdateTemplateKHR");
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyDescriptorUpdateTemplateKHR");
}

void VulkanAsciiConsumer::Process_vkUpdateDescriptorSetWithTemplateKHR(
    VkDevice                                    device,
    VkDescriptorSet                             descriptorSet,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    uint64_t                                    pData)
{
    fprintf(m_file, "%s\n", "vkUpdateDescriptorSetWithTemplateKHR");
}

void VulkanAsciiConsumer::Process_vkCreateRenderPass2KHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo2KHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkRenderPass>&         pRenderPass)
{
    fprintf(m_file, "%s\n", "vkCreateRenderPass2KHR");
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
    const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo)
{
    fprintf(m_file, "%s\n", "vkCmdBeginRenderPass2KHR");
}

void VulkanAsciiConsumer::Process_vkCmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo,
    const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo)
{
    fprintf(m_file, "%s\n", "vkCmdNextSubpass2KHR");
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo)
{
    fprintf(m_file, "%s\n", "vkCmdEndRenderPass2KHR");
}

void VulkanAsciiConsumer::Process_vkGetSwapchainStatusKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{
    fprintf(m_file, "%s\n", "vkGetSwapchainStatusKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
    const StructPointerDecoder<Decoded_VkExternalFenceProperties>& pExternalFenceProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceExternalFencePropertiesKHR");
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanAsciiConsumer::Process_vkImportFenceWin32HandleKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>& pImportFenceWin32HandleInfo)
{
    fprintf(m_file, "%s\n", "vkImportFenceWin32HandleKHR");
}

void VulkanAsciiConsumer::Process_vkGetFenceWin32HandleKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
    const PointerDecoder<HANDLE>&               pHandle)
{
    fprintf(m_file, "%s\n", "vkGetFenceWin32HandleKHR");
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void VulkanAsciiConsumer::Process_vkImportFenceFdKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>& pImportFenceFdInfo)
{
    fprintf(m_file, "%s\n", "vkImportFenceFdKHR");
}

void VulkanAsciiConsumer::Process_vkGetFenceFdKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>& pGetFdInfo,
    const PointerDecoder<int>&                  pFd)
{
    fprintf(m_file, "%s\n", "vkGetFenceFdKHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
    const StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>& pSurfaceCapabilities)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
    const PointerDecoder<uint32_t>&             pSurfaceFormatCount,
    const StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>& pSurfaceFormats)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceSurfaceFormats2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayProperties2KHR>& pProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceDisplayProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>& pProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetDisplayModeProperties2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>& pProperties)
{
    fprintf(m_file, "%s\n", "vkGetDisplayModeProperties2KHR");
}

void VulkanAsciiConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>& pDisplayPlaneInfo,
    const StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>& pCapabilities)
{
    fprintf(m_file, "%s\n", "vkGetDisplayPlaneCapabilities2KHR");
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements2KHR(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
    const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements)
{
    fprintf(m_file, "%s\n", "vkGetImageMemoryRequirements2KHR");
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
    const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements)
{
    fprintf(m_file, "%s\n", "vkGetBufferMemoryRequirements2KHR");
}

void VulkanAsciiConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
    const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
    const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>& pSparseMemoryRequirements)
{
    fprintf(m_file, "%s\n", "vkGetImageSparseMemoryRequirements2KHR");
}

void VulkanAsciiConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSamplerYcbcrConversion>& pYcbcrConversion)
{
    fprintf(m_file, "%s\n", "vkCreateSamplerYcbcrConversionKHR");
}

void VulkanAsciiConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroySamplerYcbcrConversionKHR");
}

void VulkanAsciiConsumer::Process_vkBindBufferMemory2KHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos)
{
    fprintf(m_file, "%s\n", "vkBindBufferMemory2KHR");
}

void VulkanAsciiConsumer::Process_vkBindImageMemory2KHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos)
{
    fprintf(m_file, "%s\n", "vkBindImageMemory2KHR");
}

void VulkanAsciiConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>& pSupport)
{
    fprintf(m_file, "%s\n", "vkGetDescriptorSetLayoutSupportKHR");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    fprintf(m_file, "%s\n", "vkCmdDrawIndirectCountKHR");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    fprintf(m_file, "%s\n", "vkCmdDrawIndexedIndirectCountKHR");
}

void VulkanAsciiConsumer::Process_vkCreateDebugReportCallbackEXT(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDebugReportCallbackEXT>& pCallback)
{
    fprintf(m_file, "%s\n", "vkCreateDebugReportCallbackEXT");
}

void VulkanAsciiConsumer::Process_vkDestroyDebugReportCallbackEXT(
    VkInstance                                  instance,
    VkDebugReportCallbackEXT                    callback,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyDebugReportCallbackEXT");
}

void VulkanAsciiConsumer::Process_vkDebugReportMessageEXT(
    VkInstance                                  instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    const StringDecoder&                        pLayerPrefix,
    const StringDecoder&                        pMessage)
{
    fprintf(m_file, "%s\n", "vkDebugReportMessageEXT");
}

void VulkanAsciiConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>& pTagInfo)
{
    fprintf(m_file, "%s\n", "vkDebugMarkerSetObjectTagEXT");
}

void VulkanAsciiConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>& pNameInfo)
{
    fprintf(m_file, "%s\n", "vkDebugMarkerSetObjectNameEXT");
}

void VulkanAsciiConsumer::Process_vkCmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo)
{
    fprintf(m_file, "%s\n", "vkCmdDebugMarkerBeginEXT");
}

void VulkanAsciiConsumer::Process_vkCmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer)
{
    fprintf(m_file, "%s\n", "vkCmdDebugMarkerEndEXT");
}

void VulkanAsciiConsumer::Process_vkCmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo)
{
    fprintf(m_file, "%s\n", "vkCmdDebugMarkerInsertEXT");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    fprintf(m_file, "%s\n", "vkCmdDrawIndirectCountAMD");
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    fprintf(m_file, "%s\n", "vkCmdDrawIndexedIndirectCountAMD");
}

void VulkanAsciiConsumer::Process_vkGetShaderInfoAMD(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    const PointerDecoder<size_t>&               pInfoSize,
    const PointerDecoder<uint8_t>&              pInfo)
{
    fprintf(m_file, "%s\n", "vkGetShaderInfoAMD");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
    const StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>& pExternalImageFormatProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanAsciiConsumer::Process_vkGetMemoryWin32HandleNV(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    const PointerDecoder<HANDLE>&               pHandle)
{
    fprintf(m_file, "%s\n", "vkGetMemoryWin32HandleNV");
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_VI_NN
void VulkanAsciiConsumer::Process_vkCreateViSurfaceNN(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    fprintf(m_file, "%s\n", "vkCreateViSurfaceNN");
}
#endif /* VK_USE_PLATFORM_VI_NN */

void VulkanAsciiConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>& pConditionalRenderingBegin)
{
    fprintf(m_file, "%s\n", "vkCmdBeginConditionalRenderingEXT");
}

void VulkanAsciiConsumer::Process_vkCmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer)
{
    fprintf(m_file, "%s\n", "vkCmdEndConditionalRenderingEXT");
}

void VulkanAsciiConsumer::Process_vkCmdProcessCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkCmdProcessCommandsInfoNVX>& pProcessCommandsInfo)
{
    fprintf(m_file, "%s\n", "vkCmdProcessCommandsNVX");
}

void VulkanAsciiConsumer::Process_vkCmdReserveSpaceForCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkCmdReserveSpaceForCommandsInfoNVX>& pReserveSpaceInfo)
{
    fprintf(m_file, "%s\n", "vkCmdReserveSpaceForCommandsNVX");
}

void VulkanAsciiConsumer::Process_vkCreateIndirectCommandsLayoutNVX(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNVX>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkIndirectCommandsLayoutNVX>& pIndirectCommandsLayout)
{
    fprintf(m_file, "%s\n", "vkCreateIndirectCommandsLayoutNVX");
}

void VulkanAsciiConsumer::Process_vkDestroyIndirectCommandsLayoutNVX(
    VkDevice                                    device,
    VkIndirectCommandsLayoutNVX                 indirectCommandsLayout,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyIndirectCommandsLayoutNVX");
}

void VulkanAsciiConsumer::Process_vkCreateObjectTableNVX(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkObjectTableCreateInfoNVX>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkObjectTableNVX>&     pObjectTable)
{
    fprintf(m_file, "%s\n", "vkCreateObjectTableNVX");
}

void VulkanAsciiConsumer::Process_vkDestroyObjectTableNVX(
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyObjectTableNVX");
}

void VulkanAsciiConsumer::Process_vkRegisterObjectsNVX(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    uint32_t                                    objectCount,
    const StructPointerDecoder<Decoded_VkObjectTableEntryNVX>& ppObjectTableEntries,
    const PointerDecoder<uint32_t>&             pObjectIndices)
{
    fprintf(m_file, "%s\n", "vkRegisterObjectsNVX");
}

void VulkanAsciiConsumer::Process_vkUnregisterObjectsNVX(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    uint32_t                                    objectCount,
    const PointerDecoder<VkObjectEntryTypeNVX>& pObjectEntryTypes,
    const PointerDecoder<uint32_t>&             pObjectIndices)
{
    fprintf(m_file, "%s\n", "vkUnregisterObjectsNVX");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsFeaturesNVX>& pFeatures,
    const StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsLimitsNVX>& pLimits)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX");
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const StructPointerDecoder<Decoded_VkViewportWScalingNV>& pViewportWScalings)
{
    fprintf(m_file, "%s\n", "vkCmdSetViewportWScalingNV");
}

void VulkanAsciiConsumer::Process_vkReleaseDisplayEXT(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display)
{
    fprintf(m_file, "%s\n", "vkReleaseDisplayEXT");
}

#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
void VulkanAsciiConsumer::Process_vkAcquireXlibDisplayEXT(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<Display>&              dpy,
    VkDisplayKHR                                display)
{
    fprintf(m_file, "%s\n", "vkAcquireXlibDisplayEXT");
}

void VulkanAsciiConsumer::Process_vkGetRandROutputDisplayEXT(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<Display>&              dpy,
    RROutput                                    rrOutput,
    const PointerDecoder<VkDisplayKHR>&         pDisplay)
{
    fprintf(m_file, "%s\n", "vkGetRandROutputDisplayEXT");
}
#endif /* VK_USE_PLATFORM_XLIB_XRANDR_EXT */

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    const StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>& pSurfaceCapabilities)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
}

void VulkanAsciiConsumer::Process_vkDisplayPowerControlEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>& pDisplayPowerInfo)
{
    fprintf(m_file, "%s\n", "vkDisplayPowerControlEXT");
}

void VulkanAsciiConsumer::Process_vkRegisterDeviceEventEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>& pDeviceEventInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkFence>&              pFence)
{
    fprintf(m_file, "%s\n", "vkRegisterDeviceEventEXT");
}

void VulkanAsciiConsumer::Process_vkRegisterDisplayEventEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>& pDisplayEventInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkFence>&              pFence)
{
    fprintf(m_file, "%s\n", "vkRegisterDisplayEventEXT");
}

void VulkanAsciiConsumer::Process_vkGetSwapchainCounterEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    const PointerDecoder<uint64_t>&             pCounterValue)
{
    fprintf(m_file, "%s\n", "vkGetSwapchainCounterEXT");
}

void VulkanAsciiConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>& pDisplayTimingProperties)
{
    fprintf(m_file, "%s\n", "vkGetRefreshCycleDurationGOOGLE");
}

void VulkanAsciiConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const PointerDecoder<uint32_t>&             pPresentationTimingCount,
    const StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>& pPresentationTimings)
{
    fprintf(m_file, "%s\n", "vkGetPastPresentationTimingGOOGLE");
}

void VulkanAsciiConsumer::Process_vkCmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const StructPointerDecoder<Decoded_VkRect2D>& pDiscardRectangles)
{
    fprintf(m_file, "%s\n", "vkCmdSetDiscardRectangleEXT");
}

void VulkanAsciiConsumer::Process_vkSetHdrMetadataEXT(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const PointerDecoder<VkSwapchainKHR>&       pSwapchains,
    const StructPointerDecoder<Decoded_VkHdrMetadataEXT>& pMetadata)
{
    fprintf(m_file, "%s\n", "vkSetHdrMetadataEXT");
}

#ifdef VK_USE_PLATFORM_IOS_MVK
void VulkanAsciiConsumer::Process_vkCreateIOSSurfaceMVK(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    fprintf(m_file, "%s\n", "vkCreateIOSSurfaceMVK");
}
#endif /* VK_USE_PLATFORM_IOS_MVK */

#ifdef VK_USE_PLATFORM_MACOS_MVK
void VulkanAsciiConsumer::Process_vkCreateMacOSSurfaceMVK(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    fprintf(m_file, "%s\n", "vkCreateMacOSSurfaceMVK");
}
#endif /* VK_USE_PLATFORM_MACOS_MVK */

void VulkanAsciiConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>& pNameInfo)
{
    fprintf(m_file, "%s\n", "vkSetDebugUtilsObjectNameEXT");
}

void VulkanAsciiConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>& pTagInfo)
{
    fprintf(m_file, "%s\n", "vkSetDebugUtilsObjectTagEXT");
}

void VulkanAsciiConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    fprintf(m_file, "%s\n", "vkQueueBeginDebugUtilsLabelEXT");
}

void VulkanAsciiConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    VkQueue                                     queue)
{
    fprintf(m_file, "%s\n", "vkQueueEndDebugUtilsLabelEXT");
}

void VulkanAsciiConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    fprintf(m_file, "%s\n", "vkQueueInsertDebugUtilsLabelEXT");
}

void VulkanAsciiConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    fprintf(m_file, "%s\n", "vkCmdBeginDebugUtilsLabelEXT");
}

void VulkanAsciiConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer)
{
    fprintf(m_file, "%s\n", "vkCmdEndDebugUtilsLabelEXT");
}

void VulkanAsciiConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    fprintf(m_file, "%s\n", "vkCmdInsertDebugUtilsLabelEXT");
}

void VulkanAsciiConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDebugUtilsMessengerEXT>& pMessenger)
{
    fprintf(m_file, "%s\n", "vkCreateDebugUtilsMessengerEXT");
}

void VulkanAsciiConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessengerEXT                    messenger,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyDebugUtilsMessengerEXT");
}

void VulkanAsciiConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>& pCallbackData)
{
    fprintf(m_file, "%s\n", "vkSubmitDebugUtilsMessageEXT");
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
void VulkanAsciiConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const PointerDecoder<AHardwareBuffer>&      buffer,
    const StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>& pProperties)
{
    fprintf(m_file, "%s\n", "vkGetAndroidHardwareBufferPropertiesANDROID");
}

void VulkanAsciiConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>& pInfo,
    const PointerDecoder<AHardwareBuffer>&      pBuffer)
{
    fprintf(m_file, "%s\n", "vkGetMemoryAndroidHardwareBufferANDROID");
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

void VulkanAsciiConsumer::Process_vkCmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>& pSampleLocationsInfo)
{
    fprintf(m_file, "%s\n", "vkCmdSetSampleLocationsEXT");
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    const StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>& pMultisampleProperties)
{
    fprintf(m_file, "%s\n", "vkGetPhysicalDeviceMultisamplePropertiesEXT");
}

void VulkanAsciiConsumer::Process_vkCreateValidationCacheEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkValidationCacheEXT>& pValidationCache)
{
    fprintf(m_file, "%s\n", "vkCreateValidationCacheEXT");
}

void VulkanAsciiConsumer::Process_vkDestroyValidationCacheEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    fprintf(m_file, "%s\n", "vkDestroyValidationCacheEXT");
}

void VulkanAsciiConsumer::Process_vkMergeValidationCachesEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkValidationCacheEXT                        dstCache,
    uint32_t                                    srcCacheCount,
    const PointerDecoder<VkValidationCacheEXT>& pSrcCaches)
{
    fprintf(m_file, "%s\n", "vkMergeValidationCachesEXT");
}

void VulkanAsciiConsumer::Process_vkGetValidationCacheDataEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    const PointerDecoder<size_t>&               pDataSize,
    const PointerDecoder<uint8_t>&              pData)
{
    fprintf(m_file, "%s\n", "vkGetValidationCacheDataEXT");
}

void VulkanAsciiConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    const StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>& pMemoryHostPointerProperties)
{
    fprintf(m_file, "%s\n", "vkGetMemoryHostPointerPropertiesEXT");
}

void VulkanAsciiConsumer::Process_vkCmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    fprintf(m_file, "%s\n", "vkCmdWriteBufferMarkerAMD");
}
