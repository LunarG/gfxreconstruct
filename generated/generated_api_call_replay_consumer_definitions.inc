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
    const PointerDecoder<HandleId>&             pInstance)
{
    const VkInstanceCreateInfo* in_pCreateInfo = reinterpret_cast<const VkInstanceCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkInstance out_pInstance_value = static_cast<VkInstance>(0);
    VkInstance* out_pInstance = &out_pInstance_value;

    vkCreateInstance(in_pCreateInfo, in_pAllocator, out_pInstance);

    AddHandles<VkInstance>(pInstance.GetPointer(), 1, out_pInstance, 1, &VulkanObjectMapper::AddVkInstance);
}

void VulkanReplayConsumer::Process_vkDestroyInstance(
    HandleId                                    instance,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyInstance(in_instance, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDevices(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const PointerDecoder<uint32_t>&             pPhysicalDeviceCount,
    const PointerDecoder<HandleId>&             pPhysicalDevices)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    uint32_t out_pPhysicalDeviceCount_value = pPhysicalDeviceCount.IsNull() ? static_cast<uint32_t>(0) : *(pPhysicalDeviceCount.GetPointer());
    uint32_t* out_pPhysicalDeviceCount = &out_pPhysicalDeviceCount_value;
    VkPhysicalDevice* out_pPhysicalDevices = pPhysicalDevices.IsNull() ? nullptr : AllocateArray<VkPhysicalDevice>(out_pPhysicalDeviceCount_value);

    vkEnumeratePhysicalDevices(in_instance, out_pPhysicalDeviceCount, out_pPhysicalDevices);

    AddHandles<VkPhysicalDevice>(pPhysicalDevices.GetPointer(), pPhysicalDevices.GetLength(), out_pPhysicalDevices, out_pPhysicalDeviceCount_value, &VulkanObjectMapper::AddVkPhysicalDevice);
    FreeArray<VkPhysicalDevice>(&out_pPhysicalDevices);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>& pFeatures)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkPhysicalDeviceFeatures out_pFeatures_value = {};
    VkPhysicalDeviceFeatures* out_pFeatures = &out_pFeatures_value;

    vkGetPhysicalDeviceFeatures(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    HandleId                                    physicalDevice,
    VkFormat                                    format,
    const StructPointerDecoder<Decoded_VkFormatProperties>& pFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkFormatProperties out_pFormatProperties_value = {};
    VkFormatProperties* out_pFormatProperties = &out_pFormatProperties_value;

    vkGetPhysicalDeviceFormatProperties(in_physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    const StructPointerDecoder<Decoded_VkImageFormatProperties>& pImageFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkImageFormatProperties out_pImageFormatProperties_value = {};
    VkImageFormatProperties* out_pImageFormatProperties = &out_pImageFormatProperties_value;

    vkGetPhysicalDeviceImageFormatProperties(in_physicalDevice, format, type, tiling, usage, flags, out_pImageFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>& pProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkPhysicalDeviceProperties out_pProperties_value = {};
    VkPhysicalDeviceProperties* out_pProperties = &out_pProperties_value;

    vkGetPhysicalDeviceProperties(in_physicalDevice, out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    HandleId                                    physicalDevice,
    const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
    const StructPointerDecoder<Decoded_VkQueueFamilyProperties>& pQueueFamilyProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    uint32_t out_pQueueFamilyPropertyCount_value = pQueueFamilyPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pQueueFamilyPropertyCount.GetPointer());
    uint32_t* out_pQueueFamilyPropertyCount = &out_pQueueFamilyPropertyCount_value;
    VkQueueFamilyProperties* out_pQueueFamilyProperties = pQueueFamilyProperties.IsNull() ? nullptr : AllocateArray<VkQueueFamilyProperties>(out_pQueueFamilyPropertyCount_value);

    vkGetPhysicalDeviceQueueFamilyProperties(in_physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);

    FreeArray<VkQueueFamilyProperties>(&out_pQueueFamilyProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>& pMemoryProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkPhysicalDeviceMemoryProperties out_pMemoryProperties_value = {};
    VkPhysicalDeviceMemoryProperties* out_pMemoryProperties = &out_pMemoryProperties_value;

    vkGetPhysicalDeviceMemoryProperties(in_physicalDevice, out_pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkCreateDevice(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkDeviceCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pDevice)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    const VkDeviceCreateInfo* in_pCreateInfo = reinterpret_cast<const VkDeviceCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDevice out_pDevice_value = static_cast<VkDevice>(0);
    VkDevice* out_pDevice = &out_pDevice_value;

    vkCreateDevice(in_physicalDevice, in_pCreateInfo, in_pAllocator, out_pDevice);

    AddHandles<VkDevice>(pDevice.GetPointer(), 1, out_pDevice, 1, &VulkanObjectMapper::AddVkDevice);
}

void VulkanReplayConsumer::Process_vkDestroyDevice(
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDevice(in_device, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetDeviceQueue(
    HandleId                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    const PointerDecoder<HandleId>&             pQueue)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkQueue out_pQueue_value = static_cast<VkQueue>(0);
    VkQueue* out_pQueue = &out_pQueue_value;

    vkGetDeviceQueue(in_device, queueFamilyIndex, queueIndex, out_pQueue);

    AddHandles<VkQueue>(pQueue.GetPointer(), 1, out_pQueue, 1, &VulkanObjectMapper::AddVkQueue);
}

void VulkanReplayConsumer::Process_vkQueueSubmit(
    VkResult                                    returnValue,
    HandleId                                    queue,
    uint32_t                                    submitCount,
    const StructPointerDecoder<Decoded_VkSubmitInfo>& pSubmits,
    HandleId                                    fence)
{
    VkQueue in_queue = object_mapper_.MapVkQueue(queue);
    VkSubmitInfo* in_pSubmits = reinterpret_cast<VkSubmitInfo*>(pSubmits.GetPointer());
    if (!pSubmits.IsNull())
    {
        const Decoded_VkSubmitInfo* in_pSubmits_wrapper = pSubmits.GetMetaStructPointer();
        assert(submitCount == pSubmits.GetLength());
        for (size_t i = 0; i < submitCount; ++i)
        {
            VkSemaphore* pWaitSemaphores_memory = AllocateArray<VkSemaphore>(in_pSubmits[i].waitSemaphoreCount);
            in_pSubmits[i].pWaitSemaphores = pWaitSemaphores_memory;
            MapHandles<VkSemaphore>(in_pSubmits_wrapper[i].pWaitSemaphores.GetPointer(), in_pSubmits_wrapper[i].pWaitSemaphores.GetLength(), pWaitSemaphores_memory, in_pSubmits[i].waitSemaphoreCount, &VulkanObjectMapper::MapVkSemaphore);
            VkCommandBuffer* pCommandBuffers_memory = AllocateArray<VkCommandBuffer>(in_pSubmits[i].commandBufferCount);
            in_pSubmits[i].pCommandBuffers = pCommandBuffers_memory;
            MapHandles<VkCommandBuffer>(in_pSubmits_wrapper[i].pCommandBuffers.GetPointer(), in_pSubmits_wrapper[i].pCommandBuffers.GetLength(), pCommandBuffers_memory, in_pSubmits[i].commandBufferCount, &VulkanObjectMapper::MapVkCommandBuffer);
            VkSemaphore* pSignalSemaphores_memory = AllocateArray<VkSemaphore>(in_pSubmits[i].signalSemaphoreCount);
            in_pSubmits[i].pSignalSemaphores = pSignalSemaphores_memory;
            MapHandles<VkSemaphore>(in_pSubmits_wrapper[i].pSignalSemaphores.GetPointer(), in_pSubmits_wrapper[i].pSignalSemaphores.GetLength(), pSignalSemaphores_memory, in_pSubmits[i].signalSemaphoreCount, &VulkanObjectMapper::MapVkSemaphore);
        }
    }
    VkFence in_fence = object_mapper_.MapVkFence(fence);

    vkQueueSubmit(in_queue, submitCount, in_pSubmits, in_fence);

    if (in_pSubmits != nullptr)
    {
        for (size_t i = 0; i < submitCount; ++i)
        {
            FreeArray<VkSemaphore>(&in_pSubmits[i].pWaitSemaphores);
            FreeArray<VkCommandBuffer>(&in_pSubmits[i].pCommandBuffers);
            FreeArray<VkSemaphore>(&in_pSubmits[i].pSignalSemaphores);
        }
    }
}

void VulkanReplayConsumer::Process_vkQueueWaitIdle(
    VkResult                                    returnValue,
    HandleId                                    queue)
{
    VkQueue in_queue = object_mapper_.MapVkQueue(queue);

    vkQueueWaitIdle(in_queue);
}

void VulkanReplayConsumer::Process_vkDeviceWaitIdle(
    VkResult                                    returnValue,
    HandleId                                    device)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);

    vkDeviceWaitIdle(in_device);
}

void VulkanReplayConsumer::Process_vkAllocateMemory(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pMemory)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkMemoryAllocateInfo* in_pAllocateInfo = reinterpret_cast<const VkMemoryAllocateInfo*>(pAllocateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDeviceMemory out_pMemory_value = static_cast<VkDeviceMemory>(0);
    VkDeviceMemory* out_pMemory = &out_pMemory_value;

    vkAllocateMemory(in_device, in_pAllocateInfo, in_pAllocator, out_pMemory);

    AddHandles<VkDeviceMemory>(pMemory.GetPointer(), 1, out_pMemory, 1, &VulkanObjectMapper::AddVkDeviceMemory);
}

void VulkanReplayConsumer::Process_vkFreeMemory(
    HandleId                                    device,
    HandleId                                    memory,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDeviceMemory in_memory = object_mapper_.MapVkDeviceMemory(memory);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkFreeMemory(in_device, in_memory, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkMapMemory(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    const PointerDecoder<uint64_t>&             ppData)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDeviceMemory in_memory = object_mapper_.MapVkDeviceMemory(memory);
    void* out_ppData_value = nullptr;
    void** out_ppData = &out_ppData_value;

    vkMapMemory(in_device, in_memory, offset, size, flags, out_ppData);
}

void VulkanReplayConsumer::Process_vkUnmapMemory(
    HandleId                                    device,
    HandleId                                    memory)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDeviceMemory in_memory = object_mapper_.MapVkDeviceMemory(memory);

    vkUnmapMemory(in_device, in_memory);
}

void VulkanReplayConsumer::Process_vkFlushMappedMemoryRanges(
    VkResult                                    returnValue,
    HandleId                                    device,
    uint32_t                                    memoryRangeCount,
    const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkMappedMemoryRange* in_pMemoryRanges = reinterpret_cast<VkMappedMemoryRange*>(pMemoryRanges.GetPointer());
    if (!pMemoryRanges.IsNull())
    {
        const Decoded_VkMappedMemoryRange* in_pMemoryRanges_wrapper = pMemoryRanges.GetMetaStructPointer();
        assert(memoryRangeCount == pMemoryRanges.GetLength());
        for (size_t i = 0; i < memoryRangeCount; ++i)
        {
            in_pMemoryRanges[i].memory = object_mapper_.MapVkDeviceMemory(in_pMemoryRanges_wrapper[i].memory);
        }
    }

    vkFlushMappedMemoryRanges(in_device, memoryRangeCount, in_pMemoryRanges);
}

void VulkanReplayConsumer::Process_vkInvalidateMappedMemoryRanges(
    VkResult                                    returnValue,
    HandleId                                    device,
    uint32_t                                    memoryRangeCount,
    const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkMappedMemoryRange* in_pMemoryRanges = reinterpret_cast<VkMappedMemoryRange*>(pMemoryRanges.GetPointer());
    if (!pMemoryRanges.IsNull())
    {
        const Decoded_VkMappedMemoryRange* in_pMemoryRanges_wrapper = pMemoryRanges.GetMetaStructPointer();
        assert(memoryRangeCount == pMemoryRanges.GetLength());
        for (size_t i = 0; i < memoryRangeCount; ++i)
        {
            in_pMemoryRanges[i].memory = object_mapper_.MapVkDeviceMemory(in_pMemoryRanges_wrapper[i].memory);
        }
    }

    vkInvalidateMappedMemoryRanges(in_device, memoryRangeCount, in_pMemoryRanges);
}

void VulkanReplayConsumer::Process_vkGetDeviceMemoryCommitment(
    HandleId                                    device,
    HandleId                                    memory,
    const PointerDecoder<VkDeviceSize>&         pCommittedMemoryInBytes)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDeviceMemory in_memory = object_mapper_.MapVkDeviceMemory(memory);
    VkDeviceSize out_pCommittedMemoryInBytes_value = static_cast<VkDeviceSize>(0);
    VkDeviceSize* out_pCommittedMemoryInBytes = &out_pCommittedMemoryInBytes_value;

    vkGetDeviceMemoryCommitment(in_device, in_memory, out_pCommittedMemoryInBytes);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    buffer,
    HandleId                                    memory,
    VkDeviceSize                                memoryOffset)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkBuffer in_buffer = object_mapper_.MapVkBuffer(buffer);
    VkDeviceMemory in_memory = object_mapper_.MapVkDeviceMemory(memory);

    vkBindBufferMemory(in_device, in_buffer, in_memory, memoryOffset);
}

void VulkanReplayConsumer::Process_vkBindImageMemory(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    image,
    HandleId                                    memory,
    VkDeviceSize                                memoryOffset)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImage in_image = object_mapper_.MapVkImage(image);
    VkDeviceMemory in_memory = object_mapper_.MapVkDeviceMemory(memory);

    vkBindImageMemory(in_device, in_image, in_memory, memoryOffset);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements(
    HandleId                                    device,
    HandleId                                    buffer,
    const StructPointerDecoder<Decoded_VkMemoryRequirements>& pMemoryRequirements)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkBuffer in_buffer = object_mapper_.MapVkBuffer(buffer);
    VkMemoryRequirements out_pMemoryRequirements_value = {};
    VkMemoryRequirements* out_pMemoryRequirements = &out_pMemoryRequirements_value;

    vkGetBufferMemoryRequirements(in_device, in_buffer, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements(
    HandleId                                    device,
    HandleId                                    image,
    const StructPointerDecoder<Decoded_VkMemoryRequirements>& pMemoryRequirements)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImage in_image = object_mapper_.MapVkImage(image);
    VkMemoryRequirements out_pMemoryRequirements_value = {};
    VkMemoryRequirements* out_pMemoryRequirements = &out_pMemoryRequirements_value;

    vkGetImageMemoryRequirements(in_device, in_image, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements(
    HandleId                                    device,
    HandleId                                    image,
    const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
    const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>& pSparseMemoryRequirements)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImage in_image = object_mapper_.MapVkImage(image);
    uint32_t out_pSparseMemoryRequirementCount_value = pSparseMemoryRequirementCount.IsNull() ? static_cast<uint32_t>(0) : *(pSparseMemoryRequirementCount.GetPointer());
    uint32_t* out_pSparseMemoryRequirementCount = &out_pSparseMemoryRequirementCount_value;
    VkSparseImageMemoryRequirements* out_pSparseMemoryRequirements = pSparseMemoryRequirements.IsNull() ? nullptr : AllocateArray<VkSparseImageMemoryRequirements>(out_pSparseMemoryRequirementCount_value);

    vkGetImageSparseMemoryRequirements(in_device, in_image, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    FreeArray<VkSparseImageMemoryRequirements>(&out_pSparseMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    HandleId                                    physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkSparseImageFormatProperties>& pProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkSparseImageFormatProperties* out_pProperties = pProperties.IsNull() ? nullptr : AllocateArray<VkSparseImageFormatProperties>(out_pPropertyCount_value);

    vkGetPhysicalDeviceSparseImageFormatProperties(in_physicalDevice, format, type, samples, usage, tiling, out_pPropertyCount, out_pProperties);

    FreeArray<VkSparseImageFormatProperties>(&out_pProperties);
}

void VulkanReplayConsumer::Process_vkQueueBindSparse(
    VkResult                                    returnValue,
    HandleId                                    queue,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindSparseInfo>& pBindInfo,
    HandleId                                    fence)
{
    VkQueue in_queue = object_mapper_.MapVkQueue(queue);
    VkBindSparseInfo* in_pBindInfo = reinterpret_cast<VkBindSparseInfo*>(pBindInfo.GetPointer());
    if (!pBindInfo.IsNull())
    {
        const Decoded_VkBindSparseInfo* in_pBindInfo_wrapper = pBindInfo.GetMetaStructPointer();
        assert(bindInfoCount == pBindInfo.GetLength());
        for (size_t i = 0; i < bindInfoCount; ++i)
        {
            VkSemaphore* pWaitSemaphores_memory = AllocateArray<VkSemaphore>(in_pBindInfo[i].waitSemaphoreCount);
            in_pBindInfo[i].pWaitSemaphores = pWaitSemaphores_memory;
            MapHandles<VkSemaphore>(in_pBindInfo_wrapper[i].pWaitSemaphores.GetPointer(), in_pBindInfo_wrapper[i].pWaitSemaphores.GetLength(), pWaitSemaphores_memory, in_pBindInfo[i].waitSemaphoreCount, &VulkanObjectMapper::MapVkSemaphore);
            VkSemaphore* pSignalSemaphores_memory = AllocateArray<VkSemaphore>(in_pBindInfo[i].signalSemaphoreCount);
            in_pBindInfo[i].pSignalSemaphores = pSignalSemaphores_memory;
            MapHandles<VkSemaphore>(in_pBindInfo_wrapper[i].pSignalSemaphores.GetPointer(), in_pBindInfo_wrapper[i].pSignalSemaphores.GetLength(), pSignalSemaphores_memory, in_pBindInfo[i].signalSemaphoreCount, &VulkanObjectMapper::MapVkSemaphore);
        }
    }
    VkFence in_fence = object_mapper_.MapVkFence(fence);

    vkQueueBindSparse(in_queue, bindInfoCount, in_pBindInfo, in_fence);

    if (in_pBindInfo != nullptr)
    {
        for (size_t i = 0; i < bindInfoCount; ++i)
        {
            FreeArray<VkSemaphore>(&in_pBindInfo[i].pWaitSemaphores);
            FreeArray<VkSemaphore>(&in_pBindInfo[i].pSignalSemaphores);
        }
    }
}

void VulkanReplayConsumer::Process_vkCreateFence(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkFenceCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pFence)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkFenceCreateInfo* in_pCreateInfo = reinterpret_cast<const VkFenceCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkFence out_pFence_value = static_cast<VkFence>(0);
    VkFence* out_pFence = &out_pFence_value;

    vkCreateFence(in_device, in_pCreateInfo, in_pAllocator, out_pFence);

    AddHandles<VkFence>(pFence.GetPointer(), 1, out_pFence, 1, &VulkanObjectMapper::AddVkFence);
}

void VulkanReplayConsumer::Process_vkDestroyFence(
    HandleId                                    device,
    HandleId                                    fence,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkFence in_fence = object_mapper_.MapVkFence(fence);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyFence(in_device, in_fence, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkResetFences(
    VkResult                                    returnValue,
    HandleId                                    device,
    uint32_t                                    fenceCount,
    const PointerDecoder<HandleId>&             pFences)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkFence* in_pFences = pFences.IsNull() ? nullptr : AllocateArray<VkFence>(fenceCount);
    MapHandles<VkFence>(pFences.GetPointer(), pFences.GetLength(), in_pFences, fenceCount, &VulkanObjectMapper::MapVkFence);

    vkResetFences(in_device, fenceCount, in_pFences);

    FreeArray<VkFence>(&in_pFences);
}

void VulkanReplayConsumer::Process_vkGetFenceStatus(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    fence)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkFence in_fence = object_mapper_.MapVkFence(fence);

    vkGetFenceStatus(in_device, in_fence);
}

void VulkanReplayConsumer::Process_vkWaitForFences(
    VkResult                                    returnValue,
    HandleId                                    device,
    uint32_t                                    fenceCount,
    const PointerDecoder<HandleId>&             pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkFence* in_pFences = pFences.IsNull() ? nullptr : AllocateArray<VkFence>(fenceCount);
    MapHandles<VkFence>(pFences.GetPointer(), pFences.GetLength(), in_pFences, fenceCount, &VulkanObjectMapper::MapVkFence);

    vkWaitForFences(in_device, fenceCount, in_pFences, waitAll, timeout);

    FreeArray<VkFence>(&in_pFences);
}

void VulkanReplayConsumer::Process_vkCreateSemaphore(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSemaphore)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkSemaphoreCreateInfo* in_pCreateInfo = reinterpret_cast<const VkSemaphoreCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSemaphore out_pSemaphore_value = static_cast<VkSemaphore>(0);
    VkSemaphore* out_pSemaphore = &out_pSemaphore_value;

    vkCreateSemaphore(in_device, in_pCreateInfo, in_pAllocator, out_pSemaphore);

    AddHandles<VkSemaphore>(pSemaphore.GetPointer(), 1, out_pSemaphore, 1, &VulkanObjectMapper::AddVkSemaphore);
}

void VulkanReplayConsumer::Process_vkDestroySemaphore(
    HandleId                                    device,
    HandleId                                    semaphore,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSemaphore in_semaphore = object_mapper_.MapVkSemaphore(semaphore);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroySemaphore(in_device, in_semaphore, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateEvent(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkEventCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pEvent)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkEventCreateInfo* in_pCreateInfo = reinterpret_cast<const VkEventCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkEvent out_pEvent_value = static_cast<VkEvent>(0);
    VkEvent* out_pEvent = &out_pEvent_value;

    vkCreateEvent(in_device, in_pCreateInfo, in_pAllocator, out_pEvent);

    AddHandles<VkEvent>(pEvent.GetPointer(), 1, out_pEvent, 1, &VulkanObjectMapper::AddVkEvent);
}

void VulkanReplayConsumer::Process_vkDestroyEvent(
    HandleId                                    device,
    HandleId                                    event,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkEvent in_event = object_mapper_.MapVkEvent(event);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyEvent(in_device, in_event, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetEventStatus(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    event)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkEvent in_event = object_mapper_.MapVkEvent(event);

    vkGetEventStatus(in_device, in_event);
}

void VulkanReplayConsumer::Process_vkSetEvent(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    event)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkEvent in_event = object_mapper_.MapVkEvent(event);

    vkSetEvent(in_device, in_event);
}

void VulkanReplayConsumer::Process_vkResetEvent(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    event)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkEvent in_event = object_mapper_.MapVkEvent(event);

    vkResetEvent(in_device, in_event);
}

void VulkanReplayConsumer::Process_vkCreateQueryPool(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pQueryPool)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkQueryPoolCreateInfo* in_pCreateInfo = reinterpret_cast<const VkQueryPoolCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkQueryPool out_pQueryPool_value = static_cast<VkQueryPool>(0);
    VkQueryPool* out_pQueryPool = &out_pQueryPool_value;

    vkCreateQueryPool(in_device, in_pCreateInfo, in_pAllocator, out_pQueryPool);

    AddHandles<VkQueryPool>(pQueryPool.GetPointer(), 1, out_pQueryPool, 1, &VulkanObjectMapper::AddVkQueryPool);
}

void VulkanReplayConsumer::Process_vkDestroyQueryPool(
    HandleId                                    device,
    HandleId                                    queryPool,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkQueryPool in_queryPool = object_mapper_.MapVkQueryPool(queryPool);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyQueryPool(in_device, in_queryPool, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetQueryPoolResults(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    const PointerDecoder<uint8_t>&              pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkQueryPool in_queryPool = object_mapper_.MapVkQueryPool(queryPool);
    uint8_t* out_pData = pData.IsNull() ? nullptr : AllocateArray<uint8_t>(dataSize);

    vkGetQueryPoolResults(in_device, in_queryPool, firstQuery, queryCount, dataSize, out_pData, stride, flags);

    FreeArray<uint8_t>(&out_pData);
}

void VulkanReplayConsumer::Process_vkCreateBuffer(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkBufferCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pBuffer)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkBufferCreateInfo* in_pCreateInfo = reinterpret_cast<const VkBufferCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkBuffer out_pBuffer_value = static_cast<VkBuffer>(0);
    VkBuffer* out_pBuffer = &out_pBuffer_value;

    vkCreateBuffer(in_device, in_pCreateInfo, in_pAllocator, out_pBuffer);

    AddHandles<VkBuffer>(pBuffer.GetPointer(), 1, out_pBuffer, 1, &VulkanObjectMapper::AddVkBuffer);
}

void VulkanReplayConsumer::Process_vkDestroyBuffer(
    HandleId                                    device,
    HandleId                                    buffer,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkBuffer in_buffer = object_mapper_.MapVkBuffer(buffer);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyBuffer(in_device, in_buffer, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateBufferView(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkBufferViewCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pView)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkBufferViewCreateInfo* in_pCreateInfo = reinterpret_cast<VkBufferViewCreateInfo*>(pCreateInfo.GetPointer());
    if (!pCreateInfo.IsNull())
    {
        const Decoded_VkBufferViewCreateInfo* in_pCreateInfo_wrapper = pCreateInfo.GetMetaStructPointer();
        in_pCreateInfo->buffer = object_mapper_.MapVkBuffer(in_pCreateInfo_wrapper->buffer);
    }
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkBufferView out_pView_value = static_cast<VkBufferView>(0);
    VkBufferView* out_pView = &out_pView_value;

    vkCreateBufferView(in_device, in_pCreateInfo, in_pAllocator, out_pView);

    AddHandles<VkBufferView>(pView.GetPointer(), 1, out_pView, 1, &VulkanObjectMapper::AddVkBufferView);
}

void VulkanReplayConsumer::Process_vkDestroyBufferView(
    HandleId                                    device,
    HandleId                                    bufferView,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkBufferView in_bufferView = object_mapper_.MapVkBufferView(bufferView);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyBufferView(in_device, in_bufferView, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateImage(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkImageCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pImage)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkImageCreateInfo* in_pCreateInfo = reinterpret_cast<const VkImageCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkImage out_pImage_value = static_cast<VkImage>(0);
    VkImage* out_pImage = &out_pImage_value;

    vkCreateImage(in_device, in_pCreateInfo, in_pAllocator, out_pImage);

    AddHandles<VkImage>(pImage.GetPointer(), 1, out_pImage, 1, &VulkanObjectMapper::AddVkImage);
}

void VulkanReplayConsumer::Process_vkDestroyImage(
    HandleId                                    device,
    HandleId                                    image,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImage in_image = object_mapper_.MapVkImage(image);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyImage(in_device, in_image, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetImageSubresourceLayout(
    HandleId                                    device,
    HandleId                                    image,
    const StructPointerDecoder<Decoded_VkImageSubresource>& pSubresource,
    const StructPointerDecoder<Decoded_VkSubresourceLayout>& pLayout)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImage in_image = object_mapper_.MapVkImage(image);
    const VkImageSubresource* in_pSubresource = reinterpret_cast<const VkImageSubresource*>(pSubresource.GetPointer());
    VkSubresourceLayout out_pLayout_value = {};
    VkSubresourceLayout* out_pLayout = &out_pLayout_value;

    vkGetImageSubresourceLayout(in_device, in_image, in_pSubresource, out_pLayout);
}

void VulkanReplayConsumer::Process_vkCreateImageView(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkImageViewCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pView)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImageViewCreateInfo* in_pCreateInfo = reinterpret_cast<VkImageViewCreateInfo*>(pCreateInfo.GetPointer());
    if (!pCreateInfo.IsNull())
    {
        const Decoded_VkImageViewCreateInfo* in_pCreateInfo_wrapper = pCreateInfo.GetMetaStructPointer();
        in_pCreateInfo->image = object_mapper_.MapVkImage(in_pCreateInfo_wrapper->image);
    }
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkImageView out_pView_value = static_cast<VkImageView>(0);
    VkImageView* out_pView = &out_pView_value;

    vkCreateImageView(in_device, in_pCreateInfo, in_pAllocator, out_pView);

    AddHandles<VkImageView>(pView.GetPointer(), 1, out_pView, 1, &VulkanObjectMapper::AddVkImageView);
}

void VulkanReplayConsumer::Process_vkDestroyImageView(
    HandleId                                    device,
    HandleId                                    imageView,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImageView in_imageView = object_mapper_.MapVkImageView(imageView);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyImageView(in_device, in_imageView, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateShaderModule(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pShaderModule)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkShaderModuleCreateInfo* in_pCreateInfo = reinterpret_cast<const VkShaderModuleCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkShaderModule out_pShaderModule_value = static_cast<VkShaderModule>(0);
    VkShaderModule* out_pShaderModule = &out_pShaderModule_value;

    vkCreateShaderModule(in_device, in_pCreateInfo, in_pAllocator, out_pShaderModule);

    AddHandles<VkShaderModule>(pShaderModule.GetPointer(), 1, out_pShaderModule, 1, &VulkanObjectMapper::AddVkShaderModule);
}

void VulkanReplayConsumer::Process_vkDestroyShaderModule(
    HandleId                                    device,
    HandleId                                    shaderModule,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkShaderModule in_shaderModule = object_mapper_.MapVkShaderModule(shaderModule);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyShaderModule(in_device, in_shaderModule, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreatePipelineCache(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pPipelineCache)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkPipelineCacheCreateInfo* in_pCreateInfo = reinterpret_cast<const VkPipelineCacheCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkPipelineCache out_pPipelineCache_value = static_cast<VkPipelineCache>(0);
    VkPipelineCache* out_pPipelineCache = &out_pPipelineCache_value;

    vkCreatePipelineCache(in_device, in_pCreateInfo, in_pAllocator, out_pPipelineCache);

    AddHandles<VkPipelineCache>(pPipelineCache.GetPointer(), 1, out_pPipelineCache, 1, &VulkanObjectMapper::AddVkPipelineCache);
}

void VulkanReplayConsumer::Process_vkDestroyPipelineCache(
    HandleId                                    device,
    HandleId                                    pipelineCache,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkPipelineCache in_pipelineCache = object_mapper_.MapVkPipelineCache(pipelineCache);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyPipelineCache(in_device, in_pipelineCache, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetPipelineCacheData(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    pipelineCache,
    const PointerDecoder<size_t>&               pDataSize,
    const PointerDecoder<uint8_t>&              pData)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkPipelineCache in_pipelineCache = object_mapper_.MapVkPipelineCache(pipelineCache);
    size_t out_pDataSize_value = pDataSize.IsNull() ? static_cast<size_t>(0) : *(pDataSize.GetPointer());
    size_t* out_pDataSize = &out_pDataSize_value;
    uint8_t* out_pData = pData.IsNull() ? nullptr : AllocateArray<uint8_t>(out_pDataSize_value);

    vkGetPipelineCacheData(in_device, in_pipelineCache, out_pDataSize, out_pData);

    FreeArray<uint8_t>(&out_pData);
}

void VulkanReplayConsumer::Process_vkMergePipelineCaches(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    dstCache,
    uint32_t                                    srcCacheCount,
    const PointerDecoder<HandleId>&             pSrcCaches)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkPipelineCache in_dstCache = object_mapper_.MapVkPipelineCache(dstCache);
    VkPipelineCache* in_pSrcCaches = pSrcCaches.IsNull() ? nullptr : AllocateArray<VkPipelineCache>(srcCacheCount);
    MapHandles<VkPipelineCache>(pSrcCaches.GetPointer(), pSrcCaches.GetLength(), in_pSrcCaches, srcCacheCount, &VulkanObjectMapper::MapVkPipelineCache);

    vkMergePipelineCaches(in_device, in_dstCache, srcCacheCount, in_pSrcCaches);

    FreeArray<VkPipelineCache>(&in_pSrcCaches);
}

void VulkanReplayConsumer::Process_vkCreateGraphicsPipelines(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    pipelineCache,
    uint32_t                                    createInfoCount,
    const StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>& pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pPipelines)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkPipelineCache in_pipelineCache = object_mapper_.MapVkPipelineCache(pipelineCache);
    VkGraphicsPipelineCreateInfo* in_pCreateInfos = reinterpret_cast<VkGraphicsPipelineCreateInfo*>(pCreateInfos.GetPointer());
    if (!pCreateInfos.IsNull())
    {
        const Decoded_VkGraphicsPipelineCreateInfo* in_pCreateInfos_wrapper = pCreateInfos.GetMetaStructPointer();
        assert(createInfoCount == pCreateInfos.GetLength());
        for (size_t i = 0; i < createInfoCount; ++i)
        {
            in_pCreateInfos[i].layout = object_mapper_.MapVkPipelineLayout(in_pCreateInfos_wrapper[i].layout);
            in_pCreateInfos[i].renderPass = object_mapper_.MapVkRenderPass(in_pCreateInfos_wrapper[i].renderPass);
            in_pCreateInfos[i].basePipelineHandle = object_mapper_.MapVkPipeline(in_pCreateInfos_wrapper[i].basePipelineHandle);
        }
    }
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkPipeline* out_pPipelines = pPipelines.IsNull() ? nullptr : AllocateArray<VkPipeline>(createInfoCount);

    vkCreateGraphicsPipelines(in_device, in_pipelineCache, createInfoCount, in_pCreateInfos, in_pAllocator, out_pPipelines);

    AddHandles<VkPipeline>(pPipelines.GetPointer(), pPipelines.GetLength(), out_pPipelines, createInfoCount, &VulkanObjectMapper::AddVkPipeline);
    FreeArray<VkPipeline>(&out_pPipelines);
}

void VulkanReplayConsumer::Process_vkCreateComputePipelines(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    pipelineCache,
    uint32_t                                    createInfoCount,
    const StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>& pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pPipelines)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkPipelineCache in_pipelineCache = object_mapper_.MapVkPipelineCache(pipelineCache);
    VkComputePipelineCreateInfo* in_pCreateInfos = reinterpret_cast<VkComputePipelineCreateInfo*>(pCreateInfos.GetPointer());
    if (!pCreateInfos.IsNull())
    {
        const Decoded_VkComputePipelineCreateInfo* in_pCreateInfos_wrapper = pCreateInfos.GetMetaStructPointer();
        assert(createInfoCount == pCreateInfos.GetLength());
        for (size_t i = 0; i < createInfoCount; ++i)
        {
            in_pCreateInfos[i].layout = object_mapper_.MapVkPipelineLayout(in_pCreateInfos_wrapper[i].layout);
            in_pCreateInfos[i].basePipelineHandle = object_mapper_.MapVkPipeline(in_pCreateInfos_wrapper[i].basePipelineHandle);
        }
    }
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkPipeline* out_pPipelines = pPipelines.IsNull() ? nullptr : AllocateArray<VkPipeline>(createInfoCount);

    vkCreateComputePipelines(in_device, in_pipelineCache, createInfoCount, in_pCreateInfos, in_pAllocator, out_pPipelines);

    AddHandles<VkPipeline>(pPipelines.GetPointer(), pPipelines.GetLength(), out_pPipelines, createInfoCount, &VulkanObjectMapper::AddVkPipeline);
    FreeArray<VkPipeline>(&out_pPipelines);
}

void VulkanReplayConsumer::Process_vkDestroyPipeline(
    HandleId                                    device,
    HandleId                                    pipeline,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkPipeline in_pipeline = object_mapper_.MapVkPipeline(pipeline);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyPipeline(in_device, in_pipeline, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreatePipelineLayout(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pPipelineLayout)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkPipelineLayoutCreateInfo* in_pCreateInfo = reinterpret_cast<VkPipelineLayoutCreateInfo*>(pCreateInfo.GetPointer());
    if (!pCreateInfo.IsNull())
    {
        const Decoded_VkPipelineLayoutCreateInfo* in_pCreateInfo_wrapper = pCreateInfo.GetMetaStructPointer();
        VkDescriptorSetLayout* pSetLayouts_memory = AllocateArray<VkDescriptorSetLayout>(in_pCreateInfo->setLayoutCount);
        in_pCreateInfo->pSetLayouts = pSetLayouts_memory;
        MapHandles<VkDescriptorSetLayout>(in_pCreateInfo_wrapper->pSetLayouts.GetPointer(), in_pCreateInfo_wrapper->pSetLayouts.GetLength(), pSetLayouts_memory, in_pCreateInfo->setLayoutCount, &VulkanObjectMapper::MapVkDescriptorSetLayout);
    }
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkPipelineLayout out_pPipelineLayout_value = static_cast<VkPipelineLayout>(0);
    VkPipelineLayout* out_pPipelineLayout = &out_pPipelineLayout_value;

    vkCreatePipelineLayout(in_device, in_pCreateInfo, in_pAllocator, out_pPipelineLayout);

    if (in_pCreateInfo != nullptr)
    {
        FreeArray<VkDescriptorSetLayout>(&in_pCreateInfo->pSetLayouts);
    }
    AddHandles<VkPipelineLayout>(pPipelineLayout.GetPointer(), 1, out_pPipelineLayout, 1, &VulkanObjectMapper::AddVkPipelineLayout);
}

void VulkanReplayConsumer::Process_vkDestroyPipelineLayout(
    HandleId                                    device,
    HandleId                                    pipelineLayout,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkPipelineLayout in_pipelineLayout = object_mapper_.MapVkPipelineLayout(pipelineLayout);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyPipelineLayout(in_device, in_pipelineLayout, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateSampler(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkSamplerCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSampler)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkSamplerCreateInfo* in_pCreateInfo = reinterpret_cast<const VkSamplerCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSampler out_pSampler_value = static_cast<VkSampler>(0);
    VkSampler* out_pSampler = &out_pSampler_value;

    vkCreateSampler(in_device, in_pCreateInfo, in_pAllocator, out_pSampler);

    AddHandles<VkSampler>(pSampler.GetPointer(), 1, out_pSampler, 1, &VulkanObjectMapper::AddVkSampler);
}

void VulkanReplayConsumer::Process_vkDestroySampler(
    HandleId                                    device,
    HandleId                                    sampler,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSampler in_sampler = object_mapper_.MapVkSampler(sampler);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroySampler(in_device, in_sampler, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorSetLayout(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSetLayout)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDescriptorSetLayout out_pSetLayout_value = static_cast<VkDescriptorSetLayout>(0);
    VkDescriptorSetLayout* out_pSetLayout = &out_pSetLayout_value;

    vkCreateDescriptorSetLayout(in_device, in_pCreateInfo, in_pAllocator, out_pSetLayout);

    AddHandles<VkDescriptorSetLayout>(pSetLayout.GetPointer(), 1, out_pSetLayout, 1, &VulkanObjectMapper::AddVkDescriptorSetLayout);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorSetLayout(
    HandleId                                    device,
    HandleId                                    descriptorSetLayout,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDescriptorSetLayout in_descriptorSetLayout = object_mapper_.MapVkDescriptorSetLayout(descriptorSetLayout);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDescriptorSetLayout(in_device, in_descriptorSetLayout, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorPool(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pDescriptorPool)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkDescriptorPoolCreateInfo* in_pCreateInfo = reinterpret_cast<const VkDescriptorPoolCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDescriptorPool out_pDescriptorPool_value = static_cast<VkDescriptorPool>(0);
    VkDescriptorPool* out_pDescriptorPool = &out_pDescriptorPool_value;

    vkCreateDescriptorPool(in_device, in_pCreateInfo, in_pAllocator, out_pDescriptorPool);

    AddHandles<VkDescriptorPool>(pDescriptorPool.GetPointer(), 1, out_pDescriptorPool, 1, &VulkanObjectMapper::AddVkDescriptorPool);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorPool(
    HandleId                                    device,
    HandleId                                    descriptorPool,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDescriptorPool in_descriptorPool = object_mapper_.MapVkDescriptorPool(descriptorPool);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDescriptorPool(in_device, in_descriptorPool, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkResetDescriptorPool(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDescriptorPool in_descriptorPool = object_mapper_.MapVkDescriptorPool(descriptorPool);

    vkResetDescriptorPool(in_device, in_descriptorPool, flags);
}

void VulkanReplayConsumer::Process_vkAllocateDescriptorSets(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>& pAllocateInfo,
    const PointerDecoder<HandleId>&             pDescriptorSets)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDescriptorSetAllocateInfo* in_pAllocateInfo = reinterpret_cast<VkDescriptorSetAllocateInfo*>(pAllocateInfo.GetPointer());
    if (!pAllocateInfo.IsNull())
    {
        const Decoded_VkDescriptorSetAllocateInfo* in_pAllocateInfo_wrapper = pAllocateInfo.GetMetaStructPointer();
        in_pAllocateInfo->descriptorPool = object_mapper_.MapVkDescriptorPool(in_pAllocateInfo_wrapper->descriptorPool);
        VkDescriptorSetLayout* pSetLayouts_memory = AllocateArray<VkDescriptorSetLayout>(in_pAllocateInfo->descriptorSetCount);
        in_pAllocateInfo->pSetLayouts = pSetLayouts_memory;
        MapHandles<VkDescriptorSetLayout>(in_pAllocateInfo_wrapper->pSetLayouts.GetPointer(), in_pAllocateInfo_wrapper->pSetLayouts.GetLength(), pSetLayouts_memory, in_pAllocateInfo->descriptorSetCount, &VulkanObjectMapper::MapVkDescriptorSetLayout);
    }
    VkDescriptorSet* out_pDescriptorSets = pDescriptorSets.IsNull() ? nullptr : AllocateArray<VkDescriptorSet>(in_pAllocateInfo->descriptorSetCount);

    vkAllocateDescriptorSets(in_device, in_pAllocateInfo, out_pDescriptorSets);

    if (in_pAllocateInfo != nullptr)
    {
        FreeArray<VkDescriptorSetLayout>(&in_pAllocateInfo->pSetLayouts);
    }
    AddHandles<VkDescriptorSet>(pDescriptorSets.GetPointer(), pDescriptorSets.GetLength(), out_pDescriptorSets, in_pAllocateInfo->descriptorSetCount, &VulkanObjectMapper::AddVkDescriptorSet);
    FreeArray<VkDescriptorSet>(&out_pDescriptorSets);
}

void VulkanReplayConsumer::Process_vkFreeDescriptorSets(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    descriptorPool,
    uint32_t                                    descriptorSetCount,
    const PointerDecoder<HandleId>&             pDescriptorSets)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDescriptorPool in_descriptorPool = object_mapper_.MapVkDescriptorPool(descriptorPool);
    VkDescriptorSet* in_pDescriptorSets = pDescriptorSets.IsNull() ? nullptr : AllocateArray<VkDescriptorSet>(descriptorSetCount);
    MapHandles<VkDescriptorSet>(pDescriptorSets.GetPointer(), pDescriptorSets.GetLength(), in_pDescriptorSets, descriptorSetCount, &VulkanObjectMapper::MapVkDescriptorSet);

    vkFreeDescriptorSets(in_device, in_descriptorPool, descriptorSetCount, in_pDescriptorSets);

    FreeArray<VkDescriptorSet>(&in_pDescriptorSets);
}

void VulkanReplayConsumer::Process_vkUpdateDescriptorSets(
    HandleId                                    device,
    uint32_t                                    descriptorWriteCount,
    const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    const StructPointerDecoder<Decoded_VkCopyDescriptorSet>& pDescriptorCopies)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkWriteDescriptorSet* in_pDescriptorWrites = reinterpret_cast<VkWriteDescriptorSet*>(pDescriptorWrites.GetPointer());
    if (!pDescriptorWrites.IsNull())
    {
        const Decoded_VkWriteDescriptorSet* in_pDescriptorWrites_wrapper = pDescriptorWrites.GetMetaStructPointer();
        assert(descriptorWriteCount == pDescriptorWrites.GetLength());
        for (size_t i = 0; i < descriptorWriteCount; ++i)
        {
            in_pDescriptorWrites[i].dstSet = object_mapper_.MapVkDescriptorSet(in_pDescriptorWrites_wrapper[i].dstSet);
            VkBufferView* pTexelBufferView_memory = AllocateArray<VkBufferView>(in_pDescriptorWrites[i].descriptorCount);
            in_pDescriptorWrites[i].pTexelBufferView = pTexelBufferView_memory;
            MapHandles<VkBufferView>(in_pDescriptorWrites_wrapper[i].pTexelBufferView.GetPointer(), in_pDescriptorWrites_wrapper[i].pTexelBufferView.GetLength(), pTexelBufferView_memory, in_pDescriptorWrites[i].descriptorCount, &VulkanObjectMapper::MapVkBufferView);
        }
    }
    VkCopyDescriptorSet* in_pDescriptorCopies = reinterpret_cast<VkCopyDescriptorSet*>(pDescriptorCopies.GetPointer());
    if (!pDescriptorCopies.IsNull())
    {
        const Decoded_VkCopyDescriptorSet* in_pDescriptorCopies_wrapper = pDescriptorCopies.GetMetaStructPointer();
        assert(descriptorCopyCount == pDescriptorCopies.GetLength());
        for (size_t i = 0; i < descriptorCopyCount; ++i)
        {
            in_pDescriptorCopies[i].srcSet = object_mapper_.MapVkDescriptorSet(in_pDescriptorCopies_wrapper[i].srcSet);
            in_pDescriptorCopies[i].dstSet = object_mapper_.MapVkDescriptorSet(in_pDescriptorCopies_wrapper[i].dstSet);
        }
    }

    vkUpdateDescriptorSets(in_device, descriptorWriteCount, in_pDescriptorWrites, descriptorCopyCount, in_pDescriptorCopies);

    if (in_pDescriptorWrites != nullptr)
    {
        for (size_t i = 0; i < descriptorWriteCount; ++i)
        {
            FreeArray<VkBufferView>(&in_pDescriptorWrites[i].pTexelBufferView);
        }
    }
}

void VulkanReplayConsumer::Process_vkCreateFramebuffer(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkFramebufferCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pFramebuffer)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkFramebufferCreateInfo* in_pCreateInfo = reinterpret_cast<VkFramebufferCreateInfo*>(pCreateInfo.GetPointer());
    if (!pCreateInfo.IsNull())
    {
        const Decoded_VkFramebufferCreateInfo* in_pCreateInfo_wrapper = pCreateInfo.GetMetaStructPointer();
        in_pCreateInfo->renderPass = object_mapper_.MapVkRenderPass(in_pCreateInfo_wrapper->renderPass);
        VkImageView* pAttachments_memory = AllocateArray<VkImageView>(in_pCreateInfo->attachmentCount);
        in_pCreateInfo->pAttachments = pAttachments_memory;
        MapHandles<VkImageView>(in_pCreateInfo_wrapper->pAttachments.GetPointer(), in_pCreateInfo_wrapper->pAttachments.GetLength(), pAttachments_memory, in_pCreateInfo->attachmentCount, &VulkanObjectMapper::MapVkImageView);
    }
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkFramebuffer out_pFramebuffer_value = static_cast<VkFramebuffer>(0);
    VkFramebuffer* out_pFramebuffer = &out_pFramebuffer_value;

    vkCreateFramebuffer(in_device, in_pCreateInfo, in_pAllocator, out_pFramebuffer);

    if (in_pCreateInfo != nullptr)
    {
        FreeArray<VkImageView>(&in_pCreateInfo->pAttachments);
    }
    AddHandles<VkFramebuffer>(pFramebuffer.GetPointer(), 1, out_pFramebuffer, 1, &VulkanObjectMapper::AddVkFramebuffer);
}

void VulkanReplayConsumer::Process_vkDestroyFramebuffer(
    HandleId                                    device,
    HandleId                                    framebuffer,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkFramebuffer in_framebuffer = object_mapper_.MapVkFramebuffer(framebuffer);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyFramebuffer(in_device, in_framebuffer, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateRenderPass(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pRenderPass)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkRenderPassCreateInfo* in_pCreateInfo = reinterpret_cast<const VkRenderPassCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkRenderPass out_pRenderPass_value = static_cast<VkRenderPass>(0);
    VkRenderPass* out_pRenderPass = &out_pRenderPass_value;

    vkCreateRenderPass(in_device, in_pCreateInfo, in_pAllocator, out_pRenderPass);

    AddHandles<VkRenderPass>(pRenderPass.GetPointer(), 1, out_pRenderPass, 1, &VulkanObjectMapper::AddVkRenderPass);
}

void VulkanReplayConsumer::Process_vkDestroyRenderPass(
    HandleId                                    device,
    HandleId                                    renderPass,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkRenderPass in_renderPass = object_mapper_.MapVkRenderPass(renderPass);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyRenderPass(in_device, in_renderPass, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetRenderAreaGranularity(
    HandleId                                    device,
    HandleId                                    renderPass,
    const StructPointerDecoder<Decoded_VkExtent2D>& pGranularity)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkRenderPass in_renderPass = object_mapper_.MapVkRenderPass(renderPass);
    VkExtent2D out_pGranularity_value = {};
    VkExtent2D* out_pGranularity = &out_pGranularity_value;

    vkGetRenderAreaGranularity(in_device, in_renderPass, out_pGranularity);
}

void VulkanReplayConsumer::Process_vkCreateCommandPool(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pCommandPool)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkCommandPoolCreateInfo* in_pCreateInfo = reinterpret_cast<const VkCommandPoolCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkCommandPool out_pCommandPool_value = static_cast<VkCommandPool>(0);
    VkCommandPool* out_pCommandPool = &out_pCommandPool_value;

    vkCreateCommandPool(in_device, in_pCreateInfo, in_pAllocator, out_pCommandPool);

    AddHandles<VkCommandPool>(pCommandPool.GetPointer(), 1, out_pCommandPool, 1, &VulkanObjectMapper::AddVkCommandPool);
}

void VulkanReplayConsumer::Process_vkDestroyCommandPool(
    HandleId                                    device,
    HandleId                                    commandPool,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkCommandPool in_commandPool = object_mapper_.MapVkCommandPool(commandPool);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyCommandPool(in_device, in_commandPool, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkResetCommandPool(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    commandPool,
    VkCommandPoolResetFlags                     flags)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkCommandPool in_commandPool = object_mapper_.MapVkCommandPool(commandPool);

    vkResetCommandPool(in_device, in_commandPool, flags);
}

void VulkanReplayConsumer::Process_vkAllocateCommandBuffers(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>& pAllocateInfo,
    const PointerDecoder<HandleId>&             pCommandBuffers)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkCommandBufferAllocateInfo* in_pAllocateInfo = reinterpret_cast<VkCommandBufferAllocateInfo*>(pAllocateInfo.GetPointer());
    if (!pAllocateInfo.IsNull())
    {
        const Decoded_VkCommandBufferAllocateInfo* in_pAllocateInfo_wrapper = pAllocateInfo.GetMetaStructPointer();
        in_pAllocateInfo->commandPool = object_mapper_.MapVkCommandPool(in_pAllocateInfo_wrapper->commandPool);
    }
    VkCommandBuffer* out_pCommandBuffers = pCommandBuffers.IsNull() ? nullptr : AllocateArray<VkCommandBuffer>(in_pAllocateInfo->commandBufferCount);

    vkAllocateCommandBuffers(in_device, in_pAllocateInfo, out_pCommandBuffers);

    AddHandles<VkCommandBuffer>(pCommandBuffers.GetPointer(), pCommandBuffers.GetLength(), out_pCommandBuffers, in_pAllocateInfo->commandBufferCount, &VulkanObjectMapper::AddVkCommandBuffer);
    FreeArray<VkCommandBuffer>(&out_pCommandBuffers);
}

void VulkanReplayConsumer::Process_vkFreeCommandBuffers(
    HandleId                                    device,
    HandleId                                    commandPool,
    uint32_t                                    commandBufferCount,
    const PointerDecoder<HandleId>&             pCommandBuffers)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkCommandPool in_commandPool = object_mapper_.MapVkCommandPool(commandPool);
    VkCommandBuffer* in_pCommandBuffers = pCommandBuffers.IsNull() ? nullptr : AllocateArray<VkCommandBuffer>(commandBufferCount);
    MapHandles<VkCommandBuffer>(pCommandBuffers.GetPointer(), pCommandBuffers.GetLength(), in_pCommandBuffers, commandBufferCount, &VulkanObjectMapper::MapVkCommandBuffer);

    vkFreeCommandBuffers(in_device, in_commandPool, commandBufferCount, in_pCommandBuffers);

    FreeArray<VkCommandBuffer>(&in_pCommandBuffers);
}

void VulkanReplayConsumer::Process_vkBeginCommandBuffer(
    VkResult                                    returnValue,
    HandleId                                    commandBuffer,
    const StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>& pBeginInfo)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkCommandBufferBeginInfo* in_pBeginInfo = reinterpret_cast<const VkCommandBufferBeginInfo*>(pBeginInfo.GetPointer());

    vkBeginCommandBuffer(in_commandBuffer, in_pBeginInfo);
}

void VulkanReplayConsumer::Process_vkEndCommandBuffer(
    VkResult                                    returnValue,
    HandleId                                    commandBuffer)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkEndCommandBuffer(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkResetCommandBuffer(
    VkResult                                    returnValue,
    HandleId                                    commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkResetCommandBuffer(in_commandBuffer, flags);
}

void VulkanReplayConsumer::Process_vkCmdBindPipeline(
    HandleId                                    commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    HandleId                                    pipeline)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkPipeline in_pipeline = object_mapper_.MapVkPipeline(pipeline);

    vkCmdBindPipeline(in_commandBuffer, pipelineBindPoint, in_pipeline);
}

void VulkanReplayConsumer::Process_vkCmdSetViewport(
    HandleId                                    commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const StructPointerDecoder<Decoded_VkViewport>& pViewports)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkViewport* in_pViewports = reinterpret_cast<const VkViewport*>(pViewports.GetPointer());

    vkCmdSetViewport(in_commandBuffer, firstViewport, viewportCount, in_pViewports);
}

void VulkanReplayConsumer::Process_vkCmdSetScissor(
    HandleId                                    commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const StructPointerDecoder<Decoded_VkRect2D>& pScissors)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkRect2D* in_pScissors = reinterpret_cast<const VkRect2D*>(pScissors.GetPointer());

    vkCmdSetScissor(in_commandBuffer, firstScissor, scissorCount, in_pScissors);
}

void VulkanReplayConsumer::Process_vkCmdSetLineWidth(
    HandleId                                    commandBuffer,
    float                                       lineWidth)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdSetLineWidth(in_commandBuffer, lineWidth);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBias(
    HandleId                                    commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdSetDepthBias(in_commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

void VulkanReplayConsumer::Process_vkCmdSetBlendConstants(
    HandleId                                    commandBuffer,
    const PointerDecoder<float>&                blendConstants)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const float* in_blendConstants = reinterpret_cast<const float*>(blendConstants.GetPointer());

    vkCmdSetBlendConstants(in_commandBuffer, in_blendConstants);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBounds(
    HandleId                                    commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdSetDepthBounds(in_commandBuffer, minDepthBounds, maxDepthBounds);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilCompareMask(
    HandleId                                    commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdSetStencilCompareMask(in_commandBuffer, faceMask, compareMask);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilWriteMask(
    HandleId                                    commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdSetStencilWriteMask(in_commandBuffer, faceMask, writeMask);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilReference(
    HandleId                                    commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdSetStencilReference(in_commandBuffer, faceMask, reference);
}

void VulkanReplayConsumer::Process_vkCmdBindDescriptorSets(
    HandleId                                    commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    HandleId                                    layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const PointerDecoder<HandleId>&             pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const PointerDecoder<uint32_t>&             pDynamicOffsets)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkPipelineLayout in_layout = object_mapper_.MapVkPipelineLayout(layout);
    VkDescriptorSet* in_pDescriptorSets = pDescriptorSets.IsNull() ? nullptr : AllocateArray<VkDescriptorSet>(descriptorSetCount);
    MapHandles<VkDescriptorSet>(pDescriptorSets.GetPointer(), pDescriptorSets.GetLength(), in_pDescriptorSets, descriptorSetCount, &VulkanObjectMapper::MapVkDescriptorSet);
    const uint32_t* in_pDynamicOffsets = reinterpret_cast<const uint32_t*>(pDynamicOffsets.GetPointer());

    vkCmdBindDescriptorSets(in_commandBuffer, pipelineBindPoint, in_layout, firstSet, descriptorSetCount, in_pDescriptorSets, dynamicOffsetCount, in_pDynamicOffsets);

    FreeArray<VkDescriptorSet>(&in_pDescriptorSets);
}

void VulkanReplayConsumer::Process_vkCmdBindIndexBuffer(
    HandleId                                    commandBuffer,
    HandleId                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer in_buffer = object_mapper_.MapVkBuffer(buffer);

    vkCmdBindIndexBuffer(in_commandBuffer, in_buffer, offset, indexType);
}

void VulkanReplayConsumer::Process_vkCmdBindVertexBuffers(
    HandleId                                    commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const PointerDecoder<HandleId>&             pBuffers,
    const PointerDecoder<VkDeviceSize>&         pOffsets)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer* in_pBuffers = pBuffers.IsNull() ? nullptr : AllocateArray<VkBuffer>(bindingCount);
    MapHandles<VkBuffer>(pBuffers.GetPointer(), pBuffers.GetLength(), in_pBuffers, bindingCount, &VulkanObjectMapper::MapVkBuffer);
    const VkDeviceSize* in_pOffsets = reinterpret_cast<const VkDeviceSize*>(pOffsets.GetPointer());

    vkCmdBindVertexBuffers(in_commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets);

    FreeArray<VkBuffer>(&in_pBuffers);
}

void VulkanReplayConsumer::Process_vkCmdDraw(
    HandleId                                    commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdDraw(in_commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexed(
    HandleId                                    commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdDrawIndexed(in_commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirect(
    HandleId                                    commandBuffer,
    HandleId                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer in_buffer = object_mapper_.MapVkBuffer(buffer);

    vkCmdDrawIndirect(in_commandBuffer, in_buffer, offset, drawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirect(
    HandleId                                    commandBuffer,
    HandleId                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer in_buffer = object_mapper_.MapVkBuffer(buffer);

    vkCmdDrawIndexedIndirect(in_commandBuffer, in_buffer, offset, drawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDispatch(
    HandleId                                    commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdDispatch(in_commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkCmdDispatchIndirect(
    HandleId                                    commandBuffer,
    HandleId                                    buffer,
    VkDeviceSize                                offset)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer in_buffer = object_mapper_.MapVkBuffer(buffer);

    vkCmdDispatchIndirect(in_commandBuffer, in_buffer, offset);
}

void VulkanReplayConsumer::Process_vkCmdCopyBuffer(
    HandleId                                    commandBuffer,
    HandleId                                    srcBuffer,
    HandleId                                    dstBuffer,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkBufferCopy>& pRegions)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer in_srcBuffer = object_mapper_.MapVkBuffer(srcBuffer);
    VkBuffer in_dstBuffer = object_mapper_.MapVkBuffer(dstBuffer);
    const VkBufferCopy* in_pRegions = reinterpret_cast<const VkBufferCopy*>(pRegions.GetPointer());

    vkCmdCopyBuffer(in_commandBuffer, in_srcBuffer, in_dstBuffer, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdCopyImage(
    HandleId                                    commandBuffer,
    HandleId                                    srcImage,
    VkImageLayout                               srcImageLayout,
    HandleId                                    dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkImageCopy>& pRegions)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkImage in_srcImage = object_mapper_.MapVkImage(srcImage);
    VkImage in_dstImage = object_mapper_.MapVkImage(dstImage);
    const VkImageCopy* in_pRegions = reinterpret_cast<const VkImageCopy*>(pRegions.GetPointer());

    vkCmdCopyImage(in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdBlitImage(
    HandleId                                    commandBuffer,
    HandleId                                    srcImage,
    VkImageLayout                               srcImageLayout,
    HandleId                                    dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkImageBlit>& pRegions,
    VkFilter                                    filter)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkImage in_srcImage = object_mapper_.MapVkImage(srcImage);
    VkImage in_dstImage = object_mapper_.MapVkImage(dstImage);
    const VkImageBlit* in_pRegions = reinterpret_cast<const VkImageBlit*>(pRegions.GetPointer());

    vkCmdBlitImage(in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions, filter);
}

void VulkanReplayConsumer::Process_vkCmdCopyBufferToImage(
    HandleId                                    commandBuffer,
    HandleId                                    srcBuffer,
    HandleId                                    dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer in_srcBuffer = object_mapper_.MapVkBuffer(srcBuffer);
    VkImage in_dstImage = object_mapper_.MapVkImage(dstImage);
    const VkBufferImageCopy* in_pRegions = reinterpret_cast<const VkBufferImageCopy*>(pRegions.GetPointer());

    vkCmdCopyBufferToImage(in_commandBuffer, in_srcBuffer, in_dstImage, dstImageLayout, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer(
    HandleId                                    commandBuffer,
    HandleId                                    srcImage,
    VkImageLayout                               srcImageLayout,
    HandleId                                    dstBuffer,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkImage in_srcImage = object_mapper_.MapVkImage(srcImage);
    VkBuffer in_dstBuffer = object_mapper_.MapVkBuffer(dstBuffer);
    const VkBufferImageCopy* in_pRegions = reinterpret_cast<const VkBufferImageCopy*>(pRegions.GetPointer());

    vkCmdCopyImageToBuffer(in_commandBuffer, in_srcImage, srcImageLayout, in_dstBuffer, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdUpdateBuffer(
    HandleId                                    commandBuffer,
    HandleId                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const PointerDecoder<uint8_t>&              pData)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer in_dstBuffer = object_mapper_.MapVkBuffer(dstBuffer);
    const void* in_pData = reinterpret_cast<const void*>(pData.GetPointer());

    vkCmdUpdateBuffer(in_commandBuffer, in_dstBuffer, dstOffset, dataSize, in_pData);
}

void VulkanReplayConsumer::Process_vkCmdFillBuffer(
    HandleId                                    commandBuffer,
    HandleId                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer in_dstBuffer = object_mapper_.MapVkBuffer(dstBuffer);

    vkCmdFillBuffer(in_commandBuffer, in_dstBuffer, dstOffset, size, data);
}

void VulkanReplayConsumer::Process_vkCmdClearColorImage(
    HandleId                                    commandBuffer,
    HandleId                                    image,
    VkImageLayout                               imageLayout,
    const StructPointerDecoder<Decoded_VkClearColorValue>& pColor,
    uint32_t                                    rangeCount,
    const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkImage in_image = object_mapper_.MapVkImage(image);
    const VkClearColorValue* in_pColor = reinterpret_cast<const VkClearColorValue*>(pColor.GetPointer());
    const VkImageSubresourceRange* in_pRanges = reinterpret_cast<const VkImageSubresourceRange*>(pRanges.GetPointer());

    vkCmdClearColorImage(in_commandBuffer, in_image, imageLayout, in_pColor, rangeCount, in_pRanges);
}

void VulkanReplayConsumer::Process_vkCmdClearDepthStencilImage(
    HandleId                                    commandBuffer,
    HandleId                                    image,
    VkImageLayout                               imageLayout,
    const StructPointerDecoder<Decoded_VkClearDepthStencilValue>& pDepthStencil,
    uint32_t                                    rangeCount,
    const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkImage in_image = object_mapper_.MapVkImage(image);
    const VkClearDepthStencilValue* in_pDepthStencil = reinterpret_cast<const VkClearDepthStencilValue*>(pDepthStencil.GetPointer());
    const VkImageSubresourceRange* in_pRanges = reinterpret_cast<const VkImageSubresourceRange*>(pRanges.GetPointer());

    vkCmdClearDepthStencilImage(in_commandBuffer, in_image, imageLayout, in_pDepthStencil, rangeCount, in_pRanges);
}

void VulkanReplayConsumer::Process_vkCmdClearAttachments(
    HandleId                                    commandBuffer,
    uint32_t                                    attachmentCount,
    const StructPointerDecoder<Decoded_VkClearAttachment>& pAttachments,
    uint32_t                                    rectCount,
    const StructPointerDecoder<Decoded_VkClearRect>& pRects)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkClearAttachment* in_pAttachments = reinterpret_cast<const VkClearAttachment*>(pAttachments.GetPointer());
    const VkClearRect* in_pRects = reinterpret_cast<const VkClearRect*>(pRects.GetPointer());

    vkCmdClearAttachments(in_commandBuffer, attachmentCount, in_pAttachments, rectCount, in_pRects);
}

void VulkanReplayConsumer::Process_vkCmdResolveImage(
    HandleId                                    commandBuffer,
    HandleId                                    srcImage,
    VkImageLayout                               srcImageLayout,
    HandleId                                    dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkImageResolve>& pRegions)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkImage in_srcImage = object_mapper_.MapVkImage(srcImage);
    VkImage in_dstImage = object_mapper_.MapVkImage(dstImage);
    const VkImageResolve* in_pRegions = reinterpret_cast<const VkImageResolve*>(pRegions.GetPointer());

    vkCmdResolveImage(in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdSetEvent(
    HandleId                                    commandBuffer,
    HandleId                                    event,
    VkPipelineStageFlags                        stageMask)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkEvent in_event = object_mapper_.MapVkEvent(event);

    vkCmdSetEvent(in_commandBuffer, in_event, stageMask);
}

void VulkanReplayConsumer::Process_vkCmdResetEvent(
    HandleId                                    commandBuffer,
    HandleId                                    event,
    VkPipelineStageFlags                        stageMask)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkEvent in_event = object_mapper_.MapVkEvent(event);

    vkCmdResetEvent(in_commandBuffer, in_event, stageMask);
}

void VulkanReplayConsumer::Process_vkCmdWaitEvents(
    HandleId                                    commandBuffer,
    uint32_t                                    eventCount,
    const PointerDecoder<HandleId>&             pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const StructPointerDecoder<Decoded_VkMemoryBarrier>& pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>& pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkImageMemoryBarrier>& pImageMemoryBarriers)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkEvent* in_pEvents = pEvents.IsNull() ? nullptr : AllocateArray<VkEvent>(eventCount);
    MapHandles<VkEvent>(pEvents.GetPointer(), pEvents.GetLength(), in_pEvents, eventCount, &VulkanObjectMapper::MapVkEvent);
    const VkMemoryBarrier* in_pMemoryBarriers = reinterpret_cast<const VkMemoryBarrier*>(pMemoryBarriers.GetPointer());
    VkBufferMemoryBarrier* in_pBufferMemoryBarriers = reinterpret_cast<VkBufferMemoryBarrier*>(pBufferMemoryBarriers.GetPointer());
    if (!pBufferMemoryBarriers.IsNull())
    {
        const Decoded_VkBufferMemoryBarrier* in_pBufferMemoryBarriers_wrapper = pBufferMemoryBarriers.GetMetaStructPointer();
        assert(bufferMemoryBarrierCount == pBufferMemoryBarriers.GetLength());
        for (size_t i = 0; i < bufferMemoryBarrierCount; ++i)
        {
            in_pBufferMemoryBarriers[i].buffer = object_mapper_.MapVkBuffer(in_pBufferMemoryBarriers_wrapper[i].buffer);
        }
    }
    VkImageMemoryBarrier* in_pImageMemoryBarriers = reinterpret_cast<VkImageMemoryBarrier*>(pImageMemoryBarriers.GetPointer());
    if (!pImageMemoryBarriers.IsNull())
    {
        const Decoded_VkImageMemoryBarrier* in_pImageMemoryBarriers_wrapper = pImageMemoryBarriers.GetMetaStructPointer();
        assert(imageMemoryBarrierCount == pImageMemoryBarriers.GetLength());
        for (size_t i = 0; i < imageMemoryBarrierCount; ++i)
        {
            in_pImageMemoryBarriers[i].image = object_mapper_.MapVkImage(in_pImageMemoryBarriers_wrapper[i].image);
        }
    }

    vkCmdWaitEvents(in_commandBuffer, eventCount, in_pEvents, srcStageMask, dstStageMask, memoryBarrierCount, in_pMemoryBarriers, bufferMemoryBarrierCount, in_pBufferMemoryBarriers, imageMemoryBarrierCount, in_pImageMemoryBarriers);

    FreeArray<VkEvent>(&in_pEvents);
}

void VulkanReplayConsumer::Process_vkCmdPipelineBarrier(
    HandleId                                    commandBuffer,
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
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkMemoryBarrier* in_pMemoryBarriers = reinterpret_cast<const VkMemoryBarrier*>(pMemoryBarriers.GetPointer());
    VkBufferMemoryBarrier* in_pBufferMemoryBarriers = reinterpret_cast<VkBufferMemoryBarrier*>(pBufferMemoryBarriers.GetPointer());
    if (!pBufferMemoryBarriers.IsNull())
    {
        const Decoded_VkBufferMemoryBarrier* in_pBufferMemoryBarriers_wrapper = pBufferMemoryBarriers.GetMetaStructPointer();
        assert(bufferMemoryBarrierCount == pBufferMemoryBarriers.GetLength());
        for (size_t i = 0; i < bufferMemoryBarrierCount; ++i)
        {
            in_pBufferMemoryBarriers[i].buffer = object_mapper_.MapVkBuffer(in_pBufferMemoryBarriers_wrapper[i].buffer);
        }
    }
    VkImageMemoryBarrier* in_pImageMemoryBarriers = reinterpret_cast<VkImageMemoryBarrier*>(pImageMemoryBarriers.GetPointer());
    if (!pImageMemoryBarriers.IsNull())
    {
        const Decoded_VkImageMemoryBarrier* in_pImageMemoryBarriers_wrapper = pImageMemoryBarriers.GetMetaStructPointer();
        assert(imageMemoryBarrierCount == pImageMemoryBarriers.GetLength());
        for (size_t i = 0; i < imageMemoryBarrierCount; ++i)
        {
            in_pImageMemoryBarriers[i].image = object_mapper_.MapVkImage(in_pImageMemoryBarriers_wrapper[i].image);
        }
    }

    vkCmdPipelineBarrier(in_commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, in_pMemoryBarriers, bufferMemoryBarrierCount, in_pBufferMemoryBarriers, imageMemoryBarrierCount, in_pImageMemoryBarriers);
}

void VulkanReplayConsumer::Process_vkCmdBeginQuery(
    HandleId                                    commandBuffer,
    HandleId                                    queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkQueryPool in_queryPool = object_mapper_.MapVkQueryPool(queryPool);

    vkCmdBeginQuery(in_commandBuffer, in_queryPool, query, flags);
}

void VulkanReplayConsumer::Process_vkCmdEndQuery(
    HandleId                                    commandBuffer,
    HandleId                                    queryPool,
    uint32_t                                    query)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkQueryPool in_queryPool = object_mapper_.MapVkQueryPool(queryPool);

    vkCmdEndQuery(in_commandBuffer, in_queryPool, query);
}

void VulkanReplayConsumer::Process_vkCmdResetQueryPool(
    HandleId                                    commandBuffer,
    HandleId                                    queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkQueryPool in_queryPool = object_mapper_.MapVkQueryPool(queryPool);

    vkCmdResetQueryPool(in_commandBuffer, in_queryPool, firstQuery, queryCount);
}

void VulkanReplayConsumer::Process_vkCmdWriteTimestamp(
    HandleId                                    commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    HandleId                                    queryPool,
    uint32_t                                    query)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkQueryPool in_queryPool = object_mapper_.MapVkQueryPool(queryPool);

    vkCmdWriteTimestamp(in_commandBuffer, pipelineStage, in_queryPool, query);
}

void VulkanReplayConsumer::Process_vkCmdCopyQueryPoolResults(
    HandleId                                    commandBuffer,
    HandleId                                    queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    HandleId                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkQueryPool in_queryPool = object_mapper_.MapVkQueryPool(queryPool);
    VkBuffer in_dstBuffer = object_mapper_.MapVkBuffer(dstBuffer);

    vkCmdCopyQueryPoolResults(in_commandBuffer, in_queryPool, firstQuery, queryCount, in_dstBuffer, dstOffset, stride, flags);
}

void VulkanReplayConsumer::Process_vkCmdPushConstants(
    HandleId                                    commandBuffer,
    HandleId                                    layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const PointerDecoder<uint8_t>&              pValues)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkPipelineLayout in_layout = object_mapper_.MapVkPipelineLayout(layout);
    const void* in_pValues = reinterpret_cast<const void*>(pValues.GetPointer());

    vkCmdPushConstants(in_commandBuffer, in_layout, stageFlags, offset, size, in_pValues);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass(
    HandleId                                    commandBuffer,
    const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
    VkSubpassContents                           contents)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkRenderPassBeginInfo* in_pRenderPassBegin = reinterpret_cast<VkRenderPassBeginInfo*>(pRenderPassBegin.GetPointer());
    if (!pRenderPassBegin.IsNull())
    {
        const Decoded_VkRenderPassBeginInfo* in_pRenderPassBegin_wrapper = pRenderPassBegin.GetMetaStructPointer();
        in_pRenderPassBegin->renderPass = object_mapper_.MapVkRenderPass(in_pRenderPassBegin_wrapper->renderPass);
        in_pRenderPassBegin->framebuffer = object_mapper_.MapVkFramebuffer(in_pRenderPassBegin_wrapper->framebuffer);
    }

    vkCmdBeginRenderPass(in_commandBuffer, in_pRenderPassBegin, contents);
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass(
    HandleId                                    commandBuffer,
    VkSubpassContents                           contents)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdNextSubpass(in_commandBuffer, contents);
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass(
    HandleId                                    commandBuffer)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdEndRenderPass(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdExecuteCommands(
    HandleId                                    commandBuffer,
    uint32_t                                    commandBufferCount,
    const PointerDecoder<HandleId>&             pCommandBuffers)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkCommandBuffer* in_pCommandBuffers = pCommandBuffers.IsNull() ? nullptr : AllocateArray<VkCommandBuffer>(commandBufferCount);
    MapHandles<VkCommandBuffer>(pCommandBuffers.GetPointer(), pCommandBuffers.GetLength(), in_pCommandBuffers, commandBufferCount, &VulkanObjectMapper::MapVkCommandBuffer);

    vkCmdExecuteCommands(in_commandBuffer, commandBufferCount, in_pCommandBuffers);

    FreeArray<VkCommandBuffer>(&in_pCommandBuffers);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory2(
    VkResult                                    returnValue,
    HandleId                                    device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkBindBufferMemoryInfo* in_pBindInfos = reinterpret_cast<VkBindBufferMemoryInfo*>(pBindInfos.GetPointer());
    if (!pBindInfos.IsNull())
    {
        const Decoded_VkBindBufferMemoryInfo* in_pBindInfos_wrapper = pBindInfos.GetMetaStructPointer();
        assert(bindInfoCount == pBindInfos.GetLength());
        for (size_t i = 0; i < bindInfoCount; ++i)
        {
            in_pBindInfos[i].buffer = object_mapper_.MapVkBuffer(in_pBindInfos_wrapper[i].buffer);
            in_pBindInfos[i].memory = object_mapper_.MapVkDeviceMemory(in_pBindInfos_wrapper[i].memory);
        }
    }

    vkBindBufferMemory2(in_device, bindInfoCount, in_pBindInfos);
}

void VulkanReplayConsumer::Process_vkBindImageMemory2(
    VkResult                                    returnValue,
    HandleId                                    device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkBindImageMemoryInfo* in_pBindInfos = reinterpret_cast<VkBindImageMemoryInfo*>(pBindInfos.GetPointer());
    if (!pBindInfos.IsNull())
    {
        const Decoded_VkBindImageMemoryInfo* in_pBindInfos_wrapper = pBindInfos.GetMetaStructPointer();
        assert(bindInfoCount == pBindInfos.GetLength());
        for (size_t i = 0; i < bindInfoCount; ++i)
        {
            in_pBindInfos[i].image = object_mapper_.MapVkImage(in_pBindInfos_wrapper[i].image);
            in_pBindInfos[i].memory = object_mapper_.MapVkDeviceMemory(in_pBindInfos_wrapper[i].memory);
        }
    }

    vkBindImageMemory2(in_device, bindInfoCount, in_pBindInfos);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    HandleId                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    const PointerDecoder<VkPeerMemoryFeatureFlags>& pPeerMemoryFeatures)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkPeerMemoryFeatureFlags out_pPeerMemoryFeatures_value = static_cast<VkPeerMemoryFeatureFlags>(0);
    VkPeerMemoryFeatureFlags* out_pPeerMemoryFeatures = &out_pPeerMemoryFeatures_value;

    vkGetDeviceGroupPeerMemoryFeatures(in_device, heapIndex, localDeviceIndex, remoteDeviceIndex, out_pPeerMemoryFeatures);
}

void VulkanReplayConsumer::Process_vkCmdSetDeviceMask(
    HandleId                                    commandBuffer,
    uint32_t                                    deviceMask)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdSetDeviceMask(in_commandBuffer, deviceMask);
}

void VulkanReplayConsumer::Process_vkCmdDispatchBase(
    HandleId                                    commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdDispatchBase(in_commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const PointerDecoder<uint32_t>&             pPhysicalDeviceGroupCount,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>& pPhysicalDeviceGroupProperties)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    uint32_t out_pPhysicalDeviceGroupCount_value = pPhysicalDeviceGroupCount.IsNull() ? static_cast<uint32_t>(0) : *(pPhysicalDeviceGroupCount.GetPointer());
    uint32_t* out_pPhysicalDeviceGroupCount = &out_pPhysicalDeviceGroupCount_value;
    VkPhysicalDeviceGroupProperties* out_pPhysicalDeviceGroupProperties = pPhysicalDeviceGroupProperties.IsNull() ? nullptr : AllocateArray<VkPhysicalDeviceGroupProperties>(out_pPhysicalDeviceGroupCount_value);

    vkEnumeratePhysicalDeviceGroups(in_instance, out_pPhysicalDeviceGroupCount, out_pPhysicalDeviceGroupProperties);

    FreeArray<VkPhysicalDeviceGroupProperties>(&out_pPhysicalDeviceGroupProperties);
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements2(
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
    const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImageMemoryRequirementsInfo2* in_pInfo = reinterpret_cast<VkImageMemoryRequirementsInfo2*>(pInfo.GetPointer());
    if (!pInfo.IsNull())
    {
        const Decoded_VkImageMemoryRequirementsInfo2* in_pInfo_wrapper = pInfo.GetMetaStructPointer();
        in_pInfo->image = object_mapper_.MapVkImage(in_pInfo_wrapper->image);
    }
    VkMemoryRequirements2 out_pMemoryRequirements_value = {};
    VkMemoryRequirements2* out_pMemoryRequirements = &out_pMemoryRequirements_value;

    vkGetImageMemoryRequirements2(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements2(
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
    const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkBufferMemoryRequirementsInfo2* in_pInfo = reinterpret_cast<VkBufferMemoryRequirementsInfo2*>(pInfo.GetPointer());
    if (!pInfo.IsNull())
    {
        const Decoded_VkBufferMemoryRequirementsInfo2* in_pInfo_wrapper = pInfo.GetMetaStructPointer();
        in_pInfo->buffer = object_mapper_.MapVkBuffer(in_pInfo_wrapper->buffer);
    }
    VkMemoryRequirements2 out_pMemoryRequirements_value = {};
    VkMemoryRequirements2* out_pMemoryRequirements = &out_pMemoryRequirements_value;

    vkGetBufferMemoryRequirements2(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements2(
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
    const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
    const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>& pSparseMemoryRequirements)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImageSparseMemoryRequirementsInfo2* in_pInfo = reinterpret_cast<VkImageSparseMemoryRequirementsInfo2*>(pInfo.GetPointer());
    if (!pInfo.IsNull())
    {
        const Decoded_VkImageSparseMemoryRequirementsInfo2* in_pInfo_wrapper = pInfo.GetMetaStructPointer();
        in_pInfo->image = object_mapper_.MapVkImage(in_pInfo_wrapper->image);
    }
    uint32_t out_pSparseMemoryRequirementCount_value = pSparseMemoryRequirementCount.IsNull() ? static_cast<uint32_t>(0) : *(pSparseMemoryRequirementCount.GetPointer());
    uint32_t* out_pSparseMemoryRequirementCount = &out_pSparseMemoryRequirementCount_value;
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements.IsNull() ? nullptr : AllocateArray<VkSparseImageMemoryRequirements2>(out_pSparseMemoryRequirementCount_value);

    vkGetImageSparseMemoryRequirements2(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    FreeArray<VkSparseImageMemoryRequirements2>(&out_pSparseMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures2(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>& pFeatures)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkPhysicalDeviceFeatures2 out_pFeatures_value = {};
    VkPhysicalDeviceFeatures2* out_pFeatures = &out_pFeatures_value;

    vkGetPhysicalDeviceFeatures2(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties2(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>& pProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkPhysicalDeviceProperties2 out_pProperties_value = {};
    VkPhysicalDeviceProperties2* out_pProperties = &out_pProperties_value;

    vkGetPhysicalDeviceProperties2(in_physicalDevice, out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    HandleId                                    physicalDevice,
    VkFormat                                    format,
    const StructPointerDecoder<Decoded_VkFormatProperties2>& pFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkFormatProperties2 out_pFormatProperties_value = {};
    VkFormatProperties2* out_pFormatProperties = &out_pFormatProperties_value;

    vkGetPhysicalDeviceFormatProperties2(in_physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
    const StructPointerDecoder<Decoded_VkImageFormatProperties2>& pImageFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    const VkPhysicalDeviceImageFormatInfo2* in_pImageFormatInfo = reinterpret_cast<const VkPhysicalDeviceImageFormatInfo2*>(pImageFormatInfo.GetPointer());
    VkImageFormatProperties2 out_pImageFormatProperties_value = {};
    VkImageFormatProperties2* out_pImageFormatProperties = &out_pImageFormatProperties_value;

    vkGetPhysicalDeviceImageFormatProperties2(in_physicalDevice, in_pImageFormatInfo, out_pImageFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    HandleId                                    physicalDevice,
    const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
    const StructPointerDecoder<Decoded_VkQueueFamilyProperties2>& pQueueFamilyProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    uint32_t out_pQueueFamilyPropertyCount_value = pQueueFamilyPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pQueueFamilyPropertyCount.GetPointer());
    uint32_t* out_pQueueFamilyPropertyCount = &out_pQueueFamilyPropertyCount_value;
    VkQueueFamilyProperties2* out_pQueueFamilyProperties = pQueueFamilyProperties.IsNull() ? nullptr : AllocateArray<VkQueueFamilyProperties2>(out_pQueueFamilyPropertyCount_value);

    vkGetPhysicalDeviceQueueFamilyProperties2(in_physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);

    FreeArray<VkQueueFamilyProperties2>(&out_pQueueFamilyProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>& pMemoryProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkPhysicalDeviceMemoryProperties2 out_pMemoryProperties_value = {};
    VkPhysicalDeviceMemoryProperties2* out_pMemoryProperties = &out_pMemoryProperties_value;

    vkGetPhysicalDeviceMemoryProperties2(in_physicalDevice, out_pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>& pProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    const VkPhysicalDeviceSparseImageFormatInfo2* in_pFormatInfo = reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2*>(pFormatInfo.GetPointer());
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkSparseImageFormatProperties2* out_pProperties = pProperties.IsNull() ? nullptr : AllocateArray<VkSparseImageFormatProperties2>(out_pPropertyCount_value);

    vkGetPhysicalDeviceSparseImageFormatProperties2(in_physicalDevice, in_pFormatInfo, out_pPropertyCount, out_pProperties);

    FreeArray<VkSparseImageFormatProperties2>(&out_pProperties);
}

void VulkanReplayConsumer::Process_vkTrimCommandPool(
    HandleId                                    device,
    HandleId                                    commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkCommandPool in_commandPool = object_mapper_.MapVkCommandPool(commandPool);

    vkTrimCommandPool(in_device, in_commandPool, flags);
}

void VulkanReplayConsumer::Process_vkGetDeviceQueue2(
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDeviceQueueInfo2>& pQueueInfo,
    const PointerDecoder<HandleId>&             pQueue)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkDeviceQueueInfo2* in_pQueueInfo = reinterpret_cast<const VkDeviceQueueInfo2*>(pQueueInfo.GetPointer());
    VkQueue out_pQueue_value = static_cast<VkQueue>(0);
    VkQueue* out_pQueue = &out_pQueue_value;

    vkGetDeviceQueue2(in_device, in_pQueueInfo, out_pQueue);

    AddHandles<VkQueue>(pQueue.GetPointer(), 1, out_pQueue, 1, &VulkanObjectMapper::AddVkQueue);
}

void VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversion(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pYcbcrConversion)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkSamplerYcbcrConversionCreateInfo* in_pCreateInfo = reinterpret_cast<const VkSamplerYcbcrConversionCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSamplerYcbcrConversion out_pYcbcrConversion_value = static_cast<VkSamplerYcbcrConversion>(0);
    VkSamplerYcbcrConversion* out_pYcbcrConversion = &out_pYcbcrConversion_value;

    vkCreateSamplerYcbcrConversion(in_device, in_pCreateInfo, in_pAllocator, out_pYcbcrConversion);

    AddHandles<VkSamplerYcbcrConversion>(pYcbcrConversion.GetPointer(), 1, out_pYcbcrConversion, 1, &VulkanObjectMapper::AddVkSamplerYcbcrConversion);
}

void VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversion(
    HandleId                                    device,
    HandleId                                    ycbcrConversion,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSamplerYcbcrConversion in_ycbcrConversion = object_mapper_.MapVkSamplerYcbcrConversion(ycbcrConversion);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroySamplerYcbcrConversion(in_device, in_ycbcrConversion, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplate(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pDescriptorUpdateTemplate)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDescriptorUpdateTemplateCreateInfo* in_pCreateInfo = reinterpret_cast<VkDescriptorUpdateTemplateCreateInfo*>(pCreateInfo.GetPointer());
    if (!pCreateInfo.IsNull())
    {
        const Decoded_VkDescriptorUpdateTemplateCreateInfo* in_pCreateInfo_wrapper = pCreateInfo.GetMetaStructPointer();
        in_pCreateInfo->descriptorSetLayout = object_mapper_.MapVkDescriptorSetLayout(in_pCreateInfo_wrapper->descriptorSetLayout);
        in_pCreateInfo->pipelineLayout = object_mapper_.MapVkPipelineLayout(in_pCreateInfo_wrapper->pipelineLayout);
    }
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDescriptorUpdateTemplate out_pDescriptorUpdateTemplate_value = static_cast<VkDescriptorUpdateTemplate>(0);
    VkDescriptorUpdateTemplate* out_pDescriptorUpdateTemplate = &out_pDescriptorUpdateTemplate_value;

    vkCreateDescriptorUpdateTemplate(in_device, in_pCreateInfo, in_pAllocator, out_pDescriptorUpdateTemplate);

    AddHandles<VkDescriptorUpdateTemplate>(pDescriptorUpdateTemplate.GetPointer(), 1, out_pDescriptorUpdateTemplate, 1, &VulkanObjectMapper::AddVkDescriptorUpdateTemplate);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    HandleId                                    device,
    HandleId                                    descriptorUpdateTemplate,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = object_mapper_.MapVkDescriptorUpdateTemplate(descriptorUpdateTemplate);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDescriptorUpdateTemplate(in_device, in_descriptorUpdateTemplate, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkUpdateDescriptorSetWithTemplate(
    HandleId                                    device,
    HandleId                                    descriptorSet,
    HandleId                                    descriptorUpdateTemplate,
    uint64_t                                    pData)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDescriptorSet in_descriptorSet = object_mapper_.MapVkDescriptorSet(descriptorSet);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = object_mapper_.MapVkDescriptorUpdateTemplate(descriptorUpdateTemplate);
    const void* in_pData = nullptr;

    vkUpdateDescriptorSetWithTemplate(in_device, in_descriptorSet, in_descriptorUpdateTemplate, in_pData);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
    const StructPointerDecoder<Decoded_VkExternalBufferProperties>& pExternalBufferProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    const VkPhysicalDeviceExternalBufferInfo* in_pExternalBufferInfo = reinterpret_cast<const VkPhysicalDeviceExternalBufferInfo*>(pExternalBufferInfo.GetPointer());
    VkExternalBufferProperties out_pExternalBufferProperties_value = {};
    VkExternalBufferProperties* out_pExternalBufferProperties = &out_pExternalBufferProperties_value;

    vkGetPhysicalDeviceExternalBufferProperties(in_physicalDevice, in_pExternalBufferInfo, out_pExternalBufferProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
    const StructPointerDecoder<Decoded_VkExternalFenceProperties>& pExternalFenceProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    const VkPhysicalDeviceExternalFenceInfo* in_pExternalFenceInfo = reinterpret_cast<const VkPhysicalDeviceExternalFenceInfo*>(pExternalFenceInfo.GetPointer());
    VkExternalFenceProperties out_pExternalFenceProperties_value = {};
    VkExternalFenceProperties* out_pExternalFenceProperties = &out_pExternalFenceProperties_value;

    vkGetPhysicalDeviceExternalFenceProperties(in_physicalDevice, in_pExternalFenceInfo, out_pExternalFenceProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
    const StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>& pExternalSemaphoreProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    const VkPhysicalDeviceExternalSemaphoreInfo* in_pExternalSemaphoreInfo = reinterpret_cast<const VkPhysicalDeviceExternalSemaphoreInfo*>(pExternalSemaphoreInfo.GetPointer());
    VkExternalSemaphoreProperties out_pExternalSemaphoreProperties_value = {};
    VkExternalSemaphoreProperties* out_pExternalSemaphoreProperties = &out_pExternalSemaphoreProperties_value;

    vkGetPhysicalDeviceExternalSemaphoreProperties(in_physicalDevice, in_pExternalSemaphoreInfo, out_pExternalSemaphoreProperties);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutSupport(
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>& pSupport)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(pCreateInfo.GetPointer());
    VkDescriptorSetLayoutSupport out_pSupport_value = {};
    VkDescriptorSetLayoutSupport* out_pSupport = &out_pSupport_value;

    vkGetDescriptorSetLayoutSupport(in_device, in_pCreateInfo, out_pSupport);
}

void VulkanReplayConsumer::Process_vkDestroySurfaceKHR(
    HandleId                                    instance,
    HandleId                                    surface,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    VkSurfaceKHR in_surface = object_mapper_.MapVkSurfaceKHR(surface);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroySurfaceKHR(in_instance, in_surface, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    uint32_t                                    queueFamilyIndex,
    HandleId                                    surface,
    const PointerDecoder<VkBool32>&             pSupported)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkSurfaceKHR in_surface = object_mapper_.MapVkSurfaceKHR(surface);
    VkBool32 out_pSupported_value = static_cast<VkBool32>(0);
    VkBool32* out_pSupported = &out_pSupported_value;

    vkGetPhysicalDeviceSurfaceSupportKHR(in_physicalDevice, queueFamilyIndex, in_surface, out_pSupported);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    HandleId                                    surface,
    const StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>& pSurfaceCapabilities)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkSurfaceKHR in_surface = object_mapper_.MapVkSurfaceKHR(surface);
    VkSurfaceCapabilitiesKHR out_pSurfaceCapabilities_value = {};
    VkSurfaceCapabilitiesKHR* out_pSurfaceCapabilities = &out_pSurfaceCapabilities_value;

    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(in_physicalDevice, in_surface, out_pSurfaceCapabilities);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    HandleId                                    surface,
    const PointerDecoder<uint32_t>&             pSurfaceFormatCount,
    const StructPointerDecoder<Decoded_VkSurfaceFormatKHR>& pSurfaceFormats)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkSurfaceKHR in_surface = object_mapper_.MapVkSurfaceKHR(surface);
    uint32_t out_pSurfaceFormatCount_value = pSurfaceFormatCount.IsNull() ? static_cast<uint32_t>(0) : *(pSurfaceFormatCount.GetPointer());
    uint32_t* out_pSurfaceFormatCount = &out_pSurfaceFormatCount_value;
    VkSurfaceFormatKHR* out_pSurfaceFormats = pSurfaceFormats.IsNull() ? nullptr : AllocateArray<VkSurfaceFormatKHR>(out_pSurfaceFormatCount_value);

    vkGetPhysicalDeviceSurfaceFormatsKHR(in_physicalDevice, in_surface, out_pSurfaceFormatCount, out_pSurfaceFormats);

    FreeArray<VkSurfaceFormatKHR>(&out_pSurfaceFormats);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    HandleId                                    surface,
    const PointerDecoder<uint32_t>&             pPresentModeCount,
    const PointerDecoder<VkPresentModeKHR>&     pPresentModes)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkSurfaceKHR in_surface = object_mapper_.MapVkSurfaceKHR(surface);
    uint32_t out_pPresentModeCount_value = pPresentModeCount.IsNull() ? static_cast<uint32_t>(0) : *(pPresentModeCount.GetPointer());
    uint32_t* out_pPresentModeCount = &out_pPresentModeCount_value;
    VkPresentModeKHR* out_pPresentModes = pPresentModes.IsNull() ? nullptr : AllocateArray<VkPresentModeKHR>(out_pPresentModeCount_value);

    vkGetPhysicalDeviceSurfacePresentModesKHR(in_physicalDevice, in_surface, out_pPresentModeCount, out_pPresentModes);

    FreeArray<VkPresentModeKHR>(&out_pPresentModes);
}

void VulkanReplayConsumer::Process_vkCreateSwapchainKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSwapchain)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSwapchainCreateInfoKHR* in_pCreateInfo = reinterpret_cast<VkSwapchainCreateInfoKHR*>(pCreateInfo.GetPointer());
    if (!pCreateInfo.IsNull())
    {
        const Decoded_VkSwapchainCreateInfoKHR* in_pCreateInfo_wrapper = pCreateInfo.GetMetaStructPointer();
        in_pCreateInfo->surface = object_mapper_.MapVkSurfaceKHR(in_pCreateInfo_wrapper->surface);
        in_pCreateInfo->oldSwapchain = object_mapper_.MapVkSwapchainKHR(in_pCreateInfo_wrapper->oldSwapchain);
    }
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSwapchainKHR out_pSwapchain_value = static_cast<VkSwapchainKHR>(0);
    VkSwapchainKHR* out_pSwapchain = &out_pSwapchain_value;

    vkCreateSwapchainKHR(in_device, in_pCreateInfo, in_pAllocator, out_pSwapchain);

    AddHandles<VkSwapchainKHR>(pSwapchain.GetPointer(), 1, out_pSwapchain, 1, &VulkanObjectMapper::AddVkSwapchainKHR);
}

void VulkanReplayConsumer::Process_vkDestroySwapchainKHR(
    HandleId                                    device,
    HandleId                                    swapchain,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSwapchainKHR in_swapchain = object_mapper_.MapVkSwapchainKHR(swapchain);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroySwapchainKHR(in_device, in_swapchain, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetSwapchainImagesKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    swapchain,
    const PointerDecoder<uint32_t>&             pSwapchainImageCount,
    const PointerDecoder<HandleId>&             pSwapchainImages)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSwapchainKHR in_swapchain = object_mapper_.MapVkSwapchainKHR(swapchain);
    uint32_t out_pSwapchainImageCount_value = pSwapchainImageCount.IsNull() ? static_cast<uint32_t>(0) : *(pSwapchainImageCount.GetPointer());
    uint32_t* out_pSwapchainImageCount = &out_pSwapchainImageCount_value;
    VkImage* out_pSwapchainImages = pSwapchainImages.IsNull() ? nullptr : AllocateArray<VkImage>(out_pSwapchainImageCount_value);

    vkGetSwapchainImagesKHR(in_device, in_swapchain, out_pSwapchainImageCount, out_pSwapchainImages);

    AddHandles<VkImage>(pSwapchainImages.GetPointer(), pSwapchainImages.GetLength(), out_pSwapchainImages, out_pSwapchainImageCount_value, &VulkanObjectMapper::AddVkImage);
    FreeArray<VkImage>(&out_pSwapchainImages);
}

void VulkanReplayConsumer::Process_vkAcquireNextImageKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    swapchain,
    uint64_t                                    timeout,
    HandleId                                    semaphore,
    HandleId                                    fence,
    const PointerDecoder<uint32_t>&             pImageIndex)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSwapchainKHR in_swapchain = object_mapper_.MapVkSwapchainKHR(swapchain);
    VkSemaphore in_semaphore = object_mapper_.MapVkSemaphore(semaphore);
    VkFence in_fence = object_mapper_.MapVkFence(fence);
    uint32_t out_pImageIndex_value = static_cast<uint32_t>(0);
    uint32_t* out_pImageIndex = &out_pImageIndex_value;

    vkAcquireNextImageKHR(in_device, in_swapchain, timeout, in_semaphore, in_fence, out_pImageIndex);
}

void VulkanReplayConsumer::Process_vkQueuePresentKHR(
    VkResult                                    returnValue,
    HandleId                                    queue,
    const StructPointerDecoder<Decoded_VkPresentInfoKHR>& pPresentInfo)
{
    VkQueue in_queue = object_mapper_.MapVkQueue(queue);
    VkPresentInfoKHR* in_pPresentInfo = reinterpret_cast<VkPresentInfoKHR*>(pPresentInfo.GetPointer());
    if (!pPresentInfo.IsNull())
    {
        const Decoded_VkPresentInfoKHR* in_pPresentInfo_wrapper = pPresentInfo.GetMetaStructPointer();
        VkSemaphore* pWaitSemaphores_memory = AllocateArray<VkSemaphore>(in_pPresentInfo->waitSemaphoreCount);
        in_pPresentInfo->pWaitSemaphores = pWaitSemaphores_memory;
        MapHandles<VkSemaphore>(in_pPresentInfo_wrapper->pWaitSemaphores.GetPointer(), in_pPresentInfo_wrapper->pWaitSemaphores.GetLength(), pWaitSemaphores_memory, in_pPresentInfo->waitSemaphoreCount, &VulkanObjectMapper::MapVkSemaphore);
        VkSwapchainKHR* pSwapchains_memory = AllocateArray<VkSwapchainKHR>(in_pPresentInfo->swapchainCount);
        in_pPresentInfo->pSwapchains = pSwapchains_memory;
        MapHandles<VkSwapchainKHR>(in_pPresentInfo_wrapper->pSwapchains.GetPointer(), in_pPresentInfo_wrapper->pSwapchains.GetLength(), pSwapchains_memory, in_pPresentInfo->swapchainCount, &VulkanObjectMapper::MapVkSwapchainKHR);
    }

    vkQueuePresentKHR(in_queue, in_pPresentInfo);

    if (in_pPresentInfo != nullptr)
    {
        FreeArray<VkSemaphore>(&in_pPresentInfo->pWaitSemaphores);
        FreeArray<VkSwapchainKHR>(&in_pPresentInfo->pSwapchains);
    }
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>& pDeviceGroupPresentCapabilities)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDeviceGroupPresentCapabilitiesKHR out_pDeviceGroupPresentCapabilities_value = {};
    VkDeviceGroupPresentCapabilitiesKHR* out_pDeviceGroupPresentCapabilities = &out_pDeviceGroupPresentCapabilities_value;

    vkGetDeviceGroupPresentCapabilitiesKHR(in_device, out_pDeviceGroupPresentCapabilities);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    surface,
    const PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>& pModes)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSurfaceKHR in_surface = object_mapper_.MapVkSurfaceKHR(surface);
    VkDeviceGroupPresentModeFlagsKHR out_pModes_value = static_cast<VkDeviceGroupPresentModeFlagsKHR>(0);
    VkDeviceGroupPresentModeFlagsKHR* out_pModes = &out_pModes_value;

    vkGetDeviceGroupSurfacePresentModesKHR(in_device, in_surface, out_pModes);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    HandleId                                    surface,
    const PointerDecoder<uint32_t>&             pRectCount,
    const StructPointerDecoder<Decoded_VkRect2D>& pRects)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkSurfaceKHR in_surface = object_mapper_.MapVkSurfaceKHR(surface);
    uint32_t out_pRectCount_value = pRectCount.IsNull() ? static_cast<uint32_t>(0) : *(pRectCount.GetPointer());
    uint32_t* out_pRectCount = &out_pRectCount_value;
    VkRect2D* out_pRects = pRects.IsNull() ? nullptr : AllocateArray<VkRect2D>(out_pRectCount_value);

    vkGetPhysicalDevicePresentRectanglesKHR(in_physicalDevice, in_surface, out_pRectCount, out_pRects);

    FreeArray<VkRect2D>(&out_pRects);
}

void VulkanReplayConsumer::Process_vkAcquireNextImage2KHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>& pAcquireInfo,
    const PointerDecoder<uint32_t>&             pImageIndex)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkAcquireNextImageInfoKHR* in_pAcquireInfo = reinterpret_cast<VkAcquireNextImageInfoKHR*>(pAcquireInfo.GetPointer());
    if (!pAcquireInfo.IsNull())
    {
        const Decoded_VkAcquireNextImageInfoKHR* in_pAcquireInfo_wrapper = pAcquireInfo.GetMetaStructPointer();
        in_pAcquireInfo->swapchain = object_mapper_.MapVkSwapchainKHR(in_pAcquireInfo_wrapper->swapchain);
        in_pAcquireInfo->semaphore = object_mapper_.MapVkSemaphore(in_pAcquireInfo_wrapper->semaphore);
        in_pAcquireInfo->fence = object_mapper_.MapVkFence(in_pAcquireInfo_wrapper->fence);
    }
    uint32_t out_pImageIndex_value = static_cast<uint32_t>(0);
    uint32_t* out_pImageIndex = &out_pImageIndex_value;

    vkAcquireNextImage2KHR(in_device, in_pAcquireInfo, out_pImageIndex);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>& pProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkDisplayPropertiesKHR* out_pProperties = pProperties.IsNull() ? nullptr : AllocateArray<VkDisplayPropertiesKHR>(out_pPropertyCount_value);

    vkGetPhysicalDeviceDisplayPropertiesKHR(in_physicalDevice, out_pPropertyCount, out_pProperties);

    FreeArray<VkDisplayPropertiesKHR>(&out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>& pProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkDisplayPlanePropertiesKHR* out_pProperties = pProperties.IsNull() ? nullptr : AllocateArray<VkDisplayPlanePropertiesKHR>(out_pPropertyCount_value);

    vkGetPhysicalDeviceDisplayPlanePropertiesKHR(in_physicalDevice, out_pPropertyCount, out_pProperties);

    FreeArray<VkDisplayPlanePropertiesKHR>(&out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    uint32_t                                    planeIndex,
    const PointerDecoder<uint32_t>&             pDisplayCount,
    const PointerDecoder<HandleId>&             pDisplays)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    uint32_t out_pDisplayCount_value = pDisplayCount.IsNull() ? static_cast<uint32_t>(0) : *(pDisplayCount.GetPointer());
    uint32_t* out_pDisplayCount = &out_pDisplayCount_value;
    VkDisplayKHR* out_pDisplays = pDisplays.IsNull() ? nullptr : AllocateArray<VkDisplayKHR>(out_pDisplayCount_value);

    vkGetDisplayPlaneSupportedDisplaysKHR(in_physicalDevice, planeIndex, out_pDisplayCount, out_pDisplays);

    AddHandles<VkDisplayKHR>(pDisplays.GetPointer(), pDisplays.GetLength(), out_pDisplays, out_pDisplayCount_value, &VulkanObjectMapper::AddVkDisplayKHR);
    FreeArray<VkDisplayKHR>(&out_pDisplays);
}

void VulkanReplayConsumer::Process_vkGetDisplayModePropertiesKHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    HandleId                                    display,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>& pProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkDisplayKHR in_display = object_mapper_.MapVkDisplayKHR(display);
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkDisplayModePropertiesKHR* out_pProperties = pProperties.IsNull() ? nullptr : AllocateArray<VkDisplayModePropertiesKHR>(out_pPropertyCount_value);

    vkGetDisplayModePropertiesKHR(in_physicalDevice, in_display, out_pPropertyCount, out_pProperties);

    FreeArray<VkDisplayModePropertiesKHR>(&out_pProperties);
}

void VulkanReplayConsumer::Process_vkCreateDisplayModeKHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    HandleId                                    display,
    const StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pMode)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkDisplayKHR in_display = object_mapper_.MapVkDisplayKHR(display);
    const VkDisplayModeCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkDisplayModeCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDisplayModeKHR out_pMode_value = static_cast<VkDisplayModeKHR>(0);
    VkDisplayModeKHR* out_pMode = &out_pMode_value;

    vkCreateDisplayModeKHR(in_physicalDevice, in_display, in_pCreateInfo, in_pAllocator, out_pMode);

    AddHandles<VkDisplayModeKHR>(pMode.GetPointer(), 1, out_pMode, 1, &VulkanObjectMapper::AddVkDisplayModeKHR);
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    HandleId                                    mode,
    uint32_t                                    planeIndex,
    const StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>& pCapabilities)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkDisplayModeKHR in_mode = object_mapper_.MapVkDisplayModeKHR(mode);
    VkDisplayPlaneCapabilitiesKHR out_pCapabilities_value = {};
    VkDisplayPlaneCapabilitiesKHR* out_pCapabilities = &out_pCapabilities_value;

    vkGetDisplayPlaneCapabilitiesKHR(in_physicalDevice, in_mode, planeIndex, out_pCapabilities);
}

void VulkanReplayConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSurface)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    VkDisplaySurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<VkDisplaySurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    if (!pCreateInfo.IsNull())
    {
        const Decoded_VkDisplaySurfaceCreateInfoKHR* in_pCreateInfo_wrapper = pCreateInfo.GetMetaStructPointer();
        in_pCreateInfo->displayMode = object_mapper_.MapVkDisplayModeKHR(in_pCreateInfo_wrapper->displayMode);
    }
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateDisplayPlaneSurfaceKHR(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);

    AddHandles<VkSurfaceKHR>(pSurface.GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkCreateSharedSwapchainsKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    uint32_t                                    swapchainCount,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSwapchains)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSwapchainCreateInfoKHR* in_pCreateInfos = reinterpret_cast<VkSwapchainCreateInfoKHR*>(pCreateInfos.GetPointer());
    if (!pCreateInfos.IsNull())
    {
        const Decoded_VkSwapchainCreateInfoKHR* in_pCreateInfos_wrapper = pCreateInfos.GetMetaStructPointer();
        assert(swapchainCount == pCreateInfos.GetLength());
        for (size_t i = 0; i < swapchainCount; ++i)
        {
            in_pCreateInfos[i].surface = object_mapper_.MapVkSurfaceKHR(in_pCreateInfos_wrapper[i].surface);
            in_pCreateInfos[i].oldSwapchain = object_mapper_.MapVkSwapchainKHR(in_pCreateInfos_wrapper[i].oldSwapchain);
        }
    }
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSwapchainKHR* out_pSwapchains = pSwapchains.IsNull() ? nullptr : AllocateArray<VkSwapchainKHR>(swapchainCount);

    vkCreateSharedSwapchainsKHR(in_device, swapchainCount, in_pCreateInfos, in_pAllocator, out_pSwapchains);

    AddHandles<VkSwapchainKHR>(pSwapchains.GetPointer(), pSwapchains.GetLength(), out_pSwapchains, swapchainCount, &VulkanObjectMapper::AddVkSwapchainKHR);
    FreeArray<VkSwapchainKHR>(&out_pSwapchains);
}

#ifdef VK_USE_PLATFORM_XLIB_KHR
void VulkanReplayConsumer::Process_vkCreateXlibSurfaceKHR(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSurface)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const VkXlibSurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkXlibSurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateXlibSurfaceKHR(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);

    AddHandles<VkSurfaceKHR>(pSurface.GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    VkBool32                                    returnValue,
    HandleId                                    physicalDevice,
    uint32_t                                    queueFamilyIndex,
    const PointerDecoder<Display>&              dpy,
    VisualID                                    visualID)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    Display out_dpy_value = static_cast<Display>(0);
    Display* out_dpy = &out_dpy_value;

    vkGetPhysicalDeviceXlibPresentationSupportKHR(in_physicalDevice, queueFamilyIndex, out_dpy, visualID);
}
#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
void VulkanReplayConsumer::Process_vkCreateXcbSurfaceKHR(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSurface)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const VkXcbSurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkXcbSurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateXcbSurfaceKHR(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);

    AddHandles<VkSurfaceKHR>(pSurface.GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    VkBool32                                    returnValue,
    HandleId                                    physicalDevice,
    uint32_t                                    queueFamilyIndex,
    const PointerDecoder<xcb_connection_t>&     connection,
    xcb_visualid_t                              visual_id)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    xcb_connection_t out_connection_value = static_cast<xcb_connection_t>(0);
    xcb_connection_t* out_connection = &out_connection_value;

    vkGetPhysicalDeviceXcbPresentationSupportKHR(in_physicalDevice, queueFamilyIndex, out_connection, visual_id);
}
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
void VulkanReplayConsumer::Process_vkCreateWaylandSurfaceKHR(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSurface)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const VkWaylandSurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkWaylandSurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateWaylandSurfaceKHR(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);

    AddHandles<VkSurfaceKHR>(pSurface.GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    VkBool32                                    returnValue,
    HandleId                                    physicalDevice,
    uint32_t                                    queueFamilyIndex,
    const PointerDecoder<wl_display>&           display)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    wl_display out_display_value = static_cast<wl_display>(0);
    struct wl_display* out_display = &out_display_value;

    vkGetPhysicalDeviceWaylandPresentationSupportKHR(in_physicalDevice, queueFamilyIndex, out_display);
}
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
void VulkanReplayConsumer::Process_vkCreateMirSurfaceKHR(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const StructPointerDecoder<Decoded_VkMirSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSurface)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const VkMirSurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkMirSurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateMirSurfaceKHR(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);

    AddHandles<VkSurfaceKHR>(pSurface.GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMirPresentationSupportKHR(
    VkBool32                                    returnValue,
    HandleId                                    physicalDevice,
    uint32_t                                    queueFamilyIndex,
    const PointerDecoder<MirConnection>&        connection)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    MirConnection out_connection_value = static_cast<MirConnection>(0);
    MirConnection* out_connection = &out_connection_value;

    vkGetPhysicalDeviceMirPresentationSupportKHR(in_physicalDevice, queueFamilyIndex, out_connection);
}
#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
void VulkanReplayConsumer::Process_vkCreateAndroidSurfaceKHR(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSurface)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const VkAndroidSurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkAndroidSurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateAndroidSurfaceKHR(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);

    AddHandles<VkSurfaceKHR>(pSurface.GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanReplayConsumer::Process_vkCreateWin32SurfaceKHR(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSurface)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const VkWin32SurfaceCreateInfoKHR* in_pCreateInfo = reinterpret_cast<const VkWin32SurfaceCreateInfoKHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateWin32SurfaceKHR(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);

    AddHandles<VkSurfaceKHR>(pSurface.GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    VkBool32                                    returnValue,
    HandleId                                    physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);

    vkGetPhysicalDeviceWin32PresentationSupportKHR(in_physicalDevice, queueFamilyIndex);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>& pFeatures)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkPhysicalDeviceFeatures2 out_pFeatures_value = {};
    VkPhysicalDeviceFeatures2* out_pFeatures = &out_pFeatures_value;

    vkGetPhysicalDeviceFeatures2KHR(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>& pProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkPhysicalDeviceProperties2 out_pProperties_value = {};
    VkPhysicalDeviceProperties2* out_pProperties = &out_pProperties_value;

    vkGetPhysicalDeviceProperties2KHR(in_physicalDevice, out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    HandleId                                    physicalDevice,
    VkFormat                                    format,
    const StructPointerDecoder<Decoded_VkFormatProperties2>& pFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkFormatProperties2 out_pFormatProperties_value = {};
    VkFormatProperties2* out_pFormatProperties = &out_pFormatProperties_value;

    vkGetPhysicalDeviceFormatProperties2KHR(in_physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
    const StructPointerDecoder<Decoded_VkImageFormatProperties2>& pImageFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    const VkPhysicalDeviceImageFormatInfo2* in_pImageFormatInfo = reinterpret_cast<const VkPhysicalDeviceImageFormatInfo2*>(pImageFormatInfo.GetPointer());
    VkImageFormatProperties2 out_pImageFormatProperties_value = {};
    VkImageFormatProperties2* out_pImageFormatProperties = &out_pImageFormatProperties_value;

    vkGetPhysicalDeviceImageFormatProperties2KHR(in_physicalDevice, in_pImageFormatInfo, out_pImageFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    HandleId                                    physicalDevice,
    const PointerDecoder<uint32_t>&             pQueueFamilyPropertyCount,
    const StructPointerDecoder<Decoded_VkQueueFamilyProperties2>& pQueueFamilyProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    uint32_t out_pQueueFamilyPropertyCount_value = pQueueFamilyPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pQueueFamilyPropertyCount.GetPointer());
    uint32_t* out_pQueueFamilyPropertyCount = &out_pQueueFamilyPropertyCount_value;
    VkQueueFamilyProperties2* out_pQueueFamilyProperties = pQueueFamilyProperties.IsNull() ? nullptr : AllocateArray<VkQueueFamilyProperties2>(out_pQueueFamilyPropertyCount_value);

    vkGetPhysicalDeviceQueueFamilyProperties2KHR(in_physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);

    FreeArray<VkQueueFamilyProperties2>(&out_pQueueFamilyProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>& pMemoryProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkPhysicalDeviceMemoryProperties2 out_pMemoryProperties_value = {};
    VkPhysicalDeviceMemoryProperties2* out_pMemoryProperties = &out_pMemoryProperties_value;

    vkGetPhysicalDeviceMemoryProperties2KHR(in_physicalDevice, out_pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>& pProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    const VkPhysicalDeviceSparseImageFormatInfo2* in_pFormatInfo = reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2*>(pFormatInfo.GetPointer());
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkSparseImageFormatProperties2* out_pProperties = pProperties.IsNull() ? nullptr : AllocateArray<VkSparseImageFormatProperties2>(out_pPropertyCount_value);

    vkGetPhysicalDeviceSparseImageFormatProperties2KHR(in_physicalDevice, in_pFormatInfo, out_pPropertyCount, out_pProperties);

    FreeArray<VkSparseImageFormatProperties2>(&out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    HandleId                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    const PointerDecoder<VkPeerMemoryFeatureFlags>& pPeerMemoryFeatures)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkPeerMemoryFeatureFlags out_pPeerMemoryFeatures_value = static_cast<VkPeerMemoryFeatureFlags>(0);
    VkPeerMemoryFeatureFlags* out_pPeerMemoryFeatures = &out_pPeerMemoryFeatures_value;

    vkGetDeviceGroupPeerMemoryFeaturesKHR(in_device, heapIndex, localDeviceIndex, remoteDeviceIndex, out_pPeerMemoryFeatures);
}

void VulkanReplayConsumer::Process_vkCmdSetDeviceMaskKHR(
    HandleId                                    commandBuffer,
    uint32_t                                    deviceMask)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdSetDeviceMaskKHR(in_commandBuffer, deviceMask);
}

void VulkanReplayConsumer::Process_vkCmdDispatchBaseKHR(
    HandleId                                    commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdDispatchBaseKHR(in_commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkTrimCommandPoolKHR(
    HandleId                                    device,
    HandleId                                    commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkCommandPool in_commandPool = object_mapper_.MapVkCommandPool(commandPool);

    vkTrimCommandPoolKHR(in_device, in_commandPool, flags);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const PointerDecoder<uint32_t>&             pPhysicalDeviceGroupCount,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>& pPhysicalDeviceGroupProperties)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    uint32_t out_pPhysicalDeviceGroupCount_value = pPhysicalDeviceGroupCount.IsNull() ? static_cast<uint32_t>(0) : *(pPhysicalDeviceGroupCount.GetPointer());
    uint32_t* out_pPhysicalDeviceGroupCount = &out_pPhysicalDeviceGroupCount_value;
    VkPhysicalDeviceGroupProperties* out_pPhysicalDeviceGroupProperties = pPhysicalDeviceGroupProperties.IsNull() ? nullptr : AllocateArray<VkPhysicalDeviceGroupProperties>(out_pPhysicalDeviceGroupCount_value);

    vkEnumeratePhysicalDeviceGroupsKHR(in_instance, out_pPhysicalDeviceGroupCount, out_pPhysicalDeviceGroupProperties);

    FreeArray<VkPhysicalDeviceGroupProperties>(&out_pPhysicalDeviceGroupProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
    const StructPointerDecoder<Decoded_VkExternalBufferProperties>& pExternalBufferProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    const VkPhysicalDeviceExternalBufferInfo* in_pExternalBufferInfo = reinterpret_cast<const VkPhysicalDeviceExternalBufferInfo*>(pExternalBufferInfo.GetPointer());
    VkExternalBufferProperties out_pExternalBufferProperties_value = {};
    VkExternalBufferProperties* out_pExternalBufferProperties = &out_pExternalBufferProperties_value;

    vkGetPhysicalDeviceExternalBufferPropertiesKHR(in_physicalDevice, in_pExternalBufferInfo, out_pExternalBufferProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanReplayConsumer::Process_vkGetMemoryWin32HandleKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
    const PointerDecoder<HANDLE>&               pHandle)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkMemoryGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = reinterpret_cast<VkMemoryGetWin32HandleInfoKHR*>(pGetWin32HandleInfo.GetPointer());
    if (!pGetWin32HandleInfo.IsNull())
    {
        const Decoded_VkMemoryGetWin32HandleInfoKHR* in_pGetWin32HandleInfo_wrapper = pGetWin32HandleInfo.GetMetaStructPointer();
        in_pGetWin32HandleInfo->memory = object_mapper_.MapVkDeviceMemory(in_pGetWin32HandleInfo_wrapper->memory);
    }
    HANDLE out_pHandle_value = static_cast<HANDLE>(0);
    HANDLE* out_pHandle = &out_pHandle_value;

    vkGetMemoryWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
}

void VulkanReplayConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    HANDLE                                      handle,
    const StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>& pMemoryWin32HandleProperties)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkMemoryWin32HandlePropertiesKHR out_pMemoryWin32HandleProperties_value = {};
    VkMemoryWin32HandlePropertiesKHR* out_pMemoryWin32HandleProperties = &out_pMemoryWin32HandleProperties_value;

    vkGetMemoryWin32HandlePropertiesKHR(in_device, handleType, handle, out_pMemoryWin32HandleProperties);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void VulkanReplayConsumer::Process_vkGetMemoryFdKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>& pGetFdInfo,
    const PointerDecoder<int>&                  pFd)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkMemoryGetFdInfoKHR* in_pGetFdInfo = reinterpret_cast<VkMemoryGetFdInfoKHR*>(pGetFdInfo.GetPointer());
    if (!pGetFdInfo.IsNull())
    {
        const Decoded_VkMemoryGetFdInfoKHR* in_pGetFdInfo_wrapper = pGetFdInfo.GetMetaStructPointer();
        in_pGetFdInfo->memory = object_mapper_.MapVkDeviceMemory(in_pGetFdInfo_wrapper->memory);
    }
    int out_pFd_value = static_cast<int>(0);
    int* out_pFd = &out_pFd_value;

    vkGetMemoryFdKHR(in_device, in_pGetFdInfo, out_pFd);
}

void VulkanReplayConsumer::Process_vkGetMemoryFdPropertiesKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    const StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>& pMemoryFdProperties)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkMemoryFdPropertiesKHR out_pMemoryFdProperties_value = {};
    VkMemoryFdPropertiesKHR* out_pMemoryFdProperties = &out_pMemoryFdProperties_value;

    vkGetMemoryFdPropertiesKHR(in_device, handleType, fd, out_pMemoryFdProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
    const StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>& pExternalSemaphoreProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    const VkPhysicalDeviceExternalSemaphoreInfo* in_pExternalSemaphoreInfo = reinterpret_cast<const VkPhysicalDeviceExternalSemaphoreInfo*>(pExternalSemaphoreInfo.GetPointer());
    VkExternalSemaphoreProperties out_pExternalSemaphoreProperties_value = {};
    VkExternalSemaphoreProperties* out_pExternalSemaphoreProperties = &out_pExternalSemaphoreProperties_value;

    vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(in_physicalDevice, in_pExternalSemaphoreInfo, out_pExternalSemaphoreProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanReplayConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>& pImportSemaphoreWin32HandleInfo)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImportSemaphoreWin32HandleInfoKHR* in_pImportSemaphoreWin32HandleInfo = reinterpret_cast<VkImportSemaphoreWin32HandleInfoKHR*>(pImportSemaphoreWin32HandleInfo.GetPointer());
    if (!pImportSemaphoreWin32HandleInfo.IsNull())
    {
        const Decoded_VkImportSemaphoreWin32HandleInfoKHR* in_pImportSemaphoreWin32HandleInfo_wrapper = pImportSemaphoreWin32HandleInfo.GetMetaStructPointer();
        in_pImportSemaphoreWin32HandleInfo->semaphore = object_mapper_.MapVkSemaphore(in_pImportSemaphoreWin32HandleInfo_wrapper->semaphore);
    }

    vkImportSemaphoreWin32HandleKHR(in_device, in_pImportSemaphoreWin32HandleInfo);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
    const PointerDecoder<HANDLE>&               pHandle)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSemaphoreGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = reinterpret_cast<VkSemaphoreGetWin32HandleInfoKHR*>(pGetWin32HandleInfo.GetPointer());
    if (!pGetWin32HandleInfo.IsNull())
    {
        const Decoded_VkSemaphoreGetWin32HandleInfoKHR* in_pGetWin32HandleInfo_wrapper = pGetWin32HandleInfo.GetMetaStructPointer();
        in_pGetWin32HandleInfo->semaphore = object_mapper_.MapVkSemaphore(in_pGetWin32HandleInfo_wrapper->semaphore);
    }
    HANDLE out_pHandle_value = static_cast<HANDLE>(0);
    HANDLE* out_pHandle = &out_pHandle_value;

    vkGetSemaphoreWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void VulkanReplayConsumer::Process_vkImportSemaphoreFdKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>& pImportSemaphoreFdInfo)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImportSemaphoreFdInfoKHR* in_pImportSemaphoreFdInfo = reinterpret_cast<VkImportSemaphoreFdInfoKHR*>(pImportSemaphoreFdInfo.GetPointer());
    if (!pImportSemaphoreFdInfo.IsNull())
    {
        const Decoded_VkImportSemaphoreFdInfoKHR* in_pImportSemaphoreFdInfo_wrapper = pImportSemaphoreFdInfo.GetMetaStructPointer();
        in_pImportSemaphoreFdInfo->semaphore = object_mapper_.MapVkSemaphore(in_pImportSemaphoreFdInfo_wrapper->semaphore);
    }

    vkImportSemaphoreFdKHR(in_device, in_pImportSemaphoreFdInfo);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreFdKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>& pGetFdInfo,
    const PointerDecoder<int>&                  pFd)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSemaphoreGetFdInfoKHR* in_pGetFdInfo = reinterpret_cast<VkSemaphoreGetFdInfoKHR*>(pGetFdInfo.GetPointer());
    if (!pGetFdInfo.IsNull())
    {
        const Decoded_VkSemaphoreGetFdInfoKHR* in_pGetFdInfo_wrapper = pGetFdInfo.GetMetaStructPointer();
        in_pGetFdInfo->semaphore = object_mapper_.MapVkSemaphore(in_pGetFdInfo_wrapper->semaphore);
    }
    int out_pFd_value = static_cast<int>(0);
    int* out_pFd = &out_pFd_value;

    vkGetSemaphoreFdKHR(in_device, in_pGetFdInfo, out_pFd);
}

void VulkanReplayConsumer::Process_vkCmdPushDescriptorSetKHR(
    HandleId                                    commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    HandleId                                    layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkPipelineLayout in_layout = object_mapper_.MapVkPipelineLayout(layout);
    VkWriteDescriptorSet* in_pDescriptorWrites = reinterpret_cast<VkWriteDescriptorSet*>(pDescriptorWrites.GetPointer());
    if (!pDescriptorWrites.IsNull())
    {
        const Decoded_VkWriteDescriptorSet* in_pDescriptorWrites_wrapper = pDescriptorWrites.GetMetaStructPointer();
        assert(descriptorWriteCount == pDescriptorWrites.GetLength());
        for (size_t i = 0; i < descriptorWriteCount; ++i)
        {
            in_pDescriptorWrites[i].dstSet = object_mapper_.MapVkDescriptorSet(in_pDescriptorWrites_wrapper[i].dstSet);
            VkBufferView* pTexelBufferView_memory = AllocateArray<VkBufferView>(in_pDescriptorWrites[i].descriptorCount);
            in_pDescriptorWrites[i].pTexelBufferView = pTexelBufferView_memory;
            MapHandles<VkBufferView>(in_pDescriptorWrites_wrapper[i].pTexelBufferView.GetPointer(), in_pDescriptorWrites_wrapper[i].pTexelBufferView.GetLength(), pTexelBufferView_memory, in_pDescriptorWrites[i].descriptorCount, &VulkanObjectMapper::MapVkBufferView);
        }
    }

    vkCmdPushDescriptorSetKHR(in_commandBuffer, pipelineBindPoint, in_layout, set, descriptorWriteCount, in_pDescriptorWrites);

    if (in_pDescriptorWrites != nullptr)
    {
        for (size_t i = 0; i < descriptorWriteCount; ++i)
        {
            FreeArray<VkBufferView>(&in_pDescriptorWrites[i].pTexelBufferView);
        }
    }
}

void VulkanReplayConsumer::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    HandleId                                    commandBuffer,
    HandleId                                    descriptorUpdateTemplate,
    HandleId                                    layout,
    uint32_t                                    set,
    uint64_t                                    pData)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = object_mapper_.MapVkDescriptorUpdateTemplate(descriptorUpdateTemplate);
    VkPipelineLayout in_layout = object_mapper_.MapVkPipelineLayout(layout);
    const void* in_pData = nullptr;

    vkCmdPushDescriptorSetWithTemplateKHR(in_commandBuffer, in_descriptorUpdateTemplate, in_layout, set, in_pData);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pDescriptorUpdateTemplate)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDescriptorUpdateTemplateCreateInfo* in_pCreateInfo = reinterpret_cast<VkDescriptorUpdateTemplateCreateInfo*>(pCreateInfo.GetPointer());
    if (!pCreateInfo.IsNull())
    {
        const Decoded_VkDescriptorUpdateTemplateCreateInfo* in_pCreateInfo_wrapper = pCreateInfo.GetMetaStructPointer();
        in_pCreateInfo->descriptorSetLayout = object_mapper_.MapVkDescriptorSetLayout(in_pCreateInfo_wrapper->descriptorSetLayout);
        in_pCreateInfo->pipelineLayout = object_mapper_.MapVkPipelineLayout(in_pCreateInfo_wrapper->pipelineLayout);
    }
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDescriptorUpdateTemplate out_pDescriptorUpdateTemplate_value = static_cast<VkDescriptorUpdateTemplate>(0);
    VkDescriptorUpdateTemplate* out_pDescriptorUpdateTemplate = &out_pDescriptorUpdateTemplate_value;

    vkCreateDescriptorUpdateTemplateKHR(in_device, in_pCreateInfo, in_pAllocator, out_pDescriptorUpdateTemplate);

    AddHandles<VkDescriptorUpdateTemplate>(pDescriptorUpdateTemplate.GetPointer(), 1, out_pDescriptorUpdateTemplate, 1, &VulkanObjectMapper::AddVkDescriptorUpdateTemplate);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    HandleId                                    device,
    HandleId                                    descriptorUpdateTemplate,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = object_mapper_.MapVkDescriptorUpdateTemplate(descriptorUpdateTemplate);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDescriptorUpdateTemplateKHR(in_device, in_descriptorUpdateTemplate, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkUpdateDescriptorSetWithTemplateKHR(
    HandleId                                    device,
    HandleId                                    descriptorSet,
    HandleId                                    descriptorUpdateTemplate,
    uint64_t                                    pData)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDescriptorSet in_descriptorSet = object_mapper_.MapVkDescriptorSet(descriptorSet);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = object_mapper_.MapVkDescriptorUpdateTemplate(descriptorUpdateTemplate);
    const void* in_pData = nullptr;

    vkUpdateDescriptorSetWithTemplateKHR(in_device, in_descriptorSet, in_descriptorUpdateTemplate, in_pData);
}

void VulkanReplayConsumer::Process_vkCreateRenderPass2KHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo2KHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pRenderPass)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkRenderPassCreateInfo2KHR* in_pCreateInfo = reinterpret_cast<const VkRenderPassCreateInfo2KHR*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkRenderPass out_pRenderPass_value = static_cast<VkRenderPass>(0);
    VkRenderPass* out_pRenderPass = &out_pRenderPass_value;

    vkCreateRenderPass2KHR(in_device, in_pCreateInfo, in_pAllocator, out_pRenderPass);

    AddHandles<VkRenderPass>(pRenderPass.GetPointer(), 1, out_pRenderPass, 1, &VulkanObjectMapper::AddVkRenderPass);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass2KHR(
    HandleId                                    commandBuffer,
    const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
    const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkRenderPassBeginInfo*      in_pRenderPassBegin = reinterpret_cast<VkRenderPassBeginInfo*     >(pRenderPassBegin.GetPointer());
    if (!pRenderPassBegin.IsNull())
    {
        const Decoded_VkRenderPassBeginInfo* in_pRenderPassBegin_wrapper = pRenderPassBegin.GetMetaStructPointer();
        in_pRenderPassBegin->renderPass = object_mapper_.MapVkRenderPass(in_pRenderPassBegin_wrapper->renderPass);
        in_pRenderPassBegin->framebuffer = object_mapper_.MapVkFramebuffer(in_pRenderPassBegin_wrapper->framebuffer);
    }
    const VkSubpassBeginInfoKHR*      in_pSubpassBeginInfo = reinterpret_cast<const VkSubpassBeginInfoKHR*     >(pSubpassBeginInfo.GetPointer());

    vkCmdBeginRenderPass2KHR(in_commandBuffer, in_pRenderPassBegin, in_pSubpassBeginInfo);
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass2KHR(
    HandleId                                    commandBuffer,
    const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo,
    const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkSubpassBeginInfoKHR*      in_pSubpassBeginInfo = reinterpret_cast<const VkSubpassBeginInfoKHR*     >(pSubpassBeginInfo.GetPointer());
    const VkSubpassEndInfoKHR*        in_pSubpassEndInfo = reinterpret_cast<const VkSubpassEndInfoKHR*       >(pSubpassEndInfo.GetPointer());

    vkCmdNextSubpass2KHR(in_commandBuffer, in_pSubpassBeginInfo, in_pSubpassEndInfo);
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass2KHR(
    HandleId                                    commandBuffer,
    const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkSubpassEndInfoKHR*        in_pSubpassEndInfo = reinterpret_cast<const VkSubpassEndInfoKHR*       >(pSubpassEndInfo.GetPointer());

    vkCmdEndRenderPass2KHR(in_commandBuffer, in_pSubpassEndInfo);
}

void VulkanReplayConsumer::Process_vkGetSwapchainStatusKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    swapchain)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSwapchainKHR in_swapchain = object_mapper_.MapVkSwapchainKHR(swapchain);

    vkGetSwapchainStatusKHR(in_device, in_swapchain);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
    const StructPointerDecoder<Decoded_VkExternalFenceProperties>& pExternalFenceProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    const VkPhysicalDeviceExternalFenceInfo* in_pExternalFenceInfo = reinterpret_cast<const VkPhysicalDeviceExternalFenceInfo*>(pExternalFenceInfo.GetPointer());
    VkExternalFenceProperties out_pExternalFenceProperties_value = {};
    VkExternalFenceProperties* out_pExternalFenceProperties = &out_pExternalFenceProperties_value;

    vkGetPhysicalDeviceExternalFencePropertiesKHR(in_physicalDevice, in_pExternalFenceInfo, out_pExternalFenceProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanReplayConsumer::Process_vkImportFenceWin32HandleKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>& pImportFenceWin32HandleInfo)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImportFenceWin32HandleInfoKHR* in_pImportFenceWin32HandleInfo = reinterpret_cast<VkImportFenceWin32HandleInfoKHR*>(pImportFenceWin32HandleInfo.GetPointer());
    if (!pImportFenceWin32HandleInfo.IsNull())
    {
        const Decoded_VkImportFenceWin32HandleInfoKHR* in_pImportFenceWin32HandleInfo_wrapper = pImportFenceWin32HandleInfo.GetMetaStructPointer();
        in_pImportFenceWin32HandleInfo->fence = object_mapper_.MapVkFence(in_pImportFenceWin32HandleInfo_wrapper->fence);
    }

    vkImportFenceWin32HandleKHR(in_device, in_pImportFenceWin32HandleInfo);
}

void VulkanReplayConsumer::Process_vkGetFenceWin32HandleKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
    const PointerDecoder<HANDLE>&               pHandle)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkFenceGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = reinterpret_cast<VkFenceGetWin32HandleInfoKHR*>(pGetWin32HandleInfo.GetPointer());
    if (!pGetWin32HandleInfo.IsNull())
    {
        const Decoded_VkFenceGetWin32HandleInfoKHR* in_pGetWin32HandleInfo_wrapper = pGetWin32HandleInfo.GetMetaStructPointer();
        in_pGetWin32HandleInfo->fence = object_mapper_.MapVkFence(in_pGetWin32HandleInfo_wrapper->fence);
    }
    HANDLE out_pHandle_value = static_cast<HANDLE>(0);
    HANDLE* out_pHandle = &out_pHandle_value;

    vkGetFenceWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

void VulkanReplayConsumer::Process_vkImportFenceFdKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>& pImportFenceFdInfo)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImportFenceFdInfoKHR* in_pImportFenceFdInfo = reinterpret_cast<VkImportFenceFdInfoKHR*>(pImportFenceFdInfo.GetPointer());
    if (!pImportFenceFdInfo.IsNull())
    {
        const Decoded_VkImportFenceFdInfoKHR* in_pImportFenceFdInfo_wrapper = pImportFenceFdInfo.GetMetaStructPointer();
        in_pImportFenceFdInfo->fence = object_mapper_.MapVkFence(in_pImportFenceFdInfo_wrapper->fence);
    }

    vkImportFenceFdKHR(in_device, in_pImportFenceFdInfo);
}

void VulkanReplayConsumer::Process_vkGetFenceFdKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>& pGetFdInfo,
    const PointerDecoder<int>&                  pFd)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkFenceGetFdInfoKHR* in_pGetFdInfo = reinterpret_cast<VkFenceGetFdInfoKHR*>(pGetFdInfo.GetPointer());
    if (!pGetFdInfo.IsNull())
    {
        const Decoded_VkFenceGetFdInfoKHR* in_pGetFdInfo_wrapper = pGetFdInfo.GetMetaStructPointer();
        in_pGetFdInfo->fence = object_mapper_.MapVkFence(in_pGetFdInfo_wrapper->fence);
    }
    int out_pFd_value = static_cast<int>(0);
    int* out_pFd = &out_pFd_value;

    vkGetFenceFdKHR(in_device, in_pGetFdInfo, out_pFd);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
    const StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>& pSurfaceCapabilities)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = reinterpret_cast<VkPhysicalDeviceSurfaceInfo2KHR*>(pSurfaceInfo.GetPointer());
    if (!pSurfaceInfo.IsNull())
    {
        const Decoded_VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo_wrapper = pSurfaceInfo.GetMetaStructPointer();
        in_pSurfaceInfo->surface = object_mapper_.MapVkSurfaceKHR(in_pSurfaceInfo_wrapper->surface);
    }
    VkSurfaceCapabilities2KHR out_pSurfaceCapabilities_value = {};
    VkSurfaceCapabilities2KHR* out_pSurfaceCapabilities = &out_pSurfaceCapabilities_value;

    vkGetPhysicalDeviceSurfaceCapabilities2KHR(in_physicalDevice, in_pSurfaceInfo, out_pSurfaceCapabilities);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
    const PointerDecoder<uint32_t>&             pSurfaceFormatCount,
    const StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>& pSurfaceFormats)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = reinterpret_cast<VkPhysicalDeviceSurfaceInfo2KHR*>(pSurfaceInfo.GetPointer());
    if (!pSurfaceInfo.IsNull())
    {
        const Decoded_VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo_wrapper = pSurfaceInfo.GetMetaStructPointer();
        in_pSurfaceInfo->surface = object_mapper_.MapVkSurfaceKHR(in_pSurfaceInfo_wrapper->surface);
    }
    uint32_t out_pSurfaceFormatCount_value = pSurfaceFormatCount.IsNull() ? static_cast<uint32_t>(0) : *(pSurfaceFormatCount.GetPointer());
    uint32_t* out_pSurfaceFormatCount = &out_pSurfaceFormatCount_value;
    VkSurfaceFormat2KHR* out_pSurfaceFormats = pSurfaceFormats.IsNull() ? nullptr : AllocateArray<VkSurfaceFormat2KHR>(out_pSurfaceFormatCount_value);

    vkGetPhysicalDeviceSurfaceFormats2KHR(in_physicalDevice, in_pSurfaceInfo, out_pSurfaceFormatCount, out_pSurfaceFormats);

    FreeArray<VkSurfaceFormat2KHR>(&out_pSurfaceFormats);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayProperties2KHR>& pProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkDisplayProperties2KHR* out_pProperties = pProperties.IsNull() ? nullptr : AllocateArray<VkDisplayProperties2KHR>(out_pPropertyCount_value);

    vkGetPhysicalDeviceDisplayProperties2KHR(in_physicalDevice, out_pPropertyCount, out_pProperties);

    FreeArray<VkDisplayProperties2KHR>(&out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>& pProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkDisplayPlaneProperties2KHR* out_pProperties = pProperties.IsNull() ? nullptr : AllocateArray<VkDisplayPlaneProperties2KHR>(out_pPropertyCount_value);

    vkGetPhysicalDeviceDisplayPlaneProperties2KHR(in_physicalDevice, out_pPropertyCount, out_pProperties);

    FreeArray<VkDisplayPlaneProperties2KHR>(&out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetDisplayModeProperties2KHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    HandleId                                    display,
    const PointerDecoder<uint32_t>&             pPropertyCount,
    const StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>& pProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkDisplayKHR in_display = object_mapper_.MapVkDisplayKHR(display);
    uint32_t out_pPropertyCount_value = pPropertyCount.IsNull() ? static_cast<uint32_t>(0) : *(pPropertyCount.GetPointer());
    uint32_t* out_pPropertyCount = &out_pPropertyCount_value;
    VkDisplayModeProperties2KHR* out_pProperties = pProperties.IsNull() ? nullptr : AllocateArray<VkDisplayModeProperties2KHR>(out_pPropertyCount_value);

    vkGetDisplayModeProperties2KHR(in_physicalDevice, in_display, out_pPropertyCount, out_pProperties);

    FreeArray<VkDisplayModeProperties2KHR>(&out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>& pDisplayPlaneInfo,
    const StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>& pCapabilities)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkDisplayPlaneInfo2KHR* in_pDisplayPlaneInfo = reinterpret_cast<VkDisplayPlaneInfo2KHR*>(pDisplayPlaneInfo.GetPointer());
    if (!pDisplayPlaneInfo.IsNull())
    {
        const Decoded_VkDisplayPlaneInfo2KHR* in_pDisplayPlaneInfo_wrapper = pDisplayPlaneInfo.GetMetaStructPointer();
        in_pDisplayPlaneInfo->mode = object_mapper_.MapVkDisplayModeKHR(in_pDisplayPlaneInfo_wrapper->mode);
    }
    VkDisplayPlaneCapabilities2KHR out_pCapabilities_value = {};
    VkDisplayPlaneCapabilities2KHR* out_pCapabilities = &out_pCapabilities_value;

    vkGetDisplayPlaneCapabilities2KHR(in_physicalDevice, in_pDisplayPlaneInfo, out_pCapabilities);
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements2KHR(
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
    const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImageMemoryRequirementsInfo2* in_pInfo = reinterpret_cast<VkImageMemoryRequirementsInfo2*>(pInfo.GetPointer());
    if (!pInfo.IsNull())
    {
        const Decoded_VkImageMemoryRequirementsInfo2* in_pInfo_wrapper = pInfo.GetMetaStructPointer();
        in_pInfo->image = object_mapper_.MapVkImage(in_pInfo_wrapper->image);
    }
    VkMemoryRequirements2 out_pMemoryRequirements_value = {};
    VkMemoryRequirements2* out_pMemoryRequirements = &out_pMemoryRequirements_value;

    vkGetImageMemoryRequirements2KHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
    const StructPointerDecoder<Decoded_VkMemoryRequirements2>& pMemoryRequirements)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkBufferMemoryRequirementsInfo2* in_pInfo = reinterpret_cast<VkBufferMemoryRequirementsInfo2*>(pInfo.GetPointer());
    if (!pInfo.IsNull())
    {
        const Decoded_VkBufferMemoryRequirementsInfo2* in_pInfo_wrapper = pInfo.GetMetaStructPointer();
        in_pInfo->buffer = object_mapper_.MapVkBuffer(in_pInfo_wrapper->buffer);
    }
    VkMemoryRequirements2 out_pMemoryRequirements_value = {};
    VkMemoryRequirements2* out_pMemoryRequirements = &out_pMemoryRequirements_value;

    vkGetBufferMemoryRequirements2KHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
    const PointerDecoder<uint32_t>&             pSparseMemoryRequirementCount,
    const StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>& pSparseMemoryRequirements)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkImageSparseMemoryRequirementsInfo2* in_pInfo = reinterpret_cast<VkImageSparseMemoryRequirementsInfo2*>(pInfo.GetPointer());
    if (!pInfo.IsNull())
    {
        const Decoded_VkImageSparseMemoryRequirementsInfo2* in_pInfo_wrapper = pInfo.GetMetaStructPointer();
        in_pInfo->image = object_mapper_.MapVkImage(in_pInfo_wrapper->image);
    }
    uint32_t out_pSparseMemoryRequirementCount_value = pSparseMemoryRequirementCount.IsNull() ? static_cast<uint32_t>(0) : *(pSparseMemoryRequirementCount.GetPointer());
    uint32_t* out_pSparseMemoryRequirementCount = &out_pSparseMemoryRequirementCount_value;
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements.IsNull() ? nullptr : AllocateArray<VkSparseImageMemoryRequirements2>(out_pSparseMemoryRequirementCount_value);

    vkGetImageSparseMemoryRequirements2KHR(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    FreeArray<VkSparseImageMemoryRequirements2>(&out_pSparseMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pYcbcrConversion)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkSamplerYcbcrConversionCreateInfo* in_pCreateInfo = reinterpret_cast<const VkSamplerYcbcrConversionCreateInfo*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSamplerYcbcrConversion out_pYcbcrConversion_value = static_cast<VkSamplerYcbcrConversion>(0);
    VkSamplerYcbcrConversion* out_pYcbcrConversion = &out_pYcbcrConversion_value;

    vkCreateSamplerYcbcrConversionKHR(in_device, in_pCreateInfo, in_pAllocator, out_pYcbcrConversion);

    AddHandles<VkSamplerYcbcrConversion>(pYcbcrConversion.GetPointer(), 1, out_pYcbcrConversion, 1, &VulkanObjectMapper::AddVkSamplerYcbcrConversion);
}

void VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    HandleId                                    device,
    HandleId                                    ycbcrConversion,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSamplerYcbcrConversion in_ycbcrConversion = object_mapper_.MapVkSamplerYcbcrConversion(ycbcrConversion);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroySamplerYcbcrConversionKHR(in_device, in_ycbcrConversion, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory2KHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkBindBufferMemoryInfo* in_pBindInfos = reinterpret_cast<VkBindBufferMemoryInfo*>(pBindInfos.GetPointer());
    if (!pBindInfos.IsNull())
    {
        const Decoded_VkBindBufferMemoryInfo* in_pBindInfos_wrapper = pBindInfos.GetMetaStructPointer();
        assert(bindInfoCount == pBindInfos.GetLength());
        for (size_t i = 0; i < bindInfoCount; ++i)
        {
            in_pBindInfos[i].buffer = object_mapper_.MapVkBuffer(in_pBindInfos_wrapper[i].buffer);
            in_pBindInfos[i].memory = object_mapper_.MapVkDeviceMemory(in_pBindInfos_wrapper[i].memory);
        }
    }

    vkBindBufferMemory2KHR(in_device, bindInfoCount, in_pBindInfos);
}

void VulkanReplayConsumer::Process_vkBindImageMemory2KHR(
    VkResult                                    returnValue,
    HandleId                                    device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkBindImageMemoryInfo* in_pBindInfos = reinterpret_cast<VkBindImageMemoryInfo*>(pBindInfos.GetPointer());
    if (!pBindInfos.IsNull())
    {
        const Decoded_VkBindImageMemoryInfo* in_pBindInfos_wrapper = pBindInfos.GetMetaStructPointer();
        assert(bindInfoCount == pBindInfos.GetLength());
        for (size_t i = 0; i < bindInfoCount; ++i)
        {
            in_pBindInfos[i].image = object_mapper_.MapVkImage(in_pBindInfos_wrapper[i].image);
            in_pBindInfos[i].memory = object_mapper_.MapVkDeviceMemory(in_pBindInfos_wrapper[i].memory);
        }
    }

    vkBindImageMemory2KHR(in_device, bindInfoCount, in_pBindInfos);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>& pSupport)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(pCreateInfo.GetPointer());
    VkDescriptorSetLayoutSupport out_pSupport_value = {};
    VkDescriptorSetLayoutSupport* out_pSupport = &out_pSupport_value;

    vkGetDescriptorSetLayoutSupportKHR(in_device, in_pCreateInfo, out_pSupport);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectCountKHR(
    HandleId                                    commandBuffer,
    HandleId                                    buffer,
    VkDeviceSize                                offset,
    HandleId                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer in_buffer = object_mapper_.MapVkBuffer(buffer);
    VkBuffer in_countBuffer = object_mapper_.MapVkBuffer(countBuffer);

    vkCmdDrawIndirectCountKHR(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    HandleId                                    commandBuffer,
    HandleId                                    buffer,
    VkDeviceSize                                offset,
    HandleId                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer in_buffer = object_mapper_.MapVkBuffer(buffer);
    VkBuffer in_countBuffer = object_mapper_.MapVkBuffer(countBuffer);

    vkCmdDrawIndexedIndirectCountKHR(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCreateDebugReportCallbackEXT(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pCallback)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const VkDebugReportCallbackCreateInfoEXT* in_pCreateInfo = reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDebugReportCallbackEXT out_pCallback_value = static_cast<VkDebugReportCallbackEXT>(0);
    VkDebugReportCallbackEXT* out_pCallback = &out_pCallback_value;

    vkCreateDebugReportCallbackEXT(in_instance, in_pCreateInfo, in_pAllocator, out_pCallback);

    AddHandles<VkDebugReportCallbackEXT>(pCallback.GetPointer(), 1, out_pCallback, 1, &VulkanObjectMapper::AddVkDebugReportCallbackEXT);
}

void VulkanReplayConsumer::Process_vkDestroyDebugReportCallbackEXT(
    HandleId                                    instance,
    HandleId                                    callback,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    VkDebugReportCallbackEXT in_callback = object_mapper_.MapVkDebugReportCallbackEXT(callback);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDebugReportCallbackEXT(in_instance, in_callback, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkDebugReportMessageEXT(
    HandleId                                    instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    const StringDecoder&                        pLayerPrefix,
    const StringDecoder&                        pMessage)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const char* in_pLayerPrefix = reinterpret_cast<const char*>(pLayerPrefix.GetPointer());
    const char* in_pMessage = reinterpret_cast<const char*>(pMessage.GetPointer());

    vkDebugReportMessageEXT(in_instance, flags, objectType, object, location, messageCode, in_pLayerPrefix, in_pMessage);
}

void VulkanReplayConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>& pTagInfo)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkDebugMarkerObjectTagInfoEXT* in_pTagInfo = reinterpret_cast<const VkDebugMarkerObjectTagInfoEXT*>(pTagInfo.GetPointer());

    vkDebugMarkerSetObjectTagEXT(in_device, in_pTagInfo);
}

void VulkanReplayConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>& pNameInfo)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkDebugMarkerObjectNameInfoEXT* in_pNameInfo = reinterpret_cast<const VkDebugMarkerObjectNameInfoEXT*>(pNameInfo.GetPointer());

    vkDebugMarkerSetObjectNameEXT(in_device, in_pNameInfo);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerBeginEXT(
    HandleId                                    commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkDebugMarkerMarkerInfoEXT* in_pMarkerInfo = reinterpret_cast<const VkDebugMarkerMarkerInfoEXT*>(pMarkerInfo.GetPointer());

    vkCmdDebugMarkerBeginEXT(in_commandBuffer, in_pMarkerInfo);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerEndEXT(
    HandleId                                    commandBuffer)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdDebugMarkerEndEXT(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerInsertEXT(
    HandleId                                    commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkDebugMarkerMarkerInfoEXT* in_pMarkerInfo = reinterpret_cast<const VkDebugMarkerMarkerInfoEXT*>(pMarkerInfo.GetPointer());

    vkCmdDebugMarkerInsertEXT(in_commandBuffer, in_pMarkerInfo);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectCountAMD(
    HandleId                                    commandBuffer,
    HandleId                                    buffer,
    VkDeviceSize                                offset,
    HandleId                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer in_buffer = object_mapper_.MapVkBuffer(buffer);
    VkBuffer in_countBuffer = object_mapper_.MapVkBuffer(countBuffer);

    vkCmdDrawIndirectCountAMD(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    HandleId                                    commandBuffer,
    HandleId                                    buffer,
    VkDeviceSize                                offset,
    HandleId                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer in_buffer = object_mapper_.MapVkBuffer(buffer);
    VkBuffer in_countBuffer = object_mapper_.MapVkBuffer(countBuffer);

    vkCmdDrawIndexedIndirectCountAMD(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkGetShaderInfoAMD(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    const PointerDecoder<size_t>&               pInfoSize,
    const PointerDecoder<uint8_t>&              pInfo)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkPipeline in_pipeline = object_mapper_.MapVkPipeline(pipeline);
    size_t out_pInfoSize_value = pInfoSize.IsNull() ? static_cast<size_t>(0) : *(pInfoSize.GetPointer());
    size_t* out_pInfoSize = &out_pInfoSize_value;
    uint8_t* out_pInfo = pInfo.IsNull() ? nullptr : AllocateArray<uint8_t>(out_pInfoSize_value);

    vkGetShaderInfoAMD(in_device, in_pipeline, shaderStage, infoType, out_pInfoSize, out_pInfo);

    FreeArray<uint8_t>(&out_pInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
    const StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>& pExternalImageFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkExternalImageFormatPropertiesNV out_pExternalImageFormatProperties_value = {};
    VkExternalImageFormatPropertiesNV* out_pExternalImageFormatProperties = &out_pExternalImageFormatProperties_value;

    vkGetPhysicalDeviceExternalImageFormatPropertiesNV(in_physicalDevice, format, type, tiling, usage, flags, externalHandleType, out_pExternalImageFormatProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
void VulkanReplayConsumer::Process_vkGetMemoryWin32HandleNV(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    const PointerDecoder<HANDLE>&               pHandle)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDeviceMemory in_memory = object_mapper_.MapVkDeviceMemory(memory);
    HANDLE out_pHandle_value = static_cast<HANDLE>(0);
    HANDLE* out_pHandle = &out_pHandle_value;

    vkGetMemoryWin32HandleNV(in_device, in_memory, handleType, out_pHandle);
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_VI_NN
void VulkanReplayConsumer::Process_vkCreateViSurfaceNN(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSurface)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const VkViSurfaceCreateInfoNN* in_pCreateInfo = reinterpret_cast<const VkViSurfaceCreateInfoNN*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateViSurfaceNN(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);

    AddHandles<VkSurfaceKHR>(pSurface.GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}
#endif /* VK_USE_PLATFORM_VI_NN */

void VulkanReplayConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    HandleId                                    commandBuffer,
    const StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>& pConditionalRenderingBegin)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkConditionalRenderingBeginInfoEXT* in_pConditionalRenderingBegin = reinterpret_cast<VkConditionalRenderingBeginInfoEXT*>(pConditionalRenderingBegin.GetPointer());
    if (!pConditionalRenderingBegin.IsNull())
    {
        const Decoded_VkConditionalRenderingBeginInfoEXT* in_pConditionalRenderingBegin_wrapper = pConditionalRenderingBegin.GetMetaStructPointer();
        in_pConditionalRenderingBegin->buffer = object_mapper_.MapVkBuffer(in_pConditionalRenderingBegin_wrapper->buffer);
    }

    vkCmdBeginConditionalRenderingEXT(in_commandBuffer, in_pConditionalRenderingBegin);
}

void VulkanReplayConsumer::Process_vkCmdEndConditionalRenderingEXT(
    HandleId                                    commandBuffer)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdEndConditionalRenderingEXT(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdProcessCommandsNVX(
    HandleId                                    commandBuffer,
    const StructPointerDecoder<Decoded_VkCmdProcessCommandsInfoNVX>& pProcessCommandsInfo)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkCmdProcessCommandsInfoNVX* in_pProcessCommandsInfo = reinterpret_cast<VkCmdProcessCommandsInfoNVX*>(pProcessCommandsInfo.GetPointer());
    if (!pProcessCommandsInfo.IsNull())
    {
        const Decoded_VkCmdProcessCommandsInfoNVX* in_pProcessCommandsInfo_wrapper = pProcessCommandsInfo.GetMetaStructPointer();
        in_pProcessCommandsInfo->objectTable = object_mapper_.MapVkObjectTableNVX(in_pProcessCommandsInfo_wrapper->objectTable);
        in_pProcessCommandsInfo->indirectCommandsLayout = object_mapper_.MapVkIndirectCommandsLayoutNVX(in_pProcessCommandsInfo_wrapper->indirectCommandsLayout);
        in_pProcessCommandsInfo->targetCommandBuffer = object_mapper_.MapVkCommandBuffer(in_pProcessCommandsInfo_wrapper->targetCommandBuffer);
        in_pProcessCommandsInfo->sequencesCountBuffer = object_mapper_.MapVkBuffer(in_pProcessCommandsInfo_wrapper->sequencesCountBuffer);
        in_pProcessCommandsInfo->sequencesIndexBuffer = object_mapper_.MapVkBuffer(in_pProcessCommandsInfo_wrapper->sequencesIndexBuffer);
    }

    vkCmdProcessCommandsNVX(in_commandBuffer, in_pProcessCommandsInfo);
}

void VulkanReplayConsumer::Process_vkCmdReserveSpaceForCommandsNVX(
    HandleId                                    commandBuffer,
    const StructPointerDecoder<Decoded_VkCmdReserveSpaceForCommandsInfoNVX>& pReserveSpaceInfo)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkCmdReserveSpaceForCommandsInfoNVX* in_pReserveSpaceInfo = reinterpret_cast<VkCmdReserveSpaceForCommandsInfoNVX*>(pReserveSpaceInfo.GetPointer());
    if (!pReserveSpaceInfo.IsNull())
    {
        const Decoded_VkCmdReserveSpaceForCommandsInfoNVX* in_pReserveSpaceInfo_wrapper = pReserveSpaceInfo.GetMetaStructPointer();
        in_pReserveSpaceInfo->objectTable = object_mapper_.MapVkObjectTableNVX(in_pReserveSpaceInfo_wrapper->objectTable);
        in_pReserveSpaceInfo->indirectCommandsLayout = object_mapper_.MapVkIndirectCommandsLayoutNVX(in_pReserveSpaceInfo_wrapper->indirectCommandsLayout);
    }

    vkCmdReserveSpaceForCommandsNVX(in_commandBuffer, in_pReserveSpaceInfo);
}

void VulkanReplayConsumer::Process_vkCreateIndirectCommandsLayoutNVX(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNVX>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pIndirectCommandsLayout)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkIndirectCommandsLayoutCreateInfoNVX* in_pCreateInfo = reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoNVX*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkIndirectCommandsLayoutNVX out_pIndirectCommandsLayout_value = static_cast<VkIndirectCommandsLayoutNVX>(0);
    VkIndirectCommandsLayoutNVX* out_pIndirectCommandsLayout = &out_pIndirectCommandsLayout_value;

    vkCreateIndirectCommandsLayoutNVX(in_device, in_pCreateInfo, in_pAllocator, out_pIndirectCommandsLayout);

    AddHandles<VkIndirectCommandsLayoutNVX>(pIndirectCommandsLayout.GetPointer(), 1, out_pIndirectCommandsLayout, 1, &VulkanObjectMapper::AddVkIndirectCommandsLayoutNVX);
}

void VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutNVX(
    HandleId                                    device,
    HandleId                                    indirectCommandsLayout,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkIndirectCommandsLayoutNVX in_indirectCommandsLayout = object_mapper_.MapVkIndirectCommandsLayoutNVX(indirectCommandsLayout);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyIndirectCommandsLayoutNVX(in_device, in_indirectCommandsLayout, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateObjectTableNVX(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkObjectTableCreateInfoNVX>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pObjectTable)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkObjectTableCreateInfoNVX* in_pCreateInfo = reinterpret_cast<const VkObjectTableCreateInfoNVX*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkObjectTableNVX out_pObjectTable_value = static_cast<VkObjectTableNVX>(0);
    VkObjectTableNVX* out_pObjectTable = &out_pObjectTable_value;

    vkCreateObjectTableNVX(in_device, in_pCreateInfo, in_pAllocator, out_pObjectTable);

    AddHandles<VkObjectTableNVX>(pObjectTable.GetPointer(), 1, out_pObjectTable, 1, &VulkanObjectMapper::AddVkObjectTableNVX);
}

void VulkanReplayConsumer::Process_vkDestroyObjectTableNVX(
    HandleId                                    device,
    HandleId                                    objectTable,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkObjectTableNVX in_objectTable = object_mapper_.MapVkObjectTableNVX(objectTable);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyObjectTableNVX(in_device, in_objectTable, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkRegisterObjectsNVX(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    objectTable,
    uint32_t                                    objectCount,
    const StructPointerDecoder<Decoded_VkObjectTableEntryNVX>& ppObjectTableEntries,
    const PointerDecoder<uint32_t>&             pObjectIndices)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkObjectTableNVX in_objectTable = object_mapper_.MapVkObjectTableNVX(objectTable);
    const VkObjectTableEntryNVX* const*    in_ppObjectTableEntries = reinterpret_cast<const VkObjectTableEntryNVX* const*   >(ppObjectTableEntries.GetPointer());
    const uint32_t* in_pObjectIndices = reinterpret_cast<const uint32_t*>(pObjectIndices.GetPointer());

    vkRegisterObjectsNVX(in_device, in_objectTable, objectCount, in_ppObjectTableEntries, in_pObjectIndices);
}

void VulkanReplayConsumer::Process_vkUnregisterObjectsNVX(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    objectTable,
    uint32_t                                    objectCount,
    const PointerDecoder<VkObjectEntryTypeNVX>& pObjectEntryTypes,
    const PointerDecoder<uint32_t>&             pObjectIndices)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkObjectTableNVX in_objectTable = object_mapper_.MapVkObjectTableNVX(objectTable);
    const VkObjectEntryTypeNVX* in_pObjectEntryTypes = reinterpret_cast<const VkObjectEntryTypeNVX*>(pObjectEntryTypes.GetPointer());
    const uint32_t* in_pObjectIndices = reinterpret_cast<const uint32_t*>(pObjectIndices.GetPointer());

    vkUnregisterObjectsNVX(in_device, in_objectTable, objectCount, in_pObjectEntryTypes, in_pObjectIndices);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(
    HandleId                                    physicalDevice,
    const StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsFeaturesNVX>& pFeatures,
    const StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsLimitsNVX>& pLimits)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkDeviceGeneratedCommandsFeaturesNVX out_pFeatures_value = {};
    VkDeviceGeneratedCommandsFeaturesNVX* out_pFeatures = &out_pFeatures_value;
    VkDeviceGeneratedCommandsLimitsNVX out_pLimits_value = {};
    VkDeviceGeneratedCommandsLimitsNVX* out_pLimits = &out_pLimits_value;

    vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(in_physicalDevice, out_pFeatures, out_pLimits);
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWScalingNV(
    HandleId                                    commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const StructPointerDecoder<Decoded_VkViewportWScalingNV>& pViewportWScalings)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkViewportWScalingNV* in_pViewportWScalings = reinterpret_cast<const VkViewportWScalingNV*>(pViewportWScalings.GetPointer());

    vkCmdSetViewportWScalingNV(in_commandBuffer, firstViewport, viewportCount, in_pViewportWScalings);
}

void VulkanReplayConsumer::Process_vkReleaseDisplayEXT(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    HandleId                                    display)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkDisplayKHR in_display = object_mapper_.MapVkDisplayKHR(display);

    vkReleaseDisplayEXT(in_physicalDevice, in_display);
}

#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
void VulkanReplayConsumer::Process_vkAcquireXlibDisplayEXT(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    const PointerDecoder<Display>&              dpy,
    HandleId                                    display)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    Display out_dpy_value = static_cast<Display>(0);
    Display* out_dpy = &out_dpy_value;
    VkDisplayKHR in_display = object_mapper_.MapVkDisplayKHR(display);

    vkAcquireXlibDisplayEXT(in_physicalDevice, out_dpy, in_display);
}

void VulkanReplayConsumer::Process_vkGetRandROutputDisplayEXT(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    const PointerDecoder<Display>&              dpy,
    RROutput                                    rrOutput,
    const PointerDecoder<HandleId>&             pDisplay)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    Display out_dpy_value = static_cast<Display>(0);
    Display* out_dpy = &out_dpy_value;
    VkDisplayKHR out_pDisplay_value = static_cast<VkDisplayKHR>(0);
    VkDisplayKHR* out_pDisplay = &out_pDisplay_value;

    vkGetRandROutputDisplayEXT(in_physicalDevice, out_dpy, rrOutput, out_pDisplay);

    AddHandles<VkDisplayKHR>(pDisplay.GetPointer(), 1, out_pDisplay, 1, &VulkanObjectMapper::AddVkDisplayKHR);
}
#endif /* VK_USE_PLATFORM_XLIB_XRANDR_EXT */

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    VkResult                                    returnValue,
    HandleId                                    physicalDevice,
    HandleId                                    surface,
    const StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>& pSurfaceCapabilities)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkSurfaceKHR in_surface = object_mapper_.MapVkSurfaceKHR(surface);
    VkSurfaceCapabilities2EXT out_pSurfaceCapabilities_value = {};
    VkSurfaceCapabilities2EXT* out_pSurfaceCapabilities = &out_pSurfaceCapabilities_value;

    vkGetPhysicalDeviceSurfaceCapabilities2EXT(in_physicalDevice, in_surface, out_pSurfaceCapabilities);
}

void VulkanReplayConsumer::Process_vkDisplayPowerControlEXT(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    display,
    const StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>& pDisplayPowerInfo)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDisplayKHR in_display = object_mapper_.MapVkDisplayKHR(display);
    const VkDisplayPowerInfoEXT* in_pDisplayPowerInfo = reinterpret_cast<const VkDisplayPowerInfoEXT*>(pDisplayPowerInfo.GetPointer());

    vkDisplayPowerControlEXT(in_device, in_display, in_pDisplayPowerInfo);
}

void VulkanReplayConsumer::Process_vkRegisterDeviceEventEXT(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>& pDeviceEventInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pFence)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkDeviceEventInfoEXT* in_pDeviceEventInfo = reinterpret_cast<const VkDeviceEventInfoEXT*>(pDeviceEventInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkFence out_pFence_value = static_cast<VkFence>(0);
    VkFence* out_pFence = &out_pFence_value;

    vkRegisterDeviceEventEXT(in_device, in_pDeviceEventInfo, in_pAllocator, out_pFence);

    AddHandles<VkFence>(pFence.GetPointer(), 1, out_pFence, 1, &VulkanObjectMapper::AddVkFence);
}

void VulkanReplayConsumer::Process_vkRegisterDisplayEventEXT(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    display,
    const StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>& pDisplayEventInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pFence)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkDisplayKHR in_display = object_mapper_.MapVkDisplayKHR(display);
    const VkDisplayEventInfoEXT* in_pDisplayEventInfo = reinterpret_cast<const VkDisplayEventInfoEXT*>(pDisplayEventInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkFence out_pFence_value = static_cast<VkFence>(0);
    VkFence* out_pFence = &out_pFence_value;

    vkRegisterDisplayEventEXT(in_device, in_display, in_pDisplayEventInfo, in_pAllocator, out_pFence);

    AddHandles<VkFence>(pFence.GetPointer(), 1, out_pFence, 1, &VulkanObjectMapper::AddVkFence);
}

void VulkanReplayConsumer::Process_vkGetSwapchainCounterEXT(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    const PointerDecoder<uint64_t>&             pCounterValue)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSwapchainKHR in_swapchain = object_mapper_.MapVkSwapchainKHR(swapchain);
    uint64_t out_pCounterValue_value = static_cast<uint64_t>(0);
    uint64_t* out_pCounterValue = &out_pCounterValue_value;

    vkGetSwapchainCounterEXT(in_device, in_swapchain, counter, out_pCounterValue);
}

void VulkanReplayConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    swapchain,
    const StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>& pDisplayTimingProperties)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSwapchainKHR in_swapchain = object_mapper_.MapVkSwapchainKHR(swapchain);
    VkRefreshCycleDurationGOOGLE out_pDisplayTimingProperties_value = {};
    VkRefreshCycleDurationGOOGLE* out_pDisplayTimingProperties = &out_pDisplayTimingProperties_value;

    vkGetRefreshCycleDurationGOOGLE(in_device, in_swapchain, out_pDisplayTimingProperties);
}

void VulkanReplayConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    swapchain,
    const PointerDecoder<uint32_t>&             pPresentationTimingCount,
    const StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>& pPresentationTimings)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSwapchainKHR in_swapchain = object_mapper_.MapVkSwapchainKHR(swapchain);
    uint32_t out_pPresentationTimingCount_value = pPresentationTimingCount.IsNull() ? static_cast<uint32_t>(0) : *(pPresentationTimingCount.GetPointer());
    uint32_t* out_pPresentationTimingCount = &out_pPresentationTimingCount_value;
    VkPastPresentationTimingGOOGLE* out_pPresentationTimings = pPresentationTimings.IsNull() ? nullptr : AllocateArray<VkPastPresentationTimingGOOGLE>(out_pPresentationTimingCount_value);

    vkGetPastPresentationTimingGOOGLE(in_device, in_swapchain, out_pPresentationTimingCount, out_pPresentationTimings);

    FreeArray<VkPastPresentationTimingGOOGLE>(&out_pPresentationTimings);
}

void VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleEXT(
    HandleId                                    commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const StructPointerDecoder<Decoded_VkRect2D>& pDiscardRectangles)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkRect2D* in_pDiscardRectangles = reinterpret_cast<const VkRect2D*>(pDiscardRectangles.GetPointer());

    vkCmdSetDiscardRectangleEXT(in_commandBuffer, firstDiscardRectangle, discardRectangleCount, in_pDiscardRectangles);
}

void VulkanReplayConsumer::Process_vkSetHdrMetadataEXT(
    HandleId                                    device,
    uint32_t                                    swapchainCount,
    const PointerDecoder<HandleId>&             pSwapchains,
    const StructPointerDecoder<Decoded_VkHdrMetadataEXT>& pMetadata)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkSwapchainKHR* in_pSwapchains = pSwapchains.IsNull() ? nullptr : AllocateArray<VkSwapchainKHR>(swapchainCount);
    MapHandles<VkSwapchainKHR>(pSwapchains.GetPointer(), pSwapchains.GetLength(), in_pSwapchains, swapchainCount, &VulkanObjectMapper::MapVkSwapchainKHR);
    const VkHdrMetadataEXT* in_pMetadata = reinterpret_cast<const VkHdrMetadataEXT*>(pMetadata.GetPointer());

    vkSetHdrMetadataEXT(in_device, swapchainCount, in_pSwapchains, in_pMetadata);

    FreeArray<VkSwapchainKHR>(&in_pSwapchains);
}

#ifdef VK_USE_PLATFORM_IOS_MVK
void VulkanReplayConsumer::Process_vkCreateIOSSurfaceMVK(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSurface)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const VkIOSSurfaceCreateInfoMVK* in_pCreateInfo = reinterpret_cast<const VkIOSSurfaceCreateInfoMVK*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateIOSSurfaceMVK(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);

    AddHandles<VkSurfaceKHR>(pSurface.GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}
#endif /* VK_USE_PLATFORM_IOS_MVK */

#ifdef VK_USE_PLATFORM_MACOS_MVK
void VulkanReplayConsumer::Process_vkCreateMacOSSurfaceMVK(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pSurface)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const VkMacOSSurfaceCreateInfoMVK* in_pCreateInfo = reinterpret_cast<const VkMacOSSurfaceCreateInfoMVK*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR out_pSurface_value = static_cast<VkSurfaceKHR>(0);
    VkSurfaceKHR* out_pSurface = &out_pSurface_value;

    vkCreateMacOSSurfaceMVK(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);

    AddHandles<VkSurfaceKHR>(pSurface.GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}
#endif /* VK_USE_PLATFORM_MACOS_MVK */

void VulkanReplayConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>& pNameInfo)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkDebugUtilsObjectNameInfoEXT* in_pNameInfo = reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(pNameInfo.GetPointer());

    vkSetDebugUtilsObjectNameEXT(in_device, in_pNameInfo);
}

void VulkanReplayConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>& pTagInfo)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkDebugUtilsObjectTagInfoEXT* in_pTagInfo = reinterpret_cast<const VkDebugUtilsObjectTagInfoEXT*>(pTagInfo.GetPointer());

    vkSetDebugUtilsObjectTagEXT(in_device, in_pTagInfo);
}

void VulkanReplayConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    HandleId                                    queue,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    VkQueue in_queue = object_mapper_.MapVkQueue(queue);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = reinterpret_cast<const VkDebugUtilsLabelEXT*>(pLabelInfo.GetPointer());

    vkQueueBeginDebugUtilsLabelEXT(in_queue, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    HandleId                                    queue)
{
    VkQueue in_queue = object_mapper_.MapVkQueue(queue);

    vkQueueEndDebugUtilsLabelEXT(in_queue);
}

void VulkanReplayConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    HandleId                                    queue,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    VkQueue in_queue = object_mapper_.MapVkQueue(queue);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = reinterpret_cast<const VkDebugUtilsLabelEXT*>(pLabelInfo.GetPointer());

    vkQueueInsertDebugUtilsLabelEXT(in_queue, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    HandleId                                    commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = reinterpret_cast<const VkDebugUtilsLabelEXT*>(pLabelInfo.GetPointer());

    vkCmdBeginDebugUtilsLabelEXT(in_commandBuffer, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    HandleId                                    commandBuffer)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);

    vkCmdEndDebugUtilsLabelEXT(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    HandleId                                    commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = reinterpret_cast<const VkDebugUtilsLabelEXT*>(pLabelInfo.GetPointer());

    vkCmdInsertDebugUtilsLabelEXT(in_commandBuffer, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    VkResult                                    returnValue,
    HandleId                                    instance,
    const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pMessenger)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const VkDebugUtilsMessengerCreateInfoEXT* in_pCreateInfo = reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDebugUtilsMessengerEXT out_pMessenger_value = static_cast<VkDebugUtilsMessengerEXT>(0);
    VkDebugUtilsMessengerEXT* out_pMessenger = &out_pMessenger_value;

    vkCreateDebugUtilsMessengerEXT(in_instance, in_pCreateInfo, in_pAllocator, out_pMessenger);

    AddHandles<VkDebugUtilsMessengerEXT>(pMessenger.GetPointer(), 1, out_pMessenger, 1, &VulkanObjectMapper::AddVkDebugUtilsMessengerEXT);
}

void VulkanReplayConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    HandleId                                    instance,
    HandleId                                    messenger,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    VkDebugUtilsMessengerEXT in_messenger = object_mapper_.MapVkDebugUtilsMessengerEXT(messenger);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyDebugUtilsMessengerEXT(in_instance, in_messenger, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    HandleId                                    instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>& pCallbackData)
{
    VkInstance in_instance = object_mapper_.MapVkInstance(instance);
    const VkDebugUtilsMessengerCallbackDataEXT* in_pCallbackData = reinterpret_cast<const VkDebugUtilsMessengerCallbackDataEXT*>(pCallbackData.GetPointer());

    vkSubmitDebugUtilsMessageEXT(in_instance, messageSeverity, messageTypes, in_pCallbackData);
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
void VulkanReplayConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    VkResult                                    returnValue,
    HandleId                                    device,
    const PointerDecoder<AHardwareBuffer>&      buffer,
    const StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>& pProperties)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const struct AHardwareBuffer* in_buffer = reinterpret_cast<const struct AHardwareBuffer*>(buffer.GetPointer());
    VkAndroidHardwareBufferPropertiesANDROID out_pProperties_value = {};
    VkAndroidHardwareBufferPropertiesANDROID* out_pProperties = &out_pProperties_value;

    vkGetAndroidHardwareBufferPropertiesANDROID(in_device, in_buffer, out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>& pInfo,
    const PointerDecoder<AHardwareBuffer>&      pBuffer)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkMemoryGetAndroidHardwareBufferInfoANDROID* in_pInfo = reinterpret_cast<VkMemoryGetAndroidHardwareBufferInfoANDROID*>(pInfo.GetPointer());
    if (!pInfo.IsNull())
    {
        const Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* in_pInfo_wrapper = pInfo.GetMetaStructPointer();
        in_pInfo->memory = object_mapper_.MapVkDeviceMemory(in_pInfo_wrapper->memory);
    }
    AHardwareBuffer out_pBuffer_value = static_cast<AHardwareBuffer>(0);
    struct AHardwareBuffer** out_pBuffer = &out_pBuffer_value;

    vkGetMemoryAndroidHardwareBufferANDROID(in_device, in_pInfo, out_pBuffer);
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

void VulkanReplayConsumer::Process_vkCmdSetSampleLocationsEXT(
    HandleId                                    commandBuffer,
    const StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>& pSampleLocationsInfo)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    const VkSampleLocationsInfoEXT* in_pSampleLocationsInfo = reinterpret_cast<const VkSampleLocationsInfoEXT*>(pSampleLocationsInfo.GetPointer());

    vkCmdSetSampleLocationsEXT(in_commandBuffer, in_pSampleLocationsInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    HandleId                                    physicalDevice,
    VkSampleCountFlagBits                       samples,
    const StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>& pMultisampleProperties)
{
    VkPhysicalDevice in_physicalDevice = object_mapper_.MapVkPhysicalDevice(physicalDevice);
    VkMultisamplePropertiesEXT out_pMultisampleProperties_value = {};
    VkMultisamplePropertiesEXT* out_pMultisampleProperties = &out_pMultisampleProperties_value;

    vkGetPhysicalDeviceMultisamplePropertiesEXT(in_physicalDevice, samples, out_pMultisampleProperties);
}

void VulkanReplayConsumer::Process_vkCreateValidationCacheEXT(
    VkResult                                    returnValue,
    HandleId                                    device,
    const StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    const PointerDecoder<HandleId>&             pValidationCache)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const VkValidationCacheCreateInfoEXT* in_pCreateInfo = reinterpret_cast<const VkValidationCacheCreateInfoEXT*>(pCreateInfo.GetPointer());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkValidationCacheEXT out_pValidationCache_value = static_cast<VkValidationCacheEXT>(0);
    VkValidationCacheEXT* out_pValidationCache = &out_pValidationCache_value;

    vkCreateValidationCacheEXT(in_device, in_pCreateInfo, in_pAllocator, out_pValidationCache);

    AddHandles<VkValidationCacheEXT>(pValidationCache.GetPointer(), 1, out_pValidationCache, 1, &VulkanObjectMapper::AddVkValidationCacheEXT);
}

void VulkanReplayConsumer::Process_vkDestroyValidationCacheEXT(
    HandleId                                    device,
    HandleId                                    validationCache,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkValidationCacheEXT in_validationCache = object_mapper_.MapVkValidationCacheEXT(validationCache);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    vkDestroyValidationCacheEXT(in_device, in_validationCache, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkMergeValidationCachesEXT(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    dstCache,
    uint32_t                                    srcCacheCount,
    const PointerDecoder<HandleId>&             pSrcCaches)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkValidationCacheEXT in_dstCache = object_mapper_.MapVkValidationCacheEXT(dstCache);
    VkValidationCacheEXT* in_pSrcCaches = pSrcCaches.IsNull() ? nullptr : AllocateArray<VkValidationCacheEXT>(srcCacheCount);
    MapHandles<VkValidationCacheEXT>(pSrcCaches.GetPointer(), pSrcCaches.GetLength(), in_pSrcCaches, srcCacheCount, &VulkanObjectMapper::MapVkValidationCacheEXT);

    vkMergeValidationCachesEXT(in_device, in_dstCache, srcCacheCount, in_pSrcCaches);

    FreeArray<VkValidationCacheEXT>(&in_pSrcCaches);
}

void VulkanReplayConsumer::Process_vkGetValidationCacheDataEXT(
    VkResult                                    returnValue,
    HandleId                                    device,
    HandleId                                    validationCache,
    const PointerDecoder<size_t>&               pDataSize,
    const PointerDecoder<uint8_t>&              pData)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    VkValidationCacheEXT in_validationCache = object_mapper_.MapVkValidationCacheEXT(validationCache);
    size_t out_pDataSize_value = pDataSize.IsNull() ? static_cast<size_t>(0) : *(pDataSize.GetPointer());
    size_t* out_pDataSize = &out_pDataSize_value;
    uint8_t* out_pData = pData.IsNull() ? nullptr : AllocateArray<uint8_t>(out_pDataSize_value);

    vkGetValidationCacheDataEXT(in_device, in_validationCache, out_pDataSize, out_pData);

    FreeArray<uint8_t>(&out_pData);
}

void VulkanReplayConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    VkResult                                    returnValue,
    HandleId                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    const StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>& pMemoryHostPointerProperties)
{
    VkDevice in_device = object_mapper_.MapVkDevice(device);
    const void* in_pHostPointer = nullptr;
    VkMemoryHostPointerPropertiesEXT out_pMemoryHostPointerProperties_value = {};
    VkMemoryHostPointerPropertiesEXT* out_pMemoryHostPointerProperties = &out_pMemoryHostPointerProperties_value;

    vkGetMemoryHostPointerPropertiesEXT(in_device, handleType, in_pHostPointer, out_pMemoryHostPointerProperties);
}

void VulkanReplayConsumer::Process_vkCmdWriteBufferMarkerAMD(
    HandleId                                    commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    HandleId                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    VkCommandBuffer in_commandBuffer = object_mapper_.MapVkCommandBuffer(commandBuffer);
    VkBuffer in_dstBuffer = object_mapper_.MapVkBuffer(dstBuffer);

    vkCmdWriteBufferMarkerAMD(in_commandBuffer, pipelineStage, in_dstBuffer, dstOffset, marker);
}
