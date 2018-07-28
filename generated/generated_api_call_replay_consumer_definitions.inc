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


void VulkanReplayConsumer::Process_vkCreateInstance(
    VkResult                                    returnValue,
    const StructPointerDecoder<Decoded_VkInstanceCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkInstance>&           pInstance)
{
    const VkInstanceCreateInfo* in_pCreateInfo = reinterpret_cast<const VkInstanceCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkInstance out_pInstance_value = static_cast<VkInstance>(0);
    VkInstance* out_pInstance = &out_pInstance_value;

    vkCreateInstance(in_pCreateInfo, in_pAllocator, out_pInstance);
}

void VulkanReplayConsumer::Process_vkDestroyInstance(
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyInstance(instance, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDevices(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const PointerDecoder<uint32_t>&             pPhysicalDeviceCount,
    const PointerDecoder<VkPhysicalDevice>&     pPhysicalDevices)
{
    uint32_t out_pPhysicalDeviceCount_value = pPhysicalDeviceCount.IsNull() ? static_cast<uint32_t>(0) : *(pPhysicalDeviceCount.GetPointer());
    uint32_t* out_pPhysicalDeviceCount = &out_pPhysicalDeviceCount_value;
    VkPhysicalDevice* out_pPhysicalDevices = pPhysicalDevices.IsNull() ? nullptr : new VkPhysicalDevice[out_pPhysicalDeviceCount_value];

    vkEnumeratePhysicalDevices(instance, out_pPhysicalDeviceCount, out_pPhysicalDevices);

    if (out_pPhysicalDevices != nullptr) delete [] out_pPhysicalDevices;
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>& pFeatures)
{
    VkPhysicalDeviceFeatures out_pFeatures_value = {};
    VkPhysicalDeviceFeatures* out_pFeatures = &out_pFeatures_value;

    vkGetPhysicalDeviceFeatures(physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    const StructPointerDecoder<Decoded_VkFormatProperties>& pFormatProperties)
{
    VkFormatProperties out_pFormatProperties_value = {};
    VkFormatProperties* out_pFormatProperties = &out_pFormatProperties_value;

    vkGetPhysicalDeviceFormatProperties(physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    const StructPointerDecoder<Decoded_VkImageFormatProperties>& pImageFormatProperties)
{
    VkImageFormatProperties out_pImageFormatProperties_value = {};
    VkImageFormatProperties* out_pImageFormatProperties = &out_pImageFormatProperties_value;

    vkGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, out_pImageFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>& pProperties)
{
    VkPhysicalDeviceProperties out_pProperties_value = {};
    VkPhysicalDeviceProperties* out_pProperties = &out_pProperties_value;

    vkGetPhysicalDeviceProperties(physicalDevice, out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
    const StructPointerDecoder<Decoded_VkQueueFamilyProperties>& pQueueFamilyProperties)
{
    uint32_t out_pQueueFamilyPropertyCount_value = pQueueFamilyPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pQueueFamilyPropertyCount.GetPointer());
    uint32_t* out_pQueueFamilyPropertyCount = &out_pQueueFamilyPropertyCount_value;
    VkQueueFamilyProperties* out_pQueueFamilyProperties = pQueueFamilyProperties.IsNull() ? nullptr : new VkQueueFamilyProperties[out_pQueueFamilyPropertyCount_value];

    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);

    if (out_pQueueFamilyProperties != nullptr) delete [] out_pQueueFamilyProperties;
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>& pMemoryProperties)
{
    VkPhysicalDeviceMemoryProperties out_pMemoryProperties_value = {};
    VkPhysicalDeviceMemoryProperties* out_pMemoryProperties = &out_pMemoryProperties_value;

    vkGetPhysicalDeviceMemoryProperties(physicalDevice, out_pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkCreateDevice(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkDeviceCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDevice>&             pDevice)
{
    const VkDeviceCreateInfo* in_pCreateInfo = reinterpret_cast<const VkDeviceCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDevice out_pDevice_value = static_cast<VkDevice>(0);
    VkDevice* out_pDevice = &out_pDevice_value;

    vkCreateDevice(physicalDevice, in_pCreateInfo, in_pAllocator, out_pDevice);
}

void VulkanReplayConsumer::Process_vkDestroyDevice(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDevice(device, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetDeviceQueue(
    VkDevice                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    const PointerDecoder<VkQueue>&              pQueue)
{
    VkQueue out_pQueue_value = static_cast<VkQueue>(0);
    VkQueue* out_pQueue = &out_pQueue_value;

    vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, out_pQueue);
}

void VulkanReplayConsumer::Process_vkQueueSubmit(
    VkResult                                    returnValue,
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const StructPointerDecoder<Decoded_VkSubmitInfo>& pSubmits,
    VkFence                                     fence)
{
    const VkSubmitInfo* in_pSubmits = reinterpret_cast<const VkSubmitInfo*>(pSubmits.GetPointer());

    vkQueueSubmit(queue, submitCount, in_pSubmits, fence);
}

void VulkanReplayConsumer::Process_vkQueueWaitIdle(
    VkResult                                    returnValue,
    VkQueue                                     queue)
{
    vkQueueWaitIdle(queue);
}

void VulkanReplayConsumer::Process_vkDeviceWaitIdle(
    VkResult                                    returnValue,
    VkDevice                                    device)
{
    vkDeviceWaitIdle(device);
}

void VulkanReplayConsumer::Process_vkAllocateMemory(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDeviceMemory>&       pMemory)
{
    const VkMemoryAllocateInfo* in_pAllocateInfo = reinterpret_cast<const VkMemoryAllocateInfo*>(pAllocateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDeviceMemory out_pMemory_value = static_cast<VkDeviceMemory>(0);
    VkDeviceMemory* out_pMemory = &out_pMemory_value;

    vkAllocateMemory(device, in_pAllocateInfo, in_pAllocator, out_pMemory);
}

void VulkanReplayConsumer::Process_vkFreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkFreeMemory(device, memory, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkMapMemory(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    const PointerDecoder<uint64_t>&             ppData)
{
    void* out_ppData_value = nullptr;
    void** out_ppData = &out_ppData_value;

    vkMapMemory(device, memory, offset, size, flags, out_ppData);
}

void VulkanReplayConsumer::Process_vkUnmapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory)
{
    vkUnmapMemory(device, memory);
}

void VulkanReplayConsumer::Process_vkFlushMappedMemoryRanges(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges)
{
    const VkMappedMemoryRange* in_pMemoryRanges = reinterpret_cast<const VkMappedMemoryRange*>(pMemoryRanges.GetPointer());

    vkFlushMappedMemoryRanges(device, memoryRangeCount, in_pMemoryRanges);
}

void VulkanReplayConsumer::Process_vkInvalidateMappedMemoryRanges(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges)
{
    const VkMappedMemoryRange* in_pMemoryRanges = reinterpret_cast<const VkMappedMemoryRange*>(pMemoryRanges.GetPointer());

    vkInvalidateMappedMemoryRanges(device, memoryRangeCount, in_pMemoryRanges);
}

void VulkanReplayConsumer::Process_vkGetDeviceMemoryCommitment(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const PointerDecoder<VkDeviceSize>&         pCommittedMemoryInBytes)
{
    VkDeviceSize out_pCommittedMemoryInBytes_value = static_cast<VkDeviceSize>(0);
    VkDeviceSize* out_pCommittedMemoryInBytes = &out_pCommittedMemoryInBytes_value;

    vkGetDeviceMemoryCommitment(device, memory, out_pCommittedMemoryInBytes);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    vkBindBufferMemory(device, buffer, memory, memoryOffset);
}

void VulkanReplayConsumer::Process_vkBindImageMemory(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    vkBindImageMemory(device, image, memory, memoryOffset);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const StructPointerDecoder<Decoded_VkMemoryRequirements>& pMemoryRequirements)
{
    VkMemoryRequirements out_pMemoryRequirements_value = {};
    VkMemoryRequirements* out_pMemoryRequirements = &out_pMemoryRequirements_value;

    vkGetBufferMemoryRequirements(device, buffer, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    const StructPointerDecoder<Decoded_VkMemoryRequirements>& pMemoryRequirements)
{
    VkMemoryRequirements out_pMemoryRequirements_value = {};
    VkMemoryRequirements* out_pMemoryRequirements = &out_pMemoryRequirements_value;

    vkGetImageMemoryRequirements(device, image, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
    const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>& pSparseMemoryRequirements)
{
    uint32_t out_pSparseMemoryRequirementCount_value = pSparseMemoryRequirementCount.IsNull() ? static_cast<uint32_t>(0) : *(pSparseMemoryRequirementCount.GetPointer());
    uint32_t* out_pSparseMemoryRequirementCount = &out_pSparseMemoryRequirementCount_value;
    VkSparseImageMemoryRequirements* out_pSparseMemoryRequirements = pSparseMemoryRequirements.IsNull() ? nullptr : new VkSparseImageMemoryRequirements[out_pSparseMemoryRequirementCount_value];

    vkGetImageSparseMemoryRequirements(device, image, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (out_pSparseMemoryRequirements != nullptr) delete [] out_pSparseMemoryRequirements;
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkSparseImageFormatProperties>& pProperties)
{
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkSparseImageFormatProperties* out_pProperties = pProperties.IsNull() ? nullptr : new VkSparseImageFormatProperties[out_pPropertyCount_value];

    vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, out_pPropertyCount, out_pProperties);

    if (out_pProperties != nullptr) delete [] out_pProperties;
}

void VulkanReplayConsumer::Process_vkQueueBindSparse(
    VkResult                                    returnValue,
    VkQueue                                     queue,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindSparseInfo>& pBindInfo,
    VkFence                                     fence)
{
    const VkBindSparseInfo* in_pBindInfo = reinterpret_cast<const VkBindSparseInfo*>(pBindInfo.GetPointer());

    vkQueueBindSparse(queue, bindInfoCount, in_pBindInfo, fence);
}

void VulkanReplayConsumer::Process_vkCreateFence(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkFenceCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkFence>&              pFence)
{
    const VkFenceCreateInfo* in_pCreateInfo = reinterpret_cast<const VkFenceCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkFence out_pFence_value = static_cast<VkFence>(0);
    VkFence* out_pFence = &out_pFence_value;

    vkCreateFence(device, in_pCreateInfo, in_pAllocator, out_pFence);
}

void VulkanReplayConsumer::Process_vkDestroyFence(
    VkDevice                                    device,
    VkFence                                     fence,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyFence(device, fence, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkResetFences(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const PointerDecoder<VkFence>&              pFences)
{
    const VkFence* in_pFences = reinterpret_cast<const VkFence*>(pFences.GetPointer());

    vkResetFences(device, fenceCount, in_pFences);
}

void VulkanReplayConsumer::Process_vkGetFenceStatus(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkFence                                     fence)
{
    vkGetFenceStatus(device, fence);
}

void VulkanReplayConsumer::Process_vkWaitForFences(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const PointerDecoder<VkFence>&              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    const VkFence* in_pFences = reinterpret_cast<const VkFence*>(pFences.GetPointer());

    vkWaitForFences(device, fenceCount, in_pFences, waitAll, timeout);
}

void VulkanReplayConsumer::Process_vkCreateSemaphore(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSemaphore>&          pSemaphore)
{
    const VkSemaphoreCreateInfo* in_pCreateInfo = reinterpret_cast<const VkSemaphoreCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSemaphore out_pSemaphore_value = static_cast<VkSemaphore>(0);
    VkSemaphore* out_pSemaphore = &out_pSemaphore_value;

    vkCreateSemaphore(device, in_pCreateInfo, in_pAllocator, out_pSemaphore);
}

void VulkanReplayConsumer::Process_vkDestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroySemaphore(device, semaphore, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateEvent(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkEventCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkEvent>&              pEvent)
{
    const VkEventCreateInfo* in_pCreateInfo = reinterpret_cast<const VkEventCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkEvent out_pEvent_value = static_cast<VkEvent>(0);
    VkEvent* out_pEvent = &out_pEvent_value;

    vkCreateEvent(device, in_pCreateInfo, in_pAllocator, out_pEvent);
}

void VulkanReplayConsumer::Process_vkDestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyEvent(device, event, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetEventStatus(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkEvent                                     event)
{
    vkGetEventStatus(device, event);
}

void VulkanReplayConsumer::Process_vkSetEvent(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkEvent                                     event)
{
    vkSetEvent(device, event);
}

void VulkanReplayConsumer::Process_vkResetEvent(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkEvent                                     event)
{
    vkResetEvent(device, event);
}

void VulkanReplayConsumer::Process_vkCreateQueryPool(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkQueryPool>&          pQueryPool)
{
    const VkQueryPoolCreateInfo* in_pCreateInfo = reinterpret_cast<const VkQueryPoolCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkQueryPool out_pQueryPool_value = static_cast<VkQueryPool>(0);
    VkQueryPool* out_pQueryPool = &out_pQueryPool_value;

    vkCreateQueryPool(device, in_pCreateInfo, in_pAllocator, out_pQueryPool);
}

void VulkanReplayConsumer::Process_vkDestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyQueryPool(device, queryPool, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetQueryPoolResults(
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
    void* out_pData = pData.IsNull() ? nullptr : new uint8_t[dataSize];

    vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, out_pData, stride, flags);

    if (out_pData != nullptr) delete [] out_pData;
}

void VulkanReplayConsumer::Process_vkCreateBuffer(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkBufferCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkBuffer>&             pBuffer)
{
    const VkBufferCreateInfo* in_pCreateInfo = reinterpret_cast<const VkBufferCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkBuffer out_pBuffer_value = static_cast<VkBuffer>(0);
    VkBuffer* out_pBuffer = &out_pBuffer_value;

    vkCreateBuffer(device, in_pCreateInfo, in_pAllocator, out_pBuffer);
}

void VulkanReplayConsumer::Process_vkDestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyBuffer(device, buffer, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateBufferView(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkBufferViewCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkBufferView>&         pView)
{
    const VkBufferViewCreateInfo* in_pCreateInfo = reinterpret_cast<const VkBufferViewCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkBufferView out_pView_value = static_cast<VkBufferView>(0);
    VkBufferView* out_pView = &out_pView_value;

    vkCreateBufferView(device, in_pCreateInfo, in_pAllocator, out_pView);
}

void VulkanReplayConsumer::Process_vkDestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyBufferView(device, bufferView, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateImage(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImageCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkImage>&              pImage)
{
    const VkImageCreateInfo* in_pCreateInfo = reinterpret_cast<const VkImageCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkImage out_pImage_value = static_cast<VkImage>(0);
    VkImage* out_pImage = &out_pImage_value;

    vkCreateImage(device, in_pCreateInfo, in_pAllocator, out_pImage);
}

void VulkanReplayConsumer::Process_vkDestroyImage(
    VkDevice                                    device,
    VkImage                                     image,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyImage(device, image, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetImageSubresourceLayout(
    VkDevice                                    device,
    VkImage                                     image,
    const StructPointerDecoder<Decoded_VkImageSubresource>& pSubresource,
    const StructPointerDecoder<Decoded_VkSubresourceLayout>& pLayout)
{
    const VkImageSubresource* in_pSubresource = reinterpret_cast<const VkImageSubresource*>(pSubresource.GetPointer());
    VkSubresourceLayout out_pLayout_value = {};
    VkSubresourceLayout* out_pLayout = &out_pLayout_value;

    vkGetImageSubresourceLayout(device, image, in_pSubresource, out_pLayout);
}

void VulkanReplayConsumer::Process_vkCreateImageView(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImageViewCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkImageView>&          pView)
{
    const VkImageViewCreateInfo* in_pCreateInfo = reinterpret_cast<const VkImageViewCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkImageView out_pView_value = static_cast<VkImageView>(0);
    VkImageView* out_pView = &out_pView_value;

    vkCreateImageView(device, in_pCreateInfo, in_pAllocator, out_pView);
}

void VulkanReplayConsumer::Process_vkDestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyImageView(device, imageView, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateShaderModule(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkShaderModule>&       pShaderModule)
{
    const VkShaderModuleCreateInfo* in_pCreateInfo = reinterpret_cast<const VkShaderModuleCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkShaderModule out_pShaderModule_value = static_cast<VkShaderModule>(0);
    VkShaderModule* out_pShaderModule = &out_pShaderModule_value;

    vkCreateShaderModule(device, in_pCreateInfo, in_pAllocator, out_pShaderModule);
}

void VulkanReplayConsumer::Process_vkDestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyShaderModule(device, shaderModule, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreatePipelineCache(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkPipelineCache>&      pPipelineCache)
{
    const VkPipelineCacheCreateInfo* in_pCreateInfo = reinterpret_cast<const VkPipelineCacheCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkPipelineCache out_pPipelineCache_value = static_cast<VkPipelineCache>(0);
    VkPipelineCache* out_pPipelineCache = &out_pPipelineCache_value;

    vkCreatePipelineCache(device, in_pCreateInfo, in_pAllocator, out_pPipelineCache);
}

void VulkanReplayConsumer::Process_vkDestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyPipelineCache(device, pipelineCache, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetPipelineCacheData(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const PointerDecoder<size_t>&               pDataSize,
    const PointerDecoder<uint8_t>&              pData)
{
    size_t out_pDataSize_value = pDataSize.IsNull() ? static_cast<size_t>(0) : *(pDataSize.GetPointer());
    size_t* out_pDataSize = &out_pDataSize_value;
    void* out_pData = pData.IsNull() ? nullptr : new uint8_t[out_pDataSize_value];

    vkGetPipelineCacheData(device, pipelineCache, out_pDataSize, out_pData);

    if (out_pData != nullptr) delete [] out_pData;
}

void VulkanReplayConsumer::Process_vkMergePipelineCaches(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkPipelineCache                             dstCache,
    uint32_t                                    srcCacheCount,
    const PointerDecoder<VkPipelineCache>&      pSrcCaches)
{
    const VkPipelineCache* in_pSrcCaches = reinterpret_cast<const VkPipelineCache*>(pSrcCaches.GetPointer());

    vkMergePipelineCaches(device, dstCache, srcCacheCount, in_pSrcCaches);
}

void VulkanReplayConsumer::Process_vkCreateGraphicsPipelines(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>& pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkPipeline>&           pPipelines)
{
    const VkGraphicsPipelineCreateInfo* in_pCreateInfos = reinterpret_cast<const VkGraphicsPipelineCreateInfo*>(pCreateInfos.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkPipeline* out_pPipelines = pPipelines.IsNull() ? nullptr : new VkPipeline[createInfoCount];

    vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, in_pCreateInfos, in_pAllocator, out_pPipelines);

    if (out_pPipelines != nullptr) delete [] out_pPipelines;
}

void VulkanReplayConsumer::Process_vkCreateComputePipelines(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>& pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkPipeline>&           pPipelines)
{
    const VkComputePipelineCreateInfo* in_pCreateInfos = reinterpret_cast<const VkComputePipelineCreateInfo*>(pCreateInfos.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkPipeline* out_pPipelines = pPipelines.IsNull() ? nullptr : new VkPipeline[createInfoCount];

    vkCreateComputePipelines(device, pipelineCache, createInfoCount, in_pCreateInfos, in_pAllocator, out_pPipelines);

    if (out_pPipelines != nullptr) delete [] out_pPipelines;
}

void VulkanReplayConsumer::Process_vkDestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyPipeline(device, pipeline, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreatePipelineLayout(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkPipelineLayout>&     pPipelineLayout)
{
    const VkPipelineLayoutCreateInfo* in_pCreateInfo = reinterpret_cast<const VkPipelineLayoutCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkPipelineLayout out_pPipelineLayout_value = static_cast<VkPipelineLayout>(0);
    VkPipelineLayout* out_pPipelineLayout = &out_pPipelineLayout_value;

    vkCreatePipelineLayout(device, in_pCreateInfo, in_pAllocator, out_pPipelineLayout);
}

void VulkanReplayConsumer::Process_vkDestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyPipelineLayout(device, pipelineLayout, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateSampler(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSamplerCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSampler>&            pSampler)
{
    const VkSamplerCreateInfo* in_pCreateInfo = reinterpret_cast<const VkSamplerCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSampler out_pSampler_value = static_cast<VkSampler>(0);
    VkSampler* out_pSampler = &out_pSampler_value;

    vkCreateSampler(device, in_pCreateInfo, in_pAllocator, out_pSampler);
}

void VulkanReplayConsumer::Process_vkDestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroySampler(device, sampler, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorSetLayout(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDescriptorSetLayout>& pSetLayout)
{
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDescriptorSetLayout out_pSetLayout_value = static_cast<VkDescriptorSetLayout>(0);
    VkDescriptorSetLayout* out_pSetLayout = &out_pSetLayout_value;

    vkCreateDescriptorSetLayout(device, in_pCreateInfo, in_pAllocator, out_pSetLayout);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDescriptorSetLayout(device, descriptorSetLayout, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorPool(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDescriptorPool>&     pDescriptorPool)
{
    const VkDescriptorPoolCreateInfo* in_pCreateInfo = reinterpret_cast<const VkDescriptorPoolCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDescriptorPool out_pDescriptorPool_value = static_cast<VkDescriptorPool>(0);
    VkDescriptorPool* out_pDescriptorPool = &out_pDescriptorPool_value;

    vkCreateDescriptorPool(device, in_pCreateInfo, in_pAllocator, out_pDescriptorPool);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDescriptorPool(device, descriptorPool, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkResetDescriptorPool(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    vkResetDescriptorPool(device, descriptorPool, flags);
}

void VulkanReplayConsumer::Process_vkAllocateDescriptorSets(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>& pAllocateInfo,
    const PointerDecoder<VkDescriptorSet>&      pDescriptorSets)
{
    const VkDescriptorSetAllocateInfo* in_pAllocateInfo = reinterpret_cast<const VkDescriptorSetAllocateInfo*>(pAllocateInfo.GetPointer());
    VkDescriptorSet* out_pDescriptorSets = pDescriptorSets.IsNull() ? nullptr : new VkDescriptorSet[in_pAllocateInfo->descriptorSetCount];

    vkAllocateDescriptorSets(device, in_pAllocateInfo, out_pDescriptorSets);

    if (out_pDescriptorSets != nullptr) delete [] out_pDescriptorSets;
}

void VulkanReplayConsumer::Process_vkFreeDescriptorSets(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    const PointerDecoder<VkDescriptorSet>&      pDescriptorSets)
{
    const VkDescriptorSet* in_pDescriptorSets = reinterpret_cast<const VkDescriptorSet*>(pDescriptorSets.GetPointer());

    vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, in_pDescriptorSets);
}

void VulkanReplayConsumer::Process_vkUpdateDescriptorSets(
    VkDevice                                    device,
    uint32_t                                    descriptorWriteCount,
    const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    const StructPointerDecoder<Decoded_VkCopyDescriptorSet>& pDescriptorCopies)
{
    const VkWriteDescriptorSet* in_pDescriptorWrites = reinterpret_cast<const VkWriteDescriptorSet*>(pDescriptorWrites.GetPointer());
    const VkCopyDescriptorSet* in_pDescriptorCopies = reinterpret_cast<const VkCopyDescriptorSet*>(pDescriptorCopies.GetPointer());

    vkUpdateDescriptorSets(device, descriptorWriteCount, in_pDescriptorWrites, descriptorCopyCount, in_pDescriptorCopies);
}

void VulkanReplayConsumer::Process_vkCreateFramebuffer(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkFramebufferCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkFramebuffer>&        pFramebuffer)
{
    const VkFramebufferCreateInfo* in_pCreateInfo = reinterpret_cast<const VkFramebufferCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkFramebuffer out_pFramebuffer_value = static_cast<VkFramebuffer>(0);
    VkFramebuffer* out_pFramebuffer = &out_pFramebuffer_value;

    vkCreateFramebuffer(device, in_pCreateInfo, in_pAllocator, out_pFramebuffer);
}

void VulkanReplayConsumer::Process_vkDestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyFramebuffer(device, framebuffer, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateRenderPass(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkRenderPass>&         pRenderPass)
{
    const VkRenderPassCreateInfo* in_pCreateInfo = reinterpret_cast<const VkRenderPassCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkRenderPass out_pRenderPass_value = static_cast<VkRenderPass>(0);
    VkRenderPass* out_pRenderPass = &out_pRenderPass_value;

    vkCreateRenderPass(device, in_pCreateInfo, in_pAllocator, out_pRenderPass);
}

void VulkanReplayConsumer::Process_vkDestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyRenderPass(device, renderPass, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetRenderAreaGranularity(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const StructPointerDecoder<Decoded_VkExtent2D>& pGranularity)
{
    VkExtent2D out_pGranularity_value = {};
    VkExtent2D* out_pGranularity = &out_pGranularity_value;

    vkGetRenderAreaGranularity(device, renderPass, out_pGranularity);
}

void VulkanReplayConsumer::Process_vkCreateCommandPool(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkCommandPool>&        pCommandPool)
{
    const VkCommandPoolCreateInfo* in_pCreateInfo = reinterpret_cast<const VkCommandPoolCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkCommandPool out_pCommandPool_value = static_cast<VkCommandPool>(0);
    VkCommandPool* out_pCommandPool = &out_pCommandPool_value;

    vkCreateCommandPool(device, in_pCreateInfo, in_pAllocator, out_pCommandPool);
}

void VulkanReplayConsumer::Process_vkDestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyCommandPool(device, commandPool, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkResetCommandPool(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags)
{
    vkResetCommandPool(device, commandPool, flags);
}

void VulkanReplayConsumer::Process_vkAllocateCommandBuffers(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>& pAllocateInfo,
    const PointerDecoder<VkCommandBuffer>&      pCommandBuffers)
{
    const VkCommandBufferAllocateInfo* in_pAllocateInfo = reinterpret_cast<const VkCommandBufferAllocateInfo*>(pAllocateInfo.GetPointer());
    VkCommandBuffer* out_pCommandBuffers = pCommandBuffers.IsNull() ? nullptr : new VkCommandBuffer[in_pAllocateInfo->commandBufferCount];

    vkAllocateCommandBuffers(device, in_pAllocateInfo, out_pCommandBuffers);

    if (out_pCommandBuffers != nullptr) delete [] out_pCommandBuffers;
}

void VulkanReplayConsumer::Process_vkFreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    uint32_t                                    commandBufferCount,
    const PointerDecoder<VkCommandBuffer>&      pCommandBuffers)
{
    const VkCommandBuffer* in_pCommandBuffers = reinterpret_cast<const VkCommandBuffer*>(pCommandBuffers.GetPointer());

    vkFreeCommandBuffers(device, commandPool, commandBufferCount, in_pCommandBuffers);
}

void VulkanReplayConsumer::Process_vkBeginCommandBuffer(
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>& pBeginInfo)
{
    const VkCommandBufferBeginInfo* in_pBeginInfo = reinterpret_cast<const VkCommandBufferBeginInfo*>(pBeginInfo.GetPointer());

    vkBeginCommandBuffer(commandBuffer, in_pBeginInfo);
}

void VulkanReplayConsumer::Process_vkEndCommandBuffer(
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer)
{
    vkEndCommandBuffer(commandBuffer);
}

void VulkanReplayConsumer::Process_vkResetCommandBuffer(
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    vkResetCommandBuffer(commandBuffer, flags);
}

void VulkanReplayConsumer::Process_vkCmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline)
{
    vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}

void VulkanReplayConsumer::Process_vkCmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const StructPointerDecoder<Decoded_VkViewport>& pViewports)
{
    const VkViewport* in_pViewports = reinterpret_cast<const VkViewport*>(pViewports.GetPointer());

    vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, in_pViewports);
}

void VulkanReplayConsumer::Process_vkCmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const StructPointerDecoder<Decoded_VkRect2D>& pScissors)
{
    const VkRect2D* in_pScissors = reinterpret_cast<const VkRect2D*>(pScissors.GetPointer());

    vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, in_pScissors);
}

void VulkanReplayConsumer::Process_vkCmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth)
{
    vkCmdSetLineWidth(commandBuffer, lineWidth);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

void VulkanReplayConsumer::Process_vkCmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const PointerDecoder<float>&                blendConstants)
{
    const float* in_blendConstants = reinterpret_cast<const float*>(blendConstants.GetPointer());

    vkCmdSetBlendConstants(commandBuffer, in_blendConstants);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    vkCmdSetStencilReference(commandBuffer, faceMask, reference);
}

void VulkanReplayConsumer::Process_vkCmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const PointerDecoder<VkDescriptorSet>&      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const PointerDecoder<uint32_t>&             pDynamicOffsets)
{
    const VkDescriptorSet* in_pDescriptorSets = reinterpret_cast<const VkDescriptorSet*>(pDescriptorSets.GetPointer());
    const uint32_t* in_pDynamicOffsets = reinterpret_cast<const uint32_t*>(pDynamicOffsets.GetPointer());

    vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, in_pDescriptorSets, dynamicOffsetCount, in_pDynamicOffsets);
}

void VulkanReplayConsumer::Process_vkCmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}

void VulkanReplayConsumer::Process_vkCmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const PointerDecoder<VkBuffer>&             pBuffers,
    const PointerDecoder<VkDeviceSize>&         pOffsets)
{
    const VkBuffer* in_pBuffers = reinterpret_cast<const VkBuffer*>(pBuffers.GetPointer());
    const VkDeviceSize* in_pOffsets = reinterpret_cast<const VkDeviceSize*>(pOffsets.GetPointer());

    vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets);
}

void VulkanReplayConsumer::Process_vkCmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkCmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{
    vkCmdDispatchIndirect(commandBuffer, buffer, offset);
}

void VulkanReplayConsumer::Process_vkCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkBufferCopy>& pRegions)
{
    const VkBufferCopy* in_pRegions = reinterpret_cast<const VkBufferCopy*>(pRegions.GetPointer());

    vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkImageCopy>& pRegions)
{
    const VkImageCopy* in_pRegions = reinterpret_cast<const VkImageCopy*>(pRegions.GetPointer());

    vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkImageBlit>& pRegions,
    VkFilter                                    filter)
{
    const VkImageBlit* in_pRegions = reinterpret_cast<const VkImageBlit*>(pRegions.GetPointer());

    vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, in_pRegions, filter);
}

void VulkanReplayConsumer::Process_vkCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions)
{
    const VkBufferImageCopy* in_pRegions = reinterpret_cast<const VkBufferImageCopy*>(pRegions.GetPointer());

    vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions)
{
    const VkBufferImageCopy* in_pRegions = reinterpret_cast<const VkBufferImageCopy*>(pRegions.GetPointer());

    vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const PointerDecoder<uint8_t>&              pData)
{
    const void* in_pData = reinterpret_cast<const void*>(pData.GetPointer());

    vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, in_pData);
}

void VulkanReplayConsumer::Process_vkCmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}

void VulkanReplayConsumer::Process_vkCmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const StructPointerDecoder<Decoded_VkClearColorValue>& pColor,
    uint32_t                                    rangeCount,
    const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges)
{
    const VkClearColorValue* in_pColor = reinterpret_cast<const VkClearColorValue*>(pColor.GetPointer());
    const VkImageSubresourceRange* in_pRanges = reinterpret_cast<const VkImageSubresourceRange*>(pRanges.GetPointer());

    vkCmdClearColorImage(commandBuffer, image, imageLayout, in_pColor, rangeCount, in_pRanges);
}

void VulkanReplayConsumer::Process_vkCmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const StructPointerDecoder<Decoded_VkClearDepthStencilValue>& pDepthStencil,
    uint32_t                                    rangeCount,
    const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges)
{
    const VkClearDepthStencilValue* in_pDepthStencil = reinterpret_cast<const VkClearDepthStencilValue*>(pDepthStencil.GetPointer());
    const VkImageSubresourceRange* in_pRanges = reinterpret_cast<const VkImageSubresourceRange*>(pRanges.GetPointer());

    vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, in_pDepthStencil, rangeCount, in_pRanges);
}

void VulkanReplayConsumer::Process_vkCmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const StructPointerDecoder<Decoded_VkClearAttachment>& pAttachments,
    uint32_t                                    rectCount,
    const StructPointerDecoder<Decoded_VkClearRect>& pRects)
{
    const VkClearAttachment* in_pAttachments = reinterpret_cast<const VkClearAttachment*>(pAttachments.GetPointer());
    const VkClearRect* in_pRects = reinterpret_cast<const VkClearRect*>(pRects.GetPointer());

    vkCmdClearAttachments(commandBuffer, attachmentCount, in_pAttachments, rectCount, in_pRects);
}

void VulkanReplayConsumer::Process_vkCmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkImageResolve>& pRegions)
{
    const VkImageResolve* in_pRegions = reinterpret_cast<const VkImageResolve*>(pRegions.GetPointer());

    vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    vkCmdSetEvent(commandBuffer, event, stageMask);
}

void VulkanReplayConsumer::Process_vkCmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    vkCmdResetEvent(commandBuffer, event, stageMask);
}

void VulkanReplayConsumer::Process_vkCmdWaitEvents(
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
    const VkEvent* in_pEvents = reinterpret_cast<const VkEvent*>(pEvents.GetPointer());
    const VkMemoryBarrier* in_pMemoryBarriers = reinterpret_cast<const VkMemoryBarrier*>(pMemoryBarriers.GetPointer());
    const VkBufferMemoryBarrier* in_pBufferMemoryBarriers = reinterpret_cast<const VkBufferMemoryBarrier*>(pBufferMemoryBarriers.GetPointer());
    const VkImageMemoryBarrier* in_pImageMemoryBarriers = reinterpret_cast<const VkImageMemoryBarrier*>(pImageMemoryBarriers.GetPointer());

    vkCmdWaitEvents(commandBuffer, eventCount, in_pEvents, srcStageMask, dstStageMask, memoryBarrierCount, in_pMemoryBarriers, bufferMemoryBarrierCount, in_pBufferMemoryBarriers, imageMemoryBarrierCount, in_pImageMemoryBarriers);
}

void VulkanReplayConsumer::Process_vkCmdPipelineBarrier(
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
    const VkMemoryBarrier* in_pMemoryBarriers = reinterpret_cast<const VkMemoryBarrier*>(pMemoryBarriers.GetPointer());
    const VkBufferMemoryBarrier* in_pBufferMemoryBarriers = reinterpret_cast<const VkBufferMemoryBarrier*>(pBufferMemoryBarriers.GetPointer());
    const VkImageMemoryBarrier* in_pImageMemoryBarriers = reinterpret_cast<const VkImageMemoryBarrier*>(pImageMemoryBarriers.GetPointer());

    vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, in_pMemoryBarriers, bufferMemoryBarrierCount, in_pBufferMemoryBarriers, imageMemoryBarrierCount, in_pImageMemoryBarriers);
}

void VulkanReplayConsumer::Process_vkCmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
}

void VulkanReplayConsumer::Process_vkCmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    vkCmdEndQuery(commandBuffer, queryPool, query);
}

void VulkanReplayConsumer::Process_vkCmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}

void VulkanReplayConsumer::Process_vkCmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}

void VulkanReplayConsumer::Process_vkCmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}

void VulkanReplayConsumer::Process_vkCmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const PointerDecoder<uint8_t>&              pValues)
{
    const void* in_pValues = reinterpret_cast<const void*>(pValues.GetPointer());

    vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, in_pValues);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
    VkSubpassContents                           contents)
{
    const VkRenderPassBeginInfo* in_pRenderPassBegin = reinterpret_cast<const VkRenderPassBeginInfo*>(pRenderPassBegin.GetPointer());

    vkCmdBeginRenderPass(commandBuffer, in_pRenderPassBegin, contents);
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents)
{
    vkCmdNextSubpass(commandBuffer, contents);
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass(
    VkCommandBuffer                             commandBuffer)
{
    vkCmdEndRenderPass(commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const PointerDecoder<VkCommandBuffer>&      pCommandBuffers)
{
    const VkCommandBuffer* in_pCommandBuffers = reinterpret_cast<const VkCommandBuffer*>(pCommandBuffers.GetPointer());

    vkCmdExecuteCommands(commandBuffer, commandBufferCount, in_pCommandBuffers);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory2(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos)
{
    const VkBindBufferMemoryInfo* in_pBindInfos = reinterpret_cast<const VkBindBufferMemoryInfo*>(pBindInfos.GetPointer());

    vkBindBufferMemory2(device, bindInfoCount, in_pBindInfos);
}

void VulkanReplayConsumer::Process_vkBindImageMemory2(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos)
{
    const VkBindImageMemoryInfo* in_pBindInfos = reinterpret_cast<const VkBindImageMemoryInfo*>(pBindInfos.GetPointer());

    vkBindImageMemory2(device, bindInfoCount, in_pBindInfos);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    const PointerDecoder<VkPeerMemoryFeatureFlags>& pPeerMemoryFeatures)
{
    VkPeerMemoryFeatureFlags out_pPeerMemoryFeatures_value = static_cast<VkPeerMemoryFeatureFlags>(0);
    VkPeerMemoryFeatureFlags* out_pPeerMemoryFeatures = &out_pPeerMemoryFeatures_value;

    vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, out_pPeerMemoryFeatures);
}

void VulkanReplayConsumer::Process_vkCmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    vkCmdSetDeviceMask(commandBuffer, deviceMask);
}

void VulkanReplayConsumer::Process_vkCmdDispatchBase(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const PointerDecoder<uint32_t>&             pPhysicalDeviceGroupCount,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>& pPhysicalDeviceGroupProperties)
{
    uint32_t out_pPhysicalDeviceGroupCount_value = pPhysicalDeviceGroupCount.IsNull() ? static_cast<uint32_t>(0) : *(pPhysicalDeviceGroupCount.GetPointer());
    uint32_t* out_pPhysicalDeviceGroupCount = &out_pPhysicalDeviceGroupCount_value;
    VkPhysicalDeviceGroupProperties* out_pPhysicalDeviceGroupProperties = pPhysicalDeviceGroupProperties.IsNull() ? nullptr : new VkPhysicalDeviceGroupProperties[out_pPhysicalDeviceGroupCount_value];

    vkEnumeratePhysicalDeviceGroups(instance, out_pPhysicalDeviceGroupCount, out_pPhysicalDeviceGroupProperties);

    if (out_pPhysicalDeviceGroupProperties != nullptr) delete [] out_pPhysicalDeviceGroupProperties;
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements2(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
    const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements)
{
    const VkImageMemoryRequirementsInfo2* in_pInfo = reinterpret_cast<const VkImageMemoryRequirementsInfo2*>(pInfo.GetPointer());
    VkMemoryRequirements2 out_pMemoryRequirements_value = {};
    VkMemoryRequirements2* out_pMemoryRequirements = &out_pMemoryRequirements_value;

    vkGetImageMemoryRequirements2(device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements2(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
    const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements)
{
    const VkBufferMemoryRequirementsInfo2* in_pInfo = reinterpret_cast<const VkBufferMemoryRequirementsInfo2*>(pInfo.GetPointer());
    VkMemoryRequirements2 out_pMemoryRequirements_value = {};
    VkMemoryRequirements2* out_pMemoryRequirements = &out_pMemoryRequirements_value;

    vkGetBufferMemoryRequirements2(device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements2(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
    const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
    const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>& pSparseMemoryRequirements)
{
    const VkImageSparseMemoryRequirementsInfo2* in_pInfo = reinterpret_cast<const VkImageSparseMemoryRequirementsInfo2*>(pInfo.GetPointer());
    uint32_t out_pSparseMemoryRequirementCount_value = pSparseMemoryRequirementCount.IsNull() ? static_cast<uint32_t>(0) : *(pSparseMemoryRequirementCount.GetPointer());
    uint32_t* out_pSparseMemoryRequirementCount = &out_pSparseMemoryRequirementCount_value;
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements.IsNull() ? nullptr : new VkSparseImageMemoryRequirements2[out_pSparseMemoryRequirementCount_value];

    vkGetImageSparseMemoryRequirements2(device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (out_pSparseMemoryRequirements != nullptr) delete [] out_pSparseMemoryRequirements;
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures2(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>& pFeatures)
{
    VkPhysicalDeviceFeatures2 out_pFeatures_value = {};
    VkPhysicalDeviceFeatures2* out_pFeatures = &out_pFeatures_value;

    vkGetPhysicalDeviceFeatures2(physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties2(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>& pProperties)
{
    VkPhysicalDeviceProperties2 out_pProperties_value = {};
    VkPhysicalDeviceProperties2* out_pProperties = &out_pProperties_value;

    vkGetPhysicalDeviceProperties2(physicalDevice, out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    const StructPointerDecoder<Decoded_VkFormatProperties2>& pFormatProperties)
{
    VkFormatProperties2 out_pFormatProperties_value = {};
    VkFormatProperties2* out_pFormatProperties = &out_pFormatProperties_value;

    vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
    const StructPointerDecoder<Decoded_VkImageFormatProperties2>& pImageFormatProperties)
{
    const VkPhysicalDeviceImageFormatInfo2* in_pImageFormatInfo = reinterpret_cast<const VkPhysicalDeviceImageFormatInfo2*>(pImageFormatInfo.GetPointer());
    VkImageFormatProperties2 out_pImageFormatProperties_value = {};
    VkImageFormatProperties2* out_pImageFormatProperties = &out_pImageFormatProperties_value;

    vkGetPhysicalDeviceImageFormatProperties2(physicalDevice, in_pImageFormatInfo, out_pImageFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
    const StructPointerDecoder<Decoded_VkQueueFamilyProperties2>& pQueueFamilyProperties)
{
    uint32_t out_pQueueFamilyPropertyCount_value = pQueueFamilyPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pQueueFamilyPropertyCount.GetPointer());
    uint32_t* out_pQueueFamilyPropertyCount = &out_pQueueFamilyPropertyCount_value;
    VkQueueFamilyProperties2* out_pQueueFamilyProperties = pQueueFamilyProperties.IsNull() ? nullptr : new VkQueueFamilyProperties2[out_pQueueFamilyPropertyCount_value];

    vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);

    if (out_pQueueFamilyProperties != nullptr) delete [] out_pQueueFamilyProperties;
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>& pMemoryProperties)
{
    VkPhysicalDeviceMemoryProperties2 out_pMemoryProperties_value = {};
    VkPhysicalDeviceMemoryProperties2* out_pMemoryProperties = &out_pMemoryProperties_value;

    vkGetPhysicalDeviceMemoryProperties2(physicalDevice, out_pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>& pProperties)
{
    const VkPhysicalDeviceSparseImageFormatInfo2* in_pFormatInfo = reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2*>(pFormatInfo.GetPointer());
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkSparseImageFormatProperties2* out_pProperties = pProperties.IsNull() ? nullptr : new VkSparseImageFormatProperties2[out_pPropertyCount_value];

    vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, in_pFormatInfo, out_pPropertyCount, out_pProperties);

    if (out_pProperties != nullptr) delete [] out_pProperties;
}

void VulkanReplayConsumer::Process_vkTrimCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    vkTrimCommandPool(device, commandPool, flags);
}

void VulkanReplayConsumer::Process_vkGetDeviceQueue2(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDeviceQueueInfo2>& pQueueInfo,
    const PointerDecoder<VkQueue>&              pQueue)
{
    const VkDeviceQueueInfo2* in_pQueueInfo = reinterpret_cast<const VkDeviceQueueInfo2*>(pQueueInfo.GetPointer());
    VkQueue out_pQueue_value = static_cast<VkQueue>(0);
    VkQueue* out_pQueue = &out_pQueue_value;

    vkGetDeviceQueue2(device, in_pQueueInfo, out_pQueue);
}

void VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversion(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSamplerYcbcrConversion>& pYcbcrConversion)
{
    const VkSamplerYcbcrConversionCreateInfo* in_pCreateInfo = reinterpret_cast<const VkSamplerYcbcrConversionCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSamplerYcbcrConversion out_pYcbcrConversion_value = static_cast<VkSamplerYcbcrConversion>(0);
    VkSamplerYcbcrConversion* out_pYcbcrConversion = &out_pYcbcrConversion_value;

    vkCreateSamplerYcbcrConversion(device, in_pCreateInfo, in_pAllocator, out_pYcbcrConversion);
}

void VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversion(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroySamplerYcbcrConversion(device, ycbcrConversion, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplate(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDescriptorUpdateTemplate>& pDescriptorUpdateTemplate)
{
    const VkDescriptorUpdateTemplateCreateInfo* in_pCreateInfo = reinterpret_cast<const VkDescriptorUpdateTemplateCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDescriptorUpdateTemplate out_pDescriptorUpdateTemplate_value = static_cast<VkDescriptorUpdateTemplate>(0);
    VkDescriptorUpdateTemplate* out_pDescriptorUpdateTemplate = &out_pDescriptorUpdateTemplate_value;

    vkCreateDescriptorUpdateTemplate(device, in_pCreateInfo, in_pAllocator, out_pDescriptorUpdateTemplate);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkUpdateDescriptorSetWithTemplate(
    VkDevice                                    device,
    VkDescriptorSet                             descriptorSet,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    uint64_t                                    pData)
{
    const void* in_pData = nullptr;

    vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, in_pData);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
    const StructPointerDecoder<Decoded_VkExternalBufferProperties>& pExternalBufferProperties)
{
    const VkPhysicalDeviceExternalBufferInfo* in_pExternalBufferInfo = reinterpret_cast<const VkPhysicalDeviceExternalBufferInfo*>(pExternalBufferInfo.GetPointer());
    VkExternalBufferProperties out_pExternalBufferProperties_value = {};
    VkExternalBufferProperties* out_pExternalBufferProperties = &out_pExternalBufferProperties_value;

    vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, in_pExternalBufferInfo, out_pExternalBufferProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
    const StructPointerDecoder<Decoded_VkExternalFenceProperties>& pExternalFenceProperties)
{
    const VkPhysicalDeviceExternalFenceInfo* in_pExternalFenceInfo = reinterpret_cast<const VkPhysicalDeviceExternalFenceInfo*>(pExternalFenceInfo.GetPointer());
    VkExternalFenceProperties out_pExternalFenceProperties_value = {};
    VkExternalFenceProperties* out_pExternalFenceProperties = &out_pExternalFenceProperties_value;

    vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, in_pExternalFenceInfo, out_pExternalFenceProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
    const StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>& pExternalSemaphoreProperties)
{
    const VkPhysicalDeviceExternalSemaphoreInfo* in_pExternalSemaphoreInfo = reinterpret_cast<const VkPhysicalDeviceExternalSemaphoreInfo*>(pExternalSemaphoreInfo.GetPointer());
    VkExternalSemaphoreProperties out_pExternalSemaphoreProperties_value = {};
    VkExternalSemaphoreProperties* out_pExternalSemaphoreProperties = &out_pExternalSemaphoreProperties_value;

    vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, in_pExternalSemaphoreInfo, out_pExternalSemaphoreProperties);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutSupport(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>& pSupport)
{
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(pCreateInfo.GetPointer());
    VkDescriptorSetLayoutSupport out_pSupport_value = {};
    VkDescriptorSetLayoutSupport* out_pSupport = &out_pSupport_value;

    vkGetDescriptorSetLayoutSupport(device, in_pCreateInfo, out_pSupport);
}

void VulkanReplayConsumer::Process_vkDestroySurfaceKHR(
    VkInstance                                  instance,
    VkSurfaceKHR                                surface,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroySurfaceKHR(instance, surface, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    VkSurfaceKHR                                surface,
    const PointerDecoder<VkBool32>&             pSupported)
{
    VkBool32 out_pSupported_value = static_cast<VkBool32>(0);
    VkBool32* out_pSupported = &out_pSupported_value;

    vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, out_pSupported);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    const StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>& pSurfaceCapabilities)
{
    VkSurfaceCapabilitiesKHR out_pSurfaceCapabilities_value = {};
    VkSurfaceCapabilitiesKHR* out_pSurfaceCapabilities = &out_pSurfaceCapabilities_value;

    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, out_pSurfaceCapabilities);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    const PointerDecoder<uint32_t>&             pSurfaceFormatCount,
    const StructPointerDecoder<Decoded_VkSurfaceFormatKHR>& pSurfaceFormats)
{
    uint32_t out_pSurfaceFormatCount_value = pSurfaceFormatCount.IsNull() ? static_cast<uint32_t>(0) : *(pSurfaceFormatCount.GetPointer());
    uint32_t* out_pSurfaceFormatCount = &out_pSurfaceFormatCount_value;
    VkSurfaceFormatKHR* out_pSurfaceFormats = pSurfaceFormats.IsNull() ? nullptr : new VkSurfaceFormatKHR[out_pSurfaceFormatCount_value];

    vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, out_pSurfaceFormatCount, out_pSurfaceFormats);

    if (out_pSurfaceFormats != nullptr) delete [] out_pSurfaceFormats;
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    const PointerDecoder<uint32_t>&             pPresentModeCount,
    const PointerDecoder<VkPresentModeKHR>&     pPresentModes)
{
    uint32_t out_pPresentModeCount_value = pPresentModeCount.IsNull() ? static_cast<uint32_t>(0) : *(pPresentModeCount.GetPointer());
    uint32_t* out_pPresentModeCount = &out_pPresentModeCount_value;
    VkPresentModeKHR* out_pPresentModes = pPresentModes.IsNull() ? nullptr : new VkPresentModeKHR[out_pPresentModeCount_value];

    vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, out_pPresentModeCount, out_pPresentModes);

    if (out_pPresentModes != nullptr) delete [] out_pPresentModes;
}

void VulkanReplayConsumer::Process_vkCreateSwapchainKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSwapchainKHR>&       pSwapchain)
{
    const VkSwapchainCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkSwapchainCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSwapchainKHR out_pSwapchain_value = static_cast<VkSwapchainKHR>(0);
    VkSwapchainKHR* out_pSwapchain = &out_pSwapchain_value;

    vkCreateSwapchainKHR(device, in_pCreateInfo, in_pAllocator, out_pSwapchain);
}

void VulkanReplayConsumer::Process_vkDestroySwapchainKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroySwapchainKHR(device, swapchain, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetSwapchainImagesKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const PointerDecoder<uint32_t>&             pSwapchainImageCount,
    const PointerDecoder<VkImage>&              pSwapchainImages)
{
    uint32_t out_pSwapchainImageCount_value = pSwapchainImageCount.IsNull() ? static_cast<uint32_t>(0) : *(pSwapchainImageCount.GetPointer());
    uint32_t* out_pSwapchainImageCount = &out_pSwapchainImageCount_value;
    VkImage* out_pSwapchainImages = pSwapchainImages.IsNull() ? nullptr : new VkImage[out_pSwapchainImageCount_value];

    vkGetSwapchainImagesKHR(device, swapchain, out_pSwapchainImageCount, out_pSwapchainImages);

    if (out_pSwapchainImages != nullptr) delete [] out_pSwapchainImages;
}

void VulkanReplayConsumer::Process_vkAcquireNextImageKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    timeout,
    VkSemaphore                                 semaphore,
    VkFence                                     fence,
    const PointerDecoder<uint32_t>&             pImageIndex)
{
    uint32_t out_pImageIndex_value = static_cast<uint32_t>(0);
    uint32_t* out_pImageIndex = &out_pImageIndex_value;

    vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, out_pImageIndex);
}

void VulkanReplayConsumer::Process_vkQueuePresentKHR(
    VkResult                                    returnValue,
    VkQueue                                     queue,
    const StructPointerDecoder<Decoded_VkPresentInfoKHR>& pPresentInfo)
{
    const VkPresentInfoKHR* in_pPresentInfo = reinterpret_cast<const VkPresentInfoKHR*>(pPresentInfo.GetPointer());

    vkQueuePresentKHR(queue, in_pPresentInfo);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>& pDeviceGroupPresentCapabilities)
{
    VkDeviceGroupPresentCapabilitiesKHR out_pDeviceGroupPresentCapabilities_value = {};
    VkDeviceGroupPresentCapabilitiesKHR* out_pDeviceGroupPresentCapabilities = &out_pDeviceGroupPresentCapabilities_value;

    vkGetDeviceGroupPresentCapabilitiesKHR(device, out_pDeviceGroupPresentCapabilities);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSurfaceKHR                                surface,
    const PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>& pModes)
{
    VkDeviceGroupPresentModeFlagsKHR out_pModes_value = static_cast<VkDeviceGroupPresentModeFlagsKHR>(0);
    VkDeviceGroupPresentModeFlagsKHR* out_pModes = &out_pModes_value;

    vkGetDeviceGroupSurfacePresentModesKHR(device, surface, out_pModes);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    const PointerDecoder<uint32_t>&             pRectCount,
    const StructPointerDecoder<Decoded_VkRect2D>& pRects)
{
    uint32_t out_pRectCount_value = pRectCount.IsNull() ? static_cast<uint32_t>(0) : *(pRectCount.GetPointer());
    uint32_t* out_pRectCount = &out_pRectCount_value;
    VkRect2D* out_pRects = pRects.IsNull() ? nullptr : new VkRect2D[out_pRectCount_value];

    vkGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, out_pRectCount, out_pRects);

    if (out_pRects != nullptr) delete [] out_pRects;
}

void VulkanReplayConsumer::Process_vkAcquireNextImage2KHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>& pAcquireInfo,
    const PointerDecoder<uint32_t>&             pImageIndex)
{
    const VkAcquireNextImageInfoKHR* in_pAcquireInfo = reinterpret_cast<const VkAcquireNextImageInfoKHR*>(pAcquireInfo.GetPointer());
    uint32_t out_pImageIndex_value = static_cast<uint32_t>(0);
    uint32_t* out_pImageIndex = &out_pImageIndex_value;

    vkAcquireNextImage2KHR(device, in_pAcquireInfo, out_pImageIndex);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>& pProperties)
{
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkDisplayPropertiesKHR* out_pProperties = pProperties.IsNull() ? nullptr : new VkDisplayPropertiesKHR[out_pPropertyCount_value];

    vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, out_pPropertyCount, out_pProperties);

    if (out_pProperties != nullptr) delete [] out_pProperties;
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>& pProperties)
{
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkDisplayPlanePropertiesKHR* out_pProperties = pProperties.IsNull() ? nullptr : new VkDisplayPlanePropertiesKHR[out_pPropertyCount_value];

    vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, out_pPropertyCount, out_pProperties);

    if (out_pProperties != nullptr) delete [] out_pProperties;
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    planeIndex,
    const PointerDecoder<uint32_t>&             pDisplayCount,
    const PointerDecoder<VkDisplayKHR>&         pDisplays)
{
    uint32_t out_pDisplayCount_value = pDisplayCount.IsNull() ? static_cast<uint32_t>(0) : *(pDisplayCount.GetPointer());
    uint32_t* out_pDisplayCount = &out_pDisplayCount_value;
    VkDisplayKHR* out_pDisplays = pDisplays.IsNull() ? nullptr : new VkDisplayKHR[out_pDisplayCount_value];

    vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, out_pDisplayCount, out_pDisplays);

    if (out_pDisplays != nullptr) delete [] out_pDisplays;
}

void VulkanReplayConsumer::Process_vkGetDisplayModePropertiesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>& pProperties)
{
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkDisplayModePropertiesKHR* out_pProperties = pProperties.IsNull() ? nullptr : new VkDisplayModePropertiesKHR[out_pPropertyCount_value];

    vkGetDisplayModePropertiesKHR(physicalDevice, display, out_pPropertyCount, out_pProperties);

    if (out_pProperties != nullptr) delete [] out_pProperties;
}

void VulkanReplayConsumer::Process_vkCreateDisplayModeKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDisplayModeKHR>&     pMode)
{
    const VkDisplayModeCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkDisplayModeCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDisplayModeKHR out_pMode_value = static_cast<VkDisplayModeKHR>(0);
    VkDisplayModeKHR* out_pMode = &out_pMode_value;

    vkCreateDisplayModeKHR(physicalDevice, display, in_pCreateInfo, in_pAllocator, out_pMode);
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayModeKHR                            mode,
    uint32_t                                    planeIndex,
    const StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>& pCapabilities)
{
    VkDisplayPlaneCapabilitiesKHR out_pCapabilities_value = {};
    VkDisplayPlaneCapabilitiesKHR* out_pCapabilities = &out_pCapabilities_value;

    vkGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, out_pCapabilities);
}

void VulkanReplayConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    const VkDisplaySurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkDisplaySurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateDisplayPlaneSurfaceKHR(instance, in_pCreateInfo, in_pAllocator, out_pSurface);
}

void VulkanReplayConsumer::Process_vkCreateSharedSwapchainsKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSwapchainKHR>&       pSwapchains)
{
    const VkSwapchainCreateInfoKHR* in_pCreateInfos = reinterpret_cast<const VkSwapchainCreateInfoKHR*>(pCreateInfos.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSwapchainKHR* out_pSwapchains = pSwapchains.IsNull() ? nullptr : new VkSwapchainKHR[swapchainCount];

    vkCreateSharedSwapchainsKHR(device, swapchainCount, in_pCreateInfos, in_pAllocator, out_pSwapchains);

    if (out_pSwapchains != nullptr) delete [] out_pSwapchains;
}

#ifdef VK_USE_PLATFORM_XLIB_KHR
void VulkanReplayConsumer::Process_vkCreateXlibSurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    const VkXlibSurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkXlibSurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateXlibSurfaceKHR(instance, in_pCreateInfo, in_pAllocator, out_pSurface);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    VkBool32                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    const PointerDecoder<Display>&              dpy,
    VisualID                                    visualID)
{
    Display out_dpy_value = static_cast<Display>(0);
    Display* out_dpy = &out_dpy_value;

    vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, out_dpy, visualID);
}
#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
void VulkanReplayConsumer::Process_vkCreateXcbSurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    const VkXcbSurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkXcbSurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateXcbSurfaceKHR(instance, in_pCreateInfo, in_pAllocator, out_pSurface);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    VkBool32                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    const PointerDecoder<xcb_connection_t>&     connection,
    xcb_visualid_t                              visual_id)
{
    xcb_connection_t out_connection_value = static_cast<xcb_connection_t>(0);
    xcb_connection_t* out_connection = &out_connection_value;

    vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, out_connection, visual_id);
}
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
void VulkanReplayConsumer::Process_vkCreateWaylandSurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    const VkWaylandSurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkWaylandSurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateWaylandSurfaceKHR(instance, in_pCreateInfo, in_pAllocator, out_pSurface);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    VkBool32                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    const PointerDecoder<wl_display>&           display)
{
    wl_display out_display_value = static_cast<wl_display>(0);
    struct wl_display* out_display = &out_display_value;

    vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, out_display);
}
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
void VulkanReplayConsumer::Process_vkCreateMirSurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkMirSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    const VkMirSurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkMirSurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateMirSurfaceKHR(instance, in_pCreateInfo, in_pAllocator, out_pSurface);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMirPresentationSupportKHR(
    VkBool32                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    const PointerDecoder<MirConnection>&        connection)
{
    MirConnection out_connection_value = static_cast<MirConnection>(0);
    MirConnection* out_connection = &out_connection_value;

    vkGetPhysicalDeviceMirPresentationSupportKHR(physicalDevice, queueFamilyIndex, out_connection);
}
#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
void VulkanReplayConsumer::Process_vkCreateAndroidSurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    const VkAndroidSurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkAndroidSurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateAndroidSurfaceKHR(instance, in_pCreateInfo, in_pAllocator, out_pSurface);
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanReplayConsumer::Process_vkCreateWin32SurfaceKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    const VkWin32SurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkWin32SurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateWin32SurfaceKHR(instance, in_pCreateInfo, in_pAllocator, out_pSurface);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    VkBool32                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>& pFeatures)
{
    VkPhysicalDeviceFeatures2 out_pFeatures_value = {};
    VkPhysicalDeviceFeatures2* out_pFeatures = &out_pFeatures_value;

    vkGetPhysicalDeviceFeatures2KHR(physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>& pProperties)
{
    VkPhysicalDeviceProperties2 out_pProperties_value = {};
    VkPhysicalDeviceProperties2* out_pProperties = &out_pProperties_value;

    vkGetPhysicalDeviceProperties2KHR(physicalDevice, out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    const StructPointerDecoder<Decoded_VkFormatProperties2>& pFormatProperties)
{
    VkFormatProperties2 out_pFormatProperties_value = {};
    VkFormatProperties2* out_pFormatProperties = &out_pFormatProperties_value;

    vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
    const StructPointerDecoder<Decoded_VkImageFormatProperties2>& pImageFormatProperties)
{
    const VkPhysicalDeviceImageFormatInfo2* in_pImageFormatInfo = reinterpret_cast<const VkPhysicalDeviceImageFormatInfo2*>(pImageFormatInfo.GetPointer());
    VkImageFormatProperties2 out_pImageFormatProperties_value = {};
    VkImageFormatProperties2* out_pImageFormatProperties = &out_pImageFormatProperties_value;

    vkGetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, in_pImageFormatInfo, out_pImageFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
    const StructPointerDecoder<Decoded_VkQueueFamilyProperties2>& pQueueFamilyProperties)
{
    uint32_t out_pQueueFamilyPropertyCount_value = pQueueFamilyPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pQueueFamilyPropertyCount.GetPointer());
    uint32_t* out_pQueueFamilyPropertyCount = &out_pQueueFamilyPropertyCount_value;
    VkQueueFamilyProperties2* out_pQueueFamilyProperties = pQueueFamilyProperties.IsNull() ? nullptr : new VkQueueFamilyProperties2[out_pQueueFamilyPropertyCount_value];

    vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);

    if (out_pQueueFamilyProperties != nullptr) delete [] out_pQueueFamilyProperties;
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>& pMemoryProperties)
{
    VkPhysicalDeviceMemoryProperties2 out_pMemoryProperties_value = {};
    VkPhysicalDeviceMemoryProperties2* out_pMemoryProperties = &out_pMemoryProperties_value;

    vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice, out_pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>& pProperties)
{
    const VkPhysicalDeviceSparseImageFormatInfo2* in_pFormatInfo = reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2*>(pFormatInfo.GetPointer());
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkSparseImageFormatProperties2* out_pProperties = pProperties.IsNull() ? nullptr : new VkSparseImageFormatProperties2[out_pPropertyCount_value];

    vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, in_pFormatInfo, out_pPropertyCount, out_pProperties);

    if (out_pProperties != nullptr) delete [] out_pProperties;
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    const PointerDecoder<VkPeerMemoryFeatureFlags>& pPeerMemoryFeatures)
{
    VkPeerMemoryFeatureFlags out_pPeerMemoryFeatures_value = static_cast<VkPeerMemoryFeatureFlags>(0);
    VkPeerMemoryFeatureFlags* out_pPeerMemoryFeatures = &out_pPeerMemoryFeatures_value;

    vkGetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, out_pPeerMemoryFeatures);
}

void VulkanReplayConsumer::Process_vkCmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    vkCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}

void VulkanReplayConsumer::Process_vkCmdDispatchBaseKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    vkCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkTrimCommandPoolKHR(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    vkTrimCommandPoolKHR(device, commandPool, flags);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const PointerDecoder<uint32_t>&             pPhysicalDeviceGroupCount,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>& pPhysicalDeviceGroupProperties)
{
    uint32_t out_pPhysicalDeviceGroupCount_value = pPhysicalDeviceGroupCount.IsNull() ? static_cast<uint32_t>(0) : *(pPhysicalDeviceGroupCount.GetPointer());
    uint32_t* out_pPhysicalDeviceGroupCount = &out_pPhysicalDeviceGroupCount_value;
    VkPhysicalDeviceGroupProperties* out_pPhysicalDeviceGroupProperties = pPhysicalDeviceGroupProperties.IsNull() ? nullptr : new VkPhysicalDeviceGroupProperties[out_pPhysicalDeviceGroupCount_value];

    vkEnumeratePhysicalDeviceGroupsKHR(instance, out_pPhysicalDeviceGroupCount, out_pPhysicalDeviceGroupProperties);

    if (out_pPhysicalDeviceGroupProperties != nullptr) delete [] out_pPhysicalDeviceGroupProperties;
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
    const StructPointerDecoder<Decoded_VkExternalBufferProperties>& pExternalBufferProperties)
{
    const VkPhysicalDeviceExternalBufferInfo* in_pExternalBufferInfo = reinterpret_cast<const VkPhysicalDeviceExternalBufferInfo*>(pExternalBufferInfo.GetPointer());
    VkExternalBufferProperties out_pExternalBufferProperties_value = {};
    VkExternalBufferProperties* out_pExternalBufferProperties = &out_pExternalBufferProperties_value;

    vkGetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, in_pExternalBufferInfo, out_pExternalBufferProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanReplayConsumer::Process_vkGetMemoryWin32HandleKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
    const PointerDecoder<HANDLE>&               pHandle)
{
    const VkMemoryGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = reinterpret_cast<const VkMemoryGetWin32HandleInfoKHR*>(pGetWin32HandleInfo.GetPointer());
    HANDLE out_pHandle_value = static_cast<HANDLE>(0);
    HANDLE* out_pHandle = &out_pHandle_value;

    vkGetMemoryWin32HandleKHR(device, in_pGetWin32HandleInfo, out_pHandle);
}

void VulkanReplayConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    HANDLE                                      handle,
    const StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>& pMemoryWin32HandleProperties)
{
    VkMemoryWin32HandlePropertiesKHR out_pMemoryWin32HandleProperties_value = {};
    VkMemoryWin32HandlePropertiesKHR* out_pMemoryWin32HandleProperties = &out_pMemoryWin32HandleProperties_value;

    vkGetMemoryWin32HandlePropertiesKHR(device, handleType, handle, out_pMemoryWin32HandleProperties);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void VulkanReplayConsumer::Process_vkGetMemoryFdKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>& pGetFdInfo,
    const PointerDecoder<int>&                  pFd)
{
    const VkMemoryGetFdInfoKHR* in_pGetFdInfo = reinterpret_cast<const VkMemoryGetFdInfoKHR*>(pGetFdInfo.GetPointer());
    int out_pFd_value = static_cast<int>(0);
    int* out_pFd = &out_pFd_value;

    vkGetMemoryFdKHR(device, in_pGetFdInfo, out_pFd);
}

void VulkanReplayConsumer::Process_vkGetMemoryFdPropertiesKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    const StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>& pMemoryFdProperties)
{
    VkMemoryFdPropertiesKHR out_pMemoryFdProperties_value = {};
    VkMemoryFdPropertiesKHR* out_pMemoryFdProperties = &out_pMemoryFdProperties_value;

    vkGetMemoryFdPropertiesKHR(device, handleType, fd, out_pMemoryFdProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
    const StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>& pExternalSemaphoreProperties)
{
    const VkPhysicalDeviceExternalSemaphoreInfo* in_pExternalSemaphoreInfo = reinterpret_cast<const VkPhysicalDeviceExternalSemaphoreInfo*>(pExternalSemaphoreInfo.GetPointer());
    VkExternalSemaphoreProperties out_pExternalSemaphoreProperties_value = {};
    VkExternalSemaphoreProperties* out_pExternalSemaphoreProperties = &out_pExternalSemaphoreProperties_value;

    vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, in_pExternalSemaphoreInfo, out_pExternalSemaphoreProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanReplayConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>& pImportSemaphoreWin32HandleInfo)
{
    const VkImportSemaphoreWin32HandleInfoKHR* in_pImportSemaphoreWin32HandleInfo = reinterpret_cast<const VkImportSemaphoreWin32HandleInfoKHR*>(pImportSemaphoreWin32HandleInfo.GetPointer());

    vkImportSemaphoreWin32HandleKHR(device, in_pImportSemaphoreWin32HandleInfo);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
    const PointerDecoder<HANDLE>&               pHandle)
{
    const VkSemaphoreGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = reinterpret_cast<const VkSemaphoreGetWin32HandleInfoKHR*>(pGetWin32HandleInfo.GetPointer());
    HANDLE out_pHandle_value = static_cast<HANDLE>(0);
    HANDLE* out_pHandle = &out_pHandle_value;

    vkGetSemaphoreWin32HandleKHR(device, in_pGetWin32HandleInfo, out_pHandle);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void VulkanReplayConsumer::Process_vkImportSemaphoreFdKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>& pImportSemaphoreFdInfo)
{
    const VkImportSemaphoreFdInfoKHR* in_pImportSemaphoreFdInfo = reinterpret_cast<const VkImportSemaphoreFdInfoKHR*>(pImportSemaphoreFdInfo.GetPointer());

    vkImportSemaphoreFdKHR(device, in_pImportSemaphoreFdInfo);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreFdKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>& pGetFdInfo,
    const PointerDecoder<int>&                  pFd)
{
    const VkSemaphoreGetFdInfoKHR* in_pGetFdInfo = reinterpret_cast<const VkSemaphoreGetFdInfoKHR*>(pGetFdInfo.GetPointer());
    int out_pFd_value = static_cast<int>(0);
    int* out_pFd = &out_pFd_value;

    vkGetSemaphoreFdKHR(device, in_pGetFdInfo, out_pFd);
}

void VulkanReplayConsumer::Process_vkCmdPushDescriptorSetKHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites)
{
    const VkWriteDescriptorSet* in_pDescriptorWrites = reinterpret_cast<const VkWriteDescriptorSet*>(pDescriptorWrites.GetPointer());

    vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, in_pDescriptorWrites);
}

void VulkanReplayConsumer::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    VkCommandBuffer                             commandBuffer,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint64_t                                    pData)
{
    const void* in_pData = nullptr;

    vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, in_pData);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDescriptorUpdateTemplate>& pDescriptorUpdateTemplate)
{
    const VkDescriptorUpdateTemplateCreateInfo* in_pCreateInfo = reinterpret_cast<const VkDescriptorUpdateTemplateCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDescriptorUpdateTemplate out_pDescriptorUpdateTemplate_value = static_cast<VkDescriptorUpdateTemplate>(0);
    VkDescriptorUpdateTemplate* out_pDescriptorUpdateTemplate = &out_pDescriptorUpdateTemplate_value;

    vkCreateDescriptorUpdateTemplateKHR(device, in_pCreateInfo, in_pAllocator, out_pDescriptorUpdateTemplate);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkUpdateDescriptorSetWithTemplateKHR(
    VkDevice                                    device,
    VkDescriptorSet                             descriptorSet,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    uint64_t                                    pData)
{
    const void* in_pData = nullptr;

    vkUpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, in_pData);
}

void VulkanReplayConsumer::Process_vkCreateRenderPass2KHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo2KHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkRenderPass>&         pRenderPass)
{
    const VkRenderPassCreateInfo2KHR* in_pCreateInfo = reinterpret_cast<const VkRenderPassCreateInfo2KHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkRenderPass out_pRenderPass_value = static_cast<VkRenderPass>(0);
    VkRenderPass* out_pRenderPass = &out_pRenderPass_value;

    vkCreateRenderPass2KHR(device, in_pCreateInfo, in_pAllocator, out_pRenderPass);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
    const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo)
{
    const VkRenderPassBeginInfo*      in_pRenderPassBegin = reinterpret_cast<const VkRenderPassBeginInfo*     >(pRenderPassBegin.GetPointer());
    const VkSubpassBeginInfoKHR*      in_pSubpassBeginInfo = reinterpret_cast<const VkSubpassBeginInfoKHR*     >(pSubpassBeginInfo.GetPointer());

    vkCmdBeginRenderPass2KHR(commandBuffer, in_pRenderPassBegin, in_pSubpassBeginInfo);
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo,
    const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo)
{
    const VkSubpassBeginInfoKHR*      in_pSubpassBeginInfo = reinterpret_cast<const VkSubpassBeginInfoKHR*     >(pSubpassBeginInfo.GetPointer());
    const VkSubpassEndInfoKHR*        in_pSubpassEndInfo = reinterpret_cast<const VkSubpassEndInfoKHR*       >(pSubpassEndInfo.GetPointer());

    vkCmdNextSubpass2KHR(commandBuffer, in_pSubpassBeginInfo, in_pSubpassEndInfo);
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo)
{
    const VkSubpassEndInfoKHR*        in_pSubpassEndInfo = reinterpret_cast<const VkSubpassEndInfoKHR*       >(pSubpassEndInfo.GetPointer());

    vkCmdEndRenderPass2KHR(commandBuffer, in_pSubpassEndInfo);
}

void VulkanReplayConsumer::Process_vkGetSwapchainStatusKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{
    vkGetSwapchainStatusKHR(device, swapchain);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
    const StructPointerDecoder<Decoded_VkExternalFenceProperties>& pExternalFenceProperties)
{
    const VkPhysicalDeviceExternalFenceInfo* in_pExternalFenceInfo = reinterpret_cast<const VkPhysicalDeviceExternalFenceInfo*>(pExternalFenceInfo.GetPointer());
    VkExternalFenceProperties out_pExternalFenceProperties_value = {};
    VkExternalFenceProperties* out_pExternalFenceProperties = &out_pExternalFenceProperties_value;

    vkGetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, in_pExternalFenceInfo, out_pExternalFenceProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanReplayConsumer::Process_vkImportFenceWin32HandleKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>& pImportFenceWin32HandleInfo)
{
    const VkImportFenceWin32HandleInfoKHR* in_pImportFenceWin32HandleInfo = reinterpret_cast<const VkImportFenceWin32HandleInfoKHR*>(pImportFenceWin32HandleInfo.GetPointer());

    vkImportFenceWin32HandleKHR(device, in_pImportFenceWin32HandleInfo);
}

void VulkanReplayConsumer::Process_vkGetFenceWin32HandleKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
    const PointerDecoder<HANDLE>&               pHandle)
{
    const VkFenceGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = reinterpret_cast<const VkFenceGetWin32HandleInfoKHR*>(pGetWin32HandleInfo.GetPointer());
    HANDLE out_pHandle_value = static_cast<HANDLE>(0);
    HANDLE* out_pHandle = &out_pHandle_value;

    vkGetFenceWin32HandleKHR(device, in_pGetWin32HandleInfo, out_pHandle);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void VulkanReplayConsumer::Process_vkImportFenceFdKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>& pImportFenceFdInfo)
{
    const VkImportFenceFdInfoKHR* in_pImportFenceFdInfo = reinterpret_cast<const VkImportFenceFdInfoKHR*>(pImportFenceFdInfo.GetPointer());

    vkImportFenceFdKHR(device, in_pImportFenceFdInfo);
}

void VulkanReplayConsumer::Process_vkGetFenceFdKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>& pGetFdInfo,
    const PointerDecoder<int>&                  pFd)
{
    const VkFenceGetFdInfoKHR* in_pGetFdInfo = reinterpret_cast<const VkFenceGetFdInfoKHR*>(pGetFdInfo.GetPointer());
    int out_pFd_value = static_cast<int>(0);
    int* out_pFd = &out_pFd_value;

    vkGetFenceFdKHR(device, in_pGetFdInfo, out_pFd);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
    const StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>& pSurfaceCapabilities)
{
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(pSurfaceInfo.GetPointer());
    VkSurfaceCapabilities2KHR out_pSurfaceCapabilities_value = {};
    VkSurfaceCapabilities2KHR* out_pSurfaceCapabilities = &out_pSurfaceCapabilities_value;

    vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, in_pSurfaceInfo, out_pSurfaceCapabilities);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
    const PointerDecoder<uint32_t>&             pSurfaceFormatCount,
    const StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>& pSurfaceFormats)
{
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(pSurfaceInfo.GetPointer());
    uint32_t out_pSurfaceFormatCount_value = pSurfaceFormatCount.IsNull() ? static_cast<uint32_t>(0) : *(pSurfaceFormatCount.GetPointer());
    uint32_t* out_pSurfaceFormatCount = &out_pSurfaceFormatCount_value;
    VkSurfaceFormat2KHR* out_pSurfaceFormats = pSurfaceFormats.IsNull() ? nullptr : new VkSurfaceFormat2KHR[out_pSurfaceFormatCount_value];

    vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, in_pSurfaceInfo, out_pSurfaceFormatCount, out_pSurfaceFormats);

    if (out_pSurfaceFormats != nullptr) delete [] out_pSurfaceFormats;
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayProperties2KHR>& pProperties)
{
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkDisplayProperties2KHR* out_pProperties = pProperties.IsNull() ? nullptr : new VkDisplayProperties2KHR[out_pPropertyCount_value];

    vkGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, out_pPropertyCount, out_pProperties);

    if (out_pProperties != nullptr) delete [] out_pProperties;
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>& pProperties)
{
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkDisplayPlaneProperties2KHR* out_pProperties = pProperties.IsNull() ? nullptr : new VkDisplayPlaneProperties2KHR[out_pPropertyCount_value];

    vkGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, out_pPropertyCount, out_pProperties);

    if (out_pProperties != nullptr) delete [] out_pProperties;
}

void VulkanReplayConsumer::Process_vkGetDisplayModeProperties2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>& pProperties)
{
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkDisplayModeProperties2KHR* out_pProperties = pProperties.IsNull() ? nullptr : new VkDisplayModeProperties2KHR[out_pPropertyCount_value];

    vkGetDisplayModeProperties2KHR(physicalDevice, display, out_pPropertyCount, out_pProperties);

    if (out_pProperties != nullptr) delete [] out_pProperties;
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>& pDisplayPlaneInfo,
    const StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>& pCapabilities)
{
    const VkDisplayPlaneInfo2KHR* in_pDisplayPlaneInfo = reinterpret_cast<const VkDisplayPlaneInfo2KHR*>(pDisplayPlaneInfo.GetPointer());
    VkDisplayPlaneCapabilities2KHR out_pCapabilities_value = {};
    VkDisplayPlaneCapabilities2KHR* out_pCapabilities = &out_pCapabilities_value;

    vkGetDisplayPlaneCapabilities2KHR(physicalDevice, in_pDisplayPlaneInfo, out_pCapabilities);
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements2KHR(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
    const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements)
{
    const VkImageMemoryRequirementsInfo2* in_pInfo = reinterpret_cast<const VkImageMemoryRequirementsInfo2*>(pInfo.GetPointer());
    VkMemoryRequirements2 out_pMemoryRequirements_value = {};
    VkMemoryRequirements2* out_pMemoryRequirements = &out_pMemoryRequirements_value;

    vkGetImageMemoryRequirements2KHR(device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
    const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements)
{
    const VkBufferMemoryRequirementsInfo2* in_pInfo = reinterpret_cast<const VkBufferMemoryRequirementsInfo2*>(pInfo.GetPointer());
    VkMemoryRequirements2 out_pMemoryRequirements_value = {};
    VkMemoryRequirements2* out_pMemoryRequirements = &out_pMemoryRequirements_value;

    vkGetBufferMemoryRequirements2KHR(device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
    const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
    const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>& pSparseMemoryRequirements)
{
    const VkImageSparseMemoryRequirementsInfo2* in_pInfo = reinterpret_cast<const VkImageSparseMemoryRequirementsInfo2*>(pInfo.GetPointer());
    uint32_t out_pSparseMemoryRequirementCount_value = pSparseMemoryRequirementCount.IsNull() ? static_cast<uint32_t>(0) : *(pSparseMemoryRequirementCount.GetPointer());
    uint32_t* out_pSparseMemoryRequirementCount = &out_pSparseMemoryRequirementCount_value;
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements.IsNull() ? nullptr : new VkSparseImageMemoryRequirements2[out_pSparseMemoryRequirementCount_value];

    vkGetImageSparseMemoryRequirements2KHR(device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (out_pSparseMemoryRequirements != nullptr) delete [] out_pSparseMemoryRequirements;
}

void VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSamplerYcbcrConversion>& pYcbcrConversion)
{
    const VkSamplerYcbcrConversionCreateInfo* in_pCreateInfo = reinterpret_cast<const VkSamplerYcbcrConversionCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSamplerYcbcrConversion out_pYcbcrConversion_value = static_cast<VkSamplerYcbcrConversion>(0);
    VkSamplerYcbcrConversion* out_pYcbcrConversion = &out_pYcbcrConversion_value;

    vkCreateSamplerYcbcrConversionKHR(device, in_pCreateInfo, in_pAllocator, out_pYcbcrConversion);
}

void VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroySamplerYcbcrConversionKHR(device, ycbcrConversion, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory2KHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos)
{
    const VkBindBufferMemoryInfo* in_pBindInfos = reinterpret_cast<const VkBindBufferMemoryInfo*>(pBindInfos.GetPointer());

    vkBindBufferMemory2KHR(device, bindInfoCount, in_pBindInfos);
}

void VulkanReplayConsumer::Process_vkBindImageMemory2KHR(
    VkResult                                    returnValue,
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos)
{
    const VkBindImageMemoryInfo* in_pBindInfos = reinterpret_cast<const VkBindImageMemoryInfo*>(pBindInfos.GetPointer());

    vkBindImageMemory2KHR(device, bindInfoCount, in_pBindInfos);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>& pSupport)
{
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(pCreateInfo.GetPointer());
    VkDescriptorSetLayoutSupport out_pSupport_value = {};
    VkDescriptorSetLayoutSupport* out_pSupport = &out_pSupport_value;

    vkGetDescriptorSetLayoutSupportKHR(device, in_pCreateInfo, out_pSupport);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    vkCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    vkCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCreateDebugReportCallbackEXT(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDebugReportCallbackEXT>& pCallback)
{
    const VkDebugReportCallbackCreateInfoEXT* in_pCreateInfo = reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDebugReportCallbackEXT out_pCallback_value = static_cast<VkDebugReportCallbackEXT>(0);
    VkDebugReportCallbackEXT* out_pCallback = &out_pCallback_value;

    vkCreateDebugReportCallbackEXT(instance, in_pCreateInfo, in_pAllocator, out_pCallback);
}

void VulkanReplayConsumer::Process_vkDestroyDebugReportCallbackEXT(
    VkInstance                                  instance,
    VkDebugReportCallbackEXT                    callback,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDebugReportCallbackEXT(instance, callback, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkDebugReportMessageEXT(
    VkInstance                                  instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    const StringDecoder&                        pLayerPrefix,
    const StringDecoder&                        pMessage)
{
    const char* in_pLayerPrefix = reinterpret_cast<const char*>(pLayerPrefix.GetPointer());
    const char* in_pMessage = reinterpret_cast<const char*>(pMessage.GetPointer());

    vkDebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, in_pLayerPrefix, in_pMessage);
}

void VulkanReplayConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>& pTagInfo)
{
    const VkDebugMarkerObjectTagInfoEXT* in_pTagInfo = reinterpret_cast<const VkDebugMarkerObjectTagInfoEXT*>(pTagInfo.GetPointer());

    vkDebugMarkerSetObjectTagEXT(device, in_pTagInfo);
}

void VulkanReplayConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>& pNameInfo)
{
    const VkDebugMarkerObjectNameInfoEXT* in_pNameInfo = reinterpret_cast<const VkDebugMarkerObjectNameInfoEXT*>(pNameInfo.GetPointer());

    vkDebugMarkerSetObjectNameEXT(device, in_pNameInfo);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo)
{
    const VkDebugMarkerMarkerInfoEXT* in_pMarkerInfo = reinterpret_cast<const VkDebugMarkerMarkerInfoEXT*>(pMarkerInfo.GetPointer());

    vkCmdDebugMarkerBeginEXT(commandBuffer, in_pMarkerInfo);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer)
{
    vkCmdDebugMarkerEndEXT(commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo)
{
    const VkDebugMarkerMarkerInfoEXT* in_pMarkerInfo = reinterpret_cast<const VkDebugMarkerMarkerInfoEXT*>(pMarkerInfo.GetPointer());

    vkCmdDebugMarkerInsertEXT(commandBuffer, in_pMarkerInfo);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    vkCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    vkCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkGetShaderInfoAMD(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    const PointerDecoder<size_t>&               pInfoSize,
    const PointerDecoder<uint8_t>&              pInfo)
{
    size_t out_pInfoSize_value = pInfoSize.IsNull() ? static_cast<size_t>(0) : *(pInfoSize.GetPointer());
    size_t* out_pInfoSize = &out_pInfoSize_value;
    void* out_pInfo = pInfo.IsNull() ? nullptr : new uint8_t[out_pInfoSize_value];

    vkGetShaderInfoAMD(device, pipeline, shaderStage, infoType, out_pInfoSize, out_pInfo);

    if (out_pInfo != nullptr) delete [] out_pInfo;
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
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
    VkExternalImageFormatPropertiesNV out_pExternalImageFormatProperties_value = {};
    VkExternalImageFormatPropertiesNV* out_pExternalImageFormatProperties = &out_pExternalImageFormatProperties_value;

    vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, out_pExternalImageFormatProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanReplayConsumer::Process_vkGetMemoryWin32HandleNV(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    const PointerDecoder<HANDLE>&               pHandle)
{
    HANDLE out_pHandle_value = static_cast<HANDLE>(0);
    HANDLE* out_pHandle = &out_pHandle_value;

    vkGetMemoryWin32HandleNV(device, memory, handleType, out_pHandle);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_VI_NN
void VulkanReplayConsumer::Process_vkCreateViSurfaceNN(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    const VkViSurfaceCreateInfoNN* in_pCreateInfo = reinterpret_cast<const VkViSurfaceCreateInfoNN*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateViSurfaceNN(instance, in_pCreateInfo, in_pAllocator, out_pSurface);
}
#endif /* VK_USE_PLATFORM_VI_NN */

void VulkanReplayConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>& pConditionalRenderingBegin)
{
    const VkConditionalRenderingBeginInfoEXT* in_pConditionalRenderingBegin = reinterpret_cast<const VkConditionalRenderingBeginInfoEXT*>(pConditionalRenderingBegin.GetPointer());

    vkCmdBeginConditionalRenderingEXT(commandBuffer, in_pConditionalRenderingBegin);
}

void VulkanReplayConsumer::Process_vkCmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer)
{
    vkCmdEndConditionalRenderingEXT(commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdProcessCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkCmdProcessCommandsInfoNVX>& pProcessCommandsInfo)
{
    const VkCmdProcessCommandsInfoNVX* in_pProcessCommandsInfo = reinterpret_cast<const VkCmdProcessCommandsInfoNVX*>(pProcessCommandsInfo.GetPointer());

    vkCmdProcessCommandsNVX(commandBuffer, in_pProcessCommandsInfo);
}

void VulkanReplayConsumer::Process_vkCmdReserveSpaceForCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkCmdReserveSpaceForCommandsInfoNVX>& pReserveSpaceInfo)
{
    const VkCmdReserveSpaceForCommandsInfoNVX* in_pReserveSpaceInfo = reinterpret_cast<const VkCmdReserveSpaceForCommandsInfoNVX*>(pReserveSpaceInfo.GetPointer());

    vkCmdReserveSpaceForCommandsNVX(commandBuffer, in_pReserveSpaceInfo);
}

void VulkanReplayConsumer::Process_vkCreateIndirectCommandsLayoutNVX(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNVX>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkIndirectCommandsLayoutNVX>& pIndirectCommandsLayout)
{
    const VkIndirectCommandsLayoutCreateInfoNVX* in_pCreateInfo = reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoNVX*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkIndirectCommandsLayoutNVX out_pIndirectCommandsLayout_value = static_cast<VkIndirectCommandsLayoutNVX>(0);
    VkIndirectCommandsLayoutNVX* out_pIndirectCommandsLayout = &out_pIndirectCommandsLayout_value;

    vkCreateIndirectCommandsLayoutNVX(device, in_pCreateInfo, in_pAllocator, out_pIndirectCommandsLayout);
}

void VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutNVX(
    VkDevice                                    device,
    VkIndirectCommandsLayoutNVX                 indirectCommandsLayout,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyIndirectCommandsLayoutNVX(device, indirectCommandsLayout, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateObjectTableNVX(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkObjectTableCreateInfoNVX>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkObjectTableNVX>&     pObjectTable)
{
    const VkObjectTableCreateInfoNVX* in_pCreateInfo = reinterpret_cast<const VkObjectTableCreateInfoNVX*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkObjectTableNVX out_pObjectTable_value = static_cast<VkObjectTableNVX>(0);
    VkObjectTableNVX* out_pObjectTable = &out_pObjectTable_value;

    vkCreateObjectTableNVX(device, in_pCreateInfo, in_pAllocator, out_pObjectTable);
}

void VulkanReplayConsumer::Process_vkDestroyObjectTableNVX(
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyObjectTableNVX(device, objectTable, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkRegisterObjectsNVX(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    uint32_t                                    objectCount,
    const StructPointerDecoder<Decoded_VkObjectTableEntryNVX>& ppObjectTableEntries,
    const PointerDecoder<uint32_t>&             pObjectIndices)
{
    const VkObjectTableEntryNVX* const*    in_ppObjectTableEntries = reinterpret_cast<const VkObjectTableEntryNVX* const*   >(ppObjectTableEntries.GetPointer());
    const uint32_t* in_pObjectIndices = reinterpret_cast<const uint32_t*>(pObjectIndices.GetPointer());

    vkRegisterObjectsNVX(device, objectTable, objectCount, in_ppObjectTableEntries, in_pObjectIndices);
}

void VulkanReplayConsumer::Process_vkUnregisterObjectsNVX(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    uint32_t                                    objectCount,
    const PointerDecoder<VkObjectEntryTypeNVX>& pObjectEntryTypes,
    const PointerDecoder<uint32_t>&             pObjectIndices)
{
    const VkObjectEntryTypeNVX* in_pObjectEntryTypes = reinterpret_cast<const VkObjectEntryTypeNVX*>(pObjectEntryTypes.GetPointer());
    const uint32_t* in_pObjectIndices = reinterpret_cast<const uint32_t*>(pObjectIndices.GetPointer());

    vkUnregisterObjectsNVX(device, objectTable, objectCount, in_pObjectEntryTypes, in_pObjectIndices);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(
    VkPhysicalDevice                            physicalDevice,
    const StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsFeaturesNVX>& pFeatures,
    const StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsLimitsNVX>& pLimits)
{
    VkDeviceGeneratedCommandsFeaturesNVX out_pFeatures_value = {};
    VkDeviceGeneratedCommandsFeaturesNVX* out_pFeatures = &out_pFeatures_value;
    VkDeviceGeneratedCommandsLimitsNVX out_pLimits_value = {};
    VkDeviceGeneratedCommandsLimitsNVX* out_pLimits = &out_pLimits_value;

    vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice, out_pFeatures, out_pLimits);
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const StructPointerDecoder<Decoded_VkViewportWScalingNV>& pViewportWScalings)
{
    const VkViewportWScalingNV* in_pViewportWScalings = reinterpret_cast<const VkViewportWScalingNV*>(pViewportWScalings.GetPointer());

    vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, in_pViewportWScalings);
}

void VulkanReplayConsumer::Process_vkReleaseDisplayEXT(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display)
{
    vkReleaseDisplayEXT(physicalDevice, display);
}

#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
void VulkanReplayConsumer::Process_vkAcquireXlibDisplayEXT(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<Display>&              dpy,
    VkDisplayKHR                                display)
{
    Display out_dpy_value = static_cast<Display>(0);
    Display* out_dpy = &out_dpy_value;

    vkAcquireXlibDisplayEXT(physicalDevice, out_dpy, display);
}

void VulkanReplayConsumer::Process_vkGetRandROutputDisplayEXT(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    const PointerDecoder<Display>&              dpy,
    RROutput                                    rrOutput,
    const PointerDecoder<VkDisplayKHR>&         pDisplay)
{
    Display out_dpy_value = static_cast<Display>(0);
    Display* out_dpy = &out_dpy_value;
    VkDisplayKHR out_pDisplay_value = static_cast<VkDisplayKHR>(0);
    VkDisplayKHR* out_pDisplay = &out_pDisplay_value;

    vkGetRandROutputDisplayEXT(physicalDevice, out_dpy, rrOutput, out_pDisplay);
}
#endif /* VK_USE_PLATFORM_XLIB_XRANDR_EXT */

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    VkResult                                    returnValue,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    const StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>& pSurfaceCapabilities)
{
    VkSurfaceCapabilities2EXT out_pSurfaceCapabilities_value = {};
    VkSurfaceCapabilities2EXT* out_pSurfaceCapabilities = &out_pSurfaceCapabilities_value;

    vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, out_pSurfaceCapabilities);
}

void VulkanReplayConsumer::Process_vkDisplayPowerControlEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>& pDisplayPowerInfo)
{
    const VkDisplayPowerInfoEXT* in_pDisplayPowerInfo = reinterpret_cast<const VkDisplayPowerInfoEXT*>(pDisplayPowerInfo.GetPointer());

    vkDisplayPowerControlEXT(device, display, in_pDisplayPowerInfo);
}

void VulkanReplayConsumer::Process_vkRegisterDeviceEventEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>& pDeviceEventInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkFence>&              pFence)
{
    const VkDeviceEventInfoEXT* in_pDeviceEventInfo = reinterpret_cast<const VkDeviceEventInfoEXT*>(pDeviceEventInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkFence out_pFence_value = static_cast<VkFence>(0);
    VkFence* out_pFence = &out_pFence_value;

    vkRegisterDeviceEventEXT(device, in_pDeviceEventInfo, in_pAllocator, out_pFence);
}

void VulkanReplayConsumer::Process_vkRegisterDisplayEventEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>& pDisplayEventInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkFence>&              pFence)
{
    const VkDisplayEventInfoEXT* in_pDisplayEventInfo = reinterpret_cast<const VkDisplayEventInfoEXT*>(pDisplayEventInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkFence out_pFence_value = static_cast<VkFence>(0);
    VkFence* out_pFence = &out_pFence_value;

    vkRegisterDisplayEventEXT(device, display, in_pDisplayEventInfo, in_pAllocator, out_pFence);
}

void VulkanReplayConsumer::Process_vkGetSwapchainCounterEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    const PointerDecoder<uint64_t>&             pCounterValue)
{
    uint64_t out_pCounterValue_value = static_cast<uint64_t>(0);
    uint64_t* out_pCounterValue = &out_pCounterValue_value;

    vkGetSwapchainCounterEXT(device, swapchain, counter, out_pCounterValue);
}

void VulkanReplayConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>& pDisplayTimingProperties)
{
    VkRefreshCycleDurationGOOGLE out_pDisplayTimingProperties_value = {};
    VkRefreshCycleDurationGOOGLE* out_pDisplayTimingProperties = &out_pDisplayTimingProperties_value;

    vkGetRefreshCycleDurationGOOGLE(device, swapchain, out_pDisplayTimingProperties);
}

void VulkanReplayConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const PointerDecoder<uint32_t>&             pPresentationTimingCount,
    const StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>& pPresentationTimings)
{
    uint32_t out_pPresentationTimingCount_value = pPresentationTimingCount.IsNull() ? static_cast<uint32_t>(0) : *(pPresentationTimingCount.GetPointer());
    uint32_t* out_pPresentationTimingCount = &out_pPresentationTimingCount_value;
    VkPastPresentationTimingGOOGLE* out_pPresentationTimings = pPresentationTimings.IsNull() ? nullptr : new VkPastPresentationTimingGOOGLE[out_pPresentationTimingCount_value];

    vkGetPastPresentationTimingGOOGLE(device, swapchain, out_pPresentationTimingCount, out_pPresentationTimings);

    if (out_pPresentationTimings != nullptr) delete [] out_pPresentationTimings;
}

void VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const StructPointerDecoder<Decoded_VkRect2D>& pDiscardRectangles)
{
    const VkRect2D* in_pDiscardRectangles = reinterpret_cast<const VkRect2D*>(pDiscardRectangles.GetPointer());

    vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, in_pDiscardRectangles);
}

void VulkanReplayConsumer::Process_vkSetHdrMetadataEXT(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const PointerDecoder<VkSwapchainKHR>&       pSwapchains,
    const StructPointerDecoder<Decoded_VkHdrMetadataEXT>& pMetadata)
{
    const VkSwapchainKHR* in_pSwapchains = reinterpret_cast<const VkSwapchainKHR*>(pSwapchains.GetPointer());
    const VkHdrMetadataEXT* in_pMetadata = reinterpret_cast<const VkHdrMetadataEXT*>(pMetadata.GetPointer());

    vkSetHdrMetadataEXT(device, swapchainCount, in_pSwapchains, in_pMetadata);
}

#ifdef VK_USE_PLATFORM_IOS_MVK
void VulkanReplayConsumer::Process_vkCreateIOSSurfaceMVK(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    const VkIOSSurfaceCreateInfoMVK* in_pCreateInfo = reinterpret_cast<const VkIOSSurfaceCreateInfoMVK*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateIOSSurfaceMVK(instance, in_pCreateInfo, in_pAllocator, out_pSurface);
}
#endif /* VK_USE_PLATFORM_IOS_MVK */

#ifdef VK_USE_PLATFORM_MACOS_MVK
void VulkanReplayConsumer::Process_vkCreateMacOSSurfaceMVK(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkSurfaceKHR>&         pSurface)
{
    const VkMacOSSurfaceCreateInfoMVK* in_pCreateInfo = reinterpret_cast<const VkMacOSSurfaceCreateInfoMVK*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateMacOSSurfaceMVK(instance, in_pCreateInfo, in_pAllocator, out_pSurface);
}
#endif /* VK_USE_PLATFORM_MACOS_MVK */

void VulkanReplayConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>& pNameInfo)
{
    const VkDebugUtilsObjectNameInfoEXT* in_pNameInfo = reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(pNameInfo.GetPointer());

    vkSetDebugUtilsObjectNameEXT(device, in_pNameInfo);
}

void VulkanReplayConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>& pTagInfo)
{
    const VkDebugUtilsObjectTagInfoEXT* in_pTagInfo = reinterpret_cast<const VkDebugUtilsObjectTagInfoEXT*>(pTagInfo.GetPointer());

    vkSetDebugUtilsObjectTagEXT(device, in_pTagInfo);
}

void VulkanReplayConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    const VkDebugUtilsLabelEXT* in_pLabelInfo = reinterpret_cast<const VkDebugUtilsLabelEXT*>(pLabelInfo.GetPointer());

    vkQueueBeginDebugUtilsLabelEXT(queue, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    VkQueue                                     queue)
{
    vkQueueEndDebugUtilsLabelEXT(queue);
}

void VulkanReplayConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    const VkDebugUtilsLabelEXT* in_pLabelInfo = reinterpret_cast<const VkDebugUtilsLabelEXT*>(pLabelInfo.GetPointer());

    vkQueueInsertDebugUtilsLabelEXT(queue, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    const VkDebugUtilsLabelEXT* in_pLabelInfo = reinterpret_cast<const VkDebugUtilsLabelEXT*>(pLabelInfo.GetPointer());

    vkCmdBeginDebugUtilsLabelEXT(commandBuffer, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer)
{
    vkCmdEndDebugUtilsLabelEXT(commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    const VkDebugUtilsLabelEXT* in_pLabelInfo = reinterpret_cast<const VkDebugUtilsLabelEXT*>(pLabelInfo.GetPointer());

    vkCmdInsertDebugUtilsLabelEXT(commandBuffer, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    VkResult                                    returnValue,
    VkInstance                                  instance,
    const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkDebugUtilsMessengerEXT>& pMessenger)
{
    const VkDebugUtilsMessengerCreateInfoEXT* in_pCreateInfo = reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDebugUtilsMessengerEXT out_pMessenger_value = static_cast<VkDebugUtilsMessengerEXT>(0);
    VkDebugUtilsMessengerEXT* out_pMessenger = &out_pMessenger_value;

    vkCreateDebugUtilsMessengerEXT(instance, in_pCreateInfo, in_pAllocator, out_pMessenger);
}

void VulkanReplayConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessengerEXT                    messenger,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDebugUtilsMessengerEXT(instance, messenger, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>& pCallbackData)
{
    const VkDebugUtilsMessengerCallbackDataEXT* in_pCallbackData = reinterpret_cast<const VkDebugUtilsMessengerCallbackDataEXT*>(pCallbackData.GetPointer());

    vkSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, in_pCallbackData);
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
void VulkanReplayConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const PointerDecoder<AHardwareBuffer>&      buffer,
    const StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>& pProperties)
{
    const struct AHardwareBuffer* in_buffer = reinterpret_cast<const struct AHardwareBuffer*>(buffer.GetPointer());
    VkAndroidHardwareBufferPropertiesANDROID out_pProperties_value = {};
    VkAndroidHardwareBufferPropertiesANDROID* out_pProperties = &out_pProperties_value;

    vkGetAndroidHardwareBufferPropertiesANDROID(device, in_buffer, out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>& pInfo,
    const PointerDecoder<AHardwareBuffer>&      pBuffer)
{
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* in_pInfo = reinterpret_cast<const VkMemoryGetAndroidHardwareBufferInfoANDROID*>(pInfo.GetPointer());
    AHardwareBuffer out_pBuffer_value = static_cast<AHardwareBuffer>(0);
    struct AHardwareBuffer** out_pBuffer = &out_pBuffer_value;

    vkGetMemoryAndroidHardwareBufferANDROID(device, in_pInfo, out_pBuffer);
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

void VulkanReplayConsumer::Process_vkCmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>& pSampleLocationsInfo)
{
    const VkSampleLocationsInfoEXT* in_pSampleLocationsInfo = reinterpret_cast<const VkSampleLocationsInfoEXT*>(pSampleLocationsInfo.GetPointer());

    vkCmdSetSampleLocationsEXT(commandBuffer, in_pSampleLocationsInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    const StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>& pMultisampleProperties)
{
    VkMultisamplePropertiesEXT out_pMultisampleProperties_value = {};
    VkMultisamplePropertiesEXT* out_pMultisampleProperties = &out_pMultisampleProperties_value;

    vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, out_pMultisampleProperties);
}

void VulkanReplayConsumer::Process_vkCreateValidationCacheEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    const StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<VkValidationCacheEXT>& pValidationCache)
{
    const VkValidationCacheCreateInfoEXT* in_pCreateInfo = reinterpret_cast<const VkValidationCacheCreateInfoEXT*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkValidationCacheEXT out_pValidationCache_value = static_cast<VkValidationCacheEXT>(0);
    VkValidationCacheEXT* out_pValidationCache = &out_pValidationCache_value;

    vkCreateValidationCacheEXT(device, in_pCreateInfo, in_pAllocator, out_pValidationCache);
}

void VulkanReplayConsumer::Process_vkDestroyValidationCacheEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyValidationCacheEXT(device, validationCache, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkMergeValidationCachesEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkValidationCacheEXT                        dstCache,
    uint32_t                                    srcCacheCount,
    const PointerDecoder<VkValidationCacheEXT>& pSrcCaches)
{
    const VkValidationCacheEXT* in_pSrcCaches = reinterpret_cast<const VkValidationCacheEXT*>(pSrcCaches.GetPointer());

    vkMergeValidationCachesEXT(device, dstCache, srcCacheCount, in_pSrcCaches);
}

void VulkanReplayConsumer::Process_vkGetValidationCacheDataEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    const PointerDecoder<size_t>&               pDataSize,
    const PointerDecoder<uint8_t>&              pData)
{
    size_t out_pDataSize_value = pDataSize.IsNull() ? static_cast<size_t>(0) : *(pDataSize.GetPointer());
    size_t* out_pDataSize = &out_pDataSize_value;
    void* out_pData = pData.IsNull() ? nullptr : new uint8_t[out_pDataSize_value];

    vkGetValidationCacheDataEXT(device, validationCache, out_pDataSize, out_pData);

    if (out_pData != nullptr) delete [] out_pData;
}

void VulkanReplayConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    VkResult                                    returnValue,
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    const StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>& pMemoryHostPointerProperties)
{
    const void* in_pHostPointer = nullptr;
    VkMemoryHostPointerPropertiesEXT out_pMemoryHostPointerProperties_value = {};
    VkMemoryHostPointerPropertiesEXT* out_pMemoryHostPointerProperties = &out_pMemoryHostPointerProperties_value;

    vkGetMemoryHostPointerPropertiesEXT(device, handleType, in_pHostPointer, out_pMemoryHostPointerProperties);
}

void VulkanReplayConsumer::Process_vkCmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    vkCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}
