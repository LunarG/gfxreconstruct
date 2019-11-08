/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
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

#include "generated/generated_vulkan_replay_consumer.h"

#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanReplayConsumer::Process_vkCreateInstance(
    VkResult                                    returnValue,
    const StructPointerDecoder<Decoded_VkInstanceCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    const VkInstanceCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkInstance* out_pInstance = pInstance->GetHandlePointer();

    VkResult replay_result = OverrideCreateInstance(returnValue, in_pCreateInfo, in_pAllocator, pInstance);
    CheckResult("vkCreateInstance", returnValue, replay_result);

    AddHandles<VkInstance>(pInstance->GetPointer(), 1, out_pInstance, 1, &VulkanObjectMapper::AddVkInstance);
}

void VulkanReplayConsumer::Process_vkDestroyInstance(
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetInstanceTable(in_instance)->DestroyInstance(in_instance, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDevices(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    uint32_t* out_pPhysicalDeviceCount = pPhysicalDeviceCount->AllocateOutputData(1, pPhysicalDeviceCount->IsNull() ? static_cast<uint32_t>(0) : (*pPhysicalDeviceCount->GetPointer()));
    VkPhysicalDevice* out_pPhysicalDevices = pPhysicalDevices->GetHandlePointer();

    VkResult replay_result = OverrideEnumeratePhysicalDevices(GetInstanceTable(in_instance)->EnumeratePhysicalDevices, returnValue, in_instance, pPhysicalDeviceCount, pPhysicalDevices);
    CheckResult("vkEnumeratePhysicalDevices", returnValue, replay_result);

    AddHandles<VkPhysicalDevice>(pPhysicalDevices->GetPointer(), pPhysicalDevices->GetLength(), out_pPhysicalDevices, *out_pPhysicalDeviceCount, &VulkanObjectMapper::AddVkPhysicalDevice);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkPhysicalDeviceFeatures* out_pFeatures = pFeatures->AllocateOutputData(1);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFeatures(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkFormatProperties* out_pFormatProperties = pFormatProperties->AllocateOutputData(1);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFormatProperties(in_physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkImageFormatProperties* out_pImageFormatProperties = pImageFormatProperties->AllocateOutputData(1);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceImageFormatProperties(in_physicalDevice, format, type, tiling, usage, flags, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceImageFormatProperties", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkPhysicalDeviceProperties* out_pProperties = pProperties->AllocateOutputData(1);

    OverrideGetPhysicalDeviceProperties(GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceProperties, in_physicalDevice, pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    uint32_t* out_pQueueFamilyPropertyCount = pQueueFamilyPropertyCount->AllocateOutputData(1, pQueueFamilyPropertyCount->IsNull() ? static_cast<uint32_t>(0) : (*pQueueFamilyPropertyCount->GetPointer()));
    VkQueueFamilyProperties* out_pQueueFamilyProperties = pQueueFamilyProperties->IsNull() ? nullptr : pQueueFamilyProperties->AllocateOutputData(*out_pQueueFamilyPropertyCount);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyProperties(in_physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkPhysicalDeviceMemoryProperties* out_pMemoryProperties = pMemoryProperties->AllocateOutputData(1);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceMemoryProperties(in_physicalDevice, out_pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkCreateDevice(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkDeviceCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkDevice>*             pDevice)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkDeviceCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDevice* out_pDevice = pDevice->GetHandlePointer();

    VkResult replay_result = OverrideCreateDevice(returnValue, in_physicalDevice, in_pCreateInfo, in_pAllocator, pDevice);
    CheckResult("vkCreateDevice", returnValue, replay_result);

    AddHandles<VkDevice>(pDevice->GetPointer(), 1, out_pDevice, 1, &VulkanObjectMapper::AddVkDevice);
}

void VulkanReplayConsumer::Process_vkDestroyDevice(
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyDevice(in_device, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetDeviceQueue(
    format::HandleId                            device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkQueue* out_pQueue = pQueue->GetHandlePointer();

    GetDeviceTable(in_device)->GetDeviceQueue(in_device, queueFamilyIndex, queueIndex, out_pQueue);

    AddHandles<VkQueue>(pQueue->GetPointer(), 1, out_pQueue, 1, &VulkanObjectMapper::AddVkQueue);
}

void VulkanReplayConsumer::Process_vkQueueSubmit(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    const StructPointerDecoder<Decoded_VkSubmitInfo>& pSubmits,
    format::HandleId                            fence)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectMapper::MapVkQueue);
    const VkSubmitInfo* in_pSubmits = pSubmits.GetPointer();
    MapStructArrayHandles(pSubmits.GetMetaStructPointer(), pSubmits.GetLength(), GetObjectMapper());
    VkFence in_fence = MapHandle<FenceInfo>(fence, &VulkanObjectMapper::MapVkFence);

    VkResult replay_result = GetDeviceTable(in_queue)->QueueSubmit(in_queue, submitCount, in_pSubmits, in_fence);
    CheckResult("vkQueueSubmit", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkQueueWaitIdle(
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectMapper::MapVkQueue);

    VkResult replay_result = GetDeviceTable(in_queue)->QueueWaitIdle(in_queue);
    CheckResult("vkQueueWaitIdle", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkDeviceWaitIdle(
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);

    VkResult replay_result = GetDeviceTable(in_device)->DeviceWaitIdle(in_device);
    CheckResult("vkDeviceWaitIdle", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkAllocateMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*       pMemory)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkMemoryAllocateInfo* in_pAllocateInfo = pAllocateInfo.GetPointer();
    MapStructHandles(pAllocateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDeviceMemory* out_pMemory = pMemory->GetHandlePointer();

    VkResult replay_result = OverrideAllocateMemory(GetDeviceTable(in_device)->AllocateMemory, returnValue, in_device, in_pAllocateInfo, in_pAllocator, pMemory);
    CheckResult("vkAllocateMemory", returnValue, replay_result);

    AddHandles<VkDeviceMemory>(pMemory->GetPointer(), 1, out_pMemory, 1, &VulkanObjectMapper::AddVkDeviceMemory);
}

void VulkanReplayConsumer::Process_vkFreeMemory(
    format::HandleId                            device,
    format::HandleId                            memory,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDeviceMemory in_memory = MapHandle<DeviceMemoryInfo>(memory, &VulkanObjectMapper::MapVkDeviceMemory);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    OverrideFreeMemory(GetDeviceTable(in_device)->FreeMemory, in_device, in_memory, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkMapMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDeviceMemory in_memory = MapHandle<DeviceMemoryInfo>(memory, &VulkanObjectMapper::MapVkDeviceMemory);
    void** out_ppData = ppData->AllocateOutputData(1);

    VkResult replay_result = OverrideMapMemory(GetDeviceTable(in_device)->MapMemory, returnValue, in_device, in_memory, offset, size, flags, ppData);
    CheckResult("vkMapMemory", returnValue, replay_result);

    PostProcessExternalObject(replay_result, (*ppData->GetPointer()), *out_ppData, format::ApiCallId::ApiCall_vkMapMemory, "vkMapMemory");
}

void VulkanReplayConsumer::Process_vkUnmapMemory(
    format::HandleId                            device,
    format::HandleId                            memory)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDeviceMemory in_memory = MapHandle<DeviceMemoryInfo>(memory, &VulkanObjectMapper::MapVkDeviceMemory);

    OverrideUnmapMemory(GetDeviceTable(in_device)->UnmapMemory, in_device, in_memory);
}

void VulkanReplayConsumer::Process_vkFlushMappedMemoryRanges(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkMappedMemoryRange* in_pMemoryRanges = pMemoryRanges.GetPointer();
    MapStructArrayHandles(pMemoryRanges.GetMetaStructPointer(), pMemoryRanges.GetLength(), GetObjectMapper());

    VkResult replay_result = GetDeviceTable(in_device)->FlushMappedMemoryRanges(in_device, memoryRangeCount, in_pMemoryRanges);
    CheckResult("vkFlushMappedMemoryRanges", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkInvalidateMappedMemoryRanges(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkMappedMemoryRange* in_pMemoryRanges = pMemoryRanges.GetPointer();
    MapStructArrayHandles(pMemoryRanges.GetMetaStructPointer(), pMemoryRanges.GetLength(), GetObjectMapper());

    VkResult replay_result = GetDeviceTable(in_device)->InvalidateMappedMemoryRanges(in_device, memoryRangeCount, in_pMemoryRanges);
    CheckResult("vkInvalidateMappedMemoryRanges", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetDeviceMemoryCommitment(
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDeviceMemory in_memory = MapHandle<DeviceMemoryInfo>(memory, &VulkanObjectMapper::MapVkDeviceMemory);
    VkDeviceSize* out_pCommittedMemoryInBytes = pCommittedMemoryInBytes->AllocateOutputData(1, static_cast<VkDeviceSize>(0));

    GetDeviceTable(in_device)->GetDeviceMemoryCommitment(in_device, in_memory, out_pCommittedMemoryInBytes);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            buffer,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectMapper::MapVkBuffer);
    VkDeviceMemory in_memory = MapHandle<DeviceMemoryInfo>(memory, &VulkanObjectMapper::MapVkDeviceMemory);

    VkResult replay_result = OverrideBindBufferMemory(GetDeviceTable(in_device)->BindBufferMemory, returnValue, in_device, in_buffer, in_memory, memoryOffset);
    CheckResult("vkBindBufferMemory", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkBindImageMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectMapper::MapVkImage);
    VkDeviceMemory in_memory = MapHandle<DeviceMemoryInfo>(memory, &VulkanObjectMapper::MapVkDeviceMemory);

    VkResult replay_result = OverrideBindImageMemory(GetDeviceTable(in_device)->BindImageMemory, returnValue, in_device, in_image, in_memory, memoryOffset);
    CheckResult("vkBindImageMemory", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements(
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectMapper::MapVkBuffer);
    VkMemoryRequirements* out_pMemoryRequirements = pMemoryRequirements->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetBufferMemoryRequirements(in_device, in_buffer, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements(
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectMapper::MapVkImage);
    VkMemoryRequirements* out_pMemoryRequirements = pMemoryRequirements->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetImageMemoryRequirements(in_device, in_image, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements(
    format::HandleId                            device,
    format::HandleId                            image,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectMapper::MapVkImage);
    uint32_t* out_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->AllocateOutputData(1, pSparseMemoryRequirementCount->IsNull() ? static_cast<uint32_t>(0) : (*pSparseMemoryRequirementCount->GetPointer()));
    VkSparseImageMemoryRequirements* out_pSparseMemoryRequirements = pSparseMemoryRequirements->IsNull() ? nullptr : pSparseMemoryRequirements->AllocateOutputData(*out_pSparseMemoryRequirementCount);

    GetDeviceTable(in_device)->GetImageSparseMemoryRequirements(in_device, in_image, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    uint32_t* out_pPropertyCount = pPropertyCount->AllocateOutputData(1, pPropertyCount->IsNull() ? static_cast<uint32_t>(0) : (*pPropertyCount->GetPointer()));
    VkSparseImageFormatProperties* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(in_physicalDevice, format, type, samples, usage, tiling, out_pPropertyCount, out_pProperties);
}

void VulkanReplayConsumer::Process_vkQueueBindSparse(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindSparseInfo>& pBindInfo,
    format::HandleId                            fence)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectMapper::MapVkQueue);
    const VkBindSparseInfo* in_pBindInfo = pBindInfo.GetPointer();
    MapStructArrayHandles(pBindInfo.GetMetaStructPointer(), pBindInfo.GetLength(), GetObjectMapper());
    VkFence in_fence = MapHandle<FenceInfo>(fence, &VulkanObjectMapper::MapVkFence);

    VkResult replay_result = GetDeviceTable(in_queue)->QueueBindSparse(in_queue, bindInfoCount, in_pBindInfo, in_fence);
    CheckResult("vkQueueBindSparse", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateFence(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkFenceCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkFenceCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkFence* out_pFence = pFence->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateFence(in_device, in_pCreateInfo, in_pAllocator, out_pFence);
    CheckResult("vkCreateFence", returnValue, replay_result);

    AddHandles<VkFence>(pFence->GetPointer(), 1, out_pFence, 1, &VulkanObjectMapper::AddVkFence);
}

void VulkanReplayConsumer::Process_vkDestroyFence(
    format::HandleId                            device,
    format::HandleId                            fence,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkFence in_fence = MapHandle<FenceInfo>(fence, &VulkanObjectMapper::MapVkFence);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyFence(in_device, in_fence, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkResetFences(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    const HandlePointerDecoder<VkFence>&        pFences)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkFence* in_pFences = pFences.GetHandlePointer();
    MapHandles<FenceInfo>(pFences.GetPointer(), pFences.GetLength(), in_pFences, fenceCount, &VulkanObjectMapper::MapVkFence);

    VkResult replay_result = GetDeviceTable(in_device)->ResetFences(in_device, fenceCount, in_pFences);
    CheckResult("vkResetFences", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetFenceStatus(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkFence in_fence = MapHandle<FenceInfo>(fence, &VulkanObjectMapper::MapVkFence);

    VkResult replay_result = OverrideGetFenceStatus(GetDeviceTable(in_device)->GetFenceStatus, returnValue, in_device, in_fence);
    CheckResult("vkGetFenceStatus", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkWaitForFences(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    const HandlePointerDecoder<VkFence>&        pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkFence* in_pFences = pFences.GetHandlePointer();
    MapHandles<FenceInfo>(pFences.GetPointer(), pFences.GetLength(), in_pFences, fenceCount, &VulkanObjectMapper::MapVkFence);

    VkResult replay_result = OverrideWaitForFences(GetDeviceTable(in_device)->WaitForFences, returnValue, in_device, fenceCount, in_pFences, waitAll, timeout);
    CheckResult("vkWaitForFences", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateSemaphore(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSemaphore>*          pSemaphore)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkSemaphoreCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSemaphore* out_pSemaphore = pSemaphore->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSemaphore(in_device, in_pCreateInfo, in_pAllocator, out_pSemaphore);
    CheckResult("vkCreateSemaphore", returnValue, replay_result);

    AddHandles<VkSemaphore>(pSemaphore->GetPointer(), 1, out_pSemaphore, 1, &VulkanObjectMapper::AddVkSemaphore);
}

void VulkanReplayConsumer::Process_vkDestroySemaphore(
    format::HandleId                            device,
    format::HandleId                            semaphore,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSemaphore in_semaphore = MapHandle<SemaphoreInfo>(semaphore, &VulkanObjectMapper::MapVkSemaphore);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroySemaphore(in_device, in_semaphore, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateEvent(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkEventCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkEvent>*              pEvent)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkEventCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkEvent* out_pEvent = pEvent->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateEvent(in_device, in_pCreateInfo, in_pAllocator, out_pEvent);
    CheckResult("vkCreateEvent", returnValue, replay_result);

    AddHandles<VkEvent>(pEvent->GetPointer(), 1, out_pEvent, 1, &VulkanObjectMapper::AddVkEvent);
}

void VulkanReplayConsumer::Process_vkDestroyEvent(
    format::HandleId                            device,
    format::HandleId                            event,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectMapper::MapVkEvent);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyEvent(in_device, in_event, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetEventStatus(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectMapper::MapVkEvent);

    VkResult replay_result = OverrideGetEventStatus(GetDeviceTable(in_device)->GetEventStatus, returnValue, in_device, in_event);
    CheckResult("vkGetEventStatus", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkSetEvent(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectMapper::MapVkEvent);

    VkResult replay_result = GetDeviceTable(in_device)->SetEvent(in_device, in_event);
    CheckResult("vkSetEvent", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkResetEvent(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectMapper::MapVkEvent);

    VkResult replay_result = GetDeviceTable(in_device)->ResetEvent(in_device, in_event);
    CheckResult("vkResetEvent", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateQueryPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkQueryPool>*          pQueryPool)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkQueryPoolCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkQueryPool* out_pQueryPool = pQueryPool->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateQueryPool(in_device, in_pCreateInfo, in_pAllocator, out_pQueryPool);
    CheckResult("vkCreateQueryPool", returnValue, replay_result);

    AddHandles<VkQueryPool>(pQueryPool->GetPointer(), 1, out_pQueryPool, 1, &VulkanObjectMapper::AddVkQueryPool);
}

void VulkanReplayConsumer::Process_vkDestroyQueryPool(
    format::HandleId                            device,
    format::HandleId                            queryPool,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectMapper::MapVkQueryPool);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyQueryPool(in_device, in_queryPool, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetQueryPoolResults(
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
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectMapper::MapVkQueryPool);
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(dataSize);

    VkResult replay_result = OverrideGetQueryPoolResults(GetDeviceTable(in_device)->GetQueryPoolResults, returnValue, in_device, in_queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    CheckResult("vkGetQueryPoolResults", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateBuffer(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkBufferCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkBuffer>*             pBuffer)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkBufferCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkBuffer* out_pBuffer = pBuffer->GetHandlePointer();

    VkResult replay_result = OverrideCreateBuffer(GetDeviceTable(in_device)->CreateBuffer, returnValue, in_device, in_pCreateInfo, in_pAllocator, pBuffer);
    CheckResult("vkCreateBuffer", returnValue, replay_result);

    AddHandles<VkBuffer>(pBuffer->GetPointer(), 1, out_pBuffer, 1, &VulkanObjectMapper::AddVkBuffer);
}

void VulkanReplayConsumer::Process_vkDestroyBuffer(
    format::HandleId                            device,
    format::HandleId                            buffer,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectMapper::MapVkBuffer);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyBuffer(in_device, in_buffer, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateBufferView(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkBufferViewCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkBufferView>*         pView)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkBufferViewCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkBufferView* out_pView = pView->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateBufferView(in_device, in_pCreateInfo, in_pAllocator, out_pView);
    CheckResult("vkCreateBufferView", returnValue, replay_result);

    AddHandles<VkBufferView>(pView->GetPointer(), 1, out_pView, 1, &VulkanObjectMapper::AddVkBufferView);
}

void VulkanReplayConsumer::Process_vkDestroyBufferView(
    format::HandleId                            device,
    format::HandleId                            bufferView,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkBufferView in_bufferView = MapHandle<BufferViewInfo>(bufferView, &VulkanObjectMapper::MapVkBufferView);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyBufferView(in_device, in_bufferView, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateImage(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkImageCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkImage>*              pImage)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkImageCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkImage* out_pImage = pImage->GetHandlePointer();

    VkResult replay_result = OverrideCreateImage(GetDeviceTable(in_device)->CreateImage, returnValue, in_device, in_pCreateInfo, in_pAllocator, pImage);
    CheckResult("vkCreateImage", returnValue, replay_result);

    AddHandles<VkImage>(pImage->GetPointer(), 1, out_pImage, 1, &VulkanObjectMapper::AddVkImage);
}

void VulkanReplayConsumer::Process_vkDestroyImage(
    format::HandleId                            device,
    format::HandleId                            image,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectMapper::MapVkImage);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyImage(in_device, in_image, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetImageSubresourceLayout(
    format::HandleId                            device,
    format::HandleId                            image,
    const StructPointerDecoder<Decoded_VkImageSubresource>& pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectMapper::MapVkImage);
    const VkImageSubresource* in_pSubresource = pSubresource.GetPointer();
    VkSubresourceLayout* out_pLayout = pLayout->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetImageSubresourceLayout(in_device, in_image, in_pSubresource, out_pLayout);
}

void VulkanReplayConsumer::Process_vkCreateImageView(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkImageViewCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkImageView>*          pView)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkImageViewCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkImageView* out_pView = pView->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateImageView(in_device, in_pCreateInfo, in_pAllocator, out_pView);
    CheckResult("vkCreateImageView", returnValue, replay_result);

    AddHandles<VkImageView>(pView->GetPointer(), 1, out_pView, 1, &VulkanObjectMapper::AddVkImageView);
}

void VulkanReplayConsumer::Process_vkDestroyImageView(
    format::HandleId                            device,
    format::HandleId                            imageView,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkImageView in_imageView = MapHandle<ImageViewInfo>(imageView, &VulkanObjectMapper::MapVkImageView);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyImageView(in_device, in_imageView, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateShaderModule(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkShaderModule>*       pShaderModule)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkShaderModuleCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkShaderModule* out_pShaderModule = pShaderModule->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateShaderModule(in_device, in_pCreateInfo, in_pAllocator, out_pShaderModule);
    CheckResult("vkCreateShaderModule", returnValue, replay_result);

    AddHandles<VkShaderModule>(pShaderModule->GetPointer(), 1, out_pShaderModule, 1, &VulkanObjectMapper::AddVkShaderModule);
}

void VulkanReplayConsumer::Process_vkDestroyShaderModule(
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkShaderModule in_shaderModule = MapHandle<ShaderModuleInfo>(shaderModule, &VulkanObjectMapper::MapVkShaderModule);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyShaderModule(in_device, in_shaderModule, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreatePipelineCache(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkPipelineCache>*      pPipelineCache)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkPipelineCacheCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkPipelineCache* out_pPipelineCache = pPipelineCache->GetHandlePointer();

    VkResult replay_result = OverrideCreatePipelineCache(GetDeviceTable(in_device)->CreatePipelineCache, returnValue, in_device, in_pCreateInfo, in_pAllocator, pPipelineCache);
    CheckResult("vkCreatePipelineCache", returnValue, replay_result);

    AddHandles<VkPipelineCache>(pPipelineCache->GetPointer(), 1, out_pPipelineCache, 1, &VulkanObjectMapper::AddVkPipelineCache);
}

void VulkanReplayConsumer::Process_vkDestroyPipelineCache(
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPipelineCache in_pipelineCache = MapHandle<PipelineCacheInfo>(pipelineCache, &VulkanObjectMapper::MapVkPipelineCache);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyPipelineCache(in_device, in_pipelineCache, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetPipelineCacheData(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPipelineCache in_pipelineCache = MapHandle<PipelineCacheInfo>(pipelineCache, &VulkanObjectMapper::MapVkPipelineCache);
    size_t* out_pDataSize = pDataSize->AllocateOutputData(1, pDataSize->IsNull() ? static_cast<size_t>(0) : (*pDataSize->GetPointer()));
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(*out_pDataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineCacheData(in_device, in_pipelineCache, out_pDataSize, out_pData);
    CheckResult("vkGetPipelineCacheData", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkMergePipelineCaches(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    const HandlePointerDecoder<VkPipelineCache>& pSrcCaches)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPipelineCache in_dstCache = MapHandle<PipelineCacheInfo>(dstCache, &VulkanObjectMapper::MapVkPipelineCache);
    VkPipelineCache* in_pSrcCaches = pSrcCaches.GetHandlePointer();
    MapHandles<PipelineCacheInfo>(pSrcCaches.GetPointer(), pSrcCaches.GetLength(), in_pSrcCaches, srcCacheCount, &VulkanObjectMapper::MapVkPipelineCache);

    VkResult replay_result = GetDeviceTable(in_device)->MergePipelineCaches(in_device, in_dstCache, srcCacheCount, in_pSrcCaches);
    CheckResult("vkMergePipelineCaches", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateGraphicsPipelines(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    const StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>& pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPipelineCache in_pipelineCache = MapHandle<PipelineCacheInfo>(pipelineCache, &VulkanObjectMapper::MapVkPipelineCache);
    const VkGraphicsPipelineCreateInfo* in_pCreateInfos = pCreateInfos.GetPointer();
    MapStructArrayHandles(pCreateInfos.GetMetaStructPointer(), pCreateInfos.GetLength(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkPipeline* out_pPipelines = pPipelines->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateGraphicsPipelines(in_device, in_pipelineCache, createInfoCount, in_pCreateInfos, in_pAllocator, out_pPipelines);
    CheckResult("vkCreateGraphicsPipelines", returnValue, replay_result);

    AddHandles<VkPipeline>(pPipelines->GetPointer(), pPipelines->GetLength(), out_pPipelines, createInfoCount, &VulkanObjectMapper::AddVkPipeline);
}

void VulkanReplayConsumer::Process_vkCreateComputePipelines(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    const StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>& pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPipelineCache in_pipelineCache = MapHandle<PipelineCacheInfo>(pipelineCache, &VulkanObjectMapper::MapVkPipelineCache);
    const VkComputePipelineCreateInfo* in_pCreateInfos = pCreateInfos.GetPointer();
    MapStructArrayHandles(pCreateInfos.GetMetaStructPointer(), pCreateInfos.GetLength(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkPipeline* out_pPipelines = pPipelines->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateComputePipelines(in_device, in_pipelineCache, createInfoCount, in_pCreateInfos, in_pAllocator, out_pPipelines);
    CheckResult("vkCreateComputePipelines", returnValue, replay_result);

    AddHandles<VkPipeline>(pPipelines->GetPointer(), pPipelines->GetLength(), out_pPipelines, createInfoCount, &VulkanObjectMapper::AddVkPipeline);
}

void VulkanReplayConsumer::Process_vkDestroyPipeline(
    format::HandleId                            device,
    format::HandleId                            pipeline,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPipeline in_pipeline = MapHandle<PipelineInfo>(pipeline, &VulkanObjectMapper::MapVkPipeline);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyPipeline(in_device, in_pipeline, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreatePipelineLayout(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkPipelineLayoutCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkPipelineLayout* out_pPipelineLayout = pPipelineLayout->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreatePipelineLayout(in_device, in_pCreateInfo, in_pAllocator, out_pPipelineLayout);
    CheckResult("vkCreatePipelineLayout", returnValue, replay_result);

    AddHandles<VkPipelineLayout>(pPipelineLayout->GetPointer(), 1, out_pPipelineLayout, 1, &VulkanObjectMapper::AddVkPipelineLayout);
}

void VulkanReplayConsumer::Process_vkDestroyPipelineLayout(
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPipelineLayout in_pipelineLayout = MapHandle<PipelineLayoutInfo>(pipelineLayout, &VulkanObjectMapper::MapVkPipelineLayout);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyPipelineLayout(in_device, in_pipelineLayout, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateSampler(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkSamplerCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSampler>*            pSampler)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkSamplerCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSampler* out_pSampler = pSampler->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSampler(in_device, in_pCreateInfo, in_pAllocator, out_pSampler);
    CheckResult("vkCreateSampler", returnValue, replay_result);

    AddHandles<VkSampler>(pSampler->GetPointer(), 1, out_pSampler, 1, &VulkanObjectMapper::AddVkSampler);
}

void VulkanReplayConsumer::Process_vkDestroySampler(
    format::HandleId                            device,
    format::HandleId                            sampler,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSampler in_sampler = MapHandle<SamplerInfo>(sampler, &VulkanObjectMapper::MapVkSampler);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroySampler(in_device, in_sampler, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorSetLayout(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDescriptorSetLayout* out_pSetLayout = pSetLayout->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateDescriptorSetLayout(in_device, in_pCreateInfo, in_pAllocator, out_pSetLayout);
    CheckResult("vkCreateDescriptorSetLayout", returnValue, replay_result);

    AddHandles<VkDescriptorSetLayout>(pSetLayout->GetPointer(), 1, out_pSetLayout, 1, &VulkanObjectMapper::AddVkDescriptorSetLayout);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorSetLayout(
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDescriptorSetLayout in_descriptorSetLayout = MapHandle<DescriptorSetLayoutInfo>(descriptorSetLayout, &VulkanObjectMapper::MapVkDescriptorSetLayout);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyDescriptorSetLayout(in_device, in_descriptorSetLayout, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkDescriptorPoolCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDescriptorPool* out_pDescriptorPool = pDescriptorPool->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateDescriptorPool(in_device, in_pCreateInfo, in_pAllocator, out_pDescriptorPool);
    CheckResult("vkCreateDescriptorPool", returnValue, replay_result);

    AddHandles<VkDescriptorPool>(pDescriptorPool->GetPointer(), 1, out_pDescriptorPool, 1, &VulkanObjectMapper::AddVkDescriptorPool);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorPool(
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDescriptorPool in_descriptorPool = MapHandle<DescriptorPoolInfo>(descriptorPool, &VulkanObjectMapper::MapVkDescriptorPool);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyDescriptorPool(in_device, in_descriptorPool, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkResetDescriptorPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDescriptorPool in_descriptorPool = MapHandle<DescriptorPoolInfo>(descriptorPool, &VulkanObjectMapper::MapVkDescriptorPool);

    VkResult replay_result = GetDeviceTable(in_device)->ResetDescriptorPool(in_device, in_descriptorPool, flags);
    CheckResult("vkResetDescriptorPool", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkAllocateDescriptorSets(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>& pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkDescriptorSetAllocateInfo* in_pAllocateInfo = pAllocateInfo.GetPointer();
    MapStructHandles(pAllocateInfo.GetMetaStructPointer(), GetObjectMapper());
    VkDescriptorSet* out_pDescriptorSets = pDescriptorSets->GetHandlePointer();

    VkResult replay_result = OverrideAllocateDescriptorSets(GetDeviceTable(in_device)->AllocateDescriptorSets, returnValue, in_device, in_pAllocateInfo, pDescriptorSets);
    CheckResult("vkAllocateDescriptorSets", returnValue, replay_result);

    AddHandles<VkDescriptorSet>(pDescriptorSets->GetPointer(), pDescriptorSets->GetLength(), out_pDescriptorSets, in_pAllocateInfo->descriptorSetCount, &VulkanObjectMapper::AddVkDescriptorSet);
}

void VulkanReplayConsumer::Process_vkFreeDescriptorSets(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    const HandlePointerDecoder<VkDescriptorSet>& pDescriptorSets)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDescriptorPool in_descriptorPool = MapHandle<DescriptorPoolInfo>(descriptorPool, &VulkanObjectMapper::MapVkDescriptorPool);
    VkDescriptorSet* in_pDescriptorSets = pDescriptorSets.GetHandlePointer();
    MapHandles<DescriptorSetInfo>(pDescriptorSets.GetPointer(), pDescriptorSets.GetLength(), in_pDescriptorSets, descriptorSetCount, &VulkanObjectMapper::MapVkDescriptorSet);

    VkResult replay_result = GetDeviceTable(in_device)->FreeDescriptorSets(in_device, in_descriptorPool, descriptorSetCount, in_pDescriptorSets);
    CheckResult("vkFreeDescriptorSets", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkUpdateDescriptorSets(
    format::HandleId                            device,
    uint32_t                                    descriptorWriteCount,
    const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    const StructPointerDecoder<Decoded_VkCopyDescriptorSet>& pDescriptorCopies)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkWriteDescriptorSet* in_pDescriptorWrites = pDescriptorWrites.GetPointer();
    MapStructArrayHandles(pDescriptorWrites.GetMetaStructPointer(), pDescriptorWrites.GetLength(), GetObjectMapper());
    const VkCopyDescriptorSet* in_pDescriptorCopies = pDescriptorCopies.GetPointer();
    MapStructArrayHandles(pDescriptorCopies.GetMetaStructPointer(), pDescriptorCopies.GetLength(), GetObjectMapper());

    GetDeviceTable(in_device)->UpdateDescriptorSets(in_device, descriptorWriteCount, in_pDescriptorWrites, descriptorCopyCount, in_pDescriptorCopies);
}

void VulkanReplayConsumer::Process_vkCreateFramebuffer(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkFramebufferCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkFramebuffer>*        pFramebuffer)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkFramebufferCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkFramebuffer* out_pFramebuffer = pFramebuffer->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateFramebuffer(in_device, in_pCreateInfo, in_pAllocator, out_pFramebuffer);
    CheckResult("vkCreateFramebuffer", returnValue, replay_result);

    AddHandles<VkFramebuffer>(pFramebuffer->GetPointer(), 1, out_pFramebuffer, 1, &VulkanObjectMapper::AddVkFramebuffer);
}

void VulkanReplayConsumer::Process_vkDestroyFramebuffer(
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkFramebuffer in_framebuffer = MapHandle<FramebufferInfo>(framebuffer, &VulkanObjectMapper::MapVkFramebuffer);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyFramebuffer(in_device, in_framebuffer, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateRenderPass(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkRenderPassCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkRenderPass* out_pRenderPass = pRenderPass->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateRenderPass(in_device, in_pCreateInfo, in_pAllocator, out_pRenderPass);
    CheckResult("vkCreateRenderPass", returnValue, replay_result);

    AddHandles<VkRenderPass>(pRenderPass->GetPointer(), 1, out_pRenderPass, 1, &VulkanObjectMapper::AddVkRenderPass);
}

void VulkanReplayConsumer::Process_vkDestroyRenderPass(
    format::HandleId                            device,
    format::HandleId                            renderPass,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkRenderPass in_renderPass = MapHandle<RenderPassInfo>(renderPass, &VulkanObjectMapper::MapVkRenderPass);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyRenderPass(in_device, in_renderPass, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetRenderAreaGranularity(
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkRenderPass in_renderPass = MapHandle<RenderPassInfo>(renderPass, &VulkanObjectMapper::MapVkRenderPass);
    VkExtent2D* out_pGranularity = pGranularity->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetRenderAreaGranularity(in_device, in_renderPass, out_pGranularity);
}

void VulkanReplayConsumer::Process_vkCreateCommandPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkCommandPool>*        pCommandPool)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkCommandPoolCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkCommandPool* out_pCommandPool = pCommandPool->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateCommandPool(in_device, in_pCreateInfo, in_pAllocator, out_pCommandPool);
    CheckResult("vkCreateCommandPool", returnValue, replay_result);

    AddHandles<VkCommandPool>(pCommandPool->GetPointer(), 1, out_pCommandPool, 1, &VulkanObjectMapper::AddVkCommandPool);
}

void VulkanReplayConsumer::Process_vkDestroyCommandPool(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkCommandPool in_commandPool = MapHandle<CommandPoolInfo>(commandPool, &VulkanObjectMapper::MapVkCommandPool);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyCommandPool(in_device, in_commandPool, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkResetCommandPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolResetFlags                     flags)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkCommandPool in_commandPool = MapHandle<CommandPoolInfo>(commandPool, &VulkanObjectMapper::MapVkCommandPool);

    VkResult replay_result = GetDeviceTable(in_device)->ResetCommandPool(in_device, in_commandPool, flags);
    CheckResult("vkResetCommandPool", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkAllocateCommandBuffers(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>& pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkCommandBufferAllocateInfo* in_pAllocateInfo = pAllocateInfo.GetPointer();
    MapStructHandles(pAllocateInfo.GetMetaStructPointer(), GetObjectMapper());
    VkCommandBuffer* out_pCommandBuffers = pCommandBuffers->GetHandlePointer();

    VkResult replay_result = OverrideAllocateCommandBuffers(GetDeviceTable(in_device)->AllocateCommandBuffers, returnValue, in_device, in_pAllocateInfo, pCommandBuffers);
    CheckResult("vkAllocateCommandBuffers", returnValue, replay_result);

    AddHandles<VkCommandBuffer>(pCommandBuffers->GetPointer(), pCommandBuffers->GetLength(), out_pCommandBuffers, in_pAllocateInfo->commandBufferCount, &VulkanObjectMapper::AddVkCommandBuffer);
}

void VulkanReplayConsumer::Process_vkFreeCommandBuffers(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    const HandlePointerDecoder<VkCommandBuffer>& pCommandBuffers)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkCommandPool in_commandPool = MapHandle<CommandPoolInfo>(commandPool, &VulkanObjectMapper::MapVkCommandPool);
    VkCommandBuffer* in_pCommandBuffers = pCommandBuffers.GetHandlePointer();
    MapHandles<CommandBufferInfo>(pCommandBuffers.GetPointer(), pCommandBuffers.GetLength(), in_pCommandBuffers, commandBufferCount, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_device)->FreeCommandBuffers(in_device, in_commandPool, commandBufferCount, in_pCommandBuffers);
}

void VulkanReplayConsumer::Process_vkBeginCommandBuffer(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>& pBeginInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkCommandBufferBeginInfo* in_pBeginInfo = pBeginInfo.GetPointer();
    MapStructHandles(pBeginInfo.GetMetaStructPointer(), GetObjectMapper());

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->BeginCommandBuffer(in_commandBuffer, in_pBeginInfo);
    CheckResult("vkBeginCommandBuffer", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkEndCommandBuffer(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->EndCommandBuffer(in_commandBuffer);
    CheckResult("vkEndCommandBuffer", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkResetCommandBuffer(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->ResetCommandBuffer(in_commandBuffer, flags);
    CheckResult("vkResetCommandBuffer", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdBindPipeline(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkPipeline in_pipeline = MapHandle<PipelineInfo>(pipeline, &VulkanObjectMapper::MapVkPipeline);

    GetDeviceTable(in_commandBuffer)->CmdBindPipeline(in_commandBuffer, pipelineBindPoint, in_pipeline);
}

void VulkanReplayConsumer::Process_vkCmdSetViewport(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const StructPointerDecoder<Decoded_VkViewport>& pViewports)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkViewport* in_pViewports = pViewports.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewport(in_commandBuffer, firstViewport, viewportCount, in_pViewports);
}

void VulkanReplayConsumer::Process_vkCmdSetScissor(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const StructPointerDecoder<Decoded_VkRect2D>& pScissors)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkRect2D* in_pScissors = pScissors.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetScissor(in_commandBuffer, firstScissor, scissorCount, in_pScissors);
}

void VulkanReplayConsumer::Process_vkCmdSetLineWidth(
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdSetLineWidth(in_commandBuffer, lineWidth);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBias(
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBias(in_commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

void VulkanReplayConsumer::Process_vkCmdSetBlendConstants(
    format::HandleId                            commandBuffer,
    const PointerDecoder<float>&                blendConstants)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const float* in_blendConstants = blendConstants.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetBlendConstants(in_commandBuffer, in_blendConstants);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBounds(
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBounds(in_commandBuffer, minDepthBounds, maxDepthBounds);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilCompareMask(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilCompareMask(in_commandBuffer, faceMask, compareMask);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilWriteMask(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilWriteMask(in_commandBuffer, faceMask, writeMask);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilReference(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilReference(in_commandBuffer, faceMask, reference);
}

void VulkanReplayConsumer::Process_vkCmdBindDescriptorSets(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const HandlePointerDecoder<VkDescriptorSet>& pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const PointerDecoder<uint32_t>&             pDynamicOffsets)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkPipelineLayout in_layout = MapHandle<PipelineLayoutInfo>(layout, &VulkanObjectMapper::MapVkPipelineLayout);
    VkDescriptorSet* in_pDescriptorSets = pDescriptorSets.GetHandlePointer();
    MapHandles<DescriptorSetInfo>(pDescriptorSets.GetPointer(), pDescriptorSets.GetLength(), in_pDescriptorSets, descriptorSetCount, &VulkanObjectMapper::MapVkDescriptorSet);
    const uint32_t* in_pDynamicOffsets = pDynamicOffsets.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindDescriptorSets(in_commandBuffer, pipelineBindPoint, in_layout, firstSet, descriptorSetCount, in_pDescriptorSets, dynamicOffsetCount, in_pDynamicOffsets);
}

void VulkanReplayConsumer::Process_vkCmdBindIndexBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdBindIndexBuffer(in_commandBuffer, in_buffer, offset, indexType);
}

void VulkanReplayConsumer::Process_vkCmdBindVertexBuffers(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const HandlePointerDecoder<VkBuffer>&       pBuffers,
    const PointerDecoder<VkDeviceSize>&         pOffsets)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer* in_pBuffers = pBuffers.GetHandlePointer();
    MapHandles<BufferInfo>(pBuffers.GetPointer(), pBuffers.GetLength(), in_pBuffers, bindingCount, &VulkanObjectMapper::MapVkBuffer);
    const VkDeviceSize* in_pOffsets = pOffsets.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers(in_commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets);
}

void VulkanReplayConsumer::Process_vkCmdDraw(
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDraw(in_commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexed(
    format::HandleId                            commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexed(in_commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirect(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirect(in_commandBuffer, in_buffer, offset, drawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirect(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirect(in_commandBuffer, in_buffer, offset, drawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDispatch(
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDispatch(in_commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkCmdDispatchIndirect(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDispatchIndirect(in_commandBuffer, in_buffer, offset);
}

void VulkanReplayConsumer::Process_vkCmdCopyBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkBufferCopy>& pRegions)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_srcBuffer = MapHandle<BufferInfo>(srcBuffer, &VulkanObjectMapper::MapVkBuffer);
    VkBuffer in_dstBuffer = MapHandle<BufferInfo>(dstBuffer, &VulkanObjectMapper::MapVkBuffer);
    const VkBufferCopy* in_pRegions = pRegions.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdCopyBuffer(in_commandBuffer, in_srcBuffer, in_dstBuffer, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdCopyImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkImageCopy>& pRegions)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkImage in_srcImage = MapHandle<ImageInfo>(srcImage, &VulkanObjectMapper::MapVkImage);
    VkImage in_dstImage = MapHandle<ImageInfo>(dstImage, &VulkanObjectMapper::MapVkImage);
    const VkImageCopy* in_pRegions = pRegions.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdCopyImage(in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdBlitImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkImageBlit>& pRegions,
    VkFilter                                    filter)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkImage in_srcImage = MapHandle<ImageInfo>(srcImage, &VulkanObjectMapper::MapVkImage);
    VkImage in_dstImage = MapHandle<ImageInfo>(dstImage, &VulkanObjectMapper::MapVkImage);
    const VkImageBlit* in_pRegions = pRegions.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBlitImage(in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions, filter);
}

void VulkanReplayConsumer::Process_vkCmdCopyBufferToImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_srcBuffer = MapHandle<BufferInfo>(srcBuffer, &VulkanObjectMapper::MapVkBuffer);
    VkImage in_dstImage = MapHandle<ImageInfo>(dstImage, &VulkanObjectMapper::MapVkImage);
    const VkBufferImageCopy* in_pRegions = pRegions.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdCopyBufferToImage(in_commandBuffer, in_srcBuffer, in_dstImage, dstImageLayout, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkImage in_srcImage = MapHandle<ImageInfo>(srcImage, &VulkanObjectMapper::MapVkImage);
    VkBuffer in_dstBuffer = MapHandle<BufferInfo>(dstBuffer, &VulkanObjectMapper::MapVkBuffer);
    const VkBufferImageCopy* in_pRegions = pRegions.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdCopyImageToBuffer(in_commandBuffer, in_srcImage, srcImageLayout, in_dstBuffer, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdUpdateBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const PointerDecoder<uint8_t>&              pData)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_dstBuffer = MapHandle<BufferInfo>(dstBuffer, &VulkanObjectMapper::MapVkBuffer);
    const void* in_pData = pData.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdUpdateBuffer(in_commandBuffer, in_dstBuffer, dstOffset, dataSize, in_pData);
}

void VulkanReplayConsumer::Process_vkCmdFillBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_dstBuffer = MapHandle<BufferInfo>(dstBuffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdFillBuffer(in_commandBuffer, in_dstBuffer, dstOffset, size, data);
}

void VulkanReplayConsumer::Process_vkCmdClearColorImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    const StructPointerDecoder<Decoded_VkClearColorValue>& pColor,
    uint32_t                                    rangeCount,
    const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectMapper::MapVkImage);
    const VkClearColorValue* in_pColor = pColor.GetPointer();
    const VkImageSubresourceRange* in_pRanges = pRanges.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdClearColorImage(in_commandBuffer, in_image, imageLayout, in_pColor, rangeCount, in_pRanges);
}

void VulkanReplayConsumer::Process_vkCmdClearDepthStencilImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    const StructPointerDecoder<Decoded_VkClearDepthStencilValue>& pDepthStencil,
    uint32_t                                    rangeCount,
    const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectMapper::MapVkImage);
    const VkClearDepthStencilValue* in_pDepthStencil = pDepthStencil.GetPointer();
    const VkImageSubresourceRange* in_pRanges = pRanges.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdClearDepthStencilImage(in_commandBuffer, in_image, imageLayout, in_pDepthStencil, rangeCount, in_pRanges);
}

void VulkanReplayConsumer::Process_vkCmdClearAttachments(
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    const StructPointerDecoder<Decoded_VkClearAttachment>& pAttachments,
    uint32_t                                    rectCount,
    const StructPointerDecoder<Decoded_VkClearRect>& pRects)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkClearAttachment* in_pAttachments = pAttachments.GetPointer();
    const VkClearRect* in_pRects = pRects.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdClearAttachments(in_commandBuffer, attachmentCount, in_pAttachments, rectCount, in_pRects);
}

void VulkanReplayConsumer::Process_vkCmdResolveImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const StructPointerDecoder<Decoded_VkImageResolve>& pRegions)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkImage in_srcImage = MapHandle<ImageInfo>(srcImage, &VulkanObjectMapper::MapVkImage);
    VkImage in_dstImage = MapHandle<ImageInfo>(dstImage, &VulkanObjectMapper::MapVkImage);
    const VkImageResolve* in_pRegions = pRegions.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdResolveImage(in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdSetEvent(
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectMapper::MapVkEvent);

    GetDeviceTable(in_commandBuffer)->CmdSetEvent(in_commandBuffer, in_event, stageMask);
}

void VulkanReplayConsumer::Process_vkCmdResetEvent(
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectMapper::MapVkEvent);

    GetDeviceTable(in_commandBuffer)->CmdResetEvent(in_commandBuffer, in_event, stageMask);
}

void VulkanReplayConsumer::Process_vkCmdWaitEvents(
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    const HandlePointerDecoder<VkEvent>&        pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const StructPointerDecoder<Decoded_VkMemoryBarrier>& pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>& pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkImageMemoryBarrier>& pImageMemoryBarriers)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkEvent* in_pEvents = pEvents.GetHandlePointer();
    MapHandles<EventInfo>(pEvents.GetPointer(), pEvents.GetLength(), in_pEvents, eventCount, &VulkanObjectMapper::MapVkEvent);
    const VkMemoryBarrier* in_pMemoryBarriers = pMemoryBarriers.GetPointer();
    const VkBufferMemoryBarrier* in_pBufferMemoryBarriers = pBufferMemoryBarriers.GetPointer();
    MapStructArrayHandles(pBufferMemoryBarriers.GetMetaStructPointer(), pBufferMemoryBarriers.GetLength(), GetObjectMapper());
    const VkImageMemoryBarrier* in_pImageMemoryBarriers = pImageMemoryBarriers.GetPointer();
    MapStructArrayHandles(pImageMemoryBarriers.GetMetaStructPointer(), pImageMemoryBarriers.GetLength(), GetObjectMapper());

    GetDeviceTable(in_commandBuffer)->CmdWaitEvents(in_commandBuffer, eventCount, in_pEvents, srcStageMask, dstStageMask, memoryBarrierCount, in_pMemoryBarriers, bufferMemoryBarrierCount, in_pBufferMemoryBarriers, imageMemoryBarrierCount, in_pImageMemoryBarriers);
}

void VulkanReplayConsumer::Process_vkCmdPipelineBarrier(
    format::HandleId                            commandBuffer,
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
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkMemoryBarrier* in_pMemoryBarriers = pMemoryBarriers.GetPointer();
    const VkBufferMemoryBarrier* in_pBufferMemoryBarriers = pBufferMemoryBarriers.GetPointer();
    MapStructArrayHandles(pBufferMemoryBarriers.GetMetaStructPointer(), pBufferMemoryBarriers.GetLength(), GetObjectMapper());
    const VkImageMemoryBarrier* in_pImageMemoryBarriers = pImageMemoryBarriers.GetPointer();
    MapStructArrayHandles(pImageMemoryBarriers.GetMetaStructPointer(), pImageMemoryBarriers.GetLength(), GetObjectMapper());

    GetDeviceTable(in_commandBuffer)->CmdPipelineBarrier(in_commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, in_pMemoryBarriers, bufferMemoryBarrierCount, in_pBufferMemoryBarriers, imageMemoryBarrierCount, in_pImageMemoryBarriers);
}

void VulkanReplayConsumer::Process_vkCmdBeginQuery(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectMapper::MapVkQueryPool);

    GetDeviceTable(in_commandBuffer)->CmdBeginQuery(in_commandBuffer, in_queryPool, query, flags);
}

void VulkanReplayConsumer::Process_vkCmdEndQuery(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectMapper::MapVkQueryPool);

    GetDeviceTable(in_commandBuffer)->CmdEndQuery(in_commandBuffer, in_queryPool, query);
}

void VulkanReplayConsumer::Process_vkCmdResetQueryPool(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectMapper::MapVkQueryPool);

    GetDeviceTable(in_commandBuffer)->CmdResetQueryPool(in_commandBuffer, in_queryPool, firstQuery, queryCount);
}

void VulkanReplayConsumer::Process_vkCmdWriteTimestamp(
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectMapper::MapVkQueryPool);

    GetDeviceTable(in_commandBuffer)->CmdWriteTimestamp(in_commandBuffer, pipelineStage, in_queryPool, query);
}

void VulkanReplayConsumer::Process_vkCmdCopyQueryPoolResults(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectMapper::MapVkQueryPool);
    VkBuffer in_dstBuffer = MapHandle<BufferInfo>(dstBuffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdCopyQueryPoolResults(in_commandBuffer, in_queryPool, firstQuery, queryCount, in_dstBuffer, dstOffset, stride, flags);
}

void VulkanReplayConsumer::Process_vkCmdPushConstants(
    format::HandleId                            commandBuffer,
    format::HandleId                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const PointerDecoder<uint8_t>&              pValues)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkPipelineLayout in_layout = MapHandle<PipelineLayoutInfo>(layout, &VulkanObjectMapper::MapVkPipelineLayout);
    const void* in_pValues = pValues.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdPushConstants(in_commandBuffer, in_layout, stageFlags, offset, size, in_pValues);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass(
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
    VkSubpassContents                           contents)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkRenderPassBeginInfo* in_pRenderPassBegin = pRenderPassBegin.GetPointer();
    MapStructHandles(pRenderPassBegin.GetMetaStructPointer(), GetObjectMapper());

    GetDeviceTable(in_commandBuffer)->CmdBeginRenderPass(in_commandBuffer, in_pRenderPassBegin, contents);
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass(
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdNextSubpass(in_commandBuffer, contents);
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass(
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdEndRenderPass(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdExecuteCommands(
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    const HandlePointerDecoder<VkCommandBuffer>& pCommandBuffers)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkCommandBuffer* in_pCommandBuffers = pCommandBuffers.GetHandlePointer();
    MapHandles<CommandBufferInfo>(pCommandBuffers.GetPointer(), pCommandBuffers.GetLength(), in_pCommandBuffers, commandBufferCount, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdExecuteCommands(in_commandBuffer, commandBufferCount, in_pCommandBuffers);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory2(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkBindBufferMemoryInfo* in_pBindInfos = pBindInfos.GetPointer();
    MapStructArrayHandles(pBindInfos.GetMetaStructPointer(), pBindInfos.GetLength(), GetObjectMapper());

    VkResult replay_result = OverrideBindBufferMemory2(GetDeviceTable(in_device)->BindBufferMemory2, returnValue, in_device, bindInfoCount, in_pBindInfos);
    CheckResult("vkBindBufferMemory2", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkBindImageMemory2(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkBindImageMemoryInfo* in_pBindInfos = pBindInfos.GetPointer();
    MapStructArrayHandles(pBindInfos.GetMetaStructPointer(), pBindInfos.GetLength(), GetObjectMapper());

    VkResult replay_result = OverrideBindImageMemory2(GetDeviceTable(in_device)->BindImageMemory2, returnValue, in_device, bindInfoCount, in_pBindInfos);
    CheckResult("vkBindImageMemory2", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPeerMemoryFeatureFlags* out_pPeerMemoryFeatures = pPeerMemoryFeatures->AllocateOutputData(1, static_cast<VkPeerMemoryFeatureFlags>(0));

    GetDeviceTable(in_device)->GetDeviceGroupPeerMemoryFeatures(in_device, heapIndex, localDeviceIndex, remoteDeviceIndex, out_pPeerMemoryFeatures);
}

void VulkanReplayConsumer::Process_vkCmdSetDeviceMask(
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdSetDeviceMask(in_commandBuffer, deviceMask);
}

void VulkanReplayConsumer::Process_vkCmdDispatchBase(
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDispatchBase(in_commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    uint32_t* out_pPhysicalDeviceGroupCount = pPhysicalDeviceGroupCount->AllocateOutputData(1, pPhysicalDeviceGroupCount->IsNull() ? static_cast<uint32_t>(0) : (*pPhysicalDeviceGroupCount->GetPointer()));
    VkPhysicalDeviceGroupProperties* out_pPhysicalDeviceGroupProperties = pPhysicalDeviceGroupProperties->IsNull() ? nullptr : pPhysicalDeviceGroupProperties->AllocateOutputData(*out_pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES, nullptr });

    VkResult replay_result = GetInstanceTable(in_instance)->EnumeratePhysicalDeviceGroups(in_instance, out_pPhysicalDeviceGroupCount, out_pPhysicalDeviceGroupProperties);
    CheckResult("vkEnumeratePhysicalDeviceGroups", returnValue, replay_result);

    AddStructArrayHandles<Decoded_VkPhysicalDeviceGroupProperties>(pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength(), out_pPhysicalDeviceGroupProperties, *out_pPhysicalDeviceGroupCount, GetObjectMapper());
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements2(
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkImageMemoryRequirementsInfo2* in_pInfo = pInfo.GetPointer();
    MapStructHandles(pInfo.GetMetaStructPointer(), GetObjectMapper());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetImageMemoryRequirements2(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements2(
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkBufferMemoryRequirementsInfo2* in_pInfo = pInfo.GetPointer();
    MapStructHandles(pInfo.GetMetaStructPointer(), GetObjectMapper());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetBufferMemoryRequirements2(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements2(
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkImageSparseMemoryRequirementsInfo2* in_pInfo = pInfo.GetPointer();
    MapStructHandles(pInfo.GetMetaStructPointer(), GetObjectMapper());
    uint32_t* out_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->AllocateOutputData(1, pSparseMemoryRequirementCount->IsNull() ? static_cast<uint32_t>(0) : (*pSparseMemoryRequirementCount->GetPointer()));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements->IsNull() ? nullptr : pSparseMemoryRequirements->AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetImageSparseMemoryRequirements2(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkPhysicalDeviceFeatures2* out_pFeatures = pFeatures->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFeatures2(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkPhysicalDeviceProperties2* out_pProperties = pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, nullptr });

    OverrideGetPhysicalDeviceProperties2(GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceProperties2, in_physicalDevice, pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkFormatProperties2* out_pFormatProperties = pFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFormatProperties2(in_physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkPhysicalDeviceImageFormatInfo2* in_pImageFormatInfo = pImageFormatInfo.GetPointer();
    VkImageFormatProperties2* out_pImageFormatProperties = pImageFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceImageFormatProperties2(in_physicalDevice, in_pImageFormatInfo, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceImageFormatProperties2", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    uint32_t* out_pQueueFamilyPropertyCount = pQueueFamilyPropertyCount->AllocateOutputData(1, pQueueFamilyPropertyCount->IsNull() ? static_cast<uint32_t>(0) : (*pQueueFamilyPropertyCount->GetPointer()));
    VkQueueFamilyProperties2* out_pQueueFamilyProperties = pQueueFamilyProperties->IsNull() ? nullptr : pQueueFamilyProperties->AllocateOutputData(*out_pQueueFamilyPropertyCount, VkQueueFamilyProperties2{ VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2(in_physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkPhysicalDeviceMemoryProperties2* out_pMemoryProperties = pMemoryProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceMemoryProperties2(in_physicalDevice, out_pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkPhysicalDeviceSparseImageFormatInfo2* in_pFormatInfo = pFormatInfo.GetPointer();
    uint32_t* out_pPropertyCount = pPropertyCount->AllocateOutputData(1, pPropertyCount->IsNull() ? static_cast<uint32_t>(0) : (*pPropertyCount->GetPointer()));
    VkSparseImageFormatProperties2* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkSparseImageFormatProperties2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(in_physicalDevice, in_pFormatInfo, out_pPropertyCount, out_pProperties);
}

void VulkanReplayConsumer::Process_vkTrimCommandPool(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkCommandPool in_commandPool = MapHandle<CommandPoolInfo>(commandPool, &VulkanObjectMapper::MapVkCommandPool);

    GetDeviceTable(in_device)->TrimCommandPool(in_device, in_commandPool, flags);
}

void VulkanReplayConsumer::Process_vkGetDeviceQueue2(
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkDeviceQueueInfo2>& pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkDeviceQueueInfo2* in_pQueueInfo = pQueueInfo.GetPointer();
    VkQueue* out_pQueue = pQueue->GetHandlePointer();

    GetDeviceTable(in_device)->GetDeviceQueue2(in_device, in_pQueueInfo, out_pQueue);

    AddHandles<VkQueue>(pQueue->GetPointer(), 1, out_pQueue, 1, &VulkanObjectMapper::AddVkQueue);
}

void VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversion(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkSamplerYcbcrConversionCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSamplerYcbcrConversion* out_pYcbcrConversion = pYcbcrConversion->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSamplerYcbcrConversion(in_device, in_pCreateInfo, in_pAllocator, out_pYcbcrConversion);
    CheckResult("vkCreateSamplerYcbcrConversion", returnValue, replay_result);

    AddHandles<VkSamplerYcbcrConversion>(pYcbcrConversion->GetPointer(), 1, out_pYcbcrConversion, 1, &VulkanObjectMapper::AddVkSamplerYcbcrConversion);
}

void VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversion(
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSamplerYcbcrConversion in_ycbcrConversion = MapHandle<SamplerYcbcrConversionInfo>(ycbcrConversion, &VulkanObjectMapper::MapVkSamplerYcbcrConversion);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroySamplerYcbcrConversion(in_device, in_ycbcrConversion, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplate(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkDescriptorUpdateTemplateCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDescriptorUpdateTemplate* out_pDescriptorUpdateTemplate = pDescriptorUpdateTemplate->GetHandlePointer();

    VkResult replay_result = OverrideCreateDescriptorUpdateTemplate(GetDeviceTable(in_device)->CreateDescriptorUpdateTemplate, returnValue, in_device, in_pCreateInfo, in_pAllocator, pDescriptorUpdateTemplate);
    CheckResult("vkCreateDescriptorUpdateTemplate", returnValue, replay_result);

    AddHandles<VkDescriptorUpdateTemplate>(pDescriptorUpdateTemplate->GetPointer(), 1, out_pDescriptorUpdateTemplate, 1, &VulkanObjectMapper::AddVkDescriptorUpdateTemplate);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = MapHandle<DescriptorUpdateTemplateInfo>(descriptorUpdateTemplate, &VulkanObjectMapper::MapVkDescriptorUpdateTemplate);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    OverrideDestroyDescriptorUpdateTemplate(GetDeviceTable(in_device)->DestroyDescriptorUpdateTemplate, in_device, in_descriptorUpdateTemplate, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkPhysicalDeviceExternalBufferInfo* in_pExternalBufferInfo = pExternalBufferInfo.GetPointer();
    VkExternalBufferProperties* out_pExternalBufferProperties = pExternalBufferProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalBufferProperties(in_physicalDevice, in_pExternalBufferInfo, out_pExternalBufferProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkPhysicalDeviceExternalFenceInfo* in_pExternalFenceInfo = pExternalFenceInfo.GetPointer();
    VkExternalFenceProperties* out_pExternalFenceProperties = pExternalFenceProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalFenceProperties(in_physicalDevice, in_pExternalFenceInfo, out_pExternalFenceProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkPhysicalDeviceExternalSemaphoreInfo* in_pExternalSemaphoreInfo = pExternalSemaphoreInfo.GetPointer();
    VkExternalSemaphoreProperties* out_pExternalSemaphoreProperties = pExternalSemaphoreProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(in_physicalDevice, in_pExternalSemaphoreInfo, out_pExternalSemaphoreProperties);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutSupport(
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    VkDescriptorSetLayoutSupport* out_pSupport = pSupport->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT, nullptr });

    GetDeviceTable(in_device)->GetDescriptorSetLayoutSupport(in_device, in_pCreateInfo, out_pSupport);
}

void VulkanReplayConsumer::Process_vkDestroySurfaceKHR(
    format::HandleId                            instance,
    format::HandleId                            surface,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectMapper::MapVkSurfaceKHR);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    OverrideDestroySurfaceKHR(GetInstanceTable(in_instance)->DestroySurfaceKHR, in_instance, in_surface, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    format::HandleId                            surface,
    PointerDecoder<VkBool32>*                   pSupported)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectMapper::MapVkSurfaceKHR);
    VkBool32* out_pSupported = pSupported->AllocateOutputData(1, static_cast<VkBool32>(0));

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(in_physicalDevice, queueFamilyIndex, in_surface, out_pSupported);
    CheckResult("vkGetPhysicalDeviceSurfaceSupportKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectMapper::MapVkSurfaceKHR);
    VkSurfaceCapabilitiesKHR* out_pSurfaceCapabilities = pSurfaceCapabilities->AllocateOutputData(1);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceCapabilitiesKHR(in_physicalDevice, in_surface, out_pSurfaceCapabilities);
    CheckResult("vkGetPhysicalDeviceSurfaceCapabilitiesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectMapper::MapVkSurfaceKHR);
    uint32_t* out_pSurfaceFormatCount = pSurfaceFormatCount->AllocateOutputData(1, pSurfaceFormatCount->IsNull() ? static_cast<uint32_t>(0) : (*pSurfaceFormatCount->GetPointer()));
    VkSurfaceFormatKHR* out_pSurfaceFormats = pSurfaceFormats->IsNull() ? nullptr : pSurfaceFormats->AllocateOutputData(*out_pSurfaceFormatCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceFormatsKHR(in_physicalDevice, in_surface, out_pSurfaceFormatCount, out_pSurfaceFormats);
    CheckResult("vkGetPhysicalDeviceSurfaceFormatsKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectMapper::MapVkSurfaceKHR);
    uint32_t* out_pPresentModeCount = pPresentModeCount->AllocateOutputData(1, pPresentModeCount->IsNull() ? static_cast<uint32_t>(0) : (*pPresentModeCount->GetPointer()));
    VkPresentModeKHR* out_pPresentModes = pPresentModes->IsNull() ? nullptr : pPresentModes->AllocateOutputData(*out_pPresentModeCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(in_physicalDevice, in_surface, out_pPresentModeCount, out_pPresentModes);
    CheckResult("vkGetPhysicalDeviceSurfacePresentModesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateSwapchainKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkSwapchainCreateInfoKHR* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSwapchainKHR* out_pSwapchain = pSwapchain->GetHandlePointer();

    VkResult replay_result = OverrideCreateSwapchainKHR(GetDeviceTable(in_device)->CreateSwapchainKHR, returnValue, in_device, in_pCreateInfo, in_pAllocator, pSwapchain);
    CheckResult("vkCreateSwapchainKHR", returnValue, replay_result);

    AddHandles<VkSwapchainKHR>(pSwapchain->GetPointer(), 1, out_pSwapchain, 1, &VulkanObjectMapper::AddVkSwapchainKHR);
}

void VulkanReplayConsumer::Process_vkDestroySwapchainKHR(
    format::HandleId                            device,
    format::HandleId                            swapchain,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectMapper::MapVkSwapchainKHR);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroySwapchainKHR(in_device, in_swapchain, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetSwapchainImagesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pSwapchainImageCount,
    HandlePointerDecoder<VkImage>*              pSwapchainImages)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectMapper::MapVkSwapchainKHR);
    uint32_t* out_pSwapchainImageCount = pSwapchainImageCount->AllocateOutputData(1, pSwapchainImageCount->IsNull() ? static_cast<uint32_t>(0) : (*pSwapchainImageCount->GetPointer()));
    VkImage* out_pSwapchainImages = pSwapchainImages->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->GetSwapchainImagesKHR(in_device, in_swapchain, out_pSwapchainImageCount, out_pSwapchainImages);
    CheckResult("vkGetSwapchainImagesKHR", returnValue, replay_result);

    AddHandles<VkImage>(pSwapchainImages->GetPointer(), pSwapchainImages->GetLength(), out_pSwapchainImages, *out_pSwapchainImageCount, &VulkanObjectMapper::AddVkImage);
}

void VulkanReplayConsumer::Process_vkAcquireNextImageKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    timeout,
    format::HandleId                            semaphore,
    format::HandleId                            fence,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectMapper::MapVkSwapchainKHR);
    VkSemaphore in_semaphore = MapHandle<SemaphoreInfo>(semaphore, &VulkanObjectMapper::MapVkSemaphore);
    VkFence in_fence = MapHandle<FenceInfo>(fence, &VulkanObjectMapper::MapVkFence);
    uint32_t* out_pImageIndex = pImageIndex->AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = OverrideAcquireNextImageKHR(GetDeviceTable(in_device)->AcquireNextImageKHR, returnValue, in_device, in_swapchain, timeout, in_semaphore, in_fence, pImageIndex);
    CheckResult("vkAcquireNextImageKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkQueuePresentKHR(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    const StructPointerDecoder<Decoded_VkPresentInfoKHR>& pPresentInfo)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectMapper::MapVkQueue);
    const VkPresentInfoKHR* in_pPresentInfo = pPresentInfo.GetPointer();
    MapStructHandles(pPresentInfo.GetMetaStructPointer(), GetObjectMapper());

    VkResult replay_result = GetDeviceTable(in_queue)->QueuePresentKHR(in_queue, in_pPresentInfo);
    CheckResult("vkQueuePresentKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDeviceGroupPresentCapabilitiesKHR* out_pDeviceGroupPresentCapabilities = pDeviceGroupPresentCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceGroupPresentCapabilitiesKHR(in_device, out_pDeviceGroupPresentCapabilities);
    CheckResult("vkGetDeviceGroupPresentCapabilitiesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            surface,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectMapper::MapVkSurfaceKHR);
    VkDeviceGroupPresentModeFlagsKHR* out_pModes = pModes->AllocateOutputData(1, static_cast<VkDeviceGroupPresentModeFlagsKHR>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceGroupSurfacePresentModesKHR(in_device, in_surface, out_pModes);
    CheckResult("vkGetDeviceGroupSurfacePresentModesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pRectCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pRects)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectMapper::MapVkSurfaceKHR);
    uint32_t* out_pRectCount = pRectCount->AllocateOutputData(1, pRectCount->IsNull() ? static_cast<uint32_t>(0) : (*pRectCount->GetPointer()));
    VkRect2D* out_pRects = pRects->IsNull() ? nullptr : pRects->AllocateOutputData(*out_pRectCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(in_physicalDevice, in_surface, out_pRectCount, out_pRects);
    CheckResult("vkGetPhysicalDevicePresentRectanglesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkAcquireNextImage2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>& pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkAcquireNextImageInfoKHR* in_pAcquireInfo = pAcquireInfo.GetPointer();
    MapStructHandles(pAcquireInfo.GetMetaStructPointer(), GetObjectMapper());
    uint32_t* out_pImageIndex = pImageIndex->AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = OverrideAcquireNextImage2KHR(GetDeviceTable(in_device)->AcquireNextImage2KHR, returnValue, in_device, in_pAcquireInfo, pImageIndex);
    CheckResult("vkAcquireNextImage2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    uint32_t* out_pPropertyCount = pPropertyCount->AllocateOutputData(1, pPropertyCount->IsNull() ? static_cast<uint32_t>(0) : (*pPropertyCount->GetPointer()));
    VkDisplayPropertiesKHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayPropertiesKHR", returnValue, replay_result);

    AddStructArrayHandles<Decoded_VkDisplayPropertiesKHR>(pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, GetObjectMapper());
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    uint32_t* out_pPropertyCount = pPropertyCount->AllocateOutputData(1, pPropertyCount->IsNull() ? static_cast<uint32_t>(0) : (*pPropertyCount->GetPointer()));
    VkDisplayPlanePropertiesKHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", returnValue, replay_result);

    AddStructArrayHandles<Decoded_VkDisplayPlanePropertiesKHR>(pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, GetObjectMapper());
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    planeIndex,
    PointerDecoder<uint32_t>*                   pDisplayCount,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplays)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    uint32_t* out_pDisplayCount = pDisplayCount->AllocateOutputData(1, pDisplayCount->IsNull() ? static_cast<uint32_t>(0) : (*pDisplayCount->GetPointer()));
    VkDisplayKHR* out_pDisplays = pDisplays->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(in_physicalDevice, planeIndex, out_pDisplayCount, out_pDisplays);
    CheckResult("vkGetDisplayPlaneSupportedDisplaysKHR", returnValue, replay_result);

    AddHandles<VkDisplayKHR>(pDisplays->GetPointer(), pDisplays->GetLength(), out_pDisplays, *out_pDisplayCount, &VulkanObjectMapper::AddVkDisplayKHR);
}

void VulkanReplayConsumer::Process_vkGetDisplayModePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectMapper::MapVkDisplayKHR);
    uint32_t* out_pPropertyCount = pPropertyCount->AllocateOutputData(1, pPropertyCount->IsNull() ? static_cast<uint32_t>(0) : (*pPropertyCount->GetPointer()));
    VkDisplayModePropertiesKHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayModePropertiesKHR(in_physicalDevice, in_display, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetDisplayModePropertiesKHR", returnValue, replay_result);

    AddStructArrayHandles<Decoded_VkDisplayModePropertiesKHR>(pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, GetObjectMapper());
}

void VulkanReplayConsumer::Process_vkCreateDisplayModeKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    const StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkDisplayModeKHR>*     pMode)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectMapper::MapVkDisplayKHR);
    const VkDisplayModeCreateInfoKHR* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDisplayModeKHR* out_pMode = pMode->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->CreateDisplayModeKHR(in_physicalDevice, in_display, in_pCreateInfo, in_pAllocator, out_pMode);
    CheckResult("vkCreateDisplayModeKHR", returnValue, replay_result);

    AddHandles<VkDisplayModeKHR>(pMode->GetPointer(), 1, out_pMode, 1, &VulkanObjectMapper::AddVkDisplayModeKHR);
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            mode,
    uint32_t                                    planeIndex,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkDisplayModeKHR in_mode = MapHandle<DisplayModeKHRInfo>(mode, &VulkanObjectMapper::MapVkDisplayModeKHR);
    VkDisplayPlaneCapabilitiesKHR* out_pCapabilities = pCapabilities->AllocateOutputData(1);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayPlaneCapabilitiesKHR(in_physicalDevice, in_mode, planeIndex, out_pCapabilities);
    CheckResult("vkGetDisplayPlaneCapabilitiesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkDisplaySurfaceCreateInfoKHR* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateDisplayPlaneSurfaceKHR(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateDisplayPlaneSurfaceKHR", returnValue, replay_result);

    AddHandles<VkSurfaceKHR>(pSurface->GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkCreateSharedSwapchainsKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkSwapchainCreateInfoKHR* in_pCreateInfos = pCreateInfos.GetPointer();
    MapStructArrayHandles(pCreateInfos.GetMetaStructPointer(), pCreateInfos.GetLength(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSwapchainKHR* out_pSwapchains = pSwapchains->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSharedSwapchainsKHR(in_device, swapchainCount, in_pCreateInfos, in_pAllocator, out_pSwapchains);
    CheckResult("vkCreateSharedSwapchainsKHR", returnValue, replay_result);

    AddHandles<VkSwapchainKHR>(pSwapchains->GetPointer(), pSwapchains->GetLength(), out_pSwapchains, swapchainCount, &VulkanObjectMapper::AddVkSwapchainKHR);
}

void VulkanReplayConsumer::Process_vkCreateXlibSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkXlibSurfaceCreateInfoKHR* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = OverrideCreateXlibSurfaceKHR(GetInstanceTable(in_instance)->CreateXlibSurfaceKHR, returnValue, in_instance, in_pCreateInfo, in_pAllocator, pSurface);
    CheckResult("vkCreateXlibSurfaceKHR", returnValue, replay_result);

    AddHandles<VkSurfaceKHR>(pSurface->GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dpy,
    size_t                                      visualID)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(dpy, format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR, "vkGetPhysicalDeviceXlibPresentationSupportKHR"));

    OverrideGetPhysicalDeviceXlibPresentationSupportKHR(GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceXlibPresentationSupportKHR, in_physicalDevice, queueFamilyIndex, in_dpy, visualID);
}

void VulkanReplayConsumer::Process_vkCreateXcbSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkXcbSurfaceCreateInfoKHR* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = OverrideCreateXcbSurfaceKHR(GetInstanceTable(in_instance)->CreateXcbSurfaceKHR, returnValue, in_instance, in_pCreateInfo, in_pAllocator, pSurface);
    CheckResult("vkCreateXcbSurfaceKHR", returnValue, replay_result);

    AddHandles<VkSurfaceKHR>(pSurface->GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    connection,
    uint32_t                                    visual_id)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    xcb_connection_t* in_connection = static_cast<xcb_connection_t*>(PreProcessExternalObject(connection, format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR, "vkGetPhysicalDeviceXcbPresentationSupportKHR"));

    OverrideGetPhysicalDeviceXcbPresentationSupportKHR(GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceXcbPresentationSupportKHR, in_physicalDevice, queueFamilyIndex, in_connection, visual_id);
}

void VulkanReplayConsumer::Process_vkCreateWaylandSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkWaylandSurfaceCreateInfoKHR* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = OverrideCreateWaylandSurfaceKHR(GetInstanceTable(in_instance)->CreateWaylandSurfaceKHR, returnValue, in_instance, in_pCreateInfo, in_pAllocator, pSurface);
    CheckResult("vkCreateWaylandSurfaceKHR", returnValue, replay_result);

    AddHandles<VkSurfaceKHR>(pSurface->GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    display)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    struct wl_display* in_display = static_cast<struct wl_display*>(PreProcessExternalObject(display, format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR, "vkGetPhysicalDeviceWaylandPresentationSupportKHR"));

    OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceWaylandPresentationSupportKHR, in_physicalDevice, queueFamilyIndex, in_display);
}

void VulkanReplayConsumer::Process_vkCreateAndroidSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkAndroidSurfaceCreateInfoKHR* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = OverrideCreateAndroidSurfaceKHR(GetInstanceTable(in_instance)->CreateAndroidSurfaceKHR, returnValue, in_instance, in_pCreateInfo, in_pAllocator, pSurface);
    CheckResult("vkCreateAndroidSurfaceKHR", returnValue, replay_result);

    AddHandles<VkSurfaceKHR>(pSurface->GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkCreateWin32SurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkWin32SurfaceCreateInfoKHR* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = OverrideCreateWin32SurfaceKHR(GetInstanceTable(in_instance)->CreateWin32SurfaceKHR, returnValue, in_instance, in_pCreateInfo, in_pAllocator, pSurface);
    CheckResult("vkCreateWin32SurfaceKHR", returnValue, replay_result);

    AddHandles<VkSurfaceKHR>(pSurface->GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);

    OverrideGetPhysicalDeviceWin32PresentationSupportKHR(GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceWin32PresentationSupportKHR, in_physicalDevice, queueFamilyIndex);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkPhysicalDeviceFeatures2* out_pFeatures = pFeatures->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFeatures2KHR(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkPhysicalDeviceProperties2* out_pProperties = pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, nullptr });

    OverrideGetPhysicalDeviceProperties2KHR(GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceProperties2KHR, in_physicalDevice, pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkFormatProperties2* out_pFormatProperties = pFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(in_physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkPhysicalDeviceImageFormatInfo2* in_pImageFormatInfo = pImageFormatInfo.GetPointer();
    VkImageFormatProperties2* out_pImageFormatProperties = pImageFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(in_physicalDevice, in_pImageFormatInfo, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceImageFormatProperties2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    uint32_t* out_pQueueFamilyPropertyCount = pQueueFamilyPropertyCount->AllocateOutputData(1, pQueueFamilyPropertyCount->IsNull() ? static_cast<uint32_t>(0) : (*pQueueFamilyPropertyCount->GetPointer()));
    VkQueueFamilyProperties2* out_pQueueFamilyProperties = pQueueFamilyProperties->IsNull() ? nullptr : pQueueFamilyProperties->AllocateOutputData(*out_pQueueFamilyPropertyCount, VkQueueFamilyProperties2{ VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2KHR(in_physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkPhysicalDeviceMemoryProperties2* out_pMemoryProperties = pMemoryProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceMemoryProperties2KHR(in_physicalDevice, out_pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkPhysicalDeviceSparseImageFormatInfo2* in_pFormatInfo = pFormatInfo.GetPointer();
    uint32_t* out_pPropertyCount = pPropertyCount->AllocateOutputData(1, pPropertyCount->IsNull() ? static_cast<uint32_t>(0) : (*pPropertyCount->GetPointer()));
    VkSparseImageFormatProperties2* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkSparseImageFormatProperties2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(in_physicalDevice, in_pFormatInfo, out_pPropertyCount, out_pProperties);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPeerMemoryFeatureFlags* out_pPeerMemoryFeatures = pPeerMemoryFeatures->AllocateOutputData(1, static_cast<VkPeerMemoryFeatureFlags>(0));

    GetDeviceTable(in_device)->GetDeviceGroupPeerMemoryFeaturesKHR(in_device, heapIndex, localDeviceIndex, remoteDeviceIndex, out_pPeerMemoryFeatures);
}

void VulkanReplayConsumer::Process_vkCmdSetDeviceMaskKHR(
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdSetDeviceMaskKHR(in_commandBuffer, deviceMask);
}

void VulkanReplayConsumer::Process_vkCmdDispatchBaseKHR(
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDispatchBaseKHR(in_commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkTrimCommandPoolKHR(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkCommandPool in_commandPool = MapHandle<CommandPoolInfo>(commandPool, &VulkanObjectMapper::MapVkCommandPool);

    GetDeviceTable(in_device)->TrimCommandPoolKHR(in_device, in_commandPool, flags);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    uint32_t* out_pPhysicalDeviceGroupCount = pPhysicalDeviceGroupCount->AllocateOutputData(1, pPhysicalDeviceGroupCount->IsNull() ? static_cast<uint32_t>(0) : (*pPhysicalDeviceGroupCount->GetPointer()));
    VkPhysicalDeviceGroupProperties* out_pPhysicalDeviceGroupProperties = pPhysicalDeviceGroupProperties->IsNull() ? nullptr : pPhysicalDeviceGroupProperties->AllocateOutputData(*out_pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES, nullptr });

    VkResult replay_result = GetInstanceTable(in_instance)->EnumeratePhysicalDeviceGroupsKHR(in_instance, out_pPhysicalDeviceGroupCount, out_pPhysicalDeviceGroupProperties);
    CheckResult("vkEnumeratePhysicalDeviceGroupsKHR", returnValue, replay_result);

    AddStructArrayHandles<Decoded_VkPhysicalDeviceGroupProperties>(pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength(), out_pPhysicalDeviceGroupProperties, *out_pPhysicalDeviceGroupCount, GetObjectMapper());
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkPhysicalDeviceExternalBufferInfo* in_pExternalBufferInfo = pExternalBufferInfo.GetPointer();
    VkExternalBufferProperties* out_pExternalBufferProperties = pExternalBufferProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(in_physicalDevice, in_pExternalBufferInfo, out_pExternalBufferProperties);
}

void VulkanReplayConsumer::Process_vkGetMemoryWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkMemoryGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = pGetWin32HandleInfo.GetPointer();
    MapStructHandles(pGetWin32HandleInfo.GetMetaStructPointer(), GetObjectMapper());
    HANDLE* out_pHandle = reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
    CheckResult("vkGetMemoryWin32HandleKHR", returnValue, replay_result);

    PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR, "vkGetMemoryWin32HandleKHR");
}

void VulkanReplayConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    handle,
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    HANDLE in_handle = static_cast<HANDLE>(PreProcessExternalObject(handle, format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR, "vkGetMemoryWin32HandlePropertiesKHR"));
    VkMemoryWin32HandlePropertiesKHR* out_pMemoryWin32HandleProperties = pMemoryWin32HandleProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryWin32HandlePropertiesKHR(in_device, handleType, in_handle, out_pMemoryWin32HandleProperties);
    CheckResult("vkGetMemoryWin32HandlePropertiesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetMemoryFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>& pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkMemoryGetFdInfoKHR* in_pGetFdInfo = pGetFdInfo.GetPointer();
    MapStructHandles(pGetFdInfo.GetMetaStructPointer(), GetObjectMapper());
    int* out_pFd = pFd->AllocateOutputData(1, static_cast<int>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryFdKHR(in_device, in_pGetFdInfo, out_pFd);
    CheckResult("vkGetMemoryFdKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetMemoryFdPropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkMemoryFdPropertiesKHR* out_pMemoryFdProperties = pMemoryFdProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryFdPropertiesKHR(in_device, handleType, fd, out_pMemoryFdProperties);
    CheckResult("vkGetMemoryFdPropertiesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkPhysicalDeviceExternalSemaphoreInfo* in_pExternalSemaphoreInfo = pExternalSemaphoreInfo.GetPointer();
    VkExternalSemaphoreProperties* out_pExternalSemaphoreProperties = pExternalSemaphoreProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(in_physicalDevice, in_pExternalSemaphoreInfo, out_pExternalSemaphoreProperties);
}

void VulkanReplayConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>& pImportSemaphoreWin32HandleInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkImportSemaphoreWin32HandleInfoKHR* in_pImportSemaphoreWin32HandleInfo = pImportSemaphoreWin32HandleInfo.GetPointer();
    MapStructHandles(pImportSemaphoreWin32HandleInfo.GetMetaStructPointer(), GetObjectMapper());

    VkResult replay_result = GetDeviceTable(in_device)->ImportSemaphoreWin32HandleKHR(in_device, in_pImportSemaphoreWin32HandleInfo);
    CheckResult("vkImportSemaphoreWin32HandleKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkSemaphoreGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = pGetWin32HandleInfo.GetPointer();
    MapStructHandles(pGetWin32HandleInfo.GetMetaStructPointer(), GetObjectMapper());
    HANDLE* out_pHandle = reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
    CheckResult("vkGetSemaphoreWin32HandleKHR", returnValue, replay_result);

    PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR, "vkGetSemaphoreWin32HandleKHR");
}

void VulkanReplayConsumer::Process_vkImportSemaphoreFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>& pImportSemaphoreFdInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkImportSemaphoreFdInfoKHR* in_pImportSemaphoreFdInfo = pImportSemaphoreFdInfo.GetPointer();
    MapStructHandles(pImportSemaphoreFdInfo.GetMetaStructPointer(), GetObjectMapper());

    VkResult replay_result = GetDeviceTable(in_device)->ImportSemaphoreFdKHR(in_device, in_pImportSemaphoreFdInfo);
    CheckResult("vkImportSemaphoreFdKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>& pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkSemaphoreGetFdInfoKHR* in_pGetFdInfo = pGetFdInfo.GetPointer();
    MapStructHandles(pGetFdInfo.GetMetaStructPointer(), GetObjectMapper());
    int* out_pFd = pFd->AllocateOutputData(1, static_cast<int>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreFdKHR(in_device, in_pGetFdInfo, out_pFd);
    CheckResult("vkGetSemaphoreFdKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdPushDescriptorSetKHR(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkPipelineLayout in_layout = MapHandle<PipelineLayoutInfo>(layout, &VulkanObjectMapper::MapVkPipelineLayout);
    const VkWriteDescriptorSet* in_pDescriptorWrites = pDescriptorWrites.GetPointer();
    MapStructArrayHandles(pDescriptorWrites.GetMetaStructPointer(), pDescriptorWrites.GetLength(), GetObjectMapper());

    GetDeviceTable(in_commandBuffer)->CmdPushDescriptorSetKHR(in_commandBuffer, pipelineBindPoint, in_layout, set, descriptorWriteCount, in_pDescriptorWrites);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkDescriptorUpdateTemplateCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDescriptorUpdateTemplate* out_pDescriptorUpdateTemplate = pDescriptorUpdateTemplate->GetHandlePointer();

    VkResult replay_result = OverrideCreateDescriptorUpdateTemplate(GetDeviceTable(in_device)->CreateDescriptorUpdateTemplateKHR, returnValue, in_device, in_pCreateInfo, in_pAllocator, pDescriptorUpdateTemplate);
    CheckResult("vkCreateDescriptorUpdateTemplateKHR", returnValue, replay_result);

    AddHandles<VkDescriptorUpdateTemplate>(pDescriptorUpdateTemplate->GetPointer(), 1, out_pDescriptorUpdateTemplate, 1, &VulkanObjectMapper::AddVkDescriptorUpdateTemplate);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = MapHandle<DescriptorUpdateTemplateInfo>(descriptorUpdateTemplate, &VulkanObjectMapper::MapVkDescriptorUpdateTemplate);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    OverrideDestroyDescriptorUpdateTemplate(GetDeviceTable(in_device)->DestroyDescriptorUpdateTemplateKHR, in_device, in_descriptorUpdateTemplate, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateRenderPass2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo2KHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkRenderPassCreateInfo2KHR* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkRenderPass* out_pRenderPass = pRenderPass->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateRenderPass2KHR(in_device, in_pCreateInfo, in_pAllocator, out_pRenderPass);
    CheckResult("vkCreateRenderPass2KHR", returnValue, replay_result);

    AddHandles<VkRenderPass>(pRenderPass->GetPointer(), 1, out_pRenderPass, 1, &VulkanObjectMapper::AddVkRenderPass);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass2KHR(
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
    const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkRenderPassBeginInfo* in_pRenderPassBegin = pRenderPassBegin.GetPointer();
    MapStructHandles(pRenderPassBegin.GetMetaStructPointer(), GetObjectMapper());
    const VkSubpassBeginInfoKHR* in_pSubpassBeginInfo = pSubpassBeginInfo.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBeginRenderPass2KHR(in_commandBuffer, in_pRenderPassBegin, in_pSubpassBeginInfo);
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass2KHR(
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo,
    const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkSubpassBeginInfoKHR* in_pSubpassBeginInfo = pSubpassBeginInfo.GetPointer();
    const VkSubpassEndInfoKHR* in_pSubpassEndInfo = pSubpassEndInfo.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdNextSubpass2KHR(in_commandBuffer, in_pSubpassBeginInfo, in_pSubpassEndInfo);
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass2KHR(
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkSubpassEndInfoKHR* in_pSubpassEndInfo = pSubpassEndInfo.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdEndRenderPass2KHR(in_commandBuffer, in_pSubpassEndInfo);
}

void VulkanReplayConsumer::Process_vkGetSwapchainStatusKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectMapper::MapVkSwapchainKHR);

    VkResult replay_result = GetDeviceTable(in_device)->GetSwapchainStatusKHR(in_device, in_swapchain);
    CheckResult("vkGetSwapchainStatusKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkPhysicalDeviceExternalFenceInfo* in_pExternalFenceInfo = pExternalFenceInfo.GetPointer();
    VkExternalFenceProperties* out_pExternalFenceProperties = pExternalFenceProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(in_physicalDevice, in_pExternalFenceInfo, out_pExternalFenceProperties);
}

void VulkanReplayConsumer::Process_vkImportFenceWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>& pImportFenceWin32HandleInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkImportFenceWin32HandleInfoKHR* in_pImportFenceWin32HandleInfo = pImportFenceWin32HandleInfo.GetPointer();
    MapStructHandles(pImportFenceWin32HandleInfo.GetMetaStructPointer(), GetObjectMapper());

    VkResult replay_result = GetDeviceTable(in_device)->ImportFenceWin32HandleKHR(in_device, in_pImportFenceWin32HandleInfo);
    CheckResult("vkImportFenceWin32HandleKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetFenceWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkFenceGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = pGetWin32HandleInfo.GetPointer();
    MapStructHandles(pGetWin32HandleInfo.GetMetaStructPointer(), GetObjectMapper());
    HANDLE* out_pHandle = reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetFenceWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
    CheckResult("vkGetFenceWin32HandleKHR", returnValue, replay_result);

    PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR, "vkGetFenceWin32HandleKHR");
}

void VulkanReplayConsumer::Process_vkImportFenceFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>& pImportFenceFdInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkImportFenceFdInfoKHR* in_pImportFenceFdInfo = pImportFenceFdInfo.GetPointer();
    MapStructHandles(pImportFenceFdInfo.GetMetaStructPointer(), GetObjectMapper());

    VkResult replay_result = GetDeviceTable(in_device)->ImportFenceFdKHR(in_device, in_pImportFenceFdInfo);
    CheckResult("vkImportFenceFdKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetFenceFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>& pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkFenceGetFdInfoKHR* in_pGetFdInfo = pGetFdInfo.GetPointer();
    MapStructHandles(pGetFdInfo.GetMetaStructPointer(), GetObjectMapper());
    int* out_pFd = pFd->AllocateOutputData(1, static_cast<int>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetFenceFdKHR(in_device, in_pGetFdInfo, out_pFd);
    CheckResult("vkGetFenceFdKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = pSurfaceInfo.GetPointer();
    MapStructHandles(pSurfaceInfo.GetMetaStructPointer(), GetObjectMapper());
    VkSurfaceCapabilities2KHR* out_pSurfaceCapabilities = pSurfaceCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2KHR(in_physicalDevice, in_pSurfaceInfo, out_pSurfaceCapabilities);
    CheckResult("vkGetPhysicalDeviceSurfaceCapabilities2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = pSurfaceInfo.GetPointer();
    MapStructHandles(pSurfaceInfo.GetMetaStructPointer(), GetObjectMapper());
    uint32_t* out_pSurfaceFormatCount = pSurfaceFormatCount->AllocateOutputData(1, pSurfaceFormatCount->IsNull() ? static_cast<uint32_t>(0) : (*pSurfaceFormatCount->GetPointer()));
    VkSurfaceFormat2KHR* out_pSurfaceFormats = pSurfaceFormats->IsNull() ? nullptr : pSurfaceFormats->AllocateOutputData(*out_pSurfaceFormatCount, VkSurfaceFormat2KHR{ VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceFormats2KHR(in_physicalDevice, in_pSurfaceInfo, out_pSurfaceFormatCount, out_pSurfaceFormats);
    CheckResult("vkGetPhysicalDeviceSurfaceFormats2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    uint32_t* out_pPropertyCount = pPropertyCount->AllocateOutputData(1, pPropertyCount->IsNull() ? static_cast<uint32_t>(0) : (*pPropertyCount->GetPointer()));
    VkDisplayProperties2KHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkDisplayProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayProperties2KHR", returnValue, replay_result);

    AddStructArrayHandles<Decoded_VkDisplayProperties2KHR>(pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, GetObjectMapper());
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    uint32_t* out_pPropertyCount = pPropertyCount->AllocateOutputData(1, pPropertyCount->IsNull() ? static_cast<uint32_t>(0) : (*pPropertyCount->GetPointer()));
    VkDisplayPlaneProperties2KHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkDisplayPlaneProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", returnValue, replay_result);

    AddStructArrayHandles<Decoded_VkDisplayPlaneProperties2KHR>(pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, GetObjectMapper());
}

void VulkanReplayConsumer::Process_vkGetDisplayModeProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectMapper::MapVkDisplayKHR);
    uint32_t* out_pPropertyCount = pPropertyCount->AllocateOutputData(1, pPropertyCount->IsNull() ? static_cast<uint32_t>(0) : (*pPropertyCount->GetPointer()));
    VkDisplayModeProperties2KHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkDisplayModeProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayModeProperties2KHR(in_physicalDevice, in_display, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetDisplayModeProperties2KHR", returnValue, replay_result);

    AddStructArrayHandles<Decoded_VkDisplayModeProperties2KHR>(pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, GetObjectMapper());
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>& pDisplayPlaneInfo,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkDisplayPlaneInfo2KHR* in_pDisplayPlaneInfo = pDisplayPlaneInfo.GetPointer();
    MapStructHandles(pDisplayPlaneInfo.GetMetaStructPointer(), GetObjectMapper());
    VkDisplayPlaneCapabilities2KHR* out_pCapabilities = pCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayPlaneCapabilities2KHR(in_physicalDevice, in_pDisplayPlaneInfo, out_pCapabilities);
    CheckResult("vkGetDisplayPlaneCapabilities2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements2KHR(
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkImageMemoryRequirementsInfo2* in_pInfo = pInfo.GetPointer();
    MapStructHandles(pInfo.GetMetaStructPointer(), GetObjectMapper());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetImageMemoryRequirements2KHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkBufferMemoryRequirementsInfo2* in_pInfo = pInfo.GetPointer();
    MapStructHandles(pInfo.GetMetaStructPointer(), GetObjectMapper());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetBufferMemoryRequirements2KHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkImageSparseMemoryRequirementsInfo2* in_pInfo = pInfo.GetPointer();
    MapStructHandles(pInfo.GetMetaStructPointer(), GetObjectMapper());
    uint32_t* out_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->AllocateOutputData(1, pSparseMemoryRequirementCount->IsNull() ? static_cast<uint32_t>(0) : (*pSparseMemoryRequirementCount->GetPointer()));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements->IsNull() ? nullptr : pSparseMemoryRequirements->AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetImageSparseMemoryRequirements2KHR(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkSamplerYcbcrConversionCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSamplerYcbcrConversion* out_pYcbcrConversion = pYcbcrConversion->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSamplerYcbcrConversionKHR(in_device, in_pCreateInfo, in_pAllocator, out_pYcbcrConversion);
    CheckResult("vkCreateSamplerYcbcrConversionKHR", returnValue, replay_result);

    AddHandles<VkSamplerYcbcrConversion>(pYcbcrConversion->GetPointer(), 1, out_pYcbcrConversion, 1, &VulkanObjectMapper::AddVkSamplerYcbcrConversion);
}

void VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSamplerYcbcrConversion in_ycbcrConversion = MapHandle<SamplerYcbcrConversionInfo>(ycbcrConversion, &VulkanObjectMapper::MapVkSamplerYcbcrConversion);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroySamplerYcbcrConversionKHR(in_device, in_ycbcrConversion, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkBindBufferMemoryInfo* in_pBindInfos = pBindInfos.GetPointer();
    MapStructArrayHandles(pBindInfos.GetMetaStructPointer(), pBindInfos.GetLength(), GetObjectMapper());

    VkResult replay_result = OverrideBindBufferMemory2(GetDeviceTable(in_device)->BindBufferMemory2KHR, returnValue, in_device, bindInfoCount, in_pBindInfos);
    CheckResult("vkBindBufferMemory2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkBindImageMemory2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkBindImageMemoryInfo* in_pBindInfos = pBindInfos.GetPointer();
    MapStructArrayHandles(pBindInfos.GetMetaStructPointer(), pBindInfos.GetLength(), GetObjectMapper());

    VkResult replay_result = OverrideBindImageMemory2(GetDeviceTable(in_device)->BindImageMemory2KHR, returnValue, in_device, bindInfoCount, in_pBindInfos);
    CheckResult("vkBindImageMemory2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    VkDescriptorSetLayoutSupport* out_pSupport = pSupport->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT, nullptr });

    GetDeviceTable(in_device)->GetDescriptorSetLayoutSupportKHR(in_device, in_pCreateInfo, out_pSupport);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectCountKHR(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectMapper::MapVkBuffer);
    VkBuffer in_countBuffer = MapHandle<BufferInfo>(countBuffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCountKHR(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectMapper::MapVkBuffer);
    VkBuffer in_countBuffer = MapHandle<BufferInfo>(countBuffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCountKHR(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreCounterValueKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSemaphore in_semaphore = MapHandle<SemaphoreInfo>(semaphore, &VulkanObjectMapper::MapVkSemaphore);
    uint64_t* out_pValue = pValue->AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreCounterValueKHR(in_device, in_semaphore, out_pValue);
    CheckResult("vkGetSemaphoreCounterValueKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkWaitSemaphoresKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkSemaphoreWaitInfoKHR>& pWaitInfo,
    uint64_t                                    timeout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkSemaphoreWaitInfoKHR* in_pWaitInfo = pWaitInfo.GetPointer();
    MapStructHandles(pWaitInfo.GetMetaStructPointer(), GetObjectMapper());

    VkResult replay_result = GetDeviceTable(in_device)->WaitSemaphoresKHR(in_device, in_pWaitInfo, timeout);
    CheckResult("vkWaitSemaphoresKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkSignalSemaphoreKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkSemaphoreSignalInfoKHR>& pSignalInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkSemaphoreSignalInfoKHR* in_pSignalInfo = pSignalInfo.GetPointer();
    MapStructHandles(pSignalInfo.GetMetaStructPointer(), GetObjectMapper());

    VkResult replay_result = GetDeviceTable(in_device)->SignalSemaphoreKHR(in_device, in_pSignalInfo);
    CheckResult("vkSignalSemaphoreKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkPipelineInfoKHR>& pPipelineInfo,
    PointerDecoder<uint32_t>*                   pExecutableCount,
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkPipelineInfoKHR* in_pPipelineInfo = pPipelineInfo.GetPointer();
    MapStructHandles(pPipelineInfo.GetMetaStructPointer(), GetObjectMapper());
    uint32_t* out_pExecutableCount = pExecutableCount->AllocateOutputData(1, pExecutableCount->IsNull() ? static_cast<uint32_t>(0) : (*pExecutableCount->GetPointer()));
    VkPipelineExecutablePropertiesKHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pExecutableCount, VkPipelineExecutablePropertiesKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineExecutablePropertiesKHR(in_device, in_pPipelineInfo, out_pExecutableCount, out_pProperties);
    CheckResult("vkGetPipelineExecutablePropertiesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>& pExecutableInfo,
    PointerDecoder<uint32_t>*                   pStatisticCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkPipelineExecutableInfoKHR* in_pExecutableInfo = pExecutableInfo.GetPointer();
    MapStructHandles(pExecutableInfo.GetMetaStructPointer(), GetObjectMapper());
    uint32_t* out_pStatisticCount = pStatisticCount->AllocateOutputData(1, pStatisticCount->IsNull() ? static_cast<uint32_t>(0) : (*pStatisticCount->GetPointer()));
    VkPipelineExecutableStatisticKHR* out_pStatistics = pStatistics->IsNull() ? nullptr : pStatistics->AllocateOutputData(*out_pStatisticCount, VkPipelineExecutableStatisticKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineExecutableStatisticsKHR(in_device, in_pExecutableInfo, out_pStatisticCount, out_pStatistics);
    CheckResult("vkGetPipelineExecutableStatisticsKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>& pExecutableInfo,
    PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkPipelineExecutableInfoKHR* in_pExecutableInfo = pExecutableInfo.GetPointer();
    MapStructHandles(pExecutableInfo.GetMetaStructPointer(), GetObjectMapper());
    uint32_t* out_pInternalRepresentationCount = pInternalRepresentationCount->AllocateOutputData(1, pInternalRepresentationCount->IsNull() ? static_cast<uint32_t>(0) : (*pInternalRepresentationCount->GetPointer()));
    VkPipelineExecutableInternalRepresentationKHR* out_pInternalRepresentations = pInternalRepresentations->IsNull() ? nullptr : pInternalRepresentations->AllocateOutputData(*out_pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineExecutableInternalRepresentationsKHR(in_device, in_pExecutableInfo, out_pInternalRepresentationCount, out_pInternalRepresentations);
    CheckResult("vkGetPipelineExecutableInternalRepresentationsKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateDebugReportCallbackEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkDebugReportCallbackCreateInfoEXT* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDebugReportCallbackEXT* out_pCallback = pCallback->GetHandlePointer();

    VkResult replay_result = OverrideCreateDebugReportCallbackEXT(GetInstanceTable(in_instance)->CreateDebugReportCallbackEXT, returnValue, in_instance, in_pCreateInfo, in_pAllocator, pCallback);
    CheckResult("vkCreateDebugReportCallbackEXT", returnValue, replay_result);

    AddHandles<VkDebugReportCallbackEXT>(pCallback->GetPointer(), 1, out_pCallback, 1, &VulkanObjectMapper::AddVkDebugReportCallbackEXT);
}

void VulkanReplayConsumer::Process_vkDestroyDebugReportCallbackEXT(
    format::HandleId                            instance,
    format::HandleId                            callback,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    VkDebugReportCallbackEXT in_callback = MapHandle<DebugReportCallbackEXTInfo>(callback, &VulkanObjectMapper::MapVkDebugReportCallbackEXT);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetInstanceTable(in_instance)->DestroyDebugReportCallbackEXT(in_instance, in_callback, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkDebugReportMessageEXT(
    format::HandleId                            instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    const StringDecoder&                        pLayerPrefix,
    const StringDecoder&                        pMessage)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const char* in_pLayerPrefix = pLayerPrefix.GetPointer();
    const char* in_pMessage = pMessage.GetPointer();

    GetInstanceTable(in_instance)->DebugReportMessageEXT(in_instance, flags, objectType, object, location, messageCode, in_pLayerPrefix, in_pMessage);
}

void VulkanReplayConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>& pTagInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkDebugMarkerObjectTagInfoEXT* in_pTagInfo = pTagInfo.GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->DebugMarkerSetObjectTagEXT(in_device, in_pTagInfo);
    CheckResult("vkDebugMarkerSetObjectTagEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>& pNameInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkDebugMarkerObjectNameInfoEXT* in_pNameInfo = pNameInfo.GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->DebugMarkerSetObjectNameEXT(in_device, in_pNameInfo);
    CheckResult("vkDebugMarkerSetObjectNameEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerBeginEXT(
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkDebugMarkerMarkerInfoEXT* in_pMarkerInfo = pMarkerInfo.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdDebugMarkerBeginEXT(in_commandBuffer, in_pMarkerInfo);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerEndEXT(
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDebugMarkerEndEXT(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerInsertEXT(
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkDebugMarkerMarkerInfoEXT* in_pMarkerInfo = pMarkerInfo.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdDebugMarkerInsertEXT(in_commandBuffer, in_pMarkerInfo);
}

void VulkanReplayConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const HandlePointerDecoder<VkBuffer>&       pBuffers,
    const PointerDecoder<VkDeviceSize>&         pOffsets,
    const PointerDecoder<VkDeviceSize>&         pSizes)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer* in_pBuffers = pBuffers.GetHandlePointer();
    MapHandles<BufferInfo>(pBuffers.GetPointer(), pBuffers.GetLength(), in_pBuffers, bindingCount, &VulkanObjectMapper::MapVkBuffer);
    const VkDeviceSize* in_pOffsets = pOffsets.GetPointer();
    const VkDeviceSize* in_pSizes = pSizes.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindTransformFeedbackBuffersEXT(in_commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets, in_pSizes);
}

void VulkanReplayConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const HandlePointerDecoder<VkBuffer>&       pCounterBuffers,
    const PointerDecoder<VkDeviceSize>&         pCounterBufferOffsets)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer* in_pCounterBuffers = pCounterBuffers.GetHandlePointer();
    MapHandles<BufferInfo>(pCounterBuffers.GetPointer(), pCounterBuffers.GetLength(), in_pCounterBuffers, counterBufferCount, &VulkanObjectMapper::MapVkBuffer);
    const VkDeviceSize* in_pCounterBufferOffsets = pCounterBufferOffsets.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBeginTransformFeedbackEXT(in_commandBuffer, firstCounterBuffer, counterBufferCount, in_pCounterBuffers, in_pCounterBufferOffsets);
}

void VulkanReplayConsumer::Process_vkCmdEndTransformFeedbackEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const HandlePointerDecoder<VkBuffer>&       pCounterBuffers,
    const PointerDecoder<VkDeviceSize>&         pCounterBufferOffsets)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer* in_pCounterBuffers = pCounterBuffers.GetHandlePointer();
    MapHandles<BufferInfo>(pCounterBuffers.GetPointer(), pCounterBuffers.GetLength(), in_pCounterBuffers, counterBufferCount, &VulkanObjectMapper::MapVkBuffer);
    const VkDeviceSize* in_pCounterBufferOffsets = pCounterBufferOffsets.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdEndTransformFeedbackEXT(in_commandBuffer, firstCounterBuffer, counterBufferCount, in_pCounterBuffers, in_pCounterBufferOffsets);
}

void VulkanReplayConsumer::Process_vkCmdBeginQueryIndexedEXT(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectMapper::MapVkQueryPool);

    GetDeviceTable(in_commandBuffer)->CmdBeginQueryIndexedEXT(in_commandBuffer, in_queryPool, query, flags, index);
}

void VulkanReplayConsumer::Process_vkCmdEndQueryIndexedEXT(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectMapper::MapVkQueryPool);

    GetDeviceTable(in_commandBuffer)->CmdEndQueryIndexedEXT(in_commandBuffer, in_queryPool, query, index);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    format::HandleId                            counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_counterBuffer = MapHandle<BufferInfo>(counterBuffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectByteCountEXT(in_commandBuffer, instanceCount, firstInstance, in_counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

void VulkanReplayConsumer::Process_vkGetImageViewHandleNVX(
    uint32_t                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>& pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkImageViewHandleInfoNVX* in_pInfo = pInfo.GetPointer();
    MapStructHandles(pInfo.GetMetaStructPointer(), GetObjectMapper());

    GetDeviceTable(in_device)->GetImageViewHandleNVX(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectCountAMD(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectMapper::MapVkBuffer);
    VkBuffer in_countBuffer = MapHandle<BufferInfo>(countBuffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCountAMD(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectMapper::MapVkBuffer);
    VkBuffer in_countBuffer = MapHandle<BufferInfo>(countBuffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCountAMD(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkGetShaderInfoAMD(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    PointerDecoder<size_t>*                     pInfoSize,
    PointerDecoder<uint8_t>*                    pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPipeline in_pipeline = MapHandle<PipelineInfo>(pipeline, &VulkanObjectMapper::MapVkPipeline);
    size_t* out_pInfoSize = pInfoSize->AllocateOutputData(1, pInfoSize->IsNull() ? static_cast<size_t>(0) : (*pInfoSize->GetPointer()));
    void* out_pInfo = pInfo->IsNull() ? nullptr : pInfo->AllocateOutputData(*out_pInfoSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetShaderInfoAMD(in_device, in_pipeline, shaderStage, infoType, out_pInfoSize, out_pInfo);
    CheckResult("vkGetShaderInfoAMD", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkStreamDescriptorSurfaceCreateInfoGGP* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateStreamDescriptorSurfaceGGP(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateStreamDescriptorSurfaceGGP", returnValue, replay_result);

    AddHandles<VkSurfaceKHR>(pSurface->GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
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
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkExternalImageFormatPropertiesNV* out_pExternalImageFormatProperties = pExternalImageFormatProperties->AllocateOutputData(1);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(in_physicalDevice, format, type, tiling, usage, flags, externalHandleType, out_pExternalImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceExternalImageFormatPropertiesNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetMemoryWin32HandleNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDeviceMemory in_memory = MapHandle<DeviceMemoryInfo>(memory, &VulkanObjectMapper::MapVkDeviceMemory);
    HANDLE* out_pHandle = reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryWin32HandleNV(in_device, in_memory, handleType, out_pHandle);
    CheckResult("vkGetMemoryWin32HandleNV", returnValue, replay_result);

    PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV, "vkGetMemoryWin32HandleNV");
}

void VulkanReplayConsumer::Process_vkCreateViSurfaceNN(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkViSurfaceCreateInfoNN* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateViSurfaceNN(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateViSurfaceNN", returnValue, replay_result);

    AddHandles<VkSurfaceKHR>(pSurface->GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>& pConditionalRenderingBegin)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkConditionalRenderingBeginInfoEXT* in_pConditionalRenderingBegin = pConditionalRenderingBegin.GetPointer();
    MapStructHandles(pConditionalRenderingBegin.GetMetaStructPointer(), GetObjectMapper());

    GetDeviceTable(in_commandBuffer)->CmdBeginConditionalRenderingEXT(in_commandBuffer, in_pConditionalRenderingBegin);
}

void VulkanReplayConsumer::Process_vkCmdEndConditionalRenderingEXT(
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdEndConditionalRenderingEXT(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdProcessCommandsNVX(
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkCmdProcessCommandsInfoNVX>& pProcessCommandsInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkCmdProcessCommandsInfoNVX* in_pProcessCommandsInfo = pProcessCommandsInfo.GetPointer();
    MapStructHandles(pProcessCommandsInfo.GetMetaStructPointer(), GetObjectMapper());

    GetDeviceTable(in_commandBuffer)->CmdProcessCommandsNVX(in_commandBuffer, in_pProcessCommandsInfo);
}

void VulkanReplayConsumer::Process_vkCmdReserveSpaceForCommandsNVX(
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkCmdReserveSpaceForCommandsInfoNVX>& pReserveSpaceInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkCmdReserveSpaceForCommandsInfoNVX* in_pReserveSpaceInfo = pReserveSpaceInfo.GetPointer();
    MapStructHandles(pReserveSpaceInfo.GetMetaStructPointer(), GetObjectMapper());

    GetDeviceTable(in_commandBuffer)->CmdReserveSpaceForCommandsNVX(in_commandBuffer, in_pReserveSpaceInfo);
}

void VulkanReplayConsumer::Process_vkCreateIndirectCommandsLayoutNVX(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNVX>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutNVX>* pIndirectCommandsLayout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkIndirectCommandsLayoutCreateInfoNVX* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkIndirectCommandsLayoutNVX* out_pIndirectCommandsLayout = pIndirectCommandsLayout->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateIndirectCommandsLayoutNVX(in_device, in_pCreateInfo, in_pAllocator, out_pIndirectCommandsLayout);
    CheckResult("vkCreateIndirectCommandsLayoutNVX", returnValue, replay_result);

    AddHandles<VkIndirectCommandsLayoutNVX>(pIndirectCommandsLayout->GetPointer(), 1, out_pIndirectCommandsLayout, 1, &VulkanObjectMapper::AddVkIndirectCommandsLayoutNVX);
}

void VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutNVX(
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkIndirectCommandsLayoutNVX in_indirectCommandsLayout = MapHandle<IndirectCommandsLayoutNVXInfo>(indirectCommandsLayout, &VulkanObjectMapper::MapVkIndirectCommandsLayoutNVX);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyIndirectCommandsLayoutNVX(in_device, in_indirectCommandsLayout, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkCreateObjectTableNVX(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkObjectTableCreateInfoNVX>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkObjectTableNVX>*     pObjectTable)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkObjectTableCreateInfoNVX* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkObjectTableNVX* out_pObjectTable = pObjectTable->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateObjectTableNVX(in_device, in_pCreateInfo, in_pAllocator, out_pObjectTable);
    CheckResult("vkCreateObjectTableNVX", returnValue, replay_result);

    AddHandles<VkObjectTableNVX>(pObjectTable->GetPointer(), 1, out_pObjectTable, 1, &VulkanObjectMapper::AddVkObjectTableNVX);
}

void VulkanReplayConsumer::Process_vkDestroyObjectTableNVX(
    format::HandleId                            device,
    format::HandleId                            objectTable,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkObjectTableNVX in_objectTable = MapHandle<ObjectTableNVXInfo>(objectTable, &VulkanObjectMapper::MapVkObjectTableNVX);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyObjectTableNVX(in_device, in_objectTable, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkUnregisterObjectsNVX(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            objectTable,
    uint32_t                                    objectCount,
    const PointerDecoder<VkObjectEntryTypeNVX>& pObjectEntryTypes,
    const PointerDecoder<uint32_t>&             pObjectIndices)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkObjectTableNVX in_objectTable = MapHandle<ObjectTableNVXInfo>(objectTable, &VulkanObjectMapper::MapVkObjectTableNVX);
    const VkObjectEntryTypeNVX* in_pObjectEntryTypes = pObjectEntryTypes.GetPointer();
    const uint32_t* in_pObjectIndices = pObjectIndices.GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->UnregisterObjectsNVX(in_device, in_objectTable, objectCount, in_pObjectEntryTypes, in_pObjectIndices);
    CheckResult("vkUnregisterObjectsNVX", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsFeaturesNVX>* pFeatures,
    StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsLimitsNVX>* pLimits)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkDeviceGeneratedCommandsFeaturesNVX* out_pFeatures = pFeatures->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_FEATURES_NVX, nullptr });
    VkDeviceGeneratedCommandsLimitsNVX* out_pLimits = pLimits->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_LIMITS_NVX, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceGeneratedCommandsPropertiesNVX(in_physicalDevice, out_pFeatures, out_pLimits);
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWScalingNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const StructPointerDecoder<Decoded_VkViewportWScalingNV>& pViewportWScalings)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkViewportWScalingNV* in_pViewportWScalings = pViewportWScalings.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportWScalingNV(in_commandBuffer, firstViewport, viewportCount, in_pViewportWScalings);
}

void VulkanReplayConsumer::Process_vkReleaseDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectMapper::MapVkDisplayKHR);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->ReleaseDisplayEXT(in_physicalDevice, in_display);
    CheckResult("vkReleaseDisplayEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkAcquireXlibDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    format::HandleId                            display)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(dpy, format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT, "vkAcquireXlibDisplayEXT"));
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectMapper::MapVkDisplayKHR);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->AcquireXlibDisplayEXT(in_physicalDevice, in_dpy, in_display);
    CheckResult("vkAcquireXlibDisplayEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetRandROutputDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    size_t                                      rrOutput,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(dpy, format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT, "vkGetRandROutputDisplayEXT"));
    VkDisplayKHR* out_pDisplay = pDisplay->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetRandROutputDisplayEXT(in_physicalDevice, in_dpy, rrOutput, out_pDisplay);
    CheckResult("vkGetRandROutputDisplayEXT", returnValue, replay_result);

    AddHandles<VkDisplayKHR>(pDisplay->GetPointer(), 1, out_pDisplay, 1, &VulkanObjectMapper::AddVkDisplayKHR);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectMapper::MapVkSurfaceKHR);
    VkSurfaceCapabilities2EXT* out_pSurfaceCapabilities = pSurfaceCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(in_physicalDevice, in_surface, out_pSurfaceCapabilities);
    CheckResult("vkGetPhysicalDeviceSurfaceCapabilities2EXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkDisplayPowerControlEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    const StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>& pDisplayPowerInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectMapper::MapVkDisplayKHR);
    const VkDisplayPowerInfoEXT* in_pDisplayPowerInfo = pDisplayPowerInfo.GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->DisplayPowerControlEXT(in_device, in_display, in_pDisplayPowerInfo);
    CheckResult("vkDisplayPowerControlEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkRegisterDeviceEventEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>& pDeviceEventInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkDeviceEventInfoEXT* in_pDeviceEventInfo = pDeviceEventInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkFence* out_pFence = pFence->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->RegisterDeviceEventEXT(in_device, in_pDeviceEventInfo, in_pAllocator, out_pFence);
    CheckResult("vkRegisterDeviceEventEXT", returnValue, replay_result);

    AddHandles<VkFence>(pFence->GetPointer(), 1, out_pFence, 1, &VulkanObjectMapper::AddVkFence);
}

void VulkanReplayConsumer::Process_vkRegisterDisplayEventEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    const StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>& pDisplayEventInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectMapper::MapVkDisplayKHR);
    const VkDisplayEventInfoEXT* in_pDisplayEventInfo = pDisplayEventInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkFence* out_pFence = pFence->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->RegisterDisplayEventEXT(in_device, in_display, in_pDisplayEventInfo, in_pAllocator, out_pFence);
    CheckResult("vkRegisterDisplayEventEXT", returnValue, replay_result);

    AddHandles<VkFence>(pFence->GetPointer(), 1, out_pFence, 1, &VulkanObjectMapper::AddVkFence);
}

void VulkanReplayConsumer::Process_vkGetSwapchainCounterEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    PointerDecoder<uint64_t>*                   pCounterValue)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectMapper::MapVkSwapchainKHR);
    uint64_t* out_pCounterValue = pCounterValue->AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSwapchainCounterEXT(in_device, in_swapchain, counter, out_pCounterValue);
    CheckResult("vkGetSwapchainCounterEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectMapper::MapVkSwapchainKHR);
    VkRefreshCycleDurationGOOGLE* out_pDisplayTimingProperties = pDisplayTimingProperties->AllocateOutputData(1);

    VkResult replay_result = GetDeviceTable(in_device)->GetRefreshCycleDurationGOOGLE(in_device, in_swapchain, out_pDisplayTimingProperties);
    CheckResult("vkGetRefreshCycleDurationGOOGLE", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pPresentationTimingCount,
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectMapper::MapVkSwapchainKHR);
    uint32_t* out_pPresentationTimingCount = pPresentationTimingCount->AllocateOutputData(1, pPresentationTimingCount->IsNull() ? static_cast<uint32_t>(0) : (*pPresentationTimingCount->GetPointer()));
    VkPastPresentationTimingGOOGLE* out_pPresentationTimings = pPresentationTimings->IsNull() ? nullptr : pPresentationTimings->AllocateOutputData(*out_pPresentationTimingCount);

    VkResult replay_result = GetDeviceTable(in_device)->GetPastPresentationTimingGOOGLE(in_device, in_swapchain, out_pPresentationTimingCount, out_pPresentationTimings);
    CheckResult("vkGetPastPresentationTimingGOOGLE", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const StructPointerDecoder<Decoded_VkRect2D>& pDiscardRectangles)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkRect2D* in_pDiscardRectangles = pDiscardRectangles.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetDiscardRectangleEXT(in_commandBuffer, firstDiscardRectangle, discardRectangleCount, in_pDiscardRectangles);
}

void VulkanReplayConsumer::Process_vkSetHdrMetadataEXT(
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    const HandlePointerDecoder<VkSwapchainKHR>& pSwapchains,
    const StructPointerDecoder<Decoded_VkHdrMetadataEXT>& pMetadata)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSwapchainKHR* in_pSwapchains = pSwapchains.GetHandlePointer();
    MapHandles<SwapchainKHRInfo>(pSwapchains.GetPointer(), pSwapchains.GetLength(), in_pSwapchains, swapchainCount, &VulkanObjectMapper::MapVkSwapchainKHR);
    const VkHdrMetadataEXT* in_pMetadata = pMetadata.GetPointer();

    GetDeviceTable(in_device)->SetHdrMetadataEXT(in_device, swapchainCount, in_pSwapchains, in_pMetadata);
}

void VulkanReplayConsumer::Process_vkCreateIOSSurfaceMVK(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkIOSSurfaceCreateInfoMVK* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateIOSSurfaceMVK(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateIOSSurfaceMVK", returnValue, replay_result);

    AddHandles<VkSurfaceKHR>(pSurface->GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkCreateMacOSSurfaceMVK(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkMacOSSurfaceCreateInfoMVK* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateMacOSSurfaceMVK(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateMacOSSurfaceMVK", returnValue, replay_result);

    AddHandles<VkSurfaceKHR>(pSurface->GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>& pNameInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkDebugUtilsObjectNameInfoEXT* in_pNameInfo = pNameInfo.GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->SetDebugUtilsObjectNameEXT(in_device, in_pNameInfo);
    CheckResult("vkSetDebugUtilsObjectNameEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>& pTagInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkDebugUtilsObjectTagInfoEXT* in_pTagInfo = pTagInfo.GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->SetDebugUtilsObjectTagEXT(in_device, in_pTagInfo);
    CheckResult("vkSetDebugUtilsObjectTagEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    format::HandleId                            queue,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectMapper::MapVkQueue);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = pLabelInfo.GetPointer();

    GetDeviceTable(in_queue)->QueueBeginDebugUtilsLabelEXT(in_queue, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    format::HandleId                            queue)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectMapper::MapVkQueue);

    GetDeviceTable(in_queue)->QueueEndDebugUtilsLabelEXT(in_queue);
}

void VulkanReplayConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    format::HandleId                            queue,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectMapper::MapVkQueue);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = pLabelInfo.GetPointer();

    GetDeviceTable(in_queue)->QueueInsertDebugUtilsLabelEXT(in_queue, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = pLabelInfo.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBeginDebugUtilsLabelEXT(in_commandBuffer, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdEndDebugUtilsLabelEXT(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = pLabelInfo.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdInsertDebugUtilsLabelEXT(in_commandBuffer, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkDebugUtilsMessengerCreateInfoEXT* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkDebugUtilsMessengerEXT* out_pMessenger = pMessenger->GetHandlePointer();

    VkResult replay_result = OverrideCreateDebugUtilsMessengerEXT(GetInstanceTable(in_instance)->CreateDebugUtilsMessengerEXT, returnValue, in_instance, in_pCreateInfo, in_pAllocator, pMessenger);
    CheckResult("vkCreateDebugUtilsMessengerEXT", returnValue, replay_result);

    AddHandles<VkDebugUtilsMessengerEXT>(pMessenger->GetPointer(), 1, out_pMessenger, 1, &VulkanObjectMapper::AddVkDebugUtilsMessengerEXT);
}

void VulkanReplayConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    format::HandleId                            instance,
    format::HandleId                            messenger,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    VkDebugUtilsMessengerEXT in_messenger = MapHandle<DebugUtilsMessengerEXTInfo>(messenger, &VulkanObjectMapper::MapVkDebugUtilsMessengerEXT);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetInstanceTable(in_instance)->DestroyDebugUtilsMessengerEXT(in_instance, in_messenger, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    format::HandleId                            instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>& pCallbackData)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkDebugUtilsMessengerCallbackDataEXT* in_pCallbackData = pCallbackData.GetPointer();

    GetInstanceTable(in_instance)->SubmitDebugUtilsMessageEXT(in_instance, messageSeverity, messageTypes, in_pCallbackData);
}

void VulkanReplayConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const struct AHardwareBuffer* in_buffer = static_cast<const struct AHardwareBuffer*>(PreProcessExternalObject(buffer, format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID, "vkGetAndroidHardwareBufferPropertiesANDROID"));
    VkAndroidHardwareBufferPropertiesANDROID* out_pProperties = pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetAndroidHardwareBufferPropertiesANDROID(in_device, in_buffer, out_pProperties);
    CheckResult("vkGetAndroidHardwareBufferPropertiesANDROID", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>& pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* in_pInfo = pInfo.GetPointer();
    MapStructHandles(pInfo.GetMetaStructPointer(), GetObjectMapper());
    struct AHardwareBuffer** out_pBuffer = reinterpret_cast<struct AHardwareBuffer**>(pBuffer->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryAndroidHardwareBufferANDROID(in_device, in_pInfo, out_pBuffer);
    CheckResult("vkGetMemoryAndroidHardwareBufferANDROID", returnValue, replay_result);

    PostProcessExternalObject(replay_result, (*pBuffer->GetPointer()), static_cast<void*>(*out_pBuffer), format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID, "vkGetMemoryAndroidHardwareBufferANDROID");
}

void VulkanReplayConsumer::Process_vkCmdSetSampleLocationsEXT(
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>& pSampleLocationsInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkSampleLocationsInfoEXT* in_pSampleLocationsInfo = pSampleLocationsInfo.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetSampleLocationsEXT(in_commandBuffer, in_pSampleLocationsInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    VkMultisamplePropertiesEXT* out_pMultisampleProperties = pMultisampleProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(in_physicalDevice, samples, out_pMultisampleProperties);
}

void VulkanReplayConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectMapper::MapVkImage);
    VkImageDrmFormatModifierPropertiesEXT* out_pProperties = pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetImageDrmFormatModifierPropertiesEXT(in_device, in_image, out_pProperties);
    CheckResult("vkGetImageDrmFormatModifierPropertiesEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateValidationCacheEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkValidationCacheCreateInfoEXT* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkValidationCacheEXT* out_pValidationCache = pValidationCache->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateValidationCacheEXT(in_device, in_pCreateInfo, in_pAllocator, out_pValidationCache);
    CheckResult("vkCreateValidationCacheEXT", returnValue, replay_result);

    AddHandles<VkValidationCacheEXT>(pValidationCache->GetPointer(), 1, out_pValidationCache, 1, &VulkanObjectMapper::AddVkValidationCacheEXT);
}

void VulkanReplayConsumer::Process_vkDestroyValidationCacheEXT(
    format::HandleId                            device,
    format::HandleId                            validationCache,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkValidationCacheEXT in_validationCache = MapHandle<ValidationCacheEXTInfo>(validationCache, &VulkanObjectMapper::MapVkValidationCacheEXT);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyValidationCacheEXT(in_device, in_validationCache, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkMergeValidationCachesEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    const HandlePointerDecoder<VkValidationCacheEXT>& pSrcCaches)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkValidationCacheEXT in_dstCache = MapHandle<ValidationCacheEXTInfo>(dstCache, &VulkanObjectMapper::MapVkValidationCacheEXT);
    VkValidationCacheEXT* in_pSrcCaches = pSrcCaches.GetHandlePointer();
    MapHandles<ValidationCacheEXTInfo>(pSrcCaches.GetPointer(), pSrcCaches.GetLength(), in_pSrcCaches, srcCacheCount, &VulkanObjectMapper::MapVkValidationCacheEXT);

    VkResult replay_result = GetDeviceTable(in_device)->MergeValidationCachesEXT(in_device, in_dstCache, srcCacheCount, in_pSrcCaches);
    CheckResult("vkMergeValidationCachesEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetValidationCacheDataEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkValidationCacheEXT in_validationCache = MapHandle<ValidationCacheEXTInfo>(validationCache, &VulkanObjectMapper::MapVkValidationCacheEXT);
    size_t* out_pDataSize = pDataSize->AllocateOutputData(1, pDataSize->IsNull() ? static_cast<size_t>(0) : (*pDataSize->GetPointer()));
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(*out_pDataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetValidationCacheDataEXT(in_device, in_validationCache, out_pDataSize, out_pData);
    CheckResult("vkGetValidationCacheDataEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdBindShadingRateImageNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkImageView in_imageView = MapHandle<ImageViewInfo>(imageView, &VulkanObjectMapper::MapVkImageView);

    GetDeviceTable(in_commandBuffer)->CmdBindShadingRateImageNV(in_commandBuffer, in_imageView, imageLayout);
}

void VulkanReplayConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const StructPointerDecoder<Decoded_VkShadingRatePaletteNV>& pShadingRatePalettes)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkShadingRatePaletteNV* in_pShadingRatePalettes = pShadingRatePalettes.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportShadingRatePaletteNV(in_commandBuffer, firstViewport, viewportCount, in_pShadingRatePalettes);
}

void VulkanReplayConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>& pCustomSampleOrders)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkCoarseSampleOrderCustomNV* in_pCustomSampleOrders = pCustomSampleOrders.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetCoarseSampleOrderNV(in_commandBuffer, sampleOrderType, customSampleOrderCount, in_pCustomSampleOrders);
}

void VulkanReplayConsumer::Process_vkCreateAccelerationStructureNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkAccelerationStructureCreateInfoNV* in_pCreateInfo = pCreateInfo.GetPointer();
    MapStructHandles(pCreateInfo.GetMetaStructPointer(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkAccelerationStructureNV* out_pAccelerationStructure = pAccelerationStructure->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateAccelerationStructureNV(in_device, in_pCreateInfo, in_pAllocator, out_pAccelerationStructure);
    CheckResult("vkCreateAccelerationStructureNV", returnValue, replay_result);

    AddHandles<VkAccelerationStructureNV>(pAccelerationStructure->GetPointer(), 1, out_pAccelerationStructure, 1, &VulkanObjectMapper::AddVkAccelerationStructureNV);
}

void VulkanReplayConsumer::Process_vkDestroyAccelerationStructureNV(
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkAccelerationStructureNV in_accelerationStructure = MapHandle<AccelerationStructureNVInfo>(accelerationStructure, &VulkanObjectMapper::MapVkAccelerationStructureNV);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyAccelerationStructureNV(in_device, in_accelerationStructure, in_pAllocator);
}

void VulkanReplayConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>& pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkAccelerationStructureMemoryRequirementsInfoNV* in_pInfo = pInfo.GetPointer();
    MapStructHandles(pInfo.GetMetaStructPointer(), GetObjectMapper());
    VkMemoryRequirements2KHR* out_pMemoryRequirements = pMemoryRequirements->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetAccelerationStructureMemoryRequirementsNV(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkBindAccelerationStructureMemoryNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>& pBindInfos)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkBindAccelerationStructureMemoryInfoNV* in_pBindInfos = pBindInfos.GetPointer();
    MapStructArrayHandles(pBindInfos.GetMetaStructPointer(), pBindInfos.GetLength(), GetObjectMapper());

    VkResult replay_result = GetDeviceTable(in_device)->BindAccelerationStructureMemoryNV(in_device, bindInfoCount, in_pBindInfos);
    CheckResult("vkBindAccelerationStructureMemoryNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructureNV(
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV>& pInfo,
    format::HandleId                            instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    format::HandleId                            dst,
    format::HandleId                            src,
    format::HandleId                            scratch,
    VkDeviceSize                                scratchOffset)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkAccelerationStructureInfoNV* in_pInfo = pInfo.GetPointer();
    MapStructHandles(pInfo.GetMetaStructPointer(), GetObjectMapper());
    VkBuffer in_instanceData = MapHandle<BufferInfo>(instanceData, &VulkanObjectMapper::MapVkBuffer);
    VkAccelerationStructureNV in_dst = MapHandle<AccelerationStructureNVInfo>(dst, &VulkanObjectMapper::MapVkAccelerationStructureNV);
    VkAccelerationStructureNV in_src = MapHandle<AccelerationStructureNVInfo>(src, &VulkanObjectMapper::MapVkAccelerationStructureNV);
    VkBuffer in_scratch = MapHandle<BufferInfo>(scratch, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdBuildAccelerationStructureNV(in_commandBuffer, in_pInfo, in_instanceData, instanceOffset, update, in_dst, in_src, in_scratch, scratchOffset);
}

void VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeNV           mode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkAccelerationStructureNV in_dst = MapHandle<AccelerationStructureNVInfo>(dst, &VulkanObjectMapper::MapVkAccelerationStructureNV);
    VkAccelerationStructureNV in_src = MapHandle<AccelerationStructureNVInfo>(src, &VulkanObjectMapper::MapVkAccelerationStructureNV);

    GetDeviceTable(in_commandBuffer)->CmdCopyAccelerationStructureNV(in_commandBuffer, in_dst, in_src, mode);
}

void VulkanReplayConsumer::Process_vkCmdTraceRaysNV(
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
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_raygenShaderBindingTableBuffer = MapHandle<BufferInfo>(raygenShaderBindingTableBuffer, &VulkanObjectMapper::MapVkBuffer);
    VkBuffer in_missShaderBindingTableBuffer = MapHandle<BufferInfo>(missShaderBindingTableBuffer, &VulkanObjectMapper::MapVkBuffer);
    VkBuffer in_hitShaderBindingTableBuffer = MapHandle<BufferInfo>(hitShaderBindingTableBuffer, &VulkanObjectMapper::MapVkBuffer);
    VkBuffer in_callableShaderBindingTableBuffer = MapHandle<BufferInfo>(callableShaderBindingTableBuffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdTraceRaysNV(in_commandBuffer, in_raygenShaderBindingTableBuffer, raygenShaderBindingOffset, in_missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, in_hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, in_callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}

void VulkanReplayConsumer::Process_vkCreateRayTracingPipelinesNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    const StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>& pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPipelineCache in_pipelineCache = MapHandle<PipelineCacheInfo>(pipelineCache, &VulkanObjectMapper::MapVkPipelineCache);
    const VkRayTracingPipelineCreateInfoNV* in_pCreateInfos = pCreateInfos.GetPointer();
    MapStructArrayHandles(pCreateInfos.GetMetaStructPointer(), pCreateInfos.GetLength(), GetObjectMapper());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkPipeline* out_pPipelines = pPipelines->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateRayTracingPipelinesNV(in_device, in_pipelineCache, createInfoCount, in_pCreateInfos, in_pAllocator, out_pPipelines);
    CheckResult("vkCreateRayTracingPipelinesNV", returnValue, replay_result);

    AddHandles<VkPipeline>(pPipelines->GetPointer(), pPipelines->GetLength(), out_pPipelines, createInfoCount, &VulkanObjectMapper::AddVkPipeline);
}

void VulkanReplayConsumer::Process_vkGetRayTracingShaderGroupHandlesNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPipeline in_pipeline = MapHandle<PipelineInfo>(pipeline, &VulkanObjectMapper::MapVkPipeline);
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetRayTracingShaderGroupHandlesNV(in_device, in_pipeline, firstGroup, groupCount, dataSize, out_pData);
    CheckResult("vkGetRayTracingShaderGroupHandlesNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetAccelerationStructureHandleNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkAccelerationStructureNV in_accelerationStructure = MapHandle<AccelerationStructureNVInfo>(accelerationStructure, &VulkanObjectMapper::MapVkAccelerationStructureNV);
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetAccelerationStructureHandleNV(in_device, in_accelerationStructure, dataSize, out_pData);
    CheckResult("vkGetAccelerationStructureHandleNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const HandlePointerDecoder<VkAccelerationStructureNV>& pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkAccelerationStructureNV* in_pAccelerationStructures = pAccelerationStructures.GetHandlePointer();
    MapHandles<AccelerationStructureNVInfo>(pAccelerationStructures.GetPointer(), pAccelerationStructures.GetLength(), in_pAccelerationStructures, accelerationStructureCount, &VulkanObjectMapper::MapVkAccelerationStructureNV);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectMapper::MapVkQueryPool);

    GetDeviceTable(in_commandBuffer)->CmdWriteAccelerationStructuresPropertiesNV(in_commandBuffer, accelerationStructureCount, in_pAccelerationStructures, queryType, in_queryPool, firstQuery);
}

void VulkanReplayConsumer::Process_vkCompileDeferredNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    shader)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPipeline in_pipeline = MapHandle<PipelineInfo>(pipeline, &VulkanObjectMapper::MapVkPipeline);

    VkResult replay_result = GetDeviceTable(in_device)->CompileDeferredNV(in_device, in_pipeline, shader);
    CheckResult("vkCompileDeferredNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const void* in_pHostPointer = PreProcessExternalObject(pHostPointer, format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT, "vkGetMemoryHostPointerPropertiesEXT");
    VkMemoryHostPointerPropertiesEXT* out_pMemoryHostPointerProperties = pMemoryHostPointerProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryHostPointerPropertiesEXT(in_device, handleType, in_pHostPointer, out_pMemoryHostPointerProperties);
    CheckResult("vkGetMemoryHostPointerPropertiesEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdWriteBufferMarkerAMD(
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_dstBuffer = MapHandle<BufferInfo>(dstBuffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdWriteBufferMarkerAMD(in_commandBuffer, pipelineStage, in_dstBuffer, dstOffset, marker);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainEXT>*            pTimeDomains)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    uint32_t* out_pTimeDomainCount = pTimeDomainCount->AllocateOutputData(1, pTimeDomainCount->IsNull() ? static_cast<uint32_t>(0) : (*pTimeDomainCount->GetPointer()));
    VkTimeDomainEXT* out_pTimeDomains = pTimeDomains->IsNull() ? nullptr : pTimeDomains->AllocateOutputData(*out_pTimeDomainCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsEXT(in_physicalDevice, out_pTimeDomainCount, out_pTimeDomains);
    CheckResult("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetCalibratedTimestampsEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    const StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>& pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkCalibratedTimestampInfoEXT* in_pTimestampInfos = pTimestampInfos.GetPointer();
    uint64_t* out_pTimestamps = pTimestamps->IsNull() ? nullptr : pTimestamps->AllocateOutputData(timestampCount);
    uint64_t* out_pMaxDeviation = pMaxDeviation->AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetCalibratedTimestampsEXT(in_device, timestampCount, in_pTimestampInfos, out_pTimestamps, out_pMaxDeviation);
    CheckResult("vkGetCalibratedTimestampsEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksNV(in_commandBuffer, taskCount, firstTask);
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectNV(in_commandBuffer, in_buffer, offset, drawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectMapper::MapVkBuffer);
    VkBuffer in_countBuffer = MapHandle<BufferInfo>(countBuffer, &VulkanObjectMapper::MapVkBuffer);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectCountNV(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdSetExclusiveScissorNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const StructPointerDecoder<Decoded_VkRect2D>& pExclusiveScissors)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkRect2D* in_pExclusiveScissors = pExclusiveScissors.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetExclusiveScissorNV(in_commandBuffer, firstExclusiveScissor, exclusiveScissorCount, in_pExclusiveScissors);
}

void VulkanReplayConsumer::Process_vkCmdSetCheckpointNV(
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const void* in_pCheckpointMarker = PreProcessExternalObject(pCheckpointMarker, format::ApiCallId::ApiCall_vkCmdSetCheckpointNV, "vkCmdSetCheckpointNV");

    GetDeviceTable(in_commandBuffer)->CmdSetCheckpointNV(in_commandBuffer, in_pCheckpointMarker);
}

void VulkanReplayConsumer::Process_vkGetQueueCheckpointDataNV(
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectMapper::MapVkQueue);
    uint32_t* out_pCheckpointDataCount = pCheckpointDataCount->AllocateOutputData(1, pCheckpointDataCount->IsNull() ? static_cast<uint32_t>(0) : (*pCheckpointDataCount->GetPointer()));
    VkCheckpointDataNV* out_pCheckpointData = pCheckpointData->IsNull() ? nullptr : pCheckpointData->AllocateOutputData(*out_pCheckpointDataCount, VkCheckpointDataNV{ VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV, nullptr });

    GetDeviceTable(in_queue)->GetQueueCheckpointDataNV(in_queue, out_pCheckpointDataCount, out_pCheckpointData);
}

void VulkanReplayConsumer::Process_vkInitializePerformanceApiINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>& pInitializeInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkInitializePerformanceApiInfoINTEL* in_pInitializeInfo = pInitializeInfo.GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->InitializePerformanceApiINTEL(in_device, in_pInitializeInfo);
    CheckResult("vkInitializePerformanceApiINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkUninitializePerformanceApiINTEL(
    format::HandleId                            device)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);

    GetDeviceTable(in_device)->UninitializePerformanceApiINTEL(in_device);
}

void VulkanReplayConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>& pMarkerInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkPerformanceMarkerInfoINTEL* in_pMarkerInfo = pMarkerInfo.GetPointer();

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdSetPerformanceMarkerINTEL(in_commandBuffer, in_pMarkerInfo);
    CheckResult("vkCmdSetPerformanceMarkerINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>& pMarkerInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkPerformanceStreamMarkerInfoINTEL* in_pMarkerInfo = pMarkerInfo.GetPointer();

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdSetPerformanceStreamMarkerINTEL(in_commandBuffer, in_pMarkerInfo);
    CheckResult("vkCmdSetPerformanceStreamMarkerINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    const StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>& pOverrideInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);
    const VkPerformanceOverrideInfoINTEL* in_pOverrideInfo = pOverrideInfo.GetPointer();

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdSetPerformanceOverrideINTEL(in_commandBuffer, in_pOverrideInfo);
    CheckResult("vkCmdSetPerformanceOverrideINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>& pAcquireInfo,
    HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkPerformanceConfigurationAcquireInfoINTEL* in_pAcquireInfo = pAcquireInfo.GetPointer();
    VkPerformanceConfigurationINTEL* out_pConfiguration = pConfiguration->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->AcquirePerformanceConfigurationINTEL(in_device, in_pAcquireInfo, out_pConfiguration);
    CheckResult("vkAcquirePerformanceConfigurationINTEL", returnValue, replay_result);

    AddHandles<VkPerformanceConfigurationINTEL>(pConfiguration->GetPointer(), 1, out_pConfiguration, 1, &VulkanObjectMapper::AddVkPerformanceConfigurationINTEL);
}

void VulkanReplayConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPerformanceConfigurationINTEL in_configuration = MapHandle<PerformanceConfigurationINTELInfo>(configuration, &VulkanObjectMapper::MapVkPerformanceConfigurationINTEL);

    VkResult replay_result = GetDeviceTable(in_device)->ReleasePerformanceConfigurationINTEL(in_device, in_configuration);
    CheckResult("vkReleasePerformanceConfigurationINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectMapper::MapVkQueue);
    VkPerformanceConfigurationINTEL in_configuration = MapHandle<PerformanceConfigurationINTELInfo>(configuration, &VulkanObjectMapper::MapVkPerformanceConfigurationINTEL);

    VkResult replay_result = GetDeviceTable(in_queue)->QueueSetPerformanceConfigurationINTEL(in_queue, in_configuration);
    CheckResult("vkQueueSetPerformanceConfigurationINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPerformanceParameterINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkPerformanceParameterTypeINTEL             parameter,
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkPerformanceValueINTEL* out_pValue = pValue->AllocateOutputData(1);

    VkResult replay_result = GetDeviceTable(in_device)->GetPerformanceParameterINTEL(in_device, parameter, out_pValue);
    CheckResult("vkGetPerformanceParameterINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkSetLocalDimmingAMD(
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSwapchainKHR in_swapChain = MapHandle<SwapchainKHRInfo>(swapChain, &VulkanObjectMapper::MapVkSwapchainKHR);

    GetDeviceTable(in_device)->SetLocalDimmingAMD(in_device, in_swapChain, localDimmingEnable);
}

void VulkanReplayConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkImagePipeSurfaceCreateInfoFUCHSIA* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateImagePipeSurfaceFUCHSIA(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateImagePipeSurfaceFUCHSIA", returnValue, replay_result);

    AddHandles<VkSurfaceKHR>(pSurface->GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkCreateMetalSurfaceEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkMetalSurfaceCreateInfoEXT* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateMetalSurfaceEXT(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateMetalSurfaceEXT", returnValue, replay_result);

    AddHandles<VkSurfaceKHR>(pSurface->GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkGetBufferDeviceAddressEXT(
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkBufferDeviceAddressInfoEXT>& pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkBufferDeviceAddressInfoEXT* in_pInfo = pInfo.GetPointer();
    MapStructHandles(pInfo.GetMetaStructPointer(), GetObjectMapper());

    GetDeviceTable(in_device)->GetBufferDeviceAddressEXT(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    uint32_t* out_pPropertyCount = pPropertyCount->AllocateOutputData(1, pPropertyCount->IsNull() ? static_cast<uint32_t>(0) : (*pPropertyCount->GetPointer()));
    VkCooperativeMatrixPropertiesNV* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkCooperativeMatrixPropertiesNV{ VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesNV(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pCombinationCount,
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    uint32_t* out_pCombinationCount = pCombinationCount->AllocateOutputData(1, pCombinationCount->IsNull() ? static_cast<uint32_t>(0) : (*pCombinationCount->GetPointer()));
    VkFramebufferMixedSamplesCombinationNV* out_pCombinations = pCombinations->IsNull() ? nullptr : pCombinations->AllocateOutputData(*out_pCombinationCount, VkFramebufferMixedSamplesCombinationNV{ VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(in_physicalDevice, out_pCombinationCount, out_pCombinations);
    CheckResult("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectMapper::MapVkPhysicalDevice);
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = pSurfaceInfo.GetPointer();
    MapStructHandles(pSurfaceInfo.GetMetaStructPointer(), GetObjectMapper());
    uint32_t* out_pPresentModeCount = pPresentModeCount->AllocateOutputData(1, pPresentModeCount->IsNull() ? static_cast<uint32_t>(0) : (*pPresentModeCount->GetPointer()));
    VkPresentModeKHR* out_pPresentModes = pPresentModes->IsNull() ? nullptr : pPresentModes->AllocateOutputData(*out_pPresentModeCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfacePresentModes2EXT(in_physicalDevice, in_pSurfaceInfo, out_pPresentModeCount, out_pPresentModes);
    CheckResult("vkGetPhysicalDeviceSurfacePresentModes2EXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectMapper::MapVkSwapchainKHR);

    VkResult replay_result = GetDeviceTable(in_device)->AcquireFullScreenExclusiveModeEXT(in_device, in_swapchain);
    CheckResult("vkAcquireFullScreenExclusiveModeEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectMapper::MapVkSwapchainKHR);

    VkResult replay_result = GetDeviceTable(in_device)->ReleaseFullScreenExclusiveModeEXT(in_device, in_swapchain);
    CheckResult("vkReleaseFullScreenExclusiveModeEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = pSurfaceInfo.GetPointer();
    MapStructHandles(pSurfaceInfo.GetMetaStructPointer(), GetObjectMapper());
    VkDeviceGroupPresentModeFlagsKHR* out_pModes = pModes->AllocateOutputData(1, static_cast<VkDeviceGroupPresentModeFlagsKHR>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceGroupSurfacePresentModes2EXT(in_device, in_pSurfaceInfo, out_pModes);
    CheckResult("vkGetDeviceGroupSurfacePresentModes2EXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateHeadlessSurfaceEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    const StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectMapper::MapVkInstance);
    const VkHeadlessSurfaceCreateInfoEXT* in_pCreateInfo = pCreateInfo.GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateHeadlessSurfaceEXT(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateHeadlessSurfaceEXT", returnValue, replay_result);

    AddHandles<VkSurfaceKHR>(pSurface->GetPointer(), 1, out_pSurface, 1, &VulkanObjectMapper::AddVkSurfaceKHR);
}

void VulkanReplayConsumer::Process_vkCmdSetLineStippleEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectMapper::MapVkCommandBuffer);

    GetDeviceTable(in_commandBuffer)->CmdSetLineStippleEXT(in_commandBuffer, lineStippleFactor, lineStipplePattern);
}

void VulkanReplayConsumer::Process_vkResetQueryPoolEXT(
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectMapper::MapVkDevice);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectMapper::MapVkQueryPool);

    GetDeviceTable(in_device)->ResetQueryPoolEXT(in_device, in_queryPool, firstQuery, queryCount);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
